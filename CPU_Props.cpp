#include "stdafx.h"

const _EXT CPU_Props::exts[ISA_LAST] = {
// Name							xcr0			feat
	{"---GPR----------",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"RDTSC",				_XCR0_EMPTY,	_FEAT01_EDX_RDTSC},
	{"RDTSCP",				_XCR0_EMPTY,	_EFEAT01_EDX_RDTSCP},
	{"CMOV",				_XCR0_EMPTY,	_FEAT01_EDX_CMOV},
	{"CMPX8",				_XCR0_EMPTY,	_FEAT01_EDX_CMPX8},
	{"CMPX16",				_XCR0_EMPTY,	_FEAT01_ECX_CMPX16},
	{"AMD64",				_XCR0_EMPTY,	_EFEAT01_EDX_AMD64},
	{"LAHF",				_XCR0_EMPTY,	_EFEAT01_ECX_LAHF},
	{"MOVBE",				_XCR0_EMPTY,	_FEAT01_ECX_MOVBE},
	{"ABM",					_XCR0_EMPTY,	_EFEAT01_ECX_ABM},
	{"POPCNT",				_XCR0_EMPTY,	_FEAT01_ECX_POPCNT},
	{"RDRAND",				_XCR0_EMPTY,	_FEAT01_ECX_RDRAND},
	{"RDSEED",				_XCR0_EMPTY,	_FEAT07_EBX_RDSEED},
	{"ADX",					_XCR0_EMPTY,	_FEAT07_EBX_ADX},
	{"BMI",					_XCR0_EMPTY,	_FEAT07_EBX_BMI},
	{"BMI2",				_XCR0_EMPTY,	_FEAT07_EBX_BMI2},
	{"MOVDIRI",				_XCR0_EMPTY,	_FEAT07_ECX_MOVDIRI},
	{"MOVDIR64B",			_XCR0_EMPTY,	_FEAT07_ECX_MOVDIR64B},
	{"---SIMD---------",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"SSE",					_XCR0_EMPTY,	_FEAT01_EDX_SSE},
	{"SSE2",				_XCR0_EMPTY,	_FEAT01_EDX_SSE2},
	{"SSE3",				_XCR0_EMPTY,	_FEAT01_ECX_SSE3},
	{"SSSE3",				_XCR0_EMPTY,	_FEAT01_ECX_SSSE3},
	{"SSE41",				_XCR0_EMPTY,	_FEAT01_ECX_SSE41},
	{"SSE42",				_XCR0_EMPTY,	_FEAT01_ECX_SSE42},
	{"SSE4A",				_XCR0_EMPTY,	_EFEAT01_ECX_SSE4A},
	{"CLMUL",				_XCR0_EMPTY,	_FEAT01_ECX_CLMUL},
	{"AES",					_XCR0_EMPTY,	_FEAT01_ECX_AESNI},
	{"SHA",					_XCR0_EMPTY,	_FEAT07_EBX_SHA},
	{"AVX",					_XCR0_AVX,		_FEAT01_ECX_AVX},
	{"AVX2",				_XCR0_AVX,		_FEAT07_EBX_AVX2},
	{"FMA",					_XCR0_AVX,		_FEAT01_ECX_FMA3},
	{"F16C",				_XCR0_AVX,		_FEAT01_ECX_F16C},
	{"GFNI",				_XCR0_EMPTY,	_FEAT07_ECX_GFNI},
	{"VAES",				_XCR0_EMPTY,	_FEAT07_ECX_VAES},
	{"VPCLMULQDQ",			_XCR0_EMPTY,	_FEAT07_ECX_VPCLMULQDQ},
	{"KEYLOCK",				_KEYLOCK,		_FEAT07_ECX_KEYLOCK},
	{"AVX_VNNI",			_XCR0_AVX,		_FEAT0701_EAX_AVX_VNNI},
	{"---AVX512-------",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"AVX512F",				_XCR0_AVX512,	_FEAT07_EBX_AVX512F},
	{"AVX512CD",			_XCR0_AVX512,	_FEAT07_EBX_AVX512CD},
	{"AVX512ER",			_XCR0_AVX512,	_FEAT07_EBX_AVX512ER},
	{"AVX512PF",			_XCR0_AVX512,	_FEAT07_EBX_AVX512PF},
	{"AVX512BW",			_XCR0_AVX512,	_FEAT07_EBX_AVX512BW},
	{"AVX512DQ",			_XCR0_AVX512,	_FEAT07_EBX_AVX512DQ},
	{"AVX512VL",			_XCR0_AVX512,	_FEAT07_EBX_AVX512VL},
	{"AVX512VBMI",			_XCR0_AVX512,	_FEAT07_ECX_AVX512_VBMI},
	{"AVX512IFMA",			_XCR0_AVX512,	_FEAT07_EBX_AVX512_IFMA},
	{"AVX512VNNI",			_XCR0_AVX512,	_FEAT07_ECX_AVX512_VNNI},
	{"AVX512_4VNNIW",		_XCR0_AVX512,	_FEAT07_EDX_AVX512_4VNNIW},
	{"AVX512_4FMAPS",		_XCR0_AVX512,	_FEAT07_EDX_AVX512_4FMAPS},
	{"AVX512_VPOPCNTDQ",	_XCR0_AVX512,	_FEAT07_ECX_AVX512_VPOPCNTDQ},
	{"AVX512_BITALG",		_XCR0_AVX512,	_FEAT07_ECX_AVX512_BITALG},
	{"AVX512_VBMI2",		_XCR0_AVX512,	_FEAT07_ECX_AVX512_VBMI2},
	{"AVX512_BF16",			_XCR0_AVX512,	_FEAT0701_EAX_AVX512_BF16},
	{"AVX512_VP2INTERSECT",	_XCR0_AVX512,	_FEAT07_EDX_AVX512_VP2INTERSECT},
	{"AVX512_FP16",			_XCR0_AVX512,	_FEAT07_EDX_AVX512_FP16},
	{"---AMX----------",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"AMX-BF16",			_XCR0_AMX,		_FEAT07_EDX_AMX_BF16},
	{"AMX-INT8",			_XCR0_AMX,		_FEAT07_EDX_AMX_INT8},
	{"AMX-TILE",			_XCR0_AMX,		_FEAT07_EDX_AMX_TILE},
	{"---CacheLine----",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"PREFETCHW",			_XCR0_EMPTY,	_EFEAT01_ECX_3DNOWPREF},
	{"PREFETCHWT1",			_XCR0_EMPTY,	_FEAT07_ECX_PWT1},
	{"CLFLUSH",				_XCR0_EMPTY,	_FEAT01_EDX_CLFLUSH},
	{"CLFLUSHOPT",			_XCR0_EMPTY,	_FEAT07_EBX_CLFLUSHOPT},
	{"CLWB",				_XCR0_EMPTY,	_FEAT07_EBX_CLWB},
	{"CLZERO",				_XCR0_EMPTY,	_EFEAT008_EBX_CLZERO},
	{"CLDEMOTE",			_XCR0_EMPTY,	_FEAT07_ECX_CLDEMOTE},
	{"---Misc---------",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"LNOP",				_XCR0_EMPTY,	_FEAT_NOFEAT},
	{"SERIALIZE",			_XCR0_EMPTY,	_FEAT07_EDX_SERIALIZE},
	{"HYBRID",				_XCR0_EMPTY,	_FEAT07_EDX_HYBRID},
	{"---Deprecated---",	_XCR0_EMPTY,	_FEAT_SKIP},
	{"X87",					_XCR0_EMPTY,	_FEAT01_EDX_X87},
	{"MMX",					_XCR0_EMPTY,	_FEAT01_EDX_MMX},
	{"MMX+",				_XCR0_EMPTY,	_EFEAT01_EDX_MMXP},
	{"3DNow!",				_XCR0_EMPTY,	_EFEAT01_EDX_3DNOW},
	{"3DNow!+",				_XCR0_EMPTY,	_EFEAT01_EDX_3DNOWP},
	{"XOP",					_XCR0_AVX,		_EFEAT01_ECX_XOP},
	{"FMA4",				_XCR0_AVX,		_EFEAT01_ECX_FMA4},
	{"TBM",					_XCR0_EMPTY,	_EFEAT01_ECX_TBM},
};

