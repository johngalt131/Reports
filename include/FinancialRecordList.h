

#ifndef FINANCIALRECORDLIST_H
#define FINANCIALRECORDLIST_H

#include <string>
#include <vector>
#include <map>
#include "financial_structs.h"
#include "FinancialRecord.h"

class FinancialRecordList{
 public:
  FinancialRecordList();
  ~FinancialRecordList();
  
 private:
  void Config();
  void ReadData();
  std::vector<FinancialRecord> records;
  std::string _filename;
};

typedef std::map<std::string,PROPERTY_NAME_E> PROPNAME_2_PROP;


#endif
