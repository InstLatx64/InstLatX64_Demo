// GFNI_Demo.cpp 

#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

void GFNI_Demo_rotate_epi8(void) {
	const int maxrot = 9;
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m128i test128	= _mm_xor_si128(x128, _mm_ror_gfni_epi8(_mm_rol_gfni_epi8(x128, r), r));
		assert(_mm_testz_si128(test128, test128));
	}
	printRes("x128                               ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_ror_gfni_epi8                ", _mm_ror_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_ror_gfni_epi8          ", _mm_maskz_ror_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_ror_gfni_epi8           ", _mm_mask_ror_gfni_epi8(y128, m16, x128, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_rol_gfni_epi8                ", _mm_rol_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_rol_gfni_epi8          ", _mm_maskz_rol_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_rol_gfni_epi8           ", _mm_mask_rol_gfni_epi8(y128, m16, x128, r));
#endif
	}

#if defined(__AVX2__)
	__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m256i test256	= _mm256_xor_si256(x256, _mm256_ror_gfni_epi8(_mm256_rol_gfni_epi8(x256, r), r));
		assert(_mm256_testz_si256(test256, test256));
	}
	printRes("x256                               ", x256);
	__mmask32 m32 = _INSTLATX64_DEMO_TESTMASK_32;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_ror_gfni_epi8             ", _mm256_ror_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_ror_gfni_epi8       ", _mm256_maskz_ror_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_ror_gfni_epi8        ", _mm256_mask_ror_gfni_epi8(y256, m32, x256, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_rol_gfni_epi8             ", _mm256_rol_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_rol_gfni_epi8       ", _mm256_maskz_rol_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_rol_gfni_epi8        ", _mm256_mask_rol_gfni_epi8(y256, m32, x256, r));
#endif
	}

#if defined(__AVX512F__)
	__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07), y512 = _mm512_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_ror_gfni_epi8(_mm512_rol_gfni_epi8(x512, r), r));
		assert(test512);

	}
	printRes("x512                               ", x512);
	__mmask64 m64 = _INSTLATX64_DEMO_TESTMASK_64;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_ror_gfni_epi8             ", _mm512_ror_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_ror_gfni_epi8       ", _mm512_maskz_ror_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_ror_gfni_epi8        ", _mm512_mask_ror_gfni_epi8(y512, m64, x512, r));
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_rol_gfni_epi8             ", _mm512_rol_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_rol_gfni_epi8       ", _mm512_maskz_rol_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_rol_gfni_epi8        ", _mm512_mask_rol_gfni_epi8(y512, m64, x512, r));
	}
#endif
#endif
}

void GFNI_Demo_shifti_epi8(void) {
	const int maxrot = 9;
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m128i temp128 = _mm_or_si128(_mm_srli_gfni_epi8(x128, r), _mm_slli_gfni_epi8(x128, 8 - r));
		__m128i test128	= _mm_xor_si128(x128, _mm_or_si128(_mm_slli_gfni_epi8(temp128, r), _mm_srli_gfni_epi8(temp128, 8 - r)));
		assert(_mm_testz_si128(test128, test128));
	}
	printRes("x128                               ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_srli_gfni_epi8               ", _mm_srli_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_srli_gfni_epi8         ", _mm_maskz_srli_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_srli_gfni_epi8          ", _mm_mask_srli_gfni_epi8(y128, m16, x128, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_slli_gfni_epi8               ", _mm_slli_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_slli_gfni_epi8         ", _mm_maskz_slli_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_slli_gfni_epi8          ", _mm_mask_slli_gfni_epi8(y128, m16, x128, r));
#endif
	}

#if defined(__AVX2__)
	__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m256i temp256 = _mm256_or_si256(_mm256_srli_gfni_epi8(x256, r), _mm256_slli_gfni_epi8(x256, 8 - r));
		__m256i test256	= _mm256_xor_si256(x256, _mm256_or_si256(_mm256_slli_gfni_epi8(temp256, r), _mm256_srli_gfni_epi8(temp256, 8 - r)));
		assert(_mm256_testz_si256(test256, test256));
	}
	printRes("x256                               ", x256);
	__mmask32 m32 = _INSTLATX64_DEMO_TESTMASK_32;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_srli_gfni_epi8            ", _mm256_srli_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_srli_gfni_epi8      ", _mm256_maskz_srli_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_srli_gfni_epi8       ", _mm256_mask_srli_gfni_epi8(y256, m32, x256, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_slli_gfni_epi8            ", _mm256_slli_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_slli_gfni_epi8      ", _mm256_maskz_slli_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_slli_gfni_epi8       ", _mm256_mask_slli_gfni_epi8(y256, m32, x256, r));
#endif
	}

