INCLUDE InstLatX64_PortMacros.h
INCLUDE InstLatX64_LatMacros.h


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

	mov				eax, 0f0f0ccaah
	kmovw			k1, eax
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


zen5_wrap		vmovaps,			evex_xmm2xmm,		1,	1
zen5_wrap		vmovaps,			evex_ymm2ymm,		1,	1
zen5_wrap		vmovaps,			zmm2zmm,			1,	1
zen5_wrap		vmovapd,			evex_xmm2xmm,		1,	1
zen5_wrap		vmovapd,			evex_ymm2ymm,		1,	1
zen5_wrap		vmovapd,			zmm2zmm,			1,	1
zen5_wrap		vmovups,			evex_xmm2xmm,		1,	1
zen5_wrap		vmovups,			evex_ymm2ymm,		1,	1
zen5_wrap		vmovups,			zmm2zmm,			1,	1
zen5_wrap		vmovupd,			evex_xmm2xmm,		1,	1
zen5_wrap		vmovupd,			evex_ymm2ymm,		1,	1
zen5_wrap		vmovupd,			zmm2zmm,			1,	1
zen5_wrap		vmovdqa32,			xmm2xmm,			1,	1
zen5_wrap		vmovdqa32,			ymm2ymm,			1,	1
zen5_wrap		vmovdqa32,			zmm2zmm,			1,	1
zen5_wrap		vmovdqa64,			xmm2xmm,			1,	1
zen5_wrap		vmovdqa64,			ymm2ymm,			1,	1
zen5_wrap		vmovdqa64,			zmm2zmm,			1,	1
zen5_wrap		vmovdqu8,			xmm2xmm,			1,	1
zen5_wrap		vmovdqu8,			ymm2ymm,			1,	1
zen5_wrap		vmovdqu8,			zmm2zmm,			1,	1
zen5_wrap		vmovdqu16,			xmm2xmm,			1,	1
zen5_wrap		vmovdqu16,			ymm2ymm,			1,	1
zen5_wrap		vmovdqu16,			zmm2zmm,			1,	1
zen5_wrap		vmovdqu32,			xmm2xmm,			1,	1
zen5_wrap		vmovdqu32,			ymm2ymm,			1,	1
zen5_wrap		vmovdqu32,			zmm2zmm,			1,	1
zen5_wrap		vmovdqu64,			xmm2xmm,			1,	1
zen5_wrap		vmovdqu64,			ymm2ymm,			1,	1
zen5_wrap		vmovdqu64,			zmm2zmm,			1,	1

zen5_wrap		vmovaps,			xmm2kxmm,			1,	1
zen5_wrap		vmovaps,			ymm2kymm,			1,	1
zen5_wrap		vmovaps,			zmm2kzmm,			1,	1
zen5_wrap		vmovapd,			xmm2kxmm,			1,	1
zen5_wrap		vmovapd,			ymm2kymm,			1,	1
zen5_wrap		vmovapd,			zmm2kzmm,			1,	1
zen5_wrap		vmovups,			xmm2kxmm,			1,	1
zen5_wrap		vmovups,			ymm2kymm,			1,	1
zen5_wrap		vmovups,			zmm2kzmm,			1,	1
zen5_wrap		vmovupd,			xmm2kxmm,			1,	1
zen5_wrap		vmovupd,			ymm2kymm,			1,	1
zen5_wrap		vmovupd,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqa32,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqa32,			ymm2kymm,			1,	1
zen5_wrap		vmovdqa32,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqa64,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqa64,			ymm2kymm,			1,	1
zen5_wrap		vmovdqa64,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqu8,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqu8,			ymm2kymm,			1,	1
zen5_wrap		vmovdqu8,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqu16,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqu16,			ymm2kymm,			1,	1
zen5_wrap		vmovdqu16,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqu32,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqu32,			ymm2kymm,			1,	1
zen5_wrap		vmovdqu32,			zmm2kzmm,			1,	1
zen5_wrap		vmovdqu64,			xmm2kxmm,			1,	1
zen5_wrap		vmovdqu64,			ymm2kymm,			1,	1
zen5_wrap		vmovdqu64,			zmm2kzmm,			1,	1

zen5_wrap		vmovaps,			xmm2zkxmm,			1,	1
zen5_wrap		vmovaps,			ymm2zkymm,			1,	1
zen5_wrap		vmovaps,			zmm2zkzmm,			1,	1
zen5_wrap		vmovapd,			xmm2zkxmm,			1,	1
zen5_wrap		vmovapd,			ymm2zkymm,			1,	1
zen5_wrap		vmovapd,			zmm2zkzmm,			1,	1
zen5_wrap		vmovups,			xmm2zkxmm,			1,	1
zen5_wrap		vmovups,			ymm2zkymm,			1,	1
zen5_wrap		vmovups,			zmm2zkzmm,			1,	1
zen5_wrap		vmovupd,			xmm2zkxmm,			1,	1
zen5_wrap		vmovupd,			ymm2zkymm,			1,	1
zen5_wrap		vmovupd,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqa32,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqa32,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqa32,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqa64,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqa64,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqa64,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqu8,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqu8,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqu8,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqu16,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqu16,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqu16,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqu32,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqu32,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqu32,			zmm2zkzmm,			1,	1
zen5_wrap		vmovdqu64,			xmm2zkxmm,			1,	1
zen5_wrap		vmovdqu64,			ymm2zkymm,			1,	1
zen5_wrap		vmovdqu64,			zmm2zkzmm,			1,	1

zen5_wrap		vpblendmb,			2xmm2xmm,			1,	4
zen5_wrap		vpblendmb,			2ymm2ymm,			1,	4
zen5_wrap		vpblendmb,			2zmm2zmm,			1,	2
zen5_wrap		vpblendmw,			2xmm2xmm,			1,	4
zen5_wrap		vpblendmw,			2ymm2ymm,			1,	4
zen5_wrap		vpblendmw,			2zmm2zmm,			1,	2
zen5_wrap		vpblendmd,			2xmm2xmm,			1,	4
zen5_wrap		vpblendmd,			2ymm2ymm,			1,	4
zen5_wrap		vpblendmd,			2zmm2zmm,			1,	2
zen5_wrap		vpblendmq,			2xmm2xmm,			1,	4
zen5_wrap		vpblendmq,			2ymm2ymm,			1,	4
zen5_wrap		vpblendmq,			2zmm2zmm,			1,	2

zen5_wrap		vpblendmb,			2xmm2kxmm,			1,	4
zen5_wrap		vpblendmb,			2ymm2kymm,			1,	4
zen5_wrap		vpblendmb,			2zmm2kzmm,			1,	2
zen5_wrap		vpblendmw,			2xmm2kxmm,			1,	4
zen5_wrap		vpblendmw,			2ymm2kymm,			1,	4
zen5_wrap		vpblendmw,			2zmm2kzmm,			1,	2
zen5_wrap		vpblendmd,			2xmm2kxmm,			1,	4
zen5_wrap		vpblendmd,			2ymm2kymm,			1,	4
zen5_wrap		vpblendmd,			2zmm2kzmm,			1,	2
zen5_wrap		vpblendmq,			2xmm2kxmm,			1,	4
zen5_wrap		vpblendmq,			2ymm2kymm,			1,	4
zen5_wrap		vpblendmq,			2zmm2kzmm,			1,	2

zen5_wrap		vpblendmb,			2xmm2zkxmm,			1,	4
zen5_wrap		vpblendmb,			2ymm2zkymm,			1,	4
zen5_wrap		vpblendmb,			2zmm2zkzmm,			1,	2
zen5_wrap		vpblendmw,			2xmm2zkxmm,			1,	4
zen5_wrap		vpblendmw,			2ymm2zkymm,			1,	4
zen5_wrap		vpblendmw,			2zmm2zkzmm,			1,	2
zen5_wrap		vpblendmd,			2xmm2zkxmm,			1,	4
zen5_wrap		vpblendmd,			2ymm2zkymm,			1,	4
zen5_wrap		vpblendmd,			2zmm2zkzmm,			1,	2
zen5_wrap		vpblendmq,			2xmm2zkxmm,			1,	4
zen5_wrap		vpblendmq,			2ymm2zkymm,			1,	4
zen5_wrap		vpblendmq,			2zmm2zkzmm,			1,	2

zen5_wrap		vpaddb,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpaddb,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpaddb,				2zmm2zmm,			1,	2
zen5_wrap		vpaddw,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpaddw,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpaddw,				2zmm2zmm,			1,	2
zen5_wrap		vpaddd,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpaddd,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpaddd,				2zmm2zmm,			1,	2
zen5_wrap		vpaddq,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpaddq,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpaddq,				2zmm2zmm,			1,	2

zen5_wrap		vpaddb,				2xmm2kxmm,			1,	4
zen5_wrap		vpaddb,				2ymm2kymm,			1,	4
zen5_wrap		vpaddb,				2zmm2kzmm,			1,	2
zen5_wrap		vpaddw,				2xmm2kxmm,			1,	4
zen5_wrap		vpaddw,				2ymm2kymm,			1,	4
zen5_wrap		vpaddw,				2zmm2kzmm,			1,	2
zen5_wrap		vpaddd,				2xmm2kxmm,			1,	4
zen5_wrap		vpaddd,				2ymm2kymm,			1,	4
zen5_wrap		vpaddd,				2zmm2kzmm,			1,	2
zen5_wrap		vpaddq,				2xmm2kxmm,			1,	4
zen5_wrap		vpaddq,				2ymm2kymm,			1,	4
zen5_wrap		vpaddq,				2zmm2kzmm,			1,	2

zen5_wrap		vpaddb,				2xmm2zkxmm,			1,	4
zen5_wrap		vpaddb,				2ymm2zkymm,			1,	4
zen5_wrap		vpaddb,				2zmm2zkzmm,			1,	2
zen5_wrap		vpaddw,				2xmm2zkxmm,			1,	4
zen5_wrap		vpaddw,				2ymm2zkymm,			1,	4
zen5_wrap		vpaddw,				2zmm2zkzmm,			1,	2
zen5_wrap		vpaddd,				2xmm2zkxmm,			1,	4
zen5_wrap		vpaddd,				2ymm2zkymm,			1,	4
zen5_wrap		vpaddd,				2zmm2zkzmm,			1,	2
zen5_wrap		vpaddq,				2xmm2zkxmm,			1,	4
zen5_wrap		vpaddq,				2ymm2zkymm,			1,	4
zen5_wrap		vpaddq,				2zmm2zkzmm,			1,	2

zen5_wrap		vpsubb,				2xmm2kxmm,			1,	4
zen5_wrap		vpsubb,				2ymm2kymm,			1,	4
zen5_wrap		vpsubb,				2zmm2kzmm,			1,	2
zen5_wrap		vpsubw,				2xmm2kxmm,			1,	4
zen5_wrap		vpsubw,				2ymm2kymm,			1,	4
zen5_wrap		vpsubw,				2zmm2kzmm,			1,	2
zen5_wrap		vpsubd,				2xmm2kxmm,			1,	4
zen5_wrap		vpsubd,				2ymm2kymm,			1,	4
zen5_wrap		vpsubd,				2zmm2kzmm,			1,	2
zen5_wrap		vpsubq,				2xmm2kxmm,			1,	4
zen5_wrap		vpsubq,				2ymm2kymm,			1,	4
zen5_wrap		vpsubq,				2zmm2kzmm,			1,	2

zen5_wrap		vpsubb,				2xmm2zkxmm,			1,	4
zen5_wrap		vpsubb,				2ymm2zkymm,			1,	4
zen5_wrap		vpsubb,				2zmm2zkzmm,			1,	2
zen5_wrap		vpsubw,				2xmm2zkxmm,			1,	4
zen5_wrap		vpsubw,				2ymm2zkymm,			1,	4
zen5_wrap		vpsubw,				2zmm2zkzmm,			1,	2
zen5_wrap		vpsubd,				2xmm2zkxmm,			1,	4
zen5_wrap		vpsubd,				2ymm2zkymm,			1,	4
zen5_wrap		vpsubd,				2zmm2zkzmm,			1,	2
zen5_wrap		vpsubq,				2xmm2zkxmm,			1,	4
zen5_wrap		vpsubq,				2ymm2zkymm,			1,	4
zen5_wrap		vpsubq,				2zmm2zkzmm,			1,	2

zen5_wrap		vpaddsb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpaddsb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpaddsb,			2zmm2zmm,			1,	1
zen5_wrap		vpaddsw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpaddsw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpaddsw,			2zmm2zmm,			1,	1

zen5_wrap		vpaddusb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpaddusb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpaddusb,			2zmm2zmm,			1,	1
zen5_wrap		vpaddusw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpaddusw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpaddusw,			2zmm2zmm,			1,	1

zen5_wrap		vpsubsb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsubsb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsubsb,			2zmm2zmm,			1,	1
zen5_wrap		vpsubsw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsubsw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsubsw,			2zmm2zmm,			1,	1

zen5_wrap		vpsubusb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsubusb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsubusb,			2zmm2zmm,			1,	1
zen5_wrap		vpsubusw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsubusw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsubusw,			2zmm2zmm,			1,	1

zen5_wrap		vpandnd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpandnd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpandnd,			2zmm2zmm,			1,	2
zen5_wrap		vpandnq,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpandnq,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpandnq,			2zmm2zmm,			1,	2
zen5_wrap		vpandd,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpandd,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpandd,				2zmm2zmm,			1,	2
zen5_wrap		vpandq,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpandq,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpandq,				2zmm2zmm,			1,	2

