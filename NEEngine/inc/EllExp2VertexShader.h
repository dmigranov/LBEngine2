#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer PerApplication
// {
//
//   float4x4 projectionMatrixFront;    // Offset:    0 Size:    64
//   float4x4 projectionMatrixBack;     // Offset:   64 Size:    64
//   float density;                     // Offset:  128 Size:     4
//
// }
//
// cbuffer PerFrame
// {
//
//   float4x4 viewMatrixFront;          // Offset:    0 Size:    64
//   float4x4 viewMatrixBack;           // Offset:   64 Size:    64
//
// }
//
// cbuffer PerObject
// {
//
//   float4x4 worldMatrix;              // Offset:    0 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// PerApplication                    cbuffer      NA          NA            cb0      1 
// PerFrame                          cbuffer      NA          NA            cb1      1 
// PerObject                         cbuffer      NA          NA            cb2      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// SV_InstanceID            0   x           3   INSTID    uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// FOG_FACTOR               0     z         2     NONE   float     z 
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[9], immediateIndexed
dcl_constantbuffer CB1[8], immediateIndexed
dcl_constantbuffer CB2[4], immediateIndexed
dcl_input v0.xyzw
dcl_input v1.xyzw
dcl_input v2.xy
dcl_input_sgv v3.x, instance_id
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xy
dcl_output o2.z
dcl_temps 9
if_z v3.x
  mov r0.x, cb1[0].x
  mov r0.y, cb1[1].x
  mov r0.z, cb1[2].x
  mov r0.w, cb1[3].x
  mov r1.x, cb1[0].y
  mov r1.y, cb1[1].y
  mov r1.z, cb1[2].y
  mov r1.w, cb1[3].y
  mov r2.x, cb1[0].z
  mov r2.y, cb1[1].z
  mov r2.z, cb1[2].z
  mov r2.w, cb1[3].z
  mov r3.x, cb1[0].w
  mov r3.y, cb1[1].w
  mov r3.z, cb1[2].w
  mov r3.w, cb1[3].w
  mov r4.x, cb0[0].x
  mov r4.y, cb0[1].x
  mov r4.z, cb0[2].x
  mov r4.w, cb0[3].x
  mov r5.x, cb0[0].y
  mov r5.y, cb0[1].y
  mov r5.z, cb0[2].y
  mov r5.w, cb0[3].y
  mov r6.x, cb0[0].z
  mov r6.y, cb0[1].z
  mov r6.z, cb0[2].z
  mov r6.w, cb0[3].z
  mov r7.x, cb0[0].w
  mov r7.y, cb0[1].w
  mov r7.z, cb0[2].w
  mov r7.w, cb0[3].w
else 
  ieq r8.x, v3.x, l(1)
  if_nz r8.x
    mov r0.x, cb1[4].x
    mov r0.y, cb1[5].x
    mov r0.z, cb1[6].x
    mov r0.w, cb1[7].x
    mov r1.x, cb1[4].y
    mov r1.y, cb1[5].y
    mov r1.z, cb1[6].y
    mov r1.w, cb1[7].y
    mov r2.x, cb1[4].z
    mov r2.y, cb1[5].z
    mov r2.z, cb1[6].z
    mov r2.w, cb1[7].z
    mov r3.x, cb1[4].w
    mov r3.y, cb1[5].w
    mov r3.z, cb1[6].w
    mov r3.w, cb1[7].w
    mov r4.x, cb0[4].x
    mov r4.y, cb0[5].x
    mov r4.z, cb0[6].x
    mov r4.w, cb0[7].x
    mov r5.x, cb0[4].y
    mov r5.y, cb0[5].y
    mov r5.z, cb0[6].y
    mov r5.w, cb0[7].y
    mov r6.x, cb0[4].z
    mov r6.y, cb0[5].z
    mov r6.z, cb0[6].z
    mov r6.w, cb0[7].z
    mov r7.x, cb0[4].w
    mov r7.y, cb0[5].w
    mov r7.z, cb0[6].w
    mov r7.w, cb0[7].w
  endif 
