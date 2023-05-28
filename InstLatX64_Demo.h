#pragma once

enum demoType {
	DEMO_GFNI,
	DEMO_VPCLMLQDQ,
#if defined (_M_X64)
	#if defined (__AVX2__)
		DEMO_PEXT_PDEP_EMU,
		DEMO_FIRSTBBYTE,
	#endif
	#if defined(__AVX512F__)
		DEMO_RADD,
		DEMO_SADD,
		DEMO_KMEMDST,
		DEMO_ZEN4,
		DEMO_INTRINSICS,
		DEMO_VBMI2,
		DEMO_BYTE2BYTE,
		DEMO_TZCNT,
		DEMO_HWBITPERM,
		DEMO_KMOV,
		DEMO_AMX,
		DEMO_AVX512_DECPRINT,
	#endif
	#if defined(__AVX512F__)
		DEMO_LAST	= DEMO_AVX512_DECPRINT,
	#elif defined (__AVX2__)
		DEMO_LAST	= DEMO_FIRSTBBYTE,
	#else
		DEMO_LAST	= DEMO_VPCLMLQDQ,
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

void GFNI_Demo(void);
void VPCLMULQDQ_Demo(void);

void PEXT_PDEP_Emu_Test(void);
void FirstByte_Demo(void);
void AVX512_Reduce_Add_Demo(void);
void AVX512_Saturated_AddSub_Demo(void);
void AVX512_KMemDst_Demo(void);
void Zen4_Demo(void);
void AVX512_InstrincTest(void);
void VBMI2_Demo(void);
void Byte2ByteTest(void);
void TZCNT_Test(void);
void HWBITPERM_Test(void);
void Kmov_Test(void);
void AMX_Test(void);
void AVX512_DecimalPrint_Test(void);
