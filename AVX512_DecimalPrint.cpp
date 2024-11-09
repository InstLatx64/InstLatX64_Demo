#include "stdafx.h"
#include "AVX512_DecimalPrint.h"

//#define USE_LIBDIVIDE

//References:
//https://twitter.com/lemire/status/1461181871841320962
//https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/tree/master/2021/11/17
//https://lemire.me/blog/2021/11/18/converting-integers-to-fix-digit-representations-quickly/
//https://lemire.me/blog/2019/02/08/faster-remainders-when-the-divisor-is-a-constant-beating-compilers-and-libdivide/
//https://lemire.me/blog/2019/02/20/more-fun-with-fast-remainders-when-the-divisor-is-a-constant/
//https://lemire.me/blog/2021/05/28/computing-the-number-of-digits-of-an-integer-quickly/
//https://lemire.me/blog/2021/06/03/computing-the-number-of-digits-of-an-integer-even-faster/
//https://twitter.com/trav_downs/status/1398374991721230336
//http://0x80.pl/notesen/2014-03-09-simd-int-log-10.html
//https://arxiv.org/abs/1902.01961
//https://lemire.me/blog/2022/03/28/converting-integers-to-decimal-strings-faster-with-avx-512/

#if defined (USE_LIBDIVIDE)
#include "libdivide.h"
#endif

extern CPU_Props cpu_props;

using namespace std;
#if defined (USE_LIBDIVIDE)
using namespace libdivide;
#endif

inline void _ultoa_wrap(uint32_t x, char * buff) {
	_ultoa_s(x, buff, 32, 10);
}

inline void _ltoa_wrap(int32_t x, char * buff) {
	_ltoa_s(x, buff, 32, 10);
}

inline void _ui64toa_wrap(uint64_t x, char * buff) {
	_ui64toa_s(x, buff, 32, 10);
}

inline void _i64toa_wrap(int64_t x, char * buff) {
	_i64toa_s(x, buff, 32, 10);
}

constexpr uint32_t u32_10pow(uint32_t exp) {
	uint32_t _10pow = 1;
	for (uint32_t p = 0; p < exp; p++)
		_10pow *= 10;
	return _10pow;
}

constexpr uint64_t u64_10pow(uint64_t exp) {
	uint64_t _10pow = 1;
	for (uint64_t p = 0; p < exp; p++)
		_10pow *= 10;
	return _10pow;
}

constexpr uint64_t divconst64(uint64_t divisor) {
	return  UINT64_C(0xFFFFFFFFFFFFFFFF) / divisor + 1;
}

constexpr uint64_t divconst52(uint32_t divisor) {
	return  UINT64_C(0xFFFFFFFFFFFFF) / divisor + 1;
}

constexpr uint64_t divconst52(uint64_t divisor) {
	return  UINT64_C(0xFFFFFFFFFFFFF) / divisor + 1;
}

constexpr uint32_t divconst32(uint32_t divisor) {
	return  UINT64_C(0xFFFFFFFF) / divisor + 1;
}

constexpr uint64_t divconst32(uint64_t divisor) {
	return  UINT64_C(0xFFFFFFFF) / divisor + 1;
}

/*
The IFMA decimal print method: 

Computing remainder of n by 10, 100, ..., 10^8 and then multiplication by 10.

n = 84736251
1              = n mod 10
51             = n mod 100
251            = n mod 1000
6251
36251
736251
4736251
84736251       = n mod 10^8

From this paper 
https://arxiv.org/abs/1902.01961
 page 8:

      uint32_t d = ...; // your divisor > 0
      // c = ceil ( (1 < <64) / d ) ; we take L = N
      uint64_t c = UINT64_C (0 xFFFFFFFFFFFFFFFF ) / d + 1;
      // fastmod computes (n mod d) given precomputed c
      uint32_t fastmod ( uint32_t n, uint64_t c, uint32_t d) {
          uint64_t lowbits = c * n;
          return (( __uint128_t ) lowbits * d) >> 64;
      }

Fastmod fits well for this AVX512FMA instruction pair: 
VPMADD52LUQ => lowbits = c * n + 0
VPMADD52HUQ => highbits = lowbits * 10 + asciiZero
just uses 52b and 104b numbers instead of 64 and 128, and highbits use 10 instead of d, and produces 8 decimal digits for 0 <= n <= 99999999.

The only problem is that in the 8th digit case the VPMADD52HUQ overflows, if we use the orginial 0x2af31dd ( = (2^53 - 1)/(10^8) + 1) constant as c in VPMADD52LUQ:

0x2af31dd * 99999999 = 0x10000001a50b23 

Solution: we use 0x2af31dc = 0x2af31dd - 1 as c, and use 0x1A1A400 bias instead of 0. 0x1A1A400 is the smallest bias, which does not underflows in case of the smallest 8-digit number:

0x2af31dc * 10000000 = 0x19999996FD600 = 450359960000000
(0x19999996FD600 + 0x1A1A400) * 10 = 0x1000000EAEC400

The drawback of this method is that it works only in the 0 <= n <= 99999999 range, so splitting is required even for uint32_t and int32_t too.

*/ 

// max. 10 digit uint32_t, 7:3 split
void _ultoa_avx512ifma_intrin(uint32_t n, char * buff) {
	uint32_t n_9_7				= 0;
	_mulx_u32(n, 0x0d6bf94d6UL, &n_9_7);
						n_9_7 >>= 0x17;							//n / 10^7
	const uint32_t n_6_0		= n - (n_9_7 * u32_10pow(7));	//n % 10^7
	const __m512i bcst_d		= _mm512_set1_epi32(n);
	const __m512i bcst_q_h		= _mm512_set1_epi64(n_9_7);
	const __m512i bcst_q_l		= _mm512_set1_epi64(n_6_0);
 	const __m512i zmmzero		= _mm512_setzero_si512();
 	const __m512i asciiZero		= _mm512_set1_epi64('0');

	const __m512i ifma_const	= _mm512_set_epi64(divconst52(u64_10pow(1)), divconst52(u64_10pow(2)), divconst52(u64_10pow(3)), divconst52(u64_10pow(4)), divconst52(u64_10pow(5)), divconst52(u64_10pow(6)), divconst52(u64_10pow(7)), 0);
	const __m512i permb_const	= _mm512_castsi128_si512(_mm_set_epi8(0x7F, 0x78, 0x70, 0x68, 0x60, 0x58, 0x50, 0x48, 0x38, 0x30, 0x28, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F));
	const __m512i tenPows		= _mm512_set_epi32( 0, 0, u32_10pow(1), u32_10pow(2), u32_10pow(3), u32_10pow(4), u32_10pow(5), u32_10pow(6), u32_10pow(7), u32_10pow(8), u32_10pow(9), 0, 0, 0, 0, 0);

	const __mmask16 mask		= _mm512_mask_cmpge_epu32_mask(0xffe0, bcst_d, tenPows);
	const __m512i lowbits_h		= _mm512_madd52lo_epu64(zmmzero, bcst_q_h, ifma_const);
	const __m512i lowbits_l		= _mm512_madd52lo_epu64(zmmzero, bcst_q_l, ifma_const);
	const __m512i highbits_h	= _mm512_madd52hi_epu64(asciiZero, lowbits_h, _mm512_set1_epi64(10));
	const __m512i highbits_l	= _mm512_madd52hi_epu64(asciiZero, lowbits_l, _mm512_set1_epi64(10));
	uint64_t	tz				= _tzcnt_u64(mask);
	const __m128i digits_9_0	= _mm512_castsi512_si128(_mm512_permutex2var_epi8(highbits_h, permb_const, highbits_l));
								  _mm_mask_storeu_epi8 (buff - tz, mask, digits_9_0);
}

// max. 10 digit abs(int32_t), 7:3 split
void _ltoa_avx512ifma_intrin(int32_t n, char* buff) {
	const uint32_t an			= abs(n);
	uint32_t n_9_7				= 0;
	_mulx_u32(an, 0x0d6bf94d6UL, &n_9_7);
						n_9_7 >>= 0x17;												//n / 10^7
	const uint32_t n_6_0		= an - (n_9_7 * u32_10pow(7));	//n % 10^7
	const __m512i bcst_d		= _mm512_set1_epi32(n);
	const __m512i abcst_d		= _mm512_abs_epi32(bcst_d);
	const __m512i bcst_q_h		= _mm512_set1_epi64(n_9_7);
	const __m512i bcst_q_l		= _mm512_set1_epi64(n_6_0);
	const __m512i zmmzero		= _mm512_setzero_si512();
	const __m512i asciiZero		= _mm512_set1_epi64('0');

	const __m512i ifma_const	= _mm512_set_epi64(divconst52(u64_10pow(1)), divconst52(u64_10pow(2)), divconst52(u64_10pow(3)), divconst52(u64_10pow(4)), divconst52(u64_10pow(5)), divconst52(u64_10pow(6)), divconst52(u64_10pow(7)), 0);
	const __m512i permb_const	= _mm512_castsi128_si512(_mm_set_epi8(0x7F, 0x78, 0x70, 0x68, 0x60, 0x58, 0x50, 0x48, 0x38, 0x30, 0x28, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F));
	const __m512i tenPows		= _mm512_set_epi32(0, 0, u32_10pow(1), u32_10pow(2), u32_10pow(3), u32_10pow(4), u32_10pow(5), u32_10pow(6), u32_10pow(7), u32_10pow(8), u32_10pow(9), 0, 0, 0, 0, 0);
	const __m512i tenNPows		= _mm512_set_epi32(0, 0, 0 - u32_10pow(0), 0 - u32_10pow(1), 0 - u32_10pow(2), 0 - u32_10pow(3), 0 - u32_10pow(4), 0 - u32_10pow(5), 0 - u32_10pow(6), 0 - u32_10pow(7), 0 - u32_10pow(8), 0 - u32_10pow(9), 0, 0, 0, 0);
	const __mmask16 nmask		= _mm512_mask_cmple_epi32_mask(0xfff0, bcst_d, tenNPows);
	const __mmask16 mask		= _mm512_mask_cmpge_epu32_mask(0xffe0, abcst_d, tenPows);

	const __m512i lowbits_h		= _mm512_madd52lo_epu64(zmmzero, bcst_q_h, ifma_const);
	const __m512i lowbits_l		= _mm512_madd52lo_epu64(zmmzero, bcst_q_l, ifma_const);
	const __m512i highbits_h	= _mm512_madd52hi_epu64(asciiZero, lowbits_h, _mm512_set1_epi64(10));
	const __m512i highbits_l	= _mm512_madd52hi_epu64(asciiZero, lowbits_l, _mm512_set1_epi64(10));
	const __mmask16 fullMask	= _kor_mask16(nmask, mask);
	const __m128i digits_9_0	= _mm512_castsi512_si128(_mm512_permutex2var_epi8(highbits_h, permb_const, highbits_l));
	const __m128i minus_sign	= _mm_ternarylogic_epi64(digits_9_0, _mm_set1_epi32(0x2d2d2d2d), _mm_movm_epi8(mask), 0xe4);
	uint64_t		tz			= _tzcnt_u64(fullMask);
	_mm_mask_storeu_epi8(buff - tz, fullMask, minus_sign);
}

