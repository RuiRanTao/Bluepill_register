################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/delay.c \
../Src/key.c \
../Src/led.c \
../Src/main.c \
../Src/stm32f10x_gpio.c \
../Src/sys.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/usart.c 

OBJS += \
./Src/delay.o \
./Src/key.o \
./Src/led.o \
./Src/main.o \
./Src/stm32f10x_gpio.o \
./Src/sys.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/usart.o 

C_DEPS += \
./Src/delay.d \
./Src/key.d \
./Src/led.d \
./Src/main.d \
./Src/stm32f10x_gpio.d \
./Src/sys.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx '-DSTM32F10X_MD,USE_STDPERIPH_DRIVER' -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/delay.d ./Src/delay.o ./Src/delay.su ./Src/key.d ./Src/key.o ./Src/key.su ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32f10x_gpio.d ./Src/stm32f10x_gpio.o ./Src/stm32f10x_gpio.su ./Src/sys.d ./Src/sys.o ./Src/sys.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/usart.d ./Src/usart.o ./Src/usart.su

.PHONY: clean-Src

