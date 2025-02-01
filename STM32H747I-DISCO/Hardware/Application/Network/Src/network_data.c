/**
  ******************************************************************************
  * @file    network_data.c
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
#include "network_data.h"
#include "ai_platform_interface.h"

AI_API_DECLARE_BEGIN
ai_buffer g_network_data_map_activations[AI_NETWORK_DATA_ACTIVATIONS_COUNT] = {
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 13640, 1, 1),
    13640, NULL, 0x0),    /* DTCMRAM */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 340008, 1, 1),
    340008, NULL, 0x0),    /* AXIRAM */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 451632, 1, 1),
    451632, NULL, 0xd0000000),    /* SDRAM */
  };
ai_buffer g_network_data_map_weights[AI_NETWORK_DATA_WEIGHTS_COUNT] = {
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 15380, 1, 1),
    15380, NULL, s_network_concat_217_const_array_u64),   /* concat_217_const_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 432, 1, 1),
    432, NULL, s_network_conv2d_1_weights_array_u64),   /* conv2d_1_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 64, 1, 1),
    64, NULL, s_network_conv2d_1_bias_array_u64),   /* conv2d_1_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 144, 1, 1),
    144, NULL, s_network_conv2d_2_weights_array_u64),   /* conv2d_2_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 64, 1, 1),
    64, NULL, s_network_conv2d_2_bias_array_u64),   /* conv2d_2_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 128, 1, 1),
    128, NULL, s_network_conv2d_3_weights_array_u64),   /* conv2d_3_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 32, 1, 1),
    32, NULL, s_network_conv2d_3_bias_array_u64),   /* conv2d_3_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_4_weights_array_u64),   /* conv2d_4_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_4_bias_array_u64),   /* conv2d_4_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 432, 1, 1),
    432, NULL, s_network_conv2d_6_weights_array_u64),   /* conv2d_6_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_6_bias_array_u64),   /* conv2d_6_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_7_weights_array_u64),   /* conv2d_7_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 32, 1, 1),
    32, NULL, s_network_conv2d_7_bias_array_u64),   /* conv2d_7_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_8_weights_array_u64),   /* conv2d_8_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_8_bias_array_u64),   /* conv2d_8_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 432, 1, 1),
    432, NULL, s_network_conv2d_9_weights_array_u64),   /* conv2d_9_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_9_bias_array_u64),   /* conv2d_9_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_10_weights_array_u64),   /* conv2d_10_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 32, 1, 1),
    32, NULL, s_network_conv2d_10_bias_array_u64),   /* conv2d_10_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_12_weights_array_u64),   /* conv2d_12_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_12_bias_array_u64),   /* conv2d_12_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 432, 1, 1),
    432, NULL, s_network_conv2d_14_weights_array_u64),   /* conv2d_14_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 192, 1, 1),
    192, NULL, s_network_conv2d_14_bias_array_u64),   /* conv2d_14_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_15_weights_array_u64),   /* conv2d_15_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 64, 1, 1),
    64, NULL, s_network_conv2d_15_bias_array_u64),   /* conv2d_15_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1536, 1, 1),
    1536, NULL, s_network_conv2d_16_weights_array_u64),   /* conv2d_16_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_16_bias_array_u64),   /* conv2d_16_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 864, 1, 1),
    864, NULL, s_network_conv2d_17_weights_array_u64),   /* conv2d_17_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_17_bias_array_u64),   /* conv2d_17_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1536, 1, 1),
    1536, NULL, s_network_conv2d_18_weights_array_u64),   /* conv2d_18_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 64, 1, 1),
    64, NULL, s_network_conv2d_18_bias_array_u64),   /* conv2d_18_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1536, 1, 1),
    1536, NULL, s_network_conv2d_20_weights_array_u64),   /* conv2d_20_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_20_bias_array_u64),   /* conv2d_20_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 864, 1, 1),
    864, NULL, s_network_conv2d_21_weights_array_u64),   /* conv2d_21_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_21_bias_array_u64),   /* conv2d_21_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1536, 1, 1),
    1536, NULL, s_network_conv2d_22_weights_array_u64),   /* conv2d_22_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 64, 1, 1),
    64, NULL, s_network_conv2d_22_bias_array_u64),   /* conv2d_22_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2048, 1, 1),
    2048, NULL, s_network_conv2d_182_weights_array_u64),   /* conv2d_182_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_182_bias_array_u64),   /* conv2d_182_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1536, 1, 1),
    1536, NULL, s_network_conv2d_24_weights_array_u64),   /* conv2d_24_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_24_bias_array_u64),   /* conv2d_24_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 864, 1, 1),
    864, NULL, s_network_conv2d_26_weights_array_u64),   /* conv2d_26_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, s_network_conv2d_26_bias_array_u64),   /* conv2d_26_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2304, 1, 1),
    2304, NULL, s_network_conv2d_27_weights_array_u64),   /* conv2d_27_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 96, 1, 1),
    96, NULL, s_network_conv2d_27_bias_array_u64),   /* conv2d_27_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_28_weights_array_u64),   /* conv2d_28_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_28_bias_array_u64),   /* conv2d_28_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1296, 1, 1),
    1296, NULL, s_network_conv2d_29_weights_array_u64),   /* conv2d_29_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_29_bias_array_u64),   /* conv2d_29_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_30_weights_array_u64),   /* conv2d_30_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 96, 1, 1),
    96, NULL, s_network_conv2d_30_bias_array_u64),   /* conv2d_30_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_32_weights_array_u64),   /* conv2d_32_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_32_bias_array_u64),   /* conv2d_32_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1296, 1, 1),
    1296, NULL, s_network_conv2d_33_weights_array_u64),   /* conv2d_33_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_33_bias_array_u64),   /* conv2d_33_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_34_weights_array_u64),   /* conv2d_34_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 96, 1, 1),
    96, NULL, s_network_conv2d_34_bias_array_u64),   /* conv2d_34_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_36_weights_array_u64),   /* conv2d_36_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_36_bias_array_u64),   /* conv2d_36_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1296, 1, 1),
    1296, NULL, s_network_conv2d_37_weights_array_u64),   /* conv2d_37_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_37_bias_array_u64),   /* conv2d_37_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_38_weights_array_u64),   /* conv2d_38_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 96, 1, 1),
    96, NULL, s_network_conv2d_38_bias_array_u64),   /* conv2d_38_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3456, 1, 1),
    3456, NULL, s_network_conv2d_40_weights_array_u64),   /* conv2d_40_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_40_bias_array_u64),   /* conv2d_40_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1296, 1, 1),
    1296, NULL, s_network_conv2d_41_weights_array_u64),   /* conv2d_41_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 576, 1, 1),
    576, NULL, s_network_conv2d_41_bias_array_u64),   /* conv2d_41_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 4608, 1, 1),
    4608, NULL, s_network_conv2d_42_weights_array_u64),   /* conv2d_42_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 128, 1, 1),
    128, NULL, s_network_conv2d_42_bias_array_u64),   /* conv2d_42_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6144, 1, 1),
    6144, NULL, s_network_conv2d_43_weights_array_u64),   /* conv2d_43_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_43_bias_array_u64),   /* conv2d_43_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1728, 1, 1),
    1728, NULL, s_network_conv2d_44_weights_array_u64),   /* conv2d_44_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_44_bias_array_u64),   /* conv2d_44_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6144, 1, 1),
    6144, NULL, s_network_conv2d_45_weights_array_u64),   /* conv2d_45_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 128, 1, 1),
    128, NULL, s_network_conv2d_45_bias_array_u64),   /* conv2d_45_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6144, 1, 1),
    6144, NULL, s_network_conv2d_47_weights_array_u64),   /* conv2d_47_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_47_bias_array_u64),   /* conv2d_47_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1728, 1, 1),
    1728, NULL, s_network_conv2d_48_weights_array_u64),   /* conv2d_48_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_48_bias_array_u64),   /* conv2d_48_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6144, 1, 1),
    6144, NULL, s_network_conv2d_49_weights_array_u64),   /* conv2d_49_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 128, 1, 1),
    128, NULL, s_network_conv2d_49_bias_array_u64),   /* conv2d_49_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 4096, 1, 1),
    4096, NULL, s_network_conv2d_151_weights_array_u64),   /* conv2d_151_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_151_bias_array_u64),   /* conv2d_151_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6144, 1, 1),
    6144, NULL, s_network_conv2d_51_weights_array_u64),   /* conv2d_51_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_51_bias_array_u64),   /* conv2d_51_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1728, 1, 1),
    1728, NULL, s_network_conv2d_53_weights_array_u64),   /* conv2d_53_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, s_network_conv2d_53_bias_array_u64),   /* conv2d_53_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 10752, 1, 1),
    10752, NULL, s_network_conv2d_54_weights_array_u64),   /* conv2d_54_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 224, 1, 1),
    224, NULL, s_network_conv2d_54_bias_array_u64),   /* conv2d_54_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 18816, 1, 1),
    18816, NULL, s_network_conv2d_55_weights_array_u64),   /* conv2d_55_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_55_bias_array_u64),   /* conv2d_55_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3024, 1, 1),
    3024, NULL, s_network_conv2d_56_weights_array_u64),   /* conv2d_56_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_56_bias_array_u64),   /* conv2d_56_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 18816, 1, 1),
    18816, NULL, s_network_conv2d_57_weights_array_u64),   /* conv2d_57_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 224, 1, 1),
    224, NULL, s_network_conv2d_57_bias_array_u64),   /* conv2d_57_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 18816, 1, 1),
    18816, NULL, s_network_conv2d_59_weights_array_u64),   /* conv2d_59_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_59_bias_array_u64),   /* conv2d_59_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3024, 1, 1),
    3024, NULL, s_network_conv2d_60_weights_array_u64),   /* conv2d_60_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_60_bias_array_u64),   /* conv2d_60_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 18816, 1, 1),
    18816, NULL, s_network_conv2d_61_weights_array_u64),   /* conv2d_61_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 224, 1, 1),
    224, NULL, s_network_conv2d_61_bias_array_u64),   /* conv2d_61_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 18816, 1, 1),
    18816, NULL, s_network_conv2d_63_weights_array_u64),   /* conv2d_63_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_63_bias_array_u64),   /* conv2d_63_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3024, 1, 1),
    3024, NULL, s_network_conv2d_64_weights_array_u64),   /* conv2d_64_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1344, 1, 1),
    1344, NULL, s_network_conv2d_64_bias_array_u64),   /* conv2d_64_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 37632, 1, 1),
    37632, NULL, s_network_conv2d_65_weights_array_u64),   /* conv2d_65_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 448, 1, 1),
    448, NULL, s_network_conv2d_65_bias_array_u64),   /* conv2d_65_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 143360, 1, 1),
    143360, NULL, s_network_conv2d_66_weights_array_u64),   /* conv2d_66_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 5120, 1, 1),
    5120, NULL, s_network_conv2d_66_bias_array_u64),   /* conv2d_66_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 163840, 1, 1),
    163840, NULL, s_network_conv2d_67_weights_array_u64),   /* conv2d_67_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_67_bias_array_u64),   /* conv2d_67_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_68_weights_array_u64),   /* conv2d_68_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_68_bias_array_u64),   /* conv2d_68_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_69_weights_array_u64),   /* conv2d_69_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_69_bias_array_u64),   /* conv2d_69_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_70_weights_array_u64),   /* conv2d_70_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_70_bias_array_u64),   /* conv2d_70_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_71_weights_array_u64),   /* conv2d_71_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_71_bias_array_u64),   /* conv2d_71_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_72_weights_array_u64),   /* conv2d_72_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_72_bias_array_u64),   /* conv2d_72_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_73_weights_array_u64),   /* conv2d_73_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_73_bias_array_u64),   /* conv2d_73_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_74_weights_array_u64),   /* conv2d_74_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_74_bias_array_u64),   /* conv2d_74_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_75_weights_array_u64),   /* conv2d_75_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_75_bias_array_u64),   /* conv2d_75_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_76_weights_array_u64),   /* conv2d_76_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_76_bias_array_u64),   /* conv2d_76_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3200, 1, 1),
    3200, NULL, s_network_conv2d_77_weights_array_u64),   /* conv2d_77_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 100, 1, 1),
    100, NULL, s_network_conv2d_77_bias_array_u64),   /* conv2d_77_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_82_weights_array_u64),   /* conv2d_82_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_82_bias_array_u64),   /* conv2d_82_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2560, 1, 1),
    2560, NULL, s_network_conv2d_83_weights_array_u64),   /* conv2d_83_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 80, 1, 1),
    80, NULL, s_network_conv2d_83_bias_array_u64),   /* conv2d_83_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_94_weights_array_u64),   /* conv2d_94_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_94_bias_array_u64),   /* conv2d_94_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_95_weights_array_u64),   /* conv2d_95_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_95_bias_array_u64),   /* conv2d_95_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_96_weights_array_u64),   /* conv2d_96_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_96_bias_array_u64),   /* conv2d_96_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_97_weights_array_u64),   /* conv2d_97_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_97_bias_array_u64),   /* conv2d_97_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_98_weights_array_u64),   /* conv2d_98_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_98_bias_array_u64),   /* conv2d_98_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_99_weights_array_u64),   /* conv2d_99_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_99_bias_array_u64),   /* conv2d_99_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_100_weights_array_u64),   /* conv2d_100_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_100_bias_array_u64),   /* conv2d_100_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_101_weights_array_u64),   /* conv2d_101_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_101_bias_array_u64),   /* conv2d_101_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_102_weights_array_u64),   /* conv2d_102_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_102_bias_array_u64),   /* conv2d_102_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_103_weights_array_u64),   /* conv2d_103_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_103_bias_array_u64),   /* conv2d_103_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_104_weights_array_u64),   /* conv2d_104_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_104_bias_array_u64),   /* conv2d_104_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3200, 1, 1),
    3200, NULL, s_network_conv2d_105_weights_array_u64),   /* conv2d_105_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 100, 1, 1),
    100, NULL, s_network_conv2d_105_bias_array_u64),   /* conv2d_105_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_110_weights_array_u64),   /* conv2d_110_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_110_bias_array_u64),   /* conv2d_110_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2560, 1, 1),
    2560, NULL, s_network_conv2d_111_weights_array_u64),   /* conv2d_111_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 80, 1, 1),
    80, NULL, s_network_conv2d_111_bias_array_u64),   /* conv2d_111_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_122_weights_array_u64),   /* conv2d_122_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_122_bias_array_u64),   /* conv2d_122_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 14592, 1, 1),
    14592, NULL, s_network_conv2d_123_weights_array_u64),   /* conv2d_123_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 456, 1, 1),
    456, NULL, s_network_conv2d_123_bias_array_u64),   /* conv2d_123_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1028, 1, 1),
    1028, NULL, s_network_conv2d_124_weights_array_u64),   /* conv2d_124_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 456, 1, 1),
    456, NULL, s_network_conv2d_124_bias_array_u64),   /* conv2d_124_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 11856, 1, 1),
    11856, NULL, s_network_conv2d_125_weights_array_u64),   /* conv2d_125_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 416, 1, 1),
    416, NULL, s_network_conv2d_125_bias_array_u64),   /* conv2d_125_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 936, 1, 1),
    936, NULL, s_network_conv2d_126_weights_array_u64),   /* conv2d_126_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 416, 1, 1),
    416, NULL, s_network_conv2d_126_bias_array_u64),   /* conv2d_126_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 13312, 1, 1),
    13312, NULL, s_network_conv2d_127_weights_array_u64),   /* conv2d_127_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_127_bias_array_u64),   /* conv2d_127_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_128_weights_array_u64),   /* conv2d_128_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_128_bias_array_u64),   /* conv2d_128_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_129_weights_array_u64),   /* conv2d_129_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_129_bias_array_u64),   /* conv2d_129_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_130_weights_array_u64),   /* conv2d_130_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_130_bias_array_u64),   /* conv2d_130_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_131_weights_array_u64),   /* conv2d_131_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_131_bias_array_u64),   /* conv2d_131_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_132_weights_array_u64),   /* conv2d_132_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_132_bias_array_u64),   /* conv2d_132_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3200, 1, 1),
    3200, NULL, s_network_conv2d_133_weights_array_u64),   /* conv2d_133_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 100, 1, 1),
    100, NULL, s_network_conv2d_133_bias_array_u64),   /* conv2d_133_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_138_weights_array_u64),   /* conv2d_138_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_138_bias_array_u64),   /* conv2d_138_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2560, 1, 1),
    2560, NULL, s_network_conv2d_139_weights_array_u64),   /* conv2d_139_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 80, 1, 1),
    80, NULL, s_network_conv2d_139_bias_array_u64),   /* conv2d_139_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_153_weights_array_u64),   /* conv2d_153_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_153_bias_array_u64),   /* conv2d_153_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_154_weights_array_u64),   /* conv2d_154_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_154_bias_array_u64),   /* conv2d_154_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_155_weights_array_u64),   /* conv2d_155_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_155_bias_array_u64),   /* conv2d_155_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_156_weights_array_u64),   /* conv2d_156_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_156_bias_array_u64),   /* conv2d_156_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_157_weights_array_u64),   /* conv2d_157_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_157_bias_array_u64),   /* conv2d_157_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_158_weights_array_u64),   /* conv2d_158_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_158_bias_array_u64),   /* conv2d_158_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_159_weights_array_u64),   /* conv2d_159_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_159_bias_array_u64),   /* conv2d_159_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_160_weights_array_u64),   /* conv2d_160_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_160_bias_array_u64),   /* conv2d_160_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_161_weights_array_u64),   /* conv2d_161_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_161_bias_array_u64),   /* conv2d_161_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_162_weights_array_u64),   /* conv2d_162_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_162_bias_array_u64),   /* conv2d_162_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_163_weights_array_u64),   /* conv2d_163_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_163_bias_array_u64),   /* conv2d_163_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3200, 1, 1),
    3200, NULL, s_network_conv2d_164_weights_array_u64),   /* conv2d_164_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 100, 1, 1),
    100, NULL, s_network_conv2d_164_bias_array_u64),   /* conv2d_164_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_169_weights_array_u64),   /* conv2d_169_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_169_bias_array_u64),   /* conv2d_169_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2560, 1, 1),
    2560, NULL, s_network_conv2d_170_weights_array_u64),   /* conv2d_170_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 80, 1, 1),
    80, NULL, s_network_conv2d_170_bias_array_u64),   /* conv2d_170_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_184_weights_array_u64),   /* conv2d_184_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_184_bias_array_u64),   /* conv2d_184_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_185_weights_array_u64),   /* conv2d_185_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_185_bias_array_u64),   /* conv2d_185_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_186_weights_array_u64),   /* conv2d_186_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_186_bias_array_u64),   /* conv2d_186_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_187_weights_array_u64),   /* conv2d_187_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_187_bias_array_u64),   /* conv2d_187_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_188_weights_array_u64),   /* conv2d_188_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_188_bias_array_u64),   /* conv2d_188_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_189_weights_array_u64),   /* conv2d_189_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_189_bias_array_u64),   /* conv2d_189_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_190_weights_array_u64),   /* conv2d_190_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_190_bias_array_u64),   /* conv2d_190_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_191_weights_array_u64),   /* conv2d_191_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_191_bias_array_u64),   /* conv2d_191_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_192_weights_array_u64),   /* conv2d_192_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_192_bias_array_u64),   /* conv2d_192_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16384, 1, 1),
    16384, NULL, s_network_conv2d_193_weights_array_u64),   /* conv2d_193_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_193_bias_array_u64),   /* conv2d_193_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_194_weights_array_u64),   /* conv2d_194_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_194_bias_array_u64),   /* conv2d_194_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3200, 1, 1),
    3200, NULL, s_network_conv2d_195_weights_array_u64),   /* conv2d_195_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 100, 1, 1),
    100, NULL, s_network_conv2d_195_bias_array_u64),   /* conv2d_195_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1152, 1, 1),
    1152, NULL, s_network_conv2d_203_weights_array_u64),   /* conv2d_203_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, s_network_conv2d_203_bias_array_u64),   /* conv2d_203_bias_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2560, 1, 1),
    2560, NULL, s_network_conv2d_204_weights_array_u64),   /* conv2d_204_weights_array */
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 80, 1, 1),
    80, NULL, s_network_conv2d_204_bias_array_u64),   /* conv2d_204_bias_array */
  };


