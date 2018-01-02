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
all: ../../../exe/Linux/HI3518E/pizcam

# Tool invocations
../../../exe/Linux/HI3518E/pizcam: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	../../../../../HI3518E/package_src/arm-hisiv100-linux/target/bin/arm-hisiv100nptl-linux-gcc -L../../../../../HI3518E/package_src/arm-hisiv100-linux/target/armv5te_soft/usr/lib -L../../../lib/Linux/HI3518E -L../Lib/HI3518E/lib -o "../../../exe/Linux/HI3518E/pizcam" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ../../../exe/Linux/HI3518E/pizcam
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
