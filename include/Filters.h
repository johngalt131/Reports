
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
  NOT_EQUAL,
  CONTAINS
};
  
class BFilter{
public:
  BFilter();
  virtual ~BFilter();
  virtual bool IsSatisfied() = 0;
private:
};
  
class Filter {
public:
  ~Filter();
  Filter(std::string type, GContainer::Container *Container);
  GContainer::Container *Container();
  NUMBER_COMPARISON_E GetType();
private:
  GContainer::Container *_container;
  NUMBER_COMPARISON_E _type;
};
class FilterGroup{
  friend class FilterList;
public:
  ~FilterGroup();
  void AddFilter(Filter *newFilter);
private:
  std::vector<Filter *> _filters;
};
class FilterList{
public:
  FilterList();
  FilterList(const std::string config_file);
  ~FilterList();
  void TestElements(std::vector<GContainer::Container *> &test);
private:
  void Configure();
  std::vector<FilterGroup *> _allFilters;
  std::string _filterFile;
  std::string _configFile;
  void TestAll();
};  
  
} // NAMESPACE Filters
#endif
