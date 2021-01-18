INCLUDE InstLatX64_PortMacros.h
INCLUDE InstLatX64_LatMacros.h

.data

memop0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.code 

zen3_8clks_gpr_m macro
	REPEAT 8
	ror					r13, 1
	ror					r14, 1
	ENDM
endm

zen3_8clks_port0_m macro
	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
endm

zen3_8clks_port1_m macro
	fcom				st(7)
	fcom				st(6)
	fcom				st(5)
	fcom				st(4)
	fcom				st(3)
	fcom				st(2)
	fcom				st(1)
	fcom				st(0)
endm

zen3_8clks_port2_m macro
	vmovd				xmm0, eax
	vmovd				xmm1, edx
	vmovd				xmm2, ebx
	vmovd				xmm3, r8d
	vmovd				xmm4, r9d
	vmovd				xmm5, r10d
	vmovd				xmm6, r11d
	vmovd				xmm7, r12d
endm

zen3_8clks_port01_m macro
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
	vpabsd				ymm6, ymm6
	vpabsd				ymm7, ymm7
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
	vpabsd				ymm6, ymm6
	vpabsd				ymm7, ymm7
endm

zen3_8clks_port03_m macro
	vpmaddwd			ymm0, ymm0, ymm0
	vpmaddwd			ymm1, ymm1, ymm1
	vpmaddwd			ymm2, ymm2, ymm2
	vpmaddwd			ymm3, ymm3, ymm3
	vpmaddwd			ymm4, ymm4, ymm4
	vpmaddwd			ymm5, ymm5, ymm5
	vpmaddwd			ymm6, ymm6, ymm6
	vpmaddwd			ymm7, ymm7, ymm7
	vpmaddwd			ymm0, ymm0, ymm0
	vpmaddwd			ymm1, ymm1, ymm1
	vpmaddwd			ymm2, ymm2, ymm2
	vpmaddwd			ymm3, ymm3, ymm3
	vpmaddwd			ymm4, ymm4, ymm4
	vpmaddwd			ymm5, ymm5, ymm5
	vpmaddwd			ymm6, ymm6, ymm6
	vpmaddwd			ymm7, ymm7, ymm7
endm

zen3_8clks_port12_m macro
	vpermilpd			ymm0, ymm0, 0
	vpermilpd			ymm1, ymm1, 1
	vpermilpd			ymm2, ymm2, 0
	vpermilpd			ymm3, ymm3, 1
	vpermilpd			ymm4, ymm4, 0
	vpermilpd			ymm5, ymm5, 1
	vpermilpd			ymm6, ymm6, 0
	vpermilpd			ymm7, ymm7, 1
	vpermilpd			ymm0, ymm0, 0
	vpermilpd			ymm1, ymm1, 1
	vpermilpd			ymm2, ymm2, 0
	vpermilpd			ymm3, ymm3, 1
	vpermilpd			ymm4, ymm4, 0
	vpermilpd			ymm5, ymm5, 1
	vpermilpd			ymm6, ymm6, 0
	vpermilpd			ymm7, ymm7, 1
endm

zen3_8clks_port23_m macro
	vminpd				ymm0, ymm0, ymm0
	vminpd				ymm1, ymm1, ymm1
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm0, ymm0, ymm0
	vminpd				ymm1, ymm1, ymm1
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_8clks_port0123_m macro
	REPEAT 4
	vorpd				ymm0, ymm0, ymm0
	vorpd				ymm1, ymm1, ymm1
	vorpd				ymm2, ymm2, ymm2
	vorpd				ymm3, ymm3, ymm3
	vorpd				ymm4, ymm4, ymm4
	vorpd				ymm5, ymm5, ymm5
	vorpd				ymm6, ymm6, ymm6
	vorpd				ymm7, ymm7, ymm7
	endm
endm

zen3_8clks_port45_m macro
	vmovapd				[memop1 - 080h], ymm0
	vmovapd				[memop1 - 060h], ymm1
	vmovapd				[memop1 - 040h], ymm2
	vmovapd				[memop1 - 020h], ymm3
	vmovapd				[memop1 + 000h], ymm4
	vmovapd				[memop1 + 020h], ymm5
	vmovapd				[memop1 + 040h], ymm6
	vmovapd				[memop1 + 060h], ymm7
endm

zen3_8clks_LDs_m macro
	vmovapd				ymm0,	[memop1 - 080h] 
	vmovapd				ymm1,	[memop1 - 060h] 
	vmovapd				ymm2,	[memop1 - 040h] 
	vmovapd				ymm3,	[memop1 - 020h] 
	vmovapd				ymm4,	[memop1 + 000h] 
	vmovapd				ymm5,	[memop1 + 020h] 
	vmovapd				ymm6,	[memop1 + 040h] 
	vmovapd				ymm7,	[memop1 + 060h] 
	vmovapd				ymm0,	[memop1 + 080h] 
	vmovapd				ymm1,	[memop1 + 0A0h] 
	vmovapd				ymm2,	[memop1 + 0C0h] 
	vmovapd				ymm3,	[memop1 + 0E0h] 
	vmovapd				ymm4,	[memop1 + 100h] 
	vmovapd				ymm5,	[memop1 + 120h] 
	vmovapd				ymm6,	[memop1 + 140h] 
	vmovapd				ymm7,	[memop1 + 160h] 
