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

_mm_tzcnt_epi8_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqb		xmm1, xmm1, xmm1

	vmovdqu64		xmm0, xmmword ptr [bytetest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddb			xmm2, xmm0, xmm1
	vpandn			xmm0, xmm0, xmm2
	vpopcntb		xmm0, xmm0

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
_mm_tzcnt_epi8_asm endp

_mm_tzcnt_epi16_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqw		xmm1, xmm1, xmm1

	vmovdqu64		xmm0, xmmword ptr [wordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddw			xmm2, xmm0, xmm1
	vpandn			xmm0, xmm0, xmm2
	vpopcntw		xmm0, xmm0

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
_mm_tzcnt_epi16_asm endp

_mm_tzcnt_epi32_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqd		xmm1, xmm1, xmm1

	vmovdqu64		xmm0, xmmword ptr [dwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddd			xmm2, xmm0, xmm1
	vpandn			xmm0, xmm0, xmm2
	vpopcntd		xmm0, xmm0

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
_mm_tzcnt_epi32_asm endp

_mm_tzcnt_epi64_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqq		xmm1, xmm0, xmm1	;const 0x0000000000000001

	vmovdqu64		xmm0, xmmword ptr [qwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddq			xmm2, xmm0, xmm1
	vpandn			xmm0, xmm0, xmm2
	vpopcntq		xmm0, xmm0

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
_mm_tzcnt_epi64_asm endp

_mm256_tzcnt_epi8_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqb		ymm1, ymm1, ymm1

	vmovdqu64		ymm0, ymmword ptr [bytetest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddb			ymm2, ymm0, ymm1
	vpandn			ymm0, ymm0, ymm2
	vpopcntb		ymm0, ymm0

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
_mm256_tzcnt_epi8_asm endp

_mm256_tzcnt_epi16_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqw		ymm1, ymm1, ymm1

	vmovdqu64		ymm0, ymmword ptr [wordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddw			ymm2, ymm0, ymm1
	vpandn			ymm0, ymm0, ymm2
	vpopcntw		ymm0, ymm0

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
_mm256_tzcnt_epi16_asm endp

_mm256_tzcnt_epi32_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqd		ymm1, ymm1, ymm1

	vmovdqu64		ymm0, ymmword ptr [dwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddd			ymm2, ymm0, ymm1
	vpandn			ymm0, ymm0, ymm2
	vpopcntd		ymm0, ymm0

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
_mm256_tzcnt_epi32_asm endp

_mm256_tzcnt_epi64_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpcmpeqq		ymm1, ymm1, ymm1

	vmovdqu64		ymm0, ymmword ptr [qwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddq			ymm2, ymm0, ymm1
	vpandn			ymm0, ymm0, ymm2
	vpopcntq		ymm0, ymm0

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
_mm256_tzcnt_epi64_asm endp

_mm512_tzcnt_epi8_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpternlogd		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [bytetest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddb			zmm2, zmm0, zmm1
	vpandnd			zmm0, zmm0, zmm2
	vpopcntb		zmm0, zmm0

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
_mm512_tzcnt_epi8_asm endp

_mm512_tzcnt_epi16_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpternlogd		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [wordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddw			zmm2, zmm0, zmm1
	vpandnd			zmm0, zmm0, zmm2
	vpopcntw		zmm0, zmm0

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
_mm512_tzcnt_epi16_asm endp

_mm512_tzcnt_epi32_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpternlogd		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [dwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddd			zmm2, zmm0, zmm1
	vpandnd			zmm0, zmm0, zmm2
	vpopcntd		zmm0, zmm0

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
_mm512_tzcnt_epi32_asm endp

_mm512_tzcnt_epi64_asm proc
	push			rbx
	push			rdi
	push			rsi

	vpternlogq		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [qwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddq			zmm2, zmm0, zmm1
	vpandnq			zmm0, zmm0, zmm2
	vpopcntq		zmm0, zmm0

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
_mm512_tzcnt_epi64_asm endp

_mm256_tzcnt_epi32_lzcnt_asm proc
	push			rbx
	push			rdi
	push			rsi

	mov				eax, 020h
	vpbroadcastd	ymm3, eax
	vpcmpeqd		ymm1, ymm1, ymm1

	vmovdqu64		ymm0, ymmword ptr [dwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddd			ymm2, ymm0, ymm1
	vpandn			ymm0, ymm0, ymm2
	vplzcntd		ymm0, ymm0
	vpsubd			ymm0, ymm3, ymm0

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
_mm256_tzcnt_epi32_lzcnt_asm endp

_mm512_tzcnt_epi32_lzcnt_asm proc
	push			rbx
	push			rdi
	push			rsi

	mov				eax, 020h
	vpbroadcastd	zmm3, eax
	vpternlogd		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [dwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddd			zmm2, zmm0, zmm1
	vpandnd			zmm0, zmm0, zmm2
	vplzcntd		zmm0, zmm0
	vpsubd			zmm0, zmm3, zmm0

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
_mm512_tzcnt_epi32_lzcnt_asm endp

_mm256_tzcnt_epi64_lzcnt_asm proc
	push			rbx
	push			rdi
	push			rsi

	mov				eax, 040h
	vpbroadcastq	ymm3, rax
	vpternlogq		ymm1, ymm1, ymm1, 0ffh

	vmovdqu64		ymm0, ymmword ptr [qwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddq			ymm2, ymm0, ymm1
	vpandnq			ymm0, ymm0, ymm2
	vplzcntq		ymm0, ymm0
	vpsubq			ymm0, ymm3, ymm0

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
_mm256_tzcnt_epi64_lzcnt_asm endp

_mm512_tzcnt_epi64_lzcnt_asm proc
	push			rbx
	push			rdi
	push			rsi

	mov				eax, 040h
	vpbroadcastq	zmm3, rax
	vpternlogq		zmm1, zmm1, zmm1, 0ffh

	vmovdqu64		zmm0, zmmword ptr [qwordtest_00]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpaddq			zmm2, zmm0, zmm1
	vpandnq			zmm0, zmm0, zmm2
	vplzcntq		zmm0, zmm0
	vpsubq			zmm0, zmm3, zmm0

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
_mm512_tzcnt_epi64_lzcnt_asm endp

end