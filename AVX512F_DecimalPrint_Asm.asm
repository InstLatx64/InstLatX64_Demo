.data

;u64, s64
mul_const_q			dd 05798ee24h, 000000000h, 0ad7f29ach, 000000000h, 00c6f7a0ch, 000000000h, 04f8b588fh, 000000000h, 
					   0a36e2eb2h, 000000000h, 00624dd30h, 000000000h, 047ae147bh, 000000000h, 09999999ah, 000000000h
;u32, s32
;																			9						8
mul_shuf_const_0	dd 000000000h, 000000000h, 000000000h, 000000000h, 012e0be83h, 000000000h, 05798ee24h, 000000000h
;							5						4						1						0
mul_shuf_const_1	dd 04f8b588fh, 000000000h, 0a36e2eb2h, 000000000h, 09999999ah, 000000000h, 000000001h, 000000000h
;							7						6						3						2
mul_shuf_const_2	dd 0ad7f29ach, 000000000h, 00c6f7a0ch, 000000000h, 00624dd30h, 000000000h, 047ae147bh, 000000000h
;							7						6						3						2
mul_shuf_const_3	dd 0ad7f29ach, 000000000h, 00c6f7a0ch, 000000000h, 00624dd30h, 000000000h, 047ae147bh, 000000000h

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
perm_const_q		dd	13h, 15h, 17h, 19h, 1bh, 1dh, 1fh, 01h, 03h, 05h, 07h, 09h, 0bh, 0dh, 0fh, 11h

;to_string
perm_const_tostr	dd	11h, 13h, 15h, 17h, 19h, 1bh, 1dh, 1fh, 01h, 03h, 05h, 07h, 09h, 0bh, 0dh, 0fh, 

;u64, s64
srlv_const_q		dd	17h, 13h, 10h, 0dh, 09h, 06h, 03h, 1ah, 17h, 13h, 10h, 0dh, 09h, 06h, 03h, 1ah

srlv_const_tostr	dd	1ah, 17h, 13h, 10h, 0dh, 09h, 06h, 03h, 1ah, 17h, 13h, 10h, 0dh, 09h, 06h, 03h

srlv_const			dd	20h, 20h, 20h, 20h, 20h, 20h, 1dh, 1ah, 17h, 13h, 10h, 0dh, 09h, 06h, 03h, 00h
asciiZero			dd	'0'
asciiMinus			dd	'-'

.code

align 16
_ultoa_avx512f_asm proc
	vpbroadcastd		zmm0, ecx
	mov					eax, 0ffe0h
	kmovw				k1, eax
	mov					eax, 07fffh
	kmovw				k2, eax
	vpmuludq			zmm1, zmm0, mul_shuf_const_0
	vpmuludq			zmm2, zmm0, mul_shuf_const_2
	vpcmpud				k1{k1}, zmm0, tenPows, 5
	kmovw				eax, k1
	vshufps				zmm1, zmm2, zmm1, 0ddh
	vpsubd				zmm2, zmm0, zmm1
	vpsrld				zmm0 {k2}, zmm2, 1
	vpaddd				zmm1, zmm0, zmm1
	vpsrlvd				zmm2, zmm1, srlv_const

	valignd				zmm0, zmm2, zmm2, 1
	vpslld				zmm1, zmm2, 3
	vpaddd				zmm2, zmm2, zmm2
	vpaddd				zmm1, zmm1, zmm2
	vpaddd				zmm0, zmm0, dword bcst asciiZero
	vpsubd				zmm0 {k2}{z}, zmm0, zmm1

	tzcnt				rax, rax
	sub					rdx, rax
	vpmovdb				xmmword ptr [rdx]{k1}, zmm0

	ret
_ultoa_avx512f_asm endp

align 16
_ltoa_avx512f_asm proc
	vpbroadcastd		zmm4, ecx
	mov					eax, 0fff0h
	kmovw				k3, eax
	mov					eax, 0ffe0h
	kmovw				k1, eax
	mov					eax, 07fffh
	kmovw				k2, eax
	vpabsd				zmm0, zmm4
	vpmuludq			zmm1, zmm0, mul_shuf_const_0
	vpmuludq			zmm2, zmm0, mul_shuf_const_2
	vpcmpd				k3{k3}, zmm4, tenNPows, 2
	vpcmpud				k1{k1}, zmm0, tenPows, 5
	vpbroadcastd		zmm3{k2}{z}, asciiMinus
	korw				k3, k1, k3
	kmovw				eax, k3
	vshufps				zmm1, zmm2, zmm1, 0ddh
	vpsubd				zmm2, zmm0, zmm1
	vpsrld				zmm0 {k2}, zmm2, 1
	vpaddd				zmm1, zmm0, zmm1
	vpsrlvd				zmm2, zmm1, srlv_const

	valignd				zmm0 {k2}{z}, zmm2, zmm2, 1
	vpslld				zmm1, zmm2, 3
	vpaddd				zmm2, zmm2, zmm2
	vpsubd				zmm1, zmm1, dword bcst asciiZero
	vpaddd				zmm1 {k2}{z}, zmm1, zmm2
	vpsubd				zmm3 {k1}, zmm0, zmm1

	tzcnt				rax, rax
	sub					rdx, rax
	vpmovdb				xmmword ptr [rdx]{k3}, zmm3

	ret
