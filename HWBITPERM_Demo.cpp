#include "stdafx.h"
#include "HWBITPERM_Demo.h"

extern CPU_Props cpu_props;

using namespace std;

bitperm_methods hw_reference[] = {
	{"PEXT32_HW zmm, zmm, zmm      ",	"SKX       ",	32, BEXT32_HW_Lat,	BEXT32_HW_Tp,			BEXT32_HW,		ISA_AVX512BW,		BEXT, 0},
	{"PEXT64_HW zmm, zmm, zmm      ",	"SKX       ",	64, BEXT64_HW_Lat,	BEXT64_HW_Tp,			BEXT64_HW,		ISA_AVX512BW,		BEXT, 1},
	{"PDEP32_HW zmm, zmm, zmm      ",	"SKX       ",	32, BDEP32_HW_Lat,	BDEP32_HW_Tp,			BDEP32_HW,		ISA_AVX512BW,		BDEP, 2},
	{"PDEP64_HW zmm, zmm, zmm      ",	"SKX       ",	64, BDEP64_HW_Lat,	BDEP64_HW_Tp,			BDEP64_HW,		ISA_AVX512BW,		BDEP, 3},
	{"BGRP32_HW zmm, zmm, zmm      ",	"SKX       ",	32, BGRP32_HW_Lat,	BGRP32_HW_Tp,			BGRP32_HW,		ISA_AVX512BW,		BGRP, 4},
	{"BGRP64_HW zmm, zmm, zmm      ",	"SKX       ",	64, BGRP64_HW_Lat,	BGRP64_HW_Tp,			BGRP64_HW,		ISA_AVX512BW,		BGRP, 5},
};

void HWBITPERM_Compare(__m512i p, __m512i mask, __m512i ref, int bitness, BITPERM type) {
	for (int b = 0; b < (sizeof(hw_reference) / sizeof(bitperm_methods)); b++) {
		if (cpu_props.IsFeat(hw_reference[b].isa) && (bitness == hw_reference[b].bitness) && (type == hw_reference[b].type)) {
			__m512i res = (hw_reference[b].func)(p, mask);
			__mmask64 test	= _mm512_cmpeq_epi8_mask(res, ref);
			if (test != ~0ULL)
				if (bitness == 32) {
					printRes32(hw_reference[b].name, p);
					printRes32(hw_reference[b].name, mask);
					printRes32(hw_reference[b].name, ref);
					printRes32(hw_reference[b].name, res);
				} else {
					printRes(hw_reference[b].name, p);
					printRes(hw_reference[b].name, mask);
					printRes(hw_reference[b].name, ref);
					printRes(hw_reference[b].name, res);
				}
			assert(test == ~0ULL);
		}
	}
}

unsigned int _pgrp_u32(unsigned int p, unsigned int m) {
	unsigned int zeros = _pext_u32(p, ~m) << (_mm_popcnt_u32(m));
	unsigned int ones = _pext_u32(p, m);
	return zeros | ones;
}

unsigned __int64 _pgrp_u64(unsigned __int64 p, unsigned __int64 m) {
	unsigned __int64 zeros = _pext_u64(p, ~m) << (_mm_popcnt_u64(m));
	unsigned __int64 ones = _pext_u64(p, m);
	return zeros | ones;
}

