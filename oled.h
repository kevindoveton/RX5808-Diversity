// Channels with their Mhz Values
const uint16_t channelFreqTable[] = {
	// Channel 1 - 8
	5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725, // Band A
	5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866, // Band B
	5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945, // Band E
	5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880, // Band F / Airwave
	5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917  // Band C / Immersion Raceband
};

// do coding as simple hex value to save memory.
const uint8_t channelNames[] = {
	0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, // Band A
	0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, // Band B
	0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, // Band E
	0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, // Band F / Airwave
	0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8  // Band C / Immersion Raceband
};