#include "stdafx.h"
#include "AVX512_Saturated_AddSub.h"

extern CPU_Props cpu_props;

using namespace std;

//credits:
//https://stackoverflow.com/questions/29498824/add-saturate-32-bit-signed-ints-intrinsics
//https://stackoverflow.com/questions/56526082/is-there-a-way-to-subtract-packed-unsigned-doublewords-saturated-on-x86-using
//https://godbolt.org/z/3o5KCm
//VPTERNLOGx imm8 Calculator:
//https://www.officedaytime.com/simd512e/simdimg/ternlogcalc.html

//c ? a : b
//imm8 = 0xE4
//
//a				1	1	1	1	0	0	0	0
//b				1	1	0	0	1	1	0	0
//c				1	0	1	0	1	0	1	0
//c ? a : b		1	1	1	0	0	1	0	0


//eq(a, b) & neq(a, c)
//imm8 = 0x42
//a						1	1	1	1	0	0	0	0
//b						1	1	0	0	1	1	0	0
//c						1	0	1	0	1	0	1	0
//eq(a, b) & neq(a, c)	0	1	0	0	0	0	1	0

__m512i _mm512_adds_epi32(__m512i x1, __m512i x2) {
	__m512i add		= _mm512_add_epi32(x1, x2);

	__m512i sign	= _mm512_srai_epi32(add, 31);
	__m512i of		= _mm512_ternarylogic_epi32(x1, x2, add, 0x42);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi32(LONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi32(ofvalue, add, ofmask, 0xe4);
	return	val;
}

__m512i _mm512_adds_epi64(__m512i x1, __m512i x2) {
	__m512i add		= _mm512_add_epi64(x1, x2);

	__m512i sign	= _mm512_srai_epi64(add, 63);
	__m512i of		= _mm512_ternarylogic_epi64(x1, x2, add, 0x42);

	__m512i ofmask	= _mm512_srai_epi64(of, 63);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi64(LLONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi64(ofvalue, add, ofmask, 0xe4);
	return	val;
}

//neq(a, b) & neq(a, c)
//imm8 = 0x18
//
//a						1	1	1	1	0	0	0	0
//b						1	1	0	0	1	1	0	0
//c						1	0	1	0	1	0	1	0
//neq(a, b) & eq(b, c)	0	0	0	1	1	0	0	0

__m512i _mm512_subs_epi32(__m512i x1, __m512i x2) {
	__m512i sub		= _mm512_sub_epi32(x1, x2);

	__m512i sign	= _mm512_srai_epi32(sub, 31);
	__m512i of		= _mm512_ternarylogic_epi32(x1, x2, sub, 0x18);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi32(LONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi32(ofvalue, sub, ofmask, 0xe4);
	return	val;
}

__m512i _mm512_subs_epi64(__m512i x1, __m512i x2) {
	__m512i sub		= _mm512_sub_epi64(x1, x2);

	__m512i sign	= _mm512_srai_epi64(sub, 63);
	__m512i of		= _mm512_ternarylogic_epi64(x1, x2, sub, 0x18);

	__m512i ofmask	= _mm512_srai_epi64(of, 63);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi64(LLONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi64(ofvalue, sub, ofmask, 0xe4);
	return	val;
}

//~a
//imm8 = 0x0F
//
//a		1	1	1	1	0	0	0	0
//b		1	1	0	0	1	1	0	0
//c		1	0	1	0	1	0	1	0
//~a	0	0	0	0	1	1	1	1

__m512i _mm512_adds_epu32(__m512i x1, __m512i x2) {
	return _mm512_add_epi32(_mm512_min_epu32(x1, _mm512_ternarylogic_epi32(x2, x2, x2, 0x0f)), x2);
}

__m512i _mm512_adds_epu64(__m512i x1, __m512i x2) {
	return _mm512_add_epi64(_mm512_min_epu64(x1, _mm512_ternarylogic_epi64(x2, x2, x2, 0x0f)), x2);
}

__m512i _mm512_subs_epu32(__m512i x1, __m512i x2) {
	return _mm512_sub_epi32(_mm512_max_epu32(x1, x2), x2);
}

__m512i _mm512_subs_epu64(__m512i x1, __m512i x2) {
	return _mm512_sub_epi64(_mm512_max_epu64(x1, x2), x2);
}

void AVX512_Saturated_AddSub_Demo(void) {
	__m256i testcases_a16	= _mm256_set_epi16(0, 0,        0,        0, 1, 1,        1,        1,  SHRT_MIN,  SHRT_MIN, SHRT_MIN, SHRT_MIN,  SHRT_MAX,  SHRT_MAX, SHRT_MAX, SHRT_MAX);
	__m256i testcases_b16	= _mm256_set_epi16(0, 1, SHRT_MIN, SHRT_MAX, 0, 1, SHRT_MIN, SHRT_MAX,         0,         1, SHRT_MIN, SHRT_MAX,         0,         1, SHRT_MIN, SHRT_MAX);

	printRes16("Testcases_a16               :", testcases_a16);
	printRes16("Testcases_b16               :", testcases_b16);
	printRes16("Saturated   signed add epi16:", _mm256_adds_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated   signed sub epi16:", _mm256_subs_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned add epu16:", _mm256_adds_epu16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned sub epu16:", _mm256_subs_epu16(testcases_a16, testcases_b16));

	cout << endl;

	__m512i testcases_a32	= _mm512_set_epi32(0, 0,        0,        0, 1, 1,        1,        1,  LONG_MIN,  LONG_MIN, LONG_MIN, LONG_MIN,  LONG_MAX,  LONG_MAX, LONG_MAX, LONG_MAX);
	__m512i testcases_b32	= _mm512_set_epi32(0, 1, LONG_MIN, LONG_MAX, 0, 1, LONG_MIN, LONG_MAX,         0,         1, LONG_MIN, LONG_MAX,         0,         1, LONG_MIN, LONG_MAX);

	printRes32("Testcases_a32               :", testcases_a32);
	printRes32("Testcases_b32               :", testcases_b32);
	printRes32("Saturated   signed add epi32:", _mm512_adds_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated   signed sub epi32:", _mm512_subs_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned add epu32:", _mm512_adds_epu32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned sub epu32:", _mm512_subs_epu32(testcases_a32, testcases_b32));

	cout << endl;

	__m512i testcases_a0_64	= _mm512_set_epi64(        0,          0,         0,         0,          1,          1,         1,         1);
	__m512i testcases_a1_64	= _mm512_set_epi64(LLONG_MIN,  LLONG_MIN, LLONG_MIN, LLONG_MIN,  LLONG_MAX,  LLONG_MAX, LLONG_MAX, LLONG_MAX);
	__m512i testcases_b0_64	= _mm512_set_epi64(        0,          1, LLONG_MIN, LLONG_MAX,          0,          1, LLONG_MIN, LLONG_MAX);
	__m512i testcases_b1_64	= _mm512_set_epi64(        0,          1, LLONG_MIN, LLONG_MAX,          0,          1, LLONG_MIN, LLONG_MAX);

	printRes("Testcases_a0_64             :", testcases_a0_64);
	printRes("Testcases_a1_64             :", testcases_a1_64);
	printRes("Testcases_b0_64             :", testcases_b0_64);
	printRes("Testcases_b1_64             :", testcases_b1_64);

	cout << endl;

	printRes("Saturated   signed add epi64:", _mm512_adds_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed add epi64:", _mm512_adds_epi64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated   signed sub epi64:", _mm512_subs_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed sub epi64:", _mm512_subs_epi64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated unsigned add epi64:", _mm512_adds_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned add epi64:", _mm512_adds_epu64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated unsigned sub epi64:", _mm512_subs_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned sub epi64:", _mm512_subs_epu64(testcases_a1_64, testcases_b1_64));

}