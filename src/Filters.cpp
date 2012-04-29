#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"
#include "typetoname.h"

Filters::FilterList::FilterList(const std::string filterFile){
  _filterFile = filterFile;
  Configure();
}
Filters::FilterList::FilterList(){

}
void Filters::FilterList::Configure(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*config,*filter;
  Doc = new TiXmlDocument(_filterFile);
  if( Doc->LoadFile() ){
    root = Doc->FirstChildElement("Root");
    for(filter = root->FirstChildElement("Filter"); filter != NULL; filter = filter->NextSiblingElement("Filter")){
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
      _allFilters.push_back(new Filter(oper,newContainer));
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
  std::vector<GContainer::Container *> newList;
  std::vector<Filter *>::iterator gItr = _allFilters.begin();
  for(; gItr != _allFilters.end(); gItr++){
    GContainer::ContainerIterator * theFilter = (*gItr)->Container()->GetIterator();
    if(not theFilter->Begin()){
      std::cout << "There was a problem with the Filter." <<std::endl;
      exit(-4);
    }
    //TODO: groups of filters to handle OR cases.
    std::vector<GContainer::Container *>::iterator itr = test.begin();
    for( ; itr != test.end() ; itr++){
      bool testVal = false;
      GContainer::ContainerIterator * theRecord = (*itr)->GetIterator();
      if( not theRecord->Find(theFilter->iterator->first)){
	std::cout << "This record has no field " << theFilter->iterator->first << std::endl;
	continue;
      }
      switch((*gItr)->GetType()){
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
}
