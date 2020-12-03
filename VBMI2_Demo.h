#pragma once

#define _VBMI2_DEMO_VERSION							0x0101

/* Rotate right words by imm8 bits mod 16 */

#define _mm_ror_vbmi2_epi16(a, cnt)					_mm_shrdi_epi16(a, a, cnt)
#define _mm_mask_ror_vbmi2_epi16(a, k, b, cnt)		_mm_mask_shrdi_epi16(a, k, b, b, cnt)
#define _mm_maskz_ror_vbmi2_epi16(k, a, cnt)		_mm_maskz_shrdi_epi16(k, a, a, cnt)
#define _mm256_ror_vbmi2_epi16(a, cnt)				_mm256_shrdi_epi16(a, a, cnt)
#define _mm256_mask_ror_vbmi2_epi16(a, k, b, cnt)	_mm256_mask_shrdi_epi16(a, k, b, b, cnt)
#define _mm256_maskz_ror_vbmi2_epi16(k, a, cnt)		_mm256_maskz_shrdi_epi16(k, a, a, cnt)
#define _mm512_ror_vbmi2_epi16(a, cnt)				_mm512_shrdi_epi16(a, a, cnt)
#define _mm512_mask_ror_vbmi2_epi16(a, k, b, cnt)	_mm512_mask_shrdi_epi16(a, k, b, b, cnt)
#define _mm512_maskz_ror_vbmi2_epi16(k, a, cnt)		_mm512_maskz_shrdi_epi16(k, a, a, cnt)

/* Rotate left by words by imm8 bits mod 16 */

#define _mm_rol_vbmi2_epi16(a, cnt)					_mm_shldi_epi16(a, a, cnt)
#define _mm_mask_rol_vbmi2_epi16(a, k, b, cnt)		_mm_mask_shldi_epi16(a, k, b, b, cnt)
#define _mm_maskz_rol_vbmi2_epi16(k, a, cnt)		_mm_maskz_shldi_epi16(k, a, a, cnt)
#define _mm256_rol_vbmi2_epi16(a, cnt)				_mm256_shldi_epi16(a, a, cnt)
#define _mm256_mask_rol_vbmi2_epi16(a, k, b, cnt)	_mm256_mask_shldi_epi16(a, k, b, b, cnt)
#define _mm256_maskz_rol_vbmi2_epi16(k, a, cnt)		_mm256_maskz_shldi_epi16(k, a, a, cnt)
#define _mm512_rol_vbmi2_epi16(a, cnt)				_mm512_shldi_epi16(a, a, cnt)
#define _mm512_mask_rol_vbmi2_epi16(a, k, b, cnt)	_mm512_mask_shldi_epi16(a, k, b, b, cnt)
#define _mm512_maskz_rol_vbmi2_epi16(k, a, cnt)		_mm512_maskz_shldi_epi16(k, a, a, cnt)

/* Variable rotate right words by cnt bits, cnt mod 16 */

#define _mm_rorv_vbmi2_epi16(a, cnt)				_mm_shrdv_epi16(a, a, cnt)
#define _mm_mask_rorv_vbmi2_epi16(a, k, b, cnt)		_mm_mask_blend_epi16(k, a, _mm_shrdv_epi16(b, b, cnt))
#define _mm_maskz_rorv_vbmi2_epi16(k, a, cnt)		_mm_maskz_shrdv_epi16(k, a, a, cnt)
#define _mm256_rorv_vbmi2_epi16(a, cnt)				_mm256_shrdv_epi16(a, a, cnt)
#define _mm256_mask_rorv_vbmi2_epi16(a, k, b, cnt)	_mm256_mask_blend_epi16(k, a, _mm256_shrdv_epi16(b, b, cnt))
#define _mm256_maskz_rorv_vbmi2_epi16(k, a, cnt)	_mm256_maskz_shrdv_epi16(k, a, a, cnt)
#define _mm512_rorv_vbmi2_epi16(a, cnt)				_mm512_shrdv_epi16(a, a, cnt)
#define _mm512_mask_rorv_vbmi2_epi16(a, k, b, cnt)	_mm512_mask_blend_epi16(k, a, _mm512_shrdv_epi16(b, b, cnt))
#define _mm512_maskz_rorv_vbmi2_epi16(k, a, cnt)	_mm512_maskz_shrdv_epi16(k, a, a, cnt)

/* Variable rotate left words by cnt bits, cnt mod 16 */