// max. 20 digit uint64_t, 7:7:6 split
void _ui64toa_avx512ifma_intrin(uint64_t n, char *buff) {
	uint64_t n_19_07				= 0ULL;
	uint64_t n_19_14				= 0ULL;
									  _mulx_u64(n, 0xd6bf94d5e57a42bd, &n_19_07);
									  _mulx_u64(n, 0xb424dc35095cd810, &n_19_14);
							n_19_07	>>= 0x17; // n / 10^7
							n_19_14	>>= 0x2e; // n / 10^14
	const uint64_t n_13_07			= n_19_07 - (n_19_14 * u64_10pow(7));
	const uint64_t n_06_00			= n - (n_19_07 * u64_10pow(7));

	const __m512i bcst_19_0			= _mm512_set1_epi64(n);
	const __m512i bcst_19_14		= _mm512_set1_epi64((uint32_t)n_19_14);
	const __m512i bcst_13_07		= _mm512_set1_epi64((uint32_t)n_13_07);
	const __m512i bcst_06_00		= _mm512_set1_epi64((uint32_t)n_06_00);

 	const __m512i zmmzero			= _mm512_setzero_si512();
 	const __m512i zmmTen			= _mm512_set1_epi64(10);
 	const __m512i asciiZero			= _mm512_set1_epi64('0');

	//const __m512i ifma_const		= _mm512_set_epi64(divconst52(u64_10pow(1)), divconst52(u64_10pow(2)), divconst52(u64_10pow(3)), divconst52(u64_10pow(4)), divconst52(u64_10pow(5)), divconst52(u64_10pow(6)), divconst52(u64_10pow(7)), divconst52(u64_10pow(8)) - 1);
	const __m512i ifma_const		= _mm512_setr_epi64(0x00000000002af31dc, 0x0000000001ad7f29b, 0x0000000010c6f7a0c, 0x00000000a7c5ac472, 0x000000068db8bac72, 0x0000004189374bc6b, 0x0000028f5c28f5c29, 0x0000199999999999a);
	const __m512i permb_06_00		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F38302820181008, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F));
	const __m512i permb_13_07		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F3F3F3F3F3F3F3F, 0x383028201810083F, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F));
	const __m512i permb_19_14		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F38, 0x30282018103F3F3F, 0x3F3F3F3F3F3F3F3F));

	const __m512i tenPows_07_00		= _mm512_setr_epi64(0x000000000000f4240, 0x000000000000186a0, 0x00000000000002710, 0x000000000000003e8, 0x00000000000000064, 0x0000000000000000a, 0x00000000000000000, 0x00000000000000000);
	const __m512i tenPows_15_08		= _mm512_setr_epi64(0x000005af3107a4000, 0x0000009184e72a000, 0x0000000e8d4a51000, 0x0000000174876e800, 0x000000002540be400, 0x0000000003b9aca00, 0x00000000005f5e100, 0x00000000000989680);
	const __m512i tenPows_19_16		= _mm512_setr_epi64(0x08ac7230489e80000, 0x00de0b6b3a7640000, 0x0016345785d8a0000, 0x0002386f26fc10000, 0x000038d7ea4c68000, 0x00000000000000000, 0x00000000000000000, 0x00000000000000000);

	const __m512i lowbits_19_14		= _mm512_madd52lo_epu64(zmmzero, bcst_19_14, ifma_const);
	const __m512i lowbits_13_07		= _mm512_madd52lo_epu64(zmmzero, bcst_13_07, ifma_const);
	const __m512i lowbits_06_00		= _mm512_madd52lo_epu64(zmmzero, bcst_06_00, ifma_const);
	const __m512i highbits_19_14	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_19_14);
	const __m512i highbits_13_07	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_13_07);
	const __m512i highbits_06_00	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_06_00);

	const __mmask8 mask_07_00		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_07_00);
	const __mmask8 mask_15_08		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_15_08);
	const __mmask8 mask_19_16		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_19_16);
	const __mmask16 mask_15_00		= _mm512_kunpackb(mask_07_00, mask_15_08);
	const __mmask16 mask_31_16		= _kshiftli_mask16(mask_19_16, 8 + 3);
	const __mmask32 mask_19_00		= _mm512_kunpackw(mask_15_00, mask_31_16);

	const __m256i digits_19_14		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_19_14, highbits_19_14));
	const __m256i digits_13_07		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_13_07, highbits_13_07));
	const __m256i digits_06_00		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_06_00, highbits_06_00));

	const __m256i digits_19_00		= _mm256_ternarylogic_epi64(digits_19_14, digits_13_07, digits_06_00, 0xfe);
	uint64_t		tz				= _tzcnt_u64(mask_19_00);
									  _mm256_mask_storeu_epi8 (buff - tz, mask_19_00, digits_19_00);
}

// max. 20 digit abs(int64_t), 7:7:6 split
void _i64toa_avx512ifma_intrin(int64_t n, char* buff) {
	const uint64_t an				= abs(n);
	uint64_t n_19_07				= 0ULL;
	uint64_t n_19_14				= 0ULL;
									  _mulx_u64(an, 0xd6bf94d5e57a42bd, &n_19_07);
									  _mulx_u64(an, 0xb424dc35095cd810, &n_19_14);
							n_19_07	>>= 0x17; // n / 10^7
							n_19_14	>>= 0x2e; // n / 10^14
	const uint64_t n_13_07			= n_19_07 - (n_19_14 * u64_10pow(7));
	const uint64_t n_06_00			= an - (n_19_07 * u64_10pow(7));

	const __m512i bcst_19_0			= _mm512_set1_epi64(an);
	const __m512i bcst_19_14		= _mm512_set1_epi64((uint32_t)n_19_14);
	const __m512i bcst_13_07		= _mm512_set1_epi64((uint32_t)n_13_07);
	const __m512i bcst_06_00		= _mm512_set1_epi64((uint32_t)n_06_00);

 	const __m512i zmmzero			= _mm512_setzero_si512();
	const __m512i zmmTen			= _mm512_set1_epi64(10);
	const __m512i asciiZero			= _mm512_set1_epi64('0');

	const __m512i ifma_const		= _mm512_setr_epi64(0x00000000002af31dc, 0x0000000001ad7f29b, 0x0000000010c6f7a0c, 0x00000000a7c5ac472, 0x000000068db8bac72, 0x0000004189374bc6b, 0x0000028f5c28f5c29, 0x0000199999999999a);
	const __m512i permb_06_00		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F38302820181008, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F));
	const __m512i permb_13_07		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F3F3F3F3F3F3F3F, 0x383028201810083F, 0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F3F));
	const __m512i permb_19_14		= _mm512_castsi256_si512(_mm256_set_epi64x(0x3F3F3F3F3F3F3F3F, 0x3F3F3F3F3F3F3F38, 0x30282018103F3F3F, 0x3F3F3F3F3F3F3F3F));

	const __m512i tenPows_07_00		= _mm512_setr_epi64(0x000000000000f4240, 0x000000000000186a0, 0x00000000000002710, 0x000000000000003e8, 0x00000000000000064, 0x0000000000000000a, 0x00000000000000000, 0x00000000000000000);
	const __m512i tenPows_15_08		= _mm512_setr_epi64(0x000005af3107a4000, 0x0000009184e72a000, 0x0000000e8d4a51000, 0x0000000174876e800, 0x000000002540be400, 0x0000000003b9aca00, 0x00000000005f5e100, 0x00000000000989680);
	const __m512i tenPows_19_16		= _mm512_setr_epi64(0x08ac7230489e80000, 0x00de0b6b3a7640000, 0x0016345785d8a0000, 0x0002386f26fc10000, 0x000038d7ea4c68000, 0x00000000000000000, 0x00000000000000000, 0x00000000000000000);

	const __m512i lowbits_19_14		= _mm512_madd52lo_epu64(zmmzero, bcst_19_14, ifma_const);
	const __m512i lowbits_13_07		= _mm512_madd52lo_epu64(zmmzero, bcst_13_07, ifma_const);
	const __m512i lowbits_06_00		= _mm512_madd52lo_epu64(zmmzero, bcst_06_00, ifma_const);
	const __m512i highbits_19_14	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_19_14);
	const __m512i highbits_13_07	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_13_07);
	const __m512i highbits_06_00	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_06_00);

	const __mmask8 mask_07_00		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_07_00);
	const __mmask8 mask_15_08		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_15_08);
	const __mmask8 mask_19_16		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_19_16);
	const __mmask16 mask_15_00		= _mm512_kunpackb(mask_07_00, mask_15_08);
	const __mmask16 mask_31_16		= _kshiftli_mask16(mask_19_16, 8 + 3);
	const __mmask32 mask_19_00		= _mm512_kunpackw(mask_15_00, mask_31_16);

	const uint32_t gprmask			= _cvtmask32_u32(mask_19_00);
	const uint32_t fullmask			= gprmask | ((gprmask >> 1) & (uint32_t)(n >> 63));

	const __m256i digits_19_14		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_19_14, highbits_19_14));
	const __m256i digits_13_07		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_13_07, highbits_13_07));
	const __m256i digits_06_00		= _mm512_castsi512_si256(_mm512_permutexvar_epi8(permb_06_00, highbits_06_00));

	const __m256i digits_19_00		= _mm256_ternarylogic_epi64(_mm256_ternarylogic_epi64(digits_19_14, digits_13_07, digits_06_00, 0xfe), _mm256_movm_epi8(mask_19_00), _mm256_set1_epi32(0x2d2d2d2d), 0xe2);
	uint64_t		tz				= _tzcnt_u64(fullmask);
									  _mm256_mask_storeu_epi8(buff - tz, fullmask, digits_19_00);
}

