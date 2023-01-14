#pragma once

__m512i _mm512_adds_epi32(__m512i x1, __m512i x2);
__m512i _mm512_adds_epi64(__m512i x1, __m512i x2);

__m512i _mm512_subs_epi32(__m512i x1, __m512i x2);
__m512i _mm512_subs_epi64(__m512i x1, __m512i x2);

__m512i _mm512_adds_epu32(__m512i x1, __m512i x2);
__m512i _mm512_adds_epu64(__m512i x1, __m512i x2);

__m512i _mm512_subs_epu32(__m512i x1, __m512i x2);
__m512i _mm512_subs_epu64(__m512i x1, __m512i x2);
