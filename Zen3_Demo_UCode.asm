.data

memop0	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop1	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop2	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
memop3	dq				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.code 

zen3_domain macro REGISTER, DOMAIN
	IF DOMAIN EQ 1
		vpor				REGISTER, REGISTER, REGISTER
	ELSEIF DOMAIN EQ 2
		vorpd				REGISTER, REGISTER, REGISTER
	ENDIF
endm

zen3_noop_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

IFIDNI <INST>, <fsqrt32>
	fsqrt
ELSEIFIDNI <INST>, <fsqrt64>
	fsqrt
ELSEIFIDNI <INST>, <fsqrt80>
	fsqrt
ELSE
	INST
ENDIF
	zen3_domain		xmm15, DOMAINEND
endm

zen3_x87_2op1_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

IFIDNI <INST>, <fdiv32>
	fdiv			st(0), st
ELSEIFIDNI <INST>, <fdiv64>
	fdiv			st(0), st
ELSEIFIDNI <INST>, <fdiv80>
	fdiv			st(0), st
ELSE
	INST			st(0), st
ENDIF
	zen3_domain		xmm15, DOMAINEND
endm

zen3_mm2xmm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

	INST			xmm15, mm0

	zen3_domain		xmm15, DOMAINEND
endm


zen3_2xmm2xmm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

	INST			xmm15, xmm15, xmm15

	zen3_domain		xmm15, DOMAINEND
endm

zen3_2xmmi2xmm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

	INST			xmm15, xmm15, xmm15, 0

	zen3_domain		xmm15, DOMAINEND
endm

zen3_ymmi2ymm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		ymm15, DOMAINSTART

	INST			ymm15, ymm15, 0

	zen3_domain		ymm15, DOMAINEND
endm


zen3_2ymm2ymm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		ymm15, DOMAINSTART

	INST			ymm15, ymm15, ymm15

	zen3_domain		ymm15, DOMAINEND
endm

zen3_2ymmi2ymm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		ymm15, DOMAINSTART

	INST			ymm15, ymm15, ymm15, 0

	zen3_domain		ymm15, DOMAINEND
endm

zen3_xmm2ymm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

	INST			ymm15, xmm15

	zen3_domain		ymm15, DOMAINEND
endm

zen3_ymm2xmm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		ymm15, DOMAINSTART

	INST			xmm15, ymm15

	zen3_domain		xmm15, DOMAINEND
endm

zen3_xmm2xmm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		xmm15, DOMAINSTART

	INST			xmm15, xmm15

	zen3_domain		xmm15, DOMAINEND
endm

zen3_ymm2ymm_lat_m macro INST, DOMAINSTART, DOMAINEND
	zen3_domain		ymm15, DOMAINSTART

	INST			ymm15, ymm15

	zen3_domain		ymm15, DOMAINEND
endm

zen3_vpermq_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vpermq				ymm15, ymm15, 0

	;vpbroadcastq		ymm0, xmm0
	;vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	vpbroadcastq		ymm4, xmm4
	vpbroadcastq		ymm5, xmm5
	
	;fst					st(7)
	fst					st(6)
	fst					st(5)
	fst					st(4)
	fst					st(3)
	fst					st(2)

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11
endm

zen3_vpermq_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vpermq				ymm15, ymm15, 0

	;vpabsd				ymm0, ymm0
	;vpabsd				ymm1, ymm1
	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1

	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
endm

zen3_vpermq_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vpermq				ymm15, ymm15, 0

	;vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vpermq_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpermq_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpermq_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpermd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vpermd				ymm15, ymm15, ymm15

	;vpbroadcastq		ymm0, xmm0
	;vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3

	;fcom				st(7)
	fcom				st(6)
	fcom				st(5)
	fcom				st(4)
	fcom				st(3)
	fcom				st(2)
	fcom				st(1)
	fcom				st(0)
	
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11
endm

zen3_vpermd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vpermd				ymm15, ymm15, ymm15

	;vpabsd				ymm0, ymm0
	;vpabsd				ymm1, ymm1
	;vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vpermd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vpermd				ymm15, ymm15, ymm15

	;vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
	vpmuludq			ymm12, ymm12, ymm12
	vpmuludq			ymm13, ymm13, ymm13

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
	vpmuludq			ymm12, ymm12, ymm12
	vpmuludq			ymm13, ymm13, ymm13
