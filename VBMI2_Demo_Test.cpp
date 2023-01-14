#include "stdafx.h"
#include "GFNI_Demo.h"
#include "VBMI2_Demo.h"

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

void VBMI2_Demo_rotatev_epi8(void) {
	__m128i x128	= _mm_set_epi64x(0x7fbfdfeff7fbfdfe, 0x8040201008040201), y128 = _mm_set_epi64x(0xfffefdfcfbfaf9f8, 0xf7f6f5f4f3f2f1f0);
	__m128i test128	= _mm_xor_si128(x128, _mm_rolv_vbmi2_epi8(_mm_rorv_vbmi2_epi8(x128, y128), y128));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                               ", x128);
	printRes("y128                               ", y128);
	printRes("_mm_rorv_vbmi2_epi8(x128, y128)    ", _mm_rorv_vbmi2_epi8(x128, y128));
	printRes("_mm_rolv_vbmi2_epi8(x128, y128)    ", _mm_rolv_vbmi2_epi8(x128, y128));

	__m128i full128 = _mm_set1_epi32(0xffffffff);
	printRes("_mm_maskz_rorv_vbmi2_epi8          ", _mm_maskz_rorv_vbmi2_epi8((__mmask16)0xaa55, x128, y128));
	printRes("_mm_mask_rorv_vbmi2_epi8           ", _mm_mask_rorv_vbmi2_epi8(full128, (__mmask16)0xaa55, x128, y128));
	printRes("_mm_maskz_rolv_vbmi2_epi8          ", _mm_maskz_rolv_vbmi2_epi8((__mmask16)0xac35, x128, y128));
	printRes("_mm_mask_rolv_vbmi2_epi8           ", _mm_mask_rolv_vbmi2_epi8(full128, (__mmask16)0xac35, x128, y128));

	__m256i x256	= _mm256_set_epi64x(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f), y256 = _mm256_set_epi64x(0xfffefdfcfbfaf9f8, 0xf7f6f5f4f3f2f1f0, 0x0f0e0d0c0b0a0908, 0x0706050403020100);
	__m256i test256	= _mm256_xor_si256(x256, _mm256_rolv_vbmi2_epi8(_mm256_rorv_vbmi2_epi8(x256, y256), y256));
	assert(_mm256_testz_si256(test256, test256));

	printRes("x256                               ", x256);
	printRes("y256                               ", y256);
	printRes("_mm256_rorv_vbmi2_epi8(x256, y256) ", _mm256_rorv_vbmi2_epi8(x256, y256));
	printRes("_mm256_rolv_vbmi2_epi8(x256, y256) ", _mm256_rolv_vbmi2_epi8(x256, y256));

	__m256i full256 = _mm256_set1_epi32(0xffffffff);
	printRes("_mm256_maskz_rorv_vbmi2_epi8       ", _mm256_maskz_rorv_vbmi2_epi8((__mmask32)0xcc33aa55, x256, y256));
	printRes("_mm256_mask_rorv_vbmi2_epi8        ", _mm256_mask_rorv_vbmi2_epi8(full256, (__mmask32)0xcc33aa55, x256, y256));
	printRes("_mm256_maskz_rolv_vbmi2_epi8       ", _mm256_maskz_rolv_vbmi2_epi8((__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_mask_rolv_vbmi2_epi8        ", _mm256_mask_rolv_vbmi2_epi8(full256, (__mmask32)0xac35f0a50f, x256, y256));

	__m512i x512 = _mm512_set_epi64(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f, 0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f);
	__m512i y512 = _mm512_set_epi64(0xfffefdfcfbfaf9f8, 0xf7f6f5f4f3f2f1f0, 0xefeeedecebeae9e8, 0xe7e6e5e4e3e2e1e0, 0x1f1e1d1c1b1a1918, 0x1716151413121110, 0x0f0e0d0c0b0a0908, 0x0706050403020100);
	__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_rolv_vbmi2_epi8(_mm512_rorv_vbmi2_epi8(x512, y512), y512));
	assert(test512);

	printRes("x512                               ", x512);
	printRes("y512                               ", y512);
	printRes("_mm512_rorv_vbmi2_epi8(x512, y512) ", _mm512_rorv_vbmi2_epi8(x512, y512));
	printRes("_mm512_rolv_vbmi2_epi8(x512, y512) ", _mm512_rolv_vbmi2_epi8(x512, y512));

	__m512i full512 = _mm512_set1_epi32(0xffffffff);
	printRes("_mm512_maskz_rorv_vbmi2_epi8       ", _mm512_maskz_rorv_vbmi2_epi8((__mmask64)0xcc33aa55cc33aa55, x512, y512));
	printRes("_mm512_mask_rorv_vbmi2_epi8        ", _mm512_mask_rorv_vbmi2_epi8(full512, (__mmask64)0xcc33aa55cc33aa55, x512, y512));
	printRes("_mm512_maskz_rolv_vbmi2_epi8       ", _mm512_maskz_rolv_vbmi2_epi8((__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_mask_rolv_vbmi2_epi8        ", _mm512_mask_rolv_vbmi2_epi8(full512, (__mmask64)0xf00faa5533ccff00, x512, y512));
}

void VBMI2_Demo_shiftv_epi8(void) {
	__m128i x128	= _mm_set_epi64x(0x7fbfdfeff7fbfdfe, 0x8040201008040201), y128 = _mm_set_epi64x(0x0807060504030201, 0x0706050403020100);

	__m128i temp128 = _mm_or_si128(_mm_srlv_vbmi2_epi8(x128, y128), _mm_sllv_vbmi2_epi8(x128, _mm_sub_epi8(_mm_set1_epi32(0x08080808), y128)));
	__m128i test128	= _mm_xor_si128(x128, _mm_or_si128(_mm_sllv_vbmi2_epi8(temp128, y128), _mm_srlv_vbmi2_epi8(temp128, _mm_sub_epi8(_mm_set1_epi32(0x08080808), y128))));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                               ", x128);
	printRes("y128                               ", y128);
	printRes("_mm_sllv_vbmi2_epi8(x128, y128)    ", _mm_sllv_vbmi2_epi8(x128, y128));
	printRes("_mm_srlv_vbmi2_epi8(x128, y128)    ", _mm_srlv_vbmi2_epi8(x128, y128));
	printRes("_mm_srav_vbmi2_epi8(x128, y128)    ", _mm_srav_vbmi2_epi8(x128, y128));

	__m128i full128 = _mm_set1_epi32(0xffffffff);
	printRes("_mm_maskz_sllv_vbmi2_epi8          ", _mm_maskz_sllv_vbmi2_epi8((__mmask16)0xac35, x128, y128));
	printRes("_mm_mask_sllv_vbmi2_epi8           ", _mm_mask_sllv_vbmi2_epi8(full128, (__mmask16)0xac35, x128, y128));
	printRes("_mm_maskz_srlv_vbmi2_epi8          ", _mm_maskz_srlv_vbmi2_epi8((__mmask16)0xaa55, x128, y128));
	printRes("_mm_mask_srlv_vbmi2_epi8           ", _mm_mask_srlv_vbmi2_epi8(full128, (__mmask16)0xaa55, x128, y128));
	printRes("_mm_maskz_srav_vbmi2_epi8          ", _mm_maskz_srav_vbmi2_epi8((__mmask16)0xaa55, x128, y128));
	printRes("_mm_mask_srav_vbmi2_epi8           ", _mm_mask_srav_vbmi2_epi8(full128, (__mmask16)0xaa55, x128, y128));

	__m256i x256	= _mm256_set_epi64x(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f);
	__m256i y256	= _mm256_set_epi64x(0x0706050403020100, 0x0605040302010007, 0x0504030201000706, 0x0403020100070605);

	__m256i temp256 = _mm256_or_si256(_mm256_srlv_vbmi2_epi8(x256, y256), _mm256_sllv_vbmi2_epi8(x256, _mm256_sub_epi8(_mm256_set1_epi32(0x08080808), y256)));
	__m256i test256	= _mm256_xor_si256(x256, _mm256_or_si256(_mm256_sllv_vbmi2_epi8(temp256, y256), _mm256_srlv_vbmi2_epi8(temp256, _mm256_sub_epi8(_mm256_set1_epi32(0x08080808), y256))));
	assert(_mm256_testz_si256(test256, test256));

	y256 = _mm256_set_epi64x(0xfffefdfcfbfaf9f8, 0xf7f6f5f4f3f2f1f0, 0x0f0e0d0c0b0a0908, 0x0706050403020100);

	printRes("x256                               ", x256);
	printRes("y256                               ", y256);
	printRes("_mm256_sllv_vbmi2_epi8(x256, y256) ", _mm256_sllv_vbmi2_epi8(x256, y256));
	printRes("_mm256_srlv_vbmi2_epi8(x256, y256) ", _mm256_srlv_vbmi2_epi8(x256, y256));
	printRes("_mm256_srav_vbmi2_epi8(x256, y256) ", _mm256_srav_vbmi2_epi8(x256, y256));

	__m256i full256 = _mm256_set1_epi32(0xffffffff);
	printRes("_mm256_maskz_sllv_vbmi2_epi8       ", _mm256_maskz_sllv_vbmi2_epi8((__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_mask_sllv_vbmi2_epi8        ", _mm256_mask_sllv_vbmi2_epi8(full256, (__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_maskz_srlv_vbmi2_epi8       ", _mm256_maskz_srlv_vbmi2_epi8((__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_mask_srlv_vbmi2_epi8        ", _mm256_mask_srlv_vbmi2_epi8(full256, (__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_maskz_srav_vbmi2_epi8       ", _mm256_maskz_srav_vbmi2_epi8((__mmask32)0xac35f0a50f, x256, y256));
	printRes("_mm256_mask_srav_vbmi2_epi8        ", _mm256_mask_srav_vbmi2_epi8(full256, (__mmask32)0xac35f0a50f, x256, y256));

	__m512i x512		= _mm512_set_epi64(0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f, 0x7fbfdfeff7fbfdfe, 0x8040201008040201, 0x0102040810204080, 0xfefdfbf7efdfbf7f);
	__m512i y512		= _mm512_set_epi64(0x0706050403020100, 0x0605040302010007, 0x0504030201000706, 0x0403020100070605, 0x0302010007060504, 0x0201000706050403, 0x0100070605040302, 0x0007060504030201);

	__m512i temp512		= _mm512_or_si512(_mm512_srlv_vbmi2_epi8(x512, y512), _mm512_sllv_vbmi2_epi8(x512, _mm512_sub_epi8(_mm512_set1_epi32(0x08080808), y512)));
	__mmask64 test512	= _mm512_cmpeq_epi8_mask(x512, _mm512_or_si512(_mm512_sllv_vbmi2_epi8(temp512, y512), _mm512_srlv_vbmi2_epi8(temp512, _mm512_sub_epi8(_mm512_set1_epi32(0x08080808), y512))));
	assert(test512);

	printRes("x512                               ", x512);
	printRes("y512                               ", y512);
	printRes("_mm512_sllv_vbmi2_epi8(x512, y512) ", _mm512_sllv_vbmi2_epi8(x512, y512));
	printRes("_mm512_srlv_vbmi2_epi8(x512, y512) ", _mm512_srlv_vbmi2_epi8(x512, y512));
	printRes("_mm512_srav_vbmi2_epi8(x512, y512) ", _mm512_srav_vbmi2_epi8(x512, y512));

	__m512i full512 = _mm512_set1_epi32(0xffffffff);
	printRes("_mm512_maskz_sllv_vbmi2_epi8       ", _mm512_maskz_sllv_vbmi2_epi8((__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_mask_sllv_vbmi2_epi8        ", _mm512_mask_sllv_vbmi2_epi8(full512, (__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_maskz_srlv_vbmi2_epi8       ", _mm512_maskz_srlv_vbmi2_epi8((__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_mask_srlv_vbmi2_epi8        ", _mm512_mask_srlv_vbmi2_epi8(full512, (__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_maskz_srav_vbmi2_epi8       ", _mm512_maskz_srav_vbmi2_epi8((__mmask64)0xf00faa5533ccff00, x512, y512));
	printRes("_mm512_mask_srav_vbmi2_epi8        ", _mm512_mask_srav_vbmi2_epi8(full512, (__mmask64)0xf00faa5533ccff00, x512, y512));
}

void VBMI2_Demo_rotate_epi8(void) {
	__m128i x128	= _mm_set_epi64x(0x7fbfdfeff7fbfdf7, 0x8040201008040201), y128 = _mm_set_epi64x(0x0001020304050607, 0x0706050403020100);
	__m128i test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 0), _mm_rol_vbmi2_epi8(x128, 0));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 1), _mm_rol_vbmi2_epi8(x128, 1));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 2), _mm_rol_vbmi2_epi8(x128, 2));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 3), _mm_rol_vbmi2_epi8(x128, 3));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 4), _mm_rol_vbmi2_epi8(x128, 4));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 5), _mm_rol_vbmi2_epi8(x128, 5));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 6), _mm_rol_vbmi2_epi8(x128, 6));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 7), _mm_rol_vbmi2_epi8(x128, 7));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 8), _mm_rol_vbmi2_epi8(x128, 8));
	assert(_mm_testz_si128(test128, test128));

	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 0), _mm_ror_vbmi2_epi8(x128, 0));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 1), _mm_ror_vbmi2_epi8(x128, 1));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 2), _mm_ror_vbmi2_epi8(x128, 2));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 3), _mm_ror_vbmi2_epi8(x128, 3));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 4), _mm_ror_vbmi2_epi8(x128, 4));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 5), _mm_ror_vbmi2_epi8(x128, 5));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 6), _mm_ror_vbmi2_epi8(x128, 6));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 7), _mm_ror_vbmi2_epi8(x128, 7));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_ror_gfni_epi8(x128, 8), _mm_ror_vbmi2_epi8(x128, 8));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                       ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	printRes(0, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 0));
	printRes(1, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 1));
	printRes(2, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 2));
	printRes(3, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 3));
	printRes(4, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 4));
	printRes(5, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 5));
	printRes(6, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 6));
	printRes(7, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 7));
	printRes(8, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 8));
	printRes(9, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 9));
	printRes(10, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 10));
	printRes(11, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 11));
	printRes(12, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 12));
	printRes(13, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 13));
	printRes(14, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 14));
	printRes(15, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 15));
	printRes(16, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 16));
	printRes(128, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 128));
	printRes(255, "_mm_rol_vbmi2_epi8    ", _mm_rol_vbmi2_epi8(x128, 255));
	printRes(0, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 0));
	printRes(1, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 1));
	printRes(2, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 2));
	printRes(3, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 3));
	printRes(4, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 4));
	printRes(5, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 5));
	printRes(6, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 6));
	printRes(7, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 7));
	printRes(8, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 8));
	printRes(9, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 9));
	printRes(10, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 10));
	printRes(11, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 11));
	printRes(12, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 12));
	printRes(13, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 13));
	printRes(14, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 14));
	printRes(15, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 15));
	printRes(16, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 16));
	printRes(128, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 128));
	printRes(255, "_mm_ror_vbmi2_epi8    ", _mm_ror_vbmi2_epi8(x128, 255));

	__m128i full = _mm_set1_epi32(0xffffffff);
	printRes("_mm_mask_ror_vbmi2_epi8    ", _mm_mask_ror_vbmi2_epi8(full, (__mmask16)0xc3a5, x128, 4));
	printRes("_mm_maskz_ror_vbmi2_epi8   ", _mm_maskz_ror_vbmi2_epi8((__mmask16)0xc3a5, x128, 4));
	printRes("_mm_mask_rol_vbmi2_epi8    ", _mm_mask_rol_vbmi2_epi8(full, (__mmask16)0xc3a5, x128, 4));
	printRes("_mm_maskz_rol_vbmi2_epi8   ", _mm_maskz_rol_vbmi2_epi8((__mmask16)0xc3a5, x128, 4));
}


