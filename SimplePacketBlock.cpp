/*
 * SimplePacketBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "SimplePacketBlock.h"
#include "Helpers.h"

SimplePacketBlock::SimplePacketBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length)  {
	uint32_t buffer_location=0;
	Helpers::readBuffer(buffer,(uint8_t*) &original_packet_length,sizeof(original_packet_length),&buffer_location,*endianness);
	//The total length of the packet data (including padding) is the length of the block minus the block type (4B), block total length(4B), original packet length(4B)
	//and the repeated block total length (4B) which totals 16B
	packet_data=new uint8_t[block_length-16];
	Helpers::readBuffer(buffer,(uint8_t*) &packet_data,sizeof(packet_data),&buffer_location,*endianness);
	//A simple packet block has no options
}

SimplePacketBlock::~SimplePacketBlock() {
	//Free memory
	delete packet_data;
}

