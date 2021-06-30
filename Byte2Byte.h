#pragma once

#define REPEATS	0x1000000

extern "C" unsigned __int64 Byte2Byte01(void);
extern "C" unsigned __int64 Byte2Byte02(void);
extern "C" unsigned __int64 Byte2Byte03(void); //GFNI, fastest
extern "C" unsigned __int64 Byte2Byte04(void); //For CannonLake

void Byte2ByteTest(void);