void VBMI2_Demo_shift_epi8(void) {
	__m128i x128	= _mm_set_epi64x(0x7fbfdfeff7fbfdf7, 0x8040201008040201), y128 = _mm_set1_epi8(0x7f);
	__m128i test128	= _mm_xor_si128(_mm_rol_gfni_epi8(x128, 0), _mm_slli_vbmi2_epi8(x128, 0));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 1), _mm_slli_vbmi2_epi8(x128, 1));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 2), _mm_slli_vbmi2_epi8(x128, 2));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 3), _mm_slli_vbmi2_epi8(x128, 3));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 4), _mm_slli_vbmi2_epi8(x128, 4));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 5), _mm_slli_vbmi2_epi8(x128, 5));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 6), _mm_slli_vbmi2_epi8(x128, 6));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 7), _mm_slli_vbmi2_epi8(x128, 7));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_slli_gfni_epi8(x128, 8), _mm_slli_vbmi2_epi8(x128, 8));
	assert(_mm_testz_si128(test128, test128));

	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 0), _mm_srli_vbmi2_epi8(x128, 0));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 1), _mm_srli_vbmi2_epi8(x128, 1));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 2), _mm_srli_vbmi2_epi8(x128, 2));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 3), _mm_srli_vbmi2_epi8(x128, 3));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 4), _mm_srli_vbmi2_epi8(x128, 4));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 5), _mm_srli_vbmi2_epi8(x128, 5));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 6), _mm_srli_vbmi2_epi8(x128, 6));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 7), _mm_srli_vbmi2_epi8(x128, 7));
	assert(_mm_testz_si128(test128, test128));
	test128	= _mm_xor_si128(_mm_srli_gfni_epi8(x128, 8), _mm_srli_vbmi2_epi8(x128, 8));
	assert(_mm_testz_si128(test128, test128));

	printRes("x128                       ", x128);
	__mmask16 m16 = _INSTLATX64_DEMO_TESTMASK_16;
	printRes(0, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 0));
	printRes(1, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 1));
	printRes(2, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 2));
	printRes(3, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 3));
	printRes(4, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 4));
	printRes(5, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 5));
	printRes(6, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 6));
	printRes(7, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 7));
	printRes(8, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 8));
	printRes(9, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 9));
	printRes(10, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 10));
	printRes(11, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 11));
	printRes(12, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 12));
	printRes(13, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 13));
	printRes(14, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 14));
	printRes(15, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 15));
	printRes(16, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 16));
	printRes(128, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 128));
	printRes(255, "_mm_slli_vbmi2_epi8    ", _mm_slli_vbmi2_epi8(x128, 255));
	printRes(0, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 0));
	printRes(1, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 1));
	printRes(2, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 2));
	printRes(3, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 3));
	printRes(4, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 4));
	printRes(5, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 5));
	printRes(6, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 6));
	printRes(7, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 7));
	printRes(8, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 8));
	printRes(9, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 9));
	printRes(10, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 10));
	printRes(11, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 11));
	printRes(12, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 12));
	printRes(13, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 13));
	printRes(14, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 14));
	printRes(15, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 15));
	printRes(16, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 16));
	printRes(128, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 128));
	printRes(255, "_mm_srli_vbmi2_epi8    ", _mm_srli_vbmi2_epi8(x128, 255));
	printRes(0, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 0));
	printRes(1, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 1));
	printRes(2, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 2));
	printRes(3, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 3));
	printRes(4, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 4));
	printRes(5, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 5));
	printRes(6, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 6));
	printRes(7, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 7));
	printRes(8, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 8));
	printRes(9, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 9));
	printRes(10, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 10));
	printRes(11, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 11));
	printRes(12, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 12));
	printRes(13, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 13));
	printRes(14, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 14));
	printRes(15, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 15));
	printRes(16, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 16));
	printRes(128, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 128));
	printRes(255, "_mm_srai_vbmi2_epi8    ", _mm_srai_vbmi2_epi8(x128, 255));
}

