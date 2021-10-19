################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/Input.c \
../src/Nexo_Cliente_Pedido.c \
../src/Pedido.c \
../src/Recicladora.c 

OBJS += \
./src/Cliente.o \
./src/Input.o \
./src/Nexo_Cliente_Pedido.o \
./src/Pedido.o \
./src/Recicladora.o 

C_DEPS += \
./src/Cliente.d \
./src/Input.d \
./src/Nexo_Cliente_Pedido.d \
./src/Pedido.d \
./src/Recicladora.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


