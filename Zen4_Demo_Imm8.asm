INCLUDE Zen4_Demo_Port.h

.data

memop0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.code 

InstLatX64_empty_port macro INST
endm

InstLatX64_2ymmI82ymm_lat macro INST, I8
	INST			ymm0, ymm0, ymm0, I8
endm

InstLatX64_2ymmI82ymm_port macro INST, I8
	INST			ymm8, ymm8, ymm8, I8
	INST			ymm9, ymm9, ymm9, I8
	INST			ymm10, ymm10, ymm10, I8
	INST			ymm11, ymm11, ymm11, I8
	INST			ymm12, ymm12, ymm12, I8
	INST			ymm13, ymm13, ymm13, I8
	INST			ymm14, ymm14, ymm14, I8
	INST			ymm15, ymm15, ymm15, I8
endm

InstLatX64_2zmmI82zmm_lat macro INST, I8
	INST			zmm0, zmm0, zmm0, I8
endm

InstLatX64_2zmmI82zmm_port macro INST, I8
	INST			zmm8, zmm8, zmm8, I8
	INST			zmm9, zmm9, zmm9, I8
	INST			zmm10, zmm10, zmm10, I8
	INST			zmm11, zmm11, zmm11, I8
	INST			zmm12, zmm12, zmm12, I8
	INST			zmm13, zmm13, zmm13, I8
	INST			zmm14, zmm14, zmm14, I8
	INST			zmm15, zmm15, zmm15, I8
endm

InstLatX64_xmmymmI82ymm_lat macro INST, I8
	INST					ymm0, ymm0, xmm0, I8
endm

InstLatX64_xmmymmI82ymm_port macro INST, I8
	INST			ymm8, ymm8, xmm8, I8
	INST			ymm9, ymm9, xmm9, I8
	INST			ymm10, ymm10, xmm10, I8
	INST			ymm11, ymm11, xmm11, I8
	INST			ymm12, ymm12, xmm12, I8
	INST			ymm13, ymm13, xmm13, I8
	INST			ymm14, ymm14, xmm14, I8
	INST			ymm15, ymm15, xmm15, I8
endm

InstLatX64_xmmzmmI82zmm_lat macro INST, I8
	INST			zmm0, zmm0, xmm0, I8
endm

InstLatX64_xmmzmmI82zmm_port macro INST, I8
	INST			zmm8, zmm8, xmm8, I8
	INST			zmm9, zmm9, xmm9, I8
	INST			zmm10, zmm10, xmm10, I8
	INST			zmm11, zmm11, xmm11, I8
	INST			zmm12, zmm12, xmm12, I8
	INST			zmm13, zmm13, xmm13, I8
	INST			zmm14, zmm14, xmm14, I8
	INST			zmm15, zmm15, xmm15, I8
endm

InstLatX64_ymmzmmI82zmm_lat macro INST, I8
	INST			zmm0, zmm0, ymm0, I8
endm

InstLatX64_ymmzmmI82zmm_port macro INST, I8
	INST			zmm8, zmm8, ymm8, I8
	INST			zmm9, zmm9, ymm9, I8
	INST			zmm10, zmm10, ymm10, I8
	INST			zmm11, zmm11, ymm11, I8
	INST			zmm12, zmm12, ymm12, I8
	INST			zmm13, zmm13, ymm13, I8
	INST			zmm14, zmm14, ymm14, I8
	INST			zmm15, zmm15, ymm15, I8
endm

InstLatX64_ymmI82xmm_lat macro INST, I8
	INST			xmm0, ymm0, I8
endm

InstLatX64_ymmI82xmm_port macro INST, I8
	INST			xmm8, ymm8, I8
	INST			xmm9, ymm9, I8
	INST			xmm10, ymm10, I8
	INST			xmm11, ymm11, I8
	INST			xmm12, ymm12, I8
	INST			xmm13, ymm13, I8
	INST			xmm14, ymm14, I8
	INST			xmm15, ymm15, I8
endm

InstLatX64_zmmI82xmm_lat macro INST, I8
	INST			xmm0, zmm0, I8
endm

InstLatX64_zmmI82xmm_port macro INST, I8
	INST			xmm8, zmm8, I8
	INST			xmm9, zmm9, I8
	INST			xmm10, zmm10, I8
	INST			xmm11, zmm11, I8
	INST			xmm12, zmm12, I8
	INST			xmm13, zmm13, I8
	INST			xmm14, zmm14, I8
	INST			xmm15, zmm15, I8
