INCLUDE InstLatX64_PortMacros.h
INCLUDE InstLatX64_LatMacros.h
INCLUDE Zen5_Demo_Port.h

data SEGMENT PAGE
memop0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
data ENDS

.code 

test_m macro FUNC, M1, M2, INST, DOMAINSTART, DOMAINEND, R1, R2
LOCAL looptest
FUNC proc
	push			r15
	push			r14
	push			r13
	push			r12
	push			rbx
	push			rsi
	push			rdi

	vzeroupper

	xor				eax, eax
	cpuid
	rdtscp

	shl				rdx, 32
	or				rax, rdx
	mov				rsi, rax

	mov				r15, 100000
align 16
looptest:
	REPEAT R1
	M1
	endm
	REPEAT R2
	M2				INST, DOMAINSTART, DOMAINEND
	endm

	sub				r15, 1
	jnz				looptest

	xor				eax, eax
	cpuid
	rdtscp

	shl				rdx, 32
	or				rax, rdx
	sub				rax, rsi

	pop				rdi
	pop				rsi
	pop				rbx
	pop				r12
	pop				r13
	pop				r14
	pop				r15
	ret
FUNC endp
endm

zen5_wrap macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2
	test_m		Zen5_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1
	test_m		Zen5_&INST&_&OPERANDS&_tp,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			1,	1
endm

