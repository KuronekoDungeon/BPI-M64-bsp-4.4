/*
 * Copyright (C) 2016 Allwinnertech, czy <chenzunyin@allwinnertech.com>
 */
#include "clk-sun8iw8.h"
/*
 * freq table from hardware, need follow rules
 * 1)   each table  named as
 *      factor_pll1_tbl
 *      factor_pll2_tbl
 *      ...
 * 2) for each table line
 *      a) follow the format PLLx(n,k,m,p,d1,d2,freq), and keep the factors order
 *      b) if any factor not used, skip it
 *      c) the factor is the value to write registers, not means factor+1
 *
 *      example
 *      PLL1(9, 0, 0, 2, 60000000) means PLL1(n,k,m,p,freq)
 *      PLLVIDEO0(3, 0, 96000000)       means PLLVIDEO0(n,m,freq)
 *
 */

//n,k,m,p,freq
struct sunxi_clk_factor_freq factor_pllcpu_tbl[] = {
  PLLCPU(     9,    0,    0,    2,    60000000U),
  PLLCPU(    10,    0,    0,    2,    66000000U),
  PLLCPU(    11,    0,    0,    2,    72000000U),
  PLLCPU(    12,    0,    0,    2,    78000000U),
  PLLCPU(    13,    0,    0,    2,    84000000U),
  PLLCPU(    14,    0,    0,    2,    90000000U),
  PLLCPU(    15,    0,    0,    2,    96000000U),
  PLLCPU(    16,    0,    0,    2,   102000000U),
  PLLCPU(    17,    0,    0,    2,   108000000U),
  PLLCPU(    18,    0,    0,    2,   114000000U),
  PLLCPU(     9,    0,    0,    1,   120000000U),
  PLLCPU(    10,    0,    0,    1,   132000000U),
  PLLCPU(    11,    0,    0,    1,   144000000U),
  PLLCPU(    12,    0,    0,    1,   156000000U),
  PLLCPU(    13,    0,    0,    1,   168000000U),
  PLLCPU(    14,    0,    0,    1,   180000000U),
  PLLCPU(    15,    0,    0,    1,   192000000U),
  PLLCPU(    16,    0,    0,    1,   204000000U),
  PLLCPU(    17,    0,    0,    1,   216000000U),
  PLLCPU(    18,    0,    0,    1,   228000000U),
  PLLCPU(     9,    0,    0,    0,   240000000U),
  PLLCPU(    10,    0,    0,    0,   264000000U),
  PLLCPU(    11,    0,    0,    0,   288000000U),
  PLLCPU(    12,    0,    0,    0,   312000000U),
  PLLCPU(    13,    0,    0,    0,   336000000U),
  PLLCPU(    14,    0,    0,    0,   360000000U),
  PLLCPU(    15,    0,    0,    0,   384000000U),
  PLLCPU(    16,    0,    0,    0,   408000000U),
  PLLCPU(    17,    0,    0,    0,   432000000U),
  PLLCPU(    18,    0,    0,    0,   456000000U),
  PLLCPU(    19,    0,    0,    0,   480000000U),
  PLLCPU(    20,    0,    0,    0,   504000000U),
  PLLCPU(    21,    0,    0,    0,   528000000U),
  PLLCPU(    22,    0,    0,    0,   552000000U),
  PLLCPU(    23,    0,    0,    0,   576000000U),
  PLLCPU(    24,    0,    0,    0,   600000000U),
  PLLCPU(    25,    0,    0,    0,   624000000U),
  PLLCPU(    26,    0,    0,    0,   648000000U),
  PLLCPU(    27,    0,    0,    0,   672000000U),
  PLLCPU(    28,    0,    0,    0,   696000000U),
  PLLCPU(    29,    0,    0,    0,   720000000U),
  PLLCPU(    15,    1,    0,    0,   768000000U),
  PLLCPU(    10,    2,    0,    0,   792000000U),
  PLLCPU(    16,    1,    0,    0,   816000000U),
  PLLCPU(    17,    1,    0,    0,   864000000U),
  PLLCPU(    18,    1,    0,    0,   912000000U),
  PLLCPU(    12,    2,    0,    0,   936000000U),
  PLLCPU(    19,    1,    0,    0,   960000000U),
  PLLCPU(    20,    1,    0,    0,  1008000000U),
  PLLCPU(    21,    1,    0,    0,  1056000000U),
  PLLCPU(    14,    2,    0,    0,  1080000000U),
  PLLCPU(    22,    1,    0,    0,  1104000000U),
  PLLCPU(    23,    1,    0,    0,  1152000000U),
  PLLCPU(    24,    1,    0,    0,  1200000000U),
  PLLCPU(    16,    2,    0,    0,  1224000000U),
  PLLCPU(    25,    1,    0,    0,  1248000000U),
  PLLCPU(    26,    1,    0,    0,  1296000000U),
  PLLCPU(    27,    1,    0,    0,  1344000000U),
  PLLCPU(    18,    2,    0,    0,  1368000000U),
  PLLCPU(    19,    2,    0,    0,  1440000000U),
  PLLCPU(    20,    2,    0,    0,  1512000000U),
  PLLCPU(    15,    3,    0,    0,  1536000000U),
  PLLCPU(    21,    2,    0,    0,  1584000000U),
  PLLCPU(    16,    3,    0,    0,  1632000000U),
  PLLCPU(    22,    2,    0,    0,  1656000000U),
  PLLCPU(    23,    2,    0,    0,  1728000000U),
  PLLCPU(    24,    2,    0,    0,  1800000000U),
  PLLCPU(    25,    2,    0,    0,  1872000000U),
};
//n,m,freq
struct sunxi_clk_factor_freq factor_pllvideo_tbl[] = {
PLLVIDEO(     6,    0,   168000000U),
PLLVIDEO(     7,    0,   192000000U),
PLLVIDEO(    24,    2,   200000000U),
PLLVIDEO(    16,    1,   204000000U),
PLLVIDEO(    25,    2,   208000000U),
PLLVIDEO(     8,    0,   216000000U),
PLLVIDEO(    36,    3,   222000000U),
PLLVIDEO(    27,    2,   224000000U),
PLLVIDEO(    18,    1,   228000000U),
PLLVIDEO(    76,    7,   231000000U),
PLLVIDEO(    28,    2,   232000000U),
PLLVIDEO(    38,    3,   234000000U),
PLLVIDEO(    78,    7,   237000000U),
PLLVIDEO(    79,    7,   240000000U),
PLLVIDEO(    80,    7,   243000000U),
PLLVIDEO(    40,    3,   246000000U),
PLLVIDEO(    30,    2,   248000000U),
PLLVIDEO(    82,    7,   249000000U),
PLLVIDEO(    20,    1,   252000000U),
PLLVIDEO(    84,    7,   255000000U),
PLLVIDEO(    31,    2,   256000000U),
PLLVIDEO(    42,    3,   258000000U),
PLLVIDEO(    86,    7,   261000000U),
PLLVIDEO(    43,    3,   264000000U),
PLLVIDEO(    88,    7,   267000000U),
PLLVIDEO(    44,    3,   270000000U),
PLLVIDEO(    33,    2,   272000000U),
PLLVIDEO(    90,    7,   273000000U),
PLLVIDEO(    22,    1,   276000000U),
PLLVIDEO(    92,    7,   279000000U),
PLLVIDEO(    34,    2,   280000000U),
PLLVIDEO(    46,    3,   282000000U),
PLLVIDEO(    94,    7,   285000000U),
PLLVIDEO(    23,    1,   288000000U),
PLLVIDEO(    96,    7,   291000000U),
PLLVIDEO(    97,    7,   294000000U),
PLLVIDEO(    36,    2,   296000000U),
PLLVIDEO(    98,    7,   297000000U),
PLLVIDEO(    24,    1,   300000000U),
PLLVIDEO(   100,    7,   303000000U),
PLLVIDEO(    37,    2,   304000000U),
PLLVIDEO(    50,    3,   306000000U),
PLLVIDEO(   102,    7,   309000000U),
PLLVIDEO(   103,    7,   312000000U),
PLLVIDEO(   104,    7,   315000000U),
PLLVIDEO(   105,    7,   318000000U),
PLLVIDEO(    39,    2,   320000000U),
PLLVIDEO(   106,    7,   321000000U),
PLLVIDEO(   107,    7,   324000000U),
PLLVIDEO(   108,    7,   327000000U),
PLLVIDEO(    40,    2,   328000000U),
PLLVIDEO(   109,    7,   330000000U),
PLLVIDEO(   110,    7,   333000000U),
PLLVIDEO(    55,    3,   336000000U),
PLLVIDEO(   112,    7,   339000000U),
PLLVIDEO(    56,    3,   342000000U),
PLLVIDEO(   114,    7,   345000000U),
PLLVIDEO(    57,    3,   348000000U),
PLLVIDEO(   116,    7,   351000000U),
PLLVIDEO(   117,    7,   354000000U),
PLLVIDEO(   118,    7,   357000000U),
PLLVIDEO(    29,    1,   360000000U),
PLLVIDEO(   120,    7,   363000000U),
PLLVIDEO(   121,    7,   366000000U),
PLLVIDEO(   122,    7,   369000000U),
PLLVIDEO(   123,    7,   372000000U),
PLLVIDEO(   124,    7,   375000000U),
PLLVIDEO(    62,    3,   378000000U),
PLLVIDEO(   126,    7,   381000000U),
PLLVIDEO(    63,    3,   384000000U),
PLLVIDEO(    64,    3,   390000000U),
PLLVIDEO(    65,    3,   396000000U),
PLLVIDEO(    66,    3,   402000000U),
PLLVIDEO(    67,    3,   408000000U),
PLLVIDEO(    68,    3,   414000000U),
PLLVIDEO(    34,    1,   420000000U),
PLLVIDEO(    70,    3,   426000000U),
PLLVIDEO(    17,    0,   432000000U),
PLLVIDEO(    72,    3,   438000000U),
PLLVIDEO(    73,    3,   444000000U),
PLLVIDEO(    74,    3,   450000000U),
PLLVIDEO(    37,    1,   456000000U),
PLLVIDEO(    76,    3,   462000000U),
PLLVIDEO(    77,    3,   468000000U),
PLLVIDEO(    78,    3,   474000000U),
PLLVIDEO(    19,    0,   480000000U),
PLLVIDEO(    80,    3,   486000000U),
PLLVIDEO(    40,    1,   492000000U),
PLLVIDEO(    82,    3,   498000000U),
PLLVIDEO(    20,    0,   504000000U),
PLLVIDEO(    84,    3,   510000000U),
PLLVIDEO(    85,    3,   516000000U),
PLLVIDEO(    86,    3,   522000000U),
PLLVIDEO(    87,    3,   528000000U),
PLLVIDEO(    88,    3,   534000000U),
PLLVIDEO(    89,    3,   540000000U),
PLLVIDEO(    90,    3,   546000000U),
PLLVIDEO(    22,    0,   552000000U),
PLLVIDEO(    92,    3,   558000000U),
PLLVIDEO(    93,    3,   564000000U),
PLLVIDEO(    94,    3,   570000000U),
PLLVIDEO(    95,    3,   576000000U),
PLLVIDEO(    96,    3,   582000000U),
PLLVIDEO(    97,    3,   588000000U),
PLLVIDEO(    98,    3,   594000000U),
PLLVIDEO(    24,    0,   600000000U),
PLLVIDEO(   100,    3,   606000000U),
PLLVIDEO(   101,    3,   612000000U),
PLLVIDEO(   102,    3,   618000000U),
PLLVIDEO(   103,    3,   624000000U),
PLLVIDEO(   104,    3,   630000000U),
PLLVIDEO(   105,    3,   636000000U),
PLLVIDEO(   106,    3,   642000000U),
PLLVIDEO(   107,    3,   648000000U),
PLLVIDEO(   108,    3,   654000000U),
PLLVIDEO(   109,    3,   660000000U),
PLLVIDEO(   110,    3,   666000000U),
PLLVIDEO(   111,    3,   672000000U),
PLLVIDEO(   112,    3,   678000000U),
PLLVIDEO(   113,    3,   684000000U),
PLLVIDEO(   114,    3,   690000000U),
PLLVIDEO(   115,    3,   696000000U),
PLLVIDEO(   116,    3,   702000000U),
PLLVIDEO(   117,    3,   708000000U),
PLLVIDEO(   118,    3,   714000000U),
PLLVIDEO(    29,    0,   720000000U),
PLLVIDEO(   120,    3,   726000000U),
PLLVIDEO(   121,    3,   732000000U),
PLLVIDEO(   122,    3,   738000000U),
PLLVIDEO(   123,    3,   744000000U),
PLLVIDEO(   124,    3,   750000000U),
PLLVIDEO(   125,    3,   756000000U),
PLLVIDEO(   126,    3,   762000000U),
PLLVIDEO(   127,    3,   768000000U),
PLLVIDEO(    32,    0,   792000000U),
PLLVIDEO(    33,    0,   816000000U),
PLLVIDEO(    34,    0,   840000000U),
PLLVIDEO(    35,    0,   864000000U),
PLLVIDEO(    36,    0,   888000000U),
PLLVIDEO(    37,    0,   912000000U),
PLLVIDEO(    38,    0,   936000000U),
};
//n,m,freq
struct sunxi_clk_factor_freq factor_pllve_tbl[] = {
   PLLVE(     4,    0,   120000000U),
   PLLVE(    16,    2,   136000000U),
   PLLVE(     5,    0,   144000000U),
   PLLVE(    18,    2,   152000000U),
   PLLVE(    25,    3,   156000000U),
   PLLVE(    19,    2,   160000000U),
   PLLVE(    26,    3,   162000000U),
   PLLVE(    54,    7,   165000000U),
   PLLVE(     6,    0,   168000000U),
   PLLVE(    56,    7,   171000000U),
   PLLVE(    57,    7,   174000000U),
   PLLVE(    21,    2,   176000000U),
   PLLVE(    58,    7,   177000000U),
   PLLVE(    14,    1,   180000000U),
   PLLVE(    22,    2,   184000000U),
   PLLVE(    30,    3,   186000000U),
   PLLVE(    62,    7,   189000000U),
   PLLVE(    31,    3,   192000000U),
   PLLVE(    64,    7,   195000000U),
   PLLVE(    65,    7,   198000000U),
   PLLVE(    24,    2,   200000000U),
   PLLVE(    66,    7,   201000000U),
   PLLVE(    33,    3,   204000000U),
   PLLVE(    68,    7,   207000000U),
   PLLVE(    25,    2,   208000000U),
   PLLVE(    34,    3,   210000000U),
   PLLVE(    70,    7,   213000000U),
   PLLVE(     8,    0,   216000000U),
   PLLVE(    72,    7,   219000000U),
   PLLVE(    73,    7,   222000000U),
   PLLVE(    27,    2,   224000000U),
   PLLVE(    74,    7,   225000000U),
   PLLVE(    18,    1,   228000000U),
   PLLVE(    76,    7,   231000000U),
   PLLVE(    28,    2,   232000000U),
   PLLVE(    38,    3,   234000000U),
   PLLVE(    78,    7,   237000000U),
   PLLVE(    39,    3,   240000000U),
   PLLVE(    80,    7,   243000000U),
   PLLVE(    81,    7,   246000000U),
   PLLVE(    30,    2,   248000000U),
   PLLVE(    82,    7,   249000000U),
   PLLVE(    83,    7,   252000000U),
   PLLVE(    84,    7,   255000000U),
   PLLVE(    31,    2,   256000000U),
   PLLVE(    42,    3,   258000000U),
   PLLVE(    86,    7,   261000000U),
   PLLVE(    43,    3,   264000000U),
   PLLVE(    88,    7,   267000000U),
   PLLVE(    44,    3,   270000000U),
   PLLVE(    33,    2,   272000000U),
   PLLVE(    90,    7,   273000000U),
   PLLVE(    45,    3,   276000000U),
   PLLVE(    92,    7,   279000000U),
   PLLVE(    34,    2,   280000000U),
   PLLVE(    93,    7,   282000000U),
   PLLVE(    94,    7,   285000000U),
   PLLVE(    95,    7,   288000000U),
   PLLVE(    96,    7,   291000000U),
   PLLVE(    97,    7,   294000000U),
   PLLVE(    36,    2,   296000000U),
   PLLVE(    98,    7,   297000000U),
   PLLVE(    49,    3,   300000000U),
   PLLVE(   100,    7,   303000000U),
   PLLVE(    37,    2,   304000000U),
   PLLVE(    50,    3,   306000000U),
   PLLVE(   102,    7,   309000000U),
   PLLVE(    12,    0,   312000000U),
   PLLVE(   104,    7,   315000000U),
   PLLVE(    52,    3,   318000000U),
   PLLVE(    39,    2,   320000000U),
   PLLVE(   107,    7,   324000000U),
   PLLVE(   108,    7,   327000000U),
   PLLVE(    40,    2,   328000000U),
   PLLVE(   109,    7,   330000000U),
   PLLVE(   110,    7,   333000000U),
   PLLVE(    55,    3,   336000000U),
   PLLVE(   112,    7,   339000000U),
   PLLVE(   113,    7,   342000000U),
   PLLVE(   114,    7,   345000000U),
   PLLVE(    57,    3,   348000000U),
   PLLVE(   116,    7,   351000000U),
   PLLVE(   117,    7,   354000000U),
   PLLVE(   118,    7,   357000000U),
   PLLVE(    14,    0,   360000000U),
   PLLVE(   120,    7,   363000000U),
   PLLVE(   121,    7,   366000000U),
   PLLVE(   122,    7,   369000000U),
   PLLVE(   123,    7,   372000000U),
   PLLVE(   124,    7,   375000000U),
   PLLVE(    62,    3,   378000000U),
   PLLVE(   126,    7,   381000000U),
   PLLVE(   127,    7,   384000000U),
   PLLVE(    64,    3,   390000000U),
   PLLVE(    65,    3,   396000000U),
   PLLVE(    66,    3,   402000000U),
   PLLVE(    16,    0,   408000000U),
   PLLVE(    68,    3,   414000000U),
   PLLVE(    34,    1,   420000000U),
   PLLVE(    70,    3,   426000000U),
   PLLVE(    71,    3,   432000000U),
   PLLVE(    72,    3,   438000000U),
   PLLVE(    36,    1,   444000000U),
   PLLVE(    74,    3,   450000000U),
   PLLVE(    37,    1,   456000000U),
   PLLVE(    76,    3,   462000000U),
   PLLVE(    38,    1,   468000000U),
   PLLVE(    78,    3,   474000000U),
   PLLVE(    39,    1,   480000000U),
   PLLVE(    80,    3,   486000000U),
   PLLVE(    81,    3,   492000000U),
   PLLVE(    82,    3,   498000000U),
   PLLVE(    41,    1,   504000000U),
   PLLVE(    84,    3,   510000000U),
   PLLVE(    85,    3,   516000000U),
   PLLVE(    86,    3,   522000000U),
   PLLVE(    87,    3,   528000000U),
   PLLVE(    88,    3,   534000000U),
   PLLVE(    89,    3,   540000000U),
   PLLVE(    90,    3,   546000000U),
   PLLVE(    91,    3,   552000000U),
   PLLVE(    92,    3,   558000000U),
   PLLVE(    93,    3,   564000000U),
   PLLVE(    94,    3,   570000000U),
   PLLVE(    95,    3,   576000000U),
   PLLVE(    96,    3,   582000000U),
   PLLVE(    97,    3,   588000000U),
   PLLVE(    98,    3,   594000000U),
   PLLVE(    99,    3,   600000000U),
   PLLVE(   100,    3,   606000000U),
   PLLVE(   101,    3,   612000000U),
   PLLVE(   102,    3,   618000000U),
   PLLVE(    25,    0,   624000000U),
   PLLVE(   104,    3,   630000000U),
   PLLVE(   105,    3,   636000000U),
   PLLVE(   106,    3,   642000000U),
   PLLVE(    26,    0,   648000000U),
   PLLVE(   108,    3,   654000000U),
   PLLVE(   109,    3,   660000000U),
   PLLVE(   110,    3,   666000000U),
   PLLVE(   111,    3,   672000000U),
   PLLVE(   112,    3,   678000000U),
   PLLVE(   113,    3,   684000000U),
   PLLVE(   114,    3,   690000000U),
   PLLVE(    28,    0,   696000000U),
   PLLVE(   116,    3,   702000000U),
   PLLVE(   117,    3,   708000000U),
   PLLVE(   118,    3,   714000000U),
   PLLVE(    29,    0,   720000000U),
   PLLVE(   120,    3,   726000000U),
   PLLVE(   121,    3,   732000000U),
   PLLVE(   122,    3,   738000000U),
   PLLVE(    30,    0,   744000000U),
   PLLVE(   124,    3,   750000000U),
   PLLVE(   125,    3,   756000000U),
   PLLVE(   126,    3,   762000000U),
   PLLVE(    31,    0,   768000000U),
   PLLVE(    32,    0,   792000000U),
   PLLVE(    33,    0,   816000000U),
   PLLVE(    34,    0,   840000000U),
   PLLVE(    35,    0,   864000000U),
   PLLVE(    36,    0,   888000000U),
   PLLVE(    37,    0,   912000000U),
};
//n,k,m,freq
struct sunxi_clk_factor_freq factor_pllddr0_tbl[] = {
 PLLDDR0(     0,    1,    3,    12000000U),
 PLLDDR0(     0,    2,    2,    24000000U),
 PLLDDR0(     2,    1,    3,    36000000U),
 PLLDDR0(     3,    1,    3,    48000000U),
 PLLDDR0(     8,    0,    3,    54000000U),
 PLLDDR0(     9,    0,    3,    60000000U),
 PLLDDR0(     7,    0,    2,    64000000U),
 PLLDDR0(    10,    0,    3,    66000000U),
 PLLDDR0(     3,    2,    3,    72000000U),
 PLLDDR0(    12,    0,    3,    78000000U),
 PLLDDR0(     9,    0,    2,    80000000U),
 PLLDDR0(     6,    1,    3,    84000000U),
 PLLDDR0(    10,    0,    2,    88000000U),
 PLLDDR0(     4,    2,    3,    90000000U),
 PLLDDR0(     3,    3,    3,    96000000U),
 PLLDDR0(    16,    0,    3,   102000000U),
 PLLDDR0(    12,    0,    2,   104000000U),
 PLLDDR0(     5,    2,    3,   108000000U),
 PLLDDR0(     6,    1,    2,   112000000U),
 PLLDDR0(    18,    0,    3,   114000000U),
 PLLDDR0(     9,    1,    3,   120000000U),
 PLLDDR0(     6,    2,    3,   126000000U),
 PLLDDR0(    15,    0,    2,   128000000U),
 PLLDDR0(    21,    0,    3,   132000000U),
 PLLDDR0(    16,    0,    2,   136000000U),
 PLLDDR0(    22,    0,    3,   138000000U),
 PLLDDR0(     7,    2,    3,   144000000U),
 PLLDDR0(    24,    0,    3,   150000000U),
 PLLDDR0(    18,    0,    2,   152000000U),
 PLLDDR0(    25,    0,    3,   156000000U),
 PLLDDR0(    19,    0,    2,   160000000U),
 PLLDDR0(     8,    2,    3,   162000000U),
 PLLDDR0(    27,    0,    3,   168000000U),
 PLLDDR0(    28,    0,    3,   174000000U),
 PLLDDR0(    10,    1,    2,   176000000U),
 PLLDDR0(     9,    2,    3,   180000000U),
 PLLDDR0(    22,    0,    2,   184000000U),
 PLLDDR0(    30,    0,    3,   186000000U),
 PLLDDR0(    23,    0,    2,   192000000U),
 PLLDDR0(    10,    2,    3,   198000000U),
 PLLDDR0(    24,    0,    2,   200000000U),
 PLLDDR0(    16,    1,    3,   204000000U),
 PLLDDR0(    25,    0,    2,   208000000U),
 PLLDDR0(    11,    2,    3,   216000000U),
 PLLDDR0(     6,    3,    2,   224000000U),
 PLLDDR0(    18,    1,    3,   228000000U),
 PLLDDR0(    28,    0,    2,   232000000U),
 PLLDDR0(    12,    2,    3,   234000000U),
 PLLDDR0(    19,    0,    1,   240000000U),
 PLLDDR0(    30,    0,    2,   248000000U),
 PLLDDR0(    20,    1,    3,   252000000U),
 PLLDDR0(    15,    1,    2,   256000000U),
 PLLDDR0(    21,    0,    1,   264000000U),
 PLLDDR0(    14,    2,    3,   270000000U),
 PLLDDR0(    16,    1,    2,   272000000U),
 PLLDDR0(    22,    1,    3,   276000000U),
 PLLDDR0(    11,    2,    2,   288000000U),
 PLLDDR0(    24,    0,    1,   300000000U),
 PLLDDR0(    18,    1,    2,   304000000U),
 PLLDDR0(    16,    2,    3,   306000000U),
 PLLDDR0(    25,    1,    3,   312000000U),
 PLLDDR0(    19,    1,    2,   320000000U),
 PLLDDR0(    26,    0,    1,   324000000U),
 PLLDDR0(    13,    2,    2,   336000000U),
 PLLDDR0(    18,    2,    3,   342000000U),
 PLLDDR0(    28,    0,    1,   348000000U),
 PLLDDR0(    10,    3,    2,   352000000U),
 PLLDDR0(    14,    1,    1,   360000000U),
 PLLDDR0(    22,    1,    2,   368000000U),
 PLLDDR0(    30,    0,    1,   372000000U),
 PLLDDR0(    20,    2,    3,   378000000U),
 PLLDDR0(    23,    1,    2,   384000000U),
 PLLDDR0(    10,    2,    1,   396000000U),
 PLLDDR0(    24,    1,    2,   400000000U),
 PLLDDR0(    16,    1,    1,   408000000U),
 PLLDDR0(    22,    2,    3,   414000000U),
 PLLDDR0(    12,    3,    2,   416000000U),
 PLLDDR0(    26,    1,    2,   432000000U),
 PLLDDR0(    13,    3,    2,   448000000U),
 PLLDDR0(    24,    2,    3,   450000000U),
 PLLDDR0(    18,    0,    0,   456000000U),
 PLLDDR0(    28,    1,    2,   464000000U),
 PLLDDR0(    12,    2,    1,   468000000U),
 PLLDDR0(    19,    2,    2,   480000000U),
 PLLDDR0(    30,    1,    2,   496000000U),
 PLLDDR0(    20,    2,    2,   504000000U),
 PLLDDR0(    31,    1,    2,   512000000U),
 PLLDDR0(    10,    3,    1,   528000000U),
 PLLDDR0(    14,    2,    1,   540000000U),
 PLLDDR0(    16,    3,    2,   544000000U),
 PLLDDR0(    22,    0,    0,   552000000U),
 PLLDDR0(    23,    2,    2,   576000000U),
 PLLDDR0(    24,    1,    1,   600000000U),
 PLLDDR0(    18,    3,    2,   608000000U),
 PLLDDR0(    16,    2,    1,   612000000U),
 PLLDDR0(    25,    1,    1,   624000000U),
 PLLDDR0(    19,    3,    2,   640000000U),
 PLLDDR0(    17,    2,    1,   648000000U),
 PLLDDR0(    27,    0,    0,   672000000U),
 PLLDDR0(    18,    2,    1,   684000000U),
 PLLDDR0(    28,    1,    1,   696000000U),
 PLLDDR0(     9,    2,    0,   720000000U),
 PLLDDR0(    30,    1,    1,   744000000U),
 PLLDDR0(    20,    2,    1,   756000000U),
 PLLDDR0(     7,    3,    0,   768000000U),
 PLLDDR0(    21,    2,    1,   792000000U),
 PLLDDR0(    16,    3,    1,   816000000U),
 PLLDDR0(    22,    2,    1,   828000000U),
 PLLDDR0(    17,    3,    1,   864000000U),
 PLLDDR0(    24,    2,    1,   900000000U),
 PLLDDR0(    18,    3,    1,   912000000U),
 PLLDDR0(    12,    2,    0,   936000000U),
 PLLDDR0(     9,    3,    0,   960000000U),
 PLLDDR0(    13,    2,    0,  1008000000U),
 PLLDDR0(    10,    3,    0,  1056000000U),
 PLLDDR0(    14,    2,    0,  1080000000U),
 PLLDDR0(    22,    1,    0,  1104000000U),
 PLLDDR0(    15,    2,    0,  1152000000U),
 PLLDDR0(    24,    1,    0,  1200000000U),
 PLLDDR0(    16,    2,    0,  1224000000U),
 PLLDDR0(    25,    1,    0,  1248000000U),
 PLLDDR0(    26,    1,    0,  1296000000U),
 PLLDDR0(    13,    3,    0,  1344000000U),
 PLLDDR0(    18,    2,    0,  1368000000U),
 PLLDDR0(    28,    1,    0,  1392000000U),
 PLLDDR0(    14,    3,    0,  1440000000U),
 PLLDDR0(    30,    1,    0,  1488000000U),
 PLLDDR0(    20,    2,    0,  1512000000U),
 PLLDDR0(    15,    3,    0,  1536000000U),
 PLLDDR0(    21,    2,    0,  1584000000U),
 PLLDDR0(    16,    3,    0,  1632000000U),
 PLLDDR0(    22,    2,    0,  1656000000U),
 PLLDDR0(    23,    2,    0,  1728000000U),
 PLLDDR0(    24,    2,    0,  1800000000U),
 PLLDDR0(    18,    3,    0,  1824000000U),
 PLLDDR0(    25,    2,    0,  1872000000U),
 PLLDDR0(    19,    3,    0,  1920000000U),
};
//n,k,freq
struct sunxi_clk_factor_freq factor_pllperiph0_tbl[] = {
PLLPERIPH(     1,    3,    96000000U),
PLLPERIPH(     8,    0,   108000000U),
PLLPERIPH(     9,    0,   120000000U),
PLLPERIPH(    10,    0,   132000000U),
PLLPERIPH(     3,    2,   144000000U),
PLLPERIPH(    12,    0,   156000000U),
PLLPERIPH(    13,    0,   168000000U),
PLLPERIPH(    14,    0,   180000000U),
PLLPERIPH(     7,    1,   192000000U),
PLLPERIPH(    16,    0,   204000000U),
PLLPERIPH(    17,    0,   216000000U),
PLLPERIPH(    18,    0,   228000000U),
PLLPERIPH(     4,    3,   240000000U),
PLLPERIPH(     6,    2,   252000000U),
PLLPERIPH(    21,    0,   264000000U),
PLLPERIPH(     7,    2,   288000000U),
PLLPERIPH(    24,    0,   300000000U),
PLLPERIPH(    25,    0,   312000000U),
PLLPERIPH(    26,    0,   324000000U),
PLLPERIPH(     6,    3,   336000000U),
PLLPERIPH(    28,    0,   348000000U),
PLLPERIPH(     9,    2,   360000000U),
PLLPERIPH(    30,    0,   372000000U),
PLLPERIPH(    31,    0,   384000000U),
PLLPERIPH(    10,    2,   396000000U),
PLLPERIPH(    16,    1,   408000000U),
PLLPERIPH(    17,    1,   432000000U),
PLLPERIPH(    18,    1,   456000000U),
PLLPERIPH(    12,    2,   468000000U),
PLLPERIPH(    19,    1,   480000000U),
PLLPERIPH(    20,    1,   504000000U),
PLLPERIPH(    10,    3,   528000000U),
PLLPERIPH(    14,    2,   540000000U),
PLLPERIPH(    22,    1,   552000000U),
PLLPERIPH(    11,    3,   576000000U),
PLLPERIPH(    24,    1,   600000000U),
PLLPERIPH(    16,    2,   612000000U),
PLLPERIPH(    25,    1,   624000000U),
PLLPERIPH(    17,    2,   648000000U),
PLLPERIPH(    13,    3,   672000000U),
PLLPERIPH(    18,    2,   684000000U),
PLLPERIPH(    28,    1,   696000000U),
PLLPERIPH(    29,    1,   720000000U),
PLLPERIPH(    30,    1,   744000000U),
};

