
#include <iostream>
#include <sstream>
#include "FinancialRecordList.h"
#include "financial_structs.h"
#include <map>
#include <vector>
#include <string>
#include <typeinfo>

BClass * Wrapper::getElement(std::string name){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    return Itr->second;
  }
  return NULL;
}
bool Wrapper::addElement(std::string name,
			 std::string type,
			 std::string value){
  std::string type_value;
  if(type == "string"     ||
     type == "str"        ||
     type == "String"     ||
     type == "STRING"     ||
     type == "std::string" ){
    type_value = "string";
    data<std::string> *newData = new data<std::string>(type_value,value);
    _map[name] = (BClass *)newData;
  }
  else if(type == "int"     ||
	  type == "INT"     ||
	  type == "Int" ){
    type_value = "int";
    std::stringstream string_to_int;
    int int_val = 0;
    string_to_int << value;
    string_to_int >> int_val;
    data<int> *newData = new data<int>(type_value,int_val);
    _map[name] = (BClass *)newData;
  }
  else if(type == "float"     ||
	  type == "FLOAT"     ||
	  type == "Float" ){
    type_value = "float";
    std::stringstream string_to_float;
    float float_val = 0;
    string_to_float << value;
    string_to_float >> float_val;
    data<float> *newData = new data<float>(type_value,float_val);
    _map[name] = (BClass *)newData;
  }
  else if(type == "bool"     ||
	  type == "boolean"     ||
	  type == "BOOL" ){
    type_value = "bool";
    bool bool_val = false;
    if(value == "TRUE" ||
       value == "True" ||
       value == "true" ||
       value == "1"){
      bool_val = true;
    }
    data<bool> *newData = new data<bool>(type_value,bool_val);
    _map[name] = (BClass *)newData;
  }
  else if (type == "Date" ||
	   type == "date" ||
	   type == "DATE" ){
    std::string new_date = value;
    Financial::date temp_date;
    char *delete_me;
    char *temp = strdup(new_date.c_str());
    struct tm *tmp;
    short diff;
    time_t utc_time, local_time;
    time(&utc_time);
    tmp = gmtime(&utc_time);
    time(&local_time);
    utc_time = mktime(tmp);
    diff = (short) difftime(local_time,utc_time) / (60 * 60);
    delete_me = temp;
    char *date;
    char *time;
    int   new_int;
    int   a,b;
    date = strtok(temp,"T");
    time = strtok(NULL,"T");
    time = strtok(time,"Z");
    
    date = strtok(date,"-,/");
    new_int = atoi(date);
    a = 12;
    b = 1;
    if( new_int > a || new_int < b ){
      std::cout << "new_date.month = " << new_int
		<< " And is out of range. " << std::endl;
    }
    else{
      temp_date.month = new_int;    
    }
    date = strtok(NULL,"-,/");
    temp_date.day = atoi(date);
    
    date = strtok(NULL,"-,/");
    new_int = atoi(date);
    a = 2040;
    b = 1900;
    if( new_int > a || new_int < b ){
      std::cout << "new_date.year = " << new_int
		<< " And is out of range. " << std::endl;
    }
    else{
      temp_date.year = new_int;    
    }
    if(time){
      time = strtok(time,":");
      new_int = (short) atoi(time);
      new_int += diff;
      while( new_int < 0 ){
	new_int += 24;
      }
      while( new_int > 24 ){
	new_int -= 24;
      }
      a = 24;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.hours = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.hours = new_int;
      }
      
      time = strtok(NULL,":");
      new_int = (short) atoi(time);
      a = 60;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.minutes = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.minutes = new_int;
      }
      
      time = strtok(NULL,":");
      new_int = (short) atoi(time);
      a = 60;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.seconds = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.seconds = new_int;
      }
    }
    free(temp);
    std::string type = "date";
    data<Financial::date> *newData = new data<Financial::date>(type,temp_date);
    _map[name] = (BClass *)newData;

  }

  return true;
}

bool Wrapper::getElement(const std::string name,
			 float &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  std::cout << "here" << std::endl;
  if(Itr != _map.end()){
    val = ((data<float> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool Wrapper::getElement(const std::string name,
			 int &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<int> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool Wrapper::getElement(const std::string name,
			 Financial::date &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<Financial::date> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool Wrapper::getElement(const std::string name,
			 std::string &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<std::string> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool Wrapper::getElement(const std::string name,
			 bool &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<bool> *)Itr->second)->getVal();
    return true;
  }
  return false;  
}


FinancialRecord::~FinancialRecord(){
  
}

FinancialRecord::FinancialRecord(){
  
}
