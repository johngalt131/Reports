#!/bin/bash

## Constants
# name of the file with all the fields
FIELD_FILE="fields.list"
# this is for the implementation methods
NAMESPACE="Financial"
CLASS="FinancialRecord"
# this replaces the tabs with spaces
TAB="  "
# output file for the property name structures
FILE_NAME="financial_structs.h"
# output file for the functions
GETTER_SETTER_METHODS_FILE="functions.cpp"
SETTER_ARGUMENT_PREFIX="new_"

FUNCTION_IMPLEMENTATIONS_FILE="FinancialRecord.cpp"
FUNCTION_PROTOTYPE_FILE="FinancialRecord.h"
FUNCTION_CASE_FILE="FinancialRecordList.cpp"

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
echo "number of props" | sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'| sed 's/$/\n\}\;/' >> $FILE_NAME
echo $NEWLINES >> $FILE_NAME
echo "#endif" >> $FILE_NAME

# Generate new getter and setter function names
# Setter Methods: prototypes
echo "" > $GETTER_SETTER_METHODS_FILE
echo "// BEGINPROTOTYPES" >> $GETTER_SETTER_METHODS_FILE
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// These are automatically generated getter and setter methods" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
echo "public:" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    newname="$SETTER_ARGUMENT_PREFIX$name"
    function_name=`echo "$name" | sed 's/^/set\_/'`
    MESSAGE="void $function_name(std::string $newname);"
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
echo "// These are automatically generated member variables" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
echo "private:" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do 
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    member_name=`echo "$name" | sed 's/^/\_/'`
    MESSAGE="$type $member_name;"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done
echo "// ENDPROTOTYPES" >> $GETTER_SETTER_METHODS_FILE

echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// BEGINCONSTRUCTOR" >> $GETTER_SETTER_METHODS_FILE
echo "// This is an automatically generated initialization block for constructor" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    value=`echo "$a" |  awk -F \; '{print $3}'`
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    newname="$SETTER_ARGUMENT_PREFIX$name"
    function_name=`echo "$name" | sed 's/^/set\_/'`
    MESSAGE="$function_name(\"$value\");"
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
done
echo "// ENDCONSTRUCTOR" >> $GETTER_SETTER_METHODS_FILE
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE

# Generate the tinyxml code
# This is partially dependent on the format of the xml file
# this is for the HandBase export format
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// BEGINCASE" >> $GETTER_SETTER_METHODS_FILE
echo "// This is automatically generated code" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    name=`echo "$a" | awk -F \; '{print $1}'| sed -n 's/\(.*\)/\U&/pg' | sed 's/\ /\_/g'`
    setter_function=`echo "$name" | sed 's/^/set\_/' | sed 's/\(.*\)/\L&/g'`
    temp_string="temp_string"
    echo "case $name:{" >> $GETTER_SETTER_METHODS_FILE
    echo "const char *temp = child->GetText();" >> $GETTER_SETTER_METHODS_FILE
    echo "std::string $temp_string;" >> $GETTER_SETTER_METHODS_FILE
    echo "if( temp ){ " >> $GETTER_SETTER_METHODS_FILE
    echo "temp_string = temp;" >> $GETTER_SETTER_METHODS_FILE
    echo "free(temp);" >> $GETTER_SETTER_METHODS_FILE
    echo "NAMEOFCLASS$setter_function($temp_string);" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
    echo "break;" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
done
echo "// case statements" >> $GETTER_SETTER_METHODS_FILE
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// ENDCASE" >> $GETTER_SETTER_METHODS_FILE

## Implementation of getters and setters
# setters
echo "// BEGINIMPLEMENTATION" >> $GETTER_SETTER_METHODS_FILE
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// This is an automatically generated code" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    newname="$SETTER_ARGUMENT_PREFIX$name"
    function_name=`echo "$name" | sed 's/^/set\_/'`
    echo "void $CLASS::$function_name(std::string $newname){" >> $GETTER_SETTER_METHODS_FILE
    if [ $type == "int" ];then
	aux_name="string_to_int"
	MESSAGE="std::stringstream $aux_name;
$aux_name << $newname;
$aux_name >> _$name;"
    elif [ $type == "float" ];then
	aux_name="string_to_float"
	MESSAGE="std::stringstream $aux_name;
$aux_name << $newname;
$aux_name >> _$name;"
    elif [ $type == "short" ];then
	aux_name="string_to_short"
	MESSAGE="std::stringstream $aux_name;
$aux_name << $newname;
$aux_name >> _$name;"
    elif [ $type == "bool" ];then
	aux_name="temp_bool"
	MESSAGE="bool $aux_name;
