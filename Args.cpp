#include "stdafx.h"

const paramsType Args::params[] = {
	{false,	"help",		'h',	ARG_HELP,			NULL,					"this help"},
	{false,	"help",		'?',	ARG_HELP,			NULL,					"this help"},
	{false,	"version",	'v',	ARG_VERSION,		NULL,					"version info"},
	{false,	"list",		'l',	ARG_DEMOLIST,		NULL,					"list of demo types"},
	{false,	"cpu",		'c',	ARG_CPUPROPS,		NULL,					"list of CPU properties"},
	{false,	"pcore",	'\0',	ARG_PCORE,			NULL,					"using performance core on hybrid CPU"},
	{false,	"ecore",	'\0',	ARG_ECORE,			NULL,					"using efficient core on hybrid CPU"},
	{false, "dump",		'm',	ARG_CPUIDDUMP,		NULL,					"native CPUID dump"},
	{true,	"demo",		'd',	ARG_DEMOTYPE,		ARGERR_MISS_DEMO,		"demo type"},
	{true,	"thread",	't',	ARG_THREADINDEX,	ARGERR_MISS_THREAD,		"thread index"},
	{true,	"file",		'f',	ARG_CPUIDFILE,		ARGERR_MISS_CPUIDFILE,	"CPUID from file"},
	{true,	"xcr0",		'x',	ARG_XCR0,			ARGERR_MISS_XCR0,		"forced XCR0 value in hex w/o 0x"},
};

void Args::SetError(char* errorPlace, char * tempStr, const char * errorMsg) {
	strcpy_s(errorPlace, STR_MAXLEN, errorMsg);
	strcat_s(errorPlace, STR_MAXLEN, tempStr);
	return;
}

void Args::SetParam(argType paramType, char * tempStr, char* errorPlace, int * errorCounter) {
	if (tempStr[0] == '\0') {
		if (params[paramType].arguments) {
			SetError(errorPlace, tempStr, params[paramType].missingErr);
			(*errorCounter)++;
		}
	} else {
		switch (paramType) {
			case ARG_HELP: {
				helpFlag = true;
			} break;
			case ARG_VERSION: {
				versionFlag = true;
			} break;
			case ARG_DEMOLIST: {
				listFlag = true;
			} break;
			case ARG_CPUPROPS: {
				cpuPropsFlag = true;
			} break;
			case ARG_DEMOTYPE: {
				uint32_t demo = 0;
				for (demo = 0; demo < demoCount; demo++)
					if ((_stricmp(demoList[demo].demoName, tempStr) == 0) ||
						(_stricmp(demoList[demo].alias, tempStr) == 0)){
						const uint64_t d_bit = 1ULL << (demoList[demo].demoMask & 0x3f);
						const uint64_t d_qword = min(demoList[demo].demoMask >> 6, MAX_DEMOMASK);
						demoMask[d_qword] |= d_bit;
						break;
					}
				if (demo == demoCount) {
					SetError(errorPlace, tempStr, ARGERR_INV_DEMO);
					(*errorCounter)++;
				}
			} break;
			case ARG_THREADINDEX: {
				char* endPtr = 0;
				threadIndex = strtol(tempStr, &endPtr, 10);
			}
			break;
			case ARG_PCORE: {
				if (cpu_props.IsFeat(ISA_HYBRID)) {
#if defined(_M_X64)
					_BitScanReverse64((unsigned long*)&threadIndex, cpu_props.GetBigCoreMask());
#else
					BitScanReverse((unsigned long*)&threadIndex, cpu_props.GetBigCoreMask());
#endif
				} else {
					threadIndex = 0;
				}
			}
			break;
			case ARG_ECORE: {
				if (cpu_props.IsFeat(ISA_HYBRID)) {
#if defined(_M_X64)
					threadIndex = _tzcnt_u64(cpu_props.GetLittleCoreMask());
#else
					threadIndex = _tzcnt_u32(cpu_props.GetLittleCoreMask());
#endif
				} else {
					threadIndex = 0;
				}
			}
			break;
			case ARG_CPUIDDUMP: {
				dumpFlag = true;
			} break;
			case ARG_XCR0: {
				char* endPtr = 0;
				xcr0 = strtol(tempStr, &endPtr, 16);
				if ((xcr0 & (_XCR0_X87 | _XCR0_AVX | _XCR0_AVX512 | _XCR0_AMX | _XCR0_APX)) != xcr0) {
					SetError(errorPlace, tempStr, ARGERR_INV_XCR0);
					(*errorCounter)++;
				}
			}
			break;
			case ARG_NOTHING: {
			} break;
			default: {
			} break;
		}
	}
	return;
}

