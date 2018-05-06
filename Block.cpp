/*
 * Block.cpp
 *
 *  Created on: May 4, 2018
 *      Author: mislav
 */

#include "Block.h"
#include "fstream"

Block::Block()
{

}

Block::Block(uint32_t block_type, uint32_t block_length) {

	this->block_type=block_type;
	this->block_length=block_length;
}

Block::~Block() {

}
uint32_t Block::type()
{
	return block_type;
}
uint32_t Block::length()
{
	return block_length;
}
