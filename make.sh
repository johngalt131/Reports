
LIBPATH="\
-L/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
-L/Users/travisstaley/Documents/source-code/C++/packages/genericContainer/lib/ \
"
HPATH="\
-I./include/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/genericContainer/i_include/ \
"
LIBS="\
-ltinyxml \
-lcontainer \
"
SRC="\
FinancialRecordList.cpp
FinancialRecord.cpp
"
#Filters.cpp
MAIN="main"
for a in $SRC;do
    g++ -O0 -DTIXML_USE_STL -g -c -o ./objs/"$a".o ./src/"$a" $HPATH # $LIBPATH $LIBS 
done
#g++ -g -o music music.cpp $HPATH $LIBPATH $LIBS 
g++ -O0 -DTIXML_USE_STL -g -o  $MAIN src/"$MAIN".cpp objs/*.o $HPATH $LIBPATH $LIBS 