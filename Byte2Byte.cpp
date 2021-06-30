#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

void Byte2ByteTest(void) {
	cout << "--- AVX512VBMI Byte2Byte mapping ---" << dec << right << endl;
	cout << "Masked VPERMI2B pair            :" << (double)Byte2Byte01() / (double)REPEATS << endl;
	cout << "VPERMI2B pair + kreg + TERNLOG  :" << (double)Byte2Byte02() / (double)REPEATS << endl;
	if (cpu_props.IsFeat(ISA_GFNI)) {
		cout << "VPERMI2B pair + GFNI + TERNLOG  :" << (double)Byte2Byte03() / (double)REPEATS << endl;
	}
	cout << "VPERMI2B pair + VPSHRQ + TERNLOG:" << (double)Byte2Byte04() / (double)REPEATS << endl;
}
