;InstLatX64 macros

InstLatX64_empty_port macro INST, DOMAINSTART, DOMAINEND
endm

InstLatX64_mm2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, mm0
	INST			mm1, mm1
	INST			mm2, mm2
	INST			mm3, mm3
	INST			mm4, mm4
	INST			mm5, mm5
	INST			mm6, mm6
	INST			mm7, mm7
endm

InstLatX64_mm2mmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, mm1
	INST			mm1, mm2
	INST			mm2, mm3
	INST			mm3, mm4
	INST			mm4, mm5
	INST			mm5, mm6
	INST			mm6, mm7
	INST			mm7, mm0
endm

InstLatX64_mmi2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, mm0, 0
	INST			mm1, mm1, 1
	INST			mm2, mm2, 2
	INST			mm3, mm3, 3
	INST			mm4, mm4, 4
	INST			mm5, mm5, 5
	INST			mm6, mm6, 6
	INST			mm7, mm7, 7
endm

InstLatX64_i2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, 0
	INST			mm1, 1
	INST			mm2, 2
	INST			mm3, 3
	INST			mm4, 4
	INST			mm5, 5
	INST			mm6, 6
	INST			mm7, 7
endm

InstLatX64_mm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm0, mm0
	INST			xmm1, mm1
	INST			xmm2, mm2
	INST			xmm3, mm3
	INST			xmm4, mm4
	INST			xmm5, mm5
	INST			xmm6, mm6
	INST			xmm7, mm7
endm

InstLatX64_xmm2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, xmm0
	INST			mm1, xmm1
	INST			mm2, xmm2
	INST			mm3, xmm3
	INST			mm4, xmm4
	INST			mm5, xmm5
	INST			mm6, xmm6
	INST			mm7, xmm7
endm

InstLatX64_mm2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST			eax, mm0
	INST			edx, mm1
	INST			ebx, mm2
	INST			eax, mm3
	INST			edx, mm4
	INST			ebx, mm5
	INST			eax, mm6
	INST			ebx, mm7
endm

InstLatX64_mmi2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST			eax, mm0, 0
	INST			edx, mm1, 1
	INST			ebx, mm2, 2
	INST			eax, mm3, 3
	INST			edx, mm4, 0
	INST			ebx, mm5, 1
	INST			eax, mm6, 2
	INST			ebx, mm7, 3
endm

InstLatX64_gpr32_2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, eax
	INST			mm1, edx
	INST			mm2, ebx
	INST			mm3, eax
	INST			mm4, edx
	INST			mm5, ebx
	INST			mm6, eax
	INST			mm7, ebx
endm

InstLatX64_gpr32i2mm_port macro INST, DOMAINSTART, DOMAINEND
	INST			mm0, eax, 0
	INST			mm1, edx, 1
	INST			mm2, ebx, 2
	INST			mm3, eax, 3
	INST			mm4, edx, 0
	INST			mm5, ebx, 1
	INST			mm6, eax, 2
	INST			mm7, ebx, 3
endm

InstLatX64_xmm2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST			eax, xmm8
	INST			edx, xmm9
	INST			ebx, xmm10
	INST			r8d, xmm11
	INST			r9d, xmm12
	INST			r10d, xmm13
	INST			r11d, xmm14
	INST			r12d, xmm15
endm

InstLatX64_xmmi2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST			eax, xmm8, 0
	INST			edx, xmm9, 1
	INST			ebx, xmm10, 0
	INST			r8d, xmm11, 1
	INST			r9d, xmm12, 0
	INST			r10d, xmm13, 1
	INST			r11d, xmm14, 0
	INST			r12d, xmm15, 1
endm

InstLatX64_xmm2gpr64_port macro INST, DOMAINSTART, DOMAINEND
	INST			rax, xmm8
	INST			rdx, xmm9
	INST			rbx, xmm10
	INST			r8, xmm11
	INST			r9, xmm12
	INST			r10, xmm13
	INST			r11, xmm14
	INST			r12, xmm15
endm

InstLatX64_xmmi2gpr64_port macro INST, DOMAINSTART, DOMAINEND
	INST			rax, xmm8, 0
	INST			rdx, xmm9, 1
	INST			rbx, xmm10, 0
	INST			r8, xmm11, 1
	INST			r9, xmm12, 0
	INST			r10, xmm13, 1
	INST			r11, xmm14, 0
	INST			r12, xmm15, 1
endm

InstLatX64_ymm2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST			eax, ymm8
	INST			edx, ymm9
	INST			ebx, ymm10
	INST			r8d, ymm11
	INST			r9d, ymm12
	INST			r10d, ymm13
	INST			r11d, ymm14
	INST			r12d, ymm15
endm

InstLatX64_ymm2gpr64_port macro INST, DOMAINSTART, DOMAINEND
	INST			rax, ymm8
	INST			rdx, ymm9
	INST			rbx, ymm10
	INST			r8, ymm11
	INST			r9, ymm12
	INST			r10, ymm13
	INST			r11, ymm14
	INST			r12, ymm15
endm

InstLatX64_gpr32_2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, eax
	INST			xmm9, edx
	INST			xmm10, ebx
	INST			xmm11, r8d
	INST			xmm12, r9d
	INST			xmm13, r10d
	INST			xmm14, r11d
	INST			xmm15, r12d
endm

InstLatX64_gpr64_2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, rax
	INST			xmm9, rdx
	INST			xmm10, rbx
	INST			xmm11, r8
	INST			xmm12, r9
	INST			xmm13, r10
	INST			xmm14, r11
	INST			xmm15, r12
endm

InstLatX64_gpr32i2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, eax, 0
	INST			xmm9, edx, 1
	INST			xmm10, ebx, 0
	INST			xmm11, r8d, 1
	INST			xmm12, r9d, 0
	INST			xmm13, r10d, 1
	INST			xmm14, r11d, 0
	INST			xmm15, r12d, 1
endm

InstLatX64_gpr64i2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, rax, 0
	INST			xmm9, rdx, 1
	INST			xmm10, rbx, 0
	INST			xmm11, r8, 1
	INST			xmm12, r9, 0
	INST			xmm13, r10, 1
	INST			xmm14, r11, 0
	INST			xmm15, r12, 1
endm

InstLatX64_gpr32ixmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, eax, 0
	INST			xmm9, xmm9, edx, 1
	INST			xmm10, xmm10, ebx, 0
	INST			xmm11, xmm11, r8d, 1
	INST			xmm12, xmm12, r9d, 0
	INST			xmm13, xmm13, r10d, 1
	INST			xmm14, xmm14, r11d, 0
	INST			xmm15, xmm15, r12d, 1
endm

InstLatX64_gpr64ixmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, rax, 0
	INST			xmm9, xmm9, rdx, 1
	INST			xmm10, xmm10, rbx, 0
	INST			xmm11, xmm11, r8, 1
	INST			xmm12, xmm12, r9, 0
	INST			xmm13, xmm13, r10, 1
	INST			xmm14, xmm14, r11, 0
	INST			xmm15, xmm15, r12, 1
endm

InstLatX64_gpr32xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, eax
	INST			xmm9, xmm9, edx
	INST			xmm10, xmm10, ebx
	INST			xmm11, xmm11, r8d
	INST			xmm12, xmm12, r9d
	INST			xmm13, xmm13, r10d
	INST			xmm14, xmm14, r11d
	INST			xmm15, xmm15, r12d
endm

InstLatX64_gpr64xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, rax
	INST			xmm9, xmm9, rdx
	INST			xmm10, xmm10, rbx
	INST			xmm11, xmm11, r8
	INST			xmm12, xmm12, r9
	INST			xmm13, xmm13, r10
	INST			xmm14, xmm14, r11
	INST			xmm15, xmm15, r12
endm

InstLatX64_xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8
	INST			xmm9, xmm9
	INST			xmm10, xmm10
	INST			xmm11, xmm11
	INST			xmm12, xmm12
	INST			xmm13, xmm13
	INST			xmm14, xmm14
	INST			xmm15, xmm15
endm

InstLatX64_xmm2xmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm14, xmm15
	INST			xmm15, xmm8
	INST			xmm8, xmm9
	INST			xmm9, xmm10
	INST			xmm10, xmm11
	INST			xmm11, xmm12
	INST			xmm12, xmm13
	INST			xmm13, xmm14
endm

InstLatX64_ymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8
	INST			ymm9, ymm9
	INST			ymm10, ymm10
	INST			ymm11, ymm11
	INST			ymm12, ymm12
	INST			ymm13, ymm13
	INST			ymm14, ymm14
	INST			ymm15, ymm15
endm

InstLatX64_xmm2xmm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm14, xmm15
endm

InstLatX64_xmm2xmm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm13, xmm15
	INST			xmm14, xmm15
endm

InstLatX64_ymm2ymm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm14, ymm15
endm

InstLatX64_xmmi2xmm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm13, xmm15, 0
	INST			xmm14, xmm15, 1
endm

InstLatX64_xmm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, xmm8
	INST			ymm9, xmm9
	INST			ymm10, xmm10
	INST			ymm11, xmm11
	INST			ymm12, xmm12
	INST			ymm13, xmm13
	INST			ymm14, xmm14
	INST			ymm15, xmm15
endm

InstLatX64_ymm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, ymm8
	INST			xmm9, ymm9
	INST			xmm10, ymm10
	INST			xmm11, ymm11
	INST			xmm12, ymm12
	INST			xmm13, ymm13
	INST			xmm14, ymm14
	INST			xmm15, ymm15
endm

InstLatX64_m128_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, xmmword ptr [memop0 + 00h]
	INST			ymm9, xmmword ptr [memop0 + 10h]
	INST			ymm10, xmmword ptr [memop0 + 20h]
	INST			ymm11, xmmword ptr [memop0 + 30h]
	INST			ymm12, xmmword ptr [memop0 + 40h]
	INST			ymm13, xmmword ptr [memop0 + 50h]
	INST			ymm14, xmmword ptr [memop0 + 60h]
	INST			ymm15, xmmword ptr [memop0 + 70h]
endm

InstLatX64_m64_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, qword ptr [memop0 + 00h]
	INST			ymm9, qword ptr [memop0 + 10h]
	INST			ymm10, qword ptr [memop0 + 20h]
	INST			ymm11, qword ptr [memop0 + 30h]
	INST			ymm12, qword ptr [memop0 + 40h]
	INST			ymm13, qword ptr [memop0 + 50h]
	INST			ymm14, qword ptr [memop0 + 60h]
	INST			ymm15, qword ptr [memop0 + 70h]
endm

InstLatX64_m32_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, dword ptr [memop0 + 00h]
	INST			ymm9, dword ptr [memop0 + 10h]
	INST			ymm10, dword ptr [memop0 + 20h]
	INST			ymm11, dword ptr [memop0 + 30h]
	INST			ymm12, dword ptr [memop0 + 40h]
	INST			ymm13, dword ptr [memop0 + 50h]
	INST			ymm14, dword ptr [memop0 + 60h]
	INST			ymm15, dword ptr [memop0 + 70h]
endm

InstLatX64_m16_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, word ptr [memop0 + 00h]
	INST			ymm9, word ptr [memop0 + 10h]
	INST			ymm10, word ptr [memop0 + 20h]
	INST			ymm11, word ptr [memop0 + 30h]
	INST			ymm12, word ptr [memop0 + 40h]
	INST			ymm13, word ptr [memop0 + 50h]
	INST			ymm14, word ptr [memop0 + 60h]
	INST			ymm15, word ptr [memop0 + 70h]
endm

InstLatX64_m8_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, byte ptr [memop0 + 00h]
	INST			ymm9, byte ptr [memop0 + 10h]
	INST			ymm10, byte ptr [memop0 + 20h]
	INST			ymm11, byte ptr [memop0 + 30h]
	INST			ymm12, byte ptr [memop0 + 40h]
	INST			ymm13, byte ptr [memop0 + 50h]
	INST			ymm14, byte ptr [memop0 + 60h]
	INST			ymm15, byte ptr [memop0 + 70h]
endm

InstLatX64_xmmymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, xmm8
	INST			ymm9, ymm9, xmm9
	INST			ymm10, ymm10, xmm10
	INST			ymm11, ymm11, xmm11
	INST			ymm12, ymm12, xmm12
	INST			ymm13, ymm13, xmm13
	INST			ymm14, ymm14, xmm14
	INST			ymm15, ymm15, xmm15
endm

InstLatX64_xmmymmi02ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, xmm8, 0
	INST			ymm9, ymm9, xmm9, 0
	INST			ymm10, ymm10, xmm10, 0
	INST			ymm11, ymm11, xmm11, 0
	INST			ymm12, ymm12, xmm12, 0
	INST			ymm13, ymm13, xmm13, 0
	INST			ymm14, ymm14, xmm14, 0
	INST			ymm15, ymm15, xmm15, 0
endm

InstLatX64_xmmymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, xmm8, 1
	INST			ymm9, ymm9, xmm9, 1
	INST			ymm10, ymm10, xmm10, 1
	INST			ymm11, ymm11, xmm11, 1
	INST			ymm12, ymm12, xmm12, 1
	INST			ymm13, ymm13, xmm13, 1
	INST			ymm14, ymm14, xmm14, 1
	INST			ymm15, ymm15, xmm15, 1
endm

InstLatX64_xmmzmmi02zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, zmm8, xmm8, 0
	INST			zmm9, zmm9, xmm9, 0
	INST			zmm10, zmm10, xmm10, 0
	INST			zmm11, zmm11, xmm11, 0
	INST			zmm12, zmm12, xmm12, 0
	INST			zmm13, zmm13, xmm13, 0
	INST			zmm14, zmm14, xmm14, 0
	INST			zmm15, zmm15, xmm15, 0
endm

