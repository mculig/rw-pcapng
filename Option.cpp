/*
 * Option.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "Option.h"
#include "string.h"

Option::Option(uint8_t* buffer, uint32_t* readIndex) {
	//Helper variable for buffer reading
	unsigned int buffer_location=0;
	type=*(buffer+buffer_location);
	buffer_location+=sizeof(uint16_t);
	option_length=*(buffer+buffer_location);
	buffer_location+=sizeof(uint16_t);
	option_value=new uint8_t[option_length];
	memcpy(option_value,buffer+buffer_location,sizeof(uint8_t)*option_length);
}

Option::~Option() {
	delete option_value;
}

uint16_t Option::paddedLength()
{
	//Return the true option length which includes the padding.
	return option_length+4-(option_length%4);
}
