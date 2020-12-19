#pragma once

#define _ZEN3_DEMO_VERSION		0x0100

#define REPEATS					100
#define FUNCS					15
#define FUNCS_UCODE				11

#define FUNCDEF(INST, OPERANDS)	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_lat(void);		\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_IIDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_FFDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_IFDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_FIDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port0(void);		\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port1(void);		\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port01(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port03(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port2(void);		\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port12(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port23(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port0123(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_port45(void);	\
extern "C" unsigned __int64 __fastcall INST##_##OPERANDS##_LDs(void);

#define FUNCDEF_UCODE(INST)	\
extern "C" unsigned __int64 __fastcall INST##_lat(void);		\
extern "C" unsigned __int64 __fastcall INST##_IIDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_FFDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_IFDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_FIDomain(void);	\
extern "C" unsigned __int64 __fastcall INST##_Port0_1_23(void);	\
extern "C" unsigned __int64 __fastcall INST##_Port01_23(void);	\
extern "C" unsigned __int64 __fastcall INST##_Port03_12(void);	\
extern "C" unsigned __int64 __fastcall INST##_Port0(void);		\
extern "C" unsigned __int64 __fastcall INST##_Port1(void);		\
extern "C" unsigned __int64 __fastcall INST##_Port01(void);

#define FUNCDECL(NAME, INST, OPERANDS)	\
	{#NAME, {\
	INST##_##OPERANDS##_lat, \
	INST##_##OPERANDS##_IIDomain,\
	INST##_##OPERANDS##_FFDomain,\
	INST##_##OPERANDS##_IFDomain, \
	INST##_##OPERANDS##_FIDomain, \
	INST##_##OPERANDS##_port0, \
	INST##_##OPERANDS##_port1, \
	INST##_##OPERANDS##_port01, \
	INST##_##OPERANDS##_port03, \
	INST##_##OPERANDS##_port2, \
	INST##_##OPERANDS##_port12, \
	INST##_##OPERANDS##_port23, \
	INST##_##OPERANDS##_port0123, \
	INST##_##OPERANDS##_port45, \
	INST##_##OPERANDS##_LDs, }},

#define FUNCDECL_UCODE(NAME, INST)	\
	{#NAME, {\
	INST##_lat, \
	INST##_IIDomain, \
	INST##_FFDomain, \
	INST##_IFDomain, \
	INST##_FIDomain, \
	INST##_Port0_1_23, \
	INST##_Port01_23, \
	INST##_Port03_12, \
	INST##_Port0, \
	INST##_Port1, \
	INST##_Port01 \
	}},

#define FUNCDECL0(NAME)	\
	{#NAME, {\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr}},

#define FUNCDECL_UCODE0(NAME)	\
	{#NAME, {\
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr, \
	nullptr}},

FUNCDEF(empty,				empty)

FUNCDEF(vmulpd,				2xmm2xmm)
FUNCDEF(vmulpd,				2ymm2ymm)
FUNCDEF(vmulps,				2xmm2xmm)
FUNCDEF(vmulps,				2ymm2ymm)
FUNCDEF(vmulsd,				2xmm2xmm)
FUNCDEF(vmulss,				2xmm2xmm)
FUNCDEF(vrcpps,				xmm2xmm)
FUNCDEF(vrcpps,				ymm2ymm)
FUNCDEF(vrcpss,				2xmm2xmm)
FUNCDEF(vrsqrtps,			xmm2xmm)
FUNCDEF(vrsqrtps,			ymm2ymm)
FUNCDEF(vrsqrtss,			2xmm2xmm)
FUNCDEF(vpblendvb,			3xmm2xmm)
FUNCDEF(vpblendvb,			3ymm2ymm)
FUNCDEF(vblendvpd,			3xmm2xmm)
FUNCDEF(vblendvpd,			3ymm2ymm)
FUNCDEF(vblendvps,			3xmm2xmm)
FUNCDEF(vblendvps,			3ymm2ymm)
FUNCDEF(vpblendvb,			3xmm2xmmRot)
FUNCDEF(vpblendvb,			3ymm2ymmRot)
FUNCDEF(vblendvpd,			3xmm2xmmRot)
FUNCDEF(vblendvpd,			3ymm2ymmRot)
FUNCDEF(vblendvps,			3xmm2xmmRot)
FUNCDEF(vblendvps,			3ymm2ymmRot)
FUNCDEF(vfmaddsub132pd,		2xmm2xmm)
FUNCDEF(vfmaddsub132pd,		2ymm2ymm)
FUNCDEF(vfmaddsub132ps,		2xmm2xmm)
FUNCDEF(vfmaddsub132ps,		2ymm2ymm)
FUNCDEF(vfmadd132sd,		2xmm2xmm)
FUNCDEF(vfmadd132ss,		2xmm2xmm)
FUNCDEF(vfmaddsub213pd,		2xmm2xmm)
FUNCDEF(vfmaddsub213pd,		2ymm2ymm)
FUNCDEF(vfmaddsub213ps,		2xmm2xmm)
FUNCDEF(vfmaddsub213ps,		2ymm2ymm)
FUNCDEF(vfmadd213sd,		2xmm2xmm)
FUNCDEF(vfmadd213ss,		2xmm2xmm)
FUNCDEF(vfmaddsub231pd,		2xmm2xmm)
FUNCDEF(vfmaddsub231pd,		2ymm2ymm)
FUNCDEF(vfmaddsub231ps,		2xmm2xmm)
FUNCDEF(vfmaddsub231ps,		2ymm2ymm)
FUNCDEF(vfmadd231sd,		2xmm2xmm)
FUNCDEF(vfmadd231ss,		2xmm2xmm)

