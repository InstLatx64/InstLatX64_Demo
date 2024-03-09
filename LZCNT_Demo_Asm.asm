.data

gfni_revbit		dq  08040201008040201h
gfni_tzcnt		dq  0aaccf0ff00000000h

fp16_expbias	dd	001e001eh
max_lzcntw		dd	00100010h

repeats			equ	1000000h

.code 

INIT8 macro VECREGSIZE, ISA
IFIDNI <ISA>, <BITALG>
	IFIDNI <VECREGSIZE>, <XMM>
		vpcmpeqb		xmm1, xmm1, xmm1
		vmovddup		xmm2, qword ptr [gfni_revbit]
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vpcmpeqb		ymm1, ymm1, ymm1
		vpbroadcastq	ymm2, qword ptr [gfni_revbit]
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vpternlogd		zmm1, zmm1, zmm1, 0ffh
		vpbroadcastq	zmm2, qword ptr [gfni_revbit]
	ENDIF
ELSEIFIDNI <ISA>, <GFNI>
	IFIDNI <VECREGSIZE>, <XMM>
		vpcmpeqb		xmm1, xmm1, xmm1
		vmovddup		xmm2, qword ptr [gfni_revbit]
		vmovddup		xmm3, qword ptr [gfni_tzcnt]
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vpcmpeqb		ymm1, ymm1, ymm1
		vpbroadcastq	ymm2, qword ptr [gfni_revbit]
		vpbroadcastq	ymm3, qword ptr [gfni_tzcnt]
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vpternlogd		zmm1, zmm1, zmm1, 0ffh
		vpbroadcastq	zmm2, qword ptr [gfni_revbit]
		vpbroadcastq	zmm3, qword ptr [gfni_tzcnt]
	ENDIF
ENDIF
endm

CORE8 macro VECREGSIZE, ISA
IFIDNI <ISA>, <BITALG>
	IFIDNI <VECREGSIZE>, <XMM>
		vgf2p8affineqb	xmm0, xmm0, xmm2, 0
		vpaddb			xmm3, xmm0, xmm1
		vpandn			xmm0, xmm0, xmm3
		vpopcntb		xmm0, xmm0
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vgf2p8affineqb	ymm0, ymm0, ymm2, 0
		vpaddb			ymm3, ymm0, ymm1
		vpandn			ymm0, ymm0, ymm3
		vpopcntb		ymm0, ymm0
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vgf2p8affineqb	zmm0, zmm0, zmm2, 0
		vpaddb			zmm3, zmm0, zmm1
		vpandnq			zmm0, zmm0, zmm3
		vpopcntb		zmm0, zmm0
	ENDIF
ELSEIFIDNI <ISA>, <GFNI>
	IFIDNI <VECREGSIZE>, <XMM>
		vgf2p8affineqb	xmm0, xmm0, xmm2, 0
		vpaddb			xmm4, xmm0, xmm1
		vpandn			xmm0, xmm4, xmm0
		vgf2p8affineqb	xmm0, xmm0, xmm3, 08h
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vgf2p8affineqb	ymm0, ymm0, ymm2, 0
		vpaddb			ymm4, ymm0, ymm1
		vpandn			ymm0, ymm4, ymm0
		vgf2p8affineqb	ymm0, ymm0, ymm3, 08h
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vgf2p8affineqb	zmm0, zmm0, zmm2, 0
		vpaddb			zmm4, zmm0, zmm1
		vpandnq			zmm0, zmm4, zmm0
		vgf2p8affineqb	zmm0, zmm0, zmm3, 08h
	ENDIF
ENDIF
endm

INIT16 macro VECREGSIZE, ISA
IFIDNI <ISA>, <BITALG>
	IFIDNI <VECREGSIZE>, <XMM>
		vpcmpeqw		xmm1, xmm1, xmm1
		vmovddup		xmm2, qword ptr [gfni_revbit]
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vpcmpeqb		ymm1, ymm1, ymm1
		vpbroadcastq	ymm2, qword ptr [gfni_revbit]
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vpternlogd		zmm1, zmm1, zmm1, 0ffh
		vpbroadcastq	zmm2, qword ptr [gfni_revbit]
	ENDIF
