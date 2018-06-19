/*
 * SectionHeaderBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "SectionHeaderBlock.h"
#include "Helpers.h"
#include "list"

SectionHeaderBlock::SectionHeaderBlock(uint32_t block_type, uint32_t block_length, uint32_t bom, uint8_t* buffer, bool* endianness):Block(block_type, block_length) {
	//These values will be transformed in the reader and will always come true as little endian
	this->byte_order_magic=bom;
	//Read the major version, minor version and section length
	uint32_t buffer_location=0;
	Helpers::readBuffer(buffer,(uint8_t*) &major_version,sizeof(uint16_t),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &minor_version,sizeof(uint16_t),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &section_length,sizeof(uint64_t),&buffer_location,*endianness);
	//Create the options list
	options_list=new std::list<Option>();
	//Use the helper to read the options. This allows all the logic to be in one easy-to-fix place
	Helpers::readOptions(options_list, buffer, &buffer_location ,block_length, endianness);
}

SectionHeaderBlock::~SectionHeaderBlock() {
	//Free memory. Clearing a list should call destructors for all objects and thus clean up memory
	options_list->clear();
	delete options_list;
}
