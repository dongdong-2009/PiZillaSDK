################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/p2p/p2p_cms_main/p2p_cms_main.c \
../src/p2p/p2p_cms_main/p2p_cms_main_ipcamera.c \
../src/p2p/p2p_cms_main/p2p_cms_main_nas.c 

OBJS += \
./src/p2p/p2p_cms_main/p2p_cms_main.o \
./src/p2p/p2p_cms_main/p2p_cms_main_ipcamera.o \
./src/p2p/p2p_cms_main/p2p_cms_main_nas.o 

C_DEPS += \
./src/p2p/p2p_cms_main/p2p_cms_main.d \
./src/p2p/p2p_cms_main/p2p_cms_main_ipcamera.d \
./src/p2p/p2p_cms_main/p2p_cms_main_nas.d 


# Each subdirectory must supply rules for building sources it contributes
src/p2p/p2p_cms_main/%.o: ../src/p2p/p2p_cms_main/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	../../../../../HI3518E/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-gcc -D__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__ -I../../../../../HI3518E/package_src/arm-hisiv100-linux/target/armv5te_soft/usr/include -I../../../include -O3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


