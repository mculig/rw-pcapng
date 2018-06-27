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
#include "InterfaceStatisticsBlock.h"
#include "SimplePacketBlock.h"
#include "CustomBlock.h"
#include "iostream"

//Byte order magic for little endian and big endian. Used to distinguish between the two in the Section Header Block
#define BOM_LE 0x1A2B3C4D
#define BOM_BE 0x4D3C2B1A

pcapngReader::pcapngReader(std::string path) {
	//Open the capture as a binary file
	capture.open(path, std::ios::in | std::ios::binary);
	//By default this will be false and that will mean little endian
	endianness=false;
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
	//Make sure to delete the previous block from memory.
	delete block;
	//We need to read the byte order magif if we're dealing with a section header block
	uint32_t bom;
	uint32_t type;
	uint32_t length;
	//Read the block type and length
	capture.read((char*) &type, sizeof(uint32_t));
	capture.read((char*) &length, sizeof(uint32_t));
	//If we've reached the end of file we need to return a nullptr to signal that
	if(capture.eof())
	{
		return nullptr;
	}
	//If we're at the beginning of a section
	if(type==SECTION_HEADER_BLOCK)
	{
		//Read the BOM
		capture.read((char*) &bom, sizeof(uint32_t));
		if(bom==BOM_LE)
		{
			//If we're little endian, we've got to set endianness to false
			endianness=false;
		}
		else if(bom==BOM_BE)
		{
			//Gotta set the endianness to true
			endianness=true;
		}
	}
	//If we're reading a big endian block we need to reverse type and length as they'll be in a different byte order
	if(endianness==true)
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
			std::cout<<"Found Section Header Block\n";
			block=new SectionHeaderBlock(type, length, bom, buffer, &endianness);
			break;
		case INTERFACE_DESCRIPTION_BLOCK:
			std::cout<<"Found Interface Description Block\n";
			block=new InterfaceDescriptionBlock(type, length, buffer, &endianness);
			break;
		case ENHANCED_PACKET_BLOCK:
			std::cout<<"Found Enhanced Packet Block\n";
			block=new EnhancedPacketBlock(type, length, buffer, &endianness);
			break;
		case SIMPLE_PACKET_BLOCK:
			std::cout<<"Found SimplePacketBlock\n";
			block=new SimplePacketBlock(type, length, buffer, &endianness);
			break;
		case NAME_RESOLUTION_BLOCK:
			std::cout<<"Found Name Resolution Block\n";
			block=new NameResolutionBlock(type, length, buffer, &endianness);
			break;
		case INTERFACE_STATISTICS_BLOCK:
			std::cout<<"Found Interface Statistics Block\n";
			break;
		case CUSTOM_BLOCK_COPY_ALLOWED:
			std::cout<<"Found Custom Block which may be copied to new file\n";
			block=new CustomBlock(type, length, buffer, &endianness);
			break;
		case CUSTOM_BLOCK_COPY_FORBIDDEN:
			std::cout<<"Found Custom Block which may NOT be copied to new file\n";
			block=new CustomBlock(type, length, buffer, &endianness);
			break;
		default:
			//Return a nullptr to indicate the block type didn't match any known blocks. This means we've likely encountered an arror
			std::cout<<"Unknown block type: "<<(int)type<<" likely an error!";
			return nullptr;
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

