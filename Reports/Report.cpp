/*
 * Report.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */



#include "Financial.h"
#include "DataBase.h"
#include "string"

int main (){
	static const std::string filename = "/Users/travisstaley/database.xml";
	DataBase *finance = new Financial();
	finance->setInputFile(filename);
	
	return 0;
}
