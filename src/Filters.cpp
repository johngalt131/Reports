#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"
#include "typetoname.h"

void Filters::FilterGroup::AddFilter(Filter *newFilter){
  _filters.push_back(newFilter);
}
Filters::FilterGroup::~FilterGroup(){
  std::vector<Filter *>::iterator fItr = _filters.begin();
  for( ; fItr != _filters.end();fItr++){
    delete *fItr;
    *fItr = NULL;
  }
  _filters.clear();
}
Filters::FilterList::FilterList(const std::string filterFile){
  _filterFile = filterFile;
  Configure();
}
Filters::FilterList::FilterList(){

}
Filters::FilterList::~FilterList(){
  std::vector<FilterGroup *>::iterator gItr = _allFilters.begin();
  for( ; gItr != _allFilters.end();gItr++){
    delete *gItr;
  }
  _allFilters.clear();
}
void Filters::FilterList::Configure(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*config,*report,*group,*filter,*print;
  Doc = new TiXmlDocument(_filterFile);
  if( Doc->LoadFile() ){
    root = Doc->FirstChildElement("Root");
    report = root->FirstChildElement("Report");
    for(group = report->FirstChildElement("Group"); group != NULL; group = group->NextSiblingElement("Group")){
      FilterGroup *filterGroup = new FilterGroup(); 
      for(filter = group->FirstChildElement("Filter"); filter != NULL; filter = filter->NextSiblingElement("Filter")){
	std::string name;
	std::string oper;
	std::string val;
	std::string fname;
	if(filter->Attribute("operator")){
	  oper = filter->Attribute("operator");
	}
	if(filter->Attribute("name")){
	  name = filter->Attribute("name");
	}
	if(filter->Attribute("value")){
	  val = filter->Attribute("value");
	}
	std::string type;
	Type2Name::GetInstance().GetType(name,type);
	GContainer::Container *newContainer = new GContainer::Container(name,type,val);
	filterGroup->AddFilter(new Filter(oper,newContainer));
      }
      _allFilters.push_back(filterGroup);
    }
    delete Doc;
  }
}
Filters::Filter::Filter(std::string type, GContainer::Container *Container){
  _container = Container;
  if(type == "lt"){
    _type = LESS_THAN;
  } else if (type == "gt") {
    _type = GREATER_THAN;
  }else if (type == "gte") {
    _type = GREATER_THAN_OR_EQUAL;
  }else if (type == "lte") {
    _type = LESS_THAN_OR_EQUAL;
  }else if (type == "eq") {
    _type = EQUAL;
  }else if (type == "ne") {
    _type = NOT_EQUAL;
  }
}
Filters::NUMBER_COMPARISON_E Filters::Filter::GetType(){
  return _type;
}
GContainer::Container * Filters::Filter::Container(){
  return _container;
}
void Filters::FilterList::TestElements(std::vector<GContainer::Container *> &test){
  std::vector< std::vector<GContainer::Container *> > masterList;
  std::vector<GContainer::Container *> originalList = test;
  std::vector<GContainer::Container *> newList;
  std::vector<FilterGroup *>::iterator gItr = _allFilters.begin();
  for(; gItr != _allFilters.end(); gItr++){
    std::vector<Filter *>::iterator fItr = (*gItr)->_filters.begin();
    for(; fItr != (*gItr)->_filters.end(); fItr++){
      GContainer::ContainerIterator * theFilter = (*fItr)->Container()->GetIterator();
      if(not theFilter->Begin()){
	std::cout << "There was a problem with the Filter." <<std::endl;
	exit(-4);
      }
      std::vector<GContainer::Container *>::iterator itr = test.begin();
      for( ; itr != test.end() ; itr++){
	bool testVal = false;
	GContainer::ContainerIterator * theRecord = (*itr)->GetIterator();
	if( not theRecord->Find(theFilter->iterator->first)){
	  std::cout << "This record has no field " << theFilter->iterator->first << std::endl;
	  continue;
	}
	switch((*fItr)->GetType()){
	case EQUAL:
	  testVal = (*(theRecord->iterator->second) == (theFilter->iterator->second));
	  break;
	case LESS_THAN:
	  testVal = (*(theRecord->iterator->second) < (theFilter->iterator->second));
	  break;
	case LESS_THAN_OR_EQUAL:
	  testVal = (*(theRecord->iterator->second) <= (theFilter->iterator->second));
	  break;
	case GREATER_THAN:
	  testVal = (*(theRecord->iterator->second) > (theFilter->iterator->second));
	  break;
	case GREATER_THAN_OR_EQUAL:
	  testVal = (*(theRecord->iterator->second) >= (theFilter->iterator->second));
	  break;
	case NOT_EQUAL:
	  testVal = (*(theRecord->iterator->second) != (theFilter->iterator->second));
	  break;
	default:
	  std::cout << "Bad type. Check your filter file." << std::endl;
	  break;
	}
	if(testVal){
	  newList.push_back(*itr);
	}
      }
      test.clear();
      test = newList;
      newList.clear();
    }
    masterList.push_back(test);
    newList.clear();
    test = originalList;
    std::cout << " master List has " << masterList.size() << " elements" << std::endl;
  }
  test.clear();
  std::vector< std::vector<GContainer::Container *> >::iterator mItr = masterList.begin();
  for(; mItr != masterList.end(); mItr++){
    std::vector<GContainer::Container *>::iterator lItr = mItr->begin();
    for(; lItr != mItr->end(); lItr++){
      test.push_back(*lItr);
    }
  }
}
