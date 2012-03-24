#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"

void Filters::Filters::TestAll(Filterable &testObject){
  FILTER_GROUPS::const_iterator gItr;
  gItr = _allFilters.begin();
  for( ; gItr != _allFilters.end(); gItr++){
    FILTER::const_iterator fItr;
    
  }
}