void HWBITPERM_Check64(void) {
	__m512i p, m, ref_ext, ref_dep, ref_grp;

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int b = 8 * j + i;
			p.m512i_u64[i] = ~0ULL;
			m.m512i_u64[i] = (((1ULL) << b) + ((1ULL << 63) >> b)) | (1ULL << 32) | (1ULL << 32) | (1ULL << 16) | (1ULL << 48);
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_grp.m512i_i64[i] = _pgrp_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 64, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 64, BDEP);
		HWBITPERM_Compare(p, m, ref_grp, 64, BGRP);
	}

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int b = 8 * j + i;
			p.m512i_u64[i] = ~0ULL;
			m.m512i_u64[i] = _bzhi_u64(~0, b + 1);
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_grp.m512i_i64[i] = _pgrp_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 64, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 64, BDEP);
		HWBITPERM_Compare(p, m, ref_grp, 64, BGRP);
	}

	for (int j = 0; j < 1000; j++) {
		for (int i = 0; i < 8; i++) {
			while (!_rdrand64_step(&p.m512i_u64[i]));
			while (!_rdrand64_step(&m.m512i_u64[i]));
			ref_ext.m512i_i64[i] = _pext_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_dep.m512i_i64[i] = _pdep_u64(p.m512i_u64[i], m.m512i_u64[i]);
			ref_grp.m512i_i64[i] = _pgrp_u64(p.m512i_u64[i], m.m512i_u64[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 64, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 64, BDEP);
		HWBITPERM_Compare(p, m, ref_grp, 64, BGRP);
	}
}

void HWBITPERM_Check32(void) {
	__m512i p, m, ref_ext, ref_dep, ref_grp;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 16; i++) {
			int b = 16 * j + i;
			p.m512i_u32[i] = ~0UL;
			m.m512i_u32[i] = (((1UL) << b) + ((1UL << 31) >> b)) | (1UL << 16);
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_grp.m512i_u32[i] = _pgrp_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 32, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 32, BDEP);;
		HWBITPERM_Compare(p, m, ref_grp, 32, BGRP);;
	}

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 16; i++) {
			int b = 16 * j + i;
			p.m512i_u32[i] = ~0UL;
			m.m512i_u32[i] = _bzhi_u32(~0, b + 1);
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_grp.m512i_u32[i] = _pgrp_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 32, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 32, BDEP);
		HWBITPERM_Compare(p, m, ref_grp, 32, BGRP);
	}

	for (int j = 0; j < 1000; j++) {
		for (int i = 0; i < 16; i++) {
			while (!_rdrand32_step(&p.m512i_u32[i]));
			while (!_rdrand32_step(&m.m512i_u32[i]));
			ref_ext.m512i_u32[i] = _pext_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_dep.m512i_u32[i] = _pdep_u32(p.m512i_u32[i], m.m512i_u32[i]);
			ref_grp.m512i_u32[i] = _pgrp_u32(p.m512i_u32[i], m.m512i_u32[i]);
		}
		HWBITPERM_Compare(p, m, ref_ext, 32, BEXT);
		HWBITPERM_Compare(p, m, ref_dep, 32, BDEP);
		HWBITPERM_Compare(p, m, ref_grp, 32, BGRP);
	}
}

void HWBITPERM_Time(int method) {
	unsigned __int64 minlat	= ULONG_MAX;
	unsigned __int64 mintp	= ULONG_MAX;
	for (int retry = 0; retry < DEPEXT219_RETRIES; retry++) {
		minlat = min(minlat, (hw_reference[method].lat)());
	}
	for (int retry = 0; retry < DEPEXT219_RETRIES; retry++) {
		mintp = min(mintp, (hw_reference[method].tp)());
	}
	cout << hw_reference[method].isaName <<  hw_reference[method].name << ": " << (double)minlat / (double)DEPEXT219_REPEATS << " | ";
	cout <<                                                                       (double)mintp / (double)DEPEXT219_REPEATS << " L|T";
	cout << endl;
}

void HWBITPERM_Test() {
	SetThread(2);
	HWBITPERM_Check64();
	HWBITPERM_Check32();

	cout << setw(5) << fixed << setprecision(2);
	cout << endl<< "HW/Scalar TSC CLKs:----------------------" << endl;
	for (int b = 0; b < (sizeof(hw_reference) / sizeof(bitperm_methods)); b++) {
		if ((cpu_props.IsFeat(hw_reference[b].isa)) && (hw_reference[b].lat != NULL) && (hw_reference[b].tp != NULL))
			HWBITPERM_Time(b);
	}
}
