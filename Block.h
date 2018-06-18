/*
 * Block.h
 *
 *  Created on: May 4, 2018
 *      Author: mislav
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "cstdint"
#include "fstream"


//We'll put block types here
enum BLOCK_TYPE{
SECTION_HEADER_BLOCK=0x0A0D0D0A,
INTERFACE_DESCRIPTION_BLOCK=0x00000001,
ENHANCED_PACKET_BLOCK=0x00000006,
SIMPLE_PACKET_BLOCK=0x00000003,
NAME_RESOLUTION_BLOCK=0x00000004,
INTERFACE_STATISTICS_BLOCK=0x00000005,
CUSTOM_BLOCK_COPY_ALLOWED=0x00000BAD,
CUSTOM_BLOCK_COPY_FORBIDDEN=0x40000BAD,
};

class Block {

private:
uint32_t block_type;
uint32_t block_length;

public:
	Block();
	Block(uint32_t block_type, uint32_t block_length);
	virtual ~Block();
	uint32_t type();
	uint32_t length();
};

#endif /* BLOCK_H_ */
