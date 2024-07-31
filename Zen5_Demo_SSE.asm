INCLUDE InstLatX64_PortMacros.h
INCLUDE InstLatX64_LatMacros.h
INCLUDE Zen5_Demo_Port.h

.data

memop0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

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
	finit
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

lnop2 macro
	db 066h, 090h
endm

lnop3 macro
	db 00Fh, 01Fh, 000h
endm

lnop4 macro
	db 00Fh, 01Fh, 040h, 000h
endm

lnop5 macro
	db 00Fh, 01Fh, 044h, 000h, 000h
endm

lnop6 macro
	db 066h, 00Fh, 01Fh, 044h, 000h, 000h
endm

lnop7 macro
	db 00Fh, 01Fh, 080h, 000h, 000h, 000h, 000h
endm

lnop8 macro
	db 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop9 macro
	db 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop10 macro
	db 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop11 macro
	db 066h, 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop12 macro
	db 066h, 066h, 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop13 macro
	db 066h, 066h, 066h, 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop14 macro
	db 066h, 066h, 066h, 066h, 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm

lnop15 macro
	db 066h, 066h, 066h, 066h, 066h, 066h, 066h, 00Fh, 01Fh, 084h, 000h, 000h, 000h, 000h, 000h
endm


zen5_wrap macro INST, OPERANDS, R1, R2
	;test_m		FUNC,								M1,						M2,							INST, DOMAINSTART,	DOMAINEND,	R1, R2
	test_m		Zen5_&INST&_&OPERANDS&_lat,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_lat,	INST, 0,			0,			1,	1
	test_m		Zen5_&INST&_&OPERANDS&_tp,			InstLatX64_empty_port,	InstLatX64_&OPERANDS&_port,	INST, 0,			0,			1,	1
endm

;				INST				OPERANDS			R1	R2

zen5_wrap		movaps,				xmm2xmm,			1,	1
zen5_wrap		movapd,				xmm2xmm,			1,	1
zen5_wrap		movups,				xmm2xmm,			1,	1
zen5_wrap		movupd,				xmm2xmm,			1,	1
zen5_wrap		movdqa,				xmm2xmm,			1,	1
zen5_wrap		movdqu,				xmm2xmm,			1,	1

zen5_wrap		mulpd,				xmm2xmm,			1,	2
zen5_wrap		mulps,				xmm2xmm,			1,	2
zen5_wrap		mulsd,				xmm2xmm,			1,	2
zen5_wrap		mulss,				xmm2xmm,			1,	2
zen5_wrap		rcpps,				xmm2xmm,			1,	2
zen5_wrap		rcpss,				xmm2xmm,			1,	2
zen5_wrap		rsqrtps,			xmm2xmm,			1,	2
zen5_wrap		rsqrtss,			xmm2xmm,			1,	2
zen5_wrap		pblendvb,			xmm0_2xmm,			1,	2
zen5_wrap		blendvpd,			xmm0_2xmm,			1,	2
zen5_wrap		blendvps,			xmm0_2xmm,			1,	2

zen5_wrap		addpd,				xmm2xmm,			1,	2
zen5_wrap		addps,				xmm2xmm,			1,	2
zen5_wrap		addsd,				xmm2xmm,			1,	2
zen5_wrap		addss,				xmm2xmm,			1,	2
zen5_wrap		subpd,				xmm2xmm,			1,	2
zen5_wrap		subps,				xmm2xmm,			1,	2
zen5_wrap		subsd,				xmm2xmm,			1,	2
zen5_wrap		subss,				xmm2xmm,			1,	2
zen5_wrap		addsubpd,			xmm2xmm,			1,	2
zen5_wrap		addsubps,			xmm2xmm,			1,	2
zen5_wrap		roundpd,			xmmi2xmm,			1,	2
zen5_wrap		roundps,			xmmi2xmm,			1,	2
zen5_wrap		roundsd,			xmmi2xmm,			1,	2
zen5_wrap		roundss,			xmmi2xmm,			1,	2
zen5_wrap		cvtps2dq,			xmm2xmm,			1,	2
zen5_wrap		cvtps2pd,			xmm2xmm,			1,	2
zen5_wrap		cvtpd2ps,			xmm2xmm,			1,	2
zen5_wrap		cvtpd2dq,			xmm2xmm,			1,	2
zen5_wrap		cvtdq2pd,			xmm2xmm,			1,	2
zen5_wrap		cvtdq2ps,			xmm2xmm,			1,	2
zen5_wrap		cvtss2sd,			xmm2xmm,			1,	2
zen5_wrap		cvtsd2ss,			xmm2xmm,			1,	2

