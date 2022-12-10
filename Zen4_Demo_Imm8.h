#pragma once

#define ZEN4_FUNCDEF_I8(INST, OPERANDS, I8)	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_lat(void);		\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_tp(void);		\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port01(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port23(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port12(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port123(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port0123(void);\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port45(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_tern(void);	\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_LDs(void);		\
extern "C" unsigned __int64 __fastcall Zen4_##INST##_##OPERANDS##_##I8##_port1(void);

#define ZEN4_FUNCDECL_I8(NAME, INST, OPERANDS, I8)	\
	{#NAME, {\
	Zen4_##INST##_##OPERANDS##_##I8##_lat,			\
	Zen4_##INST##_##OPERANDS##_##I8##_tp,			\
	Zen4_##INST##_##OPERANDS##_##I8##_port01,		\
	Zen4_##INST##_##OPERANDS##_##I8##_port23,		\
	Zen4_##INST##_##OPERANDS##_##I8##_port12,		\
	Zen4_##INST##_##OPERANDS##_##I8##_port123,		\
	Zen4_##INST##_##OPERANDS##_##I8##_port0123,	\
	Zen4_##INST##_##OPERANDS##_##I8##_port45,		\
	Zen4_##INST##_##OPERANDS##_##I8##_tern,		\
	Zen4_##INST##_##OPERANDS##_##I8##_LDs,			\
	Zen4_##INST##_##OPERANDS##_##I8##_port1		\
}},

ZEN4_FUNCDEF_I8(vextracti128,		ymmI82xmm,		0)
ZEN4_FUNCDEF_I8(vextractf128,		ymmI82xmm,		0)
ZEN4_FUNCDEF_I8(vextracti128,		ymmI82xmm,		1)
ZEN4_FUNCDEF_I8(vextractf128,		ymmI82xmm,		1)
ZEN4_FUNCDEF_I8(vextracti32x4 ,		ymmi82xmm,		0)
ZEN4_FUNCDEF_I8(vextractf32x4 ,		ymmi82xmm,		0)
ZEN4_FUNCDEF_I8(vextracti32x4 ,		ymmi82xmm,		1)
ZEN4_FUNCDEF_I8(vextractf32x4 ,		ymmi82xmm,		1)
ZEN4_FUNCDEF_I8(vextracti32x4 ,		zmmi82xmm,		0)
ZEN4_FUNCDEF_I8(vextractf32x4 ,		zmmi82xmm,		0)
ZEN4_FUNCDEF_I8(vextracti32x4 ,		zmmi82xmm,		1)
ZEN4_FUNCDEF_I8(vextractf32x4 ,		zmmi82xmm,		1)
ZEN4_FUNCDEF_I8(vextracti32x8 ,		zmmi82ymm,		0)
ZEN4_FUNCDEF_I8(vextractf32x8 ,		zmmi82ymm,		0)
ZEN4_FUNCDEF_I8(vextracti32x8 ,		zmmi82ymm,		1)
ZEN4_FUNCDEF_I8(vextractf32x8 ,		zmmi82ymm,		1)
ZEN4_FUNCDEF_I8(vinserti128,		xmmymmI82ymm,	0)
ZEN4_FUNCDEF_I8(vinsertf128,		xmmymmI82ymm,	0)
ZEN4_FUNCDEF_I8(vinserti128,		xmmymmI82ymm,	1)
ZEN4_FUNCDEF_I8(vinsertf128,		xmmymmI82ymm,	1)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmymmI82ymm,	0)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmymmI82ymm,	0)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmymmI82ymm,	1)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmymmI82ymm,	1)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	0)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	0)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	1)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	1)
ZEN4_FUNCDEF_I8(vinserti32x8,		ymmzmmI82zmm,	0)
ZEN4_FUNCDEF_I8(vinsertf32x8,		ymmzmmI82zmm,	0)
ZEN4_FUNCDEF_I8(vinserti32x8,		ymmzmmI82zmm,	1)
ZEN4_FUNCDEF_I8(vinsertf32x8,		ymmzmmI82zmm,	1)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		02h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		02h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		10h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		10h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		30h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		30h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		32h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		32h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		80h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		80h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		81h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		81h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		88h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		88h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		18h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		18h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		19h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		19h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		89h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		89h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		99h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		99h)

ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		02h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		02h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		01h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		02h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		02h)

ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		01h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		01h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		0f0h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		0f0h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		01h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		01h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		0f0h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		0f0h)