_ltoa_avx512f_asm endp

align 16
_ui64toa_avx512f_asm proc
	mov					r10, rdx
	mov					rdx, rcx
	vpbroadcastq		zmm16, rcx				;n
	mov					r9, 0e69594bec44de15ch	;n / 10^16
	mov					r8, 0abcc77118461cefdh	;n / 10^8

	mulx				r9, rcx, r9
	mulx				r8, rax, r8
	shr					r9, 35h					; n / 10^16 = n_19_16
	shr					r8, 1ah					; n / 10^8 = n_19_08
	imul				rcx, r9, 100000000		;n_19_16 * 100000000
	imul				rax, r8, 100000000		;n_19_8 * 100000000
	sub					r8, rcx					;n_19_8 - (n_19_16 * 100000000) = n_15_08
	sub					rdx, rax				;n - (n_19_8 * 100000000) = n_07_00

	vmovdqu32			zmm31, perm_const_q
	mov					eax, 0ff80h
	kmovw				k5, eax
	mov					eax, 0bfbfh
	kmovw				k6, eax
	mov					eax, 07fffh
	kmovw				k7, eax

	vpbroadcastd		zmm2, r9				;n_19_16
	vpbroadcastd		zmm1, r8				;n_15_08
	vpbroadcastd		zmm0, rdx				;n_07_00

	vpmuludq			zmm5, zmm2, mul_const_q
	vpmuludq			zmm4, zmm1, mul_const_q
	vpmuludq			zmm3, zmm0, mul_const_q

	vpcmpuq				k0, zmm16, tenPows_07_00, 5
	vpcmpuq				k1, zmm16, tenPows_15_08, 5
	vpcmpuq				k2, zmm16, tenPows_19_16, 5

	vpermt2d			zmm5, zmm31, zmm4
	vpermt2d			zmm3, zmm31, zmm4

	kunpckbw			k1, k0, k1
	kshiftlw			k2, k2, 11
	kmovw				r8d, k1
	kmovw				r9d, k2

	vpblendmd			zmm0 {k5}, zmm1, zmm0
	vpblendmd			zmm1 {k7}, zmm1, zmm2

	vpsubd				zmm4, zmm1, zmm5
	vpsubd				zmm2, zmm0, zmm3
	vpsrld				zmm4, zmm4, 1
	vpsrld				zmm2, zmm2, 1
	vpaddd				zmm4, zmm4, zmm5
	vpaddd				zmm2, zmm2, zmm3
	vpsrlvd				zmm4, zmm4, srlv_const_q
	vpsrlvd				zmm2, zmm2, srlv_const_q

	valignd				zmm0 {k6}, zmm2, zmm2, 1
	valignd				zmm1 {k6}, zmm2, zmm4, 1

	vpslld				zmm3, zmm2, 3
	vpslld				zmm5, zmm4, 3
	vpaddd				zmm2, zmm2, zmm2
	vpaddd				zmm4, zmm4, zmm4
	vpaddd				zmm2, zmm2, zmm3
	vpaddd				zmm4, zmm4, zmm5

	vpaddd				zmm0, zmm0, dword bcst asciiZero
	vpaddd				zmm1, zmm1, dword bcst asciiZero
	vpsubd				zmm0{k7}{z}, zmm0, zmm2
	vpsubd				zmm1, zmm1, zmm4

	shl					r8d, 16
	or					r9d, r8d
	tzcnt				r9, r9
	sub					r10, r9
	vpmovdb				xmmword ptr [r10]{k2}, zmm1
	vpmovdb				xmmword ptr [r10 + 10h]{k1}, zmm0

	ret
_ui64toa_avx512f_asm endp

