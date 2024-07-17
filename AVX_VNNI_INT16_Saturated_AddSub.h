#pragma once

#ifdef __cplusplus
extern "C" {
#endif

__m128i _mm_adds_epi32(__m128i a, __m128i b);
__m128i _mm_subs_epi32(__m128i a, __m128i b);

__m128i _mm_adds_epu32(__m128i a, __m128i b);
__m128i _mm_subs_epu32(__m128i a, __m128i b);

__m256i _mm256_adds_epi32(__m256i a, __m256i b);
__m256i _mm256_subs_epi32(__m256i a, __m256i b);

__m256i _mm256_adds_epu32(__m256i a, __m256i b);
__m256i _mm256_subs_epu32(__m256i a, __m256i b);

#ifdef __cplusplus
}
#endif
