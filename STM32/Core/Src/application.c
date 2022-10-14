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

int ledDisplay;

void turnMainRedLed(void){
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
}
void turnMainYellowLed(void){
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}
void turnMainGreenLed(void){
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}

void fsm_for_traffic(){
	switch (trafficMainState){
			case RED:
				turnMainRedLed();
				if (timer1_flag == 1){
					trafficMainState = GREEN;
					setTimer1(greenCounter * 1000);
				}
				break;
			case YELLOW:
				turnMainYellowLed();
				if (timer1_flag == 1){
					trafficMainState = RED;
					setTimer1(redCounter * 1000);
				}
				break;
			case GREEN:
				turnMainGreenLed();
				if (timer1_flag == 1){
					trafficMainState = YELLOW;
					setTimer1(yellowCounter * 1000);
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
			ledDisplay = redCounter;
			break;
		case YELLOW_MODE:
			turnMainYellowLed();
			ledDisplay = yellowCounter;
			break;
		case GREEN_MODE:
			turnMainGreenLed();
			ledDisplay = greenCounter;
			break;
	}
}


void resetTrafficLed(void){
	setTimer1(redCounter * 1000);
	setTimer2(greenCounter * 1000);
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



