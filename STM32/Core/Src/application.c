/*
 * application.c
 *
 *  Created on: Oct 5, 2022
 *      Author: KiuPhox
 */
#include "main.h"

enum ModeState{NORMAL, RED, YELLOW, GREEN};
enum ModeState modeState = NORMAL;

void fsm_for_mode(void){
	switch (modeState){
		case NORMAL:
			break;
		case RED:
			break;
		case YELLOW:
			break;
		case GREEN:
			break;
	}
}

void changeModeState(void){
	modeState++;
	if (modeState > 3){
		modeState = 0;
	}
	display7SEG(modeState + 1);
}

