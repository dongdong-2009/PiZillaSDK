################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_command.c \
../src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_main.c \
../src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_other.c 

OBJS += \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_command.o \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_main.o \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_other.o 

C_DEPS += \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_command.d \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_main.d \
./src/p2p/p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_other.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/p2p_cms_channel_client_main/ipcamera_data/%.o: ../src/p2p/p2p_cms_channel_client_main/ipcamera_data/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../RTL8196/package_src/mips-linux/bin/rsdk-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__ -D_XOPEN_SOURCE=500 -D_BSD_SOURCE -I../../../../../RTL8196/package_src/mips-linux/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

