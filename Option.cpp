/*
 * Option.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "Option.h"
#include "string.h"
#include "Helpers.h"

Option::Option(uint8_t* buffer, uint32_t* readIndex, bool* endianness) {
	Helpers::readBuffer(buffer, (uint8_t*) &type, sizeof(uint16_t),readIndex,*endianness);
	Helpers::readBuffer(buffer, (uint8_t*) &option_length, sizeof(uint16_t), readIndex, *endianness);
	option_value=new uint8_t[option_length];
	memcpy(option_value,buffer+*readIndex,sizeof(uint8_t)*option_length);
	//Skip x bytes of padding
	//Calculate padding byte count
	uint8_t padding=Helpers::calculatePaddingLength(option_length);
	//Increment readIndex by padding
	*readIndex+=padding;
}

Option::~Option() {
	delete option_value;
}

uint16_t Option::paddedLength()
{
	//Return the true option length which includes the padding.
	return option_length+Helpers::calculatePaddingLength(option_length);
}
