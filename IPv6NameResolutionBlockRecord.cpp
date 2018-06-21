/*
 * IPv6NameResolutionBlockRecord.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "IPv6NameResolutionBlockRecord.h"
#include "string.h"

IPv6NameResolutionBlockRecord::IPv6NameResolutionBlockRecord(uint8_t* buffer, uint16_t record_type, uint16_t record_length):NameResolutionBlockRecord(record_type, record_length) {
	//0 is a valid record length...why such a record other than the end record would exist is beyond me.
	if(record_length==0)
		return;
	uint16_t buffer_location=0;
	//Read the ipv6 address
	memcpy(&ipv6_addr,buffer,sizeof(uint8_t)*16);
	buffer_location+=16;
	dns_entries=new char[record_length];
	//Copy the entries, ignore the padding. We'll have to think about padding when writing.
	memcpy(dns_entries,buffer,sizeof(char)*record_length);
}

IPv6NameResolutionBlockRecord::~IPv6NameResolutionBlockRecord() {
	delete dns_entries;
}