endif 
dp4 r8.x, r0.xyzw, cb2[0].xyzw
dp4 r8.y, r0.xyzw, cb2[1].xyzw
dp4 r8.z, r0.xyzw, cb2[2].xyzw
dp4 r8.w, r0.xyzw, cb2[3].xyzw
dp4 r0.x, r1.xyzw, cb2[0].xyzw
dp4 r0.y, r1.xyzw, cb2[1].xyzw
dp4 r0.z, r1.xyzw, cb2[2].xyzw
dp4 r0.w, r1.xyzw, cb2[3].xyzw
dp4 r1.x, r2.xyzw, cb2[0].xyzw
dp4 r1.y, r2.xyzw, cb2[1].xyzw
dp4 r1.z, r2.xyzw, cb2[2].xyzw
dp4 r1.w, r2.xyzw, cb2[3].xyzw
dp4 r2.x, r3.xyzw, cb2[0].xyzw
dp4 r2.y, r3.xyzw, cb2[1].xyzw
dp4 r2.z, r3.xyzw, cb2[2].xyzw
dp4 r2.w, r3.xyzw, cb2[3].xyzw
dp4 r3.x, r8.xyzw, v0.xyzw
dp4 r3.y, r0.xyzw, v0.xyzw
dp4 r3.z, r1.xyzw, v0.xyzw
dp4 r3.w, r2.xyzw, v0.xyzw
add r0.xyzw, -r3.xyzw, l(0.000000, 0.000000, 0.000000, 1.000000)
dp4 r0.x, r0.xyzw, r0.xyzw
sqrt r0.x, r0.x
mul r0.y, r0.x, l(0.500000)
mad r0.z, -r0.x, l(0.500000), l(1.000000)
sqrt r0.z, r0.z
mad r0.x, r0.x, l(-0.009365), l(0.074261)
mad r0.x, r0.x, r0.y, l(-0.212114)
mad r0.x, r0.x, r0.y, l(1.570729)
mad r0.x, -r0.x, r0.z, l(1.570796)
dp4 o0.x, r4.xyzw, r3.xyzw
dp4 o0.y, r5.xyzw, r3.xyzw
dp4 o0.z, r6.xyzw, r3.xyzw
dp4 o0.w, r7.xyzw, r3.xyzw
dp2 r0.x, cb0[8].xxxx, r0.xxxx
mul r0.x, r0.x, r0.x
mul r0.x, r0.x, l(-1.442695)
exp o2.z, r0.x
mov o1.xyzw, v1.xyzw
mov o2.xy, v2.xyxx
ret 
// Approximately 111 instruction slots used
#endif

