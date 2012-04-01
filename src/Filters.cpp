#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"


template <typename T>
bool Filters::Filter::IsSatisfied(T test_value){
  switch(_type){
  case EQUAL:
    if(test_value == _value){
      return true;
    }else{
      return false;
    }
    break;
  case LESS_THAN:
    if(test_value < _value){
      return true;
    }else{
      return false;
    }
    break;
  case LESS_THAN_OR_EQUAL:
    if(test_value <= _value){
      return true;
    }else{
      return false;
    }
    break;
  case GREATER_THAN:
    if(test_value > _value){
      return true;
    }else{
      return false;
    }
    break;
  case GREATER_THAN_OR_EQUAL:
    if(test_value >= _value){
      return true;
    }else{
      return false;
    }
    break;
  case NOT_EQUAL:
    if(test_value != _value){
      return true;
    }else{
      return false;
    }
    break;
  }
}


#if 4 == 5
void Filters::Filters::TestAll(std::vector<Filterable> &testObject){
  
}
#endif
