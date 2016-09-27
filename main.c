#include <avr/eeprom.h>
#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "hardware.h"
#include "rx5808.h"
#include "oled.h"

#define LED_ON()            PORTA |= 0x08
#define LED_OFF()           PORTA &= ~0x08

#define BUZZER_ON()         PORTA |= 0x20; PORTA &=~0x40;
#define BUZZER_TOGGLE()     PORTA ^= 0x60;
#define BUZZER_OFF()        PORTA &= ~0x60;

#define TOTAL_BANDS         5

/* 	
	|===========================|
	|       EEPROM LAYOUT       |
	|===========================|
	| Address |       Data      | 
	|===========================|
	|   0x00  |  Current Band   |
	|   0x01  | Current Channel |
	|===========================|
*/

void init()
{
	// initialise ports
	initPorts();
	// set receiver a
	setReceiver(0);

	// initialise oled

}
`
void main()
{
	// variables
	uint8_t currentBand;
	uint8_t currentChannel;
	uint8_t rssiA;
	uint8_t rssiB;

	currentBand = 0;
	currentChannel = 0;

	init();

	while(1)
	{
		rssiA = readRSSI(0);
		rssiB = readRSSI(1);
		
	}
}