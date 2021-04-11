.data

one_dp		dq	3ff0000000000000h
shuf		dd	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

.code 

;based on Intel® 64 and IA-32 Architectures Optimization Reference Manual, 
;18.21 SERVERS WITH A SINGLE FMA UNIT
;https://software.intel.com/content/dam/develop/public/us/en/documents/64-ia-32-architectures-optimization-manual.pdf

fma_shuffle_tpt proc 
	vbroadcastsd		zmm0, [one_dp]
	vbroadcastsd		zmm1, [one_dp]
	vbroadcastsd		zmm2, [one_dp]
	vbroadcastsd		zmm3, [one_dp]
	vbroadcastsd		zmm4, [one_dp]
	vbroadcastsd		zmm5, [one_dp]
	vbroadcastsd		zmm6, [one_dp]
	vbroadcastsd		zmm7, [one_dp]
	vbroadcastsd		zmm8, [one_dp]
	vbroadcastsd		zmm9, [one_dp]
	vbroadcastsd		zmm10, [one_dp]
	vbroadcastsd		zmm11, [one_dp]
	vmovdqu32			zmm12, [shuf]
	vmovdqu32			zmm13, [shuf]
	vmovdqu32			zmm14, [shuf]
	vmovdqu32			zmm15, [shuf]
	vmovdqu32			zmm16, [shuf]
	vmovdqu32			zmm17, [shuf]
	vmovdqu32			zmm18, [shuf]
	vmovdqu32			zmm19, [shuf]
	vmovdqu32			zmm20, [shuf]
	vmovdqu32			zmm21, [shuf]
	vmovdqu32			zmm22, [shuf]
	vmovdqu32			zmm23, [shuf]
	vmovdqu32			zmm30, [shuf]
loop1:
	vfmadd231pd			zmm0, zmm0, zmm0
	vfmadd231pd			zmm1, zmm1, zmm1
	vfmadd231pd			zmm2, zmm2, zmm2
	vfmadd231pd			zmm3, zmm3, zmm3
	vfmadd231pd			zmm4, zmm4, zmm4
	vfmadd231pd			zmm5, zmm5, zmm5
	vfmadd231pd			zmm6, zmm6, zmm6
	vfmadd231pd			zmm7, zmm7, zmm7
	vfmadd231pd			zmm8, zmm8, zmm8
	vfmadd231pd			zmm9, zmm9, zmm9
	vfmadd231pd			zmm10, zmm10, zmm10
	vfmadd231pd			zmm11, zmm11, zmm11
	vpermd				zmm12, zmm30, zmm30
	vpermd				zmm13, zmm30, zmm30
	vpermd				zmm14, zmm30, zmm30
	vpermd				zmm15, zmm30, zmm30
	vpermd				zmm16, zmm30, zmm30
	vpermd				zmm17, zmm30, zmm30
	vpermd				zmm18, zmm30, zmm30
	vpermd				zmm19, zmm30, zmm30
	vpermd				zmm20, zmm30, zmm30
	vpermd				zmm21, zmm30, zmm30
	vpermd				zmm22, zmm30, zmm30
	vpermd				zmm23, zmm30, zmm30
	dec rcx
	jg loop1

	ret
fma_shuffle_tpt endp

fma_only_tpt proc 
	vbroadcastsd		zmm0, [one_dp]
	vbroadcastsd		zmm1, [one_dp]
	vbroadcastsd		zmm2, [one_dp]
	vbroadcastsd		zmm3, [one_dp]
	vbroadcastsd		zmm4, [one_dp]
	vbroadcastsd		zmm5, [one_dp]
	vbroadcastsd		zmm6, [one_dp]
	vbroadcastsd		zmm7, [one_dp]
	vbroadcastsd		zmm8, [one_dp]
	vbroadcastsd		zmm9, [one_dp]
	vbroadcastsd		zmm10, [one_dp]
	vbroadcastsd		zmm11, [one_dp]
loop1:
	vfmadd231pd			zmm0, zmm0, zmm0
	vfmadd231pd			zmm1, zmm1, zmm1
	vfmadd231pd			zmm2, zmm2, zmm2
	vfmadd231pd			zmm3, zmm3, zmm3
	vfmadd231pd			zmm4, zmm4, zmm4
	vfmadd231pd			zmm5, zmm5, zmm5
	vfmadd231pd			zmm6, zmm6, zmm6
	vfmadd231pd			zmm7, zmm7, zmm7
	vfmadd231pd			zmm8, zmm8, zmm8
	vfmadd231pd			zmm9, zmm9, zmm9
	vfmadd231pd			zmm10, zmm10, zmm10
	vfmadd231pd			zmm11, zmm11, zmm11
	dec rcx
	jg loop1

	ret
fma_only_tpt endp

end