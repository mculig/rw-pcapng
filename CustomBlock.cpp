/*
 * CustomBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "CustomBlock.h"
#include "Block.h"
#include "list"
#include "Helpers.h"

CustomBlock::CustomBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type,block_length) {
	uint32_t buffer_location=0;
	options=new std::list<Option>;
	Helpers::readBuffer(buffer,(uint8_t*) &private_enterprise_number,sizeof(private_enterprise_number),&buffer_location,*endianness);
	//Custom data is indistinguishable from potential custom options. The data may or may not include a length. It's impossible to read this as it is now.
}

CustomBlock::~CustomBlock() {
	//Free memory
	options->clear();
	delete options;
}

