/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2022
 *      Author: KiuPhox
 */

#include "main.h"
#include "input_reading.h"
#include "application.h"

#define NO_OF_BUTTONS 3

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED};
enum ButtonState buttonStates[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

void fsm_for_input_processing(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonStates[i]){
			case BUTTON_RELEASED:
				if (is_button_pressed(i)){
					if (i == 0){
						changeModeState();
					}
					buttonStates[i] = BUTTON_PRESSED;
				}
				break;
			case BUTTON_PRESSED:
				if (!is_button_pressed(i)){
					buttonStates[i] = BUTTON_RELEASED;
				}
				break;
			}
	}
}
