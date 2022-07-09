################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
ping_pong.lss \

FLASH_IMAGE += \
ping_pong.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ping_pong.elf secondary-outputs

# Tool invocations
ping_pong.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ping_pong.map -mmcu=atmega32 -o "ping_pong.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ping_pong.lss: ping_pong.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ping_pong.elf  >"ping_pong.lss"
	@echo 'Finished building: $@'
	@echo ' '

ping_pong.hex: ping_pong.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ping_pong.elf  "ping_pong.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ping_pong.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ping_pong.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ping_pong.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
