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
//   float4x4 projectionMatrix;         // Offset:    0 Size:    64
//
// }
//
// cbuffer PerFrame
// {
//
//   float4x4 viewMatrix;               // Offset:    0 Size:    64
//
// }
//
// cbuffer PerObject
// {
//
//   float4x4 worldMatrix;              // Offset:    0 Size:    64
//   float4x4 morphMatrix;              // Offset:   64 Size:    64
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
// COLOR                    0   xyz         1     NONE   float   xyz 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// SV_POSITION              0   xyzw        1      POS   float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[4], immediateIndexed
dcl_constantbuffer CB1[4], immediateIndexed
dcl_constantbuffer CB2[8], immediateIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_output o0.xyzw
dcl_output_siv o1.xyzw, position
dcl_temps 5
mov o0.xyz, v1.xyzx
mov o0.w, l(1.000000)
add r0.x, cb2[5].y, l(-1.000000)
add r0.y, v0.y, l(1.000000)
mul r0.y, r0.y, l(0.500000)
mad r0.x, r0.y, r0.x, l(1.000000)
mul r1.xyzw, r0.xxxx, cb2[1].xyzw
mul r0.xz, r0.yyyy, cb2[5].xxzx
mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
mad r1.xyzw, cb2[2].xyzw, r0.zzzz, r1.xyzw
mov r2.x, cb2[4].w
mov r2.y, cb2[5].w
mov r2.z, cb2[6].w
add r2.w, cb2[7].w, l(-1.000000)
mad r2.xyzw, r0.yyyy, r2.xyzw, l(0.000000, 0.000000, 0.000000, 1.000000)
mad r1.xyzw, cb2[3].xyzw, r2.yyyy, r1.xyzw
mul r3.xyzw, r1.yyyy, cb1[1].xyzw
mad r3.xyzw, cb1[0].xyzw, r1.xxxx, r3.xyzw
mad r3.xyzw, cb1[2].xyzw, r1.zzzz, r3.xyzw
mad r1.xyzw, cb1[3].xyzw, r1.wwww, r3.xyzw
mul r3.xyzw, r1.yyyy, cb0[1].xyzw
mad r3.xyzw, cb0[0].xyzw, r1.xxxx, r3.xyzw
mad r3.xyzw, cb0[2].xyzw, r1.zzzz, r3.xyzw
mad r1.xyzw, cb0[3].xyzw, r1.wwww, r3.xyzw
mul r1.xyzw, r1.xyzw, v0.yyyy
add r0.x, cb2[4].x, l(-1.000000)
mad r0.x, r0.y, r0.x, l(1.000000)
mul r0.zw, r0.yyyy, cb2[4].yyyz
mul r3.xyzw, r0.zzzz, cb2[1].xyzw
mad r3.xyzw, cb2[0].xyzw, r0.xxxx, r3.xyzw
mad r3.xyzw, cb2[2].xyzw, r0.wwww, r3.xyzw
mad r3.xyzw, cb2[3].xyzw, r2.xxxx, r3.xyzw
mul r4.xyzw, r3.yyyy, cb1[1].xyzw
mad r4.xyzw, cb1[0].xyzw, r3.xxxx, r4.xyzw
mad r4.xyzw, cb1[2].xyzw, r3.zzzz, r4.xyzw
mad r3.xyzw, cb1[3].xyzw, r3.wwww, r4.xyzw
mul r4.xyzw, r3.yyyy, cb0[1].xyzw
mad r4.xyzw, cb0[0].xyzw, r3.xxxx, r4.xyzw
mad r4.xyzw, cb0[2].xyzw, r3.zzzz, r4.xyzw
mad r3.xyzw, cb0[3].xyzw, r3.wwww, r4.xyzw
mad r1.xyzw, r3.xyzw, v0.xxxx, r1.xyzw
mul r0.xz, r0.yyyy, cb2[6].xxyx
mul r3.xyzw, r0.zzzz, cb2[1].xyzw
mad r3.xyzw, cb2[0].xyzw, r0.xxxx, r3.xyzw
add r0.x, cb2[6].z, l(-1.000000)
mad r0.x, r0.y, r0.x, l(1.000000)
mul r0.yzw, r0.yyyy, cb2[7].xxyz
mad r3.xyzw, cb2[2].xyzw, r0.xxxx, r3.xyzw
mad r3.xyzw, cb2[3].xyzw, r2.zzzz, r3.xyzw
mul r4.xyzw, r3.yyyy, cb1[1].xyzw
mad r4.xyzw, cb1[0].xyzw, r3.xxxx, r4.xyzw
mad r4.xyzw, cb1[2].xyzw, r3.zzzz, r4.xyzw
mad r3.xyzw, cb1[3].xyzw, r3.wwww, r4.xyzw
mul r4.xyzw, r3.yyyy, cb0[1].xyzw
mad r4.xyzw, cb0[0].xyzw, r3.xxxx, r4.xyzw
mad r4.xyzw, cb0[2].xyzw, r3.zzzz, r4.xyzw
mad r3.xyzw, cb0[3].xyzw, r3.wwww, r4.xyzw
mad r1.xyzw, r3.xyzw, v0.zzzz, r1.xyzw
mul r3.xyzw, r0.zzzz, cb2[1].xyzw
mad r3.xyzw, cb2[0].xyzw, r0.yyyy, r3.xyzw
mad r0.xyzw, cb2[2].xyzw, r0.wwww, r3.xyzw
mad r0.xyzw, cb2[3].xyzw, r2.wwww, r0.xyzw
mul r2.xyzw, r0.yyyy, cb1[1].xyzw
mad r2.xyzw, cb1[0].xyzw, r0.xxxx, r2.xyzw
mad r2.xyzw, cb1[2].xyzw, r0.zzzz, r2.xyzw
mad r0.xyzw, cb1[3].xyzw, r0.wwww, r2.xyzw
mul r2.xyzw, r0.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, r0.xxxx, r2.xyzw
mad r2.xyzw, cb0[2].xyzw, r0.zzzz, r2.xyzw
mad r0.xyzw, cb0[3].xyzw, r0.wwww, r2.xyzw
mad o1.xyzw, r0.xyzw, v0.wwww, r1.xyzw
ret 
// Approximately 72 instruction slots used
#endif