endm

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

	finit
	fld1
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

zen3_wrap macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2
	test_m		Zen3_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1
	test_m		Zen3_&INST&_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 1,			1,			1,	1
	test_m		Zen3_&INST&_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 2,			2,			1,	1
	test_m		Zen3_&INST&_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 1,			2,			1,	1
	test_m		Zen3_&INST&_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 2,			1,			1,	1
	test_m		Zen3_&INST&_&OPERANDS&_gpr,			zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port01,		zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port03,		zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port12,		zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port23,		zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_port45,		zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
	test_m		Zen3_&INST&_&OPERANDS&_LDs,			zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2
endm

;				INST				OPERANDS			R1	R2
zen3_wrap		vmulpd,				2xmm2xmm,			1,	2
zen3_wrap		vmulpd,				2ymm2ymm,			1,	2
zen3_wrap		vmulps,				2xmm2xmm,			1,	2
zen3_wrap		vmulps,				2ymm2ymm,			1,	2
zen3_wrap		vmulsd,				2xmm2xmm,			1,	2
zen3_wrap		vmulss,				2xmm2xmm,			1,	2
zen3_wrap		vrcpps,				xmm2xmm,			1,	2
zen3_wrap		vrcpps,				ymm2ymm,			1,	2
zen3_wrap		vrcpss,				2xmm2xmm,			1,	2
zen3_wrap		vrsqrtps,			xmm2xmm,			1,	2
zen3_wrap		vrsqrtps,			ymm2ymm,			1,	2
zen3_wrap		vrsqrtss,			2xmm2xmm,			1,	2
zen3_wrap		vpblendvb,			3xmm2xmm,			1,	2
zen3_wrap		vpblendvb,			3ymm2ymm,			1,	2
zen3_wrap		vblendvpd,			3xmm2xmm,			1,	2
zen3_wrap		vblendvpd,			3ymm2ymm,			1,	2
zen3_wrap		vblendvps,			3xmm2xmm,			1,	2
zen3_wrap		vblendvps,			3ymm2ymm,			1,	2
zen3_wrap		vpblendvb,			3xmm2xmmRot,		1,	2
zen3_wrap		vpblendvb,			3ymm2ymmRot,		1,	2
zen3_wrap		vblendvpd,			3xmm2xmmRot,		1,	2
zen3_wrap		vblendvpd,			3ymm2ymmRot,		1,	2
zen3_wrap		vblendvps,			3xmm2xmmRot,		1,	2
zen3_wrap		vblendvps,			3ymm2ymmRot,		1,	2
zen3_wrap		vfmaddsub132pd,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub132pd,		2ymm2ymm,			1,	2
zen3_wrap		vfmaddsub132ps,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub132ps,		2ymm2ymm,			1,	2
zen3_wrap		vfmadd132sd,		2xmm2xmm,			1,	2
zen3_wrap		vfmadd132ss,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub213pd,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub213pd,		2ymm2ymm,			1,	2
zen3_wrap		vfmaddsub213ps,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub213ps,		2ymm2ymm,			1,	2
zen3_wrap		vfmadd213sd,		2xmm2xmm,			1,	2
zen3_wrap		vfmadd213ss,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub231pd,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub231pd,		2ymm2ymm,			1,	2
zen3_wrap		vfmaddsub231ps,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub231ps,		2ymm2ymm,			1,	2
zen3_wrap		vfmadd231sd,		2xmm2xmm,			1,	2
zen3_wrap		vfmadd231ss,		2xmm2xmm,			1,	2
zen3_wrap		vfmaddsub132pd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub132pd,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmaddsub132ps,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub132ps,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmadd132sd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmadd132ss,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub213pd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub213pd,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmaddsub213ps,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub213ps,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmadd213sd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmadd213ss,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub231pd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub231pd,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmaddsub231ps,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmaddsub231ps,		2ymm2ymmRot,		1,	2
zen3_wrap		vfmadd231sd,		2xmm2xmmRot,		1,	2
zen3_wrap		vfmadd231ss,		2xmm2xmmRot,		1,	2

