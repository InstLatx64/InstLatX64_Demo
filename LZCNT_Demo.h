#pragma once

#define LZCNT_REPEATS	0x1000000

__m128i __vectorcall _mm_lzcnt_ild_epi8(__m128i a);
__m256i __vectorcall _mm256_lzcnt_ild_epi8(__m256i a);
__m512i __vectorcall _mm512_lzcnt_ild_epi8(__m512i a);

__m128i __vectorcall _mm_lzcnt_ild_epi16(__m128i a);
__m256i __vectorcall _mm256_lzcnt_ild_epi16(__m256i a);
__m512i __vectorcall _mm512_lzcnt_ild_epi16(__m512i a);

__m128i __vectorcall _mm_lzcnt_fp16_epi16(__m128i a);
__m256i __vectorcall _mm256_lzcnt_fp16_epi16(__m256i a);
__m512i __vectorcall _mm512_lzcnt_fp16_epi16(__m512i a);

__m128i __vectorcall _mm_lzcnt_ild_epi8(__m128i a);
__m256i __vectorcall _mm256_lzcnt_ild_epi8(__m256i a);
__m512i __vectorcall _mm512_lzcnt_ild_epi8(__m512i a);

__m128i __vectorcall _mm_lzcnt_ild_epi16(__m128i a);
__m256i __vectorcall _mm256_lzcnt_ild_epi16(__m256i a);
__m512i __vectorcall _mm512_lzcnt_ild_epi16(__m512i a);

__m128i __vectorcall _mm_lzcnt_fp16_epi16(__m128i a);
__m256i __vectorcall _mm256_lzcnt_fp16_epi16(__m256i a);
__m512i __vectorcall _mm512_lzcnt_fp16_epi16(__m512i a);

#ifdef __cplusplus
extern "C" {
#endif

unsigned __int64 _mm_lzcnt_epi8_asm_timed(void);
unsigned __int64 _mm_lzcnt_gfni_epi8_asm_timed(void);
unsigned __int64 _mm_lzcnt_epi16_asm_timed(void);
unsigned __int64 _mm_lzcnt_fp16_epi16_asm_timed(void);

unsigned __int64 _mm256_lzcnt_epi8_asm_timed(void);
unsigned __int64 _mm256_lzcnt_gfni_epi8_asm_timed(void);
unsigned __int64 _mm256_lzcnt_epi16_asm_timed(void);
unsigned __int64 _mm256_lzcnt_fp16_epi16_asm_timed(void);

unsigned __int64 _mm512_lzcnt_epi8_asm_timed(void);
unsigned __int64 _mm512_lzcnt_gfni_epi8_asm_timed(void);
unsigned __int64 _mm512_lzcnt_epi16_asm_timed(void);
unsigned __int64 _mm512_lzcnt_fp16_epi16_asm_timed(void);

__m128i __vectorcall  _mm_lzcnt_epi8_asm(__m128i a);
__m128i __vectorcall  _mm_lzcnt_gfni_epi8_asm(__m128i a);
__m128i __vectorcall  _mm_lzcnt_epi16_asm(__m128i a);
__m128i __vectorcall  _mm_lzcnt_fp16_epi16_asm(__m128i a);

__m256i __vectorcall  _mm256_lzcnt_epi8_asm(__m256i a);
__m256i __vectorcall  _mm256_lzcnt_gfni_epi8_asm(__m256i a);
__m256i __vectorcall  _mm256_lzcnt_epi16_asm(__m256i a);
__m256i __vectorcall  _mm256_lzcnt_fp16_epi16_asm(__m256i a);

__m512i __vectorcall  _mm512_lzcnt_epi8_asm(__m512i a);
__m512i __vectorcall  _mm512_lzcnt_gfni_epi8_asm(__m512i a);
__m512i __vectorcall  _mm512_lzcnt_epi16_asm(__m512i a);
__m512i __vectorcall  _mm512_lzcnt_fp16_epi16_asm(__m512i a);

#ifdef __cplusplus
}
#endif
