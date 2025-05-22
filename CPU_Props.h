#pragma once

#define		CPUPROPS_VERS					0x0103

#define		FEAT_MAX_COL					2

enum Feats {
//	Identification						//Introduced by..
	FEAT_GROUP_ID,						
	FEAT_VENDOR,						//486
	FEAT_FAMILY,						//486
	FEAT_MODEL,							//486
	FEAT_STEPPING,						//486
	FEAT_FMS,							//486
	FEAT_BRAND,							//AMD K5 Model 1, Intel Banias
//	GPR
	FEAT_GROUP_GPR,
	FEAT_LNOP,							//Pentium Pro, K7
	FEAT_CMOV,							//Pentium Pro
	FEAT_CMPX8,							//Pentium 
	FEAT_CMPX16,						//AMD K8 E rev, Intel Prescott X64
	FEAT_LAHF,							//Prescott x64
	FEAT_MOVBE,							//Bonnell
	FEAT_ABM,							//AMD K10, Haswell
	FEAT_POPCNT,						//AMD K10, Nehalem
	FEAT_RDRAND,						//Ivy Bridge
	FEAT_RDSEED,						//Broadwell
	FEAT_ADX,							//Broadwell
	FEAT_BMI,							//Haswell, Piledriver
	FEAT_BMI2,							//Haswell, Excavator
	FEAT_MOVDIRI,						//Tremont
	FEAT_MOVDIR64B,						//Tremont
	FEAT_RDPID,							//Goldmont
	FEAT_RDPRU,							//Zen2
	FEAT_RAO_INT,						//Crestmont
	FEAT_CMPCCXADD,						//Crestmont
	FEAT_APX,							//Diamond Rapids
//SIMD
	FEAT_GROUP_SIMD,
	FEAT_SSE,							//Pentium III
	FEAT_SSE2,							//Willamette
	FEAT_SSE3,							//Pentium 4 Prescott
	FEAT_SSSE3,							//Conroe
	FEAT_SSE41,							//Penryn
	FEAT_SSE42,							//Nehalem
	FEAT_SSE4A,							//AMD only, K10
	FEAT_CLMUL,							//Westmere
	FEAT_AES,							//Westmere
	FEAT_SHA,							//Goldmont
	FEAT_GFNI,							//Tremont
//VEX SIMD
	FEAT_GROUP_VEX,
	FEAT_AVX,							//Sandy Bridge
	FEAT_AVX2,							//Haswell
	FEAT_FMA,							//Haswell
	FEAT_F16C,							//Ivy Bridge
	FEAT_AVX_GFNI,						//IceLake-U/Y
	FEAT_AVX_VAES,						//IceLake-U/Y
	FEAT_AVX_VPCLMULQDQ,				//IceLake-U/Y
	FEAT_AVX_VNNI,						//AlderLake / Zen5
	FEAT_AVX_VNNI_INT8,					//Crestmont
	FEAT_AVX_VNNI_INT16,				//Arrow Lake
	FEAT_AVX_IFMA,						//Crestmont
	FEAT_AVX_NE_CONVERT,				//Crestmont
	FEAT_SHA512,						//Arrow Lake
	FEAT_SM3,							//Arrow Lake
	FEAT_SM4,							//Arrow Lake
//EVEX SIMD
	FEAT_GROUP_EVEX,
	FEAT_AVX512F,						//Knights Landing
	FEAT_AVX512CD,						//Knights Landing
	FEAT_AVX512ER,						//Knights Landing
	FEAT_AVX512PF,						//Knights Landing
	FEAT_AVX512BW,						//Skylake-X
	FEAT_AVX512DQ,						//Skylake-X
	FEAT_AVX512VL,						//Skylake-X
	FEAT_AVX512VBMI,					//Cannon Lake
	FEAT_AVX512IFMA,					//Cannon Lake
	FEAT_AVX512VNNI,					//Cascade Lake
	FEAT_AVX512_4VNNIW,					//Knights Mill
	FEAT_AVX512_4FMAPS,					//Knights Mill
	FEAT_AVX512_VPOPCNTDQ,				//Knights Mill
	FEAT_AVX512_GFNI,					//IceLake-U/Y
	FEAT_AVX512_VAES,					//IceLake-U/Y
	FEAT_AVX512_VPCLMULQDQ,				//IceLake-U/Y
	FEAT_AVX512_BITALG,					//IceLake-U/Y
	FEAT_AVX512_VBMI2,					//IceLake-U/Y
	FEAT_AVX512_BF16,					//Cooper Lake
	FEAT_AVX512_VP2INTERSECT,			//Tiger Lake
	FEAT_AVX512_FP16,					//Sapphire Rapids
//AVX10
	FEAT_GROUP_AVX10,
	FEAT_AVX10,							//Granite Rapids
	FEAT_AVX10_LEVEL,					//Granite Rapids
//AMX
	FEAT_GROUP_AMX,
	FEAT_AMX_TILE,						//Sapphire Rapids
	FEAT_AMX_INT8,						//Sapphire Rapids
	FEAT_AMX_BF16,						//Sapphire Rapids
	FEAT_AMX_COMPLEX,					//Granite Rapids
	FEAT_AMX_FP16,						//Granite Rapids
	FEAT_AMX_FP8,						//Diamond Rapids
	FEAT_AMX_TRANSPOSE,					//Diamond Rapids
	FEAT_AMX_TF32,						//Diamond Rapids
	FEAT_AMX_AVX512,					//Diamond Rapids
	FEAT_AMX_MOVRS,						//Diamond Rapids
//cacheline
	FEAT_GROUP_CACHELINE,
	FEAT_PREFETCHW,						//K6
	FEAT_PREFETCHWT1,					//Knights Landing
	FEAT_PREFETCHI,						//Crestmont, Zen5
	FEAT_CLFLUSH,						//Willamette
	FEAT_CLFLUSHOPT,					//Skylake
	FEAT_CLWB,							//Skylake-X
	FEAT_CLZERO,						//Zen1, AMD Only
	FEAT_CLDEMOTE,						//Tremont
//uCode
	FEAT_GROUP_UCODE,
	FEAT_ERMS_ENH_REP_MOVSB_STOSB,		//Haswell, Zen5
	FEAT_FSRM_FAST_SHORT_RRP_MOV,		//IceLake-U/Y
	FEAT_FZLM_FAST_ZERO_LEN_MOVSB,		//Sapphire Rapids
	FEAT_FSRS_FAST_SHORT_REP_STOSB,		//Sapphire Rapids, Zen4
	FEAT_FSCS_FAST_SHORT_CMPSB_SCASB,	//Sapphire Rapids
	FEAT_FSRC_FAST_SHORT_REPE_CMPSB,	//Zen4
	FEAT_FSRS_FAST_SHORT_REP_SCASB_AMD,	//Zen5
//	TSC
	FEAT_GROUP_TSC,
	FEAT_RDTSC,							//Pentium
	FEAT_RDTSCP,						//AMD K8 E rev
//KeyLocker
	FEAT_GROUP_KEYLOCKER,
	FEAT_KEYLOCK,						//Tiger Lake
	FEAT_AESKLE,						//Tiger Lake
	FEAT_WIDE_KL,						//Tiger Lake
//Uncategorized
	FEAT_GROUP_UNCATEGORIZED,
	FEAT_X86,							//8086
	FEAT_AMD64,							//K8 
	FEAT_SERIALIZE,						//Sapphire Rapids
	FEAT_HYBRID,						//Lakefield
	FEAT_MCOMMIT,						//Zen2
	FEAT_PCONFIG,						//IceLake-X
//Deprecated
	FEAT_GROUP_DEPRECATED,
	FEAT_X87,							//8087
	FEAT_MMX,							//Pentium MMX
	FEAT_MMXP,							//AMD only, AMD K7
	FEAT_3DNOW,							//AMD only, AMD K6-2
	FEAT_3DNOWP,						//AMD only, AMD K6-2+
	FEAT_XOP,							//AMD only, K15 Bulldozer
	FEAT_FMA4,							//AMD only, K15 Bulldozer
	FEAT_TBM,							//AMD only, K15.1 Piledriver
	FEAT_MPX,							//Skylake
	FEAT_HLE,							//Haswell
	FEAT_PCOMMIT,						//DOA
	FEAT_MAX_ROW = FEAT_AVX10_LEVEL + 1
};

