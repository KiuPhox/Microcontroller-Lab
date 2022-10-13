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

int redCounter = 5;
int yellowCounter = 3;
int greenCounter = 2;

int ledDisplay;

void fsm_for_mode(void){
	switch (modeState){
		case NORMAL:
			break;
		case RED:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			ledDisplay = redCounter;
			break;
		case YELLOW:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			ledDisplay = yellowCounter;
			break;
		case GREEN:
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			ledDisplay = greenCounter;
			break;
	}
}

void changeModeState(void){
	modeState++;
	if (modeState > 3){
		modeState = 0;
	}
}

void changeCounterValue(int value){
	switch (modeState){
		case NORMAL:
			break;
		case RED:
			redCounter += value;
			validateCounterValue(&redCounter);
			break;
		case YELLOW:
			yellowCounter += value;
			validateCounterValue(&yellowCounter);
			break;
		case GREEN:
			greenCounter += value;
			validateCounterValue(&greenCounter);
			break;
	}
}

void validateCounterValue(int *counter){
	if (*counter < 0){
		*counter = 0;
	}
	else if (*counter > 99){
		*counter = 99;
	}
}

