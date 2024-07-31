zen5_8clks_port01_m macro
	REPEAT 2
	pmullw				mm0, mm0
	pmullw				mm1, mm1
	pmullw				mm2, mm2
	pmullw				mm3, mm3
	pmullw				mm4, mm4
	pmullw				mm5, mm5
	pmullw				mm6, mm6
	pmullw				mm7, mm7
	endm
endm

zen5_8clks_port23_m macro
	REPEAT 2
	psllw				mm0, 1
	psllw				mm1, 1
	psllw				mm2, 1
	psllw				mm3, 1
	psllw				mm4, 1
	psllw				mm5, 1
	psllw				mm6, 1
	psllw				mm7, 1
	endm
endm

zen5_8clks_port12_m macro
	REPEAT 2
	packsswb			mm0, mm0
	packsswb			mm1, mm1
	packsswb			mm2, mm2
	packsswb			mm3, mm3
	packsswb			mm4, mm4
	packsswb			mm5, mm5
	packsswb			mm6, mm6
	packsswb			mm7, mm7
	endm
endm

zen5_8clks_port03_m macro
	REPEAT 2
	korb					k0, k0, k1
	korb					k1, k1, k2
	korb					k2, k2, k3
	korb					k3, k3, k4
	korb					k4, k4, k5
	korb					k5, k5, k6
	korb					k6, k6, k7
	korb					k7, k7, k0
	endm
endm

zen5_8clks_port0123_m macro
	REPEAT 4
	paddb					mm0, mm0
	paddb					mm1, mm1
	paddb					mm2, mm2
	paddb					mm3, mm3
	paddb					mm4, mm4
	paddb					mm5, mm5
	paddb					mm6, mm6
	paddb					mm7, mm7
	endm
endm

zen5_8clks_port1_m macro
	REPEAT 1
	kmovb					k0, eax
	kmovb					k1, eax
	kmovb					k2, eax
	kmovb					k3, eax
	kmovb					k4, eax
	kmovb					k5, eax
	kmovb					k6, eax
	kmovb					k7, eax
	endm
endm

zen5_8clks_port45_m macro
	REPEAT 2
	movq				[memop1 - 080h], mm0
	movq				[memop1 - 060h], mm1
	movq				[memop1 - 040h], mm2
	movq				[memop1 - 020h], mm3
	movq				[memop1 + 000h], mm4
	movq				[memop1 + 020h], mm5
	movq				[memop1 + 040h], mm6
	movq				[memop1 + 060h], mm7
	endm
endm

zen5_8clks_tern_m macro
	vpternlogq				zmm0, zmm1, zmm2, 0
	vpternlogq				zmm1, zmm2, zmm3, 1
	vpternlogq				zmm2, zmm3, zmm4, 2
	vpternlogq				zmm3, zmm4, zmm5, 3
	vpternlogq				zmm4, zmm5, zmm6, 4
	vpternlogq				zmm5, zmm6, zmm7, 5
	vpternlogq				zmm6, zmm7, zmm0, 6
	vpternlogq				zmm7, zmm0, zmm1, 7
endm

zen5_8clks_LDs_m macro
	REPEAT 2
	movq				mm0, [memop1 - 080h] 
	movq				mm1, [memop1 - 060h] 
	movq				mm2, [memop1 - 040h] 
	movq				mm3, [memop1 - 020h] 
	movq				mm4, [memop1 + 000h] 
	movq				mm5, [memop1 + 020h] 
	movq				mm6, [memop1 + 040h] 
	movq				mm7, [memop1 + 060h] 
	endm
endm
