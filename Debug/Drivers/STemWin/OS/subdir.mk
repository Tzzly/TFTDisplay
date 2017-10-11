################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STemWin/OS/GUI_X.c 

OBJS += \
./Drivers/STemWin/OS/GUI_X.o 

C_DEPS += \
./Drivers/STemWin/OS/GUI_X.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STemWin/OS/%.o: ../Drivers/STemWin/OS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -DSSD1289 -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/CMSIS/Include" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STemWin/inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STemWin/Config"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


