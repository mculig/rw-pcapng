/*
 * CustomBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef CUSTOMBLOCK_H_
#define CUSTOMBLOCK_H_

#include "Block.h"
#include "list"
#include "Option.h"

class CustomBlock: public Block {
	uint32_t private_enterprise_number;
	uint8_t* custom_data;
	std::list<Option>* options;
public:
	CustomBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness);
	virtual ~CustomBlock();
};

#endif /* CUSTOMBLOCK_H_ */