;				INST				OPERANDS			R1	R2
zen5_wrap		vmovaps,			xmm2xmm,			1,	1
zen5_wrap		vmovaps,			ymm2ymm,			1,	1
zen5_wrap		vmovapd,			xmm2xmm,			1,	1
zen5_wrap		vmovapd,			ymm2ymm,			1,	1
zen5_wrap		vmovups,			xmm2xmm,			1,	1
zen5_wrap		vmovups,			ymm2ymm,			1,	1
zen5_wrap		vmovupd,			xmm2xmm,			1,	1
zen5_wrap		vmovupd,			ymm2ymm,			1,	1
zen5_wrap		vmovdqa,			xmm2xmm,			1,	1
zen5_wrap		vmovdqa,			ymm2ymm,			1,	1
zen5_wrap		vmovdqu,			xmm2xmm,			1,	1
zen5_wrap		vmovdqu,			ymm2ymm,			1,	1
; Port01 2op
zen5_wrap		vmulpd,				2xmm2xmm,			1,	2
zen5_wrap		vmulpd,				2ymm2ymm,			1,	2
zen5_wrap		vmulps,				2xmm2xmm,			1,	2
zen5_wrap		vmulps,				2ymm2ymm,			1,	2
zen5_wrap		vmulsd,				2xmm2xmm,			1,	2
zen5_wrap		vmulss,				2xmm2xmm,			1,	2
zen5_wrap		vrcpps,				xmm2xmm,			1,	2
zen5_wrap		vrcpps,				ymm2ymm,			1,	2
zen5_wrap		vrcpss,				2xmm2xmm,			1,	2
zen5_wrap		vrsqrtps,			xmm2xmm,			1,	2
zen5_wrap		vrsqrtps,			ymm2ymm,			1,	2
zen5_wrap		vrsqrtss,			2xmm2xmm,			1,	2
zen5_wrap		vblendpd,			2xmmi2xmm,			1,	2
zen5_wrap		vblendpd,			2ymmi2ymm,			1,	2
; Port01 3op
zen5_wrap		vblendvpd,			3xmm2xmm,			1,	2
zen5_wrap		vblendvpd,			3ymm2ymm,			1,	2
zen5_wrap		vblendvps,			3xmm2xmm,			1,	2
zen5_wrap		vblendvps,			3ymm2ymm,			1,	2
zen5_wrap		vblendvpd,			3xmm2xmmRot,		1,	2
zen5_wrap		vblendvpd,			3ymm2ymmRot,		1,	2
zen5_wrap		vblendvps,			3xmm2xmmRot,		1,	2
zen5_wrap		vblendvps,			3ymm2ymmRot,		1,	2
zen5_wrap		vfmaddsub132pd,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub132pd,		2ymm2ymm,			1,	2
zen5_wrap		vfmaddsub132ps,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub132ps,		2ymm2ymm,			1,	2
zen5_wrap		vfmadd132sd,		2xmm2xmm,			1,	2
zen5_wrap		vfmadd132ss,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub213pd,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub213pd,		2ymm2ymm,			1,	2
zen5_wrap		vfmaddsub213ps,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub213ps,		2ymm2ymm,			1,	2
zen5_wrap		vfmadd213sd,		2xmm2xmm,			1,	2
zen5_wrap		vfmadd213ss,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub231pd,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub231pd,		2ymm2ymm,			1,	2
zen5_wrap		vfmaddsub231ps,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub231ps,		2ymm2ymm,			1,	2
zen5_wrap		vfmadd231sd,		2xmm2xmm,			1,	2
zen5_wrap		vfmadd231ss,		2xmm2xmm,			1,	2
zen5_wrap		vfmaddsub132pd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub132pd,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmaddsub132ps,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub132ps,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmadd132sd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmadd132ss,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub213pd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub213pd,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmaddsub213ps,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub213ps,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmadd213sd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmadd213ss,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub231pd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub231pd,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmaddsub231ps,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmaddsub231ps,		2ymm2ymmRot,		1,	2
zen5_wrap		vfmadd231sd,		2xmm2xmmRot,		1,	2
zen5_wrap		vfmadd231ss,		2xmm2xmmRot,		1,	2
; Port23 2op
zen5_wrap		vaddpd,				2xmm2xmm,			1,	2
zen5_wrap		vaddpd,				2ymm2ymm,			1,	2
zen5_wrap		vaddps,				2xmm2xmm,			1,	2
zen5_wrap		vaddps,				2ymm2ymm,			1,	2
zen5_wrap		vaddsd,				2xmm2xmm,			1,	2
zen5_wrap		vaddss,				2xmm2xmm,			1,	2
zen5_wrap		vsubpd,				2xmm2xmm,			1,	2
zen5_wrap		vsubpd,				2ymm2ymm,			1,	2
zen5_wrap		vsubps,				2xmm2xmm,			1,	2
zen5_wrap		vsubps,				2ymm2ymm,			1,	2
zen5_wrap		vsubsd,				2xmm2xmm,			1,	2
zen5_wrap		vsubss,				2xmm2xmm,			1,	2
zen5_wrap		vaddsubpd,			2xmm2xmm,			1,	2
zen5_wrap		vaddsubpd,			2ymm2ymm,			1,	2
zen5_wrap		vaddsubps,			2xmm2xmm,			1,	2
zen5_wrap		vaddsubps,			2ymm2ymm,			1,	2
zen5_wrap		vroundpd,			xmmi2xmm,			1,	2
zen5_wrap		vroundpd,			ymmi2ymm,			1,	2
zen5_wrap		vroundps,			xmmi2xmm,			1,	2
zen5_wrap		vroundps,			ymmi2ymm,			1,	2
zen5_wrap		vroundsd,			2xmmi2xmm,			1,	2
zen5_wrap		vroundss,			2xmmi2xmm,			1,	2
zen5_wrap		vcvtps2dq,			xmm2xmm,			1,	2
zen5_wrap		vcvtps2dq,			ymm2ymm,			1,	2
zen5_wrap		vcvtps2pd,			xmm2xmm,			1,	2
zen5_wrap		vcvtpd2ps,			xmm2xmm,			1,	2
zen5_wrap		vcvtpd2dq,			xmm2xmm,			1,	2
zen5_wrap		vcvtdq2pd,			xmm2xmm,			1,	2
zen5_wrap		vcvtdq2ps,			xmm2xmm,			1,	2
zen5_wrap		vcvtdq2ps,			ymm2ymm,			1,	2
zen5_wrap		vcvtps2ph,			xmmi2xmm,			1,	2
zen5_wrap		vcvtph2ps,			xmm2xmm,			1,	2
zen5_wrap		vcvtss2sd,			2xmm2xmm,			1,	2
zen5_wrap		vcvtsd2ss,			2xmm2xmm,			1,	2
zen5_wrap		vminpd,				2xmm2xmm,			1,	2
zen5_wrap		vminpd,				2ymm2ymm,			1,	2
zen5_wrap		vminps,				2xmm2xmm,			1,	2
zen5_wrap		vminps,				2ymm2ymm,			1,	2
zen5_wrap		vminsd,				2xmm2xmm,			1,	2
zen5_wrap		vminss,				2xmm2xmm,			1,	2
zen5_wrap		vmaxpd,				2xmm2xmm,			1,	2
zen5_wrap		vmaxpd,				2ymm2ymm,			1,	2
zen5_wrap		vmaxps,				2xmm2xmm,			1,	2
zen5_wrap		vmaxps,				2ymm2ymm,			1,	2
zen5_wrap		vmaxsd,				2xmm2xmm,			1,	2
zen5_wrap		vmaxss,				2xmm2xmm,			1,	2
zen5_wrap		vcmpeqpd,			2xmm2xmm,			1,	2
zen5_wrap		vcmpeqpd,			2ymm2ymm,			1,	2
zen5_wrap		vcmpeqps,			2xmm2xmm,			1,	2
zen5_wrap		vcmpeqps,			2ymm2ymm,			1,	2
zen5_wrap		vcmpeqsd,			2xmm2xmm,			1,	2
zen5_wrap		vcmpeqss,			2xmm2xmm,			1,	2
; Port0123 FP
zen5_wrap		vandpd,				2xmm2xmm,			1,	4
zen5_wrap		vandpd,				2ymm2ymm,			1,	4
zen5_wrap		vandps,				2xmm2xmm,			1,	4
zen5_wrap		vandps,				2ymm2ymm,			1,	4
zen5_wrap		vandnpd,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vandnpd,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vandnps,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vandnps,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vorpd,				2xmm2xmm,			1,	4
zen5_wrap		vorpd,				2ymm2ymm,			1,	4
zen5_wrap		vorps,				2xmm2xmm,			1,	4
zen5_wrap		vorps,				2ymm2ymm,			1,	4
zen5_wrap		vxorpd,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vxorpd,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vxorps,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vxorps,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vblendps,			2xmmi2xmm,			1,	4
zen5_wrap		vblendps,			2ymmi2ymm,			1,	4
; Port0123 Int
zen5_wrap		vpand,				2xmm2xmm,			1,	4
zen5_wrap		vpand,				2ymm2ymm,			1,	4
zen5_wrap		vpandn,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpandn,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpor,				2xmm2xmm,			1,	4
zen5_wrap		vpor,				2ymm2ymm,			1,	4
zen5_wrap		vpxor,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpxor,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpblendd,			2xmmi2xmm,			1,	4
zen5_wrap		vpblendd,			2ymmi2ymm,			1,	4
zen5_wrap		vpblendw,			2xmmi2xmm,			1,	4
zen5_wrap		vpblendw,			2ymmi2ymm,			1,	4

