#pragma once

ZEN5_FUNCDEF(vmovaps,				xmm2xmm)
ZEN5_FUNCDEF(vmovaps,				ymm2ymm)
ZEN5_FUNCDEF(vmovapd,				xmm2xmm)
ZEN5_FUNCDEF(vmovapd,				ymm2ymm)
ZEN5_FUNCDEF(vmovups,				xmm2xmm)
ZEN5_FUNCDEF(vmovups,				ymm2ymm)
ZEN5_FUNCDEF(vmovupd,				xmm2xmm)
ZEN5_FUNCDEF(vmovupd,				ymm2ymm)
ZEN5_FUNCDEF(vmovdqa,				xmm2xmm)
ZEN5_FUNCDEF(vmovdqa,				ymm2ymm)
ZEN5_FUNCDEF(vmovdqu,				xmm2xmm)
ZEN5_FUNCDEF(vmovdqu,				ymm2ymm)

ZEN5_FUNCDEF(vmulpd,				2xmm2xmm)
ZEN5_FUNCDEF(vmulpd,				2ymm2ymm)
ZEN5_FUNCDEF(vmulps,				2xmm2xmm)
ZEN5_FUNCDEF(vmulps,				2ymm2ymm)
ZEN5_FUNCDEF(vmulsd,				2xmm2xmm)
ZEN5_FUNCDEF(vmulss,				2xmm2xmm)
ZEN5_FUNCDEF(vrcpps,				xmm2xmm)
ZEN5_FUNCDEF(vrcpps,				ymm2ymm)
ZEN5_FUNCDEF(vrcpss,				2xmm2xmm)
ZEN5_FUNCDEF(vrsqrtps,				xmm2xmm)
ZEN5_FUNCDEF(vrsqrtps,				ymm2ymm)
ZEN5_FUNCDEF(vrsqrtss,				2xmm2xmm)
ZEN5_FUNCDEF(vpblendvb,				3xmm2xmm)
ZEN5_FUNCDEF(vpblendvb,				3ymm2ymm)
ZEN5_FUNCDEF(vblendvpd,				3xmm2xmm)
ZEN5_FUNCDEF(vblendvpd,				3ymm2ymm)
ZEN5_FUNCDEF(vblendvps,				3xmm2xmm)
ZEN5_FUNCDEF(vblendvps,				3ymm2ymm)
ZEN5_FUNCDEF(vpblendvb,				3xmm2xmmRot)
ZEN5_FUNCDEF(vpblendvb,				3ymm2ymmRot)
ZEN5_FUNCDEF(vblendvpd,				3xmm2xmmRot)
ZEN5_FUNCDEF(vblendvpd,				3ymm2ymmRot)
ZEN5_FUNCDEF(vblendvps,				3xmm2xmmRot)
ZEN5_FUNCDEF(vblendvps,				3ymm2ymmRot)
ZEN5_FUNCDEF(vfmaddsub132pd,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub132pd,		2ymm2ymm)
ZEN5_FUNCDEF(vfmaddsub132ps,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub132ps,		2ymm2ymm)
ZEN5_FUNCDEF(vfmadd132sd,			2xmm2xmm)
ZEN5_FUNCDEF(vfmadd132ss,			2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub213pd,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub213pd,		2ymm2ymm)
ZEN5_FUNCDEF(vfmaddsub213ps,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub213ps,		2ymm2ymm)
ZEN5_FUNCDEF(vfmadd213sd,			2xmm2xmm)
ZEN5_FUNCDEF(vfmadd213ss,			2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub231pd,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub231pd,		2ymm2ymm)
ZEN5_FUNCDEF(vfmaddsub231ps,		2xmm2xmm)
ZEN5_FUNCDEF(vfmaddsub231ps,		2ymm2ymm)
ZEN5_FUNCDEF(vfmadd231sd,			2xmm2xmm)
ZEN5_FUNCDEF(vfmadd231ss,			2xmm2xmm)

ZEN5_FUNCDEF(vfmaddsub132pd,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub132pd,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmaddsub132ps,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub132ps,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmadd132sd,			2xmm2xmmRot)
ZEN5_FUNCDEF(vfmadd132ss,			2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub213pd,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub213pd,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmaddsub213ps,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub213ps,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmadd213sd,			2xmm2xmmRot)
ZEN5_FUNCDEF(vfmadd213ss,			2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub231pd,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub231pd,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmaddsub231ps,		2xmm2xmmRot)
ZEN5_FUNCDEF(vfmaddsub231ps,		2ymm2ymmRot)
ZEN5_FUNCDEF(vfmadd231sd,			2xmm2xmmRot)
ZEN5_FUNCDEF(vfmadd231ss,			2xmm2xmmRot)

