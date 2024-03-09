.data

bytetest_00		db  001h, 002h, 004h, 008h, 010h, 020h, 040h, 080h
bytetest_01		db  0c0h, 0e0h, 0f0h, 0f8h, 0fch, 0feh, 0ffh, 07fh
bytetest_02		db  03fh, 01fh, 00fh, 007h, 003h, 001h, 000h, 000h
bytetest_03		db  000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
bytetest_04		db  000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
bytetest_05		db  000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
bytetest_06		db  000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
bytetest_07		db  000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h 

wordtest_00		dw  00001h, 00002h, 00004h, 00008h, 00010h, 00020h, 00040h, 00080h
wordtest_01		dw  00100h, 00200h, 00400h, 00800h, 01000h, 02000h, 04000h, 08000h
wordtest_02		dw  0ffffh, 0fffeh, 0fffch, 0fff8h, 0fff0h, 0ffe0h, 0ffc0h, 0ff80h 
wordtest_03		dw  0ff00h, 0fe00h, 0fc00h, 0f800h, 0f000h, 0e000h, 0c000h, 08000h

dwordtest_00	dd  00000000h, 00000001h, 00000002h, 00000004h, 00000008h, 00000010h, 00000020h, 00000040h
dwordtest_01	dd  00000080h, 00000100h, 00000200h, 00000400h, 10000000h, 20000000h, 40000000h, 80000000h

qwordtest_00	dq  00000000h, 00000001h, 00000002h, 00000004h, 1000000000000000h, 2000000000000000h, 4000000000000000h, 8000000000000000h

repeats			equ	1000000h

.code 

INIT macro VECREGSIZE, ISA
IFIDNI <VECREGSIZE>, <XMM>
	vpcmpeqw		xmm1, xmm1, xmm1
ELSEIFIDNI <VECREGSIZE>, <YMM>
	vpcmpeqb		ymm1, ymm1, ymm1
ELSEIFIDNI <VECREGSIZE>, <ZMM>
	vpternlogd		zmm1, zmm1, zmm1, 0ffh
ENDIF
IFIDNI <ISA>, <CD>
	mov				eax, 040h
	IFIDNI <VECREGSIZE>, <XMM>
		vpbroadcastq	xmm3, rax
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		vpbroadcastq	ymm3, rax
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		vpbroadcastq	zmm3, rax
	ENDIF
ENDIF
endm

CORE macro DATA, VECREGSIZE, ISA
IFIDNI <ISA>, <BITALG>
	IFIDNI <VECREGSIZE>, <XMM>
		IFIDNI <DATA>, <EPI8>
			vpaddb			xmm2, xmm0, xmm1
			vpandnd			xmm0, xmm0, xmm2
			vpopcntb		xmm0, xmm0
		ELSEIFIDNI <DATA>, <EPI16>
			vpaddw			xmm2, xmm0, xmm1
			vpandnd			xmm0, xmm0, xmm2
			vpopcntw		xmm0, xmm0
		ELSEIFIDNI <DATA>, <EPI32>
			vpaddd			xmm2, xmm0, xmm1
			vpandnd			xmm0, xmm0, xmm2
			vpopcntd		xmm0, xmm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			xmm2, xmm0, xmm1
			vpandnq			xmm0, xmm0, xmm2
			vpopcntq		xmm0, xmm0
		ENDIF
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		IFIDNI <DATA>, <EPI8>
			vpaddb			ymm2, ymm0, ymm1
			vpandnd			ymm0, ymm0, ymm2
			vpopcntb		ymm0, ymm0
		ELSEIFIDNI <DATA>, <EPI16>
			vpaddw			ymm2, ymm0, ymm1
			vpandnd			ymm0, ymm0, ymm2
			vpopcntw		ymm0, ymm0
		ELSEIFIDNI <DATA>, <EPI32>
			vpaddd			ymm2, ymm0, ymm1
			vpandnd			ymm0, ymm0, ymm2
			vpopcntd		ymm0, ymm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			ymm2, ymm0, ymm1
			vpandnq			ymm0, ymm0, ymm2
			vpopcntq		ymm0, ymm0
		ENDIF
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		IFIDNI <DATA>, <EPI8>
			vpaddb			zmm2, zmm0, zmm1
			vpandnd			zmm0, zmm0, zmm2
			vpopcntb		zmm0, zmm0
		ELSEIFIDNI <DATA>, <EPI16>
			vpaddw			zmm2, zmm0, zmm1
			vpandnd			zmm0, zmm0, zmm2
			vpopcntw		zmm0, zmm0
		ELSEIFIDNI <DATA>, <EPI32>
			vpaddd			zmm2, zmm0, zmm1
			vpandnd			zmm0, zmm0, zmm2
			vpopcntd		zmm0, zmm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			zmm2, zmm0, zmm1
			vpandnq			zmm0, zmm0, zmm2
			vpopcntq		zmm0, zmm0
		ENDIF
	ENDIF
