################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/zigbee/zigbee_sdk/subdir.mk
-include src/zigbee/subdir.mk
-include src/stream_out/subdir.mk
-include src/stream_in/subdir.mk
-include src/piziot_core_nas/subdir.mk
-include src/p2p/p2p_nas_main/subdir.mk
-include src/p2p/p2p_nas_channel_server_main/nas_data/command/subdir.mk
-include src/p2p/p2p_nas_channel_server_main/nas_data/subdir.mk
-include src/p2p/p2p_nas_channel_client_main/ipcamera_data/command/subdir.mk
-include src/p2p/p2p_nas_channel_client_main/ipcamera_data/subdir.mk
-include src/p2p/subdir.mk
-include src/misc/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ../../../lib/Linux/RK3328_UBM1604_Debug/libpiziot_core_nas_RK3328_UBM1604_Debug.a

# Tool invocations
../../../lib/Linux/RK3328_UBM1604_Debug/libpiziot_core_nas_RK3328_UBM1604_Debug.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	ar -r  "../../../lib/Linux/RK3328_UBM1604_Debug/libpiziot_core_nas_RK3328_UBM1604_Debug.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(ARCHIVES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) ../../../lib/Linux/RK3328_UBM1604_Debug/libpiziot_core_nas_RK3328_UBM1604_Debug.a
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
