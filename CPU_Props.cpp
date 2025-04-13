#include "stdafx.h"

const _EXT CPU_Props::exts[FEAT_LAST] = {
// Name									xcr0			feat								cpuidPlace0										cpuidPlace1
	{"---Ident--------",				_XCR0_EMPTY,	FEAT_GROUP_ID,						_FEAT_SKIP,										_FEAT_SKIP								},
	{"Vendor",							_XCR0_EMPTY,	FEAT_VENDOR,						_FEAT00_VENDOR,									_FEAT_SKIP								},
	{"Family",							_XCR0_EMPTY,	FEAT_FAMILY,						_FEAT01_FAMILY,									_FEAT_SKIP								},
	{"Model",							_XCR0_EMPTY,	FEAT_MODEL,							_FEAT01_MODEL,									_FEAT_SKIP								},
	{"Stepping",						_XCR0_EMPTY,	FEAT_STEPPING,						_FEAT01_STEPPING,								_FEAT_SKIP								},
	{"FMS",								_XCR0_EMPTY,	FEAT_FMS,							_FEAT01_FMS,									_FEAT_SKIP								},
	{"Brand",							_XCR0_EMPTY,	FEAT_BRAND,							_FEAT_NOFEAT,									_FEAT_SKIP								},
	{"---GPR----------",				_XCR0_EMPTY,	FEAT_GROUP_GPR,						_FEAT_SKIP,										_FEAT_SKIP								},
	{"LNOP",							_XCR0_EMPTY,	FEAT_LNOP,							_FEAT_NOFEAT,									_FEAT_SKIP								},
	{"CMOV",							_XCR0_EMPTY,	FEAT_CMOV,							_FEAT01_EDX_CMOV,								_FEAT_SKIP								},
	{"CMPX8",							_XCR0_EMPTY,	FEAT_CMPX8,							_FEAT01_EDX_CMPX8,								_FEAT_SKIP								},
	{"CMPX16",							_XCR0_EMPTY,	FEAT_CMPX16,						_FEAT01_ECX_CMPX16,								_FEAT_SKIP								},
	{"LAHF",							_XCR0_EMPTY,	FEAT_LAHF,							_EFEAT01_ECX_LAHF,								_FEAT_SKIP								},
	{"MOVBE",							_XCR0_EMPTY,	FEAT_MOVBE,							_FEAT01_ECX_MOVBE,								_FEAT_SKIP								},
	{"ABM",								_XCR0_EMPTY,	FEAT_ABM,							_EFEAT01_ECX_ABM,								_FEAT_SKIP								},
	{"POPCNT",							_XCR0_EMPTY,	FEAT_POPCNT,						_FEAT01_ECX_POPCNT,								_FEAT_SKIP								},
	{"RDRAND",							_XCR0_EMPTY,	FEAT_RDRAND,						_FEAT01_ECX_RDRAND,								_FEAT_SKIP								},
	{"RDSEED",							_XCR0_EMPTY,	FEAT_RDSEED,						_FEAT07_EBX_RDSEED,								_FEAT_SKIP								},
	{"ADX",								_XCR0_EMPTY,	FEAT_ADX,							_FEAT07_EBX_ADX,								_FEAT_SKIP								},
	{"BMI",								_XCR0_EMPTY,	FEAT_BMI,							_FEAT07_EBX_BMI,								_FEAT_SKIP								},
	{"BMI2",							_XCR0_EMPTY,	FEAT_BMI2,							_FEAT07_EBX_BMI2,								_FEAT_SKIP								},
	{"MOVDIRI",							_XCR0_EMPTY,	FEAT_MOVDIRI,						_FEAT07_ECX_MOVDIRI,							_FEAT_SKIP								},
	{"MOVDIR64B",						_XCR0_EMPTY,	FEAT_MOVDIR64B,						_FEAT07_ECX_MOVDIR64B,							_FEAT_SKIP								},
	{"RDPID",							_XCR0_EMPTY,	FEAT_RDPID,							_FEAT07_ECX_RDPID,								_FEAT_SKIP								},
	{"RDPRU",							_XCR0_EMPTY,	FEAT_RDPRU,							_EFEAT08_EBX_RDPRU,								_FEAT_SKIP								},
	{"RAO-INT",							_XCR0_EMPTY,	FEAT_RAO_INT,						_FEAT0701_EAX_RAO_INT,							_FEAT_SKIP								},
	{"CMPCCXADD",						_XCR0_EMPTY,	FEAT_CMPCCXADD,						_FEAT0701_EAX_CMPCCXADD,						_FEAT_SKIP								},
	{"APX_F",							_XCR0_APX,		FEAT_APX,							_FEAT0701_EDX_APX_F,							_FEAT_SKIP								},
	{"---SIMD---------",				_XCR0_EMPTY,	FEAT_GROUP_SIMD,					_FEAT_SKIP,										_FEAT_SKIP								},
	{"SSE",								_XCR0_EMPTY,	FEAT_SSE,							_FEAT01_EDX_SSE,								_FEAT_SKIP								},
	{"SSE2",							_XCR0_EMPTY,	FEAT_SSE2,							_FEAT01_EDX_SSE2,								_FEAT_SKIP								},
	{"SSE3",							_XCR0_EMPTY,	FEAT_SSE3,							_FEAT01_ECX_SSE3,								_FEAT_SKIP								},
	{"SSSE3",							_XCR0_EMPTY,	FEAT_SSSE3,							_FEAT01_ECX_SSSE3,								_FEAT_SKIP								},
	{"SSE41",							_XCR0_EMPTY,	FEAT_SSE41,							_FEAT01_ECX_SSE41,								_FEAT_SKIP								},
	{"SSE42",							_XCR0_EMPTY,	FEAT_SSE42,							_FEAT01_ECX_SSE42,								_FEAT_SKIP								},
	{"SSE4A",							_XCR0_EMPTY,	FEAT_SSE4A,							_EFEAT01_ECX_SSE4A,								_FEAT_SKIP								},
	{"CLMUL",							_XCR0_EMPTY,	FEAT_CLMUL,							_FEAT01_ECX_CLMUL,								_FEAT_SKIP								},
	{"AES",								_XCR0_EMPTY,	FEAT_AES,							_FEAT01_ECX_AESNI,								_FEAT_SKIP								},
	{"SHA",								_XCR0_EMPTY,	FEAT_SHA,							_FEAT07_EBX_SHA,								_FEAT_SKIP								},
	{"GFNI",							_XCR0_EMPTY,	FEAT_GFNI,							_FEAT07_ECX_GFNI,								_FEAT_SKIP								},
	{"--VEX-SIMD------",				_XCR0_EMPTY,	FEAT_GROUP_VEX,						_FEAT_SKIP,										_FEAT_SKIP								},
	{"AVX",								_XCR0_AVX,		FEAT_AVX,							_FEAT01_ECX_AVX,								_FEAT_SKIP								},
	{"AVX2",							_XCR0_AVX,		FEAT_AVX2,							_FEAT07_EBX_AVX2,								_FEAT_SKIP								},
	{"FMA",								_XCR0_AVX,		FEAT_FMA,							_FEAT01_ECX_FMA3,								_FEAT_SKIP								},
	{"F16C",							_XCR0_AVX,		FEAT_F16C,							_FEAT01_ECX_F16C,								_FEAT_SKIP								},
	{"AVX+GFNI",						_XCR0_AVX,		FEAT_AVX_GFNI,						_FEAT07_ECX_GFNI,								_FEAT_SKIP								},
	{"AVX+VAES",						_XCR0_AVX,		FEAT_AVX_VAES,						_FEAT07_ECX_VAES,								_FEAT_SKIP								},
	{"AVX+VPCLMULQDQ",					_XCR0_AVX,		FEAT_AVX_VPCLMULQDQ,				_FEAT07_ECX_VPCLMULQDQ,							_FEAT_SKIP								},
	{"AVX_VNNI",						_XCR0_AVX,		FEAT_AVX_VNNI,						_FEAT0701_EAX_AVX_VNNI,							_FEAT_SKIP								},
	{"AVX_VNNI_INT8",					_XCR0_AVX,		FEAT_AVX_VNNI_INT8,					_FEAT0701_EDX_AVX_VNNI_INT8,					_FEAT_SKIP								},
	{"AVX_VNNI_INT16",					_XCR0_AVX,		FEAT_AVX_VNNI_INT16,				_FEAT0701_EDX_AVX_VNNI_INT16,					_FEAT_SKIP								},
	{"AVX_IFMA",						_XCR0_AVX,		FEAT_AVX_IFMA,						_FEAT0701_EAX_AVX_IFMA,							_FEAT_SKIP								},
	{"AVX_NE_CONVERT",					_XCR0_AVX,		FEAT_AVX_NE_CONVERT,				_FEAT0701_EDX_AVX_NE_CONVERT,					_FEAT_SKIP								},
	{"SHA512",							_XCR0_AVX,		FEAT_SHA512,						_FEAT0701_EAX_SHA512,							_FEAT_SKIP								},
	{"SM3",								_XCR0_AVX,		FEAT_SM3,							_FEAT0701_EAX_SM3,								_FEAT_SKIP								},
	{"SM4",								_XCR0_AVX,		FEAT_SM4,							_FEAT0701_EAX_SM4,								_FEAT_SKIP								},
	{"--EVEX-SIMD-----",				_XCR0_EMPTY,	FEAT_GROUP_EVEX,					_FEAT_SKIP,										_FEAT_SKIP								},
	{"AVX512F",							_XCR0_AVX512,	FEAT_AVX512F,						_FEAT07_EBX_AVX512F,							_FEAT_SKIP								},
	{"AVX512CD",						_XCR0_AVX512,	FEAT_AVX512CD,						_FEAT07_EBX_AVX512CD,							_FEAT_SKIP								},
	{"AVX512ER",						_XCR0_AVX512,	FEAT_AVX512ER,						_FEAT07_EBX_AVX512ER,							_FEAT_SKIP								},
	{"AVX512PF",						_XCR0_AVX512,	FEAT_AVX512PF,						_FEAT07_EBX_AVX512PF,							_FEAT_SKIP								},
	{"AVX512BW",						_XCR0_AVX512,	FEAT_AVX512BW,						_FEAT07_EBX_AVX512BW,							_FEAT_SKIP								},
	{"AVX512DQ",						_XCR0_AVX512,	FEAT_AVX512DQ,						_FEAT07_EBX_AVX512DQ,							_FEAT_SKIP								},
	{"AVX512VL",						_XCR0_AVX512,	FEAT_AVX512VL,						_FEAT07_EBX_AVX512VL,							_FEAT_SKIP								},
	{"AVX512VBMI",						_XCR0_AVX512,	FEAT_AVX512VBMI,					_FEAT07_ECX_AVX512_VBMI,						_FEAT_SKIP								},
	{"AVX512IFMA",						_XCR0_AVX512,	FEAT_AVX512IFMA,					_FEAT07_EBX_AVX512_IFMA,						_FEAT_SKIP								},
	{"AVX512VNNI",						_XCR0_AVX512,	FEAT_AVX512VNNI,					_FEAT07_ECX_AVX512_VNNI,						_FEAT_SKIP								},
	{"AVX512_4VNNIW",					_XCR0_AVX512,	FEAT_AVX512_4VNNIW,					_FEAT07_EDX_AVX512_4VNNIW,						_FEAT_SKIP								},
	{"AVX512_4FMAPS",					_XCR0_AVX512,	FEAT_AVX512_4FMAPS,					_FEAT07_EDX_AVX512_4FMAPS,						_FEAT_SKIP								},
	{"AVX512_VPOPCNTDQ",				_XCR0_AVX512,	FEAT_AVX512_VPOPCNTDQ,				_FEAT07_ECX_AVX512_VPOPCNTDQ,					_FEAT_SKIP								},
	{"AVX512+GFNI",						_XCR0_AVX512,	FEAT_AVX512_GFNI,					_FEAT07_ECX_GFNI,								_FEAT_SKIP								},
	{"AVX512+VAES",						_XCR0_AVX512,	FEAT_AVX512_VAES,					_FEAT07_ECX_VAES,								_FEAT_SKIP								},
	{"AVX512+VPCLMULQDQ",				_XCR0_AVX512,	FEAT_AVX512_VPCLMULQDQ,				_FEAT07_ECX_VPCLMULQDQ,							_FEAT_SKIP								},
	{"AVX512_BITALG",					_XCR0_AVX512,	FEAT_AVX512_BITALG,					_FEAT07_ECX_AVX512_BITALG,						_FEAT_SKIP								},
	{"AVX512_VBMI2",					_XCR0_AVX512,	FEAT_AVX512_VBMI2,					_FEAT07_ECX_AVX512_VBMI2,						_FEAT_SKIP								},
	{"AVX512_BF16",						_XCR0_AVX512,	FEAT_AVX512_BF16,					_FEAT0701_EAX_AVX512_BF16,						_FEAT_SKIP								},
	{"AVX512_VP2INTERSECT",				_XCR0_AVX512,	FEAT_AVX512_VP2INTERSECT,			_FEAT07_EDX_AVX512_VP2INTERSECT,				_FEAT_SKIP								},
	{"AVX512_FP16",						_XCR0_AVX512,	FEAT_AVX512_FP16,					_FEAT07_EDX_AVX512_FP16,						_FEAT_SKIP								},
	{"---AMX----------",				_XCR0_EMPTY,	FEAT_GROUP_AMX,						_FEAT_SKIP,										_FEAT_SKIP								},
	{"AMX-TILE",						_XCR0_AMX,		FEAT_AMX_TILE,						_FEAT07_EDX_AMX_TILE,							_FEAT_SKIP								},
	{"AMX-INT8",						_XCR0_AMX,		FEAT_AMX_INT8,						_FEAT07_EDX_AMX_INT8,							_FEAT1E01_EAX_AMX_INT8					},
	{"AMX-BF16",						_XCR0_AMX,		FEAT_AMX_BF16,						_FEAT07_EDX_AMX_BF16,							_FEAT1E01_EAX_AMX_BF16					},
	{"AMX-COMPLEX",						_XCR0_AMX,		FEAT_AMX_COMPLEX,					_FEAT0701_EDX_AMX_COMPLEX,						_FEAT1E01_EAX_AMX_COMPLEX				},
	{"AMX-FP16",						_XCR0_AMX,		FEAT_AMX_FP16,						_FEAT0701_EAX_AMX_FP16,							_FEAT1E01_EAX_AMX_FP16					},
	{"AMX-FP8",							_XCR0_AMX,		FEAT_AMX_FP8,						_FEAT1E01_EAX_AMX_FP8,							_FEAT_SKIP								},
	{"AMX-TRANSPOSE",					_XCR0_AMX,		FEAT_AMX_TRANSPOSE,					_FEAT1E01_EAX_AMX_TRANPOSE,						_FEAT_SKIP								},
	{"AMX-TF32",						_XCR0_AMX,		FEAT_AMX_TF32,						_FEAT1E01_EAX_AMX_TF32,							_FEAT_SKIP								},
	{"AMX-AVX512",						_XCR0_AMX,		FEAT_AMX_AVX512,					_FEAT1E01_EAX_AMX_AVX512,						_FEAT_SKIP								},
	{"AMX-MOVRS",						_XCR0_AMX,		FEAT_AMX_MOVRS,						_FEAT1E01_EAX_AMX_MOVRS,						_FEAT_SKIP								},
	{"---AVX10--------",				_XCR0_EMPTY,	FEAT_GROUP_AVX10,					_FEAT_SKIP,										_FEAT_SKIP								},
	{"AVX10",							_XCR0_AVX512,	FEAT_AVX10,							_FEAT0701_EDX_AVX10,							_FEAT_SKIP								},
	{"AVX10/128",						_XCR0_AVX512,	FEAT_AVX10_128,						_FEAT24_EBX_AVX10_128,							_FEAT_SKIP								},
	{"AVX10/256",						_XCR0_AVX512,	FEAT_AVX10_256,						_FEAT24_EBX_AVX10_256,							_FEAT_SKIP								},
	{"AVX10/512",						_XCR0_AVX512,	FEAT_AVX10_512,						_FEAT24_EBX_AVX10_512,							_FEAT_SKIP								},
	{"AVX10.level",						_XCR0_AVX512,	FEAT_AVX10_LEVEL,					_FEAT24_EBX_AVX10_LEVEL,						_FEAT_SKIP								},
	{"---CacheLine----",				_XCR0_EMPTY,	FEAT_GROUP_CACHELINE,				_FEAT_SKIP,										_FEAT_SKIP								},
	{"PREFETCHW",						_XCR0_EMPTY,	FEAT_PREFETCHW,						_EFEAT01_ECX_3DNOWPREF,							_FEAT_SKIP								},
	{"PREFETCHWT1",						_XCR0_EMPTY,	FEAT_PREFETCHWT1,					_FEAT07_ECX_PWT1,								_FEAT_SKIP								},
	{"PREFETCHI",						_XCR0_EMPTY,	FEAT_PREFETCHI,						_FEAT0701_EDX_PREFETCHI,						_EFEAT21_EAX_PREFETCHI					},
	{"CLFLUSH",							_XCR0_EMPTY,	FEAT_CLFLUSH,						_FEAT01_EDX_CLFLUSH,							_FEAT_SKIP								},
	{"CLFLUSHOPT",						_XCR0_EMPTY,	FEAT_CLFLUSHOPT,					_FEAT07_EBX_CLFLUSHOPT,							_FEAT_SKIP								},
	{"CLWB",							_XCR0_EMPTY,	FEAT_CLWB,							_FEAT07_EBX_CLWB,								_FEAT_SKIP								},
	{"CLZERO",							_XCR0_EMPTY,	FEAT_CLZERO,						_EFEAT08_EBX_CLZERO,							_FEAT_SKIP								},
	{"CLDEMOTE",						_XCR0_EMPTY,	FEAT_CLDEMOTE,						_FEAT07_ECX_CLDEMOTE,							_FEAT_SKIP								},
	{"---uCode--------",				_XCR0_EMPTY,	FEAT_GROUP_UCODE,					_FEAT_SKIP,										_FEAT_SKIP								},
	{"Enh REP MOVSB/STOSB",				_XCR0_EMPTY,	FEAT_ERMS_ENH_REP_MOVSB_STOSB,		_FEAT07_EBX_ERMS_ENH_REP_MOVSB_STOSB,			_EFEAT21_EAX_AMD_ERMSB					},
	{"Fast short REP MOV",				_XCR0_EMPTY,	FEAT_FSRM_FAST_SHORT_RRP_MOV,		_FEAT07_EDX_FSRM_FAST_SHORT_RRP_MOV,			_FEAT_SKIP								},
	{"Fast zero-length MOVSB",			_XCR0_EMPTY,	FEAT_FZLM_FAST_ZERO_LEN_MOVSB,		_FEAT0701_EAX_FZLM_FAST_ZERO_LEN_MOVSB,			_FEAT_SKIP								},
	{"Fast short REP STOSB",			_XCR0_EMPTY,	FEAT_FSRS_FAST_SHORT_REP_STOSB,		_FEAT0701_EAX_FSRS_FAST_SHORT_REP_STOSB,		_EFEAT21_EAX_FSRS_FAST_SHORT_REP_STOSB	},
	{"Fast short REP CMPSB/SCASB",		_XCR0_EMPTY,	FEAT_FSCS_FAST_SHORT_CMPSB_SCASB,	_FEAT0701_EAX_FSRC_FAST_SHORT_REP_CMPSB_SCASB,	_FEAT_SKIP								},
	{"Fast Short REPE CMPSB",			_XCR0_EMPTY,	FEAT_FSRC_FAST_SHORT_REPE_CMPSB,	_EFEAT21_EAX_FSRC_FAST_SHORT_REPE_CMPSB,		_FEAT_SKIP								},
	{"Fast Short REP SCASB/AMD",		_XCR0_EMPTY,	FEAT_FSRS_FAST_SHORT_REP_SCASB_AMD,	_EFEAT21_EAX_FSRS_FAST_SHORT_REP_SCASB,			_FEAT_SKIP								},
	{"---TSC----------",				_XCR0_EMPTY,	FEAT_GROUP_GPR,						_FEAT_SKIP,										_FEAT_SKIP								},
	{"RDTSC",							_XCR0_EMPTY,	FEAT_RDTSC,							_FEAT01_EDX_RDTSC,								_FEAT_SKIP								},
	{"RDTSCP",							_XCR0_EMPTY,	FEAT_RDTSCP,						_EFEAT01_EDX_RDTSCP,							_FEAT_SKIP								},
	{"---Keylocker----",				_XCR0_EMPTY,	FEAT_GROUP_KEYLOCKER,				_FEAT_SKIP,										_FEAT_SKIP								},
	{"KEYLOCK",							_XCR0_EMPTY,	FEAT_KEYLOCK,						_FEAT07_ECX_KEYLOCK,							_FEAT_SKIP								},
	{"AESKLE",							_KEYLOCK,		FEAT_AESKLE,						_FEAT19_EBX_AESKLE,								_FEAT_SKIP								},
	{"WIDE_KL",							_KEYLOCK,		FEAT_WIDE_KL,						_FEAT19_EBX_WIDE_KL,							_FEAT_SKIP								},
	{"---Uncategorized",				_XCR0_EMPTY,	FEAT_GROUP_UNCATEGORIZED,			_FEAT_SKIP,										_FEAT_SKIP								},
	{"X86",								_XCR0_EMPTY,	FEAT_X86,							_FEAT_NOFEAT,									_FEAT_SKIP								},
	{"AMD64",							_XCR0_EMPTY,	FEAT_AMD64,							_EFEAT01_EDX_AMD64,								_FEAT_SKIP								},
	{"SERIALIZE",						_XCR0_EMPTY,	FEAT_SERIALIZE,						_FEAT07_EDX_SERIALIZE,							_FEAT_SKIP								},
	{"HYBRID",							_XCR0_EMPTY,	FEAT_HYBRID,						_FEAT07_EDX_HYBRID,								_FEAT_SKIP								},
	{"MCOMMIT",							_XCR0_EMPTY,	FEAT_MCOMMIT,						_EFEAT08_EBX_MCOMMIT,							_FEAT_SKIP								},
	{"PCONFIG",							_XCR0_EMPTY,	FEAT_PCONFIG,						_FEAT07_EDX_PCONFIG,							_FEAT_SKIP								},
	{"---Deprecated---",				_XCR0_EMPTY,	FEAT_GROUP_DEPRECATED,				_FEAT_SKIP,										_FEAT_SKIP								},
	{"X87",								_XCR0_EMPTY,	FEAT_X87,							_FEAT01_EDX_X87,								_FEAT_SKIP								},
	{"MMX",								_XCR0_EMPTY,	FEAT_MMX,							_FEAT01_EDX_MMX,								_FEAT_SKIP								},
	{"MMX+",							_XCR0_EMPTY,	FEAT_MMXP,							_EFEAT01_EDX_MMXP,								_FEAT_SKIP								},
	{"3DNow!",							_XCR0_EMPTY,	FEAT_3DNOW,							_EFEAT01_EDX_3DNOW,								_FEAT_SKIP								},
	{"3DNow!+",							_XCR0_EMPTY,	FEAT_3DNOWP,						_EFEAT01_EDX_3DNOWP,							_FEAT_SKIP								},
	{"XOP",								_XCR0_AVX,		FEAT_XOP,							_EFEAT01_ECX_XOP,								_FEAT_SKIP								},
	{"FMA4",							_XCR0_AVX,		FEAT_FMA4,							_EFEAT01_ECX_FMA4,								_FEAT_SKIP								},
	{"TBM",								_XCR0_EMPTY,	FEAT_TBM,							_EFEAT01_ECX_TBM,								_FEAT_SKIP								},
	{"MPX",								_XCR0_EMPTY,	FEAT_MPX,							_FEAT07_EBX_MPX,								_FEAT_SKIP								},
	{"HLE",								_XCR0_EMPTY,	FEAT_HLE,							_FEAT07_EBX_HLE,								_FEAT_SKIP								},
	{"PCOMMIT",							_XCR0_EMPTY,	FEAT_PCOMMIT,						_FEAT07_EBX_PCOMMIT,							_FEAT_SKIP								},
};

