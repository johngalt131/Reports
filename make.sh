#!/bin/bash

if [ $1 == "all" 2>/dev/null ];then
    echo "Making type2name"
    pushd /Users/travisstaley/Documents/source-code/C++/packages/type2name/
    ./make.sh
    popd
    echo "Making generic Container"
    pushd /Users/travisstaley/Documents/source-code/C++/packages/genericContainer/
    ./make.sh
    popd
fi
LIBPATH="\
-L/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
-L/Users/travisstaley/Documents/source-code/C++/packages/type2name/lib/ \
-L/Users/travisstaley/Documents/source-code/C++/packages/genericContainer/lib/ \
"
HPATH="\
-I./include/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/tinyxml/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/type2name/include/ \
-I/Users/travisstaley/Documents/source-code/C++/packages/genericContainer/i_include/ \
"
LIBS="\
-ltinyxml \
-lcontainer \
-ltypetoname \
"
SRC="\
RecordList.cpp
Record.cpp
Filters.cpp
"
#Filters.cpp
MAIN="main"
echo "Making Reports"
rm objs/*
# -DUSE_FILTERS
for a in $SRC;do
    g++ -O0 -DTIXML_USE_STL -DUSE_FILTERS  -g -c -o objs/$a.o ./src/$a $HPATH # $LIBPATH $LIBS]
done
#g++ -g -o music music.cpp $HPATH $LIBPATH $LIBS 
g++ -O0 -DTIXML_USE_STL -g -o  $MAIN src/"$MAIN".cpp objs/*.o $HPATH $LIBPATH $LIBS
echo "Done"