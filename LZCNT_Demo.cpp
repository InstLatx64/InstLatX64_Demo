#include "stdafx.h"
#include "LZCNT_Demo.h"
#include "GFNI_Demo.h"
#include "VBMI2_Demo.h"
/*
VPLZCNTB/W proposal:
- Byte/Word support
- BITALG lzcnt(a) = popcnt(tzmsk(bit_reverse(a)))
- FP16 lzcnt(a) = max(16, 30 - (fp16)a.exp))
- zero case handled
*/

extern CPU_Props cpu_props;

using namespace std;

__m128i __vectorcall _mm_lzcnt_epi8(__m128i a) {
	__m128i u = _mm_undefined_si128();
	__m128i r = _mm_revbit_epi8(a);
	return _mm_popcnt_epi8(_mm_andnot_si128(r, _mm_add_epi8(r, _mm_cmpeq_epi8(u, u))));
}

__m256i __vectorcall _mm256_lzcnt_epi8(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	__m256i r = _mm256_revbit_epi8(a);
	return _mm256_popcnt_epi8(_mm256_andnot_si256(r, _mm256_add_epi8(r, _mm256_cmpeq_epi8(u, u))));
}

__m512i __vectorcall _mm512_lzcnt_epi8(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	__m512i r = _mm512_revbit_epi8(a);
	return _mm512_popcnt_epi8(_mm512_andnot_si512(r, _mm512_add_epi8(r, _mm512_ternarylogic_epi32(u, u, u, 0xff))));
}

__m128i __vectorcall _mm_lzcnt_epi16(__m128i a) {
	__m128i u = _mm_undefined_si128();
	__m128i r = _mm_revbit_epi8(_mm_swaplh_epi8(a));
	return _mm_popcnt_epi16(_mm_andnot_si128(r, _mm_add_epi16(r, _mm_cmpeq_epi16(u, u))));
}

__m256i __vectorcall _mm256_lzcnt_epi16(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	__m256i r = _mm256_revbit_epi8(_mm256_swaplh_epi8(a));
	return _mm256_popcnt_epi16(_mm256_andnot_si256(r,_mm256_add_epi16(r, _mm256_cmpeq_epi16(u, u))));
}

__m512i __vectorcall _mm512_lzcnt_epi16(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	__m512i r = _mm512_revbit_epi8(_mm512_swaplh_epi8(a));
	return _mm512_popcnt_epi16(_mm512_andnot_si512(r, _mm512_add_epi16(r, _mm512_ternarylogic_epi32(u, u, u, 0xff))));
}

__m128i __vectorcall _mm_lzcnt_fp16_epi16(__m128i a) {
	return _mm_min_epi16(_mm_sub_epi16(_mm_set1_epi16(0x1e), _mm_srli_epi16(_mm_cvtepu16_ph(a), 10)), _mm_set1_epi16(0x10));
}

__m256i __vectorcall _mm256_lzcnt_fp16_epi16(__m256i a) {
	return _mm256_min_epi16(_mm256_sub_epi16(_mm256_set1_epi16(0x1e), _mm256_srli_epi16(_mm256_cvtepu16_ph(a), 10)), _mm256_set1_epi16(0x10));
}

__m512i __vectorcall _mm512_lzcnt_fp16_epi16(__m512i a) {
	return _mm512_min_epi16(_mm512_sub_epi16(_mm512_set1_epi16(0x1e), _mm512_srli_epi16(_mm512_cvtepu16_ph(a), 10)), _mm512_set1_epi16(0x10));
}

