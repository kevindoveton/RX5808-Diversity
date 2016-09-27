#include "rx5808.h"

void SERIAL_SENDBIT1()
{
	MODULE_CLK_LOW();
	_delay_us(300);
	
	MODULE_DATA_HIGH();
	_delay_us(300);
	MODULE_CLK_HIGH();
	_delay_us(300);
	
	MODULE_CLK_LOW();
	_delay_us(300);
}

void SERIAL_SENDBIT0()
{
	MODULE_CLK_LOW();
	_delay_us(300);
	
	MODULE_DATA_LOW();
	_delay_us(300);
	MODULE_CLK_HIGH();
	_delay_us(300);
	
	MODULE_CLK_LOW();
	_delay_us(300);
}

void SERIAL_ENABLE_LOW()
{
	_delay_us(100);
	MODULE_EN_LOW();
	_delay_us(100);
}

void SERIAL_ENABLE_HIGH()
{
	_delay_us(100); 
	MODULE_EN_HIGH();
	_delay_us(100);
}

void setChannelModule(uint8_t channel)
{
	uint8_t i;
	uint16_t channelData;
	
	//channelData = pgm_read_word(&channelTable[channel]);
	channelData = channelTable[channel];
	
	// bit bash out 25 bits of data
	// Order: A0-3, !R/W, D0-D19
	// A0=0, A1=0, A2=0, A3=1, RW=0, D0-19=0
	SERIAL_ENABLE_HIGH();
	_delay_ms(2);
	SERIAL_ENABLE_LOW();

	SERIAL_SENDBIT0();
	SERIAL_SENDBIT0();
	SERIAL_SENDBIT0();
	SERIAL_SENDBIT1();
	
	SERIAL_SENDBIT0();
	
	// remaining zeros
	for (i=20;i>0;i--)
		SERIAL_SENDBIT0();
	
	// Clock the data in
	SERIAL_ENABLE_HIGH();
	_delay_ms(2);
	SERIAL_ENABLE_LOW();

	// Second is the channel data from the lookup table
	// 20 bytes of register data are sent, but the MSB 4 bits are zeros
	// register address = 0x1, write, data0-15=channelData data15-19=0x0
	SERIAL_ENABLE_HIGH();
	SERIAL_ENABLE_LOW();
	
	// Register 0x1
	SERIAL_SENDBIT1();
	SERIAL_SENDBIT0();
	SERIAL_SENDBIT0();
	SERIAL_SENDBIT0();
	
	// Write to register
	SERIAL_SENDBIT1();
	
	// D0-D15
	//   note: loop runs backwards as more efficent on AVR
	for (i=16;i>0;i--)
	{
		// Is bit high or low?
		if (channelData & 0x1)
		{
			SERIAL_SENDBIT1();
		}
		else
		{
			SERIAL_SENDBIT0();
		}
		
		// Shift bits along to check the next one
		channelData >>= 1;
	}
	
	// Remaining D16-D19
	for (i=4;i>0;i--)
		SERIAL_SENDBIT0();
	
	// Finished clocking data in
	SERIAL_ENABLE_HIGH();
	_delay_ms(2);
	
	MODULE_EN_HIGH();
	MODULE_CLK_LOW();
	MODULE_DATA_LOW();
}