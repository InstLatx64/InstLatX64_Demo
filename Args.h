#pragma once

#if defined(__AVX512F__)
#define	ISA_FILENAME	"AVX512"
#elif defined (__AVX2__)
#define	ISA_FILENAME	"AVX2"
#else
#define	ISA_FILENAME	"SSE"
#endif

#if defined (_M_X64)
#define	SOLUTION_FILENAME	"_X64"
#else
#define	SOLUTION_FILENAME	"_X32"
#endif

#if defined (_DEBUG)
#define	DEBUG_FILENAME	"_Debug"
#else
#define	DEBUG_FILENAME
#endif

#define	DEMO_FILENAME	"InstLatX64_Demo_" ISA_FILENAME SOLUTION_FILENAME DEBUG_FILENAME ".exe"

#define STR_MAXLEN						256
#define MAX_ARGERROR					8
#define MAX_DEMOMASK					1

#define ARGERR_INV_CHAR					"Invalid character: "
#define ARGERR_INV_PARAM				"Invalid parameter: "
#define ARGERR_INV_SWITCH				"Invalid switch: "
#define ARGERR_INV_DEMO					"Invalid demo type: "

#define ARGERR_MISS_ARG					"Missing argument: "
#define ARGERR_MISS_DEMO				"Missing demo type: "
#define ARGERR_MISS_THREAD				"Missing thread index: "

enum argType {
	ARG_HELP,
	ARG_VERSION,
	ARG_DEMOLIST,
	ARG_CPUPROPS,
	ARG_PCORE,
	ARG_ECORE,
	ARG_CPUIDDUMP,
	ARG_DEMOTYPE,
	ARG_THREADINDEX,
	ARG_NOTHING,
};

typedef struct {
	bool				arguments;
	const char * 		longName;
	char 				shortName;
	argType				type;
	const char *		missingErr;
	const char * 		description;
} paramsType;

class Args {
private:
	static const paramsType		params[];
	uint64_t					demoMask[MAX_DEMOMASK]	= {0};
	argType						paramType;
	size_t						demoCount;
	size_t						paramCount;
	size_t						threadIndex;
	const demoTypeList*			demoList;
	bool						helpFlag;
	bool						versionFlag;
	bool						listFlag;
	bool						cpuPropsFlag;
	bool						errorFlag;
	bool						dumpFlag;
	void						SetError(char* , char*, const char* );
	void						SetParam(argType, char*, char* , int* );
public:
	Args(const demoTypeList[], size_t);
	bool						Init(int argc, char* argv[]);
	bool						IsVersion(void) const;
	bool						IsHelp(void) const;
	bool						IsDemoList(void) const;
	bool						IsCPUProps(void) const;
	bool						IsCPUIDDump(void) const;
	void						PrintUsage(void) const;
	void						PrintVersion(void) const;
	size_t						GetMaxDemo(void) const;
	size_t						GetThreadIndex(void) const;
	bool						IsSelected(size_t) const;
};

extern CPU_Props cpu_props;