zen5_wrap		minpd,				xmm2xmm,			1,	2
zen5_wrap		minps,				xmm2xmm,			1,	2
zen5_wrap		minsd,				xmm2xmm,			1,	2
zen5_wrap		minss,				xmm2xmm,			1,	2
zen5_wrap		maxpd,				xmm2xmm,			1,	2
zen5_wrap		maxps,				xmm2xmm,			1,	2
zen5_wrap		maxsd,				xmm2xmm,			1,	2
zen5_wrap		maxss,				xmm2xmm,			1,	2
zen5_wrap		cmpeqpd,			xmm2xmm,			1,	2
zen5_wrap		cmpeqps,			xmm2xmm,			1,	2
zen5_wrap		cmpeqsd,			xmm2xmm,			1,	2
zen5_wrap		cmpeqss,			xmm2xmm,			1,	2

zen5_wrap		andpd,				xmm2xmm,			1,	4
zen5_wrap		andps,				xmm2xmm,			1,	4
zen5_wrap		andnpd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		andnps,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		orpd,				xmm2xmm,			1,	4
zen5_wrap		orps,				xmm2xmm,			1,	4
zen5_wrap		xorpd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		xorps,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		blendpd,			xmmi2xmm,			1,	4
zen5_wrap		blendps,			xmmi2xmm,			1,	4

zen5_wrap		pand,				xmm2xmm,			1,	4
zen5_wrap		pandn,				xmm2xmm,			1,	4	;Zeroing idiom
zen5_wrap		pandn,				xmm2xmmRot,			1,	4
zen5_wrap		por,				xmm2xmm,			1,	4
zen5_wrap		pxor,				xmm2xmm,			1,	4	;Zeroing idiom
zen5_wrap		pxor,				xmm2xmmRot,			1,	4
zen5_wrap		pblendw,			xmmi2xmm,			1,	4

zen5_wrap		paddb,				xmm2xmm,			1,	4
zen5_wrap		paddw,				xmm2xmm,			1,	4
zen5_wrap		paddd,				xmm2xmm,			1,	4
zen5_wrap		paddq,				xmm2xmm,			1,	4
zen5_wrap		psubb,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		psubw,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		psubd,				xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		psubq,				xmm2xmmRot,			1,	4	;Zeroing idiom

zen5_wrap		pcmpeqb,			xmm2xmmRot,			1,	4	;Ones idiom
zen5_wrap		pcmpeqw,			xmm2xmmRot,			1,	4	;Ones idiom
zen5_wrap		pcmpeqd,			xmm2xmmRot,			1,	4	;Ones idiom
zen5_wrap		pcmpgtb,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		pcmpgtw,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		pcmpgtd,			xmm2xmmRot,			1,	4	;Zeroing idiom
zen5_wrap		pcmpgtq,			xmm2xmmRot,			1,	4	;Zeroing idiom

zen5_wrap		pminsb,				xmm2xmm,			1,	4
zen5_wrap		pminub,				xmm2xmm,			1,	4
zen5_wrap		pminsw,				xmm2xmm,			1,	4
zen5_wrap		pminuw,				xmm2xmm,			1,	4
zen5_wrap		pminsd,				xmm2xmm,			1,	4
zen5_wrap		pminud,				xmm2xmm,			1,	4
zen5_wrap		pmaxsb,				xmm2xmm,			1,	4
zen5_wrap		pmaxub,				xmm2xmm,			1,	4
zen5_wrap		pmaxsw,				xmm2xmm,			1,	4
zen5_wrap		pmaxuw,				xmm2xmm,			1,	4
zen5_wrap		pmaxsd,				xmm2xmm,			1,	4
zen5_wrap		pmaxud,				xmm2xmm,			1,	4

