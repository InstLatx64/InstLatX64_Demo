#include "stdafx.h"
/*
*/

extern CPU_Props cpu_props;

using namespace std;

simd_pext_pdep_methods m[] = {
	{"PEXT32_HW zmm, zmm, zmm      ",	"SKX       ",	32, PEXT32_HW_Time,			PEXT32_HW,	ISA_AVX512BW, true },
	{"PEXT64_HW zmm, zmm, zmm      ",	"SKX       ",	64, PEXT64_HW_Time,			PEXT64_HW,	ISA_AVX512BW, true },
	{"PDEP32_HW zmm, zmm, zmm      ",	"SKX       ",	32, PDEP32_HW_Time,			PDEP32_HW,	ISA_AVX512BW, false },
	{"PDEP64_HW zmm, zmm, zmm      ",	"SKX       ",	64, PDEP64_HW_Time,			PDEP64_HW,	ISA_AVX512BW, false },
};

void SIMD_PEXT_PDEP_Compare(__m512i p, __m512i mask, __m512i ref, int bitness, bool extFlag) {
	for (int b = 0; b < (sizeof(m) / sizeof(simd_pext_pdep_methods)); b++) {
		if (cpu_props.IsFeat(m[b].isa) && (bitness == m[b].bitness)  && (extFlag == m[b].extFlag)) {
			__m512i res = (m[b].func)(p, mask);
			__mmask64 test	= _mm512_cmpeq_epi8_mask(res, ref);
			if (test != ~0ULL)
				if (bitness == 32) {
					printRes32(m[b].name, p);
					printRes32(m[b].name, mask);
					printRes32(m[b].name, ref);
					printRes32(m[b].name, res);
				} else {
					printRes(m[b].name, p);
					printRes(m[b].name, mask);
					printRes(m[b].name, ref);
					printRes(m[b].name, res);
				}
			assert(test == ~0ULL);
		}
	}
}

void SIMD_PEXT_PDEP_Check64(void) {
	__m512i p, m, ref_ext, ref_dep;

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int b = 8 * j + i;
			p.m512i_u64[i] = ~0ULL;
			m.m512i_u64[i] = (((1ULL) << b) + ((1ULL << 63) >> b)) | (1ULL << 32) | (1ULL << 32) | (1ULL << 16) | (1ULL << 48);
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 64, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 64, false);
	}

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int b = 8 * j + i;
			p.m512i_u64[i] = ~0ULL;
			m.m512i_u64[i] = _bzhi_u64(~0, b + 1);
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 64, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 64, false);
	}

	for (int j = 0; j < 1000; j++) {
		for (int i = 0; i < 8; i++) {
			while (!_rdrand64_step(&p.m512i_u64[i]));
			while (!_rdrand64_step(&m.m512i_u64[i]));
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 64, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 64, false);
	}
}

void SIMD_PEXT_PDEP_Check32(void) {
	__m512i p, m, ref_ext, ref_dep;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 16; i++) {
			int b = 16 * j + i;
			p.m512i_u32[i] = ~0UL;
			m.m512i_u32[i] = (((1UL) << b) + ((1UL << 31) >> b)) | (1UL << 16);
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 32, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 32, false);
	}

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 16; i++) {
			int b = 16 * j + i;
			p.m512i_u32[i] = ~0UL;
			m.m512i_u32[i] = _bzhi_u32(~0, b + 1);
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 32, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 32, false);
	}

	for (int j = 0; j < 1000; j++) {
		for (int i = 0; i < 16; i++) {
			while (!_rdrand32_step(&p.m512i_u32[i]));
			while (!_rdrand32_step(&m.m512i_u32[i]));
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		SIMD_PEXT_PDEP_Compare(p, m, ref_ext, 32, true);
		SIMD_PEXT_PDEP_Compare(p, m, ref_dep, 32, false);
	}
}

void SIMD_PEXT_PDEP_Time(int method) {
	unsigned __int64 minres = ULONG_MAX;
	for (int retry = 0; retry < DEPEXT219_RETRIES; retry++) {
		minres = min(minres, (m[method].timed)());
	}
	cout << m[method].isaName <<  m[method].name << ": " << (double)minres / (double)DEPEXT219_REPEATS << endl;
}

void SIMD_PEXT_PDEP_Test() {
	SetProcessAffinityMask(GetCurrentProcess(), 2);
	SetThreadAffinityMask(GetCurrentThread(), 2);
	SIMD_PEXT_PDEP_Check64();
	SIMD_PEXT_PDEP_Check32();

	cout << endl<< "HW/Scalar TSC CLKs:----------------------" << endl;
	for (int b = 0; b < (sizeof(m) / sizeof(simd_pext_pdep_methods)); b++) {
		if ((cpu_props.IsFeat(m[b].isa)) && (m[b].timed != NULL))
			SIMD_PEXT_PDEP_Time(b);
	}
}
