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
	fadd				st(7), st
	fadd				st(6), st
	fadd				st(5), st
	fadd				st(4), st
	fadd				st(3), st
	fadd				st(2), st
	fadd				st(1), st
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
	movd				xmm0, eax
	movd				xmm1, edx
	movd				xmm2, ebx
	movd				xmm3, r8d
	movd				xmm4, r9d
	movd				xmm5, r10d
	movd				xmm6, r11d
	movd				xmm7, r12d
endm

zen3_8clks_port01_m macro
	pabsd				xmm0, xmm0
	pabsd				xmm1, xmm1
	pabsd				xmm2, xmm2
	pabsd				xmm3, xmm3
	pabsd				xmm4, xmm4
	pabsd				xmm5, xmm5
	pabsd				xmm6, xmm6
	pabsd				xmm7, xmm7
	pabsd				xmm0, xmm0
	pabsd				xmm1, xmm1
	pabsd				xmm2, xmm2
	pabsd				xmm3, xmm3
	pabsd				xmm4, xmm4
	pabsd				xmm5, xmm5
	pabsd				xmm6, xmm6
	pabsd				xmm7, xmm7
endm

zen3_8clks_port03_m macro
	pmaddwd				xmm0, xmm0
	pmaddwd				xmm1, xmm1
	pmaddwd				xmm2, xmm2
	pmaddwd				xmm3, xmm3
	pmaddwd				xmm4, xmm4
	pmaddwd				xmm5, xmm5
	pmaddwd				xmm6, xmm6
	pmaddwd				xmm7, xmm7
	pmaddwd				xmm0, xmm0
	pmaddwd				xmm1, xmm1
	pmaddwd				xmm2, xmm2
	pmaddwd				xmm3, xmm3
	pmaddwd				xmm4, xmm4
	pmaddwd				xmm5, xmm5
	pmaddwd				xmm6, xmm6
	pmaddwd				xmm7, xmm7
endm

zen3_8clks_port12_m macro
	psrlq				xmm0, 0
	psrlq				xmm1, 0
	psrlq				xmm2, 0
	psrlq				xmm3, 0
	psrlq				xmm4, 0
	psrlq				xmm5, 0
	psrlq				xmm6, 0
	psrlq				xmm7, 0
	psrlq				xmm0, 0
	psrlq				xmm1, 0
	psrlq				xmm2, 0
	psrlq				xmm3, 0
	psrlq				xmm4, 0
	psrlq				xmm5, 0
	psrlq				xmm6, 0
	psrlq				xmm7, 0
endm

zen3_8clks_port23_m macro
	minpd				xmm0, xmm0
	minpd				xmm1, xmm1
	minpd				xmm2, xmm2
	minpd				xmm3, xmm3
	minpd				xmm4, xmm4
	minpd				xmm5, xmm5
	minpd				xmm6, xmm6
	minpd				xmm7, xmm7
	minpd				xmm0, xmm0
	minpd				xmm1, xmm1
	minpd				xmm2, xmm2
	minpd				xmm3, xmm3
	minpd				xmm4, xmm4
	minpd				xmm5, xmm5
	minpd				xmm6, xmm6
	minpd				xmm7, xmm7
endm

zen3_8clks_port0123_m macro
	REPEAT 4
	orpd				xmm0, xmm0
	orpd				xmm1, xmm1
	orpd				xmm2, xmm2
	orpd				xmm3, xmm3
	orpd				xmm4, xmm4
	orpd				xmm5, xmm5
	orpd				xmm6, xmm6
	orpd				xmm7, xmm7
	endm
endm

zen3_8clks_port45_m macro
	movapd				[memop1 - 040h], xmm0
	movapd				[memop1 - 030h], xmm1
	movapd				[memop1 - 020h], xmm2
	movapd				[memop1 - 010h], xmm3
	movapd				[memop1 + 000h], xmm4
	movapd				[memop1 + 010h], xmm5
	movapd				[memop1 + 020h], xmm6
	movapd				[memop1 + 030h], xmm7
endm

