/*
 * IPv4NameResolutionBlockRecord.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "IPv4NameResolutionBlockRecord.h"
#include "string.h"

IPv4NameResolutionBlockRecord::IPv4NameResolutionBlockRecord(uint8_t* buffer, uint16_t record_type, uint16_t record_length):NameResolutionBlockRecord(record_type, record_length) {
	//0 is a valid record length...why such a record other than the end record would exist is beyond me.
	if(record_length==0)
		return;
	uint16_t buffer_location=0;
	memcpy(&ipv4_addr,buffer,sizeof(ipv4_addr));
	buffer_location+=sizeof(ipv4_addr);
	dns_entries=new char[record_length];
	//Copy the entries, ignore the padding. We'll have to think about padding when writing.
	memcpy(dns_entries,buffer,sizeof(char)*record_length);
}

IPv4NameResolutionBlockRecord::~IPv4NameResolutionBlockRecord() {
	// Free memory
	delete dns_entries;
}