zen5_wrap		paddsb,				xmm2xmm,			1,	2
zen5_wrap		paddsw,				xmm2xmm,			1,	2
zen5_wrap		psubsb,				xmm2xmmRot,			1,	2	;Zeroing idiom
zen5_wrap		psubsw,				xmm2xmmRot,			1,	2	;Zeroing idiom
zen5_wrap		pcmpeqq,			xmm2xmmRot,			1,	2	;Ones idiom
zen5_wrap		pabsb,				xmm2xmm,			1,	2
zen5_wrap		pabsw,				xmm2xmm,			1,	2
zen5_wrap		pabsd,				xmm2xmm,			1,	2
zen5_wrap		pavgb,				xmm2xmm,			1,	2
zen5_wrap		pavgw,				xmm2xmm,			1,	2
zen5_wrap		psignb,				xmm2xmm,			1,	2
zen5_wrap		psignw,				xmm2xmm,			1,	2
zen5_wrap		psignd,				xmm2xmm,			1,	2

zen5_wrap		aesenc,				xmm2xmm,			1,	2
zen5_wrap		aesenclast,			xmm2xmm,			1,	2
zen5_wrap		aesdec,				xmm2xmm,			1,	2
zen5_wrap		aesdeclast,			xmm2xmm,			1,	2
zen5_wrap		aesenc,				xmm2xmmRot,			1,	2
zen5_wrap		aesenclast,			xmm2xmmRot,			1,	2
zen5_wrap		aesdec,				xmm2xmmRot,			1,	2
zen5_wrap		aesdeclast,			xmm2xmmRot,			1,	2
zen5_wrap		aesimc,				xmm2xmm,			1,	2
zen5_wrap		aeskeygenassist,	xmmi2xmm,			1,	2
zen5_wrap		phminposuw,			xmm2xmm,			1,	2
zen5_wrap		extrq,				xmm2xmm,			1,	2
zen5_wrap		insertq,			xmm2xmm,			1,	2

zen5_wrap		psllw,				xmm2xmm,			1,	2
zen5_wrap		psrlw,				xmm2xmm,			1,	2
zen5_wrap		psraw,				xmm2xmm,			1,	2
zen5_wrap		pslld,				xmm2xmm,			1,	2
zen5_wrap		psrld,				xmm2xmm,			1,	2
zen5_wrap		psrad,				xmm2xmm,			1,	2
zen5_wrap		psllq,				xmm2xmm,			1,	2
zen5_wrap		psrlq,				xmm2xmm,			1,	2

zen5_wrap		psllw,				i2xmm,				1,	2
zen5_wrap		psrlw,				i2xmm,				1,	2
zen5_wrap		psraw,				i2xmm,				1,	2
zen5_wrap		pslld,				i2xmm,				1,	2
zen5_wrap		psrld,				i2xmm,				1,	2
zen5_wrap		psrad,				i2xmm,				1,	2
zen5_wrap		psllq,				i2xmm,				1,	2
zen5_wrap		psrlq,				i2xmm,				1,	2

zen5_wrap		pslldq,				i2xmm,				1,	2
zen5_wrap		psrldq,				i2xmm,				1,	2