ELSEIFIDNI <ISA>, <FP16>
	IFIDNI <VECREGSIZE>, <XMM>
		;vpbroadcastd	ymm1, dword ptr [fp16_expbias]
		;vpbroadcastd	ymm2, dword ptr [max_lzcntw]
		vpxor			xmm2, xmm2, xmm2
		vgf2p8affineqb	xmm1, xmm2, xmm2, 0f0h	;001eh const gen
		vgf2p8affineqb	xmm2, xmm2, xmm2, 080h	;0010h const gen
		vpsrlw			xmm1, xmm1, 0bh			;001eh
		vpsrlw			xmm2, xmm2, 0bh			;0010h
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		;vpbroadcastd	ymm1, dword ptr [fp16_expbias]
		;vpbroadcastd	ymm2, dword ptr [max_lzcntw]
		vpxor			xmm2, xmm2, xmm2
		vgf2p8affineqb	ymm1, ymm2, ymm2, 0f0h	;001eh const gen
		vgf2p8affineqb	ymm2, ymm2, ymm2, 080h	;0010h const gen
		vpsrlw			ymm1, ymm1, 0bh			;001eh
		vpsrlw			ymm2, ymm2, 0bh			;0010h
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		;vpbroadcastd	zmm1, dword ptr [fp16_expbias]
		;vpbroadcastd	zmm2, dword ptr [max_lzcntw]
		vpxor			xmm2, xmm2, xmm2
		vgf2p8affineqb	zmm1, zmm2, zmm2, 0f0h	;001eh const gen
		vgf2p8affineqb	zmm2, zmm2, zmm2, 080h	;0010h const gen
		vpsrlw			zmm1, zmm1, 0bh			;001eh
		vpsrlw			zmm2, zmm2, 0bh			;0010h
	ENDIF
ENDIF
endm

CORE16 macro VECREGSIZE, ISA
IFIDNI <ISA>, <BITALG>
	IFIDNI <VECREGSIZE>, <XMM>
		vpshldw			xmm0, xmm0, xmm0, 8
		vgf2p8affineqb	xmm0, xmm0, xmm2, 0
		vpaddw			xmm3, xmm0, xmm1
		vpandn			xmm0, xmm0, xmm3
		vpopcntw		xmm0, xmm0
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vpshldw			ymm0, ymm0, ymm0, 8
		vgf2p8affineqb	ymm0, ymm0, ymm2, 0
		vpaddw			ymm3, ymm0, ymm1
		vpandn			ymm0, ymm0, ymm3
		vpopcntw		ymm0, ymm0
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vpshldw			zmm0, zmm0, zmm0, 8
		vgf2p8affineqb	zmm0, zmm0, zmm2, 0
		vpaddw			zmm3, zmm0, zmm1
		vpandnd			zmm0, zmm0, zmm3
		vpopcntw		zmm0, zmm0
	ENDIF
ELSEIFIDNI <ISA>, <FP16>
	IFIDNI <VECREGSIZE>, <XMM>
		vcvtuw2ph		xmm0, xmm0
		vpsrlw			xmm0, xmm0, 0ah
		vpsubw			xmm0, xmm1, xmm0
		vpminuw			xmm0, xmm0, xmm2
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vcvtuw2ph		ymm0, ymm0
		vpsrlw			ymm0, ymm0, 0ah
		vpsubw			ymm0, ymm1, ymm0
		vpminuw			ymm0, ymm0, ymm2
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vcvtuw2ph		zmm0, zmm0
		vpsrlw			zmm0, zmm0, 0ah
		vpsubw			zmm0, zmm1, zmm0
		vpminuw			zmm0, zmm0, zmm2
	ENDIF
