#include "stdafx.h"

#include "Zen4_Demo.h"
#include "Zen4_Demo_Imm8.h"

extern CPU_Props cpu_props;

using namespace std;

zen4_methods zen4_imm8[] = {
	ZEN4_FUNCDECL0(-- Imm8 --)
	ZEN4_FUNCDECL_I8(VEXTRACTI128 x2<-y1 00h,			vextracti128,		ymmI82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTF128 x2<-y1 00h,			vextractf128,		ymmI82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTI128 x2<-y1 01h,			vextracti128,		ymmI82xmm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTF128 x2<-y1 01h,			vextractf128,		ymmI82xmm,		001h)

	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-y1 00h,			vextracti32x4,		ymmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-y1 00h,			vextractf32x4,		ymmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-y1 01h,			vextracti32x4,		ymmi82xmm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-y1 01h,			vextractf32x4,		ymmi82xmm,		001h)

	ZEN4_FUNCDECL_I8(VEXTRACTI64X2 x2<-y1 00h,			vextracti64x2,		ymmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTF64X2 x2<-y1 00h,			vextractf64x2,		ymmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTI64X2 x2<-y1 01h,			vextracti64x2,		ymmi82xmm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTF64X2 x2<-y1 01h,			vextractf64x2,		ymmi82xmm,		001h)

	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-z1 00h,			vextracti32x4,		zmmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-z1 00h,			vextractf32x4,		zmmi82xmm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-z1 01h,			vextracti32x4,		zmmi82xmm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-z1 01h,			vextractf32x4,		zmmi82xmm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-z1 02h,			vextracti32x4,		zmmi82xmm,		002h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-z1 02h,			vextractf32x4,		zmmi82xmm,		002h)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X4 x2<-z1 03h,			vextracti32x4,		zmmi82xmm,		003h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X4 x2<-z1 03h,			vextractf32x4,		zmmi82xmm,		003h)

	ZEN4_FUNCDECL_I8(VEXTRACTI32X8 y2<-z1 00h,			vextracti32x8,		zmmi82ymm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X8 y2<-z1 00h,			vextractf32x8,		zmmi82ymm,		000h)
	ZEN4_FUNCDECL_I8(VEXTRACTI32X8 y2<-z1 01h,			vextracti32x8,		zmmi82ymm,		001h)
	ZEN4_FUNCDECL_I8(VEXTRACTF32X8 y2<-z1 01h,			vextractf32x8,		zmmi82ymm,		001h)

	ZEN4_FUNCDECL_I8(VINSERTI128 y3<-y2 x1 00h,			vinserti128,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTF128 y3<-y2 x1 00h,			vinsertf128,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTI128 y3<-y2 x1 01h,			vinserti128,		xmmymmI82ymm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTF128 y3<-y2 x1 01h,			vinsertf128,		xmmymmI82ymm,	001h)

	ZEN4_FUNCDECL_I8(VINSERTI32X4 y3<-y2 x1 00h,		vinserti32x4,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 y3<-y2 x1 00h,		vinsertf32x4,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 y3<-y2 x1 01h,		vinserti32x4,		xmmymmI82ymm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 y3<-y2 x1 01h,		vinsertf32x4,		xmmymmI82ymm,	001h)

	ZEN4_FUNCDECL_I8(VINSERTI64X2 y3<-y2 x1 00h,		vinserti64x2,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTF64X2 y3<-y2 x1 00h,		vinsertf64x2,		xmmymmI82ymm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTI64X2 y3<-y2 x1 01h,		vinserti64x2,		xmmymmI82ymm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTF64X2 y3<-y2 x1 01h,		vinsertf64x2,		xmmymmI82ymm,	001h)

	ZEN4_FUNCDECL_I8(VINSERTI32X4 z3<-z2 x1 00h,		vinserti32x4,		xmmzmmI82zmm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z3<-z2 x1 00h,		vinsertf32x4,		xmmzmmI82zmm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 z3<-z2 x1 01h,		vinserti32x4,		xmmzmmI82zmm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z3<-z2 x1 01h,		vinsertf32x4,		xmmzmmI82zmm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 z3<-z2 x1 02h,		vinserti32x4,		xmmzmmI82zmm,	002h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z3<-z2 x1 02h,		vinsertf32x4,		xmmzmmI82zmm,	002h)
	ZEN4_FUNCDECL_I8(VINSERTI32X4 z3<-z2 x1 03h,		vinserti32x4,		xmmzmmI82zmm,	003h)
	ZEN4_FUNCDECL_I8(VINSERTF32X4 z3<-z2 x1 03h,		vinsertf32x4,		xmmzmmI82zmm,	003h)

	ZEN4_FUNCDECL_I8(VINSERTI32X8 z3<-z2 y1 00h,		vinserti32x8,		ymmzmmI82zmm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTF32X8 z3<-z2 y1 00h,		vinsertf32x8,		ymmzmmI82zmm,	000h)
	ZEN4_FUNCDECL_I8(VINSERTI32X8 z3<-z2 y1 01h,		vinserti32x8,		ymmzmmI82zmm,	001h)
	ZEN4_FUNCDECL_I8(VINSERTF32X8 z3<-z2 y1 01h,		vinsertf32x8,		ymmzmmI82zmm,	001h)

	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 00h,			vperm2i128,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 00h,			vperm2f128,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 01h,			vperm2i128,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 01h,			vperm2f128,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 02h,			vperm2i128,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 02h,			vperm2f128,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 03h,			vperm2i128,			2ymmI82ymm,		003h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 03h,			vperm2f128,			2ymmI82ymm,		003h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 08h,			vperm2i128,			2ymmI82ymm,		008h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 08h,			vperm2f128,			2ymmI82ymm,		008h)

	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 10h,			vperm2i128,			2ymmI82ymm,		010h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 10h,			vperm2f128,			2ymmI82ymm,		010h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 11h,			vperm2i128,			2ymmI82ymm,		011h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 11h,			vperm2f128,			2ymmI82ymm,		011h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 12h,			vperm2i128,			2ymmI82ymm,		012h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 12h,			vperm2f128,			2ymmI82ymm,		012h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 13h,			vperm2i128,			2ymmI82ymm,		013h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 13h,			vperm2f128,			2ymmI82ymm,		013h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 18h,			vperm2i128,			2ymmI82ymm,		018h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 18h,			vperm2f128,			2ymmI82ymm,		018h)

	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 20h,			vperm2i128,			2ymmI82ymm,		020h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 20h,			vperm2f128,			2ymmI82ymm,		020h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 21h,			vperm2i128,			2ymmI82ymm,		021h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 21h,			vperm2f128,			2ymmI82ymm,		021h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 22h,			vperm2i128,			2ymmI82ymm,		022h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 22h,			vperm2f128,			2ymmI82ymm,		022h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 23h,			vperm2i128,			2ymmI82ymm,		023h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 23h,			vperm2f128,			2ymmI82ymm,		023h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 28h,			vperm2i128,			2ymmI82ymm,		028h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 28h,			vperm2f128,			2ymmI82ymm,		028h)

	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 30h,			vperm2i128,			2ymmI82ymm,		030h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 30h,			vperm2f128,			2ymmI82ymm,		030h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 31h,			vperm2i128,			2ymmI82ymm,		031h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 31h,			vperm2f128,			2ymmI82ymm,		031h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 32h,			vperm2i128,			2ymmI82ymm,		032h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 32h,			vperm2f128,			2ymmI82ymm,		032h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 33h,			vperm2i128,			2ymmI82ymm,		033h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 33h,			vperm2f128,			2ymmI82ymm,		033h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 38h,			vperm2i128,			2ymmI82ymm,		038h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 38h,			vperm2f128,			2ymmI82ymm,		038h)

	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 80h,			vperm2i128,			2ymmI82ymm,		080h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 80h,			vperm2f128,			2ymmI82ymm,		080h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 81h,			vperm2i128,			2ymmI82ymm,		081h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 81h,			vperm2f128,			2ymmI82ymm,		081h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 82h,			vperm2i128,			2ymmI82ymm,		082h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 82h,			vperm2f128,			2ymmI82ymm,		082h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 83h,			vperm2i128,			2ymmI82ymm,		083h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 83h,			vperm2f128,			2ymmI82ymm,		083h)
	ZEN4_FUNCDECL_I8(VPERM2I128 y3<-y2 y1 88h,			vperm2i128,			2ymmI82ymm,		088h)
	ZEN4_FUNCDECL_I8(VPERM2F128 y3<-y2 y1 88h,			vperm2f128,			2ymmI82ymm,		088h)

	ZEN4_FUNCDECL_I8(VSHUFI32X4 y3<-y2 y1 00h,			vshufi32x4,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y3<-y2 y1 00h,			vshuff32x4,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 y3<-y2 y1 01h,			vshufi32x4,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y3<-y2 y1 01h,			vshuff32x4,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 y3<-y2 y1 02h,			vshufi32x4,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y3<-y2 y1 02h,			vshuff32x4,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 y3<-y2 y1 03h,			vshufi32x4,			2ymmI82ymm,		003h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 y3<-y2 y1 03h,			vshuff32x4,			2ymmI82ymm,		003h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y3<-y2 y1 00h,			vshufi64x2,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y3<-y2 y1 00h,			vshuff64x2,			2ymmI82ymm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y3<-y2 y1 01h,			vshufi64x2,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y3<-y2 y1 01h,			vshuff64x2,			2ymmI82ymm,		001h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y3<-y2 y1 02h,			vshufi64x2,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y3<-y2 y1 02h,			vshuff64x2,			2ymmI82ymm,		002h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 y3<-y2 y1 03h,			vshufi64x2,			2ymmI82ymm,		003h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 y3<-y2 y1 03h,			vshuff64x2,			2ymmI82ymm,		003h)

	ZEN4_FUNCDECL_I8(VSHUFI32X4 z3<-z2 z1 00h,			vshufi32x4,			2zmmI82zmm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z3<-z2 z1 00h,			vshuff32x4,			2zmmI82zmm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 z3<-z2 z1 44h,			vshufi32x4,			2zmmI82zmm,		044h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z3<-z2 z1 44h,			vshuff32x4,			2zmmI82zmm,		044h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 z3<-z2 z1 e4h,			vshufi32x4,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z3<-z2 z1 e4h,			vshuff32x4,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFI32X4 z3<-z2 z1 a5h,			vshufi32x4,			2zmmI82zmm,		0a5h)
	ZEN4_FUNCDECL_I8(VSHUFF32X4 z3<-z2 z1 a5h,			vshuff32x4,			2zmmI82zmm,		0a5h)

	ZEN4_FUNCDECL_I8(VSHUFI64X2 z3<-z2 z1 00h,			vshufi64x2,			2zmmI82zmm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z3<-z2 z1 00h,			vshuff64x2,			2zmmI82zmm,		000h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z3<-z2 z1 44h,			vshufi64x2,			2zmmI82zmm,		044h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z3<-z2 z1 44h,			vshuff64x2,			2zmmI82zmm,		044h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z3<-z2 z1 e4h,			vshufi64x2,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z3<-z2 z1 e4h,			vshuff64x2,			2zmmI82zmm,		0e4h)
	ZEN4_FUNCDECL_I8(VSHUFI64X2 z3<-z2 z1 a5h,			vshufi64x2,			2zmmI82zmm,		0a5h)
	ZEN4_FUNCDECL_I8(VSHUFF64X2 z3<-z2 z1 a5h,			vshuff64x2,			2zmmI82zmm,		0a5h)
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
