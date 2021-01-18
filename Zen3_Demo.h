#pragma once

#define _ZEN3_DEMO_VERSION		0x0100

#define ZEN3_REPEATS			100
#define ZEN3_FUNCS				16
#define ZEN3_FUNCS_X87			12
#define ZEN3_FUNCS_UCODE		11

#define ZEN3_FUNCDEF(INST, OPERANDS)	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_lat(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_IIDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_FFDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_IFDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_FIDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_gpr(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port0(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port1(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port01(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port03(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port2(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port12(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port23(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port0123(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port45(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_LDs(void);

#define ZEN3_FUNCDEF_X87(INST, OPERANDS)	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_lat(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_gpr(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port0(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port1(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port01(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port03(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port2(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port12(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port23(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port0123(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_port45(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_##OPERANDS##_LDs(void);

#define ZEN3_FUNCDEF_UCODE(INST)	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_lat(void);			\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_IIDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_FFDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_IFDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_FIDomain(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port0_1_23(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port01_23(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port03_12(void);	\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port0(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port1(void);		\
extern "C" unsigned __int64 __fastcall Zen3_##INST##_Port01(void);

#define ZEN3_FUNCDECL(NAME, INST, OPERANDS)	\
	{#NAME, {\
	Zen3_##INST##_##OPERANDS##_lat, \
	Zen3_##INST##_##OPERANDS##_IIDomain,\
	Zen3_##INST##_##OPERANDS##_FFDomain,\
	Zen3_##INST##_##OPERANDS##_IFDomain, \
	Zen3_##INST##_##OPERANDS##_FIDomain, \
	Zen3_##INST##_##OPERANDS##_gpr, \
	Zen3_##INST##_##OPERANDS##_port0, \
	Zen3_##INST##_##OPERANDS##_port1, \
	Zen3_##INST##_##OPERANDS##_port01, \
	Zen3_##INST##_##OPERANDS##_port03, \
	Zen3_##INST##_##OPERANDS##_port2, \
	Zen3_##INST##_##OPERANDS##_port12, \
	Zen3_##INST##_##OPERANDS##_port23, \
	Zen3_##INST##_##OPERANDS##_port0123, \
	Zen3_##INST##_##OPERANDS##_port45, \
	Zen3_##INST##_##OPERANDS##_LDs, }},

#define ZEN3_FUNCDECL_X87(NAME, INST, OPERANDS)	\
	{#NAME, {\
	Zen3_##INST##_##OPERANDS##_lat, \
	Zen3_##INST##_##OPERANDS##_gpr, \
	Zen3_##INST##_##OPERANDS##_port0, \
	Zen3_##INST##_##OPERANDS##_port1, \
	Zen3_##INST##_##OPERANDS##_port01, \
	Zen3_##INST##_##OPERANDS##_port03, \
	Zen3_##INST##_##OPERANDS##_port2, \
	Zen3_##INST##_##OPERANDS##_port12, \
	Zen3_##INST##_##OPERANDS##_port23, \
	Zen3_##INST##_##OPERANDS##_port0123, \
	Zen3_##INST##_##OPERANDS##_port45, \
	Zen3_##INST##_##OPERANDS##_LDs, }},

#define ZEN3_FUNCDECL_UCODE(NAME, INST)	\
	{#NAME, {\
	Zen3_##INST##_lat, \
	Zen3_##INST##_IIDomain, \
	Zen3_##INST##_FFDomain, \
	Zen3_##INST##_IFDomain, \
	Zen3_##INST##_FIDomain, \
	Zen3_##INST##_Port0_1_23, \
	Zen3_##INST##_Port01_23, \
	Zen3_##INST##_Port03_12, \
	Zen3_##INST##_Port0, \
	Zen3_##INST##_Port1, \
	Zen3_##INST##_Port01 \
	}},

#define ZEN3_FUNCDECL0(NAME)	\
	{#NAME, {\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr}},

#define ZEN3_X87_FUNCDECL0(NAME)	\
	{#NAME, {\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr}},

#define ZEN3_FUNCDECL_UCODE0(NAME)	\
	{#NAME, {\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr}},

ZEN3_FUNCDEF(empty,				empty)

typedef unsigned __int64(__fastcall* TEST_PTR)(void);

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN3_FUNCS];
} zen3_methods;

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN3_FUNCS_X87];
} zen3_methods_x87;

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN3_FUNCS_UCODE];
} zen3_methods_ucode;

void Zen3_Demo(void);