#if defined(__AVX512F__)
	__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07), y512 = _mm512_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m512i temp512		= _mm512_or_si512(_mm512_srli_gfni_epi8(x512, r), _mm512_slli_gfni_epi8(x512, 8 - r));
		__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_or_si512(_mm512_slli_gfni_epi8(temp512, r), _mm512_srli_gfni_epi8(temp512, 8 - r)));
		assert(test512);

	}
	printRes("x512                               ", x512);
	__mmask64 m64 = _INSTLATX64_DEMO_TESTMASK_64;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_srli_gfni_epi8            ", _mm512_srli_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_srli_gfni_epi8      ", _mm512_maskz_srli_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_srli_gfni_epi8       ", _mm512_mask_srli_gfni_epi8(y512, m64, x512, r));
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_slli_gfni_epi8            ", _mm512_slli_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_slli_gfni_epi8      ", _mm512_maskz_slli_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_slli_gfni_epi8       ", _mm512_mask_slli_gfni_epi8(y512, m64, x512, r));
	}
#endif
#endif
}

void GFNI_Demo_shift_epi8(void) {
	const int maxrot = 9;
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m128i temp128 = _mm_or_si128(_mm_srl_gfni_epi8(x128, _mm_cvtsi32_si128(r)), _mm_sll_gfni_epi8(x128, _mm_cvtsi32_si128(8 - r)));
		__m128i test128	= _mm_xor_si128(x128, _mm_or_si128(_mm_sll_gfni_epi8(temp128, _mm_cvtsi32_si128(r)), _mm_srl_gfni_epi8(temp128, _mm_cvtsi32_si128(8 - r))));
		assert(_mm_testz_si128(test128, test128));
	}
	printRes("x128                               ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_srl_gfni_epi8                ", _mm_srl_gfni_epi8(x128, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_srl_gfni_epi8          ", _mm_maskz_srl_gfni_epi8(m16, x128, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm_mask_srl_gfni_epi8           ", _mm_mask_srl_gfni_epi8(y128, m16, x128, _mm_cvtsi32_si128(r)));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_sll_gfni_epi8                ", _mm_sll_gfni_epi8(x128, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_sll_gfni_epi8          ", _mm_maskz_sll_gfni_epi8(m16, x128, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm_mask_sll_gfni_epi8           ", _mm_mask_sll_gfni_epi8(y128, m16, x128, _mm_cvtsi32_si128(r)));
#endif
	}

#if defined(__AVX2__)
	__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m256i temp256 = _mm256_or_si256(_mm256_srl_gfni_epi8(x256, _mm_cvtsi32_si128(r)), _mm256_sll_gfni_epi8(x256, _mm_cvtsi32_si128(8 - r)));
		__m256i test256	= _mm256_xor_si256(x256, _mm256_or_si256(_mm256_sll_gfni_epi8(temp256, _mm_cvtsi32_si128(r)), _mm256_srl_gfni_epi8(temp256, _mm_cvtsi32_si128(8 - r))));
		assert(_mm256_testz_si256(test256, test256));
	}
	printRes("x256                               ", x256);
	__mmask32 m32 = _INSTLATX64_DEMO_TESTMASK_32;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_srl_gfni_epi8             ", _mm256_srl_gfni_epi8(x256, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_srl_gfni_epi8       ", _mm256_maskz_srl_gfni_epi8(m32, x256, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm256_mask_srl_gfni_epi8        ", _mm256_mask_srl_gfni_epi8(y256, m32, x256, _mm_cvtsi32_si128(r)));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_sll_gfni_epi8             ", _mm256_sll_gfni_epi8(x256, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_sll_gfni_epi8       ", _mm256_maskz_sll_gfni_epi8(m32, x256, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm256_mask_sll_gfni_epi8        ", _mm256_mask_sll_gfni_epi8(y256, m32, x256, _mm_cvtsi32_si128(r)));
#endif
	}

#if defined(__AVX512F__)
	__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07), y512 = _mm512_set1_epi8(0x7f);
	for (int r = 0; r < maxrot; r++) {
		__m512i temp512		= _mm512_or_si512(_mm512_srl_gfni_epi8(x512, _mm_cvtsi32_si128(r)), _mm512_sll_gfni_epi8(x512, _mm_cvtsi32_si128(8 - r)));
		__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_or_si512(_mm512_sll_gfni_epi8(temp512, _mm_cvtsi32_si128(r)), _mm512_srl_gfni_epi8(temp512, _mm_cvtsi32_si128(8 - r))));
		assert(test512);

	}
	printRes("x512                               ", x512);
	__mmask64 m64 = _INSTLATX64_DEMO_TESTMASK_64;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_srl_gfni_epi8             ", _mm512_srl_gfni_epi8(x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_maskz_srl_gfni_epi8       ", _mm512_maskz_srl_gfni_epi8(m64, x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_mask_srl_gfni_epi8        ", _mm512_mask_srl_gfni_epi8(y512, m64, x512, _mm_cvtsi32_si128(r)));
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_sll_gfni_epi8             ", _mm512_sll_gfni_epi8(x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_maskz_sll_gfni_epi8       ", _mm512_maskz_sll_gfni_epi8(m64, x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_mask_sll_gfni_epi8        ", _mm512_mask_sll_gfni_epi8(y512, m64, x512, _mm_cvtsi32_si128(r)));
	}
#endif
#endif
}

