/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2022
 *      Author: KiuPhox
 */

#include "main.h"
#include "input_reading.h"

#define NO_OF_BUTTONS 3

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonStates[NO_OF_BUTTONS] = BUTTON_RELEASED;


void fsm_for_input_processing(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++){
	switch(buttonStates[i]){
		case BUTTON_RELEASED:
			if (is_button_pressed(0)){
				buttonStates[i] = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0)){
				buttonStates[i] = BUTTON_RELEASED;
			}
			else if (is_button_pressed_1s(0)){
				buttonStates[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0)){
				buttonStates[i] = BUTTON_RELEASED;
			}
			break;
		}
	}
}
