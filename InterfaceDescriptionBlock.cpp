/*
 * InterfaceDescriptionBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "InterfaceDescriptionBlock.h"

InterfaceDescriptionBlock::InterfaceDescriptionBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length, endianness) {

}

InterfaceDescriptionBlock::~InterfaceDescriptionBlock() {

}