ZEN5_FUNCDEF(vaddpd,				2xmm2xmm)
ZEN5_FUNCDEF(vaddpd,				2ymm2ymm)
ZEN5_FUNCDEF(vaddps,				2xmm2xmm)
ZEN5_FUNCDEF(vaddps,				2ymm2ymm)
ZEN5_FUNCDEF(vaddsd,				2xmm2xmm)
ZEN5_FUNCDEF(vaddss,				2xmm2xmm)
ZEN5_FUNCDEF(vsubpd,				2xmm2xmm)
ZEN5_FUNCDEF(vsubpd,				2ymm2ymm)
ZEN5_FUNCDEF(vsubps,				2xmm2xmm)
ZEN5_FUNCDEF(vsubps,				2ymm2ymm)
ZEN5_FUNCDEF(vsubsd,				2xmm2xmm)
ZEN5_FUNCDEF(vsubss,				2xmm2xmm)
ZEN5_FUNCDEF(vaddsubpd,				2xmm2xmm)
ZEN5_FUNCDEF(vaddsubpd,				2ymm2ymm)
ZEN5_FUNCDEF(vaddsubps,				2xmm2xmm)
ZEN5_FUNCDEF(vaddsubps,				2ymm2ymm)
ZEN5_FUNCDEF(vroundpd,				xmmi2xmm)
ZEN5_FUNCDEF(vroundpd,				ymmi2ymm)
ZEN5_FUNCDEF(vroundps,				xmmi2xmm)
ZEN5_FUNCDEF(vroundps,				ymmi2ymm)
ZEN5_FUNCDEF(vroundsd,				2xmmi2xmm)
ZEN5_FUNCDEF(vroundss,				2xmmi2xmm)
ZEN5_FUNCDEF(vcvtps2dq,				xmm2xmm)
ZEN5_FUNCDEF(vcvtps2dq,				ymm2ymm)
ZEN5_FUNCDEF(vcvtps2pd,				xmm2xmm)
ZEN5_FUNCDEF(vcvtpd2ps,				xmm2xmm)
ZEN5_FUNCDEF(vcvtpd2dq,				xmm2xmm)
ZEN5_FUNCDEF(vcvtdq2ps,				xmm2xmm)
ZEN5_FUNCDEF(vcvtdq2ps,				ymm2ymm)
ZEN5_FUNCDEF(vcvtdq2pd,				xmm2xmm)
ZEN5_FUNCDEF(vcvtps2ph,				xmmi2xmm)
ZEN5_FUNCDEF(vcvtph2ps,				xmm2xmm)
ZEN5_FUNCDEF(vcvtss2sd,				2xmm2xmm)
ZEN5_FUNCDEF(vcvtsd2ss,				2xmm2xmm)

ZEN5_FUNCDEF(vminpd,				2xmm2xmm)
ZEN5_FUNCDEF(vminpd,				2ymm2ymm)
ZEN5_FUNCDEF(vminps,				2xmm2xmm)
ZEN5_FUNCDEF(vminps,				2ymm2ymm)
ZEN5_FUNCDEF(vminsd,				2xmm2xmm)
ZEN5_FUNCDEF(vminss,				2xmm2xmm)
ZEN5_FUNCDEF(vmaxpd,				2xmm2xmm)
ZEN5_FUNCDEF(vmaxpd,				2ymm2ymm)
ZEN5_FUNCDEF(vmaxps,				2xmm2xmm)
ZEN5_FUNCDEF(vmaxps,				2ymm2ymm)
ZEN5_FUNCDEF(vmaxsd,				2xmm2xmm)
ZEN5_FUNCDEF(vmaxss,				2xmm2xmm)
ZEN5_FUNCDEF(vcmpeqpd,				2xmm2xmm)
ZEN5_FUNCDEF(vcmpeqpd,				2ymm2ymm)
ZEN5_FUNCDEF(vcmpeqps,				2xmm2xmm)
ZEN5_FUNCDEF(vcmpeqps,				2ymm2ymm)
ZEN5_FUNCDEF(vcmpeqsd,				2xmm2xmm)
ZEN5_FUNCDEF(vcmpeqss,				2xmm2xmm)

