/*
 * application.c
 *
 *  Created on: Oct 5, 2022
 *      Author: KiuPhox
 */
#include "main.h"
#include "timer.h"

enum ModeState{NORMAL, RED, YELLOW, GREEN};
enum ModeState modeState = NORMAL;

void fsm_for_mode(void){
	switch (modeState){
		case NORMAL:
			break;
		case RED:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			break;
	}
}

void fsm_for_led(void){

}

void changeModeState(void){
	modeState++;
	if (modeState > 3){
		modeState = 0;
	}
	display7SEG(modeState + 1);
}

