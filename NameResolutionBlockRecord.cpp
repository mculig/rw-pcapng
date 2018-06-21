/*
 * NameResolutionBlockRecord.cpp
 *
 *  Created on: May 6, 2018
 *      Author: mislav
 */

#include "NameResolutionBlockRecord.h"

NameResolutionBlockRecord::NameResolutionBlockRecord(uint16_t record_type, uint16_t record_length) {
	this->record_type=record_type;
	this->record_length=record_length;

}

NameResolutionBlockRecord::~NameResolutionBlockRecord() {
	// TODO Auto-generated destructor stub
}

