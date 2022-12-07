data SEGMENT PAGE

memdst0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memdst1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memdst2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memdst3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

data ENDS

.code

InstLatX64_xmm2m128_lat macro INST
	INST					xmmword ptr [rdi], xmm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_evex_xmm2m128_lat macro INST
	evex INST				xmmword ptr [rdi], xmm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_xmm2m64_lat macro INST
	INST					qword ptr [rdi], xmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_xmm2m32_lat macro INST
	INST					dword ptr [rdi], xmm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_xmm2m16_lat macro INST
	INST					word ptr [rdi], xmm0
	vpbroadcastw			xmm0, word ptr [rdi]
endm

InstLatX64_xmm2km64_lat macro INST
	INST					qword ptr [rdi]{k1}, xmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_xmm2km32_lat macro INST
	INST					dword ptr [rdi]{k1}, xmm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_xmm2km16_lat macro INST
	INST					word ptr [rdi]{k1}, xmm0
	vpbroadcastw			xmm0, word ptr [rdi]
endm

InstLatX64_xmm2zkm64_lat macro INST
	INST					qword ptr [rdi]{k1}{z}, xmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_xmm2zkm32_lat macro INST
	INST					dword ptr [rdi]{k1}{z}, xmm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_xmm2zkm16_lat macro INST
	INST					word ptr [rdi]{k1}{z}, xmm0
	vpbroadcastw			xmm0, word ptr [rdi]
endm

InstLatX64_evex_ymm2m256_lat macro INST
	evex INST				ymmword ptr [rdi], ymm0
	vmovdqa					ymm0, ymmword ptr [rdi]
endm

InstLatX64_ymm2m256_lat macro INST
	INST					ymmword ptr [rdi], ymm0
	vmovdqa					ymm0, ymmword ptr [rdi]
endm

InstLatX64_ymm2m128_lat macro INST
	INST					xmmword ptr [rdi], ymm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_ymm2m64_lat macro INST
	INST					qword ptr [rdi], ymm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_ymm2m32_lat macro INST
	INST					dword ptr [rdi], ymm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_ymm2km128_lat macro INST
	INST					xmmword ptr [rdi]{k1}, ymm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_ymm2km64_lat macro INST
	INST					qword ptr [rdi]{k1}, ymm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_ymm2km32_lat macro INST
	INST					dword ptr [rdi]{k1}, ymm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_ymm2zkm128_lat macro INST
	INST					xmmword ptr [rdi]{k1}{z}, ymm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_ymm2zkm64_lat macro INST
	INST					qword ptr [rdi]{k1}{z}, ymm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_ymm2zkm32_lat macro INST
	INST					dword ptr [rdi]{k1}{z}, ymm0
	vmovd					xmm0, dword ptr [rdi]
endm

InstLatX64_zmm2m512_lat macro INST
	INST					zmmword ptr [rdi], zmm0
	vmovdqa32				zmm0, zmmword ptr [rdi]
endm

InstLatX64_zmm2m128_lat macro INST
	INST					xmmword ptr [rdi], zmm0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi2m128_lat macro INST
	INST					xmmword ptr [rdi], zmm0, 1
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi02m128_lat macro INST
	INST					xmmword ptr [rdi], zmm0, 0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi2km128_lat macro INST
	INST					xmmword ptr [rdi], zmm0{k1}, 1
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi02km128_lat macro INST
	INST					xmmword ptr [rdi], zmm0{k1}, 0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi2km128_lat macro INST
	INST					xmmword ptr [rdi]{k1}, zmm0, 1
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmmi02km128_lat macro INST
	INST					xmmword ptr [rdi]{k1}, zmm0, 0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmm2m64_lat macro INST
	INST					qword ptr [rdi], zmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_zmm2km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, zmm0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi2km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, zmm0, 1
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi02km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, zmm0, 0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmm2km128_lat macro INST
	INST					xmmword ptr [rdi]{k1}, zmm0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmm2km64_lat macro INST
	INST					qword ptr [rdi]{k1}, zmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_zmm2zkm256_lat macro INST
	INST					ymmword ptr [rdi]{k1}{z}, zmm0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmm2zkm128_lat macro INST
	INST					xmmword ptr [rdi]{k1}{z}, zmm0
	vmovdqa32				xmm0, xmmword ptr [rdi]
