################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.c 

OBJS += \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.o \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.o 

C_DEPS += \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.d \
./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.c Drivers/BSP/STM32H747I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H747I_DISCO

clean-Drivers-2f-BSP-2f-STM32H747I_DISCO:
	-$(RM) ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_bus.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_camera.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_lcd.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_qspi.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sd.su ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.cyclo ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.d ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.o ./Drivers/BSP/STM32H747I_DISCO/stm32h747i_discovery_sdram.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H747I_DISCO

