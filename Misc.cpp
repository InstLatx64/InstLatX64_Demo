#include "stdafx.h"

using namespace std;

void printRes32(const char * name, __m128i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m128i) / sizeof(long) - 1; i >= 0; i--)
		cout << hex << setw(8) << setfill('0') << right << *((unsigned __int32*)&res + i) << ' ';
	cout << endl;
}

void printRes32(const char * name, __m256i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m256i) / sizeof(long) - 1; i >= 0; i--)
		cout << hex << setw(8) << setfill('0') << right << *((unsigned __int32*)&res + i) << ' ';
	cout << endl;
	}

void printRes32(const char * name, __m512i res) {
	cout << setw(24) << left << setfill(' ') << name;
	for (int i = sizeof(__m512i) / sizeof(long) - 1; i >= 0; i--)
		cout << hex << setw(8) << setfill('0') << right << *((unsigned __int32*)&res + i) << ' ';
	cout << endl;
}

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

//  Intel SDM 32546276.pdf p.1739
 uint64_t serialized_tsc(void) {
	uint64_t tsc;
	uint32_t tsc_aux;
	_mm_mfence();
	tsc = __rdtscp(&tsc_aux);
	_mm_lfence();
	return tsc;
}

void random_wrap(unsigned int * random) {
	while (!_rdrand32_step(random));
}

void random_wrap(signed int * random) {
	while (!_rdrand32_step((unsigned int *)random));
}

#if defined (_M_X64)
void random_wrap(unsigned long long * random) {
	while (!_rdrand64_step(random));
}

void random_wrap(signed long long * random) {
	while (!_rdrand64_step((unsigned long long *)random));
}
#endif

void SetThread(size_t threadindex) {
	size_t t = (size_t)1 << threadindex;
	cout << "Procmask:0x" << hex << setfill('0') << setw(sizeof(size_t) * 2) << t << dec << setfill(' ') << endl;
	SetProcessAffinityMask(GetCurrentProcess(), t);
	SetThreadAffinityMask(GetCurrentThread(), t);
	Sleep(0);
}