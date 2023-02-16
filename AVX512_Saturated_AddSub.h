#pragma once

#ifdef __cplusplus
extern "C" {
#endif

__m512i _mm512_adds_epi32(__m512i a, __m512i b);
__m512i _mm512_adds_epi64(__m512i a, __m512i b);

__m512i _mm512_subs_epi32(__m512i a, __m512i b);
__m512i _mm512_subs_epi64(__m512i a, __m512i b);

__m512i _mm512_adds_epu32(__m512i a, __m512i b);
__m512i _mm512_adds_epu64(__m512i a, __m512i b);

__m512i _mm512_subs_epu32(__m512i a, __m512i b);
__m512i _mm512_subs_epu64(__m512i a, __m512i b);

__m512i _mm512_adds_Zen4_epi32(__m512i a, __m512i b);
__m512i _mm512_adds_Zen4_epi64(__m512i a, __m512i b);

__m512i _mm512_subs_Zen4_epi32(__m512i a, __m512i b);
__m512i _mm512_subs_Zen4_epi64(__m512i a, __m512i b);

__m512i _mm512_adds_Zen4_epu32(__m512i a, __m512i b);
__m512i _mm512_adds_Zen4_epu64(__m512i a, __m512i b);

__m512i _mm512_subs_Zen4_epu32(__m512i a, __m512i b);
__m512i _mm512_subs_Zen4_epu64(__m512i a, __m512i b);

#ifdef __cplusplus
}
#endif
