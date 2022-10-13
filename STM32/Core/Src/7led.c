/*
 * 7led.c
 *
 *  Created on: Oct 13, 2022
 *      Author: KiuPhox
 */
#include "application.h"
#include "main.h"
#include "timer.h"

const int MAX_LED = 3;
int index_led = 0;

void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
			display7SEG((int)modeState + 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
			display7SEG(ledDisplay / 10);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
			display7SEG(ledDisplay % 10);
			break;
	}
}

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

void autoDisplay7Led(void){
	if (timer0_flag == 1){
		setTimer0(100);
		index_led++;
		if (index_led == MAX_LED){
			index_led = 0;
		}
		update7SEG(index_led);
	}
}