zen5_wrap		vpandnd,			2xmm2kxmm,			1,	4
zen5_wrap		vpandnd,			2ymm2kymm,			1,	4
zen5_wrap		vpandnd,			2zmm2kzmm,			1,	2
zen5_wrap		vpandnq,			2xmm2kxmm,			1,	4
zen5_wrap		vpandnq,			2ymm2kymm,			1,	4
zen5_wrap		vpandnq,			2zmm2kzmm,			1,	2
zen5_wrap		vpandd,				2xmm2kxmm,			1,	4
zen5_wrap		vpandd,				2ymm2kymm,			1,	4
zen5_wrap		vpandd,				2zmm2kzmm,			1,	2
zen5_wrap		vpandq,				2xmm2kxmm,			1,	4
zen5_wrap		vpandq,				2ymm2kymm,			1,	4
zen5_wrap		vpandq,				2zmm2kzmm,			1,	2

zen5_wrap		vpandnd,			2xmm2zkxmm,			1,	4
zen5_wrap		vpandnd,			2ymm2zkymm,			1,	4
zen5_wrap		vpandnd,			2zmm2zkzmm,			1,	2
zen5_wrap		vpandnq,			2xmm2zkxmm,			1,	4
zen5_wrap		vpandnq,			2ymm2zkymm,			1,	4
zen5_wrap		vpandnq,			2zmm2zkzmm,			1,	2
zen5_wrap		vpandd,				2xmm2zkxmm,			1,	4
zen5_wrap		vpandd,				2ymm2zkymm,			1,	4
zen5_wrap		vpandd,				2zmm2zkzmm,			1,	2
zen5_wrap		vpandq,				2xmm2zkxmm,			1,	4
zen5_wrap		vpandq,				2ymm2zkymm,			1,	4
zen5_wrap		vpandq,				2zmm2zkzmm,			1,	2

zen5_wrap		vpxord,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpxord,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpxord,				2zmm2zmm,			1,	2
zen5_wrap		vpxorq,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpxorq,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpxorq,				2zmm2zmm,			1,	2
zen5_wrap		vpord,				evex_2xmm2xmm,		1,	4
zen5_wrap		vpord,				evex_2ymm2ymm,		1,	4
zen5_wrap		vpord,				2zmm2zmm,			1,	2
zen5_wrap		vporq,				evex_2xmm2xmm,		1,	4
zen5_wrap		vporq,				evex_2ymm2ymm,		1,	4
zen5_wrap		vporq,				2zmm2zmm,			1,	2

zen5_wrap		vpxord,				2xmm2kxmm,			1,	4
zen5_wrap		vpxord,				2ymm2kymm,			1,	4
zen5_wrap		vpxord,				2zmm2kzmm,			1,	2
zen5_wrap		vpxorq,				2xmm2kxmm,			1,	4
zen5_wrap		vpxorq,				2ymm2kymm,			1,	4
zen5_wrap		vpxorq,				2zmm2kzmm,			1,	2
zen5_wrap		vpord,				2xmm2kxmm,			1,	4
zen5_wrap		vpord,				2ymm2kymm,			1,	4
zen5_wrap		vpord,				2zmm2kzmm,			1,	2
zen5_wrap		vporq,				2xmm2kxmm,			1,	4
zen5_wrap		vporq,				2ymm2kymm,			1,	4
zen5_wrap		vporq,				2zmm2kzmm,			1,	2

zen5_wrap		vpxord,				2xmm2zkxmm,			1,	4
zen5_wrap		vpxord,				2ymm2zkymm,			1,	4
zen5_wrap		vpxord,				2zmm2zkzmm,			1,	2
zen5_wrap		vpxorq,				2xmm2zkxmm,			1,	4
zen5_wrap		vpxorq,				2ymm2zkymm,			1,	4
zen5_wrap		vpxorq,				2zmm2zkzmm,			1,	2
zen5_wrap		vpord,				2xmm2zkxmm,			1,	4
zen5_wrap		vpord,				2ymm2zkymm,			1,	4
zen5_wrap		vpord,				2zmm2zkzmm,			1,	2
zen5_wrap		vporq,				2xmm2zkxmm,			1,	4
zen5_wrap		vporq,				2ymm2zkymm,			1,	4
zen5_wrap		vporq,				2zmm2zkzmm,			1,	2

zen5_wrap		vandnps,			evex_2xmm2xmm,		1,	4
zen5_wrap		vandnps,			evex_2ymm2ymm,		1,	4
zen5_wrap		vandnps,			2zmm2zmm,			1,	2
zen5_wrap		vandnpd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vandnpd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vandnpd,			2zmm2zmm,			1,	2
zen5_wrap		vandps,				evex_2xmm2xmm,		1,	4
zen5_wrap		vandps,				evex_2ymm2ymm,		1,	4
zen5_wrap		vandps,				2zmm2zmm,			1,	2
zen5_wrap		vandpd,				evex_2xmm2xmm,		1,	4
zen5_wrap		vandpd,				evex_2ymm2ymm,		1,	4
zen5_wrap		vandpd,				2zmm2zmm,			1,	2

zen5_wrap		vandnps,			2xmm2kxmm,			1,	4
zen5_wrap		vandnps,			2ymm2kymm,			1,	4
zen5_wrap		vandnps,			2zmm2kzmm,			1,	2
zen5_wrap		vandnpd,			2xmm2kxmm,			1,	4
zen5_wrap		vandnpd,			2ymm2kymm,			1,	4
zen5_wrap		vandnpd,			2zmm2kzmm,			1,	2
zen5_wrap		vandps,				2xmm2kxmm,			1,	4
zen5_wrap		vandps,				2ymm2kymm,			1,	4
zen5_wrap		vandps,				2zmm2kzmm,			1,	2
zen5_wrap		vandpd,				2xmm2kxmm,			1,	4
zen5_wrap		vandpd,				2ymm2kymm,			1,	4
zen5_wrap		vandpd,				2zmm2kzmm,			1,	2

zen5_wrap		vandnps,			2xmm2zkxmm,			1,	4
zen5_wrap		vandnps,			2ymm2zkymm,			1,	4
zen5_wrap		vandnps,			2zmm2zkzmm,			1,	2
zen5_wrap		vandnpd,			2xmm2zkxmm,			1,	4
zen5_wrap		vandnpd,			2ymm2zkymm,			1,	4
zen5_wrap		vandnpd,			2zmm2zkzmm,			1,	2
zen5_wrap		vandps,				2xmm2zkxmm,			1,	4
zen5_wrap		vandps,				2ymm2zkymm,			1,	4
zen5_wrap		vandps,				2zmm2zkzmm,			1,	2
zen5_wrap		vandpd,				2xmm2zkxmm,			1,	4
zen5_wrap		vandpd,				2ymm2zkymm,			1,	4
zen5_wrap		vandpd,				2zmm2zkzmm,			1,	2

zen5_wrap		vxorps,				evex_2xmm2xmm,		1,	4
zen5_wrap		vxorps,				evex_2ymm2ymm,		1,	4
zen5_wrap		vxorps,				2zmm2zmm,			1,	2
zen5_wrap		vxorpd,				evex_2xmm2xmm,		1,	4
zen5_wrap		vxorpd,				evex_2ymm2ymm,		1,	4
zen5_wrap		vxorpd,				2zmm2zmm,			1,	2
zen5_wrap		vorps,				evex_2xmm2xmm,		1,	4
zen5_wrap		vorps,				evex_2ymm2ymm,		1,	4
zen5_wrap		vorps,				2zmm2zmm,			1,	2
zen5_wrap		vorpd,				evex_2xmm2xmm,		1,	4
zen5_wrap		vorpd,				evex_2ymm2ymm,		1,	4
zen5_wrap		vorpd,				2zmm2zmm,			1,	2

zen5_wrap		vxorps,				2xmm2kxmm,			1,	4
zen5_wrap		vxorps,				2ymm2kymm,			1,	4
zen5_wrap		vxorps,				2zmm2kzmm,			1,	2
zen5_wrap		vxorpd,				2xmm2kxmm,			1,	4
zen5_wrap		vxorpd,				2ymm2kymm,			1,	4
zen5_wrap		vxorpd,				2zmm2kzmm,			1,	2
zen5_wrap		vorps,				2xmm2kxmm,			1,	4
zen5_wrap		vorps,				2ymm2kymm,			1,	4
zen5_wrap		vorps,				2zmm2kzmm,			1,	2
zen5_wrap		vorpd,				2xmm2kxmm,			1,	4
zen5_wrap		vorpd,				2ymm2kymm,			1,	4
zen5_wrap		vorpd,				2zmm2kzmm,			1,	2

zen5_wrap		vxorps,				2xmm2zkxmm,			1,	4
zen5_wrap		vxorps,				2ymm2zkymm,			1,	4
zen5_wrap		vxorps,				2zmm2zkzmm,			1,	2
zen5_wrap		vxorpd,				2xmm2zkxmm,			1,	4
zen5_wrap		vxorpd,				2ymm2zkymm,			1,	4
zen5_wrap		vxorpd,				2zmm2zkzmm,			1,	2
zen5_wrap		vorps,				2xmm2zkxmm,			1,	4
zen5_wrap		vorps,				2ymm2zkymm,			1,	4
zen5_wrap		vorps,				2zmm2zkzmm,			1,	2
zen5_wrap		vorpd,				2xmm2zkxmm,			1,	4
zen5_wrap		vorpd,				2ymm2zkymm,			1,	4
zen5_wrap		vorpd,				2zmm2zkzmm,			1,	2

;zen5_wrap		vpandnd,			evex_2xmm2xmmRot,	1,	4
;zen5_wrap		vpandnd,			evex_2ymm2ymmRot,	1,	4
;zen5_wrap		vpandnd,			2zmm2zmmRot,		1,	2
;zen5_wrap		vpandnq,			evex_2xmm2xmmRot,	1,	4
;zen5_wrap		vpandnq,			evex_2ymm2ymmRot,	1,	4
;zen5_wrap		vpandnq,			2zmm2zmmRot,		1,	2

;zen5_wrap		vpandnd,			2xmm2kxmmRot,		1,	4
;zen5_wrap		vpandnd,			2ymm2kymmRot,		1,	4
;zen5_wrap		vpandnd,			2zmm2kzmmRot,		1,	2
;zen5_wrap		vpandnq,			2xmm2kxmmRot,		1,	4
;zen5_wrap		vpandnq,			2ymm2kymmRot,		1,	4
;zen5_wrap		vpandnq,			2zmm2kzmmRot,		1,	2

;zen5_wrap		vpandnd,			2xmm2zkxmmRot,		1,	4
;zen5_wrap		vpandnd,			2ymm2zkymmRot,		1,	4
;zen5_wrap		vpandnd,			2zmm2zkzmmRot,		1,	2
;zen5_wrap		vpandnq,			2xmm2zkxmmRot,		1,	4
;zen5_wrap		vpandnq,			2ymm2zkymmRot,		1,	4
;zen5_wrap		vpandnq,			2zmm2zkzmmRot,		1,	2

zen5_wrap		vpternlogd,			2xmmi2xmm,			1,	4
zen5_wrap		vpternlogd,			2ymmi2ymm,			1,	4
zen5_wrap		vpternlogd,			2zmmi2zmm,			1,	2
zen5_wrap		vpternlogq,			2xmmi2xmm,			1,	4
zen5_wrap		vpternlogq,			2ymmi2ymm,			1,	4
zen5_wrap		vpternlogq,			2zmmi2zmm,			1,	2

zen5_wrap		vpternlogd,			2xmmi2kxmm,			1,	4
zen5_wrap		vpternlogd,			2ymmi2kymm,			1,	4
zen5_wrap		vpternlogd,			2zmmi2kzmm,			1,	2
zen5_wrap		vpternlogq,			2xmmi2kxmm,			1,	4
zen5_wrap		vpternlogq,			2ymmi2kymm,			1,	4
zen5_wrap		vpternlogq,			2zmmi2kzmm,			1,	2

zen5_wrap		vpternlogd,			2xmmi2zkxmm,		1,	4
zen5_wrap		vpternlogd,			2ymmi2zkymm,		1,	4
zen5_wrap		vpternlogd,			2zmmi2zkzmm,		1,	2
zen5_wrap		vpternlogq,			2xmmi2zkxmm,		1,	4
zen5_wrap		vpternlogq,			2ymmi2zkymm,		1,	4
zen5_wrap		vpternlogq,			2zmmi2zkzmm,		1,	2

zen5_wrap		vpternlogd,			2xmmi2xmmRot,		1,	4
zen5_wrap		vpternlogd,			2ymmi2ymmRot,		1,	4
zen5_wrap		vpternlogd,			2zmmi2zmmRot,		1,	2
zen5_wrap		vpternlogq,			2xmmi2xmmRot,		1,	4
zen5_wrap		vpternlogq,			2ymmi2ymmRot,		1,	4
zen5_wrap		vpternlogq,			2zmmi2zmmRot,		1,	2

zen5_wrap		vpternlogd,			2xmmi2kxmmRot,		1,	4
zen5_wrap		vpternlogd,			2ymmi2kymmRot,		1,	4
zen5_wrap		vpternlogd,			2zmmi2kzmmRot,		1,	2
zen5_wrap		vpternlogq,			2xmmi2kxmmRot,		1,	4
zen5_wrap		vpternlogq,			2ymmi2kymmRot,		1,	4
zen5_wrap		vpternlogq,			2zmmi2kzmmRot,		1,	2

