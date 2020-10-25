#include "stdafx.h"

__m128i _mm_prefix_xor_clmul_si128(__m128i a) {
	const __m128i full	= _mm_set1_epi32(0xffffffff);
	__m128i clmul0_63	= _mm_clmulepi64_si128(a, full, 0x00);
	__m128i clmul64_127	= _mm_clmulepi64_si128(a, full, 0x01);
#if !defined(__AVX512VL__)
	clmul64_127			= _mm_xor_si128(clmul64_127, _mm_shuffle_epi32(_mm_srai_epi32(clmul0_63, 31), 0x05));
#else
	clmul64_127			= _mm_xor_si128(clmul64_127, _mm_srai_epi64(clmul0_63, 63));
#endif
	return				_mm_unpacklo_epi64(clmul0_63, clmul64_127);
}

#if defined(__AVX__)
__m256i _mm256_prefix_xor_clmul_si256(__m256i a) {
	const __m256i full	= _mm256_set1_epi32(0xffffffff);
	__m256i clmul0_63	= _mm256_clmulepi64_epi128(a, full, 0x00);
	__m256i clmul64_127	= _mm256_clmulepi64_epi128(a, full, 0x01);
#if !defined(__AVX512VL__)
	clmul64_127			= _mm256_xor_si256(clmul64_127, _mm256_shuffle_epi32(_mm256_srai_epi32(clmul0_63, 31), 0x05));
#else
	clmul64_127			= _mm256_xor_si256(clmul64_127, _mm256_srai_epi64(clmul0_63, 63));
#endif
	__m256i clmul0_127	= _mm256_unpacklo_epi64(clmul0_63, clmul64_127);
#if !defined(__AVX512VL__)
	__m256i corr128_255	= _mm256_inserti128_si256(_mm256_setzero_si256(), _mm_shuffle_epi32(_mm_srai_epi32(_mm256_castsi256_si128(clmul0_127), 31), 0xff), 1);
#else
	__m256i corr128_255	= _mm256_maskz_permutex_epi64(0xc, _mm256_srai_epi64(clmul64_127, 63), 0);
#endif
	return				_mm256_xor_si256(clmul0_127, corr128_255);
}
#endif

#if defined(__AVX512F__)
__m512i _mm512_prefix_xor_clmul_si512(__m512i a) {
	const __m512i full	= _mm512_set1_epi32(0xffffffff);
	__m512i clmul0_63	= _mm512_clmulepi64_epi128(a, full, 0x00);
	__m512i clmul64_127	= _mm512_clmulepi64_epi128(a, full, 0x01);
	clmul64_127			= _mm512_xor_si512(clmul64_127, _mm512_srai_epi64(clmul0_63, 63));
	__m512i clmul0_127	= _mm512_unpacklo_epi64(clmul0_63, clmul64_127);
	__m512i corr128_255	= _mm512_maskz_permutex_epi64(0xcc, _mm512_srai_epi64(clmul64_127, 63), 0);
	__m512i clmul0_255	= _mm512_xor_si512(clmul0_127, corr128_255);
	__m512i corr256_511	= _mm512_maskz_permutexvar_epi64(0xf0, _mm512_set1_epi64(3), _mm512_srai_epi64(clmul0_255, 63));
	return				 _mm512_xor_si512(clmul0_255, corr256_511);
}
#endif