#define _mm_rolv_vbmi2_epi16(a, cnt)				_mm_shldv_epi16(a, a, cnt)
#define _mm_mask_rolv_vbmi2_epi16(a, k, b, cnt)		_mm_mask_blend_epi16(k, a, _mm_shldv_epi16(b, b, cnt))
#define _mm_maskz_rolv_vbmi2_epi16(k, a, cnt)		_mm_maskz_shldv_epi16(k, a, a, cnt)
#define _mm256_rolv_vbmi2_epi16(a, cnt)				_mm256_shldv_epi16(a, a, cnt)
#define _mm256_mask_rolv_vbmi2_epi16(a, k, b, cnt)	_mm256_mask_blend_epi16(k, a, _mm256_shldv_epi16(b, b, cnt))
#define _mm256_maskz_rolv_vbmi2_epi16(k, a, cnt)	_mm256_maskz_shldv_epi16(k, a, a, cnt)
#define _mm512_rolv_vbmi2_epi16(a, cnt)				_mm512_shldv_epi16(a, a, cnt)
#define _mm512_mask_rolv_vbmi2_epi16(a, k, b, cnt)	_mm512_mask_blend_epi16(k, a, _mm512_shldv_epi16(b, b, cnt))
#define _mm512_maskz_rolv_vbmi2_epi16(k, a, cnt)	_mm512_maskz_shldv_epi16(k, a, a, cnt)

#define _mm_swaplh_epi8(a)							_mm_shldi_epi16(a, a, 8)
#define _mm_swaphl_epi8(a)							_mm_shrdi_epi16(a, a, 8)
#define _mm256_swaplh_epi8(a)						_mm256_shldi_epi16(a, a, 8)
#define _mm256_swaphl_epi8(a)						_mm256_shrdi_epi16(a, a, 8)
#define _mm512_swaplh_epi8(a)						_mm512_shldi_epi16(a, a, 8)
#define _mm512_swaphl_epi8(a)						_mm512_shrdi_epi16(a, a, 8)

#define _shift_cnt1(cnt)							min(cnt + 8, 255)
#define _shift_cnt2(cnt)							(cnt)

#define _rotate_cnt1(cnt)							(cnt | 0x8)
#define _rotate_cnt2(cnt)							(cnt & ~0x8)

//a & ~b | c
#define _rotate_vcnt_r(size, cnt)					_##size##_ternarylogic_epi32(cnt, _##size##_set1_epi32(0x00080008), _##size##_set1_epi32(0x08000800), 0xba)
// a | b &  ~c
#define _rotate_vcnt_l(size, cnt)					_##size##_ternarylogic_epi32(cnt, _##size##_set1_epi32(0x00080008), _##size##_set1_epi32(0x08000800), 0x54)

/* Logical shift right bytes by imm bits, if imm > 7, result is 0 */

#define _mm_srli_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_srli_epi16(a, _shift_cnt1(cnt)), _mm_srli_epi16(_mm_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm_mask_srli_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_srli_vbmi2_epi8(b, cnt))
#define _mm_maskz_srli_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_srli_vbmi2_epi8(a, cnt))
#define _mm256_srli_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_srli_epi16(a, _shift_cnt1(cnt)), _mm256_srli_epi16(_mm256_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm256_mask_srli_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_srli_vbmi2_epi8(b, cnt))
#define _mm256_maskz_srli_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_srli_vbmi2_epi8(a, cnt))
#define _mm512_srli_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_srli_epi16(a, _shift_cnt1(cnt)), _mm512_srli_epi16(_mm512_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm512_mask_srli_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_srli_vbmi2_epi8(b, cnt))
#define _mm512_maskz_srli_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_srli_vbmi2_epi8(a, cnt))

/* Rotate right bytes by imm8 bits mod 8 */

#define _mm_ror_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_shrdi_epi16(a, _mm_swaphl_epi8(a), _rotate_cnt1(cnt)), _mm_shrdi_epi16(_mm_swaphl_epi8(a), a, _rotate_cnt2(cnt)), 8)
#define _mm_mask_ror_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_ror_vbmi2_epi8(b, cnt))
#define _mm_maskz_ror_vbmi2_epi8(k, a, cnt)			_mm_maskz_mov_epi8(k, _mm_ror_vbmi2_epi8(a, cnt))
#define _mm256_ror_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_shrdi_epi16(a, _mm256_swaphl_epi8(a), _rotate_cnt1(cnt)), _mm256_shrdi_epi16(_mm256_swaphl_epi8(a), a, _rotate_cnt2(cnt)), 8)
#define _mm256_mask_ror_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_ror_vbmi2_epi8(b, cnt))
#define _mm256_maskz_ror_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_ror_vbmi2_epi8(a, cnt))
#define _mm512_ror_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_shrdi_epi16(a, _mm512_swaphl_epi8(a), _rotate_cnt1(cnt)), _mm512_shrdi_epi16(_mm512_swaphl_epi8(a), a, _rotate_cnt2(cnt)), 8)
#define _mm512_mask_ror_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_ror_vbmi2_epi8(b, cnt))
#define _mm512_maskz_ror_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_ror_vbmi2_epi8(a, cnt))

