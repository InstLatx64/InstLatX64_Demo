#pragma once

#define		CPUPROPS_VERS					0x0101

enum ISAs {
//	GPR									//Introduced by..
	ISA_GROUP_GPR,
	ISA_RDTSC,							//Pentium
	ISA_RDTSCP,							//AMD K8 E rev
	ISA_CMOV,							//Pentium Pro
	ISA_CMPX8,							//Pentium 
	ISA_CMPX16,							//AMD K8 E rev, Intel Prescott X64
	ISA_AMD64,							//K8 
	ISA_LAHF,							//Prescott x64
	ISA_MOVBE,							//Bonnell
	ISA_ABM,							//AMD K10, Haswell
	ISA_POPCNT,							//AMD K10, Nehalem
	ISA_RDRAND,							//Ivy Bridge
	ISA_RDSEED,							//Broadwell
	ISA_ADX,							//Broadwell
	ISA_BMI,							//Haswell, Piledriver
	ISA_BMI2,							//Haswell, Excavator
	ISA_MOVDIRI,						//Tremont
	ISA_MOVDIR64B,						//Tremont
	ISA_RAO_INT,						//Crestmont
	ISA_CMPCCXADD,						//Crestmont
	ISA_APX,							//?
//SIMD
	ISA_GROUP_SIMD,
	ISA_SSE,							//Pentium III
	ISA_SSE2,							//Willamette
	ISA_SSE3,							//Pentium 4 Prescott
	ISA_SSSE3,							//Conroe
	ISA_SSE41,							//Penryn
	ISA_SSE42,							//Nehalem
	ISA_SSE4A,							//AMD only, K10
	ISA_CLMUL,							//Westmere
	ISA_AES,							//Westmere
	ISA_SHA,							//Goldmont
	ISA_GFNI,							//Tremont
//VEX SIMD
	ISA_GROUP_VEX,
	ISA_AVX,							//Sandy Bridge
	ISA_AVX2,							//Haswell
	ISA_FMA,							//Haswell
	ISA_F16C,							//Ivy Bridge
	ISA_AVX_GFNI,						//IceLake-U/Y
	ISA_AVX_VAES,						//IceLake-U/Y
	ISA_AVX_VPCLMULQDQ,					//IceLake-U/Y
	ISA_AVX_VNNI,						//AlderLake
	ISA_AVX_VNNI_INT8,					//Crestmont
	ISA_AVX_VNNI_INT16,					//Arrow Lake
	ISA_AVX_IFMA,						//Crestmont
	ISA_AVX_NE_CONVERT,					//Crestmont
	ISA_SHA512,							//Arrow Lake
	ISA_SM3,							//Arrow Lake
	ISA_SM4,							//Arrow Lake
//EVEX SIMD
	ISA_GROUP_EVEX,
	ISA_AVX512F,						//Knights Landing
	ISA_AVX512CD,						//Knights Landing
	ISA_AVX512ER,						//Knights Landing
	ISA_AVX512PF,						//Knights Landing
	ISA_AVX512BW,						//Skylake-X
	ISA_AVX512DQ,						//Skylake-X
	ISA_AVX512VL,						//Skylake-X
	ISA_AVX512VBMI,						//Cannon Lake
	ISA_AVX512IFMA,						//Cannon Lake
	ISA_AVX512VNNI,						//Cascade Lake
	ISA_AVX512_4VNNIW,					//Knights Mill
	ISA_AVX512_4FMAPS,					//Knights Mill
	ISA_AVX512_VPOPCNTDQ,				//Knights Mill
	ISA_AVX512_GFNI,					//IceLake-U/Y
	ISA_AVX512_VAES,					//IceLake-U/Y
	ISA_AVX512_VPCLMULQDQ,				//IceLake-U/Y
	ISA_AVX512_BITALG,					//IceLake-U/Y
	ISA_AVX512_VBMI2,					//IceLake-U/Y
	ISA_AVX512_BF16,					//Cooper Lake
	ISA_AVX512_VP2INTERSECT,			//Tiger Lake
	ISA_AVX512_FP16,					//Sapphire Rapids
//AMX
	ISA_GROUP_AMX,
	ISA_AMX_BF16,						//Sapphire Rapids
	ISA_AMX_INT8,						//Sapphire Rapids
	ISA_AMX_TILE,						//Sapphire Rapids
	ISA_AMX_FP16,						//Granite Rapids
	ISA_AMX_COMPLEX,					//Granite Rapids
//AVX10
	ISA_GROUP_AVX10,
	ISA_AVX10,							//Granite Rapids
	ISA_AVX10_128,						//Granite Rapids
	ISA_AVX10_256,						//Granite Rapids
	ISA_AVX10_512,						//Granite Rapids X
	ISA_AVX10_LEVEL,					//Granite Rapids
//cacheline
	ISA_GROUP_CACHELINE,
	ISA_PREFETCHW,						//K6
	ISA_PREFETCHWT1,					//Knights Landing
	ISA_PREFETCHI,						//Crestmont
	ISA_CLFLUSH,						//Willamette
	ISA_CLFLUSHOPT,						//Skylake
	ISA_CLWB,							//Skylake-X
	ISA_CLZERO,							//Zen1, AMD Only
	ISA_CLDEMOTE,						//Tremont
//uCode
	ISA_GROUP_UCODE,
	ISA_ERMS_ENH_REP_MOVSB_STOSB,		//Haswell
	ISA_FSRM_FAST_SHORT_RRP_MOV,		//IceLake-U/Y
	ISA_FZLM_FAST_ZERO_LEN_MOVSB,		//Sapphire Rapids
	ISA_FSRS_FAST_SHORT_REP_STOSB,		//Sapphire Rapids
	ISA_FSCS_FAST_SHORT_CMPSB_SCASB,	//Sapphire Rapids
	ISA_FSRC_FAST_SHORT_REPE_CMPSB,		//Zen4
	ISA_FSRS_FAST_SHORT_REP_STOSB_AMD,	//Zen4
//KeyLocker
	ISA_GROUP_KEYLOCKER,
	ISA_KEYLOCK,						//Tiger Lake
	ISA_AESKLE,							//Tiger Lake
	ISA_WIDE_KL,						//Tiger Lake
//Uncategorized
	ISA_GROUP_UNCATEGORIZED,
	ISA_X86,							//8086
	ISA_LNOP,							//Pentium Pro, K7
	ISA_SERIALIZE,						//Sapphire Rapids
	ISA_HYBRID,							//Lakefield
	ISA_RDPID,							//Goldmont
	ISA_RDPRU,							//Zen2
	ISA_MCOMMIT,						//Zen2
	ISA_PCONFIG,						//IceLake-X
//Deprecated
	ISA_GROUP_DEPRECATED,
	ISA_X87,							//8087
	ISA_MMX,							//Pentium MMX
	ISA_MMXP,							//AMD only, AMD K7
	ISA_3DNOW,							//AMD only, AMD K6-2
	ISA_3DNOWP,							//AMD only, AMD K6-2+
	ISA_XOP,							//AMD only, K15 Bulldozer
	ISA_FMA4,							//AMD only, K15 Bulldozer
	ISA_TBM,							//AMD only, K15.1 Piledriver
	ISA_MPX,							//Skylake
	ISA_HLE,							//Haswell
	ISA_PCOMMIT,						//DOA
	ISA_LAST
};

