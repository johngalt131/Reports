#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "tinyxml.h"
#include "Filters.h"

Filters::FilterList::FilterList(const std::string filterFile){
  _filterFile = filterFile;
  Configure();
}
Filters::FilterList::FilterList(){

}
void Filters::FilterList::Configure(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*config,*property;
  Doc = new TiXmlDocument(_filterFile);
  if( Doc->LoadFile() ){
    root = Doc->FirstChildElement("Root");
    property = root->FirstChildElement("Property");
    for( ; property != NULL; property = property->NextSiblingElement("Property")){
      std::string temp = property->Attribute("name");
      name2Type[temp] = property->Attribute("type");
    }
    delete Doc;
  }
}
/*
template <typename T>
bool Filters::Filter::IsSatisfied(T test_value){
  switch(Filters::_type){
  case Filters::EQUAL:
    if(test_value == _value){
      return true;
    }else{
      return false;
    }
    break;
  case Filters::LESS_THAN:
    if(test_value < _value){
      return true;
    }else{
      return false;
    }
    break;
  case Filters::LESS_THAN_OR_EQUAL:
    if(test_value <= _value){
      return true;
    }else{
      return false;
    }
    break;
  case Filters::GREATER_THAN:
    if(test_value > _value){
      return true;
    }else{
      return false;
    }
    break;
  case Filters::GREATER_THAN_OR_EQUAL:
    if(test_value >= _value){
      return true;
    }else{
      return false;
    }
    break;
  case Filters::NOT_EQUAL:
    if(test_value != _value){
      return true;
    }else{
      return false;
    }
    break;
  }
}
*/

#if 4 == 5
void Filters::FilterList::TestAll(std::vector<Filterable> &testObject){
  
}
#endif
