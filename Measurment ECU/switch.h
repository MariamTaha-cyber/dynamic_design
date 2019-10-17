/*
 * switch.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Mariam Taha
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

void switch_ini(uint8 Port,uint8 Pin);
uint8 switch_status(uint8 Port,uint8 Pin);


#endif /* SWITCH_H_ */
