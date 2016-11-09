################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lab7.cpp \
../src/Lab9_operators.cpp \
../src/Lab9_strings.cpp \
../src/Lab9_vectors.cpp 

OBJS += \
./src/Lab7.o \
./src/Lab9_operators.o \
./src/Lab9_strings.o \
./src/Lab9_vectors.o 

CPP_DEPS += \
./src/Lab7.d \
./src/Lab9_operators.d \
./src/Lab9_strings.d \
./src/Lab9_vectors.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


