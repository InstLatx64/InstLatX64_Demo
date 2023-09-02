#include "stdafx.h"
#include "Compiler_Intrinsic_Test.h"

//MSVC++ 5.0  _MSC_VER == 1100
//MSVC++ 6.0  _MSC_VER == 1200
//MSVC++ 7.0  _MSC_VER == 1300
//MSVC++ 7.1  _MSC_VER == 1310 (Visual Studio 2003)
//MSVC++ 8.0  _MSC_VER == 1400 (Visual Studio 2005)
//MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
//MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
//MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
//MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
//MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
//MSVC++ 15.0 _MSC_VER == 1910 (Visual Studio 2017RC)

//https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019
//Visual Studio 2017 RTW (15.0)	1910
//Visual Studio 2017 version 15.3	1911
//Visual Studio 2017 version 15.5	1912
//Visual Studio 2017 version 15.6	1913
//Visual Studio 2017 version 15.7	1914
//Visual Studio 2017 version 15.8	1915
//Visual Studio 2017 version 15.9	1916
//Visual Studio 2019 RTW (16.0)		1920
//Visual Studio 2019 version 16.1	1921
//Visual Studio 2019 version 16.2	1922
//Visual Studio 2019 version 16.3	1923
//Visual Studio 2019 version 16.4	1924
//Visual Studio 2019 version 16.5	1925
//Visual Studio 2019 version 16.6	1926
//Visual Studio 2019 version 16.7	1927
//Visual Studio 2019 version 16.8	1928
//Visual Studio 2019 version 16.9	1928
//Visual Studio 2019 version 16.10	1929
//Visual Studio 2022 version 17.0	1930
//Visual Studio 2022 version 17.1	1931
//Visual Studio 2022 version 17.2	1932
//Visual Studio 2022 version 17.3	1933
//Visual Studio 2022 version 17.4	1934
//Visual Studio 2022 version 17.5	1935
//Visual Studio 2022 version 17.6	1936
//Visual Studio 2022 version 17.7	1937