zen5_wrap		vpaddb,				2xmm2xmm,			1,	4
zen5_wrap		vpaddb,				2ymm2ymm,			1,	4
zen5_wrap		vpaddw,				2xmm2xmm,			1,	4
zen5_wrap		vpaddw,				2ymm2ymm,			1,	4
zen5_wrap		vpaddd,				2xmm2xmm,			1,	4
zen5_wrap		vpaddd,				2ymm2ymm,			1,	4
zen5_wrap		vpaddq,				2xmm2xmm,			1,	4
zen5_wrap		vpaddq,				2ymm2ymm,			1,	4
zen5_wrap		vpsubb,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubb,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubw,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubw,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubd,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubd,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubq,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpsubq,				2ymm2ymmRot,		1,	4	;Zeroing idiom

zen5_wrap		vpcmpeqb,			2xmm2xmmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpeqb,			2ymm2ymmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpeqw,			2xmm2xmmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpeqw,			2ymm2ymmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpeqd,			2xmm2xmmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpeqd,			2ymm2ymmRot,		1,	4	;Ones idiom
zen5_wrap		vpcmpgtb,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpcmpgtb,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpcmpgtw,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpcmpgtw,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpcmpgtd,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen5_wrap		vpcmpgtd,			2ymm2ymmRot,		1,	4	;Zeroing idiom

zen5_wrap		vpminsb,			2xmm2xmm,			1,	4
zen5_wrap		vpminsb,			2ymm2ymm,			1,	4
zen5_wrap		vpminub,			2xmm2xmm,			1,	4
zen5_wrap		vpminub,			2ymm2ymm,			1,	4
zen5_wrap		vpminsw,			2xmm2xmm,			1,	4
zen5_wrap		vpminsw,			2ymm2ymm,			1,	4
zen5_wrap		vpminuw,			2xmm2xmm,			1,	4
zen5_wrap		vpminuw,			2ymm2ymm,			1,	4
zen5_wrap		vpminsd,			2xmm2xmm,			1,	4
zen5_wrap		vpminsd,			2ymm2ymm,			1,	4
zen5_wrap		vpminud,			2xmm2xmm,			1,	4
zen5_wrap		vpminud,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxsb,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxsb,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxub,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxub,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxsw,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxsw,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxuw,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxuw,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxsd,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxsd,			2ymm2ymm,			1,	4
zen5_wrap		vpmaxud,			2xmm2xmm,			1,	4
zen5_wrap		vpmaxud,			2ymm2ymm,			1,	4
zen5_wrap		vpavgb,				2xmm2xmm,			1,	4
zen5_wrap		vpavgb,				2ymm2ymm,			1,	4
zen5_wrap		vpavgw,				2xmm2xmm,			1,	4
zen5_wrap		vpavgw,				2ymm2ymm,			1,	4
; Port01 Int
zen5_wrap		vpaddsb,			2xmm2xmm,			1,	2
zen5_wrap		vpaddsb,			2ymm2ymm,			1,	2
zen5_wrap		vpaddsw,			2xmm2xmm,			1,	2
zen5_wrap		vpaddsw,			2ymm2ymm,			1,	2
zen5_wrap		vpsubsb,			2xmm2xmmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpsubsb,			2ymm2ymmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpsubsw,			2xmm2xmmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpsubsw,			2ymm2ymmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpcmpeqq,			2xmm2xmmRot,		1,	2	;Ones idiom
zen5_wrap		vpcmpeqq,			2ymm2ymmRot,		1,	2	;Ones idiom
zen5_wrap		vpcmpgtq,			2xmm2xmmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpcmpgtq,			2ymm2ymmRot,		1,	2	;Zeroing idiom
zen5_wrap		vpabsb,				xmm2xmm,			1,	2
zen5_wrap		vpabsb,				ymm2ymm,			1,	2
zen5_wrap		vpabsw,				xmm2xmm,			1,	2
zen5_wrap		vpabsw,				ymm2ymm,			1,	2
zen5_wrap		vpabsd,				xmm2xmm,			1,	2
zen5_wrap		vpabsd,				ymm2ymm,			1,	2
zen5_wrap		vpsignb,			2xmm2xmm,			1,	2
zen5_wrap		vpsignb,			2ymm2ymm,			1,	2
zen5_wrap		vpsignw,			2xmm2xmm,			1,	2
zen5_wrap		vpsignw,			2ymm2ymm,			1,	2
zen5_wrap		vpsignd,			2xmm2xmm,			1,	2
zen5_wrap		vpsignd,			2ymm2ymm,			1,	2