zen5_wrap		vpternlogd,			2xmmi2zkxmmRot,		1,	4
zen5_wrap		vpternlogd,			2ymmi2zkymmRot,		1,	4
zen5_wrap		vpternlogd,			2zmmi2zkzmmRot,		1,	2
zen5_wrap		vpternlogq,			2xmmi2zkxmmRot,		1,	4
zen5_wrap		vpternlogq,			2ymmi2zkymmRot,		1,	4
zen5_wrap		vpternlogq,			2zmmi2zkzmmRot,		1,	2

zen5_wrap		vmulss,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmulps,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmulps,				evex_2ymm2ymm,		1,	2
zen5_wrap		vmulps,				2zmm2zmm,			1,	1
zen5_wrap		vmulsd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmulpd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmulpd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vmulpd,				2zmm2zmm,			1,	1

zen5_wrap		vaddss,				evex_2xmm2xmm,		1,	2
zen5_wrap		vaddps,				evex_2xmm2xmm,		1,	2
zen5_wrap		vaddps,				evex_2ymm2ymm,		1,	2
zen5_wrap		vaddps,				2zmm2zmm,			1,	1
zen5_wrap		vaddsd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vaddpd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vaddpd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vaddpd,				2zmm2zmm,			1,	1

zen5_wrap		vsubss,				evex_2xmm2xmm,		1,	2
zen5_wrap		vsubps,				evex_2xmm2xmm,		1,	2
zen5_wrap		vsubps,				evex_2ymm2ymm,		1,	2
zen5_wrap		vsubps,				2zmm2zmm,			1,	1
zen5_wrap		vsubsd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vsubpd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vsubpd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vsubpd,				2zmm2zmm,			1,	1

zen5_wrap		vfmadd132ss,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd132ps,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd132ps,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd132ps,		2zmm2zmm,			1,	1
zen5_wrap		vfmadd132sd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd132pd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd132pd,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd132pd,		2zmm2zmm,			1,	1

zen5_wrap		vfmadd132ss,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd132ps,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd132ps,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd132ps,		2zmm2zmmRot,		1,	1
zen5_wrap		vfmadd132sd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd132pd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd132pd,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd132pd,		2zmm2zmmRot,		1,	1

zen5_wrap		vfmadd231ss,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd231ps,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd231ps,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd231ps,		2zmm2zmm,			1,	1
zen5_wrap		vfmadd231sd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd231pd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd231pd,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd231pd,		2zmm2zmm,			1,	1

zen5_wrap		vfmadd231ss,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd231ps,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd231ps,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd231ps,		2zmm2zmmRot,		1,	1
zen5_wrap		vfmadd231sd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd231pd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd231pd,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd231pd,		2zmm2zmmRot,		1,	1

zen5_wrap		vfmadd213ss,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd213ps,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd213ps,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd213ps,		2zmm2zmm,			1,	1
zen5_wrap		vfmadd213sd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd213pd,		evex_2xmm2xmm,		1,	2
zen5_wrap		vfmadd213pd,		evex_2ymm2ymm,		1,	2
zen5_wrap		vfmadd213pd,		2zmm2zmm,			1,	1

zen5_wrap		vfmadd213ss,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd213ps,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd213ps,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd213ps,		2zmm2zmmRot,		1,	1
zen5_wrap		vfmadd213sd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd213pd,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vfmadd213pd,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vfmadd213pd,		2zmm2zmmRot,		1,	1

zen5_wrap		vdivss,				2xmm2xmm,			1,	2
zen5_wrap		vdivps,				2xmm2xmm	,		1,	2
zen5_wrap		vdivps,				2ymm2ymm,			1,	2
zen5_wrap		vdivps,				2zmm2zmm,			1,	1
zen5_wrap		vdivsd,				2xmm2xmm,			1,	2
zen5_wrap		vdivpd,				2xmm2xmm,			1,	2
zen5_wrap		vdivpd,				2ymm2ymm,			1,	2
zen5_wrap		vdivpd,				2zmm2zmm,			1,	1

zen5_wrap		vsqrtss,			2xmm2xmm,			1,	2
zen5_wrap		vsqrtps,			xmm2xmm		,		1,	2
zen5_wrap		vsqrtps,			ymm2ymm,			1,	2
zen5_wrap		vsqrtps,			zmm2zmm,			1,	1
zen5_wrap		vsqrtsd,			2xmm2xmm,			1,	2
zen5_wrap		vsqrtpd,			xmm2xmm,			1,	2
zen5_wrap		vsqrtpd,			ymm2ymm,			1,	2
zen5_wrap		vsqrtpd,			zmm2zmm,			1,	1

zen5_wrap		vrcp14ss,			2xmm2xmm,			1,	2
zen5_wrap		vrcp14ps,			xmm2xmm		,		1,	2
zen5_wrap		vrcp14ps,			ymm2ymm,			1,	2
zen5_wrap		vrcp14ps,			zmm2zmm,			1,	1
zen5_wrap		vrcp14sd,			2xmm2xmm,			1,	2
zen5_wrap		vrcp14pd,			xmm2xmm,			1,	2
zen5_wrap		vrcp14pd,			ymm2ymm,			1,	2
zen5_wrap		vrcp14pd,			zmm2zmm,			1,	1

zen5_wrap		vrsqrt14ss,			2xmm2xmm,			1,	2
zen5_wrap		vrsqrt14ps,			xmm2xmm		,		1,	2
zen5_wrap		vrsqrt14ps,			ymm2ymm,			1,	2
zen5_wrap		vrsqrt14ps,			zmm2zmm,			1,	1
zen5_wrap		vrsqrt14sd,			2xmm2xmm,			1,	2
zen5_wrap		vrsqrt14pd,			xmm2xmm,			1,	2
zen5_wrap		vrsqrt14pd,			ymm2ymm,			1,	2
zen5_wrap		vrsqrt14pd,			zmm2zmm,			1,	1

zen5_wrap		vminss,				evex_2xmm2xmm,		1,	2
zen5_wrap		vminps,				evex_2xmm2xmm,		1,	2
zen5_wrap		vminps,				evex_2ymm2ymm,		1,	2
zen5_wrap		vminps,				2zmm2zmm,			1,	1
zen5_wrap		vminsd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vminpd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vminpd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vminpd,				2zmm2zmm,			1,	1

zen5_wrap		vmaxss,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmaxps,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmaxps,				evex_2ymm2ymm,		1,	2
zen5_wrap		vmaxps,				2zmm2zmm,			1,	1
zen5_wrap		vmaxsd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmaxpd,				evex_2xmm2xmm,		1,	2
zen5_wrap		vmaxpd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vmaxpd,				2zmm2zmm,			1,	1

zen5_wrap		vgetexpss,			2xmm2xmm,			1,	2
zen5_wrap		vgetexpps,			xmm2xmm		,		1,	2
zen5_wrap		vgetexpps,			ymm2ymm,			1,	2
zen5_wrap		vgetexpps,			zmm2zmm,			1,	1
zen5_wrap		vgetexpsd,			2xmm2xmm,			1,	2
zen5_wrap		vgetexppd,			xmm2xmm,			1,	2
zen5_wrap		vgetexppd,			ymm2ymm,			1,	2
zen5_wrap		vgetexppd,			zmm2zmm,			1,	1

zen5_wrap		vgetmantss,			2xmmi2xmm,			1,	2
zen5_wrap		vgetmantps,			xmmi2xmm	,		1,	2
zen5_wrap		vgetmantps,			ymmi2ymm,			1,	2
zen5_wrap		vgetmantps,			zmmi2zmm,			1,	1
zen5_wrap		vgetmantsd,			2xmmi2xmm,			1,	2
zen5_wrap		vgetmantpd,			xmmi2xmm,			1,	2
zen5_wrap		vgetmantpd,			ymmi2ymm,			1,	2
zen5_wrap		vgetmantpd,			zmmi2zmm,			1,	1

zen5_wrap		vreducess,			2xmmi2xmm,			1,	2
zen5_wrap		vreduceps,			xmmi2xmm	,		1,	2
zen5_wrap		vreduceps,			ymmi2ymm,			1,	2
zen5_wrap		vreduceps,			zmmi2zmm,			1,	1
zen5_wrap		vreducesd,			2xmmi2xmm,			1,	2
zen5_wrap		vreducepd,			xmmi2xmm,			1,	2
zen5_wrap		vreducepd,			ymmi2ymm,			1,	2
zen5_wrap		vreducepd,			zmmi2zmm,			1,	1

zen5_wrap		vrndscaless,		2xmmi2xmm,			1,	2
zen5_wrap		vrndscaleps,		xmmi2xmm,			1,	2
zen5_wrap		vrndscaleps,		ymmi2ymm,			1,	2
zen5_wrap		vrndscaleps,		zmmi2zmm,			1,	1
zen5_wrap		vrndscalesd,		2xmmi2xmm,			1,	2
zen5_wrap		vrndscalepd,		xmmi2xmm,			1,	2
zen5_wrap		vrndscalepd,		ymmi2ymm,			1,	2
zen5_wrap		vrndscalepd,		zmmi2zmm,			1,	1

zen5_wrap		vscalefss,			2xmm2xmm,			1,	2
zen5_wrap		vscalefps,			2xmm2xmm,			1,	2
zen5_wrap		vscalefps,			2ymm2ymm,			1,	2
zen5_wrap		vscalefps,			2zmm2zmm,			1,	1
zen5_wrap		vscalefsd,			2xmm2xmm,			1,	2
zen5_wrap		vscalefpd,			2xmm2xmm,			1,	2
zen5_wrap		vscalefpd,			2ymm2ymm,			1,	2
zen5_wrap		vscalefpd,			2zmm2zmm,			1,	1

zen5_wrap		vrangess,			2xmmi2xmm,			1,	2
zen5_wrap		vrangeps,			2xmmi2xmm,			1,	2
zen5_wrap		vrangeps,			2ymmi2ymm,			1,	2
zen5_wrap		vrangeps,			2zmmi2zmm,			1,	1
zen5_wrap		vrangesd,			2xmmi2xmm,			1,	2
zen5_wrap		vrangepd,			2xmmi2xmm,			1,	2
zen5_wrap		vrangepd,			2ymmi2ymm,			1,	2
zen5_wrap		vrangepd,			2zmmi2zmm,			1,	1

zen5_wrap		vfixupimmss,		2xmmi2xmm,			1,	2
zen5_wrap		vfixupimmps,		2xmmi2xmm,			1,	2
zen5_wrap		vfixupimmps,		2ymmi2ymm,			1,	2
zen5_wrap		vfixupimmps,		2zmmi2zmm,			1,	1
zen5_wrap		vfixupimmsd,		2xmmi2xmm,			1,	2
zen5_wrap		vfixupimmpd,		2xmmi2xmm,			1,	2
zen5_wrap		vfixupimmpd,		2ymmi2ymm,			1,	2
zen5_wrap		vfixupimmpd,		2zmmi2zmm,			1,	1

zen5_wrap		vpminuq,			2xmm2xmm,			1,	2
zen5_wrap		vpminuq,			2ymm2ymm,			1,	2
zen5_wrap		vpminuq,			2zmm2zmm,			1,	1
zen5_wrap		vpminsq,			2xmm2xmm,			1,	2
zen5_wrap		vpminsq,			2ymm2ymm,			1,	2
zen5_wrap		vpminsq,			2zmm2zmm,			1,	1

zen5_wrap		vpmaxuq,			2xmm2xmm,			1,	2
zen5_wrap		vpmaxuq,			2ymm2ymm,			1,	2
zen5_wrap		vpmaxuq,			2zmm2zmm,			1,	1
zen5_wrap		vpmaxsq,			2xmm2xmm,			1,	2
zen5_wrap		vpmaxsq,			2ymm2ymm,			1,	2
zen5_wrap		vpmaxsq,			2zmm2zmm,			1,	1

zen5_wrap		vpabsq,				xmm2xmm,			1,	2
zen5_wrap		vpabsq,				ymm2ymm,			1,	2
zen5_wrap		vpabsq,				zmm2zmm,			1,	1

zen5_wrap		vpopcntb,			xmm2xmm,			1,	2
zen5_wrap		vpopcntb,			ymm2ymm,			1,	2
zen5_wrap		vpopcntb,			zmm2zmm,			1,	1

zen5_wrap		vpopcntw,			xmm2xmm,			1,	2
zen5_wrap		vpopcntw,			ymm2ymm,			1,	2
zen5_wrap		vpopcntw,			zmm2zmm,			1,	1

zen5_wrap		vpopcntd,			xmm2xmm,			1,	2
zen5_wrap		vpopcntd,			ymm2ymm,			1,	2
zen5_wrap		vpopcntd,			zmm2zmm,			1,	1

zen5_wrap		vpopcntq,			xmm2xmm,			1,	2
zen5_wrap		vpopcntq,			ymm2ymm,			1,	2
zen5_wrap		vpopcntq,			zmm2zmm,			1,	1

zen5_wrap		vplzcntd,			xmm2xmm,			1,	2
zen5_wrap		vplzcntd,			ymm2ymm,			1,	2
zen5_wrap		vplzcntd,			zmm2zmm,			1,	1

zen5_wrap		vplzcntq,			xmm2xmm,			1,	2
zen5_wrap		vplzcntq,			ymm2ymm,			1,	2
zen5_wrap		vplzcntq,			zmm2zmm,			1,	1

zen5_wrap		vpmultishiftqb,		2xmm2xmm,			1,	2
zen5_wrap		vpmultishiftqb,		2ymm2ymm,			1,	2
zen5_wrap		vpmultishiftqb,		2zmm2zmm,			1,	1

