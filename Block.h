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

//Block type definitions
//Section header value in HEX. This is a palindrome and is always the same
#define SECTION_HEADER_BLOCK 0x0A0D0D0A
//Interface Description Block
#define INTERFACE_DESCRIPTION_BLOCK 0x00000001
//Enhanced Packet Block
#define ENHANCED_PACKET_BLOCK 0x00000006
//Simple Packet Block
#define SIMPLE_PACKET_BLOCK 0x00000003
//Name Resolution Block
#define NAME_RESOLUTION_BLOCK 0x00000004
//Interface Statistics Block
#define INTERFACE_STATISTICS_BLOCK 0x00000005
//Custom Block that may be copied to new file
#define CUSTOM_BLOCK_COPY_ALLOWED 0x00000BAD
//Custom Block that must not be copied to new file
#define CUSTOM_BLOCK_COPY_FORBIDDEN 0x40000BAD

class Block {

uint32_t block_type;
uint32_t block_length;


//TODO Add options to blocks and read them properly


public:
	Block();
	virtual ~Block();
};

#endif /* BLOCK_H_ */
