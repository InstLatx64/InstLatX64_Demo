#pragma once

#define INSTNAMELEN		24
#define INITLEN			16
#define TESTCASE		8

typedef unsigned __int64 (*MEASURR_PTR)(uint32_t * histo, uint64_t * data, uint64_t size);

typedef unsigned __int64 (*MEASURE_PTR)(void);

typedef struct {
	const char 		inst[INSTNAMELEN];
	const char 		init[INITLEN];
	MEASURE_PTR		func[TESTCASE];
	Feats			feats;
	int				uopscount;
} measure_methods;

#define P06P1_FUNCDEF(INST, INITREG)	\
unsigned __int64 _##INST##_MOV_R##INITREG##_M1025_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_M1025_TIME(void);	\
unsigned __int64 _##INST##_MOV_R##INITREG##_M1024_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_M1024_TIME(void);	\
unsigned __int64 _##INST##_MOV_R##INITREG##_M513_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_M513_TIME(void);	\
unsigned __int64 _##INST##_MOV_R##INITREG##_M512_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_M512_TIME(void);	\
unsigned __int64 _##INST##_MOV_R##INITREG##_511_TIME(void);		\
unsigned __int64 _##INST##_MOV_E##INITREG##_511_TIME(void);		\
unsigned __int64 _##INST##_MOV_R##INITREG##_512_TIME(void);		\
unsigned __int64 _##INST##_MOV_E##INITREG##_512_TIME(void);		\
unsigned __int64 _##INST##_MOV_R##INITREG##_1023_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_1023_TIME(void);	\
unsigned __int64 _##INST##_MOV_R##INITREG##_1024_TIME(void);	\
unsigned __int64 _##INST##_MOV_E##INITREG##_1024_TIME(void);	

#define P06P1_FUNC(INST, FUNC, INITREG, ISA, UOPS)	\
	{INST, "MOV R"#INITREG", imm32",				\
		{											\
			_##FUNC##_MOV_R##INITREG##_M1025_TIME,	\
			_##FUNC##_MOV_R##INITREG##_M1024_TIME,	\
			_##FUNC##_MOV_R##INITREG##_M513_TIME,	\
			_##FUNC##_MOV_R##INITREG##_M512_TIME,	\
			_##FUNC##_MOV_R##INITREG##_511_TIME,	\
			_##FUNC##_MOV_R##INITREG##_512_TIME,	\
			_##FUNC##_MOV_R##INITREG##_1023_TIME,	\
			_##FUNC##_MOV_R##INITREG##_1024_TIME	\
		},											\
		FEAT_##ISA##, UOPS},