endm

zen3_vpermd_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpermd_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpermd_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpmovzxbq_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vpmovzxbq			ymm15, xmm15

	;vpbroadcastq		ymm0, xmm0
	;vpbroadcastq		ymm1, xmm1
	;vpbroadcastq		ymm2, xmm2
	;vpbroadcastq		ymm3, xmm3

	;fcom				st(7)
	;fcom				st(6)
	;fcom				st(5)
	;fcom				st(4)

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vpmovzxbq_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vpmovzxbq			ymm15, xmm15

	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vpmovzxbq_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vpmovzxbq			ymm15, xmm15

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	;vpsrlvq				ymm2, ymm2, ymm2
	;vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vpmovzxbq_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpmovzxbq_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpmovzxbq_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpclmulqdq_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	;
	vpclmulqdq			ymm15, ymm15, ymm15, 0

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3

REPEAT 0
	fcom					st(1)
ENDM

	;vminpd				ymm4, ymm4, ymm4
	;vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vpclmulqdq_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vpclmulqdq			ymm15, ymm15, ymm15, 0

	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	
	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3

	;vminpd				ymm4, ymm4, ymm4
	;vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vpclmulqdq_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vpclmulqdq			ymm15, ymm15, ymm15, 0

	;vpsrlvq				ymm0, ymm0, ymm0
	;vpsllvq				ymm1, ymm1, ymm1
	;vpsrlvq				ymm2, ymm2, ymm2
	;vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vpclmulqdq_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpclmulqdq_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vpclmulqdq_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vmpsadbw_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vmpsadbw 			ymm15, ymm15, ymm15, 0

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	;vpbroadcastq		ymm4, xmm4

	;fcom				st(1)
	;fcom				st(1)
	fcom				st(1)
	fcom				st(1)
	fcom				st(1)

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
endm

zen3_vmpsadbw_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vmpsadbw 			ymm15, ymm15, ymm15, 0

	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm9, ymm9

	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm9, ymm9

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
endm

zen3_vmpsadbw_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vmpsadbw 			ymm15, ymm15, ymm15, 0

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	;vpsrlvq				ymm0, ymm0, ymm0
	;vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vmpsadbw_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vmpsadbw_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vmpsadbw_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdppd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vdppd 				xmm15, xmm15, xmm15, 0

	;vpbroadcastq		ymm0, xmm0
	;vpbroadcastq		ymm1, xmm1
	;vpbroadcastq		ymm2, xmm2
	;vpbroadcastq		ymm3, xmm3
	;vpbroadcastq		ymm4, xmm4
	;;vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3

	;fcom				st(1)
	;fcom				st(1)
	;fcom				st(1)
	;fcom				st(1)
	;fcom				st(1)
	;
	;fcom				st(1)
	fcom				st(1)
	fcom				st(1)
	fcom				st(1)

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	
	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
endm

zen3_vdppd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vdppd 				xmm15, xmm15, xmm15, 0

	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm10, ymm10
	vpabsd				ymm11, ymm11
	
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm10, ymm10
	vpabsd				ymm11, ymm11
	
	;vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm10, ymm10
	vpabsd				ymm11, ymm11

	;vminpd				ymm4, ymm4, ymm4
	;vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
endm

