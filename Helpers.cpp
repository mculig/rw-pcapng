/*
 * Helpers.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: mislav
 */

#include "Helpers.h"

Helpers::Helpers() {
	// TODO Auto-generated constructor stub

}

Helpers::~Helpers() {
	// TODO Auto-generated destructor stub
}

void Helpers::readBuffer(uint8_t* buffer, uint8_t* target, uint64_t size, uint32_t* readIndex, bool endianness) {
	//If we're dealing with big endian
	if(endianness)
	{
		uint64_t j=*readIndex+size-1;
		for(uint64_t i=*readIndex;i<*readIndex+size;i++)
		{
			//Assign first byte of buffer block to last byte of target
			*(target+j)=*(buffer+i);
			--j;
		}
	}
	//If we're dealing with little endian
	else
	{
		//Just assign each byte of the buffer to the matching byte of target
		for(uint64_t i=*readIndex;i<*readIndex+size;i++)
			*(target+i)=*(buffer+i);
	}
	//Increment the readIndex
	readIndex+=size;
}
