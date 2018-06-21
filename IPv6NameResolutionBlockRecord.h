/*
 * IPv6NameResolutionBlockRecord.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef IPV6NAMERESOLUTIONBLOCKRECORD_H_
#define IPV6NAMERESOLUTIONBLOCKRECORD_H_

#include "NameResolutionBlockRecord.h"

class IPv6NameResolutionBlockRecord: public NameResolutionBlockRecord {
	uint8_t ipv6_addr[16];
	char* dns_entries;
public:
	IPv6NameResolutionBlockRecord(uint8_t* buffer, uint16_t record_type, uint16_t record_length);
	virtual ~IPv6NameResolutionBlockRecord();
};

#endif /* IPV6NAMERESOLUTIONBLOCKRECORD_H_ */
