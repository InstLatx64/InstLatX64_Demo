#pragma once

#define  CPUPROPS_VERS			0x0100

enum ISAs {
//	GPR							//Introduced by..
	ISA_GROUP_GPR,
	ISA_RDTSC,					//Pentium
	ISA_RDTSCP,					//AMD K8 E rev
	ISA_CMOV,					//Pentium Pro
	ISA_CMPX8,					//Pentium 
	ISA_CMPX16,					//AMD K8 E rev, Intel Prescott X64
	ISA_AMD64,					//K8 
	ISA_LAHF,					//Prescott x64
	ISA_MOVBE,					//Bonnell
	ISA_ABM,					//AMD K10, Haswell
	ISA_POPCNT,					//AMD K10, Nehalem
	ISA_RDRAND,					//Ivy Bridge
	ISA_RDSEED,					//Broadwell
	ISA_ADX,					//Broadwell
	ISA_BMI,					//Haswell, Piledriver
	ISA_BMI2,					//Haswell, Excavator
	ISA_MOVDIRI,				//Tremont
	ISA_MOVDIR64B,				//Tremont
//SIMD
	ISA_GROUP_SIMD,
	ISA_SSE,					//Pentium III
	ISA_SSE2,					//Willamette
	ISA_SSE3,					//Pentium 4 Prescott
	ISA_SSSE3,					//Conroe
	ISA_SSE41,					//Penryn
	ISA_SSE42,					//Nehalem
	ISA_SSE4A,					//AMD only, K10
	ISA_CLMUL,					//Westmere
	ISA_AES,					//Westmere
	ISA_SHA,					//Goldmont
	ISA_AVX,					//Sandy Bridge
	ISA_AVX2,					//Haswell
	ISA_FMA,					//Haswell
	ISA_F16C,					//Ivy Bridge
	ISA_GFNI,					//Tremont
	ISA_VAES,					//IceLake-U/Y
	ISA_VPCLMULQDQ,				//IceLake-U/Y
	ISA_KEYLOCK,				//Tiger Lake
	ISA_AVX_VNNI,				//AlderLake
//AVX512
	ISA_GROUP_AVX512,
	ISA_AVX512F,				//Knights Landing
	ISA_AVX512CD,				//Knights Landing
	ISA_AVX512ER,				//Knights Landing
	ISA_AVX512PF,				//Knights Landing
	ISA_AVX512BW,				//Skylake-X
	ISA_AVX512DQ,				//Skylake-X
	ISA_AVX512VL,				//Skylake-X
	ISA_AVX512VBMI,				//Cannon Lake
	ISA_AVX512IFMA,				//Cannon Lake
	ISA_AVX512VNNI,				//Cascade Lake
	ISA_AVX512_4VNNIW,			//Knights Mill
	ISA_AVX512_4FMAPS,			//Knights Mill
	ISA_AVX512_VPOPCNTDQ,		//Knights Mill
	ISA_AVX512_BITALG,			//IceLake-U/Y
	ISA_AVX512_VBMI2,			//IceLake-U/Y
	ISA_AVX512_BF16,			//Cooper Lake
	ISA_AVX512_VP2INTERSECT,	//Tiger Lake
	ISA_AVX512_FP16,			//?
//AMX
	ISA_GROUP_AMX,
	ISA_AMX_BF16,				//Sapphire Rapids
	ISA_AMX_INT8,				//Sapphire Rapids
	ISA_AMX_TILE,				//Sapphire Rapids
//cacheline
	ISA_GROUP_CACHELINE,
	ISA_PREFETCHW,				//K6
	ISA_PREFETCHWT1,			//Knights Landing
	ISA_CLFLUSH,				//Willamette
	ISA_CLFLUSHOPT,				//Skylake
	ISA_CLWB,					//Skylake-X
	ISA_CLZERO,					//Zen1, AMD Only
	ISA_CLDEMOTE,				//Tremont
//Misc
	ISA_GROUP_MISC,
	ISA_LNOP,					//Pentium Pro, K7
	ISA_SERIALIZE,				//Sapphire Rapids
	ISA_HYBRID,					//Lakefield
//Deprecated
	ISA_GROUP_DEPRECATED,
	ISA_X87,					//8087
	ISA_MMX,					//Pentium MMX
	ISA_MMXP,					//AMD only, AMD K7
	ISA_3DNOW,					//AMD only, AMD K6-2
	ISA_3DNOWP,					//AMD only, AMD K6-2+
	ISA_XOP,					//AMD only, K15 Bulldozer
	ISA_FMA4,					//AMD only, K15 Bulldozer
	ISA_TBM,					//AMD only, K15.1 Piledriver
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
	CPUID_FEAT19_EBX,
	CPUID_EFEAT01_ECX,
	CPUID_EFEAT01_EDX,
	CPUID_EFEAT08_EBX,
};