zen3_wrap		vaddpd,				2xmm2xmm,			1,	2
zen3_wrap		vaddpd,				2ymm2ymm,			1,	2
zen3_wrap		vaddps,				2xmm2xmm,			1,	2
zen3_wrap		vaddps,				2ymm2ymm,			1,	2
zen3_wrap		vaddsd,				2xmm2xmm,			1,	2
zen3_wrap		vaddss,				2xmm2xmm,			1,	2
zen3_wrap		vsubpd,				2xmm2xmm,			1,	2
zen3_wrap		vsubpd,				2ymm2ymm,			1,	2
zen3_wrap		vsubps,				2xmm2xmm,			1,	2
zen3_wrap		vsubps,				2ymm2ymm,			1,	2
zen3_wrap		vsubsd,				2xmm2xmm,			1,	2
zen3_wrap		vsubss,				2xmm2xmm,			1,	2
zen3_wrap		vaddsubpd,			2xmm2xmm,			1,	2
zen3_wrap		vaddsubpd,			2ymm2ymm,			1,	2
zen3_wrap		vaddsubps,			2xmm2xmm,			1,	2
zen3_wrap		vaddsubps,			2ymm2ymm,			1,	2
zen3_wrap		vroundpd,			xmmi2xmm,			1,	2
zen3_wrap		vroundpd,			ymmi2ymm,			1,	2
zen3_wrap		vroundps,			xmmi2xmm,			1,	2
zen3_wrap		vroundps,			ymmi2ymm,			1,	2
zen3_wrap		vroundsd,			2xmmi2xmm,			1,	2
zen3_wrap		vroundss,			2xmmi2xmm,			1,	2
zen3_wrap		vcvtps2dq,			xmm2xmm,			1,	2
zen3_wrap		vcvtps2dq,			ymm2ymm,			1,	2
zen3_wrap		vcvtps2pd,			xmm2xmm,			1,	2
zen3_wrap		vcvtpd2ps,			xmm2xmm,			1,	2
zen3_wrap		vcvtpd2dq,			xmm2xmm,			1,	2
zen3_wrap		vcvtdq2pd,			xmm2xmm,			1,	2
zen3_wrap		vcvtdq2ps,			xmm2xmm,			1,	2
zen3_wrap		vcvtdq2ps,			ymm2ymm,			1,	2
zen3_wrap		vcvtps2ph,			xmmi2xmm,			1,	2
zen3_wrap		vcvtph2ps,			xmm2xmm,			1,	2
zen3_wrap		vcvtss2sd,			2xmm2xmm,			1,	2
zen3_wrap		vcvtsd2ss,			2xmm2xmm,			1,	2

zen3_wrap		vminpd,				2xmm2xmm,			1,	2
zen3_wrap		vminpd,				2ymm2ymm,			1,	2
zen3_wrap		vminps,				2xmm2xmm,			1,	2
zen3_wrap		vminps,				2ymm2ymm,			1,	2
zen3_wrap		vminsd,				2xmm2xmm,			1,	2
zen3_wrap		vminss,				2xmm2xmm,			1,	2
zen3_wrap		vmaxpd,				2xmm2xmm,			1,	2
zen3_wrap		vmaxpd,				2ymm2ymm,			1,	2
zen3_wrap		vmaxps,				2xmm2xmm,			1,	2
zen3_wrap		vmaxps,				2ymm2ymm,			1,	2
zen3_wrap		vmaxsd,				2xmm2xmm,			1,	2
zen3_wrap		vmaxss,				2xmm2xmm,			1,	2
zen3_wrap		vcmpeqpd,			2xmm2xmm,			1,	2
zen3_wrap		vcmpeqpd,			2ymm2ymm,			1,	2
zen3_wrap		vcmpeqps,			2xmm2xmm,			1,	2
zen3_wrap		vcmpeqps,			2ymm2ymm,			1,	2
zen3_wrap		vcmpeqsd,			2xmm2xmm,			1,	2
zen3_wrap		vcmpeqss,			2xmm2xmm,			1,	2

zen3_wrap		vandpd,				2xmm2xmm,			1,	4
zen3_wrap		vandpd,				2ymm2ymm,			1,	4
zen3_wrap		vandps,				2xmm2xmm,			1,	4
zen3_wrap		vandps,				2ymm2ymm,			1,	4
zen3_wrap		vandnpd,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vandnpd,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vandnps,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vandnps,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vorpd,				2xmm2xmm,			1,	4
zen3_wrap		vorpd,				2ymm2ymm,			1,	4
zen3_wrap		vorps,				2xmm2xmm,			1,	4
zen3_wrap		vorps,				2ymm2ymm,			1,	4
zen3_wrap		vxorpd,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vxorpd,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vxorps,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vxorps,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vblendpd,			2xmmi2xmm,			1,	4
zen3_wrap		vblendpd,			2ymmi2ymm,			1,	4
zen3_wrap		vblendps,			2xmmi2xmm,			1,	4
zen3_wrap		vblendps,			2ymmi2ymm,			1,	4

zen3_wrap		vpand,				2xmm2xmm,			1,	4
zen3_wrap		vpand,				2ymm2ymm,			1,	4
zen3_wrap		vpandn,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpandn,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpor,				2xmm2xmm,			1,	4
zen3_wrap		vpor,				2ymm2ymm,			1,	4
zen3_wrap		vpxor,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpxor,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpblendd,			2xmmi2xmm,			1,	4
zen3_wrap		vpblendd,			2ymmi2ymm,			1,	4
zen3_wrap		vpblendw,			2xmmi2xmm,			1,	4
zen3_wrap		vpblendw,			2ymmi2ymm,			1,	4

zen3_wrap		vpaddb,				2xmm2xmm,			1,	4
zen3_wrap		vpaddb,				2ymm2ymm,			1,	4
zen3_wrap		vpaddw,				2xmm2xmm,			1,	4
zen3_wrap		vpaddw,				2ymm2ymm,			1,	4
zen3_wrap		vpaddd,				2xmm2xmm,			1,	4
zen3_wrap		vpaddd,				2ymm2ymm,			1,	4
zen3_wrap		vpaddq,				2xmm2xmm,			1,	4
zen3_wrap		vpaddq,				2ymm2ymm,			1,	4
zen3_wrap		vpsubb,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubb,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubw,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubw,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubd,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubd,				2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubq,				2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpsubq,				2ymm2ymmRot,		1,	4	;Zeroing idiom

