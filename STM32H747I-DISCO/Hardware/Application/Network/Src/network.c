/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2024-12-18T12:18:59+0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "0x8358084e73eb43945b32c94166f89d53"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2024-12-18T12:18:59+0700"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[3] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[247] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conversion_218_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 15380, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input_10_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 110592, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 110593, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 153664, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 442368, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 451632, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 110592, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 110592, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 120000, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 110592, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 110592, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 115248, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55296, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64896, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55296, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55296, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64896, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55296, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55296, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 60000, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13824, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20736, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27648, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32448, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6912, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2016, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2016, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2016, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2016, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2016, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4032, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 46080, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_68_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_68_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_70_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_70_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_71_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_73_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_75_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_76_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_76_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_77_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 900, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_82_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_82_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_83_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 720, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_94_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_94_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_95_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_97_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_98_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_98_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_99_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_100_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_100_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_101_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_102_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_102_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_103_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_105_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 225, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_110_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_110_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 180, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_122_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_122_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_123_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 456, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_124_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1824, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_124_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 456, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_125_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 416, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_126_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1664, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_126_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 416, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_128_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_128_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_130_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_130_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_131_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_132_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_132_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_133_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_138_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_138_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_139_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 80, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  upsample_150_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_152_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_153_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_153_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_154_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_155_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_155_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_156_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_157_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_157_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_158_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_160_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_161_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_161_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_162_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_163_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_163_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_164_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3600, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_169_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_169_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_170_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2880, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  upsample_181_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_183_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_184_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_184_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_186_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_186_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_187_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_188_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_188_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_189_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_190_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_190_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_192_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_192_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_193_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_194_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_194_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_195_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14400, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  concat_200_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19225, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  nl_201_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19225, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conversion_202_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 19225, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86528, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_204_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11520, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  concat_209_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15380, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conversion_210_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 15380, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  concat_217_const_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15380, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#265 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#266 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#267 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#268 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#269 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#270 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#271 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#272 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#273 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#274 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#275 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#276 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#277 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#278 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#279 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#280 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#281 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#282 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#283 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)

/* Array#284 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#285 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#286 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#287 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#288 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#289 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#290 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#291 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#292 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#293 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#294 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#295 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#296 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#297 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#298 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#299 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#300 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#301 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#302 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 112, AI_STATIC)

/* Array#303 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 143360, AI_STATIC)

/* Array#304 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1280, AI_STATIC)

/* Array#305 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 163840, AI_STATIC)

/* Array#306 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#307 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_68_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#308 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_68_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#309 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_69_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#310 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_69_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#311 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_70_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#312 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_70_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#313 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_71_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#314 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_71_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#315 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#316 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#317 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_73_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#318 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_73_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#319 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#320 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#321 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_75_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#322 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_75_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#323 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_76_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#324 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_76_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#325 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_77_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#326 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_77_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#327 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_82_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#328 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_82_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#329 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_83_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#330 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_83_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#331 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_94_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#332 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_94_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#333 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_95_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#334 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_95_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#335 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#336 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#337 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_97_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#338 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_97_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#339 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_98_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#340 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_98_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#341 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_99_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#342 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_99_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#343 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_100_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#344 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_100_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#345 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_101_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#346 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_101_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#347 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_102_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#348 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_102_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#349 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_103_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#350 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_103_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#351 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#352 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#353 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_105_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#354 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_105_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#355 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_110_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#356 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_110_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#357 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#358 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#359 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_122_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#360 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_122_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#361 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_123_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14592, AI_STATIC)

/* Array#362 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_123_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 114, AI_STATIC)

/* Array#363 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_124_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1026, AI_STATIC)

/* Array#364 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_124_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 114, AI_STATIC)

/* Array#365 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_125_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11856, AI_STATIC)

/* Array#366 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_125_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#367 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_126_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 936, AI_STATIC)

/* Array#368 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_126_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#369 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13312, AI_STATIC)

/* Array#370 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#371 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_128_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#372 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_128_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#373 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#374 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#375 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_130_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#376 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_130_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#377 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_131_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#378 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_131_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#379 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_132_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#380 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_132_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#381 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_133_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#382 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_133_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#383 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_138_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#384 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_138_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#385 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_139_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#386 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_139_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#387 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_153_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#388 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_153_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#389 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_154_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#390 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_154_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#391 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_155_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#392 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_155_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#393 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_156_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#394 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_156_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#395 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_157_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#396 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_157_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#397 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_158_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#398 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_158_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#399 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#400 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#401 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_160_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#402 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_160_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#403 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_161_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#404 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_161_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#405 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_162_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#406 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_162_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#407 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_163_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#408 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_163_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#409 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_164_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#410 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_164_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#411 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_169_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#412 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_169_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#413 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_170_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#414 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_170_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#415 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_184_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#416 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_184_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#417 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#418 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#419 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_186_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#420 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_186_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#421 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_187_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#422 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_187_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#423 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_188_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#424 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_188_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#425 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_189_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#426 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_189_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#427 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_190_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#428 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_190_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#429 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#430 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#431 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_192_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#432 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_192_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#433 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_193_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#434 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_193_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#435 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_194_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#436 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_194_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#437 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_195_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#438 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_195_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#439 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#440 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#441 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_204_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#442 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_204_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#443 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#444 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#445 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#446 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#447 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#448 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#449 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#450 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#451 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#452 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#453 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#454 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#455 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#456 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#457 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#458 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#459 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#460 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#461 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1344, AI_STATIC)

/* Array#462 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#463 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#464 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#465 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#466 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#467 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#468 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#469 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#470 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#471 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#472 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#473 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#474 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#475 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#476 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#477 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#478 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#479 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#480 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#481 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#482 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#483 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1408, AI_STATIC)

/* Array#484 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#485 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#486 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)

/* Array#487 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#488 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#489 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#490 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#491 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#492 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#493 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#494 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#495 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2464, AI_STATIC)

/* Array#496 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13248, AI_STATIC)

/* Array#497 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#498 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_68_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#499 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_69_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#500 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_70_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#501 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_71_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#502 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#503 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_73_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#504 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#505 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_75_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#506 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_76_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#507 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_77_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 762, AI_STATIC)

/* Array#508 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_82_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#509 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_83_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 712, AI_STATIC)

/* Array#510 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_94_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#511 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_95_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#512 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#513 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_97_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#514 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_98_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#515 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_99_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#516 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_100_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#517 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_101_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#518 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_102_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#519 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_103_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#520 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#521 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_105_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 762, AI_STATIC)

/* Array#522 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_110_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#523 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 712, AI_STATIC)

/* Array#524 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_122_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#525 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_123_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1652, AI_STATIC)

/* Array#526 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_124_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4219, AI_STATIC)

/* Array#527 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_125_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1496, AI_STATIC)

/* Array#528 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_126_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3849, AI_STATIC)

/* Array#529 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1696, AI_STATIC)

/* Array#530 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_128_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#531 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#532 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_130_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#533 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_131_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#534 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_132_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#535 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_133_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 762, AI_STATIC)

/* Array#536 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_138_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#537 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_139_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 712, AI_STATIC)

/* Array#538 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_153_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#539 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_154_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#540 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_155_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#541 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_156_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#542 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_157_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#543 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_158_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#544 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#545 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_160_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#546 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_161_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#547 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_162_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#548 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_163_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#549 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_164_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 762, AI_STATIC)

/* Array#550 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_169_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#551 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_170_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 712, AI_STATIC)

/* Array#552 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_184_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#553 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#554 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_186_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#555 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_187_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#556 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_188_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#557 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_189_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#558 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_190_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#559 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#560 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_192_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#561 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_193_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#562 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_194_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#563 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_195_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 762, AI_STATIC)

/* Array#564 */
AI_ARRAY_OBJ_DECLARE(
  nl_201_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 124, AI_STATIC)

/* Array#565 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#566 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_204_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 712, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_195_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 25,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005439277738332748f, 0.0009061042219400406f, 0.0008173159440048039f, 0.0008691629627719522f, 0.000927578890696168f, 0.0005663759657181799f, 0.0008951849304139614f, 0.0010521935764700174f, 0.0014845133991912007f, 0.0011004817206412554f, 0.0006735535571351647f, 0.0006915319827385247f, 0.0007747954805381596f, 0.0007590794120915234f, 0.0007726229378022254f, 0.0006652265437878668f, 0.0008350970456376672f, 0.0010502793593332171f, 0.0006652264855802059f, 0.0008605960756540298f, 0.0005812773015350103f, 0.0008144428138621151f, 0.0009007136104628444f, 0.0010220016120001674f, 0.0008693994022905827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_203_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032820217311382294f, 0.006311647593975067f, 0.00383312301710248f, 0.0028962704818695784f, 0.020154383033514023f, 0.0033653369173407555f, 0.003415994346141815f, 0.006080554332584143f, 0.009761100634932518f, 0.006735880393534899f, 0.003446827409788966f, 0.020441627129912376f, 0.01288879755884409f, 0.009120236150920391f, 0.011507228016853333f, 0.02676246501505375f, 0.011347592808306217f, 0.003055881941691041f, 0.0020108683966100216f, 0.004939626902341843f, 0.004840731620788574f, 0.004812959581613541f, 0.004529621917754412f, 0.005909983534365892f, 0.003265025094151497f, 0.003815100761130452f, 0.0076538315042853355f, 0.0035585530567914248f, 0.00472184969112277f, 0.008661933243274689f, 0.003684100927785039f, 0.0032698404975235462f, 0.0025539526250213385f, 0.022389432415366173f, 0.0017684029880911112f, 0.005225830711424351f, 0.009042707271873951f, 0.007676777429878712f, 0.008392495103180408f, 0.0034835622645914555f, 0.006733412854373455f, 0.008955874480307102f, 0.01783967763185501f, 0.004426164552569389f, 0.0027745605912059546f, 0.014530783519148827f, 0.005944032687693834f, 0.0069108884781599045f, 0.00394211383536458f, 0.006313559133559465f, 0.005665854085236788f, 0.004254532046616077f, 0.006147510837763548f, 0.0036882313434034586f, 0.0019847529474645853f, 0.0027904713060706854f, 0.003246980719268322f, 0.005757102742791176f, 0.0027396129444241524f, 0.005038334988057613f, 0.00285335723310709f, 0.003865091362968087f, 0.004228510893881321f, 0.003935700748115778f, 0.0031490405090153217f, 0.010534174740314484f, 0.0038605518639087677f, 0.0024228068068623543f, 0.005427464842796326f, 0.009639432653784752f, 0.002407233463600278f, 0.012295834720134735f, 0.0020864862017333508f, 0.005426948890089989f, 0.004940050188452005f, 0.003838892327621579f, 0.019000746309757233f, 0.005211400333791971f, 0.008822372183203697f, 0.005722148343920708f, 0.003690009703859687f, 0.011389872059226036f, 0.02724267914891243f, 0.0036232348065823317f, 0.0034144455567002296f, 0.006890728138387203f, 0.0028099806513637304f, 0.07995698601007462f, 0.0031940012704581022f, 0.019271159544587135f, 0.0045699262991547585f, 0.005572986789047718f, 0.003000608878210187f, 0.00597352534532547f, 0.014095289632678032f, 0.008310869336128235f, 0.0023954324424266815f, 0.012139873579144478f, 0.005533443298190832f, 0.0027252647560089827f, 0.005207642447203398f, 0.004814679268747568f, 0.005933729466050863f, 0.0024142891634255648f, 0.024987690150737762f, 0.0029783088248223066f, 0.00295164342969656f, 0.004035881720483303f, 0.002885631285607815f, 0.011408872902393341f, 0.007443702779710293f, 0.0031997384503483772f, 0.005101641174405813f, 0.006498889531940222f, 0.004454676061868668f, 0.0025864592753350735f, 0.013466504402458668f, 0.009925668127834797f, 0.004592809360474348f, 0.018319835886359215f, 0.0045178355649113655f, 0.006214254070073366f, 0.004633431788533926f, 0.01184486597776413f, 0.015238262712955475f, 0.0048062787391245365f, 0.006650079041719437f, 0.003734232159331441f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_204_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 20,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008452209294773638f, 0.0009272962342947721f, 0.0006684928084723651f, 0.0008070515468716621f, 0.0007686577155254781f, 0.00041035059257410467f, 0.0008247204823419452f, 0.0006806364981457591f, 0.0007874286384321749f, 0.0007555641932412982f, 0.0008287517703138292f, 0.0009072315297089517f, 0.0009141485788859427f, 0.0010040783090516925f, 0.0008326307870447636f, 0.0010043183574452996f, 0.0009696500492282212f, 0.0009168368997052312f, 0.0008433241746388376f, 0.0010386182693764567f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_input_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(127.5f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(127.5f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.495734840631485f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.460263729095459f),
    AI_PACK_INTQ_ZP(-28)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.6729233860969543f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8354147672653198f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3803407549858093f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.37148812413215637f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.39302656054496765f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2548667788505554f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_23_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.46361562609672546f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_182_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06620016694068909f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3003758490085602f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.31616654992103577f),
    AI_PACK_INTQ_ZP(-27)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_31_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3403071165084839f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.26367223262786865f),
    AI_PACK_INTQ_ZP(10)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.35459959506988525f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24107158184051514f),
    AI_PACK_INTQ_ZP(-27)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_39_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.371238648891449f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.23125803470611572f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2041988968849182f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_46_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24583518505096436f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4018298089504242f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_50_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4552469253540039f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_151_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06879377365112305f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19227024912834167f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.20125935971736908f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_58_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2358018159866333f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_59_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2737407684326172f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_62_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.32276999950408936f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_63_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17253296077251434f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0668540969491005f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_68_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0668540969491005f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_68_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07489103823900223f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_69_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_70_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_70_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09156033396720886f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_71_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_72_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_72_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0946214571595192f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_73_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_74_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_74_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10734067112207413f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_75_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_76_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_76_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10271042585372925f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_77_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_82_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_82_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14526468515396118f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_83_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_94_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0668540969491005f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_94_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06377435475587845f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_95_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_96_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_96_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07506601512432098f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_97_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_98_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_98_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0944686159491539f),
    AI_PACK_INTQ_ZP(20)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_99_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_100_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_100_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09003008902072906f),
    AI_PACK_INTQ_ZP(21)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_101_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_102_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_102_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09406519681215286f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_103_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_104_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_104_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08451511710882187f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_105_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_110_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_110_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1254081130027771f),
    AI_PACK_INTQ_ZP(-22)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_111_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_122_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_122_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05610055848956108f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_123_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023094214498996735f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_124_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023094214498996735f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_124_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06024249270558357f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_125_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018810056149959564f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_126_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018810056149959564f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_126_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.059423528611660004f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_127_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_128_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_128_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06112707033753395f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_129_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_130_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_130_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06839069724082947f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_131_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02169887349009514f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_132_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02169887349009514f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_132_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06312070786952972f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_133_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_138_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02169887349009514f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_138_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02259174734354019f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_139_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(upsample_150_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0668540969491005f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_152_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08532780408859253f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_153_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08532780408859253f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_153_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06952228397130966f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_154_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_155_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_155_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09968554973602295f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_156_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_157_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_157_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11334210634231567f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_158_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_159_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_159_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12375058978796005f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_160_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_161_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_161_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14426849782466888f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_162_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_163_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_163_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13782982528209686f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_164_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_169_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_169_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1403043121099472f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_170_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(upsample_181_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_183_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07555073499679565f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_184_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07555073499679565f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_184_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06888166815042496f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_185_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_186_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_186_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10355640202760696f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_187_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_188_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_188_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11874455958604813f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #180 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_189_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #181 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_190_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #182 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_190_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2529839873313904f),
    AI_PACK_INTQ_ZP(40)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_191_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_192_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_192_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.25836437940597534f),
    AI_PACK_INTQ_ZP(24)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_193_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_194_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_194_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3165000081062317f),
    AI_PACK_INTQ_ZP(-33)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_195_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_200_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13130971789360046f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_201_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_203_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_203_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.29178956151008606f),
    AI_PACK_INTQ_ZP(69)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_204_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_209_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08288616687059402f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_217_const_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008073904551565647f),
    AI_PACK_INTQ_ZP(-62)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.551486902457327e-08f, 3.937008052901092e-09f, 5.422201070359733e-07f, 8.916004645698195e-08f, 1.700703791129854e-07f, 5.2356423196897595e-08f, 3.937008052901092e-09f, 3.8205985219974536e-07f, 3.937008052901092e-09f, 6.109873424975376e-07f, 3.937008052901092e-09f, 1.078035438695224e-07f, 7.798495289534912e-07f, 3.937008052901092e-09f, 1.1396007266739616e-06f, 3.6678039805337903e-07f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014288374222815037f, 0.27892130613327026f, 0.0071892207488417625f, 0.017613336443901062f, 0.005759227555245161f, 0.0013815555721521378f, 0.008967295289039612f, 0.009146245196461678f, 0.11033768206834793f, 0.008581210859119892f, 0.42852288484573364f, 0.013334355317056179f, 0.0068778423592448235f, 0.14566561579704285f, 0.00135828519705683f, 0.0049396720714867115f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06877350807189941f, 0.029941854998469353f, 0.04411931708455086f, 0.08596565574407578f, 0.048934824764728546f, 0.06439283490180969f, 0.14263027906417847f, 0.13670608401298523f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007640243857167661f, 0.008316589519381523f, 0.0017471836181357503f, 0.00048344238894060254f, 0.002984799677506089f, 0.001775567652657628f, 0.00860115047544241f, 0.00048700952902436256f, 0.0006382607971318066f, 0.0010357541032135487f, 0.007049129344522953f, 0.0006019785068929195f, 0.0010973726166412234f, 0.0005115127423778176f, 0.009329750202596188f, 0.00047478656051680446f, 0.0007089953869581223f, 0.008597140200436115f, 0.004682084079831839f, 0.0037089434918016195f, 0.0005909914034418762f, 0.0010274715023115277f, 0.0012834820663556457f, 0.0020618641283363104f, 0.0016947807744145393f, 0.0007757412386126816f, 0.002961487276479602f, 0.000714001536834985f, 0.0009311417816206813f, 0.0036495316307991743f, 0.0005084049771539867f, 0.0021527267526835203f, 0.0006463725585490465f, 0.002802343340590596f, 0.00045301555655896664f, 0.00028736304375343025f, 0.0011461807880550623f, 0.011614025570452213f, 0.0003891435044351965f, 0.0014127041213214397f, 0.011233465746045113f, 0.005904435645788908f, 0.0030725584365427494f, 0.0004896026803180575f, 0.0011519239051267505f, 0.001472249161452055f, 0.011837269179522991f, 0.0004960839287377894f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010134425945580006f, 0.0030746355187147856f, 0.001677979831583798f, 0.12269020825624466f, 0.006123567931354046f, 0.007325276732444763f, 0.0026740068569779396f, 0.060705214738845825f, 0.07782800495624542f, 0.0039258552715182304f, 0.0021334742195904255f, 0.009397708810865879f, 0.0023575411178171635f, 0.007933002896606922f, 0.0017724415520206094f, 0.0668129101395607f, 0.01764880120754242f, 0.0025444331113249063f, 0.001468383357860148f, 0.0045365528203547f, 0.003730534575879574f, 0.0068969461135566235f, 0.004642543848603964f, 0.0035243500024080276f, 0.0016695299418643117f, 0.011508029885590076f, 0.003282663645222783f, 0.0061551230028271675f, 0.004450906999409199f, 0.006654968019574881f, 0.020706720650196075f, 0.015414021909236908f, 0.011202309280633926f, 0.0026696890126913786f, 0.0458434633910656f, 0.03076440468430519f, 0.005416933912783861f, 0.0012321046087890863f, 0.008562177419662476f, 0.0039440118707716465f, 0.0018502603052183986f, 0.0011864053085446358f, 0.007973682135343552f, 0.01568509452044964f, 0.008870498277246952f, 0.005578367505222559f, 0.0015704981051385403f, 0.03618074581027031f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015555370599031448f, 0.012457849457859993f, 0.01832125522196293f, 0.024771088734269142f, 0.023268384858965874f, 0.019668132066726685f, 0.02614760212600231f, 0.013305876404047012f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003560336190275848f, 0.001305578975006938f, 0.001190891140140593f, 0.0011285585351288319f, 0.0010816685389727354f, 0.0025606341660022736f, 0.002087750006467104f, 0.00045066914753988385f, 0.0004329342918936163f, 0.0013130017323419452f, 0.0009524247725494206f, 0.0006935029523447156f, 0.0013277264079079032f, 0.0007860230398364365f, 0.0032932779286056757f, 0.0002675426658242941f, 0.0025227859150618315f, 0.0003932147519662976f, 0.0020482377149164677f, 0.0007887016981840134f, 0.0009979717433452606f, 0.0010858799796551466f, 0.003631177358329296f, 0.0009166237432509661f, 0.002964000217616558f, 0.0011841654777526855f, 0.0027960692532360554f, 0.0008157612173818052f, 0.0017465953715145588f, 0.001607371843419969f, 0.0011061024852097034f, 0.0009115239372476935f, 0.00046595768071711063f, 0.0009148758836090565f, 0.004750647582113743f, 0.0012251926818862557f, 0.0004208629543427378f, 0.00382398534566164f, 0.00181931396946311f, 0.0003999380278401077f, 0.0010197039227932692f, 0.001196679542772472f, 0.0008993800729513168f, 0.0006286283023655415f, 0.0025227870792150497f, 0.004336273763328791f, 0.0017491353210061789f, 0.0014856604393571615f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #204 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008918099105358124f, 0.004435050766915083f, 0.0050494056195020676f, 0.013652428053319454f, 0.050124701112508774f, 0.0036370032466948032f, 0.0041540274396538734f, 0.009004867635667324f, 0.014541844837367535f, 0.0047469851560890675f, 0.005397976376116276f, 0.018106333911418915f, 0.009245733730494976f, 0.011488018557429314f, 0.0028948457911610603f, 0.01979384757578373f, 0.009704789146780968f, 0.011862036772072315f, 0.005389486905187368f, 0.010512231849133968f, 0.011956657283008099f, 0.006224909797310829f, 0.005814223550260067f, 0.010926051996648312f, 0.0033529242500662804f, 0.02997547574341297f, 0.008020605891942978f, 0.012598891742527485f, 0.010877535678446293f, 0.0035796777810901403f, 0.006745307240635157f, 0.013104729354381561f, 0.0692000463604927f, 0.006176861468702555f, 0.007917067036032677f, 0.004157515242695808f, 0.023531410843133926f, 0.004862410482019186f, 0.0050081973895430565f, 0.011707538738846779f, 0.011049024760723114f, 0.008051609620451927f, 0.036611367017030716f, 0.007371037732809782f, 0.006437529809772968f, 0.003447755938395858f, 0.008634772151708603f, 0.018684476613998413f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #205 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020795362070202827f, 0.021528935059905052f, 0.014298503287136555f, 0.04708680883049965f, 0.027532296255230904f, 0.03915397450327873f, 0.03569357469677925f, 0.02206757292151451f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #206 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004684694577008486f, 0.0004293889505788684f, 0.001472570700570941f, 0.000978624913841486f, 0.0012616553576663136f, 0.0005769582348875701f, 0.0006008439813740551f, 0.001006346195936203f, 0.00010146943532163277f, 0.0006070350063964725f, 0.00043621374061331153f, 0.0002660653553903103f, 0.0006206983234733343f, 0.0009821075946092606f, 0.0003991918347310275f, 0.003458946943283081f, 0.002005196176469326f, 0.0003235242038499564f, 0.0004544478142634034f, 0.00130403321236372f, 0.0017126023303717375f, 0.0002574474783614278f, 0.003436731407418847f, 0.00042696206946857274f, 0.0003440204600337893f, 0.0004702261940110475f, 0.0009920792654156685f, 0.00034467523801140487f, 0.000979920383542776f, 0.0007694437517784536f, 0.0010040632914751768f, 0.0006837820401415229f, 0.0021821395494043827f, 0.0004132078029215336f, 0.00020715277059935033f, 0.0004521420050878078f, 0.0009571099071763456f, 0.0006026714108884335f, 0.00026085335412062705f, 0.00040691031608730555f, 0.0004633452044799924f, 0.0011781518114730716f, 0.00026587306638248265f, 0.001510560279712081f, 0.0004713061498478055f, 0.0003916363057214767f, 0.0008168176282197237f, 0.0005361594958230853f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #207 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0060013774782419205f, 0.004589787684381008f, 0.001214334974065423f, 0.0018825799925252795f, 0.00353801972232759f, 0.0026762145571410656f, 0.003227767301723361f, 0.0016767331399023533f, 0.029708046466112137f, 0.0020448388531804085f, 0.00433191005140543f, 0.006045769900083542f, 0.004202733281999826f, 0.00123041239567101f, 0.004867088049650192f, 0.0014184137107804418f, 0.0014709148090332747f, 0.005718739237636328f, 0.003340741852298379f, 0.0026164257433265448f, 0.0015621164347976446f, 0.007937655784189701f, 0.004137996584177017f, 0.002780977403745055f, 0.0027919290587306023f, 0.010835917666554451f, 0.00199779006652534f, 0.006342308130115271f, 0.003340354887768626f, 0.002057816367596388f, 0.001319428440183401f, 0.0037059320602566004f, 0.0019183314871042967f, 0.005314986687153578f, 0.006823419593274593f, 0.00636694673448801f, 0.0032619070261716843f, 0.0032514934428036213f, 0.008993078023195267f, 0.002676946809515357f, 0.003609411884099245f, 0.0012233149027451873f, 0.006299463100731373f, 0.0014359346823766828f, 0.0037335494998842478f, 0.00523519329726696f, 0.0025061643682420254f, 0.004015831276774406f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #208 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04474426060914993f, 0.021447928622364998f, 0.017202844843268394f, 0.029045017436146736f, 0.019957035779953003f, 0.021006064489483833f, 0.026059765368700027f, 0.022272473201155663f, 0.05147761106491089f, 0.0317845493555069f, 0.019420765340328217f, 0.031667474657297134f, 0.042888302356004715f, 0.023664865642786026f, 0.04112206771969795f, 0.02667107619345188f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #209 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013671447522938251f, 0.0016264364821836352f, 0.00026946549769490957f, 0.0010021667694672942f, 0.0007042064680717885f, 0.001045440323650837f, 0.0006488168728537858f, 0.00027411867631599307f, 0.00033762279781512916f, 0.000743888143915683f, 0.0011556813260540366f, 0.0013695333618670702f, 0.003473749617114663f, 0.0008465053397230804f, 0.00044799924944527447f, 0.0007843479397706687f, 0.0006358286482281983f, 0.0004613026394508779f, 0.0012645908864215016f, 0.0005528040928766131f, 0.000629871676210314f, 0.0021632907446473837f, 0.0007291208603419363f, 0.0009084990015253425f, 0.0010915164602920413f, 0.0008050792384892702f, 0.0007300132419914007f, 0.0004979634541086853f, 0.0003675688349176198f, 0.0008819941431283951f, 0.0008704325882717967f, 0.0010366117348894477f, 0.0012076344573870301f, 0.0009168494143523276f, 0.0018320975359529257f, 0.0005027612787671387f, 0.0007342679891735315f, 0.00041011962457560003f, 0.0007407097145915031f, 0.0010542806703597307f, 0.0009554611751809716f, 0.002026464557275176f, 0.0005400079535320401f, 0.0007218384998850524f, 0.0004453375586308539f, 0.00038997281808406115f, 0.0006646046531386673f, 0.0016544586978852749f, 0.0018081889720633626f, 0.0008212074753828347f, 0.0011090253246948123f, 0.0009461479494348168f, 0.0004316825361456722f, 0.0010766371851786971f, 0.0007838939200155437f, 0.0009747682488523424f, 0.0004992010653950274f, 0.0009085227502509952f, 0.0017924521816894412f, 0.00044363277265802026f, 0.0026169728953391314f, 0.001217550947330892f, 0.0004349653027020395f, 0.00028391159139573574f, 0.0004032191645819694f, 0.0009302949183620512f, 0.0004229818587191403f, 0.00039729842683300376f, 0.0015539758605882525f, 0.0005782659281976521f, 0.0005746104288846254f, 0.001736271078698337f, 0.0005325751262716949f, 0.0007237936370074749f, 0.0011134383967146277f, 0.0010794397676363587f, 0.0003166572714690119f, 0.00044027648982591927f, 0.0010539354989305139f, 0.0005596835981123149f, 0.0014563036384060979f, 0.00013379642041400075f, 0.000831005338113755f, 0.0004650302871596068f, 0.0011791153810918331f, 0.0003728640731424093f, 0.0007574796909466386f, 0.0004172661283519119f, 0.0013287111651152372f, 0.000625387707259506f, 0.0003986483789049089f, 0.0007016243762336671f, 0.0007326063350774348f, 0.0006806235178373754f, 0.0006292271427810192f, 7.169272430473939e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #210 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0040307301096618176f, 0.012475775554776192f, 0.014143630862236023f, 0.005095421336591244f, 0.00575640331953764f, 0.012281366623938084f, 0.0027979586739093065f, 0.014099685475230217f, 0.008150124922394753f, 0.007928223349153996f, 0.006222816649824381f, 0.008127359673380852f, 0.0019001204054802656f, 0.003422562265768647f, 0.014271751046180725f, 0.01094815507531166f, 0.004955497570335865f, 0.008672907948493958f, 0.020168650895357132f, 0.015062044374644756f, 0.003473545191809535f, 0.011624586768448353f, 0.008109577931463718f, 0.007520722225308418f, 0.00831067468971014f, 0.007995634339749813f, 0.007081806659698486f, 0.014910486526787281f, 0.01114555075764656f, 0.005910034757107496f, 0.006415200885385275f, 0.01125141978263855f, 0.011070535518229008f, 0.004364325664937496f, 0.006331683602184057f, 0.006649576593190432f, 0.007638924289494753f, 0.0055043320171535015f, 0.01376480795443058f, 0.006617813371121883f, 0.014989431016147137f, 0.005235041957348585f, 0.029114656150341034f, 0.008196423761546612f, 0.017058847472071648f, 0.012593835592269897f, 0.004905796609818935f, 0.006774770561605692f, 0.0068658203817903996f, 0.017865357920527458f, 0.004901287145912647f, 0.02307361364364624f, 0.007611909415572882f, 0.011463486589491367f, 0.004302721004933119f, 0.006217509042471647f, 0.009786500595510006f, 0.012625615112483501f, 0.005793163087219f, 0.005237154196947813f, 0.00426053861156106f, 0.012989274226129055f, 0.007462857756763697f, 0.02000945247709751f, 0.007410175632685423f, 0.0013110358268022537f, 0.008255396038293839f, 0.015606217086315155f, 0.004857571795582771f, 0.0010721914004534483f, 0.019290437921881676f, 0.008138238452374935f, 0.0073892767541110516f, 0.0054849484004080296f, 0.003819655627012253f, 0.006889835000038147f, 0.019080044701695442f, 0.005907773040235043f, 0.007985375821590424f, 0.006487572565674782f, 0.012432613410055637f, 0.0340241938829422f, 0.0048571424558758736f, 0.008522207848727703f, 0.0047423639334738255f, 0.0068602305836975574f, 0.012269905768334866f, 0.012895232066512108f, 0.010761875659227371f, 0.004925472661852837f, 0.01192240696400404f, 0.007383410353213549f, 0.009802667424082756f, 0.004119955934584141f, 0.004426870029419661f, 0.0735602155327797f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #211 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015269762836396694f, 0.013416857458651066f, 0.0323837548494339f, 0.007676782086491585f, 0.008289617486298084f, 0.007868018001317978f, 0.01551709696650505f, 0.010272791609168053f, 0.008110668510198593f, 0.014322031289339066f, 0.01257325615733862f, 0.01667606085538864f, 0.016966698691248894f, 0.009403317235410213f, 0.01207197830080986f, 0.005733506754040718f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #212 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005085978773422539f, 0.000666400941554457f, 0.0007045870879665017f, 0.0012377527309581637f, 0.0009309904417023063f, 0.0011212254175916314f, 0.0004139846714679152f, 0.0005862487596459687f, 0.0007094580214470625f, 0.0006531717954203486f, 0.00034757080720737576f, 0.0006652763113379478f, 0.000590977375395596f, 0.0006967252120375633f, 0.0005361227667890489f, 0.000380667916033417f, 0.00025939219631254673f, 0.00034425841295160353f, 0.00034634312032721937f, 0.0006242061499506235f, 0.0005408504512161016f, 0.002384197199717164f, 0.0009180517517961562f, 0.0007775893318466842f, 0.000918756821192801f, 0.0008873323677107692f, 0.0009178864420391619f, 0.0008393453899770975f, 0.0005280943587422371f, 0.0005678644520230591f, 0.0003079923044424504f, 0.0006741792312823236f, 0.001349601079709828f, 0.0005797618650831282f, 0.0006714026676490903f, 0.0007125920383259654f, 0.0005537657416425645f, 0.00046318964450620115f, 0.0005032061017118394f, 0.00037774513475596905f, 0.0007607060251757503f, 0.0002202836622018367f, 0.000971983012277633f, 0.0005868083098903298f, 0.000525878625921905f, 0.0007294075912795961f, 0.0004250502388458699f, 0.0006036291015334427f, 0.0007814103737473488f, 0.0006848758785054088f, 0.0005700685433112085f, 0.0009412713116034865f, 0.0006170462002046406f, 0.0005655280547216535f, 0.00028024340281262994f, 0.0010329446522518992f, 0.000673781440127641f, 0.00043720155372284353f, 0.00044686440378427505f, 0.000623932050075382f, 0.0011161989532411098f, 0.0004801434406545013f, 0.00029308462399058044f, 0.0013027929235249758f, 0.0003455842088442296f, 0.00046669584116898477f, 0.00043120307964272797f, 0.0007906853570602834f, 0.0013252472272142768f, 0.000984986312687397f, 0.00018288871797267348f, 0.0006417088443413377f, 0.0011348567204549909f, 0.00044846328091807663f, 0.000644052226562053f, 0.0017387432744726539f, 0.0003122005728073418f, 0.0010792537359520793f, 0.0003827062901109457f, 0.0017796800239011645f, 0.0004075115721207112f, 0.00027372228214517236f, 0.0009161335183307528f, 0.000732947199139744f, 0.0004760394513141364f, 0.00039406929863616824f, 0.000858098326716572f, 0.0008981493883766234f, 0.0003284022386651486f, 0.0006500070448964834f, 0.0017922914121299982f, 0.00020303134806454182f, 0.0005854961927980185f, 0.0006335966172628105f, 0.000869645387865603f, 0.00024773692712187767f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #213 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009058467112481594f, 0.007758650463074446f, 0.01419601496309042f, 0.00877815019339323f, 0.0032068227883428335f, 0.004160401411354542f, 0.008127671666443348f, 0.014017457142472267f, 0.009993663057684898f, 0.005934539251029491f, 0.01928005926311016f, 0.02350260317325592f, 0.018439948558807373f, 0.00901814829558134f, 0.010684254579246044f, 0.02028343640267849f, 0.01033812202513218f, 0.024735594168305397f, 0.02397967129945755f, 0.009974106214940548f, 0.01386218424886465f, 0.0027113687247037888f, 0.00621984014287591f, 0.006599435117095709f, 0.017357677221298218f, 0.03800302371382713f, 0.005025641527026892f, 0.006906148046255112f, 0.0097151268273592f, 0.014247963204979897f, 0.02367275580763817f, 0.005536594428122044f, 0.0032209150958806276f, 0.002952153328806162f, 0.01120198518037796f, 0.008063748478889465f, 0.00899573415517807f, 0.008736724965274334f, 0.005256543401628733f, 0.021873921155929565f, 0.013940374366939068f, 0.0201325174421072f, 0.004263761453330517f, 0.011512290686368942f, 0.011718354187905788f, 0.006126769352704287f, 0.009383533149957657f, 0.005672817584127188f, 0.007642258889973164f, 0.006593469530344009f, 0.008691350929439068f, 0.005437738727778196f, 0.011186807416379452f, 0.015374060720205307f, 0.028778158128261566f, 0.008520337752997875f, 0.016566868871450424f, 0.007997003383934498f, 0.008054142817854881f, 0.00540851429104805f, 0.004698619712144136f, 0.009671734645962715f, 0.01891615055501461f, 0.004149825312197208f, 0.011076634749770164f, 0.009532161056995392f, 0.00838659517467022f, 0.006040959153324366f, 0.005846480373293161f, 0.005651690997183323f, 0.046376731246709824f, 0.014217996969819069f, 0.0016176309436559677f, 0.008681179024279118f, 0.008078240789473057f, 0.011357570998370647f, 0.017263861373066902f, 0.0063087414018809795f, 0.03528212383389473f, 0.003675197483971715f, 0.008176927454769611f, 0.013459566980600357f, 0.01141761988401413f, 0.007795889861881733f, 0.005630014464259148f, 0.018990259617567062f, 0.007248253095895052f, 0.012707538902759552f, 0.02891673892736435f, 0.00334772071801126f, 0.007755473256111145f, 0.020787373185157776f, 0.009245814755558968f, 0.0050711361691355705f, 0.005338103976100683f, 0.012284437194466591f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #214 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008627737872302532f, 0.014420989900827408f, 0.019567321985960007f, 0.009512939490377903f, 0.004110753070563078f, 0.005453452467918396f, 0.015540008433163166f, 0.009582490660250187f, 0.011890009976923466f, 0.009484544396400452f, 0.011992151848971844f, 0.012727601453661919f, 0.00880471896380186f, 0.011015295051038265f, 0.010009448044002056f, 0.007257519755512476f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #215 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_182_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003853203379549086f, 0.0004135299823246896f, 0.00044861427159048617f, 0.00043423319584690034f, 0.0004211103660054505f, 0.00047896019532345235f, 0.0005216802237555385f, 0.0004387634980957955f, 0.0006234890897758305f, 0.0004234983352944255f, 0.00044277572305873036f, 0.00046677610953338444f, 0.0004089976428076625f, 0.00040548466495238245f, 0.0005463912384584546f, 0.0004956466145813465f, 0.0003675654879771173f, 0.0004748182836920023f, 0.00036763452226296067f, 0.000421031640144065f, 0.00038561446126550436f, 0.0006082585896365345f, 0.00046198093332350254f, 0.0004802467883564532f, 0.00044481432996690273f, 0.0004284546594135463f, 0.00028626262792386115f, 0.00034401373704895377f, 0.00042527305777184665f, 0.0005749164847657084f, 0.0004946533008478582f, 0.0003048017097171396f, 0.0005152520025148988f, 0.00032018995261751115f, 0.0005916313966736197f, 0.00040922718471847475f, 0.0003971031401306391f, 0.0006225230754353106f, 0.0004564174450933933f, 0.0006236505578272045f, 0.0007074030581861734f, 0.00043523364001885056f, 0.00045514406519941986f, 0.00032491120509803295f, 0.0003910850209649652f, 0.00025749398628249764f, 0.0004730158543679863f, 0.0004534912877716124f, 0.0006830259226262569f, 0.0006200834177434444f, 0.0004776935384143144f, 0.0005299103795550764f, 0.00046129367547109723f, 0.0005159568390809f, 0.0004319538420531899f, 0.00049951410619542f, 0.00045746302930638194f, 0.0006236418848857284f, 0.0003906746278516948f, 0.00039642993942834437f, 0.0004245336458552629f, 0.00042165559716522694f, 0.0004926101537421346f, 0.0007695013773627579f, 0.000314385280944407f, 0.0003623795637395233f, 0.0004485940153244883f, 0.0004522137460298836f, 0.0002880454412661493f, 0.0007580455858260393f, 0.00032272867974825203f, 0.00030829606112092733f, 0.00039957757689990103f, 0.00048801812226884067f, 0.0004447259125299752f, 0.00045041769044473767f, 0.0004601420368999243f, 0.00026443455135449767f, 0.0005487657035700977f, 0.000365280982805416f, 0.00037320557748898864f, 0.0003571723646018654f, 0.0005514613585546613f, 0.00041208238690160215f, 0.0005838495562784374f, 0.00046982450294308364f, 0.0005725461523979902f, 0.00033452731440775096f, 0.00055079092271626f, 0.0002731414861045778f, 0.00040039769373834133f, 0.00031243538251146674f, 0.00028552114963531494f, 0.00041236099787056446f, 0.0005500185070559382f, 0.0004463867808226496f, 0.00034060669713653624f, 0.0006922835018485785f, 0.0003532427654135972f, 0.0004273266822565347f, 0.0003960813919547945f, 0.0004851096891798079f, 0.00041508785216137767f, 0.0002939702244475484f, 0.00038454978493973613f, 0.0003954317362513393f, 0.0003551107074599713f, 0.0005752125871367753f, 0.0005357990157790482f, 0.00047096071648411453f, 0.0005519807455129921f, 0.0004242969152983278f, 0.0004935216857120395f, 0.00043683723197318614f, 0.00042199130984954536f, 0.00034909279202111065f, 0.0005461821565404534f, 0.00041829561814665794f, 0.0003716742794495076f, 0.00041029744897969067f, 0.00041701324516907334f, 0.0006321585969999433f, 0.00046869341167621315f, 0.0005235346034169197f, 0.0006391630740836263f, 0.0003291491884738207f, 0.0003658524656202644f, 0.00043231132440268993f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #216 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001252907095476985f, 0.0007866051746532321f, 0.0005357922636903822f, 0.001407051458954811f, 0.00032399533665739f, 0.001711870077997446f, 0.0002554020320530981f, 0.00039101275615394115f, 0.0006617089966312051f, 0.0006639015628024936f, 0.0007892029243521392f, 0.00043149496195837855f, 0.000753252359572798f, 0.0011513188946992159f, 0.0009206985705532134f, 0.000607661553658545f, 0.0004194687935523689f, 0.0008515920490026474f, 0.002233474515378475f, 0.0005550499190576375f, 0.0006262992392294109f, 0.0009251966257579625f, 0.0005352618754841387f, 0.0008768855477683246f, 0.0006901415763422847f, 0.0008134945528581738f, 0.001062059192918241f, 0.000780796050094068f, 0.0015732687897980213f, 0.0006423104205168784f, 0.0008350022835657f, 0.0008598492713645101f, 0.0008666902431286871f, 0.0006274197367019951f, 0.0010294184321537614f, 0.0008434060146100819f, 0.0009513418772257864f, 0.00019386787607800215f, 0.0018772368784993887f, 0.0009995162254199386f, 0.0005308082909323275f, 0.000920433085411787f, 0.0005454106722027063f, 0.00031834872788749635f, 0.0004431507259141654f, 0.0007014473085291684f, 0.0021267745178192854f, 0.0008769193082116544f, 0.0002381332596996799f, 0.0005340850329957902f, 0.0010937567567452788f, 0.00043657940113916993f, 0.0005074637592770159f, 0.000614106422290206f, 0.0008094295626506209f, 0.0007870456902310252f, 0.0006094115669839084f, 0.0009115082793869078f, 0.0016816240968182683f, 0.0008646635105833411f, 0.00042663238127715886f, 0.0007977608474902809f, 0.0006080365856178105f, 0.001213032053783536f, 0.0008699140744283795f, 0.0004871967248618603f, 0.0015278372447937727f, 0.000764688418712467f, 0.00029010928119532764f, 0.0006162853678688407f, 0.0005858737858943641f, 0.000885757093783468f, 0.0011351766297593713f, 0.0015632386785000563f, 0.0013333703391253948f, 0.00043108832323923707f, 0.0007546233828179538f, 0.0018747475696727633f, 0.00066277728183195f, 0.0003626220568548888f, 0.0006355784717015922f, 0.0008653457625769079f, 0.0016328515484929085f, 0.00029635740793310106f, 0.000780254602432251f, 0.0002633832045830786f, 0.0006522407638840377f, 0.000192342369700782f, 0.0003162133216392249f, 0.0004639248945750296f, 0.00047802249900996685f, 0.0007281595026142895f, 0.001008448307402432f, 0.0006297012441791594f, 0.0012061542365700006f, 0.0002318798069609329f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #217 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018365911673754454f, 0.002512711565941572f, 0.004764203447848558f, 0.0012315193889662623f, 0.005784798413515091f, 0.0025743574369698763f, 0.009288227185606956f, 0.0019979027565568686f, 0.003517152275890112f, 0.002619723556563258f, 0.012677213177084923f, 0.005132478661835194f, 0.0027497783303260803f, 0.0031411999370902777f, 0.0015190509147942066f, 0.0026904623955488205f, 0.001938444678671658f, 0.0031864570919424295f, 0.0015936276176944375f, 0.009308640845119953f, 0.003960610367357731f, 0.004039160441607237f, 0.002238751156255603f, 0.0018508286448195577f, 0.005559205077588558f, 0.002591794589534402f, 0.0023178388364613056f, 0.002033236203715205f, 0.0022735954262316227f, 0.0030386638827621937f, 0.0010549572762101889f, 0.0028410092927515507f, 0.0025893463753163815f, 0.002453750465065241f, 0.0014976055826991796f, 0.00217417161911726f, 0.0021152503322809935f, 0.01829242892563343f, 0.0009215238969773054f, 0.0014531933702528477f, 0.00340569787658751f, 0.002753385342657566f, 0.008859327994287014f, 0.0033220993354916573f, 0.003910169471055269f, 0.004113996401429176f, 0.0010800198651850224f, 0.0019489770056679845f, 0.006500458810478449f, 0.0025177302304655313f, 0.0031780956778675318f, 0.0021878723055124283f, 0.0046583786606788635f, 0.005445216782391071f, 0.0013602579711005092f, 0.0015666851541027427f, 0.004322485998272896f, 0.004949651658535004f, 0.000647640903480351f, 0.003182602347806096f, 0.0025690102484077215f, 0.0022273161448538303f, 0.0017670345259830356f, 0.002119215205311775f, 0.0023621274158358574f, 0.004015693906694651f, 0.0010100130457431078f, 0.002251250669360161f, 0.006651652045547962f, 0.002480211202055216f, 0.004033237230032682f, 0.0017901611281558871f, 0.005330638028681278f, 0.0012920681620016694f, 0.0015178605681285262f, 0.005763121880590916f, 0.0027047856710851192f, 0.0013981949305161834f, 0.0019771780353039503f, 0.006798233836889267f, 0.0024615295697003603f, 0.0037387122865766287f, 0.0016412336844950914f, 0.00815185159444809f, 0.002845985582098365f, 0.00691735977306962f, 0.002755161141976714f, 0.0069012148305773735f, 0.00751645490527153f, 0.005799248814582825f, 0.008003203198313713f, 0.0025697185192257166f, 0.0018346679862588644f, 0.002526030642911792f, 0.0032049226574599743f, 0.008273505605757236f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #218 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020814066752791405f, 0.013453737832605839f, 0.01733287423849106f, 0.00882683414965868f, 0.012606008909642696f, 0.015118841081857681f, 0.013845168054103851f, 0.011161630973219872f, 0.012052697129547596f, 0.016603197902441025f, 0.012538066133856773f, 0.01504396554082632f, 0.008446351625025272f, 0.011700242757797241f, 0.015167387202382088f, 0.015096805058419704f, 0.01915675960481167f, 0.017912274226546288f, 0.02413829416036606f, 0.014698068611323833f, 0.01735294610261917f, 0.0077560776844620705f, 0.012388031929731369f, 0.012365937232971191f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #219 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041956454515457153f, 0.0006463839672505856f, 0.000691469176672399f, 0.0010804336052387953f, 0.0003743643464986235f, 0.0004824716306757182f, 0.000350326910847798f, 0.000764574040658772f, 0.000266521266894415f, 0.0006810975028201938f, 0.0004646977176889777f, 0.0007483952213078737f, 0.00032279439619742334f, 0.0005202944157645106f, 0.000516268890351057f, 0.000662173901218921f, 0.0005609580548480153f, 0.00018478173296898603f, 0.0010429495014250278f, 0.00043952252599410713f, 0.00030826221336610615f, 0.00038735358975827694f, 0.0003177866747137159f, 0.0009005101164802909f, 0.0008613974205218256f, 0.00017185784236062318f, 0.0006627432303503156f, 0.00019524783419910818f, 0.0006917990394867957f, 0.0004077201010659337f, 0.0003157369792461395f, 0.00047455448657274246f, 0.0005042520351707935f, 0.0006743244011886418f, 0.00041058275382965803f, 0.0006638834602199495f, 0.0005083931027911603f, 0.0006721094832755625f, 0.0007179478416219354f, 0.001090405392460525f, 0.0006478080176748335f, 0.0004917719634249806f, 0.0005474347854033113f, 0.0005524134612642229f, 0.00043332879431545734f, 0.0005122798029333353f, 0.000873681390658021f, 0.0003194060118403286f, 0.0012567598605528474f, 0.000840420019812882f, 0.000518596323672682f, 0.0005206004134379327f, 0.0011351112043485045f, 0.0006607067189179361f, 0.0003448828647378832f, 0.00022173293109517545f, 0.0010462086647748947f, 0.00038849093834869564f, 0.001972162164747715f, 0.0006204103701747954f, 0.0008636302081868052f, 0.000384681043215096f, 0.0006135625299066305f, 0.0005175826954655349f, 0.0004546708660200238f, 0.000723598466720432f, 0.0004528275749180466f, 0.00039550289511680603f, 0.000754357548430562f, 0.0012277895584702492f, 0.0003271731548011303f, 0.000837841012980789f, 0.00045965483877807856f, 0.0003585789818316698f, 0.0005873870104551315f, 0.0007117060595192015f, 0.0005012628389522433f, 0.0006759660900570452f, 0.00035784405190497637f, 0.0003013290115632117f, 0.00014604406896978617f, 0.0007286919862963259f, 0.00111069914419204f, 0.0006207448313944042f, 0.00030987904756329954f, 0.000955587369389832f, 0.0008342275978066027f, 0.0005090053309686482f, 0.0007999902591109276f, 0.00037991523277014494f, 0.0006881547160446644f, 0.001427750801667571f, 0.0006275872583501041f, 0.0005661012255586684f, 0.00036778030334971845f, 0.0007587475702166557f, 0.0005310410633683205f, 0.0002754482557065785f, 0.0008912381017580628f, 0.0006263813702389598f, 0.0006893107201904058f, 0.0007995765190571547f, 0.00043503488996066153f, 0.00041312776738777757f, 0.0005774982855655253f, 0.00027675481396727264f, 9.588900138624012e-05f, 0.000659481855109334f, 0.0007377623114734888f, 0.0008573859231546521f, 0.00033154975972138345f, 0.0005517698009498417f, 0.00044631166383624077f, 0.0004155429487582296f, 0.0004745133046526462f, 0.0006218630587682128f, 0.0002705855877138674f, 0.0006005525356158614f, 0.00024231956922449172f, 0.0004127382708247751f, 0.000304617133224383f, 0.000895595527254045f, 0.0006024488830007613f, 0.0005561342113651335f, 0.0013285441091284156f, 0.00122231210116297f, 0.0008378047496080399f, 0.0007360913441516459f, 0.00024254302843473852f, 0.00015692284796386957f, 0.00043260015081614256f, 0.0005770944408141077f, 0.0005820653750561178f, 0.0018243712838739157f, 0.0005638198344968259f, 0.00044363891356624663f, 0.0001886625832412392f, 0.0005926375743001699f, 0.0007352249813266098f, 0.0004212603671476245f, 0.0005105139571242034f, 0.00033831523614935577f, 0.0004513222083915025f, 0.0005040248506702483f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #220 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0063024782575666904f, 0.010578920133411884f, 0.0071891010738909245f, 0.006205305922776461f, 0.007295562885701656f, 0.008914565667510033f, 0.01793777011334896f, 0.009943167679011822f, 0.012018507346510887f, 0.019353102892637253f, 0.012069297023117542f, 0.003148117568343878f, 0.014825363643467426f, 0.012483379803597927f, 0.01873123086988926f, 0.013064710423350334f, 0.007763013243675232f, 0.02489614672958851f, 0.008839252404868603f, 0.017195500433444977f, 0.01379887294024229f, 0.04208981990814209f, 0.026079900562763214f, 0.00863010622560978f, 0.004378203768283129f, 0.01830284111201763f, 0.009633317589759827f, 0.008704054169356823f, 0.009722772985696793f, 0.01075510773807764f, 0.01069870125502348f, 0.02143567055463791f, 0.01970645971596241f, 0.00838319119066f, 0.01597430929541588f, 0.02016424387693405f, 0.009566225111484528f, 0.02454712614417076f, 0.016003243625164032f, 0.013088872656226158f, 0.009394259192049503f, 0.0029290844686329365f, 0.018821220844984055f, 0.009524730034172535f, 0.006206572987139225f, 0.012377426959574223f, 0.016315797343850136f, 0.011036595329642296f, 0.005107680801302195f, 0.009759130887687206f, 0.024930531159043312f, 0.015071281231939793f, 0.0014886934077367187f, 0.007707397919148207f, 0.009135117754340172f, 0.014591986313462257f, 0.007623972836881876f, 0.014224998652935028f, 0.0042434376664459705f, 0.007556179538369179f, 0.021266013383865356f, 0.025775445625185966f, 0.01089649647474289f, 0.016431177034974098f, 0.009683480486273766f, 0.006521483417600393f, 0.013909760862588882f, 0.02006593532860279f, 0.0070939697325229645f, 0.005144486203789711f, 0.023649513721466064f, 0.02155638113617897f, 0.011921051889657974f, 0.011834356933832169f, 0.0075264316983520985f, 0.009128441102802753f, 0.006328476592898369f, 0.005766845773905516f, 0.015962425619363785f, 0.008611947298049927f, 0.04204673692584038f, 0.00893566757440567f, 0.004977501463145018f, 0.008677360601723194f, 0.00921744666993618f, 0.004052184522151947f, 0.009587033651769161f, 0.008520219475030899f, 0.004696493968367577f, 0.021225085482001305f, 0.009441499598324299f, 0.0026352964341640472f, 0.007806704845279455f, 0.020548390224575996f, 0.018851926550269127f, 0.019205382093787193f, 0.006814379710704088f, 0.015604152344167233f, 0.005084109026938677f, 0.01865759678184986f, 0.007149957120418549f, 0.0026963413693010807f, 0.014025965705513954f, 0.025441566482186317f, 0.01729646697640419f, 0.016403764486312866f, 0.021713875234127045f, 0.007790225557982922f, 0.005476681515574455f, 0.015108994208276272f, 0.021088654175400734f, 0.018235988914966583f, 0.008172222413122654f, 0.02062252350151539f, 0.012167076580226421f, 0.032058823853731155f, 0.02109176106750965f, 0.009675093926489353f, 0.012969516217708588f, 0.008563701063394547f, 0.029822373762726784f, 0.002734704175963998f, 0.015394417569041252f, 0.012707238085567951f, 0.011292202398180962f, 0.003555131843313575f, 0.006071166601032019f, 0.018724776804447174f, 0.020733114331960678f, 0.01953858882188797f, 0.009696113876998425f, 0.008432446978986263f, 0.0077855647541582584f, 0.003543757600709796f, 0.03064115345478058f, 0.019460026174783707f, 0.026375776156783104f, 0.007440605666488409f, 0.011038187891244888f, 0.011713280342519283f, 0.017116190865635872f, 0.007453962229192257f, 0.0093907555565238f, 0.011356208473443985f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #221 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037508655805140734f, 0.002379485173150897f, 0.002917193342000246f, 0.009514507837593555f, 0.002718162490054965f, 0.0033131898380815983f, 0.004429314751178026f, 0.013254696503281593f, 0.0056919739581644535f, 0.003397715277969837f, 0.0029317124281078577f, 0.00545883271843195f, 0.017609667032957077f, 0.003404264571145177f, 0.0041459728963673115f, 0.00812346301972866f, 0.003016171045601368f, 0.003330717096105218f, 0.0025266932789236307f, 0.005549284629523754f, 0.0020930119790136814f, 0.014378264546394348f, 0.004580268636345863f, 0.004278520587831736f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #222 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009131169063039124f, 0.0001518289209343493f, 0.00011850173905258998f, 0.0010324054164811969f, 0.0006492122774943709f, 0.0004924951354041696f, 0.0006558001041412354f, 0.0006353416247293353f, 0.00035574019420892f, 0.00019537263142410666f, 0.00033215858275070786f, 0.0006348103634081781f, 0.0006592116551473737f, 0.0007394430576823652f, 0.00012196673196740448f, 0.0003652275481726974f, 0.0009363588760606945f, 0.00044815681758336723f, 0.000774682906921953f, 0.0005156134720891714f, 0.0012703543761745095f, 0.0007043906371109188f, 0.0005201375461183488f, 0.00029050675220787525f, 0.0012014347594231367f, 0.0007262708386406302f, 0.0005673436098732054f, 0.00034483830677345395f, 0.0007498051272705197f, 0.0008190879016183317f, 0.0006709634908474982f, 0.0005233669653534889f, 0.0007659331313334405f, 0.00035300219315104187f, 0.0006477506249211729f, 0.0005525816231966019f, 0.00042416443466208875f, 0.000200414375285618f, 0.0006313060875982046f, 0.0005240167956799269f, 0.0005969999474473298f, 0.0007748384377919137f, 0.0005070616607554257f, 0.0009679303620941937f, 0.0006312184850685298f, 0.0006632424192503095f, 0.00034691407927311957f, 0.0007458913023583591f, 0.0004055038734804839f, 0.00042278331238776445f, 0.0004765877965837717f, 0.0006064791814424098f, 0.0006162862991914153f, 0.0007756985141895711f, 0.0004207950842101127f, 0.0008217094582505524f, 0.0011943979188799858f, 0.0002236696454929188f, 0.0006655880715698004f, 0.000496895401738584f, 0.0002448213053867221f, 0.00030474693630822003f, 0.0003929650702048093f, 0.00042754001333378255f, 0.0004460423078853637f, 0.0008694828720763326f, 0.0005341343930922449f, 0.0005591105436906219f, 0.00025745146558620036f, 0.0010818621376529336f, 0.0005595876718871295f, 0.0007338449941016734f, 0.000565507507417351f, 0.00048291689017787576f, 0.0003277379728388041f, 0.0005536766839213669f, 0.00041116573265753686f, 0.00035818148171529174f, 0.0005717729800380766f, 0.0003213914460502565f, 0.0005272402777336538f, 0.0008508118917234242f, 0.000662679027300328f, 0.00021619674225803465f, 0.0004615579382516444f, 0.0003589162661228329f, 0.0007846159860491753f, 0.0007247919565998018f, 0.0003594783484004438f, 0.00045083349687047303f, 0.0006730009336024523f, 0.000617029145359993f, 0.00027140285237692297f, 0.00046409445349127054f, 0.00020681714522652328f, 0.0005302032805047929f, 0.0004593790217768401f, 0.0012962217442691326f, 0.0007655929075554013f, 0.0007194122299551964f, 0.000539101951289922f, 0.0006529566599056125f, 0.0006521438481286168f, 0.0005421001696959138f, 0.0008757736068218946f, 0.0004842424823436886f, 0.0006297242944128811f, 0.000456074281828478f, 0.00042309905984438956f, 0.0008483167621307075f, 0.00037046248326078057f, 0.0004189099417999387f, 0.0008400219958275557f, 0.0007167017902247608f, 0.0008141183643601835f, 0.0005039583775214851f, 0.000571470009163022f, 0.0006475442205555737f, 0.0008112965733744204f, 0.0010195157956331968f, 0.00042524756281636655f, 0.000718629511538893f, 0.000350684771547094f, 0.0006496301502920687f, 0.0006317985826171935f, 0.0006863404996693134f, 0.0006153503782115877f, 0.0008311748970299959f, 0.0010476059978827834f, 0.0008355063619092107f, 0.00026300724130123854f, 0.000492751831188798f, 0.0005583296879194677f, 0.0007535145268775523f, 0.00082587223732844f, 0.0009422805742360651f, 0.000995415379293263f, 0.0005631435196846724f, 0.00021186450612731278f, 0.0011691730469465256f, 0.00047260100836865604f, 0.0006454343092627823f, 0.0005199933075346053f, 0.0005174902034923434f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #223 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015795957297086716f, 0.02113594114780426f, 0.032661691308021545f, 0.003975669387727976f, 0.009423177689313889f, 0.009405890479683876f, 0.02299901284277439f, 0.005038600414991379f, 0.01714610494673252f, 0.01071302779018879f, 0.004839991685003042f, 0.0033562371972948313f, 0.06701355427503586f, 0.006766380742192268f, 0.010616534389555454f, 0.017687059938907623f, 0.010931368917226791f, 0.0032409566920250654f, 0.009197124280035496f, 0.010339519008994102f, 0.003800303442403674f, 0.016990019008517265f, 0.010393719188869f, 0.02344125509262085f, 0.0021826825104653835f, 0.01096012257039547f, 0.00765686109662056f, 0.007797219790518284f, 0.011244023218750954f, 0.0056784143671393394f, 0.015760168433189392f, 0.015095463953912258f, 0.01663707010447979f, 0.00830823089927435f, 0.019481096416711807f, 0.004434632603079081f, 0.008538179099559784f, 0.017747053876519203f, 0.011216100305318832f, 0.010865513235330582f, 0.007871630601584911f, 0.0029184066224843264f, 0.006617308594286442f, 0.005829920992255211f, 0.020672764629125595f, 0.007568414323031902f, 0.016915246844291687f, 0.009045835584402084f, 0.012874430976808071f, 0.010485007427632809f, 0.014388767071068287f, 0.006542600691318512f, 0.007204894442111254f, 0.013957040384411812f, 0.008285383693873882f, 0.008337211795151234f, 0.006522991694509983f, 0.014277222566306591f, 0.005077808164060116f, 0.006800107192248106f, 0.009129351936280727f, 0.023902669548988342f, 0.009555168449878693f, 0.01544593833386898f, 0.008065051399171352f, 0.005014786496758461f, 0.012303806841373444f, 0.007637996692210436f, 0.01954612322151661f, 0.0010697656543925405f, 0.006783366668969393f, 0.017076950520277023f, 0.01110762543976307f, 0.006392961833626032f, 0.008756978437304497f, 0.04447302967309952f, 0.005675983615219593f, 0.011612771078944206f, 0.007817286998033524f, 0.005796693731099367f, 0.01087223831564188f, 0.005815617740154266f, 0.025026051327586174f, 0.007192688062787056f, 0.007499960716813803f, 0.008704425767064095f, 0.009757384657859802f, 0.00759100029245019f, 0.015283111482858658f, 0.022481746971607208f, 0.008052404969930649f, 0.003190790070220828f, 0.018310876563191414f, 0.0023483752738684416f, 0.01738174818456173f, 0.009599127806723118f, 0.011883645318448544f, 0.005074652377516031f, 0.00802924856543541f, 0.0072210002690553665f, 0.005353167187422514f, 0.003739001927897334f, 0.0013252440840005875f, 0.011076182126998901f, 0.006128997541964054f, 0.011440986767411232f, 0.017808113247156143f, 0.006506009958684444f, 0.010136771947145462f, 0.01065410953015089f, 0.006228665355592966f, 0.017749467864632607f, 0.0066220443695783615f, 0.004046334885060787f, 0.007716715335845947f, 0.004179073963314295f, 0.01990077830851078f, 0.009331367909908295f, 0.01875230111181736f, 0.005362165160477161f, 0.011023832485079765f, 0.054732900112867355f, 0.015841010957956314f, 0.006445102859288454f, 0.016777684912085533f, 0.0030165654607117176f, 0.007210537325590849f, 0.006282809656113386f, 0.00512761902064085f, 0.007164247799664736f, 0.030286435037851334f, 0.011469384655356407f, 0.011811629869043827f, 0.0020109836477786303f, 0.002588527277112007f, 0.011653516441583633f, 0.0015512985410168767f, 0.006112825125455856f, 0.04585814103484154f, 0.0043903617188334465f, 0.020983748137950897f, 0.005651392508298159f, 0.006240128073841333f, 0.010212663561105728f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #224 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0046039302833378315f, 0.0050002881325781345f, 0.009579973295331001f, 0.015563166700303555f, 0.002847866155207157f, 0.011661702767014503f, 0.004573441110551357f, 0.02048935741186142f, 0.008211708627641201f, 0.004239792004227638f, 0.00630906131118536f, 0.005590250249952078f, 0.019843650981783867f, 0.009774915874004364f, 0.004416280891746283f, 0.01620623841881752f, 0.0042841024696826935f, 0.0037694727070629597f, 0.0037417938001453876f, 0.008607708849012852f, 0.0032941531389951706f, 0.01521135400980711f, 0.007815180346369743f, 0.006040362175554037f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #225 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000716435257345438f, 0.0004694865201599896f, 0.0009114851709455252f, 0.0005159730790182948f, 0.0004153277550358325f, 0.0005589482607319951f, 0.0004995740018785f, 0.000368978624464944f, 0.00046052286052145064f, 0.0007000617915764451f, 0.0002497695095371455f, 0.0005104559822939336f, 0.0002588922798167914f, 0.0005953272921033204f, 0.0003958078450523317f, 0.0006179458578117192f, 0.00024561211466789246f, 0.000341776612913236f, 0.0006390151684172451f, 0.00018405453010927886f, 0.0006661761435680091f, 0.0005954944645054638f, 0.00018696737242862582f, 0.0007075932226143777f, 0.0003667279670480639f, 0.0009494230034761131f, 0.0013407017104327679f, 0.0009865501197054982f, 0.00039547355845570564f, 0.0005880890530534089f, 0.0005477578961290419f, 0.0003339849354233593f, 0.00043642192031256855f, 0.00028693521744571626f, 0.0008859377121552825f, 0.0004984631668776274f, 0.00027516460977494717f, 0.0004705535829998553f, 0.0004691103531513363f, 0.0004073438758496195f, 0.000408793828682974f, 0.0006790499319322407f, 0.0004594687488861382f, 0.00031266111182048917f, 0.0005272103589959443f, 0.0002077307872241363f, 0.0004108468710910529f, 0.0010540870716795325f, 0.0005152395460754633f, 0.000633754360023886f, 0.0007613409543409944f, 0.0004825346695724875f, 0.00042926400783471763f, 0.0007143749389797449f, 0.0006898097926750779f, 0.0004981335368938744f, 0.000144156176247634f, 0.00026367438840679824f, 0.00034898691228590906f, 0.0002971912908833474f, 0.0004209882172290236f, 0.00019304905436001718f, 0.0006859872373752296f, 0.0007684950833208859f, 0.0003967780212406069f, 0.00021805052529089153f, 0.0005405560950748622f, 0.00023805821547284722f, 0.0007083459058776498f, 0.00019807204080279917f, 0.00020144888549111784f, 0.0007238416001200676f, 0.00038139219395816326f, 0.0004292831872589886f, 0.0005629595252685249f, 0.0005487604648806155f, 0.00028228157316334546f, 0.0002831273595802486f, 0.0005020443932153285f, 0.0003148575488012284f, 0.0004737533163279295f, 0.00030486914329230785f, 0.00025810650549829006f, 0.0007362761534750462f, 0.00030771541059948504f, 0.0004294269601814449f, 0.0005358881317079067f, 0.0006714404444210231f, 0.00028996929177083075f, 0.0004941007355228066f, 0.0005873272893950343f, 0.0006194965681061149f, 0.0005195019184611738f, 0.0006242923554964364f, 0.0006946337525732815f, 0.0010113709140568972f, 0.0007765516056679189f, 0.0002466631412971765f, 0.0006548350211232901f, 0.0003890452499035746f, 0.00035784891224466264f, 0.0003002854937221855f, 0.0006513796397484839f, 0.0002576715487521142f, 0.0007242619176395237f, 0.0005045519792474806f, 0.0009226278052665293f, 0.00033517644624225795f, 0.000540993467438966f, 0.0008316902676597238f, 0.00017478562949690968f, 0.00029652920784428716f, 0.0005075665540061891f, 0.00044668110786005855f, 0.0005353041342459619f, 0.00034850832889787853f, 0.0003023025637958199f, 0.0008241607574746013f, 0.00041144865099340677f, 0.0005832893075421453f, 0.0005441591492854059f, 0.00042787956772372127f, 0.0004147218423895538f, 0.00039510676288045943f, 0.0007962856907397509f, 0.00035354713327251375f, 0.00039035078953020275f, 0.00034685933496803045f, 0.0005451210308820009f, 0.0004042106738779694f, 0.00036839485983364284f, 0.0006398870027624071f, 0.00048737283213995397f, 0.0006634991732425988f, 0.00036781144444830716f, 0.0005341848009265959f, 0.0003098645538557321f, 0.0007312348461709917f, 0.0007493162993341684f, 0.0005827795248478651f, 0.00023844403040129691f, 0.0006312225596047938f, 0.000516542000696063f, 0.0003237065684515983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #226 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00262721860781312f, 0.00913160014897585f, 0.010927475057542324f, 0.006353785749524832f, 0.02077450044453144f, 0.016947275027632713f, 0.005207562819123268f, 0.011675659567117691f, 0.00578387500718236f, 0.008554436266422272f, 0.011647005565464497f, 0.010279611684381962f, 0.020646236836910248f, 0.006168333347886801f, 0.01438427809625864f, 0.003445346374064684f, 0.02778179757297039f, 0.005122537724673748f, 0.010865076445043087f, 0.017315179109573364f, 0.011875947937369347f, 0.007567014079540968f, 0.02353268675506115f, 0.0028385957702994347f, 0.018384894356131554f, 0.0016096370527520776f, 0.00940596591681242f, 0.01509731262922287f, 0.009811490774154663f, 0.00811045616865158f, 0.002101256512105465f, 0.02022608555853367f, 0.009676072746515274f, 0.012126818299293518f, 0.0061569176614284515f, 0.0031255597714334726f, 0.007765223737806082f, 0.007274856325238943f, 0.007464762777090073f, 0.006000516004860401f, 0.004793697502464056f, 0.004551458638161421f, 0.0043760910630226135f, 0.013692106120288372f, 0.009354203008115292f, 0.019764957949519157f, 0.009805711917579174f, 0.002554845530539751f, 0.008557725697755814f, 0.006241925526410341f, 0.007022184319794178f, 0.007671656087040901f, 0.008722337894141674f, 0.006247815676033497f, 0.004853221122175455f, 0.0045617856085300446f, 0.03554277867078781f, 0.010859736241400242f, 0.016843346878886223f, 0.004788050428032875f, 0.020874062553048134f, 0.03237900882959366f, 0.00825341884046793f, 0.0062577989883720875f, 0.01306206826120615f, 0.01160849817097187f, 0.013740944676101208f, 0.01731068268418312f, 0.0160661768168211f, 0.01497006043791771f, 0.01284685917198658f, 0.004870272241532803f, 0.009454133920371532f, 0.019929854199290276f, 0.011970671825110912f, 0.013854335062205791f, 0.011910704895853996f, 0.016860976815223694f, 0.002946708584204316f, 0.02160719223320484f, 0.00511526083573699f, 0.012308645993471146f, 0.013589498586952686f, 0.012605829164385796f, 0.00955094676464796f, 0.009341784752905369f, 0.030556952580809593f, 0.005919079761952162f, 0.017402729019522667f, 0.010227177292108536f, 0.006570605561137199f, 0.014762964099645615f, 0.007389985956251621f, 0.00815830659121275f, 0.00892061460763216f, 0.004294504411518574f, 0.004740393720567226f, 0.007152820937335491f, 0.010701053775846958f, 0.017831796780228615f, 0.0040333326905965805f, 0.014775597490370274f, 0.007536894641816616f, 0.01288152951747179f, 0.00799991562962532f, 0.00869958009570837f, 0.0179363451898098f, 0.015701327472925186f, 0.006664642132818699f, 0.005598615854978561f, 0.00681160856038332f, 0.012243852950632572f, 0.007565253879874945f, 0.012621997855603695f, 0.004739012103527784f, 0.016851291060447693f, 0.014057498425245285f, 0.0026120117399841547f, 0.005478722508996725f, 0.005985314957797527f, 0.021052300930023193f, 0.0024653153959661722f, 0.006298562977463007f, 0.012823870405554771f, 0.008066121488809586f, 0.01405340526252985f, 0.01401097234338522f, 0.011673474684357643f, 0.010210595093667507f, 0.003595188492909074f, 0.006179106887429953f, 0.017084728926420212f, 0.01167660765349865f, 0.028471902012825012f, 0.014212939888238907f, 0.004274400882422924f, 0.015037832781672478f, 0.007272257469594479f, 0.004915070254355669f, 0.002205739263445139f, 0.02185891382396221f, 0.003961827140301466f, 0.0123734837397933f, 0.009926964528858662f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #227 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004279810469597578f, 0.004098954144865274f, 0.007539062295109034f, 0.00682659400627017f, 0.005412285681813955f, 0.00756603991612792f, 0.0071031623519957066f, 0.016057010740041733f, 0.006867295131087303f, 0.004115781746804714f, 0.004882283508777618f, 0.005560112185776234f, 0.013707217760384083f, 0.007765359245240688f, 0.0037840416189283133f, 0.01976393535733223f, 0.004335213918238878f, 0.005686808377504349f, 0.016687139868736267f, 0.006606640759855509f, 0.002827646676450968f, 0.008297750726342201f, 0.009061494842171669f, 0.01037896703928709f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #228 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007826917571946979f, 0.00047533775796182454f, 0.0009610788547433913f, 0.0006835390231572092f, 0.0005670777172781527f, 0.0007052302826195955f, 0.0005084145814180374f, 0.0004501354123931378f, 0.0001946878619492054f, 0.0009464437607675791f, 0.000555680540855974f, 0.0003817450487986207f, 0.0015053321840241551f, 0.0005015571950934827f, 0.0007837048033252358f, 0.0005415332270786166f, 0.0008078438695520163f, 0.0005106211174279451f, 0.0006860694265924394f, 0.00028554542222991586f, 0.001261717639863491f, 0.000523883500136435f, 0.0004216911329422146f, 0.0005192020907998085f, 0.000686432933434844f, 0.00044948517461307347f, 0.00023643704480491579f, 0.00034712496562860906f, 0.00024481883156113327f, 0.00046149626723490655f, 0.0006018886924721301f, 0.0001613485801499337f, 0.0005298192845657468f, 0.0004312046803534031f, 0.00039011123590171337f, 0.0005672737024724483f, 0.0004119408840779215f, 0.000863749417476356f, 0.0005823273677378893f, 0.0008344799280166626f, 0.0006713145994581282f, 0.0008112658397294581f, 0.0004266891337465495f, 0.0007512899464927614f, 0.0002766799589153379f, 0.0008374106255359948f, 0.000884968030732125f, 0.000769738806411624f, 0.00046926463255658746f, 0.000532540725544095f, 0.0007450578850694001f, 0.0006097201840020716f, 0.000578582810703665f, 0.0005477975937537849f, 0.0006631056312471628f, 0.00012429416528902948f, 0.0005692339036613703f, 0.0004279957211110741f, 0.0006575965671800077f, 0.0008158990531228483f, 0.000309481198200956f, 0.00045264241634868085f, 0.000444093398982659f, 0.0008570612990297377f, 0.0004352388787083328f, 0.0004593027988448739f, 0.0005250498070381582f, 0.0007318369462154806f, 0.0007142568356357515f, 0.0005609634681604803f, 0.00040040307794697583f, 0.0004939419450238347f, 0.0007460060296580195f, 0.0004804649797733873f, 0.0008907876326702535f, 0.00022963016817811877f, 0.00036919451667927206f, 0.0014379348140209913f, 0.000636194774415344f, 0.00022769956558477134f, 0.0007785850903019309f, 0.0009046116028912365f, 0.0006224947283044457f, 0.000872123462613672f, 0.0007420885376632214f, 0.00031554093584418297f, 0.0004100841761101037f, 0.0006796734523959458f, 0.0006473500397987664f, 0.0010236945236101747f, 0.0006337871891446412f, 0.0006600838387385011f, 0.0005092926439829171f, 0.0006206602556630969f, 0.0005500463303178549f, 0.0005083057912997901f, 0.0005995671963319182f, 0.0009829695336520672f, 0.00036287601687945426f, 0.00048155439435504377f, 0.0006828148034401238f, 0.0006946132052689791f, 0.00044202464050613344f, 0.0007405809010379016f, 0.0006951713003218174f, 0.0006573607097379863f, 0.0003935567510779947f, 0.0008788561099208891f, 0.0007528717396780849f, 0.0005319474148564041f, 0.0007929432322271168f, 0.000512887432705611f, 0.0006699510850012302f, 0.0003695571795105934f, 0.0004759166040457785f, 0.0006916983402334154f, 0.0006889121141284704f, 0.001188540831208229f, 0.0005460074171423912f, 0.0007675382657907903f, 0.000865024165250361f, 0.0005191518575884402f, 0.0002820130321197212f, 0.001059478148818016f, 0.00031700811814516783f, 0.00033650954719632864f, 0.0006733788177371025f, 0.001195227145217359f, 0.0006848294287919998f, 0.0006840552669018507f, 0.0012055450351908803f, 0.0004560835659503937f, 0.0012618120526894927f, 0.000452869018772617f, 0.00027239701012149453f, 0.0005766497342847288f, 0.0014133586082607508f, 0.0004544296534731984f, 0.00020110396144445986f, 0.0003404456365387887f, 0.000552793440874666f, 0.0007449612021446228f, 0.0005651829997077584f, 0.0007855123258195817f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #229 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014772285940125585f, 0.004053766839206219f, 0.001880141906440258f, 0.0060570258647203445f, 0.0038058720529079437f, 0.007699847221374512f, 0.00524448836222291f, 0.009398384019732475f, 0.033496372401714325f, 0.007912379689514637f, 0.008641456253826618f, 0.006889915093779564f, 0.005138612352311611f, 0.007757196202874184f, 0.0030105765908956528f, 0.009349880740046501f, 0.005628795363008976f, 0.008181159384548664f, 0.00838508177548647f, 0.004076207987964153f, 0.006159869953989983f, 0.015894310548901558f, 0.00446748873218894f, 0.007799454964697361f, 0.00950395967811346f, 0.01069883443415165f, 0.016264259815216064f, 0.015115072950720787f, 0.013993985019624233f, 0.0036972917150706053f, 0.0012468540808185935f, 0.012585397809743881f, 0.0026820863131433725f, 0.006358159240335226f, 0.010715514421463013f, 0.003795481286942959f, 0.0015108881052583456f, 0.005644816905260086f, 0.007305354345589876f, 0.00119908491615206f, 0.0033396391663700342f, 0.004305005539208651f, 0.011286000721156597f, 0.005541685037314892f, 0.022588755935430527f, 0.0016665866132825613f, 0.0079119261354208f, 0.0037171347066760063f, 0.009338856674730778f, 0.00730736693367362f, 0.006478415336459875f, 0.005893334746360779f, 0.002821239409968257f, 0.006587386131286621f, 0.004662096034735441f, 0.028772028163075447f, 0.01001228578388691f, 0.024647139012813568f, 0.0027075852267444134f, 0.004015420097857714f, 0.012228207662701607f, 0.011939560063183308f, 0.011612657457590103f, 0.004866590723395348f, 0.00667731324210763f, 0.00331057864241302f, 0.007122451905161142f, 0.011963140219449997f, 0.006403367966413498f, 0.006143253296613693f, 0.006862171925604343f, 0.011729549616575241f, 0.008353302255272865f, 0.0023300147149711847f, 0.003977407701313496f, 0.011157350614666939f, 0.0014602247392758727f, 0.0034233094193041325f, 0.006711892317980528f, 0.018892886117100716f, 0.004042787477374077f, 0.0044230688363313675f, 0.008505182340741158f, 0.005358722060918808f, 0.0028533339500427246f, 0.008845677599310875f, 0.015504121780395508f, 0.0015148966340348125f, 0.0037391975056380033f, 0.005018013063818216f, 0.0023636280093342066f, 0.002616205019876361f, 0.005495528224855661f, 0.005620923824608326f, 0.0067900605499744415f, 0.008778950199484825f, 0.0019661379046738148f, 0.0007498021586798131f, 0.013768022879958153f, 0.0070210718549788f, 0.006241786293685436f, 0.003777966368943453f, 0.008478077128529549f, 0.0043481262400746346f, 0.005877592135220766f, 0.009612727910280228f, 0.005321326199918985f, 0.005942629650235176f, 0.00411304272711277f, 0.008821156807243824f, 0.010770910419523716f, 0.008267290890216827f, 0.004149187356233597f, 0.009426387958228588f, 0.011076658964157104f, 0.00706549221649766f, 0.006659131031483412f, 0.005815852899104357f, 0.004930128343403339f, 0.0018018840346485376f, 0.0065348390489816666f, 0.007143278140574694f, 0.017009779810905457f, 0.0021044015884399414f, 0.010251129046082497f, 0.013269308023154736f, 0.0016367530915886164f, 0.0025584932882338762f, 0.010690499097108841f, 0.011965934187173843f, 0.003346628276631236f, 0.01287359930574894f, 0.0036309179849922657f, 0.004612356889992952f, 0.00897916965186596f, 0.00961472187191248f, 0.0018119622254744172f, 0.0036187777295708656f, 0.013042294420301914f, 0.0024990118108689785f, 0.008173314854502678f, 0.009724918752908707f, 0.007990791462361813f, 0.0016012669075280428f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #230 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008857260458171368f, 0.010427121073007584f, 0.009195730090141296f, 0.011437646113336086f, 0.010122248902916908f, 0.010499678552150726f, 0.01090028416365385f, 0.009839498437941074f, 0.010634198784828186f, 0.0074335187673568726f, 0.008155004121363163f, 0.009575053118169308f, 0.007792129646986723f, 0.012465341947972775f, 0.00739618856459856f, 0.009104588069021702f, 0.009551020339131355f, 0.014144902117550373f, 0.01197013445198536f, 0.008952885866165161f, 0.008006580173969269f, 0.011634926311671734f, 0.010686686262488365f, 0.007297647651284933f, 0.00663033640012145f, 0.01740085892379284f, 0.00759786507114768f, 0.009581427089869976f, 0.008788429200649261f, 0.008282077498733997f, 0.009101226925849915f, 0.010503667406737804f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #231 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000659422657918185f, 0.0009226013207808137f, 0.0007011478883214295f, 0.00037258589873090386f, 0.0005576287512667477f, 0.000603527354542166f, 0.0006189131527207792f, 0.000522083486430347f, 0.00038996399962343276f, 0.00036181515315547585f, 0.000583885470405221f, 0.0005677801091223955f, 0.00022548565175384283f, 0.0007398234447464347f, 0.00044925790280103683f, 0.0009517366415821016f, 0.0006912538083270192f, 0.0008745307568460703f, 0.0014039702946320176f, 0.0005699310568161309f, 0.0014476148644462228f, 0.00047130807070061564f, 0.0009664773824624717f, 0.0008197889546863735f, 0.0007694950327277184f, 0.0004156157374382019f, 0.0008928650058805943f, 0.0012794033391401172f, 0.0003958888410124928f, 0.0006998283788561821f, 0.0004162428667768836f, 0.0002815107873175293f, 0.00044833094580098987f, 0.0007950846920721233f, 0.0008038611267693341f, 0.0006138578755781054f, 0.0008915450307540596f, 0.0005485363071784377f, 0.000302232539979741f, 0.000684697472024709f, 0.0007261005812324584f, 0.000849287724122405f, 0.0008214226108975708f, 0.000756879395339638f, 0.0008064222638495266f, 0.0007472580764442682f, 0.0007077465998008847f, 0.0009711754391901195f, 0.0006082283798605204f, 0.0009591501438990235f, 0.0010524544632062316f, 0.0008910406031645834f, 0.0006477347342297435f, 0.0008787690894678235f, 0.0008327329414896667f, 0.0010750234359875321f, 0.0004528679128270596f, 0.0005406938726082444f, 0.00029348049429245293f, 0.0007960893562994897f, 0.000556666636839509f, 0.001120879896916449f, 0.0012640837812796235f, 0.0011513171484693885f, 0.0006051654345355928f, 0.0009569801623001695f, 0.0007081352523528039f, 0.0008692845585756004f, 0.0009549502283334732f, 0.0018713822355493903f, 0.0007035022717900574f, 0.0009947649668902159f, 0.0015323737170547247f, 0.00036130272201262414f, 0.00027882459107786417f, 0.0009871417423710227f, 0.0009316896321251988f, 9.290854359278455e-05f, 0.0013360307784751058f, 0.00037345761666074395f, 0.00025742812431417406f, 0.0003518171142786741f, 0.0006069823284633458f, 0.0010573547333478928f, 0.0009135435102507472f, 0.0004236806707922369f, 0.0006428228807635605f, 0.0007773942197673023f, 0.0005022740224376321f, 0.001048276899382472f, 0.00038659435813315213f, 0.0008774494053795934f, 0.00034164308453910053f, 0.0009889822686091065f, 0.0004168728773947805f, 0.0008076828671619296f, 0.000924672232940793f, 0.0009309820015914738f, 0.0006090632523410022f, 0.00039687618846073747f, 0.0005362483207136393f, 0.0011974970111623406f, 0.0004493308952078223f, 0.001107756863348186f, 0.0010736898984760046f, 0.0017430108273401856f, 0.0003229948633816093f, 0.0005821716040372849f, 0.0005341842770576477f, 0.0005543605075217783f, 0.00045673592831008136f, 0.0007051100255921483f, 0.0008017655345611274f, 0.00031476301955990493f, 0.0007800491293892264f, 0.001514860661700368f, 0.00018867450125981122f, 0.0005842859973199666f, 0.00033276266185566783f, 0.0005272052367217839f, 0.0008990957285277545f, 0.00034148694248870015f, 0.0009114635759033263f, 0.00101358606480062f, 0.0007471097633242607f, 0.0005149428616277874f, 0.0007459464832209051f, 0.0005114712985232472f, 0.000857740524224937f, 0.0003468371869530529f, 0.0006377460085786879f, 0.0009500624728389084f, 0.0007771140662953258f, 0.0007934615714475513f, 0.0006937641883268952f, 0.0005285140941850841f, 0.0007424974464811385f, 0.001121792127378285f, 0.0004160275566391647f, 0.0019836886785924435f, 0.0006898092105984688f, 0.0013446783414110541f, 0.0008506513549946249f, 0.0003248763969168067f, 0.0006131997797638178f, 0.001014228560961783f, 0.0008781821234151721f, 0.0003364211297594011f, 0.00041489818249829113f, 0.0017043029656633735f, 0.00042096126708202064f, 0.0008532933425158262f, 0.0011103712022304535f, 0.0009816078236326575f, 0.0007107776473276317f, 0.001106044976040721f, 0.0007949392893351614f, 0.0005295058945193887f, 0.0008604688919149339f, 0.0008851407328620553f, 0.0005566346226260066f, 0.0011976076057180762f, 0.00041055193287320435f, 0.0003145820810459554f, 0.001014451845549047f, 0.0007342590834014118f, 0.0007787407957948744f, 0.0010568189900368452f, 0.0005740037886425853f, 0.0006394238444045186f, 0.0009673990425653756f, 0.0005213206168264151f, 0.0006232908926904202f, 0.00024277188640553504f, 0.0007764453766867518f, 0.0009118731250055134f, 0.0007112293969839811f, 0.0006671856972388923f, 0.0013249535113573074f, 0.0009684866527095437f, 0.0010994033655151725f, 0.0007928981794975698f, 0.0009147304808720946f, 0.0013032815186306834f, 0.0006297894287854433f, 0.0007338980212807655f, 0.0010436618467792869f, 0.0006382827996276319f, 0.0009538637823425233f, 0.001190775423310697f, 0.0004013430152554065f, 0.0008280878537334502f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #232 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008118631318211555f, 0.005473029799759388f, 0.00949953868985176f, 0.015933647751808167f, 0.0056959292851388454f, 0.005497517064213753f, 0.009814558550715446f, 0.00817601103335619f, 0.012026314623653889f, 0.013882195577025414f, 0.005392291583120823f, 0.016673337668180466f, 0.03650140389800072f, 0.008724159561097622f, 0.015662334859371185f, 0.002970715519040823f, 0.010297106578946114f, 0.004233159590512514f, 0.01020187046378851f, 0.008009746670722961f, 0.0032940900418907404f, 0.007858263328671455f, 0.004793193656951189f, 0.006142640020698309f, 0.008414702489972115f, 0.013666033744812012f, 0.01301671378314495f, 0.003238626988604665f, 0.010199534706771374f, 0.006690077017992735f, 0.005938697140663862f, 0.02703280746936798f, 0.013424314558506012f, 0.003761625150218606f, 0.015562494285404682f, 0.010782115161418915f, 0.005014363676309586f, 0.0052987621165812016f, 0.019611461088061333f, 0.0046734921634197235f, 0.006062740925699472f, 0.006636357866227627f, 0.007532292511314154f, 0.005793793126940727f, 0.0066346400417387486f, 0.0050417776219546795f, 0.01804095134139061f, 0.005143529269844294f, 0.01267652865499258f, 0.0016358083812519908f, 0.008855079300701618f, 0.008131664246320724f, 0.0056721908040344715f, 0.013806051574647427f, 0.0036997124552726746f, 0.0035254769027233124f, 0.008241415023803711f, 0.005633102729916573f, 0.011550212278962135f, 0.006830430123955011f, 0.007076888345181942f, 0.007441854104399681f, 0.008750495500862598f, 0.006819590926170349f, 0.019088033586740494f, 0.003321865340694785f, 0.006685149855911732f, 0.006431573070585728f, 0.003856862196698785f, 0.004659165162593126f, 0.006720451172441244f, 0.005431624129414558f, 0.0010674584191292524f, 0.01885189674794674f, 0.011809703893959522f, 0.0067985872738063335f, 0.005130115896463394f, 0.038097355514764786f, 0.005826678592711687f, 0.005472817923873663f, 0.011990982107818127f, 0.011563310399651527f, 0.008926954120397568f, 0.006793626118451357f, 0.009206718765199184f, 0.019992176443338394f, 0.005490463227033615f, 0.00493349926546216f, 0.00814175233244896f, 0.005376636050641537f, 0.021054821088910103f, 0.013004421256482601f, 0.01312517561018467f, 0.005294791888445616f, 0.014628585427999496f, 0.003986405674368143f, 0.005942100193351507f, 0.0058899689465761185f, 0.006365008186548948f, 0.01107445266097784f, 0.013458582572638988f, 0.006663620471954346f, 0.02248683199286461f, 0.004792036022990942f, 0.00597876263782382f, 0.009317716583609581f, 0.018841462209820747f, 0.01742732711136341f, 0.005932149477303028f, 0.008778329938650131f, 0.01666928455233574f, 0.005162556655704975f, 0.00400566216558218f, 0.011764854192733765f, 0.0055578346364200115f, 0.004251810722053051f, 0.019453255459666252f, 0.008789586834609509f, 0.006521958392113447f, 0.006479576695710421f, 0.006911377422511578f, 0.00868953112512827f, 0.008237699046730995f, 0.004116857890039682f, 0.003720052307471633f, 0.0050898948684334755f, 0.006434456445276737f, 0.006112674716860056f, 0.01181417889893055f, 0.0170217826962471f, 0.009544022381305695f, 0.003471692791208625f, 0.005091931205242872f, 0.003685346571728587f, 0.00730667170137167f, 0.005982507020235062f, 0.021122103556990623f, 0.004384628497064114f, 0.005568820051848888f, 0.006812233477830887f, 0.009261216036975384f, 0.0025854194536805153f, 0.0014602994779124856f, 0.026499023661017418f, 0.011087987571954727f, 0.0055356998927891254f, 0.007878042757511139f, 0.017812324687838554f, 0.012129455804824829f, 0.00619099847972393f, 0.005490260198712349f, 0.01114354096353054f, 0.00982833094894886f, 0.006171414628624916f, 0.004758504219353199f, 0.010434982366859913f, 0.005590770859271288f, 0.016956277191638947f, 0.010803846642374992f, 0.009942516684532166f, 0.010033106431365013f, 0.0034315630327910185f, 0.013461412861943245f, 0.015928862616419792f, 0.004125749692320824f, 0.008666870184242725f, 0.008798723109066486f, 0.006108432542532682f, 0.012967687100172043f, 0.0058062393218278885f, 0.009188169613480568f, 0.012763063423335552f, 0.008435283787548542f, 0.01538329292088747f, 0.009928777813911438f, 0.0029943364206701517f, 0.00612910371273756f, 0.01025637611746788f, 0.008522501215338707f, 0.006602368783205748f, 0.004683242179453373f, 0.0028378127608448267f, 0.006854070816189051f, 0.006979323457926512f, 0.007633624132722616f, 0.004867970012128353f, 0.00587696535512805f, 0.010480922646820545f, 0.007647471968084574f, 0.009268700145184994f, 0.012161887250840664f, 0.004174485336989164f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #233 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006672208663076162f, 0.005134467035531998f, 0.0020447217393666506f, 0.0012609180994331837f, 0.002566390670835972f, 0.004852015990763903f, 0.003025566693395376f, 0.007289975415915251f, 0.006489344406872988f, 0.0037949206307530403f, 0.0022400645539164543f, 0.004537752829492092f, 0.007373397704213858f, 0.0029309261590242386f, 0.00761177483946085f, 0.0111417006701231f, 0.003824943443760276f, 0.0029057213105261326f, 0.004674180876463652f, 0.006818555295467377f, 0.003461755346506834f, 0.00862955953925848f, 0.0013404042692855f, 0.011470147408545017f, 0.007249802816659212f, 0.007011960726231337f, 0.004762096330523491f, 0.0034999146591871977f, 0.009124121628701687f, 0.0031195119954645634f, 0.0085421372205019f, 0.009410875849425793f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #234 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008741934434510767f, 0.0006389304762706161f, 0.0011419218499213457f, 0.0008808015845716f, 0.0004427111998666078f, 0.00042700476478785276f, 0.0004719244025181979f, 0.0003801693383138627f, 0.0005057849921286106f, 0.0005380881484597921f, 0.0008395242039114237f, 0.0012409404153004289f, 0.0003001773147843778f, 0.0005911024054512382f, 0.0004218909307383001f, 0.001226922613568604f, 0.0007108901627361774f, 0.0005680700414814055f, 0.0003516990109346807f, 0.00023266876814886928f, 0.000543413741979748f, 0.0007505475077778101f, 0.0007754156831651926f, 0.0003589164698496461f, 0.000515432097017765f, 0.0013562159147113562f, 0.00021321841632016003f, 0.00034928438253700733f, 0.000726931553799659f, 0.0006540504400618374f, 0.0005816242774017155f, 0.00066300795879215f, 0.0007394133717752993f, 0.0006118781748227775f, 0.0012926000636070967f, 0.0007642488344572484f, 0.0006389851332642138f, 0.0006807846948504448f, 0.0006186817772686481f, 0.0006430768989957869f, 0.00042932640644721687f, 0.0006754146888852119f, 0.0004954521427862346f, 0.0006556519074365497f, 0.0006546552758663893f, 0.0005356716574169695f, 0.0005771755240857601f, 0.0007565387059003115f, 0.001144403824582696f, 0.0005431663594208658f, 0.0011216978309676051f, 0.0011310046538710594f, 0.0003597555623855442f, 0.0004037325270473957f, 0.000599019112996757f, 0.0007051262073218822f, 0.0006399726844392717f, 0.0009071451495401561f, 0.0006910505471751094f, 0.0006932010874152184f, 0.0005103550502099097f, 0.0005157484556548297f, 0.000450151099357754f, 0.0006466475897468626f, 0.0007858889875933528f, 0.0007424390641972423f, 0.0006793368374928832f, 0.0009014097740873694f, 0.0004944023094139993f, 0.00041149978642351925f, 0.0006720164092257619f, 0.0006049548974260688f, 0.0005918622482568026f, 0.0006920896121300757f, 0.00036433819332160056f, 0.0008007428259588778f, 0.0008888771990314126f, 0.0005838320357725024f, 0.00032356593874283135f, 0.0006108980742283165f, 0.0011403129901736975f, 0.0012665924150496721f, 0.0008492528577335179f, 0.0009547204826958477f, 0.0009624907397665083f, 0.0003902884782291949f, 0.00040855907718650997f, 0.000404385820729658f, 0.0007805246859788895f, 0.0010670592309907079f, 0.00023425596009474248f, 0.0005968587356619537f, 0.0007019770564511418f, 0.0009017920820042491f, 0.0010842171031981707f, 0.0002685630170162767f, 0.00045527462498284876f, 0.0010409983806312084f, 0.0008355750469490886f, 0.0004907941329292953f, 0.0005624298355542123f, 0.00025091544375754893f, 0.0009600857156328857f, 0.0005129489582031965f, 0.00044615971273742616f, 0.0006286699208430946f, 0.00044815673027187586f, 0.0008561162976548076f, 0.0007677852991037071f, 0.0012285469565540552f, 0.0004440551274456084f, 0.0006963592604734004f, 0.0006398564437404275f, 0.0005384484538808465f, 0.0009942310862243176f, 0.00034942166530527174f, 0.0003833821974694729f, 0.0005972262588329613f, 0.00046780105913057923f, 0.0001848440442699939f, 0.0007724766619503498f, 0.00044972976320423186f, 0.0007879702025093138f, 0.0009442439186386764f, 0.0005926378653384745f, 0.0007717042462900281f, 0.0007627800805494189f, 0.00043328653555363417f, 0.0006548353703692555f, 0.0011872582836076617f, 0.0006710807792842388f, 0.0008731067646294832f, 0.0007491722353734076f, 0.0011219880543649197f, 0.0008887914591468871f, 0.0005871490575373173f, 0.0010687726316973567f, 0.0008937788661569357f, 0.0008075438090600073f, 0.0007975560729391873f, 0.0006052235839888453f, 0.0006308406591415405f, 0.0005049034371040761f, 0.0006034446996636689f, 0.0005804857355542481f, 0.0007330924272537231f, 0.0002656561555340886f, 0.0005011555622331798f, 0.0006368235335685313f, 0.0008430480374954641f, 0.000651899550575763f, 0.0005893554189242423f, 0.0009933008113875985f, 0.0005890009924769402f, 0.0006671790033578873f, 0.0007808427326381207f, 0.00044461467768996954f, 0.0006550819962285459f, 0.0004643096181098372f, 0.0006055208505131304f, 0.0006016542902216315f, 0.0005399213405326009f, 0.0007211301126517355f, 0.0007921619690023363f, 0.0009280586964450777f, 0.0009962967596948147f, 0.00036954201641492546f, 0.0014902944676578045f, 0.00047885862295515835f, 0.00034127040999010205f, 0.0005131695070303977f, 0.00041570229222998023f, 0.0006893081008456647f, 0.0005043628043495119f, 0.0005094492807984352f, 0.0004727017367258668f, 0.0007234089425764978f, 0.0005167541094124317f, 0.0010040128836408257f, 0.000768100144341588f, 0.0005697173182852566f, 0.000957050418946892f, 0.0004815984866581857f, 0.0005627275095321238f, 0.0009009992354549468f, 0.00038914434844627976f, 0.0011993699008598924f, 0.0008256707224063575f, 0.0009097734582610428f, 0.0006389107438735664f, 0.00036446319427341223f, 0.0009609005646780133f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #235 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012211503461003304f, 0.0057249716483056545f, 0.015093040652573109f, 0.006670110393315554f, 0.016007136553525925f, 0.005189989693462849f, 0.01881183125078678f, 0.02200399897992611f, 0.010725465603172779f, 0.0027902729343622923f, 0.0010832686675712466f, 0.006613584700971842f, 0.0027851834893226624f, 0.003992045298218727f, 0.015793995931744576f, 0.0055092452093958855f, 0.005056494846940041f, 0.00543741462752223f, 0.008507789112627506f, 0.01481811236590147f, 0.004589760676026344f, 0.005205520894378424f, 0.010210879147052765f, 0.010612593032419682f, 0.00855573732405901f, 0.003735759062692523f, 0.02658556029200554f, 0.025559885427355766f, 0.0035706842318177223f, 0.009229467250406742f, 0.0053010666742920876f, 0.004220888949930668f, 0.006367547437548637f, 0.0046178908087313175f, 0.008753635920584202f, 0.0034423053730279207f, 0.007616001181304455f, 0.0058650909923017025f, 0.005503978580236435f, 0.00791100226342678f, 0.014399425126612186f, 0.0086049884557724f, 0.006662049330770969f, 0.00671574380248785f, 0.0031811255030333996f, 0.00575045682489872f, 0.006129401735961437f, 0.001743011991493404f, 0.004050172865390778f, 0.006241899449378252f, 0.006127818953245878f, 0.0014900789828971028f, 0.010961885564029217f, 0.008519856259226799f, 0.0016764843603596091f, 0.008608372882008553f, 0.00586332194507122f, 0.008055281825363636f, 0.01572728529572487f, 0.0064133210107684135f, 0.012095486745238304f, 0.0037085297517478466f, 0.006448658183217049f, 0.0092696538195014f, 0.011591385118663311f, 0.0011996972607448697f, 0.0022419446613639593f, 0.0031227574218064547f, 0.01964028738439083f, 0.004846921190619469f, 0.009988757781684399f, 0.010320303961634636f, 0.0045129782520234585f, 0.0017676942516118288f, 0.007332773879170418f, 0.0037487545050680637f, 0.005449786316603422f, 0.018016207963228226f, 0.013009436428546906f, 0.007969025522470474f, 0.005082463845610619f, 0.007722659036517143f, 0.004807203076779842f, 0.009557939134538174f, 0.002307248068973422f, 0.009571072645485401f, 0.008912292309105396f, 0.010254329070448875f, 0.007674613501876593f, 0.004453250672668219f, 0.029294081032276154f, 0.008830559439957142f, 0.0015398528194054961f, 0.010115954093635082f, 0.0052804904989898205f, 0.015403274446725845f, 0.008278151042759418f, 0.004904834553599358f, 0.007296644151210785f, 0.007988767698407173f, 0.012742823921144009f, 0.032733771950006485f, 0.003740273881703615f, 0.0035721142776310444f, 0.013087347149848938f, 0.0026761172339320183f, 0.00808065664023161f, 0.0068161627277731895f, 0.006299419794231653f, 0.003658540081232786f, 0.004376022145152092f, 0.008220834657549858f, 0.007376017514616251f, 0.007818344049155712f, 0.0015374666545540094f, 0.013420295901596546f, 0.007963238283991814f, 0.009876832365989685f, 0.00654189009219408f, 0.017684567719697952f, 0.005849860608577728f, 0.010524994693696499f, 0.00972819235175848f, 0.005837060511112213f, 0.002672170288860798f, 0.007203712128102779f, 0.003567929845303297f, 0.0144568532705307f, 0.001936787273734808f, 0.0020210184156894684f, 0.005067434627562761f, 0.004243994597345591f, 0.004689249210059643f, 0.003829947905614972f, 0.00792365800589323f, 0.006260013673454523f, 0.0021839714609086514f, 0.006530952174216509f, 0.013740080408751965f, 0.002031933283433318f, 0.012958276085555553f, 0.005921343807131052f, 0.006422556471079588f, 0.006911406293511391f, 0.009481332264840603f, 0.006331945303827524f, 0.013115856796503067f, 0.010313221253454685f, 0.007395527325570583f, 0.007890281267464161f, 0.004741593264043331f, 0.029188552871346474f, 0.0015805453294888139f, 0.007176181301474571f, 0.008293996565043926f, 0.003987544681876898f, 0.011622949503362179f, 0.005579665303230286f, 0.004139901604503393f, 0.0074565536342561245f, 0.00568943889811635f, 0.006321127992123365f, 0.006049714051187038f, 0.005319883115589619f, 0.007833560928702354f, 0.009670907631516457f, 0.010916040278971195f, 0.001611727406270802f, 0.007681615184992552f, 0.010924765840172768f, 0.006956321187317371f, 0.006488120183348656f, 0.014314060099422932f, 0.0046018268913030624f, 0.007828405126929283f, 0.00646682595834136f, 0.004746127407997847f, 0.005074311513453722f, 0.003823228180408478f, 0.004797017201781273f, 0.00687659066170454f, 0.004473744425922632f, 0.0067991153337061405f, 0.003459699684754014f, 0.007709610741585493f, 0.00943227019160986f, 0.0029859323985874653f, 0.008246166631579399f, 0.0011204530019313097f, 0.011158204637467861f, 0.017661193385720253f, 0.007982083596289158f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #236 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013645137660205364f, 0.007524475920945406f, 0.004335123114287853f, 0.0036622541956603527f, 0.003941937815397978f, 0.009324807673692703f, 0.004149830900132656f, 0.010415391065180302f, 0.009293354116380215f, 0.0053960965014994144f, 0.007032047025859356f, 0.0071217650547623634f, 0.017421968281269073f, 0.0031155378092080355f, 0.02101983316242695f, 0.01108144037425518f, 0.0039843483828008175f, 0.004117125645279884f, 0.006312307436019182f, 0.01320353802293539f, 0.00441595446318388f, 0.01441172230988741f, 0.0031146977562457323f, 0.029717056080698967f, 0.014473874121904373f, 0.008240073919296265f, 0.005562409292906523f, 0.006131833419203758f, 0.010495049878954887f, 0.005332957487553358f, 0.018448909744620323f, 0.029741346836090088f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #237 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_151_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003997236199211329f, 0.0004493581363931298f, 0.0005045017460361123f, 0.0005312854191288352f, 0.0005986172473058105f, 0.0004944640677422285f, 0.0004355920245870948f, 0.0004526357806753367f, 0.0004324538167566061f, 0.0003954639832954854f, 0.0006176043534651399f, 0.0005538819823414087f, 0.0004550887970253825f, 0.0005055631045252085f, 0.00045628304360434413f, 0.0003602785582188517f, 0.0004234288935549557f, 0.0005900494288653135f, 0.0006737071089446545f, 0.0004029571427963674f, 0.00046316205407492816f, 0.000496470311190933f, 0.00066560652339831f, 0.00035856966860592365f, 0.0004694485105574131f, 0.0004916261532343924f, 0.00042403186671435833f, 0.0005435465718619525f, 0.0005169878713786602f, 0.0005095410742796957f, 0.0005845086416229606f, 0.0004841746704187244f, 0.0004930123104713857f, 0.0004318785504437983f, 0.0004552651662379503f, 0.0005332861328497529f, 0.0005878469091840088f, 0.0006348612951114774f, 0.0005114224622957408f, 0.0006126977386884391f, 0.000623755098786205f, 0.0005908400635235012f, 0.0004472017171792686f, 0.0005029372405260801f, 0.0005383380339480937f, 0.0005215539713390172f, 0.0005094065563753247f, 0.0004988660220988095f, 0.0005549860070459545f, 0.0006138051394373178f, 0.00045135122491046786f, 0.000575434765778482f, 0.0005980539717711508f, 0.0003514553827699274f, 0.0005085629527457058f, 0.0006380761042237282f, 0.0005162684246897697f, 0.0005042348639108241f, 0.00044985616113990545f, 0.0004856552113778889f, 0.000508599856402725f, 0.0005346632678993046f, 0.00038723996840417385f, 0.0006089664530009031f, 0.00041627648170106113f, 0.00048318406334146857f, 0.0006414252566173673f, 0.00045640344615094364f, 0.0005032087792642415f, 0.0005117601831443608f, 0.0005935317021794617f, 0.0003682256501633674f, 0.0005484931753017008f, 0.0005122137954458594f, 0.00034679577220231295f, 0.0004821426991838962f, 0.000518840504810214f, 0.00045303860679268837f, 0.0006239248323254287f, 0.0005534874508157372f, 0.000482379604363814f, 0.00042339577339589596f, 0.00048738360055722296f, 0.0004495568573474884f, 0.000431249471148476f, 0.00040664029074832797f, 0.0005662914481945336f, 0.0004888535477221012f, 0.000538892752956599f, 0.0005510670598596334f, 0.0004976370837539434f, 0.00047766571515239775f, 0.00050113326869905f, 0.0004067686677444726f, 0.0004851842240896076f, 0.0005976420943625271f, 0.0007700814749114215f, 0.0004954022588208318f, 0.00045236601727083325f, 0.0005117167602293193f, 0.0004566854622680694f, 0.000512479804456234f, 0.0004043729859404266f, 0.00044144419371150434f, 0.0005702245980501175f, 0.0004602546396199614f, 0.00048042883281596005f, 0.0005761714419350028f, 0.00045536973630078137f, 0.0005036434740759432f, 0.0004546132986433804f, 0.0004339538572821766f, 0.0005282905767671764f, 0.000495877698995173f, 0.0005657325382344425f, 0.00044892929145134985f, 0.0004423523205332458f, 0.00035715950070880353f, 0.00042119549470953643f, 0.00034151170984841883f, 0.00035337969893589616f, 0.0004473215085454285f, 0.0005246928194537759f, 0.0005866492283530533f, 0.0003955656138714403f, 0.0005678865709342062f, 0.0006579575128853321f, 0.0005469598690979183f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #238 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000630129361525178f, 0.0004705622559413314f, 0.0005920425173826516f, 0.0006569591350853443f, 0.0008142833248712122f, 0.0010177806252613664f, 0.0006406690808944404f, 0.0008163321763277054f, 0.0006339129176922143f, 0.0004707643820438534f, 0.0004266102041583508f, 0.0006496371934190392f, 0.0008140363497659564f, 0.0006152103887870908f, 0.0010328078642487526f, 0.0008183065801858902f, 0.0007663057767786086f, 0.0007871835841797292f, 0.0008154718088917434f, 0.0006615153979510069f, 0.000614942517131567f, 0.0007981727831065655f, 0.000740192539524287f, 0.001133848913013935f, 0.0009697464993223548f, 0.0006591299315914512f, 0.0005760917556472123f, 0.0006742252153344452f, 0.0008991595241241157f, 0.0007395718130283058f, 0.0002999512362293899f, 0.00044904055539518595f, 0.0006421665311791003f, 0.0006509983213618398f, 0.0009160770568996668f, 0.0002972263318952173f, 0.0006097846198827028f, 0.0009117402951233089f, 0.0007475843885913491f, 0.0004469033156055957f, 0.0006649557035416365f, 0.0006111411494202912f, 0.0005301852943375707f, 0.0007725202012807131f, 0.0010063386289402843f, 0.0007273838273249567f, 0.0007974720210768282f, 0.0005571850924752653f, 0.0007597790099680424f, 0.000752104097045958f, 0.0012515841517597437f, 0.0006835989188402891f, 0.0006012982339598238f, 0.0010991215240210295f, 0.0009601926431059837f, 0.0007221023552119732f, 0.0005947084864601493f, 0.0005974041996523738f, 0.0007504020468331873f, 0.0012424261076375842f, 0.00011738295870600268f, 0.0005902069387957454f, 0.0008451127796433866f, 0.0011407277779653668f, 0.000738874776288867f, 0.0004374414565972984f, 0.0005609679501503706f, 0.0006232662708498538f, 0.0007938939379528165f, 0.0005093389772810042f, 0.0010050003184005618f, 0.0006925304769538343f, 0.00035873608430847526f, 0.0005391845479607582f, 0.0007671680650673807f, 0.0007380397873930633f, 0.0011751330457627773f, 0.0010562946554273367f, 0.0005436140927486122f, 0.0007372034015133977f, 0.0007632958586327732f, 0.0005408248398452997f, 0.0004603980924002826f, 0.0007851708796806633f, 0.000496274558827281f, 0.0005419764202088118f, 0.0006252480088733137f, 0.0008658497245050967f, 0.0009293980547226965f, 0.0006280157249420881f, 0.0007314226240850985f, 0.0005591639201156795f, 0.0009996325243264437f, 0.0004529142170213163f, 0.0007146695861592889f, 0.0008937740931287408f, 0.0007729569915682077f, 0.0014129637274891138f, 0.0006524554337374866f, 0.0016225832514464855f, 0.0007151840254664421f, 0.0005135484389029443f, 0.0005236223805695772f, 0.0006964262574911118f, 0.00079109868966043f, 0.0004552406317088753f, 0.0005855544586665928f, 0.0009055644040927291f, 0.0012366522569209337f, 0.00042928042239509523f, 0.0005548320477828383f, 0.00048030601465143263f, 0.000879155530128628f, 0.0005349655984900892f, 0.0006607178947888315f, 0.0009060283773578703f, 0.0006318999221548438f, 0.0005201718886382878f, 0.00047992178588174284f, 0.0009090712992474437f, 0.0008239962044171989f, 0.0007909146370366216f, 0.0017083476996049285f, 0.0005835312767885625f, 0.0004731400986202061f, 0.0008715781150385737f, 0.0006185827078297734f, 0.0006413108785636723f, 0.001238879980519414f, 0.0010870269034057856f, 0.0007285157334990799f, 0.00042789915460161865f, 0.0012039804132655263f, 0.0008441457175649703f, 0.0004267255135346204f, 0.0006090101087465882f, 6.771514017600566e-05f, 0.0006886696210131049f, 0.0005422882968559861f, 0.001295204390771687f, 0.0006446948391385376f, 0.0006996543379500508f, 0.0007026490638963878f, 0.0009698925423435867f, 0.0009659469360485673f, 0.000828427029773593f, 0.0004399420286063105f, 0.0004529468424152583f, 0.0004075280448887497f, 0.0005752068827860057f, 0.0005384376854635775f, 0.0004757173592224717f, 0.000650963163934648f, 0.0006419590790756047f, 0.000715638161636889f, 0.0008678854792378843f, 0.0008243353804573417f, 0.0007554123876616359f, 0.0004593712219502777f, 0.0009618037147447467f, 0.0010278656845912337f, 0.000851870106998831f, 0.0006118134479038417f, 0.0004343990294728428f, 0.0009113994892686605f, 0.0008861466194503009f, 0.0011858890065923333f, 0.0006051985546946526f, 0.0005727255484089255f, 0.0006634726887568831f, 0.0004779488663189113f, 0.0006805535522289574f, 0.0008474213536828756f, 0.0010377262951806188f, 0.0005522177089005709f, 0.0004149637243244797f, 0.0033703127410262823f, 0.0009696310735307634f, 0.0009040969307534397f, 0.0007381957839243114f, 0.0005664057680405676f, 0.00045652006519958377f, 0.00055601546773687f, 0.0007523783133365214f, 0.0009632548899389803f, 0.00046817498514428735f, 0.0008101424900814891f, 0.0016971816075965762f, 0.0006610549753531814f, 0.0008618405554443598f, 0.0007586307474412024f, 0.0003592479042708874f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #239 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004457448609173298f, 0.0034583613742142916f, 0.013393624685704708f, 0.0027977684512734413f, 0.007046546787023544f, 0.0028279279358685017f, 0.009409754537045956f, 0.0024468237534165382f, 0.013044754043221474f, 0.005533741321414709f, 0.0017637197161093354f, 0.002617469523102045f, 0.0037317327223718166f, 0.003631151746958494f, 0.002837440697476268f, 0.0028971792198717594f, 0.007319533731788397f, 0.0028726716991513968f, 0.0026019751094281673f, 0.0023609690833836794f, 0.004960099700838327f, 0.002916108351200819f, 0.0031531869899481535f, 0.002669340232387185f, 0.0019467076053842902f, 0.003233007388189435f, 0.0022490706760436296f, 0.007119042798876762f, 0.0022457598242908716f, 0.00313057703897357f, 0.030193917453289032f, 0.004795097280293703f, 0.003973300103098154f, 0.0031442332547158003f, 0.006767973769456148f, 0.010932083241641521f, 0.002627915469929576f, 0.002078067511320114f, 0.003382396651431918f, 0.004342897795140743f, 0.002428788226097822f, 0.0017330111004412174f, 0.0024225504603236914f, 0.005965325515717268f, 0.0015795509098097682f, 0.0035754055716097355f, 0.004353991709649563f, 0.0022472324781119823f, 0.004879335407167673f, 0.002789722755551338f, 0.003053778549656272f, 0.004105994012206793f, 0.0023851681035012007f, 0.0026594516821205616f, 0.0031907339580357075f, 0.004870079457759857f, 0.0035030515864491463f, 0.003264090744778514f, 0.005712020210921764f, 0.0019724667072296143f, 0.03759286552667618f, 0.002699738834053278f, 0.002888440852984786f, 0.0034946969244629145f, 0.003658236702904105f, 0.002867181086912751f, 0.005830856040120125f, 0.0031553013250231743f, 0.005796191282570362f, 0.0036193723790347576f, 0.003853552509099245f, 0.002261074958369136f, 0.00507647730410099f, 0.0071741375140845776f, 0.0018461485160514712f, 0.002758779563009739f, 0.001116813044063747f, 0.001182368490844965f, 0.01071800198405981f, 0.005837548058480024f, 0.01723494566977024f, 0.003508421592414379f, 0.005068882834166288f, 0.0028191946912556887f, 0.0043854848481714725f, 0.0042854491621255875f, 0.010955212637782097f, 0.0019293271470814943f, 0.0025739939883351326f, 0.0033534723334014416f, 0.006605291273444891f, 0.0021537442225962877f, 0.004323709290474653f, 0.007399148307740688f, 0.003729296149685979f, 0.002783604199066758f, 0.0025803667958825827f, 0.0008678309386596084f, 0.003569731954485178f, 0.008376076817512512f, 0.005732898600399494f, 0.003309967927634716f, 0.0015735869528725743f, 0.007058090530335903f, 0.0031674865167587996f, 0.0027873890940099955f, 0.00437281746417284f, 0.0025530452840030193f, 0.001239324570633471f, 0.003294199239462614f, 0.004412056412547827f, 0.005781406536698341f, 0.002505284734070301f, 0.009550672955811024f, 0.0012807430466637015f, 0.0014608076307922602f, 0.006175728049129248f, 0.004837777465581894f, 0.0027883443981409073f, 0.003219378413632512f, 0.002119959332048893f, 0.0018263714155182242f, 0.0014291810803115368f, 0.003182537155225873f, 0.007843290455639362f, 0.0034558360930532217f, 0.0042551131919026375f, 0.0032240774016827345f, 0.0009127852972596884f, 0.002234290586784482f, 0.0014501222176477313f, 0.006567289121448994f, 0.0036318544298410416f, 0.004648203961551189f, 0.007636561989784241f, 0.0036986125633120537f, 0.007075467612594366f, 0.0020514896605163813f, 0.006333301309496164f, 0.00204466306604445f, 0.004022005945444107f, 0.0039010311011224985f, 0.004405367653816938f, 0.00304990541189909f, 0.0014800782082602382f, 0.001447344315238297f, 0.0021858015097677708f, 0.003697893349453807f, 0.017199452966451645f, 0.0031154765747487545f, 0.004927732516080141f, 0.002328969072550535f, 0.005363777279853821f, 0.004538599401712418f, 0.00503059895709157f, 0.0013934809248894453f, 0.0022946251556277275f, 0.0038079041987657547f, 0.0063060978427529335f, 0.004688064102083445f, 0.002137725707143545f, 0.004215886816382408f, 0.004536115564405918f, 0.007760711945593357f, 0.003359520575031638f, 0.0028698823880404234f, 0.004210988990962505f, 0.0051086884923279285f, 0.0036333848256617785f, 0.0032090824097394943f, 0.006229884922504425f, 0.0023920871317386627f, 0.004289898090064526f, 0.0025619815569370985f, 0.0038120548706501722f, 0.008541170507669449f, 0.0014858071226626635f, 0.0016613838961347938f, 0.002474298467859626f, 0.0022542274091392756f, 0.0033597927540540695f, 0.018300559371709824f, 0.0021855465602129698f, 0.0012998620513826609f, 0.002377671655267477f, 0.009562377817928791f, 0.001697983592748642f, 0.003021508688107133f, 0.001958163222298026f, 0.003758748760446906f, 0.002545428927987814f, 0.013462454080581665f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #240 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004474937915802002f, 0.003261718899011612f, 0.004796752706170082f, 0.005163725931197405f, 0.006332542281597853f, 0.006886565592139959f, 0.004609338473528624f, 0.0070139020681381226f, 0.006235875189304352f, 0.005056249443441629f, 0.009972822852432728f, 0.009647204540669918f, 0.005573128815740347f, 0.005382801406085491f, 0.0035348553210496902f, 0.005124365910887718f, 0.005289820022881031f, 0.005562663543969393f, 0.009851720184087753f, 0.007654108572751284f, 0.005392844323068857f, 0.006254604086279869f, 0.006260417401790619f, 0.005453970283269882f, 0.005184129346162081f, 0.005665120203047991f, 0.010830726474523544f, 0.009144354611635208f, 0.0032397012691944838f, 0.006497370079159737f, 0.0061522601172327995f, 0.005315536633133888f, 0.006437503267079592f, 0.005197908263653517f, 0.006895529571920633f, 0.007159452885389328f, 0.006004498340189457f, 0.005212809424847364f, 0.00563696539029479f, 0.005502828396856785f, 0.004000856075435877f, 0.007205660454928875f, 0.005327892489731312f, 0.004098101519048214f, 0.0044046868570148945f, 0.00645119184628129f, 0.00906760711222887f, 0.005375351291149855f, 0.004498879890888929f, 0.006110338028520346f, 0.004795389715582132f, 0.006523482501506805f, 0.006175357848405838f, 0.007790072355419397f, 0.007088442798703909f, 0.005724701099097729f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #241 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004223091236781329f, 0.0005900216056033969f, 0.0004101495142094791f, 0.0003876005357597023f, 0.0005956936511211097f, 0.0005990356439724565f, 0.0004914346500299871f, 0.0010717491386458278f, 0.000549100455828011f, 0.0007588592125102878f, 0.000631765287835151f, 0.0005289207911118865f, 0.0013885371154174209f, 0.0004664425796363503f, 0.0005957511602900922f, 0.0005475986399687827f, 0.00038887359551154077f, 0.0006502770120278001f, 0.0003141513152513653f, 0.0003889728104695678f, 0.0004049609415233135f, 0.000749541271943599f, 0.0006795914960093796f, 0.00035331686376594007f, 0.0003008214116562158f, 0.0006112416740506887f, 0.0003988809767179191f, 0.0006349353934638202f, 0.00033592438558116555f, 0.00042103781015612185f, 0.0006469179061241448f, 0.0007740973378531635f, 0.0006793559878133237f, 0.00032074551563709974f, 0.0006814377848058939f, 0.00044138432713225484f, 0.000829528144095093f, 0.00044534108019433916f, 0.0003699388762470335f, 0.0006591484998352826f, 0.0007930187857709825f, 0.0004445234371814877f, 0.0007272554212249815f, 0.00045374728506430984f, 0.0005735513987019658f, 0.0005686809890903533f, 0.0007926320540718734f, 0.0003558734606485814f, 0.0007599904201924801f, 0.0006355052464641631f, 0.0005915833171457052f, 0.00019108627748209983f, 0.00043992046266794205f, 0.0006054567638784647f, 0.0007424080395139754f, 0.0003773053176701069f, 0.0003051878302358091f, 0.0008344338275492191f, 0.0002862900437321514f, 0.000901033403351903f, 0.0003473373071756214f, 0.000609815411735326f, 0.0004043766821268946f, 0.0004855034640058875f, 0.0004809738020412624f, 0.0002299399784533307f, 0.0003417283296585083f, 0.0004203639691695571f, 0.00062896020244807f, 0.0005176495178602636f, 0.0003835431416518986f, 0.0004605289432220161f, 0.0006154743023216724f, 0.0004058247141074389f, 0.0012788099702447653f, 0.0002169785730075091f, 0.0006053350516594946f, 0.0006031038938090205f, 0.0004323254688642919f, 0.0005789590068161488f, 0.0003311624168418348f, 0.0002682169433683157f, 0.0005250839167274535f, 0.0007910118438303471f, 0.0004923889064230025f, 0.0006999769248068333f, 0.0004662092251237482f, 0.0005964405718259513f, 0.0004008689720649272f, 0.000805104908067733f, 0.000477972294902429f, 0.0017873600590974092f, 0.000235940475249663f, 0.00026467363932169974f, 0.0002472558990120888f, 0.0007391955587081611f, 0.0009710842277854681f, 0.0004692410002462566f, 0.00035064623807556927f, 0.0002766582474578172f, 0.00045109554775990546f, 0.0010313394013792276f, 0.0009798140963539481f, 0.0004977135104127228f, 0.00047634809743613005f, 0.0004262262664269656f, 0.000531835830770433f, 0.00019874096324201673f, 0.0008591245277784765f, 0.0008692176779732108f, 0.0003859667631331831f, 0.0005220743478275836f, 0.00033681237255223095f, 0.0003828246262855828f, 0.00036565036862157285f, 0.00034391414374113083f, 0.0006653919699601829f, 0.0005528543260879815f, 0.00042587623465806246f, 0.0007854269351810217f, 0.0004049657145515084f, 0.0004415546718519181f, 0.0001787347428034991f, 0.0005678706802427769f, 0.0004035871534142643f, 0.00030558209982700646f, 0.00038958110962994397f, 0.0008890504250302911f, 0.0007469217525795102f, 0.000603495049290359f, 0.0009025695035234094f, 0.0003168441471643746f, 0.0003819251724053174f, 0.0010881151538342237f, 0.0003987272211816162f, 0.0006269954610615969f, 0.0009014984243549407f, 0.0004119947843719274f, 0.0005325591191649437f, 0.0004613576165866107f, 0.00047277347766794264f, 0.00042233095155097544f, 0.0004101933736819774f, 0.0004609724273905158f, 0.00040592506411485374f, 0.0008384075481444597f, 0.0005542994476854801f, 0.0006656842306256294f, 0.0005751936114393175f, 0.0005564925377257168f, 0.0005033358465880156f, 0.0005173923564143479f, 0.0005142043228261173f, 0.0004108395951334387f, 0.00045686113298870623f, 0.0003669818106573075f, 0.0007160087116062641f, 0.0004042972286697477f, 0.0007683085277676582f, 0.00039316597394645214f, 0.00021781963005196303f, 0.0003080209135077894f, 0.000336248631356284f, 0.0005464702844619751f, 0.0014074958162382245f, 0.00044048091513104737f, 0.0003689940203912556f, 0.0006166406092233956f, 0.0004452778957784176f, 0.0004894945304840803f, 0.0004854717117268592f, 0.0003226933185942471f, 0.0005324305384419858f, 0.0008884367416612804f, 0.0005150000215508044f, 0.00035382676287554204f, 0.000358356541255489f, 0.0007840325706638396f, 0.0006244874093681574f, 0.0009453987586311996f, 0.0004509034042712301f, 0.0009147227392531931f, 0.0004791088867932558f, 0.00015390390763059258f, 0.0005703330971300602f, 0.00043308004387654364f, 0.0006631682044826448f, 0.0005856986390426755f, 0.0003698089858517051f, 0.0006186083192005754f, 0.0005732343997806311f, 0.0008845445117913187f, 0.0003581526398193091f, 0.0004018940089736134f, 0.0012193439761176705f, 0.0005155744147486985f, 0.0008419214864261448f, 0.0014660977758467197f, 0.0006994482246227562f, 0.0005123600130900741f, 0.0005816653138026595f, 0.0008651069365441799f, 0.0004506419354584068f, 0.0006421712459996343f, 0.0004816056462004781f, 0.0005037810769863427f, 0.0005392231396399438f, 0.0003741010732483119f, 0.00033568523940630257f, 0.0007635397487320006f, 0.0007288532797247171f, 0.0008041964611038566f, 0.00036426648148335516f, 0.00035938798100687563f, 0.0008660738822072744f, 0.0003495626733638346f, 0.0006302153342403471f, 0.0004530368896666914f, 0.00042255024891346693f, 0.00032201161957345903f, 0.000452930893516168f, 0.0007843414205126464f, 0.00039217006997205317f, 0.0005655796267092228f, 0.00022541737416759133f, 0.0009613410220481455f, 0.000719312927685678f, 0.00019395673007238656f, 0.0004769938241224736f, 0.0004255831881891936f, 0.0009828486945480108f, 0.0003989508841186762f, 0.0005136766703799367f, 0.00025425106287002563f, 0.0004369738744571805f, 0.0004987390129826963f, 0.0010866723023355007f, 0.0006122830673120916f, 0.0006963065243326128f, 0.0008768087136559188f, 0.0003863385645672679f, 0.0005013828631490469f, 0.0004740224394481629f, 0.0004983110120519996f, 0.0007602592813782394f, 0.000723734381608665f, 0.0006703264079988003f, 0.0007811975083313882f, 0.0004916012985631824f, 0.0008237083675339818f, 0.0007996803033165634f, 0.00041526262066327035f, 0.0002370285801589489f, 0.0008325486560352147f, 0.00039754348108544946f, 0.0004206370504107326f, 0.00039196779835037887f, 0.0003333266358822584f, 0.0007845936925150454f, 0.0004934860044158995f, 0.0004076774639543146f, 0.0008515531662851572f, 0.00046289523015730083f, 0.0008908820454962552f, 0.0008385094115510583f, 0.0007849162211641669f, 0.0010656120721250772f, 0.00045683843200095f, 0.0006890407530590892f, 0.0004316301201470196f, 0.0006481013260781765f, 0.0008889851160347462f, 0.00039750596624799073f, 0.0005682944902218878f, 0.0004924893146380782f, 0.0004847846576012671f, 0.00027123145991936326f, 0.0003954253043048084f, 0.00028795309481211007f, 0.0005955849192105234f, 0.0005647982470691204f, 0.0005121204885654151f, 0.0006367728929035366f, 0.0010951606091111898f, 0.0005082602729089558f, 0.00025683254352770746f, 0.0007486038957722485f, 0.0007813399424776435f, 0.0007437442545779049f, 0.0006238786154426634f, 0.0005188400391489267f, 0.0004634637734852731f, 0.0008508840692229569f, 0.0005602646851912141f, 0.0008826175471767783f, 0.0009252707823179662f, 0.0004495903558563441f, 0.0009968684753403068f, 0.00036075004027225077f, 0.0003586077655199915f, 0.0004129180160816759f, 0.0004085997643414885f, 0.0004824276838917285f, 0.00045148792560212314f, 0.0008184321341104805f, 0.0005543981678783894f, 0.0002515540982130915f, 0.0006395627278834581f, 0.0008683165651746094f, 0.0008671818068251014f, 0.0006958272424526513f, 0.0005762057844549417f, 0.00041589143802411854f, 0.00016584826516918838f, 0.0005784856039099395f, 0.0005908898310735822f, 0.0005799295613542199f, 0.001000561867840588f, 0.0006893271929584444f, 0.0008528516045771539f, 0.00055405602324754f, 0.0005594517569988966f, 0.0004276935360394418f, 0.0002624116896186024f, 0.0008102861465886235f, 0.0002578598796389997f, 0.000169389444636181f, 0.0008020143723115325f, 0.0006811320781707764f, 0.0005702342605218291f, 0.0003478385042399168f, 0.00027466018218547106f, 0.000516774074640125f, 0.000531066907569766f, 0.0006668596179224551f, 0.0005612264503724873f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #242 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012292453087866306f, 0.0033699616324156523f, 0.006294779479503632f, 0.006093403324484825f, 0.004203976597636938f, 0.006876125931739807f, 0.006749745924025774f, 0.007480014581233263f, 0.008242440409958363f, 0.0022492960561066866f, 0.0075118644163012505f, 0.005143212154507637f, 0.004850959405303001f, 0.004102315753698349f, 0.004792048595845699f, 0.012874677777290344f, 0.007090373896062374f, 0.004525880794972181f, 0.00614802585914731f, 0.00697116507217288f, 0.016496004536747932f, 0.01332260575145483f, 0.0076758540235459805f, 0.015654196962714195f, 0.006815979722887278f, 0.0038554868660867214f, 0.006297013722360134f, 0.01136835291981697f, 0.012688705697655678f, 0.01546604186296463f, 0.005023780278861523f, 0.012021904811263084f, 0.00651882030069828f, 0.012290971353650093f, 0.014509722590446472f, 0.008956179954111576f, 0.002646083477884531f, 0.009149407036602497f, 0.006562412716448307f, 0.0026315185241401196f, 0.009316615760326385f, 0.007806829176843166f, 0.005530074704438448f, 0.0038310650270432234f, 0.005437397863715887f, 0.006513000465929508f, 0.004118691198527813f, 0.009144005365669727f, 0.006043745204806328f, 0.0042815618216991425f, 0.007025625556707382f, 0.0164659284055233f, 0.0032934239134192467f, 0.01154256146401167f, 0.003521097358316183f, 0.008315344341099262f, 0.01278646569699049f, 0.0027932492084801197f, 0.0074075330048799515f, 0.020988604053854942f, 0.00828475970774889f, 0.004668314475566149f, 0.01756991818547249f, 0.0039838324300944805f, 0.003845635801553726f, 0.006653631571680307f, 0.004838102962821722f, 0.005113343708217144f, 0.006796776782721281f, 0.006525981705635786f, 0.010474877431988716f, 0.0077026947401463985f, 0.009081874042749405f, 0.006619799416512251f, 0.004677582066506147f, 0.003847491927444935f, 0.009879990480840206f, 0.010847172699868679f, 0.010660790838301182f, 0.0029652223456650972f, 0.004735349211841822f, 0.011247093789279461f, 0.011406724341213703f, 0.007499487604945898f, 0.003475532168522477f, 0.009458186104893684f, 0.0063131945207715034f, 0.004251136910170317f, 0.007818668149411678f, 0.010754529386758804f, 0.003789589274674654f, 0.004216548055410385f, 0.017183467745780945f, 0.019374540075659752f, 0.00917624682188034f, 0.006675002630800009f, 0.00781095027923584f, 0.011762420646846294f, 0.0046329074539244175f, 0.009746924042701721f, 0.012310808524489403f, 0.0018324978882446885f, 0.007458151318132877f, 0.005516614764928818f, 0.01687520369887352f, 0.007476637605577707f, 0.008853313513100147f, 0.01935841143131256f, 0.011263174936175346f, 0.0024781811516731977f, 0.006128877867013216f, 0.005742236040532589f, 0.011569837108254433f, 0.0064516509883105755f, 0.009576153010129929f, 0.0140584297478199f, 0.004330235533416271f, 0.009832806885242462f, 0.00528031075373292f, 0.007138513959944248f, 0.005627341568470001f, 0.00564065296202898f, 0.009362914599478245f, 0.005775046534836292f, 0.0065040551126003265f, 0.008613808080554008f, 0.007492258213460445f, 0.0070174639113247395f, 0.005671287886798382f, 0.007355220150202513f, 0.005723242647945881f, 0.010330730117857456f, 0.006985071115195751f, 0.005251023452728987f, 0.00538003072142601f, 0.008706212043762207f, 0.005529158283025026f, 0.011655217036604881f, 0.00591011717915535f, 0.0021412745118141174f, 0.007212149910628796f, 0.0038784071803092957f, 0.01267847791314125f, 0.009742951951920986f, 0.007801086641848087f, 0.004296071361750364f, 0.003215308301150799f, 0.0028581423684954643f, 0.003204771550372243f, 0.0046247802674770355f, 0.006771782413125038f, 0.017080867663025856f, 0.0035100742243230343f, 0.003911374602466822f, 0.011999480426311493f, 0.004739678464829922f, 0.0034156388137489557f, 0.005175554193556309f, 0.01712309569120407f, 0.0059129102155566216f, 0.004712832160294056f, 0.010056620463728905f, 0.010415792465209961f, 0.005848431494086981f, 0.00331685459241271f, 0.009032663889229298f, 0.005103380884975195f, 0.0017678868025541306f, 0.006826259661465883f, 0.0030388429295271635f, 0.004388357512652874f, 0.014395277015864849f, 0.009784499183297157f, 0.010942463763058186f, 0.005342574790120125f, 0.006580626126378775f, 0.005175268277525902f, 0.0023320363834500313f, 0.013413562439382076f, 0.002107959007844329f, 0.00661894865334034f, 0.015238373540341854f, 0.007200817111879587f, 0.02112111635506153f, 0.0013323985040187836f, 0.005758420564234257f, 0.007375276181846857f, 0.003967010881751776f, 0.010156645439565182f, 0.009341082535684109f, 0.004195708315819502f, 0.0037612265441566706f, 0.0070818145759403706f, 0.0016742044826969504f, 0.007029315456748009f, 0.007941448129713535f, 0.005442171357572079f, 0.0044700028374791145f, 0.0016266816528514028f, 0.003983940463513136f, 0.007874424569308758f, 0.008660799823701382f, 0.010096295736730099f, 0.0034380594734102488f, 0.008418317884206772f, 0.005220938939601183f, 0.00441447040066123f, 0.008627334609627724f, 0.00920885056257248f, 0.007713118102401495f, 0.002800259506329894f, 0.007665527518838644f, 0.006893028970807791f, 0.010926366783678532f, 0.008090914227068424f, 0.012327345088124275f, 0.0011994736269116402f, 0.00916224904358387f, 0.009249402210116386f, 0.006870632991194725f, 0.010466723702847958f, 0.005099664907902479f, 0.0015807447489351034f, 0.002679510274901986f, 0.01785924844443798f, 0.006554082036018372f, 0.012675607576966286f, 0.014060537330806255f, 0.004897973500192165f, 0.006934871431440115f, 0.003938149660825729f, 0.006036573555320501f, 0.01017800159752369f, 0.008065765723586082f, 0.00629901560023427f, 0.005507681518793106f, 0.01227565947920084f, 0.0064855352975428104f, 0.0019447203958407044f, 0.004605262540280819f, 0.005083227995783091f, 0.006143784616142511f, 0.006369447335600853f, 0.006914528552442789f, 0.003734684083610773f, 0.009436097927391529f, 0.0054038031958043575f, 0.007643324322998524f, 0.008051177486777306f, 0.0036864380817860365f, 0.0019364469917491078f, 0.006349644623696804f, 0.016613807529211044f, 0.0027837518136948347f, 0.005128619726747274f, 0.008803920820355415f, 0.009724663570523262f, 0.007957839407026768f, 0.010306451469659805f, 0.0058820173144340515f, 0.006985797546803951f, 0.004361748229712248f, 0.004891814664006233f, 0.006247316021472216f, 0.005767025984823704f, 0.010584112256765366f, 0.007714036386460066f, 0.005686972755938768f, 0.008054276928305626f, 0.01336560770869255f, 0.008627094328403473f, 0.008542892523109913f, 0.007559100165963173f, 0.005117147695273161f, 0.008260627277195454f, 0.011932864785194397f, 0.01168048195540905f, 0.006708007771521807f, 0.01712341606616974f, 0.0051530455239117146f, 0.007198475766927004f, 0.012943357229232788f, 0.0056828586384654045f, 0.0056541902013123035f, 0.008971069008111954f, 0.013982805423438549f, 0.005407229065895081f, 0.014077884145081043f, 0.007671778090298176f, 0.009104111231863499f, 0.00797006394714117f, 0.003871672786772251f, 0.011894481256604195f, 0.006632223725318909f, 0.010471823625266552f, 0.0063257478177547455f, 0.0122187165543437f, 0.00866091437637806f, 0.016129078343510628f, 0.006868445780128241f, 0.008325571194291115f, 0.0063961343839764595f, 0.004433471243828535f, 0.007980880327522755f, 0.005517544690519571f, 0.006324156653136015f, 0.005486853886395693f, 0.008603702299296856f, 0.006145698484033346f, 0.008758289739489555f, 0.0042507098987698555f, 0.00407054228708148f, 0.011499544605612755f, 0.018378829583525658f, 0.006190343294292688f, 0.006294164806604385f, 0.008998001925647259f, 0.0011405382538214326f, 0.005015158094465733f, 0.0054489667527377605f, 0.004956620279699564f, 0.005834463983774185f, 0.005328059196472168f, 0.035272032022476196f, 0.004540243186056614f, 0.010514878667891026f, 0.014287182129919529f, 0.005494056269526482f, 0.004523226525634527f, 0.0019326622132211924f, 0.005118183325976133f, 0.010118582285940647f, 0.010135916993021965f, 0.006022598594427109f, 0.005390916019678116f, 0.005334974266588688f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #243 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007455053273588419f, 0.00771100539714098f, 0.0026690622325986624f, 0.01164006907492876f, 0.002456491347402334f, 0.0022516059689223766f, 0.002889406168833375f, 0.003578778589144349f, 0.0014330428093671799f, 0.0050752791576087475f, 0.0023979630786925554f, 0.002774776890873909f, 0.004474860616028309f, 0.0027356897480785847f, 0.005653150379657745f, 0.004185664467513561f, 0.006886835675686598f, 0.0024366348516196012f, 0.002241892507299781f, 0.006820554379373789f, 0.0035683035384863615f, 0.0022435744758695364f, 0.006123882718384266f, 0.0050395168364048f, 0.0034363032318651676f, 0.0012848315527662635f, 0.004241217393428087f, 0.0010016777087002993f, 0.005040897522121668f, 0.001641377224586904f, 0.00380651350133121f, 0.0027771717868745327f, 0.0021202960051596165f, 0.003948588855564594f, 0.0022353660315275192f, 0.0036823791451752186f, 0.0032317573204636574f, 0.00680637639015913f, 0.004210410173982382f, 0.006990036461502314f, 0.006723667960613966f, 0.0021231891587376595f, 0.0024375286884605885f, 0.006967061199247837f, 0.005451880395412445f, 0.0035149131435900927f, 0.0025658614467829466f, 0.0064064194448292255f, 0.006627017166465521f, 0.0018746356945484877f, 0.005555730313062668f, 0.00757219921797514f, 0.004090288653969765f, 0.0020111005287617445f, 0.0027364534325897694f, 0.0057200281880795956f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #244 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_59_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006612933939322829f, 0.000604095112066716f, 0.00026092896587215364f, 0.00030669072293676436f, 0.000873398850671947f, 0.0013449008110910654f, 0.0005223197513259947f, 0.00034080646582879126f, 0.00038544711424037814f, 0.0006891238735988736f, 0.0005378663772717118f, 0.00036463834112510085f, 0.0005725450464524329f, 0.0007227303576655686f, 0.0003933468833565712f, 0.0003664602409116924f, 0.000242391528445296f, 0.000607031281106174f, 0.0003265615087002516f, 0.00034454427077434957f, 0.0005061935517005622f, 0.0004350613453425467f, 0.0007770186639390886f, 0.0003558232565410435f, 0.0005442983820103109f, 0.0007133567705750465f, 0.0006333390483632684f, 0.0007752247620373964f, 0.0003513356205075979f, 0.0007852605194784701f, 0.0003230513830203563f, 0.0004331270174589008f, 0.0008615784463472664f, 0.0004163840494584292f, 0.00031849369406700134f, 0.0005378424539230764f, 0.00046192255103960633f, 0.0003590624255593866f, 0.00042895518708974123f, 0.0005008698790334165f, 0.00031176675111055374f, 0.0003452274249866605f, 0.0006627318216487765f, 0.0005510922055691481f, 0.000532737176399678f, 0.000524748582392931f, 0.0005038034287281334f, 0.0005966187454760075f, 0.000381962105166167f, 0.00041036566835828125f, 0.00045084330486133695f, 0.000804892391897738f, 0.0005812410963699222f, 0.000656497257295996f, 0.0005271087866276503f, 0.0002643750631250441f, 0.0005317137693054974f, 0.0001261154393432662f, 0.0002929174806922674f, 0.0003962595365010202f, 0.000649927300401032f, 0.00036668256507255137f, 0.00041200313717126846f, 0.00036708175321109593f, 0.00034441504976712167f, 0.00031891706748865545f, 0.0006686820997856557f, 0.0003218304773326963f, 0.00037508667446672916f, 0.0005597488489001989f, 0.00035655792453326285f, 0.0008150580106303096f, 0.0002967861946672201f, 0.0006053319084458053f, 0.0005239208694547415f, 0.000536618463229388f, 0.0006873617530800402f, 0.0004914134624414146f, 0.00031095289159566164f, 0.00024837302044034004f, 0.00033487865584902465f, 0.0006430596695281565f, 0.00046576178283430636f, 0.0004741240118164569f, 0.0005391336744651198f, 0.0003472246171440929f, 0.0003323316341266036f, 0.0005364046082831919f, 0.000747156620491296f, 0.0006421714788302779f, 0.000342048384482041f, 0.0006779227405786514f, 0.0005331741413101554f, 0.0005285539664328098f, 0.0005901792901568115f, 0.0002836189523804933f, 0.0009053978137671947f, 0.0007029488333500922f, 0.0002681068144738674f, 0.0005392347229644656f, 0.0006005815230309963f, 0.00031633873004466295f, 0.0005845552077516913f, 0.0004235733940731734f, 0.00028333227965049446f, 0.00034283811692148447f, 0.0005877695512026548f, 0.0008179825381375849f, 0.0004321950254961848f, 0.0005494416691362858f, 0.00038339171442203224f, 0.0003854059905279428f, 0.0003694579645525664f, 0.0006418194971047342f, 0.0004636679368559271f, 0.0003521943581290543f, 0.0002955904055852443f, 0.0004984069964848459f, 0.00024674239102751017f, 0.00027084333123639226f, 0.00036404389538802207f, 0.0005665273638442159f, 0.000970230030361563f, 0.00029545510187745094f, 0.0009436518303118646f, 0.0006912820390425622f, 0.0006909472867846489f, 0.0003859371936414391f, 0.00021900763385929167f, 0.0007622939301654696f, 0.00035426171962171793f, 0.0006607784889638424f, 0.0005028197192586958f, 0.0006393378716893494f, 0.0004056014004163444f, 0.0002986515173688531f, 0.0002738791226875037f, 0.0006578908069059253f, 0.00034197838976979256f, 0.0007897901232354343f, 0.0004857939202338457f, 0.0003212692681699991f, 0.00022983817325439304f, 0.00028098380425944924f, 0.0002939486876130104f, 0.00030118515132926404f, 0.0007617850787937641f, 0.0006030754884704947f, 0.0007355757406912744f, 0.0006126959924586117f, 0.0006632681470364332f, 0.00025843342882581055f, 0.0007269038469530642f, 0.0005691691185347736f, 0.0006616598111577332f, 0.00039655290311202407f, 0.0005595122929662466f, 0.0003370070771779865f, 0.0006664135144092143f, 0.0003853866655845195f, 0.0006704123225063086f, 0.0005693117855116725f, 0.0011989427730441093f, 0.00028440638561733067f, 0.0008464279235340655f, 0.000562168366741389f, 0.0005450226599350572f, 0.0004159912932664156f, 0.000770042126532644f, 0.0006073216209188104f, 0.0005717261810787022f, 0.0007193913916125894f, 0.0006265657139010727f, 0.0004921025247313082f, 0.00028031779220327735f, 0.0004347708309069276f, 0.0007012169226072729f, 0.0002703703357838094f, 0.00032222847221419215f, 0.0004935784381814301f, 0.00046712992480024695f, 0.00038475202745757997f, 0.0005496358498930931f, 0.0008280780166387558f, 0.0003290153690613806f, 0.00045254043652676046f, 0.0006561615155078471f, 0.0007276413962244987f, 0.00043991420534439385f, 0.0004344821791164577f, 0.0005130324861966074f, 0.00033313233871012926f, 0.0006570100667886436f, 0.00036091578658670187f, 0.0004989043809473515f, 0.0005244269850663841f, 0.0006727261352352798f, 0.0002301904751220718f, 0.0006990173133090138f, 0.0003874693647958338f, 0.0003809404151979834f, 0.0006229443242773414f, 0.0005297907628118992f, 0.000590870447922498f, 0.0008062887354753911f, 0.00038543189293704927f, 0.00026795308804139495f, 0.00012855403474532068f, 0.0004157594230491668f, 0.00030508439522236586f, 7.071973959682509e-05f, 0.00037363660521805286f, 0.00023728511587250978f, 0.00039995796396397054f, 0.0002605936606414616f, 0.0005387073033489287f, 0.0005500066909007728f, 0.0003312822082079947f, 0.0005066070589236915f, 0.000535240164026618f, 0.0008175612892955542f, 0.0007216257508844137f, 0.0007469977717846632f, 0.0005343997036106884f, 0.0004920856445096433f, 0.0002858984225895256f, 0.0005292186979204416f, 0.0005167314666323364f, 0.0004982968093827367f, 0.0005493756616488099f, 0.00021737345377914608f, 0.0005250889807939529f, 0.0005275807343423367f, 0.0006133423303253949f, 0.00039968854980543256f, 0.0006058650324121118f, 0.00046686394489370286f, 0.0007931332220323384f, 0.00043319049291312695f, 0.0008835976477712393f, 0.0003882861346937716f, 0.0004284652241040021f, 0.0005822596722282469f, 0.0004305104957893491f, 0.0005239120800979435f, 0.0008109420305117965f, 0.0008136979886330664f, 0.0005535041564144194f, 0.00042177431168965995f, 0.0003927792713511735f, 0.00034236841020174325f, 0.0008261153707280755f, 0.0006582039059139788f, 0.00055514374980703f, 0.0004811786056961864f, 0.00024147807562258095f, 0.0004821827169507742f, 0.0006084703491069376f, 0.0006987191154621542f, 0.00032176467357203364f, 0.00016085297102108598f, 0.00043526067747734487f, 0.0003059910668525845f, 0.0003854129754472524f, 0.0004679935809690505f, 0.00048502019490115345f, 0.0004445247759576887f, 0.00033675931626930833f, 0.0005108262412250042f, 0.000740137358661741f, 0.0005162237212061882f, 0.00022389284276869148f, 0.000710207736119628f, 0.0006948747322894633f, 0.0004822516057174653f, 0.0004771089879795909f, 0.00022589076252188534f, 0.0005295434384606779f, 0.0004184990539215505f, 0.0006084495107643306f, 0.00026853973395191133f, 0.00026165758026763797f, 0.00032327338703908026f, 0.0003434083773754537f, 0.0007326226332224905f, 0.0006264253170229495f, 0.00024680516798980534f, 0.00041061147931031883f, 0.0005080037517473102f, 0.00035066407872363925f, 0.00047363442718051374f, 0.0004332231474108994f, 0.0003767725720535964f, 0.0005860237288288772f, 0.000685100385453552f, 0.0005352575681172311f, 0.0005522918654605746f, 0.00035855386522598565f, 0.00028929064865224063f, 0.0005721208872273564f, 0.0003385648597031832f, 0.0006190630956552923f, 0.0006053975084796548f, 0.00023312208941206336f, 0.00045856478391215205f, 0.00040343208820559084f, 0.0005138941342011094f, 0.0013317209668457508f, 0.0006535100983455777f, 0.00019586125563364476f, 0.000381169724278152f, 0.000416703027440235f, 0.00025262305280193686f, 0.0003278775548096746f, 0.0004191307816654444f, 0.0005070844781585038f, 0.00043377612018957734f, 0.0005235166754573584f, 0.0005983198643662035f, 0.0005478680832311511f, 0.0003468056092970073f, 0.0004886147216893733f, 0.0007331356755457819f, 0.0004035432357341051f, 0.00026571439229883254f, 0.0004112090973649174f, 0.0006263747345656157f, 0.00022819527657702565f, 0.0004451496643014252f, 0.0005350559949874878f, 0.00022792014351580292f, 0.0003498443402349949f, 0.000713303335942328f, 0.0004050375719089061f, 0.00036580642336048186f, 0.000309489609207958f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #245 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009314318187534809f, 0.006095027085393667f, 0.002861844375729561f, 0.0023771042469888926f, 0.002507317578420043f, 0.003120667301118374f, 0.006986356806010008f, 0.004999131429940462f, 0.003912852145731449f, 0.010236198082566261f, 0.01224676426500082f, 0.0017997385002672672f, 0.00971536710858345f, 0.003143720794469118f, 0.008688013069331646f, 0.008619886822998524f, 0.007401645183563232f, 0.016908342018723488f, 0.01153541263192892f, 0.004897020291537046f, 0.0036778217181563377f, 0.0040439702570438385f, 0.006744796875864267f, 0.014939814805984497f, 0.0018510200316086411f, 0.004849507473409176f, 0.01027127169072628f, 0.006288355216383934f, 0.008039824664592743f, 0.006382402498275042f, 0.007011209614574909f, 0.008267512544989586f, 0.005501501262187958f, 0.00631857942789793f, 0.007771196309477091f, 0.004987571854144335f, 0.003759689861908555f, 0.008741340599954128f, 0.012445637956261635f, 0.002424887614324689f, 0.005583517253398895f, 0.0031191129237413406f, 0.005766354501247406f, 0.005691337864845991f, 0.004047088790684938f, 0.0019491382408887148f, 0.0076590608805418015f, 0.0054884715937078f, 0.004852041602134705f, 0.005274290218949318f, 0.011009967885911465f, 0.0039075021632015705f, 0.0016783458413556218f, 0.0013665328733623028f, 0.005960133858025074f, 0.0035765927750617266f, 0.0023816542234271765f, 0.03591389209032059f, 0.0026283334009349346f, 0.004927049856632948f, 0.00814039446413517f, 0.002877513412386179f, 0.008200888521969318f, 0.08479464799165726f, 0.003702938323840499f, 0.00695251626893878f, 0.0023481701500713825f, 0.009090764448046684f, 0.01599767990410328f, 0.0027318710926920176f, 0.016735151410102844f, 0.0027011209167540073f, 0.006003309041261673f, 0.0037882947362959385f, 0.00545013602823019f, 0.009465998969972134f, 0.005639601964503527f, 0.005832770373672247f, 0.008518664166331291f, 0.01382181141525507f, 0.006097196135669947f, 0.009221733547747135f, 0.010654456913471222f, 0.0020296741276979446f, 0.011940086260437965f, 0.004353808704763651f, 0.009404182434082031f, 0.011829346418380737f, 0.0017111527267843485f, 0.0029473896138370037f, 0.011024138890206814f, 0.017278220504522324f, 0.004409690387547016f, 0.004968843422830105f, 0.009344878606498241f, 0.0026985923759639263f, 0.0019065147498622537f, 0.003605166682973504f, 0.028562508523464203f, 0.011397094465792179f, 0.010285935364663601f, 0.012872915714979172f, 0.008422920480370522f, 0.0057654716074466705f, 0.006965307518839836f, 0.0038233462255448103f, 0.005439669359475374f, 0.005892599932849407f, 0.0074332840740680695f, 0.008196751587092876f, 0.006337753031402826f, 0.007951180450618267f, 0.004967152141034603f, 0.007288935128599405f, 0.0033260416239500046f, 0.006783831864595413f, 0.006185594480484724f, 0.00814293883740902f, 0.0063880025409162045f, 0.0024332127068191767f, 0.003939089365303516f, 0.0052266474813222885f, 0.0021916250698268414f, 0.005604221951216459f, 0.004398411605507135f, 0.010000549256801605f, 0.006576072424650192f, 0.01451464369893074f, 0.009102771058678627f, 0.005020639859139919f, 0.0035582217387855053f, 0.009934366680681705f, 0.011839890852570534f, 0.0014985756715759635f, 0.010858772322535515f, 0.0023398124612867832f, 0.007357397116720676f, 0.005736452527344227f, 0.01450673770159483f, 0.0030644903890788555f, 0.00851535890251398f, 0.004599252715706825f, 0.01481091883033514f, 0.010039927437901497f, 0.003673969302326441f, 0.005702644120901823f, 0.005495269317179918f, 0.00615767203271389f, 0.0038534183986485004f, 0.004719054792076349f, 0.0025443146005272865f, 0.004730624612420797f, 0.003746070433408022f, 0.00678574712947011f, 0.0022483421489596367f, 0.00882192887365818f, 0.004427420441061258f, 0.002502515446394682f, 0.005036845337599516f, 0.0034184667747467756f, 0.009819168597459793f, 0.0037449239753186703f, 0.00220945430919528f, 0.003826515283435583f, 0.01278829574584961f, 0.0033233570866286755f, 0.00527632562443614f, 0.006502864416688681f, 0.010243060067296028f, 0.013345411978662014f, 0.0038215795066207647f, 0.005444961600005627f, 0.008568317629396915f, 0.017943713814020157f, 0.00833369605243206f, 0.007204600144177675f, 0.0034593159798532724f, 0.0063902754336595535f, 0.0027520894072949886f, 0.008936947211623192f, 0.005411489401012659f, 0.009596562013030052f, 0.004810191225260496f, 0.008077980019152164f, 0.008347241207957268f, 0.011322660371661186f, 0.008862609043717384f, 0.0036580038722604513f, 0.003416682593524456f, 0.00984326470643282f, 0.010219783522188663f, 0.014713261276483536f, 0.0033654680009931326f, 0.007454822305589914f, 0.0032197439577430487f, 0.005297315772622824f, 0.0046474202536046505f, 0.006226920057088137f, 0.006282065995037556f, 0.00405827397480607f, 0.01311919279396534f, 0.0036989697255194187f, 0.007712170016020536f, 0.003287648316472769f, 0.004325388465076685f, 0.005409101489931345f, 0.010079038329422474f, 0.009991426952183247f, 0.0037060340400785208f, 0.010175165720283985f, 0.007014809176325798f, 0.008007288910448551f, 0.016910605132579803f, 0.0030467654578387737f, 0.011201511137187481f, 0.0028426232747733593f, 0.0071085914969444275f, 0.003539344761520624f, 0.004015517421066761f, 0.00690061179921031f, 0.004736462142318487f, 0.00428071990609169f, 0.0051472801715135574f, 0.020649995654821396f, 0.004508682526648045f, 0.005734541453421116f, 0.006279386579990387f, 0.003277398180216551f, 0.002045588567852974f, 0.002295474288985133f, 0.008198300376534462f, 0.005067364778369665f, 0.006695788353681564f, 0.008810273371636868f, 0.014631792902946472f, 0.005909347906708717f, 0.008815409615635872f, 0.0011307182721793652f, 0.00912818219512701f, 0.0017158157425001264f, 0.008702797815203667f, 0.012516471557319164f, 0.005103922914713621f, 0.010244752280414104f, 0.0062357462011277676f, 0.0030942161101847887f, 0.004217018373310566f, 0.003971512895077467f, 0.005173839628696442f, 0.00836386252194643f, 0.008284559473395348f, 0.004042338579893112f, 0.002377209020778537f, 0.007105488330125809f, 0.008143872022628784f, 0.0017943379934877157f, 0.006559189409017563f, 0.0047541651874780655f, 0.010180149227380753f, 0.010883226059377193f, 0.014536179602146149f, 0.0030778376385569572f, 0.001730922027491033f, 0.007567370776087046f, 0.009138639084994793f, 0.007257489953190088f, 0.0063891541212797165f, 0.005202081054449081f, 0.006018622778356075f, 0.009541136212646961f, 0.007912562228739262f, 0.005301958415657282f, 0.009267603978514671f, 0.005582951940596104f, 0.007022263947874308f, 0.0018958564614877105f, 0.02079514041543007f, 0.008073922246694565f, 0.007084586191922426f, 0.008434806950390339f, 0.003401213325560093f, 0.0027271544095128775f, 0.006445717066526413f, 0.006670577917248011f, 0.009078716859221458f, 0.0027980718296021223f, 0.005340836476534605f, 0.007219623774290085f, 0.009791341610252857f, 0.006191775668412447f, 0.010852167382836342f, 0.004847464617341757f, 0.007235181983560324f, 0.00729903532192111f, 0.00832440797239542f, 0.00672604376450181f, 0.035444170236587524f, 0.006943004205822945f, 0.005239542108029127f, 0.001115327817387879f, 0.009677761234343052f, 0.014309813268482685f, 0.008474888280034065f, 0.004203221760690212f, 0.017963668331503868f, 0.0047947983257472515f, 0.003845619736239314f, 0.00396792683750391f, 0.0032042991369962692f, 0.020314151421189308f, 0.005797917954623699f, 0.007250658702105284f, 0.003464789129793644f, 0.012283279560506344f, 0.01646295003592968f, 0.00665939599275589f, 0.0032080551609396935f, 0.00680903997272253f, 0.007536416407674551f, 0.005592789500951767f, 0.008610842749476433f, 0.006693732459098101f, 0.004060041159391403f, 0.007462647743523121f, 0.011043259873986244f, 0.006379985716193914f, 0.00435488298535347f, 0.008345537818968296f, 0.00940998550504446f, 0.007382740266621113f, 0.00785722117871046f, 0.003922387026250362f, 0.003030099906027317f, 0.0037622980307787657f, 0.002289985539391637f, 0.013363049365580082f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #246 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011369929648935795f, 0.013936759904026985f, 0.008922873996198177f, 0.011746958829462528f, 0.00308182742446661f, 0.004632861819118261f, 0.005298533942550421f, 0.003838322591036558f, 0.0042438022792339325f, 0.008089346811175346f, 0.004502630326896906f, 0.006308295298367739f, 0.010179203003644943f, 0.0035059174988418818f, 0.011744305491447449f, 0.009764034301042557f, 0.01041837502270937f, 0.005073153413832188f, 0.004047509282827377f, 0.0055160196498036385f, 0.0067530847154557705f, 0.005206747446209192f, 0.01114814355969429f, 0.009967319667339325f, 0.00668927701190114f, 0.004438318777829409f, 0.004159207921475172f, 0.003098896471783519f, 0.006381880957633257f, 0.0029429688584059477f, 0.009637787006795406f, 0.00434601167216897f, 0.003450909163802862f, 0.007654788438230753f, 0.006301524583250284f, 0.0062999241054058075f, 0.003929019905626774f, 0.012053987011313438f, 0.005445247981697321f, 0.008681981824338436f, 0.009345656260848045f, 0.0065657696686685085f, 0.004340941086411476f, 0.010420729406177998f, 0.007123381830751896f, 0.005642076022922993f, 0.004221268929541111f, 0.012690756469964981f, 0.01063349936157465f, 0.00312228174880147f, 0.011418082751333714f, 0.017537416890263557f, 0.007146679796278477f, 0.006040728185325861f, 0.004211640451103449f, 0.010785973630845547f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #247 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_63_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005336742615327239f, 0.0004200729599688202f, 0.000986171537078917f, 0.0007668862817808986f, 0.00032310979440808296f, 0.0003765671863220632f, 0.0005506464513018727f, 0.0003741093387361616f, 0.00046095834113657475f, 0.0005629118531942368f, 0.0005916678928770125f, 0.0004651219642255455f, 0.0003517720033414662f, 0.00045018381206318736f, 0.0004505379474721849f, 0.00035998839302919805f, 0.0004866461968049407f, 0.0008131787180900574f, 0.0006857445696368814f, 0.0008610557415522635f, 0.0005231452523730695f, 0.00044146872824057937f, 0.0002932843053713441f, 0.0005437296931631863f, 0.0004635225050151348f, 0.0006821668357588351f, 0.00042770858271978796f, 0.0008461539982818067f, 0.0006904241745360196f, 0.00039584076148457825f, 0.0005287481471896172f, 0.0004254874074831605f, 0.0005421483656391501f, 0.00043479554005898535f, 0.0004270166391506791f, 0.0002759011695161462f, 0.0007890115375630558f, 0.0005635021952912211f, 0.0004612984193954617f, 0.00042803387623280287f, 0.00040067301597446203f, 0.0003120427136309445f, 0.0003178520710207522f, 0.00036572592216543853f, 0.0006398681434802711f, 0.00031052937265485525f, 0.000669433968141675f, 0.0004181916010566056f, 0.00036873153294436634f, 0.0002344167878618464f, 0.00032670373911969364f, 0.0005535711534321308f, 0.000602636078838259f, 0.0005353002343326807f, 0.0004368061199784279f, 0.0007192182238213718f, 0.0005139732966199517f, 0.0004405408981256187f, 0.0005542032886296511f, 0.00044243063894100487f, 0.0003504154155962169f, 0.0004717525443993509f, 0.00043776025995612144f, 0.0004779790178872645f, 0.0005294968141242862f, 0.0005454422207549214f, 0.0005030383472330868f, 0.00032268810900859535f, 0.000397293217247352f, 0.00038447242695838213f, 0.0004898551851511002f, 0.00037489357055164874f, 0.0007681759307160974f, 0.0005365405813790858f, 0.0007013254798948765f, 0.0003390908532310277f, 0.0007445437950082123f, 0.0004957779892720282f, 0.0007278380217030644f, 0.000291659525828436f, 0.0008123490842990577f, 0.0005304486840032041f, 0.000507962831761688f, 0.0007265229360200465f, 0.00036524434108287096f, 0.0005137443076819181f, 0.0004307880881242454f, 0.0005140123539604247f, 0.00035503332037478685f, 0.0005337961483746767f, 0.0005026414874009788f, 0.0010232065105810761f, 0.00037299146060831845f, 0.0005114338709972799f, 0.0003675042826216668f, 0.00043500884203240275f, 0.0009862405713647604f, 0.0005082623101770878f, 0.0007802621112205088f, 0.0004123222315683961f, 0.00034072870039381087f, 0.00036510295467451215f, 0.00037377089029178023f, 0.00044542818795889616f, 0.0005735611193813384f, 0.00045572887756861746f, 0.0005643539479933679f, 0.0008988363551907241f, 0.00027746829437091947f, 0.0005713125574402511f, 0.00040094199357554317f, 0.0005028270534239709f, 0.00038054081960581243f, 0.00044782678014598787f, 0.0005923337885178626f, 0.0005345981335267425f, 0.0004520748043432832f, 0.00077629997394979f, 0.0005403741961345077f, 0.0005301857017911971f, 0.000332093593897298f, 0.0003488696529529989f, 0.0006304921698756516f, 0.0004082274390384555f, 0.0003491495444905013f, 0.00033377809450030327f, 0.0007137511274777353f, 0.0005213762051425874f, 0.0005120442365296185f, 0.0006291334866546094f, 0.00099855475127697f, 0.0004914109595119953f, 0.00043211464071646333f, 0.0004095940093975514f, 0.0002710941480472684f, 0.00046380009735003114f, 0.0004710227658506483f, 0.0005208092043176293f, 0.00044256681576371193f, 0.000588655995670706f, 0.0007595406495966017f, 0.0007299934513866901f, 0.00039953802479431033f, 0.000495943590067327f, 0.0005410137819126248f, 0.0003682506794575602f, 0.0008031040779314935f, 0.0005090697668492794f, 0.0005411452730186284f, 0.000512589467689395f, 0.0004157107905484736f, 0.00044877955224364996f, 0.0006329519674181938f, 0.0003946712822653353f, 0.00047253118827939034f, 0.0005465472931973636f, 0.00034922047052532434f, 0.00046949941315688193f, 0.00033732745214365423f, 0.0007279401179403067f, 0.0003022566088475287f, 0.00025740001001395285f, 0.00032119941897690296f, 0.0003591985732782632f, 0.0004640124971047044f, 0.0006352645577862859f, 0.00031457687146030366f, 0.00042337909690104425f, 0.0005406588315963745f, 0.0005790266441181302f, 0.0005467078881338239f, 0.0002330550050828606f, 0.0002348337002331391f, 0.0004100048099644482f, 0.0003136829473078251f, 0.00048704625805839896f, 0.000659614393953234f, 0.00037914240965619683f, 0.0004795784188900143f, 0.0004034739686176181f, 0.0005586068145930767f, 0.0005025482969358563f, 0.0005653459229506552f, 0.0004973868490196764f, 0.0007481887587346137f, 0.0007692063809372485f, 0.0006209858111105859f, 0.0004927287809550762f, 0.0006287796422839165f, 0.00030819897074252367f, 0.0003254621697124094f, 0.0006831075297668576f, 0.0003531122929416597f, 0.00019469423568807542f, 0.0006914138211868703f, 0.0004221033595968038f, 0.0007928733830340207f, 0.0004478812625166029f, 0.000578639330342412f, 0.0005559450946748257f, 0.000797994842287153f, 0.0006290285964496434f, 0.0004907814436592162f, 0.0003930106176994741f, 0.00038697649142704904f, 0.00041641181451268494f, 0.00029521650867536664f, 0.0004444219230208546f, 0.0007152397301979363f, 0.0006581161287613213f, 0.0006353642675094306f, 0.0006260162335820496f, 0.00043461399036459625f, 0.00027725426480174065f, 0.0005140351131558418f, 0.0003365606826264411f, 0.00038704799953848124f, 0.0004465622187126428f, 0.000748701742850244f, 0.00033299039932899177f, 0.0006679424550384283f, 0.00039489701157435775f, 0.0003904180775862187f, 0.0005292571731843054f, 0.0005827070563100278f, 0.0005670305108651519f, 0.0004461664939299226f, 0.00037084741052240133f, 0.00045767484698444605f, 0.0008381177322007716f, 0.0006085240165702999f, 0.0003112928243353963f, 0.0007496938924305141f, 0.00048362210509367287f, 0.000354198447894305f, 0.0004422598867677152f, 0.0006358884857036173f, 0.0004217882815282792f, 0.0004426703089848161f, 0.00043366997851990163f, 0.00040900066960603f, 0.0003560932236723602f, 0.0007928741397336125f, 0.0003082014445681125f, 0.0009816576493903995f, 0.0005691414116881788f, 0.000668862194288522f, 0.0005825301632285118f, 0.0006455864640884101f, 0.0005883977864868939f, 0.000556799815967679f, 0.0003576609888114035f, 0.0006558690220117569f, 0.00034744321601465344f, 0.00036542332964017987f, 0.0005588750937022269f, 0.00042889744509011507f, 0.000373939546989277f, 0.0005051327170804143f, 0.0006978543242439628f, 0.0005628384533338249f, 0.00025267666205763817f, 0.00036804669070988894f, 0.0004623267741408199f, 0.00041389159741811454f, 0.00043445962364785373f, 0.00046830964856781065f, 0.0008366966503672302f, 0.0004292747762519866f, 0.0004887562827207148f, 0.0006410142523236573f, 0.0005687613738700747f, 0.0005954954540356994f, 0.0003154223377350718f, 0.0005888922023586929f, 0.000343773775966838f, 0.0002755497698672116f, 0.0004411173576954752f, 0.00039434622158296406f, 0.00038192173815332353f, 0.0006942499312572181f, 0.0004452785069588572f, 0.0005176619160920382f, 0.0004282871668692678f, 0.0004522852541413158f, 0.00044615197111852467f, 0.00034886933281086385f, 0.0005188117502257228f, 0.000491557118948549f, 0.0004325492773205042f, 0.00042360034422017634f, 0.0006451421068049967f, 0.00043166065006516874f, 0.0005388857680372894f, 0.0002814031613525003f, 0.0005562983569689095f, 0.0006476675625890493f, 0.0003225928812753409f, 0.0003946038195863366f, 0.0004819019231945276f, 0.0005155076505616307f, 0.0004996781935915351f, 0.0003837849071715027f, 0.0002510669582989067f, 0.0007293851813301444f, 0.000256602797890082f, 0.0005538197583518922f, 0.0005888668238185346f, 0.0003891240048687905f, 0.0003473454562481493f, 0.0004085329710505903f, 0.00036760783405043185f, 0.000535113038495183f, 0.0004057709884364158f, 0.0006705416599288583f, 0.0002773731539491564f, 0.000668570282869041f, 0.00040445459308102727f, 0.000484961288748309f, 0.0008161841542460024f, 0.0005412666941992939f, 0.00045374862384051085f, 0.00031759508419781923f, 0.00043868497596122324f, 0.0003147567040286958f, 0.0004453104338608682f, 0.00043858925346285105f, 0.0005828686407767236f, 0.0003514762793201953f, 0.000645957188680768f, 0.0007052143919281662f, 0.0005530242924578488f, 0.0004426083469297737f, 0.00046415950055234134f, 0.0004829115641769022f, 0.0006927446811459959f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #248 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004212052561342716f, 0.011516700498759747f, 0.0031066942028701305f, 0.007954993285238743f, 0.008816909044981003f, 0.005999105982482433f, 0.007229219656437635f, 0.003097199136391282f, 0.0067014265805482864f, 0.010423761792480946f, 0.003192942589521408f, 0.007382160983979702f, 0.009640336036682129f, 0.007262087427079678f, 0.006178804207593203f, 0.016166893765330315f, 0.004624587949365377f, 0.00641969358548522f, 0.004165566526353359f, 0.00371760712005198f, 0.003690477693453431f, 0.0056421756744384766f, 0.02701234258711338f, 0.004056055098772049f, 0.00931641273200512f, 0.0038231827784329653f, 0.005441715009510517f, 0.003361861687153578f, 0.00420617638155818f, 0.01083082053810358f, 0.007126284297555685f, 0.004001956898719072f, 0.005919917020946741f, 0.004821274429559708f, 0.005699828267097473f, 0.010037386789917946f, 0.004030024167150259f, 0.0023118876852095127f, 0.008748711086809635f, 0.0033934186212718487f, 0.005475455895066261f, 0.010478049516677856f, 0.009223521687090397f, 0.006313933525234461f, 0.005680308677256107f, 0.00598407257348299f, 0.002926553599536419f, 0.005786679685115814f, 0.01104765385389328f, 0.057604484260082245f, 0.0074860271997749805f, 0.006807269062846899f, 0.0025983252562582493f, 0.012633578851819038f, 0.00919023435562849f, 0.004139421973377466f, 0.0028215860947966576f, 0.003123414935544133f, 0.004511859733611345f, 0.005365672986954451f, 0.00901487935334444f, 0.005507553927600384f, 0.005935800261795521f, 0.005432410631328821f, 0.00594307528808713f, 0.0038846272509545088f, 0.003000992350280285f, 0.004857610445469618f, 0.002780356677249074f, 0.036755044013261795f, 0.0066019208170473576f, 0.005812540650367737f, 0.004315445199608803f, 0.004345856606960297f, 0.005618222989141941f, 0.005211008246988058f, 0.005770972464233637f, 0.0038476353511214256f, 0.0036759425420314074f, 0.006415632087737322f, 0.0035046145785599947f, 0.0066842627711594105f, 0.005898821167647839f, 0.004259796813130379f, 0.012966512702405453f, 0.003482253523543477f, 0.010562391020357609f, 0.003501386381685734f, 0.0055854665115475655f, 0.0018591905245557427f, 0.002063162624835968f, 0.0025830043014138937f, 0.004052276257425547f, 0.016912925988435745f, 0.0033287606202065945f, 0.007116515655070543f, 0.00441710976883769f, 0.008323127403855324f, 0.011681376956403255f, 0.006822659634053707f, 0.013288475573062897f, 0.002213788451626897f, 0.004564066417515278f, 0.004058282356709242f, 0.004332557786256075f, 0.007512467913329601f, 0.0045067323371768f, 0.0038769198581576347f, 0.016535559669137f, 0.003981862682849169f, 0.0067961509339511395f, 0.00401310995221138f, 0.010821495205163956f, 0.005439986474812031f, 0.003961649723351002f, 0.0042524817399680614f, 0.025483449921011925f, 0.007966795936226845f, 0.005994219332933426f, 0.007699082605540752f, 0.011547340080142021f, 0.012182408012449741f, 0.0030189366079866886f, 0.010629196651279926f, 0.014205723069608212f, 0.004058826714754105f, 0.0043036676943302155f, 0.002977465745061636f, 0.0038508146535605192f, 0.0029173027724027634f, 0.004343407694250345f, 0.013274489901959896f, 0.007633523549884558f, 0.017091592773795128f, 0.004932703450322151f, 0.008216333575546741f, 0.005087256897240877f, 0.003946867771446705f, 0.011517040431499481f, 0.02096370980143547f, 0.0038240074645727873f, 0.003823002567514777f, 0.00510138925164938f, 0.006821061484515667f, 0.003916942048817873f, 0.004374916199594736f, 0.004738618619740009f, 0.004898776765912771f, 0.005301719065755606f, 0.004371600225567818f, 0.007921183481812477f, 0.006561661139130592f, 0.005763545632362366f, 0.00629497691988945f, 0.009571274742484093f, 0.00783612858504057f, 0.007535613141953945f, 0.013426066376268864f, 0.006292791571468115f, 0.008525625802576542f, 0.007621121127158403f, 0.014584172517061234f, 0.006498437840491533f, 0.011837533675134182f, 0.004009021446108818f, 0.002849841257557273f, 0.007025128696113825f, 0.004922269377857447f, 0.0044402433559298515f, 0.0034987840335816145f, 0.0027955733239650726f, 0.012002098374068737f, 0.04420039802789688f, 0.005285421386361122f, 0.043305404484272f, 0.006246091797947884f, 0.0030215769074857235f, 0.018087007105350494f, 0.00251901731826365f, 0.002765641314908862f, 0.005348378326743841f, 0.0045649087987840176f, 0.005144432187080383f, 0.0036719695199280977f, 0.0026939990930259228f, 0.0029949662275612354f, 0.005202997010201216f, 0.0027425845619291067f, 0.0036720787174999714f, 0.002910781418904662f, 0.013526811264455318f, 0.009318666532635689f, 0.01025443896651268f, 0.004809979815036058f, 0.007071513682603836f, 0.003952554427087307f, 0.0036920038983225822f, 0.0029821828939020634f, 0.00423964811488986f, 0.01082129031419754f, 0.005048784893006086f, 0.005598680581897497f, 0.0037508895620703697f, 0.004705955274403095f, 0.008102981373667717f, 0.005079313181340694f, 0.02894800528883934f, 0.009163123555481434f, 0.006964609492570162f, 0.0047892299480736256f, 0.005773399956524372f, 0.005310118198394775f, 0.006950198207050562f, 0.004147612024098635f, 0.00334610091522336f, 0.0056916698813438416f, 0.011324205435812473f, 0.006535394117236137f, 0.0020445429254323244f, 0.007975020445883274f, 0.007894271053373814f, 0.004274813458323479f, 0.015173446387052536f, 0.005231958348304033f, 0.003264613216742873f, 0.006141797639429569f, 0.004840157926082611f, 0.006291131488978863f, 0.004497940186411142f, 0.0069499993696808815f, 0.003953651990741491f, 0.005758711602538824f, 0.0042150854133069515f, 0.00598866306245327f, 0.00725726131349802f, 0.009036090224981308f, 0.004756481386721134f, 0.00732007110491395f, 0.0027147673536092043f, 0.010382156819105148f, 0.009006759151816368f, 0.004723475780338049f, 0.004518233705312014f, 0.0044861347414553165f, 0.0032128237653523684f, 0.0031988013070076704f, 0.0036289962008595467f, 0.006868068128824234f, 0.004496362991631031f, 0.005822379142045975f, 0.004218123387545347f, 0.004165866877883673f, 0.002818650333210826f, 0.010793016292154789f, 0.0032015854958444834f, 0.005045093130320311f, 0.0035915221087634563f, 0.006683278828859329f, 0.014850839041173458f, 0.0052164411172270775f, 0.006148241925984621f, 0.029036691412329674f, 0.004357525613158941f, 0.0020697657018899918f, 0.0033373283222317696f, 0.008039810694754124f, 0.0071641928516328335f, 0.0030226975213736296f, 0.014546321704983711f, 0.00443840678781271f, 0.005933900363743305f, 0.004300594795495272f, 0.008963634259998798f, 0.011821378022432327f, 0.004160645417869091f, 0.006368047092109919f, 0.0036456745583564043f, 0.006929941941052675f, 0.006009435746818781f, 0.0031094281002879143f, 0.003765610745176673f, 0.007829832844436169f, 0.005099511239677668f, 0.006138445343822241f, 0.009827664121985435f, 0.007209490053355694f, 0.005714670289307833f, 0.0025899545289576054f, 0.0045629991218447685f, 0.006789813749492168f, 0.00852978602051735f, 0.005598272662609816f, 0.0031863925978541374f, 0.006885315291583538f, 0.008158816024661064f, 0.0030318954959511757f, 0.005167053081095219f, 0.011269385926425457f, 0.011818011291325092f, 0.007699335925281048f, 0.00522588798776269f, 0.0072621251456439495f, 0.013412882573902607f, 0.016832301393151283f, 0.0068849134258925915f, 0.046941693872213364f, 0.0030853329226374626f, 0.0022263682913035154f, 0.0043399762362241745f, 0.005326688289642334f, 0.00450835470110178f, 0.007231524679809809f, 0.0038322664331644773f, 0.0038102378603070974f, 0.002640595892444253f, 0.009702794253826141f, 0.005336507689207792f, 0.0069318246096372604f, 0.005905667785555124f, 0.003606642596423626f, 0.0027894347440451384f, 0.00586660485714674f, 0.006540849804878235f, 0.0058673652820289135f, 0.005882441531866789f, 0.0033141158055514097f, 0.004490073304623365f, 0.004332044627517462f, 0.011537885293364525f, 0.004789132159203291f, 0.0032192422077059746f, 0.003736984683200717f, 0.004147867672145367f, 0.004040377214550972f, 0.00519242137670517f, 0.00222367187961936f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #249 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028040960896760225f, 0.003238917561247945f, 0.002136985072866082f, 0.0036248366814106703f, 0.00186666299123317f, 0.0023555071093142033f, 0.002385644940659404f, 0.001989303156733513f, 0.001796067925170064f, 0.001985889859497547f, 0.0015523693291470408f, 0.002675543073564768f, 0.0022015958093106747f, 0.002720760880038142f, 0.0022951061837375164f, 0.0027869855985045433f, 0.003299956675618887f, 0.002274769591167569f, 0.0013055234448984265f, 0.0024123131297528744f, 0.002761449432000518f, 0.003695463528856635f, 0.003023680532351136f, 0.0024502791929990053f, 0.005111720412969589f, 0.0026846486143767834f, 0.0024617728777229786f, 0.0016200211830437183f, 0.0016175186028704047f, 0.0021325366105884314f, 0.0035578201059252024f, 0.0028223786503076553f, 0.0029611005447804928f, 0.0030440394766628742f, 0.0015892828814685345f, 0.001893548178486526f, 0.0038759952876716852f, 0.003352738218382001f, 0.002167749684303999f, 0.001505209831520915f, 0.002253528218716383f, 0.0017706564394757152f, 0.0019601495005190372f, 0.0034824644681066275f, 0.0027378317900002003f, 0.0017523537389934063f, 0.001105997827835381f, 0.002122407080605626f, 0.0022016712464392185f, 0.001853714231401682f, 0.0019420720636844635f, 0.0015334662748500705f, 0.002011528005823493f, 0.005764801986515522f, 0.0036716563627123833f, 0.004755809903144836f, 0.002376333810389042f, 0.004270276054739952f, 0.0015648844419047236f, 0.0024712132290005684f, 0.002512869192287326f, 0.0022216627839952707f, 0.0022858469747006893f, 0.0025776601396501064f, 0.001313675893470645f, 0.002645258791744709f, 0.001490935916081071f, 0.001975185237824917f, 0.001380403060466051f, 0.0024536470882594585f, 0.003180284518748522f, 0.004545328672975302f, 0.002014684025198221f, 0.0023904971312731504f, 0.0016909361584112048f, 0.0015155243454501033f, 0.0017593640368431807f, 0.0016566852573305368f, 0.0019329950446262956f, 0.002371076960116625f, 0.002527425065636635f, 0.0019605380948632956f, 0.001563241588883102f, 0.002520735142752528f, 0.0025095243472605944f, 0.0019436668371781707f, 0.0018482067389413714f, 0.0021469034254550934f, 0.0021347717847675085f, 0.003720626700669527f, 0.0015296426136046648f, 0.002200260292738676f, 0.002023077802732587f, 0.0021092076785862446f, 0.0032886371482163668f, 0.002552944701164961f, 0.0012835153611376882f, 0.002579201478511095f, 0.0021229961421340704f, 0.0016801912570372224f, 0.002342281863093376f, 0.003396780928596854f, 0.002444349927827716f, 0.006119626108556986f, 0.0020606049802154303f, 0.0034198518842458725f, 0.0027702380903065205f, 0.0018269217107445002f, 0.0018500996520742774f, 0.0018876665271818638f, 0.0032222243025898933f, 0.001453516655601561f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #250 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002267111325636506f, 0.0017226486233994365f, 0.001803943538106978f, 0.001361335744149983f, 0.0018100887537002563f, 0.001402424299158156f, 0.0012705278350040317f, 0.002291149226948619f, 0.0013807244831696153f, 0.0022551738657057285f, 0.0015928024658933282f, 0.00212594005279243f, 0.0013673781650140882f, 0.0018862633733078837f, 0.0014721223851665854f, 0.0015887339832261205f, 0.0015579325845465064f, 0.001583143137395382f, 0.0019485177472233772f, 0.0016647826414555311f, 0.0021526170894503593f, 0.0022682331036776304f, 0.0016725260065868497f, 0.0022900900803506374f, 0.0018174556316807866f, 0.0016843985067680478f, 0.0018409533658996224f, 0.0015700444346293807f, 0.0013545415131375194f, 0.0015390117187052965f, 0.0016017104499042034f, 0.0015082497848197818f, 0.0016310923965647817f, 0.0017437805654481053f, 0.0015489277429878712f, 0.0013545653782784939f, 0.0019052679417654872f, 0.0013414145214483142f, 0.001331054954789579f, 0.002049987902864814f, 0.0013091869186609983f, 0.0017036545323207974f, 0.0014143962180241942f, 0.002128307009115815f, 0.001997065031901002f, 0.002089749788865447f, 0.0018935884581878781f, 0.0018203742802143097f, 0.001520444406196475f, 0.0013388904044404626f, 0.0021859940607100725f, 0.001782132312655449f, 0.0015398653922602534f, 0.0016478950856253505f, 0.0021057454869151115f, 0.0017639592988416553f, 0.0014933542115613818f, 0.0021721981465816498f, 0.0016889310209080577f, 0.001813138835132122f, 0.0012154817814007401f, 0.0017112910281866789f, 0.002433051820844412f, 0.0021234389860183f, 0.0010974971810355783f, 0.001492103561758995f, 0.0013343545142561197f, 0.0012696299236267805f, 0.00253760302439332f, 0.0017552566714584827f, 0.0016200438840314746f, 0.0011997530236840248f, 0.0022746799513697624f, 0.0018138423329219222f, 0.0015095578273758292f, 0.0013769959332421422f, 0.001775900716893375f, 0.0016557706985622644f, 0.0019580181688070297f, 0.001983639318495989f, 0.0015550995012745261f, 0.0018093530088663101f, 0.001963728806003928f, 0.0014142509317025542f, 0.0020661186426877975f, 0.0016797651769593358f, 0.0024043014273047447f, 0.001514076953753829f, 0.0016525600804015994f, 0.0015970520908012986f, 0.002342838328331709f, 0.0018137177685275674f, 0.0017357742181047797f, 0.00176259595900774f, 0.0013033131835982203f, 0.0015439341077581048f, 0.0012533896369859576f, 0.002036521676927805f, 0.0012825765879824758f, 0.0015810264740139246f, 0.0012704588007181883f, 0.0022478257305920124f, 0.0018867261242121458f, 0.0018493453972041607f, 0.0011589854257181287f, 0.0015727502759546041f, 0.0017667922656983137f, 0.0017221026355400681f, 0.001733803772367537f, 0.0015333907213062048f, 0.0011970363557338715f, 0.0015072175301611423f, 0.001553035108372569f, 0.001685367082245648f, 0.0015087405918166041f, 0.0013758670538663864f, 0.0013533304445445538f, 0.0012996671721339226f, 0.0015157862799242139f, 0.0026070212479680777f, 0.0015274987090379f, 0.0019077765755355358f, 0.0019998024217784405f, 0.0014131556963548064f, 0.001584874466061592f, 0.002119610086083412f, 0.0017834585160017014f, 0.0018290099687874317f, 0.001544019440189004f, 0.0010376053396612406f, 0.0020118250977247953f, 0.0012876424007117748f, 0.0018794473726302385f, 0.0015419699484482408f, 0.0022121919319033623f, 0.001277795759961009f, 0.0029359348118305206f, 0.0014333038125187159f, 0.0013000599574297667f, 0.001114650396630168f, 0.0018474553944543004f, 0.002756248228251934f, 0.0014847664861008525f, 0.0018096619751304388f, 0.0010351393138989806f, 0.0018241946818307042f, 0.0018804877763614058f, 0.0014554631197825074f, 0.001075295265763998f, 0.0019728001207113266f, 0.0021091534290462732f, 0.0018452018266543746f, 0.0012750528985634446f, 0.0016889962134882808f, 0.0012910498771816492f, 0.0012765009887516499f, 0.0019511308055371046f, 0.0015733271138742566f, 0.0023084869608283043f, 0.001912592095322907f, 0.001808347413316369f, 0.0021490242797881365f, 0.0016530462307855487f, 0.0013498853659257293f, 0.0013919093180447817f, 0.0015112938126549125f, 0.0014451290480792522f, 0.00194016401655972f, 0.002281252760440111f, 0.0015321720857173204f, 0.0016765627078711987f, 0.0013809497468173504f, 0.0017799419583752751f, 0.001814001938328147f, 0.0023651618976145983f, 0.0010821197647601366f, 0.0013076295144855976f, 0.0017599230632185936f, 0.0017888499423861504f, 0.0018260495271533728f, 0.0013268367620185018f, 0.002031215699389577f, 0.002112274058163166f, 0.0014274509157985449f, 0.001500593964010477f, 0.0023485557176172733f, 0.0017707947408780456f, 0.0013062991201877594f, 0.0017437456408515573f, 0.0018250481225550175f, 0.0020490677561610937f, 0.0014410477597266436f, 0.0015408014878630638f, 0.0021818787790834904f, 0.001455910038203001f, 0.0015415119705721736f, 0.0013487691758200526f, 0.002020943211391568f, 0.0014558170223608613f, 0.0012169394176453352f, 0.0020105401054024696f, 0.0014551004860550165f, 0.0015608634566888213f, 0.0021377066150307655f, 0.0018560755997896194f, 0.0016677158419042826f, 0.0019060196354985237f, 0.0014903988922014832f, 0.0017575256060808897f, 0.0027390695177018642f, 0.0017319914186373353f, 0.001546476618386805f, 0.0013396806316450238f, 0.0023978352546691895f, 0.001981298206374049f, 0.0015709054423496127f, 0.0011716395383700728f, 0.002269064774736762f, 0.001256059855222702f, 0.0011136929970234632f, 0.0020060534588992596f, 0.0016781191807240248f, 0.0014569680206477642f, 0.0019092425936833024f, 0.0020344064105302095f, 0.0022709534969180822f, 0.0015580145409330726f, 0.0019147025886923075f, 0.0015199462650343776f, 0.0016111915465444326f, 0.0019060255726799369f, 0.0017055788775905967f, 0.0013148224679753184f, 0.0017541821580380201f, 0.0018296190537512302f, 0.0022862351033836603f, 0.00154328893404454f, 0.0018308580620214343f, 0.0013016605516895652f, 0.001645783893764019f, 0.0021103357430547476f, 0.002127307001501322f, 0.0020533243659883738f, 0.0024481769651174545f, 0.001220353995449841f, 0.0030677092727273703f, 0.002032338408753276f, 0.0016890214756131172f, 0.0017823491944000125f, 0.0020912494510412216f, 0.002100517274811864f, 0.0019930240232497454f, 0.0021621491760015488f, 0.0011802158551290631f, 0.0020297705195844173f, 0.0022618293296545744f, 0.0014830502914264798f, 0.0014367179246619344f, 0.001640566042624414f, 0.0011839574435725808f, 0.001329118967987597f, 0.0015654850285500288f, 0.001384033472277224f, 0.0014955193037167192f, 0.0018057943088933825f, 0.0012417518300935626f, 0.0017840467626228929f, 0.001735058380290866f, 0.0013210593024268746f, 0.0010896207531914115f, 0.001259516691789031f, 0.001399113447405398f, 0.0011224659392610192f, 0.001688678516075015f, 0.001991817494854331f, 0.0016060846392065287f, 0.001590521540492773f, 0.0014145808527246118f, 0.001511348644271493f, 0.0012552047846838832f, 0.0016836317954584956f, 0.0015740253729745746f, 0.0016222343547269702f, 0.0015759175876155496f, 0.0016001268522813916f, 0.001816309872083366f, 0.0023227017372846603f, 0.002264198614284396f, 0.0011395509354770184f, 0.0015316639328375459f, 0.0020644422620534897f, 0.0013134885812178254f, 0.0014613551320508122f, 0.0016649309545755386f, 0.0010665414156392217f, 0.0017090337350964546f, 0.0021779483649879694f, 0.0010980640072375536f, 0.003163451561704278f, 0.0012284069089218974f, 0.0014453526819124818f, 0.0020505564752966166f, 0.001295346999540925f, 0.0012416825629770756f, 0.0016858996823430061f, 0.0016286504687741399f, 0.001341399853117764f, 0.0013107050908729434f, 0.0013752873055636883f, 0.0016014997381716967f, 0.0018430540803819895f, 0.0035187529865652323f, 0.0015710943844169378f, 0.0021470861975103617f, 0.0012836114037781954f, 0.003335074055939913f, 0.002132014138624072f, 0.001729250536300242f, 0.001161900581791997f, 0.0014115424128249288f, 0.0015489723300561309f, 0.0016460951883345842f, 0.0023281709291040897f, 0.0013382694451138377f, 0.001278710551559925f, 0.002173330634832382f, 0.0019509884295985103f, 0.0015425713500007987f, 0.003101702081039548f, 0.0022340158466249704f, 0.0016207693843171f, 0.002414151793345809f, 0.001491657691076398f, 0.0014009126462042332f, 0.001556297531351447f, 0.0014303199714049697f, 0.001690790755674243f, 0.0013402150943875313f, 0.0014742125058546662f, 0.001300892443396151f, 0.0014850058360025287f, 0.0023021483793854713f, 0.0014448778238147497f, 0.0015200743218883872f, 0.0017230898374691606f, 0.0015828300965949893f, 0.0018515153788030148f, 0.0013424369972199202f, 0.0018887227633967996f, 0.0017429806757718325f, 0.001688623335212469f, 0.0012626696843653917f, 0.0014725473010912538f, 0.0018677341286092997f, 0.0015631889691576362f, 0.0013135055778548121f, 0.0022717430256307125f, 0.0014860446099191904f, 0.0016098711639642715f, 0.002473909640684724f, 0.00164342625066638f, 0.0027565504424273968f, 0.002295575337484479f, 0.0013649126049131155f, 0.0011990605853497982f, 0.001349052065052092f, 0.0014114697696641088f, 0.0020233476534485817f, 0.002218132372945547f, 0.0017954488284885883f, 0.0014193066162988544f, 0.0015693239402025938f, 0.002376094227656722f, 0.0015906775370240211f, 0.0018978826701641083f, 0.0012854411033913493f, 0.0012415763922035694f, 0.0015707231359556317f, 0.0027157196309417486f, 0.0017200007569044828f, 0.0018644564552232623f, 0.0012745516141876578f, 0.0013716364046558738f, 0.0018802582053467631f, 0.0012732510222122073f, 0.0010919374180957675f, 0.0014408404240384698f, 0.0012647768016904593f, 0.0011234792182222009f, 0.001653712592087686f, 0.0015372354537248611f, 0.0010981509694829583f, 0.0011731811100617051f, 0.0018344789277762175f, 0.0019122285302728415f, 0.0016963809030130506f, 0.0015129137318581343f, 0.001734218210913241f, 0.002400321653112769f, 0.0023910864256322384f, 0.0036883829161524773f, 0.0012764498824253678f, 0.001819572877138853f, 0.001672640792094171f, 0.002263616072013974f, 0.0013218213571235538f, 0.0020103200804442167f, 0.0018326787976548076f, 0.0017649425426498055f, 0.0014745944645255804f, 0.0013511666329577565f, 0.0015730122104287148f, 0.0014939707471057773f, 0.0014206762425601482f, 0.0016643460839986801f, 0.0017491107573732734f, 0.0022264153230935335f, 0.0014902963303029537f, 0.001876684371381998f, 0.0020435843616724014f, 0.0017312956042587757f, 0.0015764408744871616f, 0.0014875089982524514f, 0.001239306409843266f, 0.002093561924993992f, 0.0013949446147307754f, 0.0011664568446576595f, 0.0020486959256231785f, 0.0017620953731238842f, 0.0018414485966786742f, 0.001048951642587781f, 0.001454135519452393f, 0.0017033624462783337f, 0.001512691960670054f, 0.002392266411334276f, 0.0009808570612221956f, 0.0013631394831463695f, 0.0026894300244748592f, 0.0015307979192584753f, 0.001777611905708909f, 0.0016718258848413825f, 0.0011740113841369748f, 0.0013534622266888618f, 0.0023875273764133453f, 0.0023834214080125093f, 0.0028080553747713566f, 0.001281178672797978f, 0.001327716512605548f, 0.0014316836604848504f, 0.0017372568836435676f, 0.0013885919470340014f, 0.002246394520625472f, 0.001550628338009119f, 0.0016084887320175767f, 0.0015440628631040454f, 0.0016744218301028013f, 0.0018902739975601435f, 0.001832147827371955f, 0.0017467074794694781f, 0.0015203747898340225f, 0.0017085610888898373f, 0.0015213899314403534f, 0.0020870273001492023f, 0.0022944293450564146f, 0.00153192481957376f, 0.0016793294344097376f, 0.0017328260000795126f, 0.001992501551285386f, 0.0012613716535270214f, 0.0020110683981329203f, 0.0024012145586311817f, 0.00179905048571527f, 0.0014090007171034813f, 0.0019595115445554256f, 0.0013872649287804961f, 0.001798841287381947f, 0.0025121071375906467f, 0.0012191710993647575f, 0.0021905626635998487f, 0.0011828448623418808f, 0.0014185963664203882f, 0.0020626357290893793f, 0.0014817480696365237f, 0.0011750967241823673f, 0.001325089717283845f, 0.001459892955608666f, 0.0024567286018282175f, 0.002533801831305027f, 0.0018491266528144479f, 0.0017070095054805279f, 0.0016631046310067177f, 0.0009867309127002954f, 0.0013923721853643656f, 0.0013740226859226823f, 0.0013383639743551612f, 0.0013109409483149648f, 0.001564539852552116f, 0.0017853528261184692f, 0.002043886110186577f, 0.0013023578794673085f, 0.0022109481506049633f, 0.001719364314340055f, 0.0014985660091042519f, 0.001173711847513914f, 0.002012293552979827f, 0.0020391377620399f, 0.0015431140782311559f, 0.001880605355836451f, 0.0013640568358823657f, 0.0010906675597652793f, 0.002059778431430459f, 0.0021002348512411118f, 0.001311355154030025f, 0.0010591932805255055f, 0.0016864606877788901f, 0.0015812061028555036f, 0.0010447683744132519f, 0.0020592946093529463f, 0.0018556001596152782f, 0.001757006742991507f, 0.002015151781961322f, 0.0018644504016265273f, 0.0019356050761416554f, 0.0022363935131579638f, 0.0023728699889034033f, 0.0015862606232985854f, 0.0013410202227532864f, 0.0016815034905448556f, 0.0014027560828253627f, 0.0015039130812510848f, 0.001692335121333599f, 0.0013688323087990284f, 0.001914897235110402f, 0.0014299353351816535f, 0.0017532469937577844f, 0.0018126519862562418f, 0.0023013039026409388f, 0.0018537023570388556f, 0.0017705886857584119f, 0.0018173831049352884f, 0.001472330535762012f, 0.002154494868591428f, 0.0015013262163847685f, 0.0018481287406757474f, 0.0016783536411821842f, 0.0014582130825147033f, 0.0015554385026916862f, 0.00258151744492352f, 0.0015909509966149926f, 0.001310241292230785f, 0.0010890288976952434f, 0.001652583247050643f, 0.0020600466523319483f, 0.0013595338677987456f, 0.002717919647693634f, 0.0014618932036682963f, 0.001905168523080647f, 0.0015346844447776675f, 0.0024766528513282537f, 0.001564730773679912f, 0.001772457966580987f, 0.0014415881596505642f, 0.0012672197772189975f, 0.002116095507517457f, 0.0020069272723048925f, 0.00195237435400486f, 0.001036371453665197f, 0.002161528682336211f, 0.001240118988789618f, 0.0013641041005030274f, 0.0016892204293981194f, 0.002304124180227518f, 0.0016581029631197453f, 0.0012780720135197043f, 0.0013945925747975707f, 0.0018772725015878677f, 0.0014509243192151189f, 0.0024667929392307997f, 0.0015488856006413698f, 0.0019623544067144394f, 0.0011084177531301975f, 0.0019231911282986403f, 0.002091164467856288f, 0.001669000368565321f, 0.0014276736183091998f, 0.0014760150806978345f, 0.0012872613733634353f, 0.0014114361256361008f, 0.0012316458160057664f, 0.0012467119377106428f, 0.0010563005926087499f, 0.001754443277604878f, 0.0019646002911031246f, 0.001800777274183929f, 0.0014547875616699457f, 0.0013694379013031721f, 0.0018519210861995816f, 0.0011691629188135266f, 0.001991470344364643f, 0.001685237162746489f, 0.002652035327628255f, 0.001946576521731913f, 0.0017670794622972608f, 0.001865878701210022f, 0.001744155422784388f, 0.001704295282252133f, 0.0012932677054777741f, 0.0017124841688200831f, 0.0015012379735708237f, 0.0012720590457320213f, 0.0018249398563057184f, 0.0015370137989521027f, 0.001994326012209058f, 0.0019433044362813234f, 0.001660857000388205f, 0.0023114399518817663f, 0.0019880563486367464f, 0.00218388345092535f, 0.0013514173915609717f, 0.0020758069586008787f, 0.0022859780583530664f, 0.001342144445516169f, 0.001389003242366016f, 0.0027718383353203535f, 0.0014836374903097749f, 0.0010977227939292789f, 0.0015886587789282203f, 0.0017448074650019407f, 0.001105717965401709f, 0.0022159686777740717f, 0.002101656747981906f, 0.0015857587568461895f, 0.0016076287720352411f, 0.0019055106677114964f, 0.0016650387551635504f, 0.0013071101857349277f, 0.0019646824803203344f, 0.001252802787348628f, 0.0020437142811715603f, 0.0020369230769574642f, 0.0018001465359702706f, 0.002238108078017831f, 0.0015376515220850706f, 0.0015420712297782302f, 0.001937496243044734f, 0.0015424295561388135f, 0.001779113314114511f, 0.0014395695179700851f, 0.0016775114927440882f, 0.001358355046249926f, 0.002792279701679945f, 0.0013230902841314673f, 0.0012885243631899357f, 0.0013505356619134545f, 0.0016341885784640908f, 0.0015153567073866725f, 0.0013049744302406907f, 0.001409474527463317f, 0.001251573790796101f, 0.0013499377528205514f, 0.0013027060776948929f, 0.0013598270015791059f, 0.0014271644176915288f, 0.0011366656981408596f, 0.0017993386136367917f, 0.0015621850034222007f, 0.002076110104098916f, 0.0012322388356551528f, 0.0013266453752294183f, 0.0015582394553348422f, 0.0015466200420632958f, 0.0011688648955896497f, 0.0012589701218530536f, 0.0013393675908446312f, 0.0018591491971164942f, 0.001193431206047535f, 0.0020378688350319862f, 0.002255118452012539f, 0.0015250671422109008f, 0.0018758688820526004f, 0.0016671718331053853f, 0.0011165027972310781f, 0.0012867464683949947f, 0.0017131437780335546f, 0.0015746350400149822f, 0.001532871276140213f, 0.0014291354455053806f, 0.0011407752754166722f, 0.0014999068807810545f, 0.002810202306136489f, 0.0020700718741863966f, 0.002243214286863804f, 0.0023650384973734617f, 0.0012317498913034797f, 0.001442308072000742f, 0.0016962114023044705f, 0.00254938961006701f, 0.0013982636155560613f, 0.002340553794056177f, 0.0015041674487292767f, 0.0019818106666207314f, 0.0016167153371497989f, 0.0020277979783713818f, 0.0015235526952892542f, 0.002181858289986849f, 0.0012912425445392728f, 0.0014221598394215107f, 0.0015273812459781766f, 0.0012260638177394867f, 0.001422101748175919f, 0.001802354003302753f, 0.001423572306521237f, 0.0017931225011125207f, 0.0021836424712091684f, 0.0016347917262464762f, 0.001251698355190456f, 0.002307626884430647f, 0.0014563658041879535f, 0.0020823883824050426f, 0.0019447347149252892f, 0.0016196485375985503f, 0.0010767232161015272f, 0.002960184123367071f, 0.0012090759119018912f, 0.0016189792659133673f, 0.0018518647411838174f, 0.0022844644263386726f, 0.0011109370971098542f, 0.002076845383271575f, 0.0011950894258916378f, 0.0016499273478984833f, 0.0017802389338612556f, 0.0014364230446517467f, 0.0014042550465092063f, 0.0014063046546652913f, 0.0016478700563311577f, 0.001063125324435532f, 0.0011070184409618378f, 0.00213265442289412f, 0.0016078860498964787f, 0.0017033620970323682f, 0.0011094720102846622f, 0.0019430936081334949f, 0.0020223064348101616f, 0.002224402967840433f, 0.0016147687565535307f, 0.001566182472743094f, 0.0015546272043138742f, 0.0019152237800881267f, 0.0016314900713041425f, 0.0017872065072879195f, 0.0020765296649187803f, 0.0015318825608119369f, 0.0016828759107738733f, 0.0014739303151145577f, 0.0012514293193817139f, 0.0014101227279752493f, 0.0017857546918094158f, 0.0015607019886374474f, 0.0014506711158901453f, 0.0016412051627412438f, 0.0020220240112394094f, 0.0021664761006832123f, 0.001614280161447823f, 0.0015419385163113475f, 0.0012203830992802978f, 0.0020431922748684883f, 0.0009511816315352917f, 0.0016944981180131435f, 0.00174738431815058f, 0.0013396190479397774f, 0.0021445045713335276f, 0.001247905776835978f, 0.0011608703061938286f, 0.002129344269633293f, 0.0028972879517823458f, 0.0013441442279145122f, 0.0020615938119590282f, 0.0013799135340377688f, 0.001645331154577434f, 0.0009021209552884102f, 0.0015876966062933207f, 0.0019079581834375858f, 0.002014660043641925f, 0.001460562227293849f, 0.0017531285993754864f, 0.0019247239688411355f, 0.0012900790898129344f, 0.0014786508399993181f, 0.0012958524748682976f, 0.001976607134565711f, 0.0021288564894348383f, 0.0012849263148382306f, 0.0013780853478237987f, 0.00117521604988724f, 0.0010801838943734765f, 0.0014319191686809063f, 0.0013308670604601502f, 0.0021020995918661356f, 0.00181110471021384f, 0.001723161549307406f, 0.0017814229940995574f, 0.002060282276943326f, 0.0013452124549075961f, 0.001370915095321834f, 0.0014646847266703844f, 0.00209373002871871f, 0.0021671492140740156f, 0.0023552558850497007f, 0.0013402090407907963f, 0.0022800511214882135f, 0.0012091498356312513f, 0.001794249634258449f, 0.001616599503904581f, 0.0016886568628251553f, 0.0013652282068505883f, 0.0014814420137554407f, 0.0020759853068739176f, 0.002130592707544565f, 0.0021315712947398424f, 0.0017562942812219262f, 0.0017770234262570739f, 0.0018426267197355628f, 0.0018545043421909213f, 0.0020287116058170795f, 0.001743348897434771f, 0.0029872783925384283f, 0.0015686320839449763f, 0.001689382130280137f, 0.002007110044360161f, 0.001379443914629519f, 0.0016318290727213025f, 0.0014986161841079593f, 0.001573992776684463f, 0.0016976185142993927f, 0.001773667405359447f, 0.00175941688939929f, 0.002675747498869896f, 0.0023492081090807915f, 0.001553002162836492f, 0.00199627666734159f, 0.0017210824880748987f, 0.0013980157673358917f, 0.0016077222535386682f, 0.0013623040867969394f, 0.0012489687651395798f, 0.001570436405017972f, 0.0017298470484092832f, 0.0012499348958954215f, 0.0019167157588526607f, 0.0016415431164205074f, 0.0014681527391076088f, 0.0016726445173844695f, 0.001713331788778305f, 0.0017968177562579513f, 0.001410424942150712f, 0.0016996576450765133f, 0.0012673774035647511f, 0.0013422833289951086f, 0.001224943553097546f, 0.0013852600241079926f, 0.0015159406466409564f, 0.0019654729403555393f, 0.0023192823864519596f, 0.0014193163951858878f, 0.0014144727028906345f, 0.0021205616649240255f, 0.0013813346158713102f, 0.0016967960400506854f, 0.001561617711558938f, 0.0018379819812253118f, 0.0015746974386274815f, 0.0016402597539126873f, 0.0016593842301517725f, 0.001523343613371253f, 0.0014413835015147924f, 0.0017515734070912004f, 0.002112808870151639f, 0.001797123928554356f, 0.0014659733278676867f, 0.0013097848277539015f, 0.0019052973948419094f, 0.0018436674727126956f, 0.002422188175842166f, 0.0012253813911229372f, 0.0026930079329758883f, 0.0020958920940756798f, 0.0021059203427284956f, 0.0016128676943480968f, 0.0023647795896977186f, 0.0012543518096208572f, 0.0009651125292293727f, 0.0013246643356978893f, 0.0016799063887447119f, 0.0018695537000894547f, 0.002445860533043742f, 0.002682965248823166f, 0.0010779736330732703f, 0.001294307061471045f, 0.0019981125369668007f, 0.0016045448137447238f, 0.002198511967435479f, 0.002213164232671261f, 0.0018111594254150987f, 0.0014521137345582247f, 0.0017004654509946704f, 0.0018613528227433562f, 0.001488763839006424f, 0.0023509140592068434f, 0.0014601066941395402f, 0.0012111426331102848f, 0.002321285894140601f, 0.002186545869335532f, 0.0014776202151551843f, 0.002185903489589691f, 0.001871169894002378f, 0.0012666018446907401f, 0.001490814029239118f, 0.0016747681656852365f, 0.0019068514229729772f, 0.0016982619417831302f, 0.0016098774503916502f, 0.002062786603346467f, 0.0016423279885202646f, 0.00157381989993155f, 0.0011510526528581977f, 0.0015749594895169139f, 0.0018341840477660298f, 0.002034272998571396f, 0.0019984738901257515f, 0.0013889740221202374f, 0.0018213423900306225f, 0.0017048123991116881f, 0.0021673706360161304f, 0.0022343716118484735f, 0.0013409147504717112f, 0.0020972902420908213f, 0.0017360306810587645f, 0.001751425676047802f, 0.001807387568987906f, 0.0019841499160975218f, 0.0012308931909501553f, 0.0020654541440308094f, 0.0019101204816251993f, 0.0020395005121827126f, 0.0015944783808663487f, 0.001979209017008543f, 0.002100219251587987f, 0.0016544002573937178f, 0.0015636889729648829f, 0.0018999010790139437f, 0.0016057264292612672f, 0.0016277686227113008f, 0.0022358736023306847f, 0.001581283169798553f, 0.0027588477823883295f, 0.0023684988263994455f, 0.0014163483865559101f, 0.0014044394483789802f, 0.0016012449050322175f, 0.0018053401727229357f, 0.0015768051380291581f, 0.0018683314556255937f, 0.001980068162083626f, 0.0016004859935492277f, 0.0013333359966054559f, 0.0016934098675847054f, 0.002397219417616725f, 0.0012613136786967516f, 0.0019669728353619576f, 0.0013432156993076205f, 0.0013502704678103328f, 0.0014610042562708259f, 0.0020918434020131826f, 0.0026839959900826216f, 0.001558411750011146f, 0.0017583246808499098f, 0.001279399381019175f, 0.0015676708426326513f, 0.0017706056823953986f, 0.0016946684336289763f, 0.0015146431978791952f, 0.0014351133722811937f, 0.003907657228410244f, 0.0014782240614295006f, 0.0009869203204289079f, 0.002232427941635251f, 0.00209418754093349f, 0.00153167056851089f, 0.001922577852383256f, 0.0020106325391680002f, 0.001953062484972179f, 0.0024648448452353477f, 0.002103970153257251f, 0.001767431735061109f, 0.0016290658386424184f, 0.0014212768292054534f, 0.0017960388213396072f, 0.0016753049567341805f, 0.0015162903582677245f, 0.0018109262455254793f, 0.0016213941853493452f, 0.0017025407869368792f, 0.0021019300911575556f, 0.001848690677434206f, 0.0018511699745431542f, 0.0026723169721663f, 0.0025219209492206573f, 0.0015079645672813058f, 0.0023874016478657722f, 0.0017750001279637218f, 0.0016024843789637089f, 0.0016717364778742194f, 0.0013533267192542553f, 0.001969045726582408f, 0.0019048805115744472f, 0.0019515050807967782f, 0.00154054572340101f, 0.0015496218111366034f, 0.0015238726045936346f, 0.0013891130220144987f, 0.0019304553279653192f, 0.0014028723817318678f, 0.0014172132359817624f, 0.0017694749403744936f, 0.002163859084248543f, 0.0018759469967335463f, 0.0013451222330331802f, 0.0023634338285773993f, 0.0014363626250997186f, 0.0018761286046355963f, 0.0012764056446030736f, 0.0013145437696948647f, 0.002032265532761812f, 0.001436877646483481f, 0.0019178615184500813f, 0.0015851689968258142f, 0.0013083470985293388f, 0.001323508913628757f, 0.0013297946425154805f, 0.0014550240011885762f, 0.0015934372786432505f, 0.0019601325038820505f, 0.0019861168693751097f, 0.0018348217708989978f, 0.0017961239209398627f, 0.0013090636348351836f, 0.0013001990737393498f, 0.0012518223375082016f, 0.002743867225944996f, 0.002129550091922283f, 0.001851538079790771f, 0.0014769595582038164f, 0.0010625929571688175f, 0.001817919546738267f, 0.0011372835142537951f, 0.0019440329633653164f, 0.0018563312478363514f, 0.0020186554174870253f, 0.0014793600421398878f, 0.002227402525022626f, 0.0015287703135982156f, 0.0022664200514554977f, 0.0014958387473598123f, 0.001750603667460382f, 0.0017788215773180127f, 0.0014269696548581123f, 0.0013349021319299936f, 0.0016016984591260552f, 0.001962369540706277f, 0.001414208090864122f, 0.0014413552125915885f, 0.001627504825592041f, 0.001973941456526518f, 0.0027207662351429462f, 0.0024098551366478205f, 0.0022806760389357805f, 0.001619811519049108f, 0.0016602427931502461f, 0.002483034273609519f, 0.0016694259829819202f, 0.0032220471184700727f, 0.0016238900134339929f, 0.0015337830409407616f, 0.0013649279717355967f, 0.0017496033105999231f, 0.0014905421994626522f, 0.001620759954676032f, 0.0017657600110396743f, 0.0014257064322009683f, 0.0015084861079230905f, 0.0013814029516652226f, 0.002452526241540909f, 0.0015247068367898464f, 0.0018341997638344765f, 0.002072937088087201f, 0.0017358394106850028f, 0.0020794749725610018f, 0.0018657654291018844f, 0.0020118700340390205f, 0.0025438587181270123f, 0.0024714104365557432f, 0.0017245679628103971f, 0.001806337502785027f, 0.0011756591266021132f, 0.0019657148513942957f, 0.0022972666192799807f, 0.0013069160049781203f, 0.0012868698686361313f, 0.001360535155981779f, 0.0015273871831595898f, 0.0016420563915744424f, 0.0014310271944850683f, 0.0014907916774973273f, 0.0014667046489194036f, 0.0015470656799152493f, 0.0017500651301816106f, 0.0014887568540871143f, 0.0023719370365142822f, 0.0014543759170919657f, 0.001811616588383913f, 0.0019250345649197698f, 0.0014904376585036516f, 0.0017810314893722534f, 0.0014462110120803118f, 0.0014424626715481281f, 0.002004856476560235f, 0.0016626318683847785f, 0.0013248540926724672f, 0.001413713558577001f, 0.0014099697582423687f, 0.0016173555050045252f, 0.0016643370036035776f, 0.002205262891948223f, 0.0016336875269189477f, 0.0018425327725708485f, 0.002102572238072753f, 0.002406478626653552f, 0.002138841897249222f, 0.0016620326787233353f, 0.0016313694650307298f, 0.0012323482660576701f, 0.0021272061858326197f, 0.0016152551397681236f, 0.0022402273025363684f, 0.0015153458807617426f, 0.0016874580178409815f, 0.0023617050610482693f, 0.001909611513838172f, 0.00209999131038785f, 0.002196256071329117f, 0.0015263912500813603f, 0.0015717869391664863f, 0.0012583887437358499f, 0.001597272465005517f, 0.0014699680032208562f, 0.0014277450973168015f, 0.0019060112535953522f, 0.0018497270066291094f, 0.0015559804160147905f, 0.0013338138815015554f, 0.001379505731165409f, 0.0014918019296601415f, 0.001397899235598743f, 0.0018880241550505161f, 0.001606410602107644f, 0.0017054795753210783f, 0.0015317375073209405f, 0.002039572922512889f, 0.0015954201808199286f, 0.001345004653558135f, 0.0017317510209977627f, 0.0017793106380850077f, 0.0017705044010654092f, 0.001274865004234016f, 0.0011825872352346778f, 0.0023108243476599455f, 0.001297829207032919f, 0.0015494400868192315f, 0.0014149593189358711f, 0.0018189570400863886f, 0.0019464045763015747f, 0.0024246578104794025f, 0.0015674440655857325f, 0.0020090800244361162f, 0.00161200191359967f, 0.001164160785265267f, 0.0023992194328457117f, 0.0013916647294536233f, 0.0021983387414366007f, 0.0014480776153504848f, 0.0014079820830374956f, 0.0015296356286853552f, 0.0023504220880568027f, 0.0012423961888998747f, 0.0013450582046061754f, 0.0014576070243492723f, 0.0015750547172501683f, 0.0011225129710510373f, 0.002310090232640505f, 0.001476743258535862f, 0.0012463259045034647f, 0.0019510900601744652f, 0.0015753537882119417f, 0.0010696976678445935f, 0.0020591251086443663f, 0.0014590516220778227f, 0.0015253311721608043f, 0.0015365772414952517f, 0.0016257615061476827f, 0.0022074333392083645f, 0.0014274228597059846f, 0.002274672966450453f, 0.002341420389711857f, 0.0026807375252246857f, 0.0011049071326851845f, 0.0014204479521140456f, 0.0014471301110461354f, 0.001616228953935206f, 0.0017647827044129372f, 0.001331036677584052f, 0.002077719196677208f, 0.0025342393200844526f, 0.0017576124519109726f, 0.0014475893694907427f, 0.001201069913804531f, 0.0014726452063769102f, 0.001577051356434822f, 0.001772005925886333f, 0.0013334988616406918f, 0.0013057340402156115f, 0.001397064421325922f, 0.0022625322453677654f, 0.001276919967494905f, 0.001729217474348843f, 0.0014810520224273205f, 0.002502995077520609f, 0.0013162344694137573f, 0.0013242834247648716f, 0.0011584294261410832f, 0.0019900957122445107f, 0.0011766531970351934f, 0.0011031487956643105f, 0.0016685236478224397f, 0.001564549165777862f, 0.0016153694596141577f, 0.0012807234888896346f, 0.0026007492560893297f, 0.0017209005309268832f, 0.0016940018394961953f, 0.001391292898915708f, 0.0013420312898233533f, 0.002815029351040721f, 0.001563441357575357f, 0.0016166697023436427f, 0.0014530381886288524f, 0.001769465277902782f, 0.001573694869875908f, 0.0019205926219001412f, 0.0022449460811913013f, 0.0024938129354268312f, 0.0014676678692921996f, 0.0017236275598406792f, 0.0014431083109229803f, 0.0012396028032526374f, 0.0014436296187341213f, 0.001823599450290203f, 0.001687217503786087f, 0.0019005226204171777f, 0.002023387001827359f, 0.0014810067368671298f, 0.0015588223468512297f, 0.0012235227040946484f, 0.0014842943055555224f, 0.0020592722576111555f, 0.002222058828920126f, 0.00126420590095222f, 0.0015812695492058992f, 0.0021638968028128147f, 0.0020309300161898136f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #251 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018062283925246447f, 0.0002848189906217158f, 0.00039276707684621215f, 0.00015046820044517517f, 0.00014619113062508404f, 0.00023697952565271407f, 0.0003781544219236821f, 0.0002799142384901643f, 0.00020851004228461534f, 0.0002313034055987373f, 0.00016720802523195744f, 0.0001978590589715168f, 0.00019711462664417922f, 0.00029384769732132554f, 0.00026705150958150625f, 0.00027436064556241035f, 0.0001768273941706866f, 0.00017452177416998893f, 0.0001930614234879613f, 0.0001621711126063019f, 0.00022301459102891386f, 0.00023914406483527273f, 0.00017767037206795067f, 0.0003091168764512986f, 0.00022881204495206475f, 0.00034670039894990623f, 0.00030093378154560924f, 0.00023961163242347538f, 0.00020466078422032297f, 0.0002093313669320196f, 0.0002616117417346686f, 0.00018736567290034145f, 0.0003541767946444452f, 0.00039867794839665294f, 0.00024211629352066666f, 0.00019032382988370955f, 0.00026493851328268647f, 0.0001977024512598291f, 0.00017567447503097355f, 0.00037564249942079186f, 0.0002014690835494548f, 0.0002725462836679071f, 0.00040443672332912683f, 0.00023805585806258023f, 0.00024600751930847764f, 0.00021858418767806143f, 0.0002815210318658501f, 0.00035012373700737953f, 0.00014866636774968356f, 0.00021038544946350157f, 0.00018277975323144346f, 0.0001554970076540485f, 0.00022796908160671592f, 0.0003969749959651381f, 0.00020222571038175374f, 0.00020358015899546444f, 0.00015031297516543418f, 0.0002448156592436135f, 0.00015434258966706693f, 0.000283541769022122f, 0.00030027260072529316f, 0.00025793607346713543f, 0.00028152469894848764f, 0.00018025454482994974f, 0.00025600139633752406f, 0.00015198305482044816f, 0.00013679999392479658f, 0.0002656595315784216f, 0.00020407022384461015f, 0.0002164444886147976f, 0.00018369201279710978f, 0.0002443870180286467f, 0.00016204513667616993f, 0.000282123452052474f, 0.00021755827765446156f, 0.00017297457088716328f, 0.0004572945472318679f, 0.0002562702866271138f, 0.00023915438214316964f, 0.00025690835900604725f, 0.0003935099521186203f, 0.00039737700717523694f, 0.000337487697834149f, 0.00016929639969021082f, 0.0004351126844994724f, 0.00023622639128006995f, 0.00020434516773093492f, 0.00026814936427399516f, 0.0003373672370798886f, 0.0001734711549943313f, 0.00042510844650678337f, 0.0002606380148790777f, 0.00020782373030669987f, 0.00020485832646954805f, 0.0002383858518442139f, 0.0002555288083385676f, 0.00020086341828573495f, 0.00020052290346939117f, 0.0002482376585248858f, 0.000286819034954533f, 0.00028946856036782265f, 0.00015356023504864424f, 0.00020844160462729633f, 0.0001410742843290791f, 0.00024137611035257578f, 0.00029809767147526145f, 0.0001562232937430963f, 0.000166498648468405f, 0.0002915977966040373f, 0.00020391499856486917f, 0.0005225309869274497f, 0.00027769326698035f, 0.00036254693986847997f, 0.00016981120279524475f, 0.00029596223612315953f, 0.00033602124312892556f, 0.00017179350834339857f, 0.0002041250845650211f, 0.0002211065439041704f, 0.000321787636494264f, 0.00048253178829327226f, 0.0002316722966497764f, 0.0002556573017500341f, 0.00037462610634975135f, 0.00027757190400734544f, 0.00013428636884782463f, 0.00019333591626491398f, 0.0002326164103578776f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #252 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_68_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036176182329654694f, 0.004149295389652252f, 0.004775478038936853f, 0.004195628687739372f, 0.006213230546563864f, 0.003933001309633255f, 0.0044595832005143166f, 0.00426565483212471f, 0.0036182233598083258f, 0.007360598538070917f, 0.006841546855866909f, 0.004027109593153f, 0.002848350442945957f, 0.0035458269994705915f, 0.004945301450788975f, 0.0034619588404893875f, 0.003818703582510352f, 0.008325469680130482f, 0.005756257567554712f, 0.002425343729555607f, 0.003455533180385828f, 0.005386783741414547f, 0.007998677901923656f, 0.005750633310526609f, 0.004285706207156181f, 0.004064195789396763f, 0.008614443242549896f, 0.0032921629026532173f, 0.004065346904098988f, 0.003078446490690112f, 0.006379168946295977f, 0.007094199303537607f, 0.003302257740870118f, 0.003976448439061642f, 0.005983003415167332f, 0.0033266593236476183f, 0.0034400576259940863f, 0.0037222125101834536f, 0.00654636463150382f, 0.00404288899153471f, 0.0067870886996388435f, 0.004500176757574081f, 0.0034562142100185156f, 0.0038923220708966255f, 0.006598128937184811f, 0.0032344532664865255f, 0.005355499684810638f, 0.00346763851121068f, 0.005404269322752953f, 0.005621646996587515f, 0.005484029185026884f, 0.0032519071828573942f, 0.007759811356663704f, 0.005025507882237434f, 0.006629275623708963f, 0.004208603408187628f, 0.002896272111684084f, 0.009155330248177052f, 0.00475148344412446f, 0.004066844936460257f, 0.005167586728930473f, 0.005823100917041302f, 0.0035338967572897673f, 0.0027594093699008226f, 0.006745256017893553f, 0.005805017426609993f, 0.006515656132251024f, 0.0035071454476565123f, 0.0061645908281207085f, 0.004446962382644415f, 0.003916533198207617f, 0.0060879881493747234f, 0.006185024511069059f, 0.0042017786763608456f, 0.003558905329555273f, 0.0038958347868174314f, 0.006551201455295086f, 0.006790520157665014f, 0.005626067519187927f, 0.00639717373996973f, 0.006323742214590311f, 0.004336275160312653f, 0.00640652934089303f, 0.006493956781923771f, 0.0030255357269197702f, 0.003608494298532605f, 0.005783848464488983f, 0.004189628642052412f, 0.005578749347478151f, 0.0034490874968469143f, 0.0028410900849848986f, 0.005300587508827448f, 0.00442128349095583f, 0.0031885660719126463f, 0.004415533971041441f, 0.005091921892017126f, 0.007159780245274305f, 0.0052905455231666565f, 0.004410651046782732f, 0.004836615640670061f, 0.00510638440027833f, 0.005645636934787035f, 0.003086383920162916f, 0.003088005818426609f, 0.007725181058049202f, 0.004317876882851124f, 0.008288155309855938f, 0.007284661289304495f, 0.0052047171629965305f, 0.0065458836033940315f, 0.0028470170218497515f, 0.0040868911892175674f, 0.00324463052675128f, 0.006016007158905268f, 0.007700607180595398f, 0.005683647468686104f, 0.003883998841047287f, 0.0036848154850304127f, 0.010371075943112373f, 0.005796345416456461f, 0.0032091503962874413f, 0.006819136906415224f, 0.005766613874584436f, 0.007061941549181938f, 0.004952381830662489f, 0.00688704801723361f, 0.005682563874870539f, 0.0026143782306462526f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #253 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_69_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014678877778351307f, 0.0016811710083857179f, 0.0010731547372415662f, 0.0005404276889748871f, 0.0020278412848711014f, 0.000950269924942404f, 0.0012158453464508057f, 0.0007671292405575514f, 0.0015551974065601826f, 0.0020168095361441374f, 0.0010110600851476192f, 0.0010059250053018332f, 0.00056644988944754f, 0.0012036864645779133f, 0.0005072556668892503f, 0.001480844453908503f, 0.0021071983501315117f, 0.0005318717448972166f, 0.0012233994202688336f, 0.0006353763747029006f, 0.0009807248134166002f, 0.0012798771494999528f, 0.001112222671508789f, 0.0007297353004105389f, 0.0013952732551842928f, 0.0008041784749366343f, 0.0012859652051702142f, 0.0012367421295493841f, 0.0011994608212262392f, 0.0009283081162720919f, 0.0014046032447367907f, 0.0013566436246037483f, 0.0010299752466380596f, 0.0008508958271704614f, 0.00149729719851166f, 0.0005983673618175089f, 0.0014731140108779073f, 0.001294462475925684f, 0.0009260635124519467f, 0.0011473229387775064f, 0.001055870670825243f, 0.0006833262159489095f, 0.0012985032517462969f, 0.0010307361371815205f, 0.0014129446353763342f, 0.0009850617498159409f, 0.0005375774344429374f, 0.0008491156040690839f, 0.0014192647067829967f, 0.0009143073693849146f, 0.0010264297015964985f, 0.001475398545153439f, 0.0010242407443001866f, 0.0011231029639020562f, 0.0013499987544491887f, 0.0021328607108443975f, 0.0016312713269144297f, 0.0014332671416923404f, 0.0005650289240293205f, 0.0017032932955771685f, 0.0016220348188653588f, 0.0010775409173220396f, 0.0009344063000753522f, 0.0015305698616430163f, 0.0015745162963867188f, 0.00197557988576591f, 0.0007187619339674711f, 0.0011134882224723697f, 0.0008408326539210975f, 0.0011451649479568005f, 0.001675611361861229f, 0.0013770096702501178f, 0.001485301647335291f, 0.0016006326768547297f, 0.0011129318736493587f, 0.0007807104848325253f, 0.0005852337344549596f, 0.0008033884223550558f, 0.0007421233458444476f, 0.0011265238281339407f, 0.0006997500313445926f, 0.0020183748565614223f, 0.0012470795772969723f, 0.001355920103378594f, 0.0014964626170694828f, 0.0013804966583848f, 0.0012950514210388064f, 0.0012506218627095222f, 0.0009763558045960963f, 0.0009728267905302346f, 0.0014759022742509842f, 0.0008610363584011793f, 0.0013450294500216842f, 0.0012260274961590767f, 0.0013055386953055859f, 0.0008200493175536394f, 0.0015743047697469592f, 0.0005776542238891125f, 0.0006409906782209873f, 0.001505521358922124f, 0.0018017601687461138f, 0.0011584798339754343f, 0.0013537777122110128f, 0.0014361917274072766f, 0.0009310333989560604f, 0.000993757857941091f, 0.0010663589928299189f, 0.0016657550586387515f, 0.001332466839812696f, 0.001489262212999165f, 0.0007131278398446739f, 0.0009899771539494395f, 0.0007770180236548185f, 0.0012893371749669313f, 0.0011490235337987542f, 0.0013504715170711279f, 0.0005263107013888657f, 0.0010727421613410115f, 0.0015596929006278515f, 0.000928517198190093f, 0.0016353140817955136f, 0.0015370569890365005f, 0.0011159422574564815f, 0.0007600014796480536f, 0.00058476731646806f, 0.0015535495476797223f, 0.0010928066913038492f, 0.0014707634691148996f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #254 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_70_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008122959174215794f, 0.004057646729052067f, 0.010327463038265705f, 0.006483434699475765f, 0.01042857300490141f, 0.006076130084693432f, 0.0060111223720014095f, 0.005215792451053858f, 0.006614247336983681f, 0.0063310363329946995f, 0.00654869619756937f, 0.010206039994955063f, 0.003478872124105692f, 0.006233798805624247f, 0.004537581000477076f, 0.006320654880255461f, 0.010820741765201092f, 0.005232075694948435f, 0.007653386332094669f, 0.005595236551016569f, 0.008831578306853771f, 0.008936181664466858f, 0.012247417122125626f, 0.004388102795928717f, 0.005313164554536343f, 0.008741522207856178f, 0.009028658270835876f, 0.005547867156565189f, 0.008242434822022915f, 0.006096409168094397f, 0.008947149850428104f, 0.005724371876567602f, 0.007134041283279657f, 0.007868356071412563f, 0.012365296483039856f, 0.006894814781844616f, 0.008107907138764858f, 0.009030343033373356f, 0.0058637987822294235f, 0.014344914816319942f, 0.010961154475808144f, 0.005433371290564537f, 0.003953292965888977f, 0.003986821044236422f, 0.005706823896616697f, 0.006311019416898489f, 0.0063111442141234875f, 0.005050537642091513f, 0.0068894014693796635f, 0.007197897415608168f, 0.008189184591174126f, 0.01198540534824133f, 0.006794222164899111f, 0.011437848210334778f, 0.0071256267838180065f, 0.0073303766548633575f, 0.006472354754805565f, 0.007510059047490358f, 0.0034728320315480232f, 0.0064726779237389565f, 0.015027460642158985f, 0.013339933007955551f, 0.004823070950806141f, 0.007865571416914463f, 0.0068546487018466f, 0.007966355420649052f, 0.005209721624851227f, 0.008228790014982224f, 0.005467341747134924f, 0.008027126081287861f, 0.009174481965601444f, 0.010918007232248783f, 0.006799325346946716f, 0.006858253385871649f, 0.0044397893361747265f, 0.007796543650329113f, 0.008104439824819565f, 0.010818892158567905f, 0.00872726459056139f, 0.007518593221902847f, 0.006097205448895693f, 0.010123939253389835f, 0.007747390773147345f, 0.010669062845408916f, 0.01272490993142128f, 0.007580989971756935f, 0.007782552391290665f, 0.01049014087766409f, 0.005495327524840832f, 0.007160425651818514f, 0.008862916380167007f, 0.006797329988330603f, 0.006562238559126854f, 0.006594821810722351f, 0.00623614015057683f, 0.0053335027769207954f, 0.00875516515225172f, 0.005154394544661045f, 0.006343904882669449f, 0.00518763717263937f, 0.009625270031392574f, 0.008415739051997662f, 0.004839313682168722f, 0.00814011599868536f, 0.006696504075080156f, 0.007889248430728912f, 0.007028400897979736f, 0.010497916489839554f, 0.008586376905441284f, 0.005189764313399792f, 0.003730242373421788f, 0.008754529058933258f, 0.0036086353939026594f, 0.007782229222357273f, 0.0050805495120584965f, 0.008129280991852283f, 0.006278351414948702f, 0.0063305324874818325f, 0.006624853238463402f, 0.00484590046107769f, 0.008521633222699165f, 0.005244947038590908f, 0.0042772311717271805f, 0.007640053518116474f, 0.00606099609285593f, 0.007570508401840925f, 0.006160000804811716f, 0.01196526363492012f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #255 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_71_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001191318267956376f, 0.0015610548434779048f, 0.0012786837760359049f, 0.001510081929154694f, 0.0008372449083253741f, 0.001013497938401997f, 0.0016538719646632671f, 0.002071320777758956f, 0.0010181305697187781f, 0.0019362946040928364f, 0.0017579665873199701f, 0.001811656984500587f, 0.0008198348223231733f, 0.0016994832549244165f, 0.0007464255904778838f, 0.0015129261882975698f, 0.0015931075904518366f, 0.0012243784731253982f, 0.0007850766414776444f, 0.0015528092626482248f, 0.002046869834885001f, 0.002010111231356859f, 0.001286101876758039f, 0.0023436504416167736f, 0.001371180173009634f, 0.002052437514066696f, 0.0016660182736814022f, 0.002234404906630516f, 0.0016680529806762934f, 0.002256284933537245f, 0.0014973214128986f, 0.0006954203709028661f, 0.0011416064808145165f, 0.0018735888879746199f, 0.0016577525530010462f, 0.0006793274078518152f, 0.0016307492041960359f, 0.0013057872420176864f, 0.0009326604777015746f, 0.001403094152919948f, 0.0020186027977615595f, 0.0007564371917396784f, 0.001614361652173102f, 0.0009950747480615973f, 0.0014413585886359215f, 0.0008499122341163456f, 0.0013738583074882627f, 0.0018387073650956154f, 0.001558627118356526f, 0.0018974397098645568f, 0.001228998531587422f, 0.001386042102240026f, 0.0019972617737948895f, 0.0008438650984317064f, 0.0010454596485942602f, 0.001785352942533791f, 0.0009042368037626147f, 0.0009708948782645166f, 0.0018325236160308123f, 0.0009898509597405791f, 0.0013761344598606229f, 0.0018110106466338038f, 0.0017732980195432901f, 0.000495600572321564f, 0.0011880742385983467f, 0.0019455674337223172f, 0.0007617339724674821f, 0.0011998382396996021f, 0.0015284926630556583f, 0.001633091946132481f, 0.0018264034297317266f, 0.0014328580582514405f, 0.001305927406065166f, 0.0018209159607067704f, 0.0011447543511167169f, 0.0005152444937266409f, 0.0010444403160363436f, 0.002065708627924323f, 0.0010926154209300876f, 0.0014677353901788592f, 0.0005582197918556631f, 0.001970444805920124f, 0.0018679797649383545f, 0.0015353154158219695f, 0.0008151272195391357f, 0.0013853764394298196f, 0.003010339802131057f, 0.0009256908087991178f, 0.0016934756422415376f, 0.0016069518169388175f, 0.0008133332594297826f, 0.001998989610001445f, 0.002238153712823987f, 0.0016051664715632796f, 0.0016983543755486608f, 0.0009377627284266055f, 0.0015069120563566685f, 0.0007795128622092307f, 0.002386125037446618f, 0.0009379267576150596f, 0.000758262409362942f, 0.0014637087006121874f, 0.0018553845584392548f, 0.0016745644388720393f, 0.0011462484253570437f, 0.0003786638262681663f, 0.0010203319834545255f, 0.0022193994373083115f, 0.0023235382977873087f, 0.0019049433758482337f, 0.0007291007786989212f, 0.0015699496725574136f, 0.0008551670471206307f, 0.0017775963060557842f, 0.0010597110958769917f, 0.0015758068766444921f, 0.0017182411393150687f, 0.0019485338125377893f, 0.0005667770747095346f, 0.0008993423543870449f, 0.0013002852210775018f, 0.0016110745491459966f, 0.0012903169263154268f, 0.000870929507073015f, 0.001407132251188159f, 0.0019665516447275877f, 0.0012638544430956244f, 0.001109226606786251f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #256 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_72_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0059419600293040276f, 0.005754048004746437f, 0.008672882802784443f, 0.007183506619185209f, 0.003921034745872021f, 0.006818348076194525f, 0.00525933550670743f, 0.00416136858984828f, 0.004476939793676138f, 0.010179635137319565f, 0.00443431967869401f, 0.006472704000771046f, 0.0048559848219156265f, 0.013730914331972599f, 0.0049908035434782505f, 0.009819965809583664f, 0.006154173985123634f, 0.009804953821003437f, 0.004998895339667797f, 0.010860847309231758f, 0.007357968483120203f, 0.004755083937197924f, 0.008642654865980148f, 0.0065818047150969505f, 0.00672535877674818f, 0.008497742004692554f, 0.006727293599396944f, 0.006649170070886612f, 0.006217780988663435f, 0.0072998227551579475f, 0.00778230233117938f, 0.005941828712821007f, 0.009786547161638737f, 0.00907919555902481f, 0.006914783734828234f, 0.004611059091985226f, 0.006089183501899242f, 0.007750716060400009f, 0.008797508664429188f, 0.011795945465564728f, 0.006167648825794458f, 0.00649301940575242f, 0.005383062642067671f, 0.00542474165558815f, 0.007047460414469242f, 0.005860114935785532f, 0.004056339152157307f, 0.006229735910892487f, 0.008230873383581638f, 0.008788718841969967f, 0.010339928790926933f, 0.010865931399166584f, 0.007844721898436546f, 0.003691727062687278f, 0.008137650787830353f, 0.00690179318189621f, 0.006373058073222637f, 0.011895960196852684f, 0.008689827285706997f, 0.004388599190860987f, 0.005873886402696371f, 0.004467471968382597f, 0.009689408354461193f, 0.005250830668956041f, 0.006296675186604261f, 0.006980856880545616f, 0.0056262388825416565f, 0.008958462625741959f, 0.00722450902685523f, 0.011609457433223724f, 0.00778660923242569f, 0.011277765035629272f, 0.010323816910386086f, 0.010160664096474648f, 0.0054121846333146095f, 0.006178613286465406f, 0.005913892760872841f, 0.008586034178733826f, 0.0050080944783985615f, 0.010133274830877781f, 0.005564590450376272f, 0.0066580986604094505f, 0.007985785603523254f, 0.00792938843369484f, 0.006198273506015539f, 0.006002173759043217f, 0.009289128705859184f, 0.005911818705499172f, 0.006963695865124464f, 0.008192944340407848f, 0.006355283781886101f, 0.010085482150316238f, 0.007594353519380093f, 0.009066625498235226f, 0.00654132105410099f, 0.007725585252046585f, 0.006755703594535589f, 0.006074818316847086f, 0.008491951040923595f, 0.00840555690228939f, 0.006644995883107185f, 0.0051834117621183395f, 0.01162349060177803f, 0.01094399020075798f, 0.005080106668174267f, 0.007924173027276993f, 0.006675416603684425f, 0.0076708015985786915f, 0.0041698310524225235f, 0.007538739126175642f, 0.007366419304162264f, 0.010326504707336426f, 0.009536506608128548f, 0.004957945551723242f, 0.005168599542230368f, 0.017010388895869255f, 0.013588312081992626f, 0.007898024283349514f, 0.004449419677257538f, 0.00574357807636261f, 0.009625525213778019f, 0.012774745002388954f, 0.005478656385093927f, 0.008678107522428036f, 0.007354403380304575f, 0.018154704943299294f, 0.00817460473626852f, 0.011630812659859657f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #257 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_73_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0016843111952766776f, 0.0006073518306948245f, 0.0016003366326913238f, 0.0012246514670550823f, 0.001069646910764277f, 0.0005394769250415266f, 0.0006013094680383801f, 0.0014588059857487679f, 0.0008927532471716404f, 0.0011518050450831652f, 0.0005997482221573591f, 0.0006544897914864123f, 0.000618396676145494f, 0.0008447692962363362f, 0.00172826845664531f, 0.00046960703912191093f, 0.001141942571848631f, 0.0007075166213326156f, 0.0024212889838963747f, 0.0018348094308748841f, 0.0005226072971709073f, 0.0012764068087562919f, 0.0009032381931319833f, 0.0011673590634018183f, 0.0011965736048296094f, 0.00041870205313898623f, 0.0016862046904861927f, 0.0010677296668291092f, 0.0014689553063362837f, 0.0009939557639881968f, 0.0018547249492257833f, 0.000824028451461345f, 0.0003460200096014887f, 0.0016343329334631562f, 0.0014549311017617583f, 0.0011773895239457488f, 0.0013720085844397545f, 0.0015726073179394007f, 0.0007456277380697429f, 0.0013885305961593986f, 0.001525441068224609f, 0.000687762803863734f, 0.0018661528592929244f, 0.0008593457750976086f, 0.0010904375230893493f, 0.0004510658618528396f, 0.0014345386298373342f, 0.0015084294136613607f, 0.00201053568162024f, 0.0012021403526887298f, 0.0011298524914309382f, 0.0011216579005122185f, 0.0011086433660238981f, 0.0017626808257773519f, 0.0005133167724125087f, 0.001526217325590551f, 0.0009054507245309651f, 0.0014316309243440628f, 0.0008859679801389575f, 0.0015455291140824556f, 0.001850023283623159f, 0.0015801152912899852f, 0.0006429656059481204f, 0.001357829081825912f, 0.0005447836010716856f, 0.0007426349329762161f, 0.0015297761419788003f, 0.0014355835737660527f, 0.0019325341563671827f, 0.0019247062737122178f, 0.0015763307455927134f, 0.0016753405798226595f, 0.0013436709996312857f, 0.00161853083409369f, 0.0006817160174250603f, 0.0012811818160116673f, 0.0016792438691481948f, 0.001226698630489409f, 0.0008402790990658104f, 0.0019544304814189672f, 0.0006280058878473938f, 0.001348806545138359f, 0.0022571689914911985f, 0.0009419886046089232f, 0.0017262609908357263f, 0.002190378261730075f, 0.0009829059708863497f, 0.002024548826739192f, 0.001534553593955934f, 0.0012848378391936421f, 0.0007653551874682307f, 0.0008474876522086561f, 0.001106171403080225f, 0.0011658709263429046f, 0.0003751488693524152f, 0.0005738507024943829f, 0.0023646787740290165f, 0.0015143887139856815f, 0.0007020607590675354f, 0.0010064681991934776f, 0.0016635953215882182f, 0.0011753069702535868f, 0.0017866181442514062f, 0.0012223825324326754f, 0.0008957151439972222f, 0.001365270814858377f, 0.0007275206735357642f, 0.0005475078942254186f, 0.0016756067052483559f, 0.0007685961318202317f, 0.0019814290571957827f, 0.0009062847238965333f, 0.0013030850095674396f, 0.0007984224357642233f, 0.0014891019091010094f, 0.0007839349564164877f, 0.0015695947222411633f, 0.0003168534894939512f, 0.0011097453534603119f, 0.0005789435235783458f, 0.0009751715697348118f, 0.0011905161663889885f, 0.0021979904267936945f, 0.0016722988802939653f, 0.001028222031891346f, 0.0004288897034712136f, 0.00285527016967535f, 0.0006083836778998375f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #258 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_74_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006463006604462862f, 0.0060830800794065f, 0.014637477695941925f, 0.0034793775994330645f, 0.009313256479799747f, 0.006922483444213867f, 0.00527985068038106f, 0.008054674603044987f, 0.004383193328976631f, 0.012222964316606522f, 0.0056832898408174515f, 0.0069792927242815495f, 0.005132520105689764f, 0.0055788615718483925f, 0.007152122911065817f, 0.0043753827922046185f, 0.008521758951246738f, 0.00347775686532259f, 0.007033505477011204f, 0.00996510311961174f, 0.005251836031675339f, 0.006257048808038235f, 0.0048522683791816235f, 0.023271439597010612f, 0.009496664628386497f, 0.005743235815316439f, 0.004932731855660677f, 0.00469172652810812f, 0.005210002884268761f, 0.006127447355538607f, 0.004332662560045719f, 0.006589130964130163f, 0.005796876735985279f, 0.0056209871545434f, 0.014076288789510727f, 0.005116966553032398f, 0.005978605709969997f, 0.008440924808382988f, 0.005708327516913414f, 0.007496034726500511f, 0.012965081259608269f, 0.007382505107671022f, 0.006023061461746693f, 0.005756740923970938f, 0.004754443187266588f, 0.00391189381480217f, 0.012145276181399822f, 0.008867787197232246f, 0.006444908678531647f, 0.01030787080526352f, 0.003947206772863865f, 0.005016381852328777f, 0.0061065517365932465f, 0.00660031707957387f, 0.006112692411988974f, 0.00586911803111434f, 0.007230883929878473f, 0.005257347598671913f, 0.006356567610055208f, 0.007703149691224098f, 0.004394204821437597f, 0.007083694450557232f, 0.003970236983150244f, 0.019058289006352425f, 0.003716642502695322f, 0.005597742740064859f, 0.009794897399842739f, 0.00939156860113144f, 0.003897366812452674f, 0.010688500478863716f, 0.007955105043947697f, 0.014602703973650932f, 0.008967113681137562f, 0.010383235290646553f, 0.003840278834104538f, 0.008121834136545658f, 0.010126521810889244f, 0.0039148456417024136f, 0.006607718765735626f, 0.012114333920180798f, 0.004904699046164751f, 0.009388635866343975f, 0.0033019219990819693f, 0.004764258861541748f, 0.008182650431990623f, 0.012532825581729412f, 0.005268652457743883f, 0.005201361142098904f, 0.004274824168533087f, 0.004915823228657246f, 0.003982193302363157f, 0.0065604993142187595f, 0.005223454441875219f, 0.008336163125932217f, 0.005279215984046459f, 0.004351695999503136f, 0.007634895853698254f, 0.009006969630718231f, 0.004090684466063976f, 0.005258938763290644f, 0.007120198104530573f, 0.006454457063227892f, 0.008269679732620716f, 0.0058319829404354095f, 0.003673456609249115f, 0.005977228283882141f, 0.0059049720875918865f, 0.0067053548991680145f, 0.008553856983780861f, 0.0054915971122682095f, 0.015791550278663635f, 0.006698049139231443f, 0.015966717153787613f, 0.004111497662961483f, 0.005554800853133202f, 0.005461578257381916f, 0.010941180400550365f, 0.004409557208418846f, 0.01715192198753357f, 0.0033196767326444387f, 0.006211314350366592f, 0.003660396672785282f, 0.012585585936903954f, 0.012922752648591995f, 0.005224978551268578f, 0.005025699269026518f, 0.005693263374269009f, 0.0032503842376172543f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #259 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_75_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005118654808029532f, 0.00037741722189821303f, 0.000559782434720546f, 0.00047425791854038835f, 0.0007010213448666036f, 0.0007958611822687089f, 0.0014277258887887f, 0.0016870660474523902f, 0.0007259969715960324f, 0.0007181185646913946f, 0.00044343830086290836f, 0.0006154419388622046f, 0.0006473471294157207f, 0.000909729627892375f, 0.0011410258011892438f, 0.0006236206390894949f, 0.0011540596606209874f, 0.0009392453357577324f, 0.0009066701168194413f, 0.0004037714679725468f, 0.0012038596905767918f, 0.0009923669276759028f, 0.0008592294761911035f, 0.0008307400275953114f, 0.0012841004645451903f, 0.0007037199684418738f, 0.001183505286462605f, 0.0011291650589555502f, 0.0014549597399309278f, 0.0008255733409896493f, 0.001032490748912096f, 0.000793730840086937f, 0.00084028544370085f, 0.001174222445115447f, 0.000639340199995786f, 0.0011866651475429535f, 0.0006856495165266097f, 0.00201389635913074f, 0.0012053013779222965f, 0.0012766254367306828f, 0.0021648516412824392f, 0.0019566102419048548f, 0.0018709589494392276f, 0.0009455838589929044f, 0.0008068543393164873f, 0.0006205975660122931f, 0.0005948694888502359f, 0.0010050550336018205f, 0.0005049040773883462f, 0.001180780935101211f, 0.0006363124120980501f, 0.0012955432757735252f, 0.00036380186793394387f, 0.0005536172538995743f, 0.000575612997636199f, 0.0005821321974508464f, 0.0018907742341980338f, 0.0006641509826295078f, 0.002456291113048792f, 0.0007486711838282645f, 0.0012441902654245496f, 0.0005922784912399948f, 0.0011070782784372568f, 0.0015222460497170687f, 0.0006024750764481723f, 0.00039967126213014126f, 0.0006603304645977914f, 0.000568791467230767f, 0.0007206960581243038f, 0.0012825955636799335f, 0.0004230131453368813f, 0.0006470567313954234f, 0.0004893015138804913f, 0.00028114751330576837f, 0.0013423538766801357f, 0.0007285926258191466f, 0.0006800512783229351f, 0.0004964484251104295f, 0.0007299765129573643f, 0.0008210918167605996f, 0.0013767891796305776f, 0.0015729512088000774f, 0.00045806667185388505f, 0.001104776980355382f, 0.000553787627723068f, 0.0004871224518865347f, 0.0006433673552237451f, 0.0019797359127551317f, 0.0015343312406912446f, 0.0006410875939764082f, 0.0003888930077664554f, 0.0010472843423485756f, 0.00147356151137501f, 0.0004981653764843941f, 0.00030054335366003215f, 0.001043038908392191f, 0.0013465300435200334f, 0.0006035346304997802f, 0.0008720913319848478f, 0.0018596829613670707f, 0.000294595054583624f, 0.0006582470959983766f, 0.000629317422863096f, 0.0007774016703478992f, 0.0005854355404153466f, 0.002039088634774089f, 0.000428069441113621f, 0.001623904681764543f, 0.0003087792720180005f, 0.001067224657163024f, 0.0010758183198049664f, 0.0012575482251122594f, 0.0007205794099718332f, 0.0009602362988516688f, 0.00047778102452866733f, 0.0005623909528367221f, 0.000809992547146976f, 0.0007410926627926528f, 0.0003233101451769471f, 0.002001939807087183f, 0.0013412872795015574f, 0.001886726706288755f, 0.0012534646084532142f, 0.0006038065766915679f, 0.0020542920101433992f, 0.0005830209120176733f, 0.0008356434991583228f, 0.0005491792690008879f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #260 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_76_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019214250147342682f, 0.0064370897598564625f, 0.004799720831215382f, 0.004168593790382147f, 0.006171863526105881f, 0.012032373808324337f, 0.005529060494154692f, 0.0033610265236347914f, 0.0029797477182000875f, 0.005100321024656296f, 0.00825849361717701f, 0.006381362210959196f, 0.005023666191846132f, 0.0037927255034446716f, 0.004992373287677765f, 0.004970379639416933f, 0.007701030001044273f, 0.006036621984094381f, 0.011965838260948658f, 0.005057065282016993f, 0.009561954066157341f, 0.008354981429874897f, 0.0026219142600893974f, 0.009172349236905575f, 0.0054640136659145355f, 0.00648365868255496f, 0.005030542146414518f, 0.0051394193433225155f, 0.006200011819601059f, 0.0040747299790382385f, 0.004542941693216562f, 0.005496573634445667f, 0.004032398108392954f, 0.004735357128083706f, 0.003995484206825495f, 0.00538175692781806f, 0.004368918482214212f, 0.01048734225332737f, 0.009646747261285782f, 0.008552683517336845f, 0.010599655099213123f, 0.004629957024008036f, 0.006100764963775873f, 0.005603736266493797f, 0.0027225641533732414f, 0.004288676660507917f, 0.020448919385671616f, 0.010461925528943539f, 0.0043261293321847916f, 0.004227982833981514f, 0.006074673496186733f, 0.004946283530443907f, 0.004791290033608675f, 0.006341730244457722f, 0.00568391103297472f, 0.0056121195666491985f, 0.007106751669198275f, 0.0037844928447157145f, 0.004954901989549398f, 0.0051916856318712234f, 0.007294224109500647f, 0.004083514679223299f, 0.009814463555812836f, 0.004184574354439974f, 0.004148672800511122f, 0.0035835502203553915f, 0.005092615727335215f, 0.004087177570909262f, 0.0047215805388987064f, 0.005352466832846403f, 0.0058809369802474976f, 0.004437330178916454f, 0.00681100320070982f, 0.005724264308810234f, 0.004988808650523424f, 0.004517179913818836f, 0.3067671060562134f, 0.005209402646869421f, 0.004800437483936548f, 0.0036785912234336138f, 0.00470699230208993f, 0.011870697140693665f, 0.006215651519596577f, 0.011501598171889782f, 0.0061369966715574265f, 0.006127688102424145f, 0.00392121123149991f, 0.004884088411927223f, 0.008532102219760418f, 0.004307576455175877f, 0.00402113189920783f, 0.00497836759313941f, 0.006883619818836451f, 0.00281636044383049f, 0.004190376028418541f, 0.005774965509772301f, 0.004803180228918791f, 0.004318772349506617f, 0.006113498471677303f, 0.009819835424423218f, 0.004293391946703196f, 0.14961861073970795f, 0.004730260465294123f, 0.002204207004979253f, 0.004965678323060274f, 0.005292053334414959f, 0.004785887431353331f, 0.0044667706824839115f, 0.0043144067749381065f, 0.010790455155074596f, 0.004901499953120947f, 0.01065198052674532f, 0.01038180012255907f, 0.007868867367506027f, 0.00501062348484993f, 0.004790813196450472f, 0.009915681555867195f, 0.010148676112294197f, 0.004034806974232197f, 0.005700259935110807f, 0.006344362627714872f, 0.010500557720661163f, 0.01119333878159523f, 0.005932170432060957f, 0.004415004514157772f, 0.004434643778949976f, 0.00721709942445159f, 0.0056843869388103485f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #261 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_77_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 25,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028051678091287613f, 0.001327322912402451f, 0.001110334531404078f, 0.001360125606879592f, 0.0011233538389205933f, 0.0010489877313375473f, 0.0011084164725616574f, 0.0014723443891853094f, 0.00172915100120008f, 0.0010223074350506067f, 0.0010072075529024005f, 0.0009279994992539287f, 0.000983724370598793f, 0.0007428204407915473f, 0.0010057473555207253f, 0.0015595259610563517f, 0.0008340495987795293f, 0.0008999655838124454f, 0.0012515021953731775f, 0.0015797909582033753f, 0.002801720052957535f, 0.001419579260982573f, 0.0011763530783355236f, 0.0013313090894371271f, 0.0012156459270045161f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #262 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_82_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002063860185444355f, 0.00302834901958704f, 0.006083836313337088f, 0.0032234438695013523f, 0.0029883587267249823f, 0.013280957005918026f, 0.0037459940649569035f, 0.0032525858841836452f, 0.0032332553528249264f, 0.0042558773420751095f, 0.009280708618462086f, 0.002963207196444273f, 0.009586838074028492f, 0.0033164643682539463f, 0.006440294440835714f, 0.0035953011829406023f, 0.006297980435192585f, 0.008743572048842907f, 0.006104691885411739f, 0.007983742281794548f, 0.0039009235333651304f, 0.005941282957792282f, 0.00335558014921844f, 0.010796722956001759f, 0.005702288821339607f, 0.0036718235351145267f, 0.0029747593216598034f, 0.004468922968953848f, 0.0029226632323116064f, 0.0030770667362958193f, 0.002695488277822733f, 0.006842856761068106f, 0.004476292058825493f, 0.003114756429567933f, 0.003375455504283309f, 0.005938966758549213f, 0.008494971320033073f, 0.0028633461333811283f, 0.010273388586938381f, 0.004781972151249647f, 0.004726420622318983f, 0.004799943417310715f, 0.0029544320423156023f, 0.0028458049055188894f, 0.0018764901906251907f, 0.0029450489673763514f, 0.010155857540667057f, 0.004712711088359356f, 0.0019427804509177804f, 0.0028799516148865223f, 0.005829786881804466f, 0.0035644664894789457f, 0.0004024710797239095f, 0.0029145660810172558f, 0.005195241421461105f, 0.0014382015215232968f, 0.0035140076652169228f, 0.006217374932020903f, 0.003354951273649931f, 0.003777687670662999f, 0.004141815472394228f, 0.0032123615965247154f, 0.0053608906455338f, 0.0028271698392927647f, 0.0038163536228239536f, 0.005671733990311623f, 0.0051872748881578445f, 0.0029622993897646666f, 0.004690331872552633f, 0.004089293070137501f, 0.008992723189294338f, 0.0023688774090260267f, 0.009632171131670475f, 0.009388094767928123f, 0.003226902335882187f, 0.0040399362333118916f, 3.0026398235349916e-05f, 0.005189478863030672f, 0.003164812456816435f, 0.0022924840450286865f, 0.003190026618540287f, 0.004305316135287285f, 0.005437828600406647f, 0.006021603476256132f, 0.009289799258112907f, 0.004108147695660591f, 0.00390904163941741f, 0.0034119971096515656f, 0.004754894878715277f, 0.0037485307548195124f, 0.00808330625295639f, 0.0030179673340171576f, 0.0026353036519140005f, 0.005610571708530188f, 0.005625470541417599f, 0.006219019182026386f, 0.004258112516254187f, 0.0012058870634064078f, 0.003254294628277421f, 0.004212432540953159f, 0.005735946353524923f, 1.3402155673247762e-05f, 0.004851606208831072f, 0.004857698921114206f, 0.004946941044181585f, 0.004443416837602854f, 0.00460914196446538f, 0.0032360046170651913f, 0.00988453347235918f, 0.005419538356363773f, 0.0012382807908579707f, 0.006467358209192753f, 0.003755002049729228f, 0.0020126288291066885f, 0.007461251690983772f, 0.0029965874273329973f, 0.002448767889291048f, 0.0053006429225206375f, 0.0027792248874902725f, 0.003575191367417574f, 0.005231148097664118f, 0.004325700458139181f, 0.0037043513730168343f, 0.005319623276591301f, 0.003747625509276986f, 0.005623384844511747f, 0.0034098890610039234f, 0.0004302732413634658f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #263 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_83_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 20,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004841762129217386f, 0.0005837157950736582f, 0.0005041051772423089f, 0.00038054102333262563f, 0.00042728561675176024f, 0.0005934872315265238f, 0.0003231146838515997f, 0.0004246682801749557f, 0.00034774219966493547f, 0.0003351483028382063f, 0.0003388930344954133f, 0.00034242268884554505f, 0.00037005843478254974f, 0.00038722489261999726f, 0.000340860802680254f, 0.0003970049729105085f, 0.0004665464221034199f, 0.00046652325545437634f, 0.0003859341377392411f, 0.00040489790262654424f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #264 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_94_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004585443530231714f, 0.0038873213343322277f, 0.0031285781878978014f, 0.004290148615837097f, 0.004242945462465286f, 0.004019180312752724f, 0.0055503579787909985f, 0.004415376577526331f, 0.003525511594489217f, 0.004249089397490025f, 0.003267904045060277f, 0.002809264464303851f, 0.0032045633997768164f, 0.0055350130423903465f, 0.00613107904791832f, 0.005446976982057095f, 0.003972375299781561f, 0.007599184289574623f, 0.005373790394514799f, 0.0024829336907714605f, 0.0033790739253163338f, 0.004491108935326338f, 0.00810759887099266f, 0.003056463086977601f, 0.005182380322366953f, 0.005297261290252209f, 0.0030010328628122807f, 0.003724488662555814f, 0.00355019373819232f, 0.0038828467950224876f, 0.007374872919172049f, 0.002718183444812894f, 0.0037784501910209656f, 0.002927635796368122f, 0.004720780998468399f, 0.0049931928515434265f, 0.009665858000516891f, 0.006611962802708149f, 0.005075416993349791f, 0.002664417028427124f, 0.004750566557049751f, 0.0026647744234651327f, 0.003655725158751011f, 0.0041077109053730965f, 0.005818658042699099f, 0.005127225536853075f, 0.0025710605550557375f, 0.0027247383259236813f, 0.006315510720014572f, 0.0035195271484553814f, 0.005130871199071407f, 0.0037902239710092545f, 0.005073559004813433f, 0.004110544454306364f, 0.00358236744068563f, 0.004746707156300545f, 0.0032610229682177305f, 0.004500105511397123f, 0.005622718017548323f, 0.002774425782263279f, 0.005993763916194439f, 0.0032299107406288385f, 0.004049837589263916f, 0.003538947319611907f, 0.0035537676885724068f, 0.004201941192150116f, 0.003185403998941183f, 0.0037997164763510227f, 0.007324705366045237f, 0.003066752105951309f, 0.004003072157502174f, 0.00513837905600667f, 0.007517833262681961f, 0.0032593596260994673f, 0.0034865273628383875f, 0.0043186005204916f, 0.004358191974461079f, 0.007373742759227753f, 0.004409818910062313f, 0.004604117013514042f, 0.004523274954408407f, 0.004382905084639788f, 0.004862202797085047f, 0.005530079826712608f, 0.0067187026143074036f, 0.0036819062661379576f, 0.007318928372114897f, 0.002943395171314478f, 0.0033608023077249527f, 0.004660952370613813f, 0.005226272623986006f, 0.006179569289088249f, 0.009682766161859035f, 0.004724651109427214f, 0.004942471161484718f, 0.0037790245842188597f, 0.004840887617319822f, 0.0051384796388447285f, 0.003675154410302639f, 0.0045792106539011f, 0.004939113277941942f, 0.004712438676506281f, 0.0069745746441185474f, 0.007210645824670792f, 0.0050866976380348206f, 0.006143839564174414f, 0.004116508178412914f, 0.006822467781603336f, 0.004625814501196146f, 0.008855930529534817f, 0.0034344664309173822f, 0.002932422561571002f, 0.0036934667732566595f, 0.004453723318874836f, 0.003974395804107189f, 0.0036940481513738632f, 0.004662550985813141f, 0.0057719978503882885f, 0.00442082853987813f, 0.003830854780972004f, 0.00360246654599905f, 0.0034651535097509623f, 0.005227132234722376f, 0.004909726791083813f, 0.004331836011260748f, 0.005139034707099199f, 0.005990298464894295f, 0.003037557704374194f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #265 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_95_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001180710387416184f, 0.0018325058044865727f, 0.0009414376108907163f, 0.0007983860559761524f, 0.0006957606528885663f, 0.0008579581626690924f, 0.001226975815370679f, 0.0013488450786098838f, 0.0012778431409969926f, 0.0010183703852817416f, 0.0009495403501205146f, 0.0017201919108629227f, 0.0005953781073912978f, 0.0009623914957046509f, 0.0007445965311489999f, 0.0004638571117538959f, 0.0008709832327440381f, 0.0012020658468827605f, 0.0012356463121250272f, 0.0014579782728105783f, 0.0013587630819529295f, 0.0012599860783666372f, 0.0012472079833969474f, 0.0006399208214133978f, 0.0009302542894147336f, 0.0016054688021540642f, 0.0007220729603432119f, 0.0016818734584376216f, 0.0006212947773747146f, 0.0007406585500575602f, 0.0013732557417824864f, 0.0005977412802167237f, 0.000663042301312089f, 0.0015919223660603166f, 0.0007496087346225977f, 0.0015138988383114338f, 0.0018038613488897681f, 0.0010776492999866605f, 0.0012999630998820066f, 0.0010778146097436547f, 0.0008850473677739501f, 0.0015161255141720176f, 0.001106423675082624f, 0.0005668520461767912f, 0.001012826687656343f, 0.0012031429214403033f, 0.0005607297061942518f, 0.00042514727101661265f, 0.000519879162311554f, 0.0006861197180114686f, 0.002015751553699374f, 0.0013891032431274652f, 0.0011030249297618866f, 0.0014177054399624467f, 0.0009333702619187534f, 0.001330355298705399f, 0.0014027892611920834f, 0.0012996563455089927f, 0.0010788517538458109f, 0.0013490694109350443f, 0.0015565224457532167f, 0.0007347906939685345f, 0.0014785743551328778f, 0.0007356342975981534f, 0.001180376042611897f, 0.0014111918862909079f, 0.0007683831499889493f, 0.000880967010743916f, 0.0017688818043097854f, 0.0013665285659953952f, 0.001118405256420374f, 0.0010383515618741512f, 0.0012304014526307583f, 0.0012925068149343133f, 0.001024264725856483f, 0.000923697545658797f, 0.0014343984657898545f, 0.00045998170389793813f, 0.0019031809642910957f, 0.0008407709538005292f, 0.0009626277606002986f, 0.0016049511032178998f, 0.0014870231971144676f, 0.0014431134331971407f, 0.0011049241293221712f, 0.0014378849882632494f, 0.0011733978753909469f, 0.0012971843825653195f, 0.0007678185938857496f, 0.0011939759133383632f, 0.0017345023807138205f, 0.0009013942908495665f, 0.0007157470681704581f, 0.0008826075354591012f, 0.0009890157962217927f, 0.001782981213182211f, 0.0010552117601037025f, 0.001635650172829628f, 0.0017325577791780233f, 0.0012570704566314816f, 0.0007356344140134752f, 0.001452846103347838f, 0.0014166267355903983f, 0.0013424308272078633f, 0.0008130362257361412f, 0.001552930218167603f, 0.0017813061131164432f, 0.0007384598138742149f, 0.000940513564273715f, 0.001518314820714295f, 0.0008909197640605271f, 0.0010256713721901178f, 0.0012837308458983898f, 0.0009296569041907787f, 0.0011346660321578383f, 0.0007914846646599472f, 0.001098231878131628f, 0.000707700673956424f, 0.0009418357512913644f, 0.0006733360351063311f, 0.0010863854549825191f, 0.00124139036051929f, 0.0009712440660223365f, 0.0012505344348028302f, 0.0009817936224862933f, 0.001037288922816515f, 0.001156811835244298f, 0.0007048682309687138f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #266 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_96_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009208153001964092f, 0.006081056781113148f, 0.008703440427780151f, 0.006253695581108332f, 0.006429547443985939f, 0.008566630072891712f, 0.008010061457753181f, 0.008321015164256096f, 0.006163598038256168f, 0.007688173092901707f, 0.00862397812306881f, 0.00566908810287714f, 0.006109507288783789f, 0.007336991839110851f, 0.008528072386980057f, 0.00825449638068676f, 0.005854488350450993f, 0.010464468039572239f, 0.008976537734270096f, 0.006119853816926479f, 0.00966550875455141f, 0.00788315199315548f, 0.009134097024798393f, 0.0026103651616722345f, 0.006327408831566572f, 0.009123444557189941f, 0.006291934754699469f, 0.01626073755323887f, 0.004759799223393202f, 0.008097171783447266f, 0.012414158321917057f, 0.007090757600963116f, 0.00755512248724699f, 0.0075554801151156425f, 0.005602922290563583f, 0.008723256178200245f, 0.008534803055226803f, 0.007368308026343584f, 0.007069175597280264f, 0.004782133270055056f, 0.0062760175205767155f, 0.008605419658124447f, 0.008193248882889748f, 0.006885702256113291f, 0.011281056329607964f, 0.008173291571438313f, 0.005649607162922621f, 0.005189943127334118f, 0.006473857909440994f, 0.008073423989117146f, 0.009849026799201965f, 0.007819443941116333f, 0.010746730491518974f, 0.009682539850473404f, 0.01066284067928791f, 0.012988264672458172f, 0.009591544978320599f, 0.006930470932275057f, 0.009438191540539265f, 0.0058729262091219425f, 0.005465614143759012f, 0.004103915300220251f, 0.00804915465414524f, 0.006906155962496996f, 0.006211855448782444f, 0.007550814654678106f, 0.007951260544359684f, 0.00808778963983059f, 0.005209348164498806f, 0.011945878155529499f, 0.00601945212110877f, 0.013510522432625294f, 0.008214590139687061f, 0.013479526154696941f, 0.009313218295574188f, 0.0089473407715559f, 0.00909061636775732f, 0.005700698588043451f, 0.0061986264772713184f, 0.007798287086188793f, 0.007715306710451841f, 0.007370667532086372f, 0.004983608145266771f, 0.00816842820495367f, 0.005723833572119474f, 0.010474119335412979f, 0.009415079839527607f, 0.007433926220983267f, 0.0063804625533521175f, 0.012533835135400295f, 0.006609562784433365f, 0.004428509622812271f, 0.00858215894550085f, 0.006051701493561268f, 0.009824089705944061f, 0.005158993415534496f, 0.006568415090441704f, 0.00872556772083044f, 0.006933277472853661f, 0.008334499783813953f, 0.006593557074666023f, 0.01167797576636076f, 0.010092143900692463f, 0.007375608664005995f, 0.006922068074345589f, 0.009221627376973629f, 0.0058153532445430756f, 0.010317199863493443f, 0.012644710950553417f, 0.006889205425977707f, 0.007268913090229034f, 0.00879902858287096f, 0.007991785183548927f, 0.008222297765314579f, 0.007038454990833998f, 0.00701517378911376f, 0.007765875663608313f, 0.006806114688515663f, 0.013708057813346386f, 0.005269954912364483f, 0.0075736078433692455f, 0.008428906090557575f, 0.006872632075101137f, 0.022742748260498047f, 0.006690419744700193f, 0.006232377607375383f, 0.010617359541356564f, 0.005229147616773844f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #267 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_97_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014867966528981924f, 0.001371566904708743f, 0.0009116632863879204f, 0.001595212728716433f, 0.000947916298173368f, 0.0015513022663071752f, 0.0023113079369068146f, 0.002164148958399892f, 0.0010405492503196f, 0.0014941181289032102f, 0.0017866560956463218f, 0.0007234710501506925f, 0.0007004502695053816f, 0.0014724616194143891f, 0.002354401396587491f, 0.0015894570387899876f, 0.0015609924448654056f, 0.001152612385340035f, 0.0015610104892402887f, 0.001794748823158443f, 0.0012632653815671802f, 0.000766936456784606f, 0.0016952207079157233f, 0.001299616415053606f, 0.0016177091747522354f, 0.0015055859694257379f, 0.0009518132428638637f, 0.0013233147328719497f, 0.001079352106899023f, 0.001433979137800634f, 0.0008871581521816552f, 0.0008449657470919192f, 0.0014296284643933177f, 0.0026939152739942074f, 0.0012287790887057781f, 0.0018802073318511248f, 0.0015691578155383468f, 0.0011361162178218365f, 0.001525614527054131f, 0.0012590986443683505f, 0.0017412237357348204f, 0.0019586405251175165f, 0.0011600014986470342f, 0.0008086854359135032f, 0.0011550290510058403f, 0.0013894784497097135f, 0.0033021189738065004f, 0.0012388813775032759f, 0.002378943609073758f, 0.0014546121237799525f, 0.0013653455534949899f, 0.0018639821792021394f, 0.0009238646598532796f, 0.001206058543175459f, 0.0014289747923612595f, 0.0013531689764931798f, 0.0016055202577263117f, 0.0011382056400179863f, 0.001452857512049377f, 0.0010667502647265792f, 0.001167908776551485f, 0.0009534042910672724f, 0.0010251563508063555f, 0.001081235590390861f, 0.0007507993723265827f, 0.0013923910446465015f, 0.0016709772171452641f, 0.0017552613280713558f, 0.0007781321764923632f, 0.001603371580131352f, 0.000997150898911059f, 0.0014314815634861588f, 0.001194983720779419f, 0.0008279289468191564f, 0.0015336902579292655f, 0.0012127545196563005f, 0.0016102287918329239f, 0.001710715121589601f, 0.0011976587120443583f, 0.0010894779115915298f, 0.0014633534010499716f, 0.0011127239558845758f, 0.0013863423373550177f, 0.002803432522341609f, 0.002197696827352047f, 0.0012040134752169251f, 0.0009516013087704778f, 0.002330964431166649f, 0.0013677473179996014f, 0.0020857241470366716f, 0.0023099181707948446f, 0.0013420676114037633f, 0.0020021258387714624f, 0.001639851601794362f, 0.0012093696277588606f, 0.0010355281410738826f, 0.0021871812641620636f, 0.0017060417449101806f, 0.001688320771791041f, 0.0010795950656756759f, 0.000754134205635637f, 0.0013056552270427346f, 0.0008860559901222587f, 0.0013333550887182355f, 0.0019681863486766815f, 0.0016987601993605494f, 0.0012911302037537098f, 0.001506167696788907f, 0.0011978844413533807f, 0.0018697204068303108f, 0.0016614842461422086f, 0.0016958924243226647f, 0.0013478483306244016f, 0.0009169276454485953f, 0.0022795782424509525f, 0.0018069333164021373f, 0.0018165743676945567f, 0.0017456839559599757f, 0.0012154344003647566f, 0.002177065471187234f, 0.0015174897853285074f, 0.001637050649151206f, 0.0012445052852854133f, 0.0011576388496905565f, 0.0014828031416982412f, 0.000956540578044951f, 0.0015949140070006251f, 0.0021267179399728775f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #268 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_98_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007989942096173763f, 0.007782483007758856f, 0.005472313147038221f, 0.008641892112791538f, 0.00525762140750885f, 0.011051887646317482f, 0.013469494879245758f, 0.006976134609431028f, 0.005473446566611528f, 0.015482651069760323f, 0.00890568271279335f, 0.006411960814148188f, 0.004700908437371254f, 0.00872119702398777f, 0.008550393395125866f, 0.009766420349478722f, 0.00915918406099081f, 0.007827071473002434f, 0.013113250024616718f, 0.00838592927902937f, 0.005018540658056736f, 0.006278667598962784f, 0.009284420870244503f, 0.006421527825295925f, 0.009789405390620232f, 0.009087388403713703f, 0.005370523780584335f, 0.009272242896258831f, 0.004442774690687656f, 0.006352744065225124f, 0.00536912027746439f, 0.01600457727909088f, 0.005070361774414778f, 0.010010428726673126f, 0.007259896025061607f, 0.009619100950658321f, 0.014417222701013088f, 0.006814879830926657f, 0.006968644913285971f, 0.008100053295493126f, 0.006530119571834803f, 0.010384861379861832f, 0.0071133836172521114f, 0.022640341892838478f, 0.00515875406563282f, 0.004666253924369812f, 0.006611637305468321f, 0.009375193156301975f, 0.007597065530717373f, 0.008179910480976105f, 0.00605448754504323f, 0.00539142033085227f, 0.009469405747950077f, 0.01131000742316246f, 0.008724339306354523f, 0.007111749611794949f, 0.009729824028909206f, 0.0076553733088076115f, 0.007828811183571815f, 0.010277657769620419f, 0.008181550540030003f, 0.0048894137144088745f, 0.006701662205159664f, 0.005688247736543417f, 0.004148639272898436f, 0.005429625976830721f, 0.006393368821591139f, 0.006009316071867943f, 0.006818106863647699f, 0.006834331899881363f, 0.008189103566110134f, 0.006687480956315994f, 0.010252362117171288f, 0.0068613383919000626f, 0.009659300558269024f, 0.007522113621234894f, 0.008143393322825432f, 0.009463883936405182f, 0.004198015201836824f, 0.004731706343591213f, 0.008401517756283283f, 0.006406368687748909f, 0.007856786251068115f, 0.006729599088430405f, 0.007026562001556158f, 0.008302546106278896f, 0.006679225247353315f, 0.00708747049793601f, 0.0050805965438485146f, 0.008914335630834103f, 0.010016180574893951f, 0.0064594559371471405f, 0.0037624649703502655f, 0.007955565117299557f, 0.0079716257750988f, 0.006673058029264212f, 0.006807152647525072f, 0.009566537104547024f, 0.006989600136876106f, 0.005397139582782984f, 0.008077171631157398f, 0.004611516837030649f, 0.004561831708997488f, 0.011051567271351814f, 0.008684513159096241f, 0.00631716288626194f, 0.006750430911779404f, 0.0061320094391703606f, 0.007256961427628994f, 0.0067064957693219185f, 0.010447192005813122f, 0.013649680651724339f, 0.00569675350561738f, 0.0037329373881220818f, 0.0070012882351875305f, 0.011413638480007648f, 0.009350961074233055f, 0.0064368173480033875f, 0.006080201826989651f, 0.007688276004046202f, 0.00637046480551362f, 0.0051551503129303455f, 0.020496558398008347f, 0.007003988604992628f, 0.011461235582828522f, 0.0047105285339057446f, 0.009346630424261093f, 0.010652544908225536f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #269 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_99_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001059320173226297f, 0.00265194452367723f, 0.0008345030946657062f, 0.0017520528053864837f, 0.0011668786173686385f, 0.0012183852959424257f, 0.0013947217958047986f, 0.0007501307409256697f, 0.0016953296726569533f, 0.0015147208468988538f, 0.0017111820634454489f, 0.0015320389065891504f, 0.001400379347614944f, 0.0017237033462151885f, 0.0013638596283271909f, 0.0019166043493896723f, 0.0012308036675676703f, 0.0011774796294048429f, 0.0017064346466213465f, 0.0015336144715547562f, 0.0012948695803061128f, 0.0012305729323998094f, 0.0015156863955780864f, 0.0018022285075858235f, 0.0007846831576898694f, 0.001326938159763813f, 0.002234767423942685f, 0.0017704665660858154f, 0.0019085909007117152f, 0.0013349727960303426f, 0.0010429901303723454f, 0.001396720646880567f, 0.001482351333834231f, 0.0010239557595923543f, 0.0013572564348578453f, 0.0017575318925082684f, 0.001182154635898769f, 0.0013251436175778508f, 0.0013980638468638062f, 0.001419166335836053f, 0.0011801669606938958f, 0.002051941119134426f, 0.00172074802685529f, 0.001264826045371592f, 0.0011662065517157316f, 0.0015924724284559488f, 0.002117360709235072f, 0.001682598260231316f, 0.0016978586791083217f, 0.001885593286715448f, 0.0012691301526501775f, 0.0018288966966792941f, 0.0012714795302599669f, 0.000966107239946723f, 0.0012576275039464235f, 0.0025750529021024704f, 0.0011329782428219914f, 0.0012536973226815462f, 0.0018325236160308123f, 0.0016851534601300955f, 0.0013459709007292986f, 0.0013174654450267553f, 0.0009681281517259777f, 0.001271902467124164f, 0.0008241074974648654f, 0.0014011352322995663f, 0.0015365942381322384f, 0.0014175318647176027f, 0.0011125182500109076f, 0.0015000615967437625f, 0.0010284754680469632f, 0.001355650252662599f, 0.0011701228795573115f, 0.0022679695393890142f, 0.0007721260190010071f, 0.0016011202242225409f, 0.0007541684899479151f, 0.001767417648807168f, 0.0012187843676656485f, 0.0019046053057536483f, 0.0010518489871174097f, 0.0017973115900531411f, 0.001174282399006188f, 0.0010592549806460738f, 0.0010765378829091787f, 0.0010802665492519736f, 0.0007852160488255322f, 0.0017572628566995263f, 0.0011977088870480657f, 0.0010398783488199115f, 0.0018726963317021728f, 0.0010055190650746226f, 0.0013892226852476597f, 0.0011115818051621318f, 0.0008601128938607872f, 0.0015360682737082243f, 0.0018017051042988896f, 0.0005562223377637565f, 0.0012638390762731433f, 0.001923820935189724f, 0.0012616693275049329f, 0.0008120770798996091f, 0.0010271662613376975f, 0.0009966428624466062f, 0.0013069764245301485f, 0.0014588613994419575f, 0.0012271746527403593f, 0.0012318050721660256f, 0.0014222851023077965f, 0.0010358114959672093f, 0.001269538071937859f, 0.0013239617692306638f, 0.0011639713775366545f, 0.0009719492518343031f, 0.0020020483061671257f, 0.0011795617174357176f, 0.0012843450531363487f, 0.0014607353368774056f, 0.0015101050958037376f, 0.0015064124017953873f, 0.0010823352495208383f, 0.0015875212848186493f, 0.0007685112650506198f, 0.0015869454946368933f, 0.00123511697165668f, 0.0014357030158862472f, 0.0009053903049789369f, 0.001668996294029057f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #270 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_100_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005143362563103437f, 0.007070086430758238f, 0.003548742737621069f, 0.012734562158584595f, 0.00996408611536026f, 0.007643795572221279f, 0.0033166888169944286f, 0.005481105763465166f, 0.007043994963169098f, 0.007329832762479782f, 0.007550586014986038f, 0.009315364994108677f, 0.008724316023290157f, 0.007892814464867115f, 0.008604914881289005f, 0.010145884938538074f, 0.0069478037767112255f, 0.0070436554960906506f, 0.00833088718354702f, 0.008581902831792831f, 0.004158601630479097f, 0.005667987745255232f, 0.007767959032207727f, 0.01050653774291277f, 0.006150770932435989f, 0.008087152615189552f, 0.005994902458041906f, 0.011254055425524712f, 0.0060592289082705975f, 0.007485413923859596f, 0.0065093813464045525f, 0.009105375967919827f, 0.010530821047723293f, 0.0063733612187206745f, 0.006871708203107119f, 0.004681417252868414f, 0.006804161239415407f, 0.006699967663735151f, 0.00691111758351326f, 0.005914774723351002f, 0.01060034241527319f, 0.010701947845518589f, 0.011104801669716835f, 0.012978790327906609f, 0.007258809637278318f, 0.007836543023586273f, 0.007436967454850674f, 0.005778882652521133f, 0.009331480599939823f, 0.009382441639900208f, 0.004416248761117458f, 0.005821174010634422f, 0.005222399719059467f, 0.011284204199910164f, 0.004406844265758991f, 0.01660868711769581f, 0.0076967948116362095f, 0.006048738025128841f, 0.007971341721713543f, 0.011610958725214005f, 0.006702935788780451f, 0.00490549486130476f, 0.0068457224406301975f, 0.004483586177229881f, 0.005542539991438389f, 0.010346639901399612f, 0.008814621716737747f, 0.00797854270786047f, 0.008387804962694645f, 0.006850831676274538f, 0.006989679299294949f, 0.005519641097635031f, 0.008287730626761913f, 0.009005983360111713f, 0.00601926539093256f, 0.007612355053424835f, 0.00683447765186429f, 0.007475926075130701f, 0.0075738439336419106f, 0.009968265891075134f, 0.005819682963192463f, 0.009625653736293316f, 0.006099108140915632f, 0.010201017372310162f, 0.006173830479383469f, 0.009165716357529163f, 0.005792814772576094f, 0.011183488182723522f, 0.007493114564567804f, 0.004469441249966621f, 0.0073073022067546844f, 0.006902053952217102f, 0.007303493097424507f, 0.004840940702706575f, 0.005869482643902302f, 0.006313323508948088f, 0.010775085538625717f, 0.0066092186607420444f, 0.007497457321733236f, 0.009654785506427288f, 0.007139001041650772f, 0.006043207831680775f, 0.008879849687218666f, 0.004865114577114582f, 0.009018411859869957f, 0.00557684525847435f, 0.008828194811940193f, 0.011654757894575596f, 0.003984970971941948f, 0.00458861468359828f, 0.005218943580985069f, 0.00529247522354126f, 0.007510025054216385f, 0.008235897868871689f, 0.010251885280013084f, 0.01356412936002016f, 0.006812374107539654f, 0.00844654906541109f, 0.010735433548688889f, 0.008215374313294888f, 0.006465311162173748f, 0.005733918864279985f, 0.008546708151698112f, 0.008601801469922066f, 0.006358504295349121f, 0.006782958284020424f, 0.007074460852891207f, 0.009426958858966827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #271 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_101_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012752946931868792f, 0.0017252416582778096f, 0.0008978958940133452f, 0.0014294380089268088f, 0.0012345713330432773f, 0.0013301579747349024f, 0.0011602170998230577f, 0.0008434182382188737f, 0.0006172748981043696f, 0.000998368370346725f, 0.0017841316293925047f, 0.0024649070110172033f, 0.0014061251422390342f, 0.0008849718724377453f, 0.0013019404141232371f, 0.0013474011793732643f, 0.0018656456377357244f, 0.0014013854088261724f, 0.0014456762000918388f, 0.0007543376996181905f, 0.001422925852239132f, 0.0007169345626607537f, 0.0005450028111226857f, 0.0012402309803292155f, 0.0010974854230880737f, 0.0009906566701829433f, 0.0011043720878660679f, 0.0005082110874354839f, 0.001653121318668127f, 0.0015863410662859678f, 0.002046766923740506f, 0.0010893355356529355f, 0.0011133374646306038f, 0.0010924584930762649f, 0.001296398346312344f, 0.0011936490191146731f, 0.0012890102807432413f, 0.0009784597204998136f, 0.0009277793578803539f, 0.0013195335632190108f, 0.001436492777429521f, 0.0012746267020702362f, 0.0013228077441453934f, 0.001130198361352086f, 0.001662742462940514f, 0.0007919635390862823f, 0.0015502943424507976f, 0.0009379241382703185f, 0.0013660658150911331f, 0.0013867897214367986f, 0.0014865499688312411f, 0.001074578845873475f, 0.0017317713936790824f, 0.0011357313487678766f, 0.001662163413129747f, 0.0008719332399778068f, 0.001168329850770533f, 0.0009357734234072268f, 0.0008080333354882896f, 0.001468349015340209f, 0.0010989232687279582f, 0.0015485441545024514f, 0.000542005873285234f, 0.0013231388293206692f, 0.0008158616255968809f, 0.0007467824034392834f, 0.0015094467671588063f, 0.0005995165556669235f, 0.000754559354390949f, 0.001735399360768497f, 0.001150251249782741f, 0.0015709707513451576f, 0.0017839664360508323f, 0.00106592639349401f, 0.0007782479515299201f, 0.0016084547387436032f, 0.000877448997925967f, 0.0013736834516748786f, 0.0007389102247543633f, 0.000774821441154927f, 0.0014463939005509019f, 0.0010397314326837659f, 0.000955370138399303f, 0.001335680834017694f, 0.0013071645516902208f, 0.0013022591592743993f, 0.001312956097535789f, 0.0007504793466068804f, 0.0012049329234287143f, 0.0015622181817889214f, 0.001689042546786368f, 0.0011991745559498668f, 0.0010331871453672647f, 0.0015455192187801003f, 0.001165782567113638f, 0.0008364954264834523f, 0.0009662635857239366f, 0.0017657896969467402f, 0.0008691236726008356f, 0.0019817466381937265f, 0.0011424748227000237f, 0.0007926631369628012f, 0.001218598335981369f, 0.001109548145905137f, 0.0014817210612818599f, 0.00083584850654006f, 0.0005499677499756217f, 0.0010801574680954218f, 0.0007552968454547226f, 0.0007820914615876973f, 0.000775154447183013f, 0.0011773519217967987f, 0.001630459912121296f, 0.0011406136909499764f, 0.0007285074680112302f, 0.00130177300889045f, 0.0017130872001871467f, 0.001580874901264906f, 0.0015165352961048484f, 0.0007194630452431738f, 0.0017990312771871686f, 0.0013869385002180934f, 0.0009580980404280126f, 0.0008670194074511528f, 0.0018598928581923246f, 0.0012643795926123857f, 0.001241815509274602f, 0.0013773806858807802f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #272 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_102_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008413982577621937f, 0.012760845012962818f, 0.010783927515149117f, 0.005676500499248505f, 0.004424841608852148f, 0.005928630009293556f, 0.007574053015559912f, 0.005003443453460932f, 0.004148541018366814f, 0.006946116220206022f, 0.005206190049648285f, 0.0054661910980939865f, 0.02029009908437729f, 0.004944676533341408f, 0.004604287911206484f, 0.006854439154267311f, 0.006005726754665375f, 0.005846276879310608f, 0.008710252121090889f, 0.004518156871199608f, 0.009577102027833462f, 0.008439392782747746f, 0.007550239097326994f, 0.007501647807657719f, 0.005119869951158762f, 0.004880448803305626f, 0.008112205192446709f, 0.0038676352705806494f, 0.01076419372111559f, 0.008539428003132343f, 0.011333613656461239f, 0.009401818737387657f, 0.01009297650307417f, 0.005124878138303757f, 0.007292150519788265f, 0.007037586532533169f, 0.01338253729045391f, 0.00755502562969923f, 0.0081099271774292f, 0.010239358991384506f, 0.008776062168180943f, 0.005415595136582851f, 0.005114714615046978f, 0.010490025393664837f, 0.00829773023724556f, 0.004280935972929001f, 0.007720236666500568f, 0.005847246386110783f, 0.006902983412146568f, 0.01742313988506794f, 0.008734720759093761f, 0.0063978577964007854f, 0.00956809613853693f, 0.007689922582358122f, 0.00884037371724844f, 0.004415720235556364f, 0.011095007881522179f, 0.005280785262584686f, 0.004752561450004578f, 0.01137612946331501f, 0.0066279214806854725f, 0.014256051741540432f, 0.006029302719980478f, 0.007311537861824036f, 0.008882896974682808f, 0.006824912969022989f, 0.00889191497117281f, 0.004692102316766977f, 0.005462158937007189f, 0.009582444094121456f, 0.009464443661272526f, 0.01142579223960638f, 0.008109315298497677f, 0.006917274557054043f, 0.003926297649741173f, 0.008156322874128819f, 0.005914474371820688f, 0.006707719527184963f, 0.005986154079437256f, 0.005924557335674763f, 0.012982040643692017f, 0.007322630379348993f, 0.008267550729215145f, 0.006485498510301113f, 0.006032572127878666f, 0.007099473848938942f, 0.009776364080607891f, 0.003295290283858776f, 0.007083655800670385f, 0.007415706291794777f, 0.00906500406563282f, 0.007896868512034416f, 0.008261195383965969f, 0.006181677803397179f, 0.00516094034537673f, 0.00403408519923687f, 0.0056350138038396835f, 0.008940358646214008f, 0.0036250061821192503f, 0.009328234009444714f, 0.0065923817455768585f, 0.007550214882940054f, 0.006282262038439512f, 0.014048310928046703f, 0.0129175316542387f, 0.0037950268015265465f, 0.00697316275909543f, 0.006198192480951548f, 0.013873379677534103f, 0.00865455437451601f, 0.00776062672957778f, 0.009385541081428528f, 0.006146400701254606f, 0.004087395500391722f, 0.005127845797687769f, 0.006396288052201271f, 0.008590173907577991f, 0.006586055736988783f, 0.008694997988641262f, 0.004133540205657482f, 0.009231018833816051f, 0.006573481019586325f, 0.008284470997750759f, 0.00759063009172678f, 0.00600391672924161f, 0.003366409335285425f, 0.0056104278191924095f, 0.004578575491905212f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #273 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_103_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002016178797930479f, 0.0010031298734247684f, 0.0010520117357373238f, 0.0010982014937326312f, 0.0010942339431494474f, 0.0012101898901164532f, 0.0012353245401754975f, 0.0009710232843644917f, 0.002251207362860441f, 0.0013180780224502087f, 0.0012973938137292862f, 0.0011785441311076283f, 0.0009592167334631085f, 0.0011895359493792057f, 0.000712838489562273f, 0.0017741499468684196f, 0.001190285081975162f, 0.0010437535820528865f, 0.0019215598003938794f, 0.0012573158601298928f, 0.0008328999392688274f, 0.0010250064078718424f, 0.0011204172624275088f, 0.0009249160066246986f, 0.0008935265359468758f, 0.001813084352761507f, 0.0010143907275050879f, 0.0015344535931944847f, 0.00209687277674675f, 0.0011838554637506604f, 0.000682842277456075f, 0.0010567214339971542f, 0.0014770603738725185f, 0.0020777052268385887f, 0.0017954586073756218f, 0.000996959744952619f, 0.0007567319553345442f, 0.0012525622732937336f, 0.0008349329000338912f, 0.0018397740786895156f, 0.0015406317543238401f, 0.0015278216451406479f, 0.002506010700017214f, 0.0007832373958081007f, 0.0016134970355778933f, 0.0010621023830026388f, 0.0009392896317876875f, 0.001314943772740662f, 0.0011470376048237085f, 0.0013035766314715147f, 0.0005387769197113812f, 0.0017240624874830246f, 0.0007054294692352414f, 0.0017964578000828624f, 0.0006239896756596863f, 0.0015698837814852595f, 0.0014431463787332177f, 0.001320619834586978f, 0.0017852039309218526f, 0.0007816411089152098f, 0.0009102041949518025f, 0.0011686653597280383f, 0.0008299658657051623f, 0.0010661904234439135f, 0.000728669750969857f, 0.0008568245684728026f, 0.0010770681547001004f, 0.001858514384366572f, 0.0008830756414681673f, 0.0010254986118525267f, 0.000754419423174113f, 0.0013834128621965647f, 0.001031898078508675f, 0.0015642223879694939f, 0.0006942861364223063f, 0.0013332038652151823f, 0.0009995196014642715f, 0.0014915282372385263f, 0.0011948758037760854f, 0.0021934914402663708f, 0.0011506173759698868f, 0.0009736737702041864f, 0.0017630134243518114f, 0.001275012269616127f, 0.0007803811458870769f, 0.0011055560316890478f, 0.0007820204482413828f, 0.0012761264806613326f, 0.002128778723999858f, 0.0008063609129749238f, 0.0011944046709686518f, 0.0014872439205646515f, 0.0010324972681701183f, 0.001856389339081943f, 0.0014360600616782904f, 0.0009425216703675687f, 0.0013116943882778287f, 0.0017979139229282737f, 0.0010020617628470063f, 0.0008814788889139891f, 0.0010536672780290246f, 0.001255450421012938f, 0.0012307909782975912f, 0.001167018199339509f, 0.0013195520732551813f, 0.0008786667021922767f, 0.0008656910504214466f, 0.0017452518222853541f, 0.0011122997384518385f, 0.0009498120052739978f, 0.0008778742630966008f, 0.0015273895114660263f, 0.0011649775551632047f, 0.0011769598349928856f, 0.001076849759556353f, 0.0018397406674921513f, 0.000877604354172945f, 0.0010838232701644301f, 0.000892954645678401f, 0.001927119679749012f, 0.0021255870815366507f, 0.0015540731837972999f, 0.002742234617471695f, 0.0011879898374900222f, 0.00053890619892627f, 0.0017532312776893377f, 0.0010860629845410585f, 0.0007818114827387035f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #274 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_104_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008283731527626514f, 0.008955284021794796f, 0.004017451778054237f, 0.011491302400827408f, 0.003824852639809251f, 0.007595325820147991f, 0.006180725060403347f, 0.008895865641534328f, 0.00560812558978796f, 0.006458145100623369f, 0.01164145115762949f, 0.01331925205886364f, 0.04921121150255203f, 0.006604189518839121f, 0.006394984200596809f, 0.005439609754830599f, 0.005390860605984926f, 0.08092696964740753f, 0.008692282252013683f, 0.0065485648810863495f, 0.019379116594791412f, 0.011766516603529453f, 0.009379325434565544f, 0.006666173227131367f, 0.005639603361487389f, 0.0072641633450984955f, 0.005932967644184828f, 0.05304386839270592f, 0.007802971638739109f, 0.00643357215449214f, 0.005073353182524443f, 0.009389262646436691f, 0.009310766123235226f, 0.00700268754735589f, 0.006322122644633055f, 0.0029071008320897818f, 0.006037513259798288f, 0.004980828147381544f, 0.0031658646184951067f, 0.004026660230010748f, 0.012691374868154526f, 0.008326837792992592f, 0.023350948467850685f, 0.00340372696518898f, 0.00886139739304781f, 0.006259091664105654f, 0.00467905355617404f, 0.008059851825237274f, 0.003400882938876748f, 0.00675539206713438f, 0.004090174566954374f, 0.004765025805681944f, 0.006778696086257696f, 0.010779543779790401f, 0.00558715034276247f, 0.011262616142630577f, 0.004641739185899496f, 0.008372623473405838f, 0.007893182337284088f, 0.006332011893391609f, 0.013902376405894756f, 0.02873745560646057f, 0.004740039352327585f, 0.005326942540705204f, 0.006915598176419735f, 0.004713260103017092f, 0.009543724358081818f, 0.010406685061752796f, 0.004866436589509249f, 0.007299880497157574f, 0.003344570053741336f, 0.004771728068590164f, 0.020638909190893173f, 0.005330848507583141f, 0.004421906545758247f, 0.0038132674526423216f, 0.011412317864596844f, 0.008822818286716938f, 0.012076159007847309f, 0.010500417090952396f, 0.009723384864628315f, 0.005096691660583019f, 0.0051452093757689f, 0.005897712428122759f, 0.003949311561882496f, 0.0036886529996991158f, 0.004736720118671656f, 0.006985263898968697f, 0.005900471471250057f, 0.0052645388059318066f, 0.009755956009030342f, 0.007630014326423407f, 0.011459440924227238f, 0.028582608327269554f, 0.004833000246435404f, 0.005173965357244015f, 0.0097527289763093f, 0.00567430118098855f, 0.004415158648043871f, 0.004278921522200108f, 0.003463710192590952f, 0.010753137059509754f, 0.005245720501989126f, 0.013158774934709072f, 0.008049055002629757f, 0.0038198870606720448f, 0.005634067580103874f, 0.008547303266823292f, 0.005920182913541794f, 0.006247223820537329f, 0.0058059534057974815f, 0.007154818624258041f, 0.007421819493174553f, 0.00944680254906416f, 0.009843699634075165f, 0.008125152438879013f, 0.005338729824870825f, 0.10193975269794464f, 0.00542732048779726f, 0.027733981609344482f, 0.0074174352921545506f, 0.0046633039601147175f, 0.009096475318074226f, 0.006226729601621628f, 0.0046222335658967495f, 0.004367168061435223f, 0.003988201729953289f, 0.008865849114954472f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #275 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_105_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 25,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001369854318909347f, 0.0008002546383067966f, 0.0010906634852290154f, 0.0010694575030356646f, 0.0014034172054380178f, 0.000824577291496098f, 0.0008912234334275126f, 0.001117330975830555f, 0.000843539834022522f, 0.0009716941858641803f, 0.000499955378472805f, 0.0013081178767606616f, 0.0009660876239649951f, 0.0010150540620088577f, 0.0007382935145869851f, 0.0008348959381692111f, 0.0005190720548853278f, 0.0006665590335614979f, 0.0010105038527399302f, 0.0010236655361950397f, 0.0012427360052242875f, 0.000850104377605021f, 0.0009886849438771605f, 0.0012026046169921756f, 0.0011863855179399252f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #276 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_110_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001207867986522615f, 0.0017963917925953865f, 0.006799668539315462f, 0.0030324936378747225f, 0.0013777809217572212f, 0.004267249722033739f, 0.0015074072871357203f, 0.0017435583285987377f, 0.0008662674226798117f, 0.001963081769645214f, 0.002411188092082739f, 1.4580245078832377e-05f, 2.077564386127051e-05f, 0.003622885327786207f, 0.019198128953576088f, 0.0010473316069692373f, 0.0013820822350680828f, 7.511340754717821e-06f, 0.004540434572845697f, 0.0031154146417975426f, 0.0005608123610727489f, 0.008748003281652927f, 0.0043212734162807465f, 0.008709718473255634f, 0.007128015160560608f, 0.0030014386866241693f, 0.0007132819155231118f, 5.476199476106558e-06f, 0.0032180831767618656f, 0.015468011610209942f, 0.0025883642956614494f, 0.005065866746008396f, 0.0007217426900751889f, 0.003225352382287383f, 0.00186702492646873f, 0.0010648255702108145f, 0.001072207698598504f, 0.005246060900390148f, 0.0030334198381751776f, 0.0013650682521983981f, 0.002725807949900627f, 0.00283918553031981f, 1.5463227782674949e-06f, 0.006632651202380657f, 0.0034971567802131176f, 0.0033796860370785f, 0.015941325575113297f, 0.0034648331347852945f, 0.0027084043249487877f, 0.001647715806029737f, 0.0031488065142184496f, 0.0022157563362270594f, 0.010465885512530804f, 0.004872102290391922f, 0.0002883367124013603f, 0.0022398110013455153f, 0.0011723762145265937f, 0.00023274394334293902f, 0.0036629175301641226f, 0.0008141102152876556f, 0.002331322757527232f, 3.4110112210328225e-06f, 0.0018232972361147404f, 0.004059832077473402f, 0.004630361218005419f, 0.0011385445250198245f, 0.0009187592659145594f, 0.002165048848837614f, 0.0028875255957245827f, 0.0033199458848685026f, 0.006721599027514458f, 0.0021109364461153746f, 4.158676802035188e-06f, 0.0006613209843635559f, 0.0006996890879236162f, 0.0008436247589997947f, 0.0043706707656383514f, 0.0011508973548188806f, 0.00207794108428061f, 0.0023037614300847054f, 0.0034743528813123703f, 0.0017075714422389865f, 0.0019883080385625362f, 0.010526816360652447f, 0.0015559858875349164f, 0.004147005267441273f, 0.002675555879250169f, 0.0020987822208553553f, 0.0011426853016018867f, 0.0007944221724756062f, 0.005649920087307692f, 0.0017415342153981328f, 0.0044853282161056995f, 2.982676505780546e-07f, 0.005941112991422415f, 0.00556196179240942f, 0.002569130389019847f, 0.0036642805207520723f, 0.002829356584697962f, 0.0014133329968899488f, 0.002281452063471079f, 0.0050981012172997f, 0.0037429737858474255f, 0.004162130411714315f, 0.002013595076277852f, 0.0038773685228079557f, 0.0013409550301730633f, 0.0034808011259883642f, 0.00206381524913013f, 0.0034864507615566254f, 0.0005535309319384396f, 0.00016271784261334687f, 0.0051283505745232105f, 0.0035629658959805965f, 0.004163410048931837f, 0.00234369863756001f, 0.0034029935486614704f, 1.123221181842382e-06f, 0.010851417668163776f, 0.0030558533035218716f, 0.004831545986235142f, 0.0024154933635145426f, 0.0037825468461960554f, 7.487916445825249e-05f, 0.009848366491496563f, 0.002056679455563426f, 0.00034483580384403467f, 0.0018165467772632837f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #277 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_111_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 20,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000578194682020694f, 0.0005255321157164872f, 0.0007000467157922685f, 0.000619070022366941f, 0.00041318906005471945f, 0.000556335027795285f, 0.0006887081544846296f, 0.000672859896440059f, 0.0006115786381997168f, 0.0007636488298885524f, 0.0005606933846138418f, 0.000737309455871582f, 0.0008083029533736408f, 0.0007823951309546828f, 0.0007373413536697626f, 0.0007033811416476965f, 0.0004975787014700472f, 0.0006147043313831091f, 0.0006187808467075229f, 0.0005257775192148983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #278 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_122_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012514111585915089f, 0.006720462813973427f, 0.00880848616361618f, 0.010177846066653728f, 0.00033792530302889645f, 0.004060571081936359f, 0.002562697045505047f, 0.006259790621697903f, 0.006661558523774147f, 0.002698490396142006f, 0.006260935682803392f, 0.004625542555004358f, 0.0011574046220630407f, 0.004271415993571281f, 0.007140507455915213f, 0.0023370569106191397f, 0.004267178010195494f, 0.005964943673461676f, 0.007990911602973938f, 0.006131269037723541f, 0.005824860651046038f, 0.008146660402417183f, 0.005617872346192598f, 0.0015968970255926251f, 0.007641491945832968f, 0.007643546909093857f, 0.0024271823931485415f, 0.010567416436970234f, 0.003487240057438612f, 0.007536675315350294f, 0.009234806522727013f, 0.010286073200404644f, 0.0038781706243753433f, 0.0024682185612618923f, 0.003116438863798976f, 0.009864380583167076f, 0.008989568799734116f, 0.0075375912711024284f, 0.008341748267412186f, 0.004141036421060562f, 0.0026694717817008495f, 0.016034675762057304f, 0.0046409722417593f, 0.0037910614628344774f, 0.0017324757063761353f, 0.0052658189088106155f, 0.004417703952640295f, 0.0008818189380690455f, 0.001877077273093164f, 0.007811553776264191f, 0.011073272675275803f, 0.0038038240745663643f, 0.0080972108989954f, 0.007475846912711859f, 0.007369087543338537f, 0.005444364622235298f, 0.0107429139316082f, 0.006585220340639353f, 0.0056898826733231544f, 0.004936703015118837f, 0.007749041076749563f, 0.00043924659257754683f, 0.0056584556587040424f, 0.004508960526436567f, 0.010778414085507393f, 0.004665495362132788f, 0.006047368980944157f, 0.012021614238619804f, 0.00962899625301361f, 0.004481642972677946f, 0.008700123988091946f, 0.003375105559825897f, 0.008349969983100891f, 0.00916549563407898f, 0.008370177820324898f, 0.006524867378175259f, 0.004823526833206415f, 0.006692461669445038f, 0.007452157326042652f, 0.004672430455684662f, 0.004771111998707056f, 0.005422769580036402f, 0.006689362693578005f, 0.005055135115981102f, 0.0033868663012981415f, 0.0028424833435565233f, 0.007572479080408812f, 0.005614100489765406f, 0.004835805855691433f, 0.0046912869438529015f, 0.004505271092057228f, 0.008150424808263779f, 0.007095075212419033f, 0.004726178012788296f, 0.006691465154290199f, 0.005142380483448505f, 0.007445116993039846f, 0.010671524330973625f, 0.0057891481555998325f, 0.008167085237801075f, 0.004756594076752663f, 0.007611417677253485f, 0.009966385550796986f, 0.0045597366988658905f, 0.007153191603720188f, 0.01147080771625042f, 0.007570352870970964f, 0.0065871598199009895f, 0.004985544830560684f, 0.004385218024253845f, 0.011466193944215775f, 0.005155581049621105f, 0.004136009607464075f, 0.009666812606155872f, 0.005100468639284372f, 0.001855317852459848f, 0.003258019220083952f, 0.0057956501841545105f, 0.004172444809228182f, 0.008067530579864979f, 0.006939108949154615f, 0.006489858962595463f, 0.00926607009023428f, 0.00035363389179110527f, 0.0055237808264791965f, 0.009471849538385868f, 0.004344727378338575f, 0.009232488460838795f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #279 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_123_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 114,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027639002655632794f, 0.0018557935254648328f, 0.001177912694402039f, 0.0013271524803712964f, 3.937008052901092e-09f, 0.0008547822944819927f, 0.0007878184551373124f, 3.937008052901092e-09f, 0.0010803807526826859f, 3.937008052901092e-09f, 0.001391862635500729f, 0.0005414983606897295f, 0.0008850444573909044f, 0.0007776592392474413f, 0.0007951827719807625f, 1.7593739585208823e-06f, 3.937008052901092e-09f, 1.4171345355862286e-05f, 0.0012255641631782055f, 0.0012219519121572375f, 0.0009941214229911566f, 0.0010572177125141025f, 0.0006214382010512054f, 0.0005632204702124f, 0.0010827445657923818f, 0.0013945099199190736f, 2.406387466180604e-06f, 0.000709439511410892f, 0.0011374513851478696f, 3.937008052901092e-09f, 8.087522292044014e-05f, 0.000919351470656693f, 6.163087618915597e-06f, 0.001152785262092948f, 3.937008052901092e-09f, 0.0012091996613889933f, 0.000595852208789438f, 0.0013539288192987442f, 0.0003407100448384881f, 3.937008052901092e-09f, 0.0013914559967815876f, 0.0009478320134803653f, 0.0012087883660569787f, 0.0009147682576440275f, 0.0010342594468966126f, 0.0011924105929210782f, 0.001274053705856204f, 0.0006086687208153307f, 1.1282501333198525e-07f, 0.0009005078463815153f, 3.937008052901092e-09f, 0.0007092644227668643f, 0.0007358300499618053f, 0.0009553503477945924f, 0.0013383557088673115f, 0.0010294533567503095f, 3.937008052901092e-09f, 0.0010277035180479288f, 0.00037448221701197326f, 3.937008052901092e-09f, 0.0018295453628525138f, 3.5280077099741902e-06f, 0.00047019857447594404f, 0.0009736603242345154f, 0.0011208296054974198f, 0.001042875344865024f, 6.113647827987734e-07f, 3.937008052901092e-09f, 0.001455147285014391f, 3.937008052901092e-09f, 0.0024463185109198093f, 2.4565228159190156e-05f, 3.937008052901092e-09f, 0.0010436123702675104f, 7.74258346325496e-09f, 0.0013457778841257095f, 0.0014453682815656066f, 0.0013325198087841272f, 0.0011747601674869657f, 3.937008052901092e-09f, 0.0017105469014495611f, 0.001135736471042037f, 0.0020537995733320713f, 1.3906894764659228e-06f, 0.0015775099163874984f, 0.0015873804222792387f, 0.0011757906759157777f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.001149641233496368f, 3.937008052901092e-09f, 0.0014224527403712273f, 0.0011767430696636438f, 0.0013123636599630117f, 0.0005469686002470553f, 4.076760160387494e-05f, 3.937008052901092e-09f, 0.0007306295447051525f, 0.0013657092349603772f, 0.0011749578407034278f, 0.001069991267286241f, 0.0008466371218673885f, 1.0301203445806095e-07f, 0.0004007242096122354f, 0.0008561830036342144f, 0.001163274166174233f, 0.0009567465167492628f, 0.0008974465890787542f, 0.0004611410840880126f, 0.00084760005120188f, 3.937008052901092e-09f, 0.0009418124100193381f, 0.0013802536996081471f, 3.937008052901092e-09f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #280 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_124_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 114,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004991966998204589f, 0.006498970091342926f, 0.004877466708421707f, 0.0074134692549705505f, 4.12820081692189e-05f, 0.0047950767911970615f, 0.003715505125001073f, 8.021157555049285e-06f, 0.005655726417899132f, 1.824067453526368e-06f, 0.006415484938770533f, 0.000656294752843678f, 0.005124122370034456f, 0.0018653612351045012f, 0.004619874991476536f, 8.806800178717822e-05f, 3.2682870369171724e-05f, 0.0001764371554600075f, 0.002410943852737546f, 0.0021636898163706064f, 0.0070864190347492695f, 0.0014157111290842295f, 0.0009662600932642817f, 0.001089655444957316f, 0.004754473455250263f, 0.008903119713068008f, 7.282217120518908e-05f, 0.0022026977967470884f, 0.0017180864233523607f, 7.606502549606375e-06f, 0.00036297296173870564f, 0.010978258214890957f, 6.211479922058061e-05f, 0.0035532922483980656f, 3.236238512727141e-07f, 0.005922636017203331f, 0.0018355553038418293f, 0.004334537778049707f, 0.0007590415189042687f, 1.1008718274752027e-06f, 0.00578034482896328f, 0.010854070074856281f, 0.005779969971626997f, 0.0018164856592193246f, 0.004552128724753857f, 0.002286344300955534f, 0.007469736970961094f, 0.0007780377636663616f, 2.0347642930573784e-05f, 0.0011359199415892363f, 2.3879047148511745e-06f, 0.001930799218825996f, 0.0035435042809695005f, 0.011901208199560642f, 0.009783187881112099f, 0.009633023291826248f, 4.4454250200942624e-06f, 0.012582981958985329f, 0.00042034618672914803f, 3.1662635592510924e-05f, 0.006144908256828785f, 8.209996303776279e-05f, 0.0012441048165783286f, 0.0038071502931416035f, 0.0031212172470986843f, 0.009621568955481052f, 0.00011448909208411351f, 3.148707264699624e-06f, 0.004669899120926857f, 7.547829454779276e-07f, 0.014573689550161362f, 0.00019158168288413435f, 5.060792773292633e-06f, 0.01306577492505312f, 1.585627433087211e-05f, 0.0050254217348992825f, 0.007065323181450367f, 0.0025820869486778975f, 0.00773064186796546f, 7.450015800714027e-06f, 0.002340941457077861f, 0.005063924472779036f, 0.007642950862646103f, 2.9956943762954324e-05f, 0.0038366999942809343f, 0.0066211470402777195f, 0.004440730437636375f, 6.3129564296104945e-06f, 2.252076001241221e-06f, 0.004938267637044191f, 2.2966241886024363e-05f, 0.007647031918168068f, 0.003293589921668172f, 0.0025465141516178846f, 0.0014821196673437953f, 0.0002589563955552876f, 7.221870532703178e-07f, 0.002749812323600054f, 0.00793004035949707f, 0.0030912919901311398f, 0.004051085561513901f, 0.004047015216201544f, 6.834138912381604e-05f, 0.00056773133110255f, 0.0014252264518290758f, 0.010151812806725502f, 0.013107948005199432f, 0.004686017520725727f, 0.000310642208205536f, 0.00415415782481432f, 1.8113869373337366e-06f, 0.00439630588516593f, 0.005472161341458559f, 6.395146101567661e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #281 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_125_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014906501164659858f, 0.0013064120430499315f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0012879769783467054f, 0.00112205371260643f, 0.001100038760341704f, 0.0008474542410112917f, 3.937008052901092e-09f, 0.0003126960655208677f, 0.0005405915435403585f, 4.245853002515787e-09f, 0.001793965115211904f, 0.0009381751297041774f, 3.937008052901092e-09f, 0.0012080819578841329f, 1.5038304468362185e-07f, 2.2896284690432367e-07f, 3.937008052901092e-09f, 0.0011400626972317696f, 0.001526851556263864f, 3.937008052901092e-09f, 0.00047155949869193137f, 2.9197847197792726e-06f, 3.937008052901092e-09f, 0.0008734174189157784f, 0.0015981437172740698f, 0.0014769239351153374f, 0.0005691293044947088f, 0.000915141892619431f, 0.0015610450645908713f, 2.2580337599720224e-08f, 0.001701993285678327f, 0.0012303912080824375f, 0.0014354302547872066f, 0.003597636939957738f, 0.001308915438130498f, 0.0012769598979502916f, 0.0008770005661062896f, 0.0009145790245383978f, 0.0013372596586123109f, 0.0005174182588234544f, 3.937008052901092e-09f, 0.0001457458274671808f, 0.0012165019288659096f, 0.0017876924248412251f, 0.0012160094920545816f, 6.425336323445663e-05f, 0.001448106486350298f, 0.001103778718970716f, 9.01032308320282e-06f, 2.485031131982396e-07f, 0.0010382365435361862f, 5.433713479163771e-09f, 0.0002162541204597801f, 1.3590997127721494e-07f, 3.937008052901092e-09f, 0.0015220503555610776f, 0.001380615751259029f, 0.000990798231214285f, 0.0010205472353845835f, 3.937008052901092e-09f, 0.001209584646858275f, 0.0014668776420876384f, 0.0011373978340998292f, 0.0018243846716359258f, 3.2468542485730723e-06f, 1.541436063234869e-06f, 4.0341424210055266e-06f, 0.0009118596790358424f, 3.937008052901092e-09f, 0.000967488915193826f, 0.00034846525522880256f, 3.937008052901092e-09f, 0.0009268613066524267f, 3.937008052901092e-09f, 9.941314601746853e-06f, 0.001534140552394092f, 2.153862396880868e-06f, 3.593062203322006e-08f, 0.001346076838672161f, 0.0006852142396382987f, 0.0008081909036263824f, 3.937008052901092e-09f, 0.0016774360556155443f, 0.0018593070562928915f, 1.665672186845768e-07f, 0.0015275689074769616f, 0.0013471967540681362f, 0.001966465264558792f, 4.5676280535644764e-08f, 3.937008052901092e-09f, 0.001244630548171699f, 0.0008224482880905271f, 0.0015643392689526081f, 7.976846738699805e-09f, 3.937008052901092e-09f, 0.001301617594435811f, 0.0012967209331691265f, 0.001424575923010707f, 0.0013981490628793836f, 0.0009275717893615365f, 9.27463588595856e-06f, 0.001249797991476953f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #282 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_126_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009619440883398056f, 0.009876150637865067f, 3.208666748832911e-05f, 2.6871098270930815e-06f, 0.00507197855040431f, 0.008878963999450207f, 0.00740263843908906f, 0.005294959060847759f, 2.0631557617889484e-06f, 0.0013401374453678727f, 0.0002805425028782338f, 9.73937931121327e-05f, 0.008379044942557812f, 0.0024898378178477287f, 1.0838796242751414e-06f, 0.01027565635740757f, 1.5806577721377835e-05f, 2.4913677407312207e-05f, 1.0209522770310286e-05f, 0.005307964980602264f, 0.012289419770240784f, 3.2723859476391226e-05f, 0.0008298620232380927f, 0.00017905897402670234f, 1.52271377373836e-06f, 0.0018897787667810917f, 0.01112899836152792f, 0.007856398820877075f, 0.0012252586893737316f, 0.0043954928405582905f, 0.009489505551755428f, 4.438938412931748e-05f, 0.005814340431243181f, 0.006644851993769407f, 0.0060656568966805935f, 0.002871426986530423f, 0.005857041571289301f, 0.007652445696294308f, 0.0038250829093158245f, 0.0027391838375478983f, 0.0038567360024899244f, 0.00109941849950701f, 2.7827783924294636e-05f, 0.0005982007132843137f, 0.008878543972969055f, 0.007888480089604855f, 0.008605346083641052f, 0.00018926408665720373f, 0.008846784010529518f, 0.00894819013774395f, 0.0001749994553392753f, 2.5733792426763102e-05f, 0.0034253497142344713f, 3.476281926850788e-05f, 0.0007132188184186816f, 0.0001292884408030659f, 1.255571078218054e-05f, 0.011578438803553581f, 0.005181937478482723f, 0.0036591922398656607f, 0.007787536364048719f, 1.5772915503475815e-05f, 0.008532555773854256f, 0.012348045594990253f, 0.008607743307948112f, 0.0026588551700115204f, 0.0001606027508387342f, 0.00014492179616354406f, 0.000334185577230528f, 0.007485180627554655f, 2.7719522677216446e-06f, 0.0010793344117701054f, 0.0006998887984082103f, 2.570805918367114e-05f, 0.0043034981936216354f, 7.850324436731171e-06f, 0.00025545660173520446f, 0.01114786509424448f, 0.00011841514788102359f, 3.719237429322675e-05f, 0.006377303507179022f, 0.0017943305429071188f, 0.001397359068505466f, 1.297629569307901e-05f, 0.005138191860169172f, 0.003981221932917833f, 2.5690969778224826e-05f, 0.008906565606594086f, 0.00966912042349577f, 0.0077234841883182526f, 1.406644059898099e-05f, 1.4432655007112771e-05f, 0.006757539231330156f, 0.0027717514894902706f, 0.007780242711305618f, 1.6388154108426534e-05f, 3.10684263240546e-05f, 0.009511921554803848f, 0.008674209006130695f, 0.010336916893720627f, 0.005878277122974396f, 0.006894326768815517f, 0.00011589352652663365f, 0.005652355495840311f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #283 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_127_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00048491708002984524f, 0.00046599574852734804f, 0.0005772256408818066f, 3.8681798741890816e-07f, 0.0004809801175724715f, 3.937008052901092e-09f, 0.000598858401644975f, 3.937008052901092e-09f, 1.118123407195526e-07f, 2.2726198949385434e-06f, 0.0005690806428901851f, 3.937008052901092e-09f, 0.0013801592867821455f, 0.0001681141584413126f, 0.0006135993753559887f, 0.0005462461849674582f, 8.26285486255074e-06f, 0.0005766115500591695f, 0.000819191918708384f, 0.0005488739116117358f, 0.0005397226777859032f, 0.0005654621636494994f, 0.0008685120264999568f, 0.0005733260186389089f, 0.0005038513336330652f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0009072737884707749f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0005719196051359177f, 7.786234345985577e-05f, 0.00046985148219391704f, 0.000649305060505867f, 0.0006745489663444459f, 0.0005936353118158877f, 3.937008052901092e-09f, 3.937008052901092e-09f, 5.022799953735557e-09f, 0.0006214097957126796f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.00031665610731579363f, 3.937008052901092e-09f, 0.0006250992882996798f, 5.43312328460388e-09f, 0.0006450793007388711f, 6.8602712417487055e-06f, 3.937008052901092e-09f, 0.0009117209701798856f, 3.937008052901092e-09f, 0.0008240038296207786f, 0.0015525252092629671f, 3.937008052901092e-09f, 0.0004400446778163314f, 1.5300084754699128e-08f, 3.937008052901092e-09f, 0.0006072141113691032f, 3.937008052901092e-09f, 0.0005617050919681787f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0006090909009799361f, 3.937008052901092e-09f, 0.0005743583315052092f, 0.0008243719930760562f, 5.1750109975046144e-08f, 0.000837134022731334f, 0.0005826742271892726f, 0.0008544494048692286f, 3.937008052901092e-09f, 0.0005506976158358157f, 0.0006226844852790236f, 0.0007587950676679611f, 3.937008052901092e-09f, 0.0009470853838138282f, 3.937008052901092e-09f, 0.000564121175557375f, 3.937008052901092e-09f, 0.00014133928925730288f, 3.937008052901092e-09f, 0.0005439679371193051f, 3.937008052901092e-09f, 0.00026386260287836194f, 0.00022391755192074925f, 0.00010049498814623803f, 3.974772698711604e-05f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0010065095266327262f, 1.8585937766602e-07f, 0.00038482644595205784f, 3.937008052901092e-09f, 0.0007163301925174892f, 0.0007869817200116813f, 4.94125274030921e-08f, 3.937008052901092e-09f, 0.0009651474538259208f, 0.0006367432069964707f, 0.00043799448758363724f, 0.0007260948186740279f, 3.937008052901092e-09f, 0.0005430413293652236f, 0.0006405222811736166f, 3.937008052901092e-09f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0007378182490356266f, 0.0006115708383731544f, 0.0007265825988724828f, 3.0921776215109276e-06f, 0.00041680855792947114f, 3.937008052901092e-09f, 0.0006094286218285561f, 3.937008052901092e-09f, 0.0006333725177682936f, 1.635379703657236e-05f, 0.0008267118828371167f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0009239595383405685f, 0.0013322620652616024f, 5.983385199215263e-05f, 0.0008300707559101284f, 3.937008052901092e-09f, 0.0005181518499739468f, 1.3017754554311978e-06f, 0.0007308247731998563f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #284 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_128_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001989025389775634f, 0.013243493624031544f, 0.005885333754122257f, 0.00018927780911326408f, 0.004758060909807682f, 3.2045722946349997e-06f, 0.0076300762593746185f, 3.7613906442857115e-06f, 2.5055916921701282e-05f, 0.00025365076726302505f, 0.007255347911268473f, 1.7479295877365075e-07f, 0.0038694434333592653f, 0.000649469206109643f, 0.005077151581645012f, 0.007884936407208443f, 0.00017965739243663847f, 0.009441101923584938f, 0.012106092646718025f, 0.007235337048768997f, 0.010577194392681122f, 0.009079307317733765f, 0.006272644270211458f, 0.003079261863604188f, 0.007979180663824081f, 3.2350752121601545e-07f, 4.292590176646627e-07f, 0.004161192569881678f, 2.0500227037700824e-05f, 2.233310806332156e-05f, 0.00647951802238822f, 0.00019136063929181546f, 0.0030096606351435184f, 0.007980932481586933f, 0.0073778764344751835f, 0.007970386184751987f, 5.117007458466105e-05f, 1.5925606930977665e-05f, 6.80114608258009e-05f, 0.012247332371771336f, 6.926063633727608e-08f, 2.7838550522574224e-06f, 0.0031234710477292538f, 6.721119279973209e-05f, 0.005012755282223225f, 3.243578612455167e-05f, 0.011368192732334137f, 0.00023554879589937627f, 1.936437229232979e-06f, 0.013700910843908787f, 7.768272189423442e-05f, 0.009377952665090561f, 0.006695588119328022f, 3.181027352638921e-08f, 0.0016001956537365913f, 6.106474756961688e-05f, 2.1661961000063457e-05f, 0.0034784614108502865f, 1.7088941604015417e-06f, 0.011907881125807762f, 1.8300239389645867e-05f, 2.0737725208164193e-06f, 0.01041895616799593f, 6.424250841519097e-06f, 0.005823604762554169f, 0.007886050269007683f, 2.8901882615173236e-05f, 0.0035904019605368376f, 0.0021860187407583f, 0.007457785774022341f, 1.949122997757513e-05f, 0.0015221290523186326f, 0.005521560553461313f, 0.008556169457733631f, 1.4745673979632556e-05f, 0.005730791948735714f, 0.0001158266604761593f, 0.012103056535124779f, 1.615695879308987e-07f, 0.0013554722536355257f, 3.697965439641848e-05f, 0.0036437998060137033f, 2.9539739898609696e-06f, 0.003126041032373905f, 0.0012838809052482247f, 0.0003012691449839622f, 0.0004445463709998876f, 3.802368553351698e-07f, 4.590743571952771e-07f, 0.005304437596350908f, 3.587852552300319e-05f, 0.0009394047083333135f, 2.0737868908327073e-05f, 0.0031756155658513308f, 0.010322997346520424f, 3.493585609248839e-05f, 7.415996350346177e-08f, 0.0036756261251866817f, 0.006212844979017973f, 0.0009574004798196256f, 0.00844163354486227f, 8.314589905467074e-08f, 0.009752031415700912f, 0.010694761760532856f, 7.99424970665541e-09f, 1.13955120468745e-05f, 1.756514575390611e-05f, 0.007634169887751341f, 0.005886134225875139f, 0.009088902734220028f, 0.00011427284334786236f, 0.004028713330626488f, 0.00017712824046611786f, 0.0017032194882631302f, 1.1808344424935058e-05f, 0.0015130973188206553f, 0.0004450177657417953f, 0.005612601991742849f, 4.054990495205857e-05f, 3.270170054747723e-06f, 0.008151222951710224f, 0.006626082584261894f, 0.0006223559030331671f, 0.008433407172560692f, 4.968234179614228e-07f, 0.010497108101844788f, 0.00024066702462732792f, 0.00651670852676034f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #285 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_129_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023311776749324054f, 2.9213158541097073e-06f, 3.194728606104036e-07f, 0.0033828290179371834f, 3.937008052901092e-09f, 0.0010965210385620594f, 0.00021308506256900728f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0014022199902683496f, 3.937008052901092e-09f, 0.00028364232275635004f, 1.1711449587892275e-08f, 0.0014836344635114074f, 0.00066800054628402f, 3.937008052901092e-09f, 0.0007806674111634493f, 0.0007091948064044118f, 1.4797784615439014e-06f, 0.0015510262455791235f, 0.000638635247014463f, 8.597515233077502e-08f, 3.937008052901092e-09f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0014103223802521825f, 0.0007345661288127303f, 0.001547820633277297f, 0.0015701120719313622f, 6.561453483300284e-05f, 0.0009043783647939563f, 0.0017553186044096947f, 0.00013476403546519578f, 0.0010865041986107826f, 0.00129502743948251f, 0.0009473009849898517f, 0.0005886687431484461f, 1.9917290046578273e-05f, 4.42626131302859e-08f, 2.3339982817560667e-06f, 0.0012338552623987198f, 3.937008052901092e-09f, 0.0010864007053896785f, 0.00021603239292744547f, 0.0004869826079811901f, 9.052245877683163e-05f, 3.937008052901092e-09f, 0.001003389130346477f, 0.000610567512921989f, 0.00015389281907118857f, 0.0011485065333545208f, 0.0019352451199665666f, 0.0014844848774373531f, 0.0008245903882198036f, 3.937008052901092e-09f, 0.0012632039142772555f, 3.937008052901092e-09f, 3.972484421410627e-07f, 3.937008052901092e-09f, 3.937008052901092e-09f, 0.0001406537921866402f, 0.00032400363124907017f, 0.0006795247318223119f, 0.0008930475451052189f, 0.0008844468975439668f, 0.0015629082918167114f, 4.6454286461994343e-07f, 3.937008052901092e-09f, 0.0006338185048662126f, 6.020703949616291e-06f, 0.0003296607465017587f, 3.937008052901092e-09f, 0.0014627957716584206f, 0.0007957611232995987f, 3.937008052901092e-09f, 0.0006608028779737651f, 3.937008052901092e-09f, 0.00184809195343405f, 0.0004069833958055824f, 3.937008052901092e-09f, 0.0006203994271345437f, 3.937008052901092e-09f, 0.0007321828161366284f, 0.0011469469172880054f, 0.0012128520756959915f, 0.0012158002937212586f, 0.00020025757839903235f, 6.107281933509512e-07f, 2.5182909666909836e-05f, 5.2956580475438386e-05f, 0.0016231666086241603f, 0.001136026345193386f, 0.0013812992256134748f, 0.0008946191519498825f, 0.00043542540515773f, 0.0003903096658177674f, 0.00031377619598060846f, 0.0008908901363611221f, 0.0008720887708477676f, 0.0007945734541863203f, 0.0007248609908856452f, 3.937008052901092e-09f, 9.17702536185061e-08f, 0.0010412799892947078f, 1.679078741290141e-05f, 1.8396855011815205e-05f, 0.00016623020928818733f, 2.7718175488189445e-07f, 3.937008052901092e-09f, 0.0013424091739580035f, 0.0004033279255963862f, 0.0013452188577502966f, 3.937008052901092e-09f, 0.0006813839427195489f, 0.002028196584433317f, 0.0029715325217694044f, 3.937008052901092e-09f, 1.2062773002696758e-08f, 3.937008052901092e-09f, 0.00032087689032778144f, 3.937008052901092e-09f, 0.0011515486985445023f, 0.0008921301923692226f, 0.0005332715227268636f, 3.937008052901092e-09f, 3.8385439893318107e-07f, 0.001810808083973825f, 3.937008052901092e-09f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #286 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_130_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010190451284870505f, 0.00015197694301605225f, 0.00012543187767732888f, 0.006542650051414967f, 6.291881504694175e-07f, 0.0065043312497437f, 0.0015249480493366718f, 2.1802998162456788e-05f, 4.970251211489085e-06f, 0.011390039697289467f, 6.8308122536109295e-06f, 0.0011100792326033115f, 2.7810085157398134e-05f, 0.0038211154751479626f, 0.0019522332586348057f, 9.842676263360772e-06f, 0.0036782838869839907f, 0.009122537449002266f, 2.1527206627069972e-05f, 0.009709959849715233f, 0.0027750032022595406f, 5.16076797794085e-05f, 1.0821948990269448e-06f, 5.7021548855118454e-05f, 5.1840324033491925e-08f, 0.0058537013828754425f, 0.010115251876413822f, 0.007044599857181311f, 0.006264334544539452f, 0.0002471873303875327f, 0.009014572016894817f, 0.008374443277716637f, 0.0006990543915890157f, 0.008220143616199493f, 0.007896948605775833f, 0.008521833457052708f, 0.002326359273865819f, 0.0003675531770568341f, 9.292391041526571e-06f, 0.00010357656719861552f, 0.00857535284012556f, 6.503538315882906e-06f, 0.005748627707362175f, 0.0006190938875079155f, 0.00407148152589798f, 0.00023494310153182596f, 7.0865198722458445e-06f, 0.008508708328008652f, 0.011281320825219154f, 0.0006326276925392449f, 0.005957865621894598f, 0.009770885109901428f, 0.005242812912911177f, 0.009546459652483463f, 2.144013524230104e-05f, 0.005837776232510805f, 1.7712181943352334e-07f, 0.00012307916767895222f, 3.0770777925681614e-07f, 2.044432949332986e-05f, 0.0003289901069365442f, 0.0015362182166427374f, 0.0019354834221303463f, 0.007901283912360668f, 0.011016836389899254f, 0.005462155677378178f, 8.657939179101959e-05f, 2.3656539838157187e-07f, 0.0019906419329345226f, 0.00016309251077473164f, 0.0005195271223783493f, 2.1296807517501293e-06f, 0.0075574214570224285f, 0.010850409977138042f, 2.155645688617369e-06f, 0.003882521530613303f, 7.618146469212661e-07f, 0.00483576487749815f, 0.0009773331694304943f, 3.3444630389567465e-06f, 0.0020867332350462675f, 4.669108420785051e-06f, 0.005922387819737196f, 0.011695765890181065f, 0.008667591027915478f, 0.0051619731821119785f, 0.0004131541936658323f, 0.00011247674410697073f, 0.0002726776001509279f, 0.0006681490340270102f, 0.0024468430783599615f, 0.008974341675639153f, 0.008422906510531902f, 0.0036979778669774532f, 0.0010152854956686497f, 0.0014824540121480823f, 0.0006888724165037274f, 0.0029375189915299416f, 0.0074061183258891106f, 0.01032499223947525f, 0.003977762535214424f, 2.6925981728709303e-06f, 0.00010612842015689239f, 0.00891235750168562f, 0.00019433525449130684f, 0.00012700987281277776f, 0.0007914049783721566f, 2.0056751964148134e-05f, 3.17735830321908e-05f, 0.008479135110974312f, 0.0014206452760845423f, 0.006510457955300808f, 1.1062961675634142e-06f, 0.004178414586931467f, 0.006753772031515837f, 0.006160118617117405f, 9.429488159184984e-07f, 6.534541898872703e-05f, 2.1302342645412864e-07f, 0.0008607943309471011f, 1.725889705994632e-05f, 0.008129147812724113f, 0.0044908649288117886f, 0.0014429640723392367f, 3.99562895836425e-06f, 0.00014726819063071162f, 0.005665605887770653f, 2.7398862584959716e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #287 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_131_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017577607650309801f, 0.0006220703362487257f, 0.0010962879750877619f, 0.0013002188643440604f, 0.0013565706321969628f, 0.0009894182439893484f, 0.0017699884483590722f, 0.0011469392338767648f, 0.0015893344534561038f, 0.0005964910960756242f, 0.0011442947434261441f, 0.001666797325015068f, 0.0015276806661859155f, 0.001014136360026896f, 0.0011489493772387505f, 0.0011265997309237719f, 0.0014191422378644347f, 0.00133022281806916f, 0.001200585626065731f, 0.0013925513485446572f, 0.0017698222072795033f, 0.0010829617967829108f, 0.0013075523311272264f, 0.001736902049742639f, 0.0008707273518666625f, 0.0012465670006349683f, 0.0011075286893174052f, 0.0013024462386965752f, 0.0012879450805485249f, 0.00020815983589272946f, 0.00039782788371667266f, 0.0007779701263643801f, 3.323898454254959e-07f, 0.0013866410590708256f, 0.001994243822991848f, 0.0012148452224209905f, 0.0016942784423008561f, 0.002149061532691121f, 0.0008781282231211662f, 0.001102154841646552f, 0.001330016297288239f, 0.0007776774000376463f, 0.0009078510338440537f, 0.0014996976824477315f, 0.0002780817449092865f, 0.0013065345119684935f, 0.0013277968391776085f, 0.0012677822960540652f, 0.0016261751297861338f, 3.937008052901092e-09f, 0.003335080109536648f, 0.0010817204602062702f, 0.0013004826614633203f, 5.1979128329548985e-05f, 4.711198986484533e-09f, 5.7446366554358974e-05f, 0.0016385972267016768f, 0.0010652109049260616f, 0.0006471003289334476f, 0.0012642459478229284f, 0.001301495241932571f, 0.0014853549655526876f, 0.0013317528646439314f, 3.937008052901092e-09f, 0.002162543125450611f, 0.0012495012488216162f, 0.0012425535824149847f, 0.001763335196301341f, 0.0016047429526224732f, 0.0015827238094061613f, 0.0015142016345635056f, 3.6259727664855745e-08f, 0.0012980859028175473f, 0.0015077036805450916f, 0.0014887809520587325f, 0.001385303563438356f, 3.6013614135299576e-06f, 0.00016683887224644423f, 0.0012485611950978637f, 0.0013121927622705698f, 0.0012385209556668997f, 0.0010367350187152624f, 0.0014220926677808166f, 0.0009764971910044551f, 3.358537242093007e-06f, 0.0013003782369196415f, 0.00042630478856153786f, 0.0011050160974264145f, 0.00013510804274119437f, 4.23953450123804e-09f, 0.0013418601593002677f, 0.00030661546043120325f, 0.0017258928855881095f, 0.0016840373864397407f, 0.0011535048251971602f, 0.0012957688886672258f, 0.0009298417717218399f, 0.0012191315181553364f, 0.0002542854053899646f, 0.0015601387713104486f, 0.000706265855114907f, 0.001252557267434895f, 0.00018605183868203312f, 0.001933099003508687f, 0.0009759744862094522f, 0.0013949124841019511f, 0.0007797823054715991f, 0.0013035107403993607f, 0.0007068851846270263f, 0.0012778214877471328f, 1.2668300541918143e-06f, 0.0011673900298774242f, 0.0009948724182322621f, 0.0013884985819458961f, 0.0015852589858695865f, 0.0011359528871253133f, 1.178874936158536e-05f, 0.0012452808441594243f, 0.0012688039569184184f, 0.0007792935357429087f, 0.0015649358974769711f, 0.0004834600258618593f, 0.002763914642855525f, 0.0010236953385174274f, 0.00029816091409884393f, 0.001421445282176137f, 0.0012095579877495766f, 0.001302411430515349f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #288 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_132_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007462092209607363f, 0.002625206718221307f, 0.007810418959707022f, 0.005612962879240513f, 0.004957870114594698f, 0.008331689052283764f, 0.005169374868273735f, 0.002232102444395423f, 0.005103700328618288f, 0.001237177406437695f, 0.00740235997363925f, 0.007376777473837137f, 0.00889556109905243f, 0.006575418170541525f, 0.004235179163515568f, 0.002488002646714449f, 0.0017825807444751263f, 0.0024924802128225565f, 0.007189671974629164f, 0.008020208217203617f, 0.006841757800430059f, 0.0019075158052146435f, 0.008060849271714687f, 0.00819073710590601f, 0.0022220725659281015f, 0.004096447955816984f, 0.00561765069141984f, 0.008605851791799068f, 0.005368300713598728f, 0.001412886194884777f, 0.000652866845484823f, 0.0025418091099709272f, 5.040506221121177e-05f, 0.007926971651613712f, 0.0020952431950718164f, 0.008247395977377892f, 0.005063832737505436f, 0.0073411972261965275f, 0.0008403857937082648f, 0.00718622887507081f, 0.007908731698989868f, 0.0008685081265866756f, 0.0037802704609930515f, 0.0070661199279129505f, 0.0005675653810612857f, 0.0051742903888225555f, 0.008865945972502232f, 0.008183808997273445f, 0.007687481120228767f, 4.142091256653657e-06f, 0.007686562370508909f, 0.0022732254583388567f, 0.006762275006622076f, 0.0001961839006980881f, 8.666637586429715e-05f, 0.0004177770751994103f, 0.00801339466124773f, 0.0028604783583432436f, 0.0008081841515377164f, 0.006714295595884323f, 0.006876497995108366f, 0.003219793550670147f, 0.007830956019461155f, 2.9399077902780846e-05f, 0.005805608816444874f, 0.007886882871389389f, 0.009432808496057987f, 0.004164367448538542f, 0.00751742348074913f, 0.008622507564723492f, 0.00927620567381382f, 2.7924232199438848e-05f, 0.0016223550774157047f, 0.0021626742091029882f, 0.008190704509615898f, 0.006933302618563175f, 0.0002246713120257482f, 0.00028100833878852427f, 0.0011087782913818955f, 0.0019737323746085167f, 0.0054904441349208355f, 0.0019277224782854319f, 0.007790614850819111f, 0.004571182187646627f, 0.00028601670055650175f, 0.007521738763898611f, 0.0007447422831319273f, 0.007266813889145851f, 0.00035345644573681056f, 2.9820417694281787e-05f, 0.006979858502745628f, 0.0005732900463044643f, 0.014574014581739902f, 0.006746549159288406f, 0.006044996902346611f, 0.008574940264225006f, 0.002136483322829008f, 0.008304017595946789f, 0.0005662782350555062f, 0.005760959815233946f, 0.0012369763571769f, 0.008496958762407303f, 0.0004115490592084825f, 0.010450460948050022f, 0.0071824705228209496f, 0.009112940169870853f, 0.0015590650727972388f, 0.008446333929896355f, 0.001216100761666894f, 0.0070016528479754925f, 9.937341383192688e-05f, 0.004679699894040823f, 0.0040843249298632145f, 0.007699775043874979f, 0.010512578301131725f, 0.00787014327943325f, 0.00028249467140994966f, 0.007438800763338804f, 0.004413464106619358f, 0.000988363055512309f, 0.0073415073566138744f, 0.0004646505112759769f, 0.00675603561103344f, 0.008419642224907875f, 0.0012367768213152885f, 0.0015213353326544166f, 0.009251383133232594f, 0.003480159677565098f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #289 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_133_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 25,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005155514809302986f, 0.0005031928885728121f, 0.0007466343813575804f, 0.0004517450579442084f, 0.0006251517916098237f, 0.0008631214732304215f, 0.0011146760080009699f, 0.0003761936095543206f, 0.0006901966407895088f, 0.0010986636625602841f, 0.0006093223346397281f, 0.0009027215419337153f, 0.0003423358721192926f, 0.00037839828291907907f, 0.0007850147085264325f, 0.000789826619438827f, 0.0010520888026803732f, 0.0003834915696643293f, 0.0003795248921960592f, 0.0009273599134758115f, 0.00041737500578165054f, 0.0005165265174582601f, 0.0009044442558661103f, 0.0007738807471469045f, 0.000527343014255166f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #290 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_138_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035086676944047213f, 0.0013653341447934508f, 0.003198712132871151f, 0.0010078402701765299f, 6.120203761383891e-05f, 0.0016942010261118412f, 0.005566070321947336f, 0.001731634489260614f, 0.0009745426941663027f, 6.51540030958131e-05f, 0.0026037527713924646f, 0.0032778538297861814f, 0.004588011652231216f, 0.00046813159133307636f, 0.00036272298893891275f, 0.0023763214703649282f, 0.00034998750197701156f, 0.00019860458269249648f, 0.003908435348421335f, 0.003147613722831011f, 0.005223464220762253f, 0.001190036186017096f, 0.0006958797457627952f, 0.0029448033310472965f, 0.00020095673971809447f, 0.0014088170137256384f, 0.0007787384674884379f, 0.003265030449256301f, 0.0008672176627442241f, 8.775768947089091e-05f, 1.4092941000853898e-06f, 0.0001679076231084764f, 0.00013489797129295766f, 0.0021386430598795414f, 0.0019064453663304448f, 0.0018959572771564126f, 0.0023335288278758526f, 0.0018925167387351394f, 0.006048158276826143f, 0.0009855760727077723f, 0.003302027005702257f, 7.586793799418956e-06f, 0.0007277801050804555f, 0.004389950539916754f, 0.0003138170868624002f, 0.0007987568387761712f, 0.0020825897809118032f, 0.0040080067701637745f, 0.003092240309342742f, 1.6544959180464502e-07f, 0.0037385825999081135f, 0.0007131801685318351f, 0.0033988661598414183f, 2.3629522161172645e-07f, 3.937008052901092e-09f, 4.030003765365109e-05f, 0.0036718235351145267f, 0.0005899575189687312f, 2.3516424334957264e-05f, 0.004220372065901756f, 0.0041520120576024055f, 0.0002756436006166041f, 0.0026753393467515707f, 3.723894042195752e-05f, 0.00025382410967722535f, 0.004815271589905024f, 0.005171698052436113f, 0.00043600352364592254f, 0.0006071949028410017f, 0.0009344866848550737f, 0.005814084317535162f, 2.3492797481594607e-05f, 5.352475636755116e-05f, 0.0031596114858984947f, 0.0029832322616130114f, 0.0043401760049164295f, 2.7842997951665893e-07f, 1.0342739187763073e-05f, 0.00021595158614218235f, 0.0001504566753283143f, 0.003184193279594183f, 7.600476237712428e-05f, 0.0012077305000275373f, 0.0002476650115568191f, 9.74064096226357e-06f, 0.0015308280708268285f, 0.000139235271490179f, 0.0032454472966492176f, 6.781786942156032e-05f, 2.7413207703830267e-07f, 0.003911752253770828f, 6.515922450489597e-06f, 0.0004619048268068582f, 0.0004275380924809724f, 0.0019982352387160063f, 0.005027941428124905f, 0.0002999250136781484f, 0.0031082306522876024f, 6.181696790008573e-06f, 0.00011965253361267969f, 0.00011893526971107349f, 0.004202545154839754f, 2.609609168757743e-07f, 0.0013246453600004315f, 0.003624273929744959f, 0.0011635577538982034f, 0.001422025845386088f, 0.0034721449483186007f, 7.305140024982393e-05f, 0.0008825463592074811f, 1.6373085145460209e-06f, 0.0004001449851784855f, 0.00018150181858800352f, 0.0025367513298988342f, 0.001468481495976448f, 0.005019365344196558f, 6.122082413639873e-05f, 0.005118084140121937f, 0.002514207037165761f, 0.00013122448581270874f, 0.0018274518661201f, 9.590036643203348e-05f, 0.0012429035268723965f, 0.0004575034836307168f, 6.588369433302432e-05f, 7.648632163181901e-06f, 0.004343029577285051f, 0.0003505697241052985f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #291 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_139_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 20,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009239526116289198f, 0.0009593351860530674f, 0.0009306178544647992f, 0.001028387458063662f, 0.001115939230658114f, 0.0007170331664383411f, 0.0011075444053858519f, 0.0008240581373684108f, 0.001140741747803986f, 0.0010049747070297599f, 0.0007452238933183253f, 0.001103693270124495f, 0.0006061631138436496f, 0.0010210282634943724f, 0.0006688167341053486f, 0.0009985985234379768f, 0.0009564990759827197f, 0.0009313970804214478f, 0.0010325080947950482f, 0.0010351863456889987f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #292 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_153_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029211868532001972f, 0.004454274661839008f, 0.0035398590844124556f, 0.0026043818797916174f, 0.0031250196043401957f, 0.002336276927962899f, 0.0039495243690907955f, 0.004229718819260597f, 0.0032726763747632504f, 0.0022816206328570843f, 0.001724171917885542f, 0.0018679590430110693f, 0.002445296151563525f, 0.002539378125220537f, 0.0032349424436688423f, 0.004608506336808205f, 0.001786777633242309f, 0.0036247766111046076f, 0.002380174584686756f, 0.0025739099364727736f, 0.0015950119122862816f, 0.00240820599719882f, 0.003894046414643526f, 0.004296182654798031f, 0.005237364675849676f, 0.006567510776221752f, 0.004165368620306253f, 0.00322921434417367f, 0.0029734650161117315f, 0.0031384152825921774f, 0.0038118448574095964f, 0.004021709319204092f, 0.003818361321464181f, 0.004108899738639593f, 0.003206453751772642f, 0.0059940507635474205f, 0.004072860348969698f, 0.0032302560284733772f, 0.0026685381308197975f, 0.0030524430330842733f, 0.0034300507977604866f, 0.0024183224886655807f, 0.002642207546159625f, 0.0018961317837238312f, 0.002083116676658392f, 0.004138421267271042f, 0.001846482278779149f, 0.004624319262802601f, 0.0023508495651185513f, 0.003635491244494915f, 0.004376579076051712f, 0.0018300533993169665f, 0.004243121948093176f, 0.004408122040331364f, 0.004243168514221907f, 0.0026897878851741552f, 0.003144671209156513f, 0.002777649322524667f, 0.0019069814588874578f, 0.0037262116093188524f, 0.0036606788635253906f, 0.0030973684042692184f, 0.003130947705358267f, 0.0024920161813497543f, 0.0029099569655954838f, 0.0038483610842376947f, 0.0024473771918565035f, 0.0021202214993536472f, 0.002725067548453808f, 0.0036008385941386223f, 0.004204275086522102f, 0.0020794388838112354f, 0.0025874455459415913f, 0.0026815535966306925f, 0.001788461348041892f, 0.0022714554797858f, 0.0035129499156028032f, 0.0027259192429482937f, 0.0036940043792128563f, 0.00312443939037621f, 0.004151139408349991f, 0.0032652379013597965f, 0.004025920294225216f, 0.0029910660814493895f, 0.003617643378674984f, 0.003987021278589964f, 0.002798382192850113f, 0.003770782146602869f, 0.00387124833650887f, 0.0035059615038335323f, 0.0030874437652528286f, 0.0032060351222753525f, 0.002120428951457143f, 0.0019779852591454983f, 0.002213862957432866f, 0.0029385043308138847f, 0.0042870803736150265f, 0.0026489037554711103f, 0.0021897880360484123f, 0.00384000176563859f, 0.003499476471915841f, 0.0031279230024665594f, 0.005495742429047823f, 0.00239472184330225f, 0.0032645566388964653f, 0.003535419935360551f, 0.0030927748885005713f, 0.0028312120120972395f, 0.002420242642983794f, 0.0028282664716243744f, 0.00719789881259203f, 0.004362397827208042f, 0.005223372485488653f, 0.0022286029998213053f, 0.0038186227902770042f, 0.0035159909166395664f, 0.0042424448765814304f, 0.0018772140610963106f, 0.005701952148228884f, 0.003607988590374589f, 0.005060309078544378f, 0.002209751633927226f, 0.0035612396895885468f, 0.0027550491504371166f, 0.0028092453721910715f, 0.0019215247593820095f, 0.00422459002584219f, 0.0019676578231155872f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #293 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_154_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013138855574652553f, 0.0010798494331538677f, 0.0016602675896137953f, 0.0011171469232067466f, 0.001365358941257f, 0.0013123222161084414f, 0.0009904420003294945f, 0.0014693420380353928f, 0.00105810456443578f, 0.001010460196994245f, 0.0014879811787977815f, 0.0014975734520703554f, 0.0013754976680502295f, 0.0012566500809043646f, 0.0012930319644510746f, 0.0015919003635644913f, 0.0016132439486682415f, 0.001483374391682446f, 0.0015604814980179071f, 0.001604342949576676f, 0.0019214787753298879f, 0.0013534672325477004f, 0.0015020264545455575f, 0.0014354418963193893f, 0.0012638791231438518f, 0.0011892387410625815f, 0.001486556138843298f, 0.0021044465247541666f, 0.001543481252156198f, 0.0012284008553251624f, 0.0010902095818892121f, 0.0016327729681506753f, 0.0012107730144634843f, 0.0014957527164369822f, 0.0016045408556237817f, 0.0015494805993512273f, 0.001265917089767754f, 0.0009044272010214627f, 0.0018703090026974678f, 0.0011364311212673783f, 0.0012303161201998591f, 0.0012282388051971793f, 0.0013415158027783036f, 0.001847045379690826f, 0.0015469308709725738f, 0.0020845921244472265f, 0.0009842364815995097f, 0.0013568871654570103f, 0.0012733215698972344f, 0.0013636504299938679f, 0.0017000274965539575f, 0.001371294492855668f, 0.0011746793752536178f, 0.0013229458127170801f, 0.001297135604545474f, 0.001012244843877852f, 0.001477162353694439f, 0.0015375259099528193f, 0.0012641634093597531f, 0.0012514349073171616f, 0.001566465594805777f, 0.0011208356590941548f, 0.0015048105269670486f, 0.00133719970472157f, 0.0012988331727683544f, 0.001659204252064228f, 0.0012511012610048056f, 0.0010434844298288226f, 0.0020187371410429478f, 0.0012329366290941834f, 0.0017355344025418162f, 0.0014447496505454183f, 0.0014236512361094356f, 0.001373847364448011f, 0.0016128078568726778f, 0.0011999012203887105f, 0.0009422342991456389f, 0.0023002871312201023f, 0.0013992897002026439f, 0.0020006271079182625f, 0.0016001437325030565f, 0.0011543112341314554f, 0.001571100321598351f, 0.0012590002734214067f, 0.0012383242137730122f, 0.001323241158388555f, 0.0010625721188262105f, 0.0012439098209142685f, 0.000793000974226743f, 0.001490181079134345f, 0.0019424299243837595f, 0.0015242137014865875f, 0.0013074170565232635f, 0.0010880198096856475f, 0.0009950469247996807f, 0.0012967378133907914f, 0.0013775336556136608f, 0.001836815383285284f, 0.0015360336983576417f, 0.0013419663300737739f, 0.0012157874880358577f, 0.001458148704841733f, 0.0012472261441871524f, 0.0014124501030892134f, 0.0015302716055884957f, 0.0017365796957165003f, 0.0012244397075846791f, 0.0012727935099974275f, 0.0013892055721953511f, 0.0011579233687371016f, 0.0014777012402191758f, 0.0015078537398949265f, 0.0009054022957570851f, 0.0011486896546557546f, 0.0012741874670609832f, 0.001325475750491023f, 0.001122824614867568f, 0.0012781718978658319f, 0.0010707246838137507f, 0.0018019783310592175f, 0.0011830703588202596f, 0.001654143794439733f, 0.0010590715100988746f, 0.0015835543163120747f, 0.0013618046650663018f, 0.001308615319430828f, 0.0014675611164420843f, 0.0015441114082932472f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #294 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_155_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0048758406192064285f, 0.004762588068842888f, 0.004947687964886427f, 0.005514263641089201f, 0.00358379865065217f, 0.008965821005403996f, 0.003981155343353748f, 0.008681109175086021f, 0.006823597010225058f, 0.005667662713676691f, 0.006159170065075159f, 0.0074287173338234425f, 0.00527716102078557f, 0.0042718760669231415f, 0.005378926172852516f, 0.006027768831700087f, 0.004008088260889053f, 0.004197875503450632f, 0.006816294509917498f, 0.005751340184360743f, 0.006666187662631273f, 0.004622247535735369f, 0.00591749744489789f, 0.005700773559510708f, 0.008047454990446568f, 0.0065989200957119465f, 0.003971726167947054f, 0.0059898304753005505f, 0.008683360181748867f, 0.013429521583020687f, 0.00673489086329937f, 0.0050907437689602375f, 0.007732589729130268f, 0.004654885269701481f, 0.005157484672963619f, 0.0038420341443270445f, 0.0036466761957854033f, 0.008523287251591682f, 0.004800535272806883f, 0.010323339141905308f, 0.0037963050417602062f, 0.004866600036621094f, 0.005863295868039131f, 0.005358519032597542f, 0.0043797567486763f, 0.00589350238442421f, 0.00838859099894762f, 0.006835103500634432f, 0.008726816624403f, 0.007934889756143093f, 0.003186445916071534f, 0.005034649278968573f, 0.0051396009512245655f, 0.004297348205000162f, 0.004945635329931974f, 0.005236818455159664f, 0.006747819017618895f, 0.006768794264644384f, 0.005461649503558874f, 0.003776637837290764f, 0.004790922161191702f, 0.006317498628050089f, 0.0035889078862965107f, 0.0066503980197012424f, 0.0054310401901602745f, 0.0053493850864470005f, 0.0068352664820849895f, 0.00697499793022871f, 0.006341784726828337f, 0.009718254208564758f, 0.004754784982651472f, 0.004870088770985603f, 0.007993392646312714f, 0.005482567474246025f, 0.007197482977062464f, 0.007776790764182806f, 0.0069521148689091206f, 0.007654066197574139f, 0.003952063154429197f, 0.0034478818997740746f, 0.0059595718048512936f, 0.004345103166997433f, 0.005917372647672892f, 0.004671828355640173f, 0.008065124042332172f, 0.008009667508304119f, 0.008967502973973751f, 0.005318494979292154f, 0.007894310168921947f, 0.005777666345238686f, 0.005808303132653236f, 0.006477240473031998f, 0.00931271631270647f, 0.006649380084127188f, 0.006837356369942427f, 0.006191494408994913f, 0.0042615290731191635f, 0.005003736354410648f, 0.005467396695166826f, 0.006195260211825371f, 0.012440389022231102f, 0.006970294751226902f, 0.005523128435015678f, 0.005369723774492741f, 0.006880311761051416f, 0.004091871436685324f, 0.007673047482967377f, 0.006218228954821825f, 0.007030102424323559f, 0.0032826580572873354f, 0.005897854920476675f, 0.006394047290086746f, 0.0068147554993629456f, 0.008944284170866013f, 0.009690336883068085f, 0.0040537575259804726f, 0.0045843301340937614f, 0.00923553854227066f, 0.00442402483895421f, 0.007686291821300983f, 0.006434893701225519f, 0.009103643707931042f, 0.01212068647146225f, 0.005999808199703693f, 0.005638345144689083f, 0.00289028394035995f, 0.004017626401036978f, 0.006610204931348562f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #295 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_156_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013376888819038868f, 0.0018593664281070232f, 0.0016525815008208156f, 0.0009209769777953625f, 0.001143772155046463f, 0.0009493771940469742f, 0.0008129041525535285f, 0.0013735747197642922f, 0.0017288941890001297f, 0.0009545366046950221f, 0.00102889200206846f, 0.0008307418902404606f, 0.0012630585115402937f, 0.0014039286179468036f, 0.0010975049808621407f, 0.002122350502759218f, 0.0013893996365368366f, 0.002139348303899169f, 0.0012045922921970487f, 0.0013061822392046452f, 0.001583970501087606f, 0.0015283201355487108f, 0.0010223828721791506f, 0.001080047688446939f, 0.0007816558936610818f, 0.0009970031678676605f, 0.0014303068164736032f, 0.0016140106599777937f, 0.0010184001876041293f, 0.001212222152389586f, 0.0014992983778938651f, 0.0014267723308876157f, 0.0013833158882334828f, 0.001202272716909647f, 0.001063880161382258f, 0.0012881779111921787f, 0.0010821260511875153f, 0.0019160016672685742f, 0.001409844495356083f, 0.0014766240492463112f, 0.0013298591366037726f, 0.0010405959328636527f, 0.0013124069664627314f, 0.0011226418428122997f, 0.0012532692635431886f, 0.0010574724292382598f, 0.0016609170706942677f, 0.0009430095087736845f, 0.0017869890434667468f, 0.0015248185954988003f, 0.001576695591211319f, 0.001018609618768096f, 0.001267563202418387f, 0.0016752907540649176f, 0.0013644372811540961f, 0.0004883307847194374f, 0.0014874390326440334f, 0.001222211983986199f, 0.0017072573537006974f, 0.0014178776182234287f, 0.0016593269538134336f, 0.0016220742836594582f, 0.0017205309122800827f, 0.0016712426440790296f, 0.0018842974677681923f, 0.00119503540918231f, 0.001166699337773025f, 0.001628920086659491f, 0.001087354845367372f, 0.001077999360859394f, 0.0008846372365951538f, 0.001218048739247024f, 0.0012459519784897566f, 0.0016785142943263054f, 0.0016513370210304856f, 0.0009810746414586902f, 0.0011108777252957225f, 0.0014207528438419104f, 0.0006730837048962712f, 0.001089116558432579f, 0.0015139930183067918f, 0.0013174525229260325f, 0.0010595876956358552f, 0.0012740627862513065f, 0.0012728861765936017f, 0.001132652279920876f, 0.0013086771359667182f, 0.0009690034203231335f, 0.001411703764460981f, 0.0014243840705603361f, 0.0013487765099853277f, 0.0010050785494968295f, 0.0015422209398820996f, 0.001783435931429267f, 0.0010105245746672153f, 0.0014572304207831621f, 0.0018250306602567434f, 0.0014202623860910535f, 0.0017066090367734432f, 0.0015117856673896313f, 0.0016288902843371034f, 0.0013084172969684005f, 0.0015263340901583433f, 0.0010385231580585241f, 0.0011032193433493376f, 0.000826949137263f, 0.0015339548699557781f, 0.001067859586328268f, 0.0010989293223246932f, 0.001182675827294588f, 0.0014999163104221225f, 0.0016297331312671304f, 0.0008687209920026362f, 0.001385362702421844f, 0.001763219479471445f, 0.001355313346721232f, 0.0011965479934588075f, 0.0013612461043521762f, 0.001373058883473277f, 0.0016431751428171992f, 0.0017053098417818546f, 0.0008192472741939127f, 0.0018593500135466456f, 0.0010184432612732053f, 0.0021021245047450066f, 0.001017419621348381f, 0.0011909357272088528f, 0.0019475395092740655f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #296 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_157_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003791637485846877f, 0.007635382004082203f, 0.007984643802046776f, 0.0047913119196891785f, 0.005778531543910503f, 0.010464946739375591f, 0.004095826763659716f, 0.004907941445708275f, 0.0045693195424973965f, 0.0051299999468028545f, 0.004985598381608725f, 0.013375373557209969f, 0.00565467169508338f, 0.008152122609317303f, 0.004611289594322443f, 0.008023177273571491f, 0.007239208556711674f, 0.009670891799032688f, 0.005484770052134991f, 0.009750095196068287f, 0.008448116481304169f, 0.007145016919821501f, 0.009340142831206322f, 0.007493059616535902f, 0.019910097122192383f, 0.0037301017437130213f, 0.007577317301183939f, 0.008613221347332f, 0.004216758068650961f, 0.007976798340678215f, 0.009190121665596962f, 0.010387291200459003f, 0.007658045738935471f, 0.009256101213395596f, 0.0162152498960495f, 0.007501894608139992f, 0.005658616777509451f, 0.006455417722463608f, 0.004199619870632887f, 0.008628109470009804f, 0.006761386524885893f, 0.009128893725574017f, 0.013364695943892002f, 0.005959704052656889f, 0.006085684988647699f, 0.005535966716706753f, 0.0065086656250059605f, 0.012330874800682068f, 0.005878529977053404f, 0.01113809458911419f, 0.0030227270908653736f, 0.0061278268694877625f, 0.006882683839648962f, 0.004997539333999157f, 0.009402679279446602f, 0.06889557838439941f, 0.006404188461601734f, 0.003989463672041893f, 0.008742304518818855f, 0.006715078372508287f, 0.0068858107551932335f, 0.0066032400354743f, 0.011281896382570267f, 0.0055302223190665245f, 0.005100863054394722f, 0.00497555872425437f, 0.007649871055036783f, 0.006618923507630825f, 0.008676516823470592f, 0.010651775635778904f, 0.006127700675278902f, 0.006191331427544355f, 0.004267123993486166f, 0.006385054439306259f, 0.005837537348270416f, 0.011686727404594421f, 0.0063852183520793915f, 0.003671097569167614f, 0.007722655311226845f, 0.005399427376687527f, 0.003293770831078291f, 0.009055115282535553f, 0.008603776805102825f, 0.0068516856990754604f, 0.008165705017745495f, 0.0063369013369083405f, 0.007179835811257362f, 0.004921937361359596f, 0.0065477825701236725f, 0.00855040829628706f, 0.005716764368116856f, 0.008399149402976036f, 0.007004796527326107f, 0.004533556755632162f, 0.011159500107169151f, 0.006656907964497805f, 0.005443204194307327f, 0.012993784621357918f, 0.005496145226061344f, 0.003862173995003104f, 0.006705723237246275f, 0.004259238485246897f, 0.010761595331132412f, 0.005338330753147602f, 0.006695250980556011f, 0.005552820395678282f, 0.006391420494765043f, 0.005604247562587261f, 0.005335573107004166f, 0.004499631002545357f, 0.0065935635939240456f, 0.006891083437949419f, 0.01358644850552082f, 0.0060024568811059f, 0.008467170409858227f, 0.006741470657289028f, 0.010561618953943253f, 0.0041982452385127544f, 0.007908623665571213f, 0.00688697025179863f, 0.003523043356835842f, 0.0064638471230864525f, 0.007095726672559977f, 0.005237695295363665f, 0.0072624580934643745f, 0.008564104326069355f, 0.006576932966709137f, 0.006636757403612137f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #297 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_158_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0016195120988413692f, 0.0015656966716051102f, 0.001233540358953178f, 0.0008469957974739373f, 0.001802815473638475f, 0.0009139428730122745f, 0.0017925022402778268f, 0.0013085735263302922f, 0.0011341723147779703f, 0.0017526218434795737f, 0.0022191726602613926f, 0.00109350576531142f, 0.0013130790321156383f, 0.0020179159473627806f, 0.0011803979286924005f, 0.001083540846593678f, 0.0011206973576918244f, 0.0009040134609676898f, 0.0006984855863265693f, 0.00209341524168849f, 0.000958294200245291f, 0.0012278740759938955f, 0.0013424776261672378f, 0.0012087344657629728f, 0.0015021666185930371f, 0.0023370019625872374f, 0.0013712665531784296f, 0.0006901695160195231f, 0.0007557919016107917f, 0.0013815159909427166f, 0.002301483880728483f, 0.001582419266924262f, 0.0006978489691391587f, 0.0011148493504151702f, 0.0016207080334424973f, 0.0009683026582933962f, 0.0006678677746094763f, 0.0006928166840225458f, 0.0009061475866474211f, 0.0016319133574143052f, 0.0015387532766908407f, 0.0018467832123860717f, 0.0014140922576189041f, 0.0010531189618632197f, 0.0008095891098491848f, 0.0009664515964686871f, 0.0012019895948469639f, 0.0008374660392291844f, 0.0007918744813650846f, 0.001088419696316123f, 0.0016049450496211648f, 0.0012248281855136156f, 0.0008285302319563925f, 0.0009956624126061797f, 0.0019132404122501612f, 0.0018261632649227977f, 0.0016685201553627849f, 0.0008305499795824289f, 0.0006865600007586181f, 0.002295770449563861f, 0.002166128484532237f, 0.000800683512352407f, 0.001021142932586372f, 0.0009395726374350488f, 0.0012731436872854829f, 0.0010205936850979924f, 0.00060759496409446f, 0.002247249474748969f, 0.0012582405470311642f, 0.001685302471742034f, 0.001955609768629074f, 0.0006638341001234949f, 0.0015575645957142115f, 0.0010938411578536034f, 0.0006608430412597954f, 0.0005939751863479614f, 0.0007487019756808877f, 0.0013860684121027589f, 0.0013832910917699337f, 0.001141275279223919f, 0.0012555975699797273f, 0.0016467897221446037f, 0.0018054863903671503f, 0.002326940419152379f, 0.0015782798873260617f, 0.0013162659015506506f, 0.00205311574973166f, 0.0013117691269144416f, 0.0014830525033175945f, 0.0012938851723447442f, 0.0017281707841902971f, 0.002274038502946496f, 0.0013186995638534427f, 0.0019118437776342034f, 0.001371313352137804f, 0.0014160877326503396f, 0.0010766980703920126f, 0.001085277646780014f, 0.0012192415306344628f, 0.001073910971172154f, 0.0011524336878210306f, 0.0009846427710726857f, 0.0017780145863071084f, 0.0009659335482865572f, 0.0006692314054816961f, 0.0009042968740686774f, 0.0017800021450966597f, 0.0013430906692519784f, 0.0010961875086650252f, 0.0006204179371707141f, 0.0018485015025362372f, 0.0006863989401608706f, 0.0016791775124147534f, 0.0015280672814697027f, 0.0012355069629848003f, 0.0012231537839397788f, 0.0018740086816251278f, 0.001247718813829124f, 0.0014521174598485231f, 0.001400651060976088f, 0.0009846891043707728f, 0.0016408484661951661f, 0.0019548030104488134f, 0.0016153431497514248f, 0.0007214471697807312f, 0.0010986393317580223f, 0.0006353513454087079f, 0.0011607982451096177f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #298 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_159_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011242183856666088f, 0.006955986842513084f, 0.0046606967225670815f, 0.003496085526421666f, 0.006016640458256006f, 0.02294057235121727f, 0.008973109535872936f, 0.013263397850096226f, 0.007570045068860054f, 0.0038783864583820105f, 0.005880344659090042f, 0.010197628289461136f, 0.004507648292928934f, 0.008073481731116772f, 0.005845955107361078f, 0.008153032511472702f, 0.005832120776176453f, 0.005097550339996815f, 0.008625020273029804f, 0.005527413450181484f, 0.006037241779267788f, 0.01385564636439085f, 0.004380856640636921f, 0.007484812755137682f, 0.004272529389709234f, 0.006096923258155584f, 0.0061369785107672215f, 0.010781857185065746f, 0.007439184468239546f, 0.006919560953974724f, 0.005070289131253958f, 0.0045939721167087555f, 0.012077773921191692f, 0.00704962108284235f, 0.007772019132971764f, 0.00323309819214046f, 0.008144871331751347f, 0.005760028026998043f, 0.013306381180882454f, 0.009091392159461975f, 0.007397964131087065f, 0.0059647406451404095f, 0.007220723200589418f, 0.00457991287112236f, 0.014821802265942097f, 0.009620937518775463f, 0.010189810767769814f, 0.004663406405597925f, 0.009249191731214523f, 0.005014530383050442f, 0.01183605007827282f, 0.004737055394798517f, 0.0059768748469650745f, 0.0036640872713178396f, 0.006371174938976765f, 0.013722438365221024f, 0.005212015472352505f, 0.008261283859610558f, 0.003916664980351925f, 0.00345837464556098f, 0.008470620959997177f, 0.018552133813500404f, 0.0059445262886583805f, 0.0062405685894191265f, 0.005258152727037668f, 0.005771739408373833f, 0.010832886211574078f, 0.012698531150817871f, 0.00416936632245779f, 0.0065362839959561825f, 0.00915965810418129f, 0.0036454449873417616f, 0.005641288589686155f, 0.006572219077497721f, 0.009319511242210865f, 0.012805764563381672f, 0.004057884216308594f, 0.00756226759403944f, 0.0025816564448177814f, 0.006969032343477011f, 0.009426110424101353f, 0.005836461205035448f, 0.007764121051877737f, 0.0073938313871622086f, 0.00642737839370966f, 0.004606954287737608f, 0.006126619875431061f, 0.004429232329130173f, 0.004365452565252781f, 0.009303719736635685f, 0.011183016002178192f, 0.009950836189091206f, 0.008447060361504555f, 0.007586688734591007f, 0.005810810253024101f, 0.010353075340390205f, 0.010048904456198215f, 0.01574556902050972f, 0.008267499506473541f, 0.006823232863098383f, 0.004665038548409939f, 0.004944545682519674f, 0.0038940038066357374f, 0.00478818453848362f, 0.005428327713161707f, 0.004851708188652992f, 0.00397547846660018f, 0.00911644846200943f, 0.006363461725413799f, 0.010041702538728714f, 0.002156043890863657f, 0.04627092182636261f, 0.008173728361725807f, 0.0055694980546832085f, 0.003903724020346999f, 0.006121455691754818f, 0.00594906834885478f, 0.006425452418625355f, 0.005061179865151644f, 0.0031648222357034683f, 0.004803727380931377f, 0.006064863409847021f, 0.005892522167414427f, 0.006333000026643276f, 0.005275531206279993f, 0.0029339527245610952f, 0.03268963843584061f, 0.005406070500612259f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #299 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_160_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000757440400775522f, 0.0019008690724149346f, 0.0018037465633824468f, 0.00131333211902529f, 0.00110710971057415f, 0.0015311201568692923f, 0.0005863969563506544f, 0.0011283804196864367f, 0.001245207735337317f, 0.0014366043033078313f, 0.0011502071283757687f, 0.0018167576054111123f, 0.0016080642817541957f, 0.0015868457267060876f, 0.0013097954215481877f, 0.0013591080205515027f, 0.0013624051352962852f, 0.0016944240778684616f, 0.0008261864422820508f, 0.0013880949700251222f, 0.0017507439479231834f, 0.002182464115321636f, 0.001245187479071319f, 0.0008420628146268427f, 0.0016557800117880106f, 0.0009144138311967254f, 0.0013398430310189724f, 0.002038284670561552f, 0.0011525133159011602f, 0.0016720425337553024f, 0.0008947137393988669f, 0.0009474142570979893f, 0.0011457140790298581f, 0.0011588665656745434f, 0.002033825032413006f, 0.0012167933164164424f, 0.0010515073081478477f, 0.0005558348493650556f, 0.001066997298039496f, 0.0020424104295670986f, 0.0013032088754698634f, 0.0016645346768200397f, 0.001149291405454278f, 0.001324641751125455f, 0.0018230500863865018f, 0.001002396340481937f, 0.0013345127226784825f, 0.0010834861313924193f, 0.0009492272511124611f, 0.0010048628319054842f, 0.0008237170986831188f, 0.0012003722367808223f, 0.0012312046019360423f, 0.0006278189248405397f, 0.0008031048928387463f, 0.001444268156774342f, 0.001867410377599299f, 0.001451668911613524f, 0.0016484132502228022f, 0.0008827302372083068f, 0.0015143215423449874f, 0.0019443432101979852f, 0.0006246875855140388f, 0.0010418705642223358f, 0.0018410768825560808f, 0.0006411541253328323f, 0.0016957552870735526f, 0.0007174460915848613f, 0.0012755832867696881f, 0.001723125926218927f, 0.0023017372004687786f, 0.001975239021703601f, 0.0006955809658393264f, 0.0012266886187717319f, 0.00055370555492118f, 0.0010090289870277047f, 0.0005986858741380274f, 0.001853033434599638f, 0.0009930083760991693f, 0.0017077410593628883f, 0.0009787647286430001f, 0.001013276632875204f, 0.0009825133020058274f, 0.001631835475564003f, 0.0011210828088223934f, 0.001254654722288251f, 0.0014351087156683207f, 0.0026086708530783653f, 0.0010851139668375254f, 0.0010689777554944158f, 0.002139878924936056f, 0.0007010494591668248f, 0.0016066826647147536f, 0.0006008340860716999f, 0.0010011428967118263f, 0.000593555043451488f, 0.0008916999213397503f, 0.0007890145061537623f, 0.000888001814018935f, 0.001212715171277523f, 0.0010248684557154775f, 0.0014909458113834262f, 0.0015754549531266093f, 0.0014232270186766982f, 0.00109610497020185f, 0.0018939075525850058f, 0.0012431180803105235f, 0.0016439090250059962f, 0.0023321774788200855f, 0.0016564053948968649f, 0.0016039919573813677f, 0.0015322078252211213f, 0.0015175605658441782f, 0.000979228992946446f, 0.0009892858797684312f, 0.0007978464127518237f, 0.0007695919484831393f, 0.0010398884769529104f, 0.0009849854977801442f, 0.0012290745507925749f, 0.001309394370764494f, 0.0007881663041189313f, 0.0015316789504140615f, 0.0016279635019600391f, 0.001063602976500988f, 0.0010707869660109282f, 0.0017550083575770259f, 0.001650169026106596f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #300 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_161_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037539147306233644f, 0.005589961539953947f, 0.013184238225221634f, 0.00426693307235837f, 0.03485748544335365f, 0.008527680300176144f, 0.011734549887478352f, 0.004800786729902029f, 0.004986111540347338f, 0.008858528919517994f, 0.008907875046133995f, 0.010234839282929897f, 0.00905891228467226f, 0.008828427642583847f, 0.010936962440609932f, 0.0044284723699092865f, 0.011383586563169956f, 0.008143388666212559f, 0.006546785123646259f, 0.007370344363152981f, 0.005438928492367268f, 0.004393774550408125f, 0.0046941670589149f, 0.003223443403840065f, 0.004289989359676838f, 0.003644354408606887f, 0.002716975286602974f, 0.006081335712224245f, 0.005017451010644436f, 0.009940838441252708f, 0.009062310680747032f, 0.004443539772182703f, 0.005365398712456226f, 0.005334463901817799f, 0.007025699131190777f, 0.004686401691287756f, 0.0035336611326783895f, 0.005709019023925066f, 0.01600733771920204f, 0.008405989035964012f, 0.004731023218482733f, 0.011184239760041237f, 0.008604173548519611f, 0.00805709883570671f, 0.005501745734363794f, 0.004647480323910713f, 0.004245954565703869f, 0.04984075203537941f, 0.006712730973958969f, 0.006811594590544701f, 0.004371006041765213f, 0.003879497293382883f, 0.0047561367973685265f, 0.0063249883241951466f, 0.0047681983560323715f, 0.011812643148005009f, 0.017640333622694016f, 0.009429793804883957f, 0.011341138742864132f, 0.00974825769662857f, 0.010942419990897179f, 0.0037675825878977776f, 0.004398216959089041f, 0.0041017355397343636f, 0.005795588251203299f, 0.007575599942356348f, 0.006170477252453566f, 0.048421453684568405f, 0.008321965113282204f, 0.005737413186579943f, 0.0073425606824457645f, 0.005699976347386837f, 0.05129946395754814f, 0.004186036065220833f, 0.011817334219813347f, 0.008001653477549553f, 0.11497021466493607f, 0.006932441610842943f, 0.004963267128914595f, 0.005891326814889908f, 0.0032553751952946186f, 0.009658790193498135f, 0.007796159945428371f, 0.00590658700093627f, 0.0038893893361091614f, 0.0043710265308618546f, 0.003904858138412237f, 0.00379699538461864f, 0.006530614569783211f, 0.0026825047098100185f, 0.008165123872458935f, 0.018199961632490158f, 0.017675070092082024f, 0.005780098959803581f, 0.00959719903767109f, 0.0058533926494419575f, 0.020793067291378975f, 0.003854630747810006f, 0.005129717756062746f, 0.004704379476606846f, 0.008135915733873844f, 0.0041956366039812565f, 0.004407254513353109f, 0.006013144738972187f, 0.00651581259444356f, 0.004705109633505344f, 0.00903498474508524f, 0.005195278208702803f, 0.0057098595425486565f, 0.010912515223026276f, 0.0047568948939442635f, 0.006659200880676508f, 0.005729790776968002f, 0.008489989675581455f, 0.009140197187662125f, 0.005448566284030676f, 0.008546232245862484f, 0.004266073927283287f, 0.00407201424241066f, 0.007036764174699783f, 0.009706743061542511f, 0.0036225446965545416f, 0.0035093093756586313f, 0.003021922195330262f, 0.009751505218446255f, 0.006884956732392311f, 0.008557633496820927f, 0.011538323946297169f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #301 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_162_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005859868251718581f, 0.000634339521639049f, 0.0006858236738480628f, 0.001107767573557794f, 0.0005653681582771242f, 0.0009589017718099058f, 0.0006638463237322867f, 0.0009483533794991672f, 0.0013979804934933782f, 0.0011624977923929691f, 0.0005685961223207414f, 0.0007356287678703666f, 0.000823097419925034f, 0.0008073154021985829f, 0.0003813031071331352f, 0.0009915470145642757f, 0.0010473853908479214f, 0.0007174229249358177f, 0.0004200393450446427f, 0.000668566906824708f, 0.0007291346555575728f, 0.0009338354575447738f, 0.0021974912378937006f, 0.0010912272846326232f, 0.0005365078104659915f, 0.0006406528991647065f, 0.0013230713084340096f, 0.0007169448654167354f, 0.0006590906414203346f, 0.0003650666621979326f, 0.0004307225754018873f, 0.0007308724452741444f, 0.0009501484455540776f, 0.0005016315844841301f, 0.0005913202767260373f, 0.0011755400337278843f, 0.0008627899223938584f, 0.0015479015419259667f, 0.0011106115998700261f, 0.0008197773131541908f, 0.0010921243811026216f, 0.0008792633307166398f, 0.0007927743718028069f, 0.0005463265697471797f, 0.0020705738570541143f, 0.0006552530685439706f, 0.001231563393957913f, 0.001642088871449232f, 0.0005307518877089024f, 0.0013896286254748702f, 0.001466592075303197f, 0.0006561545887961984f, 0.0008991425856947899f, 0.0010919106425717473f, 0.0014396813930943608f, 0.0004791522806044668f, 0.002201162511482835f, 0.0008918315288610756f, 0.0009467612253502011f, 0.0015486207557842135f, 0.0015803936403244734f, 0.0015396104427054524f, 0.0007846999214962125f, 0.0017773102736100554f, 0.0019515841268002987f, 0.0005906347651034594f, 0.0005069845938123763f, 0.0010682843858376145f, 0.0009602318750694394f, 0.0007357511203736067f, 0.00118687329813838f, 0.0005871782777830958f, 0.0016800047596916556f, 0.0007380767492577434f, 0.0005849098670296371f, 0.0008516981033608317f, 0.0005956106469966471f, 0.0010027653770521283f, 0.0005488888709805906f, 0.0006604040390811861f, 0.0014501971891149879f, 0.0008098848629742861f, 0.00038493899046443403f, 0.00041377494926564395f, 0.001609986531548202f, 0.0015603008214384317f, 0.0009931987151503563f, 0.00035865954123437405f, 0.0010798306902870536f, 0.0003826553001999855f, 0.0010994412004947662f, 0.00045720511116087437f, 0.0006878437125124037f, 0.0008631275268271565f, 0.0021939624566584826f, 0.0014107073657214642f, 0.00046303888666443527f, 0.0006806387682445347f, 0.0006159895565360785f, 0.00046948279486969113f, 0.0006418163538910449f, 0.0014208325883373618f, 0.0004805905628018081f, 0.0007422579219564795f, 0.001396337291225791f, 0.001397827174514532f, 0.000565984460990876f, 0.0005833361065015197f, 0.0005258689052425325f, 0.0004963655956089497f, 0.0017195349792018533f, 0.0005586667102761567f, 0.0014577351976186037f, 0.0006230341386981308f, 0.0012780803954228759f, 0.0013901881175115705f, 0.0014826466795057058f, 0.002309908391907811f, 0.000417560018831864f, 0.001213828451000154f, 0.0008207589271478355f, 0.0017566913738846779f, 0.0013968710554763675f, 0.0006755117792636156f, 0.0008841797825880349f, 0.0005589300999417901f, 0.0009047513594850898f, 0.0008749415865167975f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #302 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_163_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013682260178029537f, 0.0029902798123657703f, 0.0022977939806878567f, 0.0031129703857004642f, 0.0035647540353238583f, 0.002487572142854333f, 0.025754299014806747f, 0.003179180668666959f, 0.002896371530368924f, 0.0067655243910849094f, 0.0072750612162053585f, 0.004841932561248541f, 0.0030150653328746557f, 0.00677885115146637f, 0.004285306204110384f, 0.003972355276346207f, 0.006540277507156134f, 0.003946811892092228f, 0.003244892694056034f, 0.0024073903914541006f, 0.014373749494552612f, 0.008329837583005428f, 0.0029850078281015158f, 0.013582127168774605f, 0.0037235277704894543f, 0.006924530956894159f, 0.010527004487812519f, 0.004806283861398697f, 0.0028204673435539007f, 0.004887702409178019f, 0.004311455879360437f, 0.0036358204670250416f, 0.0064734662882983685f, 0.004030393436551094f, 0.004060507286339998f, 0.0058922553434967995f, 0.003318303031846881f, 0.007403786294162273f, 0.002125057391822338f, 0.00973762571811676f, 0.0023955765645951033f, 0.002986172679811716f, 0.003162478329613805f, 0.005253550596535206f, 0.002789052901789546f, 0.003717095125466585f, 0.004857415799051523f, 0.004439644981175661f, 0.0026704701595008373f, 0.012345992028713226f, 0.009077643044292927f, 0.20588277280330658f, 0.005036340095102787f, 0.0027891171630471945f, 0.007000270299613476f, 0.005380013957619667f, 0.004673388786613941f, 0.0032856783363968134f, 0.005535708740353584f, 0.009548821486532688f, 0.0037342854775488377f, 0.00946955569088459f, 0.029629819095134735f, 0.0068317558616399765f, 0.005535029340535402f, 0.004884352907538414f, 0.05615540221333504f, 0.0032251577358692884f, 0.0023583690635859966f, 0.0026056128554046154f, 0.002999565564095974f, 0.0032122102566063404f, 0.0034983064979314804f, 0.0059858751483261585f, 0.003676984691992402f, 0.3127219080924988f, 0.005496877711266279f, 0.003083660267293453f, 0.004403331782668829f, 0.031074998900294304f, 0.007067814003676176f, 0.006707489490509033f, 0.0038047977723181248f, 0.0038802954368293285f, 0.006003138609230518f, 0.006883129011839628f, 0.00544198602437973f, 0.0032582683488726616f, 0.027365269139409065f, 0.0035491278395056725f, 0.010468659922480583f, 0.004598477855324745f, 0.006558872293680906f, 0.0027116055134683847f, 0.010386781767010689f, 0.010500043630599976f, 0.004346797708421946f, 0.011098162271082401f, 0.003721042536199093f, 0.004882555454969406f, 0.005683750379830599f, 0.020664235576987267f, 0.00459081307053566f, 0.01632656529545784f, 0.008467808365821838f, 0.0030251136049628258f, 0.01753183640539646f, 0.004235119093209505f, 0.004153532441705465f, 0.007154127582907677f, 0.009307900443673134f, 0.005295895971357822f, 0.005270608235150576f, 0.012144101783633232f, 0.009366340935230255f, 0.019689388573169708f, 0.42403802275657654f, 0.003321251133456826f, 0.003824122715741396f, 0.006768498104065657f, 0.003448254894465208f, 0.006756184156984091f, 0.004195701330900192f, 0.00427015358582139f, 0.004794546402990818f, 0.013691981323063374f, 0.0053030927665531635f, 0.0057434383779764175f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #303 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_164_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 25,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003898828523233533f, 0.002685055835172534f, 0.00298159196972847f, 0.0029992377385497093f, 0.0024323381949216127f, 0.0011550390627235174f, 0.0012068686774000525f, 0.0014411240117624402f, 0.0010517796035856009f, 0.0015962523175403476f, 0.0010902436915785074f, 0.001466803951188922f, 0.0018002813449129462f, 0.0012826357269659638f, 0.0012782469857484102f, 0.0008017172222025692f, 0.0011429922888055444f, 0.001589183695614338f, 0.0012322034453973174f, 0.0009186443639919162f, 0.0036261160857975483f, 0.002133924514055252f, 0.002528558950871229f, 0.002121508587151766f, 0.0023376827593892813f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #304 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_169_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007572193630039692f, 0.004973302129656076f, 0.004678682424128056f, 0.006201071199029684f, 0.0027932554949074984f, 0.006113329902291298f, 0.014933843165636063f, 0.0029044293332844973f, 0.004908605478703976f, 0.005988670978695154f, 0.008222827687859535f, 0.008832751773297787f, 0.009735003113746643f, 0.008197855204343796f, 0.008430695161223412f, 0.006156246643513441f, 0.0026967194862663746f, 0.005271066911518574f, 0.00506492517888546f, 0.008716199547052383f, 0.007462458685040474f, 0.022279050201177597f, 0.0050262887962162495f, 0.009359405376017094f, 0.005330042913556099f, 0.006765078287571669f, 0.008287779055535793f, 0.003502004314213991f, 0.005576717667281628f, 0.006354668643325567f, 0.00753613468259573f, 0.007618176285177469f, 0.006066155154258013f, 0.0053694117814302444f, 0.0039999526925385f, 0.0057887365110218525f, 0.0034233371261507273f, 0.007645303849130869f, 0.0018338438821956515f, 0.006118967197835445f, 0.0028918497264385223f, 0.005490779876708984f, 0.005294071510434151f, 0.0028037407901138067f, 0.0037609601859003305f, 0.004644184373319149f, 0.009749699383974075f, 0.006506854202598333f, 0.003837631084024906f, 0.0050903866067528725f, 0.017920177429914474f, 0.0005783659871667624f, 0.00640494329854846f, 0.002515739295631647f, 0.005369925405830145f, 0.0028658020310103893f, 0.0037330854684114456f, 0.005294314585626125f, 0.005112296901643276f, 0.0035918389912694693f, 0.009546550922095776f, 0.006120074540376663f, 0.0007216835510917008f, 0.00338495010510087f, 0.004395709373056889f, 0.006754876580089331f, 0.006130276247859001f, 0.0038694432005286217f, 0.005438494961708784f, 0.003565720748156309f, 0.00397239625453949f, 0.006815875880420208f, 0.01936866156756878f, 0.0067087626084685326f, 0.008976196870207787f, 0.0010636162478476763f, 0.009322001598775387f, 0.005075784865766764f, 0.004418426658958197f, 0.02262490801513195f, 0.006507868878543377f, 0.006745395716279745f, 0.00577917043119669f, 0.007311868481338024f, 0.017149772495031357f, 0.003577272640541196f, 0.00907990150153637f, 0.004035658668726683f, 0.006536996923387051f, 0.004786576144397259f, 0.005158556159585714f, 0.005912315100431442f, 0.00612874748185277f, 0.0038685062900185585f, 0.005321720149368048f, 0.00525175454095006f, 0.00764459790661931f, 0.00501589197665453f, 0.004703863058239222f, 0.007961327210068703f, 0.007606850937008858f, 0.005002554971724749f, 0.006947715301066637f, 0.0118734585121274f, 0.006430790759623051f, 0.0061480263248085976f, 0.008849234320223331f, 0.003833626862615347f, 0.013308006338775158f, 0.007306113839149475f, 0.005747274029999971f, 0.008276310749351978f, 0.019943315535783768f, 0.00732807582244277f, 0.0042531657963991165f, 0.006286039017140865f, 0.0008289156248793006f, 0.003394225612282753f, 0.0038444444071501493f, 0.00639848317950964f, 0.005011609755456448f, 0.0057598077692091465f, 0.004839208908379078f, 0.004351810086518526f, 0.0036788093857467175f, 0.006881108507514f, 0.007522465195506811f, 0.005156939383596182f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #305 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_170_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 20,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00029201965662650764f, 0.00023746717488393188f, 0.0003136743325740099f, 0.0003042692260351032f, 0.0004134551272727549f, 0.0003034849651157856f, 0.0003514279087539762f, 0.0003382370341569185f, 0.00022305695165414363f, 0.0003067093202844262f, 0.00024145364295691252f, 0.0002938265970442444f, 0.0002401623351033777f, 0.00032307684887200594f, 0.00026823091320693493f, 0.0003453019598964602f, 0.000311026320559904f, 0.00032429053680971265f, 0.0003615243185777217f, 0.00040800380520522594f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #306 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_184_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006027101073414087f, 0.004133554641157389f, 0.004904669243842363f, 0.004323026165366173f, 0.002131813205778599f, 0.004029763396829367f, 0.0037991793360561132f, 0.0047301314771175385f, 0.003479528706520796f, 0.005649860482662916f, 0.0052492935210466385f, 0.0020035828929394484f, 0.004220848437398672f, 0.00481221592053771f, 0.0038771042600274086f, 0.0029894807375967503f, 0.0037896945141255856f, 0.00582381384447217f, 0.0022053353022783995f, 0.005140377674251795f, 0.0031188291031867266f, 0.0036521628499031067f, 0.0030831764452159405f, 0.002664840081706643f, 0.0031816340051591396f, 0.005246365442872047f, 0.004003801848739386f, 0.004163145553320646f, 0.004557967185974121f, 0.0034518272150307894f, 0.0040759011171758175f, 0.004677087999880314f, 0.004222270101308823f, 0.003670749021694064f, 0.002917497418820858f, 0.002943082945421338f, 0.004541450645774603f, 0.0038532468024641275f, 0.004212762229144573f, 0.005053181201219559f, 0.00540080526843667f, 0.004218114539980888f, 0.004685753956437111f, 0.0035228461492806673f, 0.005542381666600704f, 0.006326684262603521f, 0.006579661276191473f, 0.0040924022905528545f, 0.0020085738506168127f, 0.002801234368234873f, 0.0029766184743493795f, 0.003094372572377324f, 0.0033406272996217012f, 0.004475312773138285f, 0.0034662694670259953f, 0.0030183319468051195f, 0.005147009156644344f, 0.0033056617248803377f, 0.004993802402168512f, 0.003755004843696952f, 0.0034978382755070925f, 0.0051249610260128975f, 0.0028346688486635685f, 0.0020838757045567036f, 0.006310401484370232f, 0.004323153290897608f, 0.00440843915566802f, 0.004815587308257818f, 0.004769913386553526f, 0.004975032992660999f, 0.005688291508704424f, 0.0025013440754264593f, 0.004279350396245718f, 0.0035981745459139347f, 0.004589919466525316f, 0.005400556605309248f, 0.003312943270429969f, 0.0072656795382499695f, 0.0038259897846728563f, 0.0033901045098900795f, 0.0036840513348579407f, 0.0027050841599702835f, 0.004795632790774107f, 0.0042291199788451195f, 0.0052636126056313515f, 0.004693691153079271f, 0.004215569701045752f, 0.004952913150191307f, 0.0038191599305719137f, 0.004160716664046049f, 0.0036147625651210546f, 0.0055481367744505405f, 0.002643770771101117f, 0.003333624452352524f, 0.004010835662484169f, 0.005954422056674957f, 0.004511936567723751f, 0.002895055804401636f, 0.0034363477025181055f, 0.0043180473148822784f, 0.004704134073108435f, 0.004251029342412949f, 0.0035867816768586636f, 0.004049813840538263f, 0.005188200622797012f, 0.002737918635830283f, 0.0030665190424770117f, 0.002943088300526142f, 0.0044877007603645325f, 0.005008749198168516f, 0.0035571688786149025f, 0.004962875507771969f, 0.00439474917948246f, 0.005734894424676895f, 0.003770780749619007f, 0.00537498015910387f, 0.0038207105826586485f, 0.0050667654722929f, 0.0028091559652239084f, 0.005773808341473341f, 0.00357174058444798f, 0.004972276743501425f, 0.005579156801104546f, 0.0025357375852763653f, 0.0035333747509866953f, 0.003007748629897833f, 0.002601961838081479f, 0.0052215163595974445f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #307 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_185_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011731918202713132f, 0.001115344581194222f, 0.0013184451963752508f, 0.0014522576238960028f, 0.0018624627264216542f, 0.0015149237588047981f, 0.0014274962013587356f, 0.002191785490140319f, 0.0013338999124243855f, 0.001279868884012103f, 0.0014522084966301918f, 0.0016696307575330138f, 0.001490110531449318f, 0.00143565540201962f, 0.0012939170701429248f, 0.0014441716484725475f, 0.001114899292588234f, 0.0011629912769421935f, 0.0015780299436300993f, 0.0013583502732217312f, 0.0012229504063725471f, 0.001641929498873651f, 0.0013565659755840898f, 0.0012000423157587647f, 0.0012485060142353177f, 0.0015955945709720254f, 0.0012814379297196865f, 0.0012389608891680837f, 0.0013127966085448861f, 0.0013832513941451907f, 0.0013719177804887295f, 0.0018513266695663333f, 0.0011843093670904636f, 0.0016715273959562182f, 0.001249886816367507f, 0.0013567318674176931f, 0.0012432415969669819f, 0.0014279094757512212f, 0.001331735635176301f, 0.001515858224593103f, 0.001546622603200376f, 0.0017034957418218255f, 0.0013704808661714196f, 0.001497024786658585f, 0.001436280319467187f, 0.0018344060517847538f, 0.0013795995619148016f, 0.0011870249873027205f, 0.001973566832020879f, 0.0015358563978224993f, 0.0014263240154832602f, 0.001417105901055038f, 0.0011535281082615256f, 0.0016659920802339911f, 0.0010787799255922437f, 0.0014240280725061893f, 0.001504502259194851f, 0.0012429297203198075f, 0.001524726627394557f, 0.0011869792360812426f, 0.0011667035287246108f, 0.001326525118201971f, 0.0011052432237192988f, 0.001612380612641573f, 0.001633631531149149f, 0.0014723550993949175f, 0.001932628219947219f, 0.001382639748044312f, 0.0013047961983829737f, 0.0013024404179304838f, 0.0013237610692158341f, 0.0018140851752832532f, 0.001505585270933807f, 0.0013425579527392983f, 0.0013164649717509747f, 0.0010664659785106778f, 0.0017436376074329019f, 0.0012505032354965806f, 0.0009725434356369078f, 0.001382191083393991f, 0.0014566805912181735f, 0.001357563422061503f, 0.001201774924993515f, 0.0014934373321011662f, 0.0011742039350792766f, 0.0012832119828090072f, 0.0019360908772796392f, 0.0010711019858717918f, 0.0018090911908075213f, 0.0010978053323924541f, 0.0013681951677426696f, 0.00162206229288131f, 0.0011982397409155965f, 0.0013385909842327237f, 0.000970283814240247f, 0.0013745349133387208f, 0.0014571540523320436f, 0.0011012139730155468f, 0.0012340451357886195f, 0.0014741295017302036f, 0.0010801273165270686f, 0.0011534149525687099f, 0.0020522726699709892f, 0.0015451459912583232f, 0.0012591826962307096f, 0.0014098506653681397f, 0.001357017899863422f, 0.0017030705930665135f, 0.001361135975457728f, 0.0010719712590798736f, 0.0013727874029427767f, 0.0011791178258135915f, 0.00146462710108608f, 0.0013575800694525242f, 0.001555544207803905f, 0.001070262398570776f, 0.0015410446794703603f, 0.0014370897551998496f, 0.0015209177508950233f, 0.0013594869524240494f, 0.0014896445209160447f, 0.0012939131120219827f, 0.0014737049350515008f, 0.0015824069269001484f, 0.0011607316555455327f, 0.0016035408480092883f, 0.0012389112962409854f, 0.0016870310064405203f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #308 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_186_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007383327465504408f, 0.011110293678939342f, 0.0041223373264074326f, 0.006149732507765293f, 0.006993759423494339f, 0.007181439083069563f, 0.013019649311900139f, 0.010526553727686405f, 0.008880033157765865f, 0.006610471289604902f, 0.005472310818731785f, 0.007804399821907282f, 0.009006468579173088f, 0.012692971155047417f, 0.007355075795203447f, 0.00450939079746604f, 0.006341143511235714f, 0.009466524235904217f, 0.00802354235202074f, 0.008464204147458076f, 0.011536261066794395f, 0.00690504489466548f, 0.011156406253576279f, 0.010526972822844982f, 0.007399499882012606f, 0.010783929377794266f, 0.006425184663385153f, 0.007443264592438936f, 0.010285953991115093f, 0.00785526167601347f, 0.009025060571730137f, 0.006491226144134998f, 0.007533513940870762f, 0.009338468313217163f, 0.007831589318811893f, 0.007085428573191166f, 0.009712675586342812f, 0.0047754631377756596f, 0.00949283130466938f, 0.010014461353421211f, 0.010508343577384949f, 0.007542856968939304f, 0.0073007442988455296f, 0.005742039531469345f, 0.006517959292978048f, 0.006385226733982563f, 0.01151456218212843f, 0.00834621861577034f, 0.004875272046774626f, 0.008870644494891167f, 0.007898347452282906f, 0.004765376914292574f, 0.007064091973006725f, 0.013076146133244038f, 0.005107020027935505f, 0.01050629187375307f, 0.00850663986057043f, 0.011501296423375607f, 0.0064169312827289104f, 0.006485800724476576f, 0.012867918238043785f, 0.005410423502326012f, 0.010729930363595486f, 0.006306462921202183f, 0.005143263377249241f, 0.006642890628427267f, 0.007501071784645319f, 0.008866085670888424f, 0.006593682803213596f, 0.00763401435688138f, 0.008944232016801834f, 0.0058782040141522884f, 0.009366678074002266f, 0.005502777639776468f, 0.005992168094962835f, 0.012383275665342808f, 0.008224274031817913f, 0.007534241769462824f, 0.013202718459069729f, 0.010145105421543121f, 0.0060981507413089275f, 0.0055221812799572945f, 0.007140295580029488f, 0.007836226373910904f, 0.00867205299437046f, 0.010003441013395786f, 0.007577745243906975f, 0.006936959456652403f, 0.006900658831000328f, 0.009674079716205597f, 0.011999102309346199f, 0.004671826958656311f, 0.007153308484703302f, 0.00613646162673831f, 0.01514339167624712f, 0.009727038443088531f, 0.005207821261137724f, 0.008861925452947617f, 0.004877911414951086f, 0.009561987593770027f, 0.007917454466223717f, 0.005755965132266283f, 0.009128986857831478f, 0.008033188059926033f, 0.007104029878973961f, 0.005820814054459333f, 0.011034099385142326f, 0.00616616802290082f, 0.006610515061765909f, 0.007186110597103834f, 0.009537090547382832f, 0.00610877200961113f, 0.008420400321483612f, 0.009712081402540207f, 0.00697573134675622f, 0.011426197364926338f, 0.007786124013364315f, 0.009331554174423218f, 0.009760580956935883f, 0.0069997720420360565f, 0.005135456100106239f, 0.01383877918124199f, 0.008516221307218075f, 0.008615650236606598f, 0.007122163660824299f, 0.007909438572824001f, 0.005331715103238821f, 0.012640061788260937f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #309 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_187_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002184494398534298f, 0.0016819138545542955f, 0.0012983685592189431f, 0.0013906926615163684f, 0.0020909078884869814f, 0.0018308950820937753f, 0.001368985278531909f, 0.0016352611128240824f, 0.0017365224193781614f, 0.0017587724141776562f, 0.0014119960833340883f, 0.0016622485127300024f, 0.0016499320045113564f, 0.0014499896205961704f, 0.0014180134749040008f, 0.0016545766266062856f, 0.0012118853628635406f, 0.0016691869823262095f, 0.0012377997627481818f, 0.0015604440122842789f, 0.0019473197171464562f, 0.0018148766830563545f, 0.0014231118839234114f, 0.0018055540276691318f, 0.0016072943108156323f, 0.0015058458084240556f, 0.0018681009532883763f, 0.0013614639174193144f, 0.001719888299703598f, 0.0012813596986234188f, 0.0014988865004852414f, 0.001674441620707512f, 0.0013554096221923828f, 0.0017470890888944268f, 0.0016026165103539824f, 0.0014490662142634392f, 0.0017038484802469611f, 0.0016762034501880407f, 0.0019283745205029845f, 0.001556937932036817f, 0.0018624404910951853f, 0.0017109134932979941f, 0.0015893833478912711f, 0.0014711302937939763f, 0.0012230842839926481f, 0.001993261743336916f, 0.0013464411022141576f, 0.0016648167511448264f, 0.0013924244558438659f, 0.0018055348191410303f, 0.001712772878818214f, 0.0015316790668293834f, 0.0015331105096265674f, 0.002566907089203596f, 0.0019604796543717384f, 0.0019139981595799327f, 0.0014621529262512922f, 0.0013264634180814028f, 0.0015785536961629987f, 0.0014757931930944324f, 0.0013325249310582876f, 0.001834707334637642f, 0.0010743705788627267f, 0.0015958062140271068f, 0.0015927819767966866f, 0.0019101286306977272f, 0.001380152185447514f, 0.0014259780291467905f, 0.0013456635642796755f, 0.001392575679346919f, 0.0016692554345354438f, 0.0016660798573866487f, 0.0015738148940727115f, 0.00127484742552042f, 0.0018507686909288168f, 0.0011811322765424848f, 0.0017505640862509608f, 0.0013879465404897928f, 0.0015694154426455498f, 0.0018929014913737774f, 0.001206468790769577f, 0.001237288350239396f, 0.0016026681987568736f, 0.0014939513057470322f, 0.0016404046909883618f, 0.001571522792801261f, 0.0014955583028495312f, 0.0017554315272718668f, 0.0014352852012962103f, 0.0015092861140146852f, 0.0018095523118972778f, 0.0015478229615837336f, 0.0016486739041283727f, 0.0014555922243744135f, 0.0014953272184357047f, 0.0020682343747466803f, 0.0016122072702273726f, 0.0017090472392737865f, 0.001373080420307815f, 0.0012922975001856685f, 0.0013521832879632711f, 0.00137520139105618f, 0.0014755299780517817f, 0.001376587781123817f, 0.001573096145875752f, 0.0016517597250640392f, 0.001889194012619555f, 0.0022884258069097996f, 0.0014785233652219176f, 0.0018527241190895438f, 0.001326155150309205f, 0.001220181817188859f, 0.0017067453591153026f, 0.0015581849729642272f, 0.0014214428374543786f, 0.0016788443317636847f, 0.0018440894782543182f, 0.0017882917309179902f, 0.0009789586765691638f, 0.0012196592288091779f, 0.0014382593799382448f, 0.0012923979666084051f, 0.001602998236194253f, 0.0020063177216798067f, 0.0013753824168816209f, 0.0015038995770737529f, 0.001757848309352994f, 0.001191360759548843f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #310 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_188_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008330896496772766f, 0.010187621228396893f, 0.004156247712671757f, 0.013280239887535572f, 0.0049221389926970005f, 0.0055352975614368916f, 0.011751985177397728f, 0.00714444974437356f, 0.008979113772511482f, 0.005446651950478554f, 0.009831413626670837f, 0.008111097849905491f, 0.006455852184444666f, 0.007537427823990583f, 0.006066480185836554f, 0.005708557553589344f, 0.0059272488579154015f, 0.007480119355022907f, 0.0072508747689425945f, 0.014254129491746426f, 0.006308445241302252f, 0.01022820733487606f, 0.00933890976011753f, 0.004106929991394281f, 0.007953367196023464f, 0.010000008158385754f, 0.007827017456293106f, 0.008544960990548134f, 0.00711961230263114f, 0.014699562452733517f, 0.009710052981972694f, 0.006757201161235571f, 0.011190442368388176f, 0.00850382074713707f, 0.006307242903858423f, 0.011933596804738045f, 0.010768215171992779f, 0.008558028377592564f, 0.009286691434681416f, 0.005732377991080284f, 0.009311817586421967f, 0.006819811183959246f, 0.01022114884108305f, 0.013167823664844036f, 0.007778388448059559f, 0.007570987101644278f, 0.013779460452497005f, 0.012107057496905327f, 0.009594751521945f, 0.010991556569933891f, 0.008941981941461563f, 0.01014234870672226f, 0.010415975004434586f, 0.005900441203266382f, 0.006729681044816971f, 0.0047249561175704f, 0.006310589145869017f, 0.004660636652261019f, 0.008918066509068012f, 0.006199314258992672f, 0.01006360910832882f, 0.007045118138194084f, 0.010577205568552017f, 0.009388747625052929f, 0.006787053309381008f, 0.008341876789927483f, 0.008878455497324467f, 0.014517044648528099f, 0.007479975465685129f, 0.005389089696109295f, 0.008795756846666336f, 0.006375483237206936f, 0.00870499573647976f, 0.009105859324336052f, 0.006478038616478443f, 0.009337730705738068f, 0.010106820613145828f, 0.019476165995001793f, 0.007251728791743517f, 0.008715457282960415f, 0.010151073336601257f, 0.008636834099888802f, 0.008373535238206387f, 0.007828502915799618f, 0.006571303121745586f, 0.011233028955757618f, 0.006129525136202574f, 0.005234199110418558f, 0.008841287344694138f, 0.01024532038718462f, 0.009172040037810802f, 0.007825363427400589f, 0.008537011221051216f, 0.013854146003723145f, 0.010117816738784313f, 0.010232506319880486f, 0.004762639291584492f, 0.008595138788223267f, 0.007158845197409391f, 0.006733284331858158f, 0.006333553232252598f, 0.004574661608785391f, 0.01292561274021864f, 0.012434189207851887f, 0.004817577078938484f, 0.009498675353825092f, 0.009909607470035553f, 0.008211989887058735f, 0.00437161885201931f, 0.006616400554776192f, 0.010301860980689526f, 0.006920292507857084f, 0.004776414949446917f, 0.005949355196207762f, 0.008465927094221115f, 0.009309617802500725f, 0.00532269524410367f, 0.009329380467534065f, 0.009419433772563934f, 0.005676318891346455f, 0.007997287437319756f, 0.016002442687749863f, 0.005163287278264761f, 0.012091392651200294f, 0.0056774853728711605f, 0.009749282151460648f, 0.0071129887364804745f, 0.01435941644012928f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #311 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_189_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017843615496531129f, 0.0019706073217093945f, 0.0013876078883185983f, 0.0013553983299061656f, 0.0016792352544143796f, 0.0014475691132247448f, 0.0013605750864371657f, 0.0016408641822636127f, 0.0015229587443172932f, 0.001642717863433063f, 0.0012188535183668137f, 0.0024072190281003714f, 0.0006793112261220813f, 0.0016025722725316882f, 0.00128514738753438f, 0.0012664514360949397f, 0.000766949204262346f, 0.0016686840681359172f, 0.0014165288303047419f, 0.0016335357213392854f, 0.0016404386842623353f, 0.0018734721234068274f, 0.0014574389206245542f, 0.0009671172010712326f, 0.001425392460078001f, 0.0014295837609097362f, 0.001404481241479516f, 0.0018173297867178917f, 0.0013916237512603402f, 0.001549332868307829f, 0.0011876047356054187f, 0.0014188267523422837f, 0.0012522435281425714f, 0.001422068104147911f, 0.001901358598843217f, 0.0015118595911189914f, 0.0012574687134474516f, 0.0013043605722486973f, 0.0012197449104860425f, 0.0012384378351271152f, 0.00147254578769207f, 0.0018994018901139498f, 0.0010163203114643693f, 0.0013782621826976538f, 0.00146617426071316f, 0.00102463539224118f, 0.0008674083510413766f, 0.002080565085634589f, 0.0013223898131400347f, 0.0024789751041680574f, 0.0011778350453823805f, 0.0017137089744210243f, 0.0020389105193316936f, 0.001870722626335919f, 0.0010317995911464095f, 0.0013484013034030795f, 0.0012860524002462626f, 0.0010326243937015533f, 0.0014983756700530648f, 0.0022144406102597713f, 0.0015740980161353946f, 0.0017753373831510544f, 0.0017222954193130136f, 0.0006685997941531241f, 0.0009069465450011194f, 0.0008527611498720944f, 0.0021893130615353584f, 0.0016634805360808969f, 0.0016941747162491083f, 0.0015256541082635522f, 0.001371864345856011f, 0.001800402533262968f, 0.0010800600284710526f, 0.0013554729521274567f, 0.0016300329007208347f, 0.001355727668851614f, 0.0019845853094011545f, 0.0013843205524608493f, 0.0014250896638259292f, 0.001751862931996584f, 0.001985271228477359f, 0.0017740796320140362f, 0.001705873291939497f, 0.0016285100718960166f, 0.0016349201323464513f, 0.0013509542914107442f, 0.0014226111816242337f, 0.0017226150957867503f, 0.0014608745696023107f, 0.0015270162839442492f, 0.0015441493596881628f, 0.0013069368433207273f, 0.001381110749207437f, 0.0018837780226022005f, 0.0013802816392853856f, 0.001692283316515386f, 0.0013927494874224067f, 0.0017818546621128917f, 0.0018364443676546216f, 0.0019021534826606512f, 0.0020532398484647274f, 0.0018560984171926975f, 0.0013028905959799886f, 0.0012952092802152038f, 0.0016818714793771505f, 0.0013926124665886164f, 0.0011872707400470972f, 0.0016765138134360313f, 0.0014791436260566115f, 0.0010946399997919798f, 0.0015711955493316054f, 0.0014529424952343106f, 0.001255595008842647f, 0.0010741630103439093f, 0.0009840447455644608f, 0.0011040904792025685f, 0.001329778111539781f, 0.001303691416978836f, 0.0013271140633150935f, 0.0017033092444762588f, 0.001387581112794578f, 0.00197362108156085f, 0.0014596509281545877f, 0.0015607980312779546f, 0.0012878203997388482f, 0.0017335108714178205f, 0.0015236365143209696f, 0.0014528458705171943f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #312 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_190_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0055713714100420475f, 0.012600447982549667f, 0.004308751784265041f, 0.015274720266461372f, 0.008470763452351093f, 0.005230034701526165f, 0.007074546068906784f, 0.007877233438193798f, 0.006119937635958195f, 0.005334160756319761f, 0.005358177237212658f, 0.009048041887581348f, 0.040640830993652344f, 0.01218841876834631f, 0.00807043444365263f, 0.0034385949838906527f, 0.020555321127176285f, 0.006833591964095831f, 0.0051176175475120544f, 0.004648954141885042f, 0.0042563132010400295f, 0.005900553427636623f, 0.0086007509380579f, 0.018335899338126183f, 0.004750252701342106f, 0.013656506314873695f, 0.00543610006570816f, 0.005134039558470249f, 0.006874927319586277f, 0.0036990714725106955f, 0.007289504166692495f, 0.011755078099668026f, 0.015214451588690281f, 0.00882614217698574f, 0.0061318096704781055f, 0.010097282938659191f, 0.009463716298341751f, 0.005963364150375128f, 0.019188087433576584f, 0.010846976190805435f, 0.010244275443255901f, 0.0067435200326144695f, 0.03270791098475456f, 0.008584022521972656f, 0.005890268832445145f, 0.006695569958537817f, 0.02541838213801384f, 0.0042757005430758f, 0.007467115763574839f, 0.0063536278903484344f, 0.007574803661555052f, 0.007819471880793571f, 0.009372346103191376f, 0.012156419456005096f, 0.007767724338918924f, 0.0063174874521791935f, 0.01018449291586876f, 0.006285223178565502f, 0.014552170410752296f, 0.009045159444212914f, 0.006809167563915253f, 0.0032464098185300827f, 0.009314623661339283f, 0.027799708768725395f, 0.012584584765136242f, 0.018876491114497185f, 0.008411712944507599f, 0.00855774525552988f, 0.007989059202373028f, 0.007543380372226238f, 0.010361028835177422f, 0.005313442088663578f, 0.011188466101884842f, 0.0064169312827289104f, 0.007534184027463198f, 0.009670206345617771f, 0.0036658248864114285f, 0.004806354641914368f, 0.02310309000313282f, 0.00757137406617403f, 0.007085543125867844f, 0.01809573546051979f, 0.009317244403064251f, 0.00727760000154376f, 0.0067293476313352585f, 0.008907053619623184f, 0.008065548725426197f, 0.0053486027754843235f, 0.007127320859581232f, 0.008134922944009304f, 0.005159030668437481f, 0.013256778009235859f, 0.012830697000026703f, 0.011113062500953674f, 0.0046097515150904655f, 0.006268165539950132f, 0.006310575641691685f, 0.008278731256723404f, 0.004707795102149248f, 0.007802467793226242f, 0.010586326941847801f, 0.003738221013918519f, 0.007800627499818802f, 0.0059234281070530415f, 0.006202941760420799f, 0.008220233023166656f, 0.010129467584192753f, 0.00787482038140297f, 0.005506589077413082f, 0.015733705833554268f, 0.005184728652238846f, 0.006627640686929226f, 0.005491482559591532f, 0.026187313720583916f, 0.01002243347465992f, 0.012129993177950382f, 0.008144323714077473f, 0.0038005292881280184f, 0.007530855014920235f, 0.0071596987545490265f, 0.0050524440594017506f, 0.004360326565802097f, 0.00624361215159297f, 0.004901847802102566f, 0.006630990654230118f, 0.007665266748517752f, 0.0071449074894189835f, 0.004927683621644974f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #313 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_191_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009260853403247893f, 0.0009637470357120037f, 0.0005817553610540926f, 0.0012702981475740671f, 0.0009831293718889356f, 0.000630554452072829f, 0.0016251266933977604f, 0.0011665313504636288f, 0.001298096845857799f, 0.0016999451909214258f, 0.00135607470292598f, 0.0015373547794297338f, 0.00195670616813004f, 0.001708913128823042f, 0.0007805777713656425f, 0.0010433460120111704f, 0.0014694518176838756f, 0.001083376700989902f, 0.0011682052863761783f, 0.0010147327557206154f, 0.0011342136422172189f, 0.0016608437290415168f, 0.0011867518769577146f, 0.0016709910705685616f, 0.0015838402323424816f, 0.0016548015410080552f, 0.0017489674501121044f, 0.0020322727505117655f, 0.0017196345143020153f, 0.001376788248308003f, 0.001313916058279574f, 0.0013999301008880138f, 0.0016362275928258896f, 0.00191802519839257f, 0.0013370673405006528f, 0.0013911843998357654f, 0.0015458662528544664f, 0.0013732947409152985f, 0.0006947473739273846f, 0.0018895530374720693f, 0.0008569651399739087f, 0.0022490844130516052f, 0.002256704494357109f, 0.0020140570122748613f, 0.0020188463386148214f, 0.0009130246471613646f, 0.0017109581967815757f, 0.0011582515435293317f, 0.0009617534815333784f, 0.0013152349274605513f, 0.0008044907008297741f, 0.0014689513482153416f, 0.0009856775868684053f, 0.002090324182063341f, 0.0017099984688684344f, 0.0009791393531486392f, 0.0009824050357565284f, 0.0019969125278294086f, 0.0008169124484993517f, 0.0014868966536596417f, 0.0015937633579596877f, 0.0014845940750092268f, 0.001179487444460392f, 0.0010049664415419102f, 0.0011208440409973264f, 0.0005472566117532551f, 0.0016010391991585493f, 0.001222864375449717f, 0.0007310522487387061f, 0.0012018580455332994f, 0.0017442118842154741f, 0.0004649828188121319f, 0.0012777596712112427f, 0.001882453914731741f, 0.0017263760091736913f, 0.0012543932534754276f, 0.0010931160068139434f, 0.0009649988496676087f, 0.00155454664491117f, 0.0014461787650361657f, 0.0012500723823904991f, 0.0021865644957870245f, 0.0020417277701199055f, 0.0008298644097521901f, 0.0010228519095107913f, 0.0012440887512639165f, 0.0007566564017906785f, 0.002507812110707164f, 0.00084261893061921f, 0.001237565535120666f, 0.0015705210389569402f, 0.0006607315153814852f, 0.0012513514375314116f, 0.0017146983882412314f, 0.0011819291394203901f, 0.0009894557297229767f, 0.0009532611002214253f, 0.0019460372859612107f, 0.0010573131730780005f, 0.0008162233280017972f, 0.0014772904105484486f, 0.0009584564832039177f, 0.0015518901636824012f, 0.0010376686695963144f, 0.0005591480294242501f, 0.0012070114025846124f, 0.001186824170872569f, 0.0010593251790851355f, 0.0012106733629480004f, 0.001368156517855823f, 0.0008618522551842034f, 0.0010802480392158031f, 0.001801732461899519f, 0.001467936672270298f, 0.0008792986045591533f, 0.0017234024126082659f, 0.0011327783577144146f, 0.0013589054578915238f, 0.0009208175470121205f, 0.0021099140867590904f, 0.001314149470999837f, 0.0018204605439677835f, 0.001406000810675323f, 0.0018593446584418416f, 0.001081034424714744f, 0.0017154095694422722f, 0.001381360343657434f, 0.0012460913276299834f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #314 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_192_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015355546027421951f, 0.003906163154169917f, 0.03672647103667259f, 0.00827116146683693f, 0.01376400701701641f, 0.009969642385840416f, 0.010296792723238468f, 0.004386972635984421f, 0.018964245915412903f, 0.005383054725825787f, 0.0051622772589325905f, 0.00990885030478239f, 0.0056225634180009365f, 0.006081558298319578f, 0.007316065952181816f, 0.010555878281593323f, 0.006392315030097961f, 0.013655624352395535f, 0.004860231652855873f, 0.0048362454399466515f, 0.005569266155362129f, 0.005045434460043907f, 0.028190096840262413f, 0.003968897741287947f, 0.0043734596110880375f, 0.01072296779602766f, 0.008916760794818401f, 0.004942409228533506f, 0.005952102597802877f, 0.0036960879806429148f, 0.006548825651407242f, 0.006639938335865736f, 0.004710265435278416f, 0.011435561813414097f, 0.011980163864791393f, 0.00829629972577095f, 0.010408543050289154f, 0.013488533906638622f, 0.006946797948330641f, 0.005163293797522783f, 0.009455490857362747f, 0.005937865935266018f, 0.011937256902456284f, 0.005649023223668337f, 0.00448923883959651f, 0.023670678958296776f, 0.004717051051557064f, 0.020180270075798035f, 0.005411351565271616f, 0.0053776963613927364f, 0.011704887263476849f, 0.004844835493713617f, 0.013021713122725487f, 0.0038153398782014847f, 0.00876281876116991f, 0.006298019550740719f, 0.005539354402571917f, 0.005823059007525444f, 0.004925228655338287f, 0.01161253359168768f, 0.005798324942588806f, 0.004325759131461382f, 0.011702879332005978f, 0.006537912413477898f, 0.004435854963958263f, 0.007481767330318689f, 0.005906548351049423f, 0.00815117172896862f, 0.007196325343102217f, 0.012381395325064659f, 0.012619209475815296f, 0.029605383053421974f, 0.007147734519094229f, 0.007800603751093149f, 0.005067056976258755f, 0.007021838799118996f, 0.007796993013471365f, 0.006828527431935072f, 0.00851736031472683f, 0.006304596085101366f, 0.005516492296010256f, 0.0050918045453727245f, 0.011185410432517529f, 0.009853002615272999f, 0.0084746815264225f, 0.005926299374550581f, 0.003998828586190939f, 0.005757566541433334f, 0.008593558333814144f, 0.0035796070005744696f, 0.005103161558508873f, 0.0038401479832828045f, 0.004400476347655058f, 0.0038536805659532547f, 0.008625741116702557f, 0.014266196638345718f, 0.00626900140196085f, 0.013971847482025623f, 0.006150651723146439f, 0.007589132525026798f, 0.00957656092941761f, 0.018564047291874886f, 0.006874403450638056f, 0.006275491788983345f, 0.004949397873133421f, 0.004434657283127308f, 0.009170682169497013f, 0.008077176287770271f, 0.008235161192715168f, 0.006496431306004524f, 0.013266419991850853f, 0.007620719727128744f, 0.006689779926091433f, 0.007916715927422047f, 0.006133179645985365f, 0.0047017172910273075f, 0.019493278115987778f, 0.003956243861466646f, 0.012879806570708752f, 0.004114826209843159f, 0.009119810536503792f, 0.005329393781721592f, 0.008689687587320805f, 0.0037786897737532854f, 0.007554387208074331f, 0.0035957549698650837f, 0.006710604764521122f, 0.013201836496591568f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #315 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_193_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000688781205099076f, 0.001222780323587358f, 0.0025854925625026226f, 0.0017724012723192573f, 0.0011477008229121566f, 0.0011397259077057242f, 0.002436371985822916f, 0.003565734950825572f, 0.0005646544741466641f, 0.0015606855740770698f, 0.0011956236558035016f, 0.0005683613708242774f, 0.0009525493951514363f, 0.002313339849933982f, 0.0006996722659096122f, 0.0008746746461838484f, 0.002113752532750368f, 0.0022034712601453066f, 0.0024377498775720596f, 0.0007449346012435853f, 0.0004901810898445547f, 0.0009670183644630015f, 0.0009042115998454392f, 0.0008410649606958032f, 0.0010022076312452555f, 0.0010384098859503865f, 0.002543995389714837f, 0.0017158292466774583f, 0.0006908081122674048f, 0.000841342203784734f, 0.0023979470133781433f, 0.0005213356926105917f, 0.0006050133379176259f, 0.0007379562593996525f, 0.001513791736215353f, 0.0013739169808104634f, 0.0006955374265089631f, 0.0009570326656103134f, 0.0013527775881811976f, 0.0006752711487933993f, 0.0012017559492960572f, 0.0009411657229065895f, 0.0011995084350928664f, 0.000628041394520551f, 0.001143718953244388f, 0.0005573499365709722f, 0.0009269455331377685f, 0.0009467979543842375f, 0.0009847587207332253f, 0.000776327564381063f, 0.0005724415532313287f, 0.0010818538721650839f, 0.0013681817799806595f, 0.0013359194854274392f, 0.0009249047143384814f, 0.0017501739785075188f, 0.0037359301932156086f, 0.0012974233832210302f, 0.0012535277055576444f, 0.0009258548961952329f, 0.0014053341001272202f, 0.0023186802864074707f, 0.0007334366091527045f, 0.0011324173538014293f, 0.0008718397584743798f, 0.0005122220609337091f, 0.0008865298004820943f, 0.0007063572993502021f, 0.0023072948679327965f, 0.0011398575734347105f, 0.0010850438848137856f, 0.0010899670887738466f, 0.0007066933321766555f, 0.0009397062822245061f, 0.0015098421135917306f, 0.001504396670497954f, 0.000546820170711726f, 0.00313971028663218f, 0.0011081118136644363f, 0.0008421550737693906f, 0.0007042968645691872f, 0.0009566410444676876f, 0.0010760145960375667f, 0.001230016932822764f, 0.0024683380033820868f, 0.001047672820277512f, 0.002182931872084737f, 0.0009625029051676393f, 0.0011529007460922003f, 0.0012567889643833041f, 0.0005684845382347703f, 0.0009484349866397679f, 0.0009715246269479394f, 0.0011000012746080756f, 0.00048394815530627966f, 0.001075520645827055f, 0.001894191955216229f, 0.0005434711929410696f, 0.0009419597336091101f, 0.0012023927411064506f, 0.0008036204962991178f, 0.0011663089971989393f, 0.0007466657552868128f, 0.0013570277951657772f, 0.0005815794575028121f, 0.0007210577605292201f, 0.0005733981961384416f, 0.0010123855900019407f, 0.0011852327734231949f, 0.0005762160290032625f, 0.0008037209045141935f, 0.0009489015792496502f, 0.0021901121363043785f, 0.0011042108526453376f, 0.000556296668946743f, 0.0012404387816786766f, 0.0011595732066780329f, 0.0006946938228793442f, 0.0015716643538326025f, 0.0011282855411991477f, 0.0007159232045523822f, 0.0008903300040401518f, 0.00302301743067801f, 0.001954342471435666f, 0.0007958341739140451f, 0.0007837982848286629f, 0.0013158436631783843f, 0.0013679440598934889f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #316 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_194_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003960782662034035f, 0.005940271075814962f, 0.0035718341823667288f, 0.0046067251823842525f, 0.01840343326330185f, 0.005371089093387127f, 0.005304595455527306f, 0.0043657273054122925f, 0.007885858416557312f, 0.019495805725455284f, 0.004647841211408377f, 0.019596291705965996f, 0.018842820078134537f, 0.003638769732788205f, 0.011954876594245434f, 0.009831180796027184f, 0.00927339494228363f, 0.005346432328224182f, 0.004416228737682104f, 0.004149316344410181f, 0.00585408229380846f, 0.005373002961277962f, 0.0044440277852118015f, 0.0028799562714993954f, 0.004909149836748838f, 0.004200236406177282f, 0.010923271998763084f, 0.005825751926749945f, 0.007047697436064482f, 0.00704679312184453f, 0.002920989179983735f, 0.004315494559705257f, 0.0070253354497253895f, 0.011213845573365688f, 0.0037321916315704584f, 0.0037092468701303005f, 0.01877814158797264f, 0.0045104664750397205f, 0.0035005267709493637f, 0.0048449221067130566f, 0.0034805263858288527f, 0.008186855353415012f, 0.018563376739621162f, 0.00486343540251255f, 0.0048080007545650005f, 0.009157142601907253f, 0.0051720100454986095f, 0.011645949445664883f, 0.006788407918065786f, 0.007834129966795444f, 0.004769157152622938f, 0.00409168004989624f, 0.004519344307482243f, 0.00721715809777379f, 0.0042320070788264275f, 0.005135202780365944f, 0.004286096431314945f, 0.004673834890127182f, 0.00297195790335536f, 0.004954376257956028f, 0.006643614266067743f, 0.011626633815467358f, 0.006978617049753666f, 0.005534852389246225f, 0.00732374656945467f, 0.0075475722551345825f, 0.0034400366712361574f, 0.0042652226984500885f, 0.004889301490038633f, 0.004199814982712269f, 0.005189124029129744f, 0.014182264916598797f, 0.006255101878196001f, 0.0054137008264660835f, 0.004510687198489904f, 0.004387679044157267f, 0.011310000903904438f, 0.0027029283810406923f, 0.021477067843079567f, 0.00486728735268116f, 0.005636191926896572f, 0.005276451352983713f, 0.021231262013316154f, 0.003928752616047859f, 0.006326679140329361f, 0.003971883561462164f, 0.003913345746695995f, 0.004348437301814556f, 0.004215434193611145f, 0.010116922669112682f, 0.0059092906303703785f, 0.003525779116898775f, 0.004508908372372389f, 0.01977008767426014f, 0.007900215685367584f, 0.009312893263995647f, 0.005837383680045605f, 0.011153778992593288f, 0.00548137491568923f, 0.0036170361563563347f, 0.006610060576349497f, 0.006767904385924339f, 0.005409738048911095f, 0.004524050280451775f, 0.010374397039413452f, 0.004159084055572748f, 0.0038216582033783197f, 0.0028280816040933132f, 0.0053412653505802155f, 0.021970823407173157f, 0.0070419590920209885f, 0.006847321521490812f, 0.003920713439583778f, 0.0036239929031580687f, 0.003040771698579192f, 0.0048000505194067955f, 0.015644265338778496f, 0.011672228574752808f, 0.00407864386215806f, 0.009566884487867355f, 0.003068762132897973f, 0.015545010566711426f, 0.002798058558255434f, 0.006616499274969101f, 0.007756224367767572f, 0.0032935873605310917f, 0.006723366677761078f, 0.005023116245865822f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_194_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_194_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_195_weights, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 25), AI_STRIDE_INIT(4, 1, 128, 3200, 3200),
  1, &conv2d_195_weights_array, &conv2d_195_weights_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_195_bias, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &conv2d_195_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_weights, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_203_weights_array, &conv2d_203_weights_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_bias, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_203_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_204_weights, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 20), AI_STRIDE_INIT(4, 1, 128, 2560, 2560),
  1, &conv2d_204_weights_array, &conv2d_204_weights_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_204_bias, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &conv2d_204_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_scratch0, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 1344, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1344, 1344),
  1, &conv2d_182_scratch0_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch0, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_32_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_scratch0, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_40_scratch0_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_scratch0, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_47_scratch0_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_scratch0, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 1408, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1408, 1408),
  1, &conv2d_151_scratch0_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_scratch0, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_51_scratch0_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_scratch0, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_53_scratch0_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_scratch0, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_59_scratch0_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_61_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_scratch0, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_63_scratch0_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_64_scratch0_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 2464, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2464, 2464),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 13248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13248, 13248),
  1, &conv2d_66_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch0, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_67_scratch0_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_68_scratch0, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_68_scratch0_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_69_scratch0, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_69_scratch0_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_70_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_70_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_71_scratch0, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_71_scratch0_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_scratch0, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_72_scratch0_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_73_scratch0, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_73_scratch0_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_scratch0, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_74_scratch0_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_75_scratch0, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_75_scratch0_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_76_scratch0, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_76_scratch0_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_77_scratch0, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 1, 762, 1, 1), AI_STRIDE_INIT(4, 1, 1, 762, 762),
  1, &conv2d_77_scratch0_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_82_scratch0, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_82_scratch0_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_83_scratch0, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 712, 1, 1), AI_STRIDE_INIT(4, 1, 1, 712, 712),
  1, &conv2d_83_scratch0_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_94_scratch0, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_94_scratch0_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_95_scratch0, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_95_scratch0_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_scratch0, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_96_scratch0_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_97_scratch0, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_97_scratch0_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_98_scratch0, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_98_scratch0_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_99_scratch0, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_99_scratch0_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_100_scratch0, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_100_scratch0_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_101_scratch0, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_101_scratch0_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_102_scratch0, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_102_scratch0_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_103_scratch0, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_103_scratch0_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_scratch0, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_104_scratch0_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_105_scratch0, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 762, 1, 1), AI_STRIDE_INIT(4, 1, 1, 762, 762),
  1, &conv2d_105_scratch0_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_110_scratch0, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_110_scratch0_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_scratch0, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 712, 1, 1), AI_STRIDE_INIT(4, 1, 1, 712, 712),
  1, &conv2d_111_scratch0_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_122_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_122_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_123_scratch0, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 1652, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1652, 1652),
  1, &conv2d_123_scratch0_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_124_scratch0, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 4219, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4219, 4219),
  1, &conv2d_124_scratch0_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_125_scratch0, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 1496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1496, 1496),
  1, &conv2d_125_scratch0_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_126_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 3849, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3849, 3849),
  1, &conv2d_126_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_scratch0, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 1696, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1696, 1696),
  1, &conv2d_127_scratch0_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_128_scratch0, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_128_scratch0_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_scratch0, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_129_scratch0_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_130_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_130_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_131_scratch0, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_131_scratch0_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_132_scratch0, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_132_scratch0_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_133_scratch0, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 762, 1, 1), AI_STRIDE_INIT(4, 1, 1, 762, 762),
  1, &conv2d_133_scratch0_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_138_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_138_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_139_scratch0, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 712, 1, 1), AI_STRIDE_INIT(4, 1, 1, 712, 712),
  1, &conv2d_139_scratch0_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_153_scratch0, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_153_scratch0_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_154_scratch0, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_154_scratch0_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_155_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_155_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_156_scratch0, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_156_scratch0_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_157_scratch0, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_157_scratch0_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_158_scratch0, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_158_scratch0_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_scratch0, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_159_scratch0_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_160_scratch0, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_160_scratch0_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_161_scratch0, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_161_scratch0_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_162_scratch0, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_162_scratch0_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_163_scratch0, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_163_scratch0_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_164_scratch0, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 762, 1, 1), AI_STRIDE_INIT(4, 1, 1, 762, 762),
  1, &conv2d_164_scratch0_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_169_scratch0, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_169_scratch0_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_170_scratch0, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 712, 1, 1), AI_STRIDE_INIT(4, 1, 1, 712, 712),
  1, &conv2d_170_scratch0_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_184_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_184_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_scratch0, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_185_scratch0_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_186_scratch0, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_186_scratch0_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_187_scratch0, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_187_scratch0_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_188_scratch0, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_188_scratch0_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_189_scratch0, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_189_scratch0_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_190_scratch0, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_190_scratch0_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_scratch0, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_191_scratch0_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_192_scratch0, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_192_scratch0_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_193_scratch0, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_193_scratch0_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_194_scratch0, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_194_scratch0_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_195_scratch0, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 762, 1, 1), AI_STRIDE_INIT(4, 1, 1, 762, 762),
  1, &conv2d_195_scratch0_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  nl_201_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 124, 1, 1), AI_STRIDE_INIT(4, 4, 4, 496, 496),
  1, &nl_201_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_scratch0, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_203_scratch0_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_204_scratch0, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 712, 1, 1), AI_STRIDE_INIT(4, 1, 1, 712, 712),
  1, &conv2d_204_scratch0_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conversion_218_output, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 3845), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conversion_218_output_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input_10_output, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 192, 192), AI_STRIDE_INIT(4, 1, 1, 3, 576),
  1, &serving_default_input_10_output_array, &serving_default_input_10_output_array_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 192, 192), AI_STRIDE_INIT(4, 1, 1, 3, 576),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  134, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 96, 96), AI_STRIDE_INIT(4, 1, 1, 16, 1536),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_pad_before_output, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 98, 98), AI_STRIDE_INIT(4, 1, 1, 16, 1568),
  1, &conv2d_2_pad_before_output_array, &conv2d_2_pad_before_output_array_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 96, 96), AI_STRIDE_INIT(4, 1, 1, 16, 1536),
  1, &conv2d_2_output_array, &conv2d_2_output_array_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 96, 96), AI_STRIDE_INIT(4, 1, 1, 8, 768),
  1, &conv2d_3_output_array, &conv2d_3_output_array_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 96, 96), AI_STRIDE_INIT(4, 1, 1, 48, 4608),
  1, &conv2d_4_output_array, &conv2d_4_output_array_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_pad_before_output, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 97, 97), AI_STRIDE_INIT(4, 1, 1, 48, 4656),
  1, &conv2d_6_pad_before_output_array, &conv2d_6_pad_before_output_array_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 48, 48), AI_STRIDE_INIT(4, 1, 1, 48, 2304),
  1, &conv2d_6_output_array, &conv2d_6_output_array_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_7_output_array, &conv2d_7_output_array_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  142, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 48, 48), AI_STRIDE_INIT(4, 1, 1, 48, 2304),
  1, &conv2d_8_output_array, &conv2d_8_output_array_intq)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_pad_before_output, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 50, 50), AI_STRIDE_INIT(4, 1, 1, 48, 2400),
  1, &conv2d_9_pad_before_output_array, &conv2d_9_pad_before_output_array_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 48, 48), AI_STRIDE_INIT(4, 1, 1, 48, 2304),
  1, &conv2d_9_output_array, &conv2d_9_output_array_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_10_output_array, &conv2d_10_output_array_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  146, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &eltwise_11_output_array, &eltwise_11_output_array_intq)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 48, 48), AI_STRIDE_INIT(4, 1, 1, 48, 2304),
  1, &conv2d_12_output_array, &conv2d_12_output_array_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_pad_before_output, AI_STATIC,
  148, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 49, 49), AI_STRIDE_INIT(4, 1, 1, 48, 2352),
  1, &conv2d_14_pad_before_output_array, &conv2d_14_pad_before_output_array_intq)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 24, 24), AI_STRIDE_INIT(4, 1, 1, 48, 1152),
  1, &conv2d_14_output_array, &conv2d_14_output_array_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_15_output_array, &conv2d_15_output_array_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  151, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 24, 24), AI_STRIDE_INIT(4, 1, 1, 96, 2304),
  1, &conv2d_16_output_array, &conv2d_16_output_array_intq)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_pad_before_output, AI_STATIC,
  152, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 26, 26), AI_STRIDE_INIT(4, 1, 1, 96, 2496),
  1, &conv2d_17_pad_before_output_array, &conv2d_17_pad_before_output_array_intq)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 24, 24), AI_STRIDE_INIT(4, 1, 1, 96, 2304),
  1, &conv2d_17_output_array, &conv2d_17_output_array_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  154, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_18_output_array, &conv2d_18_output_array_intq)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_output, AI_STATIC,
  155, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &eltwise_19_output_array, &eltwise_19_output_array_intq)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  156, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 24, 24), AI_STRIDE_INIT(4, 1, 1, 96, 2304),
  1, &conv2d_20_output_array, &conv2d_20_output_array_intq)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_pad_before_output, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 26, 26), AI_STRIDE_INIT(4, 1, 1, 96, 2496),
  1, &conv2d_21_pad_before_output_array, &conv2d_21_pad_before_output_array_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  158, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 24, 24), AI_STRIDE_INIT(4, 1, 1, 96, 2304),
  1, &conv2d_21_output_array, &conv2d_21_output_array_intq)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  159, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_22_output_array, &conv2d_22_output_array_intq)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_output, AI_STATIC,
  160, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &eltwise_23_output_array, &eltwise_23_output_array_intq)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_output, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_182_output_array, &conv2d_182_output_array_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 24, 24), AI_STRIDE_INIT(4, 1, 1, 96, 2304),
  1, &conv2d_24_output_array, &conv2d_24_output_array_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_pad_before_output, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 25, 25), AI_STRIDE_INIT(4, 1, 1, 96, 2400),
  1, &conv2d_26_pad_before_output_array, &conv2d_26_pad_before_output_array_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  164, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 12, 12), AI_STRIDE_INIT(4, 1, 1, 96, 1152),
  1, &conv2d_26_output_array, &conv2d_26_output_array_intq)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &conv2d_27_output_array, &conv2d_27_output_array_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  166, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_28_output_array, &conv2d_28_output_array_intq)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_pad_before_output, AI_STATIC,
  167, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_pad_before_output_array, &conv2d_29_pad_before_output_array_intq)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  168, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_29_output_array, &conv2d_29_output_array_intq)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &conv2d_30_output_array, &conv2d_30_output_array_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_31_output, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &eltwise_31_output_array, &eltwise_31_output_array_intq)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_32_output_array, &conv2d_32_output_array_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_pad_before_output, AI_STATIC,
  172, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_pad_before_output_array, &conv2d_33_pad_before_output_array_intq)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_33_output_array, &conv2d_33_output_array_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  174, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &conv2d_34_output_array, &conv2d_34_output_array_intq)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_output, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &eltwise_35_output_array, &eltwise_35_output_array_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  176, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_36_output_array, &conv2d_36_output_array_intq)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_pad_before_output, AI_STATIC,
  177, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_pad_before_output_array, &conv2d_37_pad_before_output_array_intq)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  178, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_37_output_array, &conv2d_37_output_array_intq)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  179, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &conv2d_38_output_array, &conv2d_38_output_array_intq)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_39_output, AI_STATIC,
  180, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 12, 12), AI_STRIDE_INIT(4, 1, 1, 24, 288),
  1, &eltwise_39_output_array, &eltwise_39_output_array_intq)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_output, AI_STATIC,
  181, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_40_output_array, &conv2d_40_output_array_intq)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_pad_before_output, AI_STATIC,
  182, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_pad_before_output_array, &conv2d_41_pad_before_output_array_intq)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 12, 12), AI_STRIDE_INIT(4, 1, 1, 144, 1728),
  1, &conv2d_41_output_array, &conv2d_41_output_array_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  184, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_42_output_array, &conv2d_42_output_array_intq)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 12, 12), AI_STRIDE_INIT(4, 1, 1, 192, 2304),
  1, &conv2d_43_output_array, &conv2d_43_output_array_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_pad_before_output, AI_STATIC,
  186, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_pad_before_output_array, &conv2d_44_pad_before_output_array_intq)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  187, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 12, 12), AI_STRIDE_INIT(4, 1, 1, 192, 2304),
  1, &conv2d_44_output_array, &conv2d_44_output_array_intq)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  188, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_45_output_array, &conv2d_45_output_array_intq)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_46_output, AI_STATIC,
  189, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &eltwise_46_output_array, &eltwise_46_output_array_intq)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_output, AI_STATIC,
  190, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 12, 12), AI_STRIDE_INIT(4, 1, 1, 192, 2304),
  1, &conv2d_47_output_array, &conv2d_47_output_array_intq)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_pad_before_output, AI_STATIC,
  191, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_pad_before_output_array, &conv2d_48_pad_before_output_array_intq)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  192, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 12, 12), AI_STRIDE_INIT(4, 1, 1, 192, 2304),
  1, &conv2d_48_output_array, &conv2d_48_output_array_intq)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  193, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_49_output_array, &conv2d_49_output_array_intq)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_output, AI_STATIC,
  194, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &eltwise_50_output_array, &eltwise_50_output_array_intq)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_output, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_151_output_array, &conv2d_151_output_array_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_output, AI_STATIC,
  196, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 12, 12), AI_STRIDE_INIT(4, 1, 1, 192, 2304),
  1, &conv2d_51_output_array, &conv2d_51_output_array_intq)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_pad_before_output, AI_STATIC,
  197, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 13, 13), AI_STRIDE_INIT(4, 1, 1, 192, 2496),
  1, &conv2d_53_pad_before_output_array, &conv2d_53_pad_before_output_array_intq)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_output, AI_STATIC,
  198, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 6, 6), AI_STRIDE_INIT(4, 1, 1, 192, 1152),
  1, &conv2d_53_output_array, &conv2d_53_output_array_intq)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  199, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 6, 6), AI_STRIDE_INIT(4, 1, 1, 56, 336),
  1, &conv2d_54_output_array, &conv2d_54_output_array_intq)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  200, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_55_output_array, &conv2d_55_output_array_intq)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_pad_before_output, AI_STATIC,
  201, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 8, 8), AI_STRIDE_INIT(4, 1, 1, 336, 2688),
  1, &conv2d_56_pad_before_output_array, &conv2d_56_pad_before_output_array_intq)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  202, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_56_output_array, &conv2d_56_output_array_intq)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_output, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 6, 6), AI_STRIDE_INIT(4, 1, 1, 56, 336),
  1, &conv2d_57_output_array, &conv2d_57_output_array_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_58_output, AI_STATIC,
  204, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 6, 6), AI_STRIDE_INIT(4, 1, 1, 56, 336),
  1, &eltwise_58_output_array, &eltwise_58_output_array_intq)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_output, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_59_output_array, &conv2d_59_output_array_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_pad_before_output, AI_STATIC,
  206, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 8, 8), AI_STRIDE_INIT(4, 1, 1, 336, 2688),
  1, &conv2d_60_pad_before_output_array, &conv2d_60_pad_before_output_array_intq)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_output, AI_STATIC,
  207, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_60_output_array, &conv2d_60_output_array_intq)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_output, AI_STATIC,
  208, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 6, 6), AI_STRIDE_INIT(4, 1, 1, 56, 336),
  1, &conv2d_61_output_array, &conv2d_61_output_array_intq)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_62_output, AI_STATIC,
  209, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 6, 6), AI_STRIDE_INIT(4, 1, 1, 56, 336),
  1, &eltwise_62_output_array, &eltwise_62_output_array_intq)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_output, AI_STATIC,
  210, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_63_output_array, &conv2d_63_output_array_intq)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_pad_before_output, AI_STATIC,
  211, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 8, 8), AI_STRIDE_INIT(4, 1, 1, 336, 2688),
  1, &conv2d_64_pad_before_output_array, &conv2d_64_pad_before_output_array_intq)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  212, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_64_output_array, &conv2d_64_output_array_intq)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 6, 6), AI_STRIDE_INIT(4, 1, 1, 112, 672),
  1, &conv2d_65_output_array, &conv2d_65_output_array_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_output, AI_STATIC,
  214, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 6, 6), AI_STRIDE_INIT(4, 1, 1, 1280, 7680),
  1, &conv2d_66_output_array, &conv2d_66_output_array_intq)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_output, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_67_output_array, &conv2d_67_output_array_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_68_pad_before_output, AI_STATIC,
  216, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_68_pad_before_output_array, &conv2d_68_pad_before_output_array_intq)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_68_output, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_68_output_array, &conv2d_68_output_array_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_69_output, AI_STATIC,
  218, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_69_output_array, &conv2d_69_output_array_intq)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_70_pad_before_output, AI_STATIC,
  219, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_70_pad_before_output_array, &conv2d_70_pad_before_output_array_intq)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_70_output, AI_STATIC,
  220, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_70_output_array, &conv2d_70_output_array_intq)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_71_output, AI_STATIC,
  221, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_71_output_array, &conv2d_71_output_array_intq)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_pad_before_output, AI_STATIC,
  222, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_72_pad_before_output_array, &conv2d_72_pad_before_output_array_intq)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_output, AI_STATIC,
  223, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_72_output_array, &conv2d_72_output_array_intq)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_73_output, AI_STATIC,
  224, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_73_output_array, &conv2d_73_output_array_intq)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_pad_before_output, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_74_pad_before_output_array, &conv2d_74_pad_before_output_array_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_output, AI_STATIC,
  226, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_74_output_array, &conv2d_74_output_array_intq)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_75_output, AI_STATIC,
  227, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_75_output_array, &conv2d_75_output_array_intq)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_76_pad_before_output, AI_STATIC,
  228, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_76_pad_before_output_array, &conv2d_76_pad_before_output_array_intq)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_76_output, AI_STATIC,
  229, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_76_output_array, &conv2d_76_output_array_intq)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_77_output, AI_STATIC,
  230, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 6, 6), AI_STRIDE_INIT(4, 1, 1, 25, 150),
  1, &conv2d_77_output_array, &conv2d_77_output_array_intq)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_77_output0, AI_STATIC,
  231, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 180), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &conv2d_77_output_array, &conv2d_77_output_array_intq)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_82_pad_before_output, AI_STATIC,
  232, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_82_pad_before_output_array, &conv2d_82_pad_before_output_array_intq)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_82_output, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_82_output_array, &conv2d_82_output_array_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_83_output, AI_STATIC,
  234, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 6, 6), AI_STRIDE_INIT(4, 1, 1, 20, 120),
  1, &conv2d_83_output_array, &conv2d_83_output_array_intq)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_83_output0, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 180), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &conv2d_83_output_array, &conv2d_83_output_array_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_94_pad_before_output, AI_STATIC,
  236, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_94_pad_before_output_array, &conv2d_94_pad_before_output_array_intq)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_94_output, AI_STATIC,
  237, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_94_output_array, &conv2d_94_output_array_intq)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_95_output, AI_STATIC,
  238, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_95_output_array, &conv2d_95_output_array_intq)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_pad_before_output, AI_STATIC,
  239, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_96_pad_before_output_array, &conv2d_96_pad_before_output_array_intq)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_output, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_96_output_array, &conv2d_96_output_array_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_97_output, AI_STATIC,
  241, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_97_output_array, &conv2d_97_output_array_intq)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_98_pad_before_output, AI_STATIC,
  242, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_98_pad_before_output_array, &conv2d_98_pad_before_output_array_intq)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_98_output, AI_STATIC,
  243, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_98_output_array, &conv2d_98_output_array_intq)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_99_output, AI_STATIC,
  244, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_99_output_array, &conv2d_99_output_array_intq)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_100_pad_before_output, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_100_pad_before_output_array, &conv2d_100_pad_before_output_array_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_100_output, AI_STATIC,
  246, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_100_output_array, &conv2d_100_output_array_intq)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_101_output, AI_STATIC,
  247, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_101_output_array, &conv2d_101_output_array_intq)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_102_pad_before_output, AI_STATIC,
  248, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_102_pad_before_output_array, &conv2d_102_pad_before_output_array_intq)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_102_output, AI_STATIC,
  249, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_102_output_array, &conv2d_102_output_array_intq)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_103_output, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_103_output_array, &conv2d_103_output_array_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_pad_before_output, AI_STATIC,
  251, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_104_pad_before_output_array, &conv2d_104_pad_before_output_array_intq)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_output, AI_STATIC,
  252, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_104_output_array, &conv2d_104_output_array_intq)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_105_output, AI_STATIC,
  253, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 3, 3), AI_STRIDE_INIT(4, 1, 1, 25, 75),
  1, &conv2d_105_output_array, &conv2d_105_output_array_intq)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_105_output0, AI_STATIC,
  254, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 45), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &conv2d_105_output_array, &conv2d_105_output_array_intq)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_110_pad_before_output, AI_STATIC,
  255, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_110_pad_before_output_array, &conv2d_110_pad_before_output_array_intq)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_110_output, AI_STATIC,
  256, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_110_output_array, &conv2d_110_output_array_intq)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_output, AI_STATIC,
  257, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 3, 3), AI_STRIDE_INIT(4, 1, 1, 20, 60),
  1, &conv2d_111_output_array, &conv2d_111_output_array_intq)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_output0, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 45), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &conv2d_111_output_array, &conv2d_111_output_array_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_122_pad_before_output, AI_STATIC,
  259, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_122_pad_before_output_array, &conv2d_122_pad_before_output_array_intq)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_122_output, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_122_output_array, &conv2d_122_output_array_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_123_output, AI_STATIC,
  261, 0x1,
  AI_SHAPE_INIT(4, 1, 114, 2, 2), AI_STRIDE_INIT(4, 1, 1, 114, 228),
  1, &conv2d_123_output_array, &conv2d_123_output_array_intq)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_124_pad_before_output, AI_STATIC,
  262, 0x1,
  AI_SHAPE_INIT(4, 1, 114, 4, 4), AI_STRIDE_INIT(4, 1, 1, 114, 456),
  1, &conv2d_124_pad_before_output_array, &conv2d_124_pad_before_output_array_intq)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_124_output, AI_STATIC,
  263, 0x1,
  AI_SHAPE_INIT(4, 1, 114, 2, 2), AI_STRIDE_INIT(4, 1, 1, 114, 228),
  1, &conv2d_124_output_array, &conv2d_124_output_array_intq)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_125_output, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 2, 2), AI_STRIDE_INIT(4, 1, 1, 104, 208),
  1, &conv2d_125_output_array, &conv2d_125_output_array_intq)

/* Tensor #265 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_126_pad_before_output, AI_STATIC,
  265, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 4, 4), AI_STRIDE_INIT(4, 1, 1, 104, 416),
  1, &conv2d_126_pad_before_output_array, &conv2d_126_pad_before_output_array_intq)

/* Tensor #266 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_126_output, AI_STATIC,
  266, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 2, 2), AI_STRIDE_INIT(4, 1, 1, 104, 208),
  1, &conv2d_126_output_array, &conv2d_126_output_array_intq)

/* Tensor #267 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_output, AI_STATIC,
  267, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_127_output_array, &conv2d_127_output_array_intq)

/* Tensor #268 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_128_pad_before_output, AI_STATIC,
  268, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &conv2d_128_pad_before_output_array, &conv2d_128_pad_before_output_array_intq)

/* Tensor #269 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_128_output, AI_STATIC,
  269, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_128_output_array, &conv2d_128_output_array_intq)

/* Tensor #270 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_output, AI_STATIC,
  270, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_129_output_array, &conv2d_129_output_array_intq)

/* Tensor #271 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_130_pad_before_output, AI_STATIC,
  271, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &conv2d_130_pad_before_output_array, &conv2d_130_pad_before_output_array_intq)

/* Tensor #272 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_130_output, AI_STATIC,
  272, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_130_output_array, &conv2d_130_output_array_intq)

/* Tensor #273 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_131_output, AI_STATIC,
  273, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_131_output_array, &conv2d_131_output_array_intq)

/* Tensor #274 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_132_pad_before_output, AI_STATIC,
  274, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &conv2d_132_pad_before_output_array, &conv2d_132_pad_before_output_array_intq)

/* Tensor #275 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_132_output, AI_STATIC,
  275, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_132_output_array, &conv2d_132_output_array_intq)

/* Tensor #276 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_133_output, AI_STATIC,
  276, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 2, 2), AI_STRIDE_INIT(4, 1, 1, 25, 50),
  1, &conv2d_133_output_array, &conv2d_133_output_array_intq)

/* Tensor #277 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_133_output0, AI_STATIC,
  277, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 20), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &conv2d_133_output_array, &conv2d_133_output_array_intq)

/* Tensor #278 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_138_pad_before_output, AI_STATIC,
  278, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &conv2d_138_pad_before_output_array, &conv2d_138_pad_before_output_array_intq)

/* Tensor #279 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_138_output, AI_STATIC,
  279, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_138_output_array, &conv2d_138_output_array_intq)

/* Tensor #280 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_139_output, AI_STATIC,
  280, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 2, 2), AI_STRIDE_INIT(4, 1, 1, 20, 40),
  1, &conv2d_139_output_array, &conv2d_139_output_array_intq)

/* Tensor #281 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_139_output0, AI_STATIC,
  281, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 20), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &conv2d_139_output_array, &conv2d_139_output_array_intq)

/* Tensor #282 */
AI_TENSOR_OBJ_DECLARE(
  upsample_150_output, AI_STATIC,
  282, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &upsample_150_output_array, &upsample_150_output_array_intq)

/* Tensor #283 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_152_output, AI_STATIC,
  283, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &eltwise_152_output_array, &eltwise_152_output_array_intq)

/* Tensor #284 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_153_pad_before_output, AI_STATIC,
  284, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_153_pad_before_output_array, &conv2d_153_pad_before_output_array_intq)

/* Tensor #285 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_153_output, AI_STATIC,
  285, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_153_output_array, &conv2d_153_output_array_intq)

/* Tensor #286 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_154_output, AI_STATIC,
  286, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_154_output_array, &conv2d_154_output_array_intq)

/* Tensor #287 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_155_pad_before_output, AI_STATIC,
  287, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_155_pad_before_output_array, &conv2d_155_pad_before_output_array_intq)

/* Tensor #288 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_155_output, AI_STATIC,
  288, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_155_output_array, &conv2d_155_output_array_intq)

/* Tensor #289 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_156_output, AI_STATIC,
  289, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_156_output_array, &conv2d_156_output_array_intq)

/* Tensor #290 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_157_pad_before_output, AI_STATIC,
  290, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_157_pad_before_output_array, &conv2d_157_pad_before_output_array_intq)

/* Tensor #291 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_157_output, AI_STATIC,
  291, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_157_output_array, &conv2d_157_output_array_intq)

/* Tensor #292 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_158_output, AI_STATIC,
  292, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_158_output_array, &conv2d_158_output_array_intq)

/* Tensor #293 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_pad_before_output, AI_STATIC,
  293, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_159_pad_before_output_array, &conv2d_159_pad_before_output_array_intq)

/* Tensor #294 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_output, AI_STATIC,
  294, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_159_output_array, &conv2d_159_output_array_intq)

/* Tensor #295 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_160_output, AI_STATIC,
  295, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_160_output_array, &conv2d_160_output_array_intq)

/* Tensor #296 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_161_pad_before_output, AI_STATIC,
  296, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_161_pad_before_output_array, &conv2d_161_pad_before_output_array_intq)

/* Tensor #297 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_161_output, AI_STATIC,
  297, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_161_output_array, &conv2d_161_output_array_intq)

/* Tensor #298 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_162_output, AI_STATIC,
  298, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_162_output_array, &conv2d_162_output_array_intq)

/* Tensor #299 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_163_pad_before_output, AI_STATIC,
  299, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_163_pad_before_output_array, &conv2d_163_pad_before_output_array_intq)

/* Tensor #300 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_163_output, AI_STATIC,
  300, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_163_output_array, &conv2d_163_output_array_intq)

/* Tensor #301 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_164_output, AI_STATIC,
  301, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 12, 12), AI_STRIDE_INIT(4, 1, 1, 25, 300),
  1, &conv2d_164_output_array, &conv2d_164_output_array_intq)

/* Tensor #302 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_164_output0, AI_STATIC,
  302, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 720), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &conv2d_164_output_array, &conv2d_164_output_array_intq)

/* Tensor #303 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_169_pad_before_output, AI_STATIC,
  303, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 14, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1792),
  1, &conv2d_169_pad_before_output_array, &conv2d_169_pad_before_output_array_intq)

/* Tensor #304 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_169_output, AI_STATIC,
  304, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 12), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &conv2d_169_output_array, &conv2d_169_output_array_intq)

/* Tensor #305 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_170_output, AI_STATIC,
  305, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 12, 12), AI_STRIDE_INIT(4, 1, 1, 20, 240),
  1, &conv2d_170_output_array, &conv2d_170_output_array_intq)

/* Tensor #306 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_170_output0, AI_STATIC,
  306, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 720), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &conv2d_170_output_array, &conv2d_170_output_array_intq)

/* Tensor #307 */
AI_TENSOR_OBJ_DECLARE(
  upsample_181_output, AI_STATIC,
  307, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &upsample_181_output_array, &upsample_181_output_array_intq)

/* Tensor #308 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_183_output, AI_STATIC,
  308, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &eltwise_183_output_array, &eltwise_183_output_array_intq)

/* Tensor #309 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_184_pad_before_output, AI_STATIC,
  309, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_184_pad_before_output_array, &conv2d_184_pad_before_output_array_intq)

/* Tensor #310 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_184_output, AI_STATIC,
  310, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_184_output_array, &conv2d_184_output_array_intq)

/* Tensor #311 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_output, AI_STATIC,
  311, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_185_output_array, &conv2d_185_output_array_intq)

/* Tensor #312 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_186_pad_before_output, AI_STATIC,
  312, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_186_pad_before_output_array, &conv2d_186_pad_before_output_array_intq)

/* Tensor #313 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_186_output, AI_STATIC,
  313, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_186_output_array, &conv2d_186_output_array_intq)

/* Tensor #314 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_187_output, AI_STATIC,
  314, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_187_output_array, &conv2d_187_output_array_intq)

/* Tensor #315 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_188_pad_before_output, AI_STATIC,
  315, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_188_pad_before_output_array, &conv2d_188_pad_before_output_array_intq)

/* Tensor #316 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_188_output, AI_STATIC,
  316, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_188_output_array, &conv2d_188_output_array_intq)

/* Tensor #317 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_189_output, AI_STATIC,
  317, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_189_output_array, &conv2d_189_output_array_intq)

/* Tensor #318 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_190_pad_before_output, AI_STATIC,
  318, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_190_pad_before_output_array, &conv2d_190_pad_before_output_array_intq)

/* Tensor #319 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_190_output, AI_STATIC,
  319, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_190_output_array, &conv2d_190_output_array_intq)

/* Tensor #320 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_output, AI_STATIC,
  320, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_191_output_array, &conv2d_191_output_array_intq)

/* Tensor #321 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_192_pad_before_output, AI_STATIC,
  321, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_192_pad_before_output_array, &conv2d_192_pad_before_output_array_intq)

/* Tensor #322 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_192_output, AI_STATIC,
  322, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_192_output_array, &conv2d_192_output_array_intq)

/* Tensor #323 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_193_output, AI_STATIC,
  323, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_193_output_array, &conv2d_193_output_array_intq)

/* Tensor #324 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_194_pad_before_output, AI_STATIC,
  324, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_194_pad_before_output_array, &conv2d_194_pad_before_output_array_intq)

/* Tensor #325 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_194_output, AI_STATIC,
  325, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_194_output_array, &conv2d_194_output_array_intq)

/* Tensor #326 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_195_output, AI_STATIC,
  326, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 24, 24), AI_STRIDE_INIT(4, 1, 1, 25, 600),
  1, &conv2d_195_output_array, &conv2d_195_output_array_intq)

/* Tensor #327 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_195_output0, AI_STATIC,
  327, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 2880), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &conv2d_195_output_array, &conv2d_195_output_array_intq)

/* Tensor #328 */
AI_TENSOR_OBJ_DECLARE(
  concat_200_output, AI_STATIC,
  328, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 3845), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &concat_200_output_array, &concat_200_output_array_intq)

/* Tensor #329 */
AI_TENSOR_OBJ_DECLARE(
  nl_201_output, AI_STATIC,
  329, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 3845), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &nl_201_output_array, &nl_201_output_array_intq)

/* Tensor #330 */
AI_TENSOR_OBJ_DECLARE(
  conversion_202_output, AI_STATIC,
  330, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 3845), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &conversion_202_output_array, NULL)

/* Tensor #331 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_pad_before_output, AI_STATIC,
  331, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 26, 26), AI_STRIDE_INIT(4, 1, 1, 128, 3328),
  1, &conv2d_203_pad_before_output_array, &conv2d_203_pad_before_output_array_intq)

/* Tensor #332 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_output, AI_STATIC,
  332, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 24), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &conv2d_203_output_array, &conv2d_203_output_array_intq)

/* Tensor #333 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_204_output, AI_STATIC,
  333, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 24, 24), AI_STRIDE_INIT(4, 1, 1, 20, 480),
  1, &conv2d_204_output_array, &conv2d_204_output_array_intq)

/* Tensor #334 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_204_output0, AI_STATIC,
  334, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 2880), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &conv2d_204_output_array, &conv2d_204_output_array_intq)

/* Tensor #335 */
AI_TENSOR_OBJ_DECLARE(
  concat_209_output, AI_STATIC,
  335, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 3845), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &concat_209_output_array, &concat_209_output_array_intq)

/* Tensor #336 */
AI_TENSOR_OBJ_DECLARE(
  conversion_210_output, AI_STATIC,
  336, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 3845), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conversion_210_output_array, NULL)

/* Tensor #337 */
AI_TENSOR_OBJ_DECLARE(
  concat_217_const, AI_STATIC,
  337, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 1, 3845), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &concat_217_const_array, &concat_217_const_array_intq)

/* Tensor #338 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  338, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 48, 144),
  1, &conv2d_1_weights_array, &conv2d_1_weights_array_intq)

/* Tensor #339 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  339, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #340 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  340, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 16, 48),
  1, &conv2d_2_weights_array, &conv2d_2_weights_array_intq)

/* Tensor #341 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  341, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #342 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  342, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 1, 16, 128, 128),
  1, &conv2d_3_weights_array, &conv2d_3_weights_array_intq)

/* Tensor #343 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  343, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #344 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  344, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_4_weights_array, &conv2d_4_weights_array_intq)

/* Tensor #345 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  345, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #346 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  346, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_6_weights_array, &conv2d_6_weights_array_intq)

/* Tensor #347 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  347, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_6_bias_array, NULL)

/* Tensor #348 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  348, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 384, 384),
  1, &conv2d_7_weights_array, &conv2d_7_weights_array_intq)

/* Tensor #349 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  349, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #350 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  350, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_8_weights_array, &conv2d_8_weights_array_intq)

/* Tensor #351 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  351, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_8_bias_array, NULL)

/* Tensor #352 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  352, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_9_weights_array, &conv2d_9_weights_array_intq)

/* Tensor #353 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  353, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #354 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  354, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 384, 384),
  1, &conv2d_10_weights_array, &conv2d_10_weights_array_intq)

/* Tensor #355 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  355, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_10_bias_array, NULL)

/* Tensor #356 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  356, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_12_weights_array, &conv2d_12_weights_array_intq)

/* Tensor #357 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  357, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_12_bias_array, NULL)

/* Tensor #358 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  358, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_14_weights_array, &conv2d_14_weights_array_intq)

/* Tensor #359 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  359, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_14_bias_array, NULL)

/* Tensor #360 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  360, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 768, 768),
  1, &conv2d_15_weights_array, &conv2d_15_weights_array_intq)

/* Tensor #361 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  361, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_15_bias_array, NULL)

/* Tensor #362 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  362, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_16_weights_array, &conv2d_16_weights_array_intq)

/* Tensor #363 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  363, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #364 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  364, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_17_weights_array, &conv2d_17_weights_array_intq)

/* Tensor #365 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  365, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #366 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  366, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 1536, 1536),
  1, &conv2d_18_weights_array, &conv2d_18_weights_array_intq)

/* Tensor #367 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  367, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_18_bias_array, NULL)

/* Tensor #368 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  368, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_20_weights_array, &conv2d_20_weights_array_intq)

/* Tensor #369 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  369, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_20_bias_array, NULL)

/* Tensor #370 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  370, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_21_weights_array, &conv2d_21_weights_array_intq)

/* Tensor #371 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  371, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, NULL)

/* Tensor #372 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  372, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 1536, 1536),
  1, &conv2d_22_weights_array, &conv2d_22_weights_array_intq)

/* Tensor #373 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  373, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_22_bias_array, NULL)

/* Tensor #374 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_weights, AI_STATIC,
  374, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 128), AI_STRIDE_INIT(4, 1, 16, 2048, 2048),
  1, &conv2d_182_weights_array, &conv2d_182_weights_array_intq)

/* Tensor #375 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_bias, AI_STATIC,
  375, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_182_bias_array, NULL)

/* Tensor #376 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  376, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_24_weights_array, &conv2d_24_weights_array_intq)

/* Tensor #377 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  377, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_24_bias_array, NULL)

/* Tensor #378 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  378, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_26_weights_array, &conv2d_26_weights_array_intq)

/* Tensor #379 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  379, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_26_bias_array, NULL)

/* Tensor #380 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  380, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 2304, 2304),
  1, &conv2d_27_weights_array, &conv2d_27_weights_array_intq)

/* Tensor #381 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  381, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_27_bias_array, NULL)

/* Tensor #382 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  382, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_28_weights_array, &conv2d_28_weights_array_intq)

/* Tensor #383 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  383, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_28_bias_array, NULL)

/* Tensor #384 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  384, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_29_weights_array, &conv2d_29_weights_array_intq)

/* Tensor #385 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  385, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_29_bias_array, NULL)

/* Tensor #386 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  386, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_30_weights_array, &conv2d_30_weights_array_intq)

/* Tensor #387 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  387, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_30_bias_array, NULL)

/* Tensor #388 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  388, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_32_weights_array, &conv2d_32_weights_array_intq)

/* Tensor #389 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  389, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_32_bias_array, NULL)

/* Tensor #390 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  390, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_33_weights_array, &conv2d_33_weights_array_intq)

/* Tensor #391 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  391, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_33_bias_array, NULL)

/* Tensor #392 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  392, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_34_weights_array, &conv2d_34_weights_array_intq)

/* Tensor #393 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  393, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_34_bias_array, NULL)

/* Tensor #394 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  394, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_36_weights_array, &conv2d_36_weights_array_intq)

/* Tensor #395 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  395, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_36_bias_array, NULL)

/* Tensor #396 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  396, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_37_weights_array, &conv2d_37_weights_array_intq)

/* Tensor #397 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  397, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_37_bias_array, NULL)

/* Tensor #398 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  398, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_38_weights_array, &conv2d_38_weights_array_intq)

/* Tensor #399 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  399, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_38_bias_array, NULL)

/* Tensor #400 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_weights, AI_STATIC,
  400, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_40_weights_array, &conv2d_40_weights_array_intq)

/* Tensor #401 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_bias, AI_STATIC,
  401, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_40_bias_array, NULL)

/* Tensor #402 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  402, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_41_weights_array, &conv2d_41_weights_array_intq)

/* Tensor #403 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  403, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_41_bias_array, NULL)

/* Tensor #404 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  404, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 1, 144, 4608, 4608),
  1, &conv2d_42_weights_array, &conv2d_42_weights_array_intq)

/* Tensor #405 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  405, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_42_bias_array, NULL)

/* Tensor #406 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  406, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_43_weights_array, &conv2d_43_weights_array_intq)

/* Tensor #407 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  407, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_43_bias_array, NULL)

/* Tensor #408 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  408, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_44_weights_array, &conv2d_44_weights_array_intq)

/* Tensor #409 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  409, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_44_bias_array, NULL)

/* Tensor #410 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  410, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 6144, 6144),
  1, &conv2d_45_weights_array, &conv2d_45_weights_array_intq)

/* Tensor #411 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  411, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_45_bias_array, NULL)

/* Tensor #412 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_weights, AI_STATIC,
  412, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_47_weights_array, &conv2d_47_weights_array_intq)

/* Tensor #413 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_bias, AI_STATIC,
  413, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_47_bias_array, NULL)

/* Tensor #414 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  414, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_48_weights_array, &conv2d_48_weights_array_intq)

/* Tensor #415 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  415, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_48_bias_array, NULL)

/* Tensor #416 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  416, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 6144, 6144),
  1, &conv2d_49_weights_array, &conv2d_49_weights_array_intq)

/* Tensor #417 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  417, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_49_bias_array, NULL)

/* Tensor #418 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_weights, AI_STATIC,
  418, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 128), AI_STRIDE_INIT(4, 1, 32, 4096, 4096),
  1, &conv2d_151_weights_array, &conv2d_151_weights_array_intq)

/* Tensor #419 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_bias, AI_STATIC,
  419, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_151_bias_array, NULL)

/* Tensor #420 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_weights, AI_STATIC,
  420, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_51_weights_array, &conv2d_51_weights_array_intq)

/* Tensor #421 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_bias, AI_STATIC,
  421, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_51_bias_array, NULL)

/* Tensor #422 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_weights, AI_STATIC,
  422, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_53_weights_array, &conv2d_53_weights_array_intq)

/* Tensor #423 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_bias, AI_STATIC,
  423, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_53_bias_array, NULL)

/* Tensor #424 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  424, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 1, 192, 10752, 10752),
  1, &conv2d_54_weights_array, &conv2d_54_weights_array_intq)

/* Tensor #425 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  425, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_54_bias_array, NULL)

/* Tensor #426 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  426, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_55_weights_array, &conv2d_55_weights_array_intq)

/* Tensor #427 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  427, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_55_bias_array, NULL)

/* Tensor #428 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  428, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_56_weights_array, &conv2d_56_weights_array_intq)

/* Tensor #429 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  429, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_56_bias_array, NULL)

/* Tensor #430 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_weights, AI_STATIC,
  430, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 18816, 18816),
  1, &conv2d_57_weights_array, &conv2d_57_weights_array_intq)

/* Tensor #431 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_bias, AI_STATIC,
  431, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_57_bias_array, NULL)

/* Tensor #432 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_weights, AI_STATIC,
  432, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_59_weights_array, &conv2d_59_weights_array_intq)

/* Tensor #433 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_bias, AI_STATIC,
  433, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_59_bias_array, NULL)

/* Tensor #434 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_weights, AI_STATIC,
  434, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_60_weights_array, &conv2d_60_weights_array_intq)

/* Tensor #435 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_bias, AI_STATIC,
  435, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_60_bias_array, NULL)

/* Tensor #436 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_weights, AI_STATIC,
  436, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 18816, 18816),
  1, &conv2d_61_weights_array, &conv2d_61_weights_array_intq)

/* Tensor #437 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_bias, AI_STATIC,
  437, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_61_bias_array, NULL)

/* Tensor #438 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_weights, AI_STATIC,
  438, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_63_weights_array, &conv2d_63_weights_array_intq)

/* Tensor #439 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_bias, AI_STATIC,
  439, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_63_bias_array, NULL)

/* Tensor #440 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  440, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_64_weights_array, &conv2d_64_weights_array_intq)

/* Tensor #441 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  441, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_64_bias_array, NULL)

/* Tensor #442 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  442, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 1, 336, 37632, 37632),
  1, &conv2d_65_weights_array, &conv2d_65_weights_array_intq)

/* Tensor #443 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  443, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_65_bias_array, NULL)

/* Tensor #444 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_weights, AI_STATIC,
  444, 0x1,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 1, 112, 143360, 143360),
  1, &conv2d_66_weights_array, &conv2d_66_weights_array_intq)

/* Tensor #445 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_bias, AI_STATIC,
  445, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_66_bias_array, NULL)

/* Tensor #446 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_weights, AI_STATIC,
  446, 0x1,
  AI_SHAPE_INIT(4, 1280, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1280, 163840, 163840),
  1, &conv2d_67_weights_array, &conv2d_67_weights_array_intq)

/* Tensor #447 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_bias, AI_STATIC,
  447, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_67_bias_array, NULL)

/* Tensor #448 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_68_weights, AI_STATIC,
  448, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_68_weights_array, &conv2d_68_weights_array_intq)

/* Tensor #449 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_68_bias, AI_STATIC,
  449, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_68_bias_array, NULL)

/* Tensor #450 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_69_weights, AI_STATIC,
  450, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_69_weights_array, &conv2d_69_weights_array_intq)

/* Tensor #451 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_69_bias, AI_STATIC,
  451, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_69_bias_array, NULL)

/* Tensor #452 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_70_weights, AI_STATIC,
  452, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_70_weights_array, &conv2d_70_weights_array_intq)

/* Tensor #453 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_70_bias, AI_STATIC,
  453, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_70_bias_array, NULL)

/* Tensor #454 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_71_weights, AI_STATIC,
  454, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_71_weights_array, &conv2d_71_weights_array_intq)

/* Tensor #455 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_71_bias, AI_STATIC,
  455, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_71_bias_array, NULL)

/* Tensor #456 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_weights, AI_STATIC,
  456, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_72_weights_array, &conv2d_72_weights_array_intq)

/* Tensor #457 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_bias, AI_STATIC,
  457, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_72_bias_array, NULL)

/* Tensor #458 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_73_weights, AI_STATIC,
  458, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_73_weights_array, &conv2d_73_weights_array_intq)

/* Tensor #459 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_73_bias, AI_STATIC,
  459, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_73_bias_array, NULL)

/* Tensor #460 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_weights, AI_STATIC,
  460, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_74_weights_array, &conv2d_74_weights_array_intq)

/* Tensor #461 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_bias, AI_STATIC,
  461, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_74_bias_array, NULL)

/* Tensor #462 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_75_weights, AI_STATIC,
  462, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_75_weights_array, &conv2d_75_weights_array_intq)

/* Tensor #463 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_75_bias, AI_STATIC,
  463, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_75_bias_array, NULL)

/* Tensor #464 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_76_weights, AI_STATIC,
  464, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_76_weights_array, &conv2d_76_weights_array_intq)

/* Tensor #465 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_76_bias, AI_STATIC,
  465, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_76_bias_array, NULL)

/* Tensor #466 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_77_weights, AI_STATIC,
  466, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 25), AI_STRIDE_INIT(4, 1, 128, 3200, 3200),
  1, &conv2d_77_weights_array, &conv2d_77_weights_array_intq)

/* Tensor #467 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_77_bias, AI_STATIC,
  467, 0x0,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &conv2d_77_bias_array, NULL)

/* Tensor #468 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_82_weights, AI_STATIC,
  468, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_82_weights_array, &conv2d_82_weights_array_intq)

/* Tensor #469 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_82_bias, AI_STATIC,
  469, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_82_bias_array, NULL)

/* Tensor #470 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_83_weights, AI_STATIC,
  470, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 20), AI_STRIDE_INIT(4, 1, 128, 2560, 2560),
  1, &conv2d_83_weights_array, &conv2d_83_weights_array_intq)

/* Tensor #471 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_83_bias, AI_STATIC,
  471, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &conv2d_83_bias_array, NULL)

/* Tensor #472 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_94_weights, AI_STATIC,
  472, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_94_weights_array, &conv2d_94_weights_array_intq)

/* Tensor #473 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_94_bias, AI_STATIC,
  473, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_94_bias_array, NULL)

/* Tensor #474 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_95_weights, AI_STATIC,
  474, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_95_weights_array, &conv2d_95_weights_array_intq)

/* Tensor #475 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_95_bias, AI_STATIC,
  475, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_95_bias_array, NULL)

/* Tensor #476 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_weights, AI_STATIC,
  476, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_96_weights_array, &conv2d_96_weights_array_intq)

/* Tensor #477 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_bias, AI_STATIC,
  477, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_96_bias_array, NULL)

/* Tensor #478 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_97_weights, AI_STATIC,
  478, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_97_weights_array, &conv2d_97_weights_array_intq)

/* Tensor #479 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_97_bias, AI_STATIC,
  479, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_97_bias_array, NULL)

/* Tensor #480 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_98_weights, AI_STATIC,
  480, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_98_weights_array, &conv2d_98_weights_array_intq)

/* Tensor #481 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_98_bias, AI_STATIC,
  481, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_98_bias_array, NULL)

/* Tensor #482 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_99_weights, AI_STATIC,
  482, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_99_weights_array, &conv2d_99_weights_array_intq)

/* Tensor #483 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_99_bias, AI_STATIC,
  483, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_99_bias_array, NULL)

/* Tensor #484 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_100_weights, AI_STATIC,
  484, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_100_weights_array, &conv2d_100_weights_array_intq)

/* Tensor #485 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_100_bias, AI_STATIC,
  485, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_100_bias_array, NULL)

/* Tensor #486 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_101_weights, AI_STATIC,
  486, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_101_weights_array, &conv2d_101_weights_array_intq)

/* Tensor #487 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_101_bias, AI_STATIC,
  487, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_101_bias_array, NULL)

/* Tensor #488 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_102_weights, AI_STATIC,
  488, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_102_weights_array, &conv2d_102_weights_array_intq)

/* Tensor #489 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_102_bias, AI_STATIC,
  489, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_102_bias_array, NULL)

/* Tensor #490 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_103_weights, AI_STATIC,
  490, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_103_weights_array, &conv2d_103_weights_array_intq)

/* Tensor #491 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_103_bias, AI_STATIC,
  491, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_103_bias_array, NULL)

/* Tensor #492 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_weights, AI_STATIC,
  492, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_104_weights_array, &conv2d_104_weights_array_intq)

/* Tensor #493 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_bias, AI_STATIC,
  493, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_104_bias_array, NULL)

/* Tensor #494 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_105_weights, AI_STATIC,
  494, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 25), AI_STRIDE_INIT(4, 1, 128, 3200, 3200),
  1, &conv2d_105_weights_array, &conv2d_105_weights_array_intq)

/* Tensor #495 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_105_bias, AI_STATIC,
  495, 0x0,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &conv2d_105_bias_array, NULL)

/* Tensor #496 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_110_weights, AI_STATIC,
  496, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_110_weights_array, &conv2d_110_weights_array_intq)

/* Tensor #497 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_110_bias, AI_STATIC,
  497, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_110_bias_array, NULL)

/* Tensor #498 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_weights, AI_STATIC,
  498, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 20), AI_STRIDE_INIT(4, 1, 128, 2560, 2560),
  1, &conv2d_111_weights_array, &conv2d_111_weights_array_intq)

/* Tensor #499 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_bias, AI_STATIC,
  499, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &conv2d_111_bias_array, NULL)

/* Tensor #500 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_122_weights, AI_STATIC,
  500, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_122_weights_array, &conv2d_122_weights_array_intq)

/* Tensor #501 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_122_bias, AI_STATIC,
  501, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_122_bias_array, NULL)

/* Tensor #502 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_123_weights, AI_STATIC,
  502, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 114), AI_STRIDE_INIT(4, 1, 128, 14592, 14592),
  1, &conv2d_123_weights_array, &conv2d_123_weights_array_intq)

/* Tensor #503 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_123_bias, AI_STATIC,
  503, 0x0,
  AI_SHAPE_INIT(4, 1, 114, 1, 1), AI_STRIDE_INIT(4, 4, 4, 456, 456),
  1, &conv2d_123_bias_array, NULL)

/* Tensor #504 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_124_weights, AI_STATIC,
  504, 0x1,
  AI_SHAPE_INIT(4, 114, 3, 3, 1), AI_STRIDE_INIT(4, 1, 114, 114, 342),
  1, &conv2d_124_weights_array, &conv2d_124_weights_array_intq)

/* Tensor #505 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_124_bias, AI_STATIC,
  505, 0x0,
  AI_SHAPE_INIT(4, 1, 114, 1, 1), AI_STRIDE_INIT(4, 4, 4, 456, 456),
  1, &conv2d_124_bias_array, NULL)

/* Tensor #506 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_125_weights, AI_STATIC,
  506, 0x1,
  AI_SHAPE_INIT(4, 114, 1, 1, 104), AI_STRIDE_INIT(4, 1, 114, 11856, 11856),
  1, &conv2d_125_weights_array, &conv2d_125_weights_array_intq)

/* Tensor #507 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_125_bias, AI_STATIC,
  507, 0x0,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_125_bias_array, NULL)

/* Tensor #508 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_126_weights, AI_STATIC,
  508, 0x1,
  AI_SHAPE_INIT(4, 104, 3, 3, 1), AI_STRIDE_INIT(4, 1, 104, 104, 312),
  1, &conv2d_126_weights_array, &conv2d_126_weights_array_intq)

/* Tensor #509 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_126_bias, AI_STATIC,
  509, 0x0,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_126_bias_array, NULL)

/* Tensor #510 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_weights, AI_STATIC,
  510, 0x1,
  AI_SHAPE_INIT(4, 104, 1, 1, 128), AI_STRIDE_INIT(4, 1, 104, 13312, 13312),
  1, &conv2d_127_weights_array, &conv2d_127_weights_array_intq)

/* Tensor #511 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_bias, AI_STATIC,
  511, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_127_bias_array, NULL)

/* Tensor #512 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_128_weights, AI_STATIC,
  512, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_128_weights_array, &conv2d_128_weights_array_intq)

/* Tensor #513 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_128_bias, AI_STATIC,
  513, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_128_bias_array, NULL)

/* Tensor #514 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_weights, AI_STATIC,
  514, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_129_weights_array, &conv2d_129_weights_array_intq)

/* Tensor #515 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_bias, AI_STATIC,
  515, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_129_bias_array, NULL)

/* Tensor #516 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_130_weights, AI_STATIC,
  516, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_130_weights_array, &conv2d_130_weights_array_intq)

/* Tensor #517 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_130_bias, AI_STATIC,
  517, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_130_bias_array, NULL)

/* Tensor #518 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_131_weights, AI_STATIC,
  518, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_131_weights_array, &conv2d_131_weights_array_intq)

/* Tensor #519 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_131_bias, AI_STATIC,
  519, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_131_bias_array, NULL)

/* Tensor #520 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_132_weights, AI_STATIC,
  520, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_132_weights_array, &conv2d_132_weights_array_intq)

/* Tensor #521 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_132_bias, AI_STATIC,
  521, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_132_bias_array, NULL)

/* Tensor #522 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_133_weights, AI_STATIC,
  522, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 25), AI_STRIDE_INIT(4, 1, 128, 3200, 3200),
  1, &conv2d_133_weights_array, &conv2d_133_weights_array_intq)

/* Tensor #523 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_133_bias, AI_STATIC,
  523, 0x0,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &conv2d_133_bias_array, NULL)

/* Tensor #524 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_138_weights, AI_STATIC,
  524, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_138_weights_array, &conv2d_138_weights_array_intq)

/* Tensor #525 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_138_bias, AI_STATIC,
  525, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_138_bias_array, NULL)

/* Tensor #526 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_139_weights, AI_STATIC,
  526, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 20), AI_STRIDE_INIT(4, 1, 128, 2560, 2560),
  1, &conv2d_139_weights_array, &conv2d_139_weights_array_intq)

/* Tensor #527 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_139_bias, AI_STATIC,
  527, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &conv2d_139_bias_array, NULL)

/* Tensor #528 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_153_weights, AI_STATIC,
  528, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_153_weights_array, &conv2d_153_weights_array_intq)

/* Tensor #529 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_153_bias, AI_STATIC,
  529, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_153_bias_array, NULL)

/* Tensor #530 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_154_weights, AI_STATIC,
  530, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_154_weights_array, &conv2d_154_weights_array_intq)

/* Tensor #531 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_154_bias, AI_STATIC,
  531, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_154_bias_array, NULL)

/* Tensor #532 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_155_weights, AI_STATIC,
  532, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_155_weights_array, &conv2d_155_weights_array_intq)

/* Tensor #533 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_155_bias, AI_STATIC,
  533, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_155_bias_array, NULL)

/* Tensor #534 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_156_weights, AI_STATIC,
  534, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_156_weights_array, &conv2d_156_weights_array_intq)

/* Tensor #535 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_156_bias, AI_STATIC,
  535, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_156_bias_array, NULL)

/* Tensor #536 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_157_weights, AI_STATIC,
  536, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_157_weights_array, &conv2d_157_weights_array_intq)

/* Tensor #537 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_157_bias, AI_STATIC,
  537, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_157_bias_array, NULL)

/* Tensor #538 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_158_weights, AI_STATIC,
  538, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_158_weights_array, &conv2d_158_weights_array_intq)

/* Tensor #539 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_158_bias, AI_STATIC,
  539, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_158_bias_array, NULL)

/* Tensor #540 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_weights, AI_STATIC,
  540, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_159_weights_array, &conv2d_159_weights_array_intq)

/* Tensor #541 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_bias, AI_STATIC,
  541, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_159_bias_array, NULL)

/* Tensor #542 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_160_weights, AI_STATIC,
  542, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_160_weights_array, &conv2d_160_weights_array_intq)

/* Tensor #543 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_160_bias, AI_STATIC,
  543, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_160_bias_array, NULL)

/* Tensor #544 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_161_weights, AI_STATIC,
  544, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_161_weights_array, &conv2d_161_weights_array_intq)

/* Tensor #545 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_161_bias, AI_STATIC,
  545, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_161_bias_array, NULL)

/* Tensor #546 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_162_weights, AI_STATIC,
  546, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_162_weights_array, &conv2d_162_weights_array_intq)

/* Tensor #547 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_162_bias, AI_STATIC,
  547, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_162_bias_array, NULL)

/* Tensor #548 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_163_weights, AI_STATIC,
  548, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_163_weights_array, &conv2d_163_weights_array_intq)

/* Tensor #549 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_163_bias, AI_STATIC,
  549, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_163_bias_array, NULL)

/* Tensor #550 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_164_weights, AI_STATIC,
  550, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 25), AI_STRIDE_INIT(4, 1, 128, 3200, 3200),
  1, &conv2d_164_weights_array, &conv2d_164_weights_array_intq)

/* Tensor #551 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_164_bias, AI_STATIC,
  551, 0x0,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &conv2d_164_bias_array, NULL)

/* Tensor #552 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_169_weights, AI_STATIC,
  552, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_169_weights_array, &conv2d_169_weights_array_intq)

/* Tensor #553 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_169_bias, AI_STATIC,
  553, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_169_bias_array, NULL)

/* Tensor #554 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_170_weights, AI_STATIC,
  554, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 20), AI_STRIDE_INIT(4, 1, 128, 2560, 2560),
  1, &conv2d_170_weights_array, &conv2d_170_weights_array_intq)

/* Tensor #555 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_170_bias, AI_STATIC,
  555, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &conv2d_170_bias_array, NULL)

/* Tensor #556 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_184_weights, AI_STATIC,
  556, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_184_weights_array, &conv2d_184_weights_array_intq)

/* Tensor #557 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_184_bias, AI_STATIC,
  557, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_184_bias_array, NULL)

/* Tensor #558 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_weights, AI_STATIC,
  558, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_185_weights_array, &conv2d_185_weights_array_intq)

/* Tensor #559 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_bias, AI_STATIC,
  559, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_185_bias_array, NULL)

/* Tensor #560 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_186_weights, AI_STATIC,
  560, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_186_weights_array, &conv2d_186_weights_array_intq)

/* Tensor #561 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_186_bias, AI_STATIC,
  561, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_186_bias_array, NULL)

/* Tensor #562 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_187_weights, AI_STATIC,
  562, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_187_weights_array, &conv2d_187_weights_array_intq)

/* Tensor #563 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_187_bias, AI_STATIC,
  563, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_187_bias_array, NULL)

/* Tensor #564 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_188_weights, AI_STATIC,
  564, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_188_weights_array, &conv2d_188_weights_array_intq)

/* Tensor #565 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_188_bias, AI_STATIC,
  565, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_188_bias_array, NULL)

/* Tensor #566 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_189_weights, AI_STATIC,
  566, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_189_weights_array, &conv2d_189_weights_array_intq)

/* Tensor #567 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_189_bias, AI_STATIC,
  567, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_189_bias_array, NULL)

/* Tensor #568 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_190_weights, AI_STATIC,
  568, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_190_weights_array, &conv2d_190_weights_array_intq)

/* Tensor #569 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_190_bias, AI_STATIC,
  569, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_190_bias_array, NULL)

/* Tensor #570 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_weights, AI_STATIC,
  570, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_191_weights_array, &conv2d_191_weights_array_intq)

/* Tensor #571 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_bias, AI_STATIC,
  571, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_191_bias_array, NULL)

/* Tensor #572 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_192_weights, AI_STATIC,
  572, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_192_weights_array, &conv2d_192_weights_array_intq)

/* Tensor #573 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_192_bias, AI_STATIC,
  573, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_192_bias_array, NULL)

/* Tensor #574 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_193_weights, AI_STATIC,
  574, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_193_weights_array, &conv2d_193_weights_array_intq)

/* Tensor #575 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_193_bias, AI_STATIC,
  575, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_193_bias_array, NULL)

/* Tensor #576 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_194_weights, AI_STATIC,
  576, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &conv2d_194_weights_array, &conv2d_194_weights_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_210_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_209_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_210_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_210_layer, 210,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_210_chain,
  NULL, &conversion_210_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_209_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 5, &conv2d_204_output0, &conv2d_170_output0, &conv2d_83_output0, &conv2d_111_output0, &conv2d_139_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_209_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_209_layer, 209,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_209_chain,
  NULL, &conversion_210_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_204_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_204_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_204_weights, &conv2d_204_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_204_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_204_layer, 204,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_204_chain,
  NULL, &concat_209_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_203_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_203_weights, &conv2d_203_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_203_layer, 203,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_203_chain,
  NULL, &conv2d_204_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_203_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_203_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_203_pad_before_value_data, conv2d_203_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_203_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_193_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_203_pad_before_layer, 203,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_203_pad_before_chain,
  NULL, &conv2d_203_layer, AI_STATIC, 
  .value = &conv2d_203_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_202_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_201_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_202_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_202_layer, 202,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_202_chain,
  NULL, &conv2d_203_pad_before_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i32 nl_201_nl_params_data[] = { 1127941888, 24, -124 };
AI_ARRAY_OBJ_DECLARE(
    nl_201_nl_params, AI_ARRAY_FORMAT_S32,
    nl_201_nl_params_data, nl_201_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_201_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_200_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_201_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_201_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_201_layer, 201,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm_integer,
  &nl_201_chain,
  NULL, &conversion_202_layer, AI_STATIC, 
  .nl_params = &nl_201_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_200_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 5, &conv2d_195_output0, &conv2d_164_output0, &conv2d_77_output0, &conv2d_105_output0, &conv2d_133_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_200_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_200_layer, 200,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_200_chain,
  NULL, &nl_201_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_195_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_194_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_195_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_195_weights, &conv2d_195_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_195_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_195_layer, 195,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_195_chain,
  NULL, &concat_200_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_194_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_194_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_194_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_194_weights, &conv2d_194_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_194_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_194_layer, 194,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_194_chain,
  NULL, &conv2d_195_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_194_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_194_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_194_pad_before_value_data, conv2d_194_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_194_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_193_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_194_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_194_pad_before_layer, 194,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_194_pad_before_chain,
  NULL, &conv2d_194_layer, AI_STATIC, 
  .value = &conv2d_194_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_193_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_192_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_193_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_193_weights, &conv2d_193_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_193_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_193_layer, 193,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_193_chain,
  NULL, &conv2d_194_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_192_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_192_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_192_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_192_weights, &conv2d_192_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_192_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_192_layer, 192,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_192_chain,
  NULL, &conv2d_193_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_192_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_192_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_192_pad_before_value_data, conv2d_192_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_192_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_192_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_192_pad_before_layer, 192,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_192_pad_before_chain,
  NULL, &conv2d_192_layer, AI_STATIC, 
  .value = &conv2d_192_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_191_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_190_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_191_weights, &conv2d_191_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_191_layer, 191,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_191_chain,
  NULL, &conv2d_192_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_190_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_190_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_190_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_190_weights, &conv2d_190_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_190_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_190_layer, 190,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_190_chain,
  NULL, &conv2d_191_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_190_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_190_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_190_pad_before_value_data, conv2d_190_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_190_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_189_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_190_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_190_pad_before_layer, 190,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_190_pad_before_chain,
  NULL, &conv2d_190_layer, AI_STATIC, 
  .value = &conv2d_190_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_189_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_188_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_189_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_189_weights, &conv2d_189_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_189_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_189_layer, 189,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_189_chain,
  NULL, &conv2d_190_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_188_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_188_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_188_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_188_weights, &conv2d_188_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_188_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_188_layer, 188,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_188_chain,
  NULL, &conv2d_189_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_188_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_188_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_188_pad_before_value_data, conv2d_188_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_188_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_187_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_188_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_188_pad_before_layer, 188,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_188_pad_before_chain,
  NULL, &conv2d_188_layer, AI_STATIC, 
  .value = &conv2d_188_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_187_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_186_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_187_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_187_weights, &conv2d_187_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_187_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_187_layer, 187,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_187_chain,
  NULL, &conv2d_188_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_186_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_186_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_186_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_186_weights, &conv2d_186_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_186_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_186_layer, 186,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_186_chain,
  NULL, &conv2d_187_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_186_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_186_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_186_pad_before_value_data, conv2d_186_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_186_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_185_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_186_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_186_pad_before_layer, 186,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_186_pad_before_chain,
  NULL, &conv2d_186_layer, AI_STATIC, 
  .value = &conv2d_186_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_185_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_184_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_185_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_185_weights, &conv2d_185_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_185_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_185_layer, 185,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_185_chain,
  NULL, &conv2d_186_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_184_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_184_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_184_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_184_weights, &conv2d_184_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_184_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_184_layer, 184,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_184_chain,
  NULL, &conv2d_185_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_184_pad_before_value_data[] = { -17 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_184_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_184_pad_before_value_data, conv2d_184_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_184_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_183_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_184_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_184_pad_before_layer, 184,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_184_pad_before_chain,
  NULL, &conv2d_184_layer, AI_STATIC, 
  .value = &conv2d_184_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_183_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_182_output, &upsample_181_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_183_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_183_layer, 183,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_183_chain,
  NULL, &conv2d_184_pad_before_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)


AI_STATIC_CONST ai_float upsample_181_scales_data[] = { 2.0, 2.0, 1.0, 1.0 };
AI_ARRAY_OBJ_DECLARE(
    upsample_181_scales, AI_ARRAY_FORMAT_FLOAT,
    upsample_181_scales_data, upsample_181_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  upsample_181_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_154_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_181_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  upsample_181_layer, 181,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample_bilinear_is8os8,
  &upsample_181_chain,
  NULL, &eltwise_183_layer, AI_STATIC, 
  .scales = &upsample_181_scales, 
  .center = true, 
  .mode = AI_UPSAMPLE_BILINEAR, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_170_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_169_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_170_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_170_weights, &conv2d_170_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_170_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_170_layer, 170,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_170_chain,
  NULL, &upsample_181_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_169_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_169_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_169_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_169_weights, &conv2d_169_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_169_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_169_layer, 169,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_169_chain,
  NULL, &conv2d_170_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_169_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_169_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_169_pad_before_value_data, conv2d_169_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_169_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_162_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_169_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_169_pad_before_layer, 169,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_169_pad_before_chain,
  NULL, &conv2d_169_layer, AI_STATIC, 
  .value = &conv2d_169_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_164_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_163_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_164_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_164_weights, &conv2d_164_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_164_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_164_layer, 164,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_164_chain,
  NULL, &conv2d_169_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_163_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_163_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_163_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_163_weights, &conv2d_163_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_163_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_163_layer, 163,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_163_chain,
  NULL, &conv2d_164_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_163_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_163_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_163_pad_before_value_data, conv2d_163_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_163_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_162_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_163_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_163_pad_before_layer, 163,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_163_pad_before_chain,
  NULL, &conv2d_163_layer, AI_STATIC, 
  .value = &conv2d_163_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_162_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_161_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_162_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_162_weights, &conv2d_162_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_162_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_162_layer, 162,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_162_chain,
  NULL, &conv2d_163_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_161_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_161_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_161_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_161_weights, &conv2d_161_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_161_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_161_layer, 161,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_161_chain,
  NULL, &conv2d_162_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_161_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_161_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_161_pad_before_value_data, conv2d_161_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_161_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_160_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_161_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_161_pad_before_layer, 161,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_161_pad_before_chain,
  NULL, &conv2d_161_layer, AI_STATIC, 
  .value = &conv2d_161_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_160_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_160_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_160_weights, &conv2d_160_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_160_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_160_layer, 160,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_160_chain,
  NULL, &conv2d_161_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_159_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_159_weights, &conv2d_159_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_159_layer, 159,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_159_chain,
  NULL, &conv2d_160_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_159_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_159_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_159_pad_before_value_data, conv2d_159_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_159_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_158_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_159_pad_before_layer, 159,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_159_pad_before_chain,
  NULL, &conv2d_159_layer, AI_STATIC, 
  .value = &conv2d_159_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_158_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_157_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_158_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_158_weights, &conv2d_158_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_158_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_158_layer, 158,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_158_chain,
  NULL, &conv2d_159_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_157_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_157_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_157_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_157_weights, &conv2d_157_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_157_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_157_layer, 157,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_157_chain,
  NULL, &conv2d_158_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_157_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_157_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_157_pad_before_value_data, conv2d_157_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_157_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_156_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_157_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_157_pad_before_layer, 157,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_157_pad_before_chain,
  NULL, &conv2d_157_layer, AI_STATIC, 
  .value = &conv2d_157_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_156_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_155_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_156_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_156_weights, &conv2d_156_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_156_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_156_layer, 156,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_156_chain,
  NULL, &conv2d_157_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_155_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_155_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_155_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_155_weights, &conv2d_155_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_155_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_155_layer, 155,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_155_chain,
  NULL, &conv2d_156_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_155_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_155_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_155_pad_before_value_data, conv2d_155_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_155_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_154_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_155_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_155_pad_before_layer, 155,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_155_pad_before_chain,
  NULL, &conv2d_155_layer, AI_STATIC, 
  .value = &conv2d_155_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_154_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_153_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_154_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_154_weights, &conv2d_154_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_154_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_154_layer, 154,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_154_chain,
  NULL, &conv2d_155_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_153_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_153_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_153_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_153_weights, &conv2d_153_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_153_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_153_layer, 153,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_153_chain,
  NULL, &conv2d_154_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_153_pad_before_value_data[] = { -9 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_153_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_153_pad_before_value_data, conv2d_153_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_153_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_152_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_153_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_153_pad_before_layer, 153,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_153_pad_before_chain,
  NULL, &conv2d_153_layer, AI_STATIC, 
  .value = &conv2d_153_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_152_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_151_output, &upsample_150_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_152_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_152_layer, 152,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_152_chain,
  NULL, &conv2d_153_pad_before_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)


AI_STATIC_CONST ai_float upsample_150_scales_data[] = { 2.0, 2.0, 1.0, 1.0 };
AI_ARRAY_OBJ_DECLARE(
    upsample_150_scales, AI_ARRAY_FORMAT_FLOAT,
    upsample_150_scales_data, upsample_150_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  upsample_150_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_150_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  upsample_150_layer, 150,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample_bilinear_is8os8,
  &upsample_150_chain,
  NULL, &eltwise_152_layer, AI_STATIC, 
  .scales = &upsample_150_scales, 
  .center = true, 
  .mode = AI_UPSAMPLE_BILINEAR, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_139_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_138_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_139_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_139_weights, &conv2d_139_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_139_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_139_layer, 139,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_139_chain,
  NULL, &upsample_150_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_138_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_138_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_138_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_138_weights, &conv2d_138_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_138_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_138_layer, 138,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_138_chain,
  NULL, &conv2d_139_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_138_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_138_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_138_pad_before_value_data, conv2d_138_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_138_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_131_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_138_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_138_pad_before_layer, 138,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_138_pad_before_chain,
  NULL, &conv2d_138_layer, AI_STATIC, 
  .value = &conv2d_138_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_133_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_132_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_133_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_133_weights, &conv2d_133_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_133_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_133_layer, 133,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_133_chain,
  NULL, &conv2d_138_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_132_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_132_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_132_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_132_weights, &conv2d_132_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_132_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_132_layer, 132,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_132_chain,
  NULL, &conv2d_133_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_132_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_132_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_132_pad_before_value_data, conv2d_132_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_132_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_131_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_132_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_132_pad_before_layer, 132,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_132_pad_before_chain,
  NULL, &conv2d_132_layer, AI_STATIC, 
  .value = &conv2d_132_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_131_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_130_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_131_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_131_weights, &conv2d_131_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_131_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_131_layer, 131,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_131_chain,
  NULL, &conv2d_132_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_130_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_130_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_130_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_130_weights, &conv2d_130_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_130_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_130_layer, 130,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_130_chain,
  NULL, &conv2d_131_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_130_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_130_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_130_pad_before_value_data, conv2d_130_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_130_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_129_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_130_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_130_pad_before_layer, 130,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_130_pad_before_chain,
  NULL, &conv2d_130_layer, AI_STATIC, 
  .value = &conv2d_130_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_129_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_128_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_129_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_129_weights, &conv2d_129_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_129_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_129_layer, 129,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_129_chain,
  NULL, &conv2d_130_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_128_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_128_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_128_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_128_weights, &conv2d_128_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_128_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_128_layer, 128,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_128_chain,
  NULL, &conv2d_129_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_128_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_128_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_128_pad_before_value_data, conv2d_128_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_128_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_128_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_128_pad_before_layer, 128,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_128_pad_before_chain,
  NULL, &conv2d_128_layer, AI_STATIC, 
  .value = &conv2d_128_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_127_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_126_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_127_weights, &conv2d_127_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_127_layer, 127,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_127_chain,
  NULL, &conv2d_128_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_126_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_126_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_126_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_126_weights, &conv2d_126_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_126_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_126_layer, 126,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_126_chain,
  NULL, &conv2d_127_layer, AI_STATIC, 
  .groups = 104, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_126_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_126_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_126_pad_before_value_data, conv2d_126_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_126_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_125_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_126_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_126_pad_before_layer, 126,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_126_pad_before_chain,
  NULL, &conv2d_126_layer, AI_STATIC, 
  .value = &conv2d_126_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_125_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_124_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_125_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_125_weights, &conv2d_125_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_125_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_125_layer, 125,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_125_chain,
  NULL, &conv2d_126_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_124_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_124_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_124_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_124_weights, &conv2d_124_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_124_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_124_layer, 124,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_124_chain,
  NULL, &conv2d_125_layer, AI_STATIC, 
  .groups = 114, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_124_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_124_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_124_pad_before_value_data, conv2d_124_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_124_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_123_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_124_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_124_pad_before_layer, 124,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_124_pad_before_chain,
  NULL, &conv2d_124_layer, AI_STATIC, 
  .value = &conv2d_124_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_123_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_122_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_123_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_123_weights, &conv2d_123_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_123_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_123_layer, 123,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_123_chain,
  NULL, &conv2d_124_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_122_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_122_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_122_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_122_weights, &conv2d_122_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_122_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_122_layer, 122,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_122_chain,
  NULL, &conv2d_123_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_122_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_122_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_122_pad_before_value_data, conv2d_122_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_122_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_95_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_122_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_122_pad_before_layer, 122,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_122_pad_before_chain,
  NULL, &conv2d_122_layer, AI_STATIC, 
  .value = &conv2d_122_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_111_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_110_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_111_weights, &conv2d_111_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_111_layer, 111,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_111_chain,
  NULL, &conv2d_122_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_110_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_110_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_110_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_110_weights, &conv2d_110_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_110_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_110_layer, 110,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_110_chain,
  NULL, &conv2d_111_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_110_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_110_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_110_pad_before_value_data, conv2d_110_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_110_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_103_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_110_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_110_pad_before_layer, 110,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_110_pad_before_chain,
  NULL, &conv2d_110_layer, AI_STATIC, 
  .value = &conv2d_110_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_105_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_105_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_105_weights, &conv2d_105_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_105_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_105_layer, 105,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_105_chain,
  NULL, &conv2d_110_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_104_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_104_weights, &conv2d_104_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_104_layer, 104,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_104_chain,
  NULL, &conv2d_105_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_104_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_104_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_104_pad_before_value_data, conv2d_104_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_104_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_103_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_104_pad_before_layer, 104,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_104_pad_before_chain,
  NULL, &conv2d_104_layer, AI_STATIC, 
  .value = &conv2d_104_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_103_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_103_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_103_weights, &conv2d_103_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_103_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_103_layer, 103,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_103_chain,
  NULL, &conv2d_104_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_102_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_102_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_102_weights, &conv2d_102_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_102_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_102_layer, 102,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_102_chain,
  NULL, &conv2d_103_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_102_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_102_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_102_pad_before_value_data, conv2d_102_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_102_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_101_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_102_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_102_pad_before_layer, 102,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_102_pad_before_chain,
  NULL, &conv2d_102_layer, AI_STATIC, 
  .value = &conv2d_102_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_101_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_100_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_101_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_101_weights, &conv2d_101_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_101_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_101_layer, 101,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_101_chain,
  NULL, &conv2d_102_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_100_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_100_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_100_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_100_weights, &conv2d_100_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_100_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_100_layer, 100,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_100_chain,
  NULL, &conv2d_101_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_100_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_100_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_100_pad_before_value_data, conv2d_100_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_100_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_99_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_100_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_100_pad_before_layer, 100,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_100_pad_before_chain,
  NULL, &conv2d_100_layer, AI_STATIC, 
  .value = &conv2d_100_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_99_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_98_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_99_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_99_weights, &conv2d_99_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_99_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_99_layer, 99,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_99_chain,
  NULL, &conv2d_100_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_98_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_98_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_98_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_98_weights, &conv2d_98_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_98_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_98_layer, 98,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_98_chain,
  NULL, &conv2d_99_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_98_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_98_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_98_pad_before_value_data, conv2d_98_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_98_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_97_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_98_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_98_pad_before_layer, 98,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_98_pad_before_chain,
  NULL, &conv2d_98_layer, AI_STATIC, 
  .value = &conv2d_98_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_97_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_97_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_97_weights, &conv2d_97_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_97_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_97_layer, 97,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_97_chain,
  NULL, &conv2d_98_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_96_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_96_weights, &conv2d_96_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_96_layer, 96,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_96_chain,
  NULL, &conv2d_97_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_96_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_96_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_96_pad_before_value_data, conv2d_96_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_96_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_95_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_96_pad_before_layer, 96,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_96_pad_before_chain,
  NULL, &conv2d_96_layer, AI_STATIC, 
  .value = &conv2d_96_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_95_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_94_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_95_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_95_weights, &conv2d_95_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_95_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_95_layer, 95,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_95_chain,
  NULL, &conv2d_96_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_94_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_94_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_94_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_94_weights, &conv2d_94_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_94_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_94_layer, 94,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_94_chain,
  NULL, &conv2d_95_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_94_pad_before_value_data[] = { -14 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_94_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_94_pad_before_value_data, conv2d_94_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_94_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_94_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_94_pad_before_layer, 94,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_94_pad_before_chain,
  NULL, &conv2d_94_layer, AI_STATIC, 
  .value = &conv2d_94_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_83_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_82_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_83_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_83_weights, &conv2d_83_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_83_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_83_layer, 83,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_83_chain,
  NULL, &conv2d_94_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_82_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_82_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_82_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_82_weights, &conv2d_82_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_82_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_82_layer, 82,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_82_chain,
  NULL, &conv2d_83_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_82_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_82_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_82_pad_before_value_data, conv2d_82_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_82_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_82_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_82_pad_before_layer, 82,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_82_pad_before_chain,
  NULL, &conv2d_82_layer, AI_STATIC, 
  .value = &conv2d_82_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_77_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_76_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_77_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_77_weights, &conv2d_77_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_77_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_77_layer, 77,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_77_chain,
  NULL, &conv2d_82_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_76_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_76_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_76_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_76_weights, &conv2d_76_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_76_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_76_layer, 76,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_76_chain,
  NULL, &conv2d_77_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_76_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_76_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_76_pad_before_value_data, conv2d_76_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_76_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_76_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_76_pad_before_layer, 76,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_76_pad_before_chain,
  NULL, &conv2d_76_layer, AI_STATIC, 
  .value = &conv2d_76_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_75_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_75_weights, &conv2d_75_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_75_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_75_layer, 75,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_75_chain,
  NULL, &conv2d_76_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_74_weights, &conv2d_74_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_74_layer, 74,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_74_chain,
  NULL, &conv2d_75_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_74_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_74_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_74_pad_before_value_data, conv2d_74_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_74_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_73_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_74_pad_before_layer, 74,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_74_pad_before_chain,
  NULL, &conv2d_74_layer, AI_STATIC, 
  .value = &conv2d_74_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_73_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_73_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_73_weights, &conv2d_73_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_73_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_73_layer, 73,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_73_chain,
  NULL, &conv2d_74_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_72_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_72_weights, &conv2d_72_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_72_layer, 72,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_72_chain,
  NULL, &conv2d_73_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_72_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_72_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_72_pad_before_value_data, conv2d_72_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_72_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_72_pad_before_layer, 72,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_72_pad_before_chain,
  NULL, &conv2d_72_layer, AI_STATIC, 
  .value = &conv2d_72_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_71_weights, &conv2d_71_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_71_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_71_layer, 71,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_71_chain,
  NULL, &conv2d_72_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_70_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_70_weights, &conv2d_70_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_70_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_70_layer, 70,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_70_chain,
  NULL, &conv2d_71_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_70_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_70_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_70_pad_before_value_data, conv2d_70_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_70_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_70_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_70_pad_before_layer, 70,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_70_pad_before_chain,
  NULL, &conv2d_70_layer, AI_STATIC, 
  .value = &conv2d_70_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_69_weights, &conv2d_69_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_69_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_69_layer, 69,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_69_chain,
  NULL, &conv2d_70_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_68_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_68_weights, &conv2d_68_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_68_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_68_layer, 68,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_68_chain,
  NULL, &conv2d_69_layer, AI_STATIC, 
  .groups = 128, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_68_pad_before_value_data[] = { -14 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_68_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_68_pad_before_value_data, conv2d_68_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_68_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_68_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_68_pad_before_layer, 68,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_68_pad_before_chain,
  NULL, &conv2d_68_layer, AI_STATIC, 
  .value = &conv2d_68_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_67_weights, &conv2d_67_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_67_layer, 67,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_67_chain,
  NULL, &conv2d_68_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_66_weights, &conv2d_66_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_66_layer, 66,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_66_chain,
  NULL, &conv2d_67_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_65_weights, &conv2d_65_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_65_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_65_chain,
  NULL, &conv2d_66_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_64_weights, &conv2d_64_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_64_chain,
  NULL, &conv2d_65_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_64_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_64_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_64_pad_before_value_data, conv2d_64_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_pad_before_layer, 64,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_64_pad_before_chain,
  NULL, &conv2d_64_layer, AI_STATIC, 
  .value = &conv2d_64_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_63_weights, &conv2d_63_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_63_layer, 63,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_63_chain,
  NULL, &conv2d_64_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_58_output, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_62_layer, 62,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_62_chain,
  NULL, &conv2d_63_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_61_weights, &conv2d_61_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_61_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_61_chain,
  NULL, &eltwise_62_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_60_weights, &conv2d_60_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_layer, 60,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_60_chain,
  NULL, &conv2d_61_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_60_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_60_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_60_pad_before_value_data, conv2d_60_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_pad_before_layer, 60,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_60_pad_before_chain,
  NULL, &conv2d_60_layer, AI_STATIC, 
  .value = &conv2d_60_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_59_weights, &conv2d_59_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_59_layer, 59,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_59_chain,
  NULL, &conv2d_60_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_54_output, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_58_layer, 58,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_58_chain,
  NULL, &conv2d_59_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_57_weights, &conv2d_57_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_57_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_57_chain,
  NULL, &eltwise_58_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_56_chain,
  NULL, &conv2d_57_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_56_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_56_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_56_pad_before_value_data, conv2d_56_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_pad_before_layer, 56,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_56_pad_before_chain,
  NULL, &conv2d_56_layer, AI_STATIC, 
  .value = &conv2d_56_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_55_weights, &conv2d_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_55_layer, 55,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_55_chain,
  NULL, &conv2d_56_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_54_weights, &conv2d_54_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_54_layer, 54,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_54_chain,
  NULL, &conv2d_55_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_53_weights, &conv2d_53_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_layer, 53,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_53_chain,
  NULL, &conv2d_54_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_53_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_53_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_53_pad_before_value_data, conv2d_53_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_pad_before_layer, 52,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_53_pad_before_chain,
  NULL, &conv2d_53_layer, AI_STATIC, 
  .value = &conv2d_53_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_51_weights, &conv2d_51_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_51_layer, 51,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_51_chain,
  NULL, &conv2d_53_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_151_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_151_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_151_weights, &conv2d_151_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_151_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_151_layer, 151,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_151_chain,
  NULL, &conv2d_51_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_46_output, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_50_layer, 50,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_50_chain,
  NULL, &conv2d_151_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_49_chain,
  NULL, &eltwise_50_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_48_chain,
  NULL, &conv2d_49_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_48_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_48_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_48_pad_before_value_data, conv2d_48_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_pad_before_layer, 48,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_48_pad_before_chain,
  NULL, &conv2d_48_layer, AI_STATIC, 
  .value = &conv2d_48_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_47_weights, &conv2d_47_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_47_layer, 47,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_47_chain,
  NULL, &conv2d_48_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_42_output, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_46_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_46_layer, 46,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_46_chain,
  NULL, &conv2d_47_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_45_chain,
  NULL, &eltwise_46_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_44_chain,
  NULL, &conv2d_45_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_44_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_44_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_44_pad_before_value_data, conv2d_44_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_pad_before_layer, 44,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_44_pad_before_chain,
  NULL, &conv2d_44_layer, AI_STATIC, 
  .value = &conv2d_44_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_43_chain,
  NULL, &conv2d_44_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_42_chain,
  NULL, &conv2d_43_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_41_chain,
  NULL, &conv2d_42_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_41_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_41_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_41_pad_before_value_data, conv2d_41_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_pad_before_layer, 41,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_41_pad_before_chain,
  NULL, &conv2d_41_layer, AI_STATIC, 
  .value = &conv2d_41_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_40_weights, &conv2d_40_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_40_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_40_chain,
  NULL, &conv2d_41_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_35_output, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_39_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_39_layer, 39,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_39_chain,
  NULL, &conv2d_40_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_38_chain,
  NULL, &eltwise_39_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_37_chain,
  NULL, &conv2d_38_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_37_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_37_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_37_pad_before_value_data, conv2d_37_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_pad_before_layer, 37,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_37_pad_before_chain,
  NULL, &conv2d_37_layer, AI_STATIC, 
  .value = &conv2d_37_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_36_chain,
  NULL, &conv2d_37_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_31_output, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_35_layer, 35,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_35_chain,
  NULL, &conv2d_36_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_34_chain,
  NULL, &eltwise_35_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_33_chain,
  NULL, &conv2d_34_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_33_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_33_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_33_pad_before_value_data, conv2d_33_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_pad_before_layer, 33,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_33_pad_before_chain,
  NULL, &conv2d_33_layer, AI_STATIC, 
  .value = &conv2d_33_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 32,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_32_chain,
  NULL, &conv2d_33_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_output, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_31_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_31_layer, 31,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_31_chain,
  NULL, &conv2d_32_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_30_chain,
  NULL, &eltwise_31_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_29_chain,
  NULL, &conv2d_30_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_29_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_29_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_29_pad_before_value_data, conv2d_29_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_pad_before_layer, 29,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_29_pad_before_chain,
  NULL, &conv2d_29_layer, AI_STATIC, 
  .value = &conv2d_29_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_28_chain,
  NULL, &conv2d_29_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_27_chain,
  NULL, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 26,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_26_chain,
  NULL, &conv2d_27_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_26_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_26_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_26_pad_before_value_data, conv2d_26_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_pad_before_layer, 25,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_26_pad_before_chain,
  NULL, &conv2d_26_layer, AI_STATIC, 
  .value = &conv2d_26_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_24_chain,
  NULL, &conv2d_26_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_182_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_182_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_182_weights, &conv2d_182_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_182_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_182_layer, 182,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_182_chain,
  NULL, &conv2d_24_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_19_output, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_23_layer, 23,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_23_chain,
  NULL, &conv2d_182_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_22_chain,
  NULL, &eltwise_23_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_21_chain,
  NULL, &conv2d_22_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_21_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_21_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_21_pad_before_value_data, conv2d_21_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_pad_before_layer, 21,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_21_pad_before_chain,
  NULL, &conv2d_21_layer, AI_STATIC, 
  .value = &conv2d_21_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_20_chain,
  NULL, &conv2d_21_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_output, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_19_layer, 19,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_19_chain,
  NULL, &conv2d_20_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_18_chain,
  NULL, &eltwise_19_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_17_chain,
  NULL, &conv2d_18_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_17_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_17_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_17_pad_before_value_data, conv2d_17_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_pad_before_layer, 17,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_17_pad_before_chain,
  NULL, &conv2d_17_layer, AI_STATIC, 
  .value = &conv2d_17_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_16_chain,
  NULL, &conv2d_17_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_15_chain,
  NULL, &conv2d_16_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_14_chain,
  NULL, &conv2d_15_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_14_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_14_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_14_pad_before_value_data, conv2d_14_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_pad_before_layer, 13,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_14_pad_before_chain,
  NULL, &conv2d_14_layer, AI_STATIC, 
  .value = &conv2d_14_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_12_chain,
  NULL, &conv2d_14_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_output, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_11_chain,
  NULL, &conv2d_12_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_10_chain,
  NULL, &eltwise_11_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_9_chain,
  NULL, &conv2d_10_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_9_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_9_pad_before_value_data, conv2d_9_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_pad_before_layer, 9,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_9_pad_before_chain,
  NULL, &conv2d_9_layer, AI_STATIC, 
  .value = &conv2d_9_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_8_chain,
  NULL, &conv2d_9_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_7_chain,
  NULL, &conv2d_8_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_6_chain,
  NULL, &conv2d_7_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_6_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_6_pad_before_value_data, conv2d_6_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_pad_before_layer, 5,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_6_pad_before_chain,
  NULL, &conv2d_6_layer, AI_STATIC, 
  .value = &conv2d_6_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_4_chain,
  NULL, &conv2d_6_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_3_chain,
  NULL, &conv2d_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_2_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_2_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_2_pad_before_value_data, conv2d_2_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_pad_before_layer, 2,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_2_pad_before_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .value = &conv2d_2_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_rgb_sssa8_ch,
  &conv2d_1_chain,
  NULL, &conv2d_2_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_218_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_217_const),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_218_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_218_layer, 218,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_218_chain,
  NULL, &conversion_0_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1078852, 1, 1),
    1078852, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 805280, 1, 1),
    805280, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conversion_202_output, &conversion_210_output, &conversion_218_output),
  &conversion_218_layer, 0x5924a100, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 247,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1078852, 1, 1),
      1078852, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 3,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 805280, 1, 1),
      805280, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conversion_202_output, &conversion_210_output, &conversion_218_output),
  &conversion_218_layer, 0x5924a100, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 3, params)) {
    /* Updating activations (byte) offsets */
    
    conv2d_1_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_2_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 600);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 600);
    conv2d_3_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_3_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_4_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 684);
    conv2d_4_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 684);
    conv2d_6_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 1196);
    conv2d_6_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 1196);
    conv2d_7_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_8_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_9_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_10_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_12_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_14_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_15_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_16_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_17_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    conv2d_17_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    conv2d_18_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_20_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_21_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_22_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_182_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_182_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_24_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_26_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_26_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_27_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_28_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_29_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_29_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_30_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_30_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_32_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_32_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_33_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_34_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_36_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_36_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_37_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_37_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_40_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_40_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_41_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_41_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_42_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_43_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_43_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_44_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 6532);
    conv2d_44_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 6532);
    conv2d_45_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_45_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_47_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_47_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_48_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_48_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_49_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_49_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_151_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_151_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_51_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_51_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_53_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_53_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_54_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_54_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_55_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_55_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_56_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_56_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_57_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_57_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_59_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_59_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_60_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_60_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_61_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_61_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_63_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_63_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_64_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_64_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_65_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_65_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_66_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_66_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_67_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_67_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_68_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_68_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_69_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_69_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_70_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_70_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_71_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_71_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_72_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_72_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_73_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_73_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_74_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_74_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_75_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_75_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_76_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_76_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_77_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_77_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_82_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_82_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_83_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_83_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_94_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_94_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_95_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_95_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_96_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_96_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_97_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_97_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_98_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_98_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_99_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_99_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_100_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_100_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_101_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_101_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_102_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_102_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_103_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_103_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_104_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_104_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_105_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_105_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_110_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_110_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_111_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_111_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_122_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_122_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_123_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_123_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_124_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_124_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_125_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_125_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_126_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_126_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_127_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_127_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_128_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_128_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_129_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_129_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_130_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_130_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_131_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_131_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_132_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_132_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_133_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_133_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_138_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_138_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_139_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_139_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_153_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_153_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_154_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_154_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_155_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_155_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_156_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_156_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_157_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_157_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_158_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_158_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_159_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_159_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_160_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_160_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_161_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_161_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_162_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_162_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_163_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_163_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_164_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_164_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_169_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_169_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_170_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_170_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_184_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_184_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_185_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_185_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_186_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_186_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_187_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_187_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_188_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_188_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_189_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_189_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_190_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_190_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_191_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_191_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_192_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_192_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_193_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_193_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_194_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_194_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_195_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_195_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    nl_201_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    nl_201_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_203_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_203_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_204_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_204_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    serving_default_input_10_output_array.data = AI_PTR(g_network_activations_map[1] + 90996);
    serving_default_input_10_output_array.data_start = AI_PTR(g_network_activations_map[1] + 90996);
    conversion_218_output_array.data = AI_PTR(g_network_activations_map[1] + 201588);
    conversion_218_output_array.data_start = AI_PTR(g_network_activations_map[1] + 201588);
    conversion_0_output_array.data = AI_PTR(g_network_activations_map[1] + 90992);
    conversion_0_output_array.data_start = AI_PTR(g_network_activations_map[1] + 90992);
    conv2d_1_output_array.data = AI_PTR(g_network_activations_map[1] + 52576);
    conv2d_1_output_array.data_start = AI_PTR(g_network_activations_map[1] + 52576);
    conv2d_2_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 46368);
    conv2d_2_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 46368);
    conv2d_2_output_array.data = AI_PTR(g_network_activations_map[1] + 44832);
    conv2d_2_output_array.data_start = AI_PTR(g_network_activations_map[1] + 44832);
    conv2d_3_output_array.data = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_3_output_array.data_start = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_6_output_array.data = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_6_output_array.data_start = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_7_output_array.data = AI_PTR(g_network_activations_map[1] + 154656);
    conv2d_7_output_array.data_start = AI_PTR(g_network_activations_map[1] + 154656);
    conv2d_8_output_array.data = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_8_output_array.data_start = AI_PTR(g_network_activations_map[1] + 44064);
    conv2d_9_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 34656);
    conv2d_9_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 34656);
    conv2d_9_output_array.data = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_9_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_10_output_array.data = AI_PTR(g_network_activations_map[1] + 173088);
    conv2d_10_output_array.data_start = AI_PTR(g_network_activations_map[1] + 173088);
    eltwise_11_output_array.data = AI_PTR(g_network_activations_map[1] + 32352);
    eltwise_11_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_12_output_array.data = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_12_output_array.data_start = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_14_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 46128);
    conv2d_14_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 46128);
    conv2d_14_output_array.data = AI_PTR(g_network_activations_map[1] + 161376);
    conv2d_14_output_array.data_start = AI_PTR(g_network_activations_map[1] + 161376);
    conv2d_15_output_array.data = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_15_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_16_output_array.data = AI_PTR(g_network_activations_map[1] + 41568);
    conv2d_16_output_array.data_start = AI_PTR(g_network_activations_map[1] + 41568);
    conv2d_17_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 96864);
    conv2d_17_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 96864);
    conv2d_17_output_array.data = AI_PTR(g_network_activations_map[1] + 41568);
    conv2d_17_output_array.data_start = AI_PTR(g_network_activations_map[1] + 41568);
    conv2d_18_output_array.data = AI_PTR(g_network_activations_map[1] + 96864);
    conv2d_18_output_array.data_start = AI_PTR(g_network_activations_map[1] + 96864);
    eltwise_19_output_array.data = AI_PTR(g_network_activations_map[1] + 41568);
    eltwise_19_output_array.data_start = AI_PTR(g_network_activations_map[1] + 41568);
    conv2d_20_output_array.data = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_20_output_array.data_start = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_21_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 106080);
    conv2d_21_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106080);
    conv2d_21_output_array.data = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_21_output_array.data_start = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_22_output_array.data = AI_PTR(g_network_activations_map[1] + 32352);
    conv2d_22_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32352);
    eltwise_23_output_array.data = AI_PTR(g_network_activations_map[1] + 50784);
    eltwise_23_output_array.data_start = AI_PTR(g_network_activations_map[1] + 50784);
    conv2d_182_output_array.data = AI_PTR(g_network_activations_map[1] + 60000);
    conv2d_182_output_array.data_start = AI_PTR(g_network_activations_map[1] + 60000);
    conv2d_24_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_24_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_26_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_26_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_26_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_26_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_27_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_27_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_28_output_array.data = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_28_output_array.data_start = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_29_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 24192);
    conv2d_29_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 24192);
    conv2d_29_output_array.data = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_29_output_array.data_start = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_30_output_array.data = AI_PTR(g_network_activations_map[1] + 24192);
    conv2d_30_output_array.data_start = AI_PTR(g_network_activations_map[1] + 24192);
    eltwise_31_output_array.data = AI_PTR(g_network_activations_map[1] + 3456);
    eltwise_31_output_array.data_start = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_32_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_32_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_33_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 27648);
    conv2d_33_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 27648);
    conv2d_33_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_33_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_34_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_34_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_35_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    eltwise_35_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_36_output_array.data = AI_PTR(g_network_activations_map[1] + 10368);
    conv2d_36_output_array.data_start = AI_PTR(g_network_activations_map[1] + 10368);
    conv2d_37_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 31104);
    conv2d_37_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 31104);
    conv2d_37_output_array.data = AI_PTR(g_network_activations_map[1] + 10368);
    conv2d_37_output_array.data_start = AI_PTR(g_network_activations_map[1] + 10368);
    conv2d_38_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_38_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_39_output_array.data = AI_PTR(g_network_activations_map[1] + 3456);
    eltwise_39_output_array.data_start = AI_PTR(g_network_activations_map[1] + 3456);
    conv2d_40_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_40_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_41_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 27648);
    conv2d_41_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 27648);
    conv2d_41_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_41_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_42_output_array.data = AI_PTR(g_network_activations_map[1] + 20736);
    conv2d_42_output_array.data_start = AI_PTR(g_network_activations_map[1] + 20736);
    conv2d_43_output_array.data = AI_PTR(g_network_activations_map[1] + 25344);
    conv2d_43_output_array.data_start = AI_PTR(g_network_activations_map[1] + 25344);
    conv2d_44_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_44_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_44_output_array.data = AI_PTR(g_network_activations_map[1] + 25344);
    conv2d_44_output_array.data_start = AI_PTR(g_network_activations_map[1] + 25344);
    conv2d_45_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_45_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_46_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    eltwise_46_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_47_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_47_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_48_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_48_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_48_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_48_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_49_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_49_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_50_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    eltwise_50_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_151_output_array.data = AI_PTR(g_network_activations_map[1] + 13824);
    conv2d_151_output_array.data_start = AI_PTR(g_network_activations_map[1] + 13824);
    conv2d_51_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_51_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_53_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_53_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_53_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_53_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_54_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_54_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_55_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_55_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_56_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_56_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_56_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_56_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_57_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_57_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_58_output_array.data = AI_PTR(g_network_activations_map[1] + 2016);
    eltwise_58_output_array.data_start = AI_PTR(g_network_activations_map[1] + 2016);
    conv2d_59_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_59_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_60_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_60_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_60_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_60_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_61_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_61_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    eltwise_62_output_array.data = AI_PTR(g_network_activations_map[1] + 4032);
    eltwise_62_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4032);
    conv2d_63_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_63_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_64_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_64_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_64_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_64_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_65_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_65_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_66_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_66_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_67_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_67_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_68_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_68_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_68_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_68_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_69_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_69_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_70_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_70_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_70_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_70_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_71_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_71_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_72_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_72_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_72_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_72_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_73_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_73_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_74_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_74_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_74_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_74_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_75_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_75_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_76_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_76_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_76_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_76_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_77_output_array.data = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_77_output_array.data_start = AI_PTR(g_network_activations_map[1] + 32256);
    conv2d_82_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_82_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_82_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_82_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_83_output_array.data = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_83_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9216);
    conv2d_94_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_94_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_94_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_94_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_95_output_array.data = AI_PTR(g_network_activations_map[1] + 5760);
    conv2d_95_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5760);
    conv2d_96_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_96_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_96_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_96_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_97_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_97_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_98_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_98_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_98_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_98_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_99_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_99_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_100_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_100_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_100_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_100_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_101_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_101_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_102_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_102_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_102_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_102_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_103_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_103_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_104_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_104_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_104_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_104_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_105_output_array.data = AI_PTR(g_network_activations_map[1] + 8064);
    conv2d_105_output_array.data_start = AI_PTR(g_network_activations_map[1] + 8064);
    conv2d_110_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_110_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_110_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_110_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_111_output_array.data = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_111_output_array.data_start = AI_PTR(g_network_activations_map[1] + 6912);
    conv2d_122_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_122_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_122_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_122_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_123_output_array.data = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_123_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_124_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_124_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_124_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_124_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_125_output_array.data = AI_PTR(g_network_activations_map[1] + 5064);
    conv2d_125_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5064);
    conv2d_126_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_126_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_126_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_126_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_127_output_array.data = AI_PTR(g_network_activations_map[1] + 5024);
    conv2d_127_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5024);
    conv2d_128_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_128_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_128_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_128_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_129_output_array.data = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_129_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_130_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_130_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_130_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_130_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_131_output_array.data = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_131_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_132_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_132_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_132_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_132_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_133_output_array.data = AI_PTR(g_network_activations_map[1] + 5632);
    conv2d_133_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5632);
    conv2d_138_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_138_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_138_output_array.data = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_138_output_array.data_start = AI_PTR(g_network_activations_map[1] + 4608);
    conv2d_139_output_array.data = AI_PTR(g_network_activations_map[1] + 5120);
    conv2d_139_output_array.data_start = AI_PTR(g_network_activations_map[1] + 5120);
    upsample_150_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    upsample_150_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    eltwise_152_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    eltwise_152_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_153_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_153_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_153_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_153_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_154_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_154_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_155_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_155_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_155_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_155_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_156_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_156_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_157_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_157_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_157_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_157_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_158_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_158_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_159_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_159_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_159_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_159_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_160_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_160_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_161_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_161_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_161_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_161_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_162_output_array.data = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_162_output_array.data_start = AI_PTR(g_network_activations_map[1] + 133728);
    conv2d_163_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_163_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_163_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_163_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_164_output_array.data = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_164_output_array.data_start = AI_PTR(g_network_activations_map[1] + 0);
    conv2d_169_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_169_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 152160);
    conv2d_169_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_169_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_170_output_array.data = AI_PTR(g_network_activations_map[1] + 28368);
    conv2d_170_output_array.data_start = AI_PTR(g_network_activations_map[1] + 28368);
    upsample_181_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    upsample_181_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    eltwise_183_output_array.data = AI_PTR(g_network_activations_map[1] + 60000);
    eltwise_183_output_array.data_start = AI_PTR(g_network_activations_map[1] + 60000);
    conv2d_184_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 47200);
    conv2d_184_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 47200);
    conv2d_184_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_184_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_185_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_185_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_186_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_186_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_186_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_186_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_187_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_187_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_188_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 94084);
    conv2d_188_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 94084);
    conv2d_188_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_188_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_189_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_189_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_190_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_190_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_190_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_190_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_191_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_191_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_192_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 94084);
    conv2d_192_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 94084);
    conv2d_192_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_192_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_193_output_array.data = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_193_output_array.data_start = AI_PTR(g_network_activations_map[1] + 33156);
    conv2d_194_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_194_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_194_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_194_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_195_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_195_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    concat_200_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    concat_200_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    nl_201_output_array.data = AI_PTR(g_network_activations_map[1] + 126112);
    nl_201_output_array.data_start = AI_PTR(g_network_activations_map[1] + 126112);
    conversion_202_output_array.data = AI_PTR(g_network_activations_map[1] + 263108);
    conversion_202_output_array.data_start = AI_PTR(g_network_activations_map[1] + 263108);
    conv2d_203_pad_before_output_array.data = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_203_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[1] + 106884);
    conv2d_203_output_array.data = AI_PTR(g_network_activations_map[1] + 31248);
    conv2d_203_output_array.data_start = AI_PTR(g_network_activations_map[1] + 31248);
    conv2d_204_output_array.data = AI_PTR(g_network_activations_map[1] + 9936);
    conv2d_204_output_array.data_start = AI_PTR(g_network_activations_map[1] + 9936);
    concat_209_output_array.data = AI_PTR(g_network_activations_map[1] + 31248);
    concat_209_output_array.data_start = AI_PTR(g_network_activations_map[1] + 31248);
    conversion_210_output_array.data = AI_PTR(g_network_activations_map[1] + 46628);
    conversion_210_output_array.data_start = AI_PTR(g_network_activations_map[1] + 46628);
    conv2d_4_output_array.data = AI_PTR(g_network_activations_map[2] + 9264);
    conv2d_4_output_array.data_start = AI_PTR(g_network_activations_map[2] + 9264);
    conv2d_6_pad_before_output_array.data = AI_PTR(g_network_activations_map[2] + 0);
    conv2d_6_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[2] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 247, params)) {
    /* Updating weights (byte) offsets */
    
    concat_217_const_array.format |= AI_FMT_FLAG_CONST;
    concat_217_const_array.data = AI_PTR(g_network_weights_map[0] + 0);
    concat_217_const_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_network_weights_map[1] + 0);
    conv2d_1_weights_array.data_start = AI_PTR(g_network_weights_map[1] + 0);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_network_weights_map[2] + 0);
    conv2d_1_bias_array.data_start = AI_PTR(g_network_weights_map[2] + 0);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_network_weights_map[3] + 0);
    conv2d_2_weights_array.data_start = AI_PTR(g_network_weights_map[3] + 0);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_network_weights_map[4] + 0);
    conv2d_2_bias_array.data_start = AI_PTR(g_network_weights_map[4] + 0);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(g_network_weights_map[5] + 0);
    conv2d_3_weights_array.data_start = AI_PTR(g_network_weights_map[5] + 0);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(g_network_weights_map[6] + 0);
    conv2d_3_bias_array.data_start = AI_PTR(g_network_weights_map[6] + 0);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(g_network_weights_map[7] + 0);
    conv2d_4_weights_array.data_start = AI_PTR(g_network_weights_map[7] + 0);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(g_network_weights_map[8] + 0);
    conv2d_4_bias_array.data_start = AI_PTR(g_network_weights_map[8] + 0);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(g_network_weights_map[9] + 0);
    conv2d_6_weights_array.data_start = AI_PTR(g_network_weights_map[9] + 0);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(g_network_weights_map[10] + 0);
    conv2d_6_bias_array.data_start = AI_PTR(g_network_weights_map[10] + 0);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(g_network_weights_map[11] + 0);
    conv2d_7_weights_array.data_start = AI_PTR(g_network_weights_map[11] + 0);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(g_network_weights_map[12] + 0);
    conv2d_7_bias_array.data_start = AI_PTR(g_network_weights_map[12] + 0);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(g_network_weights_map[13] + 0);
    conv2d_8_weights_array.data_start = AI_PTR(g_network_weights_map[13] + 0);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(g_network_weights_map[14] + 0);
    conv2d_8_bias_array.data_start = AI_PTR(g_network_weights_map[14] + 0);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(g_network_weights_map[15] + 0);
    conv2d_9_weights_array.data_start = AI_PTR(g_network_weights_map[15] + 0);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(g_network_weights_map[16] + 0);
    conv2d_9_bias_array.data_start = AI_PTR(g_network_weights_map[16] + 0);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(g_network_weights_map[17] + 0);
    conv2d_10_weights_array.data_start = AI_PTR(g_network_weights_map[17] + 0);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(g_network_weights_map[18] + 0);
    conv2d_10_bias_array.data_start = AI_PTR(g_network_weights_map[18] + 0);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(g_network_weights_map[19] + 0);
    conv2d_12_weights_array.data_start = AI_PTR(g_network_weights_map[19] + 0);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(g_network_weights_map[20] + 0);
    conv2d_12_bias_array.data_start = AI_PTR(g_network_weights_map[20] + 0);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(g_network_weights_map[21] + 0);
    conv2d_14_weights_array.data_start = AI_PTR(g_network_weights_map[21] + 0);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(g_network_weights_map[22] + 0);
    conv2d_14_bias_array.data_start = AI_PTR(g_network_weights_map[22] + 0);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(g_network_weights_map[23] + 0);
    conv2d_15_weights_array.data_start = AI_PTR(g_network_weights_map[23] + 0);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(g_network_weights_map[24] + 0);
    conv2d_15_bias_array.data_start = AI_PTR(g_network_weights_map[24] + 0);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(g_network_weights_map[25] + 0);
    conv2d_16_weights_array.data_start = AI_PTR(g_network_weights_map[25] + 0);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(g_network_weights_map[26] + 0);
    conv2d_16_bias_array.data_start = AI_PTR(g_network_weights_map[26] + 0);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(g_network_weights_map[27] + 0);
    conv2d_17_weights_array.data_start = AI_PTR(g_network_weights_map[27] + 0);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(g_network_weights_map[28] + 0);
    conv2d_17_bias_array.data_start = AI_PTR(g_network_weights_map[28] + 0);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(g_network_weights_map[29] + 0);
    conv2d_18_weights_array.data_start = AI_PTR(g_network_weights_map[29] + 0);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(g_network_weights_map[30] + 0);
    conv2d_18_bias_array.data_start = AI_PTR(g_network_weights_map[30] + 0);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(g_network_weights_map[31] + 0);
    conv2d_20_weights_array.data_start = AI_PTR(g_network_weights_map[31] + 0);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(g_network_weights_map[32] + 0);
    conv2d_20_bias_array.data_start = AI_PTR(g_network_weights_map[32] + 0);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(g_network_weights_map[33] + 0);
    conv2d_21_weights_array.data_start = AI_PTR(g_network_weights_map[33] + 0);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(g_network_weights_map[34] + 0);
    conv2d_21_bias_array.data_start = AI_PTR(g_network_weights_map[34] + 0);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(g_network_weights_map[35] + 0);
    conv2d_22_weights_array.data_start = AI_PTR(g_network_weights_map[35] + 0);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(g_network_weights_map[36] + 0);
    conv2d_22_bias_array.data_start = AI_PTR(g_network_weights_map[36] + 0);
    conv2d_182_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_182_weights_array.data = AI_PTR(g_network_weights_map[37] + 0);
    conv2d_182_weights_array.data_start = AI_PTR(g_network_weights_map[37] + 0);
    conv2d_182_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_182_bias_array.data = AI_PTR(g_network_weights_map[38] + 0);
    conv2d_182_bias_array.data_start = AI_PTR(g_network_weights_map[38] + 0);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(g_network_weights_map[39] + 0);
    conv2d_24_weights_array.data_start = AI_PTR(g_network_weights_map[39] + 0);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(g_network_weights_map[40] + 0);
    conv2d_24_bias_array.data_start = AI_PTR(g_network_weights_map[40] + 0);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(g_network_weights_map[41] + 0);
    conv2d_26_weights_array.data_start = AI_PTR(g_network_weights_map[41] + 0);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(g_network_weights_map[42] + 0);
    conv2d_26_bias_array.data_start = AI_PTR(g_network_weights_map[42] + 0);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(g_network_weights_map[43] + 0);
    conv2d_27_weights_array.data_start = AI_PTR(g_network_weights_map[43] + 0);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(g_network_weights_map[44] + 0);
    conv2d_27_bias_array.data_start = AI_PTR(g_network_weights_map[44] + 0);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(g_network_weights_map[45] + 0);
    conv2d_28_weights_array.data_start = AI_PTR(g_network_weights_map[45] + 0);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(g_network_weights_map[46] + 0);
    conv2d_28_bias_array.data_start = AI_PTR(g_network_weights_map[46] + 0);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(g_network_weights_map[47] + 0);
    conv2d_29_weights_array.data_start = AI_PTR(g_network_weights_map[47] + 0);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(g_network_weights_map[48] + 0);
    conv2d_29_bias_array.data_start = AI_PTR(g_network_weights_map[48] + 0);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(g_network_weights_map[49] + 0);
    conv2d_30_weights_array.data_start = AI_PTR(g_network_weights_map[49] + 0);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(g_network_weights_map[50] + 0);
    conv2d_30_bias_array.data_start = AI_PTR(g_network_weights_map[50] + 0);
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(g_network_weights_map[51] + 0);
    conv2d_32_weights_array.data_start = AI_PTR(g_network_weights_map[51] + 0);
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(g_network_weights_map[52] + 0);
    conv2d_32_bias_array.data_start = AI_PTR(g_network_weights_map[52] + 0);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(g_network_weights_map[53] + 0);
    conv2d_33_weights_array.data_start = AI_PTR(g_network_weights_map[53] + 0);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(g_network_weights_map[54] + 0);
    conv2d_33_bias_array.data_start = AI_PTR(g_network_weights_map[54] + 0);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(g_network_weights_map[55] + 0);
    conv2d_34_weights_array.data_start = AI_PTR(g_network_weights_map[55] + 0);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(g_network_weights_map[56] + 0);
    conv2d_34_bias_array.data_start = AI_PTR(g_network_weights_map[56] + 0);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(g_network_weights_map[57] + 0);
    conv2d_36_weights_array.data_start = AI_PTR(g_network_weights_map[57] + 0);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(g_network_weights_map[58] + 0);
    conv2d_36_bias_array.data_start = AI_PTR(g_network_weights_map[58] + 0);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(g_network_weights_map[59] + 0);
    conv2d_37_weights_array.data_start = AI_PTR(g_network_weights_map[59] + 0);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(g_network_weights_map[60] + 0);
    conv2d_37_bias_array.data_start = AI_PTR(g_network_weights_map[60] + 0);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(g_network_weights_map[61] + 0);
    conv2d_38_weights_array.data_start = AI_PTR(g_network_weights_map[61] + 0);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(g_network_weights_map[62] + 0);
    conv2d_38_bias_array.data_start = AI_PTR(g_network_weights_map[62] + 0);
    conv2d_40_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_weights_array.data = AI_PTR(g_network_weights_map[63] + 0);
    conv2d_40_weights_array.data_start = AI_PTR(g_network_weights_map[63] + 0);
    conv2d_40_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_bias_array.data = AI_PTR(g_network_weights_map[64] + 0);
    conv2d_40_bias_array.data_start = AI_PTR(g_network_weights_map[64] + 0);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(g_network_weights_map[65] + 0);
    conv2d_41_weights_array.data_start = AI_PTR(g_network_weights_map[65] + 0);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(g_network_weights_map[66] + 0);
    conv2d_41_bias_array.data_start = AI_PTR(g_network_weights_map[66] + 0);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(g_network_weights_map[67] + 0);
    conv2d_42_weights_array.data_start = AI_PTR(g_network_weights_map[67] + 0);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(g_network_weights_map[68] + 0);
    conv2d_42_bias_array.data_start = AI_PTR(g_network_weights_map[68] + 0);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(g_network_weights_map[69] + 0);
    conv2d_43_weights_array.data_start = AI_PTR(g_network_weights_map[69] + 0);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(g_network_weights_map[70] + 0);
    conv2d_43_bias_array.data_start = AI_PTR(g_network_weights_map[70] + 0);
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(g_network_weights_map[71] + 0);
    conv2d_44_weights_array.data_start = AI_PTR(g_network_weights_map[71] + 0);
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(g_network_weights_map[72] + 0);
    conv2d_44_bias_array.data_start = AI_PTR(g_network_weights_map[72] + 0);
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(g_network_weights_map[73] + 0);
    conv2d_45_weights_array.data_start = AI_PTR(g_network_weights_map[73] + 0);
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(g_network_weights_map[74] + 0);
    conv2d_45_bias_array.data_start = AI_PTR(g_network_weights_map[74] + 0);
    conv2d_47_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_weights_array.data = AI_PTR(g_network_weights_map[75] + 0);
    conv2d_47_weights_array.data_start = AI_PTR(g_network_weights_map[75] + 0);
    conv2d_47_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_bias_array.data = AI_PTR(g_network_weights_map[76] + 0);
    conv2d_47_bias_array.data_start = AI_PTR(g_network_weights_map[76] + 0);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(g_network_weights_map[77] + 0);
    conv2d_48_weights_array.data_start = AI_PTR(g_network_weights_map[77] + 0);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(g_network_weights_map[78] + 0);
    conv2d_48_bias_array.data_start = AI_PTR(g_network_weights_map[78] + 0);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(g_network_weights_map[79] + 0);
    conv2d_49_weights_array.data_start = AI_PTR(g_network_weights_map[79] + 0);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(g_network_weights_map[80] + 0);
    conv2d_49_bias_array.data_start = AI_PTR(g_network_weights_map[80] + 0);
    conv2d_151_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_151_weights_array.data = AI_PTR(g_network_weights_map[81] + 0);
    conv2d_151_weights_array.data_start = AI_PTR(g_network_weights_map[81] + 0);
    conv2d_151_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_151_bias_array.data = AI_PTR(g_network_weights_map[82] + 0);
    conv2d_151_bias_array.data_start = AI_PTR(g_network_weights_map[82] + 0);
    conv2d_51_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_weights_array.data = AI_PTR(g_network_weights_map[83] + 0);
    conv2d_51_weights_array.data_start = AI_PTR(g_network_weights_map[83] + 0);
    conv2d_51_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_bias_array.data = AI_PTR(g_network_weights_map[84] + 0);
    conv2d_51_bias_array.data_start = AI_PTR(g_network_weights_map[84] + 0);
    conv2d_53_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_weights_array.data = AI_PTR(g_network_weights_map[85] + 0);
    conv2d_53_weights_array.data_start = AI_PTR(g_network_weights_map[85] + 0);
    conv2d_53_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_bias_array.data = AI_PTR(g_network_weights_map[86] + 0);
    conv2d_53_bias_array.data_start = AI_PTR(g_network_weights_map[86] + 0);
    conv2d_54_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_weights_array.data = AI_PTR(g_network_weights_map[87] + 0);
    conv2d_54_weights_array.data_start = AI_PTR(g_network_weights_map[87] + 0);
    conv2d_54_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_bias_array.data = AI_PTR(g_network_weights_map[88] + 0);
    conv2d_54_bias_array.data_start = AI_PTR(g_network_weights_map[88] + 0);
    conv2d_55_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_weights_array.data = AI_PTR(g_network_weights_map[89] + 0);
    conv2d_55_weights_array.data_start = AI_PTR(g_network_weights_map[89] + 0);
    conv2d_55_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_bias_array.data = AI_PTR(g_network_weights_map[90] + 0);
    conv2d_55_bias_array.data_start = AI_PTR(g_network_weights_map[90] + 0);
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(g_network_weights_map[91] + 0);
    conv2d_56_weights_array.data_start = AI_PTR(g_network_weights_map[91] + 0);
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(g_network_weights_map[92] + 0);
    conv2d_56_bias_array.data_start = AI_PTR(g_network_weights_map[92] + 0);
    conv2d_57_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_weights_array.data = AI_PTR(g_network_weights_map[93] + 0);
    conv2d_57_weights_array.data_start = AI_PTR(g_network_weights_map[93] + 0);
    conv2d_57_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_bias_array.data = AI_PTR(g_network_weights_map[94] + 0);
    conv2d_57_bias_array.data_start = AI_PTR(g_network_weights_map[94] + 0);
    conv2d_59_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_59_weights_array.data = AI_PTR(g_network_weights_map[95] + 0);
    conv2d_59_weights_array.data_start = AI_PTR(g_network_weights_map[95] + 0);
    conv2d_59_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_59_bias_array.data = AI_PTR(g_network_weights_map[96] + 0);
    conv2d_59_bias_array.data_start = AI_PTR(g_network_weights_map[96] + 0);
    conv2d_60_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_weights_array.data = AI_PTR(g_network_weights_map[97] + 0);
    conv2d_60_weights_array.data_start = AI_PTR(g_network_weights_map[97] + 0);
    conv2d_60_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_bias_array.data = AI_PTR(g_network_weights_map[98] + 0);
    conv2d_60_bias_array.data_start = AI_PTR(g_network_weights_map[98] + 0);
    conv2d_61_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_weights_array.data = AI_PTR(g_network_weights_map[99] + 0);
    conv2d_61_weights_array.data_start = AI_PTR(g_network_weights_map[99] + 0);
    conv2d_61_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_bias_array.data = AI_PTR(g_network_weights_map[100] + 0);
    conv2d_61_bias_array.data_start = AI_PTR(g_network_weights_map[100] + 0);
    conv2d_63_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_63_weights_array.data = AI_PTR(g_network_weights_map[101] + 0);
    conv2d_63_weights_array.data_start = AI_PTR(g_network_weights_map[101] + 0);
    conv2d_63_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_63_bias_array.data = AI_PTR(g_network_weights_map[102] + 0);
    conv2d_63_bias_array.data_start = AI_PTR(g_network_weights_map[102] + 0);
    conv2d_64_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_weights_array.data = AI_PTR(g_network_weights_map[103] + 0);
    conv2d_64_weights_array.data_start = AI_PTR(g_network_weights_map[103] + 0);
    conv2d_64_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_bias_array.data = AI_PTR(g_network_weights_map[104] + 0);
    conv2d_64_bias_array.data_start = AI_PTR(g_network_weights_map[104] + 0);
    conv2d_65_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_weights_array.data = AI_PTR(g_network_weights_map[105] + 0);
    conv2d_65_weights_array.data_start = AI_PTR(g_network_weights_map[105] + 0);
    conv2d_65_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_bias_array.data = AI_PTR(g_network_weights_map[106] + 0);
    conv2d_65_bias_array.data_start = AI_PTR(g_network_weights_map[106] + 0);
    conv2d_66_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_weights_array.data = AI_PTR(g_network_weights_map[107] + 0);
    conv2d_66_weights_array.data_start = AI_PTR(g_network_weights_map[107] + 0);
    conv2d_66_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_bias_array.data = AI_PTR(g_network_weights_map[108] + 0);
    conv2d_66_bias_array.data_start = AI_PTR(g_network_weights_map[108] + 0);
    conv2d_67_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_weights_array.data = AI_PTR(g_network_weights_map[109] + 0);
    conv2d_67_weights_array.data_start = AI_PTR(g_network_weights_map[109] + 0);
    conv2d_67_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_bias_array.data = AI_PTR(g_network_weights_map[110] + 0);
    conv2d_67_bias_array.data_start = AI_PTR(g_network_weights_map[110] + 0);
    conv2d_68_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_68_weights_array.data = AI_PTR(g_network_weights_map[111] + 0);
    conv2d_68_weights_array.data_start = AI_PTR(g_network_weights_map[111] + 0);
    conv2d_68_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_68_bias_array.data = AI_PTR(g_network_weights_map[112] + 0);
    conv2d_68_bias_array.data_start = AI_PTR(g_network_weights_map[112] + 0);
    conv2d_69_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_69_weights_array.data = AI_PTR(g_network_weights_map[113] + 0);
    conv2d_69_weights_array.data_start = AI_PTR(g_network_weights_map[113] + 0);
    conv2d_69_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_69_bias_array.data = AI_PTR(g_network_weights_map[114] + 0);
    conv2d_69_bias_array.data_start = AI_PTR(g_network_weights_map[114] + 0);
    conv2d_70_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_70_weights_array.data = AI_PTR(g_network_weights_map[115] + 0);
    conv2d_70_weights_array.data_start = AI_PTR(g_network_weights_map[115] + 0);
    conv2d_70_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_70_bias_array.data = AI_PTR(g_network_weights_map[116] + 0);
    conv2d_70_bias_array.data_start = AI_PTR(g_network_weights_map[116] + 0);
    conv2d_71_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_71_weights_array.data = AI_PTR(g_network_weights_map[117] + 0);
    conv2d_71_weights_array.data_start = AI_PTR(g_network_weights_map[117] + 0);
    conv2d_71_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_71_bias_array.data = AI_PTR(g_network_weights_map[118] + 0);
    conv2d_71_bias_array.data_start = AI_PTR(g_network_weights_map[118] + 0);
    conv2d_72_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_72_weights_array.data = AI_PTR(g_network_weights_map[119] + 0);
    conv2d_72_weights_array.data_start = AI_PTR(g_network_weights_map[119] + 0);
    conv2d_72_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_72_bias_array.data = AI_PTR(g_network_weights_map[120] + 0);
    conv2d_72_bias_array.data_start = AI_PTR(g_network_weights_map[120] + 0);
    conv2d_73_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_73_weights_array.data = AI_PTR(g_network_weights_map[121] + 0);
    conv2d_73_weights_array.data_start = AI_PTR(g_network_weights_map[121] + 0);
    conv2d_73_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_73_bias_array.data = AI_PTR(g_network_weights_map[122] + 0);
    conv2d_73_bias_array.data_start = AI_PTR(g_network_weights_map[122] + 0);
    conv2d_74_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_74_weights_array.data = AI_PTR(g_network_weights_map[123] + 0);
    conv2d_74_weights_array.data_start = AI_PTR(g_network_weights_map[123] + 0);
    conv2d_74_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_74_bias_array.data = AI_PTR(g_network_weights_map[124] + 0);
    conv2d_74_bias_array.data_start = AI_PTR(g_network_weights_map[124] + 0);
    conv2d_75_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_75_weights_array.data = AI_PTR(g_network_weights_map[125] + 0);
    conv2d_75_weights_array.data_start = AI_PTR(g_network_weights_map[125] + 0);
    conv2d_75_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_75_bias_array.data = AI_PTR(g_network_weights_map[126] + 0);
    conv2d_75_bias_array.data_start = AI_PTR(g_network_weights_map[126] + 0);
    conv2d_76_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_76_weights_array.data = AI_PTR(g_network_weights_map[127] + 0);
    conv2d_76_weights_array.data_start = AI_PTR(g_network_weights_map[127] + 0);
    conv2d_76_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_76_bias_array.data = AI_PTR(g_network_weights_map[128] + 0);
    conv2d_76_bias_array.data_start = AI_PTR(g_network_weights_map[128] + 0);
    conv2d_77_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_77_weights_array.data = AI_PTR(g_network_weights_map[129] + 0);
    conv2d_77_weights_array.data_start = AI_PTR(g_network_weights_map[129] + 0);
    conv2d_77_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_77_bias_array.data = AI_PTR(g_network_weights_map[130] + 0);
    conv2d_77_bias_array.data_start = AI_PTR(g_network_weights_map[130] + 0);
    conv2d_82_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_82_weights_array.data = AI_PTR(g_network_weights_map[131] + 0);
    conv2d_82_weights_array.data_start = AI_PTR(g_network_weights_map[131] + 0);
    conv2d_82_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_82_bias_array.data = AI_PTR(g_network_weights_map[132] + 0);
    conv2d_82_bias_array.data_start = AI_PTR(g_network_weights_map[132] + 0);
    conv2d_83_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_83_weights_array.data = AI_PTR(g_network_weights_map[133] + 0);
    conv2d_83_weights_array.data_start = AI_PTR(g_network_weights_map[133] + 0);
    conv2d_83_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_83_bias_array.data = AI_PTR(g_network_weights_map[134] + 0);
    conv2d_83_bias_array.data_start = AI_PTR(g_network_weights_map[134] + 0);
    conv2d_94_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_94_weights_array.data = AI_PTR(g_network_weights_map[135] + 0);
    conv2d_94_weights_array.data_start = AI_PTR(g_network_weights_map[135] + 0);
    conv2d_94_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_94_bias_array.data = AI_PTR(g_network_weights_map[136] + 0);
    conv2d_94_bias_array.data_start = AI_PTR(g_network_weights_map[136] + 0);
    conv2d_95_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_95_weights_array.data = AI_PTR(g_network_weights_map[137] + 0);
    conv2d_95_weights_array.data_start = AI_PTR(g_network_weights_map[137] + 0);
    conv2d_95_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_95_bias_array.data = AI_PTR(g_network_weights_map[138] + 0);
    conv2d_95_bias_array.data_start = AI_PTR(g_network_weights_map[138] + 0);
    conv2d_96_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_96_weights_array.data = AI_PTR(g_network_weights_map[139] + 0);
    conv2d_96_weights_array.data_start = AI_PTR(g_network_weights_map[139] + 0);
    conv2d_96_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_96_bias_array.data = AI_PTR(g_network_weights_map[140] + 0);
    conv2d_96_bias_array.data_start = AI_PTR(g_network_weights_map[140] + 0);
    conv2d_97_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_97_weights_array.data = AI_PTR(g_network_weights_map[141] + 0);
    conv2d_97_weights_array.data_start = AI_PTR(g_network_weights_map[141] + 0);
    conv2d_97_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_97_bias_array.data = AI_PTR(g_network_weights_map[142] + 0);
    conv2d_97_bias_array.data_start = AI_PTR(g_network_weights_map[142] + 0);
    conv2d_98_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_98_weights_array.data = AI_PTR(g_network_weights_map[143] + 0);
    conv2d_98_weights_array.data_start = AI_PTR(g_network_weights_map[143] + 0);
    conv2d_98_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_98_bias_array.data = AI_PTR(g_network_weights_map[144] + 0);
    conv2d_98_bias_array.data_start = AI_PTR(g_network_weights_map[144] + 0);
    conv2d_99_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_99_weights_array.data = AI_PTR(g_network_weights_map[145] + 0);
    conv2d_99_weights_array.data_start = AI_PTR(g_network_weights_map[145] + 0);
    conv2d_99_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_99_bias_array.data = AI_PTR(g_network_weights_map[146] + 0);
    conv2d_99_bias_array.data_start = AI_PTR(g_network_weights_map[146] + 0);
    conv2d_100_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_100_weights_array.data = AI_PTR(g_network_weights_map[147] + 0);
    conv2d_100_weights_array.data_start = AI_PTR(g_network_weights_map[147] + 0);
    conv2d_100_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_100_bias_array.data = AI_PTR(g_network_weights_map[148] + 0);
    conv2d_100_bias_array.data_start = AI_PTR(g_network_weights_map[148] + 0);
    conv2d_101_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_101_weights_array.data = AI_PTR(g_network_weights_map[149] + 0);
    conv2d_101_weights_array.data_start = AI_PTR(g_network_weights_map[149] + 0);
    conv2d_101_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_101_bias_array.data = AI_PTR(g_network_weights_map[150] + 0);
    conv2d_101_bias_array.data_start = AI_PTR(g_network_weights_map[150] + 0);
    conv2d_102_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_102_weights_array.data = AI_PTR(g_network_weights_map[151] + 0);
    conv2d_102_weights_array.data_start = AI_PTR(g_network_weights_map[151] + 0);
    conv2d_102_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_102_bias_array.data = AI_PTR(g_network_weights_map[152] + 0);
    conv2d_102_bias_array.data_start = AI_PTR(g_network_weights_map[152] + 0);
    conv2d_103_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_103_weights_array.data = AI_PTR(g_network_weights_map[153] + 0);
    conv2d_103_weights_array.data_start = AI_PTR(g_network_weights_map[153] + 0);
    conv2d_103_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_103_bias_array.data = AI_PTR(g_network_weights_map[154] + 0);
    conv2d_103_bias_array.data_start = AI_PTR(g_network_weights_map[154] + 0);
    conv2d_104_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_104_weights_array.data = AI_PTR(g_network_weights_map[155] + 0);
    conv2d_104_weights_array.data_start = AI_PTR(g_network_weights_map[155] + 0);
    conv2d_104_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_104_bias_array.data = AI_PTR(g_network_weights_map[156] + 0);
    conv2d_104_bias_array.data_start = AI_PTR(g_network_weights_map[156] + 0);
    conv2d_105_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_105_weights_array.data = AI_PTR(g_network_weights_map[157] + 0);
    conv2d_105_weights_array.data_start = AI_PTR(g_network_weights_map[157] + 0);
    conv2d_105_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_105_bias_array.data = AI_PTR(g_network_weights_map[158] + 0);
    conv2d_105_bias_array.data_start = AI_PTR(g_network_weights_map[158] + 0);
    conv2d_110_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_110_weights_array.data = AI_PTR(g_network_weights_map[159] + 0);
    conv2d_110_weights_array.data_start = AI_PTR(g_network_weights_map[159] + 0);
    conv2d_110_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_110_bias_array.data = AI_PTR(g_network_weights_map[160] + 0);
    conv2d_110_bias_array.data_start = AI_PTR(g_network_weights_map[160] + 0);
    conv2d_111_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_weights_array.data = AI_PTR(g_network_weights_map[161] + 0);
    conv2d_111_weights_array.data_start = AI_PTR(g_network_weights_map[161] + 0);
    conv2d_111_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_bias_array.data = AI_PTR(g_network_weights_map[162] + 0);
    conv2d_111_bias_array.data_start = AI_PTR(g_network_weights_map[162] + 0);
    conv2d_122_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_122_weights_array.data = AI_PTR(g_network_weights_map[163] + 0);
    conv2d_122_weights_array.data_start = AI_PTR(g_network_weights_map[163] + 0);
    conv2d_122_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_122_bias_array.data = AI_PTR(g_network_weights_map[164] + 0);
    conv2d_122_bias_array.data_start = AI_PTR(g_network_weights_map[164] + 0);
    conv2d_123_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_123_weights_array.data = AI_PTR(g_network_weights_map[165] + 0);
    conv2d_123_weights_array.data_start = AI_PTR(g_network_weights_map[165] + 0);
    conv2d_123_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_123_bias_array.data = AI_PTR(g_network_weights_map[166] + 0);
    conv2d_123_bias_array.data_start = AI_PTR(g_network_weights_map[166] + 0);
    conv2d_124_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_124_weights_array.data = AI_PTR(g_network_weights_map[167] + 0);
    conv2d_124_weights_array.data_start = AI_PTR(g_network_weights_map[167] + 0);
    conv2d_124_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_124_bias_array.data = AI_PTR(g_network_weights_map[168] + 0);
    conv2d_124_bias_array.data_start = AI_PTR(g_network_weights_map[168] + 0);
    conv2d_125_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_125_weights_array.data = AI_PTR(g_network_weights_map[169] + 0);
    conv2d_125_weights_array.data_start = AI_PTR(g_network_weights_map[169] + 0);
    conv2d_125_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_125_bias_array.data = AI_PTR(g_network_weights_map[170] + 0);
    conv2d_125_bias_array.data_start = AI_PTR(g_network_weights_map[170] + 0);
    conv2d_126_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_126_weights_array.data = AI_PTR(g_network_weights_map[171] + 0);
    conv2d_126_weights_array.data_start = AI_PTR(g_network_weights_map[171] + 0);
    conv2d_126_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_126_bias_array.data = AI_PTR(g_network_weights_map[172] + 0);
    conv2d_126_bias_array.data_start = AI_PTR(g_network_weights_map[172] + 0);
    conv2d_127_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_127_weights_array.data = AI_PTR(g_network_weights_map[173] + 0);
    conv2d_127_weights_array.data_start = AI_PTR(g_network_weights_map[173] + 0);
    conv2d_127_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_127_bias_array.data = AI_PTR(g_network_weights_map[174] + 0);
    conv2d_127_bias_array.data_start = AI_PTR(g_network_weights_map[174] + 0);
    conv2d_128_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_128_weights_array.data = AI_PTR(g_network_weights_map[175] + 0);
    conv2d_128_weights_array.data_start = AI_PTR(g_network_weights_map[175] + 0);
    conv2d_128_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_128_bias_array.data = AI_PTR(g_network_weights_map[176] + 0);
    conv2d_128_bias_array.data_start = AI_PTR(g_network_weights_map[176] + 0);
    conv2d_129_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_129_weights_array.data = AI_PTR(g_network_weights_map[177] + 0);
    conv2d_129_weights_array.data_start = AI_PTR(g_network_weights_map[177] + 0);
    conv2d_129_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_129_bias_array.data = AI_PTR(g_network_weights_map[178] + 0);
    conv2d_129_bias_array.data_start = AI_PTR(g_network_weights_map[178] + 0);
    conv2d_130_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_130_weights_array.data = AI_PTR(g_network_weights_map[179] + 0);
    conv2d_130_weights_array.data_start = AI_PTR(g_network_weights_map[179] + 0);
    conv2d_130_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_130_bias_array.data = AI_PTR(g_network_weights_map[180] + 0);
    conv2d_130_bias_array.data_start = AI_PTR(g_network_weights_map[180] + 0);
    conv2d_131_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_131_weights_array.data = AI_PTR(g_network_weights_map[181] + 0);
    conv2d_131_weights_array.data_start = AI_PTR(g_network_weights_map[181] + 0);
    conv2d_131_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_131_bias_array.data = AI_PTR(g_network_weights_map[182] + 0);
    conv2d_131_bias_array.data_start = AI_PTR(g_network_weights_map[182] + 0);
    conv2d_132_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_132_weights_array.data = AI_PTR(g_network_weights_map[183] + 0);
    conv2d_132_weights_array.data_start = AI_PTR(g_network_weights_map[183] + 0);
    conv2d_132_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_132_bias_array.data = AI_PTR(g_network_weights_map[184] + 0);
    conv2d_132_bias_array.data_start = AI_PTR(g_network_weights_map[184] + 0);
    conv2d_133_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_133_weights_array.data = AI_PTR(g_network_weights_map[185] + 0);
    conv2d_133_weights_array.data_start = AI_PTR(g_network_weights_map[185] + 0);
    conv2d_133_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_133_bias_array.data = AI_PTR(g_network_weights_map[186] + 0);
    conv2d_133_bias_array.data_start = AI_PTR(g_network_weights_map[186] + 0);
    conv2d_138_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_138_weights_array.data = AI_PTR(g_network_weights_map[187] + 0);
    conv2d_138_weights_array.data_start = AI_PTR(g_network_weights_map[187] + 0);
    conv2d_138_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_138_bias_array.data = AI_PTR(g_network_weights_map[188] + 0);
    conv2d_138_bias_array.data_start = AI_PTR(g_network_weights_map[188] + 0);
    conv2d_139_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_139_weights_array.data = AI_PTR(g_network_weights_map[189] + 0);
    conv2d_139_weights_array.data_start = AI_PTR(g_network_weights_map[189] + 0);
    conv2d_139_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_139_bias_array.data = AI_PTR(g_network_weights_map[190] + 0);
    conv2d_139_bias_array.data_start = AI_PTR(g_network_weights_map[190] + 0);
    conv2d_153_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_153_weights_array.data = AI_PTR(g_network_weights_map[191] + 0);
    conv2d_153_weights_array.data_start = AI_PTR(g_network_weights_map[191] + 0);
    conv2d_153_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_153_bias_array.data = AI_PTR(g_network_weights_map[192] + 0);
    conv2d_153_bias_array.data_start = AI_PTR(g_network_weights_map[192] + 0);
    conv2d_154_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_154_weights_array.data = AI_PTR(g_network_weights_map[193] + 0);
    conv2d_154_weights_array.data_start = AI_PTR(g_network_weights_map[193] + 0);
    conv2d_154_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_154_bias_array.data = AI_PTR(g_network_weights_map[194] + 0);
    conv2d_154_bias_array.data_start = AI_PTR(g_network_weights_map[194] + 0);
    conv2d_155_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_155_weights_array.data = AI_PTR(g_network_weights_map[195] + 0);
    conv2d_155_weights_array.data_start = AI_PTR(g_network_weights_map[195] + 0);
    conv2d_155_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_155_bias_array.data = AI_PTR(g_network_weights_map[196] + 0);
    conv2d_155_bias_array.data_start = AI_PTR(g_network_weights_map[196] + 0);
    conv2d_156_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_156_weights_array.data = AI_PTR(g_network_weights_map[197] + 0);
    conv2d_156_weights_array.data_start = AI_PTR(g_network_weights_map[197] + 0);
    conv2d_156_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_156_bias_array.data = AI_PTR(g_network_weights_map[198] + 0);
    conv2d_156_bias_array.data_start = AI_PTR(g_network_weights_map[198] + 0);
    conv2d_157_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_157_weights_array.data = AI_PTR(g_network_weights_map[199] + 0);
    conv2d_157_weights_array.data_start = AI_PTR(g_network_weights_map[199] + 0);
    conv2d_157_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_157_bias_array.data = AI_PTR(g_network_weights_map[200] + 0);
    conv2d_157_bias_array.data_start = AI_PTR(g_network_weights_map[200] + 0);
    conv2d_158_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_158_weights_array.data = AI_PTR(g_network_weights_map[201] + 0);
    conv2d_158_weights_array.data_start = AI_PTR(g_network_weights_map[201] + 0);
    conv2d_158_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_158_bias_array.data = AI_PTR(g_network_weights_map[202] + 0);
    conv2d_158_bias_array.data_start = AI_PTR(g_network_weights_map[202] + 0);
    conv2d_159_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_159_weights_array.data = AI_PTR(g_network_weights_map[203] + 0);
    conv2d_159_weights_array.data_start = AI_PTR(g_network_weights_map[203] + 0);
    conv2d_159_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_159_bias_array.data = AI_PTR(g_network_weights_map[204] + 0);
    conv2d_159_bias_array.data_start = AI_PTR(g_network_weights_map[204] + 0);
    conv2d_160_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_160_weights_array.data = AI_PTR(g_network_weights_map[205] + 0);
    conv2d_160_weights_array.data_start = AI_PTR(g_network_weights_map[205] + 0);
    conv2d_160_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_160_bias_array.data = AI_PTR(g_network_weights_map[206] + 0);
    conv2d_160_bias_array.data_start = AI_PTR(g_network_weights_map[206] + 0);
    conv2d_161_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_161_weights_array.data = AI_PTR(g_network_weights_map[207] + 0);
    conv2d_161_weights_array.data_start = AI_PTR(g_network_weights_map[207] + 0);
    conv2d_161_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_161_bias_array.data = AI_PTR(g_network_weights_map[208] + 0);
    conv2d_161_bias_array.data_start = AI_PTR(g_network_weights_map[208] + 0);
    conv2d_162_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_162_weights_array.data = AI_PTR(g_network_weights_map[209] + 0);
    conv2d_162_weights_array.data_start = AI_PTR(g_network_weights_map[209] + 0);
    conv2d_162_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_162_bias_array.data = AI_PTR(g_network_weights_map[210] + 0);
    conv2d_162_bias_array.data_start = AI_PTR(g_network_weights_map[210] + 0);
    conv2d_163_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_163_weights_array.data = AI_PTR(g_network_weights_map[211] + 0);
    conv2d_163_weights_array.data_start = AI_PTR(g_network_weights_map[211] + 0);
    conv2d_163_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_163_bias_array.data = AI_PTR(g_network_weights_map[212] + 0);
    conv2d_163_bias_array.data_start = AI_PTR(g_network_weights_map[212] + 0);
    conv2d_164_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_164_weights_array.data = AI_PTR(g_network_weights_map[213] + 0);
    conv2d_164_weights_array.data_start = AI_PTR(g_network_weights_map[213] + 0);
    conv2d_164_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_164_bias_array.data = AI_PTR(g_network_weights_map[214] + 0);
    conv2d_164_bias_array.data_start = AI_PTR(g_network_weights_map[214] + 0);
    conv2d_169_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_169_weights_array.data = AI_PTR(g_network_weights_map[215] + 0);
    conv2d_169_weights_array.data_start = AI_PTR(g_network_weights_map[215] + 0);
    conv2d_169_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_169_bias_array.data = AI_PTR(g_network_weights_map[216] + 0);
    conv2d_169_bias_array.data_start = AI_PTR(g_network_weights_map[216] + 0);
    conv2d_170_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_170_weights_array.data = AI_PTR(g_network_weights_map[217] + 0);
    conv2d_170_weights_array.data_start = AI_PTR(g_network_weights_map[217] + 0);
    conv2d_170_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_170_bias_array.data = AI_PTR(g_network_weights_map[218] + 0);
    conv2d_170_bias_array.data_start = AI_PTR(g_network_weights_map[218] + 0);
    conv2d_184_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_184_weights_array.data = AI_PTR(g_network_weights_map[219] + 0);
    conv2d_184_weights_array.data_start = AI_PTR(g_network_weights_map[219] + 0);
    conv2d_184_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_184_bias_array.data = AI_PTR(g_network_weights_map[220] + 0);
    conv2d_184_bias_array.data_start = AI_PTR(g_network_weights_map[220] + 0);
    conv2d_185_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_185_weights_array.data = AI_PTR(g_network_weights_map[221] + 0);
    conv2d_185_weights_array.data_start = AI_PTR(g_network_weights_map[221] + 0);
    conv2d_185_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_185_bias_array.data = AI_PTR(g_network_weights_map[222] + 0);
    conv2d_185_bias_array.data_start = AI_PTR(g_network_weights_map[222] + 0);
    conv2d_186_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_186_weights_array.data = AI_PTR(g_network_weights_map[223] + 0);
    conv2d_186_weights_array.data_start = AI_PTR(g_network_weights_map[223] + 0);
    conv2d_186_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_186_bias_array.data = AI_PTR(g_network_weights_map[224] + 0);
    conv2d_186_bias_array.data_start = AI_PTR(g_network_weights_map[224] + 0);
    conv2d_187_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_187_weights_array.data = AI_PTR(g_network_weights_map[225] + 0);
    conv2d_187_weights_array.data_start = AI_PTR(g_network_weights_map[225] + 0);
    conv2d_187_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_187_bias_array.data = AI_PTR(g_network_weights_map[226] + 0);
    conv2d_187_bias_array.data_start = AI_PTR(g_network_weights_map[226] + 0);
    conv2d_188_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_188_weights_array.data = AI_PTR(g_network_weights_map[227] + 0);
    conv2d_188_weights_array.data_start = AI_PTR(g_network_weights_map[227] + 0);
    conv2d_188_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_188_bias_array.data = AI_PTR(g_network_weights_map[228] + 0);
    conv2d_188_bias_array.data_start = AI_PTR(g_network_weights_map[228] + 0);
    conv2d_189_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_189_weights_array.data = AI_PTR(g_network_weights_map[229] + 0);
    conv2d_189_weights_array.data_start = AI_PTR(g_network_weights_map[229] + 0);
    conv2d_189_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_189_bias_array.data = AI_PTR(g_network_weights_map[230] + 0);
    conv2d_189_bias_array.data_start = AI_PTR(g_network_weights_map[230] + 0);
    conv2d_190_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_190_weights_array.data = AI_PTR(g_network_weights_map[231] + 0);
    conv2d_190_weights_array.data_start = AI_PTR(g_network_weights_map[231] + 0);
    conv2d_190_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_190_bias_array.data = AI_PTR(g_network_weights_map[232] + 0);
    conv2d_190_bias_array.data_start = AI_PTR(g_network_weights_map[232] + 0);
    conv2d_191_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_191_weights_array.data = AI_PTR(g_network_weights_map[233] + 0);
    conv2d_191_weights_array.data_start = AI_PTR(g_network_weights_map[233] + 0);
    conv2d_191_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_191_bias_array.data = AI_PTR(g_network_weights_map[234] + 0);
    conv2d_191_bias_array.data_start = AI_PTR(g_network_weights_map[234] + 0);
    conv2d_192_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_192_weights_array.data = AI_PTR(g_network_weights_map[235] + 0);
    conv2d_192_weights_array.data_start = AI_PTR(g_network_weights_map[235] + 0);
    conv2d_192_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_192_bias_array.data = AI_PTR(g_network_weights_map[236] + 0);
    conv2d_192_bias_array.data_start = AI_PTR(g_network_weights_map[236] + 0);
    conv2d_193_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_193_weights_array.data = AI_PTR(g_network_weights_map[237] + 0);
    conv2d_193_weights_array.data_start = AI_PTR(g_network_weights_map[237] + 0);
    conv2d_193_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_193_bias_array.data = AI_PTR(g_network_weights_map[238] + 0);
    conv2d_193_bias_array.data_start = AI_PTR(g_network_weights_map[238] + 0);
    conv2d_194_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_194_weights_array.data = AI_PTR(g_network_weights_map[239] + 0);
    conv2d_194_weights_array.data_start = AI_PTR(g_network_weights_map[239] + 0);
    conv2d_194_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_194_bias_array.data = AI_PTR(g_network_weights_map[240] + 0);
    conv2d_194_bias_array.data_start = AI_PTR(g_network_weights_map[240] + 0);
    conv2d_195_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_195_weights_array.data = AI_PTR(g_network_weights_map[241] + 0);
    conv2d_195_weights_array.data_start = AI_PTR(g_network_weights_map[241] + 0);
    conv2d_195_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_195_bias_array.data = AI_PTR(g_network_weights_map[242] + 0);
    conv2d_195_bias_array.data_start = AI_PTR(g_network_weights_map[242] + 0);
    conv2d_203_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_203_weights_array.data = AI_PTR(g_network_weights_map[243] + 0);
    conv2d_203_weights_array.data_start = AI_PTR(g_network_weights_map[243] + 0);
    conv2d_203_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_203_bias_array.data = AI_PTR(g_network_weights_map[244] + 0);
    conv2d_203_bias_array.data_start = AI_PTR(g_network_weights_map[244] + 0);
    conv2d_204_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_204_weights_array.data = AI_PTR(g_network_weights_map[245] + 0);
    conv2d_204_weights_array.data_start = AI_PTR(g_network_weights_map[245] + 0);
    conv2d_204_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_204_bias_array.data = AI_PTR(g_network_weights_map[246] + 0);
    conv2d_204_bias_array.data_start = AI_PTR(g_network_weights_map[246] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 124403144,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x5924a100,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_network_data_params_get(&params) != true) {
    err = ai_network_get_error(*network);
    return err;
  }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_network_init(*network, &params) != true) {
    err = ai_network_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

