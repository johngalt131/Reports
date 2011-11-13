/*
 * Financial.h
 *
 *  Created on: Sep 11, 2011
 *      Author: travisstaley
 */

#ifndef FINANCIAL_H_
#define FINANCIAL_H_

#include <string>
#include <vector>
#include "DataBase.h"
#include "FinancialRecord.h"

class Financial : public DataBase{
public:
  Financial(std::string filename);
  virtual ~Financial();
 private:
  void thisMonth();
  void parseFile();
  std::vector<Reports::FinancialRecord> records; // Pointer or no ?
};

#endif /* FINANCIAL_H_ */
