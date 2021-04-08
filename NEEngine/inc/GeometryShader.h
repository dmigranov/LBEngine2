#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// FOG_FACTOR               0     z         2     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// EDGEDISTANCE             0   xyz         1     NONE   float   xyz 
// FOG_FACTOR               0   x           2     NONE   float   x   
// TEXCOORD                 0    yz         2     NONE   float    yz 
// SV_POSITION              0   xyzw        3      POS   float   xyzw
//
gs_5_0
dcl_globalFlags refactoringAllowed
dcl_input_siv v[3][0].xyzw, position
dcl_input v[3][1].xyzw
dcl_input v[3][2].xy
dcl_input v[3][2].z
dcl_temps 3
dcl_inputprimitive triangle 
dcl_stream m0
dcl_outputtopology trianglestrip 
dcl_output o0.xyzw
dcl_output o1.xyz
dcl_output o2.x
dcl_output o2.yz
dcl_output_siv o3.xyzw, position
dcl_maxout 3
add r0.xyzw, v[1][1].xyzw, v[0][1].xyzw
add r0.xyzw, r0.xyzw, v[2][1].xyzw
mul r0.xyzw, r0.xyzw, l(0.333333, 0.333333, 0.333333, 0.333333)
mov o0.xyzw, r0.xyzw
add r1.xyz, -v[2][0].xyzx, v[1][0].xyzx
dp3 r1.x, r1.xyzx, r1.xyzx
add r1.yzw, -v[0][0].xxyz, v[1][0].xxyz
dp3 r1.y, r1.yzwy, r1.yzwy
add r1.z, r1.y, r1.x
add r2.xyz, -v[0][0].xyzx, v[2][0].xyzx
dp3 r1.w, r2.xyzx, r2.xyzx
add r1.z, -r1.w, r1.z
sqrt r2.xy, r1.xyxx
add r1.y, r1.y, r1.w
sqrt r1.w, r1.w
add r1.x, -r1.x, r1.y
dp2 r1.y, r2.yyyy, r2.xxxx
div r1.y, r1.z, r1.y
mad r1.z, |r1.y|, l(-0.018729), l(0.074261)
mad r1.z, r1.z, |r1.y|, l(-0.212114)
mad r1.z, r1.z, |r1.y|, l(1.570729)
add r2.x, -|r1.y|, l(1.000000)
lt r1.y, r1.y, -r1.y
sqrt r2.x, r2.x
mul r2.z, r1.z, r2.x
mad r2.z, r2.z, l(-2.000000), l(3.141593)
and r1.y, r1.y, r2.z
mad r1.y, r1.z, r2.x, r1.y
sincos r1.y, null, r1.y
mul r1.y, r1.y, r2.y
mov o1.x, |r1.y|
mov o1.yz, l(0,0,0,0)
mov o2.xyz, v[0][2].zxyz
mov o3.xyzw, v[0][0].xyzw
emit_stream m0
mov o0.xyzw, r0.xyzw
mov o1.xz, l(0,0,0,0)
dp2 r1.y, r2.yyyy, r1.wwww
div r1.x, r1.x, r1.y
mad r1.y, |r1.x|, l(-0.018729), l(0.074261)
mad r1.y, r1.y, |r1.x|, l(-0.212114)
mad r1.y, r1.y, |r1.x|, l(1.570729)
add r1.z, -|r1.x|, l(1.000000)
lt r1.x, r1.x, -r1.x
sqrt r1.z, r1.z
mul r2.x, r1.z, r1.y
mad r2.x, r2.x, l(-2.000000), l(3.141593)
and r1.x, r1.x, r2.x
mad r1.x, r1.y, r1.z, r1.x
sincos r1.x, null, r1.x
mul r1.y, r1.x, r2.y
mul r1.x, r1.x, r1.w
mov o1.y, |r1.y|
mov o2.xyz, v[1][2].zxyz
mov o3.xyzw, v[1][0].xyzw
emit_stream m0
mov o0.xyzw, r0.xyzw
mov o1.xy, l(0,0,0,0)
mov o1.z, |r1.x|
mov o2.xyz, v[2][2].zxyz
mov o3.xyzw, v[2][0].xyzw
emit_stream m0
cut_stream m0
ret 
// Approximately 64 instruction slots used
#endif

