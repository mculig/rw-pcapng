/*
 * InterfaceDescriptionBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef INTERFACEDESCRIPTIONBLOCK_H_
#define INTERFACEDESCRIPTIONBLOCK_H_

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
	InterfaceDescriptionBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness);
	virtual ~InterfaceDescriptionBlock();
	uint16_t linkType();
	uint16_t snapLength();
	std::list<Option>* options();
};

#endif /* INTERFACEDESCRIPTIONBLOCK_H_ */
