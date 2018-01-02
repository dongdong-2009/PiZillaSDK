################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_ipcamera_main/p2p_ipcamera_main.c \
../src/p2p/p2p_ipcamera_main/p2p_ipcamera_main_device.c 

OBJS += \
./src/p2p/p2p_ipcamera_main/p2p_ipcamera_main.o \
./src/p2p/p2p_ipcamera_main/p2p_ipcamera_main_device.o 

C_DEPS += \
./src/p2p/p2p_ipcamera_main/p2p_ipcamera_main.d \
./src/p2p/p2p_ipcamera_main/p2p_ipcamera_main_device.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/p2p_ipcamera_main/%.o: ../src/p2p/p2p_ipcamera_main/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__ -I/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