zen3_8clks_LDs_m macro
	movapd				xmm0,	[memop1 - 080h] 
	movapd				xmm1,	[memop1 - 070h] 
	movapd				xmm2,	[memop1 - 060h] 
	movapd				xmm3,	[memop1 - 050h] 
	movapd				xmm4,	[memop1 - 040h] 
	movapd				xmm5,	[memop1 - 030h]
	movapd				xmm6,	[memop1 - 020h] 
	movapd				xmm7,	[memop1 - 010h] 
	movapd				xmm0,	[memop1 + 000h] 
	movapd				xmm1,	[memop1 + 010h] 
	movapd				xmm2,	[memop1 + 020h] 
	movapd				xmm3,	[memop1 + 030h] 
	movapd				xmm4,	[memop1 + 040h] 
	movapd				xmm5,	[memop1 + 050h] 
	movapd				xmm6,	[memop1 + 060h] 
	movapd				xmm7,	[memop1 + 070h] 
endm

test_m macro FUNC, M1, M2, INST, DOMAINSTART, DOMAINEND, R1, R2, X87PREC
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

	fnstcw			word ptr [memop0]
	xor				eax, eax
	mov				ax, word ptr [memop0]
	and				ax, 0fcffh
	or				ax, X87PREC
	mov				word ptr [memop0], ax
	fldcw			word ptr [memop0]

	fld1

	pxor			xmm0, xmm0
	pxor			xmm1, xmm1
	pxor			xmm2, xmm2
	pxor			xmm3, xmm3
	pxor			xmm4, xmm4
	pxor			xmm5, xmm5
	pxor			xmm6, xmm6
	pxor			xmm7, xmm7
	pxor			xmm8, xmm8
	pxor			xmm9, xmm9
	pxor			xmm10, xmm10
	pxor			xmm11, xmm11
	pxor			xmm12, xmm12
	pxor			xmm13, xmm13
	pxor			xmm14, xmm14
	pxor			xmm15, xmm15

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
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 4,			4,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			4,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 4,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_gpr,			zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port01,		zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port03,		zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port12,		zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port23,		zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port45,		zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_LDs,			zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
endm

zen3_wrap2 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 3,			3,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_gpr,			zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port01,		zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port03,		zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port12,		zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port23,		zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port45,		zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_LDs,			zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
endm

zen3_wrap3 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0
	test_m		Zen3_&INST&_&OPERANDS&_gpr,			zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port01,		zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port03,		zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port12,		zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port23,		zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_port45,		zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
	test_m		Zen3_&INST&_&OPERANDS&_LDs,			zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0
endm

zen3_wrap32 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&32_&OPERANDS&_lat,		InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_gpr,		zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port01,	zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port03,	zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port12,	zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port23,	zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_port45,	zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
	test_m		Zen3_&INST&32_&OPERANDS&_LDs,		zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0000h
endm

zen3_wrap64 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&64_&OPERANDS&_lat,		InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_gpr,		zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port01,	zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port03,	zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port12,	zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port23,	zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_port45,	zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
	test_m		Zen3_&INST&64_&OPERANDS&_LDs,		zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0200h
endm

zen3_wrap80 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&80_&OPERANDS&_lat,		InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_IIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_FFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_IFDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_FIDomain,	InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 5,			5,			1,	1,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_gpr,		zen3_8clks_gpr_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port0,		zen3_8clks_port0_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port1,		zen3_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port01,	zen3_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port03,	zen3_8clks_port03_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port2,		zen3_8clks_port2_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port12,	zen3_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port23,	zen3_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port0123,	zen3_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_port45,	zen3_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
	test_m		Zen3_&INST&80_&OPERANDS&_LDs,		zen3_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, 0,			0,			R1,	R2,	0300h
endm

