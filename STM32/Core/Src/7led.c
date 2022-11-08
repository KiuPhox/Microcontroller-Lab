/*
 * 7led.c
 *
 *  Created on: Oct 13, 2022
 *      Author: KiuPhox
 */
#include "application.h"
#include "main.h"
#include "timer.h"

const int MAX_MODE_LED = 4;
const int MAX_TRAFFIC_LED = 4;
int index_mode_led = 0;
int index_traffic_led = 0;



void display7SEG(int counter){
	HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (C_SIDE_GPIO_Port, C_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_RESET);

	switch (counter){
		case 1:
			HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (C_SIDE_GPIO_Port, C_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 8:
			break;
		case 9:
			HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
			break;
		case 0:
			HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_SET);
			break;
	}
}

void update7SEGMode(int index){
	if ((int)modeState != 0){
		switch (index){
			case 0:
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
				display7SEG(0);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
				display7SEG((int)modeState + 1);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
				display7SEG(modeLedDisplay / 10);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
				display7SEG(modeLedDisplay % 10);
				break;
		}
	}
	else{
		switch (index){
			case 0:
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
				display7SEG(timer_counter[1] / 1000);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
				display7SEG(timer_counter[1] / 100 % 10);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
				display7SEG(timer_counter[2] / 1000);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
				display7SEG(timer_counter[2] / 100 % 10);
				break;
		}
	}
}

void autoDisplay7Led(void){
	if (timer_flag[0] == 1){
		setTimer(0, 100);
		index_mode_led++;
		if (index_mode_led == MAX_MODE_LED){
			index_mode_led = 0;
		}
		update7SEGMode(index_mode_led);
	}
}



