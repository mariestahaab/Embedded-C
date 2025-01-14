/*
 * toggle_led_bitFields.c
 *
 *  Created on: Oct 22, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <GPIO_regAddr.h>

uint32_t pressedButton(void);

// volatile uint32_t *pClkCtrlReg		= (uint32_t*) 0x40023830;
RCC_AHB1ENR_t volatile *pRCC_AHB1ENR = (RCC_AHB1ENR_t*) 0x40023830;

// volatile uint32_t *pPortCModeReg	= (uint32_t*) 0x40020800;
GPIOx_MODER_t volatile *pGPIOC_MODER = (GPIOx_MODER_t*) 0x40020800;

// volatile uint32_t *pPortCInReg		= (uint32_t*) 0x40020810;
GPIOx_IDR_t volatile *pGPIOC_IDR = (GPIOx_IDR_t*) 0x40020810;

// volatile uint32_t *pPortAModeReg	= (uint32_t*) 0x40020000;
GPIOx_MODER_t volatile *pGPIOA_MODER = (GPIOx_MODER_t*) 0x40020000;

// volatile uint32_t *pPortAOutReg		= (uint32_t*) 0x40020014;
GPIOx_ODR_t volatile *pGPIOA_ODR = (GPIOx_ODR_t*) 0x40020014;

int main(void){

	// To enable Clock for GPIO A and GPIO C in the AHB1ENR, set bits 2, 0 to 1, 1.
	pRCC_AHB1ENR -> GPIO_A_EN = 1;
	pRCC_AHB1ENR -> GPIO_C_EN = 1;

    // Set bits 27, 26 (GPIOC, MODER13) to 0, 0 respectively for Input Mode.
	pGPIOC_MODER -> MODER_13 = 0;

    // Set bits 11 and 10 (GPIO A, pin 5) to 0 and 1 respectively for General Purpose Output Mode.

	pGPIOA_MODER -> MODER_5 = 1;

    while(1){

    	if(pressedButton()){
    		pGPIOA_ODR -> ODR_5 = ~(pGPIOA_ODR -> ODR_5);
    	}
    }

    return 0;
}

/*
    while(1){

    	if(pGPIOC_IDR -> IDR_13){
    		pGPIOA_ODR -> ODR_5 = 0;
    	}
    	else{
    		pGPIOA_ODR -> ODR_5 = 1;
    	}
    }
 */

uint32_t pressedButton(void){

	static uint32_t buttonLastState;	//Default value of static variable is 0.
	uint32_t buttonCurrentState = ~(pGPIOC_IDR -> IDR_13);
	uint32_t buttonPressed = (~buttonCurrentState) & (buttonLastState);

	buttonLastState = buttonCurrentState;

	return buttonPressed;
}

