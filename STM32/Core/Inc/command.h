/*
 * command.h
 *
 *  Created on: Dec 24, 2022
 *      Author: KiuPhox
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include "main.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>

extern char command[30];
extern unsigned char command_index;
extern unsigned char command_done;


void command_parser_fsm();

#endif /* INC_COMMAND_H_ */
