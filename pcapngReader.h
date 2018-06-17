/*
 * pcapngReader.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef PCAPNGREADER_H_
#define PCAPNGREADER_H_

#include "string"
#include "fstream"
#include "Block.h"

class pcapngReader {
private:
	std::ifstream capture;
	uint8_t* buffer;
	Block* block;
	bool endianness;
public:
	void reverseEndian(uint32_t* var);
	pcapngReader(std::string path);
	virtual ~pcapngReader();
	Block* next_block();
};

#endif /* PCAPNGREADER_H_ */
