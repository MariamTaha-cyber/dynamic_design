/*
 * Measurement_ECU.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mariam Taha
 */

#include "Measurement_ECU.h"

void Measurement_ECU_init(void)
{
	UART_init();
	LCD_init();
}
uint64 calculations(uint8 Speed)
{
	uint64 Distance;
	Distance = (Speed*g_tick);
	return Distance;
}

void display_distance(uint64 Distance)
{
	LCD_goToRowColumn(0,9);
	LCD_intgerToString(Distance);
}

void screen_init(void)
{
	LCD_clearScreen();
	LCD_displayString("Distance=");
	LCD_goToRowColumn(0,15);
	LCD_displayCharacter('m');
}