InstLatX64_xmmzmmi2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, zmm8, xmm8, 1
	INST			zmm9, zmm9, xmm9, 1
	INST			zmm10, zmm10, xmm10, 1
	INST			zmm11, zmm11, xmm11, 1
	INST			zmm12, zmm12, xmm12, 1
	INST			zmm13, zmm13, xmm13, 1
	INST			zmm14, zmm14, xmm14, 1
	INST			zmm15, zmm15, xmm15, 1
endm

InstLatX64_ymmzmmi02zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, zmm8, ymm8, 0
	INST			zmm9, zmm9, ymm9, 0
	INST			zmm10, zmm10, ymm10, 0
	INST			zmm11, zmm11, ymm11, 0
	INST			zmm12, zmm12, ymm12, 0
	INST			zmm13, zmm13, ymm13, 0
	INST			zmm14, zmm14, ymm14, 0
	INST			zmm15, zmm15, ymm15, 0
endm

InstLatX64_ymmzmmi2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, zmm8, ymm8, 1
	INST			zmm9, zmm9, ymm9, 1
	INST			zmm10, zmm10, ymm10, 1
	INST			zmm11, zmm11, ymm11, 1
	INST			zmm12, zmm12, ymm12, 1
	INST			zmm13, zmm13, ymm13, 1
	INST			zmm14, zmm14, ymm14, 1
	INST			zmm15, zmm15, ymm15, 1
endm

InstLatX64_m128ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, xmmword ptr [memop0 + 00h], 1
	INST			ymm9, ymm9, xmmword ptr [memop0 + 10h], 1
	INST			ymm10, ymm10, xmmword ptr [memop0 + 20h], 1
	INST			ymm11, ymm11, xmmword ptr [memop0 + 30h], 1
	INST			ymm12, ymm12, xmmword ptr [memop0 + 40h], 1
	INST			ymm13, ymm13, xmmword ptr [memop0 + 50h], 1
	INST			ymm14, ymm14, xmmword ptr [memop0 + 60h], 1
	INST			ymm15, ymm15, xmmword ptr [memop0 + 70h], 1
endm

InstLatX64_m128ymmi02ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, xmmword ptr [memop0 + 00h], 0
	INST			ymm9, ymm9, xmmword ptr [memop0 + 10h], 0
	INST			ymm10, ymm10, xmmword ptr [memop0 + 20h], 0
	INST			ymm11, ymm11, xmmword ptr [memop0 + 30h], 0
	INST			ymm12, ymm12, xmmword ptr [memop0 + 40h], 0
	INST			ymm13, ymm13, xmmword ptr [memop0 + 50h], 0
	INST			ymm14, ymm14, xmmword ptr [memop0 + 60h], 0
	INST			ymm15, ymm15, xmmword ptr [memop0 + 70h], 0
endm

InstLatX64_m256ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymmword ptr [memop1 - 80h], 1
	INST			ymm9, ymm9, ymmword ptr [memop1 - 60h], 1
	INST			ymm10, ymm10, ymmword ptr [memop1 - 40h], 1
	INST			ymm11, ymm11, ymmword ptr [memop1 - 20h], 1
	INST			ymm12, ymm12, ymmword ptr [memop1 + 00h], 1
	INST			ymm13, ymm13, ymmword ptr [memop1 + 20h], 1
	INST			ymm14, ymm14, ymmword ptr [memop1 + 40h], 1
	INST			ymm15, ymm15, ymmword ptr [memop1 + 60h], 1
endm

InstLatX64_2xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm8
	INST			xmm9, xmm9, xmm9
	INST			xmm10, xmm10, xmm10
	INST			xmm11, xmm11, xmm11
	INST			xmm12, xmm12, xmm12
	INST			xmm13, xmm13, xmm13
	INST			xmm14, xmm14, xmm14
	INST			xmm15, xmm15, xmm15
endm

InstLatX64_2ymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymm8
	INST			ymm9, ymm9, ymm9
	INST			ymm10, ymm10, ymm10
	INST			ymm11, ymm11, ymm11
	INST			ymm12, ymm12, ymm12
	INST			ymm13, ymm13, ymm13
	INST			ymm14, ymm14, ymm14
	INST			ymm15, ymm15, ymm15
endm

InstLatX64_2xmm2xmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm14, xmm15, xmm8
	INST			xmm15, xmm8, xmm9
	INST			xmm8, xmm9, xmm10
	INST			xmm9, xmm10, xmm11
	INST			xmm10, xmm11, xmm12
	INST			xmm11, xmm12, xmm13
	INST			xmm12, xmm13, xmm14
	INST			xmm13, xmm14, xmm15
endm

InstLatX64_2ymm2ymmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm14, ymm15, ymm8
	INST			ymm15, ymm8, ymm9
	INST			ymm8, ymm9, ymm10
	INST			ymm9, ymm10, ymm11
	INST			ymm10, ymm11, ymm12
	INST			ymm11, ymm12, ymm13
	INST			ymm12, ymm13, ymm14
	INST			ymm13, ymm14, ymm15
endm

InstLatX64_2xmm2xmm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm15, xmm15, xmm15
endm

InstLatX64_2ymm2ymm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm15, ymm15, ymm15
endm

InstLatX64_2xmm2xmm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm13, xmm15, xmm15
	INST			xmm14, xmm15, xmm15
endm

InstLatX64_2ymm2ymm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm13, ymm15, ymm15
	INST			ymm14, ymm15, ymm15
endm

InstLatX64_i2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, 0
	INST			xmm9, 0
	INST			xmm10, 0
	INST			xmm11, 0
	INST			xmm12, 0
	INST			xmm13, 0
	INST			xmm14, 0
	INST			xmm15, 0
endm

InstLatX64_xmmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, 0
	INST			xmm9, xmm9, 0
	INST			xmm10, xmm10, 0
	INST			xmm11, xmm11, 0
	INST			xmm12, xmm12, 0
	INST			xmm13, xmm13, 0
	INST			xmm14, xmm14, 0
	INST			xmm15, xmm15, 0
endm

InstLatX64_xmmi2xmm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm14, xmm15, 0
endm

InstLatX64_xmmi2xmm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm13, xmm15, 0
	INST			xmm14, xmm15, 1
endm

InstLatX64_xmmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, xmm8, 0
	INST			ymm9, xmm9, 0
	INST			ymm10, xmm10, 0
	INST			ymm11, xmm11, 0
	INST			ymm12, xmm12, 0
	INST			ymm13, xmm13, 0
	INST			ymm14, xmm14, 0
	INST			ymm15, xmm15, 0
endm

InstLatX64_ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, 0
	INST			ymm9, ymm9, 0
	INST			ymm10, ymm10, 0
	INST			ymm11, ymm11, 0
	INST			ymm12, ymm12, 0
	INST			ymm13, ymm13, 0
	INST			ymm14, ymm14, 0
	INST			ymm15, ymm15, 0
endm

InstLatX64_ymmi02xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, ymm8, 0
	INST			xmm9, ymm9, 0
	INST			xmm10, ymm10, 0
	INST			xmm11, ymm11, 0
	INST			xmm12, ymm12, 0
	INST			xmm13, ymm13, 0
	INST			xmm14, ymm14, 0
	INST			xmm15, ymm15, 0
endm

InstLatX64_ymmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, ymm8, 1
	INST			xmm9, ymm9, 1
	INST			xmm10, ymm10, 1
	INST			xmm11, ymm11, 1
	INST			xmm12, ymm12, 1
	INST			xmm13, ymm13, 1
	INST			xmm14, ymm14, 1
	INST			xmm15, ymm15, 1
endm

InstLatX64_zmmi02xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, zmm8, 0
	INST			xmm9, zmm9, 0
	INST			xmm10, zmm10, 0
	INST			xmm11, zmm11, 0
	INST			xmm12, zmm12, 0
	INST			xmm13, zmm13, 0
	INST			xmm14, zmm14, 0
	INST			xmm15, zmm15, 0
endm

InstLatX64_zmmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, zmm8, 1
	INST			xmm9, zmm9, 1
	INST			xmm10, zmm10, 1
	INST			xmm11, zmm11, 1
	INST			xmm12, zmm12, 1
	INST			xmm13, zmm13, 1
	INST			xmm14, zmm14, 1
	INST			xmm15, zmm15, 1
endm

InstLatX64_zmmi02ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, zmm8, 0
	INST			ymm9, zmm9, 0
	INST			ymm10, zmm10, 0
	INST			ymm11, zmm11, 0
	INST			ymm12, zmm12, 0
	INST			ymm13, zmm13, 0
	INST			ymm14, zmm14, 0
	INST			ymm15, zmm15, 0
endm

InstLatX64_zmmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, zmm8, 1
	INST			ymm9, zmm9, 1
	INST			ymm10, zmm10, 1
	INST			ymm11, zmm11, 1
	INST			ymm12, zmm12, 1
	INST			ymm13, zmm13, 1
	INST			ymm14, zmm14, 1
	INST			ymm15, zmm15, 1
endm

InstLatX64_ymmi02m128_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmmword ptr [memop0 + 00h], ymm8, 0
	INST			xmmword ptr [memop0 + 00h], ymm9, 0
	INST			xmmword ptr [memop0 + 00h], ymm10, 0
	INST			xmmword ptr [memop0 + 00h], ymm11, 0
	INST			xmmword ptr [memop0 + 00h], ymm12, 0
	INST			xmmword ptr [memop0 + 00h], ymm13, 0
	INST			xmmword ptr [memop0 + 00h], ymm14, 0
	INST			xmmword ptr [memop0 + 00h], ymm15, 0
endm

InstLatX64_ymmi2m128_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmmword ptr [memop0 + 00h], ymm8, 1
	INST			xmmword ptr [memop0 + 00h], ymm9, 1
	INST			xmmword ptr [memop0 + 00h], ymm10, 1
	INST			xmmword ptr [memop0 + 00h], ymm11, 1
	INST			xmmword ptr [memop0 + 00h], ymm12, 1
	INST			xmmword ptr [memop0 + 00h], ymm13, 1
	INST			xmmword ptr [memop0 + 00h], ymm14, 1
	INST			xmmword ptr [memop0 + 00h], ymm15, 1
endm

InstLatX64_ymmi02km128_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm8, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm9, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm10, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm11, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm12, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm13, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm14, 0
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm15, 0
endm

InstLatX64_ymmi2km128_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm8, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm9, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm10, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm11, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm12, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm13, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm14, 1
	INST			xmmword ptr [memop0 + 00h]{k1}, ymm15, 1
endm

InstLatX64_2xmmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm8, 0
	INST			xmm9, xmm9, xmm9, 0
	INST			xmm10, xmm10, xmm10, 0
	INST			xmm11, xmm11, xmm11, 0
	INST			xmm12, xmm12, xmm12, 0
	INST			xmm13, xmm13, xmm13, 0
	INST			xmm14, xmm14, xmm14, 0
	INST			xmm15, xmm15, xmm15, 0
endm

InstLatX64_2xmmi2kxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}, xmm8, xmm8, 0
	INST			xmm9{k1}, xmm9, xmm9, 0
	INST			xmm10{k2}, xmm10, xmm10, 0
	INST			xmm11{k3}, xmm11, xmm11, 0
	INST			xmm12{k4}, xmm12, xmm12, 0
	INST			xmm13{k5}, xmm13, xmm13, 0
	INST			xmm14{k6}, xmm14, xmm14, 0
	INST			xmm15{k7}, xmm15, xmm15, 0
endm

InstLatX64_2xmmi2zkxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}{z}, xmm8, xmm8, 0
	INST			xmm9{k1}{z}, xmm9, xmm9, 0
	INST			xmm10{k2}{z}, xmm10, xmm10, 0
	INST			xmm11{k3}{z}, xmm11, xmm11, 0
	INST			xmm12{k4}{z}, xmm12, xmm12, 0
	INST			xmm13{k5}{z}, xmm13, xmm13, 0
	INST			xmm14{k6}{z}, xmm14, xmm14, 0
	INST			xmm15{k7}{z}, xmm15, xmm15, 0
endm

InstLatX64_2xmmi2xmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0, xmm1, xmm2, 0
	INST				xmm1, xmm2, xmm3, 1
	INST				xmm2, xmm3, xmm4, 2
	INST				xmm3, xmm4, xmm5, 3
	INST				xmm4, xmm5, xmm6, 4
	INST				xmm5, xmm6, xmm7, 5
	INST				xmm6, xmm7, xmm0, 6
	INST				xmm7, xmm0, xmm1, 7
	;INST				xmm0, xmm0, xmm2, 0
	;INST				xmm1, xmm1, xmm3, 1
	;INST				xmm2, xmm2, xmm4, 2
	;INST				xmm3, xmm3, xmm5, 3
	;INST				xmm4, xmm4, xmm6, 4
	;INST				xmm5, xmm5, xmm7, 5
	;INST				xmm6, xmm6, xmm0, 6
	;INST				xmm7, xmm7, xmm1, 7
endm

InstLatX64_2xmmi2kxmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k1}, xmm1, xmm2, 0
	INST				xmm1{k1}, xmm2, xmm3, 1
	INST				xmm2{k2}, xmm3, xmm4, 2
	INST				xmm3{k3}, xmm4, xmm5, 3
	INST				xmm4{k4}, xmm5, xmm6, 4
	INST				xmm5{k5}, xmm6, xmm7, 5
	INST				xmm6{k6}, xmm7, xmm0, 6
	INST				xmm7{k7}, xmm0, xmm1, 7

	;INST				xmm0{k1}, xmm1, xmm2, 0
	;INST				xmm1{k1}, xmm2, xmm3, 1
	;INST				xmm2{k2}, xmm3, xmm4, 2
	;INST				xmm3{k3}, xmm4, xmm5, 3
	;INST				xmm4{k4}, xmm5, xmm6, 4
	;INST				xmm5{k5}, xmm6, xmm7, 5
	;INST				xmm6{k6}, xmm7, xmm0, 6
	;INST				xmm7{k7}, xmm0, xmm1, 7