/*!
 * @brief Get network activations buffer initialized struct.
 * @ingroup network_data
 * @param[in] ptr a pointer to the activations array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_network_data_activations_buffer_get(const ai_handle ptr)
{
  ai_buffer buf = AI_BUFFER_INIT(
    AI_FLAG_NONE, AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, AI_NETWORK_DATA_ACTIVATIONS_SIZE, 1, AI_NETWORK_DATA_ACTIVATIONS_COUNT),
    AI_NETWORK_DATA_ACTIVATIONS_SIZE,
    NULL, ptr);
  return buf;
}

/*!
 * @brief Get network weights buffer initialized struct.
 * @ingroup network_data
 * @param[in] ptr a pointer to the weights array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_network_data_weights_buffer_get(const ai_handle ptr)
{
  ai_buffer buf = AI_BUFFER_INIT(
    AI_FLAG_NONE, AI_BUFFER_FORMAT_U8|AI_BUFFER_FMT_FLAG_CONST,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, AI_NETWORK_DATA_WEIGHTS_SIZE, 1, AI_NETWORK_DATA_WEIGHTS_COUNT),
    AI_NETWORK_DATA_WEIGHTS_SIZE,
    NULL, ptr);
  return buf;
}


/*!
 * @brief Get network weights array pointer as a handle ptr.
 * @ingroup network_data
 * @return a ai_handle pointer to the weights array
 */
AI_DEPRECATED
AI_API_ENTRY
ai_handle ai_network_data_weights_get(void)
{
  return AI_HANDLE_PTR(g_network_weights_table);

}


/*!
 * @brief Get network params configuration data structure.
 * @ingroup network_data
 * @return true if a valid configuration is present, false otherwise
 */
AI_API_ENTRY
ai_bool ai_network_data_params_get(ai_network_params* params)
{
  if (!params) return false;
  
  const ai_buffer_array map_activations = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_DATA_ACTIVATIONS_COUNT, g_network_data_map_activations);
  
  const ai_buffer_array map_weights = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_DATA_WEIGHTS_COUNT, g_network_data_map_weights);

  return ai_platform_bind_network_params(params, &map_weights, &map_activations);
}


AI_API_DECLARE_END