zen3_vdppd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vdppd 				xmm15, xmm15, xmm15, 0

	;vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm4, ymm4, ymm4
	vpsllvq				ymm5, ymm5, ymm5

	;vpmuludq			ymm6, ymm6, ymm6
	;vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	;vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm4, ymm4, ymm4
	vpsllvq				ymm5, ymm5, ymm5

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm4, ymm4, ymm4
	vpsllvq				ymm5, ymm5, ymm5

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vdppd_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdppd_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdppd_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_movq2dq_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	movq2dq 				ymm15, ymm15, ymm15

	;vpbroadcastq		ymm0, xmm0
	;vpbroadcastq		ymm1, xmm1

	fcom				st(1)
	;fcom				st(1)

	;vminpd				ymm4, ymm4, ymm4
	;vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_movq2dq_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	movq2dq 				ymm15, ymm15, ymm15

	;vpabsd				ymm0, ymm0
	;vpabsd				ymm1, ymm1
	;vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	
	;vminpd				ymm4, ymm4, ymm4
	;vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_movq2dq_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	movq2dq 				ymm15, ymm15, ymm15

	;vpsrlvq				ymm0, ymm0, ymm0
	;vpsllvq				ymm1, ymm1, ymm1
	;vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm4, ymm4, ymm4
	vpsllvq				ymm5, ymm5, ymm5

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_movq2dq_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_movq2dq_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_movq2dq_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vphaddd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vphaddd			ymm15, ymm15, ymm15

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	
	;fcom				st(0)
	;fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vphaddd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vphaddd			ymm15, ymm15, ymm15

	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3

	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	;vpabsd				ymm3, ymm3

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vphaddd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vphaddd			ymm15, ymm15, ymm15

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	;vpsllvq				ymm1, ymm1, ymm1
	;vpsrlvq				ymm2, ymm2, ymm2
	;vpsllvq				ymm3, ymm3, ymm3

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vphaddd_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vphaddd_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vphaddd_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vhaddpd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vhaddpd			ymm15, ymm15, ymm15

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	
	;fcom				st(0)
	;fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
	
	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vhaddpd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vhaddpd			ymm15, ymm15, ymm15

	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3

	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	;vpabsd				ymm3, ymm3

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	;vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7
endm

zen3_vhaddpd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vhaddpd			ymm15, ymm15, ymm15

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	;vpsllvq				ymm1, ymm1, ymm1
	;vpsrlvq				ymm2, ymm2, ymm2
	;vpsllvq				ymm3, ymm3, ymm3

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vhaddpd_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vhaddpd_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vhaddpd_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtps2pd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vcvtps2pd			ymm15, xmm15

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	;vpbroadcastq		ymm10, xmm10

	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm8, ymm8, ymm8
	;vminpd				ymm9, ymm9, ymm9
endm

zen3_vcvtps2pd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vcvtps2pd			ymm15, xmm15

	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
	vpabsd				ymm10, ymm10
	;vpabsd				ymm11, ymm11

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	vminpd				ymm4, ymm4, ymm4
	vminpd				ymm5, ymm5, ymm5
	vminpd				ymm6, ymm6, ymm6
	vminpd				ymm7, ymm7, ymm7

	;vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
endm

zen3_vcvtps2pd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vcvtps2pd			ymm15, xmm15

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	;vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	;vpsrlvq				ymm2, ymm2, ymm2
	;vpsllvq				ymm3, ymm3, ymm3

	vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vcvtps2pd_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtps2pd_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtps2pd_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtpd2ps_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	vcvtpd2ps			xmm15, ymm15

	vpbroadcastq		ymm0, xmm0
	vpbroadcastq		ymm1, xmm1
	vpbroadcastq		ymm2, xmm2
	vpbroadcastq		ymm3, xmm3
	vpbroadcastq		ymm4, xmm4
	;vpbroadcastq		ymm5, xmm5
	
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)
	fcom				st(0)

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	vminpd				ymm10, ymm10, ymm10
	vminpd				ymm11, ymm11, ymm11

	vminpd				ymm8, ymm8, ymm8
	vminpd				ymm9, ymm9, ymm9
	;vminpd				ymm12, ymm12, ymm12
	;vminpd				ymm13, ymm13, ymm13
endm

zen3_vcvtpd2ps_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	vcvtpd2ps				xmm15, ymm15

	;vpabsd				ymm0, ymm0
	;vpabsd				ymm1, ymm1
	;vpabsd				ymm0, ymm0
	;vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1

	;vminpd				ymm2, ymm2, ymm2
	;vminpd				ymm3, ymm3, ymm3
	;vminpd				ymm2, ymm2, ymm2
	;vminpd				ymm3, ymm3, ymm3
	;vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
	vminpd				ymm2, ymm2, ymm2
	vminpd				ymm3, ymm3, ymm3