endm


InstLatX64_zmmI82ymm_lat macro INST, I8
	INST			ymm0, zmm0, I8
endm

InstLatX64_zmmI82ymm_port macro INST, I8
	INST			ymm8, zmm8, I8
	INST			ymm9, zmm9, I8
	INST			ymm10, zmm10, I8
	INST			ymm11, zmm11, I8
	INST			ymm12, zmm12, I8
	INST			ymm13, zmm13, I8
	INST			ymm14, zmm14, I8
	INST			ymm15, zmm15, I8
endm

test_m macro FUNC, M1, M2, INST, R1, R2, I8
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
	M2				INST, I8
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

zen4_wrap macro INST, OPERANDS, R1, R2, I8
	;test_m		FUNC,									M1,						M2,							INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_lat,		InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 1,	1,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_tp,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_port,	INST, 1,	1,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port01,		zen4_8clks_port01_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port23,		zen4_8clks_port23_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port12,		zen4_8clks_port12_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port123,	zen4_8clks_port123_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port0123,	zen4_8clks_port0123_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port45,		zen4_8clks_port45_m,	InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_tern,		zen4_8clks_tern_m,		InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_LDs,		zen4_8clks_LDs_m,		InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
	test_m		Zen4_&INST&_&OPERANDS&_&I8&_port1,		zen4_8clks_port1_m,		InstLatX64_&OPERANDS&_port,	INST, R1,	R2,	I8
endm

zen4_wrap		vextracti128,		ymmI82xmm,			1,	2,	000h
zen4_wrap		vextractf128,		ymmI82xmm,			1,	2,	000h
zen4_wrap		vextracti128,		ymmI82xmm,			1,	2,	001h
zen4_wrap		vextractf128,		ymmI82xmm,			1,	2,	001h

zen4_wrap		vextracti32x4,		ymmi82xmm,			1,	2,	000h
zen4_wrap		vextractf32x4,		ymmi82xmm,			1,	2,	000h
zen4_wrap		vextracti32x4,		ymmi82xmm,			1,	2,	001h
zen4_wrap		vextractf32x4,		ymmi82xmm,			1,	2,	001h

zen4_wrap		vextracti64x2,		ymmi82xmm,			1,	2,	000h
zen4_wrap		vextractf64x2,		ymmi82xmm,			1,	2,	000h
zen4_wrap		vextracti64x2,		ymmi82xmm,			1,	2,	001h
zen4_wrap		vextractf64x2,		ymmi82xmm,			1,	2,	001h

zen4_wrap		vextracti32x4,		zmmi82xmm,			1,	1,	000h
zen4_wrap		vextractf32x4,		zmmi82xmm,			1,	1,	000h
zen4_wrap		vextracti32x4,		zmmi82xmm,			1,	1,	001h
zen4_wrap		vextractf32x4,		zmmi82xmm,			1,	1,	001h
zen4_wrap		vextracti32x4,		zmmi82xmm,			1,	1,	002h
zen4_wrap		vextractf32x4,		zmmi82xmm,			1,	1,	002h
zen4_wrap		vextracti32x4,		zmmi82xmm,			1,	1,	003h
zen4_wrap		vextractf32x4,		zmmi82xmm,			1,	1,	003h

zen4_wrap		vextracti32x8,		zmmi82ymm,			1,	1,	000h
zen4_wrap		vextractf32x8,		zmmi82ymm,			1,	1,	000h
zen4_wrap		vextracti32x8,		zmmi82ymm,			1,	1,	001h
zen4_wrap		vextractf32x8,		zmmi82ymm,			1,	1,	001h

zen4_wrap		vinserti128,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinsertf128,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinserti128,		xmmymmI82ymm,		1,	2,	001h
zen4_wrap		vinsertf128,		xmmymmI82ymm,		1,	2,	001h

zen4_wrap		vinserti32x4,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinsertf32x4,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinserti32x4,		xmmymmI82ymm,		1,	2,	001h
zen4_wrap		vinsertf32x4,		xmmymmI82ymm,		1,	2,	001h

zen4_wrap		vinserti64x2,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinsertf64x2,		xmmymmI82ymm,		1,	2,	000h
zen4_wrap		vinserti64x2,		xmmymmI82ymm,		1,	2,	001h
zen4_wrap		vinsertf64x2,		xmmymmI82ymm,		1,	2,	001h

