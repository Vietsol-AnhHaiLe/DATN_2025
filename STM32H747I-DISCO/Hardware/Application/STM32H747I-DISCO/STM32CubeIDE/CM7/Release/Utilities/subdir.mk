################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Utilities/lcd/stm32_lcd.c 

OBJS += \
./Utilities/stm32_lcd.o 

C_DEPS += \
./Utilities/stm32_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/stm32_lcd.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Utilities/lcd/stm32_lcd.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DSTM32_IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1U -DSTM32IPL -c -I../../../Inc/CM7 -I../../../../Network/Inc -I../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../Drivers/BSP/Components/Common -I../../../../../Drivers/BSP/Components/ov9655 -I../../../../../Drivers/BSP/Components/otm8009a -I../../../../../Drivers/BSP/Components/nt35510 -I../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../Utilities/Fonts -I../../../../../Utilities/lcd -I../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../Middlewares/ST/STM32_Objdetect_Postprocess/Inc -I../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../Drivers/CMSIS/Core/Include -I../../../../../Drivers/CMSIS/Core/DSP/Include -I../../../../../Drivers/BSP/STM32H747I-DISCO -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utilities

clean-Utilities:
	-$(RM) ./Utilities/stm32_lcd.cyclo ./Utilities/stm32_lcd.d ./Utilities/stm32_lcd.o ./Utilities/stm32_lcd.su

.PHONY: clean-Utilities

