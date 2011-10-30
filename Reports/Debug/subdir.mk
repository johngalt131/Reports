################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataBase.cpp \
../Entry.cpp \
../Financial.cpp \
../Report.cpp 

OBJS += \
./DataBase.o \
./Entry.o \
./Financial.o \
./Report.o 

CPP_DEPS += \
./DataBase.d \
./Entry.d \
./Financial.d \
./Report.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/travis/workspace/tinyxml" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


