.data

;u32, s32, u64, s64
;						00000000002af31ddh- 1 = 8th digit
;						 mod 10^8 const - 1       mod 10^7           mod 10^6            mod 10^5            mod 10^4            mod 10^3            mod 10^2           mod 10^1
ifma_const			dq	00000000002af31dch, 0000000001ad7f29bh, 0000000010c6f7a0ch, 00000000a7c5ac472h, 000000068db8bac72h, 0000004189374bc6bh, 0000028f5c28f5c29h, 0000199999999999ah

;u64, s64
;								10^6                10^5                10^4                10^3                10^2               10^1                  0                   0
tenPows_07_00		dq	000000000000f4240h, 000000000000186a0h, 00000000000002710h, 000000000000003e8h, 00000000000000064h, 0000000000000000ah, 00000000000000000h, 00000000000000000h
;								10^14               10^13               10^12               10^11               10^10              10^9                10^8                10^7       
tenPows_15_08		dq	000005af3107a4000h, 0000009184e72a000h, 0000000e8d4a51000h, 0000000174876e800h, 000000002540be400h, 0000000003b9aca00h, 00000000005f5e100h, 00000000000989680h
;								10^19               10^18               10^17               10^16               10^15                 0                 0                    0        
tenPows_19_16		dq	08ac7230489e80000h, 00de0b6b3a7640000h, 0016345785d8a0000h, 0002386f26fc10000h, 000038d7ea4c68000h, 00000000000000000h, 00000000000000000h, 00000000000000000h

;u32, s32
;						                                                              10^9        10^8        10^7        10^6        10^5        10^4        10^3        10^2        10^1        0           0
tenPows				dd	000000000h, 000000000h, 000000000h, 000000000h, 000000000h, 03b9aca00h, 005f5e100h, 000989680h, 0000f4240h, 0000186a0h, 000002710h, 0000003e8h, 000000064h, 00000000ah, 000000000h, 000000000h
;s32
;						                                                  -10^9       -10^8       -10^7       -10^6       -10^5       -10^4       -10^3       -10^2       -10^1      -10^0        0           0
tenNPows			dd	000000000h, 000000000h, 000000000h, 000000000h, 0c4653600h, 0fa0a1f00h, 0ff676980h, 0fff0bdc0h, 0fffe7960h, 0ffffd8f0h, 0fffffc18h, 0ffffff9ch, 0fffffff6h, 0ffffffffh, 000000000h, 000000000h

;u64, s64
permb_const_06_00	dq	03F3F3F3F3F3F3F3Fh, 03F3F3F3F3F3F3F3Fh, 03F3F3F3F3F3F3F3Fh, 03F38302820181008h
permb_const_13_07	dq	03F3F3F3F3F3F3F3Fh, 03F3F3F3F3F3F3F3Fh, 0383028201810083Fh, 03F3F3F3F3F3F3F3Fh
permb_const_19_14	dq	03F3F3F3F3F3F3F3Fh, 030282018103F3F3Fh, 03F3F3F3F3F3F3F38h, 03F3F3F3F3F3F3F3Fh

;u32, s32
permb_const_09_00	db  07fh, 07fh, 07fh, 07fh, 07fh, 028h, 030h, 038h, 048h, 050h, 058h, 060h, 068h, 070h, 078h, 07fh
permb_const_15_00	db  000h, 008h, 010h, 018h, 020h, 028h, 030h, 038h, 040h, 048h, 050h, 058h, 060h, 068h, 070h, 078h

;s32, s64
asciiMinus			dq  02D2D2D2D2D2D2D2Dh, 02D2D2D2D2D2D2D2Dh

;u32, s32, u64, s64
asciiZero			dq  '0'
ten					dq  10
_8th_digit_bias		dd	01a1a400h ; 10^(-8) bias

.code

align 16
_ultoa_avx512ifma_asm proc
	vpbroadcastd		zmm2, ecx
	mov					r9d, 0d6bf94d6h
	mov					r8, rdx
	mov					edx, ecx
	mulx				r9d, ecx, r9d
	shr					r9d, 17h				;n / 10^7
	imul				ecx, r9d, 10000000		;n_9_7 * 10000000
	sub					edx, ecx				;n - (n_9_7 * 10000000)
	mov					eax, 0ffe0h
	kmovw				k1, eax
	vpbroadcastq		zmm5, asciiZero
	vpbroadcastq		zmm1, r9				;n_09_07
	vpbroadcastq		zmm0, rdx				;n_06_00
	vpxor				xmm3, xmm3, xmm3
	vpxor				xmm4, xmm4, xmm4
	vpcmpud				k1{k1}, zmm2, tenPows, 5
	vmovdqa64			zmm2, zmm5
	kmovw				eax, k1

	vpmadd52luq			zmm4, zmm1, ifma_const
	vpmadd52luq			zmm3, zmm0, ifma_const
	vpmadd52huq			zmm2, zmm4, qword bcst ten
	vpmadd52huq			zmm5, zmm3, qword bcst ten
	vmovdqu				xmm0, xmmword ptr [permb_const_09_00]
	vpermi2b			zmm0, zmm2, zmm5
	tzcnt				rax, rax
	sub					r8, rax
	vmovdqu8			[r8] {k1}, xmm0

	ret
