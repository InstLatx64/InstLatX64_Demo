#pragma once
#include "stdafx.h"

#define AVX512_STR_BUFF		32

typedef void (*U32_PRINT_PTR)(uint32_t, char *);
typedef void (*S32_PRINT_PTR)(int32_t, char *);
typedef void (*U64_PRINT_PTR)(uint64_t, char *);
typedef void (*S64_PRINT_PTR)(int64_t, char *);

template <typename T_FUNC>
struct AVX512_decimalprint_methods {
	const char 		name[32];
	const char 		isaName[16];
	T_FUNC			func;
	ISAs			isa;
	bool			refFlag;
};

AVX512_decimalprint_methods<U32_PRINT_PTR> decprints_u32[];
AVX512_decimalprint_methods<S32_PRINT_PTR> decprints_s32[];
AVX512_decimalprint_methods<U64_PRINT_PTR> decprints_u64[];
AVX512_decimalprint_methods<S64_PRINT_PTR> decprints_s64[];

extern "C" void _ultoa_avx512ifma_asm(uint32_t, char *);
extern "C" void _ultoa_avx512f_asm(uint32_t, char *);

extern "C" void _ltoa_avx512ifma_asm(int32_t, char *);
extern "C" void _ltoa_avx512f_asm(int32_t, char *);

extern "C" void _ui64toa_avx512ifma_asm(uint64_t, char*);
extern "C" void _ui64toa_avx512f_asm(uint64_t, char*);

extern "C" void _i64toa_avx512ifma_asm(int64_t, char*);
extern "C" void _i64toa_avx512f_asm(int64_t, char*);

extern "C" void to_string_avx512ifma_asm(uint64_t, char*);
extern "C" void to_string_avx512f_asm(uint64_t, char*);

extern inline uint64_t serialized_tsc(void);

