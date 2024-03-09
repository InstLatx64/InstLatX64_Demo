#pragma once

#define TZCNT_REPEATS	0x1000000

__m128i __vectorcall _mm_tzcnt_epi8(__m128i a);
__m256i __vectorcall _mm256_tzcnt_epi8(__m256i a);
__m512i __vectorcall _mm512_tzcnt_epi8(__m512i a);

__m128i __vectorcall _mm_tzcnt_epi16(__m128i a);
__m256i __vectorcall _mm256_tzcnt_epi16(__m256i a);
__m512i __vectorcall _mm512_tzcnt_epi16(__m512i a);

__m128i __vectorcall _mm_tzcnt_epi32(__m128i a);
__m256i __vectorcall _mm256_tzcnt_epi32(__m256i a);
__m512i __vectorcall _mm512_tzcnt_epi32(__m512i a);

__m128i __vectorcall _mm_tzcnt_epi64(__m128i a);
__m256i __vectorcall _mm256_tzcnt_epi64(__m256i a);
__m512i __vectorcall _mm512_tzcnt_epi64(__m512i a);

#ifdef __cplusplus
extern "C" {
#endif

unsigned __int64 _mm_tzcnt_epi8_asm_timed(void);
unsigned __int64 _mm_tzcnt_epi16_asm_timed(void);
unsigned __int64 _mm_tzcnt_epi32_asm_timed(void);
unsigned __int64 _mm_tzcnt_epi64_asm_timed(void);

unsigned __int64 _mm256_tzcnt_epi8_asm_timed(void);
unsigned __int64 _mm256_tzcnt_epi16_asm_timed(void);
unsigned __int64 _mm256_tzcnt_epi32_asm_timed(void);
unsigned __int64 _mm256_tzcnt_epi64_asm_timed(void);

unsigned __int64 _mm512_tzcnt_epi8_asm_timed(void);
unsigned __int64 _mm512_tzcnt_epi16_asm_timed(void);
unsigned __int64 _mm512_tzcnt_epi32_asm_timed(void);
unsigned __int64 _mm512_tzcnt_epi64_asm_timed(void);

unsigned __int64 _mm_tzcnt_epi32_cd_asm_timed(void);
unsigned __int64 _mm256_tzcnt_epi32_cd_asm_timed(void);
unsigned __int64 _mm512_tzcnt_epi32_cd_asm_timed(void);
unsigned __int64 _mm_tzcnt_epi64_cd_asm_timed(void);
unsigned __int64 _mm256_tzcnt_epi64_cd_asm_timed(void);
unsigned __int64 _mm512_tzcnt_epi64_cd_asm_timed(void);

__m128i __vectorcall _mm_tzcnt_epi8_asm(__m128i);
__m128i __vectorcall _mm_tzcnt_epi16_asm(__m128i);
__m128i __vectorcall _mm_tzcnt_epi32_asm(__m128i);
__m128i __vectorcall _mm_tzcnt_epi64_asm(__m128i);

__m256i __vectorcall _mm256_tzcnt_epi8_asm(__m256i);
__m256i __vectorcall _mm256_tzcnt_epi16_asm(__m256i);
__m256i __vectorcall _mm256_tzcnt_epi32_asm(__m256i);
__m256i __vectorcall _mm256_tzcnt_epi64_asm(__m256i);

__m512i __vectorcall _mm512_tzcnt_epi8_asm(__m512i);
__m512i __vectorcall _mm512_tzcnt_epi16_asm(__m512i);
__m512i __vectorcall _mm512_tzcnt_epi32_asm(__m512i);
__m512i __vectorcall _mm512_tzcnt_epi64_asm(__m512i);

__m256i __vectorcall _mm256_tzcnt_epi32_cd_asm(__m256i);
__m512i __vectorcall _mm512_tzcnt_epi32_cd_asm(__m512i);
__m256i __vectorcall _mm256_tzcnt_epi64_cd_asm(__m256i);
__m512i __vectorcall _mm512_tzcnt_epi64_cd_asm(__m512i);

#ifdef __cplusplus
}
#endif