FUNCDEF(vfmaddsub132pd,		2xmm2xmmRot)
FUNCDEF(vfmaddsub132pd,		2ymm2ymmRot)
FUNCDEF(vfmaddsub132ps,		2xmm2xmmRot)
FUNCDEF(vfmaddsub132ps,		2ymm2ymmRot)
FUNCDEF(vfmadd132sd,		2xmm2xmmRot)
FUNCDEF(vfmadd132ss,		2xmm2xmmRot)
FUNCDEF(vfmaddsub213pd,		2xmm2xmmRot)
FUNCDEF(vfmaddsub213pd,		2ymm2ymmRot)
FUNCDEF(vfmaddsub213ps,		2xmm2xmmRot)
FUNCDEF(vfmaddsub213ps,		2ymm2ymmRot)
FUNCDEF(vfmadd213sd,		2xmm2xmmRot)
FUNCDEF(vfmadd213ss,		2xmm2xmmRot)
FUNCDEF(vfmaddsub231pd,		2xmm2xmmRot)
FUNCDEF(vfmaddsub231pd,		2ymm2ymmRot)
FUNCDEF(vfmaddsub231ps,		2xmm2xmmRot)
FUNCDEF(vfmaddsub231ps,		2ymm2ymmRot)
FUNCDEF(vfmadd231sd,		2xmm2xmmRot)
FUNCDEF(vfmadd231ss,		2xmm2xmmRot)

FUNCDEF(vaddpd,				2xmm2xmm)
FUNCDEF(vaddpd,				2ymm2ymm)
FUNCDEF(vaddps,				2xmm2xmm)
FUNCDEF(vaddps,				2ymm2ymm)
FUNCDEF(vaddsd,				2xmm2xmm)
FUNCDEF(vaddss,				2xmm2xmm)
FUNCDEF(vsubpd,				2xmm2xmm)
FUNCDEF(vsubpd,				2ymm2ymm)
FUNCDEF(vsubps,				2xmm2xmm)
FUNCDEF(vsubps,				2ymm2ymm)
FUNCDEF(vsubsd,				2xmm2xmm)
FUNCDEF(vsubss,				2xmm2xmm)
FUNCDEF(vaddsubpd,			2xmm2xmm)
FUNCDEF(vaddsubpd,			2ymm2ymm)
FUNCDEF(vaddsubps,			2xmm2xmm)
FUNCDEF(vaddsubps,			2ymm2ymm)
FUNCDEF(vroundpd,			xmmi2xmm)
FUNCDEF(vroundpd,			ymmi2ymm)
FUNCDEF(vroundps,			xmmi2xmm)
FUNCDEF(vroundps,			ymmi2ymm)
FUNCDEF(vroundsd,			2xmmi2xmm)
FUNCDEF(vroundss,			2xmmi2xmm)
FUNCDEF(vcvtps2dq,			xmm2xmm)
FUNCDEF(vcvtps2dq,			ymm2ymm)
FUNCDEF(vcvtps2pd,			xmm2xmm)
FUNCDEF(vcvtpd2ps,			xmm2xmm)
FUNCDEF(vcvtpd2dq,			xmm2xmm)
FUNCDEF(vcvtdq2ps,			xmm2xmm)
FUNCDEF(vcvtdq2ps,			ymm2ymm)
FUNCDEF(vcvtdq2pd,			xmm2xmm)
FUNCDEF(vcvtps2ph,			xmmi2xmm)
FUNCDEF(vcvtph2ps,			xmm2xmm)
FUNCDEF(vcvtss2sd,			2xmm2xmm)
FUNCDEF(vcvtsd2ss,			2xmm2xmm)