enum x86_regs {
	_REG_EAX,
	_REG_EBX,
	_REG_ECX,
	_REG_EDX,
};

enum _CPUID_Feats : unsigned long long {
	CPUID_FEAT01_EAX,
	CPUID_FEAT01_ECX,
	CPUID_FEAT01_EDX,
	CPUID_FEAT07_EBX,
	CPUID_FEAT07_ECX,
	CPUID_FEAT07_EDX,
	CPUID_FEAT0701_EAX,
	CPUID_FEAT0701_EDX,
	CPUID_FEAT0702_EAX,
	CPUID_FEAT0702_EDX,
	CPUID_FEAT19_EBX,
	CPUID_FEAT1D_EAX,
	CPUID_FEAT1D01_EAX,
	CPUID_FEAT1D01_EBX,
	CPUID_FEAT1D01_ECX,
	CPUID_FEAT1E_EBX,
	CPUID_FEAT24_EBX,
	CPUID_EFEAT01_ECX,
	CPUID_EFEAT01_EDX,
	CPUID_EFEAT08_EAX,
	CPUID_EFEAT08_EBX,
	CPUID_EFEAT21_EAX,
	CPUID_NUMFIELD,
	CPUID_LAST = CPUID_NUMFIELD
};

enum _XCR0  : unsigned long long {
	_XCR0_EMPTY											=	0,
	_XCR0_X87											=	0x00001,
	_XCR0_AVX											=	0x00006,
	_XCR0_AVX512										=	0x000e6,
	_XCR0_AMX											=	0x60000,
	_XCR0_APX											=	0x80000,
	_KEYLOCK,
};