const _CPUID_VENDOR CPU_Props::vendors[_VENDOR_LAST] = {
	{_VENDOR_AMD,		{0x69444D41, 0x74656273, 0x21726574}},		//"AMDisbetter!"
	{_VENDOR_AMD,		{0x68747541, 0x69746E65, 0x444D4163}},		//"AuthenticAMD"
	{_VENDOR_CENTAUR,	{0x20414956, 0x20414956, 0x20414956}},		//"VIA VIA VIA "
	{_VENDOR_CENTAUR,	{0x746E6543, 0x48727561, 0x736C7561}},		//"CentaurHauls"
	{_VENDOR_CYRIX,		{0x69727943, 0x736E4978, 0x64616574}},		//"CyrixInstead"
	{_VENDOR_HYGON,		{0x6F677948, 0x6E656273, 0x656E6975}},		//"HygonGenuine"
	{_VENDOR_INTEL,		{0x756E6547, 0x49656E69, 0x6C65746E}},		//"GenuineIntel"
	{_VENDOR_NATIONAL,	{0x646F6547, 0x79622065, 0x43534E20}},		//"Geode by NSC"
	{_VENDOR_NEXGEN,	{0x4778654E, 0x72446E65, 0x6E657669}},		//"NexGenDriven"
	{_VENDOR_SIS,		{0x20536953, 0x20536953, 0x20536953}},		//"SiS SiS SiS "
	{_VENDOR_RDC,		{0x756E6547, 0x43445220, 0x20656E69}},		//"Genuine  RDC"
	{_VENDOR_RISE,		{0x65736952, 0x65736952, 0x65736952}},		//"RiseRiseRise"
	{_VENDOR_TMTA,		{0x6E617254, 0x74656D73, 0x55504361}},		//"TransmetaCPU"
	{_VENDOR_TMTA,		{0x756E6547, 0x54656E69, 0x3638784D}},		//"GenuineTMx86"
	{_VENDOR_UMC,		{0x20434D55, 0x20434D55, 0x20434D55}},		//"UMC UMC UMC "
	{_VENDOR_VORTEX,	{0x74726F56, 0x436F5320, 0x36387865}},		//"Vortex86 SoC"
	{_VENDOR_ZHAOXIN,	{0x68532020, 0x68676E61, 0x20206961}},		//"  Shanghai  "
};

