################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/piziot_core_nas/piziot_core_nas.c 

OBJS += \
./src/piziot_core_nas/piziot_core_nas.o 

C_DEPS += \
./src/piziot_core_nas/piziot_core_nas.d 


# Each subdirectory must supply rules for building sources it contributes
src/piziot_core_nas/%.o: ../src/piziot_core_nas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__ -I/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


