/*
 * pcapngReader.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "pcapngReader.h"
#include "string"
#include "SectionHeaderBlock.h"
#include "InterfaceDescriptionBlock.h"
#include "EnhancedPacketBlock.h"
#include "NameResolutionBlock.h"

#define BOM_LE 0x1A2B3C4D
#define BOM_BE 0x4D3C2B1A

pcapngReader::pcapngReader(std::string path) {
	//Open the capture as a binary file
	capture.open(path, std::ios::in | std::ios::binary);

}

void pcapngReader::reverseEndian(uint32_t* var)
{
	uint32_t tmp;
	int j=3;
	for(int i=0;i<4;i++)
	{
		//Swap the bits around
		*(((uint8_t*) &tmp)+j)=*(((uint8_t*) var)+i);
		j--;
	}
	*var=tmp;
}

Block* pcapngReader::next_block()
{
	//By default this will be false and that will mean little endian
	endianness=false;
	//We need to read the byte order magif if we're dealing with a section header block
	uint32_t bom;
	//Make sure to delete the previous block from memory.
	delete block;
	uint32_t type;
	uint32_t length;
	//Read the block type and length
	capture.read((char*) &type, sizeof(uint32_t));
	capture.read((char*) &length, sizeof(uint32_t));
	//If we're at the beginning of a section
	if(type==SECTION_HEADER_BLOCK)
	{
		//Read the BOM
		capture.read((char*) &bom, sizeof(uint32_t));
		if(bom==BOM_LE)
		{
			//If we're little endian, we're fine
		}
		else if(bom==BOM_BE)
		{
			//If we're big endian, or bytes are reversed and our length is wrong and must be adjusted before we create a buffer and read.
			//We also need to switch type around
			reverseEndian(&type);
			reverseEndian(&length);
			//Gotta set the endianness to true
			endianness=true;
		}
	}
	//Otherwise if we're reading a big endian file
	else if(endianness=true)
	{
		reverseEndian(&type);
		reverseEndian(&length);
	}
	//Create a buffer of appropriate size
	buffer=new uint8_t[length-8];
	//Read the block data into the buffer
	capture.read((char*) &buffer, (length-8)*sizeof(uint8_t));
	//Create different blocks based on type
	switch(type)
	{
		case SECTION_HEADER_BLOCK:
			block=new SectionHeaderBlock(type, length, bom, buffer, &endianness);
			break;
		case INTERFACE_DESCRIPTION_BLOCK:
			block=new InterfaceDescriptionBlock(type, length, buffer, &endianness);
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

