#pragma once

enum demoType {
	DEMO_GFNI,
	DEMO_VPCLMLQDQ,
#if defined (_M_X64)
#if defined (__AVX2__)
	DEMO_PEXT_PDEP_EMU,
#endif
#if defined(__AVX512F__)
	DEMO_INTRINSICS,
	DEMO_VBMI2,
	DEMO_BYTE2BYTE,
	DEMO_TZCNT,
	DEMO_PEXT_PDEP,
	DEMO_KMOV,
	DEMO_AMX,
	DEMO_AVX512_DECPRINT,
	DEMO_AVX512_DECSCAN,
	DEMO_AVX512_TRANSPOSE,
	DEMO_BEXT_BDEP,
#endif
	DEMO_CPUID_HISTO,
#if defined(__AVX512F__)
	DEMO_INREG_SORT,
	DEMO_FRACTAL,
	DEMO_LAST	= DEMO_FRACTAL,
#else
	DEMO_LAST	= DEMO_CPUID_HISTO,
#endif
#else
	DEMO_LAST	= DEMO_VPCLMLQDQ,
#endif
};

typedef struct {
	const char*			demoName;
	const char*			alias;
	uint64_t			demoMask;
	ISAs				isa;
	bool				publicFlag;
	void				(*func)(void);
	const char*			comment;
} demoTypeList;