void GFNI_Demo_arith_shifti_epi8(void) {
	const int maxrot = 9;
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m128i temp128 = _mm_or_si128(_mm_srai_gfni_epi8(x128, r), _mm_slai_gfni_epi8(x128, 8 - r));
	//	__m128i test128	= _mm_xor_si128(x128, _mm_or_si128(_mm_slai_gfni_epi8(temp128, r), _mm_srai_gfni_epi8(temp128, 8 - r)));
	//	assert(_mm_testz_si128(test128, test128));
	//}
	printRes("x128                               ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_srai_gfni_epi8               ", _mm_srai_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_srai_gfni_epi8         ", _mm_maskz_srai_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_srai_gfni_epi8          ", _mm_mask_srai_gfni_epi8(y128, m16, x128, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_slai_gfni_epi8               ", _mm_slai_gfni_epi8(x128, r));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_slai_gfni_epi8         ", _mm_maskz_slai_gfni_epi8(m16, x128, r));
		printRes(r, "_mm_mask_slai_gfni_epi8          ", _mm_mask_slai_gfni_epi8(y128, m16, x128, r));
#endif
	}

#if defined(__AVX2__)
	__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m256i temp256 = _mm256_or_si256(_mm256_srai_gfni_epi8(x256, r), _mm256_slai_gfni_epi8(x256, 8 - r));
	//	__m256i test256	= _mm256_xor_si256(x256, _mm256_or_si256(_mm256_slai_gfni_epi8(temp256, r), _mm256_srai_gfni_epi8(temp256, 8 - r)));
	//	assert(_mm256_testz_si256(test256, test256));
	//}
	printRes("x256                               ", x256);
	__mmask32 m32 = _INSTLATX64_DEMO_TESTMASK_32;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_srai_gfni_epi8            ", _mm256_srai_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_srai_gfni_epi8      ", _mm256_maskz_srai_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_srai_gfni_epi8       ", _mm256_mask_srai_gfni_epi8(y256, m32, x256, r));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_slai_gfni_epi8            ", _mm256_slai_gfni_epi8(x256, r));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_slai_gfni_epi8      ", _mm256_maskz_slai_gfni_epi8(m32, x256, r));
		printRes(r, "_mm256_mask_slai_gfni_epi8       ", _mm256_mask_slai_gfni_epi8(y256, m32, x256, r));
#endif
	}

#if defined(__AVX512F__)
	__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07), y512 = _mm512_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m512i temp512		= _mm512_or_si512(_mm512_srai_gfni_epi8(x512, r), _mm512_slai_gfni_epi8(x512, 8 - r));
	//	__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_or_si512(_mm512_slai_gfni_epi8(temp512, r), _mm512_srai_gfni_epi8(temp512, 8 - r)));
	//	assert(test512);

	//}
	printRes("x512                               ", x512);
	__mmask64 m64 = _INSTLATX64_DEMO_TESTMASK_64;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_srai_gfni_epi8            ", _mm512_srai_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_srai_gfni_epi8      ", _mm512_maskz_srai_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_srai_gfni_epi8       ", _mm512_mask_srai_gfni_epi8(y512, m64, x512, r));
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_slai_gfni_epi8            ", _mm512_slai_gfni_epi8(x512, r));
		printRes(r, "_mm512_maskz_slai_gfni_epi8      ", _mm512_maskz_slai_gfni_epi8(m64, x512, r));
		printRes(r, "_mm512_mask_slai_gfni_epi8       ", _mm512_mask_slai_gfni_epi8(y512, m64, x512, r));
	}
#endif
#endif
}

