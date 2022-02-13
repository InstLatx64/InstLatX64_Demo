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

#include "InstLatX64_Demo.h"
#include "512bFMA_DP_Ports.h"
#include "CPU_Props.h"

#include "Byte2Byte.h"
#include "KmovTest.h"

#include "GFNI_Demo.h"
#include "VPCLMULQDQ_Demo.h"
#include "VBMI2_Demo.h"
#include "PEXT_PDEP_Emu.h"
#include "SIMD_PEXT_PDEP_Demo.h"
#include "TZCNT_Demo.h"

#include "Zen3_Demo.h"
#include "Zen3_Demo_AVX.h"
#include "Zen3_Demo_SSE.h"
#include "Zen3_Demo_X87.h"
#include "Zen3_Demo_UCode.h"

#include "AMX_Demo.h"