zen3_wrap		vpcmpeqb,			2xmm2xmmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpeqb,			2ymm2ymmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpeqw,			2xmm2xmmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpeqw,			2ymm2ymmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpeqd,			2xmm2xmmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpeqd,			2ymm2ymmRot,		1,	4	;Ones idiom
zen3_wrap		vpcmpgtb,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtb,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtw,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtw,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtd,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtd,			2ymm2ymmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtq,			2xmm2xmmRot,		1,	4	;Zeroing idiom
zen3_wrap		vpcmpgtq,			2ymm2ymmRot,		1,	4	;Zeroing idiom

zen3_wrap		vpminsb,			2xmm2xmm,			1,	4
zen3_wrap		vpminsb,			2ymm2ymm,			1,	4
zen3_wrap		vpminub,			2xmm2xmm,			1,	4
zen3_wrap		vpminub,			2ymm2ymm,			1,	4
zen3_wrap		vpminsw,			2xmm2xmm,			1,	4
zen3_wrap		vpminsw,			2ymm2ymm,			1,	4
zen3_wrap		vpminuw,			2xmm2xmm,			1,	4
zen3_wrap		vpminuw,			2ymm2ymm,			1,	4
zen3_wrap		vpminsd,			2xmm2xmm,			1,	4
zen3_wrap		vpminsd,			2ymm2ymm,			1,	4
zen3_wrap		vpminud,			2xmm2xmm,			1,	4
zen3_wrap		vpminud,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxsb,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxsb,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxub,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxub,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxsw,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxsw,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxuw,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxuw,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxsd,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxsd,			2ymm2ymm,			1,	4
zen3_wrap		vpmaxud,			2xmm2xmm,			1,	4
zen3_wrap		vpmaxud,			2ymm2ymm,			1,	4

zen3_wrap		vpaddsb,			2xmm2xmm,			1,	2
zen3_wrap		vpaddsb,			2ymm2ymm,			1,	2
zen3_wrap		vpaddsw,			2xmm2xmm,			1,	2
zen3_wrap		vpaddsw,			2ymm2ymm,			1,	2
zen3_wrap		vpsubsb,			2xmm2xmmRot,		1,	2	;Zeroing idiom
zen3_wrap		vpsubsb,			2ymm2ymmRot,		1,	2	;Zeroing idiom
zen3_wrap		vpsubsw,			2xmm2xmmRot,		1,	2	;Zeroing idiom
zen3_wrap		vpsubsw,			2ymm2ymmRot,		1,	2	;Zeroing idiom
zen3_wrap		vpcmpeqq,			2xmm2xmmRot,		1,	2	;Ones idiom
zen3_wrap		vpcmpeqq,			2ymm2ymmRot,		1,	2	;Ones idiom
zen3_wrap		vpabsb,				xmm2xmm,			1,	2
zen3_wrap		vpabsb,				ymm2ymm,			1,	2
zen3_wrap		vpabsw,				xmm2xmm,			1,	2
zen3_wrap		vpabsw,				ymm2ymm,			1,	2
zen3_wrap		vpabsd,				xmm2xmm,			1,	2
zen3_wrap		vpabsd,				ymm2ymm,			1,	2
zen3_wrap		vpavgb,				2xmm2xmm,			1,	2
zen3_wrap		vpavgb,				2ymm2ymm,			1,	2
zen3_wrap		vpavgw,				2xmm2xmm,			1,	2
zen3_wrap		vpavgw,				2ymm2ymm,			1,	2
zen3_wrap		vpsignb,			2xmm2xmm,			1,	2
zen3_wrap		vpsignb,			2ymm2ymm,			1,	2
zen3_wrap		vpsignw,			2xmm2xmm,			1,	2
zen3_wrap		vpsignw,			2ymm2ymm,			1,	2
zen3_wrap		vpsignd,			2xmm2xmm,			1,	2
zen3_wrap		vpsignd,			2ymm2ymm,			1,	2

zen3_wrap		vaesenc,			2xmm2xmm,			1,	2
zen3_wrap		vaesenc,			2ymm2ymm,			1,	2
zen3_wrap		vaesenclast,		2xmm2xmm,			1,	2
zen3_wrap		vaesenclast,		2ymm2ymm,			1,	2
zen3_wrap		vaesdec,			2xmm2xmm,			1,	2
zen3_wrap		vaesdec,			2ymm2ymm,			1,	2
zen3_wrap		vaesdeclast,		2xmm2xmm,			1,	2
zen3_wrap		vaesdeclast,		2ymm2ymm,			1,	2
zen3_wrap		vaesenc,			2xmm2xmmRot,		1,	2
zen3_wrap		vaesenc,			2ymm2ymmRot,		1,	2
zen3_wrap		vaesenclast,		2xmm2xmmRot,		1,	2
zen3_wrap		vaesenclast,		2ymm2ymmRot,		1,	2
zen3_wrap		vaesdec,			2xmm2xmmRot,		1,	2
zen3_wrap		vaesdec,			2ymm2ymmRot,		1,	2
zen3_wrap		vaesdeclast,		2xmm2xmmRot,		1,	2
zen3_wrap		vaesdeclast,		2ymm2ymmRot,		1,	2
zen3_wrap		vaesimc,			xmm2xmm,			1,	2
zen3_wrap		vaeskeygenassist,	xmmi2xmm,			1,	2
zen3_wrap		vphminposuw,		xmm2xmm,			1,	2
zen3_wrap		vpermilpd,			2xmm2xmm,			1,	2
zen3_wrap		vpermilpd,			2ymm2ymm,			1,	2
zen3_wrap		vpermilps,			2xmm2xmm,			1,	2
zen3_wrap		vpermilps,			2ymm2ymm,			1,	2