void LZCNT_Test(void) {
	cout << "--- AVX512_BITALG & AVX512_FP16 SIMD LZCNTB/W ---" << dec << right << endl;
	__m128i x128	= _mm_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768);
	__m256i x256	= _mm256_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768, 0x07f00, 0x07e00, 0x07c00, 0x07800, 0x07000, 0x06000, 0x04000, 0x00000);
	__m512i x512	= _mm512_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768, 0x07f00, 0x07e00, 0x07c00, 0x07800, 0x07000, 0x06000, 0x00000, 0x00000, (short)(1 << 15), 1 << 14, 1 << 13, 1 << 12, 1 << 11, 1 << 10, 1 << 9, 1 << 8, 1 << 7, 1 << 6, 1 << 5, 1 << 4, 1 << 3, 1 << 2, 1 << 1, 1 << 0);

	printRes("x128                         :", x128);
	printRes("_mm_lzcnt_epi8               :", _mm_lzcnt_epi8(x128));
	printRes("_mm_lzcnt_epi8_asm           :", _mm_lzcnt_epi8_asm(x128));
	printRes("_mm_lzcnt_gfni_epi8          :", _mm_lzcnt_gfni_epi8(x128));
	printRes("_mm_lzcnt_gfni_epi8_asm      :", _mm_lzcnt_gfni_epi8_asm(x128));
	printRes("_mm_lzcnt_epi16              :", _mm_lzcnt_epi16(x128));
	printRes("_mm_lzcnt_epi16_asm          :", _mm_lzcnt_epi16_asm(x128));
	if (cpu_props.IsFeat(ISA_AVX512_FP16)) {
		printRes("_mm_lzcnt_fp16_epi16         :", _mm_lzcnt_fp16_epi16(x128));
		printRes("_mm_lzcnt_fp16_epi16_asm     :", _mm_lzcnt_fp16_epi16_asm(x128));
	}

	printRes("x256                         :", x256);
	printRes("_mm256_lzcnt_epi8            :", _mm256_lzcnt_epi8(x256));
	printRes("_mm256_lzcnt_epi8_asm        :", _mm256_lzcnt_epi8_asm(x256));
	printRes("_mm256_lzcnt_gfni_epi8       :", _mm256_lzcnt_gfni_epi8(x256));
	printRes("_mm256_lzcnt_gfni_epi8_asm   :", _mm256_lzcnt_gfni_epi8_asm(x256));
	printRes("_mm256_lzcnt_epi16           :", _mm256_lzcnt_epi16(x256));
	printRes("_mm256_lzcnt_epi16_asm       :", _mm256_lzcnt_epi16_asm(x256));
	if (cpu_props.IsFeat(ISA_AVX512_FP16)) {
		printRes("_mm256_lzcnt_fp16_epi16      :", _mm256_lzcnt_fp16_epi16(x256));
		printRes("_mm256_lzcnt_fp16_epi16_asm  :", _mm256_lzcnt_fp16_epi16_asm(x256));
	}

	printRes("x512                         :", x512);
	printRes("_mm512_lzcnt_epi8            :", _mm512_lzcnt_epi8(x512));
	printRes("_mm512_lzcnt_epi8            :", _mm512_lzcnt_epi8_asm(x512));
	printRes("_mm512_lzcnt_gfni_epi8       :", _mm512_lzcnt_gfni_epi8(x512));
	printRes("_mm512_lzcnt_gfni_epi8       :", _mm512_lzcnt_gfni_epi8_asm(x512));
	printRes("_mm512_lzcnt_epi16           :", _mm512_lzcnt_epi16(x512));
	printRes("_mm512_lzcnt_epi16_asm       :", _mm512_lzcnt_epi16_asm(x512));
	if (cpu_props.IsFeat(ISA_AVX512_FP16)) {
		printRes("_mm512_lzcnt_fp16_epi16      :", _mm512_lzcnt_fp16_epi16(x512));
		printRes("_mm512_lzcnt_fp16_epi16_asm  :", _mm512_lzcnt_fp16_epi16_asm(x512));
	}

	cout << "TSC CLKs:----------------------" << endl;

	cout << "_mm_lzcnt_epi8_asm            :" << (double)_mm_lzcnt_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;
	cout << "_mm_lzcnt_gfni_epi8_asm       :" << (double)_mm_lzcnt_gfni_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;
	cout << "_mm256_lzcnt_epi8_asm         :" << (double)_mm256_lzcnt_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;
	cout << "_mm256_lzcnt_gfni_epi8_asm    :" << (double)_mm256_lzcnt_gfni_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;
	cout << "_mm512_lzcnt_epi8_asm         :" << (double)_mm512_lzcnt_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;
	cout << "_mm512_lzcnt_gfni_epi8_asm    :" << (double)_mm512_lzcnt_gfni_epi8_asm_timed() / (double)LZCNT_REPEATS << endl;

	cout << "_mm_lzcnt_epi16_asm           :" << (double)_mm_lzcnt_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;
	if (cpu_props.IsFeat(ISA_AVX512_FP16))
		cout << "_mm_lzcnt_fp16_epi16_asm      :" << (double)_mm_lzcnt_fp16_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;

	cout << "_mm256_lzcnt_epi16_asm        :" << (double)_mm256_lzcnt_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;
	if (cpu_props.IsFeat(ISA_AVX512_FP16))
		cout << "_mm256_lzcnt_fp16_epi16_asm   :" << (double)_mm256_lzcnt_fp16_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;

	cout << "_mm512_lzcnt_epi16_asm        :" << (double)_mm512_lzcnt_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;
	if (cpu_props.IsFeat(ISA_AVX512_FP16))
		cout << "_mm512_lzcnt_fp16_epi16_asm   :" << (double)_mm512_lzcnt_fp16_epi16_asm_timed() / (double)LZCNT_REPEATS << endl;
}
