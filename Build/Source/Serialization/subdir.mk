################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Serialization/Serialization.cpp 

OBJS += \
./Source/Serialization/Serialization.o 

CPP_DEPS += \
./Source/Serialization/Serialization.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Serialization/%.o: ../Source/Serialization/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-openwrt-linux-muslgnueabi-g++ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


