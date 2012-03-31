

#include <string>
#include <map>
#include <vector>
#ifdef USE_FILTERS
#include "Filters.h"
#endif
#include "tinyxml.h"
#include "FinancialRecordList.h"
static std::string config_file = "./config.xml";
FinancialRecordList::FinancialRecordList(){
  
  this->Config();
  this->ReadData();
  int j = 0;
}
FinancialRecordList::~FinancialRecordList(){
  
}

void FinancialRecordList::Config(){
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

void FinancialRecordList::ReadData(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*Record,*data,*child;
  Doc = new TiXmlDocument(_filename);
  if( Doc->LoadFile() ){
    root =  Doc->FirstChildElement("Data");
    Record = root->FirstChildElement("Record");
    for ( ; Record != NULL; Record = Record->NextSiblingElement("Record")){
      FinancialRecord record;
      data = Record->FirstChildElement();
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
	  record._data.addElement(name,type,val);
	}
      }
      records.push_back(record);
    }
  }
  std::vector<FinancialRecord>::iterator itr;
  itr = records.begin();
  for( ; itr != records.end(); itr++){
    BClass *tmp = NULL;
    Wrapper w = itr->_data;
    std::string name = "Credit_val";
    data<float> *val;
    tmp = w.getElement(name);
    std::cout << "null?" << std::endl;
    if(tmp){
      val = (data<float> * )tmp;
      std::cout << tmp->getType() << std::endl;
      std::cout << val->getVal() << std::endl;
    }
  }
  delete Doc;
}



