/*
 * application.c
 *
 *  Created on: Oct 5, 2022
 *      Author: KiuPhox
 */
#include "main.h"
#include "timer.h"

enum ModeState{NORMAL_MODE, RED_MODE, YELLOW_MODE, GREEN_MODE};
enum ModeState modeState = NORMAL_MODE;

enum TrafficState{RED, YELLOW, GREEN};
enum TrafficState trafficMainState = RED;
enum TrafficState trafficSideState = GREEN;

int redCounter = 5;
int yellowCounter = 3;
int greenCounter = 2;

int modeLedDisplay;
int mainLedDisplay;
int sideLedDisplay;

void fsm_for_traffic(){
	switch (trafficMainState){
			case RED:
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, SET);
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);
				if (timer_flag[1] == 1){
					trafficMainState = GREEN;
					setTimer(1, greenCounter * 1000);
				}
				break;
			case YELLOW:
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);
				if (timer_flag[1] == 1){
					trafficMainState = RED;
					setTimer(1, redCounter * 1000);
				}
				break;
			case GREEN:
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, SET);
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);
				if (timer_flag[1] == 1){
					trafficMainState = YELLOW;
					setTimer(1, yellowCounter * 1000);
				}
				break;
		}
	switch (trafficSideState){
				case RED:
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
					if (timer_flag[2] == 1){
						trafficSideState = GREEN;
						setTimer(2, greenCounter * 1000);
					}
					break;
				case YELLOW:
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
					if (timer_flag[2] == 1){
						trafficSideState = RED;
						setTimer(2, redCounter * 1000);
					}
					break;
				case GREEN:
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
					if (timer_flag[2] == 1){
						trafficSideState = YELLOW;
						setTimer(2, yellowCounter * 1000);
					}
					break;
			}
}

void fsm_for_mode(void){
	switch (modeState){
		case NORMAL_MODE:
			fsm_for_traffic();
			break;
		case RED_MODE:
			if (timer_flag[3] == 1){
				setTimer(3, 500);
				HAL_GPIO_TogglePin(RED0_GPIO_Port, RED0_Pin);
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);
				HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			}
			modeLedDisplay = redCounter;
			break;
		case YELLOW_MODE:
			if (timer_flag[3] == 1){
				setTimer(3, 500);
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
				HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				HAL_GPIO_TogglePin(YELLOW0_GPIO_Port, YELLOW0_Pin);
				HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);
				HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			}
			modeLedDisplay = yellowCounter;
			break;
		case GREEN_MODE:
			if (timer_flag[3] == 1){
				setTimer(3, 500);
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
				HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
				HAL_GPIO_TogglePin(GREEN0_GPIO_Port, GREEN0_Pin);
				HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			}
			modeLedDisplay = greenCounter;
			break;
	}
}


void resetTrafficLed(void){
	setTimer(1, redCounter * 1000);
	setTimer(2, greenCounter * 1000);
	trafficMainState = RED;
	trafficSideState = GREEN;
}


void changeModeState(void){
	modeState++;
	if (modeState > 3){
		modeState = 0;
		resetTrafficLed();
	}
}

void validateCounterValue(int *counter){
	if (*counter < 1){
		*counter = 1;
	}
	else if (*counter > 99){
		*counter = 99;
	}
}

void changeCounterValue(int value){
	switch (modeState){
		case NORMAL_MODE:
			break;
		case RED_MODE:
			redCounter += value;
			validateCounterValue(&redCounter);
			break;
		case YELLOW_MODE:
			yellowCounter += value;
			validateCounterValue(&yellowCounter);
			break;
		case GREEN_MODE:
			greenCounter += value;
			validateCounterValue(&greenCounter);
			break;
	}
}



