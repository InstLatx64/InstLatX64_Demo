#include "stdafx.h"

#include "Zen4_Demo_Imm8.h"

extern CPU_Props cpu_props;

using namespace std;

zen4_methods zen4_imm8[] = {
	ZEN4_FUNCDECL0(-- Imm8 --)
	ZEN4_FUNCDECL_I8(VEXTRACTI128 x<-y 0,				vextracti128,		ymmI82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTF128 x<-y 0,				vextractf128,		ymmI82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTI128 x<-y 1,				vextracti128,		ymmI82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTF128 x<-y 1,				vextractf128,		ymmI82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x<-y 0 ,				vextracti32x4 ,		ymmi82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x<-y 0 ,				vextractf32x4 ,		ymmi82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x<-y 1 ,				vextracti32x4 ,		ymmi82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x<-y 1 ,				vextractf32x4 ,		ymmi82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x<-z 0 ,				vextracti32x4 ,		zmmi82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x<-z 0 ,				vextractf32x4 ,		zmmi82xmm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x<-z 1 ,				vextracti32x4 ,		zmmi82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x<-z 1 ,				vextractf32x4 ,		zmmi82xmm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X8 y<-z 0,				vextracti32x8 ,		zmmi82ymm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X8 y<-z 0,				vextractf32x8 ,		zmmi82ymm,		0)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X8 y<-z 1,				vextracti32x8 ,		zmmi82ymm,		1)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X8 y<-z 1,				vextractf32x8 ,		zmmi82ymm,		1)
	ZEN4_FUNCDECL_I8(VINSERTI128 y<-y x 0,				vinserti128,		xmmymmI82ymm,	0)
	ZEN4_FUNCDECL_I8(VINSERTF128 y<-y x 0,				vinsertf128,		xmmymmI82ymm,	0)
	ZEN4_FUNCDECL_I8(VINSERTI128 y<-y x 1,				vinserti128,		xmmymmI82ymm,	1)
	ZEN4_FUNCDECL_I8(VINSERTF128 y<-y x 1,				vinsertf128,		xmmymmI82ymm,	1)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 y<-y x 0,				vinserti32x4,		xmmymmI82ymm,	0)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 y<-y x 0,				vinsertf32x4,		xmmymmI82ymm,	0)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 y<-y x 1,				vinserti32x4,		xmmymmI82ymm,	1)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 y<-y x 1,				vinsertf32x4,		xmmymmI82ymm,	1)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 z<-z x 0,				vinserti32x4,		xmmzmmI82zmm,	0)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z<-z x 0,				vinsertf32x4,		xmmzmmI82zmm,	0)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 z<-z x 1,				vinserti32x4,		xmmzmmI82zmm,	1)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z<-z x 1,				vinsertf32x4,		xmmzmmI82zmm,	1)
	ZEN4_FUNCDECL_I8(VINSERTI32X8 z<-z x 0,				vinserti32x8,		ymmzmmI82zmm,	0)
	ZEN4_FUNCDECL_I8(VINSERTF32X8 z<-z x 0,				vinsertf32x8,		ymmzmmI82zmm,	0)
	ZEN4_FUNCDECL_I8(VINSERTI32X8 z<-z x 1,				vinserti32x8,		ymmzmmI82zmm,	1)
	ZEN4_FUNCDECL_I8(VINSERTF32X8 z<-z x 1,				vinsertf32x8,		ymmzmmI82zmm,	1)

	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 01h,				vperm2i128,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 01h,				vperm2f128,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 02h,				vperm2i128,			2ymmI82ymm,		02h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 02h,				vperm2f128,			2ymmI82ymm,		02h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 10h,				vperm2i128,			2ymmI82ymm,		10h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 10h,				vperm2f128,			2ymmI82ymm,		10h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 30h,				vperm2i128,			2ymmI82ymm,		30h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 30h,				vperm2f128,			2ymmI82ymm,		30h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 32h,				vperm2i128,			2ymmI82ymm,		32h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 32h,				vperm2f128,			2ymmI82ymm,		32h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 80h,				vperm2i128,			2ymmI82ymm,		80h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 80h,				vperm2f128,			2ymmI82ymm,		80h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 81h,				vperm2i128,			2ymmI82ymm,		81h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 81h,				vperm2f128,			2ymmI82ymm,		81h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 88h,				vperm2i128,			2ymmI82ymm,		88h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 88h,				vperm2f128,			2ymmI82ymm,		88h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 18h,				vperm2i128,			2ymmI82ymm,		18h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 18h,				vperm2f128,			2ymmI82ymm,		18h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 19h,				vperm2i128,			2ymmI82ymm,		19h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 19h,				vperm2f128,			2ymmI82ymm,		19h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 89h,				vperm2i128,			2ymmI82ymm,		89h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 89h,				vperm2f128,			2ymmI82ymm,		89h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y<-y y 99h,				vperm2i128,			2ymmI82ymm,		99h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y<-y y 99h,				vperm2f128,			2ymmI82ymm,		99h)

	ZEN4_FUNCDECL_I8(VSHUFI32X4 y<-y y 01h,				vshufi32x4,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y<-y y 01h,				vshuff32x4,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 y<-y y 02h,				vshufi32x4,			2ymmI82ymm,		02h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y<-y y 02h,				vshuff32x4,			2ymmI82ymm,		02h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y<-y y 01h,				vshufi64x2,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y<-y y 01h,				vshuff64x2,			2ymmI82ymm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y<-y y 02h,				vshufi64x2,			2ymmI82ymm,		02h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y<-y y 02h,				vshuff64x2,			2ymmI82ymm,		02h)

	ZEN4_FUNCDECL_I8(VSHUFI32X4 z<-z z 01h,				vshufi32x4,			2zmmI82zmm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z<-z z 01h,				vshuff32x4,			2zmmI82zmm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 z<-z z e4h,				vshufi32x4,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z<-z z e4h,				vshuff32x4,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 z<-z z f0h,				vshufi32x4,			2zmmI82zmm,		0f0h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z<-z z f0h,				vshuff32x4,			2zmmI82zmm,		0f0h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z<-z z 01h,				vshufi64x2,			2zmmI82zmm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z<-z z 01h,				vshuff64x2,			2zmmI82zmm,		01h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z<-z z e4h,				vshufi64x2,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z<-z z e4h,				vshuff64x2,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z<-z z f0h,				vshufi64x2,			2zmmI82zmm,		0f0h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z<-z z f0h,				vshuff64x2,			2zmmI82zmm,		0f0h)
};

