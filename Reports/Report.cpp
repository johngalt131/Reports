/*
 * Report.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */



#include "Financial.h"
#include "ItunesLibrary.h"
#include "DataBase.h"
#include "string"

#include <iostream>

int main (){
  //static const std::string filename = "/Users/travisstaley/Documents/source-code/C++/Reports/Reports/demotest.xml";
  //const std::string filename = "/Users/travisstaley/Music/iTunes/iTunes Music Library.xml";  
  const std::string filename = "/Users/travisstaley/VirtualBoxShared/financial.XML";
  DataBase *finance = new Financial(filename);
  finance->thisMonth();
  return 0;
}
