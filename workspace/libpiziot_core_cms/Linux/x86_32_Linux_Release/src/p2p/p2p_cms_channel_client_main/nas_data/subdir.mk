################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_command.c \
../src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_main.c \
../src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_other.c 

OBJS += \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_command.o \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_main.o \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_other.o 

C_DEPS += \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_command.d \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_main.d \
./src/p2p/p2p_cms_channel_client_main/nas_data/p2p_cms_nas_other.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/p2p_cms_channel_client_main/nas_data/%.o: ../src/p2p/p2p_cms_channel_client_main/nas_data/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__ -D__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__ -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -m32 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


