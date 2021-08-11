.data

savereg			dq	00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h
savereg2		dq	00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h

exch0			dq	00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h
exch1			dq	00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h
exch2			dq	00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h, 00000000000000000h

.code 

EMPTY_Init macro EMPTYPAR, INST, CPU
endm

B64_HW_Core macro disp, INST
	mov				rax, qword ptr [exch0 + disp]
	INST			rdx, rax, qword ptr [exch1 + disp]
	mov				qword ptr [exch2 + disp], rdx
endm

B32_HW_Core macro disp, INST
	mov				eax, dword ptr [exch0 + disp]
	INST			edx, eax, dword ptr [exch1 + disp]
	mov				dword ptr [exch2 + disp], edx
endm

HW macro BITNESS, INST
IF BITNESS EQ 64
	vmovdqu64		zmmword ptr [exch0], zmm0
	vmovdqu64		zmmword ptr [exch1], zmm1
ELSE
	vmovdqu32		zmmword ptr [exch0], zmm0
	vmovdqu32		zmmword ptr [exch1], zmm1
ENDIF

	disp = 00h
	REPEAT 512 / BITNESS
		IF BITNESS EQ 64
			B64_HW_Core	disp, INST
		ELSE
			B32_HW_Core	disp, INST
		ENDIF
		disp = disp + (BITNESS / 8)
	endm

IF BITNESS EQ 64
	vmovdqu64		zmm0, zmmword ptr [exch2]
ELSE
	vmovdqu32		zmm0, zmmword ptr [exch2]
ENDIF
endm

TIMED macro PNAME, INIT, BITNESS, CORE, INST, CPU
PNAME proc
	push			rbx
	push			rdi
	push			rsi

	INIT			BITNESS, INST, CPU
	
	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, DEPEXT219_REPEATS

align 16
startlabel:
	CORE			BITNESS, INST

	dec				ecx
	jnz				startlabel

	mfence
	rdtscp
	lfence

	shl				rdx, 20h
	shl				rdi, 20h
	or				rax, rdx
	or				rsi, rdi

	sub				rax, rsi


	pop				rsi
	pop				rdi
	pop				rbx
	ret
PNAME endp
endm

NAKED macro PNAME, INIT, BITNESS, CORE, INST, CPU
PNAME proc

	INIT			BITNESS, INST, CPU

	CORE			BITNESS, INST


	ret
PNAME endp
endm

;Creadit: Travis Downs
;https://twitter.com/trav_downs/status/1418616866080116742?

TIMED	PEXT64_HW_Time,		EMPTY_Init,			64,	HW,				PEXT,	SKX
TIMED	PDEP64_HW_Time,		EMPTY_Init,			64,	HW,				PDEP,	SKX
TIMED	PEXT32_HW_Time,		EMPTY_Init,			32,	HW,				PEXT,	SKX
TIMED	PDEP32_HW_Time,		EMPTY_Init,			32,	HW,				PDEP,	SKX
NAKED	PEXT64_HW@@128,		EMPTY_Init,			64,	HW,				PEXT,	SKX
NAKED	PDEP64_HW@@128,		EMPTY_Init,			64,	HW,				PDEP,	SKX
NAKED	PEXT32_HW@@128,		EMPTY_Init,			32,	HW,				PEXT,	SKX
NAKED	PDEP32_HW@@128,		EMPTY_Init,			32,	HW,				PDEP,	SKX

end