zen3_wrap		vpsllvd,			2xmm2xmm,			1,	2
zen3_wrap		vpsllvd,			2ymm2ymm,			1,	2
zen3_wrap		vpsrlvd,			2xmm2xmm,			1,	2
zen3_wrap		vpsrlvd,			2ymm2ymm,			1,	2
zen3_wrap		vpsravd,			2xmm2xmm,			1,	2
zen3_wrap		vpsravd,			2ymm2ymm,			1,	2
zen3_wrap		vpsllvq,			2xmm2xmm,			1,	2
zen3_wrap		vpsllvq,			2ymm2ymm,			1,	2
zen3_wrap		vpsrlvq,			2xmm2xmm,			1,	2
zen3_wrap		vpsrlvq,			2ymm2ymm,			1,	2

zen3_wrap		vpsllw,				2xmm2xmm,			1,	2
zen3_wrap		vpsllw,				xmmymm2ymm,			1,	2
zen3_wrap		vpsrlw,				2xmm2xmm,			1,	2
zen3_wrap		vpsrlw,				xmmymm2ymm,			1,	2
zen3_wrap		vpsraw,				2xmm2xmm,			1,	2
zen3_wrap		vpsraw,				xmmymm2ymm,			1,	2
zen3_wrap		vpslld,				2xmm2xmm,			1,	2
zen3_wrap		vpslld,				xmmymm2ymm,			1,	2
zen3_wrap		vpsrld,				2xmm2xmm,			1,	2
zen3_wrap		vpsrld,				xmmymm2ymm,			1,	2
zen3_wrap		vpsrad,				2xmm2xmm,			1,	2
zen3_wrap		vpsrad,				xmmymm2ymm,			1,	2
zen3_wrap		vpsllq,				2xmm2xmm,			1,	2
zen3_wrap		vpsllq,				xmmymm2ymm,			1,	2
zen3_wrap		vpsrlq,				2xmm2xmm,			1,	2
zen3_wrap		vpsrlq,				xmmymm2ymm,			1,	2

zen3_wrap		vpsllw,				xmmi2xmm,			1,	2
zen3_wrap		vpsllw,				ymmi2ymm,			1,	2
zen3_wrap		vpsrlw,				xmmi2xmm,			1,	2
zen3_wrap		vpsrlw,				ymmi2ymm,			1,	2
zen3_wrap		vpsraw,				xmmi2xmm,			1,	2
zen3_wrap		vpsraw,				ymmi2ymm,			1,	2
zen3_wrap		vpslld,				xmmi2xmm,			1,	2
zen3_wrap		vpslld,				ymmi2ymm,			1,	2
zen3_wrap		vpsrld,				xmmi2xmm,			1,	2
zen3_wrap		vpsrld,				ymmi2ymm,			1,	2
zen3_wrap		vpsrad,				xmmi2xmm,			1,	2
zen3_wrap		vpsrad,				ymmi2ymm,			1,	2
zen3_wrap		vpsllq,				xmmi2xmm,			1,	2
zen3_wrap		vpsllq,				ymmi2ymm,			1,	2
zen3_wrap		vpsrlq,				xmmi2xmm,			1,	2
zen3_wrap		vpsrlq,				ymmi2ymm,			1,	2

zen3_wrap		vpslldq,			xmmi2xmm,			1,	2
zen3_wrap		vpslldq,			ymmi2ymm,			1,	2
zen3_wrap		vpsrldq,			xmmi2xmm,			1,	2
zen3_wrap		vpsrldq,			ymmi2ymm,			1,	2