ZEN5_FUNCDEF(vandpd,				2xmm2xmm)
ZEN5_FUNCDEF(vandpd,				2ymm2ymm)
ZEN5_FUNCDEF(vandps,				2xmm2xmm)
ZEN5_FUNCDEF(vandps,				2ymm2ymm)
ZEN5_FUNCDEF(vandnpd,				2xmm2xmmRot)
ZEN5_FUNCDEF(vandnpd,				2ymm2ymmRot)
ZEN5_FUNCDEF(vandnps,				2xmm2xmmRot)
ZEN5_FUNCDEF(vandnps,				2ymm2ymmRot)
ZEN5_FUNCDEF(vorpd,					2xmm2xmm)
ZEN5_FUNCDEF(vorpd,					2ymm2ymm)
ZEN5_FUNCDEF(vorps,					2xmm2xmm)
ZEN5_FUNCDEF(vorps,					2ymm2ymm)
ZEN5_FUNCDEF(vxorpd,				2xmm2xmmRot)
ZEN5_FUNCDEF(vxorpd,				2ymm2ymmRot)
ZEN5_FUNCDEF(vxorps,				2xmm2xmmRot)
ZEN5_FUNCDEF(vxorps,				2ymm2ymmRot)
ZEN5_FUNCDEF(vblendpd,				2xmmi2xmm)
ZEN5_FUNCDEF(vblendpd,				2ymmi2ymm)
ZEN5_FUNCDEF(vblendps,				2xmmi2xmm)
ZEN5_FUNCDEF(vblendps,				2ymmi2ymm)

ZEN5_FUNCDEF(vpand,					2xmm2xmm)
ZEN5_FUNCDEF(vpand,					2ymm2ymm)
ZEN5_FUNCDEF(vpandn,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpandn,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpor,					2xmm2xmm)
ZEN5_FUNCDEF(vpor,					2ymm2ymm)
ZEN5_FUNCDEF(vpxor,					2xmm2xmmRot)
ZEN5_FUNCDEF(vpxor,					2ymm2ymmRot)
ZEN5_FUNCDEF(vpblendd,				2xmmi2xmm)
ZEN5_FUNCDEF(vpblendd,				2ymmi2ymm)
ZEN5_FUNCDEF(vpblendw,				2xmmi2xmm)
ZEN5_FUNCDEF(vpblendw,				2ymmi2ymm)

ZEN5_FUNCDEF(vpaddb,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddb,				2ymm2ymm)
ZEN5_FUNCDEF(vpaddw,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddw,				2ymm2ymm)
ZEN5_FUNCDEF(vpaddd,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddd,				2ymm2ymm)
ZEN5_FUNCDEF(vpaddq,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddq,				2ymm2ymm)
ZEN5_FUNCDEF(vpsubb,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubb,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpsubw,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubw,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpsubd,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubd,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpsubq,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubq,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpeqb,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpeqb,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpeqw,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpeqw,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpeqd,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpeqd,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpgtb,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpgtb,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpgtw,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpgtw,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpgtd,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpgtd,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpgtq,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpgtq,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpminsb,				2xmm2xmm)
ZEN5_FUNCDEF(vpminsb,				2ymm2ymm)
ZEN5_FUNCDEF(vpminub,				2xmm2xmm)
ZEN5_FUNCDEF(vpminub,				2ymm2ymm)
ZEN5_FUNCDEF(vpminsw,				2xmm2xmm)
ZEN5_FUNCDEF(vpminsw,				2ymm2ymm)
ZEN5_FUNCDEF(vpminuw,				2xmm2xmm)
ZEN5_FUNCDEF(vpminuw,				2ymm2ymm)
ZEN5_FUNCDEF(vpminsd,				2xmm2xmm)
ZEN5_FUNCDEF(vpminsd,				2ymm2ymm)
ZEN5_FUNCDEF(vpminud,				2xmm2xmm)
ZEN5_FUNCDEF(vpminud,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxsb,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxsb,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxub,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxub,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxsw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxsw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxuw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxuw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxsd,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxsd,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaxud,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaxud,				2ymm2ymm)

