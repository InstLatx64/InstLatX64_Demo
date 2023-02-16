#include "stdafx.h"
#include "AVX512_Saturated_AddSub.h"

extern CPU_Props cpu_props;

using namespace std;

/*
The saturated addition and substraction are supported only for 8- and 16-bit long data types in Intel SSE/AVX ISA: 

 - _mm512_adds_epi8/epu8 
 - _mm512_subs_epi8/epu8
 - _mm512_adds_epi16/epu16 
 - _mm512_subs_epi16/epu16

This proposal is for the missing 32- and 64-bit versions:

 - _mm512_adds_epi32/epu32 
 - _mm512_subs_epi32/epu32
 - _mm512_adds_epi64/epu64 
 - _mm512_subs_epi64/epu64
*/

//Inspiration:
//https://twitter.com/Wunkolo/status/1579894616593076224
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

// A signed addition overflow will happen if, and only if:
// - the signs of both inputs are the same, and
// - the sign of the sum (when added with wrap-around) is different from the input:
// sign(a) = sign(b),  sign(a + b) != sign(a)
//eq(a, b) & neq(a, c)
//imm8 = 0x42
//a							1	1	1	1	0	0	0	0
//b							1	1	0	0	1	1	0	0
//a + b						1	0	1	0	1	0	1	0
//eq(a, b) & neq(a, a + b)	0	1	0	0	0	0	1	0

