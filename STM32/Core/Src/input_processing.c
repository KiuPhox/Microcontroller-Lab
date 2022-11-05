/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2022
 *      Author: KiuPhox
 */

#include "main.h"
#include "input_reading.h"
#include "7led.h"
#include "timer.h"

#define NO_OF_BUTTONS 3

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_3S};
enum ButtonState buttonStates[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

int counter = 0;

void changeCounterValue(int value){
	counter += value;
	if (counter < 0){
		counter = 9;
	}
	else if (counter > 9){
		counter = 0;
	}
}

void led_red_blinking(){
	if (timer_flag[0] == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(0, 1000);
	}
}

void fsm_simple_buttons_run (void){

	if (timer_flag[2] == 1){
		setTimer(2, 1000);
		counter--;
		if (counter < 0){
			counter = 0;
		}
		display7SEG(counter);
	}

	for (int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonStates[i]){
			case BUTTON_RELEASED:
				if (is_button_pressed(i)){
					setTimer(2, 10000);
					buttonStates[i] = BUTTON_PRESSED;
				}
				break;
			case BUTTON_PRESSED:
				if (!is_button_pressed(i)){
					if (i == 0){
						counter = 0;
					}else if (i == 1){
						changeCounterValue(1);
					}
					else if (i == 2){
						changeCounterValue(-1);
					}
					display7SEG(counter);
					buttonStates[i] = BUTTON_RELEASED;
				}
				else if (is_button_pressed_3s(i)){
					setTimer(1, 1000);
					buttonStates[i] = BUTTON_PRESSED_3S;
				}
				break;
			case BUTTON_PRESSED_3S:
				setTimer(2, 10000);
				if (i == 1){
					if (timer_flag[1] == 1){
						setTimer(1, 1000);
						changeCounterValue(1);
						display7SEG(counter);
					}
				}
				else if (i == 2){
					if (timer_flag[1] == 1){
						setTimer(1, 1000);
						changeCounterValue(-1);
						display7SEG(counter);
					}
				}

				if (!is_button_pressed(i)){
					buttonStates[i] = BUTTON_RELEASED;
				}
				break;
			}
	}
}


