// InstLatX64_Demo.cpp 
//

#include "stdafx.h"

CPU_Props cpu_props;

using namespace std;

void printRes(const char * name, __m128i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m128i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
}

void printRes(const char * name, __m256i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m256i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
	}

void printRes(const char * name, __m512i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m512i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
}

void printRes(int r, const char * name, __m128i res) {
	cout << setw(2) << r << ':' << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m128i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
	}

void printRes(int r, const char * name, __m256i res) {
	cout << setw(2) << r << ':' << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m256i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
	}

void printRes(int r, const char * name, __m512i res) {
	cout << setw(2) << r << ':' << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m512i) / sizeof(long long) - 1; i >= 0; i--)
		cout << hex << setw(16) << setfill('0') << right << *((unsigned __int64*)&res + i) << ' ';
	cout << endl;
}

int main()
{
	cpu_props.PrintVendor();
	cpu_props.PrintBrand();
	cpu_props.PrintFeats();

	if (cpu_props.IsFeat(ISA_GFNI)) {
		GFNI_Demo();
	} else {
		cout << "GFNI unspported." << endl;
	}

	if (cpu_props.IsFeat(ISA_VPCLMULQDQ) || cpu_props.IsFeat(ISA_CLMUL)) {
		VPCLMULQDQ_Demo();
	} else {
		cout << "(VP)CLMUL(QDQ) unspported." << endl;
	}

#if defined(__AVX512F__)
	if (cpu_props.IsFeat(ISA_AVX512_VBMI2)) {
		VBMI2_Demo();
	} else {
		cout << "AVX512_VBMI2 unspported." << endl;
	}
#endif

#if defined(__AVX2__)
	if (cpu_props.IsFeat(ISA_BMI2)) {
		PEXT_PDEP_Emu_Test();
	}
	else {
		cout << "BMI2 unspported." << endl;
	}
#endif

#if defined(__AVX2__) && (_M_X64)
	if (cpu_props.IsFeat(ISA_AVX2) && cpu_props.IsFeat(ISA_RDTSCP) && cpu_props.IsFeat(ISA_VAES) && cpu_props.IsFeat(ISA_VPCLMULQDQ)) {
		Zen3_Demo();
	}
	else {
		cout << "AVX2 unspported." << endl;
	}
#endif

	cout << "===================================" << endl;

}