endm

zen3_vcvtpd2ps_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	vcvtpd2ps				xmm15, ymm15

	;vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11

	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1
	vpsrlvq				ymm2, ymm2, ymm2
	vpsllvq				ymm3, ymm3, ymm3
	vpsrlvq				ymm0, ymm0, ymm0
	vpsllvq				ymm1, ymm1, ymm1

	;vpmuludq			ymm6, ymm6, ymm6
	vpmuludq			ymm7, ymm7, ymm7
	vpmuludq			ymm8, ymm8, ymm8
	vpmuludq			ymm9, ymm9, ymm9
	vpmuludq			ymm10, ymm10, ymm10
	vpmuludq			ymm11, ymm11, ymm11
endm

zen3_vcvtpd2ps_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtpd2ps_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vcvtpd2ps_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivpd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivpd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivpd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivpd_port0_m macro INST, DOMAINSTART, DOMAINEND
	vdivpd			ymm15, ymm15, ymm15
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
endm
	;vbroadcastsd	ymm4, xmm4
endm

zen3_vdivpd_port1_m macro INST, DOMAINSTART, DOMAINEND
	vdivpd			ymm15, ymm15, ymm15

REPEAT 2
	ftst
endm
endm

zen3_vdivpd_port01_m macro INST, DOMAINSTART, DOMAINEND
	vdivpd			ymm15, ymm15, ymm15

REPEAT 6
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
endm
	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_vdivps_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivps_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivps_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivps_port0_m macro INST, DOMAINSTART, DOMAINEND
	vdivps			ymm15, ymm15, ymm15
REPEAT 2
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
endm
	vbroadcastsd	ymm4, xmm4
	vbroadcastsd	ymm5, xmm5
endm

zen3_vdivps_port1_m macro INST, DOMAINSTART, DOMAINEND
	vdivps			ymm15, ymm15, ymm15

REPEAT 9
	fcom			st(0)
endm
endm

zen3_vdivps_port01_m macro INST, DOMAINSTART, DOMAINEND
	vdivps			ymm15, ymm15, ymm15

REPEAT 4
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
endm
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	;vpabsd				ymm3, ymm3

	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_vdivsd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivsd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivsd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivsd_port0_m macro INST, DOMAINSTART, DOMAINEND
	vdivsd			xmm15, xmm15, xmm15
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3

	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3

	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3

	;vbroadcastsd	ymm4, xmm4
endm

zen3_vdivsd_port1_m macro INST, DOMAINSTART, DOMAINEND
	vdivsd			xmm15, xmm15, xmm15

REPEAT 2
	ftst
endm
endm

zen3_vdivsd_port01_m macro INST, DOMAINSTART, DOMAINEND
	vdivsd			xmm15, xmm15, xmm15

REPEAT 6
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
endm
	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_vdivss_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivss_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivss_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vdivss_port0_m macro INST, DOMAINSTART, DOMAINEND
	vdivss			xmm15, xmm15, xmm15
REPEAT 2
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
endm
	vbroadcastsd	ymm4, xmm4
	vbroadcastsd	ymm5, xmm5
endm

zen3_vdivss_port1_m macro INST, DOMAINSTART, DOMAINEND
	vdivss			xmm15, xmm15, xmm15

REPEAT 9
	fcom			st(0)
endm
endm

zen3_vdivss_port01_m macro INST, DOMAINSTART, DOMAINEND
	vdivss			xmm15, xmm15, xmm15

REPEAT 4
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
endm
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	;vpabsd				ymm3, ymm3

	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_vsqrtpd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtpd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtpd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtpd_port0_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtpd			ymm15, ymm15
REPEAT 5
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM

	;vbroadcastsd	ymm4, xmm4
endm

zen3_vsqrtpd_port1_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtpd			ymm15, ymm15
REPEAT 19
	fcom			st(0)
endm
endm

zen3_vsqrtpd_port01_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtpd			ymm15, ymm15

REPEAT 9
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
endm

zen3_vsqrtps_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtps_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtps_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtps_port0_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtps			ymm15, ymm15
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_vsqrtps_port1_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtps			ymm15, ymm15

