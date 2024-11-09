#pragma once

#define B2B_FUNCS		1
#define B2B_REPEATS		1000000000.0

#define B2B_FUNCDEF(METHOD)	\
extern "C" unsigned __int64 __fastcall B2B_##METHOD##(void);

#define B2B_FUNCDECL(NAME, METHOD, ISA)	\
	{#NAME, {							\
	B2B_##METHOD##},					\
	ISA									\
	},

#define B2B_FUNCDECL0(NAME)	\
	{#NAME, {\
	nullptr}, FEAT_AVX512F},

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned __int64(__fastcall* B2B_PTR)(void);

#ifdef __cplusplus
}
#endif

typedef struct {
	const char 	name[64];
	B2B_PTR		funcs[B2B_FUNCS];
	Feats		feats;
} b2b_methods;

B2B_FUNCDEF(MASKEDVPERMI2B_LAT)
B2B_FUNCDEF(KREGROUNDTRIP_LAT)
B2B_FUNCDEF(GFNI_LAT)
B2B_FUNCDEF(SRLQ_LAT)
B2B_FUNCDEF(BLENDMB_LAT)
B2B_FUNCDEF(MINMAX_LAT)

B2B_FUNCDEF(MASKEDVPERMI2B_TP)
B2B_FUNCDEF(KREGROUNDTRIP_TP)
B2B_FUNCDEF(GFNI_TP)
B2B_FUNCDEF(SRLQ_TP)
B2B_FUNCDEF(BLENDMB_TP)
B2B_FUNCDEF(MINMAX_TP)
