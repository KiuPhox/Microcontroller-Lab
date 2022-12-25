#include "uart.h"
#include <stdio.h>
#include <string.h>

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

enum communicateState{RST, OK};

enum communicateState commState = OK;

int ADC_value = 0;

char str[20];
char out[30];

void uart_communication_fsm(){
	switch(commState){
	case RST:
		if(command_done == 1){
			command_done = 0;

			if(strcmp(command,"OK") == 0){
				HAL_UART_Transmit(&huart2, (void*)out, sprintf(out, "\r\n"), 1000);
				commState = OK;
			}
		}
		if (timer_flag[1]){
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2 , (void*)str , sprintf(str, "ADC = %d\r\n", ADC_value), 1000);
			setTimer(1, 3000);
		}
		break;
	case OK:
		if(command_done == 1){
			command_done = 0;
				if(strcmp(command,"RST") == 0){
					ADC_value = HAL_ADC_GetValue(&hadc1);
					HAL_UART_Transmit(&huart2 , (void*)str , sprintf(str, "\r\nADC = %d\r\n", ADC_value), 1000);
					commState = RST;
					setTimer(1, 3000);
				}
			command[0] = '\0';
		}
		break;
	default:
		break;
	}
}