//n,m,freq
struct sunxi_clk_factor_freq factor_pllisp_tbl[] = {
  PLLISP(     4,    0,   120000000U),
  PLLISP(     5,    0,   144000000U),
  PLLISP(    18,    2,   152000000U),
  PLLISP(    12,    1,   156000000U),
  PLLISP(    19,    2,   160000000U),
  PLLISP(     6,    0,   168000000U),
  PLLISP(    28,    3,   174000000U),
  PLLISP(    21,    2,   176000000U),
  PLLISP(    14,    1,   180000000U),
  PLLISP(    22,    2,   184000000U),
  PLLISP(    30,    3,   186000000U),
  PLLISP(    62,    7,   189000000U),
  PLLISP(    31,    3,   192000000U),
  PLLISP(    64,    7,   195000000U),
  PLLISP(    32,    3,   198000000U),
  PLLISP(    24,    2,   200000000U),
  PLLISP(    66,    7,   201000000U),
  PLLISP(    16,    1,   204000000U),
  PLLISP(    68,    7,   207000000U),
  PLLISP(    25,    2,   208000000U),
  PLLISP(    34,    3,   210000000U),
  PLLISP(    70,    7,   213000000U),
  PLLISP(    35,    3,   216000000U),
  PLLISP(    72,    7,   219000000U),
  PLLISP(    36,    3,   222000000U),
  PLLISP(    27,    2,   224000000U),
  PLLISP(    74,    7,   225000000U),
  PLLISP(    18,    1,   228000000U),
  PLLISP(    76,    7,   231000000U),
  PLLISP(    28,    2,   232000000U),
  PLLISP(    38,    3,   234000000U),
  PLLISP(    78,    7,   237000000U),
  PLLISP(    29,    2,   240000000U),
  PLLISP(    80,    7,   243000000U),
  PLLISP(    40,    3,   246000000U),
  PLLISP(    30,    2,   248000000U),
  PLLISP(    82,    7,   249000000U),
  PLLISP(    20,    1,   252000000U),
  PLLISP(    84,    7,   255000000U),
  PLLISP(    31,    2,   256000000U),
  PLLISP(    42,    3,   258000000U),
  PLLISP(    86,    7,   261000000U),
  PLLISP(    10,    0,   264000000U),
  PLLISP(    88,    7,   267000000U),
  PLLISP(    44,    3,   270000000U),
  PLLISP(    33,    2,   272000000U),
  PLLISP(    90,    7,   273000000U),
  PLLISP(    45,    3,   276000000U),
  PLLISP(    92,    7,   279000000U),
  PLLISP(    34,    2,   280000000U),
  PLLISP(    93,    7,   282000000U),
  PLLISP(    94,    7,   285000000U),
  PLLISP(    23,    1,   288000000U),
  PLLISP(    96,    7,   291000000U),
  PLLISP(    97,    7,   294000000U),
  PLLISP(    36,    2,   296000000U),
  PLLISP(    98,    7,   297000000U),
  PLLISP(    24,    1,   300000000U),
  PLLISP(   100,    7,   303000000U),
  PLLISP(    37,    2,   304000000U),
  PLLISP(    50,    3,   306000000U),
  PLLISP(   102,    7,   309000000U),
  PLLISP(    25,    1,   312000000U),
  PLLISP(   104,    7,   315000000U),
  PLLISP(    52,    3,   318000000U),
  PLLISP(    39,    2,   320000000U),
  PLLISP(   106,    7,   321000000U),
  PLLISP(    26,    1,   324000000U),
  PLLISP(   108,    7,   327000000U),
  PLLISP(    40,    2,   328000000U),
  PLLISP(    54,    3,   330000000U),
  PLLISP(   110,    7,   333000000U),
  PLLISP(    41,    2,   336000000U),
  PLLISP(   112,    7,   339000000U),
  PLLISP(   113,    7,   342000000U),
  PLLISP(   114,    7,   345000000U),
  PLLISP(    28,    1,   348000000U),
  PLLISP(   116,    7,   351000000U),
  PLLISP(   117,    7,   354000000U),
  PLLISP(   118,    7,   357000000U),
  PLLISP(    29,    1,   360000000U),
  PLLISP(   120,    7,   363000000U),
  PLLISP(   121,    7,   366000000U),
  PLLISP(   122,    7,   369000000U),
  PLLISP(    30,    1,   372000000U),
  PLLISP(   124,    7,   375000000U),
  PLLISP(   125,    7,   378000000U),
  PLLISP(   126,    7,   381000000U),
  PLLISP(    15,    0,   384000000U),
  PLLISP(    64,    3,   390000000U),
  PLLISP(    65,    3,   396000000U),
  PLLISP(    66,    3,   402000000U),
  PLLISP(    16,    0,   408000000U),
  PLLISP(    68,    3,   414000000U),
  PLLISP(    34,    1,   420000000U),
  PLLISP(    70,    3,   426000000U),
  PLLISP(    17,    0,   432000000U),
  PLLISP(    72,    3,   438000000U),
  PLLISP(    36,    1,   444000000U),
  PLLISP(    74,    3,   450000000U),
  PLLISP(    75,    3,   456000000U),
  PLLISP(    76,    3,   462000000U),
  PLLISP(    77,    3,   468000000U),
  PLLISP(    78,    3,   474000000U),
  PLLISP(    79,    3,   480000000U),
  PLLISP(    80,    3,   486000000U),
  PLLISP(    81,    3,   492000000U),
  PLLISP(    82,    3,   498000000U),
  PLLISP(    41,    1,   504000000U),
  PLLISP(    84,    3,   510000000U),
  PLLISP(    85,    3,   516000000U),
  PLLISP(    86,    3,   522000000U),
  PLLISP(    21,    0,   528000000U),
  PLLISP(    88,    3,   534000000U),
  PLLISP(    89,    3,   540000000U),
  PLLISP(    90,    3,   546000000U),
  PLLISP(    91,    3,   552000000U),
  PLLISP(    92,    3,   558000000U),
  PLLISP(    93,    3,   564000000U),
  PLLISP(    94,    3,   570000000U),
  PLLISP(    95,    3,   576000000U),
  PLLISP(    96,    3,   582000000U),
  PLLISP(    97,    3,   588000000U),
  PLLISP(    98,    3,   594000000U),
  PLLISP(    99,    3,   600000000U),
  PLLISP(   100,    3,   606000000U),
  PLLISP(   101,    3,   612000000U),
  PLLISP(   102,    3,   618000000U),
  PLLISP(    25,    0,   624000000U),
  PLLISP(   104,    3,   630000000U),
  PLLISP(   105,    3,   636000000U),
  PLLISP(   106,    3,   642000000U),
  PLLISP(   107,    3,   648000000U),
  PLLISP(   108,    3,   654000000U),
  PLLISP(   109,    3,   660000000U),
  PLLISP(   110,    3,   666000000U),
  PLLISP(    27,    0,   672000000U),
  PLLISP(   112,    3,   678000000U),
  PLLISP(   113,    3,   684000000U),
  PLLISP(   114,    3,   690000000U),
  PLLISP(   115,    3,   696000000U),
  PLLISP(   116,    3,   702000000U),
  PLLISP(   117,    3,   708000000U),
  PLLISP(   118,    3,   714000000U),
  PLLISP(    29,    0,   720000000U),
  PLLISP(   120,    3,   726000000U),
  PLLISP(   121,    3,   732000000U),
  PLLISP(   122,    3,   738000000U),
  PLLISP(   123,    3,   744000000U),
  PLLISP(   124,    3,   750000000U),
  PLLISP(   125,    3,   756000000U),
  PLLISP(   126,    3,   762000000U),
  PLLISP(   127,    3,   768000000U),
  PLLISP(    32,    0,   792000000U),
  PLLISP(    33,    0,   816000000U),
};