/* Variable logical shift right bytes by cnt bits, if cnt > 7, result is 0 */

#define _mm_srlv_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_srlv_epi16(a, _mm_adds_epu8(_mm_set1_epi32(0x00080008), _mm_srli_epi16(cnt, 8))), _mm_srlv_epi16(_mm_swaphl_epi8(a), _mm_and_si128(_mm_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm_mask_srlv_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_srlv_vbmi2_epi8(b, cnt))
#define _mm_maskz_srlv_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_srlv_vbmi2_epi8(a, cnt))
#define _mm256_srlv_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_srlv_epi16(a, _mm256_adds_epu8(_mm256_set1_epi32(0x00080008), _mm256_srli_epi16(cnt, 8))), _mm256_srlv_epi16(_mm256_swaphl_epi8(a), _mm256_and_si256(_mm256_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm256_mask_srlv_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_srlv_vbmi2_epi8(b, cnt))
#define _mm256_maskz_srlv_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_srlv_vbmi2_epi8(a, cnt))
#define _mm512_srlv_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_srlv_epi16(a, _mm512_adds_epu8(_mm512_set1_epi32(0x00080008), _mm512_srli_epi16(cnt, 8))), _mm512_srlv_epi16(_mm512_swaphl_epi8(a), _mm512_and_si512(_mm512_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm512_mask_srlv_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_srlv_vbmi2_epi8(b, cnt))
#define _mm512_maskz_srlv_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_srlv_vbmi2_epi8(a, cnt))

/* Variable rotate right bytes by cnt bits, cnt mod 8 */

#define _mm_rorv_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_shrdv_epi16(a, _mm_swaphl_epi8(a), _mm_alignr_epi8(_rotate_vcnt_r(mm, cnt), _rotate_vcnt_r(mm, cnt), 1)), _mm_shrdv_epi16(_mm_swaphl_epi8(a), a, _rotate_vcnt_r(mm, cnt)), 8)
#define _mm_mask_rorv_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_rorv_vbmi2_epi8(b, cnt))
#define _mm_maskz_rorv_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_rorv_vbmi2_epi8(a, cnt))
#define _mm256_rorv_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_shrdv_epi16(a, _mm256_swaphl_epi8(a), _mm256_alignr_epi8(_rotate_vcnt_r(mm256, cnt), _rotate_vcnt_r(mm256, cnt), 1)), _mm256_shrdv_epi16(_mm256_swaphl_epi8(a), a, _rotate_vcnt_r(mm256, cnt)), 8)
#define _mm256_mask_rorv_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_rorv_vbmi2_epi8(b, cnt))
#define _mm256_maskz_rorv_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_rorv_vbmi2_epi8(a, cnt))
#define _mm512_rorv_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_shrdv_epi16(a, _mm512_swaphl_epi8(a), _mm512_alignr_epi8(_rotate_vcnt_r(mm512, cnt), _rotate_vcnt_r(mm512, cnt), 1)), _mm512_shrdv_epi16(_mm512_swaphl_epi8(a), a, _rotate_vcnt_r(mm512, cnt)), 8)
#define _mm512_mask_rorv_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_rorv_vbmi2_epi8(b, cnt))
#define _mm512_maskz_rorv_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_rorv_vbmi2_epi8(a, cnt))

/* Logical shift left bytes by imm bits, if imm > 7, result is 0 */