zen5_wrap		vgf2p8affineqb,		2xmmi2xmm,			1,	2
zen5_wrap		vgf2p8affineqb,		2ymmi2ymm,			1,	2
zen5_wrap		vgf2p8affineqb,		evex_2xmmi2xmm,		1,	2
zen5_wrap		vgf2p8affineqb,		evex_2ymmi2ymm,		1,	2
zen5_wrap		vgf2p8affineqb,		2zmmi2zmm,			1,	1

zen5_wrap		vgf2p8affineinvqb,	2xmmi2xmm,			1,	2
zen5_wrap		vgf2p8affineinvqb,	2ymmi2ymm,			1,	2
zen5_wrap		vgf2p8affineinvqb,	evex_2xmmi2xmm,		1,	2
zen5_wrap		vgf2p8affineinvqb,	evex_2ymmi2ymm,		1,	2
zen5_wrap		vgf2p8affineinvqb,	2zmmi2zmm,			1,	1

zen5_wrap		vgf2p8mulb,			2xmm2xmm,			1,	2
zen5_wrap		vgf2p8mulb,			2ymm2ymm,			1,	2
zen5_wrap		vgf2p8mulb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vgf2p8mulb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vgf2p8mulb,			2zmm2zmm,			1,	1

zen5_wrap		vpmulhw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmulhw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmulhw,			2zmm2zmm,			1,	1

zen5_wrap		vpmulhuw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmulhuw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmulhuw,			2zmm2zmm,			1,	1

zen5_wrap		vpmulhrsw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmulhrsw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmulhrsw,			2zmm2zmm,			1,	1

zen5_wrap		vpmullw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmullw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmullw,			2zmm2zmm,			1,	1

zen5_wrap		vpmulld,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmulld,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmulld,			2zmm2zmm,			1,	1

zen5_wrap		vpmuldq,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmuldq,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmuldq,			2zmm2zmm,			1,	1

zen5_wrap		vpmuludq,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmuludq,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmuludq,			2zmm2zmm,			1,	1

zen5_wrap		vpmaddwd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmaddwd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmaddwd,			2zmm2zmm,			1,	1

zen5_wrap		vpmaddubsw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpmaddubsw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpmaddubsw,			2zmm2zmm,			1,	1

zen5_wrap		vpmadd52huq,		evex_2xmm2xmm,		1,	2
zen5_wrap		vpmadd52huq,		evex_2ymm2ymm,		1,	2
zen5_wrap		vpmadd52huq,		2zmm2zmm,			1,	1

zen5_wrap		vpmadd52luq,		evex_2xmm2xmm,		1,	2
zen5_wrap		vpmadd52luq,		evex_2ymm2ymm,		1,	2
zen5_wrap		vpmadd52luq,		2zmm2zmm,			1,	1

zen5_wrap		vpmadd52huq,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpmadd52huq,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpmadd52huq,		2zmm2zmmRot,		1,	1

zen5_wrap		vpmadd52luq,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpmadd52luq,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpmadd52luq,		2zmm2zmmRot,		1,	1

;zen5_wrap		vpdpbusd,			vex_2xmm2xmm,		1,	2
;zen5_wrap		vpdpbusd,			vex_2ymm2ymm,		1,	2
zen5_wrap		vpdpbusd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpdpbusd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpdpbusd,			2zmm2zmm,			1,	1

;zen5_wrap		vpdpbusds,			vex_2xmm2xmm,		1,	2
;zen5_wrap		vpdpbusds,			vex_2ymm2ymm,		1,	2
zen5_wrap		vpdpbusds,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpdpbusds,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpdpbusds,			2zmm2zmm,			1,	1

;zen5_wrap		vpdpwssd,			vex_2xmm2xmm,		1,	2
;zen5_wrap		vpdpwssd,			vex_2ymm2ymm,		1,	2
zen5_wrap		vpdpwssd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpdpwssd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpdpwssd,			2zmm2zmm,			1,	1

;zen5_wrap		vpdpwssds,			vex_2xmm2xmm,		1,	2
;zen5_wrap		vpdpwssds,			vex_2ymm2ymm,		1,	2
zen5_wrap		vpdpwssds,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpdpwssds,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpdpwssds,			2zmm2zmm,			1,	1

;zen5_wrap		vpdpbusd,			vex_2xmm2xmmRot,	1,	2
;zen5_wrap		vpdpbusd,			vex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpbusd,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpdpbusd,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpbusd,			2zmm2zmmRot,		1,	1

;zen5_wrap		vpdpbusds,			vex_2xmm2xmmRot,	1,	2
;zen5_wrap		vpdpbusds,			vex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpbusds,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpdpbusds,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpbusds,			2zmm2zmmRot,		1,	1

;zen5_wrap		vpdpwssd,			vex_2xmm2xmmRot,	1,	2
;zen5_wrap		vpdpwssd,			vex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpwssd,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpdpwssd,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpwssd,			2zmm2zmmRot,		1,	1

;zen5_wrap		vpdpwssds,			vex_2xmm2xmmRot,	1,	2
;zen5_wrap		vpdpwssds,			vex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpwssds,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vpdpwssds,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vpdpwssds,			2zmm2zmmRot,		1,	1

zen5_wrap		vpsadbw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsadbw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsadbw,			2zmm2zmm,			1,	1

zen5_wrap		vdbpsadbw,			2xmmi2xmm,			2,	2
zen5_wrap		vdbpsadbw,			2ymmi2ymm,			2,	2
zen5_wrap		vdbpsadbw,			2zmmi2zmm,			2,	1

zen5_wrap		vpsllw,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsllw,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsllw,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsrlw,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrlw,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsrlw,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsraw,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsraw,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsraw,				xmmzmm2zmm,			1,	1

zen5_wrap		vpslld,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpslld,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpslld,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsrld,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrld,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsrld,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsrad,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrad,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsrad,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsllq,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsllq,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsllq,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsrlq,				evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrlq,				evex_xmmymm2ymm,	1,	2
zen5_wrap		vpsrlq,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsraq,				2xmm2xmm,			1,	2
zen5_wrap		vpsraq,				xmmymm2ymm,			1,	2
zen5_wrap		vpsraq,				xmmzmm2zmm,			1,	1

zen5_wrap		vpsllvw,			2xmm2xmm,			1,	2
zen5_wrap		vpsllvw,			2ymm2ymm,			1,	2
zen5_wrap		vpsllvw,			2zmm2zmm,			1,	1

zen5_wrap		vpsrlvw,			2xmm2xmm,			1,	2
zen5_wrap		vpsrlvw,			2ymm2ymm,			1,	2
zen5_wrap		vpsrlvw,			2zmm2zmm,			1,	1

zen5_wrap		vpsravw,			2xmm2xmm,			1,	2
zen5_wrap		vpsravw,			2ymm2ymm,			1,	2
zen5_wrap		vpsravw,			2zmm2zmm,			1,	1

zen5_wrap		vpsllvd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsllvd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsllvd,			2zmm2zmm,			1,	1

zen5_wrap		vpsrlvd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrlvd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsrlvd,			2zmm2zmm,			1,	1

zen5_wrap		vpsravd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsravd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsravd,			2zmm2zmm,			1,	1

zen5_wrap		vpsllvq,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsllvq,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsllvq,			2zmm2zmm,			1,	1

zen5_wrap		vpsrlvq,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpsrlvq,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpsrlvq,			2zmm2zmm,			1,	1

zen5_wrap		vpsravq,			2xmm2xmm,			1,	2
zen5_wrap		vpsravq,			2ymm2ymm,			1,	2
zen5_wrap		vpsravq,			2zmm2zmm,			1,	1

zen5_wrap		vpsllw,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsllw,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsllw,				zmmi2zmm,			1,	1

zen5_wrap		vpsrlw,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsrlw,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsrlw,				zmmi2zmm,			1,	1

zen5_wrap		vpsraw,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsraw,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsraw,				zmmi2zmm,			1,	1

zen5_wrap		vpslld,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpslld,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpslld,				zmmi2zmm,			1,	1

zen5_wrap		vpsrld,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsrld,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsrld,				zmmi2zmm,			1,	1

zen5_wrap		vpsrad,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsrad,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsrad,				zmmi2zmm,			1,	1

zen5_wrap		vpsllq,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsllq,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsllq,				zmmi2zmm,			1,	1

zen5_wrap		vpsrlq,				evex_xmmi2xmm,		1,	2
zen5_wrap		vpsrlq,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpsrlq,				zmmi2zmm,			1,	1

zen5_wrap		vpsraq,				xmmi2xmm,			1,	2
zen5_wrap		vpsraq,				ymmi2ymm,			1,	2
zen5_wrap		vpsraq,				zmmi2zmm,			1,	1
;========================
zen5_wrap		vpshldvw,			2xmm2xmm,			1,	2
zen5_wrap		vpshldvw,			2ymm2ymm,			1,	2
zen5_wrap		vpshldvw,			2zmm2zmm,			1,	1

zen5_wrap		vpshrdvw,			2xmm2xmm,			1,	2
zen5_wrap		vpshrdvw,			2ymm2ymm,			1,	2
zen5_wrap		vpshrdvw,			2zmm2zmm,			1,	1

zen5_wrap		vpshldvd,			2xmm2xmm,			1,	2
zen5_wrap		vpshldvd,			2ymm2ymm,			1,	2
zen5_wrap		vpshldvd,			2zmm2zmm,			1,	1

zen5_wrap		vpshrdvd,			2xmm2xmm,			1,	2
zen5_wrap		vpshrdvd,			2ymm2ymm,			1,	2
zen5_wrap		vpshrdvd,			2zmm2zmm,			1,	1

zen5_wrap		vpshldvq,			2xmm2xmm,			1,	2
zen5_wrap		vpshldvq,			2ymm2ymm,			1,	2
zen5_wrap		vpshldvq,			2zmm2zmm,			1,	1

zen5_wrap		vpshrdvq,			2xmm2xmm,			1,	2
zen5_wrap		vpshrdvq,			2ymm2ymm,			1,	2
zen5_wrap		vpshrdvq,			2zmm2zmm,			1,	1

zen5_wrap		vpshldw,			2xmmi2xmm,			1,	2
zen5_wrap		vpshldw,			2ymmi2ymm,			1,	2
zen5_wrap		vpshldw,			2zmmi2zmm,			1,	1

zen5_wrap		vpshrdw,			2xmmi2xmm,			1,	2
zen5_wrap		vpshrdw,			2ymmi2ymm,			1,	2
zen5_wrap		vpshrdw,			2zmmi2zmm,			1,	1

zen5_wrap		vpshldd,			2xmmi2xmm,			1,	2
zen5_wrap		vpshldd,			2ymmi2ymm,			1,	2
zen5_wrap		vpshldd,			2zmmi2zmm,			1,	1

zen5_wrap		vpshrdd,			2xmmi2xmm,			1,	2
zen5_wrap		vpshrdd,			2ymmi2ymm,			1,	2
zen5_wrap		vpshrdd,			2zmmi2zmm,			1,	1

zen5_wrap		vpshldq,			2xmmi2xmm,			1,	2
zen5_wrap		vpshldq,			2ymmi2ymm,			1,	2
zen5_wrap		vpshldq,			2zmmi2zmm,			1,	1

zen5_wrap		vpshrdq,			2xmmi2xmm,			1,	2
zen5_wrap		vpshrdq,			2ymmi2ymm,			1,	2
zen5_wrap		vpshrdq,			2zmmi2zmm,			1,	1
;========================
zen5_wrap		vprolvd,			2xmm2xmm,			1,	2
zen5_wrap		vprolvd,			2ymm2ymm,			1,	2
zen5_wrap		vprolvd,			2zmm2zmm,			1,	1

zen5_wrap		vprorvd,			2xmm2xmm,			1,	2
zen5_wrap		vprorvd,			2ymm2ymm,			1,	2
zen5_wrap		vprorvd,			2zmm2zmm,			1,	1

zen5_wrap		vprolvq,			2xmm2xmm,			1,	2
zen5_wrap		vprolvq,			2ymm2ymm,			1,	2
zen5_wrap		vprolvq,			2zmm2zmm,			1,	1

zen5_wrap		vprorvq,			2xmm2xmm,			1,	2
zen5_wrap		vprorvq,			2ymm2ymm,			1,	2
zen5_wrap		vprorvq,			2zmm2zmm,			1,	1

zen5_wrap		vprold,				xmmi2xmm,			1,	2
zen5_wrap		vprold,				ymmi2ymm,			1,	2
zen5_wrap		vprold,				zmmi2zmm,			1,	1

zen5_wrap		vprord,				xmmi2xmm,			1,	2
zen5_wrap		vprord,				ymmi2ymm,			1,	2
zen5_wrap		vprord,				zmmi2zmm,			1,	1

zen5_wrap		vprolq,				xmmi2xmm,			1,	2
zen5_wrap		vprolq,				ymmi2ymm,			1,	2
zen5_wrap		vprolq,				zmmi2zmm,			1,	1

zen5_wrap		vprorq,				xmmi2xmm,			1,	2
zen5_wrap		vprorq,				ymmi2ymm,			1,	2
zen5_wrap		vprorq,				zmmi2zmm,			1,	1
;========================
zen5_wrap		vaesenc,			evex_2xmm2xmm,		1,	2
zen5_wrap		vaesenc,			evex_2ymm2ymm,		1,	2
zen5_wrap		vaesenc,			2zmm2zmm,			1,	1

zen5_wrap		vaesenclast,		evex_2xmm2xmm,		1,	2
zen5_wrap		vaesenclast,		evex_2ymm2ymm,		1,	2
zen5_wrap		vaesenclast,		2zmm2zmm,			1,	1

zen5_wrap		vaesdec,			evex_2xmm2xmm,		1,	2
zen5_wrap		vaesdec,			evex_2ymm2ymm,		1,	2
zen5_wrap		vaesdec,			2zmm2zmm,			1,	1