enum x86_regs {
	_REG_EAX,
	_REG_EBX,
	_REG_ECX,
	_REG_EDX,
};

enum _CPUID_Feats : unsigned long long {
	CPUID_FEAT00_EAX,
	CPUID_FEAT01_EAX,
	CPUID_FEAT01_ECX,
	CPUID_FEAT01_EDX,
	CPUID_FEAT07_EBX,
	CPUID_FEAT07_ECX,
	CPUID_FEAT07_EDX,
	CPUID_FEAT0701_EAX,
	CPUID_FEAT0701_EBX,
	CPUID_FEAT0701_ECX,
	CPUID_FEAT0701_EDX,
	CPUID_FEAT0702_EAX,
	CPUID_FEAT0702_EDX,
	CPUID_FEAT15_EAX,
	CPUID_FEAT15_EBX,
	CPUID_FEAT15_ECX,
	CPUID_FEAT16_EAX,
	CPUID_FEAT16_EBX,
	CPUID_FEAT16_ECX,
	CPUID_FEAT19_EBX,
	CPUID_FEAT1D_EAX,
	CPUID_FEAT1D01_EAX,
	CPUID_FEAT1D01_EBX,
	CPUID_FEAT1D01_ECX,
	CPUID_FEAT1E_EBX,
	CPUID_FEAT1E01_EAX,
	CPUID_FEAT24_EBX,
	CPUID_EFEAT00_EAX,
	CPUID_EFEAT01_ECX,
	CPUID_EFEAT01_EDX,
	CPUID_EFEAT07_EDX,
	CPUID_EFEAT08_EAX,
	CPUID_EFEAT08_EBX,
	CPUID_EFEAT1E_EBX,
	CPUID_EFEAT21_EAX,
	CPUID_VENDOR,
	CPUID_BRAND,
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
#define CPUID_MAXPLACE									2

#define _FEAT_SKIP										0

#define _FEAT_PLACE(BIT, REG)							((1ULL << BIT) | (CPUID_##REG << 32))

#define _FEAT_GROUP										CPUID_NOPLACE

#define _FEAT00_VENDOR									                (CPUID_VENDOR << 32)
#define _FEAT01_FAMILY									                (CPUID_NUMFIELD << 32)
#define _FEAT01_MODEL									                (CPUID_NUMFIELD << 32)
#define _FEAT01_STEPPING								                (CPUID_NUMFIELD << 32)
#define _FEAT01_FMS										                (CPUID_NUMFIELD << 32)

#define _FEAT01_EDX_X87									_FEAT_PLACE( 0, FEAT01_EDX)
#define _FEAT01_EDX_VME									_FEAT_PLACE( 1, FEAT01_EDX)
#define _FEAT01_EDX_DE									_FEAT_PLACE( 2, FEAT01_EDX)
#define _FEAT01_EDX_PSE									_FEAT_PLACE( 3, FEAT01_EDX)
#define _FEAT01_EDX_RDTSC								_FEAT_PLACE( 4, FEAT01_EDX)
#define _FEAT01_EDX_MSR									_FEAT_PLACE( 5, FEAT01_EDX)
#define _FEAT01_EDX_PAE									_FEAT_PLACE( 6, FEAT01_EDX)
#define _FEAT01_EDX_MCE									_FEAT_PLACE( 7, FEAT01_EDX)
#define _FEAT01_EDX_CMPX8								_FEAT_PLACE( 8, FEAT01_EDX)
#define _FEAT01_EDX_APIC								_FEAT_PLACE( 9, FEAT01_EDX)
#define _FEAT01_EDX_RESERVED_B10						_FEAT_PLACE(10, FEAT01_EDX)
#define _FEAT01_EDX_SEP									_FEAT_PLACE(11, FEAT01_EDX)
#define _FEAT01_EDX_MTRR								_FEAT_PLACE(12, FEAT01_EDX)
#define _FEAT01_EDX_PGE									_FEAT_PLACE(13, FEAT01_EDX)
#define _FEAT01_EDX_MCA									_FEAT_PLACE(14, FEAT01_EDX)
#define _FEAT01_EDX_CMOV								_FEAT_PLACE(15, FEAT01_EDX)
#define _FEAT01_EDX_PAT									_FEAT_PLACE(16, FEAT01_EDX)
#define _FEAT01_EDX_PSE36								_FEAT_PLACE(17, FEAT01_EDX)
#define _FEAT01_EDX_PSN									_FEAT_PLACE(18, FEAT01_EDX)
#define _FEAT01_EDX_CLFLUSH								_FEAT_PLACE(19, FEAT01_EDX)
#define _FEAT01_EDX_RESERVED_B20						_FEAT_PLACE(20, FEAT01_EDX)
#define _FEAT01_EDX_DS									_FEAT_PLACE(21, FEAT01_EDX)
#define _FEAT01_EDX_ACPI								_FEAT_PLACE(22, FEAT01_EDX)
#define	_FEAT01_EDX_MMX									_FEAT_PLACE(23, FEAT01_EDX)
#define	_FEAT01_EDX_FXSR								_FEAT_PLACE(24, FEAT01_EDX)
#define _FEAT01_EDX_SSE									_FEAT_PLACE(25, FEAT01_EDX)
#define _FEAT01_EDX_SSE2								_FEAT_PLACE(26, FEAT01_EDX)
#define _FEAT01_EDX_SS									_FEAT_PLACE(27, FEAT01_EDX)
#define _FEAT01_EDX_HTT									_FEAT_PLACE(28, FEAT01_EDX)
#define _FEAT01_EDX_TM1									_FEAT_PLACE(29, FEAT01_EDX)
#define _FEAT01_EDX_IA64								_FEAT_PLACE(30, FEAT01_EDX)
#define _FEAT01_EDX_PBE									_FEAT_PLACE(31, FEAT01_EDX)

#define _FEAT01_ECX_SSE3								_FEAT_PLACE( 0, FEAT01_ECX)
#define _FEAT01_ECX_CLMUL								_FEAT_PLACE( 1, FEAT01_ECX)
#define _FEAT01_ECX_DTES64								_FEAT_PLACE( 2, FEAT01_ECX)
#define _FEAT01_ECX_MONITOR								_FEAT_PLACE( 3, FEAT01_ECX)
#define _FEAT01_ECX_DS_CPL								_FEAT_PLACE( 4, FEAT01_ECX)
#define _FEAT01_ECX_VMX									_FEAT_PLACE( 5, FEAT01_ECX)
#define _FEAT01_ECX_SMX									_FEAT_PLACE( 6, FEAT01_ECX)
#define _FEAT01_ECX_EIST								_FEAT_PLACE( 7, FEAT01_ECX)
#define _FEAT01_ECX_TM2									_FEAT_PLACE( 8, FEAT01_ECX)
#define _FEAT01_ECX_SSSE3								_FEAT_PLACE( 9, FEAT01_ECX)
#define _FEAT01_ECX_CNXT_ID								_FEAT_PLACE(10, FEAT01_ECX)
#define _FEAT01_ECX_SDBG								_FEAT_PLACE(11, FEAT01_ECX)
#define _FEAT01_ECX_FMA3								_FEAT_PLACE(12, FEAT01_ECX)
#define _FEAT01_ECX_CMPX16								_FEAT_PLACE(13, FEAT01_ECX)
#define _FEAT01_ECX_ETPRD								_FEAT_PLACE(14, FEAT01_ECX)
#define _FEAT01_ECX_PDCM								_FEAT_PLACE(15, FEAT01_ECX)
#define _FEAT01_ECX_RESERVED_B16						_FEAT_PLACE(16, FEAT01_ECX)
#define _FEAT01_ECX_PCID								_FEAT_PLACE(17, FEAT01_ECX)
#define _FEAT01_ECX_DCA									_FEAT_PLACE(18, FEAT01_ECX)
#define _FEAT01_ECX_SSE41								_FEAT_PLACE(19, FEAT01_ECX)
#define _FEAT01_ECX_SSE42								_FEAT_PLACE(20, FEAT01_ECX)
#define _FEAT01_ECX_X2APIC								_FEAT_PLACE(21, FEAT01_ECX)
#define _FEAT01_ECX_MOVBE								_FEAT_PLACE(22, FEAT01_ECX)
#define _FEAT01_ECX_POPCNT								_FEAT_PLACE(23, FEAT01_ECX)
#define _FEAT01_ECX_TSCDEADLINE							_FEAT_PLACE(24, FEAT01_ECX)
#define _FEAT01_ECX_AESNI								_FEAT_PLACE(25, FEAT01_ECX)
#define _FEAT01_ECX_XSAVE								_FEAT_PLACE(26, FEAT01_ECX)
#define _FEAT01_ECX_OSXSAVE								_FEAT_PLACE(27, FEAT01_ECX)
#define _FEAT01_ECX_AVX									_FEAT_PLACE(28, FEAT01_ECX)
#define _FEAT01_ECX_F16C								_FEAT_PLACE(29, FEAT01_ECX)
#define _FEAT01_ECX_RDRAND								_FEAT_PLACE(30, FEAT01_ECX)
#define _FEAT01_ECX_HV									_FEAT_PLACE(31, FEAT01_ECX)

#define _FEAT07_EBX_FSGSBASE							_FEAT_PLACE( 0, FEAT07_EBX)
#define _FEAT07_EBX_TSCADJUST_MSR						_FEAT_PLACE( 1, FEAT07_EBX)
#define _FEAT07_EBX_SGX									_FEAT_PLACE( 2, FEAT07_EBX)
#define _FEAT07_EBX_BMI									_FEAT_PLACE( 3, FEAT07_EBX)
#define _FEAT07_EBX_HLE									_FEAT_PLACE( 4, FEAT07_EBX)
#define _FEAT07_EBX_AVX2								_FEAT_PLACE( 5, FEAT07_EBX)
#define _FEAT07_EBX_FDP_EXCPTN_ONLY						_FEAT_PLACE( 6, FEAT07_EBX)
#define _FEAT07_EBX_SMEP								_FEAT_PLACE( 7, FEAT07_EBX)
#define _FEAT07_EBX_BMI2								_FEAT_PLACE( 8, FEAT07_EBX)
#define _FEAT07_EBX_ERMS_ENH_REP_MOVSB_STOSB			_FEAT_PLACE( 9, FEAT07_EBX)
#define _FEAT07_EBX_INVPCID								_FEAT_PLACE(10, FEAT07_EBX)
#define _FEAT07_EBX_RTM									_FEAT_PLACE(11, FEAT07_EBX)
#define _FEAT07_EBX_RDT_M								_FEAT_PLACE(12, FEAT07_EBX)
#define _FEAT07_EBX_FPU_DS_DEPRECATED					_FEAT_PLACE(13, FEAT07_EBX)
#define _FEAT07_EBX_MPX									_FEAT_PLACE(14, FEAT07_EBX)
#define _FEAT07_EBX_RDT_A								_FEAT_PLACE(15, FEAT07_EBX)
#define _FEAT07_EBX_AVX512F								_FEAT_PLACE(16, FEAT07_EBX)
#define _FEAT07_EBX_AVX512DQ							_FEAT_PLACE(17, FEAT07_EBX)
#define _FEAT07_EBX_RDSEED								_FEAT_PLACE(18, FEAT07_EBX)
#define _FEAT07_EBX_ADX									_FEAT_PLACE(19, FEAT07_EBX)
#define _FEAT07_EBX_SMAP								_FEAT_PLACE(20, FEAT07_EBX)
#define _FEAT07_EBX_AVX512_IFMA							_FEAT_PLACE(21, FEAT07_EBX)
#define _FEAT07_EBX_PCOMMIT								_FEAT_PLACE(22, FEAT07_EBX)
#define _FEAT07_EBX_CLFLUSHOPT							_FEAT_PLACE(23, FEAT07_EBX)
#define _FEAT07_EBX_CLWB								_FEAT_PLACE(24, FEAT07_EBX)
#define _FEAT07_EBX_PT									_FEAT_PLACE(25, FEAT07_EBX)
#define _FEAT07_EBX_AVX512PF							_FEAT_PLACE(26, FEAT07_EBX)
#define _FEAT07_EBX_AVX512ER							_FEAT_PLACE(27, FEAT07_EBX)
#define _FEAT07_EBX_AVX512CD							_FEAT_PLACE(28, FEAT07_EBX)
#define _FEAT07_EBX_SHA									_FEAT_PLACE(29, FEAT07_EBX)
#define _FEAT07_EBX_AVX512BW							_FEAT_PLACE(30, FEAT07_EBX)
#define _FEAT07_EBX_AVX512VL							_FEAT_PLACE(31, FEAT07_EBX)

#define _FEAT07_ECX_PWT1								_FEAT_PLACE( 0, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VBMI							_FEAT_PLACE( 1, FEAT07_ECX)
#define _FEAT07_ECX_UMIP								_FEAT_PLACE( 2, FEAT07_ECX)
#define _FEAT07_ECX_PKU									_FEAT_PLACE( 3, FEAT07_ECX)
#define _FEAT07_ECX_OSPKE								_FEAT_PLACE( 4, FEAT07_ECX)
#define _FEAT07_ECX_WAITPKG								_FEAT_PLACE( 5, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VBMI2						_FEAT_PLACE( 6, FEAT07_ECX)
#define _FEAT07_ECX_CET_SS								_FEAT_PLACE( 7, FEAT07_ECX)
#define _FEAT07_ECX_GFNI								_FEAT_PLACE( 8, FEAT07_ECX)
#define _FEAT07_ECX_VAES								_FEAT_PLACE( 9, FEAT07_ECX)
#define _FEAT07_ECX_VPCLMULQDQ							_FEAT_PLACE(10, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VNNI							_FEAT_PLACE(11, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_BITALG						_FEAT_PLACE(12, FEAT07_ECX)
#define _FEAT07_ECX_TME_EN								_FEAT_PLACE(13, FEAT07_ECX)
#define _FEAT07_ECX_AVX512_VPOPCNTDQ					_FEAT_PLACE(14, FEAT07_ECX)
#define _FEAT07_ECX_RESERVED_B15						_FEAT_PLACE(15, FEAT07_ECX)
#define _FEAT07_ECX_LA57								_FEAT_PLACE(16, FEAT07_ECX)
#define _FEAT07_ECX_MAWAU_B17_21					                (CPUID_NUMFIELD << 32)
#define _FEAT07_ECX_RDPID								_FEAT_PLACE(22, FEAT07_ECX)
#define _FEAT07_ECX_KEYLOCK								_FEAT_PLACE(23, FEAT07_ECX)
#define _FEAT07_ECX_BUS_LOCK							_FEAT_PLACE(24, FEAT07_ECX)
#define _FEAT07_ECX_CLDEMOTE							_FEAT_PLACE(25, FEAT07_ECX)
#define _FEAT07_ECX_RESERVED_B26						_FEAT_PLACE(26, FEAT07_ECX)
#define _FEAT07_ECX_MOVDIRI								_FEAT_PLACE(27, FEAT07_ECX)
#define _FEAT07_ECX_MOVDIR64B							_FEAT_PLACE(28, FEAT07_ECX)
#define _FEAT07_ECX_ENQCMD								_FEAT_PLACE(29, FEAT07_ECX)
#define _FEAT07_ECX_SGX_LC								_FEAT_PLACE(30, FEAT07_ECX)
#define _FEAT07_ECX_PKS									_FEAT_PLACE(31, FEAT07_ECX)

#define _FEAT07_EDX_RESERVED_B00						_FEAT_PLACE( 0, FEAT07_EDX)
#define	_FEAT07_EDX_SGX_KEYS							_FEAT_PLACE( 1, FEAT07_EDX)	
#define _FEAT07_EDX_AVX512_4VNNIW						_FEAT_PLACE( 2, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_4FMAPS						_FEAT_PLACE( 3, FEAT07_EDX)
#define _FEAT07_EDX_FSRM_FAST_SHORT_RRP_MOV				_FEAT_PLACE( 4, FEAT07_EDX)
#define _FEAT07_EDX_UINTR								_FEAT_PLACE( 5, FEAT07_EDX)
#define _FEAT07_EDX_RESERVED_B06						_FEAT_PLACE( 6, FEAT07_EDX)
#define _FEAT07_EDX_RESERVED_B07						_FEAT_PLACE( 7, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_VP2INTERSECT					_FEAT_PLACE( 8, FEAT07_EDX)
#define _FEAT07_EDX_SRBDS_CTRL							_FEAT_PLACE( 9, FEAT07_EDX)
#define _FEAT07_EDX_MD_CLEAR							_FEAT_PLACE(10, FEAT07_EDX)
#define _FEAT07_EDX_RTM_ALWAYS_ABORT					_FEAT_PLACE(11, FEAT07_EDX)
#define _FEAT07_EDX_RESERVED_B12						_FEAT_PLACE(12, FEAT07_EDX)
#define _FEAT07_EDX_RTM_FORCE_ABORT						_FEAT_PLACE(13, FEAT07_EDX)
#define _FEAT07_EDX_SERIALIZE							_FEAT_PLACE(14, FEAT07_EDX)
#define _FEAT07_EDX_HYBRID								_FEAT_PLACE(15, FEAT07_EDX)
#define _FEAT07_EDX_TSXLDTRK							_FEAT_PLACE(16, FEAT07_EDX)
#define _FEAT07_EDX_RESERVED_B17						_FEAT_PLACE(17, FEAT07_EDX)
#define _FEAT07_EDX_PCONFIG								_FEAT_PLACE(18, FEAT07_EDX)
#define _FEAT07_EDX_ARCH_LBRS							_FEAT_PLACE(19, FEAT07_EDX)
#define _FEAT07_EDX_CET_IBT								_FEAT_PLACE(20, FEAT07_EDX)
#define _FEAT07_EDX_RESERVED_B21						_FEAT_PLACE(21, FEAT07_EDX)
#define _FEAT07_EDX_AMX_BF16							_FEAT_PLACE(22, FEAT07_EDX)
#define _FEAT07_EDX_AVX512_FP16							_FEAT_PLACE(23, FEAT07_EDX)
#define _FEAT07_EDX_AMX_INT8							_FEAT_PLACE(24, FEAT07_EDX)
#define _FEAT07_EDX_AMX_TILE							_FEAT_PLACE(25, FEAT07_EDX)
#define _FEAT07_EDX_IBPB								_FEAT_PLACE(26, FEAT07_EDX)
#define _FEAT07_EDX_STIBP								_FEAT_PLACE(27, FEAT07_EDX)
#define _FEAT07_EDX_L1D_FLUSH							_FEAT_PLACE(28, FEAT07_EDX)
#define _FEAT07_EDX_IA32_ARCH_CAPABILITIES				_FEAT_PLACE(29, FEAT07_EDX)
#define _FEAT07_EDX_IA32_CORE_CAPABILITIES				_FEAT_PLACE(30, FEAT07_EDX)
#define _FEAT07_EDX_SSBD								_FEAT_PLACE(31, FEAT07_EDX)

#define _FEAT0701_EAX_SHA512							_FEAT_PLACE( 0, FEAT0701_EAX)
#define _FEAT0701_EAX_SM3								_FEAT_PLACE( 1, FEAT0701_EAX)
#define _FEAT0701_EAX_SM4								_FEAT_PLACE( 2, FEAT0701_EAX)
#define _FEAT0701_EAX_RAO_INT							_FEAT_PLACE( 3, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX_VNNI							_FEAT_PLACE( 4, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX512_BF16						_FEAT_PLACE( 5, FEAT0701_EAX)
#define _FEAT0701_EAX_LASS								_FEAT_PLACE( 6, FEAT0701_EAX)
#define _FEAT0701_EAX_CMPCCXADD							_FEAT_PLACE( 7, FEAT0701_EAX)
#define _FEAT0701_EAX_ARCHPERFMON						_FEAT_PLACE( 8, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B09						_FEAT_PLACE( 9, FEAT0701_EAX)
#define _FEAT0701_EAX_FZLM_FAST_ZERO_LEN_MOVSB			_FEAT_PLACE(10, FEAT0701_EAX)
#define _FEAT0701_EAX_FSRS_FAST_SHORT_REP_STOSB			_FEAT_PLACE(11, FEAT0701_EAX)
#define _FEAT0701_EAX_FSRC_FAST_SHORT_REP_CMPSB_SCASB	_FEAT_PLACE(12, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B13						_FEAT_PLACE(13, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B14						_FEAT_PLACE(14, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B15						_FEAT_PLACE(15, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B16						_FEAT_PLACE(16, FEAT0701_EAX)
#define _FEAT0701_EAX_FRED								_FEAT_PLACE(17, FEAT0701_EAX)
#define _FEAT0701_EAX_LKGS								_FEAT_PLACE(18, FEAT0701_EAX)
#define _FEAT0701_EAX_WRMSRNS							_FEAT_PLACE(19, FEAT0701_EAX)
#define _FEAT0701_EAX_NMI_SRC							_FEAT_PLACE(20, FEAT0701_EAX)
#define _FEAT0701_EAX_AMX_FP16							_FEAT_PLACE(21, FEAT0701_EAX)
#define _FEAT0701_EAX_HRESET							_FEAT_PLACE(22, FEAT0701_EAX)
#define _FEAT0701_EAX_AVX_IFMA							_FEAT_PLACE(23, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B24						_FEAT_PLACE(24, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B25						_FEAT_PLACE(25, FEAT0701_EAX)
#define _FEAT0701_EAX_LAM								_FEAT_PLACE(26, FEAT0701_EAX)
#define _FEAT0701_EAX_MSRLIST							_FEAT_PLACE(27, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B28						_FEAT_PLACE(28, FEAT0701_EAX)
#define _FEAT0701_EAX_RESERVED_B29						_FEAT_PLACE(29, FEAT0701_EAX)
#define _FEAT0701_EAX_INVD_DISABLE_POST_BIOS_DONE		_FEAT_PLACE(30, FEAT0701_EAX)
#define _FEAT0701_EAX_MOVRS								_FEAT_PLACE(31, FEAT0701_EAX)

#define _FEAT0701_EBX_PPIN_MSR							_FEAT_PLACE( 0, FEAT0701_EBX)
#define _FEAT0701_EBX_PBNDKB							_FEAT_PLACE( 1, FEAT0701_EBX)
#define _FEAT0701_EBX_RESERVED_B02						_FEAT_PLACE( 2, FEAT0701_EBX)
#define _FEAT0701_EBX_CPUIDMAXVAL_LIM_RMV				_FEAT_PLACE( 3, FEAT0701_EBX)

#define _FEAT0701_ECX_ASYM_RDT_M						_FEAT_PLACE( 0, FEAT0701_ECX)
#define _FEAT0701_ECX_ASYM_RDT_A						_FEAT_PLACE( 1, FEAT0701_ECX)
#define _FEAT0701_ECX_MSR_IMM							_FEAT_PLACE( 5, FEAT0701_ECX)

#define _FEAT0701_EDX_RESERVED_B00						_FEAT_PLACE( 0, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B01						_FEAT_PLACE( 1, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B02						_FEAT_PLACE( 2, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B03						_FEAT_PLACE( 3, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX_VNNI_INT8						_FEAT_PLACE( 4, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX_NE_CONVERT					_FEAT_PLACE( 5, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B06						_FEAT_PLACE( 6, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B07						_FEAT_PLACE( 7, FEAT0701_EDX)
#define _FEAT0701_EDX_AMX_COMPLEX						_FEAT_PLACE( 8, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B09						_FEAT_PLACE( 9, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX_VNNI_INT16					_FEAT_PLACE(10, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B11						_FEAT_PLACE(11, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B12						_FEAT_PLACE(12, FEAT0701_EDX)
#define _FEAT0701_EDX_UTMR								_FEAT_PLACE(13, FEAT0701_EDX)
#define _FEAT0701_EDX_PREFETCHI							_FEAT_PLACE(14, FEAT0701_EDX)
#define _FEAT0701_EDX_USER_MSR							_FEAT_PLACE(15, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B16						_FEAT_PLACE(16, FEAT0701_EDX)
#define _FEAT0701_EDX_UIRET_UIF							_FEAT_PLACE(17, FEAT0701_EDX)
#define _FEAT0701_EDX_CET_SSS							_FEAT_PLACE(18, FEAT0701_EDX)
#define _FEAT0701_EDX_AVX10								_FEAT_PLACE(19, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B20						_FEAT_PLACE(20, FEAT0701_EDX)
#define _FEAT0701_EDX_APX_F								_FEAT_PLACE(21, FEAT0701_EDX)
#define _FEAT0701_EDX_RESERVED_B22						_FEAT_PLACE(22, FEAT0701_EDX)
#define _FEAT0701_EDX_MWAIT								_FEAT_PLACE(23, FEAT0701_EDX)

#define _FEAT0702_EDX_PSFD								_FEAT_PLACE( 0, FEAT0702_EDX)
#define _FEAT0702_EDX_IPRED_CTRL						_FEAT_PLACE( 1, FEAT0702_EDX)
#define _FEAT0702_EDX_RRSBA_CTRL						_FEAT_PLACE( 2, FEAT0702_EDX)
#define _FEAT0702_EDX_DDPD_U							_FEAT_PLACE( 3, FEAT0702_EDX)
#define _FEAT0702_EDX_BHI_CTRL							_FEAT_PLACE( 4, FEAT0702_EDX)
#define _FEAT0702_EDX_MCDT_NO							_FEAT_PLACE( 5, FEAT0702_EDX)
#define _FEAT0702_EDX_UC_LOCK_DISABLE					_FEAT_PLACE( 6, FEAT0702_EDX)
#define _FEAT0702_EDX_MONITOR_MITG_NO					_FEAT_PLACE( 7, FEAT0702_EDX)

#define _FEAT15_EAX_TSC_DENOMINATOR						                (CPUID_NUMFIELD << 32)
#define _FEAT15_EBX_TSC_NUMERATOR						                (CPUID_NUMFIELD << 32)
#define _FEAT15_ECX_CORE_CRYSTAL						                (CPUID_NUMFIELD << 32)

#define _FEAT16_EAX_BASE_FREQ							                (CPUID_NUMFIELD << 32)
#define _FEAT16_EBX_MAX_FREQ							                (CPUID_NUMFIELD << 32)
#define _FEAT16_ECX_BUS_FREQ							                (CPUID_NUMFIELD << 32)

#define _FEAT19_EBX_AESKLE								_FEAT_PLACE( 0, FEAT19_EBX)
#define _FEAT19_EBX_WIDE_KL								_FEAT_PLACE( 2, FEAT19_EBX)

#define _FEAT1E01_EAX_AMX_INT8							_FEAT_PLACE( 0, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_BF16							_FEAT_PLACE( 1, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_COMPLEX						_FEAT_PLACE( 2, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_FP16							_FEAT_PLACE( 3, FEAT1E01_EAX)

#define _FEAT1E01_EAX_AMX_FP8							_FEAT_PLACE( 4, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_TRANPOSE						_FEAT_PLACE( 5, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_TF32							_FEAT_PLACE( 6, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_AVX512						_FEAT_PLACE( 7, FEAT1E01_EAX)
#define _FEAT1E01_EAX_AMX_MOVRS							_FEAT_PLACE( 8, FEAT1E01_EAX)

#define _FEAT24_EBX_AVX10_128							_FEAT_PLACE(16, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_256							_FEAT_PLACE(17, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_512							_FEAT_PLACE(18, FEAT24_EBX)
#define _FEAT24_EBX_AVX10_LEVEL							                (CPUID_NUMFIELD << 32)

#define _EFEAT00_VENDOR									                (CPUID_VENDOR << 32)
#define _EFEAT01_FAMILY									                (CPUID_NUMFIELD << 32)
#define _EFEAT01_MODEL									                (CPUID_NUMFIELD << 32)
#define _EFEAT01_STEPPING								                (CPUID_NUMFIELD << 32)

#define _EFEAT01_ECX_LAHF								_FEAT_PLACE( 0, EFEAT01_ECX)
#define _EFEAT01_ECX_CMPLEGACY							_FEAT_PLACE( 1, EFEAT01_ECX)
#define _EFEAT01_ECX_SVM								_FEAT_PLACE( 2, EFEAT01_ECX)
#define _EFEAT01_ECX_EXTAPIC							_FEAT_PLACE( 3, EFEAT01_ECX)
#define _EFEAT01_ECX_ALTMOVCR8							_FEAT_PLACE( 4, EFEAT01_ECX)
#define _EFEAT01_ECX_ABM								_FEAT_PLACE( 5, EFEAT01_ECX)
#define _EFEAT01_ECX_SSE4A								_FEAT_PLACE( 6, EFEAT01_ECX)
#define _EFEAT01_ECX_MISALIGNSSE						_FEAT_PLACE( 7, EFEAT01_ECX)
#define _EFEAT01_ECX_3DNOWPREF							_FEAT_PLACE( 8, EFEAT01_ECX)
#define _EFEAT01_ECX_OSVW								_FEAT_PLACE( 9, EFEAT01_ECX)
#define _EFEAT01_ECX_IBS								_FEAT_PLACE(10, EFEAT01_ECX)
#define _EFEAT01_ECX_XOP								_FEAT_PLACE(11, EFEAT01_ECX)
#define _EFEAT01_ECX_SKINIT								_FEAT_PLACE(12, EFEAT01_ECX)
#define _EFEAT01_ECX_WDT								_FEAT_PLACE(13, EFEAT01_ECX)
#define _EFEAT01_ECX_RESERVED_B14						_FEAT_PLACE(14, EFEAT01_ECX)
#define _EFEAT01_ECX_LWP								_FEAT_PLACE(15, EFEAT01_ECX)
#define _EFEAT01_ECX_FMA4								_FEAT_PLACE(16, EFEAT01_ECX)
#define _EFEAT01_ECX_TCE								_FEAT_PLACE(17, EFEAT01_ECX)
#define _EFEAT01_ECX_RESERVED_B18						_FEAT_PLACE(18, EFEAT01_ECX)
#define _EFEAT01_ECX_NODEID								_FEAT_PLACE(19, EFEAT01_ECX)
#define _EFEAT01_ECX_RESERVED_B20						_FEAT_PLACE(20, EFEAT01_ECX)
#define _EFEAT01_ECX_TBM								_FEAT_PLACE(21, EFEAT01_ECX)
#define _EFEAT01_ECX_TOPX								_FEAT_PLACE(22, EFEAT01_ECX)
#define _EFEAT01_ECX_PCX_CORE							_FEAT_PLACE(23, EFEAT01_ECX)
#define _EFEAT01_ECX_PCX_NB								_FEAT_PLACE(24, EFEAT01_ECX)
#define _EFEAT01_ECX_RESERVED_B25						_FEAT_PLACE(25, EFEAT01_ECX)
#define _EFEAT01_ECX_DBX								_FEAT_PLACE(26, EFEAT01_ECX)
#define _EFEAT01_ECX_PERFTSC							_FEAT_PLACE(27, EFEAT01_ECX)
#define _EFEAT01_ECX_PCX_L2I_L3							_FEAT_PLACE(28, EFEAT01_ECX)
#define _EFEAT01_ECX_MONITORX							_FEAT_PLACE(29, EFEAT01_ECX)
#define _EFEAT01_ECX_ADMSKEXTN							_FEAT_PLACE(30, EFEAT01_ECX)
#define _EFEAT01_ECX_RESERVED_B31						_FEAT_PLACE(31, EFEAT01_ECX)

#define _EFEAT01_EDX_X87								_FEAT_PLACE( 0, EFEAT01_EDX)
#define _EFEAT01_EDX_VME								_FEAT_PLACE( 1, EFEAT01_EDX)
#define _EFEAT01_EDX_DE									_FEAT_PLACE( 2, EFEAT01_EDX)
#define _EFEAT01_EDX_PSE								_FEAT_PLACE( 3, EFEAT01_EDX)
#define _EFEAT01_EDX_RDTSC								_FEAT_PLACE( 4, EFEAT01_EDX)
#define _EFEAT01_EDX_MSR								_FEAT_PLACE( 5, EFEAT01_EDX)
#define _EFEAT01_EDX_PAE								_FEAT_PLACE( 6, EFEAT01_EDX)
#define _EFEAT01_EDX_MCE								_FEAT_PLACE( 7, EFEAT01_EDX)
#define _EFEAT01_EDX_CMPX8								_FEAT_PLACE( 8, EFEAT01_EDX)
#define _EFEAT01_EDX_APIC								_FEAT_PLACE( 9, EFEAT01_EDX)
#define _EFEAT01_EDX_RESERVED_B10						_FEAT_PLACE(10, EFEAT01_EDX)
#define _EFEAT01_EDX_SYSCALL							_FEAT_PLACE(11, EFEAT01_EDX)
#define _EFEAT01_EDX_MTRR								_FEAT_PLACE(12, EFEAT01_EDX)
#define _EFEAT01_EDX_PGE								_FEAT_PLACE(13, EFEAT01_EDX)
#define _EFEAT01_EDX_MCA								_FEAT_PLACE(14, EFEAT01_EDX)
#define _EFEAT01_EDX_CMOV								_FEAT_PLACE(15, EFEAT01_EDX)
#define _EFEAT01_EDX_PAT								_FEAT_PLACE(16, EFEAT01_EDX)
#define _EFEAT01_EDX_PSE36								_FEAT_PLACE(17, EFEAT01_EDX)
#define _EFEAT01_EDX_RESERVED_B18						_FEAT_PLACE(18, EFEAT01_EDX)
#define _EFEAT01_EDX_CLFLUSH							_FEAT_PLACE(19, EFEAT01_EDX)
#define _EFEAT01_EDX_NX									_FEAT_PLACE(20, EFEAT01_EDX)
#define _EFEAT01_EDX_RESERVED_B21						_FEAT_PLACE(21, EFEAT01_EDX)
#define _EFEAT01_EDX_MMXP								_FEAT_PLACE(22, EFEAT01_EDX)
#define	_EFEAT01_EDX_MMX								_FEAT_PLACE(23, EFEAT01_EDX)
#define	_EFEAT01_EDX_FXSR								_FEAT_PLACE(24, EFEAT01_EDX)
#define _EFEAT01_EDX_FFXSR								_FEAT_PLACE(25, EFEAT01_EDX)
#define _EFEAT01_EDX_1GB_PAGE							_FEAT_PLACE(26, EFEAT01_EDX)
#define _EFEAT01_EDX_RDTSCP								_FEAT_PLACE(27, EFEAT01_EDX)
#define _EFEAT01_EDX_RESERVED_B28						_FEAT_PLACE(28, EFEAT01_EDX)
#define _EFEAT01_EDX_AMD64								_FEAT_PLACE(29, EFEAT01_EDX)
#define _EFEAT01_EDX_3DNOWP								_FEAT_PLACE(30, EFEAT01_EDX)
#define _EFEAT01_EDX_3DNOW								_FEAT_PLACE(31, EFEAT01_EDX)

#define _EFEAT02_BRAND									                (CPUID_BRAND << 32)

#define _EFEAT07_EDX_TSCINV								_FEAT_PLACE( 8, EFEAT07_EDX)

#define _EFEAT08_EAX_PHYS_ADDR_BITS						                (CPUID_NUMFIELD << 32)
#define _EFEAT08_EAX_LINEAR_ADDR_BITS					                (CPUID_NUMFIELD << 32)
#define _EFEAT08_EAX_GUEST_ADDR_BITS					                (CPUID_NUMFIELD << 32)

#define _EFEAT08_EBX_CLZERO								_FEAT_PLACE( 0, EFEAT08_EBX)
#define _EFEAT08_EBX_RDPRU								_FEAT_PLACE( 4, EFEAT08_EBX)
#define _EFEAT08_EBX_MCOMMIT							_FEAT_PLACE( 8, EFEAT08_EBX)

#define _EFEAT1A_FPUSIZE								_FEAT_PLACE( 1, EFEAT1A_EAX)

#define _EFEAT21_EAX_FSRS_FAST_SHORT_REP_STOSB			_FEAT_PLACE(10, EFEAT21_EAX)
#define _EFEAT21_EAX_FSRC_FAST_SHORT_REPE_CMPSB			_FEAT_PLACE(11, EFEAT21_EAX)
#define _EFEAT21_EAX_AMD_ERMSB							_FEAT_PLACE(15, EFEAT21_EAX)
#define _EFEAT21_EAX_FSRS_FAST_SHORT_REP_SCASB			_FEAT_PLACE(19, EFEAT21_EAX)
#define _EFEAT21_EAX_PREFETCHI							_FEAT_PLACE(20, EFEAT21_EAX)

#define FEATBITARRAYSIZE								6
#define FEAT_NAME_SIZE									31
#define VENDOR_STRING_SIZE								12
#define VENDOR_NUM_SIZE									4
#define BRAND_SIZE										(4 * 4 * 4)
#define MAX_AMX_PALETTE									1
#define	MAX_STARTLEAF									6
#define	MAX_CPUIDSTR									20
#define	DEFAULT_COREINFO								(MAX_CPUIDSTR - 1)


typedef struct {
	unsigned __int64	xcr0;
	int					cpuid_res[CPUID_LAST];
} _CPUID_RES;

typedef struct _EXT_Tag {
	const char 			name[FEAT_NAME_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	_XCR0				_xcr0;
	Feats				_feats;
	unsigned __int64	cpuidPlace[CPUID_MAXPLACE];
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
	static const _EXT			exts[FEAT_MAX_COL][FEAT_MAX_ROW];
	static const _CPUID_VENDOR	vendors[_VENDOR_LAST];
	static const char*			_cpuid_names[][CPUID_STR_LAST + 1];
	_AMX_palette				AMX_palette[MAX_AMX_PALETTE];
	_AMX_TMUL					AMX_TMUL;
	UINT64						f[FEATBITARRAYSIZE]				= {0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL};
	UINT64						f_disabled[FEATBITARRAYSIZE]	= {0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL};
	DWORD_PTR					pCoreMask						= 0;
	DWORD_PTR					eCoreMask						= 0;
	DWORD_PTR					lpeCoreMask						= 0;
	DWORD_PTR					systemAffMask					= 0;
	_VENDOR						vendor							= _VENDOR_EMPTY;
	UINT64						xcr0							= 0;
	int							avx10level						= 0;
	DWORD						pCoreInfo						= DEFAULT_COREINFO;
	DWORD						eCoreInfo						= DEFAULT_COREINFO;
	DWORD						lpeCoreInfo						= DEFAULT_COREINFO;
	DWORD						pCoreIndex						= 0;
	DWORD						eCoreIndex						= 0;
	DWORD						lpeCoreIndex					= 0;
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
	bool						HybridMasks(DWORD_PTR& pCoreMask, DWORD_PTR& eCoreMask, DWORD_PTR& lpeCoreMask, DWORD_PTR& systemAffMask);
	void						SetFeats(_CPUID_RES& c);
	void						GetNativeCPUID(UINT64 arg_xcr0);
	bool						_2levelL1D() const;
public:
	CPU_Props(UINT64 arg_xcr0);
	void						PrintFeats(void) const;
	void						PrintFeat(uint64_t) const;
	void						PrintFeat(int value) const;
	void						PrintFeat(int value, WORD col, bool dir) const;
	void						PrintFeatUnit(int value, WORD col, const char * unit) const;
	void						PrintFeatHex(int value, WORD col) const;
	void						PrintFeatDecHex(int value, WORD col) const;
	void						PrintVendor(void) const;
	void						PrintBrand(void) const;
#if defined (_M_X64) && defined(__AVX512F__)
	void						Print_512bFMA_DP_Ports(void) const;
#endif
	void						PrintHybridMasks(void) const;
	void						PrintHybridType(int) const;
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
	DWORD_PTR					GetLPECoreMask() const;
	DWORD_PTR					GetPCoreIndex() const;
	DWORD_PTR					GetECoreIndex() const;
	DWORD_PTR					GetLPECoreIndex() const;
	DWORD_PTR					GetSystemAffMask() const;
	bool						GetFileCPUID(char * fname, UINT64 arg_xcr0);
#if defined (_M_X64) && defined(__AVX512F__)
	int							Get_512bFMA_DP_Ports(void) const;
#endif
};
