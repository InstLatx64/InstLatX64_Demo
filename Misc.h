#pragma once

#define _INSTLATX64_DEMO_TESTVECT_00		0xff7f3f1f0f070301
#define _INSTLATX64_DEMO_TESTVECT_01		0x80c0e0f0f8fcfeff

#define _INSTLATX64_DEMO_TESTVECT_02		0xaa55cc33a050c031
#define _INSTLATX64_DEMO_TESTVECT_03		0x030c050a33cc55aa

#define _INSTLATX64_DEMO_TESTVECT_04		0x080808ff08080808
#define _INSTLATX64_DEMO_TESTVECT_05		0x8142241818244281

#define _INSTLATX64_DEMO_TESTVECT_06		0x8040201008040201
#define _INSTLATX64_DEMO_TESTVECT_07		0x0102040810204080

#define _INSTLATX64_DEMO_TESTVECT_08		0x8040201008040000
#define _INSTLATX64_DEMO_TESTVECT_09		0x0002040810204080

#define _INSTLATX64_DEMO_TESTVECT_0A		0x8080808080808000
#define _INSTLATX64_DEMO_TESTVECT_0B		0x0101010101010101

#define _INSTLATX64_DEMO_TESTVECT_FE		0xfefefefefefefefe
#define _INSTLATX64_DEMO_TESTVECT_FF		0xffffffffffffffff

#define _INSTLATX64_DEMO_TESTMASK_8			0x5a
#define _INSTLATX64_DEMO_TESTMASK_16		0x5a7e
#define _INSTLATX64_DEMO_TESTMASK_32		0x5a7e3c18
#define _INSTLATX64_DEMO_TESTMASK_64		0x07701ff13ff37ff7

void printRes32(const char * name, __m128i res);
void printRes32(const char * name, __m256i res);
void printRes32(const char * name, __m512i res);
void printRes(const char * name, __m128i res);
void printRes(const char * name, __m256i res);
void printRes(const char * name, __m512i res);
void printRes(int r, const char * name, __m128i res);
void printRes(int r, const char * name, __m256i res);
void printRes(int r, const char * name, __m512i res);

void random_wrap(unsigned int* random);
void random_wrap(signed int* random);
void random_wrap(unsigned long long* random);
void random_wrap(signed long long* random);

uint64_t serialized_tsc(void);

void SetThread(size_t threadindex);

