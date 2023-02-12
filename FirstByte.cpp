#include "stdafx.h"
#include "FirstByte.h"

extern CPU_Props cpu_props;

using namespace std;

//original article:
//http://0x80.pl/notesen/2023-02-06-avx512-find-first-byte-in-lane.html

__m256i _mm256_firstbyte_epu32(__m256i a, char c) {
	__m256i one			= _mm256_set1_epi8(0x01);
	__m256i check		= _mm256_set1_epi8(c);
	__m256i vnnibase	= _mm256_set1_epi32(0x80808000);
	__m256i vnnimul		= _mm256_set1_epi32(0x08040201);
	__m256i shufb_const	= _mm256_broadcastsi128_si256(_mm_setr_epi64x(0x0300010002000100, 0x0400010002000100)); //first zero index

	__m256i xorres		= _mm256_xor_epi64(check, a);
	__m256i minub		= _mm256_min_epu8(one, xorres);

	/* VPDPBUSD collects LSBs into the b[3:0] bitfield: */
#if defined(__AVX512BW__)
	__m256i vnni		= _mm256_dpbusd_epi32(vnnibase, vnnimul, minub);
#else
	__m256i vnni		= _mm256_dpbusd_avx_epi32(vnnibase, vnnimul, minub);
#endif
	return				  _mm256_shuffle_epi8(shufb_const, vnni);
}

//credit: @dougallj
//https://twitter.com/dougallj/status/1624663388856156160

__m256i _mm256_firstbyte_epu64(__m256i a, char c) {
	__m256i one			= _mm256_set1_epi8(0x01);
	__m256i check		= _mm256_set1_epi8(c);
	__m256i mask		= _mm256_cmpeq_epi8(check, a);
	__m256i lowmask		= _mm256_andnot_si256(mask, _mm256_sub_epi64(mask, _mm256_set1_epi64x(1)));
	__m256i ones		= _mm256_and_si256(lowmask, one);
	return				  _mm256_sad_epu8(_mm256_setzero_si256(), ones);
}

#if defined(__AVX512BW__)
__m512i _mm512_firstbyte_epu32(__m512i a, char c) {
	__m512i one			= _mm512_set1_epi8(0x01);
	__m512i check		= _mm512_set1_epi8(c);
	__m512i vnnibase	= _mm512_set1_epi32(0x80808000);
	__m512i vnnimul		= _mm512_set1_epi32(0x08040201);
	__m512i shufb_const	= _mm512_broadcast_i64x2(_mm_setr_epi64x(0x0300010002000100, 0x0400010002000100)); //first zero index

	__m512i xorres		= _mm512_xor_epi64(check, a);
	__m512i minub		= _mm512_min_epu8(one, xorres);

	/* VPDPBUSD collects LSBs into the b[3:0] bitfield: */

	__m512i vnni		= _mm512_dpbusd_epi32(vnnibase, vnnimul, minub);
	return				  _mm512_shuffle_epi8(shufb_const, vnni);
}

__m512i _mm512_firstbyte_epu64(__m512i a, char c) {
	__m512i one			= _mm512_set1_epi8(0x01);
	__m512i check		= _mm512_set1_epi8(c);
	__m512i mirror		= _mm512_set1_epi64(0x0102040810204080);

	__m512i xorres		= _mm512_xor_epi64(check, a);
	__m512i minub		= _mm512_min_epu8(one, xorres);

	/* Mirror bits in qwords, through the    */
	/* 07-16-25-34-43-52-61-70 diagonal axis */
	/*                                       */
	/*           In[i,j] -> Out[7-j,7-i]     */
	/*                                       */
	/* In  : MSB 77 76 75 74 73 72 71 70     */
	/*           67 66 65 64 63 62 61 60     */
	/*           57 56 55 54 53 52 51 50     */
	/*           47 46 45 44 43 42 41 40     */
	/*           37 36 35 34 33 32 31 30     */
	/*           27 26 25 24 23 22 21 20     */
	/*           17 16 15 14 13 12 11 10     */
	/*           07 06 05 04 03 02 01 00 LSB */
	/*                                       */
	/* Out : MSB 00 10 20 30 40 50 60 70     */
	/*           01 11 21 31 41 51 61 71     */
	/*           02 12 22 32 42 52 62 72     */
	/*           03 13 23 33 43 53 63 73     */
	/*           04 14 24 34 44 54 64 74     */
	/*           05 15 25 35 45 55 65 75     */
	/*           06 16 26 36 46 56 66 76     */
	/*           07 17 27 37 47 57 67 77 LSB */

	__m512i gfni		= _mm512_gf2p8affine_epi64_epi8(mirror, minub, 0xff); //mirror & invert 70-60-50-40-30-20-10-00 into b[63:56] with imm8 0xff
	return 				 _mm512_lzcnt_epi64(gfni);
}
#endif

void FirstByte_Demo(void) {
#if defined(__AVX2__)
		if (cpu_props.IsFeat(ISA_AVX_VNNI)) {
			__m256i dword_testcase		= _mm256_set_epi32(0xfedcba98, 0x76543210, 0xbd000000, 0xbd0000, 0xbd00, 0xbd, 0, 0xbdbd);
			printRes32("DWORD Testcase          :", dword_testcase);
			printRes32("_mm256_firstbyte_epu32  :", _mm256_firstbyte_epu32(dword_testcase, (char)0xbd));
		}
		__m256i qword_testcase		= _mm256_set_epi64x(0, 0xbd00, 0xbdbdbd0000, 0xbdbdbdbd000000);
		printRes("QWORD Testcase          :", qword_testcase);
		printRes("_mm256_firstbyte_epu64  :", _mm256_firstbyte_epu64(qword_testcase, (char)0xbd));
#if defined(__AVX512BW__)
		if (cpu_props.IsFeat(ISA_AVX512VNNI)) {
			__m512i dword_testcase2		= _mm512_and_si512(_mm512_movm_epi8(0xfedcba9876543210), _mm512_set1_epi8((char)0xbd));
			printRes32("DWORD Testcase2         :", dword_testcase2);
			printRes32("_mm512_firstbyte_epu32  :", _mm512_firstbyte_epu32(dword_testcase2, (char)0xbd));
		}
		if (cpu_props.IsFeat(ISA_GFNI)) {
			__m512i qword_testcase2		= _mm512_setr_epi64(0xbd, 0xbd00, 0xbd0000, 0xbd000000, 0xbd00000000, 0xbd0000000000, 0xbd000000000000, 0xbd00000000000000);
			printRes("QWORD Testcase2         :", qword_testcase2);
			printRes("_mm512_firstbyte_epu64  :", _mm512_firstbyte_epu64(qword_testcase2, (char)0xbd));
		}
#endif
#endif
}