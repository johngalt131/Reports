#!/bin/bash

MAKE=0
if [ $1 == "all" ];then
    MAKE=1
fi

if [ $MAKE -gt 0];then
    pushd tinyxml
    make clean
    make
    ar cr libtinyxml.a *.o
    mv libtinyxml.a ./lib/
    popd
fi
pushd Reports
g++ -g -c *.cpp -I. -I../tinyxml/ 2>&1
rm Report.o
rm ItunesLibrary.o
g++ -g -o Report *.o Report.cpp -I../tinyxml/ -L../tinyxml/lib/ -ltinyxml 2>&1
#g++ -g -c Report.cpp -I. -I../tinyxml/ 2>&1
popd