/*
The AVX512F method:
It is based on division by powers of ten:

n / 10^8
n / 10^7
..
n / 10^1

e.g.:
n = 84736251

div10pow ways:

0
8
84
847
8473
84736
847362
8473625

rotated div10pow ways:     mul10 of div10pow:		difference:
(n / 10^0 = n in the 
least significant way)
8                           0                       8
84                          80                      4
847                         840                     7
8473                        8470                    3
84736                       84730                   6
847362                      847360                  2
8473625                     8473620                 5
84736251                    84736250                1

The division algorithm is the branchfree version of libdivide.h: 
https://libdivide.com/

uint32_t libdivide_u32_branchfree_do(
    uint32_t numer, const struct libdivide_u32_branchfree_t *denom) {
    uint32_t q = libdivide_mullhi_u32(denom->magic, numer);
    uint32_t t = ((numer - q) >> 1) + q;
    return t >> denom->more;
}

The advantage of this method is that it works on the entire uint32_t range: 0 <= n < 2^32-1, so splitting is required for uint64_t and int64_t only.
*/

void _ultoa_avx512f_intrin(uint32_t n, char * buff) {
	const __m512i bcst_d		= _mm512_set1_epi32(n);

	const __m512i mul_const0145	= _mm512_setr_epi32(0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x12e0be83, 0x00000000, 0x5798ee24, 0x00000000, 0x4f8b588f, 0x00000000, 0xa36e2eb2, 0x00000000, 0x9999999a, 0x00000000, 0x00000001, 0x00000000);
	const __m512i mul_const2367	= _mm512_setr_epi32(0xad7f29ac, 0x00000000, 0x0c6f7a0c, 0x00000000, 0x0624dd30, 0x00000000, 0x47ae147b, 0x00000000, 0xad7f29ac, 0x00000000, 0x0c6f7a0c, 0x00000000, 0x0624dd30, 0x00000000, 0x47ae147b, 0x00000000);

	const __m512i tenPows		= _mm512_set_epi32( 0, 0, u32_10pow(1), u32_10pow(2), u32_10pow(3), u32_10pow(4), u32_10pow(5), u32_10pow(6), u32_10pow(7), u32_10pow(8), u32_10pow(9), 0, 0, 0, 0, 0);
	const __m512i srlv_const	= _mm512_set_epi32( 0,  3,  6,  9, 13, 16, 19, 23, 26, 29, 32, 32, 32, 32, 32, 32);

	const __m512i mul_0145		= _mm512_mul_epu32(bcst_d, mul_const0145);
	const __m512i mul_2367		= _mm512_mul_epu32(bcst_d, mul_const2367);

	const __mmask16 mask		= _mm512_mask_cmpge_epu32_mask(0xffe0, bcst_d, tenPows);
	const __m512i dwords		= _mm512_castps_si512(_mm512_shuffle_ps(_mm512_castsi512_ps(mul_2367), _mm512_castsi512_ps(mul_0145), 0xdd));
	const __m512i temp2			= _mm512_mask_srli_epi32(bcst_d, 0x7fff, _mm512_sub_epi32(bcst_d, dwords), 1);
	const __m512i div10			= _mm512_srlv_epi32(_mm512_add_epi32(temp2, dwords), srlv_const);

	const __m512i rotated		= _mm512_alignr_epi32(div10, div10, 1);
	const __m512i mul10			= _mm512_add_epi32(_mm512_slli_epi32(div10, 3), _mm512_add_epi32(div10, div10));
	const __m512i diff			= _mm512_maskz_sub_epi32(0x7fff, _mm512_add_epi32(rotated, _mm512_set1_epi32(0x30)), mul10);
	uint64_t	tz				= _tzcnt_u64(mask);
								  _mm512_mask_cvtepi32_storeu_epi8(buff - tz, mask, diff);
	return;
}

void _ltoa_avx512f_intrin(int32_t n, char * buff) {
	const __m512i bcst_d		= _mm512_set1_epi32(n);
	const __m512i abcst_d		= _mm512_abs_epi32(bcst_d);

	const __m512i mul_const0145	= _mm512_setr_epi32(0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x12e0be83, 0x00000000, 0x5798ee24, 0x00000000, 0x4f8b588f, 0x00000000, 0xa36e2eb2, 0x00000000, 0x9999999a, 0x00000000, 0x00000001, 0x00000000);
	const __m512i mul_const2367	= _mm512_setr_epi32(0xad7f29ac, 0x00000000, 0x0c6f7a0c, 0x00000000, 0x0624dd30, 0x00000000, 0x47ae147b, 0x00000000, 0xad7f29ac, 0x00000000, 0x0c6f7a0c, 0x00000000, 0x0624dd30, 0x00000000, 0x47ae147b, 0x00000000);

	const __m512i tenPows		= _mm512_set_epi32(0, 0, u32_10pow(1), u32_10pow(2), u32_10pow(3), u32_10pow(4), u32_10pow(5), u32_10pow(6), u32_10pow(7), u32_10pow(8), u32_10pow(9), 0, 0, 0, 0, 0);
	const __m512i tenNPows		= _mm512_set_epi32(0, 0, 0 - u32_10pow(0), 0 - u32_10pow(1), 0 - u32_10pow(2), 0 - u32_10pow(3), 0 - u32_10pow(4), 0 - u32_10pow(5), 0 - u32_10pow(6), 0 - u32_10pow(7), 0 - u32_10pow(8), 0 - u32_10pow(9), 0, 0, 0, 0);
	const __m512i srlv_const	= _mm512_set_epi32( 0,  3,  6,  9, 13, 16, 19, 23, 26, 29, 32, 32, 32, 32, 32, 32);

	const __m512i mul_0145		= _mm512_mul_epu32(abcst_d, mul_const0145);
	const __m512i mul_2367		= _mm512_mul_epu32(abcst_d, mul_const2367);

	const __mmask16 mask		= _mm512_mask_cmpge_epu32_mask(0xffe0, abcst_d, tenPows);
	const __mmask16 fullMask	= _kor_mask16(_mm512_mask_cmple_epi32_mask(0xfff0, bcst_d, tenNPows), mask);
	const __m512i dwords		= _mm512_castps_si512(_mm512_shuffle_ps(_mm512_castsi512_ps(mul_2367), _mm512_castsi512_ps(mul_0145), 0xdd));
	const __m512i temp2			= _mm512_mask_srli_epi32(abcst_d, 0x7fff, _mm512_sub_epi32(abcst_d, dwords), 1);
	const __m512i div10			= _mm512_srlv_epi32(_mm512_add_epi32(temp2, dwords), srlv_const);

	const __m512i rotated		= _mm512_maskz_alignr_epi32(0x7fff, div10, div10, 1);
	const __m512i mul10			= _mm512_maskz_add_epi32(0x7fff, _mm512_sub_epi32(_mm512_slli_epi32(div10, 3), _mm512_set1_epi32(0x30)), _mm512_add_epi32(div10, div10));
	const __m512i diff			= _mm512_mask_sub_epi32(_mm512_set1_epi32('-'), mask, rotated, mul10);
	uint64_t	tz				= _tzcnt_u64(fullMask);
								  _mm512_mask_cvtepi32_storeu_epi8(buff - tz, fullMask, diff);
	return;
}

