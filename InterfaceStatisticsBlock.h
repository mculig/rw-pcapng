/*
 * InterfaceStatisticsBlock.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef INTERFACESTATISTICSBLOCK_H_
#define INTERFACESTATISTICSBLOCK_H_

#include "Block.h"
#include "list"
#include "Option.h"

class InterfaceStatisticsBlock: public Block {
	uint32_t interface_id;
	uint32_t timestamp_high;
	uint32_t timestamp_low;
	std::list<Option>* options;
public:
	InterfaceStatisticsBlock(uint32_t block_type, uint32_t block_length, uint8_t* buffer, bool* endianness);
	virtual ~InterfaceStatisticsBlock();
};

#endif /* INTERFACESTATISTICSBLOCK_H_ */
