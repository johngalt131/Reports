
LIBPATH="\
-L/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
"
HPATH="\
-I/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
"
LIBS="\
-ltinyxml \
"
SRC="\
FinancialRecordList.cpp
FinancialRecord.cpp
"
MAIN="main"
for a in $SRC;do
    g++ -DTIXML_USE_STL -g -c -o ./objs/"$a".o "$a" $HPATH # $LIBPATH $LIBS 
done
#g++ -g -o music music.cpp $HPATH $LIBPATH $LIBS 
g++ -DTIXML_USE_STL -g -o  $MAIN "$MAIN".cpp objs/*.o $HPATH $LIBPATH $LIBS 