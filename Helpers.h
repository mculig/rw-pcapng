/*
 * Helpers.h
 *
 *  Created on: Jun 18, 2018
 *      Author: mislav
 */

#include <stdint.h>

#ifndef HELPERS_H_
#define HELPERS_H_

class Helpers {
public:
	Helpers();
	virtual ~Helpers();
	static void readBuffer(uint8_t* buffer, uint8_t* target, uint64_t size, uint32_t* readIndex, bool endianness);
};

#endif /* HELPERS_H_ */
