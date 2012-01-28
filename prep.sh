#!/bin/bash

FIELD_FILE="fields.list"
NAMESPACE_OR_CLASS="Financial"
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
# other function prototypes or static data ...
ADDITIONAL_DATA="

"
echo "$H_FILE_INFO" > $FILE_NAME
NAMES_CHAR_HEADER="static const char* const PROPERTY_NAME[] = {"
# Get the list
echo "$NAMES_CHAR_HEADER" >> $FILE_NAME

cat $FIELD_FILE | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'`
    echo "\"$name\",">> $FILE_NAME
done
echo "\"Unknown Type\"" | sed 's/$/\n\}\;/' >> $FILE_NAME
echo $NEWLINES >> $FILE_NAME

NAMES_ENUM_HEADER="typedef enum PROPERTY_NAME_E{"
echo "$NAMES_ENUM_HEADER" >> $FILE_NAME


cat $FIELD_FILE | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'| sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'`
    echo "$name,">> $FILE_NAME
done
echo "Unknown Type," | sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'>> $FILE_NAME
echo "number of propers" | sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'| sed 's/$/\n\}\;/' >> $FILE_NAME
echo $NEWLINES >> $FILE_NAME
echo "#endif" >> $FILE_NAME

# Generate new getter and setter function names
# Setter Methods
echo "" > $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/set\_/'`
    MESSAGE="void $function_name($type $name);"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
# Getter Methods
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/get\_/'`
    MESSAGE="$type $function_name(void);"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
# Members
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    member_name=`echo "$name" | sed 's/^/\_/'`
    MESSAGE="$type $member_name;"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done


# Generate the tinyxml code
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'| sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'`
    setter_function=`echo "$name" | sed 's/^/set\_/'`
    echo "case $name:" >> $GETTER_SETTER_METHODS_FILE
    echo "$setter_function(child->GetText());" >> $GETTER_SETTER_METHODS_FILE
    echo "break;" >> $GETTER_SETTER_METHODS_FILE
done
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE


## Implementation of getters and setters
# setters
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/set\_/'`
    echo "void $NAMESPACE_OR_CLASS::$function_name($type $name){" >> $GETTER_SETTER_METHODS_FILE
    echo "_$name = $name;" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
done

# getters
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/get\_/'`
    echo "$type $NAMESPACE_OR_CLASS::$function_name(){" >> $GETTER_SETTER_METHODS_FILE
    echo "return _$name;" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
done




# INDENT STRUCT FILE
indent $FILE_NAME
sed "s/\t/$TAB/" <$FILE_NAME > tmp && mv tmp $FILE_NAME