endm

InstLatX64_2xmmi2zkxmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k0}{z}, xmm1, xmm2, 0
	INST				xmm1{k1}{z}, xmm2, xmm3, 1
	INST				xmm2{k2}{z}, xmm3, xmm4, 2
	INST				xmm3{k3}{z}, xmm4, xmm5, 3
	INST				xmm4{k4}{z}, xmm5, xmm6, 4
	INST				xmm5{k5}{z}, xmm6, xmm7, 5
	INST				xmm6{k6}{z}, xmm7, xmm0, 6
	INST				xmm7{k7}{z}, xmm0, xmm1, 7

	;INST				xmm0{k1}{z}, xmm0, xmm2, 0
	;INST				xmm1{k1}{z}, xmm1, xmm3, 1
	;INST				xmm2{k2}{z}, xmm2, xmm4, 2
	;INST				xmm3{k3}{z}, xmm3, xmm5, 3
	;INST				xmm4{k4}{z}, xmm4, xmm6, 4
	;INST				xmm5{k5}{z}, xmm5, xmm7, 5
	;INST				xmm6{k6}{z}, xmm6, xmm0, 6
	;INST				xmm7{k7}{z}, xmm7, xmm0, 6
endm

InstLatX64_2ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymm8, 0
	INST			ymm9, ymm9, ymm9, 0
	INST			ymm10, ymm10, ymm10, 0
	INST			ymm11, ymm11, ymm11, 0
	INST			ymm12, ymm12, ymm12, 0
	INST			ymm13, ymm13, ymm13, 0
	INST			ymm14, ymm14, ymm14, 0
	INST			ymm15, ymm15, ymm15, 0
endm

InstLatX64_2ymmi102ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymm8, 030h
	INST			ymm9, ymm9, ymm9, 030h
	INST			ymm10, ymm10, ymm10, 030h
	INST			ymm11, ymm11, ymm11, 030h
	INST			ymm12, ymm12, ymm12, 030h
	INST			ymm13, ymm13, ymm13, 030h
	INST			ymm14, ymm14, ymm14, 030h
	INST			ymm15, ymm15, ymm15, 030h
endm

InstLatX64_2ymmi2kymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}, ymm8, ymm8, 0
	INST			ymm9{k1}, ymm9, ymm9, 0
	INST			ymm10{k2}, ymm10, ymm10, 0
	INST			ymm11{k3}, ymm11, ymm11, 0
	INST			ymm12{k4}, ymm12, ymm12, 0
	INST			ymm13{k5}, ymm13, ymm13, 0
	INST			ymm14{k6}, ymm14, ymm14, 0
	INST			ymm15{k7}, ymm15, ymm15, 0
endm

InstLatX64_2ymmi2zkymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}{z}, ymm8, ymm8, 0
	INST			ymm9{k1}{z}, ymm9, ymm9, 0
	INST			ymm10{k2}{z}, ymm10, ymm10, 0
	INST			ymm11{k3}{z}, ymm11, ymm11, 0
	INST			ymm12{k4}{z}, ymm12, ymm12, 0
	INST			ymm13{k5}{z}, ymm13, ymm13, 0
	INST			ymm14{k6}{z}, ymm14, ymm14, 0
	INST			ymm15{k7}{z}, ymm15, ymm15, 0
endm

InstLatX64_2ymmi2ymmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0, ymm1, ymm2, 0
	INST				ymm1, ymm2, ymm3, 1
	INST				ymm2, ymm3, ymm4, 2
	INST				ymm3, ymm4, ymm5, 3
	INST				ymm4, ymm5, ymm6, 4
	INST				ymm5, ymm6, ymm7, 5
	INST				ymm6, ymm7, ymm0, 6
	INST				ymm7, ymm0, ymm1, 7
	;INST				ymm0, ymm0, ymm9, 0
	;INST				ymm1, ymm1, ymm9, 1
	;INST				ymm2, ymm2, ymm9, 2
	;INST				ymm3, ymm3, ymm9, 3
	;INST				ymm4, ymm4, ymm9, 4
	;INST				ymm5, ymm5, ymm9, 5
	;INST				ymm6, ymm6, ymm9, 6
	;INST				ymm7, ymm7, ymm9, 7
endm

InstLatX64_2ymmi2kymmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}, ymm1, ymm2, 0
	INST				ymm1{k1}, ymm2, ymm3, 1
	INST				ymm2{k2}, ymm3, ymm4, 2
	INST				ymm3{k3}, ymm4, ymm5, 3
	INST				ymm4{k4}, ymm5, ymm6, 4
	INST				ymm5{k5}, ymm6, ymm7, 5
	INST				ymm6{k6}, ymm7, ymm0, 6
	INST				ymm7{k7}, ymm0, ymm1, 7

	;INST				ymm0{k1}, ymm0, ymm9, 0
	;INST				ymm1{k1}, ymm1, ymm9, 1
	;INST				ymm2{k2}, ymm2, ymm9, 2
	;INST				ymm3{k3}, ymm3, ymm9, 3
	;INST				ymm4{k4}, ymm4, ymm9, 4
	;INST				ymm5{k5}, ymm5, ymm9, 5
	;INST				ymm6{k6}, ymm6, ymm9, 6
	;INST				ymm7{k7}, ymm7, ymm9, 7
endm

InstLatX64_2ymmi2zkymmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}{z}, ymm1, ymm2, 0
	INST				ymm1{k1}{z}, ymm2, ymm3, 1
	INST				ymm2{k2}{z}, ymm3, ymm4, 2
	INST				ymm3{k3}{z}, ymm4, ymm5, 3
	INST				ymm4{k4}{z}, ymm5, ymm6, 4
	INST				ymm5{k5}{z}, ymm6, ymm7, 5
	INST				ymm6{k6}{z}, ymm7, ymm0, 6
	INST				ymm7{k7}{z}, ymm0, ymm1, 7

	;INST				ymm0{k1}{z}, ymm0, ymm9, 0
	;INST				ymm1{k1}{z}, ymm1, ymm9, 1
	;INST				ymm2{k2}{z}, ymm2, ymm9, 2
	;INST				ymm3{k3}{z}, ymm3, ymm9, 3
	;INST				ymm4{k4}{z}, ymm4, ymm9, 4
	;INST				ymm5{k5}{z}, ymm5, ymm9, 5
	;INST				ymm6{k6}{z}, ymm6, ymm9, 6
	;INST				ymm7{k7}{z}, ymm7, ymm9, 7
endm

InstLatX64_3xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm8, xmm8
	INST			xmm9, xmm9, xmm9, xmm9
	INST			xmm10, xmm10, xmm10, xmm10
	INST			xmm11, xmm11, xmm11, xmm11
	INST			xmm12, xmm12, xmm12, xmm12
	INST			xmm13, xmm13, xmm13, xmm13
	INST			xmm14, xmm14, xmm14, xmm14
	INST			xmm15, xmm15, xmm15, xmm15
endm

InstLatX64_3xmm2xmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm14, xmm15, xmm8, xmm9
	INST			xmm15, xmm8, xmm9, xmm10
	INST			xmm8, xmm9, xmm10, xmm11
	INST			xmm9, xmm10, xmm11, xmm12
	INST			xmm10, xmm11, xmm12, xmm13
	INST			xmm11, xmm12, xmm13, xmm14
	INST			xmm12, xmm13, xmm14, xmm15
	INST			xmm13, xmm14, xmm15, xmm8
endm

InstLatX64_3ymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymm8, ymm8
	INST			ymm9, ymm9, ymm9, ymm9
	INST			ymm10, ymm10, ymm10, ymm10
	INST			ymm11, ymm11, ymm11, ymm11
	INST			ymm12, ymm12, ymm12, ymm12
	INST			ymm13, ymm13, ymm13, ymm13
	INST			ymm14, ymm14, ymm14, ymm14
	INST			ymm15, ymm15, ymm15, ymm15
endm

InstLatX64_3ymm2ymmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm14, ymm15, ymm8, ymm9
	INST			ymm15, ymm8, ymm9, ymm10
	INST			ymm8, ymm9, ymm10, ymm11
	INST			ymm9, ymm10, ymm11, ymm12
	INST			ymm10, ymm11, ymm12, ymm13
	INST			ymm11, ymm12, ymm13, ymm14
	INST			ymm12, ymm13, ymm14, ymm15
	INST			ymm13, ymm14, ymm15, ymm8
endm

InstLatX64_xmm0_2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm0
	INST			xmm9, xmm9, xmm0
	INST			xmm10, xmm10, xmm0
	INST			xmm11, xmm11, xmm0
	INST			xmm12, xmm12, xmm0
	INST			xmm13, xmm13, xmm0
	INST			xmm14, xmm14, xmm0
	INST			xmm15, xmm15, xmm0
endm

InstLatX64_xmm0_2xmm1_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm0
endm

InstLatX64_xmm0_2xmm2_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, xmm0
	INST			xmm9, xmm9, xmm0
endm

InstLatX64_ii2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, 0, 0
	INST			xmm9, 0, 0
	INST			xmm10, 0, 0
	INST			xmm11, 0, 0
	INST			xmm12, 0, 0
	INST			xmm13, 0, 0
	INST			xmm14, 0, 0
	INST			xmm15, 0, 0
endm

InstLatX64_xmmii2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, xmm8, 0, 0
	INST			xmm9, xmm9, 0, 0
	INST			xmm10, xmm10, 0, 0
	INST			xmm11, xmm11, 0, 0
	INST			xmm12, xmm12, 0, 0
	INST			xmm13, xmm13, 0, 0
	INST			xmm14, xmm14, 0, 0
	INST			xmm15, xmm15, 0, 0
endm

InstLatX64_xmm2F_port macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_xmm2xmm_port INST
endm

InstLatX64_ymm2F_port macro INST, DOMAINSTART, DOMAINEND
	InstLatX64_ymm2ymm_port INST
endm

InstLatX64_noop_port macro INST, DOMAINSTART, DOMAINEND
	INST
	INST
	INST
	INST
	INST
	INST
	INST
	INST
endm

InstLatX64_noop1_port macro INST, DOMAINSTART, DOMAINEND
	fincstp
	INST
	fdecstp
endm

InstLatX64_x87_1op_port macro INST, DOMAINSTART, DOMAINEND
	INST			st(7)
	INST			st(6)
	INST			st(5)
	INST			st(4)
	INST			st(3)
	INST			st(2)
	INST			st(1)
	INST			st(0) 
endm

InstLatX64_x87_2op_port macro INST, DOMAINSTART, DOMAINEND
	INST			st(7), st(0)
	INST			st(6), st(0)
	INST			st(5), st(0)
	INST			st(4), st(0)
	INST			st(3), st(0)
	INST			st(2), st(0)
	INST			st(1), st(0) 
endm

InstLatX64_x87_2opR_port macro INST, DOMAINSTART, DOMAINEND
	INST			st(0), st(7)
	INST			st(0), st(6)
	INST			st(0), st(5)
	INST			st(0), st(4)
	INST			st(0), st(3)
	INST			st(0), st(2)
	INST			st(0), st(1) 
endm

InstLatX64_x87_2op1_port macro INST, DOMAINSTART, DOMAINEND
	INST st(0), st(0)
endm

InstLatX64_x87_fstp_port macro INST, DOMAINSTART, DOMAINEND
	INST
	fstp			st(0)
	INST			
	fstp			st(0)
	INST			
	fstp			st(0)
	INST			
	fstp			st(0)
endm

InstLatX64_x87_1op_fstp_port macro INST, DOMAINSTART, DOMAINEND
	INST			st(0)
	fstp			st(0)
	INST			st(0)
	fstp			st(0)
	INST			st(0)
	fstp			st(0)
	INST			st(0)
	fstp			st(0)
endm

InstLatX64_x87_m32l_port macro INST, DOMAINSTART, DOMAINEND
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
endm

InstLatX64_x87_m64l_port macro INST, DOMAINSTART, DOMAINEND
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
endm

InstLatX64_x87_m80l_port macro INST, DOMAINSTART, DOMAINEND
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
	fstp	st(0)
endm

InstLatX64_x87_m32s_port macro INST, DOMAINSTART, DOMAINEND
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
	INST	dword ptr [memop0]
endm

InstLatX64_x87_m64s_port macro INST, DOMAINSTART, DOMAINEND
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
	INST	qword ptr [memop0]
endm

InstLatX64_x87_m80s_port macro INST, DOMAINSTART, DOMAINEND
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	fld1
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
	INST	tbyte ptr [memop0]
endm

InstLatX64_evex_xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, xmm0
	evex INST			xmm1, xmm1
	evex INST			xmm2, xmm2
	evex INST			xmm3, xmm3
	evex INST			xmm4, xmm4
	evex INST			xmm5, xmm5
	evex INST			xmm6, xmm6
	evex INST			xmm7, xmm7
endm

InstLatX64_evex_xmm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm0, xmm0
	evex INST			ymm1, xmm1
	evex INST			ymm2, xmm2
	evex INST			ymm3, xmm3
	evex INST			ymm4, xmm4
	evex INST			ymm5, xmm5
	evex INST			ymm6, xmm6
	evex INST			ymm7, xmm7
endm

InstLatX64_evex_ymm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, ymm0
	evex INST			xmm1, ymm1
	evex INST			xmm2, ymm2
	evex INST			xmm3, ymm3
	evex INST			xmm4, ymm4
	evex INST			xmm5, ymm5
	evex INST			xmm6, ymm6
	evex INST			xmm7, ymm7
endm

InstLatX64_evex_ymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm0, ymm0
	evex INST			ymm1, ymm1
	evex INST			ymm2, ymm2
	evex INST			ymm3, ymm3
	evex INST			ymm4, ymm4
	evex INST			ymm5, ymm5
	evex INST			ymm6, ymm6
	evex INST			ymm7, ymm7