enum _VENDOR  : uint32_t {
	_VENDOR_EMPTY										= 0,
	_VENDOR_AMD											= 1,
	_VENDOR_CENTAUR										= 2,
	_VENDOR_CYRIX										= 3,
	_VENDOR_HYGON										= 4,
	_VENDOR_INTEL										= 5,
	_VENDOR_NATIONAL									= 6,
	_VENDOR_NEXGEN										= 7,
	_VENDOR_SIS											= 8,
	_VENDOR_RDC											= 9,
	_VENDOR_RISE										= 10,
	_VENDOR_TMTA										= 11,
	_VENDOR_UMC											= 12,
	_VENDOR_VORTEX										= 13,
	_VENDOR_ZHAOXIN										= 14,
	_VENDOR_LAST										= _VENDOR_ZHAOXIN + 6,
};

#define _FEAT_NOFEAT									~0ULL

#define CPUID_NOPLACE									(_FEAT_NOFEAT >> 32)

#define _FEAT_SKIP										0

#define _FEAT_PLACE(BIT, REG)							((1ULL << BIT) | (CPUID_##REG << 32))


#define _FEAT01_EDX_X87									_FEAT_PLACE( 0, FEAT01_EDX)
#define _FEAT01_EDX_RDTSC								_FEAT_PLACE( 4, FEAT01_EDX)
#define _FEAT01_EDX_CMPX8								_FEAT_PLACE( 8, FEAT01_EDX)
#define _FEAT01_EDX_CMOV								_FEAT_PLACE(15, FEAT01_EDX)
#define _FEAT01_EDX_CLFLUSH								_FEAT_PLACE(19, FEAT01_EDX)
#define	_FEAT01_EDX_MMX									_FEAT_PLACE(23, FEAT01_EDX)
#define _FEAT01_EDX_SSE									_FEAT_PLACE(25, FEAT01_EDX)
#define _FEAT01_EDX_SSE2								_FEAT_PLACE(26, FEAT01_EDX)
#define _FEAT01_EDX_HTT									_FEAT_PLACE(28, FEAT01_EDX)