zen5_wrap		vaesdeclast,		evex_2xmm2xmm,		1,	2
zen5_wrap		vaesdeclast,		evex_2ymm2ymm,		1,	2
zen5_wrap		vaesdeclast,		2zmm2zmm,			1,	1

zen5_wrap		vaesenc,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vaesenc,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vaesenc,			2zmm2zmmRot,		1,	1

zen5_wrap		vaesenclast,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vaesenclast,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vaesenclast,		2zmm2zmmRot,		1,	1

zen5_wrap		vaesdec,			evex_2xmm2xmmRot,	1,	2
zen5_wrap		vaesdec,			evex_2ymm2ymmRot,	1,	2
zen5_wrap		vaesdec,			2zmm2zmmRot,		1,	1

zen5_wrap		vaesdeclast,		evex_2xmm2xmmRot,	1,	2
zen5_wrap		vaesdeclast,		evex_2ymm2ymmRot,	1,	2
zen5_wrap		vaesdeclast,		2zmm2zmmRot,		1,	1

zen5_wrap		vpclmulqdq,			evex_2xmmi2xmm,		1,	2
zen5_wrap		vpclmulqdq,			evex_2ymmi2ymm,		1,	2
zen5_wrap		vpclmulqdq,			2zmmi2zmm,			1,	1

zen5_wrap		vpacksswb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpacksswb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpacksswb,			2zmm2zmm,			1,	1

zen5_wrap		vpackuswb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpackuswb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpackuswb,			2zmm2zmm,			1,	1

zen5_wrap		vpackssdw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpackssdw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpackssdw,			2zmm2zmm,			1,	1

zen5_wrap		vpackusdw,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpackusdw,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpackusdw,			2zmm2zmm,			1,	1

zen5_wrap		vpslldq,			evex_xmmi2xmm,		1,	2
zen5_wrap		vpslldq,			evex_ymmi2ymm,		1,	2
zen5_wrap		vpslldq,			zmmi2zmm,			1,	1

zen5_wrap		vpsrldq,			evex_xmmi2xmm,		1,	2
zen5_wrap		vpsrldq,			evex_ymmi2ymm,		1,	2
zen5_wrap		vpsrldq,			zmmi2zmm,			1,	1

zen5_wrap		vpshufb,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpshufb,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpshufb,			2zmm2zmm,			1,	1

zen5_wrap		vpalignr,			evex_2xmmi2xmm,		1,	2
zen5_wrap		vpalignr,			evex_2ymmi2ymm,		1,	2
zen5_wrap		vpalignr,			2zmmi2zmm,			1,	1

zen5_wrap		vmovddup,			evex_xmm2xmm,		1,	2
zen5_wrap		vmovddup,			evex_ymm2ymm,		1,	2
zen5_wrap		vmovddup,			zmm2zmm,			1,	1

zen5_wrap		vpermilpd,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpermilpd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpermilpd,			2zmm2zmm,			1,	1

zen5_wrap		vpermilps,			evex_2xmm2xmm,		1,	2
zen5_wrap		vpermilps,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpermilps,			2zmm2zmm,			1,	1

zen5_wrap		vpmovzxbw,			evex_xmm2xmm,			1,	2
zen5_wrap		vpmovzxbw,			evex_xmm2ymm,			1,	2
zen5_wrap		vpmovzxbw,			ymm2zmm,				1,	1
zen5_wrap		vpmovzxbd,			evex_xmm2xmm,			1,	2
zen5_wrap		vpmovzxbd,			evex_xmm2ymm,			1,	2
zen5_wrap		vpmovzxbd,			xmm2zmm,				1,	1
zen5_wrap		vpmovzxbq,			evex_xmm2xmm,			1,	2
zen5_wrap		vpmovzxbq,			evex_xmm2ymm,			1,	2
zen5_wrap		vpmovzxbq,			xmm2zmm,				1,	1
zen5_wrap		vpmovzxwd,			evex_xmm2xmm,			1,	2
zen5_wrap		vpmovzxwd,			evex_xmm2ymm,			1,	2
zen5_wrap		vpmovzxwd,			ymm2zmm,				1,	1
zen5_wrap		vpmovzxwq,			evex_xmm2xmm,			1,	2
zen5_wrap		vpmovzxwq,			evex_xmm2ymm,			1,	2
zen5_wrap		vpmovzxwq,			xmm2zmm,				1,	1
zen5_wrap		vpmovzxdq,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovzxdq,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovzxdq,			ymm2zmm,			1,	1

zen5_wrap		vpmovsxbw,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxbw,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxbw,			ymm2zmm,			1,	1
zen5_wrap		vpmovsxbd,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxbd,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxbd,			xmm2zmm,			1,	1
zen5_wrap		vpmovsxbq,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxbq,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxbq,			xmm2zmm,			1,	1
zen5_wrap		vpmovsxwd,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxwd,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxwd,			ymm2zmm,			1,	1
zen5_wrap		vpmovsxwq,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxwq,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxwq,			xmm2zmm,			1,	1
zen5_wrap		vpmovsxdq,			evex_xmm2xmm,		1,	2
zen5_wrap		vpmovsxdq,			evex_xmm2ymm,		1,	2
zen5_wrap		vpmovsxdq,			ymm2zmm,			1,	1

zen5_wrap		vpmovwb,			xmm2xmm,			1,	2
zen5_wrap		vpmovwb,			ymm2xmm,			1,	2
zen5_wrap		vpmovwb,			zmm2ymm,			1,	1
zen5_wrap		vpmovdb,			xmm2xmm,			1,	2
zen5_wrap		vpmovdb,			ymm2xmm,			1,	2
zen5_wrap		vpmovdb,			zmm2xmm,			1,	1
zen5_wrap		vpmovdw,			xmm2xmm,			1,	2
zen5_wrap		vpmovdw,			ymm2xmm,			1,	2
zen5_wrap		vpmovdw,			zmm2ymm,			1,	1
zen5_wrap		vpmovqb,			xmm2xmm,			1,	2
zen5_wrap		vpmovqb,			ymm2xmm,			1,	2
zen5_wrap		vpmovqb,			zmm2xmm,			1,	1
zen5_wrap		vpmovqw,			xmm2xmm,			1,	2
zen5_wrap		vpmovqw,			ymm2xmm,			1,	2
zen5_wrap		vpmovqw,			zmm2xmm,			1,	1
zen5_wrap		vpmovqd,			xmm2xmm,			1,	2
zen5_wrap		vpmovqd,			ymm2xmm,			1,	2
zen5_wrap		vpmovqd,			zmm2ymm,			1,	1

zen5_wrap		vpmovswb,			xmm2xmm,			1,	2
zen5_wrap		vpmovswb,			ymm2xmm,			1,	2
zen5_wrap		vpmovswb,			zmm2ymm,			1,	1
zen5_wrap		vpmovsdb,			xmm2xmm,			1,	2
zen5_wrap		vpmovsdb,			ymm2xmm,			1,	2
zen5_wrap		vpmovsdb,			zmm2xmm,			1,	1
zen5_wrap		vpmovsdw,			xmm2xmm,			1,	2
zen5_wrap		vpmovsdw,			ymm2xmm,			1,	2
zen5_wrap		vpmovsdw,			zmm2ymm,			1,	1
zen5_wrap		vpmovsqb,			xmm2xmm,			1,	2
zen5_wrap		vpmovsqb,			ymm2xmm,			1,	2
zen5_wrap		vpmovsqb,			zmm2xmm,			1,	1
zen5_wrap		vpmovsqw,			xmm2xmm,			1,	2
zen5_wrap		vpmovsqw,			ymm2xmm,			1,	2
zen5_wrap		vpmovsqw,			zmm2xmm,			1,	1
zen5_wrap		vpmovsqd,			xmm2xmm,			1,	2
zen5_wrap		vpmovsqd,			ymm2xmm,			1,	2
zen5_wrap		vpmovsqd,			zmm2ymm,			1,	1

zen5_wrap		vpmovuswb,			xmm2xmm,			1,	2
zen5_wrap		vpmovuswb,			ymm2xmm,			1,	2
zen5_wrap		vpmovuswb,			zmm2ymm,			1,	1
zen5_wrap		vpmovusdb,			xmm2xmm,			1,	2
zen5_wrap		vpmovusdb,			ymm2xmm,			1,	2
zen5_wrap		vpmovusdb,			zmm2xmm,			1,	1
zen5_wrap		vpmovusdw,			xmm2xmm,			1,	2
zen5_wrap		vpmovusdw,			ymm2xmm,			1,	2
zen5_wrap		vpmovusdw,			zmm2ymm,			1,	1
zen5_wrap		vpmovusqb,			xmm2xmm,			1,	2
zen5_wrap		vpmovusqb,			ymm2xmm,			1,	2
zen5_wrap		vpmovusqb,			zmm2xmm,			1,	1
zen5_wrap		vpmovusqw,			xmm2xmm,			1,	2
zen5_wrap		vpmovusqw,			ymm2xmm,			1,	2
zen5_wrap		vpmovusqw,			zmm2xmm,			1,	1
zen5_wrap		vpmovusqd,			xmm2xmm,			1,	2
zen5_wrap		vpmovusqd,			ymm2xmm,			1,	2
zen5_wrap		vpmovusqd,			zmm2ymm,			1,	1

zen5_wrap		vbroadcastss,		evex_xmm2xmm,		1,	2
zen5_wrap		vbroadcastss,		evex_xmm2ymm,		1,	2
zen5_wrap		vbroadcastss,		xmm2zmm,			1,	1

;zen5_wrap		vbroadcastsd,		evex_xmm2xmm,		1,	2
zen5_wrap		vbroadcastsd,		evex_xmm2ymm,		1,	2
zen5_wrap		vbroadcastsd,		xmm2zmm,			1,	1

zen5_wrap		vpbroadcastb,		evex_xmm2xmm,		1,	2
zen5_wrap		vpbroadcastb,		evex_xmm2ymm,		1,	2
zen5_wrap		vpbroadcastb,		xmm2zmm,			1,	1

zen5_wrap		vpbroadcastw,		evex_xmm2xmm,		1,	2
zen5_wrap		vpbroadcastw,		evex_xmm2ymm,		1,	2
zen5_wrap		vpbroadcastw,		xmm2zmm,			1,	1

zen5_wrap		vpbroadcastd,		evex_xmm2xmm,		1,	2
zen5_wrap		vpbroadcastd,		evex_xmm2ymm,		1,	2
zen5_wrap		vpbroadcastd,		xmm2zmm,			1,	1

zen5_wrap		vpbroadcastq,		evex_xmm2xmm,		1,	2
zen5_wrap		vpbroadcastq,		evex_xmm2ymm,		1,	2
zen5_wrap		vpbroadcastq,		xmm2zmm,			1,	1

zen5_wrap		valignd,			2xmmi2xmm,			1,	2
zen5_wrap		valignd,			2ymmi2ymm,			1,	2
zen5_wrap		valignd,			2zmmi2zmm,			1,	1
zen5_wrap		valignq,			2xmmi2xmm,			1,	2
zen5_wrap		valignq,			2ymmi2ymm,			1,	2
zen5_wrap		valignq,			2zmmi2zmm,			1,	1

zen5_wrap		vpermb,				2xmm2xmm,			1,	2
zen5_wrap		vpermb,				2ymm2ymm,			1,	2
zen5_wrap		vpermb,				2zmm2zmm,			1,	1
zen5_wrap		vpermw,				2xmm2xmm,			1,	2
zen5_wrap		vpermw,				2ymm2ymm,			1,	2
zen5_wrap		vpermw,				2zmm2zmm,			1,	1
;zen5_wrap		vpermd,				2xmm2xmm,			1,	2
zen5_wrap		vpermd,				evex_2ymm2ymm,		1,	2
zen5_wrap		vpermd,				2zmm2zmm,			1,	1
;zen5_wrap		vpermq,				2xmm2xmm,			1,	2
zen5_wrap		vpermq,				evex_ymmi2ymm,		1,	2
zen5_wrap		vpermq,				evex_2ymm2ymm,		1,	2
zen5_wrap		vpermq,				zmmi2zmm,			1,	1
zen5_wrap		vpermq,				2zmm2zmm,			1,	1
;zen5_wrap		vpermps,			2xmm2xmm,			1,	2
zen5_wrap		vpermps,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpermps,			2zmm2zmm,			1,	1
;zen5_wrap		vpermpd,			2xmm2xmm,			1,	2
zen5_wrap		vpermpd,			evex_ymmi2ymm,		1,	2
zen5_wrap		vpermpd,			evex_2ymm2ymm,		1,	2
zen5_wrap		vpermpd,			zmmi2zmm,			1,	1
zen5_wrap		vpermpd,			2zmm2zmm,			1,	1

