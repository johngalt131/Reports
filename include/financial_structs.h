
// This file was created by prep.sh
// Do Not Edit

#ifndef FINANCIALSTRUCTS_H_
#define FINANCAILSTRUCTS_H_

static const char *const PROPERTY_NAME[] = {
  "Date",
  "Cleared_val",
  "Description",
  "Debit_val",
  "Num",
  "Category",
  "Budget_Category",
  "Notes",
  "Account",
  "Discretionary",
  "Credit_val",
  "Order",
  "Repay",
  "Pending_Total",
  "Reconciled_Val",
  "Cleared_Balance",
  "Reconciled_Balance",
  "Total_Discretionary",
  "Discretionary_Amt",
  "Unknown Type"
};

typedef enum PROPERTY_NAME_E {
  DATE,
  CLEARED_VAL,
  DESCRIPTION,
  DEBIT_VAL,
  NUM,
  CATEGORY,
  BUDGET_CATEGORY,
  NOTES,
  ACCOUNT,
  DISCRETIONARY,
  CREDIT_VAL,
  ORDER,
  REPAY,
  PENDING_TOTAL,
  RECONCILED_VAL,
  CLEARED_BALANCE,
  RECONCILED_BALANCE,
  TOTAL_DISCRETIONARY,
  DISCRETIONARY_AMT,
  UNKNOWN_TYPE,
  NUMBER_OF_PROPS
};

typedef enum {
  FLOAT,
  INT,
  STRING,
  COUNT
}TYPE_E;

template<typename T>
class data{
public:
  data(T t){
    value = t; 
  };
  void setVal(T t){value = t;};
  T getVal(){return value;};
private:
  T value;
};


#endif
