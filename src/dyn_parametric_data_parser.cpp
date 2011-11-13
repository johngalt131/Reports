/*
 *   File Name: dyn_dynamic_object_parser.cpp
 *
 *   Classification:  Unclassified
 *
 *   Project Name:    Common Driver Trainer
 *
 *   Contract Number: N61339-00-D-0710/0029
 *
 *   This work was generated under U.S. Government contract and the
 *   U.S. Government has unlimited data rights therein.
 *
 *   Copyright:       Copyrights 2008, 2009, 2010, 2011
 *                    Science Applications International Corporation,
 *                    All Rights reserved.
 *
 *
 *   DISTRIBUTION STATEMENT D:
 *
 *                    DISTRIBUTION AUTHORIZED TO THE DEPARTMENT OF
 *                    DEFENSE AND U.S. DOD CONTRACTORS ONLY DUE TO
 *                    SOFTWARE DOCUMENTATION; EFFECTIVE 1 OCTOBER 2007.
 *                    OTHER REQUESTS SHALL BE REFERRED TO US ARMY,
 *                    PEO-STRI-SFAE-PM CATT-GC.
 *
 *   Organization:    Science Applications International Corporation
 *                    12901 Science Drive
 *                    Orlando, FL 32826-3014
 *                    (407) 243-3700
 *
 */

#include "dyn_parametric_data_parser.h"
#include <tinyxml.h>
#include <stddef.h>
#include <dirent.h>
#include "ModelMap.h"

using namespace DYN;

// ----------------------------------------------------------------------------
//
ParametricDataParser::ParametricDataParser()
{
    std::string
        property_name_string,
        property_type_string;

    DYN::PROPERTY_NAME_E
        property_name;

    DYN::PROPERTY_TYPE_E
        property_type;

    for (int i=0; i < DYN::NUM_PROPERTY_NAMES; i++)
    {
        property_name_string = DYN::PROPERTY_NAMES[i];
        property_name = (DYN::PROPERTY_NAME_E) i;

        my_prop_str_name_to_enum[property_name_string] = property_name;
    }

    for (int i=0; i < DYN::NUM_PROPERTY_TYPES; i++)
    {
        property_type_string = DYN::PROPERTY_TYPES[i];
        property_type = (DYN::PROPERTY_TYPE_E) i;

        my_prop_str_type_to_enum[property_type_string] = property_type;
    }
}

// ----------------------------------------------------------------------------
//
ParametricDataParser::~ParametricDataParser(void)
{
    my_prop_str_name_to_enum.clear();
    my_prop_str_type_to_enum.clear();
}

// ----------------------------------------------------------------------------
//
// Parses the entire parametric data directory and all the files in it that are
// associated with any dynamic object
//
bool ParametricDataParser::parseAllParametricData(
    const std::string                   & parametric_data_dir,
    VIS_NAME_2PROPNAME2_PROPERTIES_MAP  & all_param_data)
{
    bool
       success = false;
    uint16
        vis_model_type = 0;

    //  Go through the directory and read all the files
    DIR *dp;
    struct dirent *ep;

    std::vector<std::string>
        vis_model_directory_names;

    dp = opendir (parametric_data_dir.c_str());

    if (dp != NULL)
    {
        while (ep = readdir (dp))
        {
            //puts (ep->d_name); // to print it
            std::string model_name(ep->d_name);

            if (model_name.rfind("xm") != std::string::npos)
            {
                vis_model_directory_names.push_back("/"+model_name+"/");

                success = true;
            }
        }

        syslog(LOG_INFO,
            "DYN::parseParametricData() num files to be processed  %d",
            vis_model_directory_names.size());

        (void) closedir (dp);
    }
    else
    {
        syslog(LOG_ERR,
            "DYN::parseParametricData() Couldn't open the parametric data directory");
    }

    for (int i = 0; success and i < vis_model_directory_names.size(); i++)
    {
        std::string
            model_alias;
        PROP_NAME_2_PROPERTIES_MAP
             prop_type_2properties;

        std::string
            file_name  = parametric_data_dir + vis_model_directory_names[i];

        dp = opendir (file_name.c_str());

        if (dp != NULL)
        {
            if (ep = readdir (dp))
            {
                //puts (ep->d_name); // FIXME
                std::string file_name(ep->d_name);

                if (file_name.rfind("Prop") != std::string::npos)
                {
                    success = parseParametricDataFile(
                        parametric_data_dir + vis_model_directory_names[i]+ file_name,
                        model_alias,
                        vis_model_type,
                        prop_type_2properties);

                    all_param_data[vis_model_type] = prop_type_2properties;

                    syslog(LOG_INFO,
                        "DYN::parseParametricData() the parametric file name is  %s",
                        vis_model_directory_names[i].c_str());
                }
            }
            else
            {
                syslog(LOG_ERR,
                    "DYN::parseParametricData() this file  %s "
                    " does not belong in this directory",
                    vis_model_directory_names[i].c_str());
            }

            (void) closedir (dp);
        }
        else
        {
            success = false;
            std::cout << "ERROR - Parsing The Dynamic Data Directory -"
                    "NULL when i = is " << i << std::endl ;
        }
    }

    return success;
}

