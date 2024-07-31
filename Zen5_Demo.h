#pragma once

#define _ZEN5_DEMO_VERSION		0x0100

#define ZEN5_REPEATS			100
#define ZEN5_FUNCS				2
#define ZEN5_FUNCS_X87			2

#define ZEN5_FUNCDEF(INST, OPERANDS)	\
extern "C" unsigned __int64 __fastcall Zen5_##INST##_##OPERANDS##_lat(void);		\
extern "C" unsigned __int64 __fastcall Zen5_##INST##_##OPERANDS##_tp(void);	

#define ZEN5_FUNCDEF_X87(INST, OPERANDS)	\
extern "C" unsigned __int64 __fastcall Zen5_##INST##_##OPERANDS##_lat(void);


#define ZEN5_FUNCDECL(NAME, INST, OPERANDS)	\
	{#NAME, {\
	Zen5_##INST##_##OPERANDS##_lat,			\
	Zen5_##INST##_##OPERANDS##_tp			\
}},

#define ZEN5_FUNCDECL_X87(NAME, INST, OPERANDS)	\
	{#NAME, {\
	Zen5_##INST##_##OPERANDS##_lat,			\
	}},

#define ZEN5_FUNCDECL0(NAME)	\
	{#NAME, {			\
	nullptr, \
	nullptr, \
}},

#define ZEN5_X87_FUNCDECL0(NAME)	\
	{#NAME, {\
	nullptr, \
}},

ZEN5_FUNCDEF(empty,				empty)

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned __int64(__fastcall* TEST_PTR)(void);

#ifdef __cplusplus
}
#endif

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN5_FUNCS];
} zen5_methods;

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN5_FUNCS_X87];
} zen5_methods_x87;

