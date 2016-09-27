#define MODULE_CLK_LOW()    PORTB &= ~0x04;
#define MODULE_CLK_HIGH()   PORTB |= 0x04;

#define MODULE_DATA_LOW()   PORTB &= ~0x01;
#define MODULE_DATA_HIGH()  PORTB |= 0x01;

#define MODULE_EN_LOW()     PORTB &= ~0x02;
#define MODULE_EN_HIGH()    PORTB |= 0x02;

// Channels to sent to the SPI registers
const uint16_t channelTable[] = {
	// Channel 1 - 8
	0x2A05,    0x299B,    0x2991,    0x2987,    0x291D,    0x2913,    0x2909,    0x289F,    // Band A
	0x2903,    0x290C,    0x2916,    0x291F,    0x2989,    0x2992,    0x299C,    0x2A05,    // Band B
	0x2895,    0x288B,    0x2881,    0x2817,    0x2A0F,    0x2A19,    0x2A83,    0x2A8D,    // Band E
	0x2906,    0x2910,    0x291A,    0x2984,    0x298E,    0x2998,    0x2A02,    0x2A0C,    // Band F / Airwave
	0x281D,    0x288F,    0x2902,    0x2914,    0x2987,    0x2999,    0x2A0C,    0x2A1E     // Band C / Immersion Raceband
};

void SERIAL_SENDBIT1();

void SERIAL_SENDBIT0();

void SERIAL_ENABLE_LOW();

void SERIAL_ENABLE_HIGH();

void setChannelModule(uint8_t channel);