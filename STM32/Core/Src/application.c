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

void turnMainRedLed(void){
	HAL_GPIO_WritePin(MAIN0_GPIO_Port, MAIN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MAIN1_GPIO_Port, MAIN1_Pin, GPIO_PIN_RESET);
}
void turnMainYellowLed(void){
	HAL_GPIO_WritePin(MAIN0_GPIO_Port, MAIN0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MAIN1_GPIO_Port, MAIN1_Pin, GPIO_PIN_SET);
}
void turnMainGreenLed(void){
	HAL_GPIO_WritePin(MAIN0_GPIO_Port, MAIN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MAIN1_GPIO_Port, MAIN1_Pin, GPIO_PIN_SET);
}

void turnSideRedLed(void){
	HAL_GPIO_WritePin(SIDE0_GPIO_Port, SIDE0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SIDE1_GPIO_Port, SIDE1_Pin, GPIO_PIN_RESET);
}
void turnSideYellowLed(void){
	HAL_GPIO_WritePin(SIDE0_GPIO_Port, SIDE0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SIDE1_GPIO_Port, SIDE1_Pin, GPIO_PIN_SET);
}
void turnSideGreenLed(void){
	HAL_GPIO_WritePin(SIDE0_GPIO_Port, SIDE0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SIDE1_GPIO_Port, SIDE1_Pin, GPIO_PIN_SET);
}

void fsm_for_traffic(){
	switch (trafficMainState){
			case RED:
				turnMainRedLed();
				if (timer_flag[1] == 1){
					trafficMainState = GREEN;
					setTimer(1, greenCounter * 1000);
				}
				break;
			case YELLOW:
				turnMainYellowLed();
				if (timer_flag[1] == 1){
					trafficMainState = RED;
					setTimer(1, redCounter * 1000);
				}
				break;
			case GREEN:
				turnMainGreenLed();
				if (timer_flag[1] == 1){
					trafficMainState = YELLOW;
					setTimer(1, yellowCounter * 1000);
				}
				break;
		}
	switch (trafficSideState){
				case RED:
					turnSideRedLed();
					if (timer_flag[2] == 1){
						trafficSideState = GREEN;
						setTimer(2, greenCounter * 1000);
					}
					break;
				case YELLOW:
					turnSideYellowLed();
					if (timer_flag[2] == 1){
						trafficSideState = RED;
						setTimer(2, redCounter * 1000);
					}
					break;
				case GREEN:
					turnSideGreenLed();
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
			turnMainRedLed();
			turnSideRedLed();
			modeLedDisplay = redCounter;
			break;
		case YELLOW_MODE:
			turnMainYellowLed();
			turnSideYellowLed();
			modeLedDisplay = yellowCounter;
			break;
		case GREEN_MODE:
			turnMainGreenLed();
			turnSideGreenLed();
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



