/*
 * timer.h
 *
 *  Created on: Sep 27, 2022
 *      Author: KiuPhox
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define MAX_TIMER 8

extern int timer_flag[];
extern int timer_counter[];

void setTimer(int index, int duration);
void timerRun();


#endif /* INC_TIMER_H_ */