ZEN5_FUNCDEF(vpaddsb,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddsb,				2ymm2ymm)
ZEN5_FUNCDEF(vpaddsw,				2xmm2xmm)
ZEN5_FUNCDEF(vpaddsw,				2ymm2ymm)
ZEN5_FUNCDEF(vpsubsb,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubsb,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpsubsw,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpsubsw,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpcmpeqq,				2xmm2xmmRot)
ZEN5_FUNCDEF(vpcmpeqq,				2ymm2ymmRot)
ZEN5_FUNCDEF(vpabsb,				xmm2xmm)
ZEN5_FUNCDEF(vpabsb,				ymm2ymm)
ZEN5_FUNCDEF(vpabsw,				xmm2xmm)
ZEN5_FUNCDEF(vpabsw,				ymm2ymm)
ZEN5_FUNCDEF(vpabsd,				xmm2xmm)
ZEN5_FUNCDEF(vpabsd,				ymm2ymm)
ZEN5_FUNCDEF(vpavgb,				2xmm2xmm)
ZEN5_FUNCDEF(vpavgb,				2ymm2ymm)
ZEN5_FUNCDEF(vpavgw,				2xmm2xmm)
ZEN5_FUNCDEF(vpavgw,				2ymm2ymm)
ZEN5_FUNCDEF(vpsignb,				2xmm2xmm)
ZEN5_FUNCDEF(vpsignb,				2ymm2ymm)
ZEN5_FUNCDEF(vpsignw,				2xmm2xmm)
ZEN5_FUNCDEF(vpsignw,				2ymm2ymm)
ZEN5_FUNCDEF(vpsignd,				2xmm2xmm)
ZEN5_FUNCDEF(vpsignd,				2ymm2ymm)
ZEN5_FUNCDEF(vaesenc,				2xmm2xmm)
ZEN5_FUNCDEF(vaesenc,				2ymm2ymm)
ZEN5_FUNCDEF(vaesenclast,			2xmm2xmm)
ZEN5_FUNCDEF(vaesenclast,			2ymm2ymm)
ZEN5_FUNCDEF(vaesdec,				2xmm2xmm)
ZEN5_FUNCDEF(vaesdec,				2ymm2ymm)
ZEN5_FUNCDEF(vaesdeclast,			2xmm2xmm)
ZEN5_FUNCDEF(vaesdeclast,			2ymm2ymm)
ZEN5_FUNCDEF(vaesenc,				2xmm2xmmRot)
ZEN5_FUNCDEF(vaesenc,				2ymm2ymmRot)
ZEN5_FUNCDEF(vaesenclast,			2xmm2xmmRot)
ZEN5_FUNCDEF(vaesenclast,			2ymm2ymmRot)
ZEN5_FUNCDEF(vaesdec,				2xmm2xmmRot)
ZEN5_FUNCDEF(vaesdec,				2ymm2ymmRot)
ZEN5_FUNCDEF(vaesdeclast,			2xmm2xmmRot)
ZEN5_FUNCDEF(vaesdeclast,			2ymm2ymmRot)
ZEN5_FUNCDEF(vaesimc,				xmm2xmm)
ZEN5_FUNCDEF(vaeskeygenassist,		xmmi2xmm)
ZEN5_FUNCDEF(vphminposuw,			xmm2xmm)
ZEN5_FUNCDEF(vpermilpd,				2xmm2xmm)
ZEN5_FUNCDEF(vpermilpd,				2ymm2ymm)
ZEN5_FUNCDEF(vpermilps,				2xmm2xmm)
ZEN5_FUNCDEF(vpermilps,				2ymm2ymm)

ZEN5_FUNCDEF(vpsllvd,				2xmm2xmm)
ZEN5_FUNCDEF(vpsllvd,				2ymm2ymm)
ZEN5_FUNCDEF(vpsrlvd,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrlvd,				2ymm2ymm)
ZEN5_FUNCDEF(vpsravd,				2xmm2xmm)
ZEN5_FUNCDEF(vpsravd,				2ymm2ymm)
ZEN5_FUNCDEF(vpsllvq,				2xmm2xmm)
ZEN5_FUNCDEF(vpsllvq,				2ymm2ymm)
ZEN5_FUNCDEF(vpsrlvq,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrlvq,				2ymm2ymm)
ZEN5_FUNCDEF(vpslld,				2xmm2xmm)
ZEN5_FUNCDEF(vpslld,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsrld,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrld,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsrad,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrad,				xmmymm2ymm)
ZEN5_FUNCDEF(vpslld,				2xmm2xmm)
ZEN5_FUNCDEF(vpslld,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsrld,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrld,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsrad,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrad,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsllq,				2xmm2xmm)
ZEN5_FUNCDEF(vpsllq,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsrlq,				2xmm2xmm)
ZEN5_FUNCDEF(vpsrlq,				xmmymm2ymm)
ZEN5_FUNCDEF(vpsllw,				xmmi2xmm)
ZEN5_FUNCDEF(vpsllw,				ymmi2ymm)
ZEN5_FUNCDEF(vpsrlw,				xmmi2xmm)
ZEN5_FUNCDEF(vpsrlw,				ymmi2ymm)
ZEN5_FUNCDEF(vpsraw,				xmmi2xmm)
ZEN5_FUNCDEF(vpsraw,				ymmi2ymm)
ZEN5_FUNCDEF(vpslld,				xmmi2xmm)
ZEN5_FUNCDEF(vpslld,				ymmi2ymm)
ZEN5_FUNCDEF(vpsrld,				xmmi2xmm)
ZEN5_FUNCDEF(vpsrld,				ymmi2ymm)
ZEN5_FUNCDEF(vpsrad,				xmmi2xmm)
ZEN5_FUNCDEF(vpsrad,				ymmi2ymm)
ZEN5_FUNCDEF(vpsllq,				xmmi2xmm)
ZEN5_FUNCDEF(vpsllq,				ymmi2ymm)
ZEN5_FUNCDEF(vpsrlq,				xmmi2xmm)
ZEN5_FUNCDEF(vpsrlq,				ymmi2ymm)
ZEN5_FUNCDEF(vpslldq,				xmmi2xmm)
ZEN5_FUNCDEF(vpslldq,				ymmi2ymm)
ZEN5_FUNCDEF(vpsrldq,				xmmi2xmm)
ZEN5_FUNCDEF(vpsrldq,				ymmi2ymm)

