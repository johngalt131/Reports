
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

// BEGINCONSTRUCTOR
// This is an automatically generated initialization block for constructor
// Do Not Edit
set_date("01/12/1900");
set_cleared_val("-34044");
set_description("This attribute is missing");
set_debit_val("-34044");
set_num("-34044");
set_category("This attribute is missing");
set_budget_category("This attribute is missing");
set_notes("This attribute is missing");
set_account("This attribute is missing");
set_discretionary("false");
set_credit_val("-34044");
set_order("-34044");
set_repay("false");
set_pending_total("-34044");
set_reconciled_val("-34044");
set_cleared_balance("-34044");
set_reconciled_balance("-34044");
set_total_discretionary("-34044");
set_discretionary_amt("-34044");
// ENDCONSTRUCTOR


// BEGINCASE
// This is automatically generated code
// Do Not Edit
case DATE:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_date(temp_string);
}
break;
}
case CLEARED_VAL:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_cleared_val(temp_string);
}
break;
}
case DESCRIPTION:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_description(temp_string);
}
break;
}
case DEBIT_VAL:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_debit_val(temp_string);
}
break;
}
case NUM:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_num(temp_string);
}
break;
}
case CATEGORY:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_category(temp_string);
}
break;
}
case BUDGET_CATEGORY:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_budget_category(temp_string);
}
break;
}
case NOTES:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_notes(temp_string);
}
break;
}
case ACCOUNT:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_account(temp_string);
}
break;
}
case DISCRETIONARY:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_discretionary(temp_string);
}
break;
}
case CREDIT_VAL:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_credit_val(temp_string);
}
break;
}
case ORDER:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_order(temp_string);
}
break;
}
case REPAY:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_repay(temp_string);
}
break;
}
case PENDING_TOTAL:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_pending_total(temp_string);
}
break;
}
case RECONCILED_VAL:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_reconciled_val(temp_string);
}
break;
}
case CLEARED_BALANCE:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_cleared_balance(temp_string);
}
break;
}
case RECONCILED_BALANCE:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_reconciled_balance(temp_string);
}
break;
}
case TOTAL_DISCRETIONARY:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_total_discretionary(temp_string);
}
break;
}
case DISCRETIONARY_AMT:{
const char *temp = child->GetText();
std::string temp_string;
if( temp ){ 
temp_string = temp;
NAMEOFCLASSset_discretionary_amt(temp_string);
}
break;
}
// case statements

// ENDCASE
// BEGINIMPLEMENTATION

// This is an automatically generated code
// Do Not Edit
void FinancialRecord::set_date(std::string new_date){
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
_date = new_date;

}
void FinancialRecord::set_cleared_val(std::string new_cleared_val){
std::stringstream string_to_int;
string_to_int << new_cleared_val;
string_to_int >> _cleared_val;
}
void FinancialRecord::set_description(std::string new_description){
_description = new_description;
}
void FinancialRecord::set_debit_val(std::string new_debit_val){
std::stringstream string_to_float;
string_to_float << new_debit_val;
string_to_float >> _debit_val;
}
void FinancialRecord::set_num(std::string new_num){
std::stringstream string_to_int;
string_to_int << new_num;
string_to_int >> _num;
}
void FinancialRecord::set_category(std::string new_category){
_category = new_category;
}
void FinancialRecord::set_budget_category(std::string new_budget_category){
_budget_category = new_budget_category;
}
void FinancialRecord::set_notes(std::string new_notes){
_notes = new_notes;
}
void FinancialRecord::set_account(std::string new_account){
_account = new_account;
}
void FinancialRecord::set_discretionary(std::string new_discretionary){
bool temp_bool;
std::transform(new_discretionary.begin(),new_discretionary.end(),new_discretionary.begin(), ::tolower);
if( new_discretionary == "0" || new_discretionary == "false" ){
temp_bool = false;
}
else{
temp_bool = true;
}
_discretionary = temp_bool;
}
void FinancialRecord::set_credit_val(std::string new_credit_val){
std::stringstream string_to_float;
string_to_float << new_credit_val;
string_to_float >> _credit_val;
}
void FinancialRecord::set_order(std::string new_order){
std::stringstream string_to_short;
string_to_short << new_order;
string_to_short >> _order;
}
void FinancialRecord::set_repay(std::string new_repay){
bool temp_bool;
std::transform(new_repay.begin(),new_repay.end(),new_repay.begin(), ::tolower);
if( new_repay == "0" || new_repay == "false" ){
temp_bool = false;
}
else{
temp_bool = true;
}
_repay = temp_bool;
}
void FinancialRecord::set_pending_total(std::string new_pending_total){
std::stringstream string_to_float;
string_to_float << new_pending_total;
string_to_float >> _pending_total;
}
void FinancialRecord::set_reconciled_val(std::string new_reconciled_val){
std::stringstream string_to_float;
string_to_float << new_reconciled_val;
string_to_float >> _reconciled_val;
}
void FinancialRecord::set_cleared_balance(std::string new_cleared_balance){
std::stringstream string_to_float;
string_to_float << new_cleared_balance;
string_to_float >> _cleared_balance;
}
void FinancialRecord::set_reconciled_balance(std::string new_reconciled_balance){
std::stringstream string_to_float;
string_to_float << new_reconciled_balance;
string_to_float >> _reconciled_balance;
}
void FinancialRecord::set_total_discretionary(std::string new_total_discretionary){
std::stringstream string_to_float;
string_to_float << new_total_discretionary;
string_to_float >> _total_discretionary;
}
void FinancialRecord::set_discretionary_amt(std::string new_discretionary_amt){
std::stringstream string_to_float;
string_to_float << new_discretionary_amt;
string_to_float >> _discretionary_amt;
}

// This is an automatically generated code
// Do Not Edit
Financial::date FinancialRecord::get_date(){
return _date;
}
int FinancialRecord::get_cleared_val(){
return _cleared_val;
}
std::string FinancialRecord::get_description(){
return _description;
}
float FinancialRecord::get_debit_val(){
return _debit_val;
}
int FinancialRecord::get_num(){
return _num;
}
std::string FinancialRecord::get_category(){
return _category;
}
std::string FinancialRecord::get_budget_category(){
return _budget_category;
}
std::string FinancialRecord::get_notes(){
return _notes;
}
std::string FinancialRecord::get_account(){
return _account;
}
bool FinancialRecord::get_discretionary(){
return _discretionary;
}
float FinancialRecord::get_credit_val(){
return _credit_val;
}
short FinancialRecord::get_order(){
return _order;
}
bool FinancialRecord::get_repay(){
return _repay;
}
float FinancialRecord::get_pending_total(){
return _pending_total;
}
float FinancialRecord::get_reconciled_val(){
return _reconciled_val;
}
float FinancialRecord::get_cleared_balance(){
return _cleared_balance;
}
float FinancialRecord::get_reconciled_balance(){
return _reconciled_balance;
}
float FinancialRecord::get_total_discretionary(){
return _total_discretionary;
}
float FinancialRecord::get_discretionary_amt(){
return _discretionary_amt;
}
// ENDIMPLEMENTATION