void GFNI_Demo_arith_shift_epi8(void) {
	const int maxrot = 9;
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m128i temp128 = _mm_or_si128(_mm_sra_gfni_epi8(x128, _mm_cvtsi32_si128(r)), _mm_sla_gfni_epi8(x128, _mm_cvtsi32_si128(8 - r)));
	//	__m128i test128	= _mm_xor_si128(x128, _mm_or_si128(_mm_sla_gfni_epi8(temp128, _mm_cvtsi32_si128(r)), _mm_sra_gfni_epi8(temp128, _mm_cvtsi32_si128(8 - r))));
	//	assert(_mm_testz_si128(test128, test128));
	//}
	printRes("x128                               ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_sra_gfni_epi8                ", _mm_sra_gfni_epi8(x128, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_sra_gfni_epi8          ", _mm_maskz_sra_gfni_epi8(m16, x128, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm_mask_sra_gfni_epi8           ", _mm_mask_sra_gfni_epi8(y128, m16, x128, _mm_cvtsi32_si128(r)));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm_sla_gfni_epi8                ", _mm_sla_gfni_epi8(x128, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm_maskz_sla_gfni_epi8          ", _mm_maskz_sla_gfni_epi8(m16, x128, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm_mask_sla_gfni_epi8           ", _mm_mask_sla_gfni_epi8(y128, m16, x128, _mm_cvtsi32_si128(r)));
#endif
	}

#if defined(__AVX2__)
	__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m256i temp256 = _mm256_or_si256(_mm256_sra_gfni_epi8(x256, _mm_cvtsi32_si128(r)), _mm256_sla_gfni_epi8(x256, _mm_cvtsi32_si128(8 - r)));
	//	__m256i test256	= _mm256_xor_si256(x256, _mm256_or_si256(_mm256_sla_gfni_epi8(temp256, _mm_cvtsi32_si128(r)), _mm256_sra_gfni_epi8(temp256, _mm_cvtsi32_si128(8 - r))));
	//	assert(_mm256_testz_si256(test256, test256));
	//}
	printRes("x256                               ", x256);
	__mmask32 m32 = _INSTLATX64_DEMO_TESTMASK_32;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_sra_gfni_epi8             ", _mm256_sra_gfni_epi8(x256, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_sra_gfni_epi8       ", _mm256_maskz_sra_gfni_epi8(m32, x256, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm256_mask_sra_gfni_epi8        ", _mm256_mask_sra_gfni_epi8(y256, m32, x256, _mm_cvtsi32_si128(r)));
#endif
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm256_sla_gfni_epi8             ", _mm256_sla_gfni_epi8(x256, _mm_cvtsi32_si128(r)));
#if defined(__AVX512F__)
		printRes(r, "_mm256_maskz_sla_gfni_epi8       ", _mm256_maskz_sla_gfni_epi8(m32, x256, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm256_mask_sla_gfni_epi8        ", _mm256_mask_sla_gfni_epi8(y256, m32, x256, _mm_cvtsi32_si128(r)));
#endif
	}

#if defined(__AVX512F__)
	__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07), y512 = _mm512_set1_epi8(0x7f);
	//for (int r = 0; r < maxrot; r++) {
	//	__m512i temp512		= _mm512_or_si512(_mm512_sra_gfni_epi8(x512, _mm_cvtsi32_si128(r)), _mm512_sla_gfni_epi8(x512, _mm_cvtsi32_si128(8 - r)));
	//	__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_or_si512(_mm512_sla_gfni_epi8(temp512, _mm_cvtsi32_si128(r)), _mm512_sra_gfni_epi8(temp512, _mm_cvtsi32_si128(8 - r))));
	//	assert(test512);
	//}
	printRes("x512                               ", x512);
	__mmask64 m64 = _INSTLATX64_DEMO_TESTMASK_64;
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_sra_gfni_epi8             ", _mm512_sra_gfni_epi8(x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_maskz_sra_gfni_epi8       ", _mm512_maskz_sra_gfni_epi8(m64, x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_mask_sra_gfni_epi8        ", _mm512_mask_sra_gfni_epi8(y512, m64, x512, _mm_cvtsi32_si128(r)));
	}
	for (int r = 0; r < maxrot; r++) {
		printRes(r, "_mm512_sla_gfni_epi8             ", _mm512_sla_gfni_epi8(x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_maskz_sla_gfni_epi8       ", _mm512_maskz_sla_gfni_epi8(m64, x512, _mm_cvtsi32_si128(r)));
		printRes(r, "_mm512_mask_sla_gfni_epi8        ", _mm512_mask_sla_gfni_epi8(y512, m64, x512, _mm_cvtsi32_si128(r)));
	}
#endif
#endif
}

void GFNI_Demo_inverse_epi8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	__m128i test128	= _mm_xor_si128(x128, _mm_inverse_epi8(_mm_inverse_epi8(x128)));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                          ", x128);
	printRes("_mm_inverse_epi8              ", _mm_inverse_epi8(x128));

#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_inverse_epi8        ", _mm_maskz_inverse_epi8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
		printRes("_mm_mask_inverse_epi8         ", _mm_mask_inverse_epi8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
	}
#endif
#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
		__m256i test256	= _mm256_xor_si256(x256, _mm256_inverse_epi8(_mm256_inverse_epi8(x256)));
		assert(_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_inverse_epi8           ", _mm256_inverse_epi8(x256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_inverse_epi8     ", _mm256_maskz_inverse_epi8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));
			printRes("_mm256_mask_inverse_epi8      ", _mm256_mask_inverse_epi8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));

			__m512i		x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y512 = _mm512_set1_epi8(0x7f);
			__mmask64	test512	= _mm512_cmpeq_epi8_mask(x512,  _mm512_inverse_epi8(_mm512_inverse_epi8(x512)));
			assert(test512);

			printRes("x512                          ", x512);
			printRes("_mm512_inverse_epi8           ", _mm512_inverse_epi8(x512));
			printRes("_mm512_maskz_inverse_epi8     ", _mm512_maskz_inverse_epi8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
			printRes("_mm512_mask_inverse_epi8      ", _mm512_mask_inverse_epi8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
		}
#endif
	}
#endif
}

void GFNI_Demo_set1_epi8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	//__m128i test128	= _mm_xor_si128(x128, _mm_set1_gfni_epi8(_mm_set1_gfni_epi8(x128)));
	//assert(_mm_testz_si128(test128, test128));

	printRes("x128                          ", x128);
	printRes("_mm_set1_gfni_epi8            ", _mm_set1_gfni_epi8(0xbd));

#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_set1_gfni_epi8      ", _mm_maskz_set1_gfni_epi8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, 0xbd));
		printRes("_mm_mask_set1_gfni_epi8       ", _mm_mask_set1_gfni_epi8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, 0xbd));
	}
