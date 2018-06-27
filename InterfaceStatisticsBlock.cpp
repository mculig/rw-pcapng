/*
 * InterfaceStatisticsBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "InterfaceStatisticsBlock.h"
#include "Block.h"
#include "Helpers.h"
#include "list"

InterfaceStatisticsBlock::InterfaceStatisticsBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length) {
	uint32_t buffer_location=0;
	options=new std::list<Option>;
	Helpers::readBuffer(buffer,(uint8_t*) &timestamp_high,sizeof(timestamp_high),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &timestamp_low,sizeof(timestamp_low),&buffer_location,*endianness);
	Helpers::readOptions(options, buffer, &buffer_location, block_length, endianness);
}

InterfaceStatisticsBlock::~InterfaceStatisticsBlock() {
	//Free memory
	options->clear();
	delete options;
}

