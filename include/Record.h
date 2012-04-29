

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <map>

#include "container.h"
#include "structs.h"

class Record{
 public:
  Record();
  ~Record();
public:
  GContainer::Container _data; // TODO: Make this private
  //  void addData(std::string Name,
private:
};

#endif
