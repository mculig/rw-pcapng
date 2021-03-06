/*
 * Helpers.h
 *
 *  Created on: Jun 18, 2018
 *      Author: mislav
 */

#include <stdint.h>
#include "list"
#include "Option.h"

#ifndef HELPERS_H_
#define HELPERS_H_

class Helpers {
public:
	Helpers();
	virtual ~Helpers();
	static void readBuffer(uint8_t* buffer, uint8_t* target, uint64_t size, uint32_t* readIndex, bool endianness);
	static void readOptions(std::list<Option>* options, uint8_t* buffer, uint32_t* buffer_location ,uint32_t block_length, bool* endianness);
	static int calculatePaddingLength(uint32_t length);
};

#endif /* HELPERS_H_ */