endm

InstLatX64_xmm2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, xmm0
	INST				zmm1, xmm1
	INST				zmm2, xmm2
	INST				zmm3, xmm3
	INST				zmm4, xmm4
	INST				zmm5, xmm5
	INST				zmm6, xmm6
	INST				zmm7, xmm7
endm

InstLatX64_ymm2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, ymm0
	INST				zmm1, ymm1
	INST				zmm2, ymm2
	INST				zmm3, ymm3
	INST				zmm4, ymm4
	INST				zmm5, ymm5
	INST				zmm6, ymm6
	INST				zmm7, ymm7
endm

InstLatX64_zmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0, zmm0
	INST				xmm1, zmm1
	INST				xmm2, zmm2
	INST				xmm3, zmm3
	INST				xmm4, zmm4
	INST				xmm5, zmm5
	INST				xmm6, zmm6
	INST				xmm7, zmm7
endm

InstLatX64_zmm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0, zmm0
	INST				ymm1, zmm1
	INST				ymm2, zmm2
	INST				ymm3, zmm3
	INST				ymm4, zmm4
	INST				ymm5, zmm5
	INST				ymm6, zmm6
	INST				ymm7, zmm7
endm

InstLatX64_zmm2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, zmm0
	INST				zmm1, zmm1
	INST				zmm2, zmm2
	INST				zmm3, zmm3
	INST				zmm4, zmm4
	INST				zmm5, zmm5
	INST				zmm6, zmm6
	INST				zmm7, zmm7
endm

InstLatX64_xmm2m128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 00h], xmm0
	INST				xmmword ptr [memop0 + 10h], xmm1
	INST				xmmword ptr [memop0 + 20h], xmm2
	INST				xmmword ptr [memop0 + 30h], xmm3
	INST				xmmword ptr [memop0 + 40h], xmm4
	INST				xmmword ptr [memop0 + 50h], xmm5
	INST				xmmword ptr [memop0 + 60h], xmm6
	INST				xmmword ptr [memop0 + 70h], xmm7
endm

InstLatX64_xmm2km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 00h]{k1}, xmm0
	INST				xmmword ptr [memop0 + 10h]{k1}, xmm1
	INST				xmmword ptr [memop0 + 20h]{k1}, xmm2
	INST				xmmword ptr [memop0 + 30h]{k1}, xmm3
	INST				xmmword ptr [memop0 + 40h]{k1}, xmm4
	INST				xmmword ptr [memop0 + 50h]{k1}, xmm5
	INST				xmmword ptr [memop0 + 60h]{k1}, xmm6
	INST				xmmword ptr [memop0 + 70h]{k1}, xmm7
endm

InstLatX64_xmm2zkm128_port macro INST, DOMAINSTART, DOMAINEND
	;evex INST				xmmword ptr [memop0 + 00h]{k1}{z}, xmm0
	;evex INST				xmmword ptr [memop0 + 10h]{k1}{z}, xmm1
	;evex INST				xmmword ptr [memop0 + 20h]{k1}{z}, xmm2
	;evex INST				xmmword ptr [memop0 + 30h]{k1}{z}, xmm3
	;evex INST				xmmword ptr [memop0 + 40h]{k1}{z}, xmm4
	;evex INST				xmmword ptr [memop0 + 50h]{k1}{z}, xmm5
	;evex INST				xmmword ptr [memop0 + 60h]{k1}{z}, xmm6
	;evex INST				xmmword ptr [memop0 + 70h]{k1}{z}, xmm7
endm

InstLatX64_evex_xmm2m128_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmmword ptr [memop0 + 00h], xmm0
	evex INST			xmmword ptr [memop0 + 10h], xmm1
	evex INST			xmmword ptr [memop0 + 20h], xmm2
	evex INST			xmmword ptr [memop0 + 30h], xmm3
	evex INST			xmmword ptr [memop0 + 40h], xmm4
	evex INST			xmmword ptr [memop0 + 50h], xmm5
	evex INST			xmmword ptr [memop0 + 60h], xmm6
	evex INST			xmmword ptr [memop0 + 70h], xmm7
endm

;InstLatX64_xmm2m64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 00h], xmm0
;	INST				qword ptr [memop0 + 08h], xmm1
;	INST				qword ptr [memop0 + 10h], xmm2
;	INST				qword ptr [memop0 + 18h], xmm3
;	INST				qword ptr [memop0 + 20h], xmm4
;	INST				qword ptr [memop0 + 28h], xmm5
;	INST				qword ptr [memop0 + 30h], xmm6
;	INST				qword ptr [memop0 + 38h], xmm7
;endm
;
;InstLatX64_xmm2m32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 00h], xmm0
;	INST				dword ptr [memop0 + 08h], xmm1
;	INST				dword ptr [memop0 + 10h], xmm2
;	INST				dword ptr [memop0 + 18h], xmm3
;	INST				dword ptr [memop0 + 40h], xmm4
;	INST				dword ptr [memop0 + 50h], xmm5
;	INST				dword ptr [memop0 + 60h], xmm6
;	INST				dword ptr [memop0 + 70h], xmm7
;endm
;
;InstLatX64_xmm2m16_port macro INST, DOMAINSTART, DOMAINEND
;	INST				word ptr [memop0 + 00h], xmm0
;	INST				word ptr [memop0 + 10h], xmm1
;	INST				word ptr [memop0 + 20h], xmm2
;	INST				word ptr [memop0 + 30h], xmm3
;	INST				word ptr [memop0 + 40h], xmm4
;	INST				word ptr [memop0 + 50h], xmm5
;	INST				word ptr [memop0 + 60h], xmm6
;	INST				word ptr [memop0 + 70h], xmm7
;endm
;
;InstLatX64_xmm2km64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 00h]{k1}, xmm0
;	INST				qword ptr [memop0 + 08h]{k1}, xmm1
;	INST				qword ptr [memop0 + 10h]{k1}, xmm2
;	INST				qword ptr [memop0 + 18h]{k1}, xmm3
;	INST				qword ptr [memop0 + 20h]{k1}, xmm4
;	INST				qword ptr [memop0 + 28h]{k1}, xmm5
;	INST				qword ptr [memop0 + 30h]{k1}, xmm6
;	INST				qword ptr [memop0 + 38h]{k1}, xmm7
;endm
;
;InstLatX64_xmm2km32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 00h]{k1}, xmm0
;	INST				dword ptr [memop0 + 08h]{k1}, xmm1
;	INST				dword ptr [memop0 + 10h]{k1}, xmm2
;	INST				dword ptr [memop0 + 18h]{k1}, xmm3
;	INST				dword ptr [memop0 + 40h]{k1}, xmm4
;	INST				dword ptr [memop0 + 50h]{k1}, xmm5
;	INST				dword ptr [memop0 + 60h]{k1}, xmm6
;	INST				dword ptr [memop0 + 70h]{k1}, xmm7
;endm
;
;InstLatX64_xmm2km16_port macro INST, DOMAINSTART, DOMAINEND
;	INST				word ptr [memop0 + 00h]{k1}, xmm0
;	INST				word ptr [memop0 + 10h]{k1}, xmm1
;	INST				word ptr [memop0 + 20h]{k1}, xmm2
;	INST				word ptr [memop0 + 30h]{k1}, xmm3
;	INST				word ptr [memop0 + 40h]{k1}, xmm4
;	INST				word ptr [memop0 + 50h]{k1}, xmm5
;	INST				word ptr [memop0 + 60h]{k1}, xmm6
;	INST				word ptr [memop0 + 70h]{k1}, xmm7
;endm
;
;InstLatX64_xmm2zkm64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 00h]{k1}{z}, xmm0
;	INST				qword ptr [memop0 + 08h]{k1}{z}, xmm1
;	INST				qword ptr [memop0 + 10h]{k1}{z}, xmm2
;	INST				qword ptr [memop0 + 18h]{k1}{z}, xmm3
;	INST				qword ptr [memop0 + 20h]{k1}{z}, xmm4
;	INST				qword ptr [memop0 + 28h]{k1}{z}, xmm5
;	INST				qword ptr [memop0 + 30h]{k1}{z}, xmm6
;	INST				qword ptr [memop0 + 38h]{k1}{z}, xmm7
;endm
;
;InstLatX64_xmm2zkm32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 00h]{k1}{z}, xmm0
;	INST				dword ptr [memop0 + 08h]{k1}{z}, xmm1
;	INST				dword ptr [memop0 + 10h]{k1}{z}, xmm2
;	INST				dword ptr [memop0 + 18h]{k1}{z}, xmm3
;	INST				dword ptr [memop0 + 40h]{k1}{z}, xmm4
;	INST				dword ptr [memop0 + 50h]{k1}{z}, xmm5
;	INST				dword ptr [memop0 + 60h]{k1}{z}, xmm6
;	INST				dword ptr [memop0 + 70h]{k1}{z}, xmm7
;endm
;
;InstLatX64_xmm2zkm16_port macro INST, DOMAINSTART, DOMAINEND
;	INST				word ptr [memop0 + 00h]{k1}{z}, xmm0
;	INST				word ptr [memop0 + 10h]{k1}{z}, xmm1
;	INST				word ptr [memop0 + 20h]{k1}{z}, xmm2
;	INST				word ptr [memop0 + 30h]{k1}{z}, xmm3
;	INST				word ptr [memop0 + 40h]{k1}{z}, xmm4
;	INST				word ptr [memop0 + 50h]{k1}{z}, xmm5
;	INST				word ptr [memop0 + 60h]{k1}{z}, xmm6
;	INST				word ptr [memop0 + 70h]{k1}{z}, xmm7
;endm

InstLatX64_ymm2m256_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymmword ptr [memop0 + 000h], ymm0
	INST				ymmword ptr [memop0 + 020h], ymm1
	INST				ymmword ptr [memop0 + 040h], ymm2
	INST				ymmword ptr [memop0 + 060h], ymm3
	INST				ymmword ptr [memop0 + 080h], ymm4
	INST				ymmword ptr [memop0 + 0A0h], ymm5
	INST				ymmword ptr [memop0 + 0C0h], ymm6
	INST				ymmword ptr [memop0 + 0E0h], ymm7
endm

;InstLatX64_ymm2km256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h]{k1}, ymm0
;	INST				ymmword ptr [memop0 + 020h]{k1}, ymm1
;	INST				ymmword ptr [memop0 + 040h]{k1}, ymm2
;	INST				ymmword ptr [memop0 + 060h]{k1}, ymm3
;	INST				ymmword ptr [memop0 + 080h]{k1}, ymm4
;	INST				ymmword ptr [memop0 + 0A0h]{k1}, ymm5
;	INST				ymmword ptr [memop0 + 0C0h]{k1}, ymm6
;	INST				ymmword ptr [memop0 + 0E0h]{k1}, ymm7
;endm
;
;InstLatX64_ymm2zkm256_port macro INST, DOMAINSTART, DOMAINEND
;	;INST				ymmword ptr [memop0 + 000h]{k1}{z}, ymm0
;	;INST				ymmword ptr [memop0 + 020h]{k1}{z}, ymm1
;	;INST				ymmword ptr [memop0 + 040h]{k1}{z}, ymm2
;	;INST				ymmword ptr [memop0 + 060h]{k1}{z}, ymm3
;	;INST				ymmword ptr [memop0 + 080h]{k1}{z}, ymm4
;	;INST				ymmword ptr [memop0 + 0A0h]{k1}{z}, ymm5
;	;INST				ymmword ptr [memop0 + 0C0h]{k1}{z}, ymm6
;	;INST				ymmword ptr [memop0 + 0E0h]{k1}{z}, ymm7
;endm