align 16
_i64toa_avx512f_asm proc
	mov					r10, rdx
	mov					rdx, rcx
	neg					rdx
	cmovs				rdx, rcx				;abs(n)
	vpbroadcastq		zmm16, rdx				;an
	mov					r9, 0e69594bec44de15ch	;an / 10^16
	mov					r8, 0abcc77118461cefdh	;an / 10^8

	mulx				r9, r11, r9
	mulx				r8, rax, r8
	shr					r9, 35h					;an / 10^16 = n_19_16
	shr					r8, 1ah					;an / 10^8 = n_19_08
	imul				r11, r9, 100000000		;n_19_16 * 100000000
	imul				rax, r8, 100000000		;n_19_8 * 100000000
	sub					r8, r11					;n_19_8 - (n_19_16 * 100000000) = n_15_08
	sub					rdx, rax				;an - (n_19_8 * 100000000) = n_07_00

	vmovdqu32			zmm31, perm_const_q
	mov					eax, 0ff80h
	kmovw				k5, eax
	mov					eax, 0bfbfh
	kmovw				k6, eax
	mov					eax, 07fffh
	kmovw				k7, eax

	vpbroadcastd		zmm2, r9				;n_19_16
	vpbroadcastd		zmm1, r8				;n_15_08
	vpbroadcastd		zmm0, rdx				;n_07_00

	vpmuludq			zmm5, zmm2, mul_const_q
	vpmuludq			zmm4, zmm1, mul_const_q
	vpmuludq			zmm3, zmm0, mul_const_q

	vpcmpuq				k0, zmm16, tenPows_07_00, 5
	vpcmpuq				k1, zmm16, tenPows_15_08, 5
	vpcmpuq				k2, zmm16, tenPows_19_16, 5

	vpblendmd			zmm0 {k5}, zmm1, zmm0
	vpblendmd			zmm1 {k7}, zmm1, zmm2

	vpermt2d			zmm5, zmm31, zmm4
	vpermt2d			zmm3, zmm31, zmm4

	kunpckbw			k1, k0, k1
	kshiftlw			k2, k2, 11
	kmovw				r8d, k1
	kmovw				r9d, k2

	vpsubd				zmm4, zmm1, zmm5
	vpsubd				zmm2, zmm0, zmm3
	vpsrld				zmm4, zmm4, 1
	vpsrld				zmm2, zmm2, 1
	vpaddd				zmm4, zmm4, zmm5
	vpaddd				zmm2, zmm2, zmm3
	vpsrlvd				zmm4, zmm4, srlv_const_q
	vpsrlvd				zmm2, zmm2, srlv_const_q

	valignd				zmm0 {k6}, zmm2, zmm2, 1
	valignd				zmm1 {k6}, zmm2, zmm4, 1

	vpslld				zmm3, zmm2, 3
	vpslld				zmm5, zmm4, 3
	vpaddd				zmm2, zmm2, zmm2
	vpaddd				zmm4, zmm4, zmm4
	vpaddd				zmm2{k7}{z}, zmm2, zmm3
	vpaddd				zmm4, zmm4, zmm5

	vpaddd				zmm0{k7}{z}, zmm0, dword bcst asciiZero
	vpaddd				zmm1, zmm1, dword bcst asciiZero
	vpbroadcastd		zmm3, asciiMinus
	vmovdqa32			zmm5, zmm3
	vpsubd				zmm5{k2}, zmm1, zmm4
	vpsubd				zmm3{k1}, zmm0, zmm2

	sar					rcx, 63
	shl					r8d, 16
	or					r8d, r9d
	and					ecx, r8d
	shr					ecx, 1
	or					r8, rcx
	tzcnt				r9, r8
	kmovw				k2, r8d
	shr					r8d, 16
	kmovw				k1, r8d
	sub					r10, r9
	vpmovdb				xmmword ptr [r10]{k2}, zmm5
	vpmovdb				xmmword ptr [r10 + 10h]{k1}, zmm3

	ret
_i64toa_avx512f_asm endp

align 16
to_string_avx512f_asm proc
	mov					r9, 0abcc77118461cefdh
	mov					r8, rdx
	mov					rdx, rcx
	mulx				r9, rcx, r9
	shr					r9, 1ah					;n / 10^8
	imul				rcx, r9, 100000000		;n % 10^8
	sub					rdx, rcx				;n - (n_15_08 * 100000000)

	mov					eax, 0ff00h
	kmovw				k1, eax
	mov					eax, 0ff7fh
	kmovw				k2, eax
	vmovdqu32			zmm31, perm_const_tostr

	vpbroadcastd		zmm1, r9				;n_15_08
	vpbroadcastd		zmm0, rdx				;n_07_00

	vpmuludq			zmm3, zmm1, mul_const_q
	vpmuludq			zmm2, zmm0, mul_const_q
	vpblendmd			zmm4 {k1}, zmm1, zmm0
	mov					eax, 10
	vpbroadcastd		zmm30, eax

	vpermt2d			zmm2, zmm31, zmm3
	vpsubd				zmm3, zmm4, zmm2
	vpsrld				zmm3, zmm3, 1
	vpaddd				zmm3, zmm3, zmm2
	vpsrlvd				zmm3, zmm3, srlv_const_tostr

	valignd				zmm1 {k2}, zmm0, zmm3, 1
	vpmulld				zmm2, zmm3, zmm30
	vpaddd				zmm1, zmm1, dword bcst asciiZero
	vpsubd				zmm0, zmm1, zmm2
	vpmovdb				xmmword ptr [r8], zmm0

	ret
to_string_avx512f_asm endp


end