#define _FEAT01_ECX_SSE3								_FEAT_PLACE( 0, FEAT01_ECX)
#define _FEAT01_ECX_CLMUL								_FEAT_PLACE( 1, FEAT01_ECX)
#define _FEAT01_ECX_SSSE3								_FEAT_PLACE( 9, FEAT01_ECX)
#define _FEAT01_ECX_FMA3								_FEAT_PLACE(12, FEAT01_ECX)
#define _FEAT01_ECX_CMPX16								_FEAT_PLACE(13, FEAT01_ECX)
#define _FEAT01_ECX_SSE41								_FEAT_PLACE(19, FEAT01_ECX)
#define _FEAT01_ECX_SSE42								_FEAT_PLACE(20, FEAT01_ECX)
#define _FEAT01_ECX_MOVBE								_FEAT_PLACE(22, FEAT01_ECX)
#define _FEAT01_ECX_POPCNT								_FEAT_PLACE(23, FEAT01_ECX)
#define _FEAT01_ECX_AESNI								_FEAT_PLACE(25, FEAT01_ECX)
#define _FEAT01_ECX_OSXSAVE								_FEAT_PLACE(27, FEAT01_ECX)
#define _FEAT01_ECX_AVX									_FEAT_PLACE(28, FEAT01_ECX)
#define _FEAT01_ECX_F16C								_FEAT_PLACE(29, FEAT01_ECX)
#define _FEAT01_ECX_RDRAND								_FEAT_PLACE(30, FEAT01_ECX)

#define _FEAT07_EBX_BMI									_FEAT_PLACE( 3, FEAT07_EBX)
#define _FEAT07_EBX_AVX2								_FEAT_PLACE( 5, FEAT07_EBX)
#define _FEAT07_EBX_HLE									_FEAT_PLACE( 4, FEAT07_EBX)
#define _FEAT07_EBX_BMI2								_FEAT_PLACE( 8, FEAT07_EBX)
#define _FEAT07_EBX_ERMS_ENH_REP_MOVSB_STOSB			_FEAT_PLACE( 9, FEAT07_EBX)
#define _FEAT07_EBX_MPX									_FEAT_PLACE(14, FEAT07_EBX)
#define _FEAT07_EBX_AVX512F								_FEAT_PLACE(16, FEAT07_EBX)
#define _FEAT07_EBX_AVX512DQ							_FEAT_PLACE(17, FEAT07_EBX)
#define _FEAT07_EBX_RDSEED								_FEAT_PLACE(18, FEAT07_EBX)
#define _FEAT07_EBX_ADX									_FEAT_PLACE(19, FEAT07_EBX)
#define _FEAT07_EBX_AVX512_IFMA							_FEAT_PLACE(21, FEAT07_EBX)
#define _FEAT07_EBX_PCOMMIT								_FEAT_PLACE(22, FEAT07_EBX)
#define _FEAT07_EBX_CLFLUSHOPT							_FEAT_PLACE(23, FEAT07_EBX)
#define _FEAT07_EBX_CLWB								_FEAT_PLACE(24, FEAT07_EBX)
#define _FEAT07_EBX_AVX512PF							_FEAT_PLACE(26, FEAT07_EBX)
#define _FEAT07_EBX_AVX512ER							_FEAT_PLACE(27, FEAT07_EBX)
#define _FEAT07_EBX_AVX512CD							_FEAT_PLACE(28, FEAT07_EBX)
#define _FEAT07_EBX_SHA									_FEAT_PLACE(29, FEAT07_EBX)
#define _FEAT07_EBX_AVX512BW							_FEAT_PLACE(30, FEAT07_EBX)
#define _FEAT07_EBX_AVX512VL							_FEAT_PLACE(31, FEAT07_EBX)

#define _FEAT07_ECX_PWT1								_FEAT_PLACE( 0, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VBMI							_FEAT_PLACE( 1, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VBMI2						_FEAT_PLACE( 6, FEAT07_ECX)
#define _FEAT07_ECX_GFNI								_FEAT_PLACE( 8, FEAT07_ECX)
#define _FEAT07_ECX_VAES								_FEAT_PLACE( 9, FEAT07_ECX)
#define _FEAT07_ECX_VPCLMULQDQ							_FEAT_PLACE(10, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VNNI							_FEAT_PLACE(11, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_BITALG						_FEAT_PLACE(12, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VPOPCNTDQ					_FEAT_PLACE(14, FEAT07_ECX)
#define _FEAT07_ECX_RDPID								_FEAT_PLACE(22, FEAT07_ECX)
#define _FEAT07_ECX_KEYLOCK								_FEAT_PLACE(23, FEAT07_ECX)
#define _FEAT07_ECX_CLDEMOTE							_FEAT_PLACE(25, FEAT07_ECX)
#define _FEAT07_ECX_MOVDIRI								_FEAT_PLACE(27, FEAT07_ECX)
#define _FEAT07_ECX_MOVDIR64B							_FEAT_PLACE(28, FEAT07_ECX)