;				INST				OPERANDS			R1	R2
zen3_wrap		mulpd,				xmm2xmm,			1,	2
zen3_wrap		mulps,				xmm2xmm,			1,	2
zen3_wrap		mulsd,				xmm2xmm,			1,	2
zen3_wrap		mulss,				xmm2xmm,			1,	2
zen3_wrap		rcpps,				xmm2xmm,			1,	2
zen3_wrap		rcpss,				xmm2xmm,			1,	2
zen3_wrap		rsqrtps,			xmm2xmm,			1,	2
zen3_wrap		rsqrtss,			xmm2xmm,			1,	2
zen3_wrap		pblendvb,			xmm0_2xmm,			1,	2
zen3_wrap		blendvpd,			xmm0_2xmm,			1,	2
zen3_wrap		blendvps,			xmm0_2xmm,			1,	2
;zen3_wrap		pblendvb,			3xmm2xmmRot,		1,	2
;zen3_wrap		blendvpd,			3xmm2xmmRot,		1,	2
;zen3_wrap		blendvps,			3xmm2xmmRot,		1,	2

zen3_wrap		addpd,				xmm2xmm,			1,	2
zen3_wrap		addps,				xmm2xmm,			1,	2
zen3_wrap		addsd,				xmm2xmm,			1,	2
zen3_wrap		addss,				xmm2xmm,			1,	2
zen3_wrap		subpd,				xmm2xmm,			1,	2
zen3_wrap		subps,				xmm2xmm,			1,	2
zen3_wrap		subsd,				xmm2xmm,			1,	2
zen3_wrap		subss,				xmm2xmm,			1,	2
zen3_wrap		addsubpd,			xmm2xmm,			1,	2
zen3_wrap		addsubps,			xmm2xmm,			1,	2
zen3_wrap		roundpd,			xmmi2xmm,			1,	2
zen3_wrap		roundps,			xmmi2xmm,			1,	2
zen3_wrap		roundsd,			xmmi2xmm,			1,	2
zen3_wrap		roundss,			xmmi2xmm,			1,	2
zen3_wrap		cvtps2dq,			xmm2xmm,			1,	2
zen3_wrap		cvtps2pd,			xmm2xmm,			1,	2
zen3_wrap		cvtpd2ps,			xmm2xmm,			1,	2
zen3_wrap		cvtpd2dq,			xmm2xmm,			1,	2
zen3_wrap		cvtdq2pd,			xmm2xmm,			1,	2
zen3_wrap		cvtdq2ps,			xmm2xmm,			1,	2
zen3_wrap		cvtss2sd,			xmm2xmm,			1,	2
zen3_wrap		cvtsd2ss,			xmm2xmm,			1,	2

zen3_wrap		minpd,				xmm2xmm,			1,	2
zen3_wrap		minps,				xmm2xmm,			1,	2
zen3_wrap		minsd,				xmm2xmm,			1,	2
zen3_wrap		minss,				xmm2xmm,			1,	2
zen3_wrap		maxpd,				xmm2xmm,			1,	2
zen3_wrap		maxps,				xmm2xmm,			1,	2
zen3_wrap		maxsd,				xmm2xmm,			1,	2
zen3_wrap		maxss,				xmm2xmm,			1,	2
zen3_wrap		cmpeqpd,			xmm2xmm,			1,	2
zen3_wrap		cmpeqps,			xmm2xmm,			1,	2
zen3_wrap		cmpeqsd,			xmm2xmm,			1,	2
zen3_wrap		cmpeqss,			xmm2xmm,			1,	2

zen3_wrap		andpd,				xmm2xmm,			1,	4
zen3_wrap		andps,				xmm2xmm,			1,	4
zen3_wrap		andnpd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		andnps,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		orpd,				xmm2xmm,			1,	4
zen3_wrap		orps,				xmm2xmm,			1,	4
zen3_wrap		xorpd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		xorps,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		blendpd,			xmmi2xmm,			1,	4
zen3_wrap		blendps,			xmmi2xmm,			1,	4

zen3_wrap		pand,				xmm2xmm,			1,	4
zen3_wrap		pandn,				xmm2xmm,			1,	4	;Zeroing idiom
zen3_wrap		pandn,				xmm2xmmRot,			1,	4
zen3_wrap		por,				xmm2xmm,			1,	4
zen3_wrap		pxor,				xmm2xmm,			1,	4	;Zeroing idiom
zen3_wrap		pxor,				xmm2xmmRot,			1,	4
zen3_wrap		pblendw,			xmmi2xmm,			1,	4

