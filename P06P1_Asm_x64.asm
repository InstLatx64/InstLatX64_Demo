data SEGMENT PAGE

data ENDS

INST_REPEAT EQU 1000

.code 

_BZHI macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bzhi rax, rax, rcx ; P1
	ENDM
ENDM

_BEXTR macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bextr rax, rax, rcx ; P1
	ENDM
ENDM

_BT macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bt rax, rcx ; P1
		adc eax, 0
	ENDM
ENDM

_BTC macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		btc rax, rcx ; P1
	ENDM
ENDM

_BTS macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bts rax, rcx ; P1
	ENDM
ENDM

_BTR macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		btr rax, rcx ; P1
	ENDM
ENDM

_SHLX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shlx rax, rax, rcx ; P06
		;shlx rbx, rbx, rcx ; P06
		;shlx r8, r8, rcx ; P06
	ENDM
ENDM

_SHL_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shl rax, cl ; 2*P06
		;shl rbx, cl ; 2*P06
		;shl r8, cl ; P06
	ENDM
ENDM

_SHL_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shl rax, 2 ; P06
	ENDM
ENDM

_SHL_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shl rax, 1 ; 2*P06
	ENDM
ENDM

_SHRX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shrx rax, rax, rcx ; P06
		;shrx rbx, rbx, rcx ; P06
		;shrx r8, r8, rcx ; P06
	ENDM
ENDM

_SHR_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shr rax, cl ; 2*P06
		;shr rbx, cl ; 2*P06
		;shr r8, cl  ; 2*P06
	ENDM
ENDM

_SHR_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shr rax, 2 ; P06
	ENDM
ENDM

_SHR_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		shr rax, 1 ; 2*P06
	ENDM
ENDM

_SARX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		sarx rax, rax, rcx ; P06
		;sarx rbx, rbx, rcx ; P06
		;sarx r8, r8, rcx ; P06
	ENDM
ENDM

_SAR_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		sar rax, cl ; 2*P06
		;sar rbx, cl ; 2*P06
		;sar r8, cl  ; 2*P06
	ENDM
ENDM

_SAR_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		sar rax, 2 ; P06
	ENDM
ENDM

_SAR_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		sar rax, 1 ; 2*P06
	ENDM
ENDM

_RORX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rorx rcx, rcx, 59 ; P06
	ENDM
ENDM

_ROR_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		ror rax, cl ; 2*P06
		;ror rbx, cl ; 2*P06
		;ror r8, cl  ; 2*P06
	ENDM
ENDM

_ROR_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		ror rax, 2 ; P06
	ENDM
ENDM

_ROR_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		ror rax, 1 ; 2*P06
	ENDM
ENDM

_RCR_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcr rax, cl ; 2*P06
	ENDM
ENDM

_RCR_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcr rax, 2 ; P06
	ENDM
ENDM

_RCR_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcr rax, 1 ; 2*P06
	ENDM
ENDM

_ROL_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rol rax, cl ; 2*P06
		;rol rbx, cl ; 2*P06
		;rol r8, cl  ; 2*P06
	ENDM
ENDM

_ROL_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rol rax, 2 ; P06
	ENDM
ENDM

_ROL_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rol rax, 1 ; 2*P06
	ENDM
ENDM

_RCL_CL macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcl rax, cl ; 2*P06
	ENDM
ENDM

_RCL_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcl rax, 2 ; P06
	ENDM
ENDM

_RCL_IMPL1 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		rcl rax, 1 ; 2*P06
	ENDM
ENDM

_ADC_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		adc rax, 1 ; P06
	ENDM
ENDM

_SBB_IMM8 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		sbb rax, 1 ; P06
	ENDM
ENDM

_ADOX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		adox rax, rcx ; P06
	ENDM
ENDM

_ADCX macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		adcx rax, rcx ; P06
	ENDM
ENDM

_CMOVBE macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		cmovbe rax, rcx ; P06
	ENDM
ENDM

_CMOVNBE macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		cmovnbe rax, rcx ; P06
	ENDM
ENDM

_CMOVZ macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		cmovz rax, rcx ; P06
	ENDM
ENDM

_CMOVNZ macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		cmovnz rax, rcx ; P06
	ENDM
ENDM

_BSWAP macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bswap rax ; P1+P06
	ENDM
ENDM

_POPCNT macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		popcnt rcx, rcx ; P1
	ENDM
ENDM

