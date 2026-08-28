################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SPI/SPI_General.c 

OBJS += \
./Core/Src/SPI/SPI_General.o 

C_DEPS += \
./Core/Src/SPI/SPI_General.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPI/%.o Core/Src/SPI/%.su Core/Src/SPI/%.cyclo: ../Core/Src/SPI/%.c Core/Src/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SPI

clean-Core-2f-Src-2f-SPI:
	-$(RM) ./Core/Src/SPI/SPI_General.cyclo ./Core/Src/SPI/SPI_General.d ./Core/Src/SPI/SPI_General.o ./Core/Src/SPI/SPI_General.su

.PHONY: clean-Core-2f-Src-2f-SPI

