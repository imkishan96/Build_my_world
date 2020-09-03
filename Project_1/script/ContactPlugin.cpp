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
{   printf("------------ContactPlugin: Load ---------------\n");
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
    msgs::Contacts contacts;
    contacts = this->parentSensor->Contacts();
    if(contacts.contact_size()){
        printf("Collision detected.! \n");

    }  
}
