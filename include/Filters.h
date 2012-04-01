
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
  
  class Filters{
  public:
    Filters();
    Filters(std::string config_file);
    ~Filters();
  private:
    void Configure();
    GContainer::Container _allFilters;
    std::string _filterFile;
    void TestAll();
  };  
  
} // NAMESPACE Filters
#endif
