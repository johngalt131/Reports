

#include <string>
#include <map>
#include <vector>
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
  TiXmlElement *root,*config;
  Doc = new TiXmlDocument(config_file);
  if( Doc->LoadFile() ){
    root = Doc->FirstChildElement("root");
    config = root->FirstChildElement("config");
    _filename = config->Attribute("InputFile");
  }
}

void FinancialRecordList::ReadData(){
  TiXmlDocument *Doc = NULL;
  TiXmlElement *root,*Record,*data,*child;
  Doc = new TiXmlDocument(_filename);
  if(Doc->LoadFile() ){
    root =  Doc->FirstChildElement("Data");
    Record = root->FirstChildElement("Record");
    
    while(Record){
      PROPERTY_NAME_E prop;
      FinancialRecord *record = new FinancialRecord();
      PROPNAME_2_PROP::const_iterator propItr;
      std::string property_name;
      for ( int i = 0 ; i < NUMBER_OF_PROPS ; i++){
	child = Record->FirstChildElement(PROPERTY_NAME[i]);
	switch(i){
	  
	  // BEGINCASE
	  // This is automatically generated code
	  // Do Not Edit
	case DATE:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_date(temp_string);
	  }
	  break;
	}
	case CLEARED_VAL:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_cleared_val(temp_string);
	  }
	  break;
	}
	case DESCRIPTION:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_description(temp_string);
	  }
	  break;
	}
	case DEBIT_VAL:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_debit_val(temp_string);
	  }
	  break;
	}
	case NUM:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_num(temp_string);
	  }
	  break;
	}
	case CATEGORY:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_category(temp_string);
	  }
	  break;
	}
	case BUDGET_CATEGORY:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_budget_category(temp_string);
	  }
	  break;
	}
	case NOTES:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_notes(temp_string);
	  }
	  break;
	}
	case ACCOUNT:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_account(temp_string);
	  }
	  break;
	}
	case DISCRETIONARY:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_discretionary(temp_string);
	  }
	  break;
	}
	case CREDIT_VAL:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_credit_val(temp_string);
	  }
	  break;
	}
	case ORDER:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_order(temp_string);
	  }
	  break;
	}
	case REPAY:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_repay(temp_string);
	  }
	  break;
	}
	case PENDING_TOTAL:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_pending_total(temp_string);
	  }
	  break;
	}
	case RECONCILED_VAL:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_reconciled_val(temp_string);
	  }
	  break;
	}
	case CLEARED_BALANCE:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_cleared_balance(temp_string);
	  }
	  break;
	}
	case RECONCILED_BALANCE:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_reconciled_balance(temp_string);
	  }
	  break;
	}
	case TOTAL_DISCRETIONARY:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_total_discretionary(temp_string);
	  }
	  break;
	}
	case DISCRETIONARY_AMT:{
	  const char *temp = child->GetText();
	  std::string temp_string;
	  if( temp ){ 
	    temp_string = temp;
	    //free(temp);
	    record->set_discretionary_amt(temp_string);
	  }
	  break;
	}
	  //ENDCASE
	defualt:
	  break;
	}
	// case statements
	
      }
      Record = Record->NextSiblingElement();
      records.push_back(*record);
      delete record;
    }
  }
}

