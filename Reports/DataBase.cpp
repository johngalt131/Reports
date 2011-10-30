/*
 * DataBase.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub

}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
}

void DataBase::setInputFile(std::string filename)
{
	this->inputFile = filename;
}

std::string DataBase::getInputFile(void)
{
	return this->inputFile;
}