#define _FEAT07_EDX_AVX512_4VNNIW						_FEAT_PLACE( 2, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_4FMAPS						_FEAT_PLACE( 3, FEAT07_EDX)
#define _FEAT07_EDX_FSRM_FAST_SHORT_RRP_MOV				_FEAT_PLACE( 4, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_VP2INTERSECT					_FEAT_PLACE( 8, FEAT07_EDX)
#define _FEAT07_EDX_SERIALIZE							_FEAT_PLACE(14, FEAT07_EDX)
#define _FEAT07_EDX_HYBRID								_FEAT_PLACE(15, FEAT07_EDX)
#define _FEAT07_EDX_PCONFIG								_FEAT_PLACE(18, FEAT07_EDX)
#define _FEAT07_EDX_AMX_BF16							_FEAT_PLACE(22, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_FP16							_FEAT_PLACE(23, FEAT07_EDX)
#define _FEAT07_EDX_AMX_INT8							_FEAT_PLACE(24, FEAT07_EDX)
#define _FEAT07_EDX_AMX_TILE							_FEAT_PLACE(25, FEAT07_EDX)

#define _FEAT0701_EAX_SHA512							_FEAT_PLACE( 0, FEAT0701_EAX)
#define _FEAT0701_EAX_SM3								_FEAT_PLACE( 1, FEAT0701_EAX)
#define _FEAT0701_EAX_SM4								_FEAT_PLACE( 2, FEAT0701_EAX)
#define _FEAT0701_EAX_RAO_INT							_FEAT_PLACE( 3, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX_VNNI							_FEAT_PLACE( 4, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX512_BF16						_FEAT_PLACE( 5, FEAT0701_EAX)
#define _FEAT0701_EAX_CMPCCXADD							_FEAT_PLACE( 7, FEAT0701_EAX)
#define _FEAT0701_EAX_FZLM_FAST_ZERO_LEN_MOVSB			_FEAT_PLACE(10, FEAT0701_EAX)
#define _FEAT0701_EAX_FSRS_FAST_SHORT_REP_STOSB			_FEAT_PLACE(11, FEAT0701_EAX)
#define _FEAT0701_EAX_FSRC_FAST_SHORT_REP_CMPSB_SCASB	_FEAT_PLACE(12, FEAT0701_EAX)
#define _FEAT0701_EAX_WRMSRNS							_FEAT_PLACE(19, FEAT0701_EAX)
#define _FEAT0701_EAX_AMX_FP16							_FEAT_PLACE(21, FEAT0701_EAX)
#define _FEAT0701_EAX_HRESET							_FEAT_PLACE(22, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX_IFMA							_FEAT_PLACE(23, FEAT0701_EAX)
#define _FEAT0701_EAX_MSRLIST							_FEAT_PLACE(27, FEAT0701_EAX)

#define _FEAT0701_EDX_AVX_VNNI_INT8						_FEAT_PLACE( 4, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX_NE_CONVERT					_FEAT_PLACE( 5, FEAT0701_EDX)
#define _FEAT0701_EDX_AMX_COMPLEX						_FEAT_PLACE( 8, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX_VNNI_INT16					_FEAT_PLACE(10, FEAT0701_EDX)
#define _FEAT0701_EDX_PREFETCHI							_FEAT_PLACE(14, FEAT0701_EDX)
#define _FEAT0701_EDX_APX_F								_FEAT_PLACE(21, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX10								_FEAT_PLACE(19, FEAT0701_EDX)