const char * CPU_Props::_cpuid_names[MAX_CPUIDSTR][CPUID_STR_LAST + 1] = {
/*			CPUID_STATE				CPUID_TLB_TYPE		CPUID_TLB_PAGE	CPUID_CACHE_TYPE	CPUID_ATOM_NAME	CPUID_CORE_NAME	*/
/*			0000000Dh				00000018h			00000018h		00000004h			0000001Ah		0000001Ah		*/
/* 00 */	{"X87",					"",					"",				"",					"Tremont",		"Sunny Cove"	},
/* 01 */	{"SSE",					"Data        TLB",	"4K          ",	"Data       ",		"Gracemont",	"Golden Cove"	},
/* 02 */	{"AVX",					"Instruction TLB",	"   2M       ",	"Instruction",		"Crestmont",	"Redwood Cove"	},
/* 03 */	{"MPX BNDREGS",			"Unified     TLB",	"4K+2M       ",	"Unified    ",		"Skymont",		"Lion Cove"		},
/* 04 */	{"MPX BNDCSR",			"Load Only   TLB",	"      4M    ",	"",					"",				""				},
/* 05 */	{"AVX-512 Opmask",		"Store Only  TLB",	"4K+   4M    ",	"",					"",				""				},
/* 06 */	{"AVX-512 Hi256",		"",					"   2M/4M    ",	"",					"",				""				},
/* 07 */	{"AVX-512 Hi16",		"",					"4K+2M/4M    ",	"",					"",				""				},
/* 08 */	{"PT",					"",					"         1G ",	"",					"",				""				},
/* 09 */	{"PKRU",				"",					"4K+      1G ",	"",					"",				""				},
/* 10 */	{"PASID",				"",					"   2M   +1G ",	"",					"",				""				},
/* 11 */	{"CET_U",				"",					"4K+2M   +1G ",	"",					"",				""				},
/* 12 */	{"CET_S",				"",					"      4M+1G ",	"",					"",				""				},
/* 13 */	{"HDC",					"",					"4K+   4M+1G ",	"",					"",				""				},
/* 14 */	{"UINTR",				"",					"   2M/4M+1G ",	"",					"",				""				},
/* 15 */	{"LBR",					"",					"4K+2M/4M+1G ",	"",					"",				""				},
/* 16 */	{"HWP",					"",					"",				"",					"",				""				},
/* 17 */	{"TILECFG",				"",					"",				"",					"",				""				},
/* 18 */	{"TILEDATA"				"",					"",				"",					"",				""				},
/* 19 */	{"APX"					"",					"",				"",					"",				""				},
};

CPU_Props::CPU_Props(UINT64 arg_xcr0) : family(0), model(0), stepping(0), fms(0) {
	GetNativeCPUID(arg_xcr0);
	HybridMasks(pCoreMask, eCoreMask, lpeCoreMask, systemAffMask);
}

void CPU_Props::GetNativeCPUID(UINT64 arg_xcr0) {
	int level00[4]			= {0, 0, 0, 0};
	int level01[4]			= {0, 0, 0, 0};
	int level07[4]			= {0, 0, 0, 0};
	int level0701[4]		= {0, 0, 0, 0};
	int level0702[4]		= {0, 0, 0, 0};
	int level15[4]			= {0, 0, 0, 0};
	int level16[4]			= {0, 0, 0, 0};
	int level19[4]			= {0, 0, 0, 0};
	int level1D[4]			= {0, 0, 0, 0};
	int level1D01[4]		= {0, 0, 0, 0};
	int level1E[4]			= {0, 0, 0, 0};
	int level1E01[4]		= {0, 0, 0, 0};
	int level24[4]			= {0, 0, 0, 0};
	int extLevel00[4]		= {0, 0, 0, 0};
	int extLevel01[4]		= {0, 0, 0, 0};
	int extLevel07[4]		= {0, 0, 0, 0};
	int extLevel08[4]		= {0, 0, 0, 0};
	int extLevel21[4]		= {0, 0, 0, 0};

	__cpuid(level00, 0x0);
	if (level00[_REG_EAX] >= 1)
		__cpuid(level01, 0x1);
	if (level00[_REG_EAX] >= 7)
		__cpuid(level07, 0x7);
	if (level07[_REG_EAX] > 0)
		__cpuidex(level0701, 0x7, 1);
	if (level07[_REG_EAX] > 1)
		__cpuidex(level0702, 0x7, 2);
	if (level00[_REG_EAX] >= 0x15)
		__cpuid(level15, 0x15);
	if (level00[_REG_EAX] >= 0x16)
		__cpuid(level16, 0x16);
	if (level00[_REG_EAX] >= 0x19)
		__cpuid(level19, 0x19);
	if (level00[_REG_EAX] >= 0x1D) {
		__cpuid(level1D, 0x1D);
		const unsigned int maxPalette = level1D[_REG_EAX];
		for (unsigned int p = 0; p < min(maxPalette, 1); p++) {
			__cpuidex(level1D01, 0x1D, p + 1);
		}
		if (level00[_REG_EAX] >= 0x1E) {
			__cpuid(level1E, 0x1E);
			__cpuidex(level1E01, 0x1E, 1);
		}
	}
	if (level00[_REG_EAX] >= 0x24)
		__cpuid(level24, 0x24);

	__cpuid(extLevel00, 0x80000000);
	if (extLevel00[_REG_EAX] >= 0x80000001)
		__cpuid(extLevel01, 0x80000001);
	if (extLevel00[_REG_EAX] >= 0x80000007)
		__cpuid(extLevel07, 0x80000007);
	if (extLevel00[_REG_EAX] >= 0x80000008)
		__cpuid(extLevel08, 0x80000008);
	if (extLevel00[_REG_EAX] >= 0x80000021)
		__cpuid(extLevel21, 0x80000021);

	if ((level01[_REG_ECX] & _FEAT01_ECX_OSXSAVE & 0xffffffff) == (_FEAT01_ECX_OSXSAVE & 0xffffffff))
		xcr0 = (arg_xcr0 == 0) ? _xgetbv(0) : arg_xcr0;

	vendor_num[0] = level00[_REG_EBX];
	vendor_num[1] = level00[_REG_EDX];
	vendor_num[2] = level00[_REG_ECX];

	if (extLevel00[_REG_EAX] >= 0x80000004) {
		__cpuid(brand_num[0], 0x80000002);
		__cpuid(brand_num[1], 0x80000003);
		__cpuid(brand_num[2], 0x80000004);
	}

	_CPUID_RES c = {xcr0, 
					level01[_REG_EAX], level01[_REG_ECX], level01[_REG_EDX], 
					level07[_REG_EBX], level07[_REG_ECX], level07[_REG_EDX], 
					level0701[_REG_EAX], level0701[_REG_EBX], level0701[_REG_ECX], level0701[_REG_EDX],
					level0702[_REG_EAX], level0702[_REG_EDX],
					level15[_REG_EAX], level15[_REG_EBX], level15[_REG_ECX], 
					level16[_REG_EAX], level16[_REG_EBX], level16[_REG_ECX], 
					level19[_REG_EBX], level1D[_REG_EAX], 
					level1D01[_REG_EAX], level1D01[_REG_EBX], level1D01[_REG_ECX],
					level1E[_REG_EAX], level1E01[_REG_EAX], level24[_REG_EBX],
					extLevel01[_REG_ECX], extLevel01[_REG_EDX], extLevel07[_REG_EDX], 
					extLevel08[_REG_EAX], extLevel08[_REG_EBX],
					extLevel21[_REG_EAX]};
	SetFeats(c);
}