void VBMI2SpeedTest(void) {
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
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x128 = _mm_add_epi8(_mm_ror_vbmi2_epi8(x128, 6), x128);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm_ror_vbmi2_epi8(x128, 6)           :%8I64d clks min (%016I64x)\r\n", minres, x128.m128i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x256 = _mm256_add_epi8(_mm256_ror_vbmi2_epi8(x256, 6), x256);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm256_ror_vbmi2_epi8(x256, 6)        :%8I64d clks min (%016I64x)\r\n", minres, x256.m256i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x512 = _mm512_add_epi8(_mm512_ror_vbmi2_epi8(x512, 6), x512);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm512_ror_vbmi2_epi8(x512, 6)        :%8I64d clks min (%016I64x)\r\n", minres, x512.m512i_u64[0]);

	for (int retry = 0; retry < maxRetry; retry++) {
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x128 = _mm_add_epi8(_mm_mask_ror_vbmi2_epi8(x128, k16, x128, 6), x128);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm_mask_ror_vbmi2_epi8(x128, 6)      :%8I64d clks min (%016I64x)\r\n", minres, x128.m128i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x256 = _mm256_add_epi8(_mm256_mask_ror_vbmi2_epi8(x256, k32, x256, 6), x256);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm256_mask_ror_vbmi2_epi8(x256, 6)   :%8I64d clks min (%016I64x)\r\n", minres, x256.m256i_u64[0]);

	minres = ULONG_MAX;
	for (int retry = 0; retry < maxRetry; retry++) {
		start = __rdtscp(&AUX);
		for (int rep = 0; rep < maxRepeat; rep++) {
			x512 = _mm512_add_epi8(_mm512_mask_ror_vbmi2_epi8(x512, k64, x512, 6), x512);
		}
		minres = min(minres, __rdtscp(&AUX) - start);
	}
	printf("_mm512_mask_ror_vbmi2_epi8(x512, 6)   :%8I64d clks min (%016I64x)\r\n", minres, x512.m512i_u64[0]);
};

void VBMI2_Demo(void) {
	cout << "-----------------------------------" << endl;
	VBMI2_Demo_rotate_epi16();
	cout << "-----------------------------------" << endl; 
	VBMI2_Demo_rotate_epi8();
	cout << "-----------------------------------" << endl;
	VBMI2_Demo_shift_epi8();
	cout << "-----------------------------------" << endl;
	VBMI2_Demo_rotatev_epi8();
	cout << "-----------------------------------" << endl;
	VBMI2_Demo_shiftv_epi8();
	cout << "-----------------------------------" << endl;
	VBMI2SpeedTest();
}

#endif

