/*
 * DataBase.h
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#define TIXML_USE_STL

#include "tinyxml.h"
#include "string"

class DataBase {
public:
	DataBase();
	virtual ~DataBase();
	virtual void parseFile() = 0;
	void setInputFile(std::string filename);
	std::string getInputFile(void);
private:
	std::string inputFile;
};

class iTunesLibrary : public DataBase {

};
#endif /* DATABASE_H_ */
