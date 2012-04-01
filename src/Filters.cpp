#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"

void Filters::Filters::TestAll(std::vector<Filterable> &testObject){
  std::vector<Filterable>::iterator testItr = testObject.begin();
  for( ; testItr != testObject.end(); testItr++){
    FILTER_GROUPS tempFilterGroup = _allFilters;
    FILTER_GROUPS::iterator groupsItr = tempFilterGroup.begin();
    for( ; groupsItr != tempFilterGroup.end(); groupsItr++){
      FILTER_GROUP::const_iterator gItr = groupsItr->begin();
      for( ; gItr != groupsItr->end(); gItr++){
	FILTER::const_iterator fItr = gItr->begin();
	for( ; fItr != gItr->end(); fItr++){
	  if( not fItr->isSatisfied(testItr) ){
	    gItr->erase(fItr);
	  }
	}
      }
      if(gItr->size() == 0){
	// All filters have been removed from this group
	groupsItr->erase(gItr);
      }
    }
    if(groupsItr->size() == 0){
      testObject.erase(testItr);
    }
  }
}
template <typename T>
bool Filters::Filters::IsSatisfied(T test_value){
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