FUNCDEF(vminpd,				2xmm2xmm)
FUNCDEF(vminpd,				2ymm2ymm)
FUNCDEF(vminps,				2xmm2xmm)
FUNCDEF(vminps,				2ymm2ymm)
FUNCDEF(vminsd,				2xmm2xmm)
FUNCDEF(vminss,				2xmm2xmm)
FUNCDEF(vmaxpd,				2xmm2xmm)
FUNCDEF(vmaxpd,				2ymm2ymm)
FUNCDEF(vmaxps,				2xmm2xmm)
FUNCDEF(vmaxps,				2ymm2ymm)
FUNCDEF(vmaxsd,				2xmm2xmm)
FUNCDEF(vmaxss,				2xmm2xmm)
FUNCDEF(vcmpeqpd,			2xmm2xmm)
FUNCDEF(vcmpeqpd,			2ymm2ymm)
FUNCDEF(vcmpeqps,			2xmm2xmm)
FUNCDEF(vcmpeqps,			2ymm2ymm)
FUNCDEF(vcmpeqsd,			2xmm2xmm)
FUNCDEF(vcmpeqss,			2xmm2xmm)

FUNCDEF(vandpd,				2xmm2xmm)
FUNCDEF(vandpd,				2ymm2ymm)
FUNCDEF(vandps,				2xmm2xmm)
FUNCDEF(vandps,				2ymm2ymm)
FUNCDEF(vandnpd,			2xmm2xmmRot)
FUNCDEF(vandnpd,			2ymm2ymmRot)
FUNCDEF(vandnps,			2xmm2xmmRot)
FUNCDEF(vandnps,			2ymm2ymmRot)
FUNCDEF(vorpd,				2xmm2xmm)
FUNCDEF(vorpd,				2ymm2ymm)
FUNCDEF(vorps,				2xmm2xmm)
FUNCDEF(vorps,				2ymm2ymm)
FUNCDEF(vxorpd,				2xmm2xmmRot)
FUNCDEF(vxorpd,				2ymm2ymmRot)
FUNCDEF(vxorps,				2xmm2xmmRot)
FUNCDEF(vxorps,				2ymm2ymmRot)
FUNCDEF(vblendpd,			2xmmi2xmm)
FUNCDEF(vblendpd,			2ymmi2ymm)
FUNCDEF(vblendps,			2xmmi2xmm)
FUNCDEF(vblendps,			2ymmi2ymm)

FUNCDEF(vpand,				2xmm2xmm)
FUNCDEF(vpand,				2ymm2ymm)
FUNCDEF(vpandn,				2xmm2xmmRot)
FUNCDEF(vpandn,				2ymm2ymmRot)
FUNCDEF(vpor,				2xmm2xmm)
FUNCDEF(vpor,				2ymm2ymm)
FUNCDEF(vpxor,				2xmm2xmmRot)
FUNCDEF(vpxor,				2ymm2ymmRot)
FUNCDEF(vpblendd,			2xmmi2xmm)
FUNCDEF(vpblendd,			2ymmi2ymm)
FUNCDEF(vpblendw,			2xmmi2xmm)
FUNCDEF(vpblendw,			2ymmi2ymm)