zen5_wrap		vpsllw,				2xmm2xmm,			1,	2
zen5_wrap		vpsllw,				xmmymm2ymm,			1,	2
zen5_wrap		vpsrlw,				2xmm2xmm,			1,	2
zen5_wrap		vpsrlw,				xmmymm2ymm,			1,	2
zen5_wrap		vpsraw,				2xmm2xmm,			1,	2
zen5_wrap		vpsraw,				xmmymm2ymm,			1,	2
zen5_wrap		vpslld,				2xmm2xmm,			1,	2
zen5_wrap		vpslld,				xmmymm2ymm,			1,	2
zen5_wrap		vpsrld,				2xmm2xmm,			1,	2
zen5_wrap		vpsrld,				xmmymm2ymm,			1,	2
zen5_wrap		vpsrad,				2xmm2xmm,			1,	2
zen5_wrap		vpsrad,				xmmymm2ymm,			1,	2
zen5_wrap		vpsllq,				2xmm2xmm,			1,	2
zen5_wrap		vpsllq,				xmmymm2ymm,			1,	2
zen5_wrap		vpsrlq,				2xmm2xmm,			1,	2
zen5_wrap		vpsrlq,				xmmymm2ymm,			1,	2

zen5_wrap		vpmulhw,			2xmm2xmm,			1,	2
zen5_wrap		vpmulhw,			2ymm2ymm,			1,	2
zen5_wrap		vpmulhuw,			2xmm2xmm,			1,	2
zen5_wrap		vpmulhuw,			2ymm2ymm,			1,	2
zen5_wrap		vpmulhrsw,			2xmm2xmm,			1,	2
zen5_wrap		vpmulhrsw,			2ymm2ymm,			1,	2
zen5_wrap		vpmullw,			2xmm2xmm,			1,	2
zen5_wrap		vpmullw,			2ymm2ymm,			1,	2
zen5_wrap		vpmulld,			2xmm2xmm,			1,	2
zen5_wrap		vpmulld,			2ymm2ymm,			1,	2
zen5_wrap		vpmuldq,			2xmm2xmm,			1,	2
zen5_wrap		vpmuldq,			2ymm2ymm,			1,	2
zen5_wrap		vpmuludq,			2xmm2xmm,			1,	2
zen5_wrap		vpmuludq,			2ymm2ymm,			1,	2
zen5_wrap		vpmaddwd,			2xmm2xmm,			1,	2
zen5_wrap		vpmaddwd,			2ymm2ymm,			1,	2
zen5_wrap		vpmaddubsw,			2xmm2xmm,			1,	2
zen5_wrap		vpmaddubsw,			2ymm2ymm,			1,	2
zen5_wrap		vpsadbw,			2xmm2xmm,			1,	2
zen5_wrap		vpsadbw,			2ymm2ymm,			1,	2