bool CPU_Props::GetFileCPUID(char * fname, UINT64 arg_xcr0) {
	errno_t err;
	FILE *file = NULL;
	if ((err = fopen_s(&file, fname, "rb")) == 0) {
		char linebuf[128];
		_CPUID_RES c;
		memset(&c, 0, sizeof(_CPUID_RES));
		memset(&vendor_num, 0, sizeof(vendor_num));
		memset(&brand_num, 0, sizeof(brand_num));
		memset(&f, 0, sizeof(f));
		memset(&f_disabled, 0, sizeof(f_disabled));
		c.xcr0 = (arg_xcr0 == 0) ? xcr0 : arg_xcr0;
		while(TRUE) {
			if(!fgets(linebuf, sizeof(linebuf), file))
				break;
			if (strncmp(linebuf, "CPUID ", 6) == 0) {
				uint32_t in_EAX = 0, in_ECX = 0;
				uint32_t out_EAX = 0, out_EBX = 0, out_ECX = 0, out_EDX = 0;
				/* First format, no ecx input. */
				int catched = 0;
				/* AIDA64 CPUID dump format */
				if (!catched)
					catched = sscanf_s(linebuf, "CPUID %08X: %08X-%08X-%08X-%08X [SL %2d]", &in_EAX, &out_EAX, &out_EBX, &out_ECX, &out_EDX, &in_ECX) == 6;
				if (!catched) {
					in_ECX = 0;
					catched = sscanf_s(linebuf, "CPUID %08X: %08X-%08X-%08X-%08X", &in_EAX, &out_EAX, &out_EBX, &out_ECX, &out_EDX) == 5;
				}		
				switch (in_EAX) {
					case 0x00000000:
						vendor_num[0] = out_EBX;
						vendor_num[1] = out_EDX;
						vendor_num[2] = out_ECX;
						break;
					case 0x00000001:
						c.cpuid_res[CPUID_FEAT01_EAX] = out_EAX;
						c.cpuid_res[CPUID_FEAT01_ECX] = out_ECX;
						c.cpuid_res[CPUID_FEAT01_EDX] = out_EDX;
						break;
					case 0x00000007:
						switch (in_ECX) {
							case 0:
								c.cpuid_res[CPUID_FEAT07_EBX] = out_EBX;
								c.cpuid_res[CPUID_FEAT07_ECX] = out_ECX;
								c.cpuid_res[CPUID_FEAT07_EDX] = out_EDX;
								break;
							case 1:
								c.cpuid_res[CPUID_FEAT0701_EAX] = out_EAX;
								c.cpuid_res[CPUID_FEAT0701_EBX] = out_EBX;
								c.cpuid_res[CPUID_FEAT0701_ECX] = out_ECX;
								c.cpuid_res[CPUID_FEAT0701_EDX] = out_EDX;
								break;
							case 2:
								c.cpuid_res[CPUID_FEAT0702_EAX] = out_EAX;
								c.cpuid_res[CPUID_FEAT0702_EDX] = out_EDX;
							break;
								default:
									break;
							}
							break;
					case 0x00000015:
						c.cpuid_res[CPUID_FEAT15_EAX] = out_EAX;
						c.cpuid_res[CPUID_FEAT15_EBX] = out_EBX;
						c.cpuid_res[CPUID_FEAT15_ECX] = out_ECX;
					case 0x00000016:
						c.cpuid_res[CPUID_FEAT16_EAX] = out_EAX;
						c.cpuid_res[CPUID_FEAT16_EBX] = out_EBX;
						c.cpuid_res[CPUID_FEAT16_ECX] = out_ECX;
						break;
					case 0x00000019:
						c.cpuid_res[CPUID_FEAT19_EBX] = out_EBX;
						break;
					case 0x0000001D:
						switch (in_ECX) {
							case 0:
								c.cpuid_res[CPUID_FEAT1D_EAX] = out_EAX;
								break;
							case 1:
								c.cpuid_res[CPUID_FEAT1D01_EAX] = out_EAX;
								c.cpuid_res[CPUID_FEAT1D01_EBX] = out_EBX;
								c.cpuid_res[CPUID_FEAT1D01_ECX] = out_ECX;
								break;
							default:
								break;
						}
						break;
					case 0x0000001E:
						switch (in_ECX) {
							case 0:
								c.cpuid_res[CPUID_FEAT1E_EBX] = out_EBX;
								break;
							case 1:
								c.cpuid_res[CPUID_FEAT1E01_EAX] = out_EAX;
								break;
							default:
								break;
						}
						break;
					case 0x00000024:
						c.cpuid_res[CPUID_FEAT24_EBX] = out_EBX;
						break;
					case 0x80000001:
						c.cpuid_res[CPUID_EFEAT01_ECX] = out_ECX;
						c.cpuid_res[CPUID_EFEAT01_EDX] = out_EDX;
						break;
					case 0x80000002:
					case 0x80000003:
					case 0x80000004:
						brand_num[in_EAX - 0x80000002][0] = out_EAX;
						brand_num[in_EAX - 0x80000002][1] = out_EBX;
						brand_num[in_EAX - 0x80000002][2] = out_ECX;
						brand_num[in_EAX - 0x80000002][3] = out_EDX;
						break;
					case 0x80000007:
						c.cpuid_res[CPUID_EFEAT07_EDX] = out_EDX;
					case 0x80000008:
						c.cpuid_res[CPUID_EFEAT08_EAX] = out_EAX;
						c.cpuid_res[CPUID_EFEAT08_EBX] = out_EBX;
						break;
					case 0x80000021:
						c.cpuid_res[CPUID_EFEAT21_EAX] = out_EAX;
						break;
					default:
						break;
					}
			}
		}
		fclose(file);
		f[0] = f[1] = 0;
		f_disabled[0] = f_disabled[1] = 0;
		SetFeats(c);
		return true;
	} else {
		return false;
	}
};

using namespace std;

void CPU_Props::PrintVendor(void) const {
	cout << ": \"" << std::setw(VENDOR_STRING_SIZE) << magenta << vendor_string << white << "\"" << "          ";
} 

void CPU_Props::PrintBrand(void) const {
	cout << ": \"" << std::setw(48) << gold << left << brand_string << white << "\"";
}

void CPU_Props::PrintSupportStatus(bool supp, WORD col) const {
	cout << ": " << color(col) << (supp ? "supported" : "unsupported") << white;
}

void CPU_Props::PrintSupportStatus(int num, WORD col) const {
	cout << ": " << color(col) << num << white;
}

void CPU_Props::PrintOSStatus(bool enadisa, WORD col) const {
	cout << ", " << color(col) << (enadisa ? "OS enabled" : "OS disabled") << white;
}

void CPU_Props::PrintFeat(uint64_t f) const {
	cout << left << exts[f].name;
}

void CPU_Props::PrintFeatHex(int value, WORD col) const {
	cout << ": " << color(col) << left << hex << setw(10) << value << "              " <<  white;
}

void CPU_Props::PrintFeatDecHex(int value, WORD col) const {
	cout << ": "   << color(col) << right << dec << setw(3) << value;
	cout << " (0x" <<                        hex << setw(2) << setfill('0') << value << ")              " << setfill(' ') << white;
}

//req.  XSAVE    XSAVE
//feat enabled disabled   
// 0     0        0       unsupp
// 0     0        1       unsupp
// 0     1        0       unsupp
// 0     1        1       <illegal state>
// 1     0        0       unsupp
// 1     0        1       supp, OS dis
// 1     1        0       supp, OS en
// 1     1        1       <illegal state>

void CPU_Props::PrintFeat(bool required_feat, bool xsave_enabled, bool xsave_disabled) const {
	if (!required_feat) {
		PrintSupportStatus(false, COLOR_RED);
	} else {
		if (!xsave_enabled && !xsave_disabled) {
			PrintSupportStatus(false, COLOR_RED);
		} else if (xsave_enabled) {
			PrintSupportStatus(true, COLOR_GREEN);
			PrintOSStatus(true, COLOR_GREEN);
		} else if (xsave_disabled) {
			PrintSupportStatus(true, COLOR_YELLOW);
			PrintOSStatus(false, COLOR_YELLOW);
		}
	}
}

void CPU_Props::PrintFeat(bool required_feat, bool xsave_enabled, bool xsave_disabled, int num) const {
	if (!required_feat) {
		PrintSupportStatus(false, COLOR_RED);
	} else {
		if (!xsave_enabled && !xsave_disabled) {
			PrintSupportStatus(false, COLOR_RED);
		} else if (num != -1) {
			CharColor col = xsave_enabled ? COLOR_GREEN : COLOR_YELLOW;
			PrintSupportStatus(num, col);
			if (!xsave_enabled)
				PrintOSStatus(xsave_enabled, col);
		} 
	}
}

void CPU_Props::PrintFeats(void) const {
	for (int featInd = 0; featInd < sizeof(exts) / sizeof(_EXT); featInd++) {
		cout << left << std::setw(FEAT_NAME_SIZE) << exts[featInd].name;

		if (exts[featInd].cpuidPlace[0] != _FEAT_SKIP) {
			unsigned __int64 f_low	= 1ULL << (featInd & 0x3f);
			unsigned __int64 f_high	= (featInd & ~0x3f) >> 6;
			bool enabled = (f[f_high] & f_low) != 0;
			bool disabled = (f_disabled[f_high] & f_low) != 0;
			switch(exts[featInd]._xcr0) {
				case _XCR0_AVX:
					PrintFeat(IsFeatBit(FEAT_AVX), enabled, disabled);
					break;
				case _XCR0_AVX512:
					switch (featInd) {
						case FEAT_AVX10:	
						case FEAT_AVX10_128:
						case FEAT_AVX10_256:
						case FEAT_AVX10_512:
							PrintFeat(IsFeatBit(FEAT_AVX10), enabled, disabled);
							break;
						case FEAT_AVX10_LEVEL:
							PrintFeat(IsFeatBit(FEAT_AVX10), (avx10level != 0), false, avx10level);
							break;
						default:
							PrintFeat(IsFeatBit(FEAT_AVX512F), enabled, disabled);
							break;
					}
					break;
				case _XCR0_AMX:
				case _KEYLOCK:
					PrintFeat(true, enabled, disabled);
					break;
				case _XCR0_EMPTY:
				default:
					switch (exts[featInd]._feats) {
						case FEAT_VENDOR:
							PrintVendor();
							break;
						case FEAT_FAMILY:
							PrintFeatDecHex(family, COLOR_AQUA);
							break;
						case FEAT_MODEL:
							PrintFeatDecHex(model, COLOR_AQUA);
							break;
						case FEAT_STEPPING:
							PrintFeatDecHex(stepping, COLOR_AQUA);
							break;
						case FEAT_FMS:
							PrintFeatHex(fms, COLOR_AQUA);
							break;
						case FEAT_BRAND:
							PrintBrand();
							break;
						default:
							PrintSupportStatus(enabled, enabled ? COLOR_GREEN : COLOR_RED);
							break;
					}
					break;
			}
		}
		cout << endl;
	}
}

bool CPU_Props::IsFeat(int feat) const {
	const unsigned __int64 f_low	= 1ULL << (feat & 0x3f);
	const unsigned __int64 f_high	= (feat & ~0x3f) >> 6;
	return ((f[f_high] & f_low) == f_low);
}

bool CPU_Props::IsFeatBit(int feat) const {
	const unsigned __int64 f_low	= 1ULL << (feat & 0x3f);
	const unsigned __int64 f_high	= (feat & ~0x3f) >> 6;
	return (((f[f_high] & f_low) == f_low) || ((f_disabled[f_high] & f_low) == f_low));
}

bool CPU_Props::IsZen2(void) const {
	return (family == 0x17) && (vendor_num[1] == 0x69746e65);
}

bool CPU_Props::IsZen3(void) const {
	return (family == 0x19) && (vendor_num[1] == 0x69746e65);
}

int CPU_Props::GetFamMod(void) const {
	return fms & 0xfffffff0;
}

int CPU_Props::GetFam(void) const {
	return (fms & 0xf00) >> 8;
}

int CPU_Props::GetStepping(void) const {
	return fms & 0xf;
}

bool CPU_Props::IsInBrand(const char * str) const {
	return (0 != strstr(brand_string, str));
}

_VENDOR CPU_Props::GetVendor(void) const {
	return vendor;
}

unsigned int CPU_Props::GetAMXPalette_TotalTileBytes(unsigned int p = 0) const {
	return AMX_palette[p].total_tile_bytes;
};

unsigned int CPU_Props::GetAMXPalette_MaxName(unsigned int p = 0) const {
	return AMX_palette[p].max_names;
};