zen5_wrap		punpcklbw,			xmm2xmm,			1,	4
zen5_wrap		punpckhbw,			xmm2xmm,			1,	4
zen5_wrap		punpcklwd,			xmm2xmm,			1,	4
zen5_wrap		punpckhwd,			xmm2xmm,			1,	4
zen5_wrap		punpckldq,			xmm2xmm,			1,	4
zen5_wrap		punpckhdq,			xmm2xmm,			1,	4
zen5_wrap		punpcklqdq,			xmm2xmm,			1,	4
zen5_wrap		punpckhqdq,			xmm2xmm,			1,	4
zen5_wrap		unpcklps,			xmm2xmm,			1,	4
zen5_wrap		unpckhps,			xmm2xmm,			1,	4
zen5_wrap		unpcklpd,			xmm2xmm,			1,	4
zen5_wrap		unpckhpd,			xmm2xmm,			1,	4
zen5_wrap		movhlps,			xmm2xmm,			1,	4
zen5_wrap		movlhps,			xmm2xmm,			1,	4
zen5_wrap		packsswb,			xmm2xmm,			1,	2
zen5_wrap		packuswb,			xmm2xmm,			1,	2
zen5_wrap		packssdw,			xmm2xmm,			1,	2
zen5_wrap		packusdw,			xmm2xmm,			1,	2
zen5_wrap		shufpd,				xmmi2xmm,			1,	4
zen5_wrap		shufps,				xmmi2xmm,			1,	4
zen5_wrap		pshufb,				xmm2xmm,			1,	2
zen5_wrap		pshuflw,			xmmi2xmm,			1,	4
zen5_wrap		pshufhw,			xmmi2xmm,			1,	4
zen5_wrap		pshufd,				xmmi2xmm,			1,	4
zen5_wrap		palignr,			xmmi2xmm,			1,	2
zen5_wrap		movddup,			xmm2xmm,			1,	4
zen5_wrap		movsldup,			xmm2xmm,			1,	4
zen5_wrap		movshdup,			xmm2xmm,			1,	4
zen5_wrap		pmovzxbw,			xmm2xmm,			1,	2
zen5_wrap		pmovzxbd,			xmm2xmm,			1,	2
zen5_wrap		pmovzxbq,			xmm2xmm,			1,	2
zen5_wrap		pmovzxwd,			xmm2xmm,			1,	2
zen5_wrap		pmovzxwq,			xmm2xmm,			1,	2
zen5_wrap		pmovzxdq,			xmm2xmm,			1,	2
zen5_wrap		pmovsxbw,			xmm2xmm,			1,	2
zen5_wrap		pmovsxbd,			xmm2xmm,			1,	2
zen5_wrap		pmovsxbq,			xmm2xmm,			1,	2
zen5_wrap		pmovsxwd,			xmm2xmm,			1,	2
zen5_wrap		pmovsxwq,			xmm2xmm,			1,	2
zen5_wrap		pmovsxdq,			xmm2xmm,			1,	2
zen5_wrap		insertps,			xmmi2xmm,			1,	2

zen5_wrap		pmulhw,				xmm2xmm,			1,	2
zen5_wrap		pmulhuw,			xmm2xmm,			1,	2
zen5_wrap		pmulhrsw,			xmm2xmm,			1,	2
zen5_wrap		pmullw,				xmm2xmm,			1,	2
zen5_wrap		pmulld,				xmm2xmm,			1,	2
zen5_wrap		pmuldq,				xmm2xmm,			1,	2
zen5_wrap		pmuludq,			xmm2xmm,			1,	2
zen5_wrap		pmaddwd,			xmm2xmm,			1,	2
zen5_wrap		pmaddubsw,			xmm2xmm,			1,	2
zen5_wrap		psadbw,				xmm2xmm,			1,	2

zen5_wrap		divpd,				xmm2xmm2,			1,	1
zen5_wrap		divps,				xmm2xmm2,			1,	1
zen5_wrap		divsd,				xmm2xmm2,			1,	1
zen5_wrap		divss,				xmm2xmm2,			1,	1
zen5_wrap		sqrtpd,				xmm2xmm1,			2,	1
zen5_wrap		sqrtps,				xmm2xmm1,			2,	1
zen5_wrap		sqrtsd,				xmm2xmm1,			2,	1
zen5_wrap		sqrtss,				xmm2xmm1,			2,	1

zen5_wrap		movd,				xmm2gpr32,			1,	2
zen5_wrap		movd,				xmm2gpr64,			1,	2
zen5_wrap		movd,				gpr32_2xmm,			1,	1
zen5_wrap		movd,				gpr64_2xmm,			1,	1

zen5_wrap		pextrb,				xmmi2gpr32,			1,	2
zen5_wrap		pextrb,				xmmi2gpr64,			1,	2
zen5_wrap		pextrw,				xmmi2gpr32,			1,	2
zen5_wrap		pextrw,				xmmi2gpr64,			1,	2
zen5_wrap		pextrd,				xmmi2gpr32,			1,	2
zen5_wrap		pextrq,				xmmi2gpr64,			1,	2
zen5_wrap		pinsrb,				gpr32i2xmm,			1,	1
zen5_wrap		pinsrw,				gpr32i2xmm,			1,	1
zen5_wrap		pinsrd,				gpr32i2xmm,			1,	1
zen5_wrap		pinsrq,				gpr64i2xmm,			1,	1

zen5_wrap		cvtss2si,			xmm2gpr32,			1,	2
zen5_wrap		cvtss2si,			xmm2gpr64,			1,	2
zen5_wrap		cvtsd2si,			xmm2gpr32,			1,	2
zen5_wrap		cvtsd2si,			xmm2gpr64,			1,	2
zen5_wrap		cvtsi2ss,			gpr32_2xmm,			1,	1
zen5_wrap		cvtsi2ss,			gpr64_2xmm,			1,	1
zen5_wrap		cvtsi2sd,			gpr32_2xmm,			1,	1
zen5_wrap		cvtsi2sd,			gpr64_2xmm,			1,	1
zen5_wrap		extractps,			xmmi2gpr32,			1,	2

