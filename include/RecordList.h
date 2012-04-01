

#ifndef RECORDLIST_H
#define RECORDLIST_H

#include <string>
#include <vector>
#include <map>
#include "Record.h"

class RecordList{
 public:
  RecordList();
  ~RecordList();
 private:
  void Config();
  void ReadData();
  GContainer::NAME_2_TYPE name2Type;
  std::vector<Record> records;
  std::string _filename;
  std::string _fieldsFile;
};

#endif