enum _XCR0 {
	_XCR0_EMPTY									=	0,
	_XCR0_AVX									=	0x6,
	_XCR0_AVX512								=	0xe6,
	_XCR0_AMX									=	(0x3 << 17),
	_KEYLOCK,
};

#define _FEAT_NOFEAT							~0ULL

#define CPUID_NOPLACE							(_FEAT_NOFEAT >> 32)

#define _FEAT_SKIP								0

#define _FEAT01_EDX_X87							((1ULL <<  0) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_RDTSC						((1ULL <<  4) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_CMPX8						((1ULL <<  8) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_CMOV						((1ULL << 15) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_CLFLUSH						((1ULL << 19) | (CPUID_FEAT01_EDX << 32))
#define	_FEAT01_EDX_MMX							((1ULL << 23) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_SSE							((1ULL << 25) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_SSE2						((1ULL << 26) | (CPUID_FEAT01_EDX << 32))
#define _FEAT01_EDX_HTT							((1ULL << 28) | (CPUID_FEAT01_EDX << 32))

#define _FEAT01_ECX_SSE3						((1ULL <<  0) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_CLMUL						((1ULL <<  1) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_SSSE3						((1ULL <<  9) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_FMA3						((1ULL << 12) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_CMPX16						((1ULL << 13) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_SSE41						((1ULL << 19) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_SSE42						((1ULL << 20) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_MOVBE						((1ULL << 22) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_POPCNT						((1ULL << 23) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_AESNI						((1ULL << 25) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_OSXSAVE						(1ULL << 27)
#define _FEAT01_ECX_AVX							((1ULL << 28) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_F16C						((1ULL << 29) | (CPUID_FEAT01_ECX << 32))
#define _FEAT01_ECX_RDRAND						((1ULL << 30) | (CPUID_FEAT01_ECX << 32))

#define _FEAT07_EBX_BMI							((1ULL <<  3) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX2						((1ULL <<  5) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_BMI2						((1ULL <<  8) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512F						((1ULL << 16) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512DQ					((1ULL << 17) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_RDSEED						((1ULL << 18) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_ADX							((1ULL << 19) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512_IFMA					((1ULL << 21) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_CLFLUSHOPT					((1ULL << 23) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_CLWB						((1ULL << 24) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512PF					((1ULL << 26) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512ER					((1ULL << 27) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512CD					((1ULL << 28) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_SHA							((1ULL << 29) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512BW					((1ULL << 30) | (CPUID_FEAT07_EBX << 32))
#define _FEAT07_EBX_AVX512VL					((1ULL << 31) | (CPUID_FEAT07_EBX << 32))

#define _FEAT07_ECX_PWT1						((1ULL <<  0) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_AVX512_VBMI					((1ULL <<  1) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_AVX512_VBMI2				((1ULL <<  6) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_GFNI						((1ULL <<  8) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_VAES						((1ULL <<  9) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_VPCLMULQDQ					((1ULL << 10) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_AVX512_VNNI					((1ULL << 11) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_AVX512_BITALG				((1ULL << 12) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_AVX512_VPOPCNTDQ			((1ULL << 14) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_KEYLOCK						((1ULL << 23) | (CPUID_FEAT19_EBX << 32))
#define _FEAT07_ECX_CLDEMOTE					((1ULL << 25) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_MOVDIRI						((1ULL << 27) | (CPUID_FEAT07_ECX << 32))
#define _FEAT07_ECX_MOVDIR64B					((1ULL << 28) | (CPUID_FEAT07_ECX << 32))

