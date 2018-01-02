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
all: ../../../exe/Linux/x86_32_Linux_Release/pizcam

# Tool invocations
../../../exe/Linux/x86_32_Linux_Release/pizcam: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L../../../lib/Linux/x86_32_Linux_Release -L../Lib/x86_32_Linux_Release/lib -m32 -o "../../../exe/Linux/x86_32_Linux_Release/pizcam" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ../../../exe/Linux/x86_32_Linux_Release/pizcam
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
