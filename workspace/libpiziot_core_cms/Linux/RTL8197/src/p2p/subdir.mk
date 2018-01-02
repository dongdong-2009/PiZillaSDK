################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_func.c \
../src/p2p/p2p_func_client.c \
../src/p2p/p2p_protocol_ipcamera.c \
../src/p2p/p2p_protocol_nas.c 

OBJS += \
./src/p2p/p2p_func.o \
./src/p2p/p2p_func_client.o \
./src/p2p/p2p_protocol_ipcamera.o \
./src/p2p/p2p_protocol_nas.o 

C_DEPS += \
./src/p2p/p2p_func.d \
./src/p2p/p2p_func_client.d \
./src/p2p/p2p_protocol_ipcamera.d \
./src/p2p/p2p_protocol_nas.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/%.o: ../src/p2p/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../RTL8197/package_src/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/bin/rsdk-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__ -I../../../../../RTL8197/package_src/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


