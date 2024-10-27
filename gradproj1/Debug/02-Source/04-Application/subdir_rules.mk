################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
02-Source/04-Application/%.obj: ../02-Source/04-Application/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/00-Library/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/ADC/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/DIO/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/EEPROM/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/Interrupt/EXT_INT/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/Interrupt/Global interrupt/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/01-MCAL/UART/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/02-HAL/BNO055_IMU/Inc" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/02-HAL/I2C/Inc" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="C:/Users/El-Wattaneya/workspace_v11/gradproj1/02-Source/00-Library/Inc" --include_path="C:/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="02-Source/04-Application/$(basename $(<F)).d_raw" --obj_directory="02-Source/04-Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


