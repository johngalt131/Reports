
LIBPATH="\
-L/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
"
HPATH="\
-I./include/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
"
LIBS="\
-ltinyxml \
"
SRC="\
FinancialRecordList.cpp
FinancialRecord.cpp
Filters.cpp
"
MAIN="main"
for a in $SRC;do
    g++ -O3 -DTIXML_USE_STL -g -c -o ./objs/"$a".o ./src/"$a" $HPATH # $LIBPATH $LIBS 
done
#g++ -g -o music music.cpp $HPATH $LIBPATH $LIBS 
g++ -O3 -DTIXML_USE_STL -g -o  $MAIN src/"$MAIN".cpp objs/*.o $HPATH $LIBPATH $LIBS 