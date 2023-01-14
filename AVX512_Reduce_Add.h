#pragma once

uint32_t _mm512_reduce2_add_epu8(__m512i z);
uint32_t _mm512_reduce2_add_epu16(__m512i z);
uint64_t _mm512_reduce2_add_epu32(__m512i z);
uint64_t _mm512_reduce2_add_epu64(__m512i z);
uint64_t _mm512_reduce2_add_epu128(__m512i z, uint64_t* hi);
