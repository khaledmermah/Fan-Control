################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_motor.c \
../LM35.c \
../PWM.c \
../adc.c \
../gpio.c \
../icu.c \
../lcd.c \
../main.c 

OBJS += \
./DC_motor.o \
./LM35.o \
./PWM.o \
./adc.o \
./gpio.o \
./icu.o \
./lcd.o \
./main.o 

C_DEPS += \
./DC_motor.d \
./LM35.d \
./PWM.d \
./adc.d \
./gpio.d \
./icu.d \
./lcd.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


