

#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

class FinancialRecord{

 public:
  void set_date(date date);
  void set_cleared_val(int cleared_val);
  void set_description(std::string description);
  void set_debit_val(float debit_val);
  void set_num(int num);
  void set_category(std::string category);
  void set_budget_category(std::string budget_category);
  void set_notes(std::string notes);
  void set_account(std::string account);
  void set_discretionary(bool discretionary);
  void set_credit_val(float credit_val);
  void set_order(short order);
  void set_repay(bool repay);
  void set_pending_total(float pending_total);
  void set_reconciled_val(float reconciled_val);
  void set_cleared_balance(float cleared_balance);
  void set_reconciled_balance(float reconciled_balance);
  void set_total_discretionary(float total_discretionary);
  void set_discretionary_amt(float discretionary_amt);
  
  date get_date(void);
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
  
 private:
  date _date;
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
  
};


#endif