#endif
#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
		//__m256i test256	= _mm256_xor_si256(x256, _mm256_set1_gfni_epi8(_mm256_set1_gfni_epi8(x256)));
		//assert(_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_set1_gfni_epi8         ", _mm256_set1_gfni_epi8(0xbd));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_set1_gfni_epi8   ", _mm256_maskz_set1_gfni_epi8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, 0xbd));
			printRes("_mm256_mask_set1_gfni_epi8    ", _mm256_mask_set1_gfni_epi8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, 0xbd));

			__m512i		x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y512 = _mm512_set1_epi8(0x7f);
			//__mmask64	test512	= _mm512_cmpeq_epi8_mask(x512,  _mm512_set1_gfni_epi8(_mm512_set1_gfni_epi8(x512)));
			//assert(test512);

			printRes("x512                          ", x512);
			printRes("_mm512_set1_gfni_epi8         ", _mm512_set1_gfni_epi8(0xbd));
			printRes("_mm512_maskz_set1_gfni_epi8   ", _mm512_maskz_set1_gfni_epi8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, 0xbd));
			printRes("_mm512_mask_set1_gfni_epi8    ", _mm512_mask_set1_gfni_epi8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, 0xbd));
		}
#endif
	}
#endif
}

void GFNI_Demo_revbit_epi8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	__m128i test128	= _mm_xor_si128(x128,  _mm_revbit_epi8(_mm_revbit_epi8(x128)));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                          ", x128);
	printRes("_mm_revbit_epi8               ", _mm_revbit_epi8(x128));

#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_revbit_epi8         ", _mm_maskz_revbit_epi8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
		printRes("_mm_mask_revbit_epi8          ", _mm_mask_revbit_epi8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
	}
#endif
#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
		__m256i test256	= _mm256_xor_si256(x256,  _mm256_revbit_epi8(_mm256_revbit_epi8(x256)));
		assert(_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_revbit_epi8            ", _mm256_revbit_epi8(x256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_revbit_epi8      ", _mm256_maskz_revbit_epi8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));
			printRes("_mm256_mask_revbit_epi8       ", _mm256_mask_revbit_epi8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));

			__m512i		x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y512 = _mm512_set1_epi8(0x7f);
			__mmask64	test512	= _mm512_cmpeq_epi8_mask(x512,  _mm512_revbit_epi8(_mm512_revbit_epi8(x512)));
			assert(test512);

			printRes("x512                          ", x512);
			printRes("_mm512_revbit_epi8            ", _mm512_revbit_epi8(x512));
			printRes("_mm512_maskz_revbit_epi8      ", _mm512_maskz_revbit_epi8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
			printRes("_mm512_mask_revbit_epi8       ", _mm512_mask_revbit_epi8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
		}
#endif
	}
#endif
}

void GFNI_Demo_bcstbit_epi8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);

	printRes("x128                          ", x128);
	printRes("_mm_bcstbit_epi8              ", _mm_bcstbit_epi8(x128, 0));

#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_bcstbit_epi8        ", _mm_maskz_bcstbit_epi8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128, 0));
		printRes("_mm_mask_bcstbit_epi8         ", _mm_mask_bcstbit_epi8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128, 0));
	}
#endif
#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);

		printRes("x256                          ", x256);
		printRes("_mm256_bcstbit_epi8           ", _mm256_bcstbit_epi8(x256, 1));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_bcstbit_epi8     ", _mm256_maskz_bcstbit_epi8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256, 1));
			printRes("_mm256_mask_bcstbit_epi8      ", _mm256_mask_bcstbit_epi8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256, 1));

			__m512i		x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y512 = _mm512_set1_epi8(0x7f);

			printRes("x512                          ", x512);
			printRes("_mm512_bcstbit_epi8           ", _mm512_bcstbit_epi8(x512, 2));
			printRes("_mm512_maskz_bcstbit_epi8     ", _mm512_maskz_bcstbit_epi8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512, 2));
			printRes("_mm512_mask_bcstbit_epi8      ", _mm512_mask_bcstbit_epi8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512, 2));
		}
