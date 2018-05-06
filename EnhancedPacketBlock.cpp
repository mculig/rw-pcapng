/*
 * EnhancedPacketBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "EnhancedPacketBlock.h"
#include "string.h"

EnhancedPacketBlock::EnhancedPacketBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer):Block(block_type, block_length)  {
	//Helper variable for buffer reading
	unsigned int buffer_location=0;
	//Helper variable for adding options to the option list
	Option *temp;
	options_list=new std::list<Option>;
	//Move through the buffer to read the required data
	interface_id=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	timestamp_high=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	timestamp_low=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	captured_packet_length=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	original_packet_length=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	packet_data=new uint8_t[captured_packet_length];
	memcpy(packet_data,buffer+buffer_location,sizeof(uint8_t)*captured_packet_length);
	//I don't copy the data with the padding out of convenience, but must skip the padding as well
	buffer_location+=(captured_packet_length+4-captured_packet_length%4);
	//If there is more than 4 bytes remaining we know there is at least an option
	//before the second length field at the end of the block
	while((block_length-8)>(buffer_location+4))
	{
		temp=new Option(buffer+buffer_location);
		options_list->push_back(*temp);
		buffer_location+=temp->paddedLength();
		//Break the loop if an end of options option is read
		if(temp->option_type==OPT_ENDOFOPT)
			break;
	}
}

EnhancedPacketBlock::~EnhancedPacketBlock() {
	//Free memory. Clearing a list should call destructors for all objects and thus clean up memory
	options_list->clear();
	delete options_list;
	delete packet_data;
}