zen3_wrap		paddb,				xmm2xmm,			1,	4
zen3_wrap		paddw,				xmm2xmm,			1,	4
zen3_wrap		paddd,				xmm2xmm,			1,	4
zen3_wrap		paddq,				xmm2xmm,			1,	4
zen3_wrap		psubb,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		psubw,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		psubd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		psubq,				xmm2xmmRot,			1,	4	;Zeroing idiom

zen3_wrap		pcmpeqb,			xmm2xmmRot,			1,	4	;Ones idiom
zen3_wrap		pcmpeqw,			xmm2xmmRot,			1,	4	;Ones idiom
zen3_wrap		pcmpeqd,			xmm2xmmRot,			1,	4	;Ones idiom
zen3_wrap		pcmpgtb,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		pcmpgtw,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		pcmpgtd,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen3_wrap		pcmpgtq,			xmm2xmmRot,			1,	4	;Zeroing idiom

zen3_wrap		pminsb,				xmm2xmm,			1,	4
zen3_wrap		pminub,				xmm2xmm,			1,	4
zen3_wrap		pminsw,				xmm2xmm,			1,	4
zen3_wrap		pminuw,				xmm2xmm,			1,	4
zen3_wrap		pminsd,				xmm2xmm,			1,	4
zen3_wrap		pminud,				xmm2xmm,			1,	4
zen3_wrap		pmaxsb,				xmm2xmm,			1,	4
zen3_wrap		pmaxub,				xmm2xmm,			1,	4
zen3_wrap		pmaxsw,				xmm2xmm,			1,	4
zen3_wrap		pmaxuw,				xmm2xmm,			1,	4
zen3_wrap		pmaxsd,				xmm2xmm,			1,	4
zen3_wrap		pmaxud,				xmm2xmm,			1,	4

zen3_wrap		paddsb,				xmm2xmm,			1,	2
zen3_wrap		paddsw,				xmm2xmm,			1,	2
zen3_wrap		psubsb,				xmm2xmmRot,			1,	2	;Zeroing idiom
zen3_wrap		psubsw,				xmm2xmmRot,			1,	2	;Zeroing idiom
zen3_wrap		pcmpeqq,			xmm2xmmRot,			1,	2	;Ones idiom
zen3_wrap		pabsb,				xmm2xmm,			1,	2
zen3_wrap		pabsw,				xmm2xmm,			1,	2
zen3_wrap		pabsd,				xmm2xmm,			1,	2
zen3_wrap		pavgb,				xmm2xmm,			1,	2
zen3_wrap		pavgw,				xmm2xmm,			1,	2
zen3_wrap		psignb,				xmm2xmm,			1,	2
zen3_wrap		psignw,				xmm2xmm,			1,	2
zen3_wrap		psignd,				xmm2xmm,			1,	2

zen3_wrap		aesenc,				xmm2xmm,			1,	2
zen3_wrap		aesenclast,			xmm2xmm,			1,	2
zen3_wrap		aesdec,				xmm2xmm,			1,	2
zen3_wrap		aesdeclast,			xmm2xmm,			1,	2
zen3_wrap		aesenc,				xmm2xmmRot,			1,	2
zen3_wrap		aesenclast,			xmm2xmmRot,			1,	2
zen3_wrap		aesdec,				xmm2xmmRot,			1,	2
zen3_wrap		aesdeclast,			xmm2xmmRot,			1,	2
zen3_wrap		aesimc,				xmm2xmm,			1,	2
zen3_wrap		aeskeygenassist,	xmmi2xmm,			1,	2
zen3_wrap		phminposuw,			xmm2xmm,			1,	2
zen3_wrap		extrq,				xmm2xmm,			1,	2
zen3_wrap		insertq,			xmm2xmm,			1,	2

zen3_wrap		psllw,				xmm2xmm,			1,	2
zen3_wrap		psrlw,				xmm2xmm,			1,	2
zen3_wrap		psraw,				xmm2xmm,			1,	2
zen3_wrap		pslld,				xmm2xmm,			1,	2
zen3_wrap		psrld,				xmm2xmm,			1,	2
zen3_wrap		psrad,				xmm2xmm,			1,	2
zen3_wrap		psllq,				xmm2xmm,			1,	2
zen3_wrap		psrlq,				xmm2xmm,			1,	2

