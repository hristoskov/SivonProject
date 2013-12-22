################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UIControl/UIControl.cpp 

OBJS += \
./UIControl/UIControl.o 

CPP_DEPS += \
./UIControl/UIControl.d 


# Each subdirectory must supply rules for building sources it contributes
UIControl/%.o: ../UIControl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


