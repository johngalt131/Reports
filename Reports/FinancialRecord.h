/*
 * FinancialRecord.h
 *
 *  Created on: Nov 6, 2011
 *      Author: travisstaley
 */

#ifndef FINANCIALRECORD_H_
#define FINANCIALRECORD_H_

#include <vector>
#include <string>
#include "Record.h"
namespace Reports{

  typedef struct Date{
    short month;
    short day;
    short year;
  };

  typedef struct{
  
    Date date;
    std::string Description;
    float  Debit_val;
    short  Num;
    std::string Category;
    //Cleared_val;
    std::string Budget_Category;
    float Balance;
    std::string  Notes;
    std::string  Account;
    bool Discretionary;
    float Order;
    float Debit;
    float Credit;
    char Cleared[2];
    bool Repay;
    float Cleared_Balance;
    float Reconciled_Balance;
    float Discretionary_Amt;
  } FinancialRecord;
  
  /* class FinancialRecord : public Record{ */
  /*  public: */
  /*   FinancialRecord(); */
  /*   virtual ~FinancialRecord(); */
  /*  private: */
  /*   std::vector<_FinancialRecord_> records; */
  /* }; */
} // namespace Reports
#endif /* FINANCIALRECORD_H_ */
