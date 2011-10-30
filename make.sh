#!/bin/bash

pushd tinyxml
make clean
make
ar cr libtinyxml.a *.o
mv libtinyxml.a ./lib/
popd
pushd Reports
g++ -g -c *.cpp -I. -I../tinyxml/
rm Report.o
g++ -g -o Report *.o Report.cpp -I../tinyxml/ -L../tinyxml/lib/ -ltinyxml
popd