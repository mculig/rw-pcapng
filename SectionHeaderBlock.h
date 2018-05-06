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
	uint32_t byte_order_magic;
	uint16_t major_version;
	uint16_t minor_version;
	uint64_t section_length;
	std::list<Option> options;
public:
	SectionHeaderBlock();
	virtual ~SectionHeaderBlock();
};

#endif /* SECTIONHEADERBLOCK_H_ */
