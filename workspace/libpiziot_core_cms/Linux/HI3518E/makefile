################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/piziot_core_cms/subdir.mk
-include src/p2p/p2p_cms_main/subdir.mk
-include src/p2p/p2p_cms_channel_client_main/nas_data/command/subdir.mk
-include src/p2p/p2p_cms_channel_client_main/nas_data/subdir.mk
-include src/p2p/p2p_cms_channel_client_main/ipcamera_data/command/subdir.mk
-include src/p2p/p2p_cms_channel_client_main/ipcamera_data/subdir.mk
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
all: ../../../lib/Linux/HI3518E/libpiziot_core_cms_HI3518E.a

# Tool invocations
../../../lib/Linux/HI3518E/libpiziot_core_cms_HI3518E.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	../../../../../HI3518E/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-ar -r  "../../../lib/Linux/HI3518E/libpiziot_core_cms_HI3518E.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(ARCHIVES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) ../../../lib/Linux/HI3518E/libpiziot_core_cms_HI3518E.a
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