ZEN5_FUNCDEF(vpunpcklbw,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpcklbw,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpckhbw,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpckhbw,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpcklwd,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpcklwd,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpckhwd,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpckhwd,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpckldq,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpckldq,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpckhdq,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpckhdq,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpcklqdq,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpcklqdq,			2ymm2ymm)
ZEN5_FUNCDEF(vpunpckhqdq,			2xmm2xmm)
ZEN5_FUNCDEF(vpunpckhqdq,			2ymm2ymm)
ZEN5_FUNCDEF(vunpcklps,				2xmm2xmm)
ZEN5_FUNCDEF(vunpcklps,				2ymm2ymm)
ZEN5_FUNCDEF(vunpckhps,				2xmm2xmm)
ZEN5_FUNCDEF(vunpckhps,				2ymm2ymm)
ZEN5_FUNCDEF(vunpcklpd,				2xmm2xmm)
ZEN5_FUNCDEF(vunpcklpd,				2ymm2ymm)
ZEN5_FUNCDEF(vunpckhpd,				2xmm2xmm)
ZEN5_FUNCDEF(vunpckhpd,				2ymm2ymm)
ZEN5_FUNCDEF(vmovhlps,				2xmm2xmm)
ZEN5_FUNCDEF(vmovlhps,				2xmm2xmm)
ZEN5_FUNCDEF(vpacksswb,				2xmm2xmm)
ZEN5_FUNCDEF(vpacksswb,				2ymm2ymm)
ZEN5_FUNCDEF(vpackuswb,				2xmm2xmm)
ZEN5_FUNCDEF(vpackuswb,				2ymm2ymm)
ZEN5_FUNCDEF(vpackssdw,				2xmm2xmm)
ZEN5_FUNCDEF(vpackssdw,				2ymm2ymm)
ZEN5_FUNCDEF(vpackusdw,				2xmm2xmm)
ZEN5_FUNCDEF(vpackusdw,				2ymm2ymm)
ZEN5_FUNCDEF(vpermilpd,				xmmi2xmm)
ZEN5_FUNCDEF(vpermilpd,				ymmi2ymm)
ZEN5_FUNCDEF(vpermilps,				xmmi2xmm)
ZEN5_FUNCDEF(vpermilps,				ymmi2ymm)
ZEN5_FUNCDEF(vshufpd,				2xmmi2xmm)
ZEN5_FUNCDEF(vshufpd,				2ymmi2ymm)
ZEN5_FUNCDEF(vshufps,				2xmmi2xmm)
ZEN5_FUNCDEF(vshufps,				2ymmi2ymm)
ZEN5_FUNCDEF(vpshufb,				2xmm2xmm)
ZEN5_FUNCDEF(vpshufb,				2ymm2ymm)
ZEN5_FUNCDEF(vpshuflw,				xmmi2xmm)
ZEN5_FUNCDEF(vpshuflw,				ymmi2ymm)
ZEN5_FUNCDEF(vpshufhw,				xmmi2xmm)
ZEN5_FUNCDEF(vpshufhw,				ymmi2ymm)
ZEN5_FUNCDEF(vpshufd,				xmmi2xmm)
ZEN5_FUNCDEF(vpshufd,				ymmi2ymm)
ZEN5_FUNCDEF(vpalignr,				2xmmi2xmm)
ZEN5_FUNCDEF(vpalignr,				2ymmi2ymm)
ZEN5_FUNCDEF(vmovddup,				xmm2xmm)
ZEN5_FUNCDEF(vmovddup,				ymm2ymm)
ZEN5_FUNCDEF(vmovsldup,				xmm2xmm)
ZEN5_FUNCDEF(vmovsldup,				ymm2ymm)
ZEN5_FUNCDEF(vmovshdup,				xmm2xmm)
ZEN5_FUNCDEF(vmovshdup,				ymm2ymm)
ZEN5_FUNCDEF(vpbroadcastb,			xmm2xmm)
ZEN5_FUNCDEF(vpbroadcastw,			xmm2xmm)
ZEN5_FUNCDEF(vpbroadcastd,			xmm2xmm)
ZEN5_FUNCDEF(vpbroadcastq,			xmm2xmm)
ZEN5_FUNCDEF(vbroadcastss,			xmm2xmm)
ZEN5_FUNCDEF(vpmovzxbw,				xmm2xmm)
ZEN5_FUNCDEF(vpmovzxbd,				xmm2xmm)
ZEN5_FUNCDEF(vpmovzxbq,				xmm2xmm)
ZEN5_FUNCDEF(vpmovzxwd,				xmm2xmm)
ZEN5_FUNCDEF(vpmovzxwq,				xmm2xmm)
ZEN5_FUNCDEF(vpmovzxdq,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxbw,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxbd,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxbq,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxwd,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxwq,				xmm2xmm)
ZEN5_FUNCDEF(vpmovsxdq,				xmm2xmm)
ZEN5_FUNCDEF(vinsertps,				2xmmi2xmm)