zen4_wrap		vinserti32x4,		xmmzmmI82zmm,		1,	2,	000h
zen4_wrap		vinsertf32x4,		xmmzmmI82zmm,		1,	2,	000h
zen4_wrap		vinserti32x4,		xmmzmmI82zmm,		1,	2,	001h
zen4_wrap		vinsertf32x4,		xmmzmmI82zmm,		1,	2,	001h
zen4_wrap		vinserti32x4,		xmmzmmI82zmm,		1,	2,	002h
zen4_wrap		vinsertf32x4,		xmmzmmI82zmm,		1,	2,	002h
zen4_wrap		vinserti32x4,		xmmzmmI82zmm,		1,	2,	003h
zen4_wrap		vinsertf32x4,		xmmzmmI82zmm,		1,	2,	003h

zen4_wrap		vinserti32x8,		ymmzmmI82zmm,		1,	2,	000h
zen4_wrap		vinsertf32x8,		ymmzmmI82zmm,		1,	2,	000h
zen4_wrap		vinserti32x8,		ymmzmmI82zmm,		1,	2,	001h
zen4_wrap		vinsertf32x8,		ymmzmmI82zmm,		1,	2,	001h

zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	003h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	003h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	008h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	008h

zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	010h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	010h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	011h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	011h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	012h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	012h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	013h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	013h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	018h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	018h

zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	020h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	020h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	021h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	021h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	022h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	022h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	023h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	023h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	028h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	028h

zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	030h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	030h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	031h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	031h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	032h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	032h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	033h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	033h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	038h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	038h

zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	080h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	080h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	081h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	081h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	082h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	082h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	083h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	083h
zen4_wrap		vperm2i128,			2ymmI82ymm,			1,	2,	088h
zen4_wrap		vperm2f128,			2ymmI82ymm,			1,	2,	088h

zen4_wrap		vshufi32x4,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vshuff32x4,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vshufi32x4,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vshuff32x4,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vshufi32x4,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vshuff32x4,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vshufi32x4,			2ymmI82ymm,			1,	2,	003h
zen4_wrap		vshuff32x4,			2ymmI82ymm,			1,	2,	003h
zen4_wrap		vshufi64x2,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vshuff64x2,			2ymmI82ymm,			1,	2,	000h
zen4_wrap		vshufi64x2,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vshuff64x2,			2ymmI82ymm,			1,	2,	001h
zen4_wrap		vshufi64x2,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vshuff64x2,			2ymmI82ymm,			1,	2,	002h
zen4_wrap		vshufi64x2,			2ymmI82ymm,			1,	2,	003h
zen4_wrap		vshuff64x2,			2ymmI82ymm,			1,	2,	003h

zen4_wrap		vshufi32x4,			2zmmI82zmm,			1,	2,	000h
zen4_wrap		vshuff32x4,			2zmmI82zmm,			1,	2,	000h
zen4_wrap		vshufi32x4,			2zmmI82zmm,			1,	2,	044h
zen4_wrap		vshuff32x4,			2zmmI82zmm,			1,	2,	044h
zen4_wrap		vshufi32x4,			2zmmI82zmm,			1,	2,	0e4h
zen4_wrap		vshuff32x4,			2zmmI82zmm,			1,	2,	0e4h
zen4_wrap		vshufi32x4,			2zmmI82zmm,			1,	2,	0a5h
zen4_wrap		vshuff32x4,			2zmmI82zmm,			1,	2,	0a5h

zen4_wrap		vshufi64x2,			2zmmI82zmm,			1,	2,	000h
zen4_wrap		vshuff64x2,			2zmmI82zmm,			1,	2,	000h
zen4_wrap		vshufi64x2,			2zmmI82zmm,			1,	2,	044h
zen4_wrap		vshuff64x2,			2zmmI82zmm,			1,	2,	044h
zen4_wrap		vshufi64x2,			2zmmI82zmm,			1,	2,	0e4h
zen4_wrap		vshuff64x2,			2zmmI82zmm,			1,	2,	0e4h
zen4_wrap		vshufi64x2,			2zmmI82zmm,			1,	2,	0a5h
zen4_wrap		vshuff64x2,			2zmmI82zmm,			1,	2,	0a5h

END