;InstLatX64_evex_ymm2m256_port macro INST, DOMAINSTART, DOMAINEND
;	evex INST			ymmword ptr [memop0 + 000h], ymm0
;	evex INST			ymmword ptr [memop0 + 020h], ymm1
;	evex INST			ymmword ptr [memop0 + 040h], ymm2
;	evex INST			ymmword ptr [memop0 + 060h], ymm3
;	evex INST			ymmword ptr [memop0 + 080h], ymm4
;	evex INST			ymmword ptr [memop0 + 0A0h], ymm5
;	evex INST			ymmword ptr [memop0 + 0C0h], ymm6
;	evex INST			ymmword ptr [memop0 + 0E0h], ymm7
;endm
;
;InstLatX64_ymm2m128_port macro INST, DOMAINSTART, DOMAINEND
;	INST				xmmword ptr [memop0 + 000h], ymm0
;	INST				xmmword ptr [memop0 + 010h], ymm1
;	INST				xmmword ptr [memop0 + 020h], ymm2
;	INST				xmmword ptr [memop0 + 030h], ymm3
;	INST				xmmword ptr [memop0 + 040h], ymm4
;	INST				xmmword ptr [memop0 + 050h], ymm5
;	INST				xmmword ptr [memop0 + 060h], ymm6
;	INST				xmmword ptr [memop0 + 070h], ymm7
;endm
;
;InstLatX64_ymm2m64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 000h], ymm0
;	INST				qword ptr [memop0 + 008h], ymm1
;	INST				qword ptr [memop0 + 010h], ymm2
;	INST				qword ptr [memop0 + 018h], ymm3
;	INST				qword ptr [memop0 + 020h], ymm4
;	INST				qword ptr [memop0 + 028h], ymm5
;	INST				qword ptr [memop0 + 030h], ymm6
;	INST				qword ptr [memop0 + 038h], ymm7
;endm
;
;InstLatX64_ymm2m32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 000h], ymm0
;	INST				dword ptr [memop0 + 004h], ymm1
;	INST				dword ptr [memop0 + 008h], ymm2
;	INST				dword ptr [memop0 + 00Ch], ymm3
;	INST				dword ptr [memop0 + 010h], ymm4
;	INST				dword ptr [memop0 + 014h], ymm5
;	INST				dword ptr [memop0 + 018h], ymm6
;	INST				dword ptr [memop0 + 01Ch], ymm7
;endm
;
;InstLatX64_ymm2km128_port macro INST, DOMAINSTART, DOMAINEND
;	INST				xmmword ptr [memop0 + 000h]{k1}, ymm0
;	INST				xmmword ptr [memop0 + 010h]{k1}, ymm1
;	INST				xmmword ptr [memop0 + 020h]{k1}, ymm2
;	INST				xmmword ptr [memop0 + 030h]{k1}, ymm3
;	INST				xmmword ptr [memop0 + 040h]{k1}, ymm4
;	INST				xmmword ptr [memop0 + 050h]{k1}, ymm5
;	INST				xmmword ptr [memop0 + 060h]{k1}, ymm6
;	INST				xmmword ptr [memop0 + 070h]{k1}, ymm7
;endm
;
;InstLatX64_ymm2km64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 000h]{k1}, ymm0
;	INST				qword ptr [memop0 + 008h]{k1}, ymm1
;	INST				qword ptr [memop0 + 010h]{k1}, ymm2
;	INST				qword ptr [memop0 + 018h]{k1}, ymm3
;	INST				qword ptr [memop0 + 020h]{k1}, ymm4
;	INST				qword ptr [memop0 + 028h]{k1}, ymm5
;	INST				qword ptr [memop0 + 030h]{k1}, ymm6
;	INST				qword ptr [memop0 + 038h]{k1}, ymm7
;endm
;
;InstLatX64_ymm2km32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 000h]{k1}, ymm0
;	INST				dword ptr [memop0 + 004h]{k1}, ymm1
;	INST				dword ptr [memop0 + 008h]{k1}, ymm2
;	INST				dword ptr [memop0 + 00Ch]{k1}, ymm3
;	INST				dword ptr [memop0 + 010h]{k1}, ymm4
;	INST				dword ptr [memop0 + 014h]{k1}, ymm5
;	INST				dword ptr [memop0 + 018h]{k1}, ymm6
;	INST				dword ptr [memop0 + 01Ch]{k1}, ymm7
;endm
;
;InstLatX64_ymm2zkm128_port macro INST, DOMAINSTART, DOMAINEND
;	INST				xmmword ptr [memop0 + 000h]{k1}{z}, ymm0
;	INST				xmmword ptr [memop0 + 010h]{k1}{z}, ymm1
;	INST				xmmword ptr [memop0 + 020h]{k1}{z}, ymm2
;	INST				xmmword ptr [memop0 + 030h]{k1}{z}, ymm3
;	INST				xmmword ptr [memop0 + 040h]{k1}{z}, ymm4
;	INST				xmmword ptr [memop0 + 050h]{k1}{z}, ymm5
;	INST				xmmword ptr [memop0 + 060h]{k1}{z}, ymm6
;	INST				xmmword ptr [memop0 + 070h]{k1}{z}, ymm7
;endm
;
;InstLatX64_ymm2zkm64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 000h]{k1}{z}, ymm0
;	INST				qword ptr [memop0 + 008h]{k1}{z}, ymm1
;	INST				qword ptr [memop0 + 010h]{k1}{z}, ymm2
;	INST				qword ptr [memop0 + 018h]{k1}{z}, ymm3
;	INST				qword ptr [memop0 + 020h]{k1}{z}, ymm4
;	INST				qword ptr [memop0 + 028h]{k1}{z}, ymm5
;	INST				qword ptr [memop0 + 030h]{k1}{z}, ymm6
;	INST				qword ptr [memop0 + 038h]{k1}{z}, ymm7
;endm
;
;InstLatX64_ymm2zkm32_port macro INST, DOMAINSTART, DOMAINEND
;	INST				dword ptr [memop0 + 000h]{k1}{z}, ymm0
;	INST				dword ptr [memop0 + 004h]{k1}{z}, ymm1
;	INST				dword ptr [memop0 + 008h]{k1}{z}, ymm2
;	INST				dword ptr [memop0 + 00Ch]{k1}{z}, ymm3
;	INST				dword ptr [memop0 + 010h]{k1}{z}, ymm4
;	INST				dword ptr [memop0 + 014h]{k1}{z}, ymm5
;	INST				dword ptr [memop0 + 018h]{k1}{z}, ymm6
;	INST				dword ptr [memop0 + 01Ch]{k1}{z}, ymm7
;endm

InstLatX64_zmm2m512_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmmword ptr [memop0 + 000h], zmm0
	INST				zmmword ptr [memop0 + 040h], zmm1
	INST				zmmword ptr [memop0 + 080h], zmm2
	INST				zmmword ptr [memop0 + 0C0h], zmm3
	INST				zmmword ptr [memop0 + 100h], zmm4
	INST				zmmword ptr [memop0 + 140h], zmm5
	INST				zmmword ptr [memop0 + 180h], zmm6
	INST				zmmword ptr [memop0 + 1C0h], zmm7
endm

;InstLatX64_zmm2km512_port macro INST, DOMAINSTART, DOMAINEND
;	INST				zmmword ptr [memop0 + 000h]{k1}, zmm0
;	INST				zmmword ptr [memop0 + 040h]{k1}, zmm1
;	INST				zmmword ptr [memop0 + 080h]{k1}, zmm2
;	INST				zmmword ptr [memop0 + 0C0h]{k1}, zmm3
;	INST				zmmword ptr [memop0 + 100h]{k1}, zmm4
;	INST				zmmword ptr [memop0 + 140h]{k1}, zmm5
;	INST				zmmword ptr [memop0 + 180h]{k1}, zmm6
;	INST				zmmword ptr [memop0 + 1C0h]{k1}, zmm7
;endm
;
;InstLatX64_zmm2zkm512_port macro INST, DOMAINSTART, DOMAINEND
;	;INST				zmmword ptr [memop0 + 000h]{k1}{z}, zmm0
;	;INST				zmmword ptr [memop0 + 040h]{k1}{z}, zmm1
;	;INST				zmmword ptr [memop0 + 080h]{k1}{z}, zmm2
;	;INST				zmmword ptr [memop0 + 0C0h]{k1}{z}, zmm3
;	;INST				zmmword ptr [memop0 + 100h]{k1}{z}, zmm4
;	;INST				zmmword ptr [memop0 + 140h]{k1}{z}, zmm5
;	;INST				zmmword ptr [memop0 + 180h]{k1}{z}, zmm6
;	;INST				zmmword ptr [memop0 + 1C0h]{k1}{z}, zmm7
;endm

;InstLatX64_zmm2m256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h], zmm0
;	INST				ymmword ptr [memop0 + 020h], zmm1
;	INST				ymmword ptr [memop0 + 040h], zmm2
;	INST				ymmword ptr [memop0 + 060h], zmm3
;	INST				ymmword ptr [memop0 + 080h], zmm4
;	INST				ymmword ptr [memop0 + 0A0h], zmm5
;	INST				ymmword ptr [memop0 + 0C0h], zmm6
;	INST				ymmword ptr [memop0 + 0E0h], zmm7
;endm
;
;InstLatX64_zmmi2m256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h], zmm0, 1
;	INST				ymmword ptr [memop0 + 020h], zmm1, 1
;	INST				ymmword ptr [memop0 + 040h], zmm2, 1
;	INST				ymmword ptr [memop0 + 060h], zmm3, 1
;	INST				ymmword ptr [memop0 + 080h], zmm4, 1
;	INST				ymmword ptr [memop0 + 0A0h], zmm5, 1
;	INST				ymmword ptr [memop0 + 0C0h], zmm6, 1
;	INST				ymmword ptr [memop0 + 0E0h], zmm7, 1
;endm
;
;InstLatX64_zmmi02m256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h], zmm0, 0
;	INST				ymmword ptr [memop0 + 020h], zmm1, 0
;	INST				ymmword ptr [memop0 + 040h], zmm2, 0
;	INST				ymmword ptr [memop0 + 060h], zmm3, 0
;	INST				ymmword ptr [memop0 + 080h], zmm4, 0
;	INST				ymmword ptr [memop0 + 0A0h], zmm5, 0
;	INST				ymmword ptr [memop0 + 0C0h], zmm6, 0
;	INST				ymmword ptr [memop0 + 0E0h], zmm7, 0
;endm
;
;InstLatX64_zmmi2km256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h]{k1}, zmm0, 1
;	INST				ymmword ptr [memop0 + 020h]{k1}, zmm1, 1
;	INST				ymmword ptr [memop0 + 040h]{k1}, zmm2, 1
;	INST				ymmword ptr [memop0 + 060h]{k1}, zmm3, 1
;	INST				ymmword ptr [memop0 + 080h]{k1}, zmm4, 1
;	INST				ymmword ptr [memop0 + 0A0h]{k1}, zmm5, 1
;	INST				ymmword ptr [memop0 + 0C0h]{k1}, zmm6, 1
;	INST				ymmword ptr [memop0 + 0E0h]{k1}, zmm7, 1
;endm
;
;InstLatX64_zmmi02km256_port macro INST, DOMAINSTART, DOMAINEND
;	INST				ymmword ptr [memop0 + 000h]{k1}, zmm0, 0
;	INST				ymmword ptr [memop0 + 020h]{k1}, zmm1, 0
;	INST				ymmword ptr [memop0 + 040h]{k1}, zmm2, 0
;	INST				ymmword ptr [memop0 + 060h]{k1}, zmm3, 0
;	INST				ymmword ptr [memop0 + 080h]{k1}, zmm4, 0
;	INST				ymmword ptr [memop0 + 0A0h]{k1}, zmm5, 0
;	INST				ymmword ptr [memop0 + 0C0h]{k1}, zmm6, 0
;	INST				ymmword ptr [memop0 + 0E0h]{k1}, zmm7, 0
;endm
;
;InstLatX64_zmm2m128_port macro INST, DOMAINSTART, DOMAINEND
;	INST				xmmword ptr [memop0 + 000h], zmm0
;	INST				xmmword ptr [memop0 + 010h], zmm1
;	INST				xmmword ptr [memop0 + 020h], zmm2
;	INST				xmmword ptr [memop0 + 030h], zmm3
;	INST				xmmword ptr [memop0 + 040h], zmm4
;	INST				xmmword ptr [memop0 + 050h], zmm5
;	INST				xmmword ptr [memop0 + 060h], zmm6
;	INST				xmmword ptr [memop0 + 070h], zmm7
;endm
;
;InstLatX64_zmm2m64_port macro INST, DOMAINSTART, DOMAINEND
;	INST				qword ptr [memop0 + 000h], zmm0
;	INST				qword ptr [memop0 + 008h], zmm1
;	INST				qword ptr [memop0 + 010h], zmm2
;	INST				qword ptr [memop0 + 018h], zmm3
;	INST				qword ptr [memop0 + 020h], zmm4
;	INST				qword ptr [memop0 + 028h], zmm5
;	INST				qword ptr [memop0 + 030h], zmm6
;	INST				qword ptr [memop0 + 038h], zmm7
;endm

InstLatX64_zmm2km256_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymmword ptr [memop0 + 000h]{k1}, zmm0
	INST				ymmword ptr [memop0 + 020h]{k1}, zmm1
	INST				ymmword ptr [memop0 + 040h]{k1}, zmm2
	INST				ymmword ptr [memop0 + 060h]{k1}, zmm3
	INST				ymmword ptr [memop0 + 080h]{k1}, zmm4
	INST				ymmword ptr [memop0 + 0A0h]{k1}, zmm5
	INST				ymmword ptr [memop0 + 0C0h]{k1}, zmm6
	INST				ymmword ptr [memop0 + 0E0h]{k1}, zmm7
endm

InstLatX64_zmm2km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h]{k1}, zmm0
	INST				xmmword ptr [memop0 + 010h]{k1}, zmm1
	INST				xmmword ptr [memop0 + 020h]{k1}, zmm2
	INST				xmmword ptr [memop0 + 030h]{k1}, zmm3
	INST				xmmword ptr [memop0 + 040h]{k1}, zmm4
	INST				xmmword ptr [memop0 + 050h]{k1}, zmm5
	INST				xmmword ptr [memop0 + 060h]{k1}, zmm6
	INST				xmmword ptr [memop0 + 070h]{k1}, zmm7
endm

InstLatX64_zmm2km64_port macro INST, DOMAINSTART, DOMAINEND
	INST				qword ptr [memop0 + 000h]{k1}, zmm0
	INST				qword ptr [memop0 + 008h]{k1}, zmm1
	INST				qword ptr [memop0 + 010h]{k1}, zmm2
	INST				qword ptr [memop0 + 018h]{k1}, zmm3
	INST				qword ptr [memop0 + 020h]{k1}, zmm4
	INST				qword ptr [memop0 + 028h]{k1}, zmm5
	INST				qword ptr [memop0 + 030h]{k1}, zmm6
	INST				qword ptr [memop0 + 038h]{k1}, zmm7
endm

InstLatX64_zmm2zkm256_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymmword ptr [memop0 + 000h]{k1}{z}, zmm0
	INST				ymmword ptr [memop0 + 020h]{k1}{z}, zmm1
	INST				ymmword ptr [memop0 + 040h]{k1}{z}, zmm2
	INST				ymmword ptr [memop0 + 060h]{k1}{z}, zmm3
	INST				ymmword ptr [memop0 + 080h]{k1}{z}, zmm4
	INST				ymmword ptr [memop0 + 0A0h]{k1}{z}, zmm5
	INST				ymmword ptr [memop0 + 0C0h]{k1}{z}, zmm6
	INST				ymmword ptr [memop0 + 0E0h]{k1}{z}, zmm7
endm