_ultoa_avx512ifma_asm endp

align 16
_ltoa_avx512ifma_asm proc
	vpbroadcastd		zmm2, ecx				;n
	mov					r8, rdx
	mov					edx, ecx
	neg					edx
	cmovs				edx, ecx				;abs(n)
	mov					r9d, 0d6bf94d6h
	mulx				r9d, ecx, r9d
	shr					r9d, 17h				;an / 10^7
	imul				ecx, r9d, 10000000		;n_9_7 * 10000000
	sub					edx, ecx				;an - (n_9_7 * 10000000)
	mov					eax, 0ffe0h
	kmovw				k1, eax
	mov					eax, 0fff0h
	kmovw				k2, eax
	vpbroadcastq		zmm5, asciiZero
	vpbroadcastq		zmm1, r9				;n_09_07
	vpbroadcastq		zmm0, rdx				;n_06_00
	vpcmpd				k2{k2}, zmm2, tenNPows, 2
	vpabsd				zmm4, zmm2
	vpcmpud				k1{k1}, zmm4, tenPows, 5
	vpxor				xmm3, xmm3, xmm3
	vpxor				xmm4, xmm4, xmm4
	vmovdqa64			zmm2, zmm5
	korw				k2, k1, k2
	kmovw				eax, k2

	vpmadd52luq			zmm4, zmm1, ifma_const
	vpmadd52luq			zmm3, zmm0, ifma_const
	vpmadd52huq			zmm2, zmm4, qword bcst ten
	vpmadd52huq			zmm5, zmm3, qword bcst ten
	vmovdqu				xmm0, xmmword ptr [permb_const_09_00]
	vpmovm2b			xmm1, k1
	vpermi2b			zmm0, zmm2, zmm5
	vpternlogd			xmm0, xmm1, dword bcst asciiMinus, 0e2h ;b ? a : c
	tzcnt				rax, rax
	sub					r8, rax
	vmovdqu8			[r8] {k2}, xmm0

	ret
_ltoa_avx512ifma_asm endp

align 16
_ui64toa_avx512ifma_asm proc
	mov					r10, rdx
	mov					rdx, rcx
	vpbroadcastq		zmm16, rcx				;n
	mov					r9, 0b424dc35095cd810h	;n / 10^14
	mov					r8, 0d6bf94d5e57a42bdh	;n / 10^7

	mulx				r9, rcx, r9
	mulx				r8, rax, r8
	shr					r9, 2eh					; n / 10^14 = n_19_14
	shr					r8, 17h					; n / 10^7 = n_19_07
	imul				rcx, r9, 10000000		;n_19_14 * 10000000
	imul				rax, r8, 10000000		;n_19_07 * 10000000
	sub					r8, rcx					;n_19_07 - (n_19_14 * 10000000) = n_13_07
	sub					rdx, rax				;n - (n_19_07 * 10000000) = n_06_00

	vpxor				xmm5, xmm5, xmm5
	vpxor				xmm4, xmm4, xmm4
	vpxor				xmm3, xmm3, xmm3

	vpbroadcastq		zmm19, asciiZero
	vmovdqa64			zmm18, zmm19
	vmovdqa64			zmm17, zmm19
	vpbroadcastq		zmm2, r9				;n_19_14
	vpbroadcastq		zmm1, r8				;n_13_07
	vpbroadcastq		zmm0, rdx				;n_06_00

	vmovdqu64			zmm20, ifma_const
	vpbroadcastq		zmm21, ten

	vpmadd52luq			zmm5, zmm2, zmm20
	vpmadd52luq			zmm4, zmm1, zmm20
	vpmadd52luq			zmm3, zmm0, zmm20
	vpmadd52huq			zmm19, zmm5, zmm21
	vpmadd52huq			zmm18, zmm4, zmm21
	vpmadd52huq			zmm17, zmm3, zmm21

	vpcmpuq				k0, zmm16, tenPows_07_00, 5
	vpcmpuq				k1, zmm16, tenPows_15_08, 5
	vpcmpuq				k2, zmm16, tenPows_19_16, 5

	kunpckbw			k0, k0, k1
	kshiftlw			k2, k2, 8 + 3
	kunpckwd			k1, k0, k2
	kmovd				eax, k1

	vmovdqu64			zmm24, permb_const_19_14
	vmovdqu64			zmm23, permb_const_13_07
	vmovdqu64			zmm22, permb_const_06_00

	vpermb				zmm2, zmm24, zmm19
	vpermb				zmm1, zmm23, zmm18
	vpermb				zmm0, zmm22, zmm17

	tzcnt				rax, rax
	sub					r10, rax
	vpternlogd			ymm0, ymm1, ymm2, 0feh	;orABC
	vmovdqu8			ymmword ptr [r10]{k1}, ymm0

	ret
