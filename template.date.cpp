NAMESPACE::date temp_date;
char *delete_me;
char *temp = strdup(INSERT_NAME.c_str());
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
  std::cout << "INSERT_NAME.month = " << new_int
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
  std::cout << "INSERT_NAME.year = " << new_int
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
  std::cout << "INSERT_NAME._time.hours = " << new_int
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
  std::cout << "INSERT_NAME._time.minutes = " << new_int
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
  std::cout << "INSERT_NAME._time.seconds = " << new_int
	    << " And is out of range. " << std::endl;
 }
 else{
   temp_date._time.seconds = new_int;
 }
 }
free(temp);
