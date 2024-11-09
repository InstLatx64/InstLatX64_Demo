#pragma once

#define DEPEXT219_RANDOM		10000
#define DEPEXT219_RETRIES		10000
#define DEPEXT219_REPEATS		5000

enum BITPERM {
	BEXT,
	BDEP,
	BGRP
};

typedef unsigned __int64 (*BITPERM_PTR)(void);

typedef __m512i (__vectorcall *BITPERM_PTR2)(__m512i, __m512i);

typedef struct {
	const char 		name[32];
	const char 		isaName[16];
	int				bitness;
	BITPERM_PTR		lat;
	BITPERM_PTR		tp;
	BITPERM_PTR2	func;
	Feats			feats;
	BITPERM			type;
	int				ref;
} bitperm_methods;

#ifdef __cplusplus
extern "C" {
#endif

unsigned __int64 BEXT32_HW_Lat(void);
unsigned __int64 BEXT64_HW_Lat(void);
unsigned __int64 BEXT32_HW_Tp(void);
unsigned __int64 BEXT64_HW_Tp(void);
__m512i __vectorcall  BEXT32_HW(__m512i, __m512i);
__m512i __vectorcall  BEXT64_HW(__m512i, __m512i);

unsigned __int64 BDEP32_HW_Lat(void);
unsigned __int64 BDEP64_HW_Lat(void);
unsigned __int64 BDEP32_HW_Tp(void);
unsigned __int64 BDEP64_HW_Tp(void);
__m512i __vectorcall  BDEP32_HW(__m512i, __m512i);
__m512i __vectorcall  BDEP64_HW(__m512i, __m512i);

unsigned __int64 BGRP32_HW_Lat(void);
unsigned __int64 BGRP64_HW_Lat(void);
unsigned __int64 BGRP32_HW_Tp(void);
unsigned __int64 BGRP64_HW_Tp(void);
__m512i __vectorcall  BGRP32_HW(__m512i, __m512i);
__m512i __vectorcall  BGRP64_HW(__m512i, __m512i);

unsigned int _pgrp_u32(unsigned int p, unsigned int m);
unsigned __int64 _pgrp_u64(unsigned __int64 p, unsigned __int64 m);

#ifdef __cplusplus
}
#endif