//n,k,freq
struct sunxi_clk_factor_freq factor_pllperiph1_tbl[] = {
PLLPERIPH(     7,    0,    96000000U),
PLLPERIPH(     8,    0,   108000000U),
PLLPERIPH(     4,    1,   120000000U),
PLLPERIPH(    10,    0,   132000000U),
PLLPERIPH(    11,    0,   144000000U),
PLLPERIPH(    12,    0,   156000000U),
PLLPERIPH(     6,    1,   168000000U),
PLLPERIPH(     4,    2,   180000000U),
PLLPERIPH(    15,    0,   192000000U),
PLLPERIPH(    16,    0,   204000000U),
PLLPERIPH(     8,    1,   216000000U),
PLLPERIPH(    18,    0,   228000000U),
PLLPERIPH(     9,    1,   240000000U),
PLLPERIPH(     6,    2,   252000000U),
PLLPERIPH(    10,    1,   264000000U),
PLLPERIPH(    22,    0,   276000000U),
PLLPERIPH(    23,    0,   288000000U),
PLLPERIPH(    24,    0,   300000000U),
PLLPERIPH(    25,    0,   312000000U),
PLLPERIPH(    26,    0,   324000000U),
PLLPERIPH(    27,    0,   336000000U),
PLLPERIPH(    28,    0,   348000000U),
PLLPERIPH(     9,    2,   360000000U),
PLLPERIPH(    30,    0,   372000000U),
PLLPERIPH(    15,    1,   384000000U),
PLLPERIPH(    10,    2,   396000000U),
PLLPERIPH(    16,    1,   408000000U),
PLLPERIPH(    17,    1,   432000000U),
PLLPERIPH(    18,    1,   456000000U),
PLLPERIPH(    12,    2,   468000000U),
PLLPERIPH(    19,    1,   480000000U),
PLLPERIPH(    20,    1,   504000000U),
PLLPERIPH(    10,    3,   528000000U),
PLLPERIPH(    14,    2,   540000000U),
PLLPERIPH(    22,    1,   552000000U),
PLLPERIPH(    11,    3,   576000000U),
PLLPERIPH(    24,    1,   600000000U),
PLLPERIPH(    16,    2,   612000000U),
PLLPERIPH(    25,    1,   624000000U),
PLLPERIPH(    26,    1,   648000000U),
PLLPERIPH(    27,    1,   672000000U),
PLLPERIPH(    18,    2,   684000000U),
PLLPERIPH(    28,    1,   696000000U),
PLLPERIPH(    29,    1,   720000000U),
PLLPERIPH(    30,    1,   744000000U),
};