FUNCDEF(vpaddb,				2xmm2xmm)
FUNCDEF(vpaddb,				2ymm2ymm)
FUNCDEF(vpaddw,				2xmm2xmm)
FUNCDEF(vpaddw,				2ymm2ymm)
FUNCDEF(vpaddd,				2xmm2xmm)
FUNCDEF(vpaddd,				2ymm2ymm)
FUNCDEF(vpaddq,				2xmm2xmm)
FUNCDEF(vpaddq,				2ymm2ymm)
FUNCDEF(vpsubb,				2xmm2xmmRot)
FUNCDEF(vpsubb,				2ymm2ymmRot)
FUNCDEF(vpsubw,				2xmm2xmmRot)
FUNCDEF(vpsubw,				2ymm2ymmRot)
FUNCDEF(vpsubd,				2xmm2xmmRot)
FUNCDEF(vpsubd,				2ymm2ymmRot)
FUNCDEF(vpsubq,				2xmm2xmmRot)
FUNCDEF(vpsubq,				2ymm2ymmRot)
FUNCDEF(vpcmpeqb,			2xmm2xmmRot)
FUNCDEF(vpcmpeqb,			2ymm2ymmRot)
FUNCDEF(vpcmpeqw,			2xmm2xmmRot)
FUNCDEF(vpcmpeqw,			2ymm2ymmRot)
FUNCDEF(vpcmpeqd,			2xmm2xmmRot)
FUNCDEF(vpcmpeqd,			2ymm2ymmRot)
FUNCDEF(vpcmpgtb,			2xmm2xmmRot)
FUNCDEF(vpcmpgtb,			2ymm2ymmRot)
FUNCDEF(vpcmpgtw,			2xmm2xmmRot)
FUNCDEF(vpcmpgtw,			2ymm2ymmRot)
FUNCDEF(vpcmpgtd,			2xmm2xmmRot)
FUNCDEF(vpcmpgtd,			2ymm2ymmRot)
FUNCDEF(vpcmpgtq,			2xmm2xmmRot)
FUNCDEF(vpcmpgtq,			2ymm2ymmRot)
FUNCDEF(vpminsb,			2xmm2xmm)
FUNCDEF(vpminsb,			2ymm2ymm)
FUNCDEF(vpminub,			2xmm2xmm)
FUNCDEF(vpminub,			2ymm2ymm)
FUNCDEF(vpminsw,			2xmm2xmm)
FUNCDEF(vpminsw,			2ymm2ymm)
FUNCDEF(vpminuw,			2xmm2xmm)
FUNCDEF(vpminuw,			2ymm2ymm)
FUNCDEF(vpminsd,			2xmm2xmm)
FUNCDEF(vpminsd,			2ymm2ymm)
FUNCDEF(vpminud,			2xmm2xmm)
FUNCDEF(vpminud,			2ymm2ymm)
FUNCDEF(vpmaxsb,			2xmm2xmm)
FUNCDEF(vpmaxsb,			2ymm2ymm)
FUNCDEF(vpmaxub,			2xmm2xmm)
FUNCDEF(vpmaxub,			2ymm2ymm)
FUNCDEF(vpmaxsw,			2xmm2xmm)
FUNCDEF(vpmaxsw,			2ymm2ymm)
FUNCDEF(vpmaxuw,			2xmm2xmm)
FUNCDEF(vpmaxuw,			2ymm2ymm)
FUNCDEF(vpmaxsd,			2xmm2xmm)
FUNCDEF(vpmaxsd,			2ymm2ymm)
FUNCDEF(vpmaxud,			2xmm2xmm)
FUNCDEF(vpmaxud,			2ymm2ymm)

FUNCDEF(vpaddsb,			2xmm2xmm)
FUNCDEF(vpaddsb,			2ymm2ymm)
FUNCDEF(vpaddsw,			2xmm2xmm)
FUNCDEF(vpaddsw,			2ymm2ymm)
FUNCDEF(vpsubsb,			2xmm2xmmRot)
FUNCDEF(vpsubsb,			2ymm2ymmRot)
FUNCDEF(vpsubsw,			2xmm2xmmRot)
FUNCDEF(vpsubsw,			2ymm2ymmRot)
FUNCDEF(vpcmpeqq,			2xmm2xmmRot)
FUNCDEF(vpcmpeqq,			2ymm2ymmRot)
FUNCDEF(vpabsb,				xmm2xmm)
FUNCDEF(vpabsb,				ymm2ymm)
FUNCDEF(vpabsw,				xmm2xmm)
FUNCDEF(vpabsw,				ymm2ymm)
FUNCDEF(vpabsd,				xmm2xmm)
FUNCDEF(vpabsd,				ymm2ymm)
FUNCDEF(vpavgb,				2xmm2xmm)
FUNCDEF(vpavgb,				2ymm2ymm)
FUNCDEF(vpavgw,				2xmm2xmm)
FUNCDEF(vpavgw,				2ymm2ymm)
FUNCDEF(vpsignb,			2xmm2xmm)
FUNCDEF(vpsignb,			2ymm2ymm)
FUNCDEF(vpsignw,			2xmm2xmm)
FUNCDEF(vpsignw,			2ymm2ymm)
FUNCDEF(vpsignd,			2xmm2xmm)
FUNCDEF(vpsignd,			2ymm2ymm)
FUNCDEF(vaesenc,			2xmm2xmm)
FUNCDEF(vaesenc,			2ymm2ymm)
FUNCDEF(vaesenclast,		2xmm2xmm)
FUNCDEF(vaesenclast,		2ymm2ymm)
FUNCDEF(vaesdec,			2xmm2xmm)
FUNCDEF(vaesdec,			2ymm2ymm)
FUNCDEF(vaesdeclast,		2xmm2xmm)
FUNCDEF(vaesdeclast,		2ymm2ymm)
FUNCDEF(vaesenc,			2xmm2xmmRot)
FUNCDEF(vaesenc,			2ymm2ymmRot)
FUNCDEF(vaesenclast,		2xmm2xmmRot)
FUNCDEF(vaesenclast,		2ymm2ymmRot)
FUNCDEF(vaesdec,			2xmm2xmmRot)
FUNCDEF(vaesdec,			2ymm2ymmRot)
FUNCDEF(vaesdeclast,		2xmm2xmmRot)
FUNCDEF(vaesdeclast,		2ymm2ymmRot)
FUNCDEF(vaesimc,			xmm2xmm)
FUNCDEF(vaeskeygenassist,	xmmi2xmm)
FUNCDEF(vphminposuw,		xmm2xmm)
FUNCDEF(vpermilpd,			2xmm2xmm)
FUNCDEF(vpermilpd,			2ymm2ymm)
FUNCDEF(vpermilps,			2xmm2xmm)
FUNCDEF(vpermilps,			2ymm2ymm)

