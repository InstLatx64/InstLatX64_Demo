#pragma once

#define TZCNT_REPEATS	0x1000000

extern "C" unsigned __int64 _mm_tzcnt_epi8_asm(void);
extern "C" unsigned __int64 _mm_tzcnt_epi16_asm(void);
extern "C" unsigned __int64 _mm_tzcnt_epi32_asm(void);
extern "C" unsigned __int64 _mm_tzcnt_epi64_asm(void);

extern "C" unsigned __int64 _mm256_tzcnt_epi8_asm(void);
extern "C" unsigned __int64 _mm256_tzcnt_epi16_asm(void);
extern "C" unsigned __int64 _mm256_tzcnt_epi32_asm(void);
extern "C" unsigned __int64 _mm256_tzcnt_epi64_asm(void);

extern "C" unsigned __int64 _mm512_tzcnt_epi8_asm(void);
extern "C" unsigned __int64 _mm512_tzcnt_epi16_asm(void);
extern "C" unsigned __int64 _mm512_tzcnt_epi32_asm(void);
extern "C" unsigned __int64 _mm512_tzcnt_epi64_asm(void);

extern "C" unsigned __int64 _mm256_tzcnt_epi32_lzcnt_asm(void);
extern "C" unsigned __int64 _mm512_tzcnt_epi32_lzcnt_asm(void);
extern "C" unsigned __int64 _mm256_tzcnt_epi64_lzcnt_asm(void);
extern "C" unsigned __int64 _mm512_tzcnt_epi64_lzcnt_asm(void);

__m128i _mm_tzcnt_epi8(__m128i a);
__m256i _mm256_tzcnt_epi8(__m256i a);
__m512i _mm512_tzcnt_epi8(__m512i a);

__m128i _mm_tzcnt_epi16(__m128i a);
__m256i _mm256_tzcnt_epi16(__m256i a);
__m512i _mm512_tzcnt_epi16(__m512i a);

__m128i _mm_tzcnt_epi32(__m128i a);
__m256i _mm256_tzcnt_epi32(__m256i a);
__m512i _mm512_tzcnt_epi32(__m512i a);

__m128i _mm_tzcnt_epi64(__m128i a);
__m256i _mm256_tzcnt_epi64(__m256i a);
__m512i _mm512_tzcnt_epi64(__m512i a);

