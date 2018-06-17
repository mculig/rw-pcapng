/*
 * SectionHeaderBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef SECTIONHEADERBLOCK_H_
#define SECTIONHEADERBLOCK_H_

#include "Block.h"
#include "Option.h"
#include "list"

class SectionHeaderBlock: public Block {
public:
	uint32_t byte_order_magic;
	uint16_t major_version;
	uint16_t minor_version;
	uint64_t section_length;
	std::list<Option> *options_list;
public:
	SectionHeaderBlock(uint32_t block_type, uint32_t block_length, uint32_t bom, uint8_t* buffer, bool* endianness);
	virtual ~SectionHeaderBlock();
};

#endif /* SECTIONHEADERBLOCK_H_ */
