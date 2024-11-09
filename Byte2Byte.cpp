#include "stdafx.h"
#include "Byte2Byte.h"

extern CPU_Props cpu_props;

using namespace std;

b2b_methods b2b[] = {
	{"Masked VPERMI2B pair             LAT", B2B_MASKEDVPERMI2B_LAT,	FEAT_AVX512VBMI},
	{"VPERMI2B pair + kreg + TERNLOG   LAT", B2B_KREGROUNDTRIP_LAT,		FEAT_AVX512VBMI},
	{"VPERMI2B pair + GFNI + TERNLOG   LAT", B2B_GFNI_LAT,				FEAT_GFNI},
	{"VPERMI2B pair + VPSHRQ + TERNLOG LAT", B2B_SRLQ_LAT,				FEAT_AVX512VBMI},
	{"VPERMI2B pair + VPBLENDMB        LAT", B2B_BLENDMB_LAT,			FEAT_AVX512VBMI},
	{"VPERMI2B pair + VPMIN/MAXSB      LAT", B2B_MINMAX_LAT,			FEAT_AVX512VBMI},

	{"Masked VPERMI2B pair             TP ", B2B_MASKEDVPERMI2B_TP,		FEAT_AVX512VBMI},
	{"VPERMI2B pair + kreg + TERNLOG   TP ", B2B_KREGROUNDTRIP_TP,		FEAT_AVX512VBMI},
	{"VPERMI2B pair + GFNI + TERNLOG   TP ", B2B_GFNI_TP,				FEAT_GFNI},
	{"VPERMI2B pair + VPSHRQ + TERNLOG TP ", B2B_SRLQ_TP,				FEAT_AVX512VBMI},
	{"VPERMI2B pair + VPBLENDMB        TP ", B2B_BLENDMB_TP,			FEAT_AVX512VBMI},
	{"VPERMI2B pair + VPMIN/MAXSB      TP ", B2B_MINMAX_TP,				FEAT_AVX512VBMI},
};

void Byte2ByteTest(void) {
	SetThread(3);
	cout << "--- AVX512VBMI Byte2Byte mapping ---" << dec << right << endl;
	for (int b = 0; b < sizeof(b2b) / sizeof(b2b_methods); b++) {
		if (cpu_props.IsFeat(b2b[b].feats))
			cout << b2b[b].name << ':' << (double)((b2b[b].funcs[0])()) / B2B_REPEATS << endl;
	}
}