REPEAT 13
	fcom			st(0)
endm
endm

zen3_vsqrtps_port01_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtps				ymm15, ymm15

REPEAT 6
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_vsqrtsd_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtsd_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtsd_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtsd_port0_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtsd			xmm15, xmm15, xmm15
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
endm
	vbroadcastsd	ymm4, xmm4
endm

zen3_vsqrtsd_port1_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtsd			xmm15, xmm15, xmm15

REPEAT 19
	fcom			st(0)
endm
endm

zen3_vsqrtsd_port01_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtsd			xmm15, xmm15, xmm15

REPEAT 9
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
endm

zen3_vsqrtss_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtss_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtss_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_vsqrtss_port0_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtss			xmm15, xmm15, xmm15
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_vsqrtss_port1_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtss			xmm15, xmm15, xmm15

REPEAT 13
	fcom			st(0)
endm
endm

zen3_vsqrtss_port01_m macro INST, DOMAINSTART, DOMAINEND
	vsqrtss			xmm15, xmm15, xmm15

REPEAT 6
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
endm

zen3_fsqrt32_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt32_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt32_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt32_port0_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_fsqrt32_port1_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
	fincstp
REPEAT 13
	fcom			st(0)
endm
	fdecstp
endm

zen3_fsqrt32_port01_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt

REPEAT 5
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
endm

zen3_fsqrt64_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt64_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt64_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt64_port0_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
REPEAT 5
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	;vbroadcastsd	ymm0, xmm0
	;vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_fsqrt64_port1_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
	fincstp
REPEAT 15
	fcom			st(0)
endm
	fdecstp
endm

zen3_fsqrt64_port01_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt

REPEAT 9
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	vpabsd				ymm4, ymm4
	vpabsd				ymm5, ymm5
endm

zen3_fsqrt80_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt80_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt80_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fsqrt80_port0_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
REPEAT 5
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
endm

zen3_fsqrt80_port1_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt
	fincstp
REPEAT 21
	fcom			st(0)
endm
	fdecstp
endm

zen3_fsqrt80_port01_m macro INST, DOMAINSTART, DOMAINEND
	fsqrt

REPEAT 11
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	;vpabsd				ymm4, ymm4
	;pabsd				ymm5, ymm5
endm

zen3_fdiv32_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv32_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv32_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv32_port0_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
REPEAT 2
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
endm

zen3_fdiv32_port1_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
	fincstp
REPEAT 9
	fcom			st(0)
endm
	fdecstp
endm

zen3_fdiv32_port01_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st

REPEAT 5
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM
endm

zen3_fdiv64_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv64_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv64_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv64_port0_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	;vbroadcastsd	ymm0, xmm0
	;vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_fdiv64_port1_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
	fincstp
REPEAT 12
	fcom			st(0)
endm
	fdecstp
endm

zen3_fdiv64_port01_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st

REPEAT 6
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM
endm

zen3_fdiv80_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv80_port01_23_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv80_port03_12_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_fdiv80_port0_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
REPEAT 3
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	vbroadcastsd	ymm2, xmm2
	vbroadcastsd	ymm3, xmm3
ENDM
	vbroadcastsd	ymm0, xmm0
	vbroadcastsd	ymm1, xmm1
	;vbroadcastsd	ymm2, xmm2
endm

zen3_fdiv80_port1_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st
	fincstp
REPEAT 14
	fcom			st(0)
endm
	fdecstp
endm

zen3_fdiv80_port01_m macro INST, DOMAINSTART, DOMAINEND
	fdiv st(0), st

REPEAT 7
	vpabsd				ymm0, ymm0
	vpabsd				ymm1, ymm1
	vpabsd				ymm2, ymm2
	vpabsd				ymm3, ymm3
ENDM

	;vpabsd				ymm4, ymm4
	;vpabsd				ymm5, ymm5
endm