void AVX512_InstrincTest(void)
{
	__m512i		x = _mm512_setzero_si512();
	__m512i		y = _mm512_setzero_si512();
	__m512i		z = _mm512_setzero_si512();
	__m512d		a = _mm512_set1_pd(0.0);
	__mmask64	m64 = 0;
	__mmask32	m32 = 0;
	__mmask16	m16 = 0;
	__mmask8	m8 = 0;

//AVX512PF
	//int *base = 0;
	//_mm512_prefetch_i64gather_pd(x, base, 8, _MM_HINT_T1);					//VGATHERPF0DPD
//AVX512ER
	//__m512d b = _mm512_rcp28_round_pd(a, 0);									//VRCP28PD
//AVX512_4FMAPS 
	//__m512ix4 c;
	//__m512 c = _mm512_4fmadd_ps();											//V4FMADDPS
//AVX512_4VNNI
	//x = _mm512_4dpwssd_epi32();												//VP4DPWSSDS
//VAES
	x = _mm512_aesenc_epi128(x, y);												//VAESENC
	x = _mm512_aesenclast_epi128(x, y);											//VAESENCLAST
	x = _mm512_aesdec_epi128(x, y);												//VAESDEC
	x = _mm512_aesdeclast_epi128(x, y);											//VAESDECLAST
//VPCLMULQDQ
	x = _mm512_clmulepi64_epi128(x, y, 0);										//VPCLMULQDQ
//VBMI
	x = _mm512_permutexvar_epi8(x, y);											//VPERMB
//IFMA
	x = _mm512_madd52lo_epu64(x, y, z);											//VPMADD52HUQ
//VNNI
	x = _mm512_dpbusd_epi32(x, y, z);											//VPDPBUSD
#if (_MSC_VER > 1920)
//GFNI
	x = _mm512_gf2p8affineinv_epi64_epi8(x, y, 0);								//VGF2P8AFFINEINVQB
	x = _mm512_gf2p8affine_epi64_epi8(x, y, 0);									//VGF2P8AFFINEQB
	x = _mm512_gf2p8mul_epi8(x, y);												//VGF2P8MULB
//AVX512_VPOPCNTDQ
	x = _mm512_popcnt_epi32(x);													//VPOPCNTD
	x = _mm512_popcnt_epi64(x);													//VPOPCNTQ
//AVX512_BITALG
	x = _mm512_popcnt_epi8(x);													//VPOPCNTB
	x = _mm512_popcnt_epi16(x);													//VPOPCNTW
	m64 = _mm512_bitshuffle_epi64_mask(x, y);									//VPSHUFBITQMB
//AVX512_VBMI2
	x = _mm512_mask_compress_epi8(x, m64, y);									//VPCOMPRESSB
	x = _mm512_mask_compress_epi16(x, m32, y);									//VPCOMPRESSW
	x = _mm512_mask_expand_epi8(x, m64, y);										//VPEXPANDB
	x = _mm512_mask_expand_epi16(x, m32, y);									//VPEXPANDW
	x = _mm512_shldi_epi16(x, y, 0);											//VPSHLDW
	x = _mm512_shldi_epi32(x, y, 0);											//VPSHLDD
	x = _mm512_shldi_epi64(x, y, 0);											//VPSHLDQ
	x = _mm512_shrdi_epi16(x, y, 0);											//VPSHRDW
	x = _mm512_shrdi_epi32(x, y, 0);											//VPSHRDD
	x = _mm512_shrdi_epi64(x, y, 0);											//VPSHRDQ
	x = _mm512_shldv_epi16(x, y, z);											//VPSHLDVW
	x = _mm512_shldv_epi32(x, y, z);											//VPSHLDVD
	x = _mm512_shldv_epi64(x, y, z);											//VPSHLDVQ
	x = _mm512_shrdv_epi16(x, y, z);											//VPSHRDVW
	x = _mm512_shrdv_epi32(x, y, z);											//VPSHRDVD
	x = _mm512_shrdv_epi64(x, y, z);											//VPSHRDVQ
 //AVX512_VP2INTERSECT
	_mm512_2intersect_epi32(x, y, &m16, &m16);									//VP2INTERSECTD
	_mm512_2intersect_epi64(x, y, &m8, &m8);									//VP2INTERSECTQ
	std::cout << x.m512i_u64[0];
//AVX512_BF16
	__m512		fl32accu_512 = _mm512_setzero();
	__m512		fl32_512_in1 = _mm512_setzero();
	__m512		fl32_512_in2 = _mm512_setzero();
	__m512bh bf16_512res = _mm512_cvtne2ps2bf16(fl32_512_in1, fl32_512_in2);	//VCVTNE2PS2BF16
	__m256bh bf16_256res = _mm512_cvtneps2bf16(fl32_512_in1);					//VCVTNEPS2BF16
	fl32accu_512 = _mm512_dpbf16_ps(fl32accu_512, bf16_512res, bf16_512res);	//VDPBF16PS
	std::cout << fl32accu_512.m512_f32[0] << bf16_256res.m256i_u64[0];
//AVX512_FP16
#if (_MSC_VER > 1930)
	__m512h		halfprec = _mm512_castps_ph(_mm512_setzero_ps());
	__m512h		halfprec2 = _mm512_add_ph(halfprec, halfprec);					//VADDPH
#if (_MSC_VER >= 1933)
	__bfloat16 bf16 = _mm_cvtness_sbh(1234.56f);
	float f = _mm_cvtsbh_ss(bf16);
	std::cout << f << std::endl;
#endif
#endif
#endif
}

void AVX_VNNI_InstrincTest(void) {
	__m256i		a = _mm256_setzero_si256();
	__m256i		b = _mm256_setzero_si256();
	__m256i		src = _mm256_setzero_si256();
	
	__m256i		res_AVX_VNNI		= _mm256_dpbusds_avx_epi32(src, a, b);
#if (_MSC_VER >= 1937)
	__m256i		res_AVX_VNNI_INT8	= _mm256_dpbuud_epi32(src, a, b);
#if (_MSC_VER > 1937)
	__m256i		res_AVX_VNNI_INT16	= _mm256_dpwuud_avx_epi32(src, a, b);
//_mm_sm3msg1_epi32 
//_mm_sm3msg2_epi32 
//_mm_sm3rnds2_epi32
//
//_mm256_sha512msg1_epi64 
//_mm256_sha512msg2_epi64 
//_mm256_sha512rnds2_epi64 
//
//_mm_sm4key4_epi32 
//_mm256_sm4key4_epi32 
//_mm_sm4rnds4_epi32 
//_mm256_sm4rnds4_epi32 
#endif
#endif
}