zen3_wrap		psllw,				i2xmm,				1,	2
zen3_wrap		psrlw,				i2xmm,				1,	2
zen3_wrap		psraw,				i2xmm,				1,	2
zen3_wrap		pslld,				i2xmm,				1,	2
zen3_wrap		psrld,				i2xmm,				1,	2
zen3_wrap		psrad,				i2xmm,				1,	2
zen3_wrap		psllq,				i2xmm,				1,	2
zen3_wrap		psrlq,				i2xmm,				1,	2

zen3_wrap		pslldq,				i2xmm,				1,	2
zen3_wrap		psrldq,				i2xmm,				1,	2

zen3_wrap		punpcklbw,			xmm2xmm,			1,	2
zen3_wrap		punpckhbw,			xmm2xmm,			1,	2
zen3_wrap		punpcklwd,			xmm2xmm,			1,	2
zen3_wrap		punpckhwd,			xmm2xmm,			1,	2
zen3_wrap		punpckldq,			xmm2xmm,			1,	2
zen3_wrap		punpckhdq,			xmm2xmm,			1,	2
zen3_wrap		punpcklqdq,			xmm2xmm,			1,	2
zen3_wrap		punpckhqdq,			xmm2xmm,			1,	2
zen3_wrap		unpcklps,			xmm2xmm,			1,	2
zen3_wrap		unpckhps,			xmm2xmm,			1,	2
zen3_wrap		unpcklpd,			xmm2xmm,			1,	2
zen3_wrap		unpckhpd,			xmm2xmm,			1,	2
zen3_wrap		movhlps,			xmm2xmm,			1,	2
zen3_wrap		movlhps,			xmm2xmm,			1,	2
zen3_wrap		packsswb,			xmm2xmm,			1,	2
zen3_wrap		packuswb,			xmm2xmm,			1,	2
zen3_wrap		packssdw,			xmm2xmm,			1,	2
zen3_wrap		packusdw,			xmm2xmm,			1,	2
zen3_wrap		shufpd,				xmmi2xmm,			1,	2
zen3_wrap		shufps,				xmmi2xmm,			1,	2
zen3_wrap		pshufb,				xmm2xmm,			1,	2
zen3_wrap		pshuflw,			xmmi2xmm,			1,	2
zen3_wrap		pshufhw,			xmmi2xmm,			1,	2
zen3_wrap		pshufd,				xmmi2xmm,			1,	2
zen3_wrap		palignr,			xmmi2xmm,			1,	2
zen3_wrap		movddup,			xmm2xmm,			1,	2
zen3_wrap		movsldup,			xmm2xmm,			1,	2
zen3_wrap		movshdup,			xmm2xmm,			1,	2
zen3_wrap		pmovzxbw,			xmm2xmm,			1,	2
zen3_wrap		pmovzxbd,			xmm2xmm,			1,	2
zen3_wrap		pmovzxbq,			xmm2xmm,			1,	2
zen3_wrap		pmovzxwd,			xmm2xmm,			1,	2
zen3_wrap		pmovzxwq,			xmm2xmm,			1,	2
zen3_wrap		pmovzxdq,			xmm2xmm,			1,	2
zen3_wrap		pmovsxbw,			xmm2xmm,			1,	2
zen3_wrap		pmovsxbd,			xmm2xmm,			1,	2
zen3_wrap		pmovsxbq,			xmm2xmm,			1,	2
zen3_wrap		pmovsxwd,			xmm2xmm,			1,	2
zen3_wrap		pmovsxwq,			xmm2xmm,			1,	2
zen3_wrap		pmovsxdq,			xmm2xmm,			1,	2
zen3_wrap		insertps,			xmmi2xmm,			1,	2

