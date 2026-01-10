################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include PeripheralWrapper/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Cpu/CStart/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC27D/Tricore/Asclin/Asc/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := mes1_esw_mcs_project_bubble_level
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
mes1_esw_mcs_project_bubble_level.hex \

SECONDARY_LIST += \
mes1_esw_mcs_project_bubble_level.lst \

SECONDARY_SIZE += \
mes1_esw_mcs_project_bubble_level.siz \


# All Target
all: main-build

# Main-build Target
main-build: mes1_esw_mcs_project_bubble_level.elf secondary-outputs

# Tool invocations
mes1_esw_mcs_project_bubble_level.elf: $(OBJS) ../Lcf_Gnuc_Tricore_Tc.lsl makefile $(OPTIONAL_TOOL_DEPS) .mes1_esw_mcs_project_bubble_level.elf.opt
	@echo 'Building target: $@'
	@echo 'Invoking: AURIX GCC Linker'
	tricore-elf-gcc @.mes1_esw_mcs_project_bubble_level.elf.opt
	@echo 'Finished building target: $@'
	@echo ' '

.mes1_esw_mcs_project_bubble_level.elf.opt:
	$(file >$@, -T"../Lcf_Gnuc_Tricore_Tc.lsl" -nocrt0 -Wl,--gc-sections -mtc161 -o "mes1_esw_mcs_project_bubble_level.elf" $(OBJS))

.PHONY: .mes1_esw_mcs_project_bubble_level.elf.opt

mes1_esw_mcs_project_bubble_level.hex: mes1_esw_mcs_project_bubble_level.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AURIX Object Copy'
	tricore-elf-objcopy -O ihex "mes1_esw_mcs_project_bubble_level.elf" "mes1_esw_mcs_project_bubble_level.hex"
	@echo 'Finished building: $@'
	@echo ' '

mes1_esw_mcs_project_bubble_level.lst: mes1_esw_mcs_project_bubble_level.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AURIX Create Listing'
	tricore-elf-objdump -h -S "mes1_esw_mcs_project_bubble_level.elf" > "mes1_esw_mcs_project_bubble_level.lst"
	@echo 'Finished building: $@'
	@echo ' '

mes1_esw_mcs_project_bubble_level.siz: mes1_esw_mcs_project_bubble_level.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AURIX Print Size'
	tricore-elf-size  --format=berkeley "mes1_esw_mcs_project_bubble_level.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) mes1_esw_mcs_project_bubble_level.elf mes1_esw_mcs_project_bubble_level.hex mes1_esw_mcs_project_bubble_level.lst mes1_esw_mcs_project_bubble_level.siz
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
