/*
 * EnhancedPacketBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef ENHANCEDPACKETBLOCK_H_
#define ENHANCEDPACKETBLOCK_H_

#include "Block.h"
#include "Option.h"
#include "list"

class EnhancedPacketBlock: public Block {
public:
	uint32_t interface_id;
	uint32_t timestamp_high;
	uint32_t timestamp_low;
	uint32_t captured_packet_length;
	uint32_t original_packet_length;
	uint8_t* packet_data;
	std::list<Option>* options_list;
public:
	EnhancedPacketBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness);
	virtual ~EnhancedPacketBlock();
};

#endif /* ENHANCEDPACKETBLOCK_H_ */