zen5_wrap		vaesenc,			2xmm2xmm,			1,	2
zen5_wrap		vaesenc,			2ymm2ymm,			1,	2
zen5_wrap		vaesenclast,		2xmm2xmm,			1,	2
zen5_wrap		vaesenclast,		2ymm2ymm,			1,	2
zen5_wrap		vaesdec,			2xmm2xmm,			1,	2
zen5_wrap		vaesdec,			2ymm2ymm,			1,	2
zen5_wrap		vaesdeclast,		2xmm2xmm,			1,	2
zen5_wrap		vaesdeclast,		2ymm2ymm,			1,	2
zen5_wrap		vaesenc,			2xmm2xmmRot,		1,	2
zen5_wrap		vaesenc,			2ymm2ymmRot,		1,	2
zen5_wrap		vaesenclast,		2xmm2xmmRot,		1,	2
zen5_wrap		vaesenclast,		2ymm2ymmRot,		1,	2
zen5_wrap		vaesdec,			2xmm2xmmRot,		1,	2
zen5_wrap		vaesdec,			2ymm2ymmRot,		1,	2
zen5_wrap		vaesdeclast,		2xmm2xmmRot,		1,	2
zen5_wrap		vaesdeclast,		2ymm2ymmRot,		1,	2
zen5_wrap		vaesimc,			xmm2xmm,			1,	2
zen5_wrap		vaeskeygenassist,	xmmi2xmm,			1,	2
; Port23 Int
zen5_wrap		vpsllvd,			2xmm2xmm,			1,	2
zen5_wrap		vpsllvd,			2ymm2ymm,			1,	2
zen5_wrap		vpsrlvd,			2xmm2xmm,			1,	2
zen5_wrap		vpsrlvd,			2ymm2ymm,			1,	2
zen5_wrap		vpsravd,			2xmm2xmm,			1,	2
zen5_wrap		vpsravd,			2ymm2ymm,			1,	2
zen5_wrap		vpsllvq,			2xmm2xmm,			1,	2
zen5_wrap		vpsllvq,			2ymm2ymm,			1,	2
zen5_wrap		vpsrlvq,			2xmm2xmm,			1,	2
zen5_wrap		vpsrlvq,			2ymm2ymm,			1,	2
zen5_wrap		vpsllw,				xmmi2xmm,			1,	2
zen5_wrap		vpsllw,				ymmi2ymm,			1,	2
zen5_wrap		vpsrlw,				xmmi2xmm,			1,	2
zen5_wrap		vpsrlw,				ymmi2ymm,			1,	2
zen5_wrap		vpsraw,				xmmi2xmm,			1,	2
zen5_wrap		vpsraw,				ymmi2ymm,			1,	2
zen5_wrap		vpslld,				xmmi2xmm,			1,	2
zen5_wrap		vpslld,				ymmi2ymm,			1,	2
zen5_wrap		vpsrld,				xmmi2xmm,			1,	2
zen5_wrap		vpsrld,				ymmi2ymm,			1,	2
zen5_wrap		vpsrad,				xmmi2xmm,			1,	2
zen5_wrap		vpsrad,				ymmi2ymm,			1,	2
zen5_wrap		vpsllq,				xmmi2xmm,			1,	2
zen5_wrap		vpsllq,				ymmi2ymm,			1,	2
zen5_wrap		vpsrlq,				xmmi2xmm,			1,	2
zen5_wrap		vpsrlq,				ymmi2ymm,			1,	2
; Port12 Int 3 read op
zen5_wrap		vpblendvb,			3xmm2xmm,			1,	2
zen5_wrap		vpblendvb,			3ymm2ymm,			1,	2
zen5_wrap		vpblendvb,			3xmm2xmmRot,		1,	2
zen5_wrap		vpblendvb,			3ymm2ymmRot,		1,	2
; Port12 Int 2op
zen5_wrap		vphminposuw,		xmm2xmm,			1,	2
zen5_wrap		vpacksswb,			2xmm2xmm,			1,	2
zen5_wrap		vpacksswb,			2ymm2ymm,			1,	2
zen5_wrap		vpackuswb,			2xmm2xmm,			1,	2
zen5_wrap		vpackuswb,			2ymm2ymm,			1,	2
zen5_wrap		vpackssdw,			2xmm2xmm,			1,	2
zen5_wrap		vpackssdw,			2ymm2ymm,			1,	2
zen5_wrap		vpackusdw,			2xmm2xmm,			1,	2
zen5_wrap		vpackusdw,			2ymm2ymm,			1,	2
zen5_wrap		vpslldq,			xmmi2xmm,			1,	2
zen5_wrap		vpslldq,			ymmi2ymm,			1,	2
zen5_wrap		vpsrldq,			xmmi2xmm,			1,	2
zen5_wrap		vpsrldq,			ymmi2ymm,			1,	2
zen5_wrap		vpshufb,			2xmm2xmm,			1,	2
zen5_wrap		vpshufb,			2ymm2ymm,			1,	2
zen5_wrap		vpalignr,			2xmmi2xmm,			1,	2
zen5_wrap		vpalignr,			2ymmi2ymm,			1,	2
zen5_wrap		vpmovzxbw,			xmm2xmm,			1,	2
zen5_wrap		vpmovzxbd,			xmm2xmm,			1,	2
zen5_wrap		vpmovzxbq,			xmm2xmm,			1,	2
zen5_wrap		vpmovzxwd,			xmm2xmm,			1,	2
zen5_wrap		vpmovzxwq,			xmm2xmm,			1,	2
zen5_wrap		vpmovzxdq,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxbw,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxbd,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxbq,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxwd,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxwq,			xmm2xmm,			1,	2
zen5_wrap		vpmovsxdq,			xmm2xmm,			1,	2
zen5_wrap		vpermilpd,			2xmm2xmm,			1,	2
zen5_wrap		vpermilpd,			2ymm2ymm,			1,	2
zen5_wrap		vpermilps,			2xmm2xmm,			1,	2
zen5_wrap		vpermilps,			2ymm2ymm,			1,	2
zen5_wrap		vinserti128,		xmmymmi02ymm,		1,	2
zen5_wrap		vinsertf128,		xmmymmi02ymm,		1,	2
zen5_wrap		vinserti128,		xmmymmi2ymm,		1,	2
zen5_wrap		vinsertf128,		xmmymmi2ymm,		1,	2
zen5_wrap		vinserti128,		m128ymmi02ymm,		1,	2
zen5_wrap		vinsertf128,		m128ymmi02ymm,		1,	2
zen5_wrap		vinserti128,		m128ymmi2ymm,		1,	2
zen5_wrap		vinsertf128,		m128ymmi2ymm,		1,	2
zen5_wrap		vextracti128,		ymmi02xmm,			1,	2
zen5_wrap		vextractf128,		ymmi02xmm,			1,	2
zen5_wrap		vextracti128,		ymmi2xmm,			1,	2
zen5_wrap		vextractf128,		ymmi2xmm,			1,	2
zen5_wrap		vextracti128,		ymmi02m128,			1,	2
zen5_wrap		vextractf128,		ymmi02m128,			1,	2
zen5_wrap		vextracti128,		ymmi2m128,			1,	2
zen5_wrap		vextractf128,		ymmi2m128,			1,	2
zen5_wrap		vperm2i128,			2ymmi2ymm,			1,	2
zen5_wrap		vperm2f128,			2ymmi2ymm,			1,	2
zen5_wrap		vperm2i128,			2ymmi102ymm,		1,	2
zen5_wrap		vperm2f128,			2ymmi102ymm,		1,	2
zen5_wrap		vperm2i128,			m256ymmi2ymm,		1,	2
zen5_wrap		vperm2f128,			m256ymmi2ymm,		1,	2
zen5_wrap		vbroadcastss,		xmm2ymm,			1,	2
zen5_wrap		vbroadcastsd,		xmm2ymm,			1,	2
zen5_wrap		vpbroadcastb,		xmm2ymm,			1,	2
zen5_wrap		vpbroadcastw,		xmm2ymm,			1,	2
zen5_wrap		vpbroadcastd,		xmm2ymm,			1,	2
zen5_wrap		vpbroadcastq,		xmm2ymm,			1,	2
zen5_wrap		vbroadcastss,		m32_2ymm,			1,	2
zen5_wrap		vbroadcastsd,		m64_2ymm,			1,	2
zen5_wrap		vpbroadcastb,		m8_2ymm,			1,	2
zen5_wrap		vpbroadcastw,		m16_2ymm,			1,	2
zen5_wrap		vpbroadcastd,		m32_2ymm,			1,	2
zen5_wrap		vpbroadcastq,		m64_2ymm,			1,	2

