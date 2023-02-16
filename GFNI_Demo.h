#pragma once

//Some non-cryptographical use of GFNI's GF2P8AFFINE instruction
// 8 bit shift and rotate mimicing the Intel's intrinsics:
// _(mm|mm256|mm512)(|_mask|_maskz)_(srli|srl|srai|sra|slli|sll|ror|rol)_epi8
//
//Based on 
//-- Geoffrey Langdale's blogpost:
//https://branchfree.org/2019/05/29/why-ice-lake-is-important-a-bit-bashers-perspective/
//-- Wojciech Mu³a's blogpost
//http://0x80.pl/articles/avx512-galois-field-for-bit-shuffling.html
//-- Marcus D. R. Klarqvist, Wojciech Mu³a, Daniel Lemire: Efficient Computation of Positional Population Counts Using SIMD Instructions
//https://arxiv.org/abs/1911.02696
//-- A list of "out-of-band" uses for the GF2P8AFFINEQB instruction I haven't seen documented elsewhere
//https://gist.github.com/animetosho/6cb732ccb5ecd86675ca0a442b3c0622

#define _GFNI_DEMO_VERSION		0x0101

#define _GFNI_DEMO_IDENT		0x0102040810204080
#define _GFNI_DEMO_REVBIT		0x8040201008040201
#define _GFNI_DEMO_BCST			0x0101010101010101
#define _GFNI_DEMO_PREFXOR		0x0103070f1f3f7fff
#define _GFNI_DEMO_TZCNT		0xaaccf0ff00000000

#define _GFNI_DEMO_SLL(i)		((0x0102040810204080 >> (i)) & (0x0101010101010101ULL * (0xff >> (i))))
#define _GFNI_DEMO_SRL(i)		((0x0102040810204080 << (i)) & (0x0101010101010101ULL * ((0xff << (i)) & 0xff)))
#define _GFNI_DEMO_SLA(i)		(_GFNI_DEMO_SLL(i) | ((0x0101010101010101ULL << (64 - (8 * i))) & (0ULL - (i > 0))))
#define _GFNI_DEMO_SRA(i)		(_GFNI_DEMO_SRL(i) | ((0x8080808080808080ULL >> (64 - (8 * i))) & (0ULL - (i > 0))))
#define _GFNI_DEMO_ROL(i)		(_GFNI_DEMO_SRL(8 - i) | _GFNI_DEMO_SLL(i))
#define _GFNI_DEMO_ROR(i)		(_GFNI_DEMO_SLL(8 - i) | _GFNI_DEMO_SRL(i))

/* Logical shift right by imm, if imm > 7, result is 0 */

#define _mm_srli_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm_mask_srli_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm_maskz_srli_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)

#define _mm256_srli_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm256_mask_srli_gfni_epi8(s, k, a, cnt)	_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm256_maskz_srli_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(cnt)), 0)

#define _mm512_srli_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm512_mask_srli_gfni_epi8(s, k, a, cnt)	_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SRL(cnt)), 0)
#define _mm512_maskz_srli_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SRL(cnt)), 0)

/* Logical shift right by b[2:0], if b[63:0] > 7, result is 0 */

#define _mm_srl_gfni_epi8(a, b)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm_mask_srl_gfni_epi8(s, k, a, b)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm_maskz_srl_gfni_epi8(k, a, b)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)

#define _mm256_srl_gfni_epi8(a, b)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm256_mask_srl_gfni_epi8(s, k, a, b)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm256_maskz_srl_gfni_epi8(k, a, b)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)

#define _mm512_srl_gfni_epi8(a, b)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm512_mask_srl_gfni_epi8(s, k, a, b)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)
#define _mm512_maskz_srl_gfni_epi8(k, a, b)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SRL(_mm_cvtsi128_si32(b))), 0)

/* Arithmetical shift right by imm, if imm > 7, result is filled with MSB */

#define _mm_srai_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm_mask_srai_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm_maskz_srai_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)

#define _mm256_srai_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm256_mask_srai_gfni_epi8(s, k, a, cnt)	_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm256_maskz_srai_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(cnt)), 0)

