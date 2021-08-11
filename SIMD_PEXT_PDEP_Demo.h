#pragma once

#define DEPEXT219_RANDOM		10000
#define DEPEXT219_RETRIES		10000
#define DEPEXT219_REPEATS		1000

typedef unsigned __int64 (*PEXT_PDEP_PTR)(void);

typedef __m512i (__vectorcall *PEXT_PDEP_PTR2)(__m512i, __m512i);

typedef struct {
	const char 		name[32];
	const char 		isaName[16];
	int				bitness;
	PEXT_PDEP_PTR	timed;
	PEXT_PDEP_PTR2	func;
	ISAs			isa;
	bool			extFlag;
} simd_pext_pdep_methods;

#ifdef __cplusplus
extern "C" {
#endif

unsigned __int64 PEXT32_HW_Time(void);
unsigned __int64 PEXT64_HW_Time(void);
__m512i __vectorcall  PEXT32_HW(__m512i, __m512i);
__m512i __vectorcall  PEXT64_HW(__m512i, __m512i);

unsigned __int64 PDEP32_HW_Time(void);
unsigned __int64 PDEP64_HW_Time(void);
__m512i __vectorcall  PDEP32_HW(__m512i, __m512i);
__m512i __vectorcall  PDEP64_HW(__m512i, __m512i);

#ifdef __cplusplus
}
#endif

void SIMD_PEXT_PDEP_Test(void);

