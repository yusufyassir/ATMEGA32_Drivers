################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/7_SEG/Seg_Program.c 

OBJS += \
./HAL/7_SEG/Seg_Program.o 

C_DEPS += \
./HAL/7_SEG/Seg_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/7_SEG/%.o: ../HAL/7_SEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\sector-5\ATMEGA32_Drivers\MCAL\DIO" -I"D:\sector-5\ATMEGA32_Drivers\MCAL\ADC" -I"D:\sector-5\ATMEGA32_Drivers\HAL\LCD" -I"D:\sector-5\ATMEGA32_Drivers\HAL\7_SEG" -I"D:\sector-5\ATMEGA32_Drivers\COMMON" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