#define _mm512_srai_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm512_mask_srai_gfni_epi8(s, k, a, cnt)	_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SRA(cnt)), 0)
#define _mm512_maskz_srai_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SRA(cnt)), 0)

/* Arithmetical shift right by b[2:0], if b[63:0] > 7, result is filled with MSB */

#define _mm_sra_gfni_epi8(a, b)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm_mask_sra_gfni_epi8(s, k, a, b)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm_maskz_sra_gfni_epi8(k, a, b)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)

#define _mm256_sra_gfni_epi8(a, b)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm256_mask_sra_gfni_epi8(s, k, a, b)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm256_maskz_sra_gfni_epi8(k, a, b)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)

#define _mm512_sra_gfni_epi8(a, b)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm512_mask_sra_gfni_epi8(s, k, a, b)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)
#define _mm512_maskz_sra_gfni_epi8(k, a, b)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SRA(_mm_cvtsi128_si32(b))), 0)

/* Logical shift left by imm, if imm > 7, result is 0 */

#define _mm_slli_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm_mask_slli_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm_maskz_slli_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)

#define _mm256_slli_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm256_mask_slli_gfni_epi8(s, k, a, cnt)	_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm256_maskz_slli_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(cnt)), 0)

#define _mm512_slli_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm512_mask_slli_gfni_epi8(s, k, a, cnt)	_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SLL(cnt)), 0)
#define _mm512_maskz_slli_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SLL(cnt)), 0)

/* Logical shift left by b[2:0], if b[63:0] > 7, result is 0 */

#define _mm_sll_gfni_epi8(a, b)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm_mask_sll_gfni_epi8(s, k, a, b)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm_maskz_sll_gfni_epi8(k, a, b)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)

#define _mm256_sll_gfni_epi8(a, b)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm256_mask_sll_gfni_epi8(s, k, a, b)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm256_maskz_sll_gfni_epi8(k, a, b)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)

#define _mm512_sll_gfni_epi8(a, b)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm512_mask_sll_gfni_epi8(s, k, a, b)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)
#define _mm512_maskz_sll_gfni_epi8(k, a, b)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SLL(_mm_cvtsi128_si32(b))), 0)

/* Arithmetical shift left by imm, if imm > 7, result is filled with LSB */

#define _mm_slai_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm_mask_slai_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm_maskz_slai_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)

#define _mm256_slai_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm256_mask_slai_gfni_epi8(s, k, a, cnt)	_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm256_maskz_slai_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(cnt)), 0)

#define _mm512_slai_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm512_mask_slai_gfni_epi8(s, k, a, cnt)	_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SLA(cnt)), 0)
#define _mm512_maskz_slai_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SLA(cnt)), 0)

/* Arithmetical shift left by b[2:0], if b[63:0] > 7, result is filled with LSB */

#define _mm_sla_gfni_epi8(a, b)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm_mask_sla_gfni_epi8(s, k, a, b)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm_maskz_sla_gfni_epi8(k, a, b)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)

#define _mm256_sla_gfni_epi8(a, b)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm256_mask_sla_gfni_epi8(s, k, a, b)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm256_maskz_sla_gfni_epi8(k, a, b)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)

#define _mm512_sla_gfni_epi8(a, b)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm512_mask_sla_gfni_epi8(s, k, a, b)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)
#define _mm512_maskz_sla_gfni_epi8(k, a, b)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_SLA(_mm_cvtsi128_si32(b))), 0)

/* Rotate right by imm8 mod 8 */

#define _mm_ror_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm_mask_ror_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm_maskz_ror_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)

#define _mm256_ror_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm256_mask_ror_gfni_epi8(s, k, a, cnt)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm256_maskz_ror_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_ROR(cnt)), 0)

#define _mm512_ror_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm512_mask_ror_gfni_epi8(s, k, a, cnt)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_ROR(cnt)), 0)
#define _mm512_maskz_ror_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_ROR(cnt)), 0)

/* Rotate left by imm8 mod 8 */

#define _mm_rol_gfni_epi8(a, cnt)					_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm_mask_rol_gfni_epi8(s, k, a, cnt)		_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm_maskz_rol_gfni_epi8(k, a, cnt)			_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)