_LZCNT macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		lzcnt rcx, rcx ; P1
	ENDM
ENDM

_TZCNT macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		tzcnt rcx, rcx ; P1
	ENDM
ENDM

_BSR macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bsr rcx, rcx ; P1
	ENDM
ENDM

_BSF macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		bsf rcx, rcx ; P1
	ENDM
ENDM

_CRC32 macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		crc32 rcx, rcx ; P1
	ENDM
ENDM

_PDEP macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		pdep rax, rax, rcx ; P1
	ENDM
ENDM

_PEXT macro I1, I2
		mov I1, I2
	REPEAT INST_REPEAT
		pext rax, rax, rcx ; P1
	ENDM
ENDM

TIMED2 macro PNAME, CORE, I1, I2
PNAME proc
	push			r15
	push			r14
	push			rbx
	push			rdi
	push			rsi

	mfence
	rdtscp
	lfence
	shl				rdx, 20h
	or				rax, rdx
	mov				r15, rax

	mov				rdx, INST_REPEAT
	xor				eax, eax
	xor				ebx, eax
	xor				ecx, ecx

LOOPLABEL:
	CORE I1, I2

	dec rdx
	jnz LOOPLABEL


	mfence
	rdtscp
	lfence
	shl				rdx, 20h
	or				rax, rdx
	sub				rax, r15

	pop				rsi
	pop				rdi
	pop				rbx
	pop				r14
	pop				r15
	ret
PNAME endp
endm

wrap macro INST, MCRO, INITREG
	TIMED2	 _&INST&_MOV_R&INITREG&_M1025_TIME,				MCRO,		R&INITREG&,		-1025
	TIMED2	 _&INST&_MOV_E&INITREG&_M1025_TIME,				MCRO,		E&INITREG&,		-1025
	TIMED2	 _&INST&_MOV_R&INITREG&_M1024_TIME,				MCRO,		R&INITREG&,		-1024
	TIMED2	 _&INST&_MOV_E&INITREG&_M1024_TIME,				MCRO,		E&INITREG&,		-1024
	TIMED2	 _&INST&_MOV_R&INITREG&_M513_TIME,				MCRO,		R&INITREG&,		-513
	TIMED2	 _&INST&_MOV_E&INITREG&_M513_TIME,				MCRO,		E&INITREG&,		-513
	TIMED2	 _&INST&_MOV_R&INITREG&_M512_TIME,				MCRO,		R&INITREG&,		-512
	TIMED2	 _&INST&_MOV_E&INITREG&_M512_TIME,				MCRO,		E&INITREG&,		-512
	TIMED2	 _&INST&_MOV_R&INITREG&_511_TIME,				MCRO,		R&INITREG&,		511
	TIMED2	 _&INST&_MOV_E&INITREG&_511_TIME,				MCRO,		E&INITREG&,		511
	TIMED2	 _&INST&_MOV_R&INITREG&_512_TIME,				MCRO,		R&INITREG&,		512
	TIMED2	 _&INST&_MOV_E&INITREG&_512_TIME,				MCRO,		E&INITREG&,		512
	TIMED2	 _&INST&_MOV_R&INITREG&_1023_TIME,				MCRO,		R&INITREG&,		1023
	TIMED2	 _&INST&_MOV_E&INITREG&_1023_TIME,				MCRO,		E&INITREG&,		1023
	TIMED2	 _&INST&_MOV_R&INITREG&_1024_TIME,				MCRO,		R&INITREG&,		1024
	TIMED2	 _&INST&_MOV_E&INITREG&_1024_TIME,				MCRO,		E&INITREG&,		1024
endm

wrap BT_RAX_RCX,			_BT,		CX
wrap BT_RAX_RCX,			_BT,		AX
wrap BTC_RAX_RCX,			_BTC,		CX
wrap BTC_RAX_RCX,			_BTC,		AX
wrap BTR_RAX_RCX,			_BTR,		CX
wrap BTR_RAX_RCX,			_BTR,		AX
wrap BTS_RAX_RCX,			_BTS,		CX
wrap BTS_RAX_RCX,			_BTS,		AX
wrap BZHI_RAX_RAX_RCX,		_BZHI,		CX
wrap BZHI_RAX_RAX_RCX,		_BZHI,		AX
wrap BEXTR_RAX_RAX_RCX,		_BEXTR,		CX
wrap BEXTR_RAX_RAX_RCX,		_BEXTR,		AX

