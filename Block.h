/*
 * Block.h
 *
 *  Created on: May 4, 2018
 *      Author: mislav
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "cstdint"
#include "fstream"


class Block {

private:
uint32_t block_type;
uint32_t block_length;


public:
	Block();
	Block(uint32_t block_type, uint32_t block_length);
	virtual ~Block();
	uint32_t type();
	uint32_t length();
};

#endif /* BLOCK_H_ */