endm

InstLatX64_zmm2zkm64_lat macro INST
	INST					qword ptr [rdi]{k1}{z}, zmm0
	vmovq					xmm0, qword ptr [rdi]
endm

InstLatX64_xmm2km128_lat macro INST
	INST					xmmword ptr [rdi]{k1}, xmm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_ymm2km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, ymm0
	vmovdqa					ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmm2km512_lat macro INST
	INST					zmmword ptr [rdi]{k1}, zmm0
	vmovdqa32				zmm0, zmmword ptr [rdi]
endm

InstLatX64_zmm2m256_lat macro INST
	INST					ymmword ptr [rdi], zmm0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi2m256_lat macro INST
	INST					ymmword ptr [rdi], zmm0, 1
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi02m256_lat macro INST
	INST					ymmword ptr [rdi], zmm0, 0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi2km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, zmm0, 1
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmmi02km256_lat macro INST
	INST					ymmword ptr [rdi]{k1}, zmm0, 0
	vmovdqa32				ymm0, ymmword ptr [rdi]
endm

InstLatX64_xmm2zkm128_lat macro INST
	INST					xmmword ptr [rdi]{k1}{z}, xmm0
	vmovdqa					xmm0, xmmword ptr [rdi]
endm

InstLatX64_ymm2zkm256_lat macro INST
	INST					ymmword ptr [rdi]{k1}{z}, ymm0
	vmovdqa					ymm0, ymmword ptr [rdi]
endm

InstLatX64_zmm2zkm512_lat macro INST
	INST					zmmword ptr [rdi]{k1}{z}, zmm0
	vmovdqa32				zmm0, zmmword ptr [rdi]
endm

InstLatX64_ymmi02m128_lat macro INST
	INST					xmmword ptr [rdi + 00h], ymm0, 0
	vmovdqa					xmm0, xmmword ptr [rdi + 00h]
endm

InstLatX64_ymmi2m128_lat macro INST
	INST					xmmword ptr [rdi + 00h], ymm0, 1
	vmovdqa					xmm0, xmmword ptr [rdi + 00h]
endm

InstLatX64_ymmi02km128_lat macro INST
	INST					xmmword ptr [rdi + 00h]{k1}, ymm0, 0
	vmovdqa					xmm0, xmmword ptr [rdi + 00h]
endm

InstLatX64_ymmi2km128_lat macro INST
	INST					xmmword ptr [rdi + 00h]{k1}, ymm0, 1
	vmovdqa					xmm0, xmmword ptr [rdi + 00h]
endm

InstLatX64_scatterdx2x_lat macro INST
	INST				dword ptr [rdi + xmm1*4]{k1}, xmm3
	kmovw				k1, k0
endm

InstLatX64_scatterdy2y_lat macro INST
	INST				dword ptr [rdi + ymm1*4]{k1}, ymm3
	kmovw				k1, k0
endm

InstLatX64_scatterdz2z_lat macro INST
	INST				dword ptr [rdi + zmm1*4]{k1}, zmm3
	kmovw				k1, k0
endm

InstLatX64_scatterqx2x_lat macro INST
	INST				qword ptr [rdi + xmm2*8]{k1}, xmm4
	kmovw				k1, k0
endm

InstLatX64_scatterqy2y_lat macro INST
	INST				qword ptr [rdi + ymm2*8]{k1}, ymm4
	kmovw				k1, k0
endm

InstLatX64_scatterqz2z_lat macro INST
	INST				qword ptr [rdi + zmm2*8]{k1}, zmm4
	kmovw				k1, k0
