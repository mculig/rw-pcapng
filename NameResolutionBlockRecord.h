/*
 * NameResolutionBlockRecord.h
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#ifndef NAMERESOLUTIONBLOCKRECORD_H_
#define NAMERESOLUTIONBLOCKRECORD_H_

#include "cstdint"
#include "NameResolutionBlockRecord.h"
#include "list"
#include "Option.h"

class NameResolutionBlockRecord {
	uint16_t record_type;
	uint16_t record_length;
	std::list<NameResolutionBlockRecord> records;
	std::list<Option> options;
public:
	NameResolutionBlockRecord();
	virtual ~NameResolutionBlockRecord();
};

#endif /* NAMERESOLUTIONBLOCKRECORD_H_ */