CPU_Props::CPU_Props() : family(0), modell(0), stepping(0), hexID(0), fms(0) {
	int level00[4]			= {0, 0, 0, 0};
	int level01[4]			= {0, 0, 0, 0};
	int level07[4]			= {0, 0, 0, 0};
	int level0701[4]		= {0, 0, 0, 0};
	int level19[4]			= {0, 0, 0, 0};
	int extLevel00[4]		= {0, 0, 0, 0};
	int extLevel01[4]		= {0, 0, 0, 0};
	int extLevel08[4]		= {0, 0, 0, 0};
	unsigned __int64 xcr0	= 0;

	__cpuid(level00, 0x0);
	if (level00[_REG_EAX] >= 1)
		__cpuid(level01, 0x1);
	if (level00[_REG_EAX] >= 7)
		__cpuid(level07, 0x7);
	if (level07[_REG_EAX] > 0)
		__cpuidex(level0701, 0x7, 1);
	if (level00[_REG_EAX] >= 0x19)
		__cpuid(level19, 0x19);
	
	__cpuid(extLevel00, 0x80000000);
	if (extLevel00[_REG_EAX] >= 0x80000001)
		__cpuid(extLevel01, 0x80000001);
	if (extLevel00[_REG_EAX] >= 0x80000008)
		__cpuid(extLevel08, 0x80000008);

	if ((level01[_REG_ECX] & _FEAT01_ECX_OSXSAVE) == _FEAT01_ECX_OSXSAVE)  //OSXSAVE
		xcr0 = _xgetbv(0);

	vendor_num[0] = level00[_REG_EBX];
	vendor_num[1] = level00[_REG_EDX];
	vendor_num[2] = level00[_REG_ECX];

	family		= ((level01[_REG_EAX] >> 8) & 0xf) + ((level01[_REG_EAX] >> 20) & 0xf);
	modell		= (((level01[_REG_EAX] >> 4) & 0xf) | ((level01[_REG_EAX] >> 12) & 0xf0));
	stepping	= (level01[_REG_EAX] & 0xf);
	hexID		= level01[_REG_EAX];

	fms = level01[_REG_EAX];

	if (extLevel00[_REG_EAX] >= 0x80000004) {
		__cpuid(brand_num[0], 0x80000002);
		__cpuid(brand_num[1], 0x80000003);
		__cpuid(brand_num[2], 0x80000004);
	}

	_CPUID_RES c = {xcr0, 
					level01[_REG_EAX], level01[_REG_ECX], level01[_REG_EDX], 
					level07[_REG_EBX], level07[_REG_ECX], level07[_REG_EDX], level0701[_REG_EAX],
					level19[_REG_EBX],
					extLevel01[_REG_ECX], extLevel01[_REG_EDX], 
					extLevel08[_REG_EBX]};

	for (int featInd = 0; featInd < sizeof(exts) / sizeof(_EXT); featInd++) {
		unsigned long place	= (unsigned long)(exts[featInd].featbit >> 32);
		unsigned long fbit	= (unsigned long)(exts[featInd].featbit & ~0UL);
		unsigned __int64 f_low	= 1ULL << (featInd & 0x3f);
		unsigned __int64 f_high	= (featInd & ~0x3f) >> 6;
		switch (place) {
			case _FEAT_SKIP:
				continue;
			case CPUID_NOPLACE: //special LNOP detection
				if ((family == 0x6) || (family == 0x7) || (family == 0xf))
					f[f_high] |= f_low;
				break;
			case CPUID_FEAT19_EBX:
				if ((c.cpuid_res[CPUID_FEAT07_ECX] & fbit) != 0)
					if ((c.cpuid_res[CPUID_FEAT19_EBX] & _FEAT19_EBX_AESKL) != 0)
						f[f_high] |= f_low;
					else
						f_disabled[f_high] |= f_low;
				break;
			default:
				if ((c.cpuid_res[place] & fbit) == fbit) {
					if (exts[featInd].xcr0 == _XCR0_EMPTY)
						f[f_high] |= f_low;
					else
						if ((c.xcr0 & exts[featInd].xcr0) == exts[featInd].xcr0)
							f[f_high] |= f_low;
						else
							f_disabled[f_high] |= f_low;
				}
		}
	}
}

