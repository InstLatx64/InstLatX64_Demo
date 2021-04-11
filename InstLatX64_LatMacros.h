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
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m64_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, qword ptr [memop0 + 00h]
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m32_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, dword ptr [memop0 + 00h]
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m16_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, word ptr [memop0 + 00h]
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m8_2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, byte ptr [memop0 + 00h]
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmm0
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_xmmymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmm0, 1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_m128ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, xmmword ptr [memop0], 1
	InstLatX64_domain		ymm0, DOMAINEND
endm

InstLatX64_ymmi2m128_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmmword ptr [memop0 + 00h], ymm0, 1
	InstLatX64_domain		xmm0, DOMAINEND
endm

InstLatX64_ymmi2xmm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		xmm0, DOMAINSTART
	INST					xmm0, ymm0, 0
	InstLatX64_domain		xmm0, DOMAINEND
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

InstLatX64_m256ymmi2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_domain		ymm0, DOMAINSTART
	INST					ymm0, ymm0, ymmword ptr [memop0 + 00h], 0
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