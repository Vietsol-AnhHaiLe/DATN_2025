/**
  ******************************************************************************
  * @file    network_data.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2024-12-18T12:18:59+0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H

#include "network_config.h"
#include "network_data_params.h"

AI_DEPRECATED
#define AI_NETWORK_DATA_ACTIVATIONS(ptr_)  \
  ai_network_data_activations_buffer_get(AI_HANDLE_PTR(ptr_))

AI_DEPRECATED
#define AI_NETWORK_DATA_WEIGHTS(ptr_)  \
  ai_network_data_weights_buffer_get(AI_HANDLE_PTR(ptr_))


AI_API_DECLARE_BEGIN


extern const ai_u64 s_network_concat_217_const_array_u64[1923];
extern const ai_u64 s_network_conv2d_1_weights_array_u64[54];
extern const ai_u64 s_network_conv2d_1_bias_array_u64[8];
extern const ai_u64 s_network_conv2d_2_weights_array_u64[18];
extern const ai_u64 s_network_conv2d_2_bias_array_u64[8];
extern const ai_u64 s_network_conv2d_3_weights_array_u64[16];
extern const ai_u64 s_network_conv2d_3_bias_array_u64[4];
extern const ai_u64 s_network_conv2d_4_weights_array_u64[48];
extern const ai_u64 s_network_conv2d_4_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_6_weights_array_u64[54];
extern const ai_u64 s_network_conv2d_6_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_7_weights_array_u64[48];
extern const ai_u64 s_network_conv2d_7_bias_array_u64[4];
extern const ai_u64 s_network_conv2d_8_weights_array_u64[48];
extern const ai_u64 s_network_conv2d_8_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_9_weights_array_u64[54];
extern const ai_u64 s_network_conv2d_9_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_10_weights_array_u64[48];
extern const ai_u64 s_network_conv2d_10_bias_array_u64[4];
extern const ai_u64 s_network_conv2d_12_weights_array_u64[48];
extern const ai_u64 s_network_conv2d_12_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_14_weights_array_u64[54];
extern const ai_u64 s_network_conv2d_14_bias_array_u64[24];
extern const ai_u64 s_network_conv2d_15_weights_array_u64[96];
extern const ai_u64 s_network_conv2d_15_bias_array_u64[8];
extern const ai_u64 s_network_conv2d_16_weights_array_u64[192];
extern const ai_u64 s_network_conv2d_16_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_17_weights_array_u64[108];
extern const ai_u64 s_network_conv2d_17_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_18_weights_array_u64[192];
extern const ai_u64 s_network_conv2d_18_bias_array_u64[8];
extern const ai_u64 s_network_conv2d_20_weights_array_u64[192];
extern const ai_u64 s_network_conv2d_20_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_21_weights_array_u64[108];
extern const ai_u64 s_network_conv2d_21_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_22_weights_array_u64[192];
extern const ai_u64 s_network_conv2d_22_bias_array_u64[8];
extern const ai_u64 s_network_conv2d_182_weights_array_u64[256];
extern const ai_u64 s_network_conv2d_182_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_24_weights_array_u64[192];
extern const ai_u64 s_network_conv2d_24_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_26_weights_array_u64[108];
extern const ai_u64 s_network_conv2d_26_bias_array_u64[48];
extern const ai_u64 s_network_conv2d_27_weights_array_u64[288];
extern const ai_u64 s_network_conv2d_27_bias_array_u64[12];
extern const ai_u64 s_network_conv2d_28_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_28_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_29_weights_array_u64[162];
extern const ai_u64 s_network_conv2d_29_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_30_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_30_bias_array_u64[12];
extern const ai_u64 s_network_conv2d_32_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_32_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_33_weights_array_u64[162];
extern const ai_u64 s_network_conv2d_33_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_34_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_34_bias_array_u64[12];
extern const ai_u64 s_network_conv2d_36_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_36_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_37_weights_array_u64[162];
extern const ai_u64 s_network_conv2d_37_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_38_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_38_bias_array_u64[12];
extern const ai_u64 s_network_conv2d_40_weights_array_u64[432];
extern const ai_u64 s_network_conv2d_40_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_41_weights_array_u64[162];
extern const ai_u64 s_network_conv2d_41_bias_array_u64[72];
extern const ai_u64 s_network_conv2d_42_weights_array_u64[576];
extern const ai_u64 s_network_conv2d_42_bias_array_u64[16];
extern const ai_u64 s_network_conv2d_43_weights_array_u64[768];
extern const ai_u64 s_network_conv2d_43_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_44_weights_array_u64[216];
extern const ai_u64 s_network_conv2d_44_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_45_weights_array_u64[768];
extern const ai_u64 s_network_conv2d_45_bias_array_u64[16];
extern const ai_u64 s_network_conv2d_47_weights_array_u64[768];
extern const ai_u64 s_network_conv2d_47_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_48_weights_array_u64[216];
extern const ai_u64 s_network_conv2d_48_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_49_weights_array_u64[768];
extern const ai_u64 s_network_conv2d_49_bias_array_u64[16];
extern const ai_u64 s_network_conv2d_151_weights_array_u64[512];
extern const ai_u64 s_network_conv2d_151_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_51_weights_array_u64[768];
extern const ai_u64 s_network_conv2d_51_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_53_weights_array_u64[216];
extern const ai_u64 s_network_conv2d_53_bias_array_u64[96];
extern const ai_u64 s_network_conv2d_54_weights_array_u64[1344];
extern const ai_u64 s_network_conv2d_54_bias_array_u64[28];
extern const ai_u64 s_network_conv2d_55_weights_array_u64[2352];
extern const ai_u64 s_network_conv2d_55_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_56_weights_array_u64[378];
extern const ai_u64 s_network_conv2d_56_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_57_weights_array_u64[2352];
extern const ai_u64 s_network_conv2d_57_bias_array_u64[28];
extern const ai_u64 s_network_conv2d_59_weights_array_u64[2352];
extern const ai_u64 s_network_conv2d_59_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_60_weights_array_u64[378];
extern const ai_u64 s_network_conv2d_60_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_61_weights_array_u64[2352];
extern const ai_u64 s_network_conv2d_61_bias_array_u64[28];
extern const ai_u64 s_network_conv2d_63_weights_array_u64[2352];
extern const ai_u64 s_network_conv2d_63_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_64_weights_array_u64[378];
extern const ai_u64 s_network_conv2d_64_bias_array_u64[168];
extern const ai_u64 s_network_conv2d_65_weights_array_u64[4704];
extern const ai_u64 s_network_conv2d_65_bias_array_u64[56];
extern const ai_u64 s_network_conv2d_66_weights_array_u64[17920];
extern const ai_u64 s_network_conv2d_66_bias_array_u64[640];
extern const ai_u64 s_network_conv2d_67_weights_array_u64[20480];
extern const ai_u64 s_network_conv2d_67_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_68_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_68_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_69_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_69_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_70_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_70_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_71_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_71_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_72_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_72_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_73_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_73_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_74_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_74_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_75_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_75_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_76_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_76_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_77_weights_array_u64[400];
extern const ai_u64 s_network_conv2d_77_bias_array_u64[13];
extern const ai_u64 s_network_conv2d_82_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_82_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_83_weights_array_u64[320];
extern const ai_u64 s_network_conv2d_83_bias_array_u64[10];
extern const ai_u64 s_network_conv2d_94_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_94_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_95_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_95_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_96_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_96_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_97_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_97_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_98_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_98_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_99_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_99_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_100_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_100_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_101_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_101_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_102_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_102_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_103_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_103_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_104_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_104_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_105_weights_array_u64[400];
extern const ai_u64 s_network_conv2d_105_bias_array_u64[13];
extern const ai_u64 s_network_conv2d_110_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_110_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_111_weights_array_u64[320];
extern const ai_u64 s_network_conv2d_111_bias_array_u64[10];
extern const ai_u64 s_network_conv2d_122_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_122_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_123_weights_array_u64[1824];
extern const ai_u64 s_network_conv2d_123_bias_array_u64[57];
extern const ai_u64 s_network_conv2d_124_weights_array_u64[129];
extern const ai_u64 s_network_conv2d_124_bias_array_u64[57];
extern const ai_u64 s_network_conv2d_125_weights_array_u64[1482];
extern const ai_u64 s_network_conv2d_125_bias_array_u64[52];
extern const ai_u64 s_network_conv2d_126_weights_array_u64[117];
extern const ai_u64 s_network_conv2d_126_bias_array_u64[52];
extern const ai_u64 s_network_conv2d_127_weights_array_u64[1664];
extern const ai_u64 s_network_conv2d_127_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_128_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_128_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_129_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_129_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_130_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_130_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_131_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_131_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_132_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_132_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_133_weights_array_u64[400];
extern const ai_u64 s_network_conv2d_133_bias_array_u64[13];
extern const ai_u64 s_network_conv2d_138_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_138_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_139_weights_array_u64[320];
extern const ai_u64 s_network_conv2d_139_bias_array_u64[10];
extern const ai_u64 s_network_conv2d_153_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_153_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_154_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_154_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_155_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_155_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_156_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_156_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_157_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_157_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_158_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_158_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_159_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_159_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_160_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_160_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_161_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_161_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_162_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_162_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_163_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_163_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_164_weights_array_u64[400];
extern const ai_u64 s_network_conv2d_164_bias_array_u64[13];
extern const ai_u64 s_network_conv2d_169_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_169_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_170_weights_array_u64[320];
extern const ai_u64 s_network_conv2d_170_bias_array_u64[10];
extern const ai_u64 s_network_conv2d_184_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_184_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_185_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_185_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_186_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_186_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_187_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_187_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_188_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_188_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_189_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_189_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_190_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_190_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_191_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_191_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_192_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_192_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_193_weights_array_u64[2048];
extern const ai_u64 s_network_conv2d_193_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_194_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_194_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_195_weights_array_u64[400];
extern const ai_u64 s_network_conv2d_195_bias_array_u64[13];
extern const ai_u64 s_network_conv2d_203_weights_array_u64[144];
extern const ai_u64 s_network_conv2d_203_bias_array_u64[64];
extern const ai_u64 s_network_conv2d_204_weights_array_u64[320];
extern const ai_u64 s_network_conv2d_204_bias_array_u64[10];



/*!
 * @brief Get network activations buffer initialized struct.
 * @ingroup network_data
 * @param[in] ptr a pointer to the activations array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_network_data_activations_buffer_get(const ai_handle ptr);

/*!
 * @brief Get network weights buffer initialized struct.
 * @ingroup network_data
 * @param[in] ptr a pointer to the weights array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_network_data_weights_buffer_get(const ai_handle ptr);

/*!
 * @brief Get network weights array pointer as a handle ptr.
 * @ingroup network_data
 * @return a ai_handle pointer to the weights array
 */
AI_DEPRECATED
AI_API_ENTRY
ai_handle ai_network_data_weights_get(void);


/*!
 * @brief Get network params configuration data structure.
 * @ingroup network_data
 * @return true if a valid configuration is present, false otherwise
 */
AI_API_ENTRY
ai_bool ai_network_data_params_get(ai_network_params* params);


AI_API_DECLARE_END

#endif /* NETWORK_DATA_H */

