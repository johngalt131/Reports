

#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

#include <string>

namespace Financial{
  typedef struct time{
    short hours;
    short minutes;
    short seconds;
  };
  typedef struct date{
    short day;
    short month;
    short year;
    time _time;
  };
}

class FinancialRecord{
 public:
  FinancialRecord();
  ~FinancialRecord();
// BEGINPROTOTYPES

// These are automatically generated getter and setter methods
// Do Not Edit
public:
void set_date(std::string new_date);
void set_cleared_val(std::string new_cleared_val);
void set_description(std::string new_description);
void set_debit_val(std::string new_debit_val);
void set_num(std::string new_num);
void set_category(std::string new_category);
void set_budget_category(std::string new_budget_category);
void set_notes(std::string new_notes);
void set_account(std::string new_account);
void set_discretionary(std::string new_discretionary);
void set_credit_val(std::string new_credit_val);
void set_order(std::string new_order);
void set_repay(std::string new_repay);
void set_pending_total(std::string new_pending_total);
void set_reconciled_val(std::string new_reconciled_val);
void set_cleared_balance(std::string new_cleared_balance);
void set_reconciled_balance(std::string new_reconciled_balance);
void set_total_discretionary(std::string new_total_discretionary);
void set_discretionary_amt(std::string new_discretionary_amt);

Financial::date get_date(void);
int get_cleared_val(void);
std::string get_description(void);
float get_debit_val(void);
int get_num(void);
std::string get_category(void);
std::string get_budget_category(void);
std::string get_notes(void);
std::string get_account(void);
bool get_discretionary(void);
float get_credit_val(void);
short get_order(void);
bool get_repay(void);
float get_pending_total(void);
float get_reconciled_val(void);
float get_cleared_balance(void);
float get_reconciled_balance(void);
float get_total_discretionary(void);
float get_discretionary_amt(void);

// These are automatically generated member variables
// Do Not Edit
private:
Financial::date _date;
int _cleared_val;
std::string _description;
float _debit_val;
int _num;
std::string _category;
std::string _budget_category;
std::string _notes;
std::string _account;
bool _discretionary;
float _credit_val;
short _order;
bool _repay;
float _pending_total;
float _reconciled_val;
float _cleared_balance;
float _reconciled_balance;
float _total_discretionary;
float _discretionary_amt;
// ENDPROTOTYPES
};


#endif
