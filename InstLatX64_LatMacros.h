InstLatX64_domain macro REGISTER, DOMAIN
	IF DOMAIN EQ 1
		vpor				REGISTER, REGISTER, REGISTER
	ELSEIF DOMAIN EQ 2
		vorpd				REGISTER, REGISTER, REGISTER
	ELSEIF DOMAIN EQ 3
		por					REGISTER, REGISTER
	ELSEIF DOMAIN EQ 4
		orpd				REGISTER, REGISTER
	ELSEIF DOMAIN EQ 5
	ENDIF
endm

InstLatX64_empty_lat macro INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_mm2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				mm0, mm0
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_mm2mmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_mm2mm_lat INST, DOMAINSTART, DOMAINEND 
endm

InstLatX64_mmi2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				mm0, mm0, 1
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_i2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				mm0, 1
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_mm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				xmm0, mm0
	movdq2q				mm0, xmm0
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_xmm2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	xmm0, DOMAINSTART
	INST				mm0, xmm0
	movq2dq				xmm0, mm0
	InstLatX64_domain	xmm0, DOMAINEND
endm

InstLatX64_mm2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				eax, mm0
	movd				mm0, eax
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_mmi2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	INST				eax, mm0, 1
	movd				mm0, eax
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_gpr32_2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	movd				eax, mm0
	INST				mm0, eax
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_gpr32i2mm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain	mm0, DOMAINSTART
	movd				eax, mm0
	INST				mm0, eax, 1
	InstLatX64_domain	mm0, DOMAINEND
endm

InstLatX64_xmm2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					eax, xmm0
	vmovd					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmmi2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					eax, xmm0, 0
	vmovd					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmm2gpr64_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					rax, xmm0
	vmovd					xmm0, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmmi2gpr64_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					rax, xmm0, 0
	vmovd					xmm0, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					eax, ymm0
	vmovd					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2gpr64_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					rax, ymm0
	vmovd					xmm0, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32i2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	movd					eax, xmm0
	INST					xmm0, eax, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64i2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	movd					rax, xmm0
	INST					xmm0, rax, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32_2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32_2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64_2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					rax, xmm0
	INST					xmm0, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32ixmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0, xmm0, eax, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64ixmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					rax, xmm0
	INST					xmm0, xmm0, rax, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0, xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					rax, xmm0
	INST					xmm0, xmm0, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmm2xmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmm2xmm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmm2xmm_lat	INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_xmm2xmm2_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmm2xmm_lat	INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_ymm2ymm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_ymm2ymm_lat	INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_xmm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ymm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, ymm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_m128_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, xmmword ptr [memop0 + 00h]
	vmovdqa					xmmword ptr [memop0], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m64_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, qword ptr [memop0 + 00h]
	vmovq					qword ptr [memop0 + 00h], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m32_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, dword ptr [memop0 + 00h]
	vmovd					dword ptr [memop0 + 00h], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m16_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, word ptr [memop0 + 00h]
	vmovd					dword ptr [memop0 + 00h], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m8_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, byte ptr [memop0 + 00h]
	vmovd					dword ptr [memop0 + 00h], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmymmi02ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmm0, 1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmzmmi02zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, xmm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_xmmzmmi2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, xmm0, 1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_ymmzmmi02zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, ymm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_ymmzmmi2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, ymm0, 1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_m128ymmi02ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmmword ptr [memop0], 0
	vmovdqa					xmmword ptr [memop0], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m128ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmmword ptr [memop0], 1
	vmovdqa					xmmword ptr [memop0], xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ymmi02m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0 + 00h], ymm0, 0
	vmovdqa					xmm0, xmmword ptr [memop0 + 00h]
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0 + 00h], ymm0, 1
	vmovdqa					xmm0, xmmword ptr [memop0 + 00h]
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi02km128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0 + 00h]{k1}, ymm0, 0
	vmovdqa					xmm0, xmmword ptr [memop0 + 00h]
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi2km128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0 + 00h]{k1}, ymm0, 1
	vmovdqa					xmm0, xmmword ptr [memop0 + 00h]
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi02xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, ymm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, ymm0, 1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_zmmi02xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, zmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_zmmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, zmm0, 1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_zmmi02ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, zmm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, zmm0, 1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2xmm2xmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2ymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_evex_2xmm2xmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, xmm0, xmm1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_evex_2ymm2ymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, ymm0, ymm1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2zmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, zmm1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmm2xmm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_2xmm2xmm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_2ymm2ymm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_2ymm2ymm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_2xmm2xmm2_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_2xmm2xmm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_2ymm2ymm2_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_2ymm2ymm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_i2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmmi2xmm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmmi2xmm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_xmmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					ymm0, xmm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2xmmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2xmmi2kxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0{k1}, xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2xmmi2zkxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0{k1}{z}, xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2xmmi2xmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm1, xmm2, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2xmmi2kxmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0{k1}, xmm1, xmm2, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2xmmi2zkxmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0{k1}{z}, xmm1, xmm2, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_m256ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymmword ptr [memop0 + 00h], 0
	vmovdqa					ymmword ptr [memop0 + 00h], ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_3xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_3ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_3xmm2xmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm1, xmm2
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_3ymm2ymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm1, ymm2
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ii2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, 0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmmii2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, 0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmm2F_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0
	cmove					eax, edx
	vmovd					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2F_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0
	cmove					eax, edx
	vmovd					xmm0, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_noop_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_noop1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_x87_1op_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST	st(0)
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_x87_2op_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					st(0), st(0)
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_x87_2op1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_x87_2op_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_x87_2opR_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_x87_2op_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_x87_fstp_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST	
	fstp					st(0)
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_x87_1op_fstp_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					st(0)
	fstp					st(0)
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi102ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymm0, 30h
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi2kymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0{k1}, ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi2zkymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0{k1}{z}, ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi2ymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm1, ymm2, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi2kymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0{k1}, ymm1, ymm2, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2ymmi2zkymmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0{k1}{z}, ymm1, ymm2, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmm0_2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_xmm0_2xmm1_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmm0_2xmm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_xmm0_2xmm2_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmm0_2xmm_lat INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_x87_m32l_lat macro INST, DOMAINSTART, DOMAINEND
	INST	dword ptr [memop0]
	fstp	st(0)
