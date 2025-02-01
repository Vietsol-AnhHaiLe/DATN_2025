################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/STM32H747I-DISCO/STM32CubeIDE/startup_cm4.s \
H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/STM32H747I-DISCO/STM32CubeIDE/startup_stm32h747xx.s 

OBJS += \
./Application/STM32CubeIDE/startup_cm4.o \
./Application/STM32CubeIDE/startup_stm32h747xx.o 

S_DEPS += \
./Application/STM32CubeIDE/startup_cm4.d \
./Application/STM32CubeIDE/startup_stm32h747xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/STM32CubeIDE/startup_cm4.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/STM32H747I-DISCO/STM32CubeIDE/startup_cm4.s Application/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Application/STM32CubeIDE/startup_stm32h747xx.o: H:/stm32ai-modelzoo-2.1.0/stm32ai_application_code/object_detection/Application/STM32H747I-DISCO/STM32CubeIDE/startup_stm32h747xx.s Application/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-STM32CubeIDE

clean-Application-2f-STM32CubeIDE:
	-$(RM) ./Application/STM32CubeIDE/startup_cm4.d ./Application/STM32CubeIDE/startup_cm4.o ./Application/STM32CubeIDE/startup_stm32h747xx.d ./Application/STM32CubeIDE/startup_stm32h747xx.o

.PHONY: clean-Application-2f-STM32CubeIDE