FUNCDEF(vpsllvd,			2xmm2xmm)
FUNCDEF(vpsllvd,			2ymm2ymm)
FUNCDEF(vpsrlvd,			2xmm2xmm)
FUNCDEF(vpsrlvd,			2ymm2ymm)
FUNCDEF(vpsravd,			2xmm2xmm)
FUNCDEF(vpsravd,			2ymm2ymm)
FUNCDEF(vpsllvq,			2xmm2xmm)
FUNCDEF(vpsllvq,			2ymm2ymm)
FUNCDEF(vpsrlvq,			2xmm2xmm)
FUNCDEF(vpsrlvq,			2ymm2ymm)
FUNCDEF(vpsllw,				xmmi2xmm)
FUNCDEF(vpsllw,				ymmi2ymm)
FUNCDEF(vpsrlw,				xmmi2xmm)
FUNCDEF(vpsrlw,				ymmi2ymm)
FUNCDEF(vpsraw,				xmmi2xmm)
FUNCDEF(vpsraw,				ymmi2ymm)
FUNCDEF(vpslld,				xmmi2xmm)
FUNCDEF(vpslld,				ymmi2ymm)
FUNCDEF(vpsrld,				xmmi2xmm)
FUNCDEF(vpsrld,				ymmi2ymm)
FUNCDEF(vpsrad,				xmmi2xmm)
FUNCDEF(vpsrad,				ymmi2ymm)
FUNCDEF(vpsllq,				xmmi2xmm)
FUNCDEF(vpsllq,				ymmi2ymm)
FUNCDEF(vpsrlq,				xmmi2xmm)
FUNCDEF(vpsrlq,				ymmi2ymm)
FUNCDEF(vpslldq,			xmmi2xmm)
FUNCDEF(vpslldq,			ymmi2ymm)
FUNCDEF(vpsrldq,			xmmi2xmm)
FUNCDEF(vpsrldq,			ymmi2ymm)

