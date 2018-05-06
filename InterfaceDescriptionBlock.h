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
	uint16_t link_type;
	uint16_t reserved;
	uint32_t snap_length;
	std::list<Option> options;
public:
	InterfaceDescriptionBlock();
	virtual ~InterfaceDescriptionBlock();
};

#endif /* INTERFACEDESCRIPTIONBLOCK_H_ */