endm

InstLatX64_scatterqx2y_lat macro INST
	INST				qword ptr [rdi + ymm2*8]{k1}, xmm4
	kmovw				k1, k0
endm

InstLatX64_scatterqy2z_lat macro INST
	INST				qword ptr [rdi + zmm2*8]{k1}, ymm4
	kmovw				k1, k0
endm

InstLatX64_scatterdy2x_lat macro INST
	INST				dword ptr [rdi + xmm1*4]{k1}, ymm3
	kmovw				k1, k0
endm

InstLatX64_scatterdz2y_lat macro INST
	INST				dword ptr [rdi + ymm1*4]{k1}, zmm3
	kmovw				k1, k0
endm

kmemdst macro FUNC, M1, INST, OPERANDS
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
	lea				rdi, [memdst0]
IFIDN @substr(OPERANDS, 1, 7), <scatter>
	mov				rax, 0706050403020100h
	vmovq			xmm1, rax
	vpmovzxbq		zmm2, xmm1				;vsib64
	mov				rax, 0F0E0D0C0B0A0908h
	vpinsrq			xmm1, xmm1, rax, 1
	vpmovzxbd		zmm1, xmm1				;vsib32
	vpternlogq		zmm4, zmm4, zmm4, 0ffh
	vpsubd			zmm3, zmm4, zmm1
	vpsubq			zmm4, zmm4, zmm2


	kmovq			k0, rcx
ENDIF
	kmovq			k1, rcx
	xor				eax, eax
	cpuid
	rdtscp

	shl				rdx, 32
	or				rax, rdx
	mov				rsi, rax

	mov				r15, 100000
align 16
looptest:
	M1				INST

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

kmemdst_wrap macro INST, OPERANDS
	;			FUNC,								M1,							INST
	kmemdst		KMemDst_&INST&_&OPERANDS&_lat,		InstLatX64_&OPERANDS&_lat,	INST, OPERANDS
endm

	;vpscatterdd		dword ptr [rdi + xmm0*1]{k1}, xmm2
	;vpscatterdd		dword ptr [rdi + ymm0*1]{k1}, ymm2
	;vpscatterdd		dword ptr [rdi + zmm0*1]{k1}, zmm2
	;
	;vpscatterqq		qword ptr [rdi + xmm0*1]{k1}, xmm2
	;vpscatterqq		qword ptr [rdi + ymm0*1]{k1}, ymm2
	;vpscatterqq		qword ptr [rdi + zmm0*1]{k1}, zmm2
	;
	;vpscatterqd		qword ptr [rdi + xmm0*1]{k1}, xmm2
	;vpscatterqd		qword ptr [rdi + ymm0*1]{k1}, xmm2
	;vpscatterqd		qword ptr [rdi + zmm0*1]{k1}, ymm2
	;
	;vpscatterdq		dword ptr [rdi + xmm0*1]{k1}, xmm2
	;vpscatterdq		dword ptr [rdi + xmm0*1]{k1}, ymm2
	;vpscatterdq		dword ptr [rdi + ymm0*1]{k1}, zmm2


;				INST				OPERANDS
kmemdst_wrap	vpscatterdd,		scatterdx2x
kmemdst_wrap	vpscatterdd,		scatterdy2y
kmemdst_wrap	vpscatterdd,		scatterdz2z

kmemdst_wrap	vpscatterqq,		scatterqx2x
kmemdst_wrap	vpscatterqq,		scatterqy2y
kmemdst_wrap	vpscatterqq,		scatterqz2z

kmemdst_wrap	vpscatterqd,		scatterqx2x
kmemdst_wrap	vpscatterqd,		scatterqx2y
kmemdst_wrap	vpscatterqd,		scatterqy2z

kmemdst_wrap	vpscatterdq,		scatterdx2x
kmemdst_wrap	vpscatterdq,		scatterdy2x
kmemdst_wrap	vpscatterdq,		scatterdz2y

