################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/InterProcessMessage/Message.c \
../Source/InterProcessMessage/Requestor.c \
../Source/InterProcessMessage/Responder.c 

OBJS += \
./Source/InterProcessMessage/Message.o \
./Source/InterProcessMessage/Requestor.o \
./Source/InterProcessMessage/Responder.o 

C_DEPS += \
./Source/InterProcessMessage/Message.d \
./Source/InterProcessMessage/Requestor.d \
./Source/InterProcessMessage/Responder.d 


# Each subdirectory must supply rules for building sources it contributes
Source/InterProcessMessage/%.o: ../Source/InterProcessMessage/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-openwrt-linux-muslgnueabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


