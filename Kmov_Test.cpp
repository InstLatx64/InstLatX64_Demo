#include "stdafx.h"

extern CPU_Props cpu_props;

using namespace std;

void Kmov_Test(void) {
	cout << "--- KMOV + POPCNT ---" << dec << right << endl;
	cout << "4x KMOVW + 4x POPCNT + 3x ADD   :" << (double)KmovTest01() / (double)REPEATS << endl;
	cout << "3x KUNPCK + 1x KMOVQ + 1x POPCNT:" << (double)KmovTest02() / (double)REPEATS << endl;
	cout << "4x KMOVW mem + POPCNT mem       :" << (double)KmovTest03() / (double)REPEATS << endl;
}