// max. 20 digit uint64_t, 8:8:4 split due to VPMOVDB continuity
void _ui64toa_avx512f_intrin(uint64_t n, char *buff) {
	uint64_t n_19_08				= 0ULL;
	uint64_t n_19_16				= 0ULL;
									  _mulx_u64(n, 0xabcc77118461cefd, &n_19_08);
									  _mulx_u64(n, 0xe69594bec44de15c, &n_19_16);
							n_19_08	>>= 0x1a; // n / 10^8
							n_19_16	>>= 0x35; // n / 10^16
	uint64_t n_15_08				= n_19_08 - (n_19_16 * u64_10pow(8));
	uint64_t n_07_00				= n - (n_19_08 * u64_10pow(8));

	const __m512i bcst_19_00		= _mm512_set1_epi64(n);
	const __m512i bcst_19_16		= _mm512_set1_epi32((uint32_t)n_19_16);
	const __m512i bcst_15_08		= _mm512_set1_epi32((uint32_t)n_15_08);
	const __m512i bcst_07_00		= _mm512_set1_epi32((uint32_t)n_07_00);
 
	const __m512i mul_const			= _mm512_set_epi32(0, 0x9999999a, 0, 0x47ae147b, 0, 0x0624dd30, 0, 0xa36e2eb2, 0, 0x4f8b588f, 0, 0x0c6f7a0c, 0, 0xad7f29ac, 0, 0x5798ee24);
	const __m512i perm_const		= _mm512_set_epi32(17, 15, 13, 11, 9, 7, 5, 3, 1, 31, 29, 27, 25, 23, 21, 19);
	const __m512i srlv_const		= _mm512_set_epi32(26, 3,  6,  9, 13, 16, 19, 23, 26, 3,  6,  9, 13, 16, 19, 23);

	const __m512i tenPows_07_00		= _mm512_setr_epi64(0x000000000000f4240, 0x000000000000186a0, 0x00000000000002710, 0x000000000000003e8, 0x00000000000000064, 0x0000000000000000a, 0x00000000000000000, 0x00000000000000000);
	const __m512i tenPows_15_08		= _mm512_setr_epi64(0x000005af3107a4000, 0x0000009184e72a000, 0x0000000e8d4a51000, 0x0000000174876e800, 0x000000002540be400, 0x0000000003b9aca00, 0x00000000005f5e100, 0x00000000000989680);
	const __m512i tenPows_19_16		= _mm512_setr_epi64(0x08ac7230489e80000, 0x00de0b6b3a7640000, 0x0016345785d8a0000, 0x0002386f26fc10000, 0x000038d7ea4c68000, 0x00000000000000000, 0x00000000000000000, 0x00000000000000000);

	const __m512i mul_19_16			= _mm512_mul_epu32(bcst_19_16, mul_const);
	const __m512i mul_15_08			= _mm512_mul_epu32(bcst_15_08, mul_const);
	const __m512i mul_07_00			= _mm512_mul_epu32(bcst_07_00, mul_const);

	const __mmask8 mask_07_00		= _mm512_cmpge_epu64_mask(bcst_19_00, tenPows_07_00);
	const __mmask8 mask_15_08		= _mm512_cmpge_epu64_mask(bcst_19_00, tenPows_15_08);
	const __mmask8 mask_19_16		= _mm512_cmpge_epu64_mask(bcst_19_00, tenPows_19_16);
	const __mmask16 mask_15_00		= _mm512_kunpackb(mask_07_00, mask_15_08);
	const __mmask16 mask_31_16		= _kshiftli_mask16(mask_19_16, 8 + 3);
	const __m512i dwords14_00		= _mm512_permutex2var_epi32(mul_07_00, perm_const, mul_15_08);
	const __m512i dwords19_15		= _mm512_permutex2var_epi32(mul_19_16, perm_const, mul_15_08);
	const __m512i bcst_14_00		= _mm512_mask_blend_epi32(0xff80, bcst_15_08, bcst_07_00);
	const __m512i bcst_19_15		= _mm512_mask_blend_epi32(0x8000, bcst_19_16, bcst_15_08);
	const __m512i temp_14_00		= _mm512_srli_epi32(_mm512_sub_epi32(bcst_14_00, dwords14_00), 1);
	const __m512i temp_19_15		= _mm512_srli_epi32(_mm512_sub_epi32(bcst_19_15, dwords19_15), 1);
	const __m512i div10pow_14_00	= _mm512_srlv_epi32(_mm512_add_epi32(temp_14_00, dwords14_00), srlv_const);
	const __m512i div10pow_19_15	= _mm512_srlv_epi32(_mm512_add_epi32(temp_19_15, dwords19_15), srlv_const);

	const __m512i rotated_14_00		= _mm512_mask_alignr_epi32(bcst_14_00, 0xbfbf, div10pow_14_00, div10pow_14_00, 1);
	const __m512i rotated_19_15		= _mm512_mask_alignr_epi32(bcst_19_15, 0xbfbf, div10pow_14_00, div10pow_19_15, 1);

	const __m512i mul10_14_00		= _mm512_add_epi32(_mm512_slli_epi32(div10pow_14_00, 3), _mm512_add_epi32(div10pow_14_00, div10pow_14_00));
	const __m512i mul10_19_15		= _mm512_add_epi32(_mm512_slli_epi32(div10pow_19_15, 3), _mm512_add_epi32(div10pow_19_15, div10pow_19_15));

	const __m512i diff_14_0			= _mm512_maskz_sub_epi32(0x7fff, _mm512_add_epi32(rotated_14_00, _mm512_set1_epi32('0')), mul10_14_00);
	const __m512i diff_19_15		= _mm512_sub_epi32(_mm512_add_epi32(rotated_19_15, _mm512_set1_epi32('0')), mul10_19_15);

	uint32_t mask_19_00				= (mask_15_00 << 16) | mask_31_16;
	uint64_t tz						= _tzcnt_u64(mask_19_00);
									  _mm512_mask_cvtepi32_storeu_epi8(buff - tz, mask_31_16, diff_19_15);
									  _mm512_mask_cvtepi32_storeu_epi8(buff - tz + 0x10, mask_15_00, diff_14_0);
}

// max. 20 digit abs(int64_t), 8:8:4 split due to VPMOVDB continuity
void _i64toa_avx512f_intrin(int64_t n, char *buff) {
	const uint64_t an				= abs(n);
	uint64_t n_19_08				= 0ULL;
	uint64_t n_19_16				= 0ULL;
									  _mulx_u64(an, 0xabcc77118461cefd, &n_19_08);
									  _mulx_u64(an, 0xe69594bec44de15c, &n_19_16);
							n_19_08	>>= 0x1a; // n / 10^8
							n_19_16	>>= 0x35; // n / 10^16
	uint64_t n_15_08				= n_19_08 - (n_19_16 * u64_10pow(8));
	uint64_t n_07_00				= an - (n_19_08 * u64_10pow(8));

	const __m512i bcst_19_0			= _mm512_set1_epi64(an);
	const __m512i bcst_19_16		= _mm512_set1_epi32((uint32_t)n_19_16);
	const __m512i bcst_15_08		= _mm512_set1_epi32((uint32_t)n_15_08);
	const __m512i bcst_07_00		= _mm512_set1_epi32((uint32_t)n_07_00);
 
	const __m512i mul_const			= _mm512_set_epi32(0, 0x9999999a, 0, 0x47ae147b, 0, 0x0624dd30, 0, 0xa36e2eb2, 0, 0x4f8b588f, 0, 0x0c6f7a0c, 0, 0xad7f29ac, 0, 0x5798ee24);
	const __m512i perm_const		= _mm512_set_epi32(17, 15, 13, 11, 9, 7, 5, 3, 1, 31, 29, 27, 25, 23, 21, 19);
	const __m512i srlv_const		= _mm512_set_epi32(26, 3,  6,  9, 13, 16, 19, 23, 26, 3,  6,  9, 13, 16, 19, 23);
	const __m512i tenPows_07_00		= _mm512_setr_epi64(0x000000000000f4240, 0x000000000000186a0, 0x00000000000002710, 0x000000000000003e8, 0x00000000000000064, 0x0000000000000000a, 0x00000000000000000, 0x00000000000000000);
	const __m512i tenPows_15_08		= _mm512_setr_epi64(0x000005af3107a4000, 0x0000009184e72a000, 0x0000000e8d4a51000, 0x0000000174876e800, 0x000000002540be400, 0x0000000003b9aca00, 0x00000000005f5e100, 0x00000000000989680);
	const __m512i tenPows_19_16		= _mm512_setr_epi64(0x08ac7230489e80000, 0x00de0b6b3a7640000, 0x0016345785d8a0000, 0x0002386f26fc10000, 0x000038d7ea4c68000, 0x00000000000000000, 0x00000000000000000, 0x00000000000000000);

	const __m512i mul_19_16			= _mm512_mul_epu32(bcst_19_16, mul_const);
	const __m512i mul_15_08			= _mm512_mul_epu32(bcst_15_08, mul_const);
	const __m512i mul_07_00			= _mm512_mul_epu32(bcst_07_00, mul_const);

	const __mmask8 mask_07_00		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_07_00);
	const __mmask8 mask_15_08		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_15_08);
	const __mmask8 mask_19_16		= _mm512_cmpge_epu64_mask(bcst_19_0, tenPows_19_16);
	const __mmask16 mask_15_00		= _mm512_kunpackb(mask_07_00, mask_15_08);
	const __mmask16 mask_31_16		= _kshiftli_mask16(mask_19_16, 8 + 3);
	const __m512i dwords14_00		= _mm512_permutex2var_epi32(mul_07_00, perm_const, mul_15_08);
	const __m512i dwords19_15		= _mm512_permutex2var_epi32(mul_19_16, perm_const, mul_15_08);
	const __m512i bcst_14_00		= _mm512_mask_blend_epi32(0xff80, bcst_15_08, bcst_07_00);
	const __m512i bcst_19_15		= _mm512_mask_blend_epi32(0x8000, bcst_19_16, bcst_15_08);
	const __m512i temp_14_00		= _mm512_srli_epi32(_mm512_sub_epi32(bcst_14_00, dwords14_00), 1);
	const __m512i temp_19_15		= _mm512_srli_epi32(_mm512_sub_epi32(bcst_19_15, dwords19_15), 1);
	const __m512i div10pow_14_00	= _mm512_srlv_epi32(_mm512_add_epi32(temp_14_00, dwords14_00), srlv_const);
	const __m512i div10pow_19_15	= _mm512_srlv_epi32(_mm512_add_epi32(temp_19_15, dwords19_15), srlv_const);

	const __m512i rotated_14_00		= _mm512_mask_alignr_epi32(bcst_14_00, 0xbfbf, div10pow_14_00, div10pow_14_00, 1);
	const __m512i rotated_19_15		= _mm512_mask_alignr_epi32(bcst_19_15, 0xbfbf, div10pow_14_00, div10pow_19_15, 1);

	const __m512i mul10_14_00		= _mm512_maskz_add_epi32(0x7fff, _mm512_slli_epi32(div10pow_14_00, 3), _mm512_add_epi32(div10pow_14_00, div10pow_14_00));
	const __m512i mul10_19_15		= _mm512_add_epi32(_mm512_slli_epi32(div10pow_19_15, 3), _mm512_add_epi32(div10pow_19_15, div10pow_19_15));

	const __m512i diff_14_00		= _mm512_mask_sub_epi32(_mm512_set1_epi32('-'), mask_15_00, _mm512_maskz_add_epi32(0x7fff, rotated_14_00, _mm512_set1_epi32('0')), mul10_14_00);
	const __m512i diff_19_15		= _mm512_mask_sub_epi32(_mm512_set1_epi32('-'), mask_31_16, _mm512_add_epi32(rotated_19_15, _mm512_set1_epi32('0')), mul10_19_15);

	uint32_t mask_19_00				= (mask_15_00 << 16) | mask_31_16;
	const uint32_t finalmask		=  mask_19_00 | ((n >> 63) & (mask_19_00 >> 1));
	uint64_t tz						= _tzcnt_u64(finalmask);
									  _mm512_mask_cvtepi32_storeu_epi8(buff - tz, finalmask, diff_19_15);
									  _mm512_mask_cvtepi32_storeu_epi8(buff - tz + 0x10, finalmask >> 16, diff_14_00);
}