zen3_movq2dq_port0_1_23_m macro INST, DOMAINSTART, DOMAINEND
	;movq2dq 			xmm15, mm0
	movdq2q 			mm0, xmm15
	;
	;movq2dq 			xmm14, mm1
	movdq2q 			mm1, xmm14
	;
	;movq2dq 			xmm13, mm2
	movdq2q 			mm2, xmm13
	;;
	;movq2dq 			xmm12, mm3
	;;movdq2q 			mm4, xmm12
	;
	;movq2dq 			xmm11, mm4
	;
	;movq2dq 			xmm10, mm5
	;
	;movq2dq 			xmm9, mm6
	;
	;movq2dq 			xmm8, mm7

	;fcom				st(1)
	;fcom				st(1)
	;fcom				st(1)

	;paddd				xmm0, xmm0
	;paddd				xmm1, xmm1
	;paddd				xmm2, xmm2
	;paddd				xmm3, xmm3

	;paddd				xmm0, xmm0
	;paddd				xmm1, xmm1
	;paddd				xmm2, xmm2
	;paddd				xmm4, xmm

	;paddd				xmm0, xmm0
	;paddd				xmm1, xmm1
	;paddd				xmm2, xmm2
	;paddd				xmm3, xmm3

	;movd				xmm1, eax
	;movd				xmm2, edx
	;movd				xmm3, ebx

	movd				mm1, eax
	movd				mm2, edx
	movd				mm3, ebx

	;psrlq				xmm0, 0
	;psllq				xmm1, 1
	;psrlq				xmm2, 2
	;psllq				xmm3, 3
	;psrlq				xmm4, 4
	;psllq				xmm5, 5

	;movd				eax, xmm1
	;movd				edx, xmm2
	;movd				ebx, xmm3

	;movd				eax, mm4
	;movd				edx, mm5
	;movd				ebx, mm6

	;pmuludq				xmm6, xmm6
	;pmuludq				xmm7, xmm7
	;pmuludq				xmm8, xmm8
	;pmuludq				xmm9, xmm9
	;pmuludq				xmm10, xmm10
	;pmuludq				xmm11, xmm11

endm

zen3_movq2dq_port01_23_m macro INST, DOMAINSTART, DOMAINEND
	movq2dq 			xmm15, mm0

	paddd				xmm0, xmm0
	paddd				xmm1, xmm1
	paddd				xmm2, xmm2
	paddd				xmm3, xmm3

	paddd				xmm4, xmm4
	paddd				xmm5, xmm5
	;paddd				xmm6, xmm6
	;paddd				xmm7, xmm7
endm

zen3_movq2dq_port03_12_m macro INST, DOMAINSTART, DOMAINEND
	movq2dq 			xmm15, mm0
	movdq2q 			mm1, xmm14

	psrlq				xmm0, 0
	psllq				xmm1, 1
	psrlq				xmm2, 2
	psllq				xmm3, 3
	psrlq				xmm4, 4
	psllq				xmm5, 5

	;pmuludq				xmm6, xmm6
	;pmuludq				xmm7, xmm7
	;pmuludq				xmm8, xmm8
	pmuludq				xmm9, xmm9
	pmuludq				xmm10, xmm10
	pmuludq				xmm11, xmm11
endm

zen3_movq2dq_port0_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_movq2dq_port1_m macro INST, DOMAINSTART, DOMAINEND
endm

zen3_movq2dq_port01_m macro INST, DOMAINSTART, DOMAINEND
endm

test_m macro FUNC, M1, INST, DOMAINSTART, DOMAINEND
LOCAL looptest
FUNC proc
	push			r15
	push			r14
	push			r13
	push			r12
	push			rbx
	push			rdi
	push			rsi
	finit
	vzeroupper
	mov				eax, 1
	vcvtsi2ss		xmm15, xmm15, rax
	vbroadcastss	ymm15, xmm15

	fnstcw word ptr [memop0]
	xor eax, eax
	mov ax, word ptr [memop0]
	and ax, 0fcffh
	IFIDNI <INST>, <fsqrt32>
	ELSEIFIDNI <INST>, <fdiv32>
	ELSEIFIDNI <INST>, <fsqrt64>
		or ax, 0200h
	ELSEIFIDNI <INST>, <fdiv64>
		or ax, 0200h
	ELSEIFIDNI <INST>, <fdiv80>
		or ax, 0300h
	ELSEIFIDNI <INST>, <fsqrt80>
		or ax, 0300h
	ENDIF
	mov word ptr [memop0 + 02h], ax
	fldcw word ptr [memop0 + 02h]
	fld1
	fld1

	xor				eax, eax
	cpuid
	rdtscp

	shl				rdx, 32
	or				rax, rdx
	mov				rsi, rax

	mov				rcx, 100000
