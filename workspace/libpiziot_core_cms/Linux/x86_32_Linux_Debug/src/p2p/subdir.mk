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
	gcc -D__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__ -D__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__ -I../../../include -O0 -g3 -Wall -Werror -c -fmessage-length=0 -m32 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