ZEN5_FUNCDEF(vpmulhw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmulhw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmulhuw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmulhuw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmulhrsw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmulhrsw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmullw,				2xmm2xmm)
ZEN5_FUNCDEF(vpmullw,				2ymm2ymm)
ZEN5_FUNCDEF(vpmulld,				2xmm2xmm)
ZEN5_FUNCDEF(vpmulld,				2ymm2ymm)
ZEN5_FUNCDEF(vpmuldq,				2xmm2xmm)
ZEN5_FUNCDEF(vpmuldq,				2ymm2ymm)
ZEN5_FUNCDEF(vpmuludq,				2xmm2xmm)
ZEN5_FUNCDEF(vpmuludq,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaddwd,				2xmm2xmm)
ZEN5_FUNCDEF(vpmaddwd,				2ymm2ymm)
ZEN5_FUNCDEF(vpmaddubsw,			2xmm2xmm)
ZEN5_FUNCDEF(vpmaddubsw,			2ymm2ymm)
ZEN5_FUNCDEF(vpsadbw,				2xmm2xmm)
ZEN5_FUNCDEF(vpsadbw,				2ymm2ymm)

ZEN5_FUNCDEF(vinserti128,			xmmymmi02ymm)
ZEN5_FUNCDEF(vinsertf128,			xmmymmi02ymm)
ZEN5_FUNCDEF(vinserti128,			xmmymmi2ymm)
ZEN5_FUNCDEF(vinsertf128,			xmmymmi2ymm)
ZEN5_FUNCDEF(vinserti128,			m128ymmi02ymm)
ZEN5_FUNCDEF(vinsertf128,			m128ymmi02ymm)
ZEN5_FUNCDEF(vinserti128,			m128ymmi2ymm)
ZEN5_FUNCDEF(vinsertf128,			m128ymmi2ymm)
ZEN5_FUNCDEF(vextracti128,			ymmi02xmm)
ZEN5_FUNCDEF(vextractf128,			ymmi02xmm)
ZEN5_FUNCDEF(vextracti128,			ymmi2xmm)
ZEN5_FUNCDEF(vextractf128,			ymmi2xmm)
ZEN5_FUNCDEF(vextracti128,			ymmi02m128)
ZEN5_FUNCDEF(vextractf128,			ymmi02m128)
ZEN5_FUNCDEF(vextracti128,			ymmi2m128)
ZEN5_FUNCDEF(vextractf128,			ymmi2m128)
ZEN5_FUNCDEF(vperm2i128,			2ymmi2ymm)
ZEN5_FUNCDEF(vperm2f128,			2ymmi2ymm)
ZEN5_FUNCDEF(vperm2i128,			2ymmi102ymm)
ZEN5_FUNCDEF(vperm2f128,			2ymmi102ymm)
ZEN5_FUNCDEF(vperm2i128,			m256ymmi2ymm)
ZEN5_FUNCDEF(vperm2f128,			m256ymmi2ymm)
ZEN5_FUNCDEF(vpbroadcastq,			xmm2ymm)
ZEN5_FUNCDEF(vbroadcastsd,			xmm2ymm)
ZEN5_FUNCDEF(vpbroadcastb,			xmm2ymm)
ZEN5_FUNCDEF(vpbroadcastw,			xmm2ymm)
ZEN5_FUNCDEF(vpbroadcastd,			xmm2ymm)
ZEN5_FUNCDEF(vbroadcastss,			xmm2ymm)
ZEN5_FUNCDEF(vbroadcastss,			m32_2ymm)
ZEN5_FUNCDEF(vbroadcastsd,			m64_2ymm)
ZEN5_FUNCDEF(vpbroadcastb,			m8_2ymm)
ZEN5_FUNCDEF(vpbroadcastw,			m16_2ymm)
ZEN5_FUNCDEF(vpbroadcastd,			m32_2ymm)
ZEN5_FUNCDEF(vpbroadcastq,			m64_2ymm)

