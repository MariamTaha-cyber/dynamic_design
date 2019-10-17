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

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

void switch_init(uint8 Port,uint8 Pin);
uint8 switch_status(uint8 Port,uint8 Pin);


#endif /* SWITCH_H_ */