#define _mm_slli_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_slli_epi16(_mm_swaplh_epi8(a), _shift_cnt2(cnt)), _mm_slli_epi16(a, _shift_cnt1(cnt)), 8)
#define _mm_mask_slli_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_slli_vbmi2_epi8(b, cnt))
#define _mm_maskz_slli_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_slli_vbmi2_epi8(a, cnt))
#define _mm256_slli_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_slli_epi16(_mm256_swaplh_epi8(a), _shift_cnt2(cnt)), _mm256_slli_epi16(a, _shift_cnt1(cnt)), 8)
#define _mm256_mask_slli_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_slli_vbmi2_epi8(b, cnt))
#define _mm256_maskz_slli_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_slli_vbmi2_epi8(a, cnt))
#define _mm512_slli_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_slli_epi16(_mm512_swaplh_epi8(a), _shift_cnt2(cnt)), _mm512_slli_epi16(a, _shift_cnt1(cnt)), 8)
#define _mm512_mask_slli_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_slli_vbmi2_epi8(b, cnt))
#define _mm512_maskz_slli_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_slli_vbmi2_epi8(a, cnt))

/* Rotate left bytes by imm8 bits mod 8 */

#define _mm_rol_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_shldi_epi16(_mm_swaplh_epi8(a), a, _rotate_cnt2(cnt)), _mm_shldi_epi16(a, _mm_swaplh_epi8(a), _rotate_cnt1(cnt)), 8)
#define _mm_mask_rol_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_rol_vbmi2_epi8(b, cnt))
#define _mm_maskz_rol_vbmi2_epi8(k, a, cnt)			_mm_maskz_mov_epi8(k, _mm_rol_vbmi2_epi8(a, cnt))
#define _mm256_rol_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_shldi_epi16(_mm256_swaplh_epi8(a), a, _rotate_cnt2(cnt)), _mm256_shldi_epi16(a, _mm256_swaplh_epi8(a), _rotate_cnt1(cnt)), 8)
#define _mm256_mask_rol_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_rol_vbmi2_epi8(b, cnt))
#define _mm256_maskz_rol_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_rol_vbmi2_epi8(a, cnt))
#define _mm512_rol_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_shldi_epi16(_mm512_swaplh_epi8(a), a, _rotate_cnt2(cnt)), _mm512_shldi_epi16(a, _mm512_swaplh_epi8(a), _rotate_cnt1(cnt)), 8)
#define _mm512_mask_rol_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_rol_vbmi2_epi8(b, cnt))
#define _mm512_maskz_rol_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_rol_vbmi2_epi8(a, cnt))

/* Variable logical shift left bytes by cnt bits, if cnt > 7, result is 0 */

#define _mm_sllv_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_sllv_epi16(_mm_swaplh_epi8(a), _mm_srli_epi16(cnt, 8)), _mm_sllv_epi16(a, _mm_adds_epu8(_mm_set1_epi32(0x00080008), _mm_and_si128(_mm_set1_epi32(0x00ff00ff), cnt))), 8)
#define _mm_mask_sllv_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_sllv_vbmi2_epi8(b, cnt))
#define _mm_maskz_sllv_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_sllv_vbmi2_epi8(a, cnt))
#define _mm256_sllv_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_sllv_epi16(_mm256_swaplh_epi8(a), _mm256_srli_epi16(cnt, 8)), _mm256_sllv_epi16(a, _mm256_adds_epu8(_mm256_set1_epi32(0x00080008), _mm256_and_si256(_mm256_set1_epi32(0x00ff00ff), cnt))), 8)
#define _mm256_mask_sllv_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_sllv_vbmi2_epi8(b, cnt))
#define _mm256_maskz_sllv_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_sllv_vbmi2_epi8(a, cnt))
#define _mm512_sllv_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_sllv_epi16(_mm512_swaplh_epi8(a), _mm512_srli_epi16(cnt, 8)), _mm512_sllv_epi16(a, _mm512_adds_epu8(_mm512_set1_epi32(0x00080008), _mm512_and_si512(_mm512_set1_epi32(0x00ff00ff), cnt))), 8)
#define _mm512_mask_sllv_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_sllv_vbmi2_epi8(b, cnt))
#define _mm512_maskz_sllv_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_sllv_vbmi2_epi8(a, cnt))

/* Variable rotate left bytes by cnt bits, cnt mod 8 */