kmemdst_wrap	vscatterdps,		scatterdx2x
kmemdst_wrap	vscatterdps,		scatterdy2y
kmemdst_wrap	vscatterdps,		scatterdz2z

kmemdst_wrap	vscatterqpd,		scatterqx2x
kmemdst_wrap	vscatterqpd,		scatterqy2y
kmemdst_wrap	vscatterqpd,		scatterqz2z

kmemdst_wrap	vscatterqps,		scatterqx2x
kmemdst_wrap	vscatterqps,		scatterqx2y
kmemdst_wrap	vscatterqps,		scatterqy2z

kmemdst_wrap	vscatterdpd,		scatterdx2x
kmemdst_wrap	vscatterdpd,		scatterdy2x
kmemdst_wrap	vscatterdpd,		scatterdz2y

kmemdst_wrap	vmovd,				xmm2m32
kmemdst_wrap	vmovq,				xmm2m64

kmemdst_wrap	vmovaps,			evex_xmm2m128
kmemdst_wrap	vmovaps,			evex_ymm2m256
kmemdst_wrap	vmovaps,			zmm2m512
kmemdst_wrap	vmovapd,			evex_xmm2m128
kmemdst_wrap	vmovapd,			evex_ymm2m256
kmemdst_wrap	vmovapd,			zmm2m512
kmemdst_wrap	vmovups,			evex_xmm2m128
kmemdst_wrap	vmovups,			evex_ymm2m256
kmemdst_wrap	vmovups,			zmm2m512
kmemdst_wrap	vmovupd,			evex_xmm2m128
kmemdst_wrap	vmovupd,			evex_ymm2m256
kmemdst_wrap	vmovupd,			zmm2m512
kmemdst_wrap	vmovdqa32,			xmm2m128
kmemdst_wrap	vmovdqa32,			ymm2m256
kmemdst_wrap	vmovdqa32,			zmm2m512
kmemdst_wrap	vmovdqa64,			xmm2m128
kmemdst_wrap	vmovdqa64,			ymm2m256
kmemdst_wrap	vmovdqa64,			zmm2m512
kmemdst_wrap	vmovdqu8,			xmm2m128
kmemdst_wrap	vmovdqu8,			ymm2m256
kmemdst_wrap	vmovdqu8,			zmm2m512
kmemdst_wrap	vmovdqu16,			xmm2m128
kmemdst_wrap	vmovdqu16,			ymm2m256
kmemdst_wrap	vmovdqu16,			zmm2m512
kmemdst_wrap	vmovdqu32,			xmm2m128
kmemdst_wrap	vmovdqu32,			ymm2m256
kmemdst_wrap	vmovdqu32,			zmm2m512
kmemdst_wrap	vmovdqu64,			xmm2m128
kmemdst_wrap	vmovdqu64,			ymm2m256
kmemdst_wrap	vmovdqu64,			zmm2m512

