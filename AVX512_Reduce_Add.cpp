#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

//credit: @geofflangdale https://twitter.com/geofflangdale/status/1609575574946865154

uint32_t _mm512_reduce2_add_epu8(__m512i z) {
	__m128i permb_collect	= _mm_setr_epi64x(0x3830282018100800, 0x3931292119110901);
	__m512i sad				= _mm512_sad_epu8(_mm512_setzero_si512(), z);
	__m128i permb			= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(permb_collect), sad));
	__m128i sad2			= _mm_sad_epu8(_mm_setzero_si128(), permb);
	return _mm_cvtsi128_si32(_mm_add_epi32(sad2, _mm_srli_si128(sad2, 7)));
}

uint32_t _mm512_reduce2_add_epu16(__m512i z) {
	__m128i pshufb_collect	= _mm_setr_epi32(0x06040200, 0x0e0c0a08, 0x07050301, 0x0f0d0b09);
	__m512i pshufb			= _mm512_shuffle_epi8(z, _mm512_broadcast_i32x4(pshufb_collect));
	__m512i sad				= _mm512_sad_epu8(_mm512_setzero_si512(), pshufb);
	__m128i permb_collect	= _mm_setr_epi32(0x30201000, 0x31211101, 0x38281808, 0x39291909);
	__m128i permb			= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(permb_collect), sad));
	__m128i dbsad			= _mm_maskz_dbsad_epu8(0x55, permb, _mm_setzero_si128(), 0);
	__m128i add				= _mm_add_epi32(_mm_srli_epi64(dbsad, 24), dbsad);
	return _mm_cvtsi128_si32(_mm_add_epi32(add, _mm_srli_si128(add, 7)));
}

uint64_t _mm512_reduce2_add_epu32(__m512i z) {
	__m128i transpose_4x4	= _mm_setr_epi32(0x0c080400, 0x0d090501, 0x0e0a0602, 0x0f0b0703);
	__m512i transpose		= _mm512_shuffle_epi8(z, _mm512_broadcast_i32x4(transpose_4x4));
	__m512i dbsad			= _mm512_maskz_dbsad_epu8(0x55555555, transpose, _mm512_setzero_si512(), 0);
	__m512i permb_collect	= _mm512_setr_epi32(0x30201000, 0x3f3f3f3f, 0x31211101, 0x34241404, 0x35251505, 0x38281808, 0x39291909, 0x3c2c1c0c, 0x3d2d1d0d, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f);
	__m512i permb			= _mm512_permutexvar_epi8(permb_collect, dbsad);
	__m512i sad				= _mm512_sad_epu8(permb, _mm512_setzero_si512());
	__m128i permb2			= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(_mm_setr_epi64x(0x3f3f3f2018100800, 0x3f3f21191109013f)), sad));
	return _mm_cvtsi128_si64(_mm_add_epi64(permb2, _mm_unpackhi_epi64(permb2, permb2)));
}

uint64_t _mm512_reduce2_add_epu64(__m512i z) {
	__m512i transpose_8x8	= _mm512_setr_epi64(0x3830282018100800, 0x3931292119110901, 0x3a322a221a120a02, 0x3b332b231b130b03, 0x3c342c241c140c04, 0x3d352d251d150d05, 0x3e362e261e160e06, 0x3f372f271f170f07);
	__m512i transpose		= _mm512_permutexvar_epi8(transpose_8x8, z);
	__m512i sad				= _mm512_sad_epu8(transpose, _mm512_setzero_si512());
	__m128i collect			= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(_mm_setr_epi64x(0x3830282018100800, 0x312921191109013f)), sad));
	return _mm_cvtsi128_si64(_mm_add_epi64(collect, _mm_unpackhi_epi64(collect, collect)));
}

uint64_t _mm512_reduce2_add_epu128(__m512i z, uint64_t* hi) {
	__m512i transpose_8x8	= _mm512_setr_epi64(0x3830282018100800, 0x3931292119110901, 0x3a322a221a120a02, 0x3b332b231b130b03, 0x3c342c241c140c04, 0x3d352d251d150d05, 0x3e362e261e160e06, 0x3f372f271f170f07);
	__m512i transpose		= _mm512_permutexvar_epi8(transpose_8x8, z);
	__m512i sad				= _mm512_sad_epu8(transpose, _mm512_setzero_si512());
	__m128i collect0		= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(_mm_setr_epi64x(0x3830282018100800, 0x3f38302820181008)), sad));
	__m128i collect1		= _mm512_castsi512_si128(_mm512_permutexvar_epi8(_mm512_zextsi128_si512(_mm_setr_epi64x(0x312921191109013f, 0x3931292119110901)), sad));
	__m128i add				= _mm_add_epi64(collect0, collect1);
	*hi						= _mm_extract_epi64(add, 1) >> 56;
	return _mm_cvtsi128_si64(add);
}

void AVX512_Reduce_Add_Demo(void) {
	__m512i u = _mm512_undefined_epi32();

	cout << hex;
	/* Microsoft built-in reduce_add intrinsics */
	//cout  << setw(16) << right << _mm512_reduce_add_epu8(_mm512_set1_epi8(0xFE)) << endl;
	//cout  << setw(16) << right << _mm512_reduce_add_epu16(_mm512_set1_epi16(0xFEDC)) << endl;
	//cout  << setw(16) << right << _mm512_reduce_add_epi32(_mm512_set1_epi32(0xFEDCBA98)) << endl;
	//cout  << setw(16) << right << _mm512_reduce_add_epi64(_mm512_set1_epi64(0xFEDCBA9876543210)) << endl;

	cout  << setw(16) << right << _mm512_reduce2_add_epu8(_mm512_set1_epi8((char)0xFE)) << endl;
	cout  << setw(16) << right << _mm512_reduce2_add_epu16(_mm512_set1_epi16((short)0xFEDC)) << endl;
	cout  << setw(16) << right << _mm512_reduce2_add_epu32(_mm512_set1_epi32(0xFEDCBA98)) << endl;
	cout  << setw(16) << right << _mm512_reduce2_add_epu64(_mm512_set1_epi64(0xFEDCBA9876543210)) << endl;
	
	uint64_t hi, lo = _mm512_reduce2_add_epu128(_mm512_set1_epi64(0xFEDCBA9876543210), &hi);
	cout  << setw(16) << right << hi << ':' << lo << endl;
}