;Port0123
zen5_wrap		vpermilpd,			xmmi2xmm,			1,	4
zen5_wrap		vpermilpd,			ymmi2ymm,			1,	4
zen5_wrap		vpermilps,			xmmi2xmm,			1,	4
zen5_wrap		vpermilps,			ymmi2ymm,			1,	4
zen5_wrap		vpbroadcastb,		xmm2xmm,			1,	4
zen5_wrap		vpbroadcastw,		xmm2xmm,			1,	4
zen5_wrap		vpbroadcastd,		xmm2xmm,			1,	4
zen5_wrap		vpbroadcastq,		xmm2xmm,			1,	4
zen5_wrap		vbroadcastss,		xmm2xmm,			1,	4
zen5_wrap		vpunpcklbw,			2xmm2xmm,			1,	4
zen5_wrap		vpunpcklbw,			2ymm2ymm,			1,	4
zen5_wrap		vpunpckhbw,			2xmm2xmm,			1,	4
zen5_wrap		vpunpckhbw,			2ymm2ymm,			1,	4
zen5_wrap		vpunpcklwd,			2xmm2xmm,			1,	4
zen5_wrap		vpunpcklwd,			2ymm2ymm,			1,	4
zen5_wrap		vpunpckhwd,			2xmm2xmm,			1,	4
zen5_wrap		vpunpckhwd,			2ymm2ymm,			1,	4
zen5_wrap		vpunpckldq,			2xmm2xmm,			1,	4
zen5_wrap		vpunpckldq,			2ymm2ymm,			1,	4
zen5_wrap		vpunpckhdq,			2xmm2xmm,			1,	4
zen5_wrap		vpunpckhdq,			2ymm2ymm,			1,	4
zen5_wrap		vpunpcklqdq,		2xmm2xmm,			1,	4
zen5_wrap		vpunpcklqdq,		2ymm2ymm,			1,	4
zen5_wrap		vpunpckhqdq,		2xmm2xmm,			1,	4
zen5_wrap		vpunpckhqdq,		2ymm2ymm,			1,	4
zen5_wrap		vunpcklps,			2xmm2xmm,			1,	4
zen5_wrap		vunpcklps,			2ymm2ymm,			1,	4
zen5_wrap		vunpckhps,			2xmm2xmm,			1,	4
zen5_wrap		vunpckhps,			2ymm2ymm,			1,	4
zen5_wrap		vunpcklpd,			2xmm2xmm,			1,	4
zen5_wrap		vunpcklpd,			2ymm2ymm,			1,	4
zen5_wrap		vunpckhpd,			2xmm2xmm,			1,	4
zen5_wrap		vunpckhpd,			2ymm2ymm,			1,	4
zen5_wrap		vmovhlps,			2xmm2xmm,			1,	4
zen5_wrap		vmovlhps,			2xmm2xmm,			1,	4
zen5_wrap		vshufpd,			2xmmi2xmm,			1,	4
zen5_wrap		vshufpd,			2ymmi2ymm,			1,	4
zen5_wrap		vshufps,			2xmmi2xmm,			1,	4
zen5_wrap		vshufps,			2ymmi2ymm,			1,	4
zen5_wrap		vpshuflw,			xmmi2xmm,			1,	4
zen5_wrap		vpshuflw,			ymmi2ymm,			1,	4
zen5_wrap		vpshufhw,			xmmi2xmm,			1,	4
zen5_wrap		vpshufhw,			ymmi2ymm,			1,	4
zen5_wrap		vpshufd,			xmmi2xmm,			1,	4
zen5_wrap		vpshufd,			ymmi2ymm,			1,	4
zen5_wrap		vmovddup,			xmm2xmm,			1,	4
zen5_wrap		vmovddup,			ymm2ymm,			1,	4
zen5_wrap		vmovsldup,			xmm2xmm,			1,	4
zen5_wrap		vmovsldup,			ymm2ymm,			1,	4
zen5_wrap		vmovshdup,			xmm2xmm,			1,	4
zen5_wrap		vmovshdup,			ymm2ymm,			1,	4
zen5_wrap		vinsertps,			2xmmi2xmm,			1,	4

