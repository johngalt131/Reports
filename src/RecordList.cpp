

#include <string>
#include <map>
#include <vector>
#ifdef USE_FILTERS
#include "Filters.h"
#endif
#include "tinyxml.h"
#include "RecordList.h"

static const  std::string config_file = "./config.xml";
RecordList::RecordList(){
  
  this->Config();
  this->ReadData();
}
RecordList::~RecordList(){
  
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
    delete Doc;
  }
  Doc = new TiXmlDocument(_fieldsFile);
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

void RecordList::ReadData(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*trecord,*data,*child;
  Doc = new TiXmlDocument(_filename);
  if( Doc->LoadFile() ){
    root =  Doc->FirstChildElement("Data");
    trecord = root->FirstChildElement("Record");
    for ( ; trecord != NULL; trecord = trecord->NextSiblingElement("Record")){
      Record record;
      data = trecord->FirstChildElement();
      for(; data != NULL; data = data->NextSiblingElement()){
	std::string name = data->ValueStr();
	std::string val;
	if(data->GetText()){
	  val = data->GetText();
	}
	else{
	  continue;
	}
	NAME_2_TYPE::const_iterator tItr = name2Type.find(name);
	if(tItr != name2Type.end()){
	  std::string type = tItr->second;
	  if(not record._data.addElement(name,type,val)) {
	    std::cout << "There was a problem adding "
		      << name << " type = "
		      << type << ", val  = "
		      << val << std::endl;
	  }
	}
      }
      records.push_back(record);
    }
  }
  // TEST
  std::vector<Record>::iterator itr;
  itr = records.begin();
  for( ; itr != records.end(); itr++){
    GContainer::Container w = itr->_data;
    std::string name = "Notes";
    std::string val;
    if(w.getElement(name,val)){
      std::cout <<"val = "<< val << std::endl;    
    }
  }
  
  //TEST
  delete Doc;
}