zen5_wrap		vpermi2b,			2xmm2xmm,			1,	2
zen5_wrap		vpermi2b,			2ymm2ymm,			1,	2
zen5_wrap		vpermi2b,			2zmm2zmm,			1,	1
zen5_wrap		vpermt2b,			2xmm2xmm,			1,	2
zen5_wrap		vpermt2b,			2ymm2ymm,			1,	2
zen5_wrap		vpermt2b,			2zmm2zmm,			1,	1
zen5_wrap		vpermi2w,			2xmm2xmm,			1,	2
zen5_wrap		vpermi2w,			2ymm2ymm,			1,	2
zen5_wrap		vpermi2w,			2zmm2zmm,			1,	1
zen5_wrap		vpermt2w,			2xmm2xmm,			1,	2
zen5_wrap		vpermt2w,			2ymm2ymm,			1,	2
zen5_wrap		vpermt2w,			2zmm2zmm,			1,	1
zen5_wrap		vpermi2d,			2xmm2xmm,			1,	2
zen5_wrap		vpermi2d,			2ymm2ymm,			1,	2
zen5_wrap		vpermi2d,			2zmm2zmm,			1,	1
zen5_wrap		vpermt2d,			2xmm2xmm,			1,	2
zen5_wrap		vpermt2d,			2ymm2ymm,			1,	2
zen5_wrap		vpermt2d,			2zmm2zmm,			1,	1
zen5_wrap		vpermi2q,			2xmm2xmm,			1,	2
zen5_wrap		vpermi2q,			2ymm2ymm,			1,	2
zen5_wrap		vpermi2q,			2zmm2zmm,			1,	1
zen5_wrap		vpermt2q,			2xmm2xmm,			1,	2
zen5_wrap		vpermt2q,			2ymm2ymm,			1,	2
zen5_wrap		vpermt2q,			2zmm2zmm,			1,	1

zen5_wrap		vinsertf32x4,		xmmymmi02ymm,		1,	2
zen5_wrap		vinsertf32x4,		xmmzmmi02zmm,		1,	1
zen5_wrap		vinserti32x4,		xmmymmi02ymm,		1,	2
zen5_wrap		vinserti32x4,		xmmzmmi02zmm,		1,	1
zen5_wrap		vinsertf64x2,		xmmymmi02ymm,		1,	2
zen5_wrap		vinsertf64x2,		xmmzmmi02zmm,		1,	1
zen5_wrap		vinserti64x2,		xmmymmi02ymm,		1,	2
zen5_wrap		vinserti64x2,		xmmzmmi02zmm,		1,	1
zen5_wrap		vinsertf32x8,		ymmzmmi02zmm,		1,	1
zen5_wrap		vinserti32x8,		ymmzmmi02zmm,		1,	1
zen5_wrap		vinsertf64x4,		ymmzmmi02zmm,		1,	1
zen5_wrap		vinserti64x4,		ymmzmmi02zmm,		1,	1

zen5_wrap		vinsertf32x4,		xmmymmi2ymm,		1,	2
zen5_wrap		vinsertf32x4,		xmmzmmi2zmm,		1,	1
zen5_wrap		vinserti32x4,		xmmymmi2ymm,		1,	2
zen5_wrap		vinserti32x4,		xmmzmmi2zmm,		1,	1
zen5_wrap		vinsertf64x2,		xmmymmi2ymm,		1,	2
zen5_wrap		vinsertf64x2,		xmmzmmi2zmm,		1,	1
zen5_wrap		vinserti64x2,		xmmymmi2ymm,		1,	2
zen5_wrap		vinserti64x2,		xmmzmmi2zmm,		1,	1
zen5_wrap		vinsertf32x8,		ymmzmmi2zmm,		1,	1
zen5_wrap		vinserti32x8,		ymmzmmi2zmm,		1,	1
zen5_wrap		vinsertf64x4,		ymmzmmi2zmm,		1,	1
zen5_wrap		vinserti64x4,		ymmzmmi2zmm,		1,	1

zen5_wrap		vextractf32x4,		ymmi02xmm,			1,	2
zen5_wrap		vextractf32x4,		zmmi02xmm,			1,	1
zen5_wrap		vextracti32x4,		ymmi02xmm,			1,	2
zen5_wrap		vextracti32x4,		zmmi02xmm,			1,	1
zen5_wrap		vextractf64x2,		ymmi02xmm,			1,	2
zen5_wrap		vextractf64x2,		zmmi02xmm,			1,	1
zen5_wrap		vextracti64x2,		ymmi02xmm,			1,	2
zen5_wrap		vextracti64x2,		zmmi02xmm,			1,	1
zen5_wrap		vextractf32x8,		zmmi02ymm,			1,	1
zen5_wrap		vextracti32x8,		zmmi02ymm,			1,	1
zen5_wrap		vextractf64x4,		zmmi02ymm,			1,	1
zen5_wrap		vextracti64x4,		zmmi02ymm,			1,	1

zen5_wrap		vextractf32x4,		ymmi2xmm,			1,	2
zen5_wrap		vextractf32x4,		zmmi2xmm,			1,	1
zen5_wrap		vextracti32x4,		ymmi2xmm,			1,	2
zen5_wrap		vextracti32x4,		zmmi2xmm,			1,	1
zen5_wrap		vextractf64x2,		ymmi2xmm,			1,	2
zen5_wrap		vextractf64x2,		zmmi2xmm,			1,	1
zen5_wrap		vextracti64x2,		ymmi2xmm,			1,	2
zen5_wrap		vextracti64x2,		zmmi2xmm,			1,	1
zen5_wrap		vextractf32x8,		zmmi2ymm,			1,	1
zen5_wrap		vextracti32x8,		zmmi2ymm,			1,	1
zen5_wrap		vextractf64x4,		zmmi2ymm,			1,	1
zen5_wrap		vextracti64x4,		zmmi2ymm,			1,	1

zen5_wrap		vshufi32x4,			2ymmi2ymm,			1,	2
zen5_wrap		vshuff32x4,			2ymmi2ymm,			1,	2
zen5_wrap		vshufi64x2,			2zmmi2zmm,			1,	1
zen5_wrap		vshuff64x2,			2zmmi2zmm,			1,	1

zen5_wrap		vpshufbitqmb,		2xmm2k,				1,	2
zen5_wrap		vpshufbitqmb,		2ymm2k,				1,	2
zen5_wrap		vpshufbitqmb,		2zmm2k,				1,	1

zen5_wrap		vpshufbitqmb,		2xmmk2k,			1,	2
zen5_wrap		vpshufbitqmb,		2ymmk2k,			1,	2
zen5_wrap		vpshufbitqmb,		2zmmk2k,			1,	1

zen5_wrap		vptestmb,			2xmm2k,				1,	2
zen5_wrap		vptestmb,			2ymm2k,				1,	2
zen5_wrap		vptestmb,			2zmm2k,				1,	1
zen5_wrap		vptestmw,			2xmm2k,				1,	2
zen5_wrap		vptestmw,			2ymm2k,				1,	2
zen5_wrap		vptestmw,			2zmm2k,				1,	1
zen5_wrap		vptestmd,			2xmm2k,				1,	2
zen5_wrap		vptestmd,			2ymm2k,				1,	2
zen5_wrap		vptestmd,			2zmm2k,				1,	1
zen5_wrap		vptestmq,			2xmm2k,				1,	2
zen5_wrap		vptestmq,			2ymm2k,				1,	2
zen5_wrap		vptestmq,			2zmm2k,				1,	1

zen5_wrap		vptestmb,			2xmmk2k,			1,	2
zen5_wrap		vptestmb,			2ymmk2k,			1,	2
zen5_wrap		vptestmb,			2zmmk2k,			1,	1
zen5_wrap		vptestmw,			2xmmk2k,			1,	2
zen5_wrap		vptestmw,			2ymmk2k,			1,	2
zen5_wrap		vptestmw,			2zmmk2k,			1,	1
zen5_wrap		vptestmd,			2xmmk2k,			1,	2
zen5_wrap		vptestmd,			2ymmk2k,			1,	2
zen5_wrap		vptestmd,			2zmmk2k,			1,	1
zen5_wrap		vptestmq,			2xmmk2k,			1,	2
zen5_wrap		vptestmq,			2ymmk2k,			1,	2
zen5_wrap		vptestmq,			2zmmk2k,			1,	1

zen5_wrap		vptestnmb,			2xmm2k,				1,	2
zen5_wrap		vptestnmb,			2ymm2k,				1,	2
zen5_wrap		vptestnmb,			2zmm2k,				1,	1
zen5_wrap		vptestnmw,			2xmm2k,				1,	2
zen5_wrap		vptestnmw,			2ymm2k,				1,	2
zen5_wrap		vptestnmw,			2zmm2k,				1,	1
zen5_wrap		vptestnmd,			2xmm2k,				1,	2
zen5_wrap		vptestnmd,			2ymm2k,				1,	2
zen5_wrap		vptestnmd,			2zmm2k,				1,	1
zen5_wrap		vptestnmq,			2xmm2k,				1,	2
zen5_wrap		vptestnmq,			2ymm2k,				1,	2
zen5_wrap		vptestnmq,			2zmm2k,				1,	1

zen5_wrap		vptestnmb,			2xmmk2k,			1,	2
zen5_wrap		vptestnmb,			2ymmk2k,			1,	2
zen5_wrap		vptestnmb,			2zmmk2k,			1,	1
zen5_wrap		vptestnmw,			2xmmk2k,			1,	2
zen5_wrap		vptestnmw,			2ymmk2k,			1,	2
zen5_wrap		vptestnmw,			2zmmk2k,			1,	1
zen5_wrap		vptestnmd,			2xmmk2k,			1,	2
zen5_wrap		vptestnmd,			2ymmk2k,			1,	2
zen5_wrap		vptestnmd,			2zmmk2k,			1,	1
zen5_wrap		vptestnmq,			2xmmk2k,			1,	2
zen5_wrap		vptestnmq,			2ymmk2k,			1,	2
zen5_wrap		vptestnmq,			2zmmk2k,			1,	1

zen5_wrap		vpcmpeqb,			2xmm2k,				1,	2
zen5_wrap		vpcmpeqb,			2ymm2k,				1,	2
zen5_wrap		vpcmpeqb,			2zmm2k,				1,	1
zen5_wrap		vpcmpeqw,			2xmm2k,				1,	2
zen5_wrap		vpcmpeqw,			2ymm2k,				1,	2
zen5_wrap		vpcmpeqw,			2zmm2k,				1,	1
zen5_wrap		vpcmpeqd,			2xmm2k,				1,	2
zen5_wrap		vpcmpeqd,			2ymm2k,				1,	2
zen5_wrap		vpcmpeqd,			2zmm2k,				1,	1
zen5_wrap		vpcmpeqq,			2xmm2k,				1,	2
zen5_wrap		vpcmpeqq,			2ymm2k,				1,	2
zen5_wrap		vpcmpeqq,			2zmm2k,				1,	1

zen5_wrap		vpcmpeqb,			2xmmk2k,			1,	2
zen5_wrap		vpcmpeqb,			2ymmk2k,			1,	2
zen5_wrap		vpcmpeqb,			2zmmk2k,			1,	1
zen5_wrap		vpcmpeqw,			2xmmk2k,			1,	2
zen5_wrap		vpcmpeqw,			2ymmk2k,			1,	2
zen5_wrap		vpcmpeqw,			2zmmk2k,			1,	1
zen5_wrap		vpcmpeqd,			2xmmk2k,			1,	2
zen5_wrap		vpcmpeqd,			2ymmk2k,			1,	2
zen5_wrap		vpcmpeqd,			2zmmk2k,			1,	1
zen5_wrap		vpcmpeqq,			2xmmk2k,			1,	2
zen5_wrap		vpcmpeqq,			2ymmk2k,			1,	2
zen5_wrap		vpcmpeqq,			2zmmk2k,			1,	1

zen5_wrap		vpcmpgtb,			2xmm2k,				1,	2
zen5_wrap		vpcmpgtb,			2ymm2k,				1,	2
zen5_wrap		vpcmpgtb,			2zmm2k,				1,	1
zen5_wrap		vpcmpgtw,			2xmm2k,				1,	2
zen5_wrap		vpcmpgtw,			2ymm2k,				1,	2
zen5_wrap		vpcmpgtw,			2zmm2k,				1,	1
zen5_wrap		vpcmpgtd,			2xmm2k,				1,	2
zen5_wrap		vpcmpgtd,			2ymm2k,				1,	2
zen5_wrap		vpcmpgtd,			2zmm2k,				1,	1
zen5_wrap		vpcmpgtq,			2xmm2k,				1,	2
zen5_wrap		vpcmpgtq,			2ymm2k,				1,	2
zen5_wrap		vpcmpgtq,			2zmm2k,				1,	1

zen5_wrap		vpcmpgtb,			2xmmk2k,			1,	2
zen5_wrap		vpcmpgtb,			2ymmk2k,			1,	2
zen5_wrap		vpcmpgtb,			2zmmk2k,			1,	1
zen5_wrap		vpcmpgtw,			2xmmk2k,			1,	2
zen5_wrap		vpcmpgtw,			2ymmk2k,			1,	2
zen5_wrap		vpcmpgtw,			2zmmk2k,			1,	1
zen5_wrap		vpcmpgtd,			2xmmk2k,			1,	2
zen5_wrap		vpcmpgtd,			2ymmk2k,			1,	2
zen5_wrap		vpcmpgtd,			2zmmk2k,			1,	1
zen5_wrap		vpcmpgtq,			2xmmk2k,			1,	2
zen5_wrap		vpcmpgtq,			2ymmk2k,			1,	2
zen5_wrap		vpcmpgtq,			2zmmk2k,			1,	1

zen5_wrap		vpcmpgtb,			2xmm2kRot,			1,	2
zen5_wrap		vpcmpgtb,			2ymm2kRot,			1,	2
zen5_wrap		vpcmpgtb,			2zmm2kRot,			1,	1
zen5_wrap		vpcmpgtw,			2xmm2kRot,			1,	2
zen5_wrap		vpcmpgtw,			2ymm2kRot,			1,	2
zen5_wrap		vpcmpgtw,			2zmm2kRot,			1,	1
zen5_wrap		vpcmpgtd,			2xmm2kRot,			1,	2
zen5_wrap		vpcmpgtd,			2ymm2kRot,			1,	2
zen5_wrap		vpcmpgtd,			2zmm2kRot,			1,	1
zen5_wrap		vpcmpgtq,			2xmm2kRot,			1,	2
zen5_wrap		vpcmpgtq,			2ymm2kRot,			1,	2
zen5_wrap		vpcmpgtq,			2zmm2kRot,			1,	1

