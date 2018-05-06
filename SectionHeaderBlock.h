/*
 * SectionHeaderBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef SECTIONHEADERBLOCK_H_
#define SECTIONHEADERBLOCK_H_

//Option types definition for this block. Option types have to be defined for every block since pcapng reuses type numbers
#define OPT_ENDOFOPT 0
#define OPT_COMMENT 1
#define OPT_CUSTOM_UTF8_COPY_ALLOWED 2988
#define OPT_CUSTOM_UTF8_COPY_FORBIDDEN 2989
#define OPT_CUSTOM_BINARY_COPY_ALLOWED 19372
#define OPT_CUSTOM_BINARY_COPY_FORBIDDEN 19373
#define SHB_HARDWARE 2
#define SHB_OS 3
#define SHB_USERAPPL 4

#include "Block.h"
#include "Option.h"
#include "list"

class SectionHeaderBlock: public Block {
	uint32_t byte_order_magic;
	uint16_t major_version;
	uint16_t minor_version;
	uint64_t section_length;
	std::list<Option> *options;
public:
	SectionHeaderBlock(uint32_t block_type, uint32_t block_length,uint8_t* buffer);
	virtual ~SectionHeaderBlock();
};

#endif /* SECTIONHEADERBLOCK_H_ */
