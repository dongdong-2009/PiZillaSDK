################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/pizcam/pizcam.c \
../src/pizcam/pizcam_main.c \
../src/pizcam/pizcam_setting.c 

OBJS += \
./src/pizcam/pizcam.o \
./src/pizcam/pizcam_main.o \
./src/pizcam/pizcam_setting.o 

C_DEPS += \
./src/pizcam/pizcam.d \
./src/pizcam/pizcam_main.d \
./src/pizcam/pizcam_setting.d 


# Each subdirectory must supply rules for building sources it contributes
src/pizcam/%.o: ../src/pizcam/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__ -D__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__ -I../../../include -O0 -g3 -Wall -Werror -c -fmessage-length=0 -m32 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


