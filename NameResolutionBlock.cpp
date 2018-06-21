/*
 * NameResolutionBlock.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: mislav
 */

#include "NameResolutionBlock.h"
#include "Helpers.h"
#include "IPv4NameResolutionBlockRecord.h"
#include "IPv6NameResolutionBlockRecord.h"
#include "string.h"

NameResolutionBlock::NameResolutionBlock(uint32_t block_type, uint32_t block_length, uint32_t bom, uint8_t* buffer, bool* endianness):Block(block_type, block_length)  {
	options=new std::list<Option>;
	records=new std::list<NameResolutionBlockRecord>;
	uint32_t buffer_location=0;
	bool endRecord=false;
	uint16_t record_type;
	uint16_t record_value_length;
	uint8_t* recordBuffer;
	while(!endRecord)
	{
		Helpers::readBuffer(buffer,(uint8_t*) &record_type,sizeof(record_type),&buffer_location,*endianness);
		Helpers::readBuffer(buffer,(uint8_t*) &record_value_length, sizeof(record_value_length), &buffer_location, *endianness);
		//If the record is 0, we have a nullptr buffer because we still need to pass one, but it won't be read. Otherwise we create an appropriate length buffer
		if(record_value_length==0)
			recordBuffer=nullptr;
		else
		{
			recordBuffer=new uint8_t[record_value_length];
			memcpy(recordBuffer,buffer, sizeof(uint8_t)*record_value_length);
		}
		if(record_type==NRB_RECORD_IPv4)
		{
			IPv4NameResolutionBlockRecord* tmp=new IPv4NameResolutionBlockRecord(recordBuffer,record_type, record_value_length);
			records->push_back(*tmp);
			delete tmp;
		}
		else if(record_type==NRB_RECORD_IPv6)
		{
			IPv6NameResolutionBlockRecord* tmp=new IPv6NameResolutionBlockRecord(recordBuffer,record_type,record_value_length);
			records->push_back(*tmp);
			delete tmp;
		}
		else if(record_type==NRB_RECORD_END)
		{
			NameResolutionBlockRecord* tmp=new NameResolutionBlockRecord(record_type, record_value_length);
			records->push_back(*tmp);
			delete tmp;
			endRecord=true;
		}
		//Skip ahead by the length + the padding so we can read the next option
		buffer_location+=record_value_length+Helpers::calculatePaddingLength(record_value_length);
	}
	Helpers::readOptions(options, buffer, &buffer_location, block_length, endianness);
}

NameResolutionBlock::~NameResolutionBlock() {
	//Free memory
	records->clear();
	delete records;
	options->clear();
	delete options;
}

