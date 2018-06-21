/*
 * IPv4NameResolutionBlockRecord.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef IPV4NAMERESOLUTIONBLOCKRECORD_H_
#define IPV4NAMERESOLUTIONBLOCKRECORD_H_

#include "NameResolutionBlockRecord.h"

class IPv4NameResolutionBlockRecord: public NameResolutionBlockRecord {
	uint32_t ipv4_addr;
	char* dns_entries;
public:
	IPv4NameResolutionBlockRecord(uint8_t* buffer, uint16_t record_type, uint16_t record_length);
	virtual ~IPv4NameResolutionBlockRecord();
};

#endif /* IPV4NAMERESOLUTIONBLOCKRECORD_H_ */