ENDIF
endm


TIMED macro PNAME, DATA, VECREGSIZE, ISA
PNAME proc
	push			rbx
	push			rdi
	push			rsi

IFIDNI <DATA>, <EPI8>
	INIT8			VECREGSIZE, ISA
ELSEIFIDNI <DATA>, <EPI16>
	INIT16			VECREGSIZE, ISA
ENDIF

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

align 16
startlabel:
IFIDNI <DATA>, <EPI8>
	CORE8			VECREGSIZE, ISA
ELSEIFIDNI <DATA>, <EPI16>
	CORE16			VECREGSIZE, ISA
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

NAKED macro PNAME, DATA, VECREGSIZE, ISA
PNAME proc

IFIDNI <DATA>, <EPI8>
	INIT8			VECREGSIZE, ISA
ELSEIFIDNI <DATA>, <EPI16>
	INIT16			VECREGSIZE, ISA
ENDIF

IFIDNI <DATA>, <EPI8>
	CORE8			VECREGSIZE, ISA
ELSEIFIDNI <DATA>, <EPI16>
	CORE16			VECREGSIZE, ISA
ENDIF

	ret
PNAME endp
endm

TIMED _mm_lzcnt_epi8_asm_timed,				EPI8,	XMM,	BITALG
TIMED _mm256_lzcnt_epi8_asm_timed,			EPI8,	YMM,	BITALG
TIMED _mm512_lzcnt_epi8_asm_timed,			EPI8,	ZMM,	BITALG

NAKED _mm_lzcnt_epi8_asm@@16,				EPI8,	XMM,	BITALG
NAKED _mm256_lzcnt_epi8_asm@@32,			EPI8,	YMM,	BITALG
NAKED _mm512_lzcnt_epi8_asm@@64,			EPI8,	ZMM,	BITALG

TIMED _mm_lzcnt_gfni_epi8_asm_timed,		EPI8,	XMM,	GFNI
TIMED _mm256_lzcnt_gfni_epi8_asm_timed,		EPI8,	YMM,	GFNI
TIMED _mm512_lzcnt_gfni_epi8_asm_timed,		EPI8,	ZMM,	GFNI

NAKED _mm_lzcnt_gfni_epi8_asm@@16,			EPI8,	XMM,	GFNI
NAKED _mm256_lzcnt_gfni_epi8_asm@@32,		EPI8,	YMM,	GFNI
NAKED _mm512_lzcnt_gfni_epi8_asm@@64,		EPI8,	ZMM,	GFNI

TIMED _mm_lzcnt_epi16_asm_timed,			EPI16,	XMM,	BITALG
TIMED _mm256_lzcnt_epi16_asm_timed,			EPI16,	YMM,	BITALG
TIMED _mm512_lzcnt_epi16_asm_timed,			EPI16,	ZMM,	BITALG

NAKED _mm_lzcnt_epi16_asm@@16,				EPI16,	ZMM,	BITALG
NAKED _mm256_lzcnt_epi16_asm@@32,			EPI16,	ZMM,	BITALG
NAKED _mm512_lzcnt_epi16_asm@@64,			EPI16,	ZMM,	BITALG

TIMED _mm_lzcnt_fp16_epi16_asm_timed,		EPI16,	XMM,	FP16
TIMED _mm256_lzcnt_fp16_epi16_asm_timed,	EPI16,	YMM,	FP16
TIMED _mm512_lzcnt_fp16_epi16_asm_timed,	EPI16,	ZMM,	FP16

NAKED _mm_lzcnt_fp16_epi16_asm@@16,			EPI16,	ZMM,	FP16
NAKED _mm256_lzcnt_fp16_epi16_asm@@32,		EPI16,	ZMM,	FP16
NAKED _mm512_lzcnt_fp16_epi16_asm@@64,		EPI16,	ZMM,	FP16


end