wrap SHLX_RAX_RAX_RCX,		_SHLX,		CX
wrap SHLX_RAX_RAX_RCX,		_SHLX,		AX
wrap SHL_RAX_CL,			_SHL_CL,	CX
wrap SHL_RAX_CL,			_SHL_CL,	AX
wrap SHL_RAX_IMM8,			_SHL_IMM8,	AX
wrap SHL_RAX_IMPL1,			_SHL_IMPL1,	AX

wrap SHRX_RAX_RAX_RCX,		_SHRX,		CX
wrap SHRX_RAX_RAX_RCX,		_SHRX,		AX
wrap SHR_RAX_CL,			_SHR_CL,	CX
wrap SHR_RAX_CL,			_SHR_CL,	AX
wrap SHR_RAX_IMM8,			_SHR_IMM8,	AX
wrap SHR_RAX_IMPL1,			_SHR_IMPL1,	AX

wrap SARX_RAX_RAX_RCX,		_SARX,		CX
wrap SARX_RAX_RAX_RCX,		_SARX,		AX
wrap SAR_RAX_CL,			_SAR_CL,	CX
wrap SAR_RAX_CL,			_SAR_CL,	AX
wrap SAR_RAX_IMM8,			_SAR_IMM8,	AX
wrap SAR_RAX_IMPL1,			_SAR_IMPL1,	AX

wrap RORX_RCX_RCX_IMM8,		_RORX,		CX

wrap ROR_RAX_CL,			_ROR_CL,	CX
wrap ROR_RAX_CL,			_ROR_CL,	AX
wrap ROR_RAX_IMM8,			_ROR_IMM8,	AX
wrap ROR_RAX_IMPL1,			_ROR_IMPL1,	AX

wrap RCR_RAX_CL,			_RCR_CL,	CX
wrap RCR_RAX_CL,			_RCR_CL,	AX
wrap RCR_RAX_IMM8,			_RCR_IMM8,	AX
wrap RCR_RAX_IMPL1,			_RCR_IMPL1,	AX

wrap ROL_RAX_CL,			_ROL_CL,	CX
wrap ROL_RAX_CL,			_ROL_CL,	AX
wrap ROL_RAX_IMM8,			_ROL_IMM8,	AX
wrap ROL_RAX_IMPL1,			_ROL_IMPL1,	AX

wrap RCL_RAX_CL,			_RCL_CL,	CX
wrap RCL_RAX_CL,			_RCL_CL,	AX
wrap RCL_RAX_IMM8,			_RCL_IMM8,	AX
wrap RCL_RAX_IMPL1,			_RCL_IMPL1,	AX

wrap ADC_RAX_IMM8,			_ADC_IMM8,	AX
wrap SBB_RAX_IMM8,			_SBB_IMM8,	AX

wrap ADCX_RAX_RCX,			_ADCX,		CX
wrap ADCX_RAX_RCX,			_ADCX,		AX
wrap ADOX_RAX_RCX,			_ADOX,		CX
wrap ADOX_RAX_RCX,			_ADOX,		AX

wrap CMOVBE_RAX_RCX,		_CMOVBE,	CX
wrap CMOVNBE_RAX_RCX,		_CMOVNBE,	CX
wrap CMOVZ_RAX_RCX,			_CMOVZ,		CX
wrap CMOVNZ_RAX_RCX,		_CMOVNZ,	CX

wrap CMOVBE_RAX_RCX,		_CMOVBE,	AX
wrap CMOVNBE_RAX_RCX,		_CMOVNBE,	AX
wrap CMOVZ_RAX_RCX,			_CMOVZ,		AX
wrap CMOVNZ_RAX_RCX,		_CMOVNZ,	AX

wrap BSWAP_RAX,				_BSWAP,		AX
wrap POPCNT_RCX_RCX,		_POPCNT,	CX
wrap LZCNT_RCX_RCX,			_LZCNT,		CX
wrap TZCNT_RCX_RCX,			_TZCNT,		CX

wrap BSR_RCX_RCX,			_BSR,		CX
wrap BSF_RCX_RCX,			_BSF,		CX

wrap CRC32_RCX_RCX,			_CRC32,		CX
wrap PDEP_RAX_RAX_RCX,		_PDEP,		CX
wrap PDEP_RAX_RAX_RCX,		_PDEP,		AX
wrap PEXT_RAX_RAX_RCX,		_PEXT,		CX
wrap PEXT_RAX_RAX_RCX,		_PEXT,		AX




END