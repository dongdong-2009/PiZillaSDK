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
	../../../../../HI3520D/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__ -I../../../../../HI3520D/package_src/arm-hisiv100-linux/target/armv7a_soft/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


