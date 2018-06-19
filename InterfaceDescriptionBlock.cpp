/*
 * InterfaceDescriptionBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "InterfaceDescriptionBlock.h"
#include "Helpers.h"

InterfaceDescriptionBlock::InterfaceDescriptionBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length) {
	uint32_t buffer_location=0;
	Helpers::readBuffer(buffer,(uint8_t*) &link_type, sizeof(link_type),&buffer_location, *endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &reserved, sizeof(reserved), &buffer_location, *endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &snap_length, sizeof(snap_length),&buffer_location, *endianness);
	options_list=new std::list<Option>();
	//Use the helper to read the options. This allows all the logic to be in one easy-to-fix place
	Helpers::readOptions(options_list, buffer, &buffer_location ,block_length, endianness);
}

InterfaceDescriptionBlock::~InterfaceDescriptionBlock() {
	options_list->clear();
	delete options_list;
}