#define _FEAT07_EDX_AVX512_4VNNIW				((1ULL <<  2) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_4FMAPS				((1ULL <<  3) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_VP2INTERSECT			((1ULL <<  8) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_4VNNIW				((1ULL <<  2) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_4FMAPS				((1ULL <<  3) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_VP2INTERSECT			((1ULL <<  8) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_SERIALIZE					((1ULL << 14) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_HYBRID						((1ULL << 15) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AMX_BF16					((1ULL << 22) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AVX512_FP16					((1ULL << 23) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AMX_INT8					((1ULL << 24) | (CPUID_FEAT07_EDX << 32))
#define _FEAT07_EDX_AMX_TILE					((1ULL << 25) | (CPUID_FEAT07_EDX << 32))

#define _FEAT19_EBX_AESKL						((1ULL << 0) | (CPUID_FEAT19_EBX << 32))

#define _FEAT0701_EAX_AVX_VNNI					((1ULL <<  4) | (CPUID_FEAT0701_EAX << 32))
#define _FEAT0701_EAX_AVX512_BF16				((1ULL <<  5) | (CPUID_FEAT0701_EAX << 32))

#define _EFEAT01_ECX_LAHF						((1ULL <<  0) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_ABM						((1ULL <<  5) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_SSE4A						((1ULL <<  6) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_3DNOWPREF					((1ULL <<  8) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_XOP						((1ULL << 11) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_FMA4						((1ULL << 16) | (CPUID_EFEAT01_ECX << 32))
#define _EFEAT01_ECX_TBM						((1ULL << 21) | (CPUID_EFEAT01_ECX << 32))

#define _EFEAT01_EDX_MMXP						((1ULL << 22) | (CPUID_EFEAT01_EDX << 32))
#define _EFEAT01_EDX_RDTSCP						((1ULL << 27) | (CPUID_EFEAT01_EDX << 32))
#define _EFEAT01_EDX_AMD64						((1ULL << 29) | (CPUID_EFEAT01_EDX << 32))
#define _EFEAT01_EDX_3DNOWP						((1ULL << 30) | (CPUID_EFEAT01_EDX << 32))
#define _EFEAT01_EDX_3DNOW						((1ULL << 31) | (CPUID_EFEAT01_EDX << 32))

#define _EFEAT008_EBX_CLZERO					((1ULL <<  0) | (CPUID_EFEAT08_EBX << 32))
#define _EFEAT008_EBX_RDPRU						((1ULL <<  4) | (CPUID_EFEAT08_EBX << 32))
#define _EFEAT008_EBX_MCOMMIT					((1ULL <<  8) | (CPUID_EFEAT08_EBX << 32))

#define FEATSIZE								2
#define CPUID_FIELDS							11
#define FEAT_NAME_SIZE							20
#define VENDOR_STRING_SIZE						12
#define VENDOR_NUM_SIZE							4
#define BRAND_SIZE								(4 * 4 * 4)

typedef struct {
	unsigned __int64	xcr0;
	int					cpuid_res[CPUID_FIELDS];
} _CPUID_RES;

typedef struct _EXT_Tag {
	const char 			name[FEAT_NAME_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	_XCR0				xcr0;
	unsigned __int64	featbit;
} _EXT;

extern UINT64 ISA[2];

class CPU_Props {
private:
	static const _EXT	exts[ISA_LAST];
	UINT64				f[FEATSIZE]				= {0ULL, 0ULL};
	UINT64				f_disabled[FEATSIZE]	= {0ULL, 0ULL};
	union {
		char			vendor_string[VENDOR_STRING_SIZE];
		unsigned long	vendor_num[VENDOR_NUM_SIZE]  = {0, 0, 0, 0};
	};
	union {
		char			brand_string[BRAND_SIZE];
		int				brand_num[4][4]  = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	};
	int					family;
	int					modell;
	int					stepping;
	int					hexID;
	int					fms;
	void				PrintSupportStatus(bool) const;
	void				PrintOSStatus(bool) const;
public:
	CPU_Props();
	void				PrintFeats(void) const;
	void				PrintVendor(void) const;
	void				PrintBrand(void) const;
	bool				IsFeat(int) const;
	bool				IsZen2(void) const;
	bool				IsZen3(void) const;
};