ELSEIFIDNI <ISA>, <CD>
	IFIDNI <VECREGSIZE>, <XMM>
		IFIDNI <DATA>, <EPI32>
			vpaddd			xmm2, xmm0, xmm1
			vpandnd			xmm0, xmm0, xmm2
			vplzcntd		xmm0, xmm0
			vpsubd			xmm0, xmm3, xmm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			xmm2, xmm0, xmm1
			vpandnq			xmm0, xmm0, xmm2
			vplzcntq		xmm0, xmm0
			vpsubq			xmm0, xmm3, xmm0
		ENDIF
	ELSEIFIDNI <VECREGSIZE>, <YMM>
		IFIDNI <DATA>, <EPI32>
			vpaddd			ymm2, ymm0, ymm1
			vpandnd			ymm0, ymm0, ymm2
			vplzcntd		ymm0, ymm0
			vpsubd			ymm0, ymm3, ymm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			ymm2, ymm0, ymm1
			vpandnq			ymm0, ymm0, ymm2
			vplzcntq		ymm0, ymm0
			vpsubq			ymm0, ymm3, ymm0
		ENDIF
	ELSEIFIDNI <VECREGSIZE>, <ZMM>
		IFIDNI <DATA>, <EPI32>
			vpaddd			zmm2, zmm0, zmm1
			vpandnd			zmm0, zmm0, zmm2
			vplzcntd		zmm0, zmm0
			vpsubd			zmm0, zmm3, zmm0
		ELSEIFIDNI <DATA>, <EPI64>
			vpaddq			zmm2, zmm0, zmm1
			vpandnq			zmm0, zmm0, zmm2
			vplzcntq		zmm0, zmm0
			vpsubq			zmm0, zmm3, zmm0
		ENDIF
	ENDIF
ENDIF
endm

TIMED macro PNAME, DATA, VECREGSIZE, ISA
PNAME proc
	push			rbx
	push			rdi
	push			rsi

	INIT			VECREGSIZE, ISA

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

align 16
startlabel:
	CORE			DATA, VECREGSIZE, ISA

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

	INIT			VECREGSIZE, ISA

	CORE			DATA, VECREGSIZE, ISA

	ret
PNAME endp
endm

TIMED _mm_tzcnt_epi8_asm_timed,				EPI8,	XMM,		BITALG
TIMED _mm_tzcnt_epi16_asm_timed,			EPI16,	XMM,		BITALG
TIMED _mm_tzcnt_epi32_asm_timed,			EPI32,	XMM,		BITALG
TIMED _mm_tzcnt_epi64_asm_timed,			EPI64,	XMM,		BITALG

NAKED _mm_tzcnt_epi8_asm@@16,				EPI8,	XMM,		BITALG
NAKED _mm_tzcnt_epi16_asm@@16,				EPI16,	XMM,		BITALG
NAKED _mm_tzcnt_epi32_asm@@16,				EPI32,	XMM,		BITALG
NAKED _mm_tzcnt_epi64_asm@@16,				EPI64,	XMM,		BITALG

TIMED _mm256_tzcnt_epi8_asm_timed,			EPI8,	YMM,		BITALG
TIMED _mm256_tzcnt_epi16_asm_timed,			EPI16,	YMM,		BITALG
TIMED _mm256_tzcnt_epi32_asm_timed,			EPI32,	YMM,		BITALG
TIMED _mm256_tzcnt_epi64_asm_timed,			EPI64,	YMM,		BITALG

NAKED _mm256_tzcnt_epi8_asm@@16,			EPI8,	YMM,		BITALG
NAKED _mm256_tzcnt_epi16_asm@@16,			EPI16,	YMM,		BITALG
NAKED _mm256_tzcnt_epi32_asm@@16,			EPI32,	YMM,		BITALG
NAKED _mm256_tzcnt_epi64_asm@@16,			EPI64,	YMM,		BITALG

TIMED _mm512_tzcnt_epi8_asm_timed,			EPI8,	ZMM,		BITALG
TIMED _mm512_tzcnt_epi16_asm_timed,			EPI16,	ZMM,		BITALG
TIMED _mm512_tzcnt_epi32_asm_timed,			EPI32,	ZMM,		BITALG
TIMED _mm512_tzcnt_epi64_asm_timed,			EPI64,	ZMM,		BITALG

NAKED _mm512_tzcnt_epi8_asm@@16,			EPI8,	ZMM,		BITALG
NAKED _mm512_tzcnt_epi16_asm@@16,			EPI16,	ZMM,		BITALG
NAKED _mm512_tzcnt_epi32_asm@@16,			EPI32,	ZMM,		BITALG
NAKED _mm512_tzcnt_epi64_asm@@16,			EPI64,	ZMM,		BITALG

TIMED _mm_tzcnt_epi32_cd_asm_timed,			EPI32,	XMM,		CD
TIMED _mm_tzcnt_epi64_cd_asm_timed,			EPI64,	XMM,		CD
TIMED _mm256_tzcnt_epi32_cd_asm_timed,		EPI32,	YMM,		CD
TIMED _mm256_tzcnt_epi64_cd_asm_timed,		EPI64,	YMM,		CD
TIMED _mm512_tzcnt_epi32_cd_asm_timed,		EPI32,	ZMM,		CD
TIMED _mm512_tzcnt_epi64_cd_asm_timed,		EPI64,	ZMM,		CD

NAKED _mm_tzcnt_epi32_cd_asm@@16,			EPI32,	XMM,		CD
NAKED _mm_tzcnt_epi64_cd_asm@@16,			EPI64,	XMM,		CD
NAKED _mm256_tzcnt_epi32_cd_asm@@16,		EPI32,	YMM,		CD
NAKED _mm256_tzcnt_epi64_cd_asm@@16,		EPI64,	YMM,		CD
NAKED _mm512_tzcnt_epi32_cd_asm@@16,		EPI32,	ZMM,		CD
NAKED _mm512_tzcnt_epi64_cd_asm@@16,		EPI64,	ZMM,		CD

end