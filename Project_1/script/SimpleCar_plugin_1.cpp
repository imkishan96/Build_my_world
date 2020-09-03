#include "SimpleCar_plugin_1.h"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin_1)

SimpleCar_plugin_1::SimpleCar_plugin_1() : ModelPlugin(){
    //printf("------------SimpleCar_plugin_1: constructor ---------------\n");
}

void SimpleCar_plugin_1::Load(physics::ModelPtr _parent, sdf::ElementPtr )
{   
    //printf("------------SimpleCar_plugin_1: Load ---------------\n");    
    this->model = _parent;
    this->updateConnection = event::Events::ConnectWorldUpdateBegin
        (std::bind(&SimpleCar_plugin_1::OnUpdate, this));
}

void SimpleCar_plugin_1::OnUpdate()
{   
    ignition::math::Vector3d init_vel(0.3, 0, 0);
    this->model->SetLinearVel(init_vel);
}
