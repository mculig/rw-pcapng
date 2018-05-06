/*
 * InterfaceDescriptionBlock.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "InterfaceDescriptionBlock.h"

InterfaceDescriptionBlock::InterfaceDescriptionBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer):Block(block_type, block_length) {
	//Helper variable for buffer reading
		unsigned int buffer_location=0;
		//Helper variable for adding options to the option list
		Option *temp;
		options_list=new std::list<Option>;
		//Move through the buffer to read the required data
		link_type=*(buffer+buffer_location);
		buffer_location+=sizeof(uint16_t);
		reserved=*(buffer+buffer_location);
		buffer_location+=sizeof(uint16_t);
		snap_length=*(buffer+buffer_location);
		buffer_location+=sizeof(uint32_t);
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

InterfaceDescriptionBlock::~InterfaceDescriptionBlock() {
	//Free memory. Clearing a list should call destructors for all objects and thus clean up memory
		options_list->clear();
		delete options_list;
}