#endif
	}
#endif
}

void GFNI_Demo_rotate_8x8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);
	__m128i test128	= _mm_xor_si128(x128, _mm_rotate_8x8(_mm_rotate_8x8(_mm_rotate_8x8(_mm_rotate_8x8(x128)))));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                          ", x128);
	printRes("_mm_rotate_8x8                ", _mm_rotate_8x8(x128));
#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_rotate_8x8          ", _mm_maskz_rotate_8x8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
		printRes("_mm_mask_rotate_8x8           ", _mm_mask_rotate_8x8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
	}
#endif
#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05), y256 = _mm256_set1_epi8(0x7f);
		__m256i test256 = _mm256_xor_si256(x256, _mm256_rotate_8x8(_mm256_rotate_8x8(_mm256_rotate_8x8(_mm256_rotate_8x8(x256)))));
		assert (_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_rotate_8x8             ", _mm256_rotate_8x8(x256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_rotate_8x8       ", _mm256_maskz_rotate_8x8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));
			printRes("_mm256_mask_rotate_8x8        ", _mm256_mask_rotate_8x8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));

			__m512i x512 = _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07, _INSTLATX64_DEMO_TESTVECT_08, _INSTLATX64_DEMO_TESTVECT_09), y512 = _mm512_set1_epi8(0x7f);
			__mmask64 test512 =_mm512_cmpeq_epi8_mask(x512, _mm512_rotate_8x8(_mm512_rotate_8x8(_mm512_rotate_8x8(_mm512_rotate_8x8(x512)))));
			assert(test512);

			printRes("x512                          ", x512);
			printRes("_mm512_rotate_8x8             ", _mm512_rotate_8x8(x512));
			printRes("_mm512_maskz_rotate_8x8       ", _mm512_maskz_rotate_8x8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
			printRes("_mm512_mask_rotate_8x8        ", _mm512_mask_rotate_8x8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
		}
#endif
	}
#endif
}

void GFNI_Demo_mirror_8x8(void) {
	__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y128 = _mm_set1_epi8(0x7f);
	__m128i test128	= _mm_xor_si128(x128,_mm_mirror_8x8(_mm_mirror_8x8(x128)));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                          ", x128);
	printRes("_mm_mirror_8x8                ", _mm_mirror_8x8(x128));
#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_mirror_8x8          ", _mm_maskz_mirror_8x8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
		printRes("_mm_mask_mirror_8x8           ", _mm_mask_mirror_8x8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
	}
#endif

#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05), y256 = _mm256_set1_epi8(0x7f);
		__m256i test256 = _mm256_xor_si256(x256, _mm256_mirror_8x8(_mm256_mirror_8x8(x256)));
		assert (_mm256_testz_si256(test256, test256));

		printRes("x256                          ", x256);
		printRes("_mm256_mirror_8x8             ", _mm256_mirror_8x8(x256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_mirror_8x8       ", _mm256_maskz_mirror_8x8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));
			printRes("_mm256_mask_mirror_8x8        ", _mm256_mask_mirror_8x8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));

			__m512i x512 = _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_06, _INSTLATX64_DEMO_TESTVECT_07, _INSTLATX64_DEMO_TESTVECT_08, _INSTLATX64_DEMO_TESTVECT_09), y512 = _mm512_set1_epi8(0x7f);
			__mmask64 test512 =_mm512_cmpeq_epi8_mask(x512, _mm512_mirror_8x8(_mm512_mirror_8x8(x512)));
			assert(test512);

			printRes("x512                          ", x512);
			printRes("_mm512_mirror_8x8             ", _mm512_mirror_8x8(x512));
			printRes("_mm512_maskz_mirror_8x8       ", _mm512_maskz_mirror_8x8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
			printRes("_mm512_mask_mirror_8x8        ", _mm512_mask_mirror_8x8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
		}
#endif
	}
#endif
}

void GFNI_Demo_multiplication_8x8(void) {
	__m128i x128 = _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05), y128 = _mm_set1_epi8(0x7f), unit128 = _mm_set1_epi64x(0x0102040810204080);

	printRes("x128                          ", x128);
	printRes("_mm_multiplication_8x8 xx     ", _mm_multiplication_8x8(x128, x128));
	printRes("_mm_multiplication_8x8 xu     ", _mm_multiplication_8x8(x128, unit128));
	printRes("_mm_multiplication_8x8 ux     ", _mm_multiplication_8x8(unit128, x128));
