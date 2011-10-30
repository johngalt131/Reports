/*
 * Financial.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#include "Financial.h"
#include "fstream"
#include "stdlib.h"
#include "stdio.h"
#include "tinyxml.h"

Financial::Financial() {
	// TODO Auto-generated constructor stub

}

Financial::~Financial() {
	// TODO Auto-generated destructor stub
}

void Financial::parseFile()
{
	FILE *databasefile = fopen(this->getInputFile().c_str(),"r");
	TiXmlDocument *Doc; //= new TiXmlDocument(this->getInputFile().c_str());
	Doc->LoadFile(databasefile);
	TiXmlElement *root = Doc->RootElement();
	std::cout << root->FirstChild()->Value()<< std::endl;
}


