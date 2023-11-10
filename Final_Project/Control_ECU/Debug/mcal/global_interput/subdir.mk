################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/global_interput/global_interput.c 

OBJS += \
./mcal/global_interput/global_interput.o 

C_DEPS += \
./mcal/global_interput/global_interput.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/global_interput/%.o: ../mcal/global_interput/%.c mcal/global_interput/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