void Zen4_Test(zen4_methods *insts, int index) {
	volatile unsigned __int64 minres = ULONG_MAX;
	if (insts[index].funcs[0] != nullptr) {
		cout << setw(4) << right << dec << setfill(' ') << index << '|';
		cout << setw(36) << left << insts[index].name << '|' << right;
		for (int f = 0; f < ZEN4_FUNCS; f++) {
			minres = ULONG_MAX;
			(insts[index].funcs[f])();
			for (int rep = 0; rep < ZEN4_REPEATS; rep++) {
				minres = min(minres, (insts[index].funcs[f])());
			}
			cout << setw(10) << right << minres << '|';
		}
	} else {
		cout << "    |";
		cout << setw(36) << left << insts[index].name << '|' << right;
		//       012345667890
		cout << "--LATENCY-|";
		cout << "THROUGHPUT|";
		cout <<	"--PORT01--|";
		cout << "--PORT23--|";
		cout << "--PORT12--|";
		cout << "--PORT123-|";
		cout << "--PORT0123|";
		cout << "--PORT45--|";
		cout << "-TERRNLOG-|";
		cout << "--LDs-----|";
		cout <<	"--PORT1---|";
	}
	cout << endl;
};

void Zen4_Demo(void)
{
	SetThread(3);

	for (int b = 0; b < sizeof(zen4_imm8) / sizeof(zen4_methods); b++) {
		Zen4_Test(zen4_imm8, b);
	}
}
