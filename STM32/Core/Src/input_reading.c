/*
 * input_reading.c
 *
 *  Created on: Oct 4, 2022
 *      Author: KiuPhox
 */
#include "main.h"
#define NO_OF_BUTTONS 3

#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

static uint8_t buttonPins[NO_OF_BUTTONS] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOB, buttonPins[i]);
		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
	}
}

unsigned int is_button_pressed(int index){
	if (index >= NO_OF_BUTTONS)
		return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