void Args::PrintUsage(void) const {
	printf("\r\nUsage: %s [switches]", DEMO_FILENAME);
	printf("\r\nExample: %s --demo=GFNI -d=VBMI2 --help --version -c", DEMO_FILENAME);
	printf("\r\nSwitches:");
	for (unsigned int comm = 0; comm < sizeof(params) / sizeof(paramsType); comm++)
		if (params[comm].shortName != '\0')
			printf("\r\n\t[-%c|--%-16s] %s", params[comm].shortName, params[comm].longName, params[comm].description);
		else
			printf("\r\n\t   [--%-16s] %s", params[comm].longName, params[comm].description);
	printf("\r\n");
}

void Args::PrintVersion(void) const {
	std::cout << "Build date:" << __DATE__ << " Time:" << __TIME__ << std::endl;
};

bool Args::IsVersion(void) const{
	return versionFlag;
};

bool Args::IsHelp(void) const {
	return helpFlag;
};

bool Args::IsDemoList(void) const {
	return listFlag;
};

bool Args::IsCPUProps(void) const {
	return cpuPropsFlag;
};

bool Args::IsCPUIDDump(void) const {
	return dumpFlag;
};

bool Args::IsCPUIDFile(void) const {
	return cpuidFileFlag;
};

size_t Args::GetMaxDemo(void) const {
	return DEMO_LAST;
};

size_t Args::GetThreadIndex(void) const {
	return threadIndex;
};

char* Args::GetCPUIDFileName() const {
	return cpuidFileName;
};

bool Args::IsValid(void) const {
	return validFlag;
};

UINT64 Args::GetXCR0() const {
	return xcr0;
};

bool Args::IsSelected(size_t i) const {
	return ((demoMask[i >> 6] & (1ULL << (i & 0x3f))) != 0);
};

Args::Args(const demoTypeList* demos, size_t size, int argc, char** argv) :
	demoList(demos), demoCount(size), paramCount(sizeof(params) / sizeof(paramsType)),
	versionFlag(0), helpFlag(0), listFlag(0), cpuPropsFlag(0), errorFlag(0), dumpFlag(0), cpuidFileFlag(0), 
	paramType(ARG_NOTHING), threadIndex(0), cpuidFileName(0), xcr0(0) {
	validFlag = Init(argc, argv);
};

bool Args::Init(int argc, char** argv) {
	char errorStr[MAX_ARGERROR][STR_MAXLEN];
	memset(errorStr, 0, MAX_ARGERROR * STR_MAXLEN);
	int errorCounter = 0;
	for (int32_t a = 1; a < argc; a++) {
		bool handledFlag = false;
		switch (argv[a][0]) {
			case '/':
			case '-':
				switch (argv[a][1]) {
					case '/':
					case '-': {
						for (unsigned int p = 0; p < paramCount; p++) {
							if (params[p].arguments) {
								char* equPos = strchr(&(argv[a][2]), '=');
								if (equPos != 0) {
									const size_t paramSize = equPos - &(argv[a][2]);
									if (_strnicmp(params[p].longName, &(argv[a][2]), paramSize) == 0) {
										SetParam(params[p].type, equPos + 1, errorStr[errorCounter], &errorCounter);
										handledFlag = true;
										break;
									}
								} else {
									SetError(errorStr[errorCounter], &(argv[a][2]), params[p].missingErr);
									handledFlag = true;
									errorCounter++;
								}
							} else {
								if (_stricmp(params[p].longName, &(argv[a][2])) == 0) {
									SetParam(params[p].type, &(argv[a][3]), errorStr[errorCounter], &errorCounter);
									handledFlag = true;
									break;
								}
							}
						}
					}	break;
					case '\0':
					case ' ':
					case '=': {
						SetError(errorStr[errorCounter], &(argv[a][0]), ARGERR_MISS_ARG);
						handledFlag = true;
						errorCounter++;
					} break;
					default: {
						bool findEqu = (argv[a][2] == '=');
						for (size_t p = 0; p < paramCount; p++) {
							char* find = strchr(&argv[a][1], params[p].shortName);
							if (!params[p].arguments && (find != 0) && (!findEqu)) {
								handledFlag = true;
								SetParam(params[p].type, find, errorStr[errorCounter], &errorCounter);
							} else if (params[p].arguments && (params[p].shortName == argv[a][1])) {
								if (findEqu) {
									handledFlag = true;
									SetParam(params[p].type, &(argv[a][3]), errorStr[errorCounter], &errorCounter);
									break;
								} else {
									handledFlag = true;
									SetError(errorStr[errorCounter], &(argv[a][2]), params[p].missingErr);
									errorCounter++;
									break;
								}
							}
						}
					}	break;
				}
				break;
			default:
				break;
		}
		if (!handledFlag) {
			SetError(errorStr[errorCounter], &(argv[a][0]), ARGERR_INV_SWITCH);
			errorCounter++;
		}
	}
	if (errorCounter > 0) {
		for (int errs = 0; errs < errorCounter; errs++)
			printf_s("\r\n%s", errorStr[errs]);
		printf_s("\r\n");
		return false;
	}
	return true;
}