#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_multiplication_8x8    ", _mm_maskz_multiplication_8x8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128, x128));
		printRes("_mm_mask_multiplication_8x8     ", _mm_mask_multiplication_8x8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128, x128));
	}
#endif

#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f), z256 = _mm256_set1_epi64x(0x0102040810204080), w256 = _mm256_set1_epi64x(0x8040201008040201);
		printRes("x256                            ", x256);
		printRes("_mm256_multiplication_8x8       ", _mm256_multiplication_8x8(x256, z256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_multiplication_8x8 ", _mm256_maskz_multiplication_8x8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256, x256));
			printRes("_mm256_mask_multiplication_8x8  ", _mm256_mask_multiplication_8x8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256, x256));

			__m512i x512 = _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_04, _INSTLATX64_DEMO_TESTVECT_05, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y512 = _mm512_set1_epi8(0x7f), z512 = _mm512_set1_epi64(0x0102040810204080), w512 = _mm512_set1_epi64(0x8040201008040201);;
			printRes("x512                            ", x512);
			printRes("_mm512_multiplication_8x8       ", _mm512_multiplication_8x8(x512, x512));
			printRes("_mm512_maskz_multiplication_8x8 ", _mm512_maskz_multiplication_8x8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512, x512));
			printRes("_mm512_mask_multiplication_8x8  ", _mm512_mask_multiplication_8x8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512, x512));
		}
#endif
	}
#endif
}

void GFNI_Demo_prefix_xor_epi8(void) {
	__m128i x128 = _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01), y128 = _mm_set1_epi8(0x7f);

	printRes("x128                          ", x128);
	printRes("_mm_prefix_xor_epi8           ", _mm_prefix_xor_epi8(x128));
