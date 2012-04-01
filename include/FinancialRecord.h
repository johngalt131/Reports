

#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

#include <string>
#include <map>

#include "financial_structs.h"
#include "container.h"
#include "structs.h"

class FinancialRecord{
 public:
  FinancialRecord();
  ~FinancialRecord();
 public:
  GContainer::Container _data; // TODO: Make this private
  Date::date th;
  //  void addData(std::string Name,
 private:
};

#endif