zen3_wrap		pmulhw,				xmm2xmm,			1,	2
zen3_wrap		pmulhuw,			xmm2xmm,			1,	2
zen3_wrap		pmulhrsw,			xmm2xmm,			1,	2
zen3_wrap		pmullw,				xmm2xmm,			1,	2
zen3_wrap		pmulld,				xmm2xmm,			1,	2
zen3_wrap		pmuldq,				xmm2xmm,			1,	2
zen3_wrap		pmuludq,			xmm2xmm,			1,	2
zen3_wrap		pmaddwd,			xmm2xmm,			1,	2
zen3_wrap		pmaddubsw,			xmm2xmm,			1,	2
zen3_wrap		psadbw,				xmm2xmm,			1,	2

zen3_wrap		divpd,				xmm2xmm2,			1,	1
zen3_wrap		divps,				xmm2xmm2,			1,	1
zen3_wrap		divsd,				xmm2xmm2,			1,	1
zen3_wrap		divss,				xmm2xmm2,			1,	1
zen3_wrap		sqrtpd,				xmm2xmm1,			2,	1
zen3_wrap		sqrtps,				xmm2xmm1,			2,	1
zen3_wrap		sqrtsd,				xmm2xmm1,			2,	1
zen3_wrap		sqrtss,				xmm2xmm1,			2,	1

zen3_wrap		movd,				xmm2gpr32,			1,	1
zen3_wrap		movd,				xmm2gpr64,			1,	1
zen3_wrap		movd,				gpr32_2xmm,			1,	1
zen3_wrap		movd,				gpr64_2xmm,			1,	1

zen3_wrap		pextrb,				xmmi2gpr32,			1,	1
zen3_wrap		pextrb,				xmmi2gpr64,			1,	1
zen3_wrap		pextrw,				xmmi2gpr32,			1,	1
zen3_wrap		pextrw,				xmmi2gpr64,			1,	1
zen3_wrap		pextrd,				xmmi2gpr32,			1,	1
zen3_wrap		pextrq,				xmmi2gpr64,			1,	1
zen3_wrap		pinsrb,				gpr32i2xmm,			1,	1
zen3_wrap		pinsrw,				gpr32i2xmm,			1,	1
zen3_wrap		pinsrd,				gpr32i2xmm,			1,	1
zen3_wrap		pinsrq,				gpr64i2xmm,			1,	1

zen3_wrap		cvtss2si,			xmm2gpr32,			1,	1
zen3_wrap		cvtss2si,			xmm2gpr64,			1,	1
zen3_wrap		cvtsd2si,			xmm2gpr32,			1,	1
zen3_wrap		cvtsd2si,			xmm2gpr64,			1,	1
zen3_wrap		cvtsi2ss,			gpr32_2xmm,			1,	1
zen3_wrap		cvtsi2ss,			gpr64_2xmm,			1,	1
zen3_wrap		cvtsi2sd,			gpr32_2xmm,			1,	1
zen3_wrap		cvtsi2sd,			gpr64_2xmm,			1,	1
zen3_wrap		extractps,			xmmi2gpr32,			1,	1

zen3_wrap		pmovmskb,			xmm2gpr32,			1,	1
zen3_wrap		pmovmskb,			xmm2gpr64,			1,	1

zen3_wrap		movmskpd,			xmm2gpr32,			1,	1
zen3_wrap		movmskpd,			xmm2gpr64,			1,	1

zen3_wrap		movmskps,			xmm2gpr32,			1,	1
zen3_wrap		movmskps,			xmm2gpr64,			1,	1

zen3_wrap		ptest,				xmm2F,				1,	1

zen3_wrap		comisd,				xmm2F,				1,	1
zen3_wrap		comiss,				xmm2F,				1,	1
zen3_wrap		ucomisd,			xmm2F,				1,	1
zen3_wrap		ucomiss,			xmm2F,				1,	1

zen3_wrap		haddpd,				xmm2xmm,			1,	1
zen3_wrap		haddps,				xmm2xmm,			1,	1
zen3_wrap		hsubpd,				xmm2xmm,			1,	1
zen3_wrap		hsubps,				xmm2xmm,			1,	1
zen3_wrap		phaddw,				xmm2xmm,			1,	1
zen3_wrap		phaddd,				xmm2xmm,			1,	1
zen3_wrap		phaddsw,			xmm2xmm,			1,	1
zen3_wrap		phsubw,				xmm2xmm,			1,	1
zen3_wrap		phsubd,				xmm2xmm,			1,	1
zen3_wrap		phsubsw,			xmm2xmm,			1,	1

