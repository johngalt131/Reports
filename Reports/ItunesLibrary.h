/*
 * ItunesLibrary.h
 *
 *  Created on: Oct 30, 2011
 *      Author: travisstaley
 */

#ifndef ITUNESLIBRARY_H_
#define ITUNESLIBRARY_H_

#include "ItunesRecord.h"
#include "DataBase.h"

class ItunesLibrary: public ItunesRecord, public DataBase {
public:
	ItunesLibrary();
	virtual ~ItunesLibrary();
	void parseFile();
};

#endif /* ITUNESLIBRARY_H_ */
