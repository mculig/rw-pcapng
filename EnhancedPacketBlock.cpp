/*
 * EnhancedPacketBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "EnhancedPacketBlock.h"
#include "string.h"

EnhancedPacketBlock::EnhancedPacketBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length)  {

}

EnhancedPacketBlock::~EnhancedPacketBlock() {

}

