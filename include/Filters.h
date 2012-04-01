
#ifndef FILTERS_H
#define FILTERS_H

#include <vector>
#include <map>
#include <string>

#include "container.h"

namespace Filters{
  
  enum NUMBER_COMPARISON_E{
    EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL
  };
  
  class BFilter{
  public:
    BFilter();
    virtual ~BFilter();
    virtual bool IsSatisfied() = 0;
  private:
  };
  
  template <typename T>
  class Filter: public BFilter{
  public:
    bool IsSatisfied(T test_value);
  private:
    T _value;
    NUMBER_COMPARISON_E _type;
  };
  
  class FilterList{
  public:
    FilterList();
    FilterList(const std::string config_file);
    ~FilterList();
  private:
    void Configure();
    GContainer::NAME_2_TYPE name2Type;
    GContainer::Container _allFilters;
    std::string _filterFile;
    std::string _configFile;
    void TestAll();
  };  
  
} // NAMESPACE Filters
#endif
