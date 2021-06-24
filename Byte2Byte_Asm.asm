.data

byteconst_00_3f	dq	00706050403020100h, 00f0e0d0c0b0a0908h, 01716151413121110h, 01f1e1d1c1b1a1918h, 02726252423222120h, 02f2e2d2c2b2a2928h, 03736353433323130h, 03f3e3d3c3b3a3938h 
byteconst_40_7f	dq	04746454443424140h, 04f4e4d4c4b4a4948h, 05756555453525150h, 05f5e5d5c5b5a5958h, 06766656463626160h, 06f6e6d6c6b6a6968h, 07776757473727170h, 07f7e7d7c7b7a7978h 
byteconst_80_bf	dq	08786858483828180h, 08f8e8d8c8b8a8988h, 09796959493929190h, 09f9e9d9c9b9a9998h, 0a7a6a5a4a3a2a1a0h, 0afaeadacabaaa9a8h, 0b7b6b5b4b3b2b1b0h, 0bfbebdbcbbbab9b8h 
byteconst_c0_ff	dq	0c7c6c5c4c3c2c1c0h, 0cfcecdcccbcac9c8h, 0d7d6d5d4d3d2d1d0h, 0dfdedddcdbdad9d8h, 0e7e6e5e4e3e2e1e0h, 0efeeedecebeae9e8h, 0f7f6f5f4f3f2f1f0h, 0fffefdfcfbfaf9f8h 

inp0			dq	0f5e78b9234190de4h, 0b79b5e89124e4ca9h, 06549ba41bb976aa9h, 03566abb891220879h
inp1			dq	04a2eff9876341568h, 03973abdeff67892ah, 0ce49735167564bdeh, 0b8790eff12537166h

gfni_sra		dq	08080808080808080h

repeats			equ	1000000

.code 

Byte2Byte01 proc
	push			rbx
	push			rdi
	push			rsi
	vmovdqu64		zmm28, zmmword ptr [byteconst_00_3f]
	vmovdqu64		zmm29, zmmword ptr [byteconst_40_7f]
	vmovdqu64		zmm30, zmmword ptr [byteconst_80_bf]
	vmovdqu64		zmm31, zmmword ptr [byteconst_c0_ff]

	vmovdqu64		zmm0, zmmword ptr [inp0]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpmovb2m		k1, zmm0
	vpermi2b		zmm0, zmm28, zmm29
	vpermi2b		zmm0 {k1}, zmm30, zmm31
		
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
byte2byte01 endp

Byte2Byte02 proc
	push			rbx
	push			rdi
	push			rsi
	vmovdqu64		zmm28, zmmword ptr [byteconst_00_3f]
	vmovdqu64		zmm29, zmmword ptr [byteconst_40_7f]
	vmovdqu64		zmm30, zmmword ptr [byteconst_80_bf]
	vmovdqu64		zmm31, zmmword ptr [byteconst_c0_ff]

	vmovdqu64		zmm0, zmmword ptr [inp0]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vpmovb2m		k0, zmm0
	vmovdqa64		zmm1, zmm0
	vpermi2b		zmm0, zmm28, zmm29
	vpermi2b		zmm1, zmm30, zmm31
	vpmovm2b		zmm2, k0
	
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a

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
byte2byte02 endp

Byte2Byte03 proc
	push			rbx
	push			rdi
	push			rsi
	vmovdqu64		zmm28, zmmword ptr [byteconst_00_3f]
	vmovdqu64		zmm29, zmmword ptr [byteconst_40_7f]
	vmovdqu64		zmm30, zmmword ptr [byteconst_80_bf]
	vmovdqu64		zmm31, zmmword ptr [byteconst_c0_ff]

	vpbroadcastq	zmm27, qword ptr [gfni_sra]

	vmovdqu64		zmm0, zmmword ptr [inp0]

	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	vgf2p8affineqb	zmm2, zmm0, zmm27, 0
	vpermi2b		zmm0, zmm28, zmm29
	vpermi2b		zmm1, zmm30, zmm31
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a

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
byte2byte03 endp

end