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
	../../../../../HI3518E/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__ -I../../../../../HI3518E/package_src/arm-hisiv100-linux/target/armv5te_soft/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


