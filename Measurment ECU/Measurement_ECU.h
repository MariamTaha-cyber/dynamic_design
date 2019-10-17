/*
 * Measurement_ECU.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Mariam Taha
 */

#ifndef MEASUREMENT_ECU_H_
#define MEASUREMENT_ECU_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
#include "TIMER.h"
#include "lcd.h"
#include "uart.h"
#include "switch.h"


void Measurement_ECU_init(void);
uint64 calculations(uint8 Speed);
void display_distance(uint64 Distance);
void screen_init(void);




#endif /* MEASUREMENT_ECU_H_ */
