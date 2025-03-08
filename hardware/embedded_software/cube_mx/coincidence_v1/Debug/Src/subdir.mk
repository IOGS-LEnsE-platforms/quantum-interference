################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/lptim.c \
../Src/main.c \
../Src/stm32g4xx_hal_msp.c \
../Src/stm32g4xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32g4xx.c \
../Src/tim.c \
../Src/usart.c 

OBJS += \
./Src/gpio.o \
./Src/lptim.o \
./Src/main.o \
./Src/stm32g4xx_hal_msp.o \
./Src/stm32g4xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32g4xx.o \
./Src/tim.o \
./Src/usart.o 

C_DEPS += \
./Src/gpio.d \
./Src/lptim.d \
./Src/main.d \
./Src/stm32g4xx_hal_msp.d \
./Src/stm32g4xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32g4xx.d \
./Src/tim.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Inc -IC:/Users/julie/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/julie/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/julie/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.1/Drivers/CMSIS/Device/ST/STM32G4xx/Include -IC:/Users/julie/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/lptim.cyclo ./Src/lptim.d ./Src/lptim.o ./Src/lptim.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32g4xx_hal_msp.cyclo ./Src/stm32g4xx_hal_msp.d ./Src/stm32g4xx_hal_msp.o ./Src/stm32g4xx_hal_msp.su ./Src/stm32g4xx_it.cyclo ./Src/stm32g4xx_it.d ./Src/stm32g4xx_it.o ./Src/stm32g4xx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32g4xx.cyclo ./Src/system_stm32g4xx.d ./Src/system_stm32g4xx.o ./Src/system_stm32g4xx.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su ./Src/usart.cyclo ./Src/usart.d ./Src/usart.o ./Src/usart.su

.PHONY: clean-Src

