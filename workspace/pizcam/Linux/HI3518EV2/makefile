################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/pizcam/subdir.mk
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
all: ../../../exe/Linux/HI3518EV2/pizcam

# Tool invocations
../../../exe/Linux/HI3518EV2/pizcam: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	../../../../../HI3518EV2/package_src/arm-hisiv300-linux/target/bin/arm-hisiv300-linux-gcc -L../../../../../HI3518EV2/package_src/arm-hisiv300-linux/target/usr/lib/armv5te_arm9_soft -L../../../lib/Linux/HI3518EV2 -L../Lib/HI3518EV2/lib -o "../../../exe/Linux/HI3518EV2/pizcam" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ../../../exe/Linux/HI3518EV2/pizcam
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
