// InstLatX64_Demo.cpp 
//

#include "stdafx.h"

CPU_Props cpu_props;

using namespace std;

const demoTypeList demos[] = {
	{"GFNI",				"",			DEMO_GFNI,				ISA_GFNI,				true,	GFNI_Demo,					"SIMD byte granularity shifts/rotates, 8x8 bit, pospocnt, etc."},
	{"VPCLMULQDQ",			"CLMUL",	DEMO_VPCLMLQDQ,			ISA_CLMUL,				true,	VPCLMULQDQ_Demo,			"SIMD prefix xor / parity"},
#if defined (_M_X64)
#if defined (__AVX2__)
	{"PEXT_PDEP",			"PEXT",		DEMO_PEXT_PDEP_EMU,		ISA_BMI2,				true,	PEXT_PDEP_Emu_Test,			"Fast GPR PEXT/PDEP instruction emulation for AMDs"},
#endif
#if defined(__AVX512F__)
	{"KMemDst",				"KMem",		DEMO_KMEMDST,			ISA_AVX512F,			true,	AVX512_KMemDst_Demo,			"AVX512 insts with masked memory destination"},
	{"Intrinsics",			"Intrin",	DEMO_INTRINSICS,		ISA_AVX512F,			true,	AVX512_InstrincTest,		"Visual Studio Compiler Intrinsics Test"},
	{"VBMI2",				"",			DEMO_VBMI2,				ISA_AVX512_VBMI2,		true,	VBMI2_Demo,					"SIMD variable rots and shifts for words and bytes"},
	{"Byte2Byte",			"B2B",		DEMO_BYTE2BYTE,			ISA_AVX512VBMI,			true,	Byte2ByteTest,				"Fastest Byte2Byte SIMD replacemant"},
	{"TZCNT",				"",			DEMO_TZCNT,				ISA_AVX512_VPOPCNTDQ,	true,	TZCNT_Test,					"Missing SIMD TZCNT emulation"},
	{"SIMD_PEXT_PDEP",		"PEXT",		DEMO_PEXT_PDEP,			ISA_AVX512BW,			true,	SIMD_PEXT_PDEP_Test,		"SIMD PEXT, PDEP"},
	{"KMOV",				"",			DEMO_KMOV,				ISA_AVX512BW,			true,	Kmov_Test,					"KMOV"},
	{"AMX",					"",			DEMO_AMX,				ISA_AMX_BF16,			true,	AMX_Test,					"AMX 101"},
	{"AVX512_DecPrint",		"Print",	DEMO_AVX512_DECPRINT,	ISA_AVX512F,			true,	AVX512_DecimalPrint_Test,	"AVX512F & AVX512_IFMA decimal print"},
#endif
#endif
};

Args args(demos, sizeof(demos) / sizeof(demoTypeList));

int main(int argc, char* argv[])
{
	args.Init(argc, argv);

	if (args.IsVersion())
		args.PrintVersion();

	if (args.IsHelp())
		args.PrintUsage();

	if (args.IsDemoList()) {
		cout << endl << "Demo types:";
		for (uint32_t demo = 0; demo < sizeof(demos) / sizeof(demoTypeList); demo++) {
			cout << endl << setw(16) << demos[demo].demoName;
			if (_stricmp(demos[demo].alias, "") != 0)
				cout << " (alias:" << setw(6) << demos[demo].alias << ')';
			else
				cout << "               ";
			cout << (demos[demo].publicFlag ? " [PUB] " : "       ");
			if (_stricmp(demos[demo].comment, "") != 0)
				cout << '(' << demos[demo].comment << ')';
	}
		cout << endl;
	}

	if (args.IsCPUProps()) {
		cpu_props.PrintVendor();
		cpu_props.PrintBrand();
		cpu_props.PrintFeats();
		if (cpu_props.IsFeat(ISA_HYBRID))
			cpu_props.PrintHybridMasks();
#if defined (_M_X64)
		if (cpu_props.IsFeat(ISA_AVX512F))
			cpu_props.Print_512bFMA_DP_Ports();
#endif
		//cpu_props.ForcedAVX512();
	}

	for (uint32_t demo = 0; demo <= args.GetMaxDemo(); demo++) {
		if (args.IsSelected(demo)) {
	cout << "===================================" << endl;
			cout << demos[demo].demoName << endl;
			if (cpu_props.IsFeat(demos[demo].isa)) {
				(demos[demo].func)();
			} else {
				cpu_props.PrintFeat(demos[demo].isa);
				cout << " unspported." << endl;
			}
		}
	}
	return 0;
}

