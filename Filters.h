
#ifndef FILTERS_H
#define FILTERS_H

#include <vector>
#include <map>
#include <string>
#include "Filterable.h"

namespace Filters{
  
  class Filter{
  public:
    Filter();
    ~Filter();
    virtual bool IsSatisfied();  
  private:
  };
  
  //Forward declaration
  class Filters;

  typedef std::vector<Filter> FILTER;
  typedef std::vector< FILTER > FILTER_GROUPS;
  
 class FloatFilter: public Filter{
  public:
    bool IsSatisfied(float test_value);
  private:
    
  };
  
  class Filters{
  public:
    Filters();
    Filters(std::string config_file);
    ~Filters();
    
  private:
    FILTER_GROUPS _allFilters;
    std::string _filterFile;
    void TestAll(Filterable &testObject);
  };  

} // NAMESPACE Filters
#endif
