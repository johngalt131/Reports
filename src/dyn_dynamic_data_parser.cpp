/*
 *   File Name: dyn_dynamic_data_parser.cpp
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

#include "dyn_dynamic_data_parser.h"

using namespace DYN;

// ----------------------------------------------------------------------------
//
DynamicDataParser::DynamicDataParser()
{
}

// ----------------------------------------------------------------------------
//
DynamicDataParser::~DynamicDataParser(void)
{
}

// ----------------------------------------------------------------------------
//
bool DynamicDataParser::parseDynamicDataFile(
    const std::string                & dynamic_data_file_name,
    DYNAMIC_OBJECT_STATES_CONTAINER  & dynamic_objects,
    MINEFIELDS_CONTAINER             & minefields,
    ASSOCIATIONS_CONTAINER           & associations)
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
        XMLdoc(dynamic_data_file_name.c_str());

    if (not XMLdoc.LoadFile())
    {
        std::cout << "PARSER ERROR !!! " << dynamic_data_file_name << std::endl;

        syslog(LOG_ERR,
            "DYN DATA PARSER: Failed to load file %s",
            XMLdoc.ErrorDesc());
        success = false;
    }
    else
    {
        syslog(LOG_INFO,
            "_Parser: Parsing %s", dynamic_data_file_name.c_str());

        root = XMLdoc.FirstChildElement("DynamicData");

        if (root)
        {
            try
            {
                TiXmlElement *dyn_obj_element =
                    root->FirstChildElement("DynamicObjects");

                TiXmlElement *child =
                    dyn_obj_element->FirstChildElement("DynamicObject");

                //<DynamicObject
                //      name="Cargo box"   visual_model="xm_cargobox"
                //      hazard_type="IED"
                //      uuid="244a1586-f7cd-4fc2-a57c-111dbdbcc19b"
                //      visibility="AboveGround" status="Active">
                //   <Placement
                //       x="6160.041" y="21572.43" z="4.86066"
                //       yaw="0"   pitch="0" roll="0" />
                //</DynamicObject>
                while (child)
                {
                    std::string
                        name_string         = child->Attribute("name"),
                        visual_model_string = child->Attribute("visual_model"),
                        visibility_string   = child->Attribute("visibility"),
                        hzrd_type_string    = child->Attribute("hazard_type"),
                        status_string       = child->Attribute("status"),
                        uuid_string         = child->Attribute("uuid");

                    TiXmlElement *placement =
                        child->FirstChildElement("Placement");

                    std::string
                        x_string     = placement->Attribute("x"),
                        y_string     = placement->Attribute("y"),
                        z_string     = placement->Attribute("z"),
                        yaw_string   = placement->Attribute("yaw"),
                        pitch_string = placement->Attribute("pitch"),
                        roll_string  = placement->Attribute("roll");

                    DYNAMIC_OBJECT_STATE_T
                        dynamic_object;

                    memset(&dynamic_object, 0, sizeof(DYNAMIC_OBJECT_STATE_T));

                    try
                    {
                        memcpy(&dynamic_object.uuid, uuid_string.c_str(), sizeof(UUID_T));

                        if (status_string == "Active")
                        {
                            dynamic_object.status = OBJ_ACTIVE;
                        }
                        else
                        {
                            // FIXME: handle all the other STATUS cases
                            dynamic_object.status = OBJ_IN_ACTIVE;
                        }

                        unsigned short tmpUShort = 0;
                        
                        if (UTILITIES::MODEL_INFO::ModelMap::instance().getModelType(
                                     visual_model_string, tmpUShort)) {
                            dynamic_object.model_type = tmpUShort;
                        } else {
                            syslog(LOG_ERR,
                                    "DYN OBJECT PARSER: INVALID VISUAL MODEL TYPE ");
                            dynamic_object.model_type = 99;
                        }

                        if (visibility_string == "Underground")
                        {
                            dynamic_object.visibility_state  = OBJ_UNDERGROUND;
                        }
                        else if (visibility_string == "PartiallyUnderground")
                        {
                            dynamic_object.visibility_state  = OBJ_PARTIALY_UNDERGROUND;
                        }
                        else if (visibility_string == "AboveGround")
                        {
                            dynamic_object.visibility_state  = OBJ_ABOVE_GROUND;
                            // same as OBJ_ABOVE_GROUND
                        }

                        dynamic_object.triggered = false;
                        dynamic_object.visible = true;


                        if (hzrd_type_string != "Minefield")
                        {
                            dynamic_object.movable   = true;
                        }

                        dynamic_object.location.p.x     = convertTo<float>(x_string);
                        dynamic_object.location.p.y     = convertTo<float>(y_string);
                        dynamic_object.location.p.z     = convertTo<float>(z_string);
                        dynamic_object.location.o.yaw   = convertTo<float>(yaw_string);
                        dynamic_object.location.o.pitch = convertTo<float>(pitch_string);
                        dynamic_object.location.o.roll  = convertTo<float>(roll_string);

                        success = true;
                    }
                    catch (BadConversion  e)
                    {
                        syslog(LOG_ERR,
                            "property XML_Parser: Failed to convert string !");
                        success = false;
                    }

                    // insert in the map let the buyer be aware!!!
                    dynamic_objects[dynamic_object.uuid] = dynamic_object;

                    child = child->NextSiblingElement("DynamicObject");
                }

                //<Associations>
                //  <ControllingObject uuid="55e55c6b-ba18-4b5e-8163-837a2752e681"   >
                //       <AssociatedWith uuid="22e22c6b-ba18-4b5e-8163-837a2752e681" />
                //       <AssociatedWith uuid="42e42c6b-ba18-4b5e-8163-837a2752e681" />
                //  </ControllingObject>
                //</Associations>
                TiXmlElement
                    *associations_ptr =
                        dyn_obj_element->NextSiblingElement("Associations");

                TiXmlElement
                    *controlling_object_ptr= NULL;
                if (associations_ptr)
                {
                    controlling_object_ptr =
                    associations_ptr->FirstChildElement("ControllingObject");
                }

                while (controlling_object_ptr)
                {
                    UUID_T
                       temp_controller_id;

                    memcpy(&temp_controller_id,
                         controlling_object_ptr->Attribute("uuid"), sizeof(UUID_T));

                    TiXmlElement *associated_with =
                        controlling_object_ptr->FirstChildElement("AssociatedWith");
                    DYN::UUID_CONTAINER
                        temp_uuids;

                    temp_uuids.clear();

                    while (associated_with)
                    {
                        UUID_T
                           temp_id;

                        memcpy(&temp_id, associated_with->Attribute("uuid"), sizeof(UUID_T));
                        temp_uuids.push_back(temp_id);

                        associated_with = associated_with->NextSiblingElement("AssociatedWith");
                    }

                    associations[temp_controller_id] = temp_uuids;

                    controlling_object_ptr =
                            controlling_object_ptr->NextSiblingElement("ControllingObject");
                }

                // <Minefield name="Minefield1"
                //     visual_model="xx_marked_mine_field"
                //            uuid="13e11c6b-ba18-4b5e-8163-837a2752e681" >
                //     <Corner x="x1" y="y1" z="z1"  />
                //     <Corner x="x2" y="y2" z="z2"  />
                //     <Corner x="x3" y="y3" z="z3"  />
                //     <Corner x="x4" y="y4" z="z4"  />
                // </Minefield>
                DYN::UUID_CONTAINER
                    mf_uuids;

                TiXmlElement
                    *all_minefields_ptr =
                        dyn_obj_element->NextSiblingElement("Minefields");
                TiXmlElement
                    *minefield_ptr = NULL;

                if (all_minefields_ptr)
                {
                    minefield_ptr =
                       all_minefields_ptr->FirstChildElement("Minefield");
                }

                while (minefield_ptr)
                {
                    UUID_T
                       temp_mf_id;

                    MINEFIELD_T
                       temp_minefield;

                    memset(&temp_minefield,0, sizeof(MINEFIELD_T));

                    // FIXME other attributes
                    memcpy(&temp_mf_id,
                        minefield_ptr->Attribute("uuid"), sizeof(UUID_T));

                    std::string
                         mf_vis_model_name =
                                 minefield_ptr->Attribute("visual_model");

                    temp_minefield.minefield_type = 1; // This is not used anywhere

                    std::string
                       x_str, y_str, z_str;

                    TiXmlElement *corner_ptr =
                            minefield_ptr->FirstChildElement("Corner");

                    for (int i=0; corner_ptr != 0 ; i++)
                    {
                        x_str = corner_ptr->Attribute("x");
                        y_str = corner_ptr->Attribute("y");
                        z_str = corner_ptr->Attribute("z");

                        temp_minefield.corners.corner[i].x = convertTo<float>(x_str);
                        temp_minefield.corners.corner[i].y = convertTo<float>(y_str);
                        temp_minefield.corners.corner[i].z = convertTo<float>(z_str);

                        corner_ptr = minefield_ptr->NextSiblingElement("Corner");
                    }

                    minefields[temp_mf_id] = temp_minefield;

                    minefield_ptr =
                            minefield_ptr->NextSiblingElement("Minefield");
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








