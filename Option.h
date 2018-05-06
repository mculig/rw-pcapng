/*
 * Option.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef OPTION_H_
#define OPTION_H_

#include "cstdint"

class Option {
	uint16_t option_type;
	uint16_t option_length;
	uint8_t *option_value;
public:
	Option(uint8_t* buffer);
	virtual ~Option();
	uint16_t length();
	uint16_t type();

};

#endif /* OPTION_H_ */