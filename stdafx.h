#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <intrin.h>
#include <limits.h>
#include <zmmintrin.h>
#include <windows.h>

#include <iostream>
#include <iomanip>

#include <assert.h>

#include "Misc.h"
#include "CPU_Props.h"
#include "InstLatX64_Demo.h"
#include "512bFMA_DP_Ports.h"
#include "Args.h"

#include "Byte2Byte.h"
#include "KmovTest.h"

#include "GFNI_Demo.h"
#include "VPCLMULQDQ_Demo.h"
#include "VBMI2_Demo.h"
#include "PEXT_PDEP_Emu.h"
#include "SIMD_PEXT_PDEP_Demo.h"
#include "TZCNT_Demo.h"

#include "AMX_Demo.h"
#include "AVX512_DecimalPrint.h"
#include "Compiler_Intrinsic_Test.h"