/*
 * InterfaceDescriptionBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef INTERFACEDESCRIPTIONBLOCK_H_
#define INTERFACEDESCRIPTIONBLOCK_H_

//This block can really have a lot of options
#define IF_NAME 2
#define IF_DESCRIPTION 3
#define IF_IPv4 4
#define IF_IPv6 5
#define IF_MAC 6
#define IF_EUI 7
#define IF_SPEED 8
#define IF_TSRESOL 9
#define IF_TZONE 10
#define IF_FILTER 11
#define IF_OS 12
#define IF_FCSLEN 13
#define IF_TSOFFSET 14


#include "Block.h"
#include "Option.h"
#include "list"

class InterfaceDescriptionBlock: public Block {
public:
	uint16_t link_type;
	uint16_t reserved;
	uint32_t snap_length;
	std::list<Option> *options_list;
public:
	InterfaceDescriptionBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer);
	virtual ~InterfaceDescriptionBlock();
	uint16_t linkType();
	uint16_t snapLength();
	std::list<Option>* options();
};

#endif /* INTERFACEDESCRIPTIONBLOCK_H_ */
