#include "stdafx.h"
#include "AVX_VNNI_INT16_Saturated_AddSub.h"

extern CPU_Props cpu_props;

using namespace std;

__m128i _mm_adds_epi32(__m128i a, __m128i b) {
	__m128i movwhdup	=	_mm_set_epi32(0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302);
	__m128i _2x32768	=	_mm_set1_epi32(0x80008000);
	__m128i one			=	_mm_set1_epi32(0x1);
	__m128i b_high		=	_mm_shuffle_epi8(b, movwhdup);
	__m128i temp		=	_mm_dpwusds_epi32(a, _2x32768, b_high);
	__m128i zpn_one		=	_mm_sign_epi16(one, _mm_or_si128(b_high, one));
	return					_mm_dpwsuds_epi32(temp, zpn_one, b);
}

__m128i _mm_subs_epi32(__m128i a, __m128i b) {
	__m128i movwhdup	=	_mm_set_epi32(0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302);
	__m128i _m2x32768	=	_mm_set1_epi32(0x80008000);
	__m128i one			=	_mm_set1_epi32(0x1);
	__m128i m_one		=	_mm_set1_epi32(0xffff);
	__m128i b_high		=	_mm_shuffle_epi8(b, movwhdup);
	__m128i temp		=	_mm_dpwssds_avx_epi32(a, _m2x32768, b_high);
	__m128i zpn_one		=	_mm_sign_epi16(m_one, _mm_or_si128(b_high, one));
	return					_mm_dpwsuds_epi32(temp, zpn_one, b);
}

__m128i _mm_adds_epu32(__m128i a, __m128i b) {
	return _mm_add_epi32(_mm_min_epu32(a, _mm_xor_si128(b, _mm_cmpeq_epi32(b, b))), b);
}

__m128i _mm_subs_epu32(__m128i a, __m128i b) {
	return _mm_sub_epi32(_mm_max_epu32(a, b), b);
}

__m256i _mm256_adds_epi32(__m256i a, __m256i b) {
	__m256i movwhdup	=	_mm256_set_epi32(0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302, 0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302);
	__m256i _2x32768	=	_mm256_set1_epi32(0x80008000);
	__m256i one			=	_mm256_set1_epi32(0x1);
	__m256i b_high		=	_mm256_shuffle_epi8(b, movwhdup);
	__m256i temp		=	_mm256_dpwusds_epi32(a, _2x32768, b_high);
	__m256i zpn_one		=	_mm256_sign_epi16(one, _mm256_or_si256(b_high, one));
	return					_mm256_dpwsuds_epi32(temp, zpn_one, b);
}

__m256i _mm256_subs_epi32(__m256i a, __m256i b) {
	__m256i movwhdup	=	_mm256_set_epi32(0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302, 0x0f0e0f0e, 0x0b0a0b0a, 0x07060706, 0x03020302);
	__m256i _m2x32768	=	_mm256_set1_epi32(0x80008000);
	__m256i one			=	_mm256_set1_epi32(0x1);
	__m256i m_one		=	_mm256_set1_epi32(0xffff);
	__m256i b_high		=	_mm256_shuffle_epi8(b, movwhdup);
	__m256i temp		=	_mm256_dpwssds_avx_epi32(a, _m2x32768, b_high);
	__m256i zpn_one		=	_mm256_sign_epi16(m_one, _mm256_or_si256(b_high, one));
	return					_mm256_dpwsuds_epi32(temp, zpn_one, b);
}

__m256i _mm256_adds_epu32(__m256i a, __m256i b) {
	return _mm256_add_epi32(_mm256_min_epu32(a, _mm256_xor_si256(b, _mm256_cmpeq_epi32(b, b))), b);
}

__m256i _mm256_subs_epu32(__m256i a, __m256i b) {
	return _mm256_sub_epi32(_mm256_max_epu32(a, b), b);
}

void AVX_VNNI_Saturated_AddSub_Demo(void) {
	uint16_t x16 = __rdtsc() & 0xffff;
	uint32_t x32 = x16 * 0x10001;

	__m256i testcases_a16	= _mm256_set_epi16(0, 0,        0,        0, x16, x16,      x16,      x16,  SHRT_MIN,  SHRT_MIN, SHRT_MIN, SHRT_MIN,  SHRT_MAX,  SHRT_MAX, SHRT_MAX, SHRT_MAX);
	__m256i testcases_b16	= _mm256_set_epi16(0, x16, SHRT_MIN, SHRT_MAX, 0, x16, SHRT_MIN, SHRT_MAX,         0,       x16, SHRT_MIN, SHRT_MAX,         0,       x16, SHRT_MIN, SHRT_MAX);

	printRes16("Testcases_a16               :", testcases_a16);
	printRes16("Testcases_b16               :", testcases_b16);
	printRes16("Saturated   signed add epi16:", _mm256_adds_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated   signed sub epi16:", _mm256_subs_epi16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned add epu16:", _mm256_adds_epu16(testcases_a16, testcases_b16));
	printRes16("Saturated unsigned sub epu16:", _mm256_subs_epu16(testcases_a16, testcases_b16));


	__m256i testcases_a32_0	= _mm256_set_epi32(0, 0,        0,        0, x32, x32,      x32,      x32);
	__m256i testcases_a32_1	= _mm256_set_epi32(LONG_MIN,  LONG_MIN, LONG_MIN, LONG_MIN,  LONG_MAX,  LONG_MAX, LONG_MAX, LONG_MAX);
	__m256i testcases_b32_0	= _mm256_set_epi32(0, x32, LONG_MIN, LONG_MAX, 0, x32, LONG_MIN, LONG_MAX);
	__m256i testcases_b32_1	= _mm256_set_epi32(0, x32, LONG_MIN, LONG_MAX, 0, x32, LONG_MIN, LONG_MAX);

	printRes32("Testcases_a32_0             :", testcases_a32_0);
	printRes32("Testcases_a32_1             :", testcases_a32_1);
	printRes32("Testcases_b32_0             :", testcases_b32_0);
	printRes32("Testcases_b32_1             :", testcases_b32_1);
	printRes32("Saturated   signed add epi32:", _mm256_adds_epi32(testcases_a32_0, testcases_b32_0));
	printRes32("Saturated   signed add epi32:", _mm256_adds_epi32(testcases_a32_1, testcases_b32_1));
	printRes32("Saturated   signed sub epi32:", _mm256_subs_epi32(testcases_a32_0, testcases_b32_0));
	printRes32("Saturated   signed sub epi32:", _mm256_subs_epi32(testcases_a32_1, testcases_b32_1));
	printRes32("Saturated unsigned add epu32:", _mm256_adds_epu32(testcases_a32_0, testcases_b32_0));
	printRes32("Saturated unsigned add epu32:", _mm256_adds_epu32(testcases_a32_1, testcases_b32_1));
	printRes32("Saturated unsigned sub epu32:", _mm256_subs_epu32(testcases_a32_0, testcases_b32_0));
	printRes32("Saturated unsigned sub epu32:", _mm256_subs_epu32(testcases_a32_1, testcases_b32_1));
}