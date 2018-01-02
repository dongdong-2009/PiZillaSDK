################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/piziot_core_cms/piziot_core_cms.c 

OBJS += \
./src/piziot_core_cms/piziot_core_cms.o 

C_DEPS += \
./src/piziot_core_cms/piziot_core_cms.d 


# Each subdirectory must supply rules for building sources it contributes
src/piziot_core_cms/%.o: ../src/piziot_core_cms/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../BCM28XX/package_src/raspberrypi_tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__ -I../../../../../BCM28XX/package_src/raspberrypi_tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


