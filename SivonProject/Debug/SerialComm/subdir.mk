################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SerialComm/SerialComm.cpp 

OBJS += \
./SerialComm/SerialComm.o 

CPP_DEPS += \
./SerialComm/SerialComm.d 


# Each subdirectory must supply rules for building sources it contributes
SerialComm/%.o: ../SerialComm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


