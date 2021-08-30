.data

tempmem			dq	00101010101010101h

repeats			equ	1000000h

.code 

KmovTest01 proc
	push			rbx
	push			rdi
	push			rsi

	kxnorq			k0, k0, k0
	kxnorq			k1, k1, k1
	kxnorq			k2, k2, k2
	kxnorq			k3, k3, k3

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	kmovw			ebx, k0		;P0
	kmovw			edx, k0		;P0
	kmovw			eax, k0		;P0
	kmovw			r8d, k0		;P0

	popcnt			ebx, ebx	;P1
	popcnt			edx, edx	;P1
	popcnt			eax, eax	;P1
	popcnt			r8d, r8d	;P1

	add				ebx, edx	;P0156
	add				eax, r8d	;P0156
	add				eax, ebx	;P0156

	kmovw			k0, eax		;P5

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
KmovTest01 endp

KmovTest02 proc
	push			rbx
	push			rdi
	push			rsi

	kxnorq			k0, k0, k0
	kxorq			k1, k1, k1
	kxorq			k2, k2, k2
	kxorq			k3, k3, k3

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	kunpckwd		k1, k0, k0		;P5
	kunpckwd		k2, k0, k0		;P5
	kunpckdq		k3, k1, k2		;P5

	kmovq			rax, k3			;P0
	popcnt			rax, rax		;P1
	kmovq			k0, rax			;P5

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
KmovTest02 endp

KmovTest03 proc
	push			rbx
	push			rdi
	push			rsi

	kxnorq			k0, k0, k0
	kxnorq			k1, k1, k1
	kxnorq			k2, k2, k2
	kxnorq			k3, k3, k3

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	kmovw			word ptr [tempmem + 0], k0
	kmovw			word ptr [tempmem + 2], k0
	kmovw			word ptr [tempmem + 4], k0
	kmovw			word ptr [tempmem + 6], k0

	popcnt			rax, qword ptr [tempmem]

	kmovq			k0, rax
		
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
KmovTest03 endp

end