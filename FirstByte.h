#pragma once

__m256i _mm256_firstbyte_epu32(__m256i a, char c);
__m256i _mm256_firstbyte_epu64(__m256i a, char c);
__m512i _mm512_firstbyte_epu32(__m512i a, char c);
__m512i _mm512_firstbyte_epu64(__m512i a, char c);