endm

InstLatX64_x87_m64l_lat macro INST, DOMAINSTART, DOMAINEND
	INST	qword ptr [memop0]
	fstp	st(0)
endm

InstLatX64_x87_m80l_lat macro INST, DOMAINSTART, DOMAINEND
	INST	tbyte ptr [memop0]
	fstp	st(0)
endm

InstLatX64_x87_m32s_lat macro INST, DOMAINSTART, DOMAINEND
	fld1
	INST	dword ptr [memop0]
endm

InstLatX64_x87_m64s_lat macro INST, DOMAINSTART, DOMAINEND
	fld1
	INST	qword ptr [memop0]
endm

InstLatX64_x87_m80s_lat macro INST, DOMAINSTART, DOMAINEND
	fld1
	INST	tbyte ptr [memop0]
endm

InstLatX64_evex_xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

;InstLatX64_evex_xmm2m128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	evex INST				xmmword ptr [memop0], xmm0
;	vmovdqa					xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_evex_ymm2m256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	evex INST				ymmword ptr [memop0], ymm0
;	vmovdqa					ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm

InstLatX64_xmm2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0], xmm0
	vmovdqa					xmm0, xmmword ptr [memop0]
	InstLatX64_domain		xmm0, DOMAINEND
endm

;InstLatX64_xmm2m64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					qword ptr [memop0], xmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2m32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					dword ptr [memop0], xmm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2m16_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					word ptr [memop0], xmm0
;	vpbroadcastw			xmm0, word ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2km64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}, xmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2km32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					dword ptr [memop0]{k1}, xmm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2km16_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					word ptr [memop0]{k1}, xmm0
;	vpbroadcastw			xmm0, word ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2zkm64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}{z}, xmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2zkm32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					dword ptr [memop0]{k1}{z}, xmm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2zkm16_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					word ptr [memop0]{k1}{z}, xmm0
;	vpbroadcastw			xmm0, word ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm

InstLatX64_ymm2m256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymmword ptr [memop0], ymm0
	vmovdqa					ymm0, ymmword ptr [memop0]
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ymm2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					xmmword ptr [memop0], ymm0
	vmovdqa					xmm0, xmmword ptr [memop0]
	InstLatX64_domain		ymm0, DOMAINEND
endm

;InstLatX64_ymm2m64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					qword ptr [memop0], ymm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2m32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					dword ptr [memop0], ymm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}, ymm0
;	vmovdqa					xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2km64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}, ymm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2km32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					dword ptr [memop0]{k1}, ymm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2zkm128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}{z}, ymm0
;	vmovdqa					xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2zkm64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}{z}, ymm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_ymm2zkm32_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					dword ptr [memop0]{k1}{z}, ymm0
;	vmovd					xmm0, dword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm

InstLatX64_zmm2m512_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmmword ptr [memop0], zmm0
	vmovdqa32				zmm0, zmmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmm2m256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					ymmword ptr [memop0], zmm0
	vmovdqa32				ymm0, ymmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi2m256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					ymmword ptr [memop0], zmm0, 1
	vmovdqa32				ymm0, ymmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi02m256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					ymmword ptr [memop0], zmm0, 0
	vmovdqa32				ymm0, ymmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi2km256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					ymmword ptr [memop0]{k1}, zmm0, 1
	vmovdqa32				ymm0, ymmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi02km256_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					ymmword ptr [memop0]{k1}, zmm0, 0
	vmovdqa32				ymm0, ymmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmm2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					xmmword ptr [memop0], zmm0
	vmovdqa32				xmm0, xmmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					xmmword ptr [memop0], zmm0, 1
	vmovdqa32				xmm0, xmmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmmi02m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					xmmword ptr [memop0], zmm0, 0
	vmovdqa32				xmm0, xmmword ptr [memop0]
	InstLatX64_domain		zmm0, DOMAINEND
endm

;InstLatX64_zmmi2km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0], zmm0{k1}, 1
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmmi02km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0], zmm0{k1}, 0
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmmi2km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}, zmm0, 1
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmmi02km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}, zmm0, 0
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2m64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					qword ptr [memop0], zmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2km256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}, zmm0
;	vmovdqa32				ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmmi2km256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}, zmm0, 1
;	vmovdqa32				ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmmi02km256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}, zmm0, 0
;	vmovdqa32				ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}, zmm0
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2km64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}, zmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2zkm256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}{z}, zmm0
;	vmovdqa32				ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2zkm128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}{z}, zmm0
;	vmovdqa32				xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_zmm2zkm64_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					qword ptr [memop0]{k1}{z}, zmm0
;	vmovq					xmm0, qword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2km128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	INST					xmmword ptr [memop0]{k1}, xmm0
;	vmovdqa					xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_ymm2km256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}, ymm0
;	vmovdqa					ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_zmm2km512_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					zmmword ptr [memop0]{k1}, zmm0
;	vmovdqa32				zmm0, zmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm
;
;InstLatX64_xmm2zkm128_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		xmm0, DOMAINSTART
;	;vpcompressb				xmmword ptr [memop0]{k1}, xmm0
;	;vpmovqb					word ptr [memop0]{k1}, xmm0
;	;vpmovqb					word ptr [memop0]{k1}{z}, xmm0
;	;vextracti32x8			ymmword ptr [memop0]{k1}{z}, zmm0, 1
;	;vmovaps					ymmword ptr [memop0]{k1}, ymm0
;	;vmovaps					ymmword ptr [memop0]{k1}{z}, ymm0
;	INST					xmmword ptr [memop0]{k1}, xmm0
;	vmovdqa					xmm0, xmmword ptr [memop0]
;	InstLatX64_domain		xmm0, DOMAINEND
;endm
;
;InstLatX64_ymm2zkm256_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		ymm0, DOMAINSTART
;	INST					ymmword ptr [memop0]{k1}{z}, ymm0
;	vmovdqa					ymm0, ymmword ptr [memop0]
;	InstLatX64_domain		ymm0, DOMAINEND
;endm
;
;InstLatX64_zmm2zkm512_lat macro INST, DOMAINSTART, DOMAINEND
;	InstLatX64_domain		zmm0, DOMAINSTART
;	INST					zmmword ptr [memop0]{k1}{z}, zmm0
;	vmovdqa32				zmm0, zmmword ptr [memop0]
;	InstLatX64_domain		zmm0, DOMAINEND
;endm

InstLatX64_evex_xmm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_evex_ymm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, ymm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_evex_ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmm2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, xmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_ymm2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, ymm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_zmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, zmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_zmm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, zmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmm2kxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0 {k1}, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2kymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0 {k1}, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmm2kzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0 {k1}, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_xmm2zkxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0 {k1}{z}, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2zkymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0 {k1}{z}, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmm2zkzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0 {k1}{z}, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmm2kxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0 {k1}, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2kymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0 {k1}, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2kzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0 {k1}, zmm0, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmm2zkxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0 {k1}{z}, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2zkymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0 {k1}{z}, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2zkzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0 {k1}{z}, zmm0, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm


InstLatX64_zmm2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_evex_xmmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_evex_ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_evex_ymmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, ymm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_zmmi2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_evex_2xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_evex_2ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_evex_2xmmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	evex INST				xmm0, xmm0, xmm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_evex_2ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST				ymm0, ymm0, ymm0, 0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmmi2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, zmm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2zmmi2kzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0{k1}, zmm0, zmm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2zmmi2zkzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0{k1}{z}, zmm0, zmm0, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2zmmi2zmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm1, zmm2, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2zmmi2kzmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0{k1}, zmm1, zmm2, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2zmmi2zkzmmRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0{k1}{z}, zmm1, zmm2, 0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_vex_2xmm2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vex INST				xmm0, xmm0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_vex_2ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vex INST				ymm0, ymm0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_evex_xmmymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	evex INST					ymm0, ymm0, xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmzmm2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, zmm0, xmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k0, xmm0, xmm0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k0, ymm0, ymm0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k0, zmm0, zmm0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmmk2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k1{k1}, xmm0, xmm0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymmk2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k1{k1}, ymm0, ymm0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmmk2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k1{k1}, zmm0, zmm0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmm2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k0, xmm0, xmm1
	vpmovm2b				xmm0, k0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymm2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k0, ymm0, ymm1
	vpmovm2b				xmm0, k0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmm2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k0, zmm0, zmm1
	vpmovm2b				xmm0, k0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmmk2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k1{k1}, xmm0, xmm1
	vpmovm2b				xmm0, k1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymmk2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k1{k1}, ymm0, ymm1
	vpmovm2b				xmm0, k1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmmk2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k1{k1}, zmm0, zmm1
	vpmovm2b				xmm0, k1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_xmm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k0, xmm0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k0, ymm0
	vpmovm2b				ymm0, k0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmm2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k0, zmm0
	vpmovm2b				zmm0, k0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_k2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, k0
	vpmovb2m				k0, xmm0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_k2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, k0
	vpmovb2m				k0, ymm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_k2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					zmm0, k0
	vpmovb2m				k0, zmm0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k0, xmm0, xmm0, 0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k0, ymm0, ymm0, 0
	vpmovm2b				ymm0, k0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k0, zmm0, zmm0, 0
	vpmovm2b				zmm0, k0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_xmmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k0, xmm0, 0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k0, ymm0, 0
	vpmovm2b				xmm0, k0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmmi2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k0, zmm0, 0
	vpmovm2b				zmm0, k0
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_xmmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k1{k1}, xmm0, 0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k1{k1}, ymm0, 0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_zmmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k1{k1}, zmm0, 0
	vpmovm2b				zmm0, k1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_2xmmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					k1{k1}, xmm0, xmm0, 0
	vpmovm2b				xmm0, k1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_2ymmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					k1{k1}, ymm0, ymm0, 0
	vpmovm2b				ymm0, k1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_2zmmik2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	INST					k1{k1}, zmm0, zmm0, 0
	vpmovm2b				zmm0, k1
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_k2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_2k2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, k0, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_2k2kRot_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, k0, k1
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_ki2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, k0, 0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_2k2c_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, k0
	cmovz					rax, rdx
	kmovq					k0, rax
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_gpr32_2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, eax
	kmovd					eax, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_gpr64_2k_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	INST					k0, rax
	kmovq					rax, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_k2gpr32_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	kmovd					k0, eax
	INST					eax, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_k2gpr64_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		k0, DOMAINSTART
	kmovd					k0, rax
	INST					rax, k0
	InstLatX64_domain		k0, DOMAINEND
endm

InstLatX64_gpr32_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					ymm0, eax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr32_2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					zmm0, eax
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_gpr32_2kxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0{k1}, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32_2kymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					ymm0{k1}, eax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr32_2kzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					zmm0{k1}, eax
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_gpr32_2zkxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					xmm0{k1}{z}, eax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr32_2zkymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					ymm0{k1}{z}, eax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr32_2zkzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovd					eax, xmm0
	INST					zmm0{k1}{z}, eax
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_gpr64_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					ymm0, rax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr64_2zmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					zmm0, rax
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_gpr64_2kxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					xmm0{k1}, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64_2kymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					ymm0{k1}, rax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr64_2kzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					zmm0{k1}, rax
	InstLatX64_domain		zmm0, DOMAINEND
endm

InstLatX64_gpr64_2zkxmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					xmm0{k1}{z}, rax
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_gpr64_2zkymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					ymm0{k1}{z}, rax
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_gpr64_2zkzmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		zmm0, DOMAINSTART
	vmovq					rax, xmm0
	INST					zmm0{k1}{z}, rax
	InstLatX64_domain		zmm0, DOMAINEND
endm
