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
all: ../../../exe/Linux/RTL8196/pizcam

# Tool invocations
../../../exe/Linux/RTL8196/pizcam: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	../../../../../RTL8196/package_src/mips-linux/bin/rsdk-linux-gcc -L../../../../../RTL8196/mips-linux/lib -L../../../lib/Linux/RTL8196 -L../Lib/RTL8196/lib -o "../../../exe/Linux/RTL8196/pizcam" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ../../../exe/Linux/RTL8196/pizcam
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
