################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/stream_out/stream_out_main.c 

OBJS += \
./src/stream_out/stream_out_main.o 

C_DEPS += \
./src/stream_out/stream_out_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/stream_out/%.o: ../src/stream_out/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__ -D__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__ -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -m32 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