kmemdst_wrap	vmovaps,			xmm2km128
kmemdst_wrap	vmovaps,			ymm2km256
kmemdst_wrap	vmovaps,			zmm2km512
kmemdst_wrap	vmovapd,			xmm2km128
kmemdst_wrap	vmovapd,			ymm2km256
kmemdst_wrap	vmovapd,			zmm2km512
kmemdst_wrap	vmovups,			xmm2km128
kmemdst_wrap	vmovups,			ymm2km256
kmemdst_wrap	vmovups,			zmm2km512
kmemdst_wrap	vmovupd,			xmm2km128
kmemdst_wrap	vmovupd,			ymm2km256
kmemdst_wrap	vmovupd,			zmm2km512
kmemdst_wrap	vmovdqa32,			xmm2km128
kmemdst_wrap	vmovdqa32,			ymm2km256
kmemdst_wrap	vmovdqa32,			zmm2km512
kmemdst_wrap	vmovdqa64,			xmm2km128
kmemdst_wrap	vmovdqa64,			ymm2km256
kmemdst_wrap	vmovdqa64,			zmm2km512
kmemdst_wrap	vmovdqu8,			xmm2km128
kmemdst_wrap	vmovdqu8,			ymm2km256
kmemdst_wrap	vmovdqu8,			zmm2km512
kmemdst_wrap	vmovdqu16,			xmm2km128
kmemdst_wrap	vmovdqu16,			ymm2km256
kmemdst_wrap	vmovdqu16,			zmm2km512
kmemdst_wrap	vmovdqu32,			xmm2km128
kmemdst_wrap	vmovdqu32,			ymm2km256
kmemdst_wrap	vmovdqu32,			zmm2km512
kmemdst_wrap	vmovdqu64,			xmm2km128
kmemdst_wrap	vmovdqu64,			ymm2km256
kmemdst_wrap	vmovdqu64,			zmm2km512

;kmemdst_wrap	vmovaps,			xmm2zkm128
;kmemdst_wrap	vmovaps,			ymm2zkm256
;kmemdst_wrap	vmovaps,			zmm2zkm512
;kmemdst_wrap	vmovapd,			xmm2zkm128
;kmemdst_wrap	vmovapd,			ymm2zkm256
;kmemdst_wrap	vmovapd,			zmm2zkm512
;kmemdst_wrap	vmovups,			xmm2zkm128
;kmemdst_wrap	vmovups,			ymm2zkm256
;kmemdst_wrap	vmovups,			zmm2zkm512
;kmemdst_wrap	vmovupd,			xmm2zkm128
;kmemdst_wrap	vmovupd,			ymm2zkm256
;kmemdst_wrap	vmovupd,			zmm2zkm512
;kmemdst_wrap	vmovdqa32,			xmm2zkm128
;kmemdst_wrap	vmovdqa32,			ymm2zkm256
;kmemdst_wrap	vmovdqa32,			zmm2zkm512
;kmemdst_wrap	vmovdqa64,			xmm2zkm128
;kmemdst_wrap	vmovdqa64,			ymm2zkm256
;kmemdst_wrap	vmovdqa64,			zmm2zkm512
;kmemdst_wrap	vmovdqu8,			xmm2zkm128
;kmemdst_wrap	vmovdqu8,			ymm2zkm256
;kmemdst_wrap	vmovdqu8,			zmm2zkm512
;kmemdst_wrap	vmovdqu16,			xmm2zkm128
;kmemdst_wrap	vmovdqu16,			ymm2zkm256
;kmemdst_wrap	vmovdqu16,			zmm2zkm512
;kmemdst_wrap	vmovdqu32,			xmm2zkm128
;kmemdst_wrap	vmovdqu32,			ymm2zkm256
;kmemdst_wrap	vmovdqu32,			zmm2zkm512
;kmemdst_wrap	vmovdqu64,			xmm2zkm128
;kmemdst_wrap	vmovdqu64,			ymm2zkm256
;kmemdst_wrap	vmovdqu64,			zmm2zkm512

kmemdst_wrap	vextractf32x4,		ymmi02m128
kmemdst_wrap	vextractf32x4,		zmmi02m128
kmemdst_wrap	vextracti32x4,		ymmi02m128
kmemdst_wrap	vextracti32x4,		zmmi02m128
kmemdst_wrap	vextractf64x2,		ymmi02m128
kmemdst_wrap	vextractf64x2,		zmmi02m128
kmemdst_wrap	vextracti64x2,		ymmi02m128
kmemdst_wrap	vextracti64x2,		zmmi02m128
kmemdst_wrap	vextractf32x8,		zmmi02m256
kmemdst_wrap	vextracti32x8,		zmmi02m256
kmemdst_wrap	vextractf64x4,		zmmi02m256
kmemdst_wrap	vextracti64x4,		zmmi02m256

