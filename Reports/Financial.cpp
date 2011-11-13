/*
 * Financial.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#include "Financial.h"
#include "FinancialRecord.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "tinyxml.h"

Financial::Financial(std::string filename) {
  this->setInputFile(filename);
  this->parseFile();
}

Financial::~Financial() {
  // TODO Auto-generated destructor stub
}

void Financial::thisMonth() {

  std::vector<Reports::FinancialRecord>::iterator itr;
  for(itr = this->records.begin(); itr != this->records.end(); itr++){
    std::cout << itr->Notes
	      << "\n"
	      << std::endl;
  }
}

void Financial::parseFile()
{
  // Test that the document exists, and is readable
  FILE *databasefile = fopen(this->getInputFile().c_str(),"r");
  if( databasefile == NULL){
    std::cout << "Couldn't open the file. "
	      << this->getInputFile()
	      << std::endl;
    exit(0);
  }
  fclose(databasefile);
  // Test that the document exists, and is readable

  
  TiXmlDocument Doc(this->getInputFile());
  
  if ( Doc.LoadFile() ){
    TiXmlElement *root = Doc.FirstChildElement("Data");
    std::cout << root->Attribute("pdb") << std::endl;
    TiXmlElement *attribute;
    TiXmlElement *child = root->FirstChildElement("Record");
    while (child){
      Reports::FinancialRecord Temp;

      attribute = child->FirstChildElement("Date");
      if(attribute){
	if(attribute->GetText()){
	  std::string delimeter = "/";
	  std::string temp = attribute->GetText();
	  char *token = strtok(strdup(temp.c_str()),delimeter.c_str());
	  Temp.date.month = (short) atoi(token);
	  token = strtok(NULL,delimeter.c_str());
	  Temp.date.day   = (short) atoi(token);
	  token = strtok(NULL,delimeter.c_str());
	  Temp.date.year  = (short) atoi(token);
	}
      }
      attribute = child->FirstChildElement("Description");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Description = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Num");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Num = atoi(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Category");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Category = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Budget_Category");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Budget_Category = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Balance");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Balance = atof(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Notes");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Notes = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Account");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Account = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Discretionary");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Discretionary = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Order");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Order = atoi(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Debit");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Debit = atof(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Credit");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Credit = atof(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Repay");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Repay = attribute->GetText();
	}
      }
      attribute = child->FirstChildElement("Cleared_Balance");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Cleared_Balance = atof(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Reconciled_Balance");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Reconciled_Balance = atof(attribute->GetText());
	}
      }
      attribute = child->FirstChildElement("Discretionary_Amt");
      if(attribute){
	if(attribute->GetText()){
	  Temp.Discretionary_Amt = atof(attribute->GetText());
	}
      }
      this->records.push_back(Temp);
      child = child->NextSiblingElement("Record");
    }

  }
}


