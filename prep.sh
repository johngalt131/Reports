#!/bin/bash

TAB="  "
FILE_NAME="financial_structs.h"
GETTER_SETTER_METHODS_FILE="functions.txt"
# Empty the file
H_FILE_INFO="
// This file was created by prep.sh
// Do Not Edit

#ifndef FINANCIALSTRUCTS_H_
#define FINANCAILSTRUCTS_H_
"
NEWLINES="

"
ADDITIONAL_DATA="

"
echo "$H_FILE_INFO" > $FILE_NAME
NAMES_CHAR_HEADER="static const char* const PROPERTY_NAME[] = {"
# Get the list
echo "$NAMES_CHAR_HEADER" >> $FILE_NAME

cat fields.list | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'`
    echo "\"$name\",">> $FILE_NAME
done
echo "\"Unknown Type\"" | sed 's/$/\n\}\;/' >> $FILE_NAME
echo $NEWLINES >> $FILE_NAME

NAMES_ENUM_HEADER="typedef enum PROPERTY_NAME_E{"
echo "$NAMES_ENUM_HEADER" >> $FILE_NAME


cat fields.list | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'| sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'`
    echo "$name,">> $FILE_NAME
done
echo "Unknown Type," | sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'>> $FILE_NAME
echo "number of propers" | sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'| sed 's/$/\n\}\;/' >> $FILE_NAME
echo $NEWLINES >> $FILE_NAME
echo "#endif" >> $FILE_NAME

# Generate new getter and setter function names
echo "" > $GETTER_SETTER_METHODS_FILE
cat fields.list | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/set\_/'`
    MESSAGE="void $function_name($type $name);"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
cat fields.list | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/set\_/'`
    MESSAGE="$type $function_name(void);"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done


# INDENT
indent $FILE_NAME
sed "s/\t/$TAB/" <$FILE_NAME > tmp && mv tmp $FILE_NAME