ZEN5_FUNCDEF(vdivpd,				2xmm2xmm2)
ZEN5_FUNCDEF(vdivpd,				2ymm2ymm2)
ZEN5_FUNCDEF(vdivps,				2xmm2xmm2)
ZEN5_FUNCDEF(vdivps,				2ymm2ymm2)
ZEN5_FUNCDEF(vdivsd,				2xmm2xmm2)
ZEN5_FUNCDEF(vdivss,				2xmm2xmm2)
ZEN5_FUNCDEF(vsqrtpd,				xmm2xmm1)
ZEN5_FUNCDEF(vsqrtpd,				ymm2ymm1)
ZEN5_FUNCDEF(vsqrtps,				xmm2xmm1)
ZEN5_FUNCDEF(vsqrtps,				ymm2ymm1)
ZEN5_FUNCDEF(vsqrtsd,				2xmm2xmm1)
ZEN5_FUNCDEF(vsqrtss,				2xmm2xmm1)

ZEN5_FUNCDEF(vmovd,					xmm2gpr32)
ZEN5_FUNCDEF(vmovd,					xmm2gpr64)
ZEN5_FUNCDEF(vmovd,					gpr32_2xmm)
ZEN5_FUNCDEF(vmovd,					gpr64_2xmm)
ZEN5_FUNCDEF(vpextrb,				xmmi2gpr32)
ZEN5_FUNCDEF(vpextrb,				xmmi2gpr64)
ZEN5_FUNCDEF(vpextrw,				xmmi2gpr32)
ZEN5_FUNCDEF(vpextrw,				xmmi2gpr64)
ZEN5_FUNCDEF(vpextrd,				xmmi2gpr32)
ZEN5_FUNCDEF(vpextrq,				xmmi2gpr64)
ZEN5_FUNCDEF(vpinsrb,				gpr32ixmm2xmm)
ZEN5_FUNCDEF(vpinsrw,				gpr32ixmm2xmm)
ZEN5_FUNCDEF(vpinsrd,				gpr32ixmm2xmm)
ZEN5_FUNCDEF(vpinsrq,				gpr64ixmm2xmm)
ZEN5_FUNCDEF(vcvtss2si,				xmm2gpr32)
ZEN5_FUNCDEF(vcvtss2si,				xmm2gpr64)
ZEN5_FUNCDEF(vcvtsd2si,				xmm2gpr32)
ZEN5_FUNCDEF(vcvtsd2si,				xmm2gpr64)
ZEN5_FUNCDEF(vcvtsi2ss,				gpr32xmm2xmm)
ZEN5_FUNCDEF(vcvtsi2ss,				gpr64xmm2xmm)
ZEN5_FUNCDEF(vcvtsi2sd,				gpr32xmm2xmm)
ZEN5_FUNCDEF(vcvtsi2sd,				gpr64xmm2xmm)
ZEN5_FUNCDEF(vextractps,			xmmi2gpr32)
ZEN5_FUNCDEF(vpmovmskb,				xmm2gpr32)
ZEN5_FUNCDEF(vpmovmskb,				xmm2gpr64)
ZEN5_FUNCDEF(vpmovmskb,				ymm2gpr32)
ZEN5_FUNCDEF(vpmovmskb,				ymm2gpr64)
ZEN5_FUNCDEF(vmovmskpd,				xmm2gpr32)
ZEN5_FUNCDEF(vmovmskpd,				xmm2gpr64)
ZEN5_FUNCDEF(vmovmskpd,				ymm2gpr32)
ZEN5_FUNCDEF(vmovmskpd,				ymm2gpr64)
ZEN5_FUNCDEF(vmovmskps,				xmm2gpr32)
ZEN5_FUNCDEF(vmovmskps,				xmm2gpr64)
ZEN5_FUNCDEF(vmovmskps,				ymm2gpr32)
ZEN5_FUNCDEF(vmovmskps,				ymm2gpr64)
ZEN5_FUNCDEF(vptest,				xmm2F)
ZEN5_FUNCDEF(vptest,				ymm2F)
ZEN5_FUNCDEF(vtestpd,				xmm2F)
ZEN5_FUNCDEF(vtestpd,				ymm2F)
ZEN5_FUNCDEF(vtestps,				xmm2F)
ZEN5_FUNCDEF(vtestps,				ymm2F)
ZEN5_FUNCDEF(vcomisd,				xmm2F)
ZEN5_FUNCDEF(vcomiss,				xmm2F)
ZEN5_FUNCDEF(vucomisd,				xmm2F)
ZEN5_FUNCDEF(vucomiss,				xmm2F)