zen5_wrap		vdivpd,				2xmm2xmm2,			1,	1
zen5_wrap		vdivpd,				2ymm2ymm2,			1,	1
zen5_wrap		vdivps,				2xmm2xmm2,			1,	1
zen5_wrap		vdivps,				2ymm2ymm2,			1,	1
zen5_wrap		vdivsd,				2xmm2xmm2,			1,	1
zen5_wrap		vdivss,				2xmm2xmm2,			1,	1
zen5_wrap		vsqrtpd,			xmm2xmm1,			2,	1
zen5_wrap		vsqrtpd,			ymm2ymm1,			2,	1
zen5_wrap		vsqrtps,			xmm2xmm1,			2,	1
zen5_wrap		vsqrtps,			ymm2ymm1,			2,	1
zen5_wrap		vsqrtsd,			2xmm2xmm1,			2,	1
zen5_wrap		vsqrtss,			2xmm2xmm1,			2,	1

zen5_wrap		vmovd,				xmm2gpr32,			1,	2
zen5_wrap		vmovd,				xmm2gpr64,			1,	2
zen5_wrap		vmovd,				gpr32_2xmm,			1,	1
zen5_wrap		vmovd,				gpr64_2xmm,			1,	1

zen5_wrap		vpextrb,			xmmi2gpr32,			1,	2
zen5_wrap		vpextrb,			xmmi2gpr64,			1,	2
zen5_wrap		vpextrw,			xmmi2gpr32,			1,	2
zen5_wrap		vpextrw,			xmmi2gpr64,			1,	2
zen5_wrap		vpextrd,			xmmi2gpr32,			1,	2
zen5_wrap		vpextrq,			xmmi2gpr64,			1,	2
zen5_wrap		vpinsrb,			gpr32ixmm2xmm,		1,	1
zen5_wrap		vpinsrw,			gpr32ixmm2xmm,		1,	1
zen5_wrap		vpinsrd,			gpr32ixmm2xmm,		1,	1
zen5_wrap		vpinsrq,			gpr64ixmm2xmm,		1,	1

zen5_wrap		vcvtss2si,			xmm2gpr32,			1,	2
zen5_wrap		vcvtss2si,			xmm2gpr64,			1,	2
zen5_wrap		vcvtsd2si,			xmm2gpr32,			1,	2
zen5_wrap		vcvtsd2si,			xmm2gpr64,			1,	2
zen5_wrap		vcvtsi2ss,			gpr32xmm2xmm,		1,	1
zen5_wrap		vcvtsi2ss,			gpr64xmm2xmm,		1,	1
zen5_wrap		vcvtsi2sd,			gpr32xmm2xmm,		1,	1
zen5_wrap		vcvtsi2sd,			gpr64xmm2xmm,		1,	1
zen5_wrap		vextractps,			xmmi2gpr32,			1,	1

zen5_wrap		vpmovmskb,			xmm2gpr32,			1,	2
zen5_wrap		vpmovmskb,			xmm2gpr64,			1,	2
zen5_wrap		vpmovmskb,			ymm2gpr32,			1,	2
zen5_wrap		vpmovmskb,			ymm2gpr64,			1,	2