#define _mm256_rol_gfni_epi8(a, cnt)				_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm256_mask_rol_gfni_epi8(s, k, a, cnt)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm256_maskz_rol_gfni_epi8(k, a, cnt)		_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_ROL(cnt)), 0)

#define _mm512_rol_gfni_epi8(a, cnt)				_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm512_mask_rol_gfni_epi8(s, k, a, cnt)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_ROL(cnt)), 0)
#define _mm512_maskz_rol_gfni_epi8(k, a, cnt)		_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_ROL(cnt)), 0)

/* Reverse bits within bytes */
/* In  : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */
/* Out : MSB B0 B1 B2 B3 B4 B5 B6 B7 LSB */

#define _mm_revbit_epi8(a)							_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_REVBIT), 0)
#define _mm_mask_revbit_epi8(s, k, a)				_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_REVBIT), 0)
#define _mm_maskz_revbit_epi8(k, a)					_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_REVBIT), 0)

#define _mm256_revbit_epi8(a)						_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_REVBIT), 0)
#define _mm256_mask_revbit_epi8(s, k, a)			_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_REVBIT), 0)
#define _mm256_maskz_revbit_epi8(k, a)				_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_REVBIT), 0)

#define _mm512_revbit_epi8(a)						_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_REVBIT), 0)
#define _mm512_mask_revbit_epi8(s, k, a)			_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_REVBIT), 0)
#define _mm512_maskz_revbit_epi8(k, a)				_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_REVBIT), 0)

/* Broadcast b-th bit within bytes */
/* In  : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */
/* Out : MSB Bb Bb Bb Bb Bb Bb Bb Bb LSB */

#define _mm_bcstbit_epi8(a, b)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_BCST << b), 0)
#define _mm_mask_bcstbit_epi8(s, k, a, b)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_BCST << b), 0)
#define _mm_maskz_bcstbit_epi8(k, a, b)				_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_BCST << b), 0)

#define _mm256_bcstbit_epi8(a, b)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_BCST << b), 0)
#define _mm256_mask_bcstbit_epi8(s, k, a, b)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_BCST << b), 0)
#define _mm256_maskz_bcstbit_epi8(k, a, b)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_BCST << b), 0)

#define _mm512_bcstbit_epi8(a, b)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_BCST << b), 0)
#define _mm512_mask_bcstbit_epi8(s, k, a, b)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_BCST << b), 0)
#define _mm512_maskz_bcstbit_epi8(k, a, b)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_BCST << b), 0)

/* Prefix xor in bytes */
/* In  : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */
/* ------------------------------------- */
/*           B0                          */
/*           ^                           */
/*           B1 B0                       */
/*           ^  ^                        */
/*           B2 B1 B0                    */
/*           ^  ^  ^                     */
/*           B3 B2 B1 B0                 */
/*           ^  ^  ^  ^                  */
/*           B4 B3 B2 B1 B0              */
/*           ^  ^  ^  ^  ^               */
/*           B5 B4 B3 B2 B1 B0           */
/*           ^  ^  ^  ^  ^  ^            */
/*           B6 B5 B4 B3 B2 B1 B0        */
/*           ^  ^  ^  ^  ^  ^  ^         */
/* Out : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */

#define _mm_prefix_xor_epi8(a)						_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)
#define _mm_mask_prefix_xor_epi8(s, k, a)			_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)
#define _mm_maskz_prefix_xor_epi8(k, a)				_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)

#define _mm256_prefix_xor_epi8(a)					_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)
#define _mm256_mask_prefix_xor_epi8(s, k, a)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)
#define _mm256_maskz_prefix_xor_epi8(k, a)			_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_PREFXOR), 0)

#define _mm512_prefix_xor_epi8(a)					_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_PREFXOR), 0)
#define _mm512_mask_prefix_xor_epi8(s, k, a)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_PREFXOR), 0)
#define _mm512_maskz_prefix_xor_epi8(k, a)			_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_PREFXOR), 0)

