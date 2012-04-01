

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <map>

#include "report_structs.h"
#include "container.h"
#include "structs.h"

class Record{
 public:
  Record();
  ~Record();
 public:
  GContainer::Container _data; // TODO: Make this private
  Date::date th;
  //  void addData(std::string Name,
 private:
};

#endif