#define _mm_rolv_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_shldv_epi16(a, _mm_swaphl_epi8(a), _mm_alignr_epi8(_rotate_vcnt_l(mm, cnt), _rotate_vcnt_l(mm, cnt), 1)), _mm_shldv_epi16(_mm_swaphl_epi8(a), a, _rotate_vcnt_l(mm, cnt)), 8)
#define _mm_mask_rolv_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_rolv_vbmi2_epi8(b, cnt))
#define _mm_maskz_rolv_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_rolv_vbmi2_epi8(a, cnt))
#define _mm256_rolv_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_shldv_epi16(_mm256_swaplh_epi8(a), a, _mm256_alignr_epi8(_rotate_vcnt_l(mm256, cnt), _rotate_vcnt_l(mm256, cnt), 1)), _mm256_shldv_epi16(a, _mm256_swaplh_epi8(a), _rotate_vcnt_l(mm256, cnt)), 8)
#define _mm256_mask_rolv_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_rolv_vbmi2_epi8(b, cnt))
#define _mm256_maskz_rolv_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_rolv_vbmi2_epi8(a, cnt))
#define _mm512_rolv_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_shldv_epi16(_mm512_swaplh_epi8(a), a, _mm512_alignr_epi8(_rotate_vcnt_l(mm512, cnt), _rotate_vcnt_l(mm512, cnt), 1)), _mm512_shldv_epi16(a, _mm512_swaplh_epi8(a), _rotate_vcnt_l(mm512, cnt)), 8)
#define _mm512_mask_rolv_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_rolv_vbmi2_epi8(b, cnt))
#define _mm512_maskz_rolv_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_rolv_vbmi2_epi8(a, cnt))

/* Arithmetcial shift right bytes by imm bits, if imm > 7, result is filled with MSB */

#define _mm_srai_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_srai_epi16(a, _shift_cnt1(cnt)), _mm_srai_epi16(_mm_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm_mask_srai_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_srai_vbmi2_epi8(b, cnt))
#define _mm_maskz_srai_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_srai_vbmi2_epi8(a, cnt))
#define _mm256_srai_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_srai_epi16(a, _shift_cnt1(cnt)), _mm256_srai_epi16(_mm256_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm256_mask_srai_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_srai_vbmi2_epi8(b, cnt))
#define _mm256_maskz_srai_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_srai_vbmi2_epi8(a, cnt))
#define _mm512_srai_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_srai_epi16(a, _shift_cnt1(cnt)), _mm512_srai_epi16(_mm512_swaphl_epi8(a), _shift_cnt2(cnt)), 8)
#define _mm512_mask_srai_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_srai_vbmi2_epi8(b, cnt))
#define _mm512_maskz_srai_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_srai_vbmi2_epi8(a, cnt))

/* Variable arithmetical shift right bytes by cnt bits, if cnt > 7, result is filled with MSB */

#define _mm_srav_vbmi2_epi8(a, cnt)					_mm_shldi_epi16(_mm_srav_epi16(a, _mm_adds_epu8(_mm_srli_epi16(cnt, 8), _mm_set1_epi32(0x00080008))), _mm_srav_epi16(_mm_swaphl_epi8(a), _mm_and_si128(_mm_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm_mask_srav_vbmi2_epi8(a, k, b, cnt)		_mm_mask_mov_epi8(a, k, _mm_srav_vbmi2_epi8(b, cnt))
#define _mm_maskz_srav_vbmi2_epi8(k, a, cnt)		_mm_maskz_mov_epi8(k, _mm_srav_vbmi2_epi8(a, cnt))
#define _mm256_srav_vbmi2_epi8(a, cnt)				_mm256_shldi_epi16(_mm256_srav_epi16(a, _mm256_adds_epu8(_mm256_srli_epi16(cnt, 8), _mm256_set1_epi32(0x00080008))), _mm256_srav_epi16(_mm256_swaphl_epi8(a), _mm256_and_si256(_mm256_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm256_mask_srav_vbmi2_epi8(a, k, b, cnt)	_mm256_mask_mov_epi8(a, k, _mm256_srav_vbmi2_epi8(b, cnt))
#define _mm256_maskz_srav_vbmi2_epi8(k, a, cnt)		_mm256_maskz_mov_epi8(k, _mm256_srav_vbmi2_epi8(a, cnt))
#define _mm512_srav_vbmi2_epi8(a, cnt)				_mm512_shldi_epi16(_mm512_srav_epi16(a, _mm512_adds_epu8(_mm512_srli_epi16(cnt, 8), _mm512_set1_epi32(0x00080008))), _mm512_srav_epi16(_mm512_swaphl_epi8(a), _mm512_and_si512(_mm512_set1_epi32(0x00ff00ff), cnt)), 8)
#define _mm512_mask_srav_vbmi2_epi8(a, k, b, cnt)	_mm512_mask_mov_epi8(a, k, _mm512_srav_vbmi2_epi8(b, cnt))
#define _mm512_maskz_srav_vbmi2_epi8(k, a, cnt)		_mm512_maskz_mov_epi8(k, _mm512_srav_vbmi2_epi8(a, cnt))

void VBMI2_Demo(void);