#define _FEAT19_EBX_AESKLE								_FEAT_PLACE(0, FEAT19_EBX)
#define _FEAT19_EBX_WIDE_KL								_FEAT_PLACE(2, FEAT19_EBX)

#define _FEAT24_EBX_AVX10_128							_FEAT_PLACE(16, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_256							_FEAT_PLACE(17, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_512							_FEAT_PLACE(18, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_LEVEL							                (CPUID_NUMFIELD << 32)

#define _EFEAT01_ECX_LAHF								_FEAT_PLACE( 0, EFEAT01_ECX)
#define _EFEAT01_ECX_ABM								_FEAT_PLACE( 5, EFEAT01_ECX)
#define _EFEAT01_ECX_SSE4A								_FEAT_PLACE( 6, EFEAT01_ECX)
#define _EFEAT01_ECX_3DNOWPREF							_FEAT_PLACE( 8, EFEAT01_ECX)
#define _EFEAT01_ECX_XOP								_FEAT_PLACE(11, EFEAT01_ECX)
#define _EFEAT01_ECX_FMA4								_FEAT_PLACE(16, EFEAT01_ECX)
#define _EFEAT01_ECX_TBM								_FEAT_PLACE(21, EFEAT01_ECX)

#define _EFEAT01_EDX_MMXP								_FEAT_PLACE(22, EFEAT01_EDX)
#define _EFEAT01_EDX_RDTSCP								_FEAT_PLACE(27, EFEAT01_EDX)
#define _EFEAT01_EDX_AMD64								_FEAT_PLACE(29, EFEAT01_EDX)
#define _EFEAT01_EDX_3DNOWP								_FEAT_PLACE(30, EFEAT01_EDX)
#define _EFEAT01_EDX_3DNOW								_FEAT_PLACE(31, EFEAT01_EDX)

#define _EFEAT008_EBX_CLZERO							_FEAT_PLACE( 0, EFEAT08_EBX)
#define _EFEAT008_EBX_RDPRU								_FEAT_PLACE( 4, EFEAT08_EBX)
#define _EFEAT008_EBX_MCOMMIT							_FEAT_PLACE( 8, EFEAT08_EBX)

#define _EFEAT21_EAX_FSRS_FAST_SHORT_REP_STOSB			_FEAT_PLACE( 10, EFEAT21_EAX)
#define _EFEAT21_EAX_FSRC_FAST_SHORT_REPE_CMPSB			_FEAT_PLACE( 11, EFEAT21_EAX)

#define FEATSIZE										2
#define FEAT_NAME_SIZE									31
#define VENDOR_STRING_SIZE								12
#define VENDOR_NUM_SIZE									4
#define BRAND_SIZE										(4 * 4 * 4)
#define MAX_AMX_PALETTE									1
#define	MAX_STARTLEAF									6
#define	MAX_CPUIDSTR									20


typedef struct {
	unsigned __int64	xcr0;
	int					cpuid_res[CPUID_LAST];
} _CPUID_RES;