zen5_wrap		vpcmpgtb,			2xmmk2kRot,			1,	2
zen5_wrap		vpcmpgtb,			2ymmk2kRot,			1,	2
zen5_wrap		vpcmpgtb,			2zmmk2kRot,			1,	1
zen5_wrap		vpcmpgtw,			2xmmk2kRot,			1,	2
zen5_wrap		vpcmpgtw,			2ymmk2kRot,			1,	2
zen5_wrap		vpcmpgtw,			2zmmk2kRot,			1,	1
zen5_wrap		vpcmpgtd,			2xmmk2kRot,			1,	2
zen5_wrap		vpcmpgtd,			2ymmk2kRot,			1,	2
zen5_wrap		vpcmpgtd,			2zmmk2kRot,			1,	1
zen5_wrap		vpcmpgtq,			2xmmk2kRot,			1,	2
zen5_wrap		vpcmpgtq,			2ymmk2kRot,			1,	2
zen5_wrap		vpcmpgtq,			2zmmk2kRot,			1,	1

zen5_wrap		vpcmpb,				2xmmi2k,			1,	2
zen5_wrap		vpcmpb,				2ymmi2k,			1,	2
zen5_wrap		vpcmpb,				2zmmi2k,			1,	1
zen5_wrap		vpcmpw,				2xmmi2k,			1,	2
zen5_wrap		vpcmpw,				2ymmi2k,			1,	2
zen5_wrap		vpcmpw,				2zmmi2k,			1,	1
zen5_wrap		vpcmpd,				2xmmi2k,			1,	2
zen5_wrap		vpcmpd,				2ymmi2k,			1,	2
zen5_wrap		vpcmpd,				2zmmi2k,			1,	1
zen5_wrap		vpcmpq,				2xmmi2k,			1,	2
zen5_wrap		vpcmpq,				2ymmi2k,			1,	2
zen5_wrap		vpcmpq,				2zmmi2k,			1,	1

zen5_wrap		vpcmpb,				2xmmik2k,			1,	2
zen5_wrap		vpcmpb,				2ymmik2k,			1,	2
zen5_wrap		vpcmpb,				2zmmik2k,			1,	1
zen5_wrap		vpcmpw,				2xmmik2k,			1,	2
zen5_wrap		vpcmpw,				2ymmik2k,			1,	2
zen5_wrap		vpcmpw,				2zmmik2k,			1,	1
zen5_wrap		vpcmpd,				2xmmik2k,			1,	2
zen5_wrap		vpcmpd,				2ymmik2k,			1,	2
zen5_wrap		vpcmpd,				2zmmik2k,			1,	1
zen5_wrap		vpcmpq,				2xmmik2k,			1,	2
zen5_wrap		vpcmpq,				2ymmik2k,			1,	2
zen5_wrap		vpcmpq,				2zmmik2k,			1,	1

zen5_wrap		vpcmpub,			2xmmi2k,			1,	2
zen5_wrap		vpcmpub,			2ymmi2k,			1,	2
zen5_wrap		vpcmpub,			2zmmi2k,			1,	1
zen5_wrap		vpcmpuw,			2xmmi2k,			1,	2
zen5_wrap		vpcmpuw,			2ymmi2k,			1,	2
zen5_wrap		vpcmpuw,			2zmmi2k,			1,	1
zen5_wrap		vpcmpud,			2xmmi2k,			1,	2
zen5_wrap		vpcmpud,			2ymmi2k,			1,	2
zen5_wrap		vpcmpud,			2zmmi2k,			1,	1
zen5_wrap		vpcmpuq,			2xmmi2k,			1,	2
zen5_wrap		vpcmpuq,			2ymmi2k,			1,	2
zen5_wrap		vpcmpuq,			2zmmi2k,			1,	1

zen5_wrap		vpcmpub,			2xmmik2k,			1,	2
zen5_wrap		vpcmpub,			2ymmik2k,			1,	2
zen5_wrap		vpcmpub,			2zmmik2k,			1,	1
zen5_wrap		vpcmpuw,			2xmmik2k,			1,	2
zen5_wrap		vpcmpuw,			2ymmik2k,			1,	2
zen5_wrap		vpcmpuw,			2zmmik2k,			1,	1
zen5_wrap		vpcmpud,			2xmmik2k,			1,	2
zen5_wrap		vpcmpud,			2ymmik2k,			1,	2
zen5_wrap		vpcmpud,			2zmmik2k,			1,	1
zen5_wrap		vpcmpuq,			2xmmik2k,			1,	2
zen5_wrap		vpcmpuq,			2ymmik2k,			1,	2
zen5_wrap		vpcmpuq,			2zmmik2k,			1,	1

zen5_wrap		vcmpss,				2xmmi2k,			1,	2
zen5_wrap		vcmpps,				2xmmi2k,			1,	2
zen5_wrap		vcmpps,				2ymmi2k,			1,	2
zen5_wrap		vcmpps,				2zmmi2k,			1,	1

zen5_wrap		vcmpsd,				2xmmi2k,			1,	2
zen5_wrap		vcmppd,				2xmmi2k,			1,	2
zen5_wrap		vcmppd,				2ymmi2k,			1,	2
zen5_wrap		vcmppd,				2zmmi2k,			1,	1

zen5_wrap		vcmpss,				2xmmik2k,			1,	2
zen5_wrap		vcmpps,				2xmmik2k,			1,	2
zen5_wrap		vcmpps,				2ymmik2k,			1,	2
zen5_wrap		vcmpps,				2zmmik2k,			1,	1

zen5_wrap		vcmpsd,				2xmmik2k,			1,	2
zen5_wrap		vcmppd,				2xmmik2k,			1,	2
zen5_wrap		vcmppd,				2ymmik2k,			1,	2
zen5_wrap		vcmppd,				2zmmik2k,			1,	1

zen5_wrap		vfpclassss,			xmmi2k,				1,	2
zen5_wrap		vfpclassps,			xmmi2k,				1,	2
zen5_wrap		vfpclassps,			ymmi2k,				1,	2
zen5_wrap		vfpclassps,			zmmi2k,				1,	1

zen5_wrap		vfpclasssd,			xmmi2k,				1,	2
zen5_wrap		vfpclasspd,			xmmi2k,				1,	2
zen5_wrap		vfpclasspd,			ymmi2k,				1,	2
zen5_wrap		vfpclasspd,			zmmi2k,				1,	1

zen5_wrap		vfpclassss,			xmmik2k,			1,	2
zen5_wrap		vfpclassps,			xmmik2k,			1,	2
zen5_wrap		vfpclassps,			ymmik2k,			1,	2
zen5_wrap		vfpclassps,			zmmik2k,			1,	1

zen5_wrap		vfpclasssd,			xmmik2k,			1,	2
zen5_wrap		vfpclasspd,			xmmik2k,			1,	2
zen5_wrap		vfpclasspd,			ymmik2k,			1,	2
zen5_wrap		vfpclasspd,			zmmik2k,			1,	1

zen5_wrap		vpmovb2m,			xmm2k,				1,	2
zen5_wrap		vpmovb2m,			ymm2k,				1,	2
zen5_wrap		vpmovb2m,			zmm2k,				1,	1
zen5_wrap		vpmovw2m,			xmm2k,				1,	2
zen5_wrap		vpmovw2m,			ymm2k,				1,	2
zen5_wrap		vpmovw2m,			zmm2k,				1,	1
zen5_wrap		vpmovd2m,			xmm2k,				1,	2
zen5_wrap		vpmovd2m,			ymm2k,				1,	2
zen5_wrap		vpmovd2m,			zmm2k,				1,	1
zen5_wrap		vpmovq2m,			xmm2k,				1,	2
zen5_wrap		vpmovq2m,			ymm2k,				1,	2
zen5_wrap		vpmovq2m,			zmm2k,				1,	1

zen5_wrap		vpmovm2b,			k2xmm,				1,	4
zen5_wrap		vpmovm2b,			k2ymm,				1,	4
zen5_wrap		vpmovm2b,			k2zmm,				1,	2
zen5_wrap		vpmovm2w,			k2xmm,				1,	4
zen5_wrap		vpmovm2w,			k2ymm,				1,	4
zen5_wrap		vpmovm2w,			k2zmm,				1,	2
zen5_wrap		vpmovm2d,			k2xmm,				1,	4
zen5_wrap		vpmovm2d,			k2ymm,				1,	4
zen5_wrap		vpmovm2d,			k2zmm,				1,	2
zen5_wrap		vpmovm2q,			k2xmm,				1,	4
zen5_wrap		vpmovm2q,			k2ymm,				1,	4
zen5_wrap		vpmovm2q,			k2zmm,				1,	2

zen5_wrap		vpbroadcastmb2q,	k2xmm,				1,	2
zen5_wrap		vpbroadcastmb2q,	k2ymm,				1,	2
zen5_wrap		vpbroadcastmb2q,	k2zmm,				1,	1
zen5_wrap		vpbroadcastmw2d,	k2xmm,				1,	2
zen5_wrap		vpbroadcastmw2d,	k2ymm,				1,	2
zen5_wrap		vpbroadcastmw2d,	k2zmm,				1,	1

zen5_wrap		vpermilpd,			evex_xmmi2xmm,		1,	4
zen5_wrap		vpermilpd,			evex_ymmi2ymm,		1,	4
zen5_wrap		vpermilpd,			zmmi2zmm,			1,	2

zen5_wrap		vpermilps,			evex_xmmi2xmm,		1,	4
zen5_wrap		vpermilps,			evex_ymmi2ymm,		1,	4
zen5_wrap		vpermilps,			zmmi2zmm,			1,	2

zen5_wrap		vpunpcklbw,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpcklbw,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpcklbw,			2zmm2zmm,			1,	2

zen5_wrap		vpunpckhbw,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpckhbw,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpckhbw,			2zmm2zmm,			1,	2

zen5_wrap		vpunpcklwd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpcklwd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpcklwd,			2zmm2zmm,			1,	2

zen5_wrap		vpunpckhwd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpckhwd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpckhwd,			2zmm2zmm,			1,	2

zen5_wrap		vpunpckldq,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpckldq,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpckldq,			2zmm2zmm,			1,	2

zen5_wrap		vpunpckhdq,			evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpckhdq,			evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpckhdq,			2zmm2zmm,			1,	2

zen5_wrap		vpunpcklqdq,		evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpcklqdq,		evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpcklqdq,		2zmm2zmm,			1,	2

zen5_wrap		vpunpckhqdq,		evex_2xmm2xmm,		1,	4
zen5_wrap		vpunpckhqdq,		evex_2ymm2ymm,		1,	4
zen5_wrap		vpunpckhqdq,		2zmm2zmm,			1,	2

zen5_wrap		vunpcklps,			evex_2xmm2xmm,		1,	4
zen5_wrap		vunpcklps,			evex_2ymm2ymm,		1,	4
zen5_wrap		vunpcklps,			2zmm2zmm,			1,	2

zen5_wrap		vunpckhps,			evex_2xmm2xmm,		1,	4
zen5_wrap		vunpckhps,			evex_2ymm2ymm,		1,	4
zen5_wrap		vunpckhps,			2zmm2zmm,			1,	2

zen5_wrap		vunpcklpd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vunpcklpd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vunpcklpd,			2zmm2zmm,			1,	2

zen5_wrap		vunpckhpd,			evex_2xmm2xmm,		1,	4
zen5_wrap		vunpckhpd,			evex_2ymm2ymm,		1,	4
zen5_wrap		vunpckhpd,			2zmm2zmm,			1,	2

zen5_wrap		vmovhlps,			evex_2xmm2xmm,		1,	4
zen5_wrap		vmovlhps,			evex_2xmm2xmm,		1,	4
	
zen5_wrap		vshufpd,			evex_2xmmi2xmm,		1,	4
zen5_wrap		vshufpd,			evex_2ymmi2ymm,		1,	4
zen5_wrap		vshufpd,			2zmmi2zmm,			1,	2

zen5_wrap		vshufps,			evex_2xmmi2xmm,		1,	4
zen5_wrap		vshufps,			evex_2ymmi2ymm,		1,	4
zen5_wrap		vshufps,			2zmmi2zmm,			1,	2

zen5_wrap		vpshuflw,			evex_xmmi2xmm,		1,	4
zen5_wrap		vpshuflw,			evex_ymmi2ymm,		1,	4
zen5_wrap		vpshuflw,			zmmi2zmm,			1,	2

zen5_wrap		vpshufhw,			evex_xmmi2xmm,		1,	4
zen5_wrap		vpshufhw,			evex_ymmi2ymm,		1,	4
zen5_wrap		vpshufhw,			zmmi2zmm,			1,	2

zen5_wrap		vpshufd,			evex_xmmi2xmm,		1,	4
zen5_wrap		vpshufd,			evex_ymmi2ymm,		1,	4
zen5_wrap		vpshufd,			zmmi2zmm,			1,	2

zen5_wrap		vmovsldup,			evex_xmm2xmm,		1,	4
zen5_wrap		vmovsldup,			evex_ymm2ymm,		1,	4
zen5_wrap		vmovsldup,			zmm2zmm,			1,	2

zen5_wrap		vmovshdup,			evex_xmm2xmm,		1,	4
zen5_wrap		vmovshdup,			evex_ymm2ymm,		1,	4
zen5_wrap		vmovshdup,			zmm2zmm,			1,	2

