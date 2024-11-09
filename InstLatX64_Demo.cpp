// InstLatX64_Demo.cpp 
//

#include "stdafx.h"

using namespace std;

const demoTypeList demos[] = {
	{"GFNI",					"",			DEMO_GFNI,				FEAT_GFNI,				true,	GFNI_Demo,						"SIMD byte granularity shifts/rotates, 8x8 bit, pospocnt, etc."},
	{"VPCLMULQDQ",				"CLMUL",	DEMO_VPCLMLQDQ,			FEAT_CLMUL,				true,	VPCLMULQDQ_Demo,				"SIMD prefix xor / parity"},
#if defined (__AVX2__)
	{"AVX_VNNI_INT16_AddSubS",	"VSAdd",	DEMO_VNNI_SADD,			FEAT_AVX_VNNI_INT16,	true,	AVX_VNNI_Saturated_AddSub_Demo,	"_mm256_adds/subs_epi/epu/32 implementation"},
#endif
#if defined (_M_X64)
#if defined (__AVX2__)
	{"PEXT_PDEP",				"PEXT",		DEMO_PEXT_PDEP_EMU,		FEAT_BMI2,				true,	PEXT_PDEP_Emu_Test,				"Fast GPR PEXT/PDEP instruction emulation for AMDs"},
	{"FirstByte",				"",			DEMO_FIRSTBBYTE,		FEAT_AVX2,				true,	FirstByte_Demo,					"Finding first byte in lanes"},
#endif
#if defined(__AVX512F__)
	{"Reduce_Add",				"RAdd",		DEMO_RADD,				FEAT_AVX512VBMI,		true,	AVX512_Reduce_Add_Demo,			"_mm512_reduce_add_epu8/16/32/64 implementation"},
	{"Saturated_AddSub",		"SAdd",		DEMO_AVX512_SADD,		FEAT_AVX512F,			true,	AVX512_Saturated_AddSub_Demo,	"_mm512_adds/subs_epi/epu/32/64 implementation"},
	{"KMemDst",					"KMem",		DEMO_KMEMDST,			FEAT_AVX512F,			true,	AVX512_KMemDst_Demo,			"AVX512 insts with masked memory destination"},
	{"Zen4",					"Zen4",		DEMO_ZEN4,				FEAT_AVX512F,			true,	Zen4_Demo,						"AMD Zen4 SIMD analysis"},
	{"Zen5",					"Zen5",		DEMO_ZEN5,				FEAT_AVX512F,			true,	Zen5_Demo,						"AMD Zen5 SIMD analysis"},
	{"Intrinsics",				"Intrin",	DEMO_INTRINSICS,		FEAT_AVX512F,			true,	AVX512_InstrincTest,			"Visual Studio Compiler Intrinsics Test"},
	{"VBMI2",					"",			DEMO_VBMI2,				FEAT_AVX512_VBMI2,		true,	VBMI2_Demo,						"SIMD variable rots and shifts for words and bytes"},
	{"Byte2Byte",				"B2B",		DEMO_BYTE2BYTE,			FEAT_AVX512VBMI,		true,	Byte2ByteTest,					"Fastest Byte2Byte SIMD replacemant"},
	{"LZCNT",					"",			DEMO_LZCNT,				FEAT_AVX512_BITALG,		true,	LZCNT_Test,						"Missing SIMD VPLZCNTB/W emulation"},
	{"TZCNT",					"",			DEMO_TZCNT,				FEAT_AVX512_VPOPCNTDQ,	true,	TZCNT_Test,						"Missing SIMD VPTZCNTB/W/D/Q emulation"},
	{"HWBITPERM",				"HWB",		DEMO_HWBITPERM,			FEAT_AVX512BW,			true,	HWBITPERM_Test,					"SVE2 vector BITPERM (BEXT/BDEP/BGRP) emulation with HW scalar BMI2 PEXT/PDEP instructions"},
	{"KMOV",					"",			DEMO_KMOV,				FEAT_AVX512BW,			true,	Kmov_Test,						"KMOV"},
	{"AMX",						"",			DEMO_AMX,				FEAT_AMX_BF16,			true,	AMX_Test,						"AMX 101"},
	{"AVX512_DecPrint",			"Print",	DEMO_AVX512_DECPRINT,	FEAT_AVX512F,			true,	AVX512_DecimalPrint_Test,		"AVX512F & AVX512_IFMA decimal print"},
	{"ByteShift",				"BGVSER",	DEMO_AVX512_BGVSER,		FEAT_AVX512VBMI,		true,	AVX512_BGVSER_Test,				"Byte-Granularity Variable Shift on Entire Register"},
#endif
#endif
};

Args args(demos, sizeof(demos) / sizeof(demoTypeList), __argc, __argv);
CPU_Props cpu_props(args.GetXCR0());

int main(void)
{
	if (args.IsValid()) {

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
		bool fileRead = true;
		if (args.IsCPUIDFile()) {
			fileRead = cpu_props.GetFileCPUID(args.GetCPUIDFileName(), args.GetXCR0());
		}
		if (fileRead) {
			if (args.IsCPUProps()) {
				cpu_props.PrintVendor();
				cpu_props.PrintBrand();
				cpu_props.PrintFeats();
				if (cpu_props.IsFeat(FEAT_HYBRID))
					cpu_props.PrintHybridMasks();
#if defined (_M_X64)
				if (cpu_props.IsFeat(FEAT_AVX512F))
					cpu_props.Print_512bFMA_DP_Ports();
#endif
				//cpu_props.ForcedAVX512();
				cpu_props.PrintXCR0();
			}

			if (args.IsCPUIDDump())
				cpu_props.PrintCPUIDDump();
	
			for (uint32_t demo = 0; demo <= args.GetMaxDemo(); demo++) {
				if (args.IsSelected(demo)) {
					cout << "===================================" << endl;
					cout << demos[demo].demoName << endl;
					if (cpu_props.IsFeat(demos[demo].feats)) {
						(demos[demo].func)();
					} else {
						cpu_props.PrintFeat(demos[demo].feats);
						cout << " unspported." << endl;
					}
				}
			}
		} else {
			cout << "CPUID file open error: " << args.GetCPUIDFileName();
		}
	}
	return 0;
}

