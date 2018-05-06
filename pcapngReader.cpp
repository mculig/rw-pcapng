/*
 * pcapngReader.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "pcapngReader.h"
#include "string"
#include "SectionHeaderBlock.h"

pcapngReader::pcapngReader(std::string path) {
	//Open the capture as a binary file
	capture.open(path, std::ios::in | std::ios::binary);

}

Block* pcapngReader::next_block()
{
	//Make sure to delete the previous block from memory.
	delete block;
	uint32_t type;
	uint32_t length;
	//Read the block type and length
	capture.read((char*) &type, sizeof(uint32_t));
	capture.read((char*) &length, sizeof(uint32_t));
	//Create a buffer of appropriate size
	buffer=new uint8_t[length-8];
	//Read the block data into the buffer
	capture.read((char*) &buffer, (length-8)*sizeof(uint8_t));
	//Create different blocks based on type
	switch(type)
	{
		case SECTION_HEADER_BLOCK:
			block=new SectionHeaderBlock(type, length,buffer);
			break;
		case INTERFACE_DESCRIPTION_BLOCK:
			break;
		case ENHANCED_PACKET_BLOCK:
			break;
		case SIMPLE_PACKET_BLOCK:
			break;
		case NAME_RESOLUTION_BLOCK:
			break;
		case INTERFACE_STATISTICS_BLOCK:
			break;
		case CUSTOM_BLOCK_COPY_ALLOWED:
			break;
		case CUSTOM_BLOCK_COPY_FORBIDDEN:
			break;
		default:
			break;
	}

	//Delete the buffer. Memory leaks are bad, m'kay?
	delete buffer;
	return block;
}

pcapngReader::~pcapngReader() {
	//Free memory from the last read block
	delete block;
	//Close the file
	capture.close();
}

