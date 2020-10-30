#pragma once

/* Prefix xor for entire vector register */

__m128i _mm_prefix_xor_clmul_si128(__m128i a);

#if defined(__AVX2__)
__m256i _mm256_prefix_xor_clmul_si256(__m256i a);
#endif

#if defined(__AVX512F__)
__m512i _mm512_prefix_xor_clmul_si512(__m512i a);
#endif

void VPCLMULQDQ_Demo(void);