unsigned int CPU_Props::GetAMXRows() const {
	return AMX_TMUL.tmul_maxk;
};

unsigned int CPU_Props::GetAMXCols() const {
	return AMX_TMUL.tmul_maxn;
};

bool CPU_Props::HybridMasks(DWORD_PTR& pCoreMask, DWORD_PTR& eCoreMask, DWORD_PTR& lpeCoreMask, DWORD_PTR& systemMask) {
	DWORD_PTR processMask = 0, systemAffMask = 0;
	BOOL affFlag = GetProcessAffinityMask(GetCurrentProcess(), &processMask, &systemAffMask);
	if (affFlag != 0) {
		systemMask = systemAffMask;
		const DWORD_PTR threads = _ild_popcnt(systemAffMask);
		DWORD_PTR origThreadMask = SetThreadAffinityMask(GetCurrentThread(), 1);
		switch(GetVendor()) {
			case _VENDOR_INTEL: {
				int level00[4]			= {0, 0, 0, 0};
				__cpuid(level00, 0x0);
				if (level00[_REG_EAX] >= 0x1A) {
					for (unsigned int th = 0; th < threads; th++) {
						DWORD_PTR testMask = ((DWORD_PTR)1 << th);
						SetThreadAffinityMask(GetCurrentThread(), testMask);
						Sleep(0);
						int level1A[4] = {0, 0, 0, 0};
						__cpuid(level1A, 0x1A);
						switch (level1A[_REG_EAX] >> 24) {
							case 0x20: {
								switch (GetFamMod()) {
									case 0x000A06A0:  //METEORLAKE_L
									case 0x000A06C0:  //METEORLAKE
									case 0x000B0650: {//ARROWLAKE_U
										int leafData[4] = { 0, 0, 0, 0 };
										int _cacheleaf = 0x4;
										int _L3subleaf = 0x3;
										__cpuidex(leafData, _cacheleaf, _L3subleaf); //L3 cache test
										if (leafData[_REG_EAX] != 0) {
											eCoreMask	|= testMask;
											eCoreInfo	= level1A[_REG_EAX];
											eCoreIndex	= th;
										} else {
											lpeCoreMask		|= testMask;
											lpeCoreInfo		= level1A[_REG_EAX];
											lpeCoreIndex	= th;
										}
									} break;
									case 0x000B06C0:   //LUNARLAKE?
									case 0x000B06D0: { //LUNARLAKE_M
										lpeCoreMask		|= testMask;
										lpeCoreInfo		= level1A[_REG_EAX];
										lpeCoreIndex	= th;
									} break;
									case 0x000C0650: { //ARROW_LAKE_H
										switch (level1A[_REG_EAX] & 0xffffff) {
											case 0x02: {	//Crestmont
												lpeCoreMask		|= testMask;
												lpeCoreInfo		= level1A[_REG_EAX];
												lpeCoreIndex	= th;
											} break;
											case 0x3:		//Skymont
											default: {
												eCoreMask	|= testMask;
												eCoreInfo	= level1A[_REG_EAX];
												eCoreIndex	= th;
											} break;
										}
									} break;
									//other known Hybrids
									//case 0x000806A0:   //LAKEFIELD
									//case 0x00090670:   //ALDERLAKE_S
									//case 0x000906A0:   //ALDERLAKE_L
									//case 0x000B0670:   //RAPTORLAKE_S
									//case 0x000B06A0:   //RAPTORLAKE_L
									//case 0x000C0660:   //ARROWLAKE_S
									//case 0x000C06A0:   //ARROWLAKE_R
									//case 0x000C06C0:   //PANTHERLAKE_L
									//case 0x00400F00:   //NOVALAKE_S?
									default: {
										eCoreMask	|= testMask;
										eCoreInfo	= level1A[_REG_EAX];
										eCoreIndex	= th;
									} break;
								}
							} break;
							case 0x40: {
								pCoreMask	|= testMask;
								pCoreInfo	= level1A[_REG_EAX];
								pCoreIndex	= th;
							} break;
							default: {
								pCoreMask	|= testMask;
								pCoreInfo	= level1A[_REG_EAX];
								pCoreIndex	= th;
								break;
							}
						}
					} //for (unsigned int th = 0; th < threads; th++) 
				} // if (level00[_REG_EAX] >= 0x1A) 
			} break;
			case _VENDOR_AMD: {
				int extLevel00[4]		= {0, 0, 0, 0};
				__cpuid(extLevel00, 0x80000000);
				if (extLevel00[_REG_EAX] >= 0x80000026) {
					for (unsigned int th = 0; th < threads; th++) {
						DWORD_PTR testMask = ((DWORD_PTR)1 << th);
						SetThreadAffinityMask(GetCurrentThread(), testMask);
						Sleep(0);
						int extlevel26[4] = {0, 0, 0, 0};
						__cpuid(extlevel26, 0x80000026);
						switch (extlevel26[_REG_EBX] >> 24) {
							default:
							case 0x0: {
								pCoreMask	|= testMask;
								pCoreInfo	= extlevel26[_REG_EBX];
								pCoreIndex	= th;
							} break;
							case 0x1: {
								eCoreMask	|= testMask;
								eCoreInfo	= extlevel26[_REG_EBX];
								eCoreIndex	= th;
							} break;
						}
					}
				}
			} break;
			default:
				break;
		}
		SetThreadAffinityMask(GetCurrentThread(), origThreadMask);
		return true;
	} else {
		return false;
	}
}

void CPU_Props::ForcedAVX512(void) const {
	if (IsFeat(FEAT_AVX512F)) {
		DWORD_PTR processMask = 0, systemAffMask = 0;
		BOOL affFlag = GetProcessAffinityMask(GetCurrentProcess(), &processMask, &systemAffMask);
		if (affFlag != 0) {
			const DWORD_PTR threads = _ild_popcnt(systemAffMask);
			DWORD_PTR origThreadMask = SetThreadAffinityMask(GetCurrentThread(), 1);
			for (unsigned int th = 0; th < threads; th++) {
				DWORD_PTR testMask = ((DWORD_PTR) 1 << th);
				SetThreadAffinityMask(GetCurrentThread(), testMask);
				Sleep(0);
				__m512i test =  _mm512_set1_epi32(th);
				cout << "AVX512F VPBROADCASTD zmm, gpr executed on thread " << test.m512i_u32[0] << endl;
			}
			SetThreadAffinityMask(GetCurrentThread(), origThreadMask);
			return;
		}
	}
}

void CPU_Props::PrintHybridMasks(void) const {
	cout << "--Hybrid info--" << endl;
	cout << "systemAffinityMask: 0x" << hex << setw(sizeof(DWORD_PTR) * 2) << setfill('0') << right << systemAffMask << endl;
	if (pCoreMask != 0) {
		cout << "PCoreMask         : 0x" << hex << setw(sizeof(DWORD_PTR) * 2) << setfill('0') << right << pCoreMask << ' ';
		if (pCoreInfo != DEFAULT_COREINFO)
			PrintHybridType(pCoreInfo);
		cout << endl;
	}
	if (eCoreMask != 0) {
		cout << "ECoreMask         : 0x" << hex << setw(sizeof(DWORD_PTR) * 2) << setfill('0') << right << eCoreMask << ' ';
		if (eCoreInfo != DEFAULT_COREINFO)
			PrintHybridType(eCoreInfo);
		cout << endl;
	}
	if (lpeCoreMask != 0) {
		cout << "LPECoreMask       : 0x" << hex << setw(sizeof(DWORD_PTR) * 2) << setfill('0') << right << lpeCoreMask << ' ';
		if (lpeCoreInfo != DEFAULT_COREINFO)
			PrintHybridType(lpeCoreInfo);
		cout << endl;
	}
	cout << setfill(' ');
}

void CPU_Props::PrintHybridType(int hybrid) const {
	switch(GetVendor()) {
		default:
		case _VENDOR_INTEL: {
			int type = hybrid & 0xff;
			switch (hybrid >> 24) {
				case 0x20:
					cout << "[Atom: ";
					cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, type)][CPUID_ATOM_NAME];
					cout << ']';
					break;
				case 0x40:
					cout << "[Core: ";
					switch(GetFamMod()) {
						default:
							cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, type)][CPUID_CORE_NAME];
							break;
						case 0x000B0670:
						case 0x000B06A0:
						case 0x000B06F0:
							cout << "Raptor Cove";
							break;
					}
					cout << ']';
					break;
				default:
					break;
			}
		} break;
		case _VENDOR_AMD: {
			switch (hybrid >> 24) {
				default:
				case 0x00:
					cout << "[P-core]";
					break;
				case 0x01:
					cout << "[E-core]";
					break;
			}
		} break;
	}
}

void CPU_Props::PrintXCR0(void) const {
	cout << "XCR0: 0x" << hex << setw(sizeof(DWORD_PTR) * 2) << setfill('0') << right << xcr0 << endl;
}

DWORD_PTR CPU_Props::GetPCoreMask(void) const {
	return pCoreMask;
};

DWORD_PTR CPU_Props::GetECoreMask(void) const {
	return eCoreMask;
};

DWORD_PTR CPU_Props::GetLPECoreMask(void) const {
	return lpeCoreMask;
};

DWORD_PTR CPU_Props::GetPCoreIndex(void) const {
	return pCoreIndex;
};

DWORD_PTR CPU_Props::GetECoreIndex(void) const {
	return eCoreIndex;
};

DWORD_PTR CPU_Props::GetLPECoreIndex(void) const {
	return lpeCoreIndex;
};

DWORD_PTR CPU_Props::GetSystemAffMask(void) const {
	return systemAffMask;
};

#if defined (_M_X64) && defined(__AVX512F__)
void CPU_Props::Print_512bFMA_DP_Ports(void) const {
	cout << "512b double precision FMA ports: " << Get_512bFMA_DP_Ports() << endl;
}