zen3_wrap		vpunpcklbw,			2xmm2xmm,			1,	2
zen3_wrap		vpunpcklbw,			2ymm2ymm,			1,	2
zen3_wrap		vpunpckhbw,			2xmm2xmm,			1,	2
zen3_wrap		vpunpckhbw,			2ymm2ymm,			1,	2
zen3_wrap		vpunpcklwd,			2xmm2xmm,			1,	2
zen3_wrap		vpunpcklwd,			2ymm2ymm,			1,	2
zen3_wrap		vpunpckhwd,			2xmm2xmm,			1,	2
zen3_wrap		vpunpckhwd,			2ymm2ymm,			1,	2
zen3_wrap		vpunpckldq,			2xmm2xmm,			1,	2
zen3_wrap		vpunpckldq,			2ymm2ymm,			1,	2
zen3_wrap		vpunpckhdq,			2xmm2xmm,			1,	2
zen3_wrap		vpunpckhdq,			2ymm2ymm,			1,	2
zen3_wrap		vpunpcklqdq,		2xmm2xmm,			1,	2
zen3_wrap		vpunpcklqdq,		2ymm2ymm,			1,	2
zen3_wrap		vpunpckhqdq,		2xmm2xmm,			1,	2
zen3_wrap		vpunpckhqdq,		2ymm2ymm,			1,	2
zen3_wrap		vunpcklps,			2xmm2xmm,			1,	2
zen3_wrap		vunpcklps,			2ymm2ymm,			1,	2
zen3_wrap		vunpckhps,			2xmm2xmm,			1,	2
zen3_wrap		vunpckhps,			2ymm2ymm,			1,	2
zen3_wrap		vunpcklpd,			2xmm2xmm,			1,	2
zen3_wrap		vunpcklpd,			2ymm2ymm,			1,	2
zen3_wrap		vunpckhpd,			2xmm2xmm,			1,	2
zen3_wrap		vunpckhpd,			2ymm2ymm,			1,	2
zen3_wrap		vmovhlps,			2xmm2xmm,			1,	2
zen3_wrap		vmovlhps,			2xmm2xmm,			1,	2
zen3_wrap		vpacksswb,			2xmm2xmm,			1,	2
zen3_wrap		vpacksswb,			2ymm2ymm,			1,	2
zen3_wrap		vpackuswb,			2xmm2xmm,			1,	2
zen3_wrap		vpackuswb,			2ymm2ymm,			1,	2
zen3_wrap		vpackssdw,			2xmm2xmm,			1,	2
zen3_wrap		vpackssdw,			2ymm2ymm,			1,	2
zen3_wrap		vpackusdw,			2xmm2xmm,			1,	2
zen3_wrap		vpackusdw,			2ymm2ymm,			1,	2
zen3_wrap		vpermilpd,			xmmi2xmm,			1,	2
zen3_wrap		vpermilpd,			ymmi2ymm,			1,	2
zen3_wrap		vpermilps,			xmmi2xmm,			1,	2
zen3_wrap		vpermilps,			ymmi2ymm,			1,	2
zen3_wrap		vshufpd,			2xmmi2xmm,			1,	2
zen3_wrap		vshufpd,			2ymmi2ymm,			1,	2
zen3_wrap		vshufps,			2xmmi2xmm,			1,	2
zen3_wrap		vshufps,			2ymmi2ymm,			1,	2
zen3_wrap		vpshufb,			2xmm2xmm,			1,	2
zen3_wrap		vpshufb,			2ymm2ymm,			1,	2
zen3_wrap		vpshuflw,			xmmi2xmm,			1,	2
zen3_wrap		vpshuflw,			ymmi2ymm,			1,	2
zen3_wrap		vpshufhw,			xmmi2xmm,			1,	2
zen3_wrap		vpshufhw,			ymmi2ymm,			1,	2
zen3_wrap		vpshufd,			xmmi2xmm,			1,	2
zen3_wrap		vpshufd,			ymmi2ymm,			1,	2
zen3_wrap		vpalignr,			2xmmi2xmm,			1,	2
zen3_wrap		vpalignr,			2ymmi2ymm,			1,	2
zen3_wrap		vmovddup,			xmm2xmm,			1,	2
zen3_wrap		vmovddup,			ymm2ymm,			1,	2
zen3_wrap		vmovsldup,			xmm2xmm,			1,	2
zen3_wrap		vmovsldup,			ymm2ymm,			1,	2
zen3_wrap		vmovshdup,			xmm2xmm,			1,	2
zen3_wrap		vmovshdup,			ymm2ymm,			1,	2
zen3_wrap		vpbroadcastb,		xmm2xmm,			1,	2
zen3_wrap		vpbroadcastw,		xmm2xmm,			1,	2
zen3_wrap		vpbroadcastd,		xmm2xmm,			1,	2
zen3_wrap		vpbroadcastq,		xmm2xmm,			1,	2
zen3_wrap		vbroadcastss,		xmm2xmm,			1,	2
zen3_wrap		vpmovzxbw,			xmm2xmm,			1,	2
zen3_wrap		vpmovzxbd,			xmm2xmm,			1,	2
zen3_wrap		vpmovzxbq,			xmm2xmm,			1,	2
zen3_wrap		vpmovzxwd,			xmm2xmm,			1,	2
zen3_wrap		vpmovzxwq,			xmm2xmm,			1,	2
zen3_wrap		vpmovzxdq,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxbw,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxbd,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxbq,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxwd,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxwq,			xmm2xmm,			1,	2
zen3_wrap		vpmovsxdq,			xmm2xmm,			1,	2
zen3_wrap		vinsertps,			2xmmi2xmm,			1,	2

zen3_wrap		vpmulhw,			2xmm2xmm,			1,	2
zen3_wrap		vpmulhw,			2ymm2ymm,			1,	2
zen3_wrap		vpmulhuw,			2xmm2xmm,			1,	2
zen3_wrap		vpmulhuw,			2ymm2ymm,			1,	2
zen3_wrap		vpmulhrsw,			2xmm2xmm,			1,	2
zen3_wrap		vpmulhrsw,			2ymm2ymm,			1,	2
zen3_wrap		vpmullw,			2xmm2xmm,			1,	2
zen3_wrap		vpmullw,			2ymm2ymm,			1,	2
zen3_wrap		vpmulld,			2xmm2xmm,			1,	2
zen3_wrap		vpmulld,			2ymm2ymm,			1,	2
zen3_wrap		vpmuldq,			2xmm2xmm,			1,	2
zen3_wrap		vpmuldq,			2ymm2ymm,			1,	2
zen3_wrap		vpmuludq,			2xmm2xmm,			1,	2
zen3_wrap		vpmuludq,			2ymm2ymm,			1,	2
zen3_wrap		vpmaddwd,			2xmm2xmm,			1,	2
zen3_wrap		vpmaddwd,			2ymm2ymm,			1,	2
zen3_wrap		vpmaddubsw,			2xmm2xmm,			1,	2
zen3_wrap		vpmaddubsw,			2ymm2ymm,			1,	2
zen3_wrap		vpsadbw,			2xmm2xmm,			1,	2
zen3_wrap		vpsadbw,			2ymm2ymm,			1,	2