const BYTE g_mvs[] =
{
     68,  88,  66,  67, 200,  80, 
    133, 117,  76,  62,  72,  89, 
    188,  49,  27, 134, 131, 168, 
    219, 202,   1,   0,   0,   0, 
     32,  14,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    112,   2,   0,   0, 192,   2, 
      0,   0,  20,   3,   0,   0, 
    132,  13,   0,   0,  82,  68, 
     69,  70,  52,   2,   0,   0, 
      3,   0,   0,   0, 192,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,   0,   1,   0,   0, 
     12,   2,   0,   0,  82,  68, 
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
    156,   0,   0,   0,   1,   0, 
      0,   0,   8,   1,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    171,   0,   0,   0,   1,   0, 
      0,   0, 112,   1,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,   2,   0, 
      0,   0, 164,   1,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     48,   1,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0,  76,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 112, 114, 
    111, 106, 101,  99, 116, 105, 
    111, 110,  77,  97, 116, 114, 
    105, 120,   0, 102, 108, 111, 
     97, 116,  52, 120,  52,   0, 
    171, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  65,   1, 
      0,   0, 152,   1,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
     76,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    118, 105, 101, 119,  77,  97, 
    116, 114, 105, 120,   0, 171, 
    244,   1,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0,  76,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   0,   2, 
      0,   0,  64,   0,   0,   0, 
     64,   0,   0,   0,   2,   0, 
      0,   0,  76,   1,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 119, 111, 114, 108, 
    100,  77,  97, 116, 114, 105, 
    120,   0, 109, 111, 114, 112, 
    104,  77,  97, 116, 114, 105, 
    120,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     73,  83,  71,  78,  72,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,  56,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      7,   7,   0,   0,  80,  79, 
     83,  73,  84,  73,  79,  78, 
      0,  67,  79,  76,  79,  82, 
      0, 171,  79,  83,  71,  78, 
     76,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     62,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
     67,  79,  76,  79,  82,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
    171, 171,  83,  72,  69,  88, 
    104,  10,   0,   0,  80,   0, 
      1,   0, 154,   2,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,  95,   0, 
      0,   3, 242,  16,  16,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 104,   0,   0,   2, 
      5,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26, 128,  32,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,  16, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  56,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
     82,   0,  16,   0,   0,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,   6, 130, 
     32,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   6,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
     54,   0,   0,   6,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
     54,   0,   0,   6,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   2,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   2,   0, 
      0,   0,   7,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128, 191,  50,   0,   0,  12, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     86,  21,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      2,   0,   0,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  56,   0, 
      0,   8, 194,   0,  16,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     86, 137,  32,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   3,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  86,   5,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      4,   0,   0,   0,  86,   5, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,   6,  16,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   8,  82,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,   6, 129,  32,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   3,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  56,   0, 
      0,   8, 226,   0,  16,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
      6, 137,  32,   0,   2,   0, 
      0,   0,   7,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      3,   0,   0,   0, 166,  10, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  86,   5,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      4,   0,   0,   0,  86,   5, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0, 166,  26,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   3,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      2,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9, 242,  32, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0, 246,  31,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     72,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  66,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
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
      0,   0,   0,   0
};
