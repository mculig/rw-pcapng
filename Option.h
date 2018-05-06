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
	uint16_t option_code;
	uint16_t option_length;
	uint8_t *option_value;
public:
	Option();
	virtual ~Option();
};

#endif /* OPTION_H_ */