zen3_wrap		vinserti128,		xmmymmi2ymm,		1,	1
zen3_wrap		vinsertf128,		xmmymmi2ymm,		1,	1
zen3_wrap		vinserti128,		m128ymmi2ymm,		1,	1
zen3_wrap		vinsertf128,		m128ymmi2ymm,		1,	1
zen3_wrap		vextracti128,		ymmi2xmm,			1,	1
zen3_wrap		vextractf128,		ymmi2xmm,			1,	1
zen3_wrap		vextracti128,		ymmi2m128,			1,	1
zen3_wrap		vextractf128,		ymmi2m128,			1,	1
zen3_wrap		vperm2i128,			2ymmi2ymm,			1,	1
zen3_wrap		vperm2f128,			2ymmi2ymm,			1,	1
zen3_wrap		vperm2i128,			m256ymmi2ymm,		1,	1
zen3_wrap		vperm2f128,			m256ymmi2ymm,		1,	1
zen3_wrap		vbroadcastss,		xmm2ymm,			1,	1
zen3_wrap		vbroadcastsd,		xmm2ymm,			1,	1
zen3_wrap		vpbroadcastb,		xmm2ymm,			1,	1
zen3_wrap		vpbroadcastw,		xmm2ymm,			1,	1
zen3_wrap		vpbroadcastd,		xmm2ymm,			1,	1
zen3_wrap		vpbroadcastq,		xmm2ymm,			1,	1
zen3_wrap		vbroadcastss,		m32_2ymm,			1,	1
zen3_wrap		vbroadcastsd,		m64_2ymm,			1,	1
zen3_wrap		vpbroadcastb,		m8_2ymm,			1,	1
zen3_wrap		vpbroadcastw,		m16_2ymm,			1,	1
zen3_wrap		vpbroadcastd,		m32_2ymm,			1,	1
zen3_wrap		vpbroadcastq,		m64_2ymm,			1,	1

zen3_wrap		vdivpd,				2xmm2xmm2,			1,	1
zen3_wrap		vdivpd,				2ymm2ymm2,			1,	1
zen3_wrap		vdivps,				2xmm2xmm2,			1,	1
zen3_wrap		vdivps,				2ymm2ymm2,			1,	1
zen3_wrap		vdivsd,				2xmm2xmm2,			1,	1
zen3_wrap		vdivss,				2xmm2xmm2,			1,	1
zen3_wrap		vsqrtpd,			xmm2xmm1,			2,	1
zen3_wrap		vsqrtpd,			ymm2ymm1,			2,	1
zen3_wrap		vsqrtps,			xmm2xmm1,			2,	1
zen3_wrap		vsqrtps,			ymm2ymm1,			2,	1
zen3_wrap		vsqrtsd,			2xmm2xmm1,			2,	1
zen3_wrap		vsqrtss,			2xmm2xmm1,			2,	1

zen3_wrap		vmovd,				xmm2gpr32,			1,	1
zen3_wrap		vmovd,				xmm2gpr64,			1,	1
zen3_wrap		vmovd,				gpr32_2xmm,			1,	1
zen3_wrap		vmovd,				gpr64_2xmm,			1,	1

zen3_wrap		vpextrb,			xmmi2gpr32,			1,	1
zen3_wrap		vpextrb,			xmmi2gpr64,			1,	1
zen3_wrap		vpextrw,			xmmi2gpr32,			1,	1
zen3_wrap		vpextrw,			xmmi2gpr64,			1,	1
zen3_wrap		vpextrd,			xmmi2gpr32,			1,	1
zen3_wrap		vpextrq,			xmmi2gpr64,			1,	1
zen3_wrap		vpinsrb,			gpr32ixmm2xmm,		1,	1
zen3_wrap		vpinsrw,			gpr32ixmm2xmm,		1,	1
zen3_wrap		vpinsrd,			gpr32ixmm2xmm,		1,	1
zen3_wrap		vpinsrq,			gpr64ixmm2xmm,		1,	1

zen3_wrap		vcvtss2si,			xmm2gpr32,			1,	1
zen3_wrap		vcvtss2si,			xmm2gpr64,			1,	1
zen3_wrap		vcvtsd2si,			xmm2gpr32,			1,	1
zen3_wrap		vcvtsd2si,			xmm2gpr64,			1,	1
zen3_wrap		vcvtsi2ss,			gpr32xmm2xmm,		1,	1
zen3_wrap		vcvtsi2ss,			gpr64xmm2xmm,		1,	1
zen3_wrap		vcvtsi2sd,			gpr32xmm2xmm,		1,	1
zen3_wrap		vcvtsi2sd,			gpr64xmm2xmm,		1,	1
zen3_wrap		vextractps,			xmmi2gpr32,			1,	1