kmemdst_wrap	vextractf32x4,		ymmi2m128
kmemdst_wrap	vextractf32x4,		zmmi2m128
kmemdst_wrap	vextracti32x4,		ymmi2m128
kmemdst_wrap	vextracti32x4,		zmmi2m128
kmemdst_wrap	vextractf64x2,		ymmi2m128
kmemdst_wrap	vextractf64x2,		zmmi2m128
kmemdst_wrap	vextracti64x2,		ymmi2m128
kmemdst_wrap	vextracti64x2,		zmmi2m128
kmemdst_wrap	vextractf32x8,		zmmi2m256
kmemdst_wrap	vextracti32x8,		zmmi2m256
kmemdst_wrap	vextractf64x4,		zmmi2m256
kmemdst_wrap	vextracti64x4,		zmmi2m256

kmemdst_wrap	vextractf32x4,		ymmi02km128
kmemdst_wrap	vextractf32x4,		zmmi02km128
kmemdst_wrap	vextracti32x4,		ymmi02km128
kmemdst_wrap	vextracti32x4,		zmmi02km128
kmemdst_wrap	vextractf64x2,		ymmi02km128
kmemdst_wrap	vextractf64x2,		zmmi02km128
kmemdst_wrap	vextracti64x2,		ymmi02km128
kmemdst_wrap	vextracti64x2,		zmmi02km128
kmemdst_wrap	vextractf32x8,		zmmi02km256
kmemdst_wrap	vextracti32x8,		zmmi02km256
kmemdst_wrap	vextractf64x4,		zmmi02km256
kmemdst_wrap	vextracti64x4,		zmmi02km256

kmemdst_wrap	vextractf32x4,		ymmi2km128
kmemdst_wrap	vextractf32x4,		zmmi2km128
kmemdst_wrap	vextracti32x4,		ymmi2km128
kmemdst_wrap	vextracti32x4,		zmmi2km128
kmemdst_wrap	vextractf64x2,		ymmi2km128
kmemdst_wrap	vextractf64x2,		zmmi2km128
kmemdst_wrap	vextracti64x2,		ymmi2km128
kmemdst_wrap	vextracti64x2,		zmmi2km128
kmemdst_wrap	vextractf32x8,		zmmi2km256
kmemdst_wrap	vextracti32x8,		zmmi2km256
kmemdst_wrap	vextractf64x4,		zmmi2km256
kmemdst_wrap	vextracti64x4,		zmmi2km256

kmemdst_wrap	vpmovwb,			xmm2m64
kmemdst_wrap	vpmovwb,			ymm2m128
kmemdst_wrap	vpmovwb,			zmm2m256
kmemdst_wrap	vpmovdb,			xmm2m32
kmemdst_wrap	vpmovdb,			ymm2m64
kmemdst_wrap	vpmovdb,			zmm2m128
kmemdst_wrap	vpmovdw,			xmm2m64
kmemdst_wrap	vpmovdw,			ymm2m128
kmemdst_wrap	vpmovdw,			zmm2m256
kmemdst_wrap	vpmovqb,			xmm2m16
kmemdst_wrap	vpmovqb,			ymm2m32
kmemdst_wrap	vpmovqb,			zmm2m64
kmemdst_wrap	vpmovqw,			xmm2m32
kmemdst_wrap	vpmovqw,			ymm2m64
kmemdst_wrap	vpmovqw,			zmm2m128
kmemdst_wrap	vpmovqd,			xmm2m64
kmemdst_wrap	vpmovqd,			ymm2m128
kmemdst_wrap	vpmovqd,			zmm2m256

