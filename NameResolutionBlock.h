/*
 * NameResolutionBlock.h
 *
 *  Created on: Jun 17, 2018
 *      Author: mislav
 */

#ifndef NAMERESOLUTIONBLOCK_H_
#define NAMERESOLUTIONBLOCK_H_

#include "NameResolutionBlockRecord.h"
#include "list"
#include "Option.h"
#include "Block.h"

enum NRB_TYPE{
NRB_RECORD_END=0x0000,
NRB_RECORD_IPv4=0x0001,
NRB_RECORD_IPv6=0x0002
};

class NameResolutionBlock: public Block{
private:
	std::list<NameResolutionBlockRecord>* records;
	std::list<Option>* options;
public:
	NameResolutionBlock(uint32_t block_type, uint32_t block_length, uint32_t bom, uint8_t* buffer, bool* endianness);
	virtual ~NameResolutionBlock();
};

#endif /* NAMERESOLUTIONBLOCK_H_ */