zen3_wrap		vpmovmskb,			xmm2gpr32,			1,	1
zen3_wrap		vpmovmskb,			xmm2gpr64,			1,	1
zen3_wrap		vpmovmskb,			ymm2gpr32,			1,	1
zen3_wrap		vpmovmskb,			ymm2gpr64,			1,	1

zen3_wrap		vmovmskpd,			xmm2gpr32,			1,	1
zen3_wrap		vmovmskpd,			xmm2gpr64,			1,	1
zen3_wrap		vmovmskpd,			ymm2gpr32,			1,	1
zen3_wrap		vmovmskpd,			ymm2gpr64,			1,	1

zen3_wrap		vmovmskps,			xmm2gpr32,			1,	1
zen3_wrap		vmovmskps,			xmm2gpr64,			1,	1
zen3_wrap		vmovmskps,			ymm2gpr32,			1,	1
zen3_wrap		vmovmskps,			ymm2gpr64,			1,	1

zen3_wrap		vptest,				xmm2F,				1,	1
zen3_wrap		vptest,				ymm2F,				1,	1
zen3_wrap		vtestpd,			xmm2F,				1,	1
zen3_wrap		vtestpd,			ymm2F,				1,	1
zen3_wrap		vtestps,			xmm2F,				1,	1
zen3_wrap		vtestps,			ymm2F,				1,	1

zen3_wrap		vcomisd,			xmm2F,				1,	1
zen3_wrap		vcomiss,			xmm2F,				1,	1
zen3_wrap		vucomisd,			xmm2F,				1,	1
zen3_wrap		vucomiss,			xmm2F,				1,	1

zen3_wrap		vpermq,				ymmi2ymm,			1,	1
zen3_wrap		vpermpd,			ymmi2ymm,			1,	1
zen3_wrap		vpermd,				2ymm2ymm,			1,	1
zen3_wrap		vpermps,			2ymm2ymm,			1,	1
zen3_wrap		vpmovzxbw,			xmm2ymm,			1,	1
zen3_wrap		vpmovzxbd,			xmm2ymm,			1,	1
zen3_wrap		vpmovzxbq,			xmm2ymm,			1,	1
zen3_wrap		vpmovzxwd,			xmm2ymm,			1,	1
zen3_wrap		vpmovzxwq,			xmm2ymm,			1,	1
zen3_wrap		vpmovzxdq,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxbw,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxbd,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxbq,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxwd,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxwq,			xmm2ymm,			1,	1
zen3_wrap		vpmovsxdq,			xmm2ymm,			1,	1
zen3_wrap		vcvtps2pd,			xmm2ymm,			1,	1
zen3_wrap		vcvtpd2ps,			ymm2xmm,			1,	1
zen3_wrap		vcvtdq2pd,			xmm2ymm,			1,	1
zen3_wrap		vcvtpd2dq,			ymm2xmm,			1,	1
zen3_wrap		vcvtph2ps,			xmm2ymm,			1,	1
zen3_wrap		vcvtps2ph,			ymmi2xmm,			1,	1

zen3_wrap		vhaddpd,			2xmm2xmm,			1,	1
zen3_wrap		vhaddpd,			2ymm2ymm,			1,	1
zen3_wrap		vhaddps,			2xmm2xmm,			1,	1
zen3_wrap		vhaddps,			2ymm2ymm,			1,	1
zen3_wrap		vhsubpd,			2xmm2xmm,			1,	1
zen3_wrap		vhsubpd,			2ymm2ymm,			1,	1
zen3_wrap		vhsubps,			2xmm2xmm,			1,	1
zen3_wrap		vhsubps,			2ymm2ymm,			1,	1
zen3_wrap		vphaddw,			2xmm2xmm,			1,	1
zen3_wrap		vphaddw,			2ymm2ymm,			1,	1
zen3_wrap		vphaddd,			2xmm2xmm,			1,	1
zen3_wrap		vphaddd,			2ymm2ymm,			1,	1
zen3_wrap		vphaddsw,			2xmm2xmm,			1,	1
zen3_wrap		vphaddsw,			2ymm2ymm,			1,	1
zen3_wrap		vphsubw,			2xmm2xmm,			1,	1
zen3_wrap		vphsubw,			2ymm2ymm,			1,	1
zen3_wrap		vphsubd,			2xmm2xmm,			1,	1
zen3_wrap		vphsubd,			2ymm2ymm,			1,	1
zen3_wrap		vphsubsw,			2xmm2xmm,			1,	1
zen3_wrap		vphsubsw,			2ymm2ymm,			1,	1

zen3_wrap		vdppd,				2xmmi2xmm,			1,	1
zen3_wrap		vdpps,				2xmmi2xmm,			1,	1
zen3_wrap		vdpps,				2ymmi2ymm,			1,	1
zen3_wrap		vpclmulqdq,			2xmmi2xmm,			1,	1
zen3_wrap		vpclmulqdq,			2ymmi2ymm,			1,	1
zen3_wrap		vmpsadbw,			2xmmi2xmm,			1,	1
zen3_wrap		vmpsadbw,			2ymmi2ymm,			1,	1

end