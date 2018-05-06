/*
 * SimplePacketBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef SIMPLEPACKETBLOCK_H_
#define SIMPLEPACKETBLOCK_H_

#include "Block.h"

class SimplePacketBlock: public Block {
	uint32_t original_packet_length;
	uint8_t* packet_data;
public:
	SimplePacketBlock();
	virtual ~SimplePacketBlock();
};

#endif /* SIMPLEPACKETBLOCK_H_ */
