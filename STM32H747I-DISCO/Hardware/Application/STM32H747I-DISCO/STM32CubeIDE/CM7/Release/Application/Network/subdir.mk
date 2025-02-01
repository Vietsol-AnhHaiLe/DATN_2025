################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network_data.c \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network_data_params.c 

OBJS += \
./Application/Network/network.o \
./Application/Network/network_data.o \
./Application/Network/network_data_params.o 

C_DEPS += \
./Application/Network/network.d \
./Application/Network/network_data.d \
./Application/Network/network_data_params.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Network/network.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network.c Application/Network/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Network/network_data.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network_data.c Application/Network/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Network/network_data_params.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/Network/Src/network_data_params.c Application/Network/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Network

clean-Application-2f-Network:
	-$(RM) ./Application/Network/network.cyclo ./Application/Network/network.d ./Application/Network/network.o ./Application/Network/network.su ./Application/Network/network_data.cyclo ./Application/Network/network_data.d ./Application/Network/network_data.o ./Application/Network/network_data.su ./Application/Network/network_data_params.cyclo ./Application/Network/network_data_params.d ./Application/Network/network_data_params.o ./Application/Network/network_data_params.su

.PHONY: clean-Application-2f-Network