void to_string_avx512f_intrin(uint64_t n, char *out) {          
	uint64_t n_15_08			= 0;
								  _mulx_u64(n, 0xabcc77118461cefd, &n_15_08);
						n_15_08	>>= 0x1a;									//n / 10^8
	const uint64_t n_07_00		= n - (n_15_08 * u64_10pow(8));				//n % 10^8
	const __m512i bcst_h		= _mm512_set1_epi32((uint32_t)n_15_08);
	const __m512i bcst_l		= _mm512_set1_epi32((uint32_t)n_07_00);
 
    //                                                  10^(-1)       10^(-2)         10^(-3)       10^(-4)         10^(-5)       10^(-6)       10^(-7)         10^(-8)
	const __m512i mul_const		= _mm512_set_epi32(0, 0x9999999a, 0, 0x47ae147b, 0, 0x0624dd30, 0, 0xa36e2eb2, 0, 0x4f8b588f, 0, 0x0c6f7a0c, 0, 0xad7f29ac, 0, 0x5798ee24);
	const __m512i perm_const	= _mm512_set_epi32(15, 13, 11, 9, 7, 5, 3, 1, 31, 29, 27, 25, 23, 21, 19, 17);
	const __m512i srlv_const	= _mm512_broadcast_i64x4(_mm256_set_epi32(3,  6,  9, 13, 16, 19, 23, 26));

	const __m512i mul_h			= _mm512_mul_epu32(bcst_h, mul_const);
	const __m512i mul_l			= _mm512_mul_epu32(bcst_l, mul_const);

	const __m512i dwords		= _mm512_permutex2var_epi32(mul_l, perm_const, mul_h);
	const __m512i bcst_mix		= _mm512_mask_blend_epi32(0xff00, bcst_h, bcst_l);
	const __m512i temp2			= _mm512_srli_epi32(_mm512_sub_epi32(bcst_mix, dwords), 1);
	const __m512i div10pow		= _mm512_srlv_epi32(_mm512_add_epi32(temp2, dwords), srlv_const);

	const __m512i rotated		= _mm512_mask_alignr_epi32(bcst_h, 0xff7f, bcst_l, div10pow, 1);
    //mullo = better throughput
	const __m512i mul10			= _mm512_mullo_epi32(div10pow, _mm512_set1_epi32(10));
    //add = better latency
	//const __m512i mul10			= _mm512_add_epi32(_mm512_slli_epi32(div10pow, 3), _mm512_add_epi32(div10pow, div10pow));
	const __m512i diff			= _mm512_sub_epi32(_mm512_add_epi32(rotated, _mm512_set1_epi32('0')), mul10);
	_mm512_mask_cvtepi32_storeu_epi8(out, 0xffff, diff);
}

void to_string_avx512ifma_intrin(uint64_t n, char *out) {
	uint64_t n_15_08			= 0;
								  _mulx_u64(n, 0xabcc77118461cefd, &n_15_08);
						n_15_08	>>= 0x1a;									//n / 10^8
	const uint64_t n_07_00		= n - (n_15_08 * u64_10pow(8));				//n % 10^8
	const __m512i bcstq_h		= _mm512_set1_epi64(n_15_08);
	const __m512i bcstq_l		= _mm512_set1_epi64(n_07_00);
 	const __m512i zmmzero		= _mm512_castsi128_si512(_mm_cvtsi64_si128(0x1A1A400)); //8th digit bias
 	const __m512i zmmTen		= _mm512_set1_epi64(10);
 	const __m512i asciiZero		= _mm512_set1_epi64('0');

	//const __m512i ifma_const	= _mm512_set_epi64(divconst52(u64_10pow(1)), divconst52(u64_10pow(2)), divconst52(u64_10pow(3)), divconst52(u64_10pow(4)), divconst52(u64_10pow(5)), divconst52(u64_10pow(6)), divconst52(u64_10pow(7)), divconst52(u64_10pow(8)) - 1);
	const __m512i ifma_const	= _mm512_setr_epi64(0x00000000002af31dc, 0x0000000001ad7f29b, 0x0000000010c6f7a0c, 0x00000000a7c5ac472, 0x000000068db8bac72, 0x0000004189374bc6b, 0x0000028f5c28f5c29, 0x0000199999999999a);
	const __m512i permb_const	= _mm512_castsi128_si512(_mm_set_epi8(0x78, 0x70, 0x68, 0x60, 0x58, 0x50, 0x48, 0x40, 0x38, 0x30, 0x28, 0x20, 0x18, 0x10, 0x08, 0x00));

	const __m512i lowbits_h		= _mm512_madd52lo_epu64(zmmzero, bcstq_h, ifma_const);
	const __m512i lowbits_l		= _mm512_madd52lo_epu64(zmmzero, bcstq_l, ifma_const);
	const __m512i highbits_h	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_h);
	const __m512i highbits_l	= _mm512_madd52hi_epu64(asciiZero, zmmTen, lowbits_l);
	const __m128i digits_15_0	= _mm512_castsi512_si128(_mm512_permutex2var_epi8(highbits_h, permb_const, highbits_l));
	_mm_storeu_si128((__m128i *)out, digits_15_0);
}

//reference to_string method from
//https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/blob/master/2021/11/17/convert.cpp
void to_string_avx2(uint64_t v, char *out) {
 
  // begin: copy of to_string_sse2

  // v is 16-digit number = abcdefghijklmnop
  const __m128i div_10000 = _mm_set1_epi32(0xd1b71759);
  const __m128i mul_10000 = _mm_set1_epi32(10000);
  const int div_10000_shift = 45;

  // can't be easliy done in SSE
  const uint32_t a = v / 100000000; // 8-digit number: abcdefgh
  const uint32_t b = v % 100000000; // 8-digit number: ijklmnop

  //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
  // x            = [       0       |      ijklmnop |       0       | abcdefgh  ]
  __m128i x = _mm_set_epi64x(b, a);

  // x div 10^4   = [       0       |          ijkl |       0       | abcd ]
  __m128i x_div_10000;
  x_div_10000 = _mm_mul_epu32(x, div_10000);
  x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

  // x mod 10^4   = [       0       |          mnop |       0       | efgh ]
  __m128i x_mod_10000;
  x_mod_10000 = _mm_mul_epu32(x_div_10000, mul_10000);
  x_mod_10000 = _mm_sub_epi32(x, x_mod_10000);

  // y            = [          mnop |          ijkl |          efgh | abcd ]
  __m128i y = _mm_or_si128(x_div_10000, _mm_slli_epi64(x_mod_10000, 32));

  // end of copy, AVX2 code now
#include "AVX512_String_Table.h"

  const __m128i ascii = _mm_i32gather_epi32(reinterpret_cast<int const*>(&bigtable), y, 4);

  _mm_storeu_si128((__m128i *)out, ascii);
}

AVX512_decimalprint_methods<U32_PRINT_PTR> decprints_u32[] = {
	{"_ultoa                        ",	"X64",			_ultoa_wrap,					FEAT_AMD64,			true},
	{"_ultoa_avx512f_asm            ",	"AVX512F",		_ultoa_avx512f_asm,		 		FEAT_AVX512F,		false},
	{"_ultoa_avx512f_intrin         ",	"AVX512F",		_ultoa_avx512f_intrin,			FEAT_AVX512F,		false},
	{"_ultoa_avx512ifma_asm         ",	"AVX512IFMA",	_ultoa_avx512ifma_asm,			FEAT_AVX512IFMA,	false},
	{"_ultoa_avx512ifma_intrin      ",	"AVX512IFMA",	_ultoa_avx512ifma_intrin,		FEAT_AVX512IFMA,	false},
};

