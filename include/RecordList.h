

#ifndef RECORDLIST_H
#define RECORDLIST_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include "Record.h"

class RecordList{
 public:
  RecordList();
  ~RecordList();
 private:
  void Config();
  void ReadData();
  std::vector<GContainer::Container *> records;
  std::string _filename;
  std::string _filterFile;
  std::string _fieldsFile;
};

#endif