__m512i _mm512_adds_epi32(__m512i a, __m512i b) {
	__m512i add		= _mm512_add_epi32(a, b);

	__m512i sign	= _mm512_srai_epi32(add, 31);
	__m512i of		= _mm512_ternarylogic_epi32(a, b, add, 0x42);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi32(LONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi32(ofvalue, add, ofmask, 0xe4);
	return	val;
}

__m512i _mm512_adds_epi64(__m512i a, __m512i b) {
	__m512i add		= _mm512_add_epi64(a, b);

	__m512i sign	= _mm512_srai_epi64(add, 63);
	__m512i of		= _mm512_ternarylogic_epi64(a, b, add, 0x42);

	__m512i ofmask	= _mm512_srai_epi64(of, 63);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi64(LLONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi64(ofvalue, add, ofmask, 0xe4);
	return	val;
}

// A signed substraction overflow will happen if, and only if:
// - if the signs of the two inputs are different, and
// - the sign of the difference (when substracted with wrap-around) is different from the minuend:
// sign(a) != sign(b),  sign(a - b) != sign(a)
//imm8 = 0x18
//a							1	1	1	1	0	0	0	0
//b							1	1	0	0	1	1	0	0
//a - b						1	0	1	0	1	0	1	0
//neq(a, b) & neq(a - b, a)	0	0	0	1	1	0	0	0

__m512i _mm512_subs_epi32(__m512i a, __m512i b) {
	__m512i sub		= _mm512_sub_epi32(a, b);

	__m512i sign	= _mm512_srai_epi32(sub, 31);
	__m512i of		= _mm512_ternarylogic_epi32(a, b, sub, 0x18);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(_mm512_set1_epi32(LONG_MIN), sign);

	__m512i val		= _mm512_ternarylogic_epi32(ofvalue, sub, ofmask, 0xe4);
	return	val;
}

__m512i _mm512_subs_epi64(__m512i a, __m512i b) {
	__m512i sub		= _mm512_sub_epi64(a, b);

	__m512i sign	= _mm512_srai_epi64(sub, 63);
	__m512i of		= _mm512_ternarylogic_epi64(a, b, sub, 0x18);

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

__m512i _mm512_adds_epu32(__m512i a, __m512i b) {
	return _mm512_add_epi32(_mm512_min_epu32(a, _mm512_ternarylogic_epi32(b, b, b, 0x0f)), b);
}

__m512i _mm512_adds_epu64(__m512i a, __m512i b) {
	return _mm512_add_epi64(_mm512_min_epu64(a, _mm512_ternarylogic_epi64(b, b, b, 0x0f)), b);
}

__m512i _mm512_subs_epu32(__m512i a, __m512i b) {
	return _mm512_sub_epi32(_mm512_max_epu32(a, b), b);
}

__m512i _mm512_subs_epu64(__m512i a, __m512i b) {
	return _mm512_sub_epi64(_mm512_max_epu64(a, b), b);
}

//the Zen4 versions consider the peculiarities of TERNLOG handling on AMD CPUs:
//https://uops.info/html-lat/ZEN4/VPTERNLOGD_ZMM_ZMM_ZMM_I8-Measurements.html
//Instruction: VPTERNLOGD ZMM0, ZMM1, ZMM2, 2
//Code:
//	vpternlogd zmm0,zmm1,zmm2,0x2
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//Results:
//MPERF: 5.17
//APERF: 6.0 -> 1 clk
//
//Instruction: VPTERNLOGD ZMM1, ZMM0, ZMM2, 2
//Code:
//	vpternlogd zmm1,zmm0,zmm2,0x2
//	vandpd zmm0,zmm1,zmm1
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//Results:
//MPERF: 6.11
//APERF: 7.06 -> 2 clks
//
//Instruction: VPTERNLOGD ZMM1, ZMM2, ZMM0, 2
//Code:
//	vpternlogd zmm1,zmm2,zmm0,0x2
//	vandpd zmm0,zmm1,zmm1
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//	vandpd zmm0,zmm0,zmm0
//Results:
//MPERF: 6.19
//APERF: 7.0 -> 2 clks

//a ? b : c
//imm8 = 0xCA
//a				1	1	1	1	0	0	0	0
//b				1	1	0	0	1	1	0	0
//c				1	0	1	0	1	0	1	0
//a ? b : c		1	1	0	0	1	0	1	0

// A signed addition overflow will happen if, and only if:
// - if the signs of both inputs are the same, and 
// - the sign of the sum (when added with wrap-around) is different from the input:
// sign(a) = sign(b),  sign(a + b) != sign(a)
//imm8 = 0x18
//a + b						1	1	1	1	0	0	0	0
//a							1	1	0	0	1	1	0	0
//b							1	0	1	0	1	0	1	0
//eq(a, b) & neq(a+b, a)	0	0	0	1	1	0	0	0

__m512i _mm512_adds_Zen4_epi32(__m512i a, __m512i b) {
	__m512i add		= _mm512_add_epi32(a, b);

	__m512i sign	= _mm512_srai_epi32(add, 31);
	__m512i of		= _mm512_ternarylogic_epi32(add, a, b, 0x18);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(sign, _mm512_set1_epi32(LONG_MIN));

	__m512i val		= _mm512_ternarylogic_epi32(ofmask, ofvalue, add, 0xca);
	return	val;
}

__m512i _mm512_adds_Zen4_epi64(__m512i a, __m512i b) {
	__m512i add		= _mm512_add_epi64(a, b);

	__m512i sign	= _mm512_srai_epi64(add, 63);
	__m512i of		= _mm512_ternarylogic_epi64(add, a, b, 0x18);

	__m512i ofmask	= _mm512_srai_epi64(of, 63);
	__m512i ofvalue	= _mm512_xor_si512(sign, _mm512_set1_epi64(LLONG_MIN));

	__m512i val		= _mm512_ternarylogic_epi64(ofmask, ofvalue, add, 0xca);
	return	val;
}

// A signed substraction overflow will happen if, and only if:
// - the signs of the two inputs are different, and 
// - the sign of the difference (when substracted with wrap-around) is different from the minuend:
// sign(a) != sign(b),  sign(a - b) != sign(a)
//imm8 = 0x24
//a	- b						1	1	1	1	0	0	0	0
//a							1	1	0	0	1	1	0	0
//b							1	0	1	0	1	0	1	0
//neq(a, b) & neq(a - b, a)	0	0	1	0	0	1	0	0

__m512i _mm512_subs_Zen4_epi32(__m512i a, __m512i b) {
	__m512i sub		= _mm512_sub_epi32(a, b);

	__m512i sign	= _mm512_srai_epi32(sub, 31);
	__m512i of		= _mm512_ternarylogic_epi32(sub, a, b, 0x24);

	__m512i ofmask	= _mm512_srai_epi32(of, 31);
	__m512i ofvalue	= _mm512_xor_si512(sign, _mm512_set1_epi32(LONG_MIN));

	__m512i val		= _mm512_ternarylogic_epi32(ofmask, ofvalue, sub, 0xca);
	return	val;
}

__m512i _mm512_subs_Zen4_epi64(__m512i a, __m512i b) {
	__m512i sub		= _mm512_sub_epi64(a, b);

	__m512i sign	= _mm512_srai_epi64(sub, 63);
	__m512i of		= _mm512_ternarylogic_epi64(sub, a, b, 0x24);

	__m512i ofmask	= _mm512_srai_epi64(of, 63);
	__m512i ofvalue	= _mm512_xor_si512(sign, _mm512_set1_epi64(LLONG_MIN));

	__m512i val		= _mm512_ternarylogic_epi64(ofmask, ofvalue, sub, 0xca);
	return	val;
}

//~a
//imm8 = 0x0F
//
//a		1	1	1	1	0	0	0	0
//b		1	1	0	0	1	1	0	0
//c		1	0	1	0	1	0	1	0
//~a	0	0	0	0	1	1	1	1

__m512i _mm512_adds_Zen4_epu32(__m512i a, __m512i b) {
	__m512i u = _mm512_undefined_epi32();
	return _mm512_add_epi32(_mm512_min_epu32(a, _mm512_ternarylogic_epi32(b, u, u, 0x0f)), b);
}

__m512i _mm512_adds_Zen4_epu64(__m512i a, __m512i b) {
	__m512i u = _mm512_undefined_epi32(); // there isn't _mm512_undefined_epi64();
	return _mm512_add_epi64(_mm512_min_epu64(a, _mm512_ternarylogic_epi64(b, u, u, 0x0f)), b);
}

__m512i _mm512_subs_Zen4_epu32(__m512i a, __m512i b) {
	return _mm512_sub_epi32(_mm512_max_epu32(a, b), b);
}

__m512i _mm512_subs_Zen4_epu64(__m512i a, __m512i b) {
	return _mm512_sub_epi64(_mm512_max_epu64(a, b), b);
}

void AVX512_Saturated_AddSub_Demo(void) {
	uint16_t x16 = __rdtsc() & 0xffff;
	uint32_t x32 = x16 * 0x10001;
	uint64_t x64 = x16 * 0x1000100010001;

	__m256i testcases_a16	= _mm256_set_epi16(0, 0,        0,        0, x16, x16,      x16,      x16,  SHRT_MIN,  SHRT_MIN, SHRT_MIN, SHRT_MIN,  SHRT_MAX,  SHRT_MAX, SHRT_MAX, SHRT_MAX);
	__m256i testcases_b16	= _mm256_set_epi16(0, x16, SHRT_MIN, SHRT_MAX, 0, x16, SHRT_MIN, SHRT_MAX,         0,       x16, SHRT_MIN, SHRT_MAX,         0,       x16, SHRT_MIN, SHRT_MAX);

	printRes16("Testcases_a16               :", testcases_a16);
	printRes16("Testcases_b16               :", testcases_b16);
	printRes16("Saturated   signed add epi16:", _mm256_adds_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated   signed sub epi16:", _mm256_subs_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned add epu16:", _mm256_adds_epu16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned sub epu16:", _mm256_subs_epu16(testcases_a16, testcases_b16));

	cout << endl;

	__m512i testcases_a32	= _mm512_set_epi32(0, 0,        0,        0, x32, x32,      x32,      x32,  LONG_MIN,  LONG_MIN, LONG_MIN, LONG_MIN,  LONG_MAX,  LONG_MAX, LONG_MAX, LONG_MAX);
	__m512i testcases_b32	= _mm512_set_epi32(0, x32, LONG_MIN, LONG_MAX, 0, x32, LONG_MIN, LONG_MAX, 0, x32, LONG_MIN, LONG_MAX, 0, x32, LONG_MIN, LONG_MAX);

	printRes32("Testcases_a32               :", testcases_a32);
	printRes32("Testcases_b32               :", testcases_b32);
	printRes32("Saturated   signed add epi32:", _mm512_adds_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated   signed add epi32:", _mm512_adds_Zen4_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated   signed sub epi32:", _mm512_subs_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated   signed sub epi32:", _mm512_subs_Zen4_epi32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned add epu32:", _mm512_adds_epu32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned add epu32:", _mm512_adds_Zen4_epu32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned sub epu32:", _mm512_subs_epu32(testcases_a32, testcases_b32));
	printRes32("Saturated unsigned sub epu32:", _mm512_subs_Zen4_epu32(testcases_a32, testcases_b32));

	cout << endl;

	__m512i testcases_a0_64	= _mm512_set_epi64(        0,          0,         0,         0,        x64,        x64,       x64,       x64);
	__m512i testcases_a1_64	= _mm512_set_epi64(LLONG_MIN,  LLONG_MIN, LLONG_MIN, LLONG_MIN,  LLONG_MAX,  LLONG_MAX, LLONG_MAX, LLONG_MAX);
	__m512i testcases_b0_64	= _mm512_set_epi64(        0,        x64, LLONG_MIN, LLONG_MAX,          0,        x64, LLONG_MIN, LLONG_MAX);
	__m512i testcases_b1_64	= _mm512_set_epi64(        0,        x64, LLONG_MIN, LLONG_MAX,          0,        x64, LLONG_MIN, LLONG_MAX);

	printRes("Testcases_a0_64             :", testcases_a0_64);
	printRes("Testcases_a1_64             :", testcases_a1_64);
	printRes("Testcases_b0_64             :", testcases_b0_64);
	printRes("Testcases_b1_64             :", testcases_b1_64);

	cout << endl;

	printRes("Saturated   signed add epi64:", _mm512_adds_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed add epi64:", _mm512_adds_Zen4_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed add epi64:", _mm512_adds_epi64(testcases_a1_64, testcases_b1_64));
	printRes("Saturated   signed add epi64:", _mm512_adds_Zen4_epi64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated   signed sub epi64:", _mm512_subs_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed sub epi64:", _mm512_subs_Zen4_epi64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated   signed sub epi64:", _mm512_subs_epi64(testcases_a1_64, testcases_b1_64));
	printRes("Saturated   signed sub epi64:", _mm512_subs_Zen4_epi64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated unsigned add epu64:", _mm512_adds_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned add epu64:", _mm512_adds_Zen4_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned add epu64:", _mm512_adds_epu64(testcases_a1_64, testcases_b1_64));
	printRes("Saturated unsigned add epu64:", _mm512_adds_Zen4_epu64(testcases_a1_64, testcases_b1_64));

	cout << endl;

	printRes("Saturated unsigned sub epu64:", _mm512_subs_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned sub epu64:", _mm512_subs_Zen4_epu64(testcases_a0_64, testcases_b0_64));
	printRes("Saturated unsigned sub epu64:", _mm512_subs_epu64(testcases_a1_64, testcases_b1_64));
	printRes("Saturated unsigned sub epu64:", _mm512_subs_Zen4_epu64(testcases_a1_64, testcases_b1_64));

}