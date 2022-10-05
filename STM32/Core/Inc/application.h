/*
 * application.h
 *
 *  Created on: Oct 5, 2022
 *      Author: KiuPhox
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

extern enum ModeState modeState;
void changeModeState(void);
void fsm_for_mode(void);

#endif /* INC_APPLICATION_H_ */
