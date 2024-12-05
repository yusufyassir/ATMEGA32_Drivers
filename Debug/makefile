################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/7_SEG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ATMEGA32_Drivers.lss \

FLASH_IMAGE += \
ATMEGA32_Drivers.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATMEGA32_Drivers.elf secondary-outputs

# Tool invocations
ATMEGA32_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATMEGA32_Drivers.map -mmcu=atmega32 -o "ATMEGA32_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATMEGA32_Drivers.lss: ATMEGA32_Drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATMEGA32_Drivers.elf  >"ATMEGA32_Drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATMEGA32_Drivers.hex: ATMEGA32_Drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATMEGA32_Drivers.elf  "ATMEGA32_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATMEGA32_Drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATMEGA32_Drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATMEGA32_Drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