void InstrincTest(void) {
	long value32b = 0 ;
	long long *dst = 0, *src = 0, value64b = 0;
#if (_MSC_VER > 1920)
//CLDEMOTE
	_cldemote(dst);													//CLDEMOTE
//MOVDIRI
	_directstoreu_u32(dst, value32b);								//MOVDIRI
#if defined(_M_X64)
	_directstoreu_u64(dst, value64b);								//MOVDIRI
#endif
//MOVDIR64B
	_movdir64b(dst, src);											//MOVDIR64B
//WAITPKG
	uint32_t control = 0;
	uint64_t counter = 0;
	uint64_t watch = 0;
	 uint8_t x = _tpause(control, counter);							//TPAUSE
	_umonitor(&watch);												//UMONITOR
	uint8_t w = _umwait(control, counter);							//MWAIT
//PCONFIG
	size_t data[3] = {0, 0, 0};
	_pconfig_u32(0, data);											//PCONFIG
//WBNOINVD
	_wbnoinvd();													//WBNOINVD
//ENQCMD
	int e = _enqcmd(dst, src);										//ENQCMD
	int f = _enqcmds(dst, src);										//ENQCMDS
#if (_MSC_VER > 1926)
//SERIALIZE
	_serialize();													//SERIALIZE
//TSXLDTRK
	_xresldtrk();													//XRESLDTRK
	_xsusldtrk();													//XSUSLDTRK
#if defined (_M_X64)
//PREFETCHI
//C1001 up to VS17.7.3
//#if (_MSC_VER >= 1937)
//	char prefetchtest = 0;
//	_mm_prefetch(&prefetchtest, _MM_HINT_IT0);						//PREFETCHIT0
//	_mm_prefetch(&prefetchtest, _MM_HINT_IT1);						//PREFETCHIT1
//#endif
#if (_MSC_VER > 1927)
//AMX-TILE
	unsigned char load_tilecfg[64], store_tilecfg[64];
	unsigned char tile0[1024], tile1[1024];
	_tile_loadconfig(load_tilecfg);									//LDTILECFG
	_tile_storeconfig(store_tilecfg);								//STTILECFG
	_tile_loadd(0, tile0, 64);										//TILELOADD
	_tile_stream_loadd(1, tile1, 64);								//TILELOADDT1
	_tile_stored(0, tile1, 64);										//TILESTORED
	_tile_stored(1, tile0, 64);										//TILESTORED
	_tile_zero(2);													//TILEZERO
	_tile_release();												//TILERELEASE
//AMX-BF16
	_tile_dpbf16ps(2, 1, 0);										//TDPBF16PS
//AMX-FP16
#if (_MSC_VER >= 1936)
	_tile_dpfp16ps(2, 1, 0);										//TDPFP16PS
//AMX-COMPLEX
#if (_MSC_VER >= 1937)
	_tile_cmmimfp16ps(2, 1, 0);										//TCMMIMFP16PS
	_tile_cmmrlfp16ps(2, 1, 0);										//TCMMRLFP16PS
#endif
#endif
//AMX-INT8
	_tile_dpbssd(3, 2, 1);											//TDPBSSD
	_tile_dpbsud(4, 3, 2);											//TDPBSUD
	_tile_dpbusd(5, 4, 3);											//TDPBUSD
	_tile_dpbuud(6, 5, 4);											//TDPBUUD
#endif // defined (_M_X64)
#endif //_MSC_VER > 1927
#endif //_MSC_VER > 1926
#endif //_MSC_VER > 1920
}