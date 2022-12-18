.data

;ident mapping
;byteconst_00_3f	dq	00706050403020100h, 00f0e0d0c0b0a0908h, 01716151413121110h, 01f1e1d1c1b1a1918h, 02726252423222120h, 02f2e2d2c2b2a2928h, 03736353433323130h, 03f3e3d3c3b3a3938h 
;byteconst_40_7f	dq	04746454443424140h, 04f4e4d4c4b4a4948h, 05756555453525150h, 05f5e5d5c5b5a5958h, 06766656463626160h, 06f6e6d6c6b6a6968h, 07776757473727170h, 07f7e7d7c7b7a7978h 
;byteconst_80_bf	dq	08786858483828180h, 08f8e8d8c8b8a8988h, 09796959493929190h, 09f9e9d9c9b9a9998h, 0a7a6a5a4a3a2a1a0h, 0afaeadacabaaa9a8h, 0b7b6b5b4b3b2b1b0h, 0bfbebdbcbbbab9b8h 
;byteconst_c0_ff	dq	0c7c6c5c4c3c2c1c0h, 0cfcecdcccbcac9c8h, 0d7d6d5d4d3d2d1d0h, 0dfdedddcdbdad9d8h, 0e7e6e5e4e3e2e1e0h, 0efeeedecebeae9e8h, 0f7f6f5f4f3f2f1f0h, 0fffefdfcfbfaf9f8h 

;+1 mapping
byteconst_00_3f	dq	00807060504030201h, 0100f0e0d0c0b0a09h, 01817161514131211h, 0201f1e1d1c1b1a19h, 02827262524232221h, 0302f2e2d2c2b2a29h, 03837363534333231h, 0403f3e3d3c3b3a39h 
byteconst_40_7f	dq	04847464544434241h, 0504f4e4d4c4b4a49h, 05857565554535251h, 0605f5e5d5c5b5a59h, 06867666564636261h, 0706f6e6d6c6b6a69h, 07877767574737271h, 0807f7e7d7c7b7a79h 
byteconst_80_bf	dq	08887868584838281h, 0908f8e8d8c8b8a89h, 09897969594939291h, 0a09f9e9d9c9b9a99h, 0a8a7a6a5a4a3a2a1h, 0b0afaeadacabaaa9h, 0b8b7b6b5b4b3b2b1h, 0c0bfbebdbcbbbab9h 
byteconst_c0_ff	dq	0c8c7c6c5c4c3c2c1h, 0d0cfcecdcccbcac9h, 0d8d7d6d5d4d3d2d1h, 0e0dfdedddcdbdad9h, 0e8e7e6e5e4e3e2e1h, 0f0efeeedecebeae9h, 0f8f7f6f5f4f3f2f1h, 000fffefdfcfbfaf9h 

inp0			dq	0f5e78b9234190de4h, 0b79b5e89124e4ca9h, 06549ba41bb976aa9h, 03566abb891220879h
;inp1			dq	04a2eff9876341568h, 03973abdeff67892ah, 0ce49735167564bdeh, 0b8790eff12537166h
;
gfni_sra		dq	08080808080808080h
lsb				dq	00101010101010101h
;
repeats			equ	1000000000

.code 

MASKEDVPERMI2B MACRO LAT
	vpmovb2m		k1, zmm0
	vmovdqa64		zmm1, zmm0
	knotq			k2, k1
	vpermi2b		zmm0 {k1}{z}, zmm30, zmm31
	vpermi2b		zmm1 {k2}{z}, zmm28, zmm29
IF LAT EQ 0 
	vporq			zmm0, zmm0, zmm1
ELSE
	vporq			zmm4, zmm0, zmm1
ENDIF
ENDM
		
KREGROUNDTRIP MACRO LAT
	vpmovb2m		k0, zmm0
	vmovdqa64		zmm1, zmm0
	vpermi2b		zmm0, zmm28, zmm29
	vpermi2b		zmm1, zmm30, zmm31
	vpmovm2b		zmm2, k0
IF LAT EQ 0 
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a
ELSE
	vpternlogq		zmm1, zmm1, zmm2, 0d8h ;c?b:a
ENDIF
ENDM

GFNI MACRO LAT
	vmovdqa64		zmm1, zmm0
	vmovdqa64		zmm2, zmm0
	vpermi2b		zmm0, zmm28, zmm29
	vpermi2b		zmm1, zmm30, zmm31
	vgf2p8affineqb	zmm2, zmm2, zmm27, 0
