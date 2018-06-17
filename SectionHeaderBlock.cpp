/*
 * SectionHeaderBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "SectionHeaderBlock.h"

SectionHeaderBlock::SectionHeaderBlock(uint32_t block_type, uint32_t block_length, uint32_t bom, uint8_t* buffer, bool* endianness):Block(block_type, block_length, endianness) {

}

SectionHeaderBlock::~SectionHeaderBlock() {
	//Free memory. Clearing a list should call destructors for all objects and thus clean up memory
	options_list->clear();
	delete options_list;
}