zen5_wrap		vinsertps,			evex_2xmmi2xmm,		1,	4

zen5_wrap		kandb,				2k2k,				1,	2
zen5_wrap		kandw,				2k2k,				1,	2
zen5_wrap		kandd,				2k2k,				1,	2
zen5_wrap		kandq,				2k2k,				1,	2
zen5_wrap		kandnb,				2k2k,				1,	2
zen5_wrap		kandnw,				2k2k,				1,	2
zen5_wrap		kandnd,				2k2k,				1,	2
zen5_wrap		kandnq,				2k2k,				1,	2
zen5_wrap		kandnb,				2k2kRot,			1,	2
zen5_wrap		kandnw,				2k2kRot,			1,	2
zen5_wrap		kandnd,				2k2kRot,			1,	2
zen5_wrap		kandnq,				2k2kRot,			1,	2
zen5_wrap		kaddb,				2k2k,				1,	2
zen5_wrap		kaddw,				2k2k,				1,	2
zen5_wrap		kaddd,				2k2k,				1,	2
zen5_wrap		kaddq,				2k2k,				1,	2
zen5_wrap		korb,				2k2k,				1,	2
zen5_wrap		korw,				2k2k,				1,	2
zen5_wrap		kord,				2k2k,				1,	2
zen5_wrap		korq,				2k2k,				1,	2
zen5_wrap		korb,				2k2kRot,			1,	2
zen5_wrap		korw,				2k2kRot,			1,	2
zen5_wrap		kord,				2k2kRot,			1,	2
zen5_wrap		korq,				2k2kRot,			1,	2
zen5_wrap		kxorb,				2k2k,				1,	2
zen5_wrap		kxorw,				2k2k,				1,	2
zen5_wrap		kxord,				2k2k,				1,	2
zen5_wrap		kxorq,				2k2k,				1,	2
zen5_wrap		kxorb,				2k2kRot,			1,	2
zen5_wrap		kxorw,				2k2kRot,			1,	2
zen5_wrap		kxord,				2k2kRot,			1,	2
zen5_wrap		kxorq,				2k2kRot,			1,	2
zen5_wrap		kxnorb,				2k2k,				1,	2
zen5_wrap		kxnorw,				2k2k,				1,	2
zen5_wrap		kxnord,				2k2k,				1,	2
zen5_wrap		kxnorq,				2k2k,				1,	2
zen5_wrap		kxnorb,				2k2kRot,			1,	2
zen5_wrap		kxnorw,				2k2kRot,			1,	2
zen5_wrap		kxnord,				2k2kRot,			1,	2
zen5_wrap		kxnorq,				2k2kRot,			1,	2
zen5_wrap		knotb,				k2k,				1,	2
zen5_wrap		knotw,				k2k,				1,	2
zen5_wrap		knotd,				k2k,				1,	2
zen5_wrap		knotq,				k2k,				1,	2

zen5_wrap		kmovb,				k2k,				1,	2
zen5_wrap		kmovw,				k2k,				1,	2
zen5_wrap		kmovd,				k2k,				1,	2
zen5_wrap		kmovq,				k2k,				1,	2

zen5_wrap		kshiftlb,			ki2k,				1,	2
zen5_wrap		kshiftlw,			ki2k,				1,	2
zen5_wrap		kshiftld,			ki2k,				1,	2
zen5_wrap		kshiftlq,			ki2k,				1,	2
zen5_wrap		kshiftrb,			ki2k,				1,	2
zen5_wrap		kshiftrw,			ki2k,				1,	2
zen5_wrap		kshiftrd,			ki2k,				1,	2
zen5_wrap		kshiftrq,			ki2k,				1,	2

zen5_wrap		ktestb,				2k2c,				2,	2
zen5_wrap		ktestw,				2k2c,				2,	2
zen5_wrap		ktestd,				2k2c,				2,	2
zen5_wrap		ktestq,				2k2c,				2,	2
zen5_wrap		kortestb,			2k2c,				2,	2
zen5_wrap		kortestw,			2k2c,				2,	2
zen5_wrap		kortestd,			2k2c,				2,	2
zen5_wrap		kortestq,			2k2c,				2,	2

zen5_wrap		vcvtps2dq,			evex_xmm2xmm,		1,	2
zen5_wrap		vcvtps2dq,			evex_ymm2ymm,		1,	2
zen5_wrap		vcvtps2dq,			zmm2zmm,			1,	1

zen5_wrap		vcvtpd2qq,			evex_xmm2xmm,		1,	2
zen5_wrap		vcvtpd2qq,			evex_ymm2ymm,		1,	2
zen5_wrap		vcvtpd2qq,			zmm2zmm,			1,	1

zen5_wrap		vcvtps2pd,			evex_xmm2xmm,		2,	2
zen5_wrap		vcvtps2pd,			evex_xmm2ymm,		2,	2
zen5_wrap		vcvtps2pd,			ymm2zmm,			2,	1

zen5_wrap		vcvtph2ps,			evex_xmm2xmm,		2,	2
zen5_wrap		vcvtph2ps,			evex_xmm2ymm,		2,	2
zen5_wrap		vcvtph2ps,			ymm2zmm,			2,	1

zen5_wrap		vcvtpd2ps,			evex_xmm2xmm,		2,	2
zen5_wrap		vcvtpd2ps,			evex_ymm2xmm,		2,	2
zen5_wrap		vcvtpd2ps,			zmm2ymm,			2,	1

zen5_wrap		vcvtps2ph,			evex_xmmi2xmm,		2,	2
zen5_wrap		vcvtps2ph,			evex_ymmi2xmm,		2,	2
zen5_wrap		vcvtps2ph,			zmmi2ymm,			2,	1

zen5_wrap		vcvtneps2bf16,		xmm2xmm,			2,	2
zen5_wrap		vcvtneps2bf16,		ymm2xmm,			2,	2
zen5_wrap		vcvtneps2bf16,		zmm2ymm,			2,	1

zen5_wrap		vcvtne2ps2bf16,		2xmm2xmm,			2,	2
zen5_wrap		vcvtne2ps2bf16,		2ymm2ymm,			2,	2
zen5_wrap		vcvtne2ps2bf16,		2zmm2zmm,			2,	1

zen5_wrap		vdpbf16ps,			2xmm2xmm,			1,	2
zen5_wrap		vdpbf16ps,			2ymm2ymm,			1,	2
zen5_wrap		vdpbf16ps,			2zmm2zmm,			1,	1

zen5_wrap		vpconflictd,		xmm2xmm,			2,	1
zen5_wrap		vpconflictd,		ymm2ymm,			2,	1
zen5_wrap		vpconflictd,		zmm2zmm,			2,	1
zen5_wrap		vpconflictq,		xmm2xmm,			2,	1
zen5_wrap		vpconflictq,		ymm2ymm,			2,	1
zen5_wrap		vpconflictq,		zmm2zmm,			2,	1

zen5_wrap		vp2intersectd,		2xmm2k,				2,	1
zen5_wrap		vp2intersectd,		2ymm2k,				2,	1
zen5_wrap		vp2intersectd,		2zmm2k,				2,	1
zen5_wrap		vp2intersectq,		2xmm2k,				2,	1
zen5_wrap		vp2intersectq,		2ymm2k,				2,	1
zen5_wrap		vp2intersectq,		2zmm2k,				2,	1

zen5_wrap		vpcompressb,		xmm2xmm,			2,	1
zen5_wrap		vpcompressw,		xmm2xmm,			2,	1
zen5_wrap		vpcompressd,		xmm2xmm,			2,	1
zen5_wrap		vpcompressq,		xmm2xmm,			2,	1
zen5_wrap		vcompressps,		xmm2xmm,			2,	1
zen5_wrap		vcompresspd,		xmm2xmm,			2,	1

zen5_wrap		vpexpandb,			xmm2xmm,			2,	1
zen5_wrap		vpexpandw,			xmm2xmm,			2,	1
zen5_wrap		vpexpandd,			xmm2xmm,			2,	1
zen5_wrap		vpexpandq,			xmm2xmm,			2,	1
zen5_wrap		vexpandps,			xmm2xmm,			2,	1
zen5_wrap		vexpandpd,			xmm2xmm,			2,	1

zen5_wrap		vpcompressb,		ymm2ymm,			2,	1
zen5_wrap		vpcompressw,		ymm2ymm,			2,	1
zen5_wrap		vpcompressd,		ymm2ymm,			2,	1
zen5_wrap		vpcompressq,		ymm2ymm,			2,	1
zen5_wrap		vcompressps,		ymm2ymm,			2,	1
zen5_wrap		vcompresspd,		ymm2ymm,			2,	1

zen5_wrap		vpexpandb,			ymm2ymm,			2,	1
zen5_wrap		vpexpandw,			ymm2ymm,			2,	1
zen5_wrap		vpexpandd,			ymm2ymm,			2,	1
zen5_wrap		vpexpandq,			ymm2ymm,			2,	1
zen5_wrap		vexpandps,			ymm2ymm,			2,	1
zen5_wrap		vexpandpd,			ymm2ymm,			2,	1

zen5_wrap		vpcompressb,		zmm2zmm,			2,	1
zen5_wrap		vpcompressw,		zmm2zmm,			2,	1
zen5_wrap		vpcompressd,		zmm2zmm,			2,	1
zen5_wrap		vpcompressq,		zmm2zmm,			2,	1
zen5_wrap		vcompressps,		zmm2zmm,			2,	1
zen5_wrap		vcompresspd,		zmm2zmm,			2,	1

zen5_wrap		vpexpandb,			zmm2zmm,			2,	1
zen5_wrap		vpexpandw,			zmm2zmm,			2,	1
zen5_wrap		vpexpandd,			zmm2zmm,			2,	1
zen5_wrap		vpexpandq,			zmm2zmm,			2,	1
zen5_wrap		vexpandps,			zmm2zmm,			2,	1
zen5_wrap		vexpandpd,			zmm2zmm,			2,	1

zen5_wrap		vpbroadcastb,		gpr32_2xmm,			1,	1
zen5_wrap		vpbroadcastb,		gpr32_2ymm,			1,	1
zen5_wrap		vpbroadcastb,		gpr32_2zmm,			1,	1

zen5_wrap		vpbroadcastw,		gpr32_2xmm,			1,	1
zen5_wrap		vpbroadcastw,		gpr32_2ymm,			1,	1
zen5_wrap		vpbroadcastw,		gpr32_2zmm,			1,	1

zen5_wrap		vpbroadcastd,		gpr32_2xmm,			1,	1
zen5_wrap		vpbroadcastd,		gpr32_2ymm,			1,	1
zen5_wrap		vpbroadcastd,		gpr32_2zmm,			1,	1

zen5_wrap		vpbroadcastq,		gpr64_2xmm,			1,	1
zen5_wrap		vpbroadcastq,		gpr64_2ymm,			1,	1
zen5_wrap		vpbroadcastq,		gpr64_2zmm,			1,	1

zen5_wrap		vpbroadcastb,		gpr32_2kxmm,		1,	1
zen5_wrap		vpbroadcastb,		gpr32_2kymm,		1,	1
zen5_wrap		vpbroadcastb,		gpr32_2kzmm,		1,	1

zen5_wrap		vpbroadcastw,		gpr32_2kxmm,		1,	1
zen5_wrap		vpbroadcastw,		gpr32_2kymm,		1,	1
zen5_wrap		vpbroadcastw,		gpr32_2kzmm,		1,	1

zen5_wrap		vpbroadcastd,		gpr32_2kxmm,		1,	1
zen5_wrap		vpbroadcastd,		gpr32_2kymm,		1,	1
zen5_wrap		vpbroadcastd,		gpr32_2kzmm,		1,	1

zen5_wrap		vpbroadcastq,		gpr64_2kxmm,		1,	1
zen5_wrap		vpbroadcastq,		gpr64_2kymm,		1,	1
zen5_wrap		vpbroadcastq,		gpr64_2kzmm,		1,	1

zen5_wrap		vpbroadcastb,		gpr32_2zkxmm,		1,	1
zen5_wrap		vpbroadcastb,		gpr32_2zkymm,		1,	1
zen5_wrap		vpbroadcastb,		gpr32_2zkzmm,		1,	1

zen5_wrap		vpbroadcastw,		gpr32_2zkxmm,		1,	1
zen5_wrap		vpbroadcastw,		gpr32_2zkymm,		1,	1
zen5_wrap		vpbroadcastw,		gpr32_2zkzmm,		1,	1

zen5_wrap		vpbroadcastd,		gpr32_2zkxmm,		1,	1
zen5_wrap		vpbroadcastd,		gpr32_2zkymm,		1,	1
zen5_wrap		vpbroadcastd,		gpr32_2zkzmm,		1,	1

zen5_wrap		vpbroadcastq,		gpr64_2zkxmm,		1,	1
zen5_wrap		vpbroadcastq,		gpr64_2zkymm,		1,	1
zen5_wrap		vpbroadcastq,		gpr64_2zkzmm,		1,	1

zen5_wrap		kmovb,				gpr32_2k,			1,	1
zen5_wrap		kmovw,				gpr32_2k,			1,	1
zen5_wrap		kmovd,				gpr32_2k,			1,	1
zen5_wrap		kmovq,				gpr64_2k,			1,	1

zen5_wrap		kmovb,				k2gpr32,			1,	2
zen5_wrap		kmovw,				k2gpr32,			1,	2
zen5_wrap		kmovd,				k2gpr32,			1,	2
zen5_wrap		kmovq,				k2gpr64,			1,	2



end