IF LAT EQ 0 
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a
ELSE
	vpternlogq		zmm1, zmm1, zmm2, 0d8h ;c?b:a
ENDIF
ENDM

SRLQ MACRO LAT
	vmovdqa64		zmm1, zmm0
	vpermi2b		zmm1, zmm30, zmm31
	vpsrlq			zmm2, zmm0, 7
	vpermi2b		zmm0, zmm28, zmm29
	vpandq			zmm2, zmm2, zmm27
	vpsubb			zmm2, zmm26, zmm2
IF LAT EQ 0 
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a
ELSE
	vpternlogq		zmm1, zmm1, zmm2, 0d8h ;c?b:a
ENDIF
ENDM

BLENDMB MACRO LAT
	vpmovb2m		k1, zmm0
	vmovdqa64		zmm1, zmm0
	vpermi2b		zmm0, zmm30, zmm31
	vpermi2b		zmm1, zmm28, zmm29
IF LAT EQ 0 
	vpblendmb		zmm0{k1}, zmm1, zmm0
ELSE
	vpblendmb		zmm4{k1}, zmm1, zmm0
ENDIF
ENDM

MINMAX MACRO LAT
	vmovdqa64		zmm1, zmm0
	vpermi2b		zmm1, zmm30, zmm31
	vpmaxsb			zmm2, zmm0, zmm27
	vpermi2b		zmm0, zmm28, zmm29
	vpminsb			zmm2, zmm2, zmm26
IF LAT EQ 0 
	vpternlogq		zmm0, zmm1, zmm2, 0d8h ;c?b:a
ELSE
	vpternlogq		zmm1, zmm1, zmm2, 0d8h ;c?b:a
ENDIF
ENDM

B2B_WRAPPER MACRO FUNCNAME, M1, LAT
FUNCNAME PROC
	push			rbx
	push			rdi
	push			rsi

IFIDNI <M1>, <GFNI>
	vpbroadcastq	zmm27, qword ptr [gfni_sra]
ELSEIFIDNI <M1>, <SRLQ>
	vpxorq			zmm26, zmm26, zmm26
	vpbroadcastq	zmm27, qword ptr [lsb]
ELSEIFIDNI <M1>, <MINMAX>
	vpxorq			zmm26, zmm26, zmm26
	vpternlogq		zmm27, zmm27, zmm27, 0ffh
ENDIF
	vmovdqu64		zmm28, zmmword ptr [byteconst_00_3f]
	vmovdqu64		zmm29, zmmword ptr [byteconst_40_7f]
	vmovdqu64		zmm30, zmmword ptr [byteconst_80_bf]
	vmovdqu64		zmm31, zmmword ptr [byteconst_c0_ff]
	vmovdqu64		zmm0, zmmword ptr [inp0]
	vmovdqu64		zmm3, zmm0			;equ test
	mfence
	rdtscp
	lfence

	mov				esi, eax
	mov				edi, edx

	mov				ecx, repeats

startlabel:
	M1				LAT
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

	vpcmpeqb		k0, zmm0, zmm3		;equ test

	pop				rsi
	pop				rdi
	pop				rbx
	ret
FUNCNAME ENDP
ENDM

B2B_WRAPPER		B2B_MASKEDVPERMI2B_LAT,	MASKEDVPERMI2B, 0
B2B_WRAPPER		B2B_MASKEDVPERMI2B_TP,	MASKEDVPERMI2B, 1

B2B_WRAPPER		B2B_KREGROUNDTRIP_LAT,	KREGROUNDTRIP,	0
B2B_WRAPPER		B2B_KREGROUNDTRIP_TP,	KREGROUNDTRIP,	1

B2B_WRAPPER		B2B_GFNI_LAT,			GFNI,			0
B2B_WRAPPER		B2B_GFNI_TP,			GFNI,			1

B2B_WRAPPER		B2B_SRLQ_LAT,			SRLQ,			0
B2B_WRAPPER		B2B_SRLQ_TP,			SRLQ,			1

B2B_WRAPPER		B2B_BLENDMB_LAT,		BLENDMB,		0
B2B_WRAPPER		B2B_BLENDMB_TP,			BLENDMB,		1

B2B_WRAPPER		B2B_MINMAX_LAT,			MINMAX,			0
B2B_WRAPPER		B2B_MINMAX_TP,			MINMAX,			1

end