/* Rotating bit in qwords around center  */
/*                                       */
/*           In[i,j] -> Out[j,7-i]       */
/*                                       */
/* In  : MSB 77 76 75 74 73 72 71 70     */
/*           67 66 65 64 63 62 61 60     */
/*           57 56 55 54 53 52 51 50     */
/*           47 46 45 44 43 42 41 40     */
/*           37 36 35 34 33 32 31 30     */
/*           27 26 25 24 23 22 21 20     */
/*           17 16 15 14 13 12 11 10     */
/*           07 06 05 04 03 02 01 00 LSB */
/*                                       */
/* Out : MSB 07 17 27 37 47 57 67 77     */
/*           06 16 26 36 46 56 66 76     */
/*           05 15 25 35 45 55 65 75     */
/*           04 14 24 34 44 54 64 74     */
/*           03 13 23 33 43 53 63 73     */
/*           02 12 22 32 42 52 62 72     */
/*           01 11 21 31 41 51 61 71     */
/*           00 10 20 30 40 50 60 70 LSB */

#define _mm_rotate_8x8(a)							_mm_gf2p8affine_epi64_epi8(_mm_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)
#define _mm_mask_rotate_8x8(s, k, a)				_mm_mask_gf2p8affine_epi64_epi8(s, k, _mm_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)
#define _mm_maskz_rotate_8x8(k, a)					_mm_maskz_gf2p8affine_epi64_epi8(k, _mm_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)

#define _mm256_rotate_8x8(a)						_mm256_gf2p8affine_epi64_epi8(_mm256_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)
#define _mm256_mask_rotate_8x8(s, k, a)				_mm256_mask_gf2p8affine_epi64_epi8(s, k, _mm256_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)
#define _mm256_maskz_rotate_8x8(k, a)				_mm256_maskz_gf2p8affine_epi64_epi8(k, _mm256_set1_epi64x(_GFNI_DEMO_REVBIT), a, 0)

#define _mm512_rotate_8x8(a)						_mm512_gf2p8affine_epi64_epi8(_mm512_set1_epi64(_GFNI_DEMO_REVBIT), a, 0)
#define _mm512_mask_rotate_8x8(s, k, a)				_mm512_mask_gf2p8affine_epi64_epi8(s, k, _mm512_set1_epi64(_GFNI_DEMO_REVBIT), a, 0)
#define _mm512_maskz_rotate_8x8(k, a)				_mm512_maskz_gf2p8affine_epi64_epi8(k, _mm512_set1_epi64(_GFNI_DEMO_REVBIT), a, 0)

/* Mirror bits in qwords, through the    */
/* 07-16-25-34-43-52-61-70 diagonal axis */
/*                                       */
/*           In[i,j] -> Out[7-j,7-i]     */
/*                                       */
/* In  : MSB 77 76 75 74 73 72 71 70     */
/*           67 66 65 64 63 62 61 60     */
/*           57 56 55 54 53 52 51 50     */
/*           47 46 45 44 43 42 41 40     */
/*           37 36 35 34 33 32 31 30     */
/*           27 26 25 24 23 22 21 20     */
/*           17 16 15 14 13 12 11 10     */
/*           07 06 05 04 03 02 01 00 LSB */
/*                                       */
/* Out : MSB 00 10 20 30 40 50 60 70     */
/*           01 11 21 31 41 51 61 71     */
/*           02 12 22 32 42 52 62 72     */
/*           03 13 23 33 43 53 63 73     */
/*           04 14 24 34 44 54 64 74     */
/*           05 15 25 35 45 55 65 75     */
/*           06 16 26 36 46 56 66 76     */
/*           07 17 27 37 47 57 67 77 LSB */

#define _mm_mirror_8x8(a)							_mm_gf2p8affine_epi64_epi8(_mm_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)
#define _mm_mask_mirror_8x8(s, k, a)				_mm_mask_gf2p8affine_epi64_epi8(s, k, _mm_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)
#define _mm_maskz_mirror_8x8(k, a)					_mm_maskz_gf2p8affine_epi64_epi8(k, _mm_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)

#define _mm256_mirror_8x8(a)						_mm256_gf2p8affine_epi64_epi8(_mm256_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)
#define _mm256_mask_mirror_8x8(s, k, a)				_mm256_mask_gf2p8affine_epi64_epi8(s, k, _mm256_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)
#define _mm256_maskz_mirror_8x8(k, a)				_mm256_maskz_gf2p8affine_epi64_epi8(k, _mm256_set1_epi64x(_GFNI_DEMO_IDENT), a, 0)