zen5_wrap		vmovmskpd,			xmm2gpr32,			1,	2
zen5_wrap		vmovmskpd,			xmm2gpr64,			1,	2
zen5_wrap		vmovmskpd,			ymm2gpr32,			1,	2
zen5_wrap		vmovmskpd,			ymm2gpr64,			1,	2

zen5_wrap		vmovmskps,			xmm2gpr32,			1,	2
zen5_wrap		vmovmskps,			xmm2gpr64,			1,	2
zen5_wrap		vmovmskps,			ymm2gpr32,			1,	2
zen5_wrap		vmovmskps,			ymm2gpr64,			1,	2

zen5_wrap		vptest,				xmm2F,				1,	2
zen5_wrap		vptest,				ymm2F,				1,	2
zen5_wrap		vtestpd,			xmm2F,				1,	2
zen5_wrap		vtestpd,			ymm2F,				1,	2
zen5_wrap		vtestps,			xmm2F,				1,	2
zen5_wrap		vtestps,			ymm2F,				1,	2

zen5_wrap		vcomisd,			xmm2F,				1,	2
zen5_wrap		vcomiss,			xmm2F,				1,	2
zen5_wrap		vucomisd,			xmm2F,				1,	2
zen5_wrap		vucomiss,			xmm2F,				1,	2

zen5_wrap		vpermq,				ymmi2ymm,			1,	1
zen5_wrap		vpermpd,			ymmi2ymm,			1,	1
zen5_wrap		vpermd,				2ymm2ymm,			1,	1
zen5_wrap		vpermps,			2ymm2ymm,			1,	1
zen5_wrap		vpmovzxbw,			xmm2ymm,			1,	1
zen5_wrap		vpmovzxbd,			xmm2ymm,			1,	1
zen5_wrap		vpmovzxbq,			xmm2ymm,			1,	1
zen5_wrap		vpmovzxwd,			xmm2ymm,			1,	1
zen5_wrap		vpmovzxwq,			xmm2ymm,			1,	1
zen5_wrap		vpmovzxdq,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxbw,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxbd,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxbq,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxwd,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxwq,			xmm2ymm,			1,	1
zen5_wrap		vpmovsxdq,			xmm2ymm,			1,	1
zen5_wrap		vcvtps2pd,			xmm2ymm,			1,	1
zen5_wrap		vcvtpd2ps,			ymm2xmm,			1,	1
zen5_wrap		vcvtdq2pd,			xmm2ymm,			1,	1
zen5_wrap		vcvtpd2dq,			ymm2xmm,			1,	1
zen5_wrap		vcvtph2ps,			xmm2ymm,			1,	1
zen5_wrap		vcvtps2ph,			ymmi2xmm,			1,	1

zen5_wrap		vhaddpd,			2xmm2xmm,			1,	1
zen5_wrap		vhaddpd,			2ymm2ymm,			1,	1
zen5_wrap		vhaddps,			2xmm2xmm,			1,	1
zen5_wrap		vhaddps,			2ymm2ymm,			1,	1
zen5_wrap		vhsubpd,			2xmm2xmm,			1,	1
zen5_wrap		vhsubpd,			2ymm2ymm,			1,	1
zen5_wrap		vhsubps,			2xmm2xmm,			1,	1
zen5_wrap		vhsubps,			2ymm2ymm,			1,	1
zen5_wrap		vphaddw,			2xmm2xmm,			1,	1
zen5_wrap		vphaddw,			2ymm2ymm,			1,	1
zen5_wrap		vphaddd,			2xmm2xmm,			1,	1
zen5_wrap		vphaddd,			2ymm2ymm,			1,	1
zen5_wrap		vphaddsw,			2xmm2xmm,			1,	1
zen5_wrap		vphaddsw,			2ymm2ymm,			1,	1
zen5_wrap		vphsubw,			2xmm2xmm,			1,	1
zen5_wrap		vphsubw,			2ymm2ymm,			1,	1
zen5_wrap		vphsubd,			2xmm2xmm,			1,	1
zen5_wrap		vphsubd,			2ymm2ymm,			1,	1
zen5_wrap		vphsubsw,			2xmm2xmm,			1,	1
zen5_wrap		vphsubsw,			2ymm2ymm,			1,	1

zen5_wrap		vdppd,				2xmmi2xmm,			1,	1
zen5_wrap		vdpps,				2xmmi2xmm,			1,	1
zen5_wrap		vdpps,				2ymmi2ymm,			1,	1
zen5_wrap		vpclmulqdq,			2xmmi2xmm,			1,	1
zen5_wrap		vpclmulqdq,			2ymmi2ymm,			1,	1
zen5_wrap		vmpsadbw,			2xmmi2xmm,			1,	1
zen5_wrap		vmpsadbw,			2ymmi2ymm,			1,	1

end