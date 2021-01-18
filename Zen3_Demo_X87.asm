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

zen3_wrapx87 macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2,	X87PREC
	test_m		Zen3_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1,	0
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

zen3_wrapx87	fxch,				x87_1op,			1,	1
zen3_wrapx87	fabs,				noop,				1,	1
zen3_wrapx87	fchs,				noop,				1,	1
zen3_wrapx87	fxam,				noop,				1,	1
zen3_wrapx87	ftst,				noop,				1,	1
zen3_wrapx87	fcom,				x87_1op,			1,	1
zen3_wrapx87	fcomi,				x87_2opR,			1,	1

zen3_wrapx87	fld,				x87_1op_fstp,		1,	1
zen3_wrapx87	fldz,				x87_fstp,			1,	1
zen3_wrapx87	fld1,				x87_fstp,			1,	1
zen3_wrapx87	fldpi,				x87_fstp,			1,	1
zen3_wrapx87	fst,				x87_1op,			1,	1
zen3_wrapx87	ffree,				x87_1op,			1,	1
zen3_wrapx87	fdecstp,			noop,				1,	1
zen3_wrapx87	fincstp,			noop,				1,	1
zen3_wrapx87	fnop,				noop,				1,	1

zen3_wrapx87	fld,				x87_m32l,			1,	1
zen3_wrapx87	fld,				x87_m64l,			1,	1
zen3_wrapx87	fld,				x87_m80l,			1,	1

zen3_wrapx87	fstp,				x87_m32s,			1,	1
zen3_wrapx87	fstp,				x87_m64s,			1,	1
zen3_wrapx87	fstp,				x87_m80s,			1,	1

end