#define _mm512_mirror_8x8(a)						_mm512_gf2p8affine_epi64_epi8(_mm512_set1_epi64(_GFNI_DEMO_IDENT), a, 0)
#define _mm512_mask_mirror_8x8(s, k, a)				_mm512_mask_gf2p8affine_epi64_epi8(s, k, _mm512_set1_epi64(_GFNI_DEMO_IDENT), a, 0)
#define _mm512_maskz_mirror_8x8(k, a)				_mm512_maskz_gf2p8affine_epi64_epi8(k, _mm512_set1_epi64(_GFNI_DEMO_IDENT), a, 0)

/* Multiplication 8x8 bits in qwords */
/*                                   */
/*              7                    */
/* res[i][j] = XOR(a[i][k],b[k][j])  */
/*             k=0                   */

#define _mm_multiplication_8x8(a, b)				_mm_gf2p8affine_epi64_epi8(_mm_mirror_8x8(b), a, 0)
#define _mm_mask_multiplication_8x8(s, k, a, b)		_mm_mask_gf2p8affine_epi64_epi8(s, k, _mm_mirror_8x8(b), a, 0)
#define _mm_maskz_multiplication_8x8(k, a, b)		_mm_maskz_gf2p8affine_epi64_epi8(k, _mm_mirror_8x8(b), a, 0)

#define _mm256_multiplication_8x8(a, b)				_mm256_gf2p8affine_epi64_epi8(_mm256_mirror_8x8(b), a, 0)
#define _mm256_mask_multiplication_8x8(s, k, a, b)	_mm256_mask_gf2p8affine_epi64_epi8(s, k, _mm256_mirror_8x8(b), a, 0)
#define _mm256_maskz_multiplication_8x8(k, a, b)	_mm256_maskz_gf2p8affine_epi64_epi8(k, _mm256_mirror_8x8(b), a, 0)

#define _mm512_multiplication_8x8(a, b)				_mm512_gf2p8affine_epi64_epi8(_mm512_mirror_8x8(b), a, 0)
#define _mm512_mask_multiplication_8x8(s, k, a, b)	_mm512_mask_gf2p8affine_epi64_epi8(s, k, _mm512_mirror_8x8(b), a, 0)
#define _mm512_maskz_multiplication_8x8(k, a, b)	_mm512_maskz_gf2p8affine_epi64_epi8(k, _mm512_mirror_8x8(b), a, 0)

/* Inverse bits within result bytes, conjunction with other operations */
/* In  : MSB  B7  B6  B5  B4  B3  B2  B1  B0 LSB*/
/* Out : MSB ~B7 ~B6 ~B5 ~B4 ~B3 ~B2 ~B1 ~B0 LSB*/

#define _mm_inverse_epi8(a)							_mm_gf2p8affine_epi64_epi8(a, _mm_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)
#define _mm_mask_inverse_epi8(s, k, a)				_mm_mask_gf2p8affine_epi64_epi8(s, k, a, _mm_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)
#define _mm_maskz_inverse_epi8(k, a)				_mm_maskz_gf2p8affine_epi64_epi8(k, a, _mm_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)

#define _mm256_inverse_epi8(a)						_mm256_gf2p8affine_epi64_epi8(a, _mm256_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)
#define _mm256_mask_inverse_epi8(s, k, a)			_mm256_mask_gf2p8affine_epi64_epi8(s, k, a, _mm256_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)
#define _mm256_maskz_inverse_epi8(k, a)				_mm256_maskz_gf2p8affine_epi64_epi8(k, a, _mm256_set1_epi64x(_GFNI_DEMO_IDENT), 0xff)

#define _mm512_inverse_epi8(a)						_mm512_gf2p8affine_epi64_epi8(a, _mm512_set1_epi64(_GFNI_DEMO_IDENT), 0xff)
#define _mm512_mask_inverse_epi8(s, k, a)			_mm512_mask_gf2p8affine_epi64_epi8(s, k, a, _mm512_set1_epi64(_GFNI_DEMO_IDENT), 0xff)
#define _mm512_maskz_inverse_epi8(k, a)				_mm512_maskz_gf2p8affine_epi64_epi8(k, a, _mm512_set1_epi64(_GFNI_DEMO_IDENT), 0xff)

