################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/eeprom/external_eeprom.c 

OBJS += \
./hal/eeprom/external_eeprom.o 

C_DEPS += \
./hal/eeprom/external_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
hal/eeprom/%.o: ../hal/eeprom/%.c hal/eeprom/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