zen3_wrap		dppd,				xmmi2xmm,			1,	1
zen3_wrap		dpps,				xmmi2xmm,			1,	1
zen3_wrap		pclmulqdq,			xmmi2xmm,			1,	1
zen3_wrap		mpsadbw,			xmmi2xmm,			1,	1
zen3_wrap		extrq,				ii2xmm,				1,	1
zen3_wrap		insertq,			xmmii2xmm,			1,	1

zen3_wrap		sha1msg1,			xmm2xmm,			1,	2
zen3_wrap		sha1msg2,			xmm2xmm,			1,	2
zen3_wrap		sha1nexte,			xmm2xmm,			1,	2
zen3_wrap		sha1rnds4,			xmmi2xmm1,			2,	1
zen3_wrap		sha256msg1,			xmm2xmm,			1,	2
zen3_wrap		sha256msg2,			xmm2xmm,			1,	1
zen3_wrap		sha256rnds2,		xmm0_2xmm1,			2,	1

zen3_wrap		pcmpestri,			xmmi2xmm,			1,	1
zen3_wrap		pcmpestrm,			xmmi2xmm,			1,	1
zen3_wrap		pcmpistri,			xmmi2xmm,			1,	1
zen3_wrap		pcmpistrm,			xmmi2xmm,			1,	1

zen3_wrap2		pand,				mm2mm,				1,	4
zen3_wrap2		pandn,				mm2mm,				1,	4	;Zeroing idiom
zen3_wrap2		pandn,				mm2mmRot,			1,	4
zen3_wrap2		por,				mm2mm,				1,	4
zen3_wrap2		pxor,				mm2mm,				1,	4	;Zeroing idiom
zen3_wrap2		pxor,				mm2mmRot,			1,	4
zen3_wrap2		paddb,				mm2mm,				1,	4
zen3_wrap2		paddw,				mm2mm,				1,	4
zen3_wrap2		paddd,				mm2mm,				1,	4
zen3_wrap2		paddq,				mm2mm,				1,	4
zen3_wrap2		psubb,				mm2mmRot,			1,	4
zen3_wrap2		psubw,				mm2mmRot,			1,	4
zen3_wrap2		psubd,				mm2mmRot,			1,	4
zen3_wrap2		psubq,				mm2mmRot,			1,	4

zen3_wrap2		paddsb,				mm2mm,				1,	2
zen3_wrap2		paddsw,				mm2mm,				1,	2
zen3_wrap2		psubsb,				mm2mmRot,			1,	2
zen3_wrap2		psubsw,				mm2mmRot,			1,	2

zen3_wrap2		pabsb,				mm2mm,				1,	2
zen3_wrap2		pabsw,				mm2mm,				1,	2
zen3_wrap2		pabsd,				mm2mm,				1,	2
zen3_wrap2		pavgb,				mm2mm,				1,	2
zen3_wrap2		pavgw,				mm2mm,				1,	2
zen3_wrap2		psignb,				mm2mm,				1,	2
zen3_wrap2		psignw,				mm2mm,				1,	2
zen3_wrap2		psignd,				mm2mm,				1,	2

zen3_wrap2		pshufw,				mmi2mm,				1,	2
zen3_wrap2		palignr,			mmi2mm,				1,	2

zen3_wrap2		psllw,				mm2mm,				1,	2
zen3_wrap2		psrlw,				mm2mm,				1,	2
zen3_wrap2		psraw,				mm2mm,				1,	2
zen3_wrap2		pslld,				mm2mm,				1,	2
zen3_wrap2		psrld,				mm2mm,				1,	2
zen3_wrap2		psrad,				mm2mm,				1,	2
zen3_wrap2		psllq,				mm2mm,				1,	2
zen3_wrap2		psrlq,				mm2mm,				1,	2