/* Compile time known imm byte a broadcast without touching the memory or Port5 */

#define _mm_set1_gfni_epi8(a)						_mm_gf2p8affine_epi64_epi8(_mm_setzero_si128(), _mm_setzero_si128(), a)
#define _mm_mask_set1_gfni_epi8(s, k, a)			_mm_mask_gf2p8affine_epi64_epi8(s, k, _mm_setzero_si128(), _mm_setzero_si128(), a)
#define _mm_maskz_set1_gfni_epi8(k, a)				_mm_maskz_gf2p8affine_epi64_epi8(k, _mm_setzero_si128(), _mm_setzero_si128(), a)

#define _mm256_set1_gfni_epi8(a)					_mm256_gf2p8affine_epi64_epi8(_mm256_setzero_si256(), _mm256_setzero_si256(), a)
#define _mm256_mask_set1_gfni_epi8(s, k, a)			_mm256_mask_gf2p8affine_epi64_epi8(s, k, _mm256_setzero_si256(), _mm256_setzero_si256(), a)
#define _mm256_maskz_set1_gfni_epi8(k, a)			_mm256_maskz_gf2p8affine_epi64_epi8(k, _mm256_setzero_si256(), _mm256_setzero_si256(), a)

#define _mm512_set1_gfni_epi8(a)					_mm512_gf2p8affine_epi64_epi8(_mm512_setzero_si512(), _mm512_setzero_si512(), a)
#define _mm512_mask_set1_gfni_epi8(s, k, a)			_mm512_mask_gf2p8affine_epi64_epi8(s, k, _mm512_setzero_si512(), _mm512_setzero_si512(), a)
#define _mm512_maskz_set1_gfni_epi8(k, a)			_mm512_maskz_gf2p8affine_epi64_epi8(k, _mm512_setzero_si512(), _mm512_setzero_si512(), a)

#if defined(__AVX512F__) && defined(_M_X64)
/* Pospopcount u8  */
/* In  : MSB        77 76 75 74 73 72 71 70      */
/*                  67 66 65 64 63 62 61 60      */
/*                  57 56 55 54 53 52 51 50      */
/*                  47 46 45 44 43 42 41 40      */
/*                  37 36 35 34 33 32 31 30      */
/*                  27 26 25 24 23 22 21 20      */
/*                  17 16 15 14 13 12 11 10      */
/*                  07 06 05 04 03 02 01 00 LSB  */
/*                                               */
/* Out : MSB popcnt(77,67,57,47,37,27,17,07)     */
/*           popcnt(76,66,56,46,36,26,16,06)     */
/*           popcnt(75,65,55,45,35,25,15,05)     */
/*           popcnt(74,64,54,44,34,24,14,04)     */
/*           popcnt(73,63,53,43,33,23,13,03)     */
/*           popcnt(72,62,52,42,32,22,12,02)     */
/*           popcnt(71,61,51,41,31,21,11,01)     */
/*           popcnt(70,60,50,40,30,20,10,00) LSB */

#define _mm_pospopcnt_u8_si128_epi8(a)				_mm_cvtepi16_epi8(_mm_popcnt_epi16(_mm_shuffle_epi8(_mm_rotate_8x8(a), _mm_set_epi64x(0x0f070e060d050c04, 0x0b030a0209010800))))
#define _mm256_pospopcnt_u8_si256_epi8(a)			_mm256_cvtepi32_epi8(_mm256_popcnt_epi32(_mm256_permutexvar_epi8(_mm256_set_epi64x(0x1f170f071e160e06, 0x1d150d051c140c04, 0x1b130b031a120a02, 0x1911090118100800), _mm256_rotate_8x8(a))))
#define _mm512_pospopcnt_u8_si512_epi8(a)			_mm512_cvtepi64_epi8(_mm512_popcnt_epi64(_mm512_permutexvar_epi8(_mm512_set_epi64(0x3f372f271f170f07, 0x3e362e261e160e06, 0x3d352d251d150d05, 0x3c342c241c140c04, 0x3b332b231b130b03, 0x3a322a221a120a02, 0x3931292119110901, 0x3830282018100800), _mm512_rotate_8x8(a))))

