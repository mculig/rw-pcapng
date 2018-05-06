/*
 * pcapngReader.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef PCAPNGREADER_H_
#define PCAPNGREADER_H_

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


#include "string"
#include "fstream"
#include "Block.h"

class pcapngReader {
private:
	std::ifstream capture;
	uint8_t* buffer;
	Block* block;
public:
	pcapngReader(std::string path);
	virtual ~pcapngReader();
	Block* next_block();
};

#endif /* PCAPNGREADER_H_ */
