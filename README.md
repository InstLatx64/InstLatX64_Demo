# InstLatX64_Demo

Collected source form of some ideas 

## GFNI_Demo.h - 
wrapper header for non-cryptographical use of (V)GF2P8AFFINEQB instruction in style of Intel intrinsics:
* emulating the missing byte-garnularity shift and rotate instructions;
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(srli|srl|srai|sra|slli|sll|ror|rol)_gfni_epi8
```
Unfortunately there are no variable versions (though they are variable versions in that you don't need to know the shift/rotate values in compiler time)

* revbit, bit-broadcast, prefix-xor operations for bytes
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(revbit|bcstbit|prefix_xor)_epi8
```    

* rotate, mirror, multiplication operations for 8x8 bit matrices
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(mirror|rotate|multiplication)_8x8
```    

* auxiliary: imm8 operand of (V)GF2P8AFFINEQB xors the result bytes, so it useful e.g. for inverting the all above functions or using for compile time known byte broadcast without using GPRs, Port5 or memory 
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(inverse|set1_gfni)_epi8
```    

* entire register pospopcount (if AVX512_BITALG & AVX512_VPOPCNTDQ also supported):
```    
    _(mm|mm256|mm512)_pospopcount_(u8|u16)_(si128|si256|si512)_epi8
```    

# VBMI2_Demo.h 
wrapper header for VPSHLDW/VPSHRDW/VPSHLDVW/VPSHRDVW instructions for substituting the missing VPROLW/VPRORW/VPRORVW/VPRORVW instructions with the good old shld r1, r1 = rol r1 trick
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(ror|rol)_vbmi2_epi16
```    
wrapper header for emulating the missing byte-garnularity shift and rotate instructions in variable versions too
```    
    _(mm|mm256|mm512)(|_mask|_maskz)_(slli|srli|srai|ror|rol)_vbmi2_epi8
    _(mm|mm256|mm512)(|_mask|_maskz)_(sllv|srlv|srav|rorv|rolv)_vbmi2_epi8
```    

# VPCLMULQDQ_Demo.h  
experimental implementation of entire register (128/256/512b, xmm/ymm/zmm) prefix-xor operation with the VPCLMULQDQ extension
```    
    _mm_prefix_xor_clmul_si128(__m128i a);
    _mm256_prefix_xor_clmul_si256(__m256i a);
    _mm512_prefix_xor_clmul_si512(__m512i a);
```    

# Compiler_Intrinsic_Test.cpp  
for testing Visual Studio AVX512 capabilities
# TZCNT_Demo.cpp  
SIMD TZCNT routines
# PEXT_PDEP_Emu.cpp  
Faster PEXT and PDEP emulation for AMD Excavator/Zen/Zen+/Zen2 based on Zach Wegner's ZP7 (Zach's Peppy Parallel-Prefix-Popcountin' PEXT/PDEP Polyfill)
# CPU_Props.* 
detection of CPU properties for dispatching code paths
# Zen3_Demo.* 
code for examining of the issue ports x87, MMX, SSE, AVX instructions in AMD Zen3/Vermeer CPU (CPUID A20F10). It is based on ideas from uops.info. Output example: \Results\Zen3_Demo.txt
# AVX512_DecimalPrint.* 
AVX512F, AVX512IFMA based implementation of _ultoa, _ltoa, _ui64toa, _i64toa functions.

## References
*  Geoff Langdale [Why Ice Lake is Important (a bit-basher’s perspective)](https://branchfree.org/2019/05/29/why-ice-lake-is-important-a-bit-bashers-perspective/)
*  Marcus D. R. Klarqvist, Wojciech Muła, Daniel Lemire [Efficient Computation of Positional Population Counts Using SIMD Instructions](https://arxiv.org/abs/1911.02696)
*  Wojciech Muła [AVX512VBMI — remove spaces from text](http://0x80.pl/articles/avx512-galois-field-for-bit-shuffling.html)
*  Zach Wegner [ZP7 (Zach's Peppy Parallel-Prefix-Popcountin' PEXT/PDEP Polyfill)](https://github.com/zwegner/zp7)
*  Abel, Andreas and Reineke, Jan [uops.info: Characterizing Latency, Throughput, and Port Usage of Instructions on Intel Microarchitectures](https://arxiv.org/pdf/1810.04610.pdf)
*  PerforatedBlob [TZCNT - TERNLOG->ANDN](https://twitter.com/PerforatedBlob/status/1418421045447454724)
*  TravisDowns [Scalar/HW GPR PDEP/PEXT reference code](https://twitter.com/trav_downs/status/1418616866080116742)
*  Daniel Lemire [Converting integers to decimal strings faster with AVX-512](https://lemire.me/blog/2022/03/28/converting-integers-to-decimal-strings-faster-with-avx-512/)