//based on 
//https://github.com/jeffhammond/vpu-count
//https://ark.intel.com/content/www/us/en/ark/products/codename/37572/skylake.html#@Server
//https://ark.intel.com/content/www/us/en/ark/products/codename/124664/cascade-lake.html
//https://ark.intel.com/content/www/us/en/ark/products/codename/189143/cooper-lake.html
//https://ark.intel.com/content/www/us/en/ark/products/codename/74979/ice-lake.html
//06_55h / CPUID 6065x stepping info:
//https://software.intel.com/security-software-guidance/processors-affected-transient-execution-attack-mitigation-product-cpu-model
//Future CPUIDs:
//https://www.reddit.com/user/Komachi_ENSAKA/comments/iy9avs/memo/
//CPU notation:
//https://github.com/torvalds/linux/blob/master/arch/x86/include/asm/intel-family.h
//Jintide CPUs:
//https://www.montage-tech.com/Jintide_Platform/Jintide_CPU 
//https://old.hotchips.org/hc31/HC31_2.11_Jintide_Server_CPU_final_r6.0.pdf
//46th Intel ISA Future Programming Reference 319433-046.pdf:
//https://cdrdv2.intel.com/v1/dl/getContent/671368
//Xeon 3450C source:
//https://twitter.com/OneRaichu/status/1613202364256882688
//
// Actual Intel brand strings CPUID 80000003h-80000005h
// 00000000001111111111222222222233333333334444444
// 01234567890123456789012345678901234567890123456
//"Intel(R) Core(TM) i9-7980XE CPU @ 2.60GHz"
//"Intel(R) Core(TM) i9-7900X CPU @ 3.30GHz"
//"Intel(R) Core(TM) i7-7820X CPU @ 3.60GHz"
//"Intel(R) Core(TM) i7-7800X CPU @ 3.50GHz"
//"Intel(R) Xeon(R) Platinum 8268 CPU @ 2.90GHz"
//"Intel(R) Xeon(R) Platinum 8180 CPU @ 2.50GHz"
//"Intel(R) Xeon(R) Platinum 8176 CPU @ 2.10GHz"
//"Intel(R) Xeon(R) Platinum 8170 CPU @ 2.10GHz"
//"Intel(R) Xeon(R) Gold 6258R CPU @ 2.70GHz"
//"Intel(R) Xeon(R) Gold 6250 CPU @ 3.90GHz"
//"Intel(R) Xeon(R) Gold 6240C CPU @ 2.60GHz"
//"Intel(R) Xeon(R) Gold 6212U CPU @ 2.40GHz"
//"Intel(R) Xeon(R) Gold 6154 CPU @ 3.00GHz"
//"Intel(R) Xeon(R) Gold 6154 CPU @ 3.00GHz"
//"Intel(R) Xeon(R) Gold 6149 CPU @ 3.10GHz"
//"Intel(R) Xeon(R) Gold 6130 CPU @ 2.10GHz"
//"Intel(R) Xeon(R) Gold 5220R CPU @ 2.20GHz"
//"Intel(R) Xeon(R) Gold 5218 CPU @ 2.30GHz"
//"Intel(R) Xeon(R) Gold 5215 CPU @ 2.50GHz"
//                       ^^^^
// 00000000001111111111222222222233333333334444444
// 01234567890123456789012345678901234567890123456
//"Intel(R) Xeon(R) Silver 4214 CPU @ 2.20GHz"
//"Intel(R) Xeon(R) Silver 4108 CPU @ 1.80GHz"
//"Intel(R) Xeon(R) Bronze 3104 CPU @ 1.70GHz"
//"Intel(R) Xeon(R) D-2183IT CPU @ 2.20GHz"
//"Intel(R) Xeon(R) W-3275 CPU @ 2.50GHz"
//"Intel(R) Xeon(R) W-3175X CPU @ 3.10GHz"
//"Intel(R) Xeon(R) W-2295 CPU @ 3.00GHz"
//"Intel(R) Xeon(R) W-2191B CPU @ 2.30GHz"
//"Intel(R) Xeon(R) W-2155 CPU @ 3.30GHz"
//"Intel(R) Xeon(R) W-2125 CPU @ 4.00GHz"
//                  ^   ^
// 00000000001111111111222222222233333333334444444
// 01234567890123456789012345678901234567890123456
//"Montage(R) Jintide(R) C2460 1"
//"Genuine Intel(R) CPU 0000%@"
//"" <empty>

int CPU_Props::Get_512bFMA_DP_Ports(void) const { //v0100
	if (IsFeat(FEAT_AVX512F)) {
		switch(GetVendor()) {
			case _VENDOR_INTEL:
				switch(GetFamMod()) {
					case 0x00050650: {	//SKYLAKE_X
							switch (GetStepping()) {
								case 0: case 1: case 2:		//SkyLake-X/W/D/SP ES
								case 3: case 4:				//SkyLake-X/W/D/SP
								case 5: case 6: case 7: {	//Cascade Lake-X/W/D/SP
									if (IsInBrand("Core"))
										return 2;
									else if (IsInBrand("Xeon")) 
										if (IsInBrand("Platinum"))
											return 2;
										else if (IsInBrand("Silver") ||	IsInBrand("Bronze"))
											return 1;
										else if (IsInBrand("Gold"))
											if (brand_string[22] == '5')  {
												if ((10 * (brand_string[24] - '0')) + (brand_string[25] - '0') == 22) 
													return 2; //Xeon Gold 5222, 5122
												else
													return 1;
											} else {//Xeon Gold 6xxx
												return 2;
											}
										else
											switch (brand_string[17]) {
												case 'W':
													if (brand_string[21] == '0') //Xeon W-2104, W-2102
														return 1;
													else 
														return 2;
												case 'D':
													return 1;
												default: //unknown Xeon
													return 2;
											}
									else //unknown brand string, 
										//e.g.1 "Genuine Intel(R) CPU 0000%@"
										//e.g.2 "Montage(R) Jintide(R) C2460 1", 
										return Get_512bFMA_DP_Ports_FromOptimGuide();
										//return 2;
								}
								case 0xa: case 0xb: //Cooper Lake
								default: 
									return 2;
							}
						} break;
					case 0x000806F0: {	//Golden Cove              / SAPPHIRERAPIDS_X 
						if (IsInBrand("3408U") || IsInBrand("3508U") || IsInBrand("3450C")) //Intel Xeon Bronze 3408U; Xeon Bronze 3508U; Xeon 3450C Processor
							return 1;
						else
							return 2;
						} break;
					case 0x00060660:	//Palm Cove                         / CANNONLAKE_L 
					case 0x00060670:	//Palm Cove                         / CANNONLAKE - cancelled ?
					case 0x000606C0:	//Sunny Cove                        / ICELAKE_D
					case 0x000706D0: 	//Sunny Cove                        / ICELAKE - cancelled ?
					case 0x000706E0: 	//Sunny Cove                        / ICELAKE_L
					case 0x00080650:	//Silvermont                        / XEON_PHI_KNM 1 for DP, 2 for SP
					case 0x000806C0: 	//Willow Cove                       / TIGERLAKE_L
					case 0x000806D0: 	//Willow Cove                       / TIGERLAKE
					case 0x00090650:	//Golden Cove                       / SAPPHIRERAPIDS
					case 0x00090670:	//Golden Cove + Gracemont           / ALDERLAKE
					case 0x000906A0:	//Golden Cove + Gracemont           / ALDERLAKE_L
					case 0x000A0670: 	//Cypress Cove                      / ROCKETLAKE
					case 0x000A0680: 	//Cypress Cove                      / ROCKETLAKE_L - cancelled ?
						return 1;
					case 0x00050670:	//Silvermont                        / XEON_PHI_KNL
					case 0x000606A0:	//Sunny Cove                        / ICELAKE_X
					case 0x000A06D0:	//Redwood Cove                      / GRANITERAPIDS_X AVX10.1/512
					case 0x000A06E0:	//Redwood Cove                      / GRANITERAPIDS_D
					case 0x000C06F0:	//Raptor Cove                       / EMERALDRAPIDS_X
					case 0x000D0660:	//Panther Cove                      / DIAMONDRAPIDS_X, AVX10.2/512
					case 0x00400F10:	//Panther Cove                      / DIAMONDRAPIDS_X, AVX10.2/512
						return 2;
					case 0x000806A0:	//Sunny Cove + Tremont              / LAKEFIELD, AVX512 disabled
					case 0x000A06A0:	//Redwood Cove + Crestmont          / METEORLAKE_L
					case 0x000A06C0:	//Redwood Cove + Crestmont          / METEORLAKE
					case 0x000A06F0:	//Crestmont                         / SIERRAFOREST_X
					case 0x000B0650:	//Redwood Cove + Crestmont          / ARROWLAKE_U
					case 0x000B0660:	//Crestmont                         / GRANDRIDGE
					case 0x000B0670:	//Raptor Cove + Gracemont           / RAPTORLAKE
					case 0x000B06A0:	//Raptor Cove + Gracemont           / RAPTORLAKE_P
					case 0x000B06C0:	//Lion Cove + Skymont               / LUNARLAKE
					case 0x000B06D0:	//Lion Cove + Skymont               / LUNARLAKE_M
					case 0x000B06E0:	//Gracemont                         / ALDERLAKE_N
					case 0x000B06F0:	//Raptor Cove + Gracemont           / RAPTORLAKE_S
					case 0x000C0650:	//Lion Cove + Skymont + Crestmont   / ARROW_LAKE_H
					case 0x000C0660:	//Lion Cove + Skymont               / ARROW_LAKE_S
					case 0x000C06C0:	//Cougar Cove + Darkmont            / PANTHER_LAKE
					case 0x000D06D0:	//Darkmont                          / CLEARWATERFOREST_X
					case 0x00400F00:	//Panther Cove + Arctic Wolf?       / NOVALAKE, AVX10.2/256?
					default:			//on other cores, AVX512F unsupported
						return 0;
					//future
					//case 0x000906D0:	//Sunny Cove   / ICELAKE_NNPI / Spring Hill - cancelled ?
					//case 0x000906F0:	//Sunny Cove   / ICELAKE_R ?
				}
				break;
			case _VENDOR_AMD:
				switch(GetFamMod() & 0xffffff00) {
					case 0x00A10F00:	//Zen4/Genoa, Storm Peak
					case 0x00A60F00:	//Zen4/Raphael
					case 0x00A70F00:	//Zen4/Phoenix, Phoenix2
					case 0x00A80F00:	//Zen4/MI300C
					case 0x00A90F00:	//Zen4/MI300A
					case 0x00AA0F00:	//Zen4/Bergamo
					//Zen5 CPUID source: https://github.com/ganeshgit/llvm-project/blob/cedee6b46865b0ca560364193ffec2c1366b06e6/llvm/lib/TargetParser/Host.cpp
					case 0x00B20F00:	//Zen5/Strix Point
					case 0x00B30F00:	//Zen5/Strix Point2, Strix Point3
					case 0x00B60F00:	//Zen5/Krackan
						return 1;
					case 0x00B00F00:	//Zen5/Turin
					case 0x00B10F00:	//Zen5/Turin Dense
					case 0x00B40F00:	//Zen5/Granite Ridge
					case 0x00B50F00:	//Zen5/Weisshorn
					case 0x00B70F00:	//Zen5/Strix Halo
						return 2;
					default:
						return 0;
				}
			case _VENDOR_CENTAUR:
			case _VENDOR_ZHAOXIN:
				switch(GetFamMod() & 0xfffffff0) {
					case 0x00040670:	//CNS
						return 1;
					case 0x000507B0:	//ZX-F
					default:
						return 0;
				}
			default:
				return 0;
		} // switch(GetVendor()) 
	} else { //if (IsFeat(FEAT_AVX512F)) 
		return 0;
	}
}
#endif

void CPU_Props::PrintLeaf(uint32_t leafs, int* leaf) const {
	cout << "CPUID ";
	cout << hex << uppercase << right << setw(8) << setfill('0') << leafs << ": ";
	for (int reg = _REG_EAX; reg <= _REG_EDX; reg++) {
		cout << hex << uppercase << right << setw(8) << setfill('0') << leaf[reg];
		cout << ((reg != _REG_EDX) ? '-' : ' ');
	}
}

void CPU_Props::PrintSingleLeaf(uint32_t leafs, int* leaf) const {
	PrintLeaf(leafs, leaf);
	cout << endl;
}

void CPU_Props::PrintSubLeaf(uint32_t leafs, int* leaf, int subLeaf) const {
	PrintLeaf(leafs, leaf);
	cout << "[SL " << hex << uppercase << setw(2) << right << setfill('0') << subLeaf << ']' << endl;
}

void CPU_Props::PrintSubLeaf(uint32_t leafs, int* leaf, int subLeaf, cpuidStr str, int strInd) const {
	PrintLeaf(leafs, leaf);
	cout << "[SL " << hex << uppercase << setw(2) << right << setfill('0') << subLeaf << "] [" << _cpuid_names[min(MAX_CPUIDSTR - 1, strInd)][min(str, CPUID_STR_LAST - 1)] << ']' << endl;
}

