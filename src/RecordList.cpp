
#include <string>
#include <map>
#include <vector>
#include "typetoname.h"
#ifdef USE_FILTERS
#warning "using filters"
#include "Filters.h"
#endif
#include "tinyxml.h"
#include "RecordList.h"
static const  std::string config_file = "./config.xml";
#ifdef USE_FILTERS
static Filters::FilterList *filters;
#endif
RecordList::RecordList(){
  
  this->Config();
  this->ReadData();
#ifdef USE_FILTERS
  filters = new Filters::FilterList(_filterFile);
  std::vector<GContainer::Container *> FilteredList = records;
  filters->TestElements(FilteredList);
  std::cout << "Old size is " << records.size() << std::endl;
  std::cout << "New size is " << FilteredList.size() << std::endl;
  
  std::vector<GContainer::Container *>::iterator itr;
  itr = FilteredList.begin();
  for( ; itr != FilteredList.end(); itr++){
    GContainer::Container *w = *itr;
    std::string name = "Notes";
    std::string val;
    static int i = 0;
    i++;
    if(w->GetElement(name,val)){
      std::cout <<"val " << i << " from filtered = "<< val << std::endl;    
    }
  }
#endif
}
RecordList::~RecordList(){
  std::vector<GContainer::Container *>::iterator rItr = records.begin();
  for(; rItr != records.end(); rItr++){
    delete *rItr;
    *rItr = NULL;
    records.erase(rItr);
  }
}

void RecordList::Config(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*config,*property;
  Doc = new TiXmlDocument(config_file);
  if( Doc->LoadFile() ){
    root = Doc->FirstChildElement("root");
    config = root->FirstChildElement("config");
    _filename = config->Attribute("InputFile");
    _fieldsFile = config->Attribute("FieldsFile");
    _filterFile = config->Attribute("FilterFile");
    delete Doc;
  }
  Type2Name::GetInstance().Initialize(_fieldsFile);
}

void RecordList::ReadData(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*trecord,*data,*child;
  Doc = new TiXmlDocument(_filename);
  if( Doc->LoadFile() ){
    root =  Doc->FirstChildElement("Data");
    trecord = root->FirstChildElement("Record");
    for ( ; trecord != NULL; trecord = trecord->NextSiblingElement("Record")){
      GContainer::Container *record = new GContainer::Container();
      data = trecord->FirstChildElement();
      for(; data != NULL; data = data->NextSiblingElement()){
	std::string name = data->ValueStr();
	std::string val;
	if(data->GetText()){
	  val = data->GetText();
	}else{
	  // Currently I'm not adding the field if it contains
	  // no data.
	  // val = "";
	  continue;
	}
	std::string type;
	if(Type2Name::GetInstance().GetType(name,type)){
	  if(not record->AddElement(name,type,val)){
	    std::cout << "There was a problem adding "
		      << name << " type = "
		      << type << ", val  = "
		      << val << " number = "
		      << records.size() + 1 << std::endl;
	  }
	}
      }
      records.push_back(record);
      record = NULL;
    }
  }
  //  TEST
  for(int i = 0; i < records.size(); i++){
    GContainer::Container *w = records[i];
    std::string name = "Description";
    std::string val;
    if(w->GetElement(name,val)){
      std::cout <<"VAL = "<< val << std::endl;    
    }
  }
  for(int i = 0; i<100;i++){
    std::vector<GContainer::Container *>::iterator itr;
    itr = records.begin();
    for( ; itr != records.end(); itr++){
      GContainer::Container *w = *itr;
      std::string name = "Notes";
      std::string val;
      if(w->GetElement(name,val)){
	std::cout <<"val = "<< val << std::endl;
      }
    }
  }
  //TEST
  delete Doc;
}