InstLatX64_zmm2zkm128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h]{k1}{z}, zmm0
	INST				xmmword ptr [memop0 + 010h]{k1}{z}, zmm1
	INST				xmmword ptr [memop0 + 020h]{k1}{z}, zmm2
	INST				xmmword ptr [memop0 + 030h]{k1}{z}, zmm3
	INST				xmmword ptr [memop0 + 040h]{k1}{z}, zmm4
	INST				xmmword ptr [memop0 + 050h]{k1}{z}, zmm5
	INST				xmmword ptr [memop0 + 060h]{k1}{z}, zmm6
	INST				xmmword ptr [memop0 + 070h]{k1}{z}, zmm7
endm

InstLatX64_zmm2zkm64_port macro INST, DOMAINSTART, DOMAINEND
	INST				qword ptr [memop0 + 000h]{k1}, zmm0
	INST				qword ptr [memop0 + 008h]{k1}, zmm1
	INST				qword ptr [memop0 + 010h]{k1}, zmm2
	INST				qword ptr [memop0 + 018h]{k1}, zmm3
	INST				qword ptr [memop0 + 020h]{k1}, zmm4
	INST				qword ptr [memop0 + 028h]{k1}, zmm5
	INST				qword ptr [memop0 + 030h]{k1}, zmm6
	INST				qword ptr [memop0 + 038h]{k1}, zmm7
endm

InstLatX64_zmmi2m128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h], zmm0, 1
	INST				xmmword ptr [memop0 + 010h], zmm1, 1
	INST				xmmword ptr [memop0 + 020h], zmm2, 1
	INST				xmmword ptr [memop0 + 030h], zmm3, 1
	INST				xmmword ptr [memop0 + 040h], zmm4, 1
	INST				xmmword ptr [memop0 + 050h], zmm5, 1
	INST				xmmword ptr [memop0 + 060h], zmm6, 1
	INST				xmmword ptr [memop0 + 070h], zmm7, 1
endm

InstLatX64_zmmi02m128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h], zmm0, 0
	INST				xmmword ptr [memop0 + 010h], zmm1, 0
	INST				xmmword ptr [memop0 + 020h], zmm2, 0
	INST				xmmword ptr [memop0 + 030h], zmm3, 0
	INST				xmmword ptr [memop0 + 040h], zmm4, 0
	INST				xmmword ptr [memop0 + 050h], zmm5, 0
	INST				xmmword ptr [memop0 + 060h], zmm6, 0
	INST				xmmword ptr [memop0 + 070h], zmm7, 0
endm

InstLatX64_zmmi2km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h], zmm0{k1}, 1
	INST				xmmword ptr [memop0 + 010h], zmm1{k1}, 1
	INST				xmmword ptr [memop0 + 020h], zmm2{k1}, 1
	INST				xmmword ptr [memop0 + 030h], zmm3{k1}, 1
	INST				xmmword ptr [memop0 + 040h], zmm4{k1}, 1
	INST				xmmword ptr [memop0 + 050h], zmm5{k1}, 1
	INST				xmmword ptr [memop0 + 060h], zmm6{k1}, 1
	INST				xmmword ptr [memop0 + 070h], zmm7{k1}, 1
endm

InstLatX64_zmmi02km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h], zmm0{k1}, 0
	INST				xmmword ptr [memop0 + 010h], zmm1{k1}, 0
	INST				xmmword ptr [memop0 + 020h], zmm2{k1}, 0
	INST				xmmword ptr [memop0 + 030h], zmm3{k1}, 0
	INST				xmmword ptr [memop0 + 040h], zmm4{k1}, 0
	INST				xmmword ptr [memop0 + 050h], zmm5{k1}, 0
	INST				xmmword ptr [memop0 + 060h], zmm6{k1}, 0
	INST				xmmword ptr [memop0 + 070h], zmm7{k1}, 0
endm

InstLatX64_zmmi2km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h]{k1}, zmm0, 1
	INST				xmmword ptr [memop0 + 010h]{k1}, zmm1, 1
	INST				xmmword ptr [memop0 + 020h]{k1}, zmm2, 1
	INST				xmmword ptr [memop0 + 030h]{k1}, zmm3, 1
	INST				xmmword ptr [memop0 + 040h]{k1}, zmm4, 1
	INST				xmmword ptr [memop0 + 050h]{k1}, zmm5, 1
	INST				xmmword ptr [memop0 + 060h]{k1}, zmm6, 1
	INST				xmmword ptr [memop0 + 070h]{k1}, zmm7, 1
endm

InstLatX64_zmmi02km128_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmmword ptr [memop0 + 000h]{k1}, zmm0, 0
	INST				xmmword ptr [memop0 + 010h]{k1}, zmm1, 0
	INST				xmmword ptr [memop0 + 020h]{k1}, zmm2, 0
	INST				xmmword ptr [memop0 + 030h]{k1}, zmm3, 0
	INST				xmmword ptr [memop0 + 040h]{k1}, zmm4, 0
	INST				xmmword ptr [memop0 + 050h]{k1}, zmm5, 0
	INST				xmmword ptr [memop0 + 060h]{k1}, zmm6, 0
	INST				xmmword ptr [memop0 + 070h]{k1}, zmm7, 0
endm

InstLatX64_xmm2kxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k1}, xmm0
	INST				xmm1{k1}, xmm1
	INST				xmm2{k2}, xmm2
	INST				xmm3{k3}, xmm3
	INST				xmm4{k4}, xmm4
	INST				xmm5{k5}, xmm5
	INST				xmm6{k6}, xmm6
	INST				xmm7{k7}, xmm7
endm

InstLatX64_ymm2kymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}, ymm0
	INST				ymm1{k1}, ymm1
	INST				ymm2{k2}, ymm2
	INST				ymm3{k3}, ymm3
	INST				ymm4{k4}, ymm4
	INST				ymm5{k5}, ymm5
	INST				ymm6{k6}, ymm6
	INST				ymm7{k7}, ymm7
endm

InstLatX64_zmm2kzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k1}, zmm0
	INST				zmm1{k1}, zmm1
	INST				zmm2{k2}, zmm2
	INST				zmm3{k3}, zmm3
	INST				zmm4{k4}, zmm4
	INST				zmm5{k5}, zmm5
	INST				zmm6{k6}, zmm6
	INST				zmm7{k7}, zmm7
endm

InstLatX64_xmm2zkxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k1}{z}, xmm0
	INST				xmm1{k1}{z}, xmm1
	INST				xmm2{k2}{z}, xmm2
	INST				xmm3{k3}{z}, xmm3
	INST				xmm4{k4}{z}, xmm4
	INST				xmm5{k5}{z}, xmm5
	INST				xmm6{k6}{z}, xmm6
	INST				xmm7{k7}{z}, xmm7
endm

InstLatX64_ymm2zkymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}{z}, ymm0
	INST				ymm1{k1}{z}, ymm1
	INST				ymm2{k2}{z}, ymm2
	INST				ymm3{k3}{z}, ymm3
	INST				ymm4{k4}{z}, ymm4
	INST				ymm5{k5}{z}, ymm5
	INST				ymm6{k6}{z}, ymm6
	INST				ymm7{k7}{z}, ymm7
endm

InstLatX64_zmm2zkzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k1}{z}, zmm0
	INST				zmm1{k1}{z}, zmm1
	INST				zmm2{k2}{z}, zmm2
	INST				zmm3{k3}{z}, zmm3
	INST				zmm4{k4}{z}, zmm4
	INST				zmm5{k5}{z}, zmm5
	INST				zmm6{k6}{z}, zmm6
	INST				zmm7{k7}{z}, zmm7
endm

InstLatX64_2xmm2kxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k1}, xmm0, xmm0
	INST				xmm1{k1}, xmm1, xmm1
	INST				xmm2{k2}, xmm2, xmm2
	INST				xmm3{k3}, xmm3, xmm3
	INST				xmm4{k4}, xmm4, xmm4
	INST				xmm5{k5}, xmm5, xmm5
	INST				xmm6{k6}, xmm6, xmm6
	INST				xmm7{k7}, xmm7, xmm7
endm

InstLatX64_2ymm2kymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}, ymm0, ymm0
	INST				ymm1{k1}, ymm1, ymm1
	INST				ymm2{k2}, ymm2, ymm2
	INST				ymm3{k3}, ymm3, ymm3
	INST				ymm4{k4}, ymm4, ymm4
	INST				ymm5{k5}, ymm5, ymm5
	INST				ymm6{k6}, ymm6, ymm6
	INST				ymm7{k7}, ymm7, ymm7
endm

InstLatX64_2zmm2kzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k1}, zmm0, zmm0
	INST				zmm1{k1}, zmm1, zmm1
	INST				zmm2{k2}, zmm2, zmm2
	INST				zmm3{k3}, zmm3, zmm3
	INST				zmm4{k4}, zmm4, zmm4
	INST				zmm5{k5}, zmm5, zmm5
	INST				zmm6{k6}, zmm6, zmm6
	INST				zmm7{k7}, zmm7, zmm7
endm

InstLatX64_2xmm2zkxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0{k1}{z}, xmm0, xmm0
	INST				xmm1{k1}{z}, xmm1, xmm1
	INST				xmm2{k2}{z}, xmm2, xmm2
	INST				xmm3{k3}{z}, xmm3, xmm3
	INST				xmm4{k4}{z}, xmm4, xmm4
	INST				xmm5{k5}{z}, xmm5, xmm5
	INST				xmm6{k6}{z}, xmm6, xmm6
	INST				xmm7{k7}{z}, xmm7, xmm7
endm

InstLatX64_2ymm2zkymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0{k1}{z}, ymm0, ymm0
	INST				ymm1{k1}{z}, ymm1, ymm1
	INST				ymm2{k2}{z}, ymm2, ymm2
	INST				ymm3{k3}{z}, ymm3, ymm3
	INST				ymm4{k4}{z}, ymm4, ymm4
	INST				ymm5{k5}{z}, ymm5, ymm5
	INST				ymm6{k6}{z}, ymm6, ymm6
	INST				ymm7{k7}{z}, ymm7, ymm7
endm

InstLatX64_2zmm2zkzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k1}{z}, zmm0, zmm0
	INST				zmm1{k1}{z}, zmm1, zmm1
	INST				zmm2{k2}{z}, zmm2, zmm2
	INST				zmm3{k3}{z}, zmm3, zmm3
	INST				zmm4{k4}{z}, zmm4, zmm4
	INST				zmm5{k5}{z}, zmm5, zmm5
	INST				zmm6{k6}{z}, zmm6, zmm6
	INST				zmm7{k7}{z}, zmm7, zmm7
endm

InstLatX64_evex_xmmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, xmm0, 0
	evex INST			xmm1, xmm1, 1
	evex INST			xmm2, xmm2, 2
	evex INST			xmm3, xmm3, 3
	evex INST			xmm4, xmm4, 4
	evex INST			xmm5, xmm5, 5
	evex INST			xmm6, xmm6, 6
	evex INST			xmm7, xmm7, 7
endm

InstLatX64_evex_ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm0, ymm0, 0
	evex INST			ymm1, ymm1, 1
	evex INST			ymm2, ymm2, 2
	evex INST			ymm3, ymm3, 3
	evex INST			ymm4, ymm4, 4
	evex INST			ymm5, ymm5, 5
	evex INST			ymm6, ymm6, 6
	evex INST			ymm7, ymm7, 7
endm

InstLatX64_evex_ymmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, ymm0, 0
	evex INST			xmm1, ymm1, 1
	evex INST			xmm2, ymm2, 2
	evex INST			xmm3, ymm3, 3
	evex INST			xmm4, ymm4, 4
	evex INST			xmm5, ymm5, 5
	evex INST			xmm6, ymm6, 6
	evex INST			xmm7, ymm7, 7
endm

InstLatX64_zmmi2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, zmm0, 0
	INST				zmm1, zmm1, 1
	INST				zmm2, zmm2, 2
	INST				zmm3, zmm3, 3
	INST				zmm4, zmm4, 4
	INST				zmm5, zmm5, 5
	INST				zmm6, zmm6, 6
	INST				zmm7, zmm7, 7
endm

InstLatX64_evex_2xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, xmm0, xmm0
	evex INST			xmm1, xmm1, xmm1
	evex INST			xmm2, xmm2, xmm2
	evex INST			xmm3, xmm3, xmm3
	evex INST			xmm4, xmm4, xmm4
	evex INST			xmm5, xmm5, xmm5
	evex INST			xmm6, xmm6, xmm6
	evex INST			xmm7, xmm7, xmm7
endm

InstLatX64_evex_2ymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm0, ymm0, ymm0
	evex INST			ymm1, ymm1, ymm1
	evex INST			ymm2, ymm2, ymm2
	evex INST			ymm3, ymm3, ymm3
	evex INST			ymm4, ymm4, ymm4
	evex INST			ymm5, ymm5, ymm5
	evex INST			ymm6, ymm6, ymm6
	evex INST			ymm7, ymm7, ymm7
endm

InstLatX64_2zmm2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, zmm0, zmm0
	INST				zmm1, zmm1, zmm1
	INST				zmm2, zmm2, zmm2
	INST				zmm3, zmm3, zmm3
	INST				zmm4, zmm4, zmm4
	INST				zmm5, zmm5, zmm5
	INST				zmm6, zmm6, zmm6
	INST				zmm7, zmm7, zmm7
endm

InstLatX64_evex_2xmmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			xmm0, xmm0, xmm0, 0
	evex INST			xmm1, xmm1, xmm1, 1
	evex INST			xmm2, xmm2, xmm2, 2
	evex INST			xmm3, xmm3, xmm3, 3
	evex INST			xmm4, xmm4, xmm4, 4
	evex INST			xmm5, xmm5, xmm5, 5
	evex INST			xmm6, xmm6, xmm6, 6
	evex INST			xmm7, xmm7, xmm7, 7
endm