void CPU_Props::SetFeats(_CPUID_RES& c) {
	for (int v = 0; v < _VENDOR_LAST; v++) {
		if ((vendors[v].vendor[0] == vendor_num[0]) && 
			(vendors[v].vendor[1] == vendor_num[1]) &&
			(vendors[v].vendor[2] == vendor_num[2])) {
			vendor = vendors[v].v;
			break;
		}
	}
	family		= ((c.cpuid_res[CPUID_FEAT01_EAX] >> 8) & 0xf) + ((c.cpuid_res[CPUID_FEAT01_EAX] >> 20) & 0xf);
	model		= ((c.cpuid_res[CPUID_FEAT01_EAX] >> 4) & 0xf) | ((c.cpuid_res[CPUID_FEAT01_EAX] >> 12) & 0xf0);
	stepping	= (c.cpuid_res[CPUID_FEAT01_EAX] & 0xf);
	fms			= c.cpuid_res[CPUID_FEAT01_EAX];

	for (int featInd = 0; featInd < sizeof(exts) / sizeof(_EXT); featInd++) {
		if (*exts[featInd].name == 0)
			continue;
		for (int cpuidPlaces = 0; cpuidPlaces < CPUID_MAXPLACE; cpuidPlaces++) {
			unsigned long place = (unsigned long)(exts[featInd].cpuidPlace[cpuidPlaces] >> 32);
			unsigned long fbit = (unsigned long)(exts[featInd].cpuidPlace[cpuidPlaces] & ~0UL);
			unsigned __int64 f_low = 1ULL << (featInd & 0x3f);
			unsigned __int64 f_high = (featInd & ~0x3f) >> 6;
			switch (place) {
				case _FEAT_SKIP:
					continue;
				case CPUID_NOPLACE:
					switch (exts[featInd]._feats) { //special LNOP detection
						case FEAT_LNOP: {
							switch (GetFam()) {
								case 0x6:
								case 0x7:
								case 0xf:
									f[f_high] |= f_low;
									break;
								default:
									break;
								}
							} break;
						case FEAT_X86: { //FEAT_X86 always present
							f[f_high] |= f_low;
						} break;
						default:
							break;
						}
					break;
				case CPUID_NUMFIELD: //non-binary CPUID info
					switch (exts[featInd]._feats) {
						case FEAT_FAMILY: {
							family		= ((c.cpuid_res[CPUID_FEAT01_EAX] >> 8) & 0xf) + ((c.cpuid_res[CPUID_FEAT01_EAX] >> 20) & 0xf);
						} break;
						case FEAT_MODEL: {
							model		= ((c.cpuid_res[CPUID_FEAT01_EAX] >> 4) & 0xf) | ((c.cpuid_res[CPUID_FEAT01_EAX] >> 12) & 0xf0);
						} break;
						case FEAT_STEPPING: {
							stepping	= c.cpuid_res[CPUID_FEAT01_EAX] & 0xf;
						} break;
						case FEAT_FMS: {
							fms			= c.cpuid_res[CPUID_FEAT01_EAX];
						} break;
						case FEAT_AVX10_LEVEL: {
							if (IsFeat(FEAT_AVX10))
								avx10level = c.cpuid_res[CPUID_FEAT24_EBX] & 0xff;
						} break;
						default:
							break;
					}
					break;
				default:
					if ((c.cpuid_res[min(CPUID_LAST - 1, place)] & fbit) == fbit) {
						switch (exts[featInd]._xcr0) {
							case _XCR0_EMPTY:
								f[f_high] |= f_low;
								break;
							case _KEYLOCK:
								if (IsFeat(FEAT_KEYLOCK))
									f[f_high] |= f_low;
								break;
							default:
								if ((c.xcr0 & exts[featInd]._xcr0) == exts[featInd]._xcr0)
									f[f_high] |= f_low;
								else
									f_disabled[f_high] |= f_low;
								break;
						}
					}
					break;
			}
		}
	}
	if (IsFeat(FEAT_AMX_TILE)) {
		AMX_palette[0].total_tile_bytes	= c.cpuid_res[CPUID_FEAT1D01_EAX] & 0xffff;
		AMX_palette[0].bytes_per_tile	= c.cpuid_res[CPUID_FEAT1D01_EAX] >> 16;
		AMX_palette[0].bytes_per_row	= c.cpuid_res[CPUID_FEAT1D01_EBX] & 0xffff;
		AMX_palette[0].max_names		= c.cpuid_res[CPUID_FEAT1D01_EBX] >> 16;
		AMX_palette[0].max_rows			= c.cpuid_res[CPUID_FEAT1D01_ECX] & 0xffff;

		AMX_TMUL.tmul_maxk	= c.cpuid_res[CPUID_FEAT1E_EBX] & 0xff;
		AMX_TMUL.tmul_maxn	= (c.cpuid_res[CPUID_FEAT1E_EBX] >> 8) & 0xffff;
	}
}

bool CPU_Props::_2levelL1D() const {
	bool	retVal = false;
	int		leaf[4] = {0, 0, 0, 0};
	__cpuid(leaf, 0x00);
	if (leaf[0] >= 0x1A) {
		__cpuid(leaf, 0x1A);
		switch (leaf[0]) {
			case 0x40000003: //Lion Cove
				retVal = true;
				break;
			default:
				break;
		}
	}
	return retVal;
}

