/*
 * EnhancedPacketBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "EnhancedPacketBlock.h"
#include "string.h"
#include "Option.h"
#include "list"
#include "Helpers.h"

EnhancedPacketBlock::EnhancedPacketBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness):Block(block_type, block_length)  {
	uint32_t buffer_location=0;
	Helpers::readBuffer(buffer,(uint8_t*) &interface_id,sizeof(interface_id),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &timestamp_high,sizeof(timestamp_high),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &timestamp_low,sizeof(timestamp_low),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &captured_packet_length,sizeof(captured_packet_length),&buffer_location,*endianness);
	Helpers::readBuffer(buffer,(uint8_t*) &original_packet_length,sizeof(original_packet_length),&buffer_location,*endianness);
	//Padding not included in length so this will be just the captured packet
	packet_data=new uint8_t[captured_packet_length];
	memcpy(packet_data, buffer+buffer_location,captured_packet_length);
	//Calculate the padding and move the buffer accordingly
	int padding=captured_packet_length-(captured_packet_length%4);
	buffer_location+=captured_packet_length+padding;
	//Create the options list
	options_list=new std::list<Option>();
	//Use the helper to read the options. This allows all the logic to be in one easy-to-fix place
	Helpers::readOptions(options_list, buffer, &buffer_location ,block_length, endianness);
}

EnhancedPacketBlock::~EnhancedPacketBlock() {
	//Free memory
	delete packet_data;
	options_list->clear();
	delete options_list;
}