InstLatX64_evex_2ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm0, ymm0, ymm0, 0
	evex INST			ymm1, ymm1, ymm1, 1
	evex INST			ymm2, ymm2, ymm2, 2
	evex INST			ymm3, ymm3, ymm3, 3
	evex INST			ymm4, ymm4, ymm4, 4
	evex INST			ymm5, ymm5, ymm5, 5
	evex INST			ymm6, ymm6, ymm6, 6
	evex INST			ymm7, ymm7, ymm7, 7
endm

InstLatX64_2zmmi2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, zmm0, zmm0, 0
	INST				zmm1, zmm1, zmm1, 1
	INST				zmm2, zmm2, zmm2, 2
	INST				zmm3, zmm3, zmm3, 3
	INST				zmm4, zmm4, zmm4, 4
	INST				zmm5, zmm5, zmm5, 5
	INST				zmm6, zmm6, zmm6, 6
	INST				zmm7, zmm7, zmm7, 7
endm

InstLatX64_2zmmi2kzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k0}, zmm0, zmm0, 0
	INST				zmm1{k1}, zmm1, zmm1, 1
	INST				zmm2{k2}, zmm2, zmm2, 2
	INST				zmm3{k3}, zmm3, zmm3, 3
	INST				zmm4{k4}, zmm4, zmm4, 4
	INST				zmm5{k5}, zmm5, zmm5, 5
	INST				zmm6{k6}, zmm6, zmm6, 6
	INST				zmm7{k7}, zmm7, zmm7, 7
endm

InstLatX64_2zmmi2zkzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k0}{z}, zmm0, zmm0, 0
	INST				zmm1{k1}{z}, zmm1, zmm1, 1
	INST				zmm2{k2}{z}, zmm2, zmm2, 2
	INST				zmm3{k3}{z}, zmm3, zmm3, 3
	INST				zmm4{k4}{z}, zmm4, zmm4, 4
	INST				zmm5{k5}{z}, zmm5, zmm5, 5
	INST				zmm6{k6}{z}, zmm6, zmm6, 6
	INST				zmm7{k7}{z}, zmm7, zmm7, 7
endm

InstLatX64_2zmmi2zmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, zmm1, zmm2, 0
	INST				zmm1, zmm2, zmm3, 1
	INST				zmm2, zmm3, zmm4, 2
	INST				zmm3, zmm4, zmm5, 3
	INST				zmm4, zmm5, zmm6, 4
	INST				zmm5, zmm6, zmm7, 5
	INST				zmm6, zmm7, zmm0, 6
	INST				zmm7, zmm0, zmm1, 7

	;INST				zmm0, zmm0, zmm9, 0
	;INST				zmm1, zmm1, zmm9, 1
	;INST				zmm2, zmm2, zmm9, 2
	;INST				zmm3, zmm3, zmm9, 3
	;INST				zmm4, zmm4, zmm9, 4
	;INST				zmm5, zmm5, zmm9, 5
	;INST				zmm6, zmm6, zmm9, 6
	;INST				zmm7, zmm7, zmm9, 7
endm

InstLatX64_2zmmi2kzmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k0}, zmm1, zmm2, 0
	INST				zmm1{k1}, zmm2, zmm3, 1
	INST				zmm2{k2}, zmm3, zmm4, 2
	INST				zmm3{k3}, zmm4, zmm5, 3
	INST				zmm4{k4}, zmm5, zmm6, 4
	INST				zmm5{k5}, zmm6, zmm7, 5
	INST				zmm6{k6}, zmm7, zmm0, 6
	INST				zmm7{k7}, zmm0, zmm1, 7

	;INST				zmm0{k0}, zmm0, zmm9, 0
	;INST				zmm1{k1}, zmm1, zmm9, 1
	;INST				zmm2{k2}, zmm2, zmm9, 2
	;INST				zmm3{k3}, zmm3, zmm9, 3
	;INST				zmm4{k4}, zmm4, zmm9, 4
	;INST				zmm5{k5}, zmm5, zmm9, 5
	;INST				zmm6{k6}, zmm6, zmm9, 6
	;INST				zmm7{k7}, zmm7, zmm9, 7
endm

InstLatX64_2zmmi2zkzmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0{k0}{z}, zmm1, zmm2, 0
	INST				zmm1{k1}{z}, zmm2, zmm3, 1
	INST				zmm2{k2}{z}, zmm3, zmm4, 2
	INST				zmm3{k3}{z}, zmm4, zmm5, 3
	INST				zmm4{k4}{z}, zmm5, zmm6, 4
	INST				zmm5{k5}{z}, zmm6, zmm7, 5
	INST				zmm6{k6}{z}, zmm7, zmm0, 6
	INST				zmm7{k7}{z}, zmm0, zmm1, 7

	;INST				zmm0{k0}{z}, zmm0, zmm9, 0
	;INST				zmm1{k1}{z}, zmm1, zmm9, 1
	;INST				zmm2{k2}{z}, zmm2, zmm9, 2
	;INST				zmm3{k3}{z}, zmm3, zmm9, 3
	;INST				zmm4{k4}{z}, zmm4, zmm9, 4
	;INST				zmm5{k5}{z}, zmm5, zmm9, 5
	;INST				zmm6{k6}{z}, zmm6, zmm9, 6
	;INST				zmm7{k7}{z}, zmm7, zmm9, 7
endm

InstLatX64_vex_2xmm2xmm_port macro INST, DOMAINSTART, DOMAINEND
	vex INST			xmm0, xmm0, xmm0
	vex INST			xmm1, xmm1, xmm1
	vex INST			xmm2, xmm2, xmm2
	vex INST			xmm3, xmm3, xmm3
	vex INST			xmm4, xmm4, xmm4
	vex INST			xmm5, xmm5, xmm5
	vex INST			xmm6, xmm6, xmm6
	vex INST			xmm7, xmm7, xmm7
endm

InstLatX64_vex_2ymm2ymm_lat macro INST, DOMAINSTART, DOMAINEND
	vex INST			ymm0, ymm0, ymm0
	vex INST			ymm1, ymm1, ymm1
	vex INST			ymm2, ymm2, ymm2
	vex INST			ymm3, ymm3, ymm3
	vex INST			ymm4, ymm4, ymm4
	vex INST			ymm5, ymm5, ymm5
	vex INST			ymm6, ymm6, ymm6
	vex INST			ymm7, ymm7, ymm7
endm

InstLatX64_evex_xmmymm2ymm_port macro INST, DOMAINSTART, DOMAINEND
	evex INST			ymm8, ymm8, xmm8
	evex INST			ymm9, ymm9, xmm9
	evex INST			ymm10, ymm10, xmm10
	evex INST			ymm11, ymm11, xmm11
	evex INST			ymm12, ymm12, xmm12
	evex INST			ymm13, ymm13, xmm13
	evex INST			ymm14, ymm14, xmm14
	evex INST			ymm15, ymm15, xmm15
endm

InstLatX64_xmmzmm2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, zmm8, xmm8
	INST			zmm9, zmm9, xmm9
	INST			zmm10, zmm10, xmm10
	INST			zmm11, zmm11, xmm11
	INST			zmm12, zmm12, xmm12
	INST			zmm13, zmm13, xmm13
	INST			zmm14, zmm14, xmm14
	INST			zmm15, zmm15, xmm15
endm


InstLatX64_evex_2xmm2xmmRot_port macro INST, DOMAINSTART, DOMAINEND
	evex INST		xmm14, xmm15, xmm8
	evex INST		xmm15, xmm8, xmm9
	evex INST		xmm8, xmm9, xmm10
	evex INST		xmm9, xmm10, xmm11
	evex INST		xmm10, xmm11, xmm12
	evex INST		xmm11, xmm12, xmm13
	evex INST		xmm12, xmm13, xmm14
	evex INST		xmm13, xmm14, xmm15
endm

InstLatX64_evex_2ymm2ymmRot_port macro INST, DOMAINSTART, DOMAINEND
	evex INST		ymm14, ymm15, ymm8
	evex INST		ymm15, ymm8, ymm9
	evex INST		ymm8, ymm9, ymm10
	evex INST		ymm9, ymm10, ymm11
	evex INST		ymm10, ymm11, ymm12
	evex INST		ymm11, ymm12, ymm13
	evex INST		ymm12, ymm13, ymm14
	evex INST		ymm13, ymm14, ymm15
endm

InstLatX64_2zmm2zmmRot_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm14, zmm15, zmm8
	INST			zmm15, zmm8, zmm9
	INST			zmm8, zmm9, zmm10
	INST			zmm9, zmm10, zmm11
	INST			zmm10, zmm11, zmm12
	INST			zmm11, zmm12, zmm13
	INST			zmm12, zmm13, zmm14
	INST			zmm13, zmm14, zmm15
endm

InstLatX64_2xmm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, xmm0, xmm0
	INST				k1, xmm1, xmm1
	INST				k2, xmm2, xmm2
	INST				k3, xmm3, xmm3
	INST				k4, xmm4, xmm4
	INST				k5, xmm5, xmm5
	INST				k6, xmm6, xmm6
	INST				k7, xmm7, xmm7
endm

InstLatX64_2ymm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, ymm0, ymm0
	INST				k1, ymm1, ymm1
	INST				k2, ymm2, ymm2
	INST				k3, ymm3, ymm3
	INST				k4, ymm4, ymm4
	INST				k5, ymm5, ymm5
	INST				k6, ymm6, ymm6
	INST				k7, ymm7, ymm7
endm

InstLatX64_2zmm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, zmm0, zmm0
	INST				k1, zmm1, zmm1
	INST				k2, zmm2, zmm2
	INST				k3, zmm3, zmm3
	INST				k4, zmm4, zmm4
	INST				k5, zmm5, zmm5
	INST				k6, zmm6, zmm6
	INST				k7, zmm7, zmm7
endm

InstLatX64_2xmmk2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, xmm0, xmm0
	INST				k1{k1}, xmm1, xmm1
	INST				k2{k2}, xmm2, xmm2
	INST				k3{k3}, xmm3, xmm3
	INST				k4{k4}, xmm4, xmm4
	INST				k5{k5}, xmm5, xmm5
	INST				k6{k6}, xmm6, xmm6
	INST				k7{k7}, xmm7, xmm7
endm

InstLatX64_2ymmk2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, ymm0, ymm0
	INST				k1{k1}, ymm1, ymm1
	INST				k2{k2}, ymm2, ymm2
	INST				k3{k3}, ymm3, ymm3
	INST				k4{k4}, ymm4, ymm4
	INST				k5{k5}, ymm5, ymm5
	INST				k6{k6}, ymm6, ymm6
	INST				k7{k7}, ymm7, ymm7
endm

InstLatX64_2zmmk2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, zmm0, zmm0
	INST				k1{k1}, zmm1, zmm1
	INST				k2{k2}, zmm2, zmm2
	INST				k3{k3}, zmm3, zmm3
	INST				k4{k4}, zmm4, zmm4
	INST				k5{k5}, zmm5, zmm5
	INST				k6{k6}, zmm6, zmm6
	INST				k7{k7}, zmm7, zmm7
endm

InstLatX64_2xmm2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, xmm0, xmm1
	INST				k1, xmm1, xmm2
	INST				k2, xmm2, xmm3
	INST				k3, xmm3, xmm4
	INST				k4, xmm4, xmm5
	INST				k5, xmm5, xmm6
	INST				k6, xmm6, xmm7
	INST				k7, xmm7, xmm0
endm

InstLatX64_2ymm2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, ymm0, ymm1
	INST				k1, ymm1, ymm2
	INST				k2, ymm2, ymm3
	INST				k3, ymm3, ymm4
	INST				k4, ymm4, ymm5
	INST				k5, ymm5, ymm6
	INST				k6, ymm6, ymm7
	INST				k7, ymm7, ymm0
endm

InstLatX64_2zmm2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, zmm0, zmm1
	INST				k1, zmm1, zmm2
	INST				k2, zmm2, zmm3
	INST				k3, zmm3, zmm4
	INST				k4, zmm4, zmm5
	INST				k5, zmm5, zmm6
	INST				k6, zmm6, zmm7
	INST				k7, zmm7, zmm0
endm

InstLatX64_2xmmk2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, xmm0, xmm1
	INST				k1{k1}, xmm1, xmm2
	INST				k2{k2}, xmm2, xmm3
	INST				k3{k3}, xmm3, xmm4
	INST				k4{k4}, xmm4, xmm5
	INST				k5{k5}, xmm5, xmm6
	INST				k6{k6}, xmm6, xmm7
	INST				k7{k7}, xmm7, xmm0
endm

InstLatX64_2ymmk2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, ymm0, ymm1
	INST				k1{k1}, ymm1, ymm2
	INST				k2{k2}, ymm2, ymm3
	INST				k3{k3}, ymm3, ymm4
	INST				k4{k4}, ymm4, ymm5
	INST				k5{k5}, ymm5, ymm6
	INST				k6{k6}, ymm6, ymm7
	INST				k7{k7}, ymm7, ymm0
endm

InstLatX64_2zmmk2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, zmm0, zmm1
	INST				k1{k1}, zmm1, zmm2
	INST				k2{k2}, zmm2, zmm3
	INST				k3{k3}, zmm3, zmm4
	INST				k4{k4}, zmm4, zmm5
	INST				k5{k5}, zmm5, zmm6
	INST				k6{k6}, zmm6, zmm7
	INST				k7{k7}, zmm7, zmm0
endm

InstLatX64_xmm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, xmm0
	INST				k1, xmm1
	INST				k2, xmm2
	INST				k3, xmm3
	INST				k4, xmm4
	INST				k5, xmm5
	INST				k6, xmm6
	INST				k7, xmm7
endm

InstLatX64_ymm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, ymm0
	INST				k1, ymm1
	INST				k2, ymm2
	INST				k3, ymm3
	INST				k4, ymm4
	INST				k5, ymm5
	INST				k6, ymm6
	INST				k7, ymm7
endm