/* Pospopcount u16  */
/* In:  MSB 7F 7E 7D 7C 7B 7A 79 78 77 76 75 74 73 72 71 70     */
/*          6F 6E 6D 6C 6B 6A 69 68 67 66 65 64 63 62 61 60     */
/*          5F 5E 5D 5C 5B 5A 59 58 57 56 55 54 53 52 51 50     */
/*          4F 4E 4D 4C 4B 4A 49 48 47 46 45 44 43 42 41 40     */
/*          3F 3E 3D 3C 3B 3A 39 38 37 36 35 34 33 32 31 30     */
/*          2F 2E 2D 2C 2B 2A 29 28 27 26 25 24 23 22 21 20     */
/*          1F 1E 1D 1C 1B 1A 19 18 17 16 15 14 13 12 11 10     */
/*          0F 0E 0D 0C 0B 0A 09 08 07 06 05 04 03 02 01 00 LSB */
/*                                              */
/* Out: MSB popcnt(7F,6F,5F,4F,3F,2F,1F,0F)     */
/*          popcnt(7E,6E,5E,4E,3E,2E,1E,0E)     */
/*          popcnt(7D,6D,5D,4D,3D,2D,1D,0D)     */
/*          popcnt(7C,6C,5C,4C,3C,2C,1C,0C)     */
/*          popcnt(7B,6B,5B,4B,3B,2B,1B,0B)     */
/*          popcnt(7A,6A,5A,4A,3A,2A,1A,0A)     */
/*          popcnt(79,69,59,49,39,29,19,09)     */
/*          popcnt(78,68,58,48,38,28,18,08)     */
/*          popcnt(77,67,57,47,37,27,17,07)     */
/*          popcnt(76,66,56,46,36,26,16,06)     */
/*          popcnt(75,65,55,45,35,25,15,05)     */
/*          popcnt(74,64,54,44,34,24,14,04)     */ 
/*          popcnt(73,63,53,43,33,23,13,03)     */
/*          popcnt(72,62,52,42,32,22,12,02)     */
/*          popcnt(71,61,51,41,31,21,11,01)     */
/*          popcnt(70,60,50,40,30,20,10,00) LSB */

#define _mm_pospopcnt_u16_si128_epi8(a)				_mm_popcnt_epi8(_mm_rotate_8x8(_mm_shuffle_epi8(a, _mm_set_epi64x(0x0f0d0b0907050301, 0x0e0c0a0806040200))))
#define _mm256_pospopcnt_u16_si256_epi8(a)			_mm256_cvtepi16_epi8(_mm256_popcnt_epi16(_mm256_permutexvar_epi8(_mm256_set_epi64x(0x1f0f1e0e1d0d1c0c, 0x1b0b1a0a19091808, 0x1707160615051404, 0x1303120211011000), _mm256_rotate_8x8(_mm256_shuffle_epi8(a, _mm256_broadcastsi128_si256(_mm_set_epi64x(0x0f0d0b0907050301, 0x0e0c0a0806040200)))))))
#define _mm512_pospopcnt_u16_si512_epi8(a)			_mm512_cvtepi32_epi8(_mm512_popcnt_epi32(_mm512_permutexvar_epi8(_mm512_set_epi64(0x3f2f1f0f3e2e1e0e, 0x3d2d1d0d3c2c1c0c, 0x3b2b1b0b3a2a1a0a, 0x3929190938281808, 0x3727170736261606, 0x3525150534241404, 0x3323130332221202, 0x3121110130201000), _mm512_rotate_8x8(_mm512_shuffle_epi8(a, _mm512_broadcast_i32x4(_mm_set_epi64x(0x0f0d0b0907050301, 0x0e0c0a0806040200)))))))
#endif

/* Count the number of trailing zero bits for packed bytes */
/* In  : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */
/* Out : MSB  0  0  0  0       tzcnt LSB */