void CPU_Props::PrintCPUIDDump(void) const {
	WORD gCount = GetActiveProcessorGroupCount();
	GROUP_AFFINITY ga;
	GROUP_AFFINITY ga_orig;
	GetThreadGroupAffinity(GetCurrentThread(), &ga_orig);
	ga.Reserved[0]	= ga.Reserved[1] =	ga.Reserved[2] = 0;
	for (uint32_t gr = 0; gr < gCount; gr++) {
		DWORD apc = GetActiveProcessorCount(gr);
		DWORD_PTR processMask = ~0ULL >> (sizeof(DWORD_PTR) * 8 - apc);
		ga.Group	= gr;
		int      leaf[5]					= {0, 0, 0, 0, 0};
		uint32_t startLeafs[MAX_STARTLEAF]	= { 0x00000000, //Standard
												0x20000000, //Xeon Phi
												0x40000000, //VirtualMachine
												0x80000000, //AMD
												0x80860000, //Transmeta
												0xc0000000	//Centaur/Via/Zhaoxin
												};
		for (unsigned int th = 0; th < apc; th++) {
			DWORD_PTR testMask = ((DWORD_PTR) 1 << th);
			ga.Mask		= testMask;
			SetThreadGroupAffinity(GetCurrentThread(), &ga, NULL);
			cout << "Group: 0x" << hex << uppercase << setw(2) << setfill('0') << gr;
			cout << " Affinity mask: 0x" << hex << uppercase << setw(16) << setfill('0') << testMask << endl;
			Sleep(0);
			for (int startleaf = 0; startleaf < MAX_STARTLEAF; startleaf++) {
				__cpuid(leaf, startLeafs[startleaf]);
				const uint32_t lastLeaf = leaf[_REG_EAX];
				if (lastLeaf != 0) {
					for (uint32_t leafs = startLeafs[startleaf]; leafs <= lastLeaf; leafs++) {
						__cpuid(leaf, leafs);
						switch (leafs) {
							default:
								PrintSingleLeaf(leafs, leaf);
								break;
							case 0x00000000: {	//Standard
								PrintLeaf(leafs, leaf);
								cout << '[' << std::setw(VENDOR_STRING_SIZE) << vendor_string << ']' << endl;
							} break;
							case 0x20000000:	//Xeon Phi
							case 0x80000000:	//AMD
							case 0x80860000:	//Transmeta
							case 0xc0000000: {	//Centaur/Via/Zhaoxin
								PrintLeaf(leafs, leaf);
								union {
									char					vendor_string[VENDOR_STRING_SIZE];
									unsigned long			vendor_num[VENDOR_NUM_SIZE]  = {0, 0, 0, 0};
								} vendor;
								vendor.vendor_num[0] = leaf[_REG_EBX];
								vendor.vendor_num[1] = leaf[_REG_EDX];
								vendor.vendor_num[2] = leaf[_REG_ECX];
								cout << '[' << vendor.vendor_string << ']' << endl;
							} break;
							case 0x40000000: {	//VirtualMachine
								PrintLeaf(leafs, leaf);
								union {
									char					vendor_string[VENDOR_STRING_SIZE];
									unsigned long			vendor_num[VENDOR_NUM_SIZE]  = {0, 0, 0, 0};
								} vendor;
								vendor.vendor_num[0] = leaf[_REG_EBX];
								vendor.vendor_num[1] = leaf[_REG_ECX];
								vendor.vendor_num[2] = leaf[_REG_EDX];
								cout << '[' << vendor.vendor_string << ']' << endl;
							} break;
							case 0x04:	//Deterministic Cache Parameters Leaf
							case 0x8000001D: {
								int subleaf = 0;
								__cpuidex(leaf, leafs, subleaf);
								while ((leaf[_REG_EAX] & 0x1f) != 0) {
									unsigned int type = leaf[_REG_EAX] & 0x1f;
									unsigned int clevel = (leaf[_REG_EAX] >> 5) & 0x7;
									unsigned int cacheLine	= (leaf[_REG_EBX] & 0x7ff) + 1;				//cacheline size
									unsigned int cacheAssoc	= (leaf[_REG_EBX] >> 22) + 1;				//cache associativity
									unsigned int cacheSize	= ((leaf[_REG_EBX] >> 12) & 0x3ff) + 1;		//partitions
												cacheSize	*= leaf[_REG_ECX] + 1;						//cache sets
												cacheSize	*= cacheLine * cacheAssoc;					//size in bytes
												cacheSize	>>= 10;										//in KiB

									PrintLeaf(leafs, leaf);
									cout << "[SL " << hex << uppercase << setw(2) << right << setfill('0') << subleaf;
									if (_2levelL1D() && (type == 1) && (clevel == 1)) {
										cout << "] [L0 + L" << clevel << ' ';
										cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, type)][CPUID_CACHE_TYPE] << ' ';
										cout << dec << setw(2) << right << setfill(' ') << cacheSize << " + 192 KiB ";
									} else {
										cout << "] [L" << clevel << "      ";
										cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, type)][CPUID_CACHE_TYPE] << ' ';
										cout << dec << setw(8) << right << setfill(' ') << cacheSize << " KiB ";
									}
									cout << dec << setw(3) << right << setfill(' ') << cacheAssoc << "-way ";
									cout << dec << setw(3) << right << setfill(' ') << cacheLine << "-byte Line ";
									cout << (leaf[_REG_EDX] & 0x001 ? 'W' : '-'); //EDX Bit 00: Write-Back Invalidate/Invalidate.
									cout << (leaf[_REG_EDX] & 0x002 ? 'L' : '-'); //EDX Bit 01: Cache Inclusivenes
									cout << (leaf[_REG_EDX] & 0x004 ? 'C' : '-'); //EDX Bit 02: Complex Cache Indexing or Direct mapped(???)
									cout << (leaf[_REG_EAX] & 0x100 ? 'S' : '-'); //EAX Bit 08: Self Initializing cache level (does not need SW initialization
									cout << (leaf[_REG_EAX] & 0x200 ? 'A' : '-'); //EAX Bit 09: Fully Associative cache.
									cout << ']' << endl;

									__cpuidex(leaf, leafs, ++subleaf);
								};
							} break;
							case 0x07:	//Structured Extended Feature Flags Enumeration Leaf
							case 0x14:	//Intel Processor Trace Enumeration Main Leaf
							case 0x17:	//System-On-Chip Vendor Attribute Enumeration Main Leaf
							//case 0x1D:
							case 0x20:	//Processor History Reset Sub-leaf 
							case 0x23:	//Architectural Performance Monitoring Extended Main Leaf
							case 0x24:	{//AVX10 Leaf
								int lastSubLeaf = leaf[_REG_EAX];
								for (int subleaf = 0; subleaf <= lastSubLeaf; subleaf++) {
									__cpuidex(leaf, leafs, subleaf);
									PrintSubLeaf(leafs, leaf, subleaf);
								};
							} break;
							case 0x0B:	//Extended Topology Enumeration Leaf
							case 0x1F:	{//V2 Extended Topology Enumeration Leaf
								int subleaf = 0;
								__cpuidex(leaf, leafs, subleaf);
								PrintSubLeaf(leafs, leaf, subleaf++);
								do {
									__cpuidex(leaf, leafs, subleaf);
									PrintSubLeaf(leafs, leaf, subleaf++);
								} while ((leaf[_REG_ECX] & 0xffffff00) != 0); 
							} break;
							case 0x0D:	{//Processor Extended State Enumeration Main Leaf
								PrintSubLeaf(leafs, leaf, 0, CPUID_STATE, 0);
								uint64_t validmask = (uint64_t)leaf[_REG_EDX] << 32 | leaf[_REG_EAX];
								__cpuidex(leaf, leafs, 1);
								validmask |= (uint64_t)leaf[_REG_EDX] << 32 | leaf[_REG_ECX];
								PrintSubLeaf(leafs, leaf, 1, CPUID_STATE, 1);
								for (int subleaf = 2; subleaf < 0x40; subleaf++) {
									if ((validmask & (1ULL << subleaf)) != 0) {
										__cpuidex(leaf, leafs, subleaf);
										PrintSubLeaf(leafs, leaf, subleaf, CPUID_STATE, subleaf);
									}
								}
							} break;
							case 0x0F: { //Intel Resource Director Technology (Intel RDT) Monitoring Enumeration
								int levels = leaf[_REG_EDX];
								PrintSubLeaf(leafs, leaf, 0);
								for (int level = 1; level < 32; level++) {
									if ((levels & (1UL << level)) != 0) {
										__cpuidex(leaf, leafs, level);
										PrintSubLeaf(leafs, leaf, level);
									}
								}
							} break;
							case 0x10:		   //Intel Resource Director Technology (Intel RDT) Allocation Enumeration
							case 0x80000020: { //Platform QoS
								int levels = leaf[_REG_EBX];
								PrintSubLeaf(leafs, leaf, 0);
								for (int level = 1; level < 32; level++) {
									if ((levels & (1UL << level)) != 0) {
										__cpuidex(leaf, leafs, level);
										PrintSubLeaf(leafs, leaf, level);
									}
								}
							} break;
							case 0x12: { //Intel SGX Capability Enumeration Leaf
								PrintSubLeaf(leafs, leaf, 0);
								__cpuidex(leaf, leafs, 1);
								PrintSubLeaf(leafs, leaf, 1);
								__cpuidex(leaf, leafs, 2);
								int subleaf = 2;
								while (leaf[_REG_EAX] != 0) {
									PrintSubLeaf(leafs, leaf, subleaf);
									__cpuidex(leaf, leafs, ++subleaf);
								}
							} break;
							case 0x15: {//Time Stamp Counter and Core Crystal Clock Information Leaf
								PrintLeaf(leafs, leaf);
								cout << '[' ;
								cout << dec << leaf[_REG_EAX];
								cout << " / ";
								cout << dec << leaf[_REG_EBX];
								cout << " / ";
								cout << dec << leaf[_REG_ECX];
								cout << ']' << endl;
							} break;
							case 0x16: {//Processor Frequency Information Leaf
								PrintLeaf(leafs, leaf);
								cout << '[' ;
								cout << dec << (leaf[_REG_EAX] & 0xffff);
								cout << " / ";
								cout << dec << (leaf[_REG_EBX] & 0xffff);
								cout << " / ";
								cout << dec << (leaf[_REG_ECX] & 0xffff);
								cout << ']' << endl;
							} break;
							case 0x18:	{//Deterministic Address Translation Parameters Main Leaf
								int lastSubLeaf = leaf[_REG_EAX];
								PrintSubLeaf(leafs, leaf, 0);
								for (int subleaf = 0; subleaf <= lastSubLeaf; subleaf++) {
									__cpuidex(leaf, leafs, subleaf);
									unsigned int TLBpage	= leaf[_REG_EBX] & 0xf;
									unsigned int TLBassoc	= leaf[_REG_EBX] >> 16;
									unsigned int TLBset		= leaf[_REG_ECX];
									unsigned int TLBentries	= TLBassoc * TLBset;
									unsigned int TLBlevel	= (leaf[_REG_EDX] >> 5) & 0x7;
									unsigned int TLBtype	= leaf[_REG_EDX] & 0x1f;
									if (TLBtype != 0) {
										PrintLeaf(leafs, leaf);
										cout << "[SL " << hex << uppercase << setw(2) << right << setfill('0') << subleaf;
										cout << "] [";
										cout << dec << setw(5) << right << setfill(' ') << TLBentries << ' ';
										cout << dec << setw(3) << right << setfill(' ') << TLBassoc << "-way L";
										cout << TLBlevel << ' ';
										cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, TLBpage)][CPUID_TLB_PAGE] << ' ';
										cout <<  _cpuid_names[min(MAX_CPUIDSTR - 1, TLBtype)][CPUID_TLB_TYPE];
										cout << ']' << endl;
									}
								};
							} break;
							case 0x1A:	{//Native Model ID Enumeration Leaf
								PrintLeaf(leafs, leaf);
								if (cpu_props.IsFeat(FEAT_HYBRID)) {
									int hybrid = leaf[_REG_EAX];
									PrintHybridType(hybrid);
								}
								cout << endl;
							} break;
							case 0x1D:	{//Tile Information Main Leaf
								PrintSubLeaf(leafs, leaf, 0);
								const unsigned int maxPalette = leaf[_REG_EAX];
								for (unsigned int subleaf = 1, palette = 0; palette < maxPalette; subleaf++, palette++) {
									__cpuidex(leaf, leafs, subleaf);
									PrintLeaf(leafs, leaf);
									cout << "[SL " << hex << uppercase << setw(2) << right << setfill('0') << subleaf;
									cout << "] [";
									_AMX_palette pal;
									pal.total_tile_bytes	= leaf[_REG_EAX] & 0xffff;
									pal.bytes_per_tile		= leaf[_REG_EAX] >> 16;
									pal.bytes_per_row		= leaf[_REG_EBX] & 0xffff;
									pal.max_names			= leaf[_REG_EBX] >> 16;
									pal.max_rows			= leaf[_REG_ECX] & 0xffff;
									cout << "[AMX_palette " << setfill(' ') << dec << palette;
									cout << " total_tile_bytes:" << setw(5) << pal.total_tile_bytes;
									cout << " bytes_per_tile:" << setw(4) << pal.bytes_per_tile;
									cout << " bytes_per_row:" << setw(3) << pal.bytes_per_row;
									cout << " max_names:" << setw(3) << pal.max_names;
									cout << " max_rows:" << setw(3) << pal.max_rows;
									cout << ']' << endl;
								}
							} break;
							case 0x1E:	{//TMUL Information Main Leaf
								PrintLeaf(leafs, leaf);
								if (leaf[_REG_EBX] != 0) {
									_AMX_TMUL	AMX_TMUL;
									AMX_TMUL.tmul_maxk	= leaf[_REG_EBX] & 0xff;
									AMX_TMUL.tmul_maxn	= (leaf[_REG_EBX] >> 8) & 0xffff;
									cout << "[AMX_TMUL maxk: " << dec << (unsigned int)AMX_TMUL.tmul_maxk;
									cout << " maxn: " << (unsigned int)AMX_TMUL.tmul_maxn;
									cout << ']';
								}
								cout << endl;
							} break;
							case 0x80000002:
							case 0x80000003:
							case 0x80000004: { //Brand String
								PrintLeaf(leafs, leaf);
								cout << '[' << dec;
								cout << (char *)leaf;
								cout << ']' << endl;
							} break;
							case 0x80000005: { //L1 Cache and TLB Information
								PrintLeaf(leafs, leaf);
								//unsigned int L1DTLB2Massoc	= leaf[_REG_EAX] >> 24;
								//unsigned int L1DTLB2Msize	= (leaf[_REG_EAX] >> 16) & 0xff;
								//unsigned int L1ITLB2Massoc	= (leaf[_REG_EAX] >> 8) & 0xff;
								//unsigned int L1ITLB2Msize	= leaf[_REG_EAX] & 0xff;

								//unsigned int L1DTLB4Kassoc	= leaf[_REG_EBX] >> 24;
								//unsigned int L1DTLB4Ksize	= (leaf[_REG_EBX] >> 16) & 0xff;
								//unsigned int L1ITLB4Kassoc	= (leaf[_REG_EBX] >> 8) & 0xff;
								//unsigned int L1ITLB4Ksize	= leaf[_REG_EBX] & 0xff;

								unsigned int L1Dsize		= leaf[_REG_ECX] >> 24;
								//unsigned int L1Dassoc		= (leaf[_REG_ECX] >> 16) & 0xff;
								unsigned int L1Isize		= leaf[_REG_EDX] >> 24;
								//unsigned int L1Iassoc		= (leaf[_REG_EDX] >> 16) & 0xff;
								cout << '[' << dec;
								if (L1Dsize != 0)
									cout << "L1D " << L1Dsize << " KiB" /*<< L1Dassoc << "-way*/;
								if (L1Isize != 0)
									cout << "/L1I " << L1Isize << " KiB" /*<< L1Iassoc << "-way*/;
								cout << ']' << endl;
							} break;
							case 0x80000006: { //L2 Cache and TLB and L3 Cache Information
								PrintLeaf(leafs, leaf);
								//unsigned int L2DTLB2Massoc	= leaf[_REG_EAX] >> 24;
								//unsigned int L2DTLB2Msize	= (leaf[_REG_EAX] >> 16) & 0xff;
								//unsigned int L2ITLB2Massoc	= (leaf[_REG_EAX] >> 8) & 0xff;
								//unsigned int L2ITLB2Msize	= leaf[_REG_EAX] & 0xff;

								//unsigned int L2DTLB4Kassoc	= leaf[_REG_EBX] >> 24;
								//unsigned int L2DTLB4Ksize	= (leaf[_REG_EBX] >> 16) & 0xff;
								//unsigned int L2ITLB4Kassoc	= (leaf[_REG_EBX] >> 8) & 0xff;
								//unsigned int L2ITLB4Ksize	= leaf[_REG_EBX] & 0xff;

								unsigned int L2size		= leaf[_REG_ECX] >> 16;
								//unsigned int L2assoc	= (leaf[_REG_ECX] >> 12) & 0xf;
								unsigned int L3size		= leaf[_REG_EDX] >> 18;
								//unsigned int L3assoc	= (leaf[_REG_EDX] >> 12) & 0xf;
								cout << '[' << dec;
								if (L2size != 0)
									cout << "L2 " << dec << L2size << " KiB"/* << L2assoc << "-way /"*/;
								if (L3size != 0)
									cout << " / in-package L3 " << L3size * 512 << " KiB"/* << L3assoc << "-way]"*/;
								cout << ']' << endl;
							} break;
							case 0x80000026: { //Extended CPU Topology
								int subleaf = 0;
								__cpuidex(leaf, leafs, subleaf);
								//24594 Rev 3.34 p. 1878
								//while ((leaf[_REG_ECX] & 0xff00) != 0) {
								//56713 Rev 3.05 p. 118
								while ((leaf[_REG_EBX] & 0xffff) != 0) {
									PrintSubLeaf(leafs, leaf, subleaf);
									__cpuidex(leaf, leafs, ++subleaf);
								};
							} break;
						} //switch (leafs) 
					} //for (int leafs = 0; leafs <= lastLeaf; leafs++)
				} //if (lastLeaf != 0) 
			} //for (int startleaf = 0; startleaf < MAX_STARTLEAF; startleaf++) 
		} //for (unsigned int th = 0; th < apc; th++) 
	} //for (uint32_t gr = 0; gr < gCount; gr++)
	SetThreadGroupAffinity(GetCurrentThread(), &ga_orig, NULL);
	return;
}