zen3_wrap2		psllw,				i2mm,				1,	2
zen3_wrap2		psrlw,				i2mm,				1,	2
zen3_wrap2		psraw,				i2mm,				1,	2
zen3_wrap2		pslld,				i2mm,				1,	2
zen3_wrap2		psrld,				i2mm,				1,	2
zen3_wrap2		psrad,				i2mm,				1,	2
zen3_wrap2		psllq,				i2mm,				1,	2
zen3_wrap2		psrlq,				i2mm,				1,	2

zen3_wrap2		punpcklbw,			mm2mm,				1,	2
zen3_wrap2		punpckhbw,			mm2mm,				1,	2
zen3_wrap2		punpcklwd,			mm2mm,				1,	2
zen3_wrap2		punpckhwd,			mm2mm,				1,	2
zen3_wrap2		punpckldq,			mm2mm,				1,	2
zen3_wrap2		punpckhdq,			mm2mm,				1,	2
zen3_wrap2		packsswb,			mm2mm,				1,	2
zen3_wrap2		packuswb,			mm2mm,				1,	2
zen3_wrap2		packssdw,			mm2mm,				1,	2

zen3_wrap2		pmulhw,				mm2mm,				1,	2
zen3_wrap2		pmulhuw,			mm2mm,				1,	2
zen3_wrap2		pmullw,				mm2mm,				1,	2
zen3_wrap2		pmuludq,			mm2mm,				1,	2
zen3_wrap2		pmaddwd,			mm2mm,				1,	2

zen3_wrap2		pmovmskb,			mm2gpr32,			1,	1
zen3_wrap2		movd,				mm2gpr32,			1,	1
zen3_wrap2		movd,				gpr32_2mm,			1,	1
zen3_wrap2		movq2dq,			mm2xmm,				1,	1
zen3_wrap2		movdq2q,			xmm2mm,				1,	1
zen3_wrap2		pextrw,				mmi2gpr32,			1,	1
zen3_wrap2		pinsrw,				gpr32i2mm,			1,	1
zen3_wrap2		cvtps2pi,			xmm2mm,				1,	1
zen3_wrap2		cvtpd2pi,			xmm2mm,				1,	1
zen3_wrap2		cvtpi2ps,			mm2xmm,				1,	1
zen3_wrap2		cvtpi2pd,			mm2xmm,				1,	1

zen3_wrap32		fadd,				x87_2op,			1,	1
zen3_wrap32		fsub,				x87_2op,			1,	1
zen3_wrap32		fmul,				x87_2op,			1,	1
zen3_wrap32		fdiv,				x87_2op1,			3,	1
zen3_wrap32		fsqrt,				noop1,				3,	1

zen3_wrap64		fadd,				x87_2op,			1,	1
zen3_wrap64		fsub,				x87_2op,			1,	1
zen3_wrap64		fmul,				x87_2op,			1,	1
zen3_wrap64		fdiv,				x87_2op1,			3,	1
zen3_wrap64		fsqrt,				noop1,				3,	1

zen3_wrap80		fadd,				x87_2op,			1,	1
zen3_wrap80		fsub,				x87_2op,			1,	1
zen3_wrap80		fmul,				x87_2op,			1,	1
zen3_wrap80		fdiv,				x87_2op1,			3,	1
zen3_wrap80		fsqrt,				noop1,				3,	1

zen3_wrap3		fxch,				x87_1op,			1,	1
zen3_wrap3		fabs,				noop,				1,	1
zen3_wrap3		fchs,				noop,				1,	1
zen3_wrap3		fxam,				noop,				1,	1
zen3_wrap3		ftst,				noop,				1,	1
zen3_wrap3		fcom,				x87_1op,			1,	1
zen3_wrap3		fcomi,				x87_2opR,			1,	1

zen3_wrap3		fld,				x87_1op_fstp,		1,	1
zen3_wrap3		fldz,				x87_fstp,			1,	1
zen3_wrap3		fld1,				x87_fstp,			1,	1
zen3_wrap3		fldpi,				x87_fstp,			1,	1
zen3_wrap3		fst,				x87_1op,			1,	1
zen3_wrap3		ffree,				x87_1op,			1,	1
zen3_wrap3		fdecstp,			noop,				1,	1
zen3_wrap3		fincstp,			noop,				1,	1
zen3_wrap3		fnop,				noop,				1,	1

end