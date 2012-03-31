
#ifndef FILTERS_H
#define FILTERS_H

#include <vector>
#include <map>
#include <string>
#include "Filterable.h"

namespace Filters{
  
  enum NUMBER_COMPARISON_E{
    EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL
  }
  
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
  typedef std::vector<FILTER> FILTER_GROUP;
  typedef std::vector<FILTER_GROUP> FILTER_GROUPS;

 class FloatFilter: public Filter{
  public:
    bool IsSatisfied(float test_value);
  private:
    float _value;
    NUMBER_COMPARISON_E _type;
  };
  
  class Filters{
  public:
    Filters();
    Filters(std::string config_file);
    ~Filters();
    
  private:
    FILTER_GROUPS _allFilters;
    std::string _filterFile;
    void TestAll(std::vector<Filterable> &testObjects);
  };  

} // NAMESPACE Filters
#endif