kmemdst_wrap	vpmovswb,			xmm2m64
kmemdst_wrap	vpmovswb,			ymm2m128
kmemdst_wrap	vpmovswb,			zmm2m256
kmemdst_wrap	vpmovsdb,			xmm2m32
kmemdst_wrap	vpmovsdb,			ymm2m64
kmemdst_wrap	vpmovsdb,			zmm2m128
kmemdst_wrap	vpmovsdw,			xmm2m64
kmemdst_wrap	vpmovsdw,			ymm2m128
kmemdst_wrap	vpmovsdw,			zmm2m256
kmemdst_wrap	vpmovsqb,			xmm2m16
kmemdst_wrap	vpmovsqb,			ymm2m32
kmemdst_wrap	vpmovsqb,			zmm2m64
kmemdst_wrap	vpmovsqw,			xmm2m32
kmemdst_wrap	vpmovsqw,			ymm2m64
kmemdst_wrap	vpmovsqw,			zmm2m128
kmemdst_wrap	vpmovsqd,			xmm2m64
kmemdst_wrap	vpmovsqd,			ymm2m128
kmemdst_wrap	vpmovsqd,			zmm2m256
;
kmemdst_wrap	vpmovuswb,			xmm2m64
kmemdst_wrap	vpmovuswb,			ymm2m128
kmemdst_wrap	vpmovuswb,			zmm2m256
kmemdst_wrap	vpmovusdb,			xmm2m32
kmemdst_wrap	vpmovusdb,			ymm2m64
kmemdst_wrap	vpmovusdb,			zmm2m128
kmemdst_wrap	vpmovusdw,			xmm2m64
kmemdst_wrap	vpmovusdw,			ymm2m128
kmemdst_wrap	vpmovusdw,			zmm2m256
kmemdst_wrap	vpmovusqb,			xmm2m16
kmemdst_wrap	vpmovusqb,			ymm2m32
kmemdst_wrap	vpmovusqb,			zmm2m64
kmemdst_wrap	vpmovusqw,			xmm2m32
kmemdst_wrap	vpmovusqw,			ymm2m64
kmemdst_wrap	vpmovusqw,			zmm2m128
kmemdst_wrap	vpmovusqd,			xmm2m64
kmemdst_wrap	vpmovusqd,			ymm2m128
kmemdst_wrap	vpmovusqd,			zmm2m256

kmemdst_wrap	vpmovwb,			xmm2km64
kmemdst_wrap	vpmovwb,			ymm2km128
kmemdst_wrap	vpmovwb,			zmm2km256
kmemdst_wrap	vpmovdb,			xmm2km32
kmemdst_wrap	vpmovdb,			ymm2km64
kmemdst_wrap	vpmovdb,			zmm2km128
kmemdst_wrap	vpmovdw,			xmm2km64
kmemdst_wrap	vpmovdw,			ymm2km128
kmemdst_wrap	vpmovdw,			zmm2km256
kmemdst_wrap	vpmovqb,			xmm2km16
kmemdst_wrap	vpmovqb,			ymm2km32
kmemdst_wrap	vpmovqb,			zmm2km64
kmemdst_wrap	vpmovqw,			xmm2km32
kmemdst_wrap	vpmovqw,			ymm2km64
kmemdst_wrap	vpmovqw,			zmm2km128
kmemdst_wrap	vpmovqd,			xmm2km64
kmemdst_wrap	vpmovqd,			ymm2km128
kmemdst_wrap	vpmovqd,			zmm2km256
;
kmemdst_wrap	vpmovswb,			xmm2km64
kmemdst_wrap	vpmovswb,			ymm2km128
kmemdst_wrap	vpmovswb,			zmm2km256
kmemdst_wrap	vpmovsdb,			xmm2km32
kmemdst_wrap	vpmovsdb,			ymm2km64
kmemdst_wrap	vpmovsdb,			zmm2km128
kmemdst_wrap	vpmovsdw,			xmm2km64
kmemdst_wrap	vpmovsdw,			ymm2km128
kmemdst_wrap	vpmovsdw,			zmm2km256
kmemdst_wrap	vpmovsqb,			xmm2km16
kmemdst_wrap	vpmovsqb,			ymm2km32
kmemdst_wrap	vpmovsqb,			zmm2km64
kmemdst_wrap	vpmovsqw,			xmm2km32
kmemdst_wrap	vpmovsqw,			ymm2km64
kmemdst_wrap	vpmovsqw,			zmm2km128
kmemdst_wrap	vpmovsqd,			xmm2km64
kmemdst_wrap	vpmovsqd,			ymm2km128
kmemdst_wrap	vpmovsqd,			zmm2km256
;
kmemdst_wrap	vpmovuswb,			xmm2km64
kmemdst_wrap	vpmovuswb,			ymm2km128
kmemdst_wrap	vpmovuswb,			zmm2km256
kmemdst_wrap	vpmovusdb,			xmm2km32
kmemdst_wrap	vpmovusdb,			ymm2km64
kmemdst_wrap	vpmovusdb,			zmm2km128
kmemdst_wrap	vpmovusdw,			xmm2km64
kmemdst_wrap	vpmovusdw,			ymm2km128
kmemdst_wrap	vpmovusdw,			zmm2km256
kmemdst_wrap	vpmovusqb,			xmm2km16
kmemdst_wrap	vpmovusqb,			ymm2km32
kmemdst_wrap	vpmovusqb,			zmm2km64
kmemdst_wrap	vpmovusqw,			xmm2km32
kmemdst_wrap	vpmovusqw,			ymm2km64
kmemdst_wrap	vpmovusqw,			zmm2km128
kmemdst_wrap	vpmovusqd,			xmm2km64
kmemdst_wrap	vpmovusqd,			ymm2km128
kmemdst_wrap	vpmovusqd,			zmm2km256