typedef struct _EXT_Tag {
	const char 			name[FEAT_NAME_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	_XCR0				_xcr0;
	unsigned __int64	featbit;
} _EXT;

typedef struct _VENDOR_Tag {
	_VENDOR				v;
	uint32_t			vendor[3];
} _CPUID_VENDOR;

extern UINT64 ISA[2];

struct _AMX_palette {
	uint16_t	total_tile_bytes;
	uint16_t	bytes_per_tile;
	uint16_t	bytes_per_row;
	uint16_t	max_names;
	uint16_t	max_rows;
	_AMX_palette() : total_tile_bytes(0), bytes_per_tile(0), bytes_per_row(0), max_names(0), max_rows(0) {};
};

struct _AMX_TMUL {
	uint8_t		tmul_maxk;
	uint8_t		tmul_maxn;
	_AMX_TMUL() : tmul_maxk(0), tmul_maxn(0) {};
};

enum cpuidStr {
	CPUID_STATE,
	CPUID_TLB_TYPE,
	CPUID_TLB_PAGE,
	CPUID_CACHE_TYPE,
	CPUID_ATOM_NAME,
	CPUID_CORE_NAME,
	CPUID_STR_LAST = CPUID_CORE_NAME,
};

class CPU_Props {
private:
	static const _EXT			exts[ISA_LAST];
	static const _CPUID_VENDOR	vendors[_VENDOR_LAST];
	static const char*			_cpuid_names[][CPUID_STR_LAST + 1];
	_AMX_palette				AMX_palette[MAX_AMX_PALETTE];
	_AMX_TMUL					AMX_TMUL;
	UINT64						f[FEATSIZE]				= {0ULL, 0ULL};
	UINT64						f_disabled[FEATSIZE]	= {0ULL, 0ULL};
	DWORD_PTR					PCoreMask				= 0;
	DWORD_PTR					ECoreMask				= 0;
	DWORD_PTR					LPECoreMask				= 0;
	DWORD_PTR					systemAffMask			= 0;
	_VENDOR						vendor					= _VENDOR_EMPTY;
	UINT64						xcr0					= 0;
	int							avx10level				= 0;
	union {
		char					vendor_string[VENDOR_STRING_SIZE];
		unsigned long			vendor_num[VENDOR_NUM_SIZE]  = {0, 0, 0, 0};
	};
	union {
		char					brand_string[BRAND_SIZE];
		int						brand_num[4][4]  = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	};
	int							family;
	int							model;
	int							stepping;
	int							fms;
	void						PrintSupportStatus(bool, WORD col) const;
	void						PrintSupportStatus(int, WORD col) const;
	void						PrintOSStatus(bool, WORD col) const;
	void						PrintFeat(bool feat, bool enabled, bool disabled) const;
	void						PrintFeat(bool feat, bool enabled, bool disabled, int num) const;
	void						PrintLeaf(uint32_t leafs, int* leaf) const;
	void						PrintSingleLeaf(uint32_t leafs, int* leaf) const;
	void						PrintSubLeaf(uint32_t leafs, int* leaf, int subLeaf) const;
	void						PrintSubLeaf(uint32_t leafs, int* leaf, int subLeaf, cpuidStr str, int strInd) const;
	bool						HybridMasks(DWORD_PTR& pCoreMask, DWORD_PTR& eCoreMask, DWORD_PTR& LPECoreMask, DWORD_PTR& systemAffMask) const;
	void						SetFeats(_CPUID_RES& c);
	void						GetNativeCPUID(UINT64 arg_xcr0);
public:
	CPU_Props(UINT64 arg_xcr0);
	void						PrintFeats(void) const;
	void						PrintFeat(uint64_t) const;
	void						PrintVendor(void) const;
	void						PrintBrand(void) const;
	void						Print_512bFMA_DP_Ports(void) const;
	void						PrintHybridMasks(void) const;
	void						PrintCPUIDDump(void) const;
	void						PrintXCR0(void) const;
	void						ForcedAVX512(void) const;
	bool						IsFeat(int) const;
	bool						IsFeatBit(int) const;
	bool						IsZen2(void) const;
	bool						IsZen3(void) const;
	int							GetFamMod(void) const;
	int							GetFam(void) const;
	int							GetStepping(void) const;
	_VENDOR						GetVendor(void) const;
	bool						IsInBrand(const char* str) const;
	unsigned int				GetAMXPalette_TotalTileBytes(unsigned int p) const;
	unsigned int				GetAMXPalette_MaxName(unsigned int p) const;
	unsigned int				GetAMXRows() const;
	unsigned int				GetAMXCols() const;
	DWORD_PTR					GetPCoreMask() const;
	DWORD_PTR					GetECoreMask() const;
	DWORD_PTR					GetSystemAffMask() const;
	bool						GetFileCPUID(char * fname, UINT64 arg_xcr0);
#if defined (_M_X64)
	int							Get_512bFMA_DP_Ports(void) const;
#endif
};
