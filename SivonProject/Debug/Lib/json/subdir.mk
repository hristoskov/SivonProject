################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Lib/json/block_allocator.cpp \
../Lib/json/json.cpp 

OBJS += \
./Lib/json/block_allocator.o \
./Lib/json/json.o 

CPP_DEPS += \
./Lib/json/block_allocator.d \
./Lib/json/json.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/json/%.o: ../Lib/json/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


