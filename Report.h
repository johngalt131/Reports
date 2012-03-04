
#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>
#include "stdlib.h"
#include "stdio.h"

#include "Report.h"


class Report{
 public:
  Report();
  ~Report();
  
 private:
  std::vector<ReportType> types;
  std::string _config_file;
};

class ReportType{
 public:
  ReportType();
  ~ReportType();
  virtual bool isSatisfied();
 private:
  
};


#endif