const BYTE g_ellexp2vs[] =
{
     68,  88,  66,  67,  10,  53, 
     54, 105,  26,   6,  36,  47, 
    226,  88, 199, 137, 138, 216, 
     25, 197,   1,   0,   0,   0, 
    148,  16,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     20,   3,   0,   0, 172,   3, 
      0,   0,  68,   4,   0,   0, 
    248,  15,   0,   0,  82,  68, 
     69,  70, 216,   2,   0,   0, 
      3,   0,   0,   0, 192,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,   0,   1,   0,   0, 
    176,   2,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    156,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 171,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 180,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     80, 101, 114,  65, 112, 112, 
    108, 105,  99,  97, 116, 105, 
    111, 110,   0,  80, 101, 114, 
     70, 114,  97, 109, 101,   0, 
     80, 101, 114,  79,  98, 106, 
    101,  99, 116,   0, 171, 171, 
    156,   0,   0,   0,   3,   0, 
      0,   0,   8,   1,   0,   0, 
    144,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    171,   0,   0,   0,   2,   0, 
      0,   0,  12,   2,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,   1,   0, 
      0,   0, 124,   2,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,   1,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 160,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 196,   1, 
      0,   0,  64,   0,   0,   0, 
     64,   0,   0,   0,   2,   0, 
      0,   0, 160,   1,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 217,   1,   0,   0, 
    128,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    232,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    112, 114, 111, 106, 101,  99, 
    116, 105, 111, 110,  77,  97, 
    116, 114, 105, 120,  70, 114, 
    111, 110, 116,   0, 102, 108, 
    111,  97, 116,  52, 120,  52, 
      0, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 150,   1, 
      0,   0, 112, 114, 111, 106, 
    101,  99, 116, 105, 111, 110, 
     77,  97, 116, 114, 105, 120, 
     66,  97,  99, 107,   0, 100, 
    101, 110, 115, 105, 116, 121, 
      0, 102, 108, 111,  97, 116, 
      0, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 225,   1, 
      0,   0,  92,   2,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    160,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    108,   2,   0,   0,  64,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 160,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 118, 105, 
    101, 119,  77,  97, 116, 114, 
    105, 120,  70, 114, 111, 110, 
    116,   0, 118, 105, 101, 119, 
     77,  97, 116, 114, 105, 120, 
     66,  97,  99, 107,   0, 171, 
    164,   2,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 160,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 119, 111, 
    114, 108, 100,  77,  97, 116, 
    114, 105, 120,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  73,  83,  71,  78, 
    144,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,  15,   0,   0, 
    113,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
    119,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   1,   1,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  67,  79,  76, 
     79,  82,   0,  84,  69,  88, 
     67,  79,  79,  82,  68,   0, 
     83,  86,  95,  73, 110, 115, 
    116,  97, 110,  99, 101,  73, 
     68,   0, 171, 171,  79,  83, 
     71,  78, 144,   0,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0, 104,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 116,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0, 122,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,  12, 
      0,   0, 131,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   4,  11, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  70, 
     79,  71,  95,  70,  65,  67, 
     84,  79,  82,   0, 171, 171, 
     83,  72,  69,  88, 172,  11, 
      0,   0,  80,   0,   1,   0, 
    235,   2,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      2,   0,   0,   0,   4,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   2,   0, 
      0,   0,  96,   0,   0,   4, 
     18,  16,  16,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3,  50,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3,  66,  32,  16,   0, 
      2,   0,   0,   0, 104,   0, 
      0,   2,   9,   0,   0,   0, 
     31,   0,   0,   3,  10,  16, 
     16,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     58, 128,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   3,   0,   0,   0, 
     58, 128,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   3,   0,   0,   0, 
     58, 128,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     58, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   4,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   4,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   4,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   5,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   5,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   6,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   6,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   6,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   6,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   7,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   7,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   7,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   7,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     18,   0,   0,   1,  32,   0, 
      0,   7,  18,   0,  16,   0, 
      8,   0,   0,   0,  10,  16, 
     16,   0,   3,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  31,   0,   4,   3, 
     10,   0,  16,   0,   8,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      1,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      1,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  58, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   3,   0, 
      0,   0,  58, 128,  32,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  58, 128,  32,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58, 128,  32,   0, 
      1,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   4,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   5,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   5,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   5,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   6,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   6,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   6,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   6,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  54,   0,   0,   6, 
     18,   0,  16,   0,   7,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     34,   0,  16,   0,   7,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
     66,   0,  16,   0,   7,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  54,   0,   0,   6, 
    130,   0,  16,   0,   7,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  21,   0,   0,   1, 
     21,   0,   0,   1,  17,   0, 
      0,   8,  18,   0,  16,   0, 
      8,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,   8,  34,   0, 
     16,   0,   8,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   8, 
     66,   0,  16,   0,   8,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   8, 130,   0,  16,   0, 
      8,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
     17,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,   8, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,  17,   0, 
      0,   8,  66,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
     17,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   3,   0, 
      0,   0,  17,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   8,  34,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
     17,   0,   0,   8,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,  17,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,  17,   0, 
      0,   8,  18,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,   8,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   8, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   8, 130,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
     17,   0,   0,   7,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   8,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   7,  34,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   7, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     17,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  11, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
     17,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  75,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  50,   0, 
      0,  10,  66,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  75,   0,   0,   5, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  48, 110, 
     25, 188,   1,  64,   0,   0, 
     39,  22, 152,  61,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
    132,  52,  89, 190,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
    164,  13, 201,  63,  50,   0, 
      0,  10,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 219,  15, 
    201,  63,  17,   0,   0,   7, 
     18,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     17,   0,   0,   7,  34,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   5,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  17,   0, 
      0,   7,  66,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   6,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  17,   0,   0,   7, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      7,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     15,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
     59, 170, 184, 191,  25,   0, 
      0,   5,  66,  32,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   1,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
     50,  32,  16,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      2,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0, 111,   0, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  38,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  66,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
