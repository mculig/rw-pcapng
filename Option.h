/*
 * Option.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef OPTION_H_
#define OPTION_H_

#include "cstdint"

//Option type will be an enum and since they can have multiple names for the same value we'll just toss them all here
//This will be a large enum but it's easier having it all in one place
//For easier manipulation we'll leave the type as an integer, but will do checks against this enum using casts
enum OPTION_TYPE {
//Same for all blocks
OPT_ENDOFOPT=0,
OPT_COMMENT=1,
OPT_CUSTOM_UTF8_COPY_ALLOWED=2988,
OPT_CUSTOM_UTF8_COPY_FORBIDDEN=2989,
OPT_CUSTOM_BINARY_COPY_ALLOWED=19372,
OPT_CUSTOM_BINARY_COPY_FORBIDDEN=19373,
//Interface statistics block
ISB_STARTTIME=2,
ISB_ENDTIME=3,
ISB_IFRECV=4,
ISB_IFDROP=5,
ISB_FILTERACCEPT=6,
ISB_OSDROP=7,
ISB_USRDELIV=8,
//Interface description block
IF_NAME=2,
IF_DESCRIPTION=3,
IF_IPv4=4,
IF_IPv6=5,
IF_MAC=6,
IF_EUI=7,
IF_SPEED=8,
IF_TSRESOL=9,
IF_TZONE=10,
IF_FILTER=11,
IF_OS=12,
IF_FCSLEN=13,
IF_TSOFFSET=14,
//Enhanced packet block
EPB_FLAGS=2,
EPB_HASH=3,
EPB_DROPCOUNT=4,
//Section header block
SHB_HARDWARE=2,
SHB_OS=3,
SHB_USERAPPL=4,
//Name resolution block
NS_DNSNAME=2,
NS_DNSIP4ADDR=3,
NS_DNSIP6ADDR=4
};

class Option {
public:
	uint16_t type;
	uint16_t option_length;
	uint8_t *option_value;
public:
	Option(uint8_t* buffer);
	virtual ~Option();
	uint16_t paddedLength();

};

#endif /* OPTION_H_ */
