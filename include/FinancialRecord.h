

#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

#include <string>
#include <map>

#include "financial_structs.h"

namespace Financial{
  typedef struct time{
    short hours;
    short minutes;
    short seconds;
  };
  typedef struct date{
    short day;
    short month;
    short year;
    time _time;
  };
}
class BClass{
public:
  BClass(){};
  virtual std::string getType() = 0;
private:
};

template <typename T>
class data : public BClass
{
public:
  data(std::string type,T t){
    _value = t; 
    _type = type;
  };
  void setVal(T t){_value = t;};
  T getVal(){return _value;};
  std::string getType(){return _type;};
private:
  std::string _type;
  T _value;
};

class Wrapper{
public:
  Wrapper(){};
  bool addElement(const std::string name,
		  const std::string type,
		  const std::string value);
  BClass * getElement(const std::string name);
private:
  std::map<std::string,BClass *> _map;
};


class FinancialRecord{
 public:
  FinancialRecord();
  ~FinancialRecord();
 public:
  Wrapper _data; // TODO: Make this private
  //  void addData(std::string Name,
 private:
};


#endif
