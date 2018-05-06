/*
 * Block.h
 *
 *  Created on: May 4, 2018
 *      Author: mislav
 */

#ifndef BLOCK_H_
#define BLOCK_H_

//Options that share their type in all subclasses of Block are here to avoid defining them over and over
#define OPT_ENDOFOPT 0
#define OPT_COMMENT 1
#define OPT_CUSTOM_UTF8_COPY_ALLOWED 2988
#define OPT_CUSTOM_UTF8_COPY_FORBIDDEN 2989
#define OPT_CUSTOM_BINARY_COPY_ALLOWED 19372
#define OPT_CUSTOM_BINARY_COPY_FORBIDDEN 19373

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
