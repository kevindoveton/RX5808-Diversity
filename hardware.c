#include "hardware.h"

void initPorts()
{

}

void setReceiver(uint8_t receiver)
{
	switch (receiver)
	{
		case 0:
			// a high, others low
			break;
		case 1:
			// b high, others low
			break;
		default:
			// a high, others low
			break;
	}
}

int readRSSI(uint8_t receiver);