// ----------------------------------------------------------------------------
//
bool ParametricDataParser::parseParametricDataFile(
            const std::string           &parametric_data_file_name,
            std::string                 &model_alias,
            uint16                      &vis_model_type,
            PROP_NAME_2_PROPERTIES_MAP  &prop_type_2properties)
{
    bool
        success = false;

    TiXmlElement
        *root,
        *child,
        *parent,
        *property;

    // Load the xml file
    TiXmlDocument
        XMLdoc(parametric_data_file_name.c_str());

    if (not XMLdoc.LoadFile())
    {
        std::cout << "LOADING FILE ERROR " << std::endl;

        // log error
        syslog(LOG_ERR,
            "DYN OBJECT PARSER: Failed to load file %s",
            XMLdoc.ErrorDesc());
        success = false;
    }
    else
    {
        syslog(LOG_INFO,
            "_Parser: Parsing %s", parametric_data_file_name.c_str());

        root = XMLdoc.FirstChildElement("Object");

        if (root)
        {
            // We don't really need these but just in case we do
            std::string
                visual_model_name = root->Attribute("Name"),
                type = root->Attribute("Type"),  // Always DynamicObject
                the_model_alias = root->Attribute("Alias");

            model_alias = the_model_alias;

            bool
                found = UTILITIES::MODEL_INFO::ModelMap::instance().getModelType(
                             visual_model_name, vis_model_type);

            if (found)
            {
                syslog(LOG_ERR,
                        "DYN OBJECT PARSER: INVALID VISUAL MODEL TYPE ");
            }

            try
            {
                TiXmlElement *child =
                    root->FirstChildElement("PhysicalProperties");

                child = child->FirstChildElement("attribute");

                while (child)
                {
                    std::string
                        name_string  = child->Attribute("name"),
                        type_string  = child->Attribute("type"),
                        value_string = child->Attribute("value");

                    // Find out what enum to load and what convert the string of value to
                    DYN::PROPERTY_NAME_E
                       name = getPropertyName(name_string);

                    DYN::PROPERTY_TYPE_E
                       type = getPropertyType(type_string);

                     //std::cout<< "XXX name_string  "<< name_string << std::endl;
                     //std::cout<< "XXX type_string  "<< type_string << std::endl;
                     //std::cout<< "XXX value_string "<< value_string<< std::endl;

                    if (name != DYN::INVALID_PROPERTY_NAME and
                        type != DYN::INVALID_PROPERTY_TYPE)
                    {
                        DYN::ObjectProperty
                            object_property;

                        try
                        {
                            DYN::PROPERTY_DATA_TYPE_E
                                prop_data_type =
                                    DYN::ObjectProperty::getPropertyValueDataType(type);

                            if (prop_data_type==DYN::INT_DATA_TYPE)
                            {
                                int
                                    temp_int_val = convertTo<int>(value_string);

                                //std::cout << "INT name_string  "
                                //          << name_string   << std::endl;
                                //std::cout << "
                                //          INT type_string  " << type_string
                                //          << std::endl;
                                //std::cout << "           INT value_string "
                                //          << value_string << std::endl;
                                //std::cout << "           INT temp_int_val "
                                //          << temp_int_val << std::endl;

                                object_property.setAll(
                                    name, type, temp_int_val);
                                success = true;
                            }
                            else if (prop_data_type == DYN::FLOAT_DATA_TYPE)
                            {
                                float
                                    temp_float_val = convertTo<float>(value_string);

                                //std::cout << "FLOAT name_string  "
                                //  << name_string   << std::endl;
                                //std::cout << "          FLOAT type_string  "
                                //  << type_string   << std::endl;
                                //std::cout << "          FLOAT  value_string "
                                //  << value_string << std::endl;
                                //std::cout << "          FLOAT  temp_float_val "
                                //  << temp_float_val << std::endl;

                                object_property.setAll(
                                    name, type, temp_float_val);
                                success = true;
                            }
                        }
                        catch (BadConversion  e)
                        {
                            syslog(LOG_ERR,
                                "property XML_Parser: Failed to convert string !");
                            success = false;
                        }

                        // insert in the map let the buyer be aware!!!
                        prop_type_2properties[name] = object_property;
                    }

                    child = child->NextSiblingElement("attribute");
                }
            }
            catch (NullPointerError const &e)
            {
                syslog(LOG_ERR,
                    "XML_Parser: Unexpected data from the properties file %s",
                    e.what());

                success = false;
            }
        }
    }

    return success;
}

// ----------------------------------------------------------------------------
//
DYN::PROPERTY_TYPE_E ParametricDataParser::getPropertyType(
                const std::string &property_type_string)
{
    DYN::PROPERTY_TYPE_E
         type = DYN::INVALID_PROPERTY_TYPE;

    std::map<std::string, DYN::PROPERTY_TYPE_E>::iterator
        itor;

    itor = my_prop_str_type_to_enum.find(property_type_string);

    if (itor != my_prop_str_type_to_enum.end())
    {
        type = itor->second;
    }

    return type;
}

// ----------------------------------------------------------------------------
//
DYN::PROPERTY_NAME_E ParametricDataParser::getPropertyName(
                const std::string &property_name_string)
{
    DYN::PROPERTY_NAME_E
        name = DYN::INVALID_PROPERTY_NAME;

    std::map<std::string, DYN::PROPERTY_NAME_E>::iterator
        itor;

    itor =  my_prop_str_name_to_enum.find(property_name_string);

    if (itor != my_prop_str_name_to_enum.end())
    {
        name = itor->second;
    }

    return name;
}


