#include "ContactPlugin.h"

using namespace gazebo;

GZ_REGISTER_SENSOR_PLUGIN(ContactPlugin)

ContactPlugin::ContactPlugin() : SensorPlugin()
{
    printf("------------ContactPlugin: constructor ---------------\n");
}

ContactPlugin::~ContactPlugin()
{
}

void ContactPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
    this->parentSensor = 
    std::dynamic_pointer_cast<sensors::ContactSensor>(_sensor);
    if(!this->parentSensor)
    {
        gzerr << " come on bro! where is ContactSensor. \n" ;
        return;
    }

    this->updateConnection = this->parentSensor->ConnectUpdated(
        std::bind(&ContactPlugin::onUpdate, this));

    this->parentSensor->SetActive(true);
}

void ContactPlugin::onUpdate()
{   
    //printf("Collision detected.! \n");
    
    msgs::Contacts contacts;
    contacts = this->parentSensor->Contacts();
    if(contacts.contact_size()){
        printf("Collision detected.! \n");
    }

    // for (unsigned int i = 0; i < contacts.contact_size(); ++i)
    // {
    //     std::cout << "Collision between[" << contacts.contact(i).collision1()
    //             << "] and [" << contacts.contact(i).collision2() << "]\n";

    //     for (unsigned int j = 0; j < contacts.contact(i).position_size(); ++j)
    //     {
    //     std::cout << j << "  Position:"
    //                 << contacts.contact(i).position(j).x() << " "
    //                 << contacts.contact(i).position(j).y() << " "
    //                 << contacts.contact(i).position(j).z() << "\n";
    //     std::cout << "   Normal:"
    //                 << contacts.contact(i).normal(j).x() << " "
    //                 << contacts.contact(i).normal(j).y() << " "
    //                 << contacts.contact(i).normal(j).z() << "\n";
    //     std::cout << "   Depth:" << contacts.contact(i).depth(j) << "\n";
    //     }
    // }    
}