#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512F)) {
		printRes("_mm_maskz_prefix_xor_epi8     ", _mm_maskz_prefix_xor_epi8((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
		printRes("_mm_mask_prefix_xor_epi8      ", _mm_mask_prefix_xor_epi8(y128, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x128));
	}
#endif

#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_AVX)) {
		__m256i x256 = _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03), y256 = _mm256_set1_epi8(0x7f);
		printRes("x256                          ", x256);
		printRes("_mm256_prefix_xor_epi8        ", _mm256_prefix_xor_epi8(x256));
#if defined(__AVX512F__)
		if (cpu_props.IsFeat(ISA_AVX512F)) {
			printRes("_mm256_maskz_prefix_xor_epi8  ", _mm256_maskz_prefix_xor_epi8((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));
			printRes("_mm256_mask_prefix_xor_epi8   ", _mm256_mask_prefix_xor_epi8(y256, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x256));

			__m512i x512 = _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_0A, _INSTLATX64_DEMO_TESTVECT_0A, _INSTLATX64_DEMO_TESTVECT_0B, _INSTLATX64_DEMO_TESTVECT_0B), y512 = _mm512_set1_epi8(0x7f);
			printRes("x512                          ", x512);
			printRes("_mm512_prefix_xor_epi8        ", _mm512_prefix_xor_epi8(x512));
			printRes("_mm512_maskz_prefix_xor_epi8  ", _mm512_maskz_prefix_xor_epi8((__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
			printRes("_mm512_mask_prefix_xor_epi8   ", _mm512_mask_prefix_xor_epi8(y512, (__mmask64)_INSTLATX64_DEMO_TESTMASK_64, x512));
		}
#endif
	}
#endif
}

#if defined(__AVX512F__) && defined(_M_X64)
void GFNI_Demo_pospopcount_u8() {
	__m128i x128 = _mm_set_epi64x(0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff);//_mm_set1_epi16(0x18);
	__m256i x256 = _mm256_set_epi64x(0x0000000100030007, 0x000f001f003f007f, 0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff);
	__m512i x512 = _mm512_set_epi64(0x0000000100030007, 0x000f001f003f007f, 0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff, 0x7fff3fff1fff0fff, 0x07ff03ff01ff00ff, 0x007f003f001f000f, 0x0007000300010000);


	printRes("x128                               ", x128);
	__m128i res0  = _mm_pospopcnt_u8_si128_epi8(x128);
	printRes("_mm_pospopcnt_u8_si128_epi8        ", res0);

	printRes("x256                               ", x256);
	__m128i res1  = _mm256_pospopcnt_u8_si256_epi8(x256);
	printRes("_mm256_pospopcnt_u8_si256_epi8     ", res1);

	printRes("x512                               ", x512);
	__m128i res2  = _mm512_pospopcnt_u8_si512_epi8(x512);
	printRes("_mm512_pospopcnt_u8_si512_epi8     ", res2);
}

void GFNI_Demo_pospopcount_u16() {
	__m128i x128 = _mm_set_epi64x(0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff);//_mm_set1_epi16(0x18);
	__m256i x256 = _mm256_set_epi64x(0x0000000100030007, 0x000f001f003f007f, 0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff);
	__m512i x512 = _mm512_set_epi64(0x0000000100030007, 0x000f001f003f007f, 0x00ff01ff03ff07ff, 0x0fff1fff3fff7fff,0x7fff3fff1fff0fff, 0x07ff03ff01ff00ff, 0x007f003f001f000f, 0x0007000300010000);
	printRes("x128                               ", x128);
	printRes("_mm_pospopcnt_u16_si128_epi8       ", _mm_pospopcnt_u16_si128_epi8(x128));

	x128 = _mm_set_epi64x(0x7fff3fff1fff0fff, 0x07ff03ff01ff00ff);

	printRes("x128                               ", x128);
	__m128i res0  = _mm_pospopcnt_u16_si128_epi8(x128);
	printRes("_mm_pospopcnt_u16_si128_epi8       ", res0);

	printRes("x256                               ", x256);
	__m128i res1  = _mm256_pospopcnt_u16_si256_epi8(x256);
	printRes("_mm256_pospopcnt_u16_si256_epi8    ", res1);

	printRes("x512                               ", x512);
	__m128i res2  = _mm512_pospopcnt_u16_si512_epi8(x512);
	printRes("_mm512_pospopcnt_u16_si512_epi8    ", res2);

}

void GFNISpeedTest(void) {
	unsigned int AUX = 0;
	volatile unsigned __int64 minres = ULONG_MAX, rdtscp = ULONG_MAX, start = 0;

	const int maxRetry = 100;
	const int maxRepeat = 100000;

	__m128i x128	= _mm_set_epi64x(0x7fbfdfeff7fbfdf7, 0xfefdfbf7efdfbf7f);
	__m256i x256	= _mm256_set_epi64x(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f);
	__m512i x512	= _mm512_set_epi64(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f, 0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f);
	__mmask8 k8 = 0xaa;
	__mmask16 k16 = 0xaaaa;
	__mmask32 k32 = 0xaaaaaaaa;
	__mmask64 k64 = 0xaaaaaaaaaaaaaaaa;

	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x128 = _mm_add_epi8(_mm_ror_gfni_epi8(x128, 6), x128);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm_ror_gfni_epi8(x128, 6)           :%8I64d clks min (%016Ix)\r\n", minres, x128.m128i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x256 = _mm256_add_epi8(_mm256_ror_gfni_epi8(x256, 6), x256);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm256_ror_gfni_epi8(x256, 6)        :%8I64d clks min (%016Ix)\r\n", minres, x256.m256i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x512 = _mm512_add_epi8(_mm512_ror_gfni_epi8(x512, 6), x512);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm512_ror_gfni_epi8(x512, 6)        :%8I64d clks min (%016Ix)\r\n", minres, x512.m512i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x128 = _mm_add_epi8(_mm_mask_ror_gfni_epi8(x128, k16, x128, 6), x128);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm_mask_ror_gfni_epi8(x128, 6)      :%8I64d clks min (%016Ix)\r\n", minres, x128.m128i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x256 = _mm256_add_epi8(_mm256_mask_ror_gfni_epi8(x256, k32, x256, 6), x256);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm256_mask_ror_gfni_epi8(x256, 6)   :%8I64d clks min (%016Ix)\r\n", minres, x256.m256i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = serialized_tsc();
		for (int rep = 0; rep < maxRepeat; rep++) {
			x512 = _mm512_add_epi8(_mm512_mask_ror_gfni_epi8(x512, k64, x512, 6), x512);
		}
		minres = min(minres, serialized_tsc() - start);
	}
	printf("_mm512_mask_ror_gfni_epi8(x512, 6)   :%8I64d clks min (%016Ix)\r\n", minres, x512.m512i_u64[0]);
};
#endif

void GFNI_Demo(void) {
	cout << "-----------------------------------" << endl;
	GFNI_Demo_rotate_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_shifti_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_shift_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_arith_shifti_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_arith_shift_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_inverse_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_set1_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_revbit_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_bcstbit_epi8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_rotate_8x8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_mirror_8x8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_multiplication_8x8();
	cout << "-----------------------------------" << endl;
	GFNI_Demo_prefix_xor_epi8();

#if defined(__AVX512F__) && (_M_X64)
	cout << "-----------------------------------" << endl;
	if (cpu_props.IsFeat(ISA_AVX512_VPOPCNTDQ) && cpu_props.IsFeat(ISA_AVX512_BITALG))
			GFNI_Demo_pospopcount_u8();
	cout << "-----------------------------------" << endl;
	if (cpu_props.IsFeat(ISA_AVX512_VPOPCNTDQ) && cpu_props.IsFeat(ISA_AVX512_BITALG))
			GFNI_Demo_pospopcount_u16();
	cout << "-----------------------------------" << endl;
	GFNISpeedTest();
#endif
}
