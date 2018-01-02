################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/stream_out/subdir.mk
-include src/stream_in/subdir.mk
-include src/piziot_core_ipcamera/subdir.mk
-include src/p2p/p2p_ipcamera_main/subdir.mk
-include src/p2p/p2p_ipcamera_channel_server_main/ipcamera_data/command/subdir.mk
-include src/p2p/p2p_ipcamera_channel_server_main/ipcamera_data/subdir.mk
-include src/p2p/subdir.mk
-include src/misc/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ../../../lib/Linux/HI3520D/libpiziot_core_ipcamera_HI3520D.a

# Tool invocations
../../../lib/Linux/HI3520D/libpiziot_core_ipcamera_HI3520D.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	../../../../../HI3520D/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-ar -r  "../../../lib/Linux/HI3520D/libpiziot_core_ipcamera_HI3520D.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ARCHIVES)$(OBJS)$(C_DEPS) ../../../lib/Linux/HI3520D/libpiziot_core_ipcamera_HI3520D.a
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