InstLatX64_zmm2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, zmm0
	INST				k1, zmm1
	INST				k2, zmm2
	INST				k3, zmm3
	INST				k4, zmm4
	INST				k5, zmm5
	INST				k6, zmm6
	INST				k7, zmm7
endm

InstLatX64_k2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				xmm0, k0
	INST				xmm1, k1
	INST				xmm2, k2
	INST				xmm3, k3
	INST				xmm4, k4
	INST				xmm5, k5
	INST				xmm6, k6
	INST				xmm7, k7
endm

InstLatX64_k2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST				ymm0, k0
	INST				ymm1, k1
	INST				ymm2, k2
	INST				ymm3, k3
	INST				ymm4, k4
	INST				ymm5, k5
	INST				ymm6, k6
	INST				ymm7, k7
endm

InstLatX64_k2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST				zmm0, k0
	INST				zmm1, k1
	INST				zmm2, k2
	INST				zmm3, k3
	INST				zmm4, k4
	INST				zmm5, k5
	INST				zmm6, k6
	INST				zmm7, k7
endm

InstLatX64_xmmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, xmm0, 0
	INST				k1, xmm1, 1
	INST				k2, xmm2, 2
	INST				k3, xmm3, 3
	INST				k4, xmm4, 4
	INST				k5, xmm5, 5
	INST				k6, xmm6, 6
	INST				k7, xmm7, 7
endm

InstLatX64_ymmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, ymm0, 0
	INST				k1, ymm1, 1
	INST				k2, ymm2, 2
	INST				k3, ymm3, 3
	INST				k4, ymm4, 4
	INST				k5, ymm5, 5
	INST				k6, ymm6, 6
	INST				k7, ymm7, 7
endm

InstLatX64_zmmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, zmm0, 0
	INST				k1, zmm1, 1
	INST				k2, zmm2, 2
	INST				k3, zmm3, 3
	INST				k4, zmm4, 4
	INST				k5, zmm5, 5
	INST				k6, zmm6, 6
	INST				k7, zmm7, 7
endm

InstLatX64_xmmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, xmm0, 0
	INST				k1{k1}, xmm1, 1
	INST				k2{k2}, xmm2, 2
	INST				k3{k3}, xmm3, 3
	INST				k4{k4}, xmm4, 4
	INST				k5{k5}, xmm5, 5
	INST				k6{k6}, xmm6, 6
	INST				k7{k7}, xmm7, 7
endm

InstLatX64_ymmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, ymm0, 0
	INST				k1{k1}, ymm1, 1
	INST				k2{k2}, ymm2, 2
	INST				k3{k3}, ymm3, 3
	INST				k4{k4}, ymm4, 4
	INST				k5{k5}, ymm5, 5
	INST				k6{k6}, ymm6, 6
	INST				k7{k7}, ymm7, 7
endm

InstLatX64_zmmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, zmm0, 0
	INST				k1{k1}, zmm1, 1
	INST				k2{k2}, zmm2, 2
	INST				k3{k3}, zmm3, 3
	INST				k4{k4}, zmm4, 4
	INST				k5{k5}, zmm5, 5
	INST				k6{k6}, zmm6, 6
	INST				k7{k7}, zmm7, 7
endm

InstLatX64_k2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, k0
	INST				k1, k1
	INST				k2, k2
	INST				k3, k3
	INST				k4, k4
	INST				k5, k5
	INST				k6, k6
	INST				k7, k7
endm

InstLatX64_2k2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, k0, k0
	INST				k1, k1, k1
	INST				k2, k2, k2
	INST				k3, k3, k3
	INST				k4, k4, k4
	INST				k5, k5, k5
	INST				k6, k6, k6
	INST				k7, k7, k7
endm

InstLatX64_2k2c_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, k0
	INST				k1, k1
	INST				k2, k2
	INST				k3, k3
	INST				k4, k4
	INST				k5, k5
	INST				k6, k6
	INST				k7, k7
endm

InstLatX64_ki2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, k0, 0
	INST				k1, k1, 1
	INST				k2, k2, 2
	INST				k3, k3, 3
	INST				k4, k4, 4
	INST				k5, k5, 5
	INST				k6, k6, 6
	INST				k7, k7, 7
endm

InstLatX64_2k2kRot_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, k0, k1
	INST				k1, k1, k2
	INST				k2, k2, k3
	INST				k3, k3, k4
	INST				k4, k4, k5
	INST				k5, k5, k6
	INST				k6, k6, k7
	INST				k7, k7, k0
endm

InstLatX64_gpr32_2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, eax
	INST				k1, edx
	INST				k2, ebx
	INST				k3, r8d
	INST				k4, r9d
	INST				k5, r10d
	INST				k6, r11d
	INST				k7, r12d
endm

InstLatX64_gpr64_2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, rax
	INST				k1, rdx
	INST				k2, rbx
	INST				k3, r8
	INST				k4, r9
	INST				k5, r10
	INST				k6, r11
	INST				k7, r12
endm

InstLatX64_k2gpr32_port macro INST, DOMAINSTART, DOMAINEND
	INST				eax , k0
	INST				edx	, k1
	INST				ebx	, k2
	INST				r8d	, k3
	INST				r9d	, k4
	INST				r10d, k5
	INST				r11d, k6
	INST				r12d, k7
endm

InstLatX64_k2gpr64_port macro INST, DOMAINSTART, DOMAINEND
	INST				rax, k0
	INST				rdx, k1
	INST				rbx, k2
	INST				r8,	 k3
	INST				r9,	 k4
	INST				r10, k5
	INST				r11, k6
	INST				r12, k7
endm

InstLatX64_2xmmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, xmm0, xmm0, 0
	INST				k1, xmm1, xmm1, 1
	INST				k2, xmm2, xmm2, 2
	INST				k3, xmm3, xmm3, 3
	INST				k4, xmm4, xmm4, 4
	INST				k5, xmm5, xmm5, 5
	INST				k6, xmm6, xmm6, 6
	INST				k7, xmm7, xmm7, 7
endm

InstLatX64_2ymmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, ymm0, ymm0, 0
	INST				k1, ymm1, ymm1, 1
	INST				k2, ymm2, ymm2, 2
	INST				k3, ymm3, ymm3, 3
	INST				k4, ymm4, ymm4, 4
	INST				k5, ymm5, ymm5, 5
	INST				k6, ymm6, ymm6, 6
	INST				k7, ymm7, ymm7, 7
endm

InstLatX64_2zmmi2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0, zmm0, zmm0, 0
	INST				k1, zmm1, zmm1, 1
	INST				k2, zmm2, zmm2, 2
	INST				k3, zmm3, zmm3, 3
	INST				k4, zmm4, zmm4, 4
	INST				k5, zmm5, zmm5, 5
	INST				k6, zmm6, zmm6, 6
	INST				k7, zmm7, zmm7, 7
endm

InstLatX64_2xmmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, xmm0, xmm0, 0
	INST				k1{k1}, xmm1, xmm1, 1
	INST				k2{k2}, xmm2, xmm2, 2
	INST				k3{k3}, xmm3, xmm3, 3
	INST				k4{k4}, xmm4, xmm4, 4
	INST				k5{k5}, xmm5, xmm5, 5
	INST				k6{k6}, xmm6, xmm6, 6
	INST				k7{k7}, xmm7, xmm7, 7
endm

InstLatX64_2ymmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, ymm0, ymm0, 0
	INST				k1{k1}, ymm1, ymm1, 1
	INST				k2{k2}, ymm2, ymm2, 2
	INST				k3{k3}, ymm3, ymm3, 3
	INST				k4{k4}, ymm4, ymm4, 4
	INST				k5{k5}, ymm5, ymm5, 5
	INST				k6{k6}, ymm6, ymm6, 6
	INST				k7{k7}, ymm7, ymm7, 7
endm

InstLatX64_2zmmik2k_port macro INST, DOMAINSTART, DOMAINEND
	INST				k0{k1}, zmm0, zmm0, 0
	INST				k1{k1}, zmm1, zmm1, 1
	INST				k2{k2}, zmm2, zmm2, 2
	INST				k3{k3}, zmm3, zmm3, 3
	INST				k4{k4}, zmm4, zmm4, 4
	INST				k5{k5}, zmm5, zmm5, 5
	INST				k6{k6}, zmm6, zmm6, 6
	INST				k7{k7}, zmm7, zmm7, 7
endm

InstLatX64_gpr32_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, eax
	INST			ymm9, edx
	INST			ymm10, ebx
	INST			ymm11, r8d
	INST			ymm12, r9d
	INST			ymm13, r10d
	INST			ymm14, r11d
	INST			ymm15, r12d
endm

InstLatX64_gpr64_2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, rax
	INST			ymm9, rdx
	INST			ymm10, rbx
	INST			ymm11, r8
	INST			ymm12, r9
	INST			ymm13, r10
	INST			ymm14, r11
	INST			ymm15, r12
endm

InstLatX64_gpr32_2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, eax
	INST			zmm9, edx
	INST			zmm10, ebx
	INST			zmm11, r8d
	INST			zmm12, r9d
	INST			zmm13, r10d
	INST			zmm14, r11d
	INST			zmm15, r12d
endm

InstLatX64_gpr64_2zmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8, rax
	INST			zmm9, rdx
	INST			zmm10, rbx
	INST			zmm11, r8
	INST			zmm12, r9
	INST			zmm13, r10
	INST			zmm14, r11
	INST			zmm15, r12
endm

InstLatX64_gpr32_2kxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}, eax
	INST			xmm9{k1}, edx
	INST			xmm10{k1}, ebx
	INST			xmm11{k1}, r8d
	INST			xmm12{k1}, r9d
	INST			xmm13{k1}, r10d
	INST			xmm14{k1}, r11d
	INST			xmm15{k1}, r12d
endm

InstLatX64_gpr64_2kxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}, rax
	INST			xmm9{k1}, rdx
	INST			xmm10{k1}, rbx
	INST			xmm11{k1}, r8
	INST			xmm12{k1}, r9
	INST			xmm13{k1}, r10
	INST			xmm14{k1}, r11
	INST			xmm15{k1}, r12
endm

InstLatX64_gpr32_2kymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}, eax
	INST			ymm9{k1}, edx
	INST			ymm10{k1}, ebx
	INST			ymm11{k1}, r8d
	INST			ymm12{k1}, r9d
	INST			ymm13{k1}, r10d
	INST			ymm14{k1}, r11d
	INST			ymm15{k1}, r12d
endm

InstLatX64_gpr64_2kymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}, rax
	INST			ymm9{k1}, rdx
	INST			ymm10{k1}, rbx
	INST			ymm11{k1}, r8
	INST			ymm12{k1}, r9
	INST			ymm13{k1}, r10
	INST			ymm14{k1}, r11
	INST			ymm15{k1}, r12
endm

InstLatX64_gpr32_2kzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8{k1}, eax
	INST			zmm9{k1}, edx
	INST			zmm10{k1}, ebx
	INST			zmm11{k1}, r8d
	INST			zmm12{k1}, r9d
	INST			zmm13{k1}, r10d
	INST			zmm14{k1}, r11d
	INST			zmm15{k1}, r12d
endm

InstLatX64_gpr64_2kzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8{k1}, rax
	INST			zmm9{k1}, rdx
	INST			zmm10{k1}, rbx
	INST			zmm11{k1}, r8
	INST			zmm12{k1}, r9
	INST			zmm13{k1}, r10
	INST			zmm14{k1}, r11
	INST			zmm15{k1}, r12
endm

InstLatX64_gpr32_2zkxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}{z}, eax
	INST			xmm9{k1}{z}, edx
	INST			xmm10{k1}{z}, ebx
	INST			xmm11{k1}{z}, r8d
	INST			xmm12{k1}{z}, r9d
	INST			xmm13{k1}{z}, r10d
	INST			xmm14{k1}{z}, r11d
	INST			xmm15{k1}{z}, r12d
endm

InstLatX64_gpr64_2zkxmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8{k1}{z}, rax
	INST			xmm9{k1}{z}, rdx
	INST			xmm10{k1}{z}, rbx
	INST			xmm11{k1}{z}, r8
	INST			xmm12{k1}{z}, r9
	INST			xmm13{k1}{z}, r10
	INST			xmm14{k1}{z}, r11
	INST			xmm15{k1}{z}, r12
endm

InstLatX64_gpr32_2zkymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}{z}, eax
	INST			ymm9{k1}{z}, edx
	INST			ymm10{k1}{z}, ebx
	INST			ymm11{k1}{z}, r8d
	INST			ymm12{k1}{z}, r9d
	INST			ymm13{k1}{z}, r10d
	INST			ymm14{k1}{z}, r11d
	INST			ymm15{k1}{z}, r12d
endm

InstLatX64_gpr64_2zkymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8{k1}{z}, rax
	INST			ymm9{k1}{z}, rdx
	INST			ymm10{k1}{z}, rbx
	INST			ymm11{k1}{z}, r8
	INST			ymm12{k1}{z}, r9
	INST			ymm13{k1}{z}, r10
	INST			ymm14{k1}{z}, r11
	INST			ymm15{k1}{z}, r12
endm

InstLatX64_gpr32_2zkzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8{k1}{z}, eax
	INST			zmm9{k1}{z}, edx
	INST			zmm10{k1}{z}, ebx
	INST			zmm11{k1}{z}, r8d
	INST			zmm12{k1}{z}, r9d
	INST			zmm13{k1}{z}, r10d
	INST			zmm14{k1}{z}, r11d
	INST			zmm15{k1}{z}, r12d
endm

InstLatX64_gpr64_2zkzmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			zmm8{k1}{z}, rax
	INST			zmm9{k1}{z}, rdx
	INST			zmm10{k1}{z}, rbx
	INST			zmm11{k1}{z}, r8
	INST			zmm12{k1}{z}, r9
	INST			zmm13{k1}{z}, r10
	INST			zmm14{k1}{z}, r11
	INST			zmm15{k1}{z}, r12
endm