const BYTE g_gs[] =
{
     68,  88,  66,  67, 132, 157, 
     46, 114,  40, 209, 140,  49, 
    197,  51, 165, 200,  83, 157, 
     32, 209,   1,   0,   0,   0, 
    108,  10,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    160,   0,   0,   0,  56,   1, 
      0,   0,   8,   2,   0,   0, 
    208,   9,   0,   0,  82,  68, 
     69,  70, 100,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  71,   0,   1,   0,   0, 
     60,   0,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  73,  83, 
     71,  78, 144,   0,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0, 104,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,  15, 
      0,   0, 116,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,  15, 
      0,   0, 122,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0, 131,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   4,   4, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  70, 
     79,  71,  95,  70,  65,  67, 
     84,  79,  82,   0, 171, 171, 
     79,  83,  71,  53, 200,   0, 
      0,   0,   5,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 148,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,   0,   0,   0,   0, 
    154,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   8,   0,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      1,  14,   0,   0,   0,   0, 
      0,   0, 178,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   6,   9, 
      0,   0,   0,   0,   0,   0, 
    187,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,   0,   0,   0, 
     67,  79,  76,  79,  82,   0, 
     69,  68,  71,  69,  68,  73, 
     83,  84,  65,  78,  67,  69, 
      0,  70,  79,  71,  95,  70, 
     65,  67,  84,  79,  82,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  83,  86,  95, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0, 171,  83,  72, 
     69,  88, 192,   7,   0,   0, 
     80,   0,   2,   0, 240,   1, 
      0,   0, 106,   8,   0,   1, 
     97,   0,   0,   5, 242,  16, 
     32,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  95,   0,   0,   4, 
    242,  16,  32,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     95,   0,   0,   4,  50,  16, 
     32,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  95,   0, 
      0,   4,  66,  16,  32,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0,  93,  24, 
      0,   1, 143,   0,   0,   3, 
      0,   0,  17,   0,   0,   0, 
      0,   0,  92,  40,   0,   1, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3,  18,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3,  98,  32, 
     16,   0,   2,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  94,   0, 
      0,   2,   3,   0,   0,   0, 
      0,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     70,  30,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  30,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 171, 170, 170,  62, 
    171, 170, 170,  62, 171, 170, 
    170,  62, 171, 170, 170,  62, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,  18,  32, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
     70,  18,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,  10, 226,   0,  16,   0, 
      1,   0,   0,   0,   6,  25, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,  25,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0, 150,   7,  16,   0, 
      1,   0,   0,   0, 150,   7, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,  10, 114,   0,  16,   0, 
      2,   0,   0,   0,  70,  18, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70,  18,  32,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   8,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  75,   0,   0,   5, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  75,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     15,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   5,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      2,   0,   0,   0,  14,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16, 128, 
    129,   0,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
     48, 110, 153, 188,   1,  64, 
      0,   0,  39,  22, 152,  61, 
     50,   0,   0,  10,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16, 128, 
    129,   0,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
    132,  52,  89, 190,  50,   0, 
      0,  10,  66,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16, 128, 129,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0, 164,  13, 
    201,  63,   0,   0,   0,   8, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16, 128, 
    193,   0,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  49,   0, 
      0,   8,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     75,   0,   0,   5,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,   1,  64, 
      0,   0, 219,  15,  73,  64, 
      1,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,   9,  34,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  77,   0, 
      0,   6,  34,   0,  16,   0, 
      1,   0,   0,   0,   0, 208, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  54,   0,   0,   6, 
     18,  32,  16,   0,   1,   0, 
      0,   0,  26,   0,  16, 128, 
    129,   0,   0,   0,   1,   0, 
      0,   0,  54,   0,   0,   8, 
     98,  32,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   6, 114,  32,  16,   0, 
      2,   0,   0,   0,  38,  25, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   6, 242,  32,  16,   0, 
      3,   0,   0,   0,  70,  30, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 117,   0, 
      0,   3,   0,   0,  17,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   8,  82,  32, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     14,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10,  34,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16, 128, 129,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  48, 110, 153, 188, 
      1,  64,   0,   0,  39,  22, 
    152,  61,  50,   0,   0,  10, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16, 128, 129,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0, 132,  52,  89, 190, 
     50,   0,   0,  10,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16, 128, 
    129,   0,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
    164,  13, 201,  63,   0,   0, 
      0,   8,  66,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16, 128, 193,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     49,   0,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  75,   0,   0,   5, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0, 192, 
      1,  64,   0,   0, 219,  15, 
     73,  64,   1,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     77,   0,   0,   6,  18,   0, 
     16,   0,   1,   0,   0,   0, 
      0, 208,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   6, 
     34,  32,  16,   0,   1,   0, 
      0,   0,  26,   0,  16, 128, 
    129,   0,   0,   0,   1,   0, 
      0,   0,  54,   0,   0,   6, 
    114,  32,  16,   0,   2,   0, 
      0,   0,  38,  25,  32,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0,  54,   0,   0,   6, 
    242,  32,  16,   0,   3,   0, 
      0,   0,  70,  30,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 117,   0,   0,   3, 
      0,   0,  17,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8,  50,  32,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  66,  32, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16, 128, 129,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6, 114,  32, 
     16,   0,   2,   0,   0,   0, 
     38,  25,  32,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 242,  32, 
     16,   0,   3,   0,   0,   0, 
     70,  30,  32,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
    117,   0,   0,   3,   0,   0, 
     17,   0,   0,   0,   0,   0, 
    118,   0,   0,   3,   0,   0, 
     17,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     64,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  42,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