kmemdst_wrap	vpcompressb,		xmm2m128
kmemdst_wrap	vpcompressw,		xmm2m128
kmemdst_wrap	vpcompressd,		xmm2m128
kmemdst_wrap	vpcompressq,		xmm2m128
kmemdst_wrap	vcompressps,		xmm2m128
kmemdst_wrap	vcompresspd,		xmm2m128

kmemdst_wrap	vpcompressb,		ymm2m256
kmemdst_wrap	vpcompressw,		ymm2m256
kmemdst_wrap	vpcompressd,		ymm2m256
kmemdst_wrap	vpcompressq,		ymm2m256
kmemdst_wrap	vcompressps,		ymm2m256
kmemdst_wrap	vcompresspd,		ymm2m256

kmemdst_wrap	vpcompressb,		zmm2m512
kmemdst_wrap	vpcompressw,		zmm2m512
kmemdst_wrap	vpcompressd,		zmm2m512
kmemdst_wrap	vpcompressq,		zmm2m512
kmemdst_wrap	vcompressps,		zmm2m512
kmemdst_wrap	vcompresspd,		zmm2m512

kmemdst_wrap	vpcompressb,		xmm2km128
kmemdst_wrap	vpcompressw,		xmm2km128
kmemdst_wrap	vpcompressd,		xmm2km128
kmemdst_wrap	vpcompressq,		xmm2km128
kmemdst_wrap	vcompressps,		xmm2km128
kmemdst_wrap	vcompresspd,		xmm2km128

kmemdst_wrap	vpcompressb,		ymm2km256
kmemdst_wrap	vpcompressw,		ymm2km256
kmemdst_wrap	vpcompressd,		ymm2km256
kmemdst_wrap	vpcompressq,		ymm2km256
kmemdst_wrap	vcompressps,		ymm2km256
kmemdst_wrap	vcompresspd,		ymm2km256

kmemdst_wrap	vpcompressb,		zmm2km512
kmemdst_wrap	vpcompressw,		zmm2km512
kmemdst_wrap	vpcompressd,		zmm2km512
kmemdst_wrap	vpcompressq,		zmm2km512
kmemdst_wrap	vcompressps,		zmm2km512
kmemdst_wrap	vcompresspd,		zmm2km512

end