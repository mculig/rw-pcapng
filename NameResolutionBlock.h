/*
 * NameResolutionBlock.h
 *
 *  Created on: Jun 17, 2018
 *      Author: mislav
 */

#ifndef NAMERESOLUTIONBLOCK_H_
#define NAMERESOLUTIONBLOCK_H_

#include "NameResolutionBlockRecord.h"
#include "list"
#include "Option.h"

class NameResolutionBlock {
private:
	std::list<NameResolutionBlockRecord> records;
	std::list<Option> options;
public:
	NameResolutionBlock();
	virtual ~NameResolutionBlock();
};

#endif /* NAMERESOLUTIONBLOCK_H_ */
