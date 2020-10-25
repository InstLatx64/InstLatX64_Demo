// VPCLMULQDQ_Demo.cpp 

#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

void VPCLMULQDQ_Demo_prefix_xor(void) {
	//PS-XOR(x) ^ PS-XOR(y) == PS-XOR(x ^ y)
	unsigned long long q64_0 = 0, q64_1 = 0;
#if !defined(_M_X64)
	while (!_rdrand32_step((unsigned int *)&q64_0));
	while (!_rdrand32_step((unsigned int *)&q64_0 + 1));
	while (!_rdrand32_step((unsigned int *)&q64_1));
	while (!_rdrand32_step((unsigned int *)&q64_1 + 1));
#else
	while (!_rdrand64_step(&q64_0));
	while (!_rdrand64_step(&q64_1));
#endif

	__m128i x128	= _mm_set_epi64x(q64_0, _rotl64(q64_0, q64_0 & 0x3f));
	__m128i y128	= _mm_set_epi64x(q64_1, _rotl64(q64_1, q64_1 & 0x3f));

	__m128i test128	= _mm_xor_si128(
	_mm_xor_si128(_mm_prefix_xor_clmul_si128(x128), _mm_prefix_xor_clmul_si128(y128)),
	_mm_prefix_xor_clmul_si128(_mm_xor_si128(x128, y128)));
	assert(_mm_testz_si128(test128, test128));
	printRes("x128                          ", x128);
	printRes("_mm_prefix_xor_clmul_si128    ", _mm_prefix_xor_clmul_si128(x128));
	
#if defined(__AVX__)
	if (cpu_props.IsFeat(ISA_AVX) && cpu_props.IsFeat(ISA_VPCLMULQDQ)) {
		unsigned long long q64_2 = 0, q64_3 = 0;
#if !defined(_M_X64)
		while (!_rdrand32_step((unsigned int *)&q64_2));
		while (!_rdrand32_step((unsigned int *)&q64_2 + 1));
		while (!_rdrand32_step((unsigned int *)&q64_3));
		while (!_rdrand32_step((unsigned int *)&q64_3 + 1));
#else
		while (!_rdrand64_step(&q64_2));
		while (!_rdrand64_step(&q64_3));
#endif
		__m256i x256 = _mm256_set_epi64x(q64_0, _rotl64(q64_0, q64_0 & 0x3f), q64_2, _rotl64(q64_2, q64_2 & 0x3f));
		__m256i y256 = _mm256_set_epi64x(q64_1, _rotl64(q64_1, q64_1 & 0x3f), q64_3, _rotl64(q64_3, q64_3 & 0x3f));
 
 		__m256i test256	= _mm256_xor_si256(
		_mm256_xor_si256(_mm256_prefix_xor_clmul_si256(x256), _mm256_prefix_xor_clmul_si256(y256)),
		_mm256_prefix_xor_clmul_si256(_mm256_xor_si256(x256, y256)));
		assert(_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_prefix_xor_clmul_si256 ", _mm256_prefix_xor_clmul_si256(x256));
	}
#endif
#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F) && cpu_props.IsFeat(ISA_VPCLMULQDQ)) {
		unsigned long long q64_2 = 0, q64_3 = 0;
#if !defined(_M_X64)
		while (!_rdrand32_step((unsigned int *)&q64_2));
		while (!_rdrand32_step((unsigned int *)&q64_2 + 1));
		while (!_rdrand32_step((unsigned int *)&q64_3));
		while (!_rdrand32_step((unsigned int *)&q64_3 + 1));
#else
		while (!_rdrand64_step(&q64_2));
		while (!_rdrand64_step(&q64_3));
#endif
		__m512i x512 = _mm512_set_epi64(q64_0, _rotl64(q64_0, q64_0 & 0x3f), q64_2, _rotl64(q64_2, q64_2 & 0x3f), q64_1, _rotl64(q64_1, q64_0 & 0x3f), q64_3, _rotl64(q64_2, q64_2 & 0x3f));
		__m512i y512 = _mm512_set_epi64(q64_1, _rotl64(q64_1, q64_1 & 0x3f), q64_3, _rotl64(q64_3, q64_3 & 0x3f), q64_0, _rotl64(q64_0, q64_1 & 0x3f), q64_2, _rotl64(q64_3, q64_3 & 0x3f));

		__mmask64 test512 =_mm512_cmpeq_epi8_mask(
		_mm512_xor_si512(_mm512_prefix_xor_clmul_si512(x512), _mm512_prefix_xor_clmul_si512(y512)),
		_mm512_prefix_xor_clmul_si512(_mm512_xor_si512(x512, y512)));
		assert(test512);

		printRes("x512                          ", x512);
		printRes("_mm512_prefix_xor_clmul_si512 ", _mm512_prefix_xor_clmul_si512(x512));
	}
#endif
}

void VPCLMULQDQ_Demo(void) {
	cout << "-----------------------------------" << endl;
	VPCLMULQDQ_Demo_prefix_xor();
}
