################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SPI_Drv/subdir.mk
-include DIO_DRV/subdir.mk
-include App/subdir.mk
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
SPI_Slave_Drv.lss \

FLASH_IMAGE += \
SPI_Slave_Drv.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_Slave_Drv.elf secondary-outputs

# Tool invocations
SPI_Slave_Drv.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_Slave_Drv.map -mmcu=atmega32 -o "SPI_Slave_Drv.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_Slave_Drv.lss: SPI_Slave_Drv.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_Slave_Drv.elf  >"SPI_Slave_Drv.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_Slave_Drv.hex: SPI_Slave_Drv.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_Slave_Drv.elf  "SPI_Slave_Drv.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_Slave_Drv.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_Slave_Drv.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_Slave_Drv.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
