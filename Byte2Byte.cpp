#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

void Byte2ByteTest(void) {
	cout << "--- AVX512VBMI Byte2Byte mapping ---" << dec << right << endl;
	cout << "Masked VPERMI2B pair          :" << Byte2Byte01() << endl;
	cout << "VPERMI2B pair + kreg + TERNLOG:" << Byte2Byte02() << endl;
	if (cpu_props.IsFeat(ISA_GFNI)) {
		cout << "VPERMI2B pair + GFNI + TERNLOG:" << Byte2Byte03() << endl;
	}
}