FUNCDEF(vpunpcklbw,			2xmm2xmm)
FUNCDEF(vpunpcklbw,			2ymm2ymm)
FUNCDEF(vpunpckhbw,			2xmm2xmm)
FUNCDEF(vpunpckhbw,			2ymm2ymm)
FUNCDEF(vpunpcklwd,			2xmm2xmm)
FUNCDEF(vpunpcklwd,			2ymm2ymm)
FUNCDEF(vpunpckhwd,			2xmm2xmm)
FUNCDEF(vpunpckhwd,			2ymm2ymm)
FUNCDEF(vpunpckldq,			2xmm2xmm)
FUNCDEF(vpunpckldq,			2ymm2ymm)
FUNCDEF(vpunpckhdq,			2xmm2xmm)
FUNCDEF(vpunpckhdq,			2ymm2ymm)
FUNCDEF(vpunpcklqdq,		2xmm2xmm)
FUNCDEF(vpunpcklqdq,		2ymm2ymm)
FUNCDEF(vpunpckhqdq,		2xmm2xmm)
FUNCDEF(vpunpckhqdq,		2ymm2ymm)
FUNCDEF(vunpcklps,			2xmm2xmm)
FUNCDEF(vunpcklps,			2ymm2ymm)
FUNCDEF(vunpckhps,			2xmm2xmm)
FUNCDEF(vunpckhps,			2ymm2ymm)
FUNCDEF(vunpcklpd,			2xmm2xmm)
FUNCDEF(vunpcklpd,			2ymm2ymm)
FUNCDEF(vunpckhpd,			2xmm2xmm)
FUNCDEF(vunpckhpd,			2ymm2ymm)
FUNCDEF(vmovhlps,			2xmm2xmm)
FUNCDEF(vmovlhps,			2xmm2xmm)
FUNCDEF(vpacksswb,			2xmm2xmm)
FUNCDEF(vpacksswb,			2ymm2ymm)
FUNCDEF(vpackuswb,			2xmm2xmm)
FUNCDEF(vpackuswb,			2ymm2ymm)
FUNCDEF(vpackssdw,			2xmm2xmm)
FUNCDEF(vpackssdw,			2ymm2ymm)
FUNCDEF(vpackusdw,			2xmm2xmm)
FUNCDEF(vpackusdw,			2ymm2ymm)
FUNCDEF(vpermilpd,			xmmi2xmm)
FUNCDEF(vpermilpd,			ymmi2ymm)
FUNCDEF(vpermilps,			xmmi2xmm)
FUNCDEF(vpermilps,			ymmi2ymm)
FUNCDEF(vshufpd,			2xmmi2xmm)
FUNCDEF(vshufpd,			2ymmi2ymm)
FUNCDEF(vshufps,			2xmmi2xmm)
FUNCDEF(vshufps,			2ymmi2ymm)
FUNCDEF(vpshufb,			2xmm2xmm)
FUNCDEF(vpshufb,			2ymm2ymm)
FUNCDEF(vpshuflw,			xmmi2xmm)
FUNCDEF(vpshuflw,			ymmi2ymm)
FUNCDEF(vpshufhw,			xmmi2xmm)
FUNCDEF(vpshufhw,			ymmi2ymm)
FUNCDEF(vpshufd,			xmmi2xmm)
FUNCDEF(vpshufd,			ymmi2ymm)
FUNCDEF(vpalignr,			2xmmi2xmm)
FUNCDEF(vpalignr,			2ymmi2ymm)
FUNCDEF(vmovddup,			xmm2xmm)
FUNCDEF(vmovddup,			ymm2ymm)
FUNCDEF(vmovsldup,			xmm2xmm)
FUNCDEF(vmovsldup,			ymm2ymm)
FUNCDEF(vmovshdup,			xmm2xmm)
FUNCDEF(vmovshdup,			ymm2ymm)
FUNCDEF(vpbroadcastb,		xmm2xmm)
FUNCDEF(vpbroadcastw,		xmm2xmm)
FUNCDEF(vpbroadcastd,		xmm2xmm)
FUNCDEF(vpbroadcastq,		xmm2xmm)
FUNCDEF(vpmovzxbw,			xmm2xmm)
FUNCDEF(vpmovzxbd,			xmm2xmm)
FUNCDEF(vpmovzxbq,			xmm2xmm)
FUNCDEF(vpmovzxwd,			xmm2xmm)
FUNCDEF(vpmovzxwq,			xmm2xmm)
FUNCDEF(vpmovzxdq,			xmm2xmm)
FUNCDEF(vpmovsxbw,			xmm2xmm)
FUNCDEF(vpmovsxbd,			xmm2xmm)
FUNCDEF(vpmovsxbq,			xmm2xmm)
FUNCDEF(vpmovsxwd,			xmm2xmm)
FUNCDEF(vpmovsxwq,			xmm2xmm)
FUNCDEF(vpmovsxdq,			xmm2xmm)
FUNCDEF(vinsertps,			2xmmi2xmm)

FUNCDEF(vpmulhw,			2xmm2xmm)
FUNCDEF(vpmulhw,			2ymm2ymm)
FUNCDEF(vpmulhuw,			2xmm2xmm)
FUNCDEF(vpmulhuw,			2ymm2ymm)
FUNCDEF(vpmulhrsw,			2xmm2xmm)
FUNCDEF(vpmulhrsw,			2ymm2ymm)
FUNCDEF(vpmullw,			2xmm2xmm)
FUNCDEF(vpmullw,			2ymm2ymm)
FUNCDEF(vpmulld,			2xmm2xmm)
FUNCDEF(vpmulld,			2ymm2ymm)
FUNCDEF(vpmuldq,			2xmm2xmm)
FUNCDEF(vpmuldq,			2ymm2ymm)
FUNCDEF(vpmuludq,			2xmm2xmm)
FUNCDEF(vpmuludq,			2ymm2ymm)
FUNCDEF(vpmaddwd,			2xmm2xmm)
FUNCDEF(vpmaddwd,			2ymm2ymm)
FUNCDEF(vpmaddubsw,			2xmm2xmm)
FUNCDEF(vpmaddubsw,			2ymm2ymm)
FUNCDEF(vpsadbw,			2xmm2xmm)
FUNCDEF(vpsadbw,			2ymm2ymm)

FUNCDEF(vinserti128,		xmmymmi2ymm)
FUNCDEF(vinsertf128,		xmmymmi2ymm)
FUNCDEF(vextracti128,		ymmi2xmm)
FUNCDEF(vextractf128,		ymmi2xmm)
FUNCDEF(vperm2i128,			2ymmi2ymm)
FUNCDEF(vperm2f128,			2ymmi2ymm)
FUNCDEF(vpbroadcastq,		xmm2ymm)
FUNCDEF(vbroadcastsd,		xmm2ymm)
FUNCDEF(vpbroadcastb,		xmm2ymm)
FUNCDEF(vpbroadcastw,		xmm2ymm)
FUNCDEF(vpbroadcastd,		xmm2ymm)
FUNCDEF(vbroadcastss,		xmm2ymm)

FUNCDEF(vdivpd,				2xmm2xmm2)
FUNCDEF(vdivpd,				2ymm2ymm2)
FUNCDEF(vdivps,				2xmm2xmm2)
FUNCDEF(vdivps,				2ymm2ymm2)
FUNCDEF(vdivsd,				2xmm2xmm2)
FUNCDEF(vdivss,				2xmm2xmm2)
FUNCDEF(vsqrtpd,			xmm2xmm1)
FUNCDEF(vsqrtpd,			ymm2ymm1)
FUNCDEF(vsqrtps,			xmm2xmm1)
FUNCDEF(vsqrtps,			ymm2ymm1)
FUNCDEF(vsqrtsd,			2xmm2xmm1)
FUNCDEF(vsqrtss,			2xmm2xmm1)

FUNCDEF(vmovd,				xmm2gpr32)
FUNCDEF(vmovd,				xmm2gpr64)
FUNCDEF(vmovd,				gpr32_2xmm)
FUNCDEF(vmovd,				gpr64_2xmm)
FUNCDEF(vpextrb,			xmmi2gpr32)
FUNCDEF(vpextrb,			xmmi2gpr64)
FUNCDEF(vpextrw,			xmmi2gpr32)
FUNCDEF(vpextrw,			xmmi2gpr64)
FUNCDEF(vpextrd,			xmmi2gpr32)
FUNCDEF(vpextrd,			xmmi2gpr64)
FUNCDEF(vpextrq,			xmmi2gpr64)
FUNCDEF(vpinsrb,			gpr32i2xmm)
FUNCDEF(vpinsrw,			gpr32i2xmm)
FUNCDEF(vpinsrd,			gpr32i2xmm)
FUNCDEF(vpinsrq,			gpr64i2xmm)
FUNCDEF(vcvtss2si,			xmm2gpr32)
FUNCDEF(vcvtss2si,			xmm2gpr64)
FUNCDEF(vcvtsd2si,			xmm2gpr32)
FUNCDEF(vcvtsd2si,			xmm2gpr64)
FUNCDEF(vcvtsi2ss,			gpr32xmm2xmm)
FUNCDEF(vcvtsi2ss,			gpr64xmm2xmm)
FUNCDEF(vcvtsi2sd,			gpr32xmm2xmm)
FUNCDEF(vcvtsi2sd,			gpr64xmm2xmm)
FUNCDEF(vextractps,			xmmi2gpr32)
FUNCDEF(vpmovmskb,			xmm2gpr32)
FUNCDEF(vpmovmskb,			xmm2gpr64)
FUNCDEF(vpmovmskb,			ymm2gpr32)
FUNCDEF(vpmovmskb,			ymm2gpr64)
FUNCDEF(vmovmskpd,			xmm2gpr32)
FUNCDEF(vmovmskpd,			xmm2gpr64)
FUNCDEF(vmovmskpd,			ymm2gpr32)
FUNCDEF(vmovmskpd,			ymm2gpr64)
FUNCDEF(vmovmskps,			xmm2gpr32)
FUNCDEF(vmovmskps,			xmm2gpr64)
FUNCDEF(vmovmskps,			ymm2gpr32)
FUNCDEF(vmovmskps,			ymm2gpr64)
FUNCDEF(vptest,				xmm2F)
FUNCDEF(vptest,				ymm2F)
FUNCDEF(vtestpd,			xmm2F)
FUNCDEF(vtestpd,			ymm2F)
FUNCDEF(vtestps,			xmm2F)
FUNCDEF(vtestps,			ymm2F)
FUNCDEF(vcomisd,			xmm2F)
FUNCDEF(vcomiss,			xmm2F)
FUNCDEF(vucomisd,			xmm2F)
FUNCDEF(vucomiss,			xmm2F)

FUNCDEF(vpermq,				ymmi2ymm)
FUNCDEF(vpermpd,			ymmi2ymm)
FUNCDEF(vpermd,				2ymm2ymm)
FUNCDEF(vpermps,			2ymm2ymm)
FUNCDEF(vpmovzxbw,			xmm2ymm)
FUNCDEF(vpmovzxbd,			xmm2ymm)
FUNCDEF(vpmovzxbq,			xmm2ymm)
FUNCDEF(vpmovzxwd,			xmm2ymm)
FUNCDEF(vpmovzxwq,			xmm2ymm)
FUNCDEF(vpmovzxdq,			xmm2ymm)
FUNCDEF(vpmovsxbw,			xmm2ymm)
FUNCDEF(vpmovsxbd,			xmm2ymm)
FUNCDEF(vpmovsxbq,			xmm2ymm)
FUNCDEF(vpmovsxwd,			xmm2ymm)
FUNCDEF(vpmovsxwq,			xmm2ymm)
FUNCDEF(vpmovsxdq,			xmm2ymm)
FUNCDEF(vcvtps2pd,			xmm2ymm)
FUNCDEF(vcvtpd2ps,			ymm2xmm)
FUNCDEF(vcvtdq2pd,			xmm2ymm)
FUNCDEF(vcvtpd2dq,			ymm2xmm)
FUNCDEF(vcvtph2ps,			xmm2ymm)
FUNCDEF(vcvtps2ph,			ymmi2xmm)

FUNCDEF(vhaddpd,			2xmm2xmm)
FUNCDEF(vhaddpd,			2ymm2ymm)
FUNCDEF(vhaddps,			2xmm2xmm)
FUNCDEF(vhaddps,			2ymm2ymm)
FUNCDEF(vhsubpd,			2xmm2xmm)
FUNCDEF(vhsubpd,			2ymm2ymm)
FUNCDEF(vhsubps,			2xmm2xmm)
FUNCDEF(vhsubps,			2ymm2ymm)

FUNCDEF(vphaddw,			2xmm2xmm)
FUNCDEF(vphaddw,			2ymm2ymm)
FUNCDEF(vphaddd,			2xmm2xmm)
FUNCDEF(vphaddd,			2ymm2ymm)
FUNCDEF(vphaddsw,			2xmm2xmm)
FUNCDEF(vphaddsw,			2ymm2ymm)
FUNCDEF(vphsubw,			2xmm2xmm)
FUNCDEF(vphsubw,			2ymm2ymm)
FUNCDEF(vphsubd,			2xmm2xmm)
FUNCDEF(vphsubd,			2ymm2ymm)
FUNCDEF(vphsubsw,			2xmm2xmm)
FUNCDEF(vphsubsw,			2ymm2ymm)

FUNCDEF(vdppd,				2xmmi2xmm)
FUNCDEF(vdpps,				2xmmi2xmm)
FUNCDEF(vdpps,				2ymmi2ymm)
FUNCDEF(vpclmulqdq,			2xmmi2xmm)
FUNCDEF(vpclmulqdq,			2ymmi2ymm)
FUNCDEF(vmpsadbw,			2xmmi2xmm)
FUNCDEF(vmpsadbw,			2ymmi2ymm)

FUNCDEF(fadd,				x87_2op)
FUNCDEF(fsub,				x87_2op)
FUNCDEF(fmul,				x87_2op)
FUNCDEF(fdiv,				x87_2op1)
FUNCDEF(fsqrt,				noop1)
FUNCDEF(fxch,				x87_1op)
FUNCDEF(fabs,				noop)
FUNCDEF(fchs,				noop)
FUNCDEF(ftst,				noop)
FUNCDEF(fcom,				x87_1op)
FUNCDEF(fcomi,				x87_2opR)
FUNCDEF(fld,				x87_1op_fstp)
FUNCDEF(fldz,				x87_fstp)
FUNCDEF(fld1,				x87_fstp)
FUNCDEF(fldpi,				x87_fstp)
FUNCDEF(fst,				x87_1op)
FUNCDEF(fxam,				noop)
FUNCDEF(fdecstp,			noop)
FUNCDEF(fincstp,			noop)
FUNCDEF(fnop,				noop)

FUNCDEF_UCODE(vpermq)
FUNCDEF_UCODE(vpermd)
FUNCDEF_UCODE(vpmovzxbq)
FUNCDEF_UCODE(vpclmulqdq)
FUNCDEF_UCODE(vmpsadbw)
FUNCDEF_UCODE(vdppd)
FUNCDEF_UCODE(vphaddd)

FUNCDEF_UCODE(vhaddpd)
FUNCDEF_UCODE(vcvtps2pd)
FUNCDEF_UCODE(vcvtpd2ps)

FUNCDEF_UCODE(vdivpd)
FUNCDEF_UCODE(vdivps)
FUNCDEF_UCODE(vdivsd)
FUNCDEF_UCODE(vdivss)

FUNCDEF_UCODE(vsqrtpd)
FUNCDEF_UCODE(vsqrtps)
FUNCDEF_UCODE(vsqrtsd)
FUNCDEF_UCODE(vsqrtss)

FUNCDEF_UCODE(fsqrt32)
FUNCDEF_UCODE(fsqrt64)
FUNCDEF_UCODE(fsqrt80)
FUNCDEF_UCODE(fdiv32)
FUNCDEF_UCODE(fdiv64)
FUNCDEF_UCODE(fdiv80)

typedef unsigned __int64(__fastcall* TEST_PTR)(void);

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[FUNCS];
} methods;

typedef struct {
	const char 	name[64];
	TEST_PTR	funcs[FUNCS_UCODE];
} methods_ucode;

void Zen3_Demo(void);