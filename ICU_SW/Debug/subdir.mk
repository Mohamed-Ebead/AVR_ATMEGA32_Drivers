################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../EXT_INT_Prog.c \
../LCD_Prog.c \
../Timer0_Prog.c \
../Timer1_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./EXT_INT_Prog.o \
./LCD_Prog.o \
./Timer0_Prog.o \
./Timer1_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./EXT_INT_Prog.d \
./LCD_Prog.d \
./Timer0_Prog.d \
./Timer1_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