using namespace std;

void CPU_Props::PrintVendor(void) const {
	cout << "Vendor: \"" << std::setw(VENDOR_STRING_SIZE) << vendor_string << "\"" << endl;
	cout << "Family:" << family;
	cout << " Model:" << modell;
	cout << " Stepping:" << stepping;
	cout << " (" << hex << hexID << ')';
	cout << endl;
} 

void CPU_Props::PrintBrand(void) const {
	cout << "Brand: \"" << std::setw(48) << brand_string << "\"" << endl;
}

void CPU_Props::PrintSupportStatus(bool supp) const {
	if (supp)
		cout << ": supported";
	else
		cout << ": unsupported";
}

void CPU_Props::PrintOSStatus(bool enadisa) const {
	if (enadisa)
		cout << ", OS enabled";
	else
		cout << ", OS disabled";
}

void CPU_Props::PrintFeats(void) const {
	for (int featInd = 0; featInd < sizeof(exts) / sizeof(_EXT); featInd++) {
		cout << left << std::setw(FEAT_NAME_SIZE) << exts[featInd].name;

		if(exts[featInd].featbit != _FEAT_SKIP) {
			unsigned __int64 f_low	= 1ULL << (featInd & 0x3f);
			unsigned __int64 f_high	= (featInd & ~0x3f) >> 6;
			switch(exts[featInd].xcr0) {
				case _XCR0_AVX:
				case _XCR0_AVX512:
				case _XCR0_AMX:
				case _KEYLOCK:
					if ((f_disabled[f_high] & f_low) != 0) {
						PrintSupportStatus(true);
						PrintOSStatus(false);
					} else {
						if ((f[f_high] & f_low) == 0) {
							PrintSupportStatus(false);
						} else {
							PrintSupportStatus(true);
							PrintOSStatus(true);
						}
					}
					break;
				case _XCR0_EMPTY:
				default:
					PrintSupportStatus((f[f_high] & f_low) != 0);
					break;
			}
		}
		cout << endl;
	}
}

bool CPU_Props::IsFeat(int feat) const {
	const unsigned __int64 f_low	= 1ULL << (feat & 0x3f);
	const unsigned __int64 f_high	= (feat & ~0x3f) >> 6;
	return ((f[f_high] & f_low) == f_low);
}

bool CPU_Props::IsZen2(void) const {
	return (family == 0x17) && (vendor_num[1] == 0x69746e65);
}

bool CPU_Props::IsZen3(void) const {
	return (family == 0x19) && (vendor_num[1] == 0x69746e65);
}
