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
	IFIDNI <INST>, <PGRP>
		mov				r9,  qword ptr [exch1 + disp]
		pext			rdx, rax, r9
		popcnt			r8, r9
		not				r9
		pext			r9, rax, r9
		shlx			r9, r9, r8
		or				rdx, r9
	ELSE
		INST			rdx, rax, qword ptr [exch1 + disp]
	ENDIF
	mov				qword ptr [exch2 + disp], rdx
endm

B32_HW_Core macro disp, INST
	mov				eax, dword ptr [exch0 + disp]
	IFIDNI <INST>, <PGRP>
		mov				r9d,  dword ptr [exch1 + disp]
		pext			edx, eax, r9d
		popcnt			r8d, r9d
		not				r9d
		pext			r9d, eax, r9d
		shlx			r9d, r9d, r8d
		or				edx, r9d
	ELSE
		INST			edx, eax, dword ptr [exch1 + disp]
	ENDIF
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

TIMED macro PNAME, INIT, BITNESS, CORE, INST, CPU, TPLAT
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

IFIDNI <TPLAT>, <LAT>
	IF BITNESS EQ 64
		vmovdqa64		zmm1, zmm0
	ELSE
		vmovdqa32		zmm1, zmm0
	ENDIF
ELSEIFIDNI <TPLAT>, <TP>
	vpxor			xmm0, xmm0, xmm0
	vpxor			xmm1, xmm1, xmm1
ENDIF

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

TIMED	BEXT64_HW_Lat,			EMPTY_Init,		64,	HW,				PEXT,	SKX, LAT
TIMED	BDEP64_HW_Lat,			EMPTY_Init,		64,	HW,				PDEP,	SKX, LAT
TIMED	BGRP64_HW_Lat,			EMPTY_Init,		64,	HW,				PGRP,	SKX, LAT
TIMED	BEXT32_HW_Lat,			EMPTY_Init,		32,	HW,				PEXT,	SKX, LAT
TIMED	BDEP32_HW_Lat,			EMPTY_Init,		32,	HW,				PDEP,	SKX, LAT
TIMED	BGRP32_HW_Lat,			EMPTY_Init,		32,	HW,				PGRP,	SKX, LAT

TIMED	BEXT64_HW_Tp,			EMPTY_Init,		64,	HW,				PEXT,	SKX, TP
TIMED	BDEP64_HW_Tp,			EMPTY_Init,		64,	HW,				PDEP,	SKX, TP
TIMED	BGRP64_HW_Tp,			EMPTY_Init,		64,	HW,				PGRP,	SKX, TP
TIMED	BEXT32_HW_Tp,			EMPTY_Init,		32,	HW,				PEXT,	SKX, TP
TIMED	BDEP32_HW_Tp,			EMPTY_Init,		32,	HW,				PDEP,	SKX, TP
TIMED	BGRP32_HW_Tp,			EMPTY_Init,		32,	HW,				PGRP,	SKX, TP

NAKED	BEXT64_HW@@128,			EMPTY_Init,		64,	HW,				PEXT,	SKX
NAKED	BDEP64_HW@@128,			EMPTY_Init,		64,	HW,				PDEP,	SKX
NAKED	BGRP64_HW@@128,			EMPTY_Init,		64,	HW,				PGRP,	SKX
NAKED	BEXT32_HW@@128,			EMPTY_Init,		32,	HW,				PEXT,	SKX
NAKED	BDEP32_HW@@128,			EMPTY_Init,		32,	HW,				PDEP,	SKX
NAKED	BGRP32_HW@@128,			EMPTY_Init,		32,	HW,				PGRP,	SKX

end