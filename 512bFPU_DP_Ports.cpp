#include "stdafx.h"

//from Intel® 64 and IA-32 Architectures Optimization Reference Manual
//18.21 SERVERS WITH A SINGLE FMA UNIT
//https://software.intel.com/content/dam/develop/public/us/en/documents/64-ia-32-architectures-optimization-manual.pdf

int Get_512bFPU_DP_Ports_FromOptimGuide(void) {
	uint64_t fma_shuf_tpt_test[3];
	uint64_t fma_shuf_tpt_test_min;
	uint64_t fma_only_tpt_test[3];
	uint64_t fma_only_tpt_test_min;
	uint64_t start = 0;
	int number_of_fma_units_per_core = 2;
	/*********************************************************/
	/* Step 1: Warmup */
	/*********************************************************/
	fma_only_tpt(100000); 
	/*********************************************************/
	/* Step 2: Execute FMA and Shuffle TPT Test */
	/*********************************************************/
	for(int i = 0; i < 3; i++){
		start = __rdtsc();
		fma_shuffle_tpt(1000);
		fma_shuf_tpt_test[i] = __rdtsc() - start;
	}
	/*********************************************************/
	/* Step 3: Execute FMA only TPT Test */
	/*********************************************************/
	for(int i = 0; i < 3; i++){
		start = __rdtsc();
		fma_only_tpt(1000);
		fma_only_tpt_test[i] = __rdtsc() - start;
	}
	/*********************************************************/
	/* Step 4: Decide if 1 FMA server or 2 FMA server */
	/*********************************************************/
	fma_shuf_tpt_test_min = fma_shuf_tpt_test[0];
	fma_only_tpt_test_min = fma_only_tpt_test[0];
	for(int i = 1; i < 3; i++){
		if ((int)fma_shuf_tpt_test[i] < (int)fma_shuf_tpt_test_min) fma_shuf_tpt_test_min = fma_shuf_tpt_test[i];
		if ((int)fma_only_tpt_test[i] < (int)fma_only_tpt_test_min) fma_only_tpt_test_min = fma_only_tpt_test[i];
	}
	if(((double)fma_shuf_tpt_test_min/(double)fma_only_tpt_test_min) < 1.5){
		number_of_fma_units_per_core = 1;
	}
	//printf("%I64d FMA server\n", number_of_fma_units_per_core);
	return number_of_fma_units_per_core;
}
