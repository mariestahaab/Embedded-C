################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../exercise_lec75_ASCII_getchar.c 

C_DEPS += \
./exercise_lec75_ASCII_getchar.d 

OBJS += \
./exercise_lec75_ASCII_getchar.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./exercise_lec75_ASCII_getchar.d ./exercise_lec75_ASCII_getchar.o

.PHONY: clean--2e-