_ui64toa_avx512ifma_asm endp

align 16
_i64toa_avx512ifma_asm proc
	mov					r10, rdx
	mov					rdx, rcx
	neg					rdx
	cmovs				rdx, rcx				;abs(n)
	vpbroadcastq		zmm16, rdx
	mov					r9, 0b424dc35095cd810h	;an / 10^14
	mov					r8, 0d6bf94d5e57a42bdh	;an / 10^7

	mulx				r9, r11, r9
	mulx				r8, rax, r8
	shr					r9, 2eh					;an / 10^14 = n_19_14
	shr					r8, 17h					;an / 10^7 = n_19_07
	imul				r11, r9, 10000000		;n_19_14 * 10000000
	imul				rax, r8, 10000000		;n_19_07 * 10000000
	sub					r8, r11					;n_19_07 - (n_19_14 * 10000000) = n_13_07
	sub					rdx, rax				;an - (n_19_07 * 10000000) = n_06_00

	vpxor				xmm5, xmm5, xmm5
	vpxor				xmm4, xmm4, xmm4
	vpxor				xmm3, xmm3, xmm3

	vpbroadcastq		zmm19, asciiZero
	vmovdqa64			zmm18, zmm19
	vmovdqa64			zmm17, zmm19
	vpbroadcastq		zmm2, r9				;n_19_14
	vpbroadcastq		zmm1, r8				;n_13_07
	vpbroadcastq		zmm0, rdx				;n_06_00

	vmovdqu64			zmm20, ifma_const
	vpbroadcastq		zmm21, ten

	vpmadd52luq			zmm5, zmm2, zmm20
	vpmadd52luq			zmm4, zmm1, zmm20
	vpmadd52luq			zmm3, zmm0, zmm20
	vpmadd52huq			zmm19, zmm5, zmm21
	vpmadd52huq			zmm18, zmm4, zmm21
	vpmadd52huq			zmm17, zmm3, zmm21

	vpcmpuq				k0, zmm16, tenPows_07_00, 5
	vpcmpuq				k1, zmm16, tenPows_15_08, 5
	vpcmpuq				k2, zmm16, tenPows_19_16, 5

	kunpckbw			k0, k0, k1
	kshiftlw			k2, k2, 8 + 3
	kunpckwd			k1, k0, k2
	kmovd				eax, k1
	vpmovm2b			ymm3, k1

	vmovdqu64			zmm24, permb_const_19_14
	vmovdqu64			zmm23, permb_const_13_07
	vmovdqu64			zmm22, permb_const_06_00

	vpermb				zmm2, zmm24, zmm19
	vpermb				zmm1, zmm23, zmm18
	vpermb				zmm0, zmm22, zmm17
	vpternlogd			ymm0, ymm1, ymm2, 0feh
	vpternlogd			ymm0, ymm3, dword bcst asciiMinus, 0e2h ;b ? a : c
	
	sar					rcx, 63
	and					ecx, eax
	shr					ecx, 1
	or					eax, ecx
	kmovd				k1, eax
	tzcnt				rax, rax
	sub					r10, rax
	vmovdqu8			ymmword ptr [r10]{k1}, ymm0

	ret
_i64toa_avx512ifma_asm endp

align 16
to_string_avx512ifma_asm proc
	mov					r9, 0abcc77118461cefdh
	mov					r8, rdx
	mov					rdx, rcx
	mulx				r9, rcx, r9
	shr					r9, 1ah					;n / 10^8
	imul				rcx, r9, 100000000		;n % 10^8
	sub					rdx, rcx				;n - (n_15_08 * 100000000)
	vmovd				xmm3, _8th_digit_bias
	vmovdqu				xmm4, xmm3
	vpbroadcastq		zmm5, asciiZero
	vpbroadcastq		zmm1, r9				;n_15_08
	vpbroadcastq		zmm0, rdx				;n_07_00
	vmovdqa64			zmm2, zmm5

	vpmadd52luq			zmm4, zmm1, ifma_const
	vpmadd52luq			zmm3, zmm0, ifma_const
	vpmadd52huq			zmm2, zmm4, qword bcst ten
	vpmadd52huq			zmm5, zmm3, qword bcst ten
	vmovdqu				xmm0, xmmword ptr [permb_const_15_00]
	vpermi2b			zmm0, zmm2, zmm5
	vmovdqu				xmmword ptr [r8], xmm0

	ret
to_string_avx512ifma_asm endp


end