

#ifndef FINANCIALRECORDLIST_H
#define FINANCIALRECORDLIST_H

#include <string>
#include <vector>
#include <map>
#include "FinancialRecord.h"

static NAME_2_TYPE name2Type;
class FinancialRecordList{
 public:
  FinancialRecordList();
  ~FinancialRecordList();
 private:
  void Config();
  void ReadData();
  std::vector<FinancialRecord> records;
  std::string _filename;
  std::string _fieldsFile;
};

#endif