zen5_wrap		pmovmskb,			xmm2gpr32,			1,	2
zen5_wrap		pmovmskb,			xmm2gpr64,			1,	2

zen5_wrap		movmskpd,			xmm2gpr32,			1,	2
zen5_wrap		movmskpd,			xmm2gpr64,			1,	2

zen5_wrap		movmskps,			xmm2gpr32,			1,	2
zen5_wrap		movmskps,			xmm2gpr64,			1,	2

zen5_wrap		ptest,				xmm2F,				1,	2

zen5_wrap		comisd,				xmm2F,				1,	2
zen5_wrap		comiss,				xmm2F,				1,	2
zen5_wrap		ucomisd,			xmm2F,				1,	2
zen5_wrap		ucomiss,			xmm2F,				1,	2

zen5_wrap		haddpd,				xmm2xmm,			1,	1
zen5_wrap		haddps,				xmm2xmm,			1,	1
zen5_wrap		hsubpd,				xmm2xmm,			1,	1
zen5_wrap		hsubps,				xmm2xmm,			1,	1
zen5_wrap		phaddw,				xmm2xmm,			1,	1
zen5_wrap		phaddd,				xmm2xmm,			1,	1
zen5_wrap		phaddsw,			xmm2xmm,			1,	1
zen5_wrap		phsubw,				xmm2xmm,			1,	1
zen5_wrap		phsubd,				xmm2xmm,			1,	1
zen5_wrap		phsubsw,			xmm2xmm,			1,	1

zen5_wrap		dppd,				xmmi2xmm,			1,	1
zen5_wrap		dpps,				xmmi2xmm,			1,	1
zen5_wrap		pclmulqdq,			xmmi2xmm,			1,	1
zen5_wrap		mpsadbw,			xmmi2xmm,			1,	1
zen5_wrap		extrq,				ii2xmm,				1,	1
zen5_wrap		insertq,			xmmii2xmm,			1,	1

zen5_wrap		sha1msg1,			xmm2xmm,			1,	2
zen5_wrap		sha1msg2,			xmm2xmm,			1,	2
zen5_wrap		sha1nexte,			xmm2xmm,			1,	2
zen5_wrap		sha1rnds4,			xmmi2xmm1,			2,	1
zen5_wrap		sha256msg1,			xmm2xmm,			1,	2
zen5_wrap		sha256msg2,			xmm2xmm,			1,	1
zen5_wrap		sha256rnds2,		xmm0_2xmm1,			2,	1

zen5_wrap		pcmpestri,			xmmi2xmm,			1,	1
zen5_wrap		pcmpestrm,			xmmi2xmm,			1,	1
zen5_wrap		pcmpistri,			xmmi2xmm,			1,	1
zen5_wrap		pcmpistrm,			xmmi2xmm,			1,	1

zen5_wrap		pand,				mm2mm,				1,	4
zen5_wrap		pandn,				mm2mm,				1,	4	;Zeroing idiom
zen5_wrap		pandn,				mm2mmRot,			1,	4
zen5_wrap		por,				mm2mm,				1,	4
zen5_wrap		pxor,				mm2mm,				1,	4	;Zeroing idiom
zen5_wrap		pxor,				mm2mmRot,			1,	4
zen5_wrap		paddb,				mm2mm,				1,	4
zen5_wrap		paddw,				mm2mm,				1,	4
zen5_wrap		paddd,				mm2mm,				1,	4
zen5_wrap		paddq,				mm2mm,				1,	4
zen5_wrap		psubb,				mm2mmRot,			1,	4
zen5_wrap		psubw,				mm2mmRot,			1,	4
zen5_wrap		psubd,				mm2mmRot,			1,	4
zen5_wrap		psubq,				mm2mmRot,			1,	4

zen5_wrap		paddsb,				mm2mm,				1,	2
zen5_wrap		paddsw,				mm2mm,				1,	2
zen5_wrap		psubsb,				mm2mmRot,			1,	2
zen5_wrap		psubsw,				mm2mmRot,			1,	2