align 16
looptest:
	M1				INST, DOMAINSTART, DOMAINEND

	sub				rcx, 1
	jnz				looptest

	xor				eax, eax
	cpuid
	rdtscp

	shl				rdx, 32
	or				rax, rdx
	sub				rax, rsi

	pop				rsi
	pop				rdi
	pop				rbx
	pop				r12
	pop				r13
	pop				r14
	pop				r15
	ret
FUNC endp
endm

zen3_ucoded_wrap macro INST, OPERANDS
	test_m		Zen3_&INST&_lat,		zen3_&OPERANDS&_lat_m,		INST, 0, 0
	test_m		Zen3_&INST&_IIDomain,	zen3_&OPERANDS&_lat_m,		INST, 1, 1
	test_m		Zen3_&INST&_FFDomain,	zen3_&OPERANDS&_lat_m,		INST, 2, 2
	test_m		Zen3_&INST&_IFDomain,	zen3_&OPERANDS&_lat_m,		INST, 1, 2
	test_m		Zen3_&INST&_FIDomain,	zen3_&OPERANDS&_lat_m,		INST, 2, 1
	test_m		Zen3_&INST&_Port0_1_23,	zen3_&INST&_port0_1_23_m,	INST, 0, 0
	test_m		Zen3_&INST&_Port01_23,	zen3_&INST&_port01_23_m,	INST, 0, 0
	test_m		Zen3_&INST&_Port03_12,	zen3_&INST&_port03_12_m,	INST, 0, 0
	test_m		Zen3_&INST&_Port0,		zen3_&INST&_port0_m,		INST, 0, 0
	test_m		Zen3_&INST&_Port1,		zen3_&INST&_port1_m,		INST, 0, 0
	test_m		Zen3_&INST&_Port01,		zen3_&INST&_port01_m,		INST, 0, 0
endm

zen3_ucoded_wrap	vpermq,				ymmi2ymm
zen3_ucoded_wrap	vpermd,				2ymm2ymm
zen3_ucoded_wrap	vpmovzxbq,			xmm2ymm
zen3_ucoded_wrap	vpclmulqdq,			2ymmi2ymm
zen3_ucoded_wrap	vmpsadbw,			2ymmi2ymm
zen3_ucoded_wrap	vdppd,				2xmmi2xmm
zen3_ucoded_wrap	movq2dq,			mm2xmm
zen3_ucoded_wrap	vphaddd,			2ymm2ymm
zen3_ucoded_wrap	vhaddpd,			2ymm2ymm
zen3_ucoded_wrap	vcvtps2pd,			xmm2ymm
zen3_ucoded_wrap	vcvtpd2ps,			ymm2xmm
zen3_ucoded_wrap	vdivpd,				2ymm2ymm
zen3_ucoded_wrap	vdivps,				2ymm2ymm
zen3_ucoded_wrap	vdivsd,				2xmm2xmm
zen3_ucoded_wrap	vdivss,				2xmm2xmm

zen3_ucoded_wrap	vsqrtpd,			ymm2ymm
zen3_ucoded_wrap	vsqrtps,			ymm2ymm
zen3_ucoded_wrap	vsqrtsd,			2xmm2xmm
zen3_ucoded_wrap	vsqrtss,			2xmm2xmm

zen3_ucoded_wrap	fsqrt32,			noop
zen3_ucoded_wrap	fsqrt64,			noop
zen3_ucoded_wrap	fsqrt80,			noop

zen3_ucoded_wrap	fdiv32,				x87_2op1
zen3_ucoded_wrap	fdiv64,				x87_2op1
zen3_ucoded_wrap	fdiv80,				x87_2op1

end