#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;


#if defined(__AVX512F__)

void VBMI2_Demo_rotate_epi16(void) {
	if (cpu_props.IsFeat(ISA_AVX512VL)) {
		__m128i x128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01);
		__m128i y128	= _mm_set_epi64x(_INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF);
		__m128i one128	= _mm_set1_epi64x(_INSTLATX64_DEMO_TESTVECT_0B * 4);
		__m128i test128	= _mm_xor_si128(x128, _mm_rolv_vbmi2_epi16(_mm_rorv_vbmi2_epi16(x128, one128), one128));
		assert(_mm_testz_si128(test128, test128));

		test128	= _mm_xor_si128(x128, _mm_rol_vbmi2_epi16(_mm_ror_vbmi2_epi16(x128, 4), 4));
		assert(_mm_testz_si128(test128, test128));

		printRes("x128                                ", x128);
		printRes("_mm_rorv_vbmi2_epi16                ", _mm_rorv_vbmi2_epi16(x128, one128));
		printRes("_mm_ror_vbmi2_epi16                 ", _mm_ror_vbmi2_epi16(x128, 4));
		printRes("_mm_maskz_rorv_vbmi2_epi16          ", _mm_maskz_rorv_vbmi2_epi16((__mmask8)_INSTLATX64_DEMO_TESTMASK_8, x128, one128));
		printRes("_mm_maskz_ror_vbmi2_epi16           ", _mm_maskz_ror_vbmi2_epi16((__mmask8)_INSTLATX64_DEMO_TESTMASK_8, x128, 4));
		printRes("_mm_mask_rorv_vbmi2_epi16           ", _mm_mask_rorv_vbmi2_epi16(y128, (__mmask8)_INSTLATX64_DEMO_TESTMASK_8, x128, one128));
		printRes("_mm_mask_ror_vbmi2_epi16            ", _mm_mask_ror_vbmi2_epi16(y128, (__mmask8)_INSTLATX64_DEMO_TESTMASK_8, x128, 4));

		__m256i x256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03);
		__m256i y256	= _mm256_set_epi64x(_INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF, _INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF);
		__m256i one256	= _mm256_set1_epi64x(_INSTLATX64_DEMO_TESTVECT_0B * 8);
		__m256i test256	= _mm256_xor_si256(x256, _mm256_rolv_vbmi2_epi16(_mm256_rorv_vbmi2_epi16(x256, one256), one256));
		assert(_mm256_testz_si256(test256, test256));

		test256	= _mm256_xor_si256(x256, _mm256_rol_vbmi2_epi16(_mm256_ror_vbmi2_epi16(x256, 8), 8));
		assert(_mm256_testz_si256(test256, test256));

		printRes("x256                                ", x256);
		printRes("_mm256_rorv_vbmi2_epi16             ", _mm256_rorv_vbmi2_epi16(x256, one256));
		printRes("_mm256_ror_vbmi2_epi16              ", _mm256_ror_vbmi2_epi16(x256, 8));
		printRes("_mm256_maskz_rorv_vbmi2_epi16       ", _mm256_maskz_rorv_vbmi2_epi16((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x256, one256));
		printRes("_mm256_maskz_ror_vbmi2_epi16        ", _mm256_maskz_ror_vbmi2_epi16((__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x256, 8));
		printRes("_mm256_mask_rorv_vbmi2_epi16        ", _mm256_mask_rorv_vbmi2_epi16(y256, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x256, one256));
		printRes("_mm256_mask_ror_vbmi2_epi16         ", _mm256_mask_ror_vbmi2_epi16(y256, (__mmask16)_INSTLATX64_DEMO_TESTMASK_16, x256, 8));

		__m512i x512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03, _INSTLATX64_DEMO_TESTVECT_00, _INSTLATX64_DEMO_TESTVECT_01, _INSTLATX64_DEMO_TESTVECT_02, _INSTLATX64_DEMO_TESTVECT_03);
		__m512i y512	= _mm512_set_epi64(_INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF, _INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF, _INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF, _INSTLATX64_DEMO_TESTVECT_FE, _INSTLATX64_DEMO_TESTVECT_FF);
		__m512i one512	= _mm512_set1_epi64(_INSTLATX64_DEMO_TESTVECT_0B * 16);
		__mmask64	test512	= _mm512_cmpeq_epi8_mask(x512,  _mm512_rolv_vbmi2_epi16(_mm512_rorv_vbmi2_epi16(x512, one512), one512));
		assert(test512);

		test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_rol_vbmi2_epi16(_mm512_ror_vbmi2_epi16(x512, 16), 16));
		assert(test512);

		printRes("x512                                ", x512);
		printRes("_mm512_rorv_vbmi2_epi16             ", _mm512_rorv_vbmi2_epi16(x512, one512));
		printRes("_mm512_ror_vbmi2_epi16              ", _mm512_ror_vbmi2_epi16(x512, 16));
		printRes("_mm512_maskz_rorv_vbmi2_epi16       ", _mm512_maskz_rorv_vbmi2_epi16((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x512, one512));
		printRes("_mm512_maskz_ror_vbmi2_epi16        ", _mm512_maskz_ror_vbmi2_epi16((__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x512, 16));
		printRes("_mm512_mask_rorv_vbmi2_epi16        ", _mm512_mask_rorv_vbmi2_epi16(y512, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x512, one512));
		printRes("_mm512_mask_ror_vbmi2_epi16         ", _mm512_mask_ror_vbmi2_epi16(y512, (__mmask32)_INSTLATX64_DEMO_TESTMASK_32, x512, 16));
	}
}

void VBMI2_Demo(void) {
	cout << "-----------------------------------" << endl;
	VBMI2_Demo_rotate_epi16();
}

#endif

