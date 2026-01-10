################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PeripheralWrapper/tc275_Oled_Driver.c \
../PeripheralWrapper/tc275_SPI_Wrapper.c \
../PeripheralWrapper/tc275_led_app.c \
../PeripheralWrapper/tc275_uart_app.c 

C_DEPS += \
./PeripheralWrapper/tc275_Oled_Driver.d \
./PeripheralWrapper/tc275_SPI_Wrapper.d \
./PeripheralWrapper/tc275_led_app.d \
./PeripheralWrapper/tc275_uart_app.d 

OBJS += \
./PeripheralWrapper/tc275_Oled_Driver.o \
./PeripheralWrapper/tc275_SPI_Wrapper.o \
./PeripheralWrapper/tc275_led_app.o \
./PeripheralWrapper/tc275_uart_app.o 


# Each subdirectory must supply rules for building sources it contributes
PeripheralWrapper/%.o: ../PeripheralWrapper/%.c PeripheralWrapper/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/zobay/git/bubble_level/mes1_esw_mcs_project_bubble_level/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-PeripheralWrapper

clean-PeripheralWrapper:
	-$(RM) ./PeripheralWrapper/tc275_Oled_Driver.d ./PeripheralWrapper/tc275_Oled_Driver.o ./PeripheralWrapper/tc275_SPI_Wrapper.d ./PeripheralWrapper/tc275_SPI_Wrapper.o ./PeripheralWrapper/tc275_led_app.d ./PeripheralWrapper/tc275_led_app.o ./PeripheralWrapper/tc275_uart_app.d ./PeripheralWrapper/tc275_uart_app.o

.PHONY: clean-PeripheralWrapper

