################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_command.c \
../src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_main.c \
../src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_other.c 

OBJS += \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_command.o \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_main.o \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_other.o 

C_DEPS += \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_command.d \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_main.d \
./src/p2p/p2p_nas_channel_server_main/nas_data/p2p_nas_device_channel_other.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/p2p_nas_channel_server_main/nas_data/%.o: ../src/p2p/p2p_nas_channel_server_main/nas_data/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__ -I/usr/include -I../../../include -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


