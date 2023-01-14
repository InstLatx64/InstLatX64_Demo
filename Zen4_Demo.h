#pragma once

#define _ZEN4_DEMO_VERSION		0x0100

#define ZEN4_REPEATS			100
#define ZEN4_FUNCS				11

#define ZEN4_FUNCDECL0(NAME)	\
	{#NAME, {			\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr,}},

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned __int64(__fastcall* TEST_PTR)(void);

#ifdef __cplusplus
}
#endif

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[ZEN4_FUNCS];
} zen4_methods;