zen5_wrap		pabsb,				mm2mm,				1,	2
zen5_wrap		pabsw,				mm2mm,				1,	2
zen5_wrap		pabsd,				mm2mm,				1,	2
zen5_wrap		pavgb,				mm2mm,				1,	2
zen5_wrap		pavgw,				mm2mm,				1,	2
zen5_wrap		psignb,				mm2mm,				1,	2
zen5_wrap		psignw,				mm2mm,				1,	2
zen5_wrap		psignd,				mm2mm,				1,	2

zen5_wrap		pshufw,				mmi2mm,				1,	2
zen5_wrap		palignr,			mmi2mm,				1,	2

zen5_wrap		psllw,				mm2mm,				1,	2
zen5_wrap		psrlw,				mm2mm,				1,	2
zen5_wrap		psraw,				mm2mm,				1,	2
zen5_wrap		pslld,				mm2mm,				1,	2
zen5_wrap		psrld,				mm2mm,				1,	2
zen5_wrap		psrad,				mm2mm,				1,	2
zen5_wrap		psllq,				mm2mm,				1,	2
zen5_wrap		psrlq,				mm2mm,				1,	2

zen5_wrap		psllw,				i2mm,				1,	2
zen5_wrap		psrlw,				i2mm,				1,	2
zen5_wrap		psraw,				i2mm,				1,	2
zen5_wrap		pslld,				i2mm,				1,	2
zen5_wrap		psrld,				i2mm,				1,	2
zen5_wrap		psrad,				i2mm,				1,	2
zen5_wrap		psllq,				i2mm,				1,	2
zen5_wrap		psrlq,				i2mm,				1,	2

zen5_wrap		punpcklbw,			mm2mm,				1,	4
zen5_wrap		punpckhbw,			mm2mm,				1,	4
zen5_wrap		punpcklwd,			mm2mm,				1,	4
zen5_wrap		punpckhwd,			mm2mm,				1,	4
zen5_wrap		punpckldq,			mm2mm,				1,	4
zen5_wrap		punpckhdq,			mm2mm,				1,	4
zen5_wrap		packsswb,			mm2mm,				1,	4
zen5_wrap		packuswb,			mm2mm,				1,	4
zen5_wrap		packssdw,			mm2mm,				1,	4

zen5_wrap		pmulhw,				mm2mm,				1,	2
zen5_wrap		pmulhuw,			mm2mm,				1,	2
zen5_wrap		pmullw,				mm2mm,				1,	2
zen5_wrap		pmuludq,			mm2mm,				1,	2
zen5_wrap		pmaddwd,			mm2mm,				1,	2

zen5_wrap		pmovmskb,			mm2gpr32,			1,	2
zen5_wrap		movd,				mm2gpr32,			1,	2
zen5_wrap		movd,				gpr32_2mm,			1,	1
zen5_wrap		movq2dq,			mm2xmm,				1,	1
zen5_wrap		movdq2q,			xmm2mm,				1,	1
zen5_wrap		pextrw,				mmi2gpr32,			1,	2
zen5_wrap		pinsrw,				gpr32i2mm,			1,	1
zen5_wrap		cvtps2pi,			xmm2mm,				1,	1
zen5_wrap		cvtpd2pi,			xmm2mm,				1,	1
zen5_wrap		cvtpi2ps,			mm2xmm,				1,	1
zen5_wrap		cvtpi2pd,			mm2xmm,				1,	1

zen5_wrap		nop,				noop,				1,	1
zen5_wrap		lnop2,				noop,				1,	1
zen5_wrap		lnop3,				noop,				1,	1
zen5_wrap		lnop4,				noop,				1,	1
zen5_wrap		lnop5,				noop,				1,	1
zen5_wrap		lnop6,				noop,				1,	1
zen5_wrap		lnop7,				noop,				1,	1
zen5_wrap		lnop8,				noop,				1,	1
zen5_wrap		lnop9,				noop,				1,	1
zen5_wrap		lnop10,				noop,				1,	1
zen5_wrap		lnop11,				noop,				1,	1
zen5_wrap		lnop12,				noop,				1,	1
zen5_wrap		lnop13,				noop,				1,	1
zen5_wrap		lnop14,				noop,				1,	1
zen5_wrap		lnop15,				noop,				1,	1

end