#define _mm_tzcnt_gfni_epi8(a)						_mm_gf2p8affine_epi64_epi8(_mm_andnot_si128(_mm_add_epi8(a, _mm_set1_epi32(-1)), a), _mm_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)
#define _mm_mask_tzcnt_gfni_epi8(s, k, a)			_mm_mask_gf2p8affine_epi64_epi8(s, k, _mm_andnot_si128(_mm_add_epi8(a, _mm_set1_epi32(-1)), a), _mm_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)
#define _mm_maskz_tzcnt_gfni_epi8(k, a)				_mm_maskz_gf2p8affine_epi64_epi8(k, _mm_andnot_si128(_mm_add_epi8(a, _mm_set1_epi32(-1)), a), _mm_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)

#define _mm256_tzcnt_gfni_epi8(a)					_mm256_gf2p8affine_epi64_epi8(_mm256_andnot_si256(_mm256_add_epi8(a, _mm256_set1_epi32(-1)), a), _mm256_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)
#define _mm256_mask_tzcnt_gfni_epi8(s, k, a)		_mm256_mask_gf2p8affine_epi64_epi8(s, k, _mm256_andnot_si256(_mm256_add_epi8(a, _mm256_set1_epi32(-1)), a), _mm256_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)
#define _mm256_maskz_tzcnt_gfni_epi8(k, a)			_mm256_maskz_gf2p8affine_epi64_epi8(k, _mm256_andnot_si256(_mm256_add_epi8(a, _mm256_set1_epi32(-1)), a), _mm256_set1_epi64x(_GFNI_DEMO_TZCNT), 0x8)

#define _mm512_tzcnt_gfni_epi8(a)					_mm512_gf2p8affine_epi64_epi8(_mm512_andnot_si512(_mm512_add_epi8(a, _mm512_set1_epi32(-1)), a), _mm512_set1_epi64(_GFNI_DEMO_TZCNT), 0x8)
#define _mm512_mask_tzcnt_gfni_epi8(s, k, a)		_mm512_mask_gf2p8affine_epi64_epi8(s, k, _mm512_andnot_si512(_mm512_add_epi8(a, _mm512_set1_epi32(-1)), a), _mm512_set1_epi64(_GFNI_DEMO_TZCNT), 0x8)
#define _mm512_maskz_tzcnt_gfni_epi8(k, a)			_mm512_maskz_gf2p8affine_epi64_epi8(k, _mm512_andnot_si512(_mm512_add_epi8(a, _mm512_set1_epi32(-1)), a), _mm512_set1_epi64(_GFNI_DEMO_TZCNT), 0x8)

/* Count the number of leading zero bits for packed bytes */
/* In  : MSB B7 B6 B5 B4 B3 B2 B1 B0 LSB */
/* Out : MSB  0  0  0  0       lzcnt LSB */

#define _mm_lzcnt_gfni_epi8(a)						_mm_tzcnt_gfni_epi8(_mm_revbit_epi8(a))
#define _mm_mask_lzcnt_gfni_epi8(s, k, a)			_mm_mask_tzcnt_gfni_epi8(s, k, _mm_revbit_epi8(a))	
#define _mm_maskz_lzcnt_gfni_epi8(k, a)				_mm_maskz_tzcnt_gfni_epi8(k, _mm_revbit_epi8(a))		

#define _mm256_lzcnt_gfni_epi8(a)					_mm256_tzcnt_gfni_epi8(_mm256_revbit_epi8(a))			
#define _mm256_mask_lzcnt_gfni_epi8(s, k, a)		_mm256_mask_tzcnt_gfni_epi8(s, k, _mm256_revbit_epi8(a))
#define _mm256_maskz_lzcnt_gfni_epi8(k, a)			_mm256_maskz_tzcnt_gfni_epi8(k, _mm256_revbit_epi8(a))	

#define _mm512_lzcnt_gfni_epi8(a)					_mm512_tzcnt_gfni_epi8(_mm512_revbit_epi8(a))			
#define _mm512_mask_lzcnt_gfni_epi8(s, k, a)		_mm512_mask_tzcnt_gfni_epi8(s, k, _mm512_revbit_epi8(a))
#define _mm512_maskz_lzcnt_gfni_epi8(k, a)			_mm512_maskz_tzcnt_gfni_epi8(k, _mm512_revbit_epi8(a))	

extern inline uint64_t serialized_tsc(void);