ZEN5_FUNCDEF(vpermq,				ymmi2ymm)
ZEN5_FUNCDEF(vpermpd,				ymmi2ymm)
ZEN5_FUNCDEF(vpermd,				2ymm2ymm)
ZEN5_FUNCDEF(vpermps,				2ymm2ymm)
ZEN5_FUNCDEF(vpmovzxbw,				xmm2ymm)
ZEN5_FUNCDEF(vpmovzxbd,				xmm2ymm)
ZEN5_FUNCDEF(vpmovzxbq,				xmm2ymm)
ZEN5_FUNCDEF(vpmovzxwd,				xmm2ymm)
ZEN5_FUNCDEF(vpmovzxwq,				xmm2ymm)
ZEN5_FUNCDEF(vpmovzxdq,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxbw,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxbd,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxbq,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxwd,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxwq,				xmm2ymm)
ZEN5_FUNCDEF(vpmovsxdq,				xmm2ymm)
ZEN5_FUNCDEF(vcvtps2pd,				xmm2ymm)
ZEN5_FUNCDEF(vcvtpd2ps,				ymm2xmm)
ZEN5_FUNCDEF(vcvtdq2pd,				xmm2ymm)
ZEN5_FUNCDEF(vcvtpd2dq,				ymm2xmm)
ZEN5_FUNCDEF(vcvtph2ps,				xmm2ymm)
ZEN5_FUNCDEF(vcvtps2ph,				ymmi2xmm)

ZEN5_FUNCDEF(vhaddpd,				2xmm2xmm)
ZEN5_FUNCDEF(vhaddpd,				2ymm2ymm)
ZEN5_FUNCDEF(vhaddps,				2xmm2xmm)
ZEN5_FUNCDEF(vhaddps,				2ymm2ymm)
ZEN5_FUNCDEF(vhsubpd,				2xmm2xmm)
ZEN5_FUNCDEF(vhsubpd,				2ymm2ymm)
ZEN5_FUNCDEF(vhsubps,				2xmm2xmm)
ZEN5_FUNCDEF(vhsubps,				2ymm2ymm)

ZEN5_FUNCDEF(vphaddw,				2xmm2xmm)
ZEN5_FUNCDEF(vphaddw,				2ymm2ymm)
ZEN5_FUNCDEF(vphaddd,				2xmm2xmm)
ZEN5_FUNCDEF(vphaddd,				2ymm2ymm)
ZEN5_FUNCDEF(vphaddsw,				2xmm2xmm)
ZEN5_FUNCDEF(vphaddsw,				2ymm2ymm)
ZEN5_FUNCDEF(vphsubw,				2xmm2xmm)
ZEN5_FUNCDEF(vphsubw,				2ymm2ymm)
ZEN5_FUNCDEF(vphsubd,				2xmm2xmm)
ZEN5_FUNCDEF(vphsubd,				2ymm2ymm)
ZEN5_FUNCDEF(vphsubsw,				2xmm2xmm)
ZEN5_FUNCDEF(vphsubsw,				2ymm2ymm)

ZEN5_FUNCDEF(vdppd,					2xmmi2xmm)
ZEN5_FUNCDEF(vdpps,					2xmmi2xmm)
ZEN5_FUNCDEF(vdpps,					2ymmi2ymm)
ZEN5_FUNCDEF(vpclmulqdq,			2xmmi2xmm)
ZEN5_FUNCDEF(vpclmulqdq,			2ymmi2ymm)
ZEN5_FUNCDEF(vmpsadbw,				2xmmi2xmm)
ZEN5_FUNCDEF(vmpsadbw,				2ymmi2ymm)

