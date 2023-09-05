#pragma once

__m256i _mm256_bslli_epi256(__m256i a, int i);
__m256i _mm256_bsrli_epi256(__m256i a, int i);
__m256i _mm256_palignr_epi256(__m256i a, __m256i b, int i);
__m256i _mm256_palignl_epi256(__m256i a, __m256i b, int i);
__m256i _mm256_rotater_epi256(__m256i a, int i);
__m256i _mm256_rotatel_epi256(__m256i a, int i);

__m512i _mm512_bslli_epi512(__m512i a, int i);
__m512i _mm512_bsrli_epi512(__m512i a, int i);
__m512i _mm512_palignr_epi512(__m512i a, __m512i b, int i);
__m512i _mm512_palignl_epi512(__m512i a, __m512i b, int i);
__m512i _mm512_rotater_epi512(__m512i a, int i);
__m512i _mm512_rotatel_epi512(__m512i a, int i);