std::transform($newname.begin(),$newname.end(),$newname.begin(), ::tolower);
if( $newname == \"0\" || $newname == \"false\" ){
$aux_name = false;
}
else{
$aux_name = true;
}
_$name = $aux_name;"	
    elif [ $type == "Financial::date" ];then
	aux_name=""
	MESSAGE_FILE="template.date.cpp"
	cat $MESSAGE_FILE | sed "s/INSERT_NAME/$newname/" | sed "s/NAMESPACE/$NAMESPACE/" >> $GETTER_SETTER_METHODS_FILE
	echo "_$name = $newname;" >> $GETTER_SETTER_METHODS_FILE
    elif [ $type == "std::string" ];then
	aux_name="$newname"
	MESSAGE="_$name = $aux_name;"
    else
	echo "WHAT THE FUCK. Specify the right type" >> $GETTER_SETTER_METHODS_FILE
    fi
    echo "$MESSAGE" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
done

# getters
echo $NEWLINES >> $GETTER_SETTER_METHODS_FILE
echo "// This is an automatically generated code" >> $GETTER_SETTER_METHODS_FILE
echo "// Do Not Edit" >> $GETTER_SETTER_METHODS_FILE
cat $FIELD_FILE | while read a;do
    type=`echo "$a" |  awk -F \; '{print $2}'`
    name=`echo "$a" |  awk -F \; '{print $1}' | sed -n 's/\(.*\)/\L&/pg'`
    function_name=`echo "$name" | sed 's/^/get\_/'`
    echo "$type $CLASS::$function_name(){" >> $GETTER_SETTER_METHODS_FILE
    echo "return _$name;" >> $GETTER_SETTER_METHODS_FILE
    echo "}" >> $GETTER_SETTER_METHODS_FILE
done
echo "// ENDIMPLEMENTATION" >> $GETTER_SETTER_METHODS_FILE

# INDENT STRUCT FILE
indent $FILE_NAME
sed "s/\t/$TAB/" <$FILE_NAME > tmp && mv tmp $FILE_NAME


## now put all in the right places.

sed -n '1,/BEGINCASE/ p' < $FUNCTION_CASE_FILE > tmp
sed -n '/BEGINCASE/,/ENDCASE/ p' < $GETTER_SETTER_METHODS_FILE >> tmp
sed -n '/ENDCASE/,$ p' < $FUNCTION_CASE_FILE >> tmp
mv tmp $FUNCTION_CASE_FILE
indent $FILE_NAME
sed "s/\t/$TAB/" <$FILE_NAME > tmp && mv tmp $FILE_NAME


sed -n '1,/BEGINPROTOTYPES/ p' < $FUNCTION_PROTOTYPE_FILE > tmp
sed -n '/BEGINPROTOTYPES/,/ENDPROTOTYPES/ p' < $GETTER_SETTER_METHODS_FILE >> tmp
sed -n '/ENDPROTOTYPES/,$ p' < $FUNCTION_PROTOTYPE_FILE >> tmp
mv tmp $FUNCTION_PROTOTYPE_FILE
indent $FUNCTION_PROTOTYPE_FILE
sed "s/\t/$TAB/" <$FUNCTION_PROTOTYPE_FILE > tmp && mv tmp $FUNCTION_PROTOTYPE_FILE

sed -n '1,/BEGINIMPLEMENTATION/ p' < $FUNCTION_IMPLEMENTATIONS_FILE > tmp
sed -n '/BEGINIMPLEMENTATION/,/ENDIMPLEMENTATION/ p' < $GETTER_SETTER_METHODS_FILE >> tmp
sed -n '/ENDIMPLEMENTATION/,$ p' < $FUNCTION_IMPLEMENTATIONS_FILE >> tmp
mv tmp $FUNCTION_IMPLEMENTATIONS_FILE

sed -n '1,/BEGINCONSTRUCTOR/ p' < $FUNCTION_IMPLEMENTATIONS_FILE > tmp
sed -n '/BEGINCONSTRUCTOR/,/ENDCONSTRUCTOR/ p' < $GETTER_SETTER_METHODS_FILE >> tmp
sed -n '/BEGINCONSTRUCTOR/,$ p' < $FUNCTION_IMPLEMENTATIONS_FILE >> tmp
mv tmp $FUNCTION_IMPLEMENTATIONS_FILE
indent $FUNCTION_IMPLEMENTATIONS_FILE
sed "s/\t/$TAB/" <$FUNCTION_IMPLEMENTATIONS_FILE > tmp && mv tmp $FUNCTION_IMPLEMENTATIONS_FILE




