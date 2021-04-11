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

InstLatX64_m256ymmi2ymm_port macro INST, DOMAINSTART, DOMAINEND
	INST			ymm8, ymm8, ymmword ptr [memop1 - 80h], 0
	INST			ymm9, ymm9, ymmword ptr [memop1 - 60h], 0
	INST			ymm10, ymm10, ymmword ptr [memop1 - 40h], 0
	INST			ymm11, ymm11, ymmword ptr [memop1 - 20h], 0
	INST			ymm12, ymm12, ymmword ptr [memop1 + 00h], 0
	INST			ymm13, ymm13, ymmword ptr [memop1 + 20h], 0
	INST			ymm14, ymm14, ymmword ptr [memop1 + 40h], 0
	INST			ymm15, ymm15, ymmword ptr [memop1 + 60h], 0
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

InstLatX64_ymmi2xmm_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmm8, ymm8, 0
	INST			xmm9, ymm9, 0
	INST			xmm10, ymm10, 0
	INST			xmm11, ymm11, 0
	INST			xmm12, ymm12, 0
	INST			xmm13, ymm13, 0
	INST			xmm14, ymm14, 0
	INST			xmm15, ymm15, 0
endm

InstLatX64_ymmi2m128_port macro INST, DOMAINSTART, DOMAINEND
	INST			xmmword ptr [memop0 + 00h], ymm8, 0
	INST			xmmword ptr [memop0 + 00h], ymm9, 0
	INST			xmmword ptr [memop0 + 00h], ymm10, 0
	INST			xmmword ptr [memop0 + 00h], ymm11, 0
	INST			xmmword ptr [memop0 + 00h], ymm12, 0
	INST			xmmword ptr [memop0 + 00h], ymm13, 0
	INST			xmmword ptr [memop0 + 00h], ymm14, 0
	INST			xmmword ptr [memop0 + 00h], ymm15, 0
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