/*
 * Financial.h
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#ifndef FINANCIAL_H_
#define FINANCIAL_H_

#include "string"
#include "DataBase.h"

class Financial : public DataBase{
public:
	Financial();
	virtual ~Financial();
	void parseFile();
};

#endif /* FINANCIAL_H_ */
