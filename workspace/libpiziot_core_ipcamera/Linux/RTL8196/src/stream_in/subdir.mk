################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/stream_in/stream_in_emulator.c \
../src/stream_in/stream_in_main.c 

OBJS += \
./src/stream_in/stream_in_emulator.o \
./src/stream_in/stream_in_main.o 

C_DEPS += \
./src/stream_in/stream_in_emulator.d \
./src/stream_in/stream_in_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/stream_in/%.o: ../src/stream_in/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../RTL8196/package_src/mips-linux/bin/rsdk-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__ -D_XOPEN_SOURCE=500 -D_BSD_SOURCE -I../../../../../RTL8196/package_src/mips-linux/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