//n,m,freq
struct sunxi_clk_factor_freq factor_pllddr1_tbl[] = {
 PLLDDR1(     8,    0,   216000000U),
 PLLDDR1(     9,    0,   240000000U),
 PLLDDR1(    10,    0,   264000000U),
 PLLDDR1(    11,    0,   288000000U),
 PLLDDR1(    12,    0,   312000000U),
 PLLDDR1(    13,    0,   336000000U),
 PLLDDR1(    14,    0,   360000000U),
 PLLDDR1(    15,    0,   384000000U),
 PLLDDR1(    16,    0,   408000000U),
 PLLDDR1(    17,    0,   432000000U),
 PLLDDR1(    18,    0,   456000000U),
 PLLDDR1(    19,    0,   480000000U),
 PLLDDR1(    20,    0,   504000000U),
 PLLDDR1(    21,    0,   528000000U),
 PLLDDR1(    22,    0,   552000000U),
 PLLDDR1(    23,    0,   576000000U),
 PLLDDR1(    24,    0,   600000000U),
 PLLDDR1(    25,    0,   624000000U),
 PLLDDR1(    26,    0,   648000000U),
 PLLDDR1(    27,    0,   672000000U),
 PLLDDR1(    28,    0,   696000000U),
 PLLDDR1(    29,    0,   720000000U),
 PLLDDR1(    30,    0,   744000000U),
 PLLDDR1(    31,    0,   768000000U),
 PLLDDR1(    32,    0,   792000000U),
 PLLDDR1(    33,    0,   816000000U),
 PLLDDR1(    34,    0,   840000000U),
 PLLDDR1(    35,    0,   864000000U),
 PLLDDR1(    36,    0,   888000000U),
 PLLDDR1(    37,    0,   912000000U),
 PLLDDR1(    38,    0,   936000000U),
 PLLDDR1(    39,    0,   960000000U),
 PLLDDR1(    40,    0,   984000000U),
 PLLDDR1(    41,    0,  1008000000U),
 PLLDDR1(    42,    0,  1032000000U),
 PLLDDR1(    43,    0,  1056000000U),
 PLLDDR1(    44,    0,  1080000000U),
 PLLDDR1(    45,    0,  1104000000U),
 PLLDDR1(    46,    0,  1128000000U),
 PLLDDR1(    47,    0,  1152000000U),
 PLLDDR1(    48,    0,  1176000000U),
 PLLDDR1(    49,    0,  1200000000U),
 PLLDDR1(    50,    0,  1224000000U),
 PLLDDR1(    51,    0,  1248000000U),
 PLLDDR1(    52,    0,  1272000000U),
 PLLDDR1(    53,    0,  1296000000U),
 PLLDDR1(    54,    0,  1320000000U),
 PLLDDR1(    55,    0,  1344000000U),
 PLLDDR1(    56,    0,  1368000000U),
 PLLDDR1(    57,    0,  1392000000U),
 PLLDDR1(    58,    0,  1416000000U),
 PLLDDR1(    59,    0,  1440000000U),
 PLLDDR1(    60,    0,  1464000000U),
 PLLDDR1(    61,    0,  1488000000U),
 PLLDDR1(    62,    0,  1512000000U),
 PLLDDR1(    63,    0,  1536000000U),
 PLLDDR1(    64,    0,  1560000000U),
 PLLDDR1(    65,    0,  1584000000U),
 PLLDDR1(    66,    0,  1608000000U),
 PLLDDR1(    67,    0,  1632000000U),
 PLLDDR1(    68,    0,  1656000000U),
 PLLDDR1(    69,    0,  1680000000U),
 PLLDDR1(    70,    0,  1704000000U),
 PLLDDR1(    71,    0,  1728000000U),
 PLLDDR1(    72,    0,  1752000000U),
 PLLDDR1(    73,    0,  1776000000U),
 PLLDDR1(    74,    0,  1800000000U),
 PLLDDR1(    75,    0,  1824000000U),
 PLLDDR1(    76,    0,  1848000000U),
 PLLDDR1(    77,    0,  1872000000U),
 PLLDDR1(    78,    0,  1896000000U),
 PLLDDR1(    79,    0,  1920000000U),
 PLLDDR1(    80,    0,  1944000000U),
 PLLDDR1(    81,    0,  1968000000U),
 PLLDDR1(    82,    0,  1992000000U),
 PLLDDR1(    83,    0,  2016000000U),
 PLLDDR1(    84,    0,  2040000000U),
 PLLDDR1(    85,    0,  2064000000U),
 PLLDDR1(    86,    0,  2088000000U),
};


static unsigned int pllcpu_max,pllvideo_max,pllve_max ,
		    pllddr0_max,pllperiph0_max ,pllperiph1_max,
		    pllddr1_max,pllisp_max;

#define PLL_MAX_ASSIGN(name)	pll##name##_max=factor_pll##name##_tbl[ARRAY_SIZE(factor_pll##name##_tbl)-1].freq

void sunxi_clk_factor_initlimits(void)
{
	PLL_MAX_ASSIGN(cpu);PLL_MAX_ASSIGN(video);PLL_MAX_ASSIGN(ve);
	PLL_MAX_ASSIGN(periph0);PLL_MAX_ASSIGN(periph1);PLL_MAX_ASSIGN(ddr0);
	PLL_MAX_ASSIGN(ddr1);PLL_MAX_ASSIGN(isp);
}