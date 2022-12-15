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

ZEN4_FUNCDEF_I8(vextracti128,		ymmI82xmm,		000h)
ZEN4_FUNCDEF_I8(vextractf128,		ymmI82xmm,		000h)
ZEN4_FUNCDEF_I8(vextracti128,		ymmI82xmm,		001h)
ZEN4_FUNCDEF_I8(vextractf128,		ymmI82xmm,		001h)

ZEN4_FUNCDEF_I8(vextracti32x4,		ymmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextractf32x4,		ymmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextracti32x4,		ymmi82xmm,		001h)
ZEN4_FUNCDEF_I8(vextractf32x4,		ymmi82xmm,		001h)

ZEN4_FUNCDEF_I8(vextracti64x2,		ymmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextractf64x2,		ymmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextracti64x2,		ymmi82xmm,		001h)
ZEN4_FUNCDEF_I8(vextractf64x2,		ymmi82xmm,		001h)

ZEN4_FUNCDEF_I8(vextracti32x4,		zmmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextractf32x4,		zmmi82xmm,		000h)
ZEN4_FUNCDEF_I8(vextracti32x4,		zmmi82xmm,		001h)
ZEN4_FUNCDEF_I8(vextractf32x4,		zmmi82xmm,		001h)
ZEN4_FUNCDEF_I8(vextracti32x4,		zmmi82xmm,		002h)
ZEN4_FUNCDEF_I8(vextractf32x4,		zmmi82xmm,		002h)
ZEN4_FUNCDEF_I8(vextracti32x4,		zmmi82xmm,		003h)
ZEN4_FUNCDEF_I8(vextractf32x4,		zmmi82xmm,		003h)

ZEN4_FUNCDEF_I8(vextracti32x8,		zmmi82ymm,		000h)
ZEN4_FUNCDEF_I8(vextractf32x8,		zmmi82ymm,		000h)
ZEN4_FUNCDEF_I8(vextracti32x8,		zmmi82ymm,		001h)
ZEN4_FUNCDEF_I8(vextractf32x8,		zmmi82ymm,		001h)

ZEN4_FUNCDEF_I8(vinserti128,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinsertf128,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinserti128,		xmmymmI82ymm,	001h)
ZEN4_FUNCDEF_I8(vinsertf128,		xmmymmI82ymm,	001h)

ZEN4_FUNCDEF_I8(vinserti32x4,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmymmI82ymm,	001h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmymmI82ymm,	001h)

ZEN4_FUNCDEF_I8(vinserti64x2,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinsertf64x2,		xmmymmI82ymm,	000h)
ZEN4_FUNCDEF_I8(vinserti64x2,		xmmymmI82ymm,	001h)
ZEN4_FUNCDEF_I8(vinsertf64x2,		xmmymmI82ymm,	001h)

ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	000h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	000h)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	001h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	001h)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	002h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	002h)
ZEN4_FUNCDEF_I8(vinserti32x4,		xmmzmmI82zmm,	003h)
ZEN4_FUNCDEF_I8(vinsertf32x4,		xmmzmmI82zmm,	003h)

ZEN4_FUNCDEF_I8(vinserti32x8,		ymmzmmI82zmm,	000h)
ZEN4_FUNCDEF_I8(vinsertf32x8,		ymmzmmI82zmm,	000h)
ZEN4_FUNCDEF_I8(vinserti32x8,		ymmzmmI82zmm,	001h)
ZEN4_FUNCDEF_I8(vinsertf32x8,		ymmzmmI82zmm,	001h)

ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		003h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		003h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		008h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		008h)

ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		010h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		010h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		011h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		011h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		012h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		012h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		013h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		013h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		018h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		018h)

ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		020h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		020h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		021h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		021h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		022h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		022h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		023h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		023h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		028h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		028h)

ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		030h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		030h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		031h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		031h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		032h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		032h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		033h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		033h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		038h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		038h)

ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		080h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		080h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		081h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		081h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		082h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		082h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		083h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		083h)
ZEN4_FUNCDEF_I8(vperm2i128,			2ymmI82ymm,		088h)
ZEN4_FUNCDEF_I8(vperm2f128,			2ymmI82ymm,		088h)

ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2ymmI82ymm,		003h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2ymmI82ymm,		003h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		000h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		001h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		002h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2ymmI82ymm,		003h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2ymmI82ymm,		003h)

ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		000h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		000h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		044h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		044h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshufi32x4,			2zmmI82zmm,		0a5h)
ZEN4_FUNCDEF_I8(vshuff32x4,			2zmmI82zmm,		0a5h)

ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		000h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		000h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		044h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		044h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		0e4h)
ZEN4_FUNCDEF_I8(vshufi64x2,			2zmmI82zmm,		0a5h)
ZEN4_FUNCDEF_I8(vshuff64x2,			2zmmI82zmm,		0a5h)