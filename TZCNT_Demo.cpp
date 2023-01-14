#include "stdafx.h"
#include "TZCNT_Demo.h"
/*
SIMD TZCNT proposal: POPCNT vs LZCNT:
- Byte/Word support too, not just DWord/QWord
- faster (const 5 vs 8/9 clks on TGL, RKL)
- tzcnt(a) = popcnt(tzmsk(a)) = popcnt(~a & (a-1)) = popcnt(andn(a, a-1)) = popcnt(andn(a, a+(-1))) (thx, @PerforatedBlob! https://twitter.com/PerforatedBlob/status/1418421045447454724)
- only 1 const
- zero case handled
*/

extern CPU_Props cpu_props;

using namespace std;

__m128i _mm_tzcnt_epi8(__m128i a) {
	__m128i u = _mm_undefined_si128();
	return _mm_popcnt_epi8(_mm_andnot_si128(a, _mm_add_epi8(a, _mm_cmpeq_epi8(u, u))));
}

__m256i _mm256_tzcnt_epi8(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	return _mm256_popcnt_epi8(_mm256_andnot_si256(a, _mm256_add_epi8(a, _mm256_cmpeq_epi8(u, u))));
}

__m512i _mm512_tzcnt_epi8(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	return _mm512_popcnt_epi8(_mm512_andnot_si512(a, _mm512_add_epi8(a, _mm512_ternarylogic_epi32(u, u, u, 0xff))));
}

__m128i _mm_tzcnt_epi16(__m128i a) {
	__m128i u = _mm_undefined_si128();
	return _mm_popcnt_epi16(_mm_andnot_si128(a, _mm_add_epi16(a, _mm_cmpeq_epi16(u, u))));
}

__m256i _mm256_tzcnt_epi16(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	return _mm256_popcnt_epi16(_mm256_andnot_si256(a,_mm256_add_epi16(a, _mm256_cmpeq_epi16(u, u))));
}

__m512i _mm512_tzcnt_epi16(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	return _mm512_popcnt_epi16(_mm512_andnot_si512(a, _mm512_add_epi16(a, _mm512_ternarylogic_epi32(u, u, u, 0xff))));
}

__m128i _mm_tzcnt_epi32(__m128i a) {
	__m128i u = _mm_undefined_si128();
	return _mm_popcnt_epi32(_mm_andnot_si128(a, _mm_add_epi32(a, _mm_cmpeq_epi32(u, u))));
}

__m256i _mm256_tzcnt_epi32(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	return _mm256_popcnt_epi32(_mm256_andnot_si256(a, _mm256_add_epi32(a, _mm256_cmpeq_epi32(u, u))));
}

__m512i _mm512_tzcnt_epi32(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	return _mm512_popcnt_epi32(_mm512_andnot_si512(a, _mm512_add_epi32(a, _mm512_ternarylogic_epi32(u, u, u, 0xff))));
}

__m128i _mm_tzcnt_epi64(__m128i a) {
	__m128i u = _mm_undefined_si128();
	return _mm_popcnt_epi64(_mm_andnot_si128(a, _mm_add_epi64(a, _mm_cmpeq_epi64(u, u))));
}

__m256i _mm256_tzcnt_epi64(__m256i a) {
	__m256i u = _mm256_undefined_si256();
	return _mm256_popcnt_epi64(_mm256_andnot_si256(a, _mm256_add_epi64(a, _mm256_cmpeq_epi64(u, u))));
}

__m512i _mm512_tzcnt_epi64(__m512i a) {
	__m512i u = _mm512_undefined_epi32();
	return _mm512_popcnt_epi64(_mm512_andnot_si512(a, _mm512_add_epi64(a, _mm512_ternarylogic_epi64(u, u, u, 0xff))));
}

void TZCNT_Test(void) {
	cout << "--- AVX512_BITALG & AVX512_VPOPCNTDQ SIMD TZCNT ---" << dec << right << endl;
	__m128i x128	= _mm_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768), y128 = _mm_set1_epi16(0x7f);
	__m256i x256	= _mm256_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768, 0x07f00, 0x07e00, 0x07c00, 0x07800, 0x07000, 0x06000, 0x04000, 0x00000), y256 = _mm256_set1_epi16(0x7f);
	__m512i x512	= _mm512_set_epi16(0x0000, 0x0001, 0x0002, 0x0004, 0x1000, 0x2000, 0x4000, -32768, 0x07f00, 0x07e00, 0x07c00, 0x07800, 0x07000, 0x06000, 0x00000, 0x00000, -1, -2, -4, -8, -16, -32, -64, -128, -256, -512, -1024, -2048, -4096, -8192, -16384, -32768), y512 = _mm512_set1_epi16(0x7f);
	__mmask8 m8 = _INSTLATX64_DEMO_TESTMASK_8;
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;

	printRes("x128                         :", x128);
	printRes("_mm_tzcnt_epi8               :", _mm_tzcnt_epi8(x128));
	printRes("_mm_tzcnt_epi16              :", _mm_tzcnt_epi16(x128));
	printRes("_mm_tzcnt_epi32              :", _mm_tzcnt_epi32(x128));
	printRes("_mm_tzcnt_epi64              :", _mm_tzcnt_epi64(x128));

	printRes("x256                         :", x256);
	printRes("_mm256_tzcnt_epi8            :", _mm256_tzcnt_epi8(x256));
	printRes("_mm256_tzcnt_epi16           :", _mm256_tzcnt_epi16(x256));
	printRes("_mm256_tzcnt_epi32           :", _mm256_tzcnt_epi32(x256));
	printRes("_mm256_tzcnt_epi64           :", _mm256_tzcnt_epi64(x256));

	printRes("x512                         :", x512);
	printRes("_mm512_tzcnt_epi8            :", _mm512_tzcnt_epi8(x512));
	printRes("_mm512_tzcnt_epi16           :", _mm512_tzcnt_epi16(x512));
	printRes("_mm512_tzcnt_epi32           :", _mm512_tzcnt_epi32(x512));
	printRes("_mm512_tzcnt_epi64           :", _mm512_tzcnt_epi64(x512));

	cout << "TSC CLKs:----------------------" << endl;

	cout << "_mm_tzcnt_epi8_asm            :" << (double)_mm_tzcnt_epi8_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm_tzcnt_epi16_asm           :" << (double)_mm_tzcnt_epi16_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm_tzcnt_epi32_asm           :" << (double)_mm_tzcnt_epi32_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm_tzcnt_epi64_asm           :" << (double)_mm_tzcnt_epi64_asm() / (double)TZCNT_REPEATS << endl;

	cout << "_mm256_tzcnt_epi8_asm         :" << (double)_mm256_tzcnt_epi8_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm256_tzcnt_epi16_asm        :" << (double)_mm256_tzcnt_epi16_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm256_tzcnt_epi32_asm        :" << (double)_mm256_tzcnt_epi32_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm256_tzcnt_epi64_asm        :" << (double)_mm256_tzcnt_epi64_asm() / (double)TZCNT_REPEATS << endl;

	cout << "_mm512_tzcnt_epi8_asm         :" << (double)_mm512_tzcnt_epi8_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm512_tzcnt_epi16_asm        :" << (double)_mm512_tzcnt_epi16_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm512_tzcnt_epi32_asm        :" << (double)_mm512_tzcnt_epi32_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm512_tzcnt_epi64_asm        :" << (double)_mm512_tzcnt_epi64_asm() / (double)TZCNT_REPEATS << endl;

	cout << "_mm256_tzcnt_epi32_lzcnt_asm  :" << (double)_mm256_tzcnt_epi32_lzcnt_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm512_tzcnt_epi32_lzcnt_asm  :" << (double)_mm512_tzcnt_epi32_lzcnt_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm256_tzcnt_epi64_lzcnt_asm  :" << (double)_mm256_tzcnt_epi64_lzcnt_asm() / (double)TZCNT_REPEATS << endl;
	cout << "_mm512_tzcnt_epi64_lzcnt_asm  :" << (double)_mm512_tzcnt_epi64_lzcnt_asm() / (double)TZCNT_REPEATS << endl;
}
