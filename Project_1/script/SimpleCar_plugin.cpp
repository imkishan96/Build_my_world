#include "SimpleCar_plugin.h"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin)

SimpleCar_plugin::SimpleCar_plugin() : ModelPlugin(){
    printf("------------SimpleCar_plugin: constructor ---------------\n");
}

void SimpleCar_plugin::Load(physics::ModelPtr _parent, sdf::ElementPtr )
{   
    printf("------------SimpleCar_plugin: Load ---------------\n");    
    this->model = _parent;
    this->updateConnection = event::Events::ConnectWorldUpdateBegin
        (std::bind(&SimpleCar_plugin::OnUpdate, this));
}

void SimpleCar_plugin::OnUpdate()
{   
    ignition::math::Vector3d init_vel(0, 0.3, 0);
    this->model->SetLinearVel(init_vel);
}