AVX512_decimalprint_methods<S32_PRINT_PTR> decprints_s32[] = {
	{"_ltoa                         ",	"X64",			_ltoa_wrap,						FEAT_AMD64,			true},
	{"_ltoa_avx512f_asm             ",	"AVX512F",		_ltoa_avx512f_asm,				FEAT_AVX512F,		false},
	{"_ltoa_avx512f_intrin          ",	"AVX512F",		_ltoa_avx512f_intrin,			FEAT_AVX512F,		false},
	{"_ltoa_avx512ifma_asm          ",	"AVX512IFMA",	_ltoa_avx512ifma_asm,			FEAT_AVX512IFMA,	false},
	{"_ltoa_avx512ifma_intrin       ",	"AVX512IFMA",	_ltoa_avx512ifma_intrin,		FEAT_AVX512IFMA,	false},
};

AVX512_decimalprint_methods<U64_PRINT_PTR> decprints_u64[] = {
	{"_ui64toa                      ",	"X64",			_ui64toa_wrap,					FEAT_AMD64,			true},
	{"_ui64toa_avx512f_asm          ",	"AVX512F",		_ui64toa_avx512f_asm,			FEAT_AVX512F,		false},
	{"_ui64toa_avx512f_intrin       ",	"AVX512F",		_ui64toa_avx512f_intrin,		FEAT_AVX512F,		false},
	{"_ui64toa_avx512ifma_asm       ",	"AVX512IFMA",	_ui64toa_avx512ifma_asm,		FEAT_AVX512IFMA,	false},
	{"_ui64toa_avx512ifma_intrin    ",	"AVX512IFMA",	_ui64toa_avx512ifma_intrin,		FEAT_AVX512IFMA,	false},
};

AVX512_decimalprint_methods<S64_PRINT_PTR> decprints_s64[] = {
	{"_i64toa                       ",	"X64",			_i64toa_wrap,					FEAT_AMD64,			true},
	{"_i64toa_avx512f_asm           ",	"AVX512F",		_i64toa_avx512f_asm,			FEAT_AVX512F,		false},
	{"_i64toa_avx512f_intrin        ",	"AVX512F",		_i64toa_avx512f_intrin,			FEAT_AVX512F,		false},
	{"_i64toa_avx512ifma_asm        ",	"AVX512IFMA",	_i64toa_avx512ifma_asm,			FEAT_AVX512IFMA,	false},
	{"_i64toa_avx512ifma_intrin     ",	"AVX512IFMA",	_i64toa_avx512ifma_intrin,		FEAT_AVX512IFMA,	false},
};

AVX512_decimalprint_methods<U64_PRINT_PTR>  decprints2_u64[] = {
	{"to_string_avx2                ",	"X64",			to_string_avx2,					FEAT_AMD64,			true},
	{"to_string_avx512f_intrin      ",	"AVX512F",		to_string_avx512f_intrin,		FEAT_AVX512F,		false},
	{"to_string_avx512f_asm         ",	"AVX512F",		to_string_avx512f_asm,			FEAT_AVX512F,		false},
	{"to_string_avx512ifma_asm      ",	"AVX512IFMA",	to_string_avx512ifma_asm,		FEAT_AVX512IFMA,	false},
	{"to_string_avx512ifma_intrin   ",	"AVX512IFMA",	to_string_avx512ifma_intrin,	FEAT_AVX512IFMA,	false},
};


#if defined (USE_LIBDIVIDE)
void ConstGen(void) {
	libdivide_u32_t ldv_u32;
	libdivide_s32_t ldv_s32;
	libdivide_u64_t ldv_u64;
	libdivide_s64_t ldv_s64;

	libdivide_u32_branchfree_t ldvbf_u32;
	libdivide_s32_branchfree_t ldvbf_s32;
	libdivide_u64_branchfree_t ldvbf_u64;
	libdivide_s64_branchfree_t ldvbf_s64;

	for (uint32_t d = 10, i = 1; d <= 1000000000; d *= 10, i++) {
		ldvbf_u32	= libdivide_u32_branchfree_gen(d);
		ldv_u32		= libdivide_u32_gen(d);
		ldvbf_s32	= libdivide_s32_branchfree_gen(d);
		ldv_s32		= libdivide_s32_gen(d);
		std::cout <<                dec << setfill(' ') << setw(2)  << i;
		std::cout <<  "|"        << dec << setfill(' ') << setw(10) << d;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldvbf_u32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_u32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldv_u32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_u32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldvbf_s32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_s32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldv_s32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_s32.more << endl;
	}
	for (uint32_t d = 5, i = 1; d <= 100000000; d *= 5, i++) {
		ldvbf_u32	= libdivide_u32_branchfree_gen(d);
		ldv_u32		= libdivide_u32_gen(d);
		ldvbf_s32	= libdivide_s32_branchfree_gen(d);
		ldv_s32		= libdivide_s32_gen(d);
		std::cout <<                dec << setfill(' ') << setw(2)  << i;
		std::cout <<  "|"        << dec << setfill(' ') << setw(10) << d;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldvbf_u32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_u32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldv_u32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_u32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldvbf_s32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_s32.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(8)  << ldv_s32.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_s32.more << endl;
	}
	for (uint64_t d = 10, i = 1; d < 10000000000000000000; d *= 10, i++) {
		ldvbf_u64	= libdivide_u64_branchfree_gen(d);
		ldv_u64		= libdivide_u64_gen(d);
		ldvbf_s64	= libdivide_s64_branchfree_gen(d);
		ldv_s64		= libdivide_s64_gen(d);
		std::cout <<                dec << setfill(' ') << setw(2)  << i;
		std::cout << "|"         << dec << setfill(' ') << setw(20) << d;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(16) << ldvbf_u64.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_u64.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(16) << ldv_u64.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_u64.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(16) << ldvbf_s64.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldvbf_s64.more;
		std::cout << "|magic:0x" << hex << setfill('0') << setw(16) << ldv_s64.magic;
		std::cout << " more:0x"  << hex << setfill('0') << setw(2)  << (int)ldv_s64.more << endl;
	}
}
//Output:
//; 1|        10|magic:0x9999999a more:0x03|magic:0xcccccccd more:0x03|magic:0xcccccccd more:0x43|magic:0x66666667 more:0x02
//; 2|       100|magic:0x47ae147b more:0x06|magic:0xa3d70a3e more:0x06|magic:0xa3d70a3e more:0x46|magic:0x51eb851f more:0x05
//; 3|      1000|magic:0x0624dd30 more:0x09|magic:0x83126e98 more:0x09|magic:0x83126e98 more:0x49|magic:0x4189374c more:0x08
//; 4|     10000|magic:0xa36e2eb2 more:0x0d|magic:0xd1b71759 more:0x0d|magic:0xd1b71759 more:0x4d|magic:0x68db8bad more:0x0c
//; 5|    100000|magic:0x4f8b588f more:0x10|magic:0x4f8b588f more:0x50|magic:0xa7c5ac48 more:0x50|magic:0x53e2d624 more:0x0f
//; 6|   1000000|magic:0x0c6f7a0c more:0x13|magic:0x8637bd06 more:0x13|magic:0x8637bd06 more:0x53|magic:0x431bde83 more:0x12
//; 7|  10000000|magic:0xad7f29ac more:0x17|magic:0xd6bf94d6 more:0x17|magic:0xd6bf94d6 more:0x57|magic:0x6b5fca6b more:0x16
//; 8| 100000000|magic:0x5798ee24 more:0x1a|magic:0xabcc7712 more:0x1a|magic:0xabcc7712 more:0x5a|magic:0x55e63b89 more:0x19
//; 9|1000000000|magic:0x12e0be83 more:0x1d|magic:0x12e0be83 more:0x5d|magic:0x89705f42 more:0x5d|magic:0x44b82fa1 more:0x1c
//; 1|                  10|magic:0x999999999999999a more:0x03|magic:0xcccccccccccccccd more:0x03|magic:0xcccccccccccccccd more:0x43|magic:0x6666666666666667 more:0x02
//; 2|                 100|magic:0x47ae147ae147ae15 more:0x06|magic:0x47ae147ae147ae15 more:0x46|magic:0xa3d70a3d70a3d70b more:0x46|magic:0xa3d70a3d70a3d70b more:0x46
//; 3|                1000|magic:0x0624dd2f1a9fbe77 more:0x09|magic:0x0624dd2f1a9fbe77 more:0x49|magic:0x83126e978d4fdf3c more:0x49|magic:0x4189374bc6a7ef9e more:0x08
//; 4|               10000|magic:0xa36e2eb1c432ca58 more:0x0d|magic:0xd1b71758e219652c more:0x0d|magic:0xd1b71758e219652c more:0x4d|magic:0x68db8bac710cb296 more:0x0c
//; 5|              100000|magic:0x4f8b588e368f0847 more:0x10|magic:0x4f8b588e368f0847 more:0x50|magic:0xa7c5ac471b478424 more:0x50|magic:0x53e2d6238da3c212 more:0x0f
//; 6|             1000000|magic:0x0c6f7a0b5ed8d36c more:0x13|magic:0x8637bd05af6c69b6 more:0x13|magic:0x8637bd05af6c69b6 more:0x53|magic:0x431bde82d7b634db more:0x12
//; 7|            10000000|magic:0xad7f29abcaf48579 more:0x17|magic:0xd6bf94d5e57a42bd more:0x17|magic:0xd6bf94d5e57a42bd more:0x57|magic:0xd6bf94d5e57a42bd more:0x57
//; 8|           100000000|magic:0x5798ee2308c39dfa more:0x1a|magic:0xabcc77118461cefd more:0x1a|magic:0xabcc77118461cefd more:0x5a|magic:0x55e63b88c230e77f more:0x19
//; 9|          1000000000|magic:0x12e0be826d694b2f more:0x1d|magic:0x12e0be826d694b2f more:0x5d|magic:0x89705f4136b4a598 more:0x5d|magic:0x44b82fa09b5a52cc more:0x1c
//;10|         10000000000|magic:0xb7cdfd9d7bdbab7e more:0x21|magic:0xdbe6fecebdedd5bf more:0x21|magic:0xdbe6fecebdedd5bf more:0x61|magic:0x6df37f675ef6eae0 more:0x20
//;11|        100000000000|magic:0x5fd7fe17964955fe more:0x24|magic:0xafebff0bcb24aaff more:0x24|magic:0xafebff0bcb24aaff more:0x64|magic:0x57f5ff85e5925580 more:0x23
//;12|       1000000000000|magic:0x19799812dea11198 more:0x27|magic:0x8cbccc096f5088cc more:0x27|magic:0x8cbccc096f5088cc more:0x67|magic:0x465e6604b7a84466 more:0x26
//;13|      10000000000000|magic:0xc25c268497681c27 more:0x2b|magic:0xe12e13424bb40e14 more:0x2b|magic:0xe12e13424bb40e14 more:0x6b|magic:0x709709a125da070a more:0x2a
//;14|     100000000000000|magic:0x6849b86a12b9b01f more:0x2e|magic:0xb424dc35095cd810 more:0x2e|magic:0xb424dc35095cd810 more:0x6e|magic:0x5a126e1a84ae6c08 more:0x2d
//;15|    1000000000000000|magic:0x203af9ee756159b3 more:0x31|magic:0x203af9ee756159b3 more:0x71|magic:0x901d7cf73ab0acda more:0x71|magic:0x480ebe7b9d58566d more:0x30
//;16|   10000000000000000|magic:0xcd2b297d889bc2b7 more:0x35|magic:0xe69594bec44de15c more:0x35|magic:0xe69594bec44de15c more:0x75|magic:0x734aca5f6226f0ae more:0x34
//;17|  100000000000000000|magic:0x70ef54646d496893 more:0x38|magic:0x70ef54646d496893 more:0x78|magic:0xb877aa3236a4b44a more:0x78|magic:0x5c3bd5191b525a25 more:0x37
//;18| 1000000000000000000|magic:0x2725dd1d243aba0f more:0x3b|magic:0x2725dd1d243aba0f more:0x7b|magic:0x9392ee8e921d5d08 more:0x7b|magic:0x49c97747490eae84 more:0x3a
#endif

