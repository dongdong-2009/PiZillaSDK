################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/pizcms/pizcms.c \
../src/pizcms/pizcms_main.c \
../src/pizcms/pizcms_setting.c 

OBJS += \
./src/pizcms/pizcms.o \
./src/pizcms/pizcms_main.o \
./src/pizcms/pizcms_setting.o 

C_DEPS += \
./src/pizcms/pizcms.d \
./src/pizcms/pizcms_main.d \
./src/pizcms/pizcms_setting.d 


# Each subdirectory must supply rules for building sources it contributes
src/pizcms/%.o: ../src/pizcms/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../RTL8197/package_src/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/bin/rsdk-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__ -I../../../../../RTL8197/package_src/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


