zen4_8clks_port01_m macro
	REPEAT 2
	paddsb				mm0, mm0
	paddsb				mm1, mm1
	paddsb				mm2, mm2
	paddsb				mm3, mm3
	paddsb				mm4, mm4
	paddsb				mm5, mm5
	paddsb				mm6, mm6
	paddsb				mm7, mm7
	endm
endm

zen4_8clks_port23_m macro
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

zen4_8clks_port12_m macro
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

zen4_8clks_port123_m macro
	REPEAT 3
	punpcklbw			mm0, mm0
	punpcklbw			mm1, mm1
	punpcklbw			mm2, mm2
	punpcklbw			mm3, mm3
	punpcklbw			mm4, mm4
	punpcklbw			mm5, mm5
	punpcklbw			mm6, mm6
	punpcklbw			mm7, mm7
	endm
endm

zen4_8clks_port0123_m macro
	REPEAT 4
	por					mm0, mm0
	por					mm1, mm1
	por					mm2, mm2
	por					mm3, mm3
	por					mm4, mm4
	por					mm5, mm5
	por					mm6, mm6
	por					mm7, mm7
	endm
endm

zen4_8clks_port45_m macro
	REPEAT 1
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

zen4_8clks_LDs_m macro
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

zen4_8clks_port1_m macro
	REPEAT 1
	pinsrw				mm0, eax, 0
	pinsrw				mm1, eax, 0
	pinsrw				mm2, eax, 0
	pinsrw				mm3, eax, 0
	pinsrw				mm4, eax, 0
	pinsrw				mm5, eax, 0
	pinsrw				mm6, eax, 0
	pinsrw				mm7, eax, 0
	endm
endm

zen4_8clks_tern_m macro
	vpternlogq				zmm0, zmm1, zmm2, 0
	vpternlogq				zmm1, zmm2, zmm3, 1
	vpternlogq				zmm2, zmm3, zmm4, 2
	vpternlogq				zmm3, zmm4, zmm5, 3
	vpternlogq				zmm4, zmm5, zmm6, 4
	vpternlogq				zmm5, zmm6, zmm7, 5
	vpternlogq				zmm6, zmm7, zmm0, 6
	vpternlogq				zmm7, zmm0, zmm1, 7
endm