//// c = ceil ( (1 < <64) / d ) ; we take L = N
//// fastmod computes (n mod d) given precomputed c
//uint32_t fastmod( uint64_t n /* , uint64_t c */, uint32_t d) {
//	uint64_t c = UINT64_C(0xFFFFFFFFFFFFFFFF) / d + 1;
//	uint64_t lowbits = c * n;
//	unsigned long long h64;
//#ifdef _MSC_VER
//	_umul128(lowbits, d, &h64);
//	return (uint32_t)h64;
//#else
//	return (( __uint128_t ) lowbits * d) >> 64;
//#endif
//}

template <typename T_FUNC, typename T_DATA, int N>
bool print_check(AVX512_decimalprint_methods<T_FUNC> (&table)[N], T_DATA data, bool chop = false, bool print = false) {
	T_DATA testCases[]                   = {
			0,
			(T_DATA)-1,
			1,
			9,
			10,
			99,
			100,
			999,
			1000,
			9999,
			10000,
			99999,
			100000,
			999999,
			1000000,
			9999999,
			10000000,
			10000001,
			19999999,
			20000000,
			29999999,
			30000000,
			39999999,
			40000000,
			49999999,
			50000000,
			59999999,
			60000000,
			69999999,
			70000000,
			79999999,
			80000000,
			89999999,
			90000000,
			99999998,
			99999999,
			100000000,
			199999999,
			200000000,
			299999999,
			300000000,
			399999999,
			400000000,
			499999999,
			500000000,
			599999999,
			600000000,
			699999999,
			700000000,
			799999999,
			800000000,
			899999999,
			900000000,
			999999917,
			999999918,
			999999999,
			(T_DATA)1000000000,
			(T_DATA)1000000001,
			(T_DATA)1000000005,
			(T_DATA)1000000008,
			(T_DATA)1000000010,
			(T_DATA)9999999999,
			(T_DATA)LONG_MAX,
			(T_DATA)ULONG_MAX,
			(T_DATA)LLONG_MIN,
			(T_DATA)LLONG_MAX,
			(T_DATA)ULLONG_MAX,
	};
	char buff_reference[AVX512_STR_BUFF] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char buff_result[AVX512_STR_BUFF]    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	T_DATA testCase;
	for (int tests = 0; tests < 100; tests++) {
	//for (int testCase = 0; testCase < 1000000000; testCase++) {
		if (tests < sizeof(testCases) / sizeof(T_DATA)) 
			testCase = testCases[tests];
		else
			random_wrap((T_DATA*)&testCase);
		if (chop) {
			testCase &= testCase % 10000000000000000;
		}
		for (int b = 0; b < (sizeof(table) / sizeof(AVX512_decimalprint_methods<T_FUNC>)); b++) {
			if (cpu_props.IsFeat(table[b].feats)) {
				if (table[b].refFlag) {
					(table[b].func)(testCase, buff_reference);
					if (print) {
						std::cout << dec << setw(sizeof(T_DATA)*2 + 4) << testCase << " ";
					}
			} else {
					memset(buff_result, 0, AVX512_STR_BUFF);
					(table[b].func)(testCase, buff_result);
					if (strcmp(buff_reference, buff_result) == 0) {
						if (print) {
							std::cout << ' ' << b;
							std::cout << ":OK.      ";
						}
					} else {
						if (print) {
							std::cout << table[b].name;
							std::cout << dec << setw(sizeof(T_DATA)*2 + 2) << testCase << " ";
							std::cout << ":Error!!! ";
							std::cout << buff_result;
						}
						return false;
					}
				}
			}
		}
		if (print) {
			std::cout << endl;
		}
	}
	return true;
}

template <typename T_FUNC, typename T_DATA, int N>
void print_test(AVX512_decimalprint_methods<T_FUNC> (&table)[N], T_DATA data, bool zmmMode = false) {
	char buff_result[AVX512_STR_BUFF]	= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned __int64 refTime			= 0;
	unsigned __int64 bestTime			= ULLONG_MAX;
	unsigned __int64 start				= 0; 
	unsigned __int64 end				= 0;
	int				bestmethod			= 0;
#if defined (_DEBUG)
	const unsigned int starti			= 0xffff0000;
	const unsigned int endi				= 0xffffffff;
#else
	const unsigned int starti			= 0xff800000;
	const unsigned int endi				= 0xffffffff;
#endif
	__m512i noopt;
	std::cout << "Throughput Test ";
	if (zmmMode)
		std::cout << "(zmmMode=" << zmmMode << ')';
	std::cout << endl;
	for (int b = 0; b < (sizeof(table) / sizeof(AVX512_decimalprint_methods<T_FUNC>)); b++) {
		if (cpu_props.IsFeat(table[b].feats)) {
			if (table[b].refFlag) {
				start = serialized_tsc();
				for (unsigned int i = starti; i < endi; i++) {
					if (zmmMode)
						noopt = _mm512_xor_epi64(_mm512_undefined_epi32(), _mm512_undefined_epi32());
					(table[b].func)(i, buff_result);
				}
				refTime = serialized_tsc() - start;
				std::cout << setw(2) << b << ':' << table[b].name << dec << setfill(' ') << setw(20) << refTime << " Baseline" << endl;
			} else {
				start = serialized_tsc();
				for (unsigned int i = starti; i < endi; i++) {
					(table[b].func)(i, buff_result);
				}
				end = serialized_tsc() - start;
				std::cout << setw(2) << b << ':' << table[b].name << dec << setw(20) << end << " Speed-up:" << (double)refTime / (double)end << endl;
				if (bestTime > end) {
					bestTime = end;
					bestmethod = b;
				}
			}
		}
	}
	std::cout << "------Best Throughput:" << endl;
	std::cout << setw(2) << bestmethod << ':' << table[bestmethod].name << dec << setw(20) << bestTime << " Speed-up:" << (double)refTime / (double)bestTime << endl;
	std::cout << "----------------------" << endl; 

	std::cout << "Latency Test ";
	if (zmmMode)
		std::cout << "(zmmMode=" << zmmMode << ')';
	std::cout << endl;

	bestTime = ULLONG_MAX;
	for (int b = 0; b < (sizeof(table) / sizeof(AVX512_decimalprint_methods<T_FUNC>)); b++) {
		if (cpu_props.IsFeat(table[b].feats)) {
			if (table[b].refFlag) {
				start = serialized_tsc();
				for (unsigned int i = starti; i < endi; i++) {
					if (zmmMode)
						noopt = _mm512_xor_epi64(_mm512_undefined_epi32(), _mm512_undefined_epi32());
					(table[b].func)(*(unsigned int *)buff_result, buff_result);
				}
				refTime = serialized_tsc() - start;
				std::cout << setw(2) << b << ':' << table[b].name << dec << setw(20) << refTime << " Baseline" << endl;
			} else {
				start = serialized_tsc();
				for (unsigned int i = starti; i < endi; i++) {
					(table[b].func)(*(unsigned int *)buff_result, buff_result);
				}
				end = serialized_tsc() - start;
				std::cout << setw(2) << b << ':' << table[b].name << dec << setw(20) << end << " Speed-up:" << (double)refTime / (double)end << endl;
				if (bestTime > end) {
					bestTime = end;
					bestmethod = b;
				}
			}
		}
	}
	std::cout << "------Best Latency:" << endl; 
	std::cout << setw(2) << bestmethod << ':' << table[bestmethod].name << dec << setw(20) << bestTime << " Speed-up:" << (double)refTime / (double)bestTime << endl;
	std::cout << "-------------------" << endl; 
}

template <typename T_DATA>
void dechex_cout(const char * str, T_DATA val) {
	cout << str << dec << setw(20) << setfill(' ') << val << hex << '(' << setw(sizeof(T_DATA) * 2) << setfill('0') << val << ')' << setfill(' ') << endl;
}

void avx512ifma_print_test(void) {
	for (uint64_t p = 1ULL; p < 9; p++) {
		uint64_t pow = u64_10pow(p);
		for (uint64_t n = pow, digit = 1; n < (10 * pow); n += pow, digit++) {
			const __m512i xmm_n		= _mm512_set_epi64(n - 1, n, n - 1, n, n - 1, n, n - 1, n);
			const __m512i ifma_const= _mm512_setr_epi64(divconst52(u64_10pow(p + 1)) - 1, divconst52(u64_10pow(p + 1)) - 1, divconst52(u64_10pow(p + 1)) - 1, divconst52(u64_10pow(p + 1)) - 1, divconst52(u64_10pow(p + 1)), divconst52(u64_10pow(p + 1)), 0, 0);
			const __m512i corr_const= _mm512_setr_epi64(0x1A1A400, 0x1A1A400, 0, 0, 0, 0, 0, 0);

			const __m512i lowbits	= _mm512_madd52lo_epu64(corr_const, xmm_n, ifma_const);
			const __m512i highbits	= _mm512_madd52hi_epu64(_mm512_setzero_si512(), lowbits, _mm512_set1_epi64(10));
			const __m512i highbits2	= _mm512_madd52lo_epu64(_mm512_setzero_si512(), lowbits, _mm512_set1_epi64(10));

			const uint64_t res		= _mm_cvtsi128_si64(_mm512_castsi512_si128(highbits));

			if (highbits.m512i_u64[4] - 1 == highbits.m512i_u64[5]) {
				cout << endl;
			} else {
				dechex_cout("p            = ", p);
				dechex_cout("n            = ", n);
				dechex_cout("n[0]         = ", xmm_n.m512i_u64[0]);
				dechex_cout("n[1]         = ", xmm_n.m512i_u64[1]);
				dechex_cout("n[2]         = ", xmm_n.m512i_u64[2]);
				dechex_cout("n[3]         = ", xmm_n.m512i_u64[3]);
				dechex_cout("n[4]         = ", xmm_n.m512i_u64[4]);
				dechex_cout("n[5]         = ", xmm_n.m512i_u64[5]);
				dechex_cout("ifma[0]      = ", ifma_const.m512i_u64[0]);
				dechex_cout("ifma[1]      = ", ifma_const.m512i_u64[1]);
				dechex_cout("ifma[2]      = ", ifma_const.m512i_u64[2]);
				dechex_cout("ifma[3]      = ", ifma_const.m512i_u64[3]);
				dechex_cout("ifma[4]      = ", ifma_const.m512i_u64[4]);
				dechex_cout("ifma[5]      = ", ifma_const.m512i_u64[5]);
				dechex_cout("lowbits[0]   = ", lowbits.m512i_u64[0]);
				dechex_cout("lowbits[1]   = ", lowbits.m512i_u64[1]);
				dechex_cout("lowbits[2]   = ", lowbits.m512i_u64[2]);
				dechex_cout("lowbits[3]   = ", lowbits.m512i_u64[3]);
				dechex_cout("lowbits[4]   = ", lowbits.m512i_u64[4]);
				dechex_cout("lowbits[5]   = ", lowbits.m512i_u64[5]);
				dechex_cout("highbits[0]  = ", highbits.m512i_u64[0]);
				dechex_cout("highbits[1]  = ", highbits.m512i_u64[1]);
				dechex_cout("highbits[2]  = ", highbits.m512i_u64[2]);
				dechex_cout("highbits[3]  = ", highbits.m512i_u64[3]);
				dechex_cout("highbits[4]  = ", highbits.m512i_u64[4]);
				dechex_cout("highbits[5]  = ", highbits.m512i_u64[5]);
				dechex_cout("highbits2[0] = ", highbits2.m512i_u64[0]);
				dechex_cout("highbits2[1] = ", highbits2.m512i_u64[1]);
				dechex_cout("highbits2[2] = ", highbits2.m512i_u64[2]);
				dechex_cout("highbits2[3] = ", highbits2.m512i_u64[3]);
				dechex_cout("highbits2[4] = ", highbits2.m512i_u64[4]);
				dechex_cout("highbits2[5] = ", highbits2.m512i_u64[5]);
				dechex_cout("diff         = ", highbits2.m512i_u64[2] - highbits2.m512i_u64[3]);
				dechex_cout("highbits     = ", res);
				cout << "====================" << endl;
			}
		}
	}
}

void avx512f_print_test(void) {
	for (uint32_t p = 0; p < 5; p++) {
		uint64_t pow = u64_10pow(p);
		for (uint64_t n = pow, digit = 1; n < (10 * pow); n += pow, digit++) {
			const __m256i xmm_n		= _mm256_set_epi64x(n - 1, n, n - 1, n);
			const __m256i mul_const= _mm256_set_epi64x(divconst32(u32_10pow(p + 1)) - 1, divconst32(u32_10pow(p + 1)) - 1, divconst32(u32_10pow(p + 1)), divconst32(u32_10pow(p + 1)));

			const __m256i lowbits	= _mm256_mul_epu32(xmm_n, mul_const);
			const __m256i highbits	= _mm256_mul_epu32(lowbits, _mm256_set1_epi64x(10));
			const __m256i highbits2	= _mm256_srli_epi64(highbits, 32);

			const uint64_t res		= _mm_cvtsi128_si64(_mm256_castsi256_si128(highbits));

			//if (highbits2.m256i_u64[0] - 1 == highbits2.m256i_u64[1]) {
			//	cout << endl;
			//} else {
				dechex_cout("p            = ", p);
				dechex_cout("n            = ", n);
				dechex_cout("n[0]         = ", xmm_n.m256i_u64[0]);
				dechex_cout("n[1]         = ", xmm_n.m256i_u64[1]);
				dechex_cout("n[2]         = ", xmm_n.m256i_u64[2]);
				dechex_cout("n[3]         = ", xmm_n.m256i_u64[3]);
				dechex_cout("mul[0]       = ", mul_const.m256i_u64[0]);
				dechex_cout("mul[1]       = ", mul_const.m256i_u64[1]);
				dechex_cout("mul[2]       = ", mul_const.m256i_u64[2]);
				dechex_cout("mul[3]       = ", mul_const.m256i_u64[3]);
				dechex_cout("lowbits[0]   = ", lowbits.m256i_u64[0]);
				dechex_cout("lowbits[1]   = ", lowbits.m256i_u64[1]);
				dechex_cout("lowbits[2]   = ", lowbits.m256i_u64[2]);
				dechex_cout("lowbits[3]   = ", lowbits.m256i_u64[3]);
				dechex_cout("highbits[0]  = ", highbits.m256i_u64[0]);
				dechex_cout("highbits[1]  = ", highbits.m256i_u64[1]);
				dechex_cout("highbits[2]  = ", highbits.m256i_u64[2]);
				dechex_cout("highbits[3]  = ", highbits.m256i_u64[3]);
				dechex_cout("highbits2[0] = ", highbits2.m256i_u64[0]);
				dechex_cout("highbits2[1] = ", highbits2.m256i_u64[1]);
				dechex_cout("highbits2[2] = ", highbits2.m256i_u64[2]);
				dechex_cout("highbits2[3] = ", highbits2.m256i_u64[3]);
				dechex_cout("diff         = ", highbits2.m256i_u64[2] - highbits2.m256i_u64[3]);
				dechex_cout("highbit s    = ", res);
				cout << "====================" << endl;
			//}
		}
	}
}

void AVX512_DecimalPrint_Test(void) {
	SetThread(2);

	//avx512ifma_print_test();
	//avx512f_print_test();
#if defined (USE_LIBDIVIDE)
	ConstGen();
#endif
	uint32_t	u32	= 0;
	int32_t		s32	= 0;
	uint64_t	u64	= 0;
	int64_t		s64	= 0;

	if (print_check(decprints_u32, u32, false)) {
		cout << "_ultoa OK." <<  endl;
		print_test(decprints_u32, u32);
		//print_test(decprints_u32, u32, true);
	} else {
		print_check(decprints_u32, u32, false, true);
	}
	std::cout << "===================" << endl; 
	if (print_check(decprints_s32, s32, false)) {
		cout << "_ltoa OK." <<  endl;
		print_test(decprints_s32, s32);
		//print_test(decprints_s32, s32, true);
	} else {
		print_check(decprints_s32, s32, false, true);
	}
	std::cout << "===================" << endl; 
	if (print_check(decprints_u64, u64, false)) {
		cout << "_ui64toa OK." <<  endl;
		print_test(decprints_u64, u64);
		//print_test(decprints_u64, u64, true);
	} else {
		print_check(decprints_u64, u64, false, true);
	}
	std::cout << "===================" << endl; 
	if (print_check(decprints_s64, s64, false)) {
		cout << "_i64toa OK." <<  endl;
		print_test(decprints_s64, s64);
		//print_test(decprints_s64, s64, true);
	} else {
		print_check(decprints_s64, s64, false, true);
	}
	std::cout << "===================" << endl; 
	if (print_check(decprints2_u64, u64, true)) {
		cout << "to_string OK." <<  endl;
		print_test(decprints2_u64, u64);
		//print_test(decprints2_u64, u64, true);
	} else {
		print_check(decprints2_u64, u64, true, true);
	}

}
