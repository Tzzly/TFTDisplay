################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STemWin/Config/GUIConf.c \
../Drivers/STemWin/Config/GUIDRV_Template.c \
../Drivers/STemWin/Config/LCDConf.c \
../Drivers/STemWin/Config/LCD_STM32F4.c \
../Drivers/STemWin/Config/SIMConf.c \
../Drivers/STemWin/Config/ts.c 

OBJS += \
./Drivers/STemWin/Config/GUIConf.o \
./Drivers/STemWin/Config/GUIDRV_Template.o \
./Drivers/STemWin/Config/LCDConf.o \
./Drivers/STemWin/Config/LCD_STM32F4.o \
./Drivers/STemWin/Config/SIMConf.o \
./Drivers/STemWin/Config/ts.o 

C_DEPS += \
./Drivers/STemWin/Config/GUIConf.d \
./Drivers/STemWin/Config/GUIDRV_Template.d \
./Drivers/STemWin/Config/LCDConf.d \
./Drivers/STemWin/Config/LCD_STM32F4.d \
./Drivers/STemWin/Config/SIMConf.d \
./Drivers/STemWin/Config/ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STemWin/Config/%.o: ../Drivers/STemWin/Config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -DSSD1289 -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/CMSIS/Include" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STemWin/inc" -I"C:/Users/twizz/OneDrive/Documents/GitHub/TFTDisplay/Drivers/STemWin/Config"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


