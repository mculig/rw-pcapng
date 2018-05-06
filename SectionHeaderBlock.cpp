/*
 * SectionHeaderBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "SectionHeaderBlock.h"

SectionHeaderBlock::SectionHeaderBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer):Block(block_type, block_length) {
	//Helper variable for buffer reading
	unsigned int buffer_location=0;
	//Helper variable for adding options to the option list
	Option *temp;
	options=new std::list<Option>;
	//Move through the buffer to read the required data
	byte_order_magic=*(buffer+buffer_location);
	buffer_location+=sizeof(uint32_t);
	major_version=*(buffer+buffer_location);
	buffer_location+=sizeof(uint16_t);
	minor_version=*(buffer+buffer_location);
	buffer_location+=sizeof(uint16_t);
	section_length=*(buffer+buffer_location);
	//If there is more than 7 bytes remaining we know there is at least an option
	//before the second length field at the end of the block
	while(block_length-8>buffer_location+7)
	{
		temp=new Option(buffer+buffer_location);
		options->push_back(*temp);
		buffer_location+=temp->length();
		//Break the loop if an end of options option is read
		if(temp->type()==OPT_ENDOFOPT)
			break;
	}
}

SectionHeaderBlock::~SectionHeaderBlock() {
	//Free memory. Clearing a list should call destructors for all objects and thus clean up memory
	options->clear();
	delete options;
}

