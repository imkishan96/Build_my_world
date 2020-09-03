#include "SimpleCar_plugin.h"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin)

SimpleCar_plugin::SimpleCar_plugin() : ModelPlugin(){
    printf("------------SimpleCar_plugin: constructor ---------------\n");
    //obj_vec.push_back(this);
    //this->myID = obj_vec.size()-1; 
    //printf("------------SimpleCar_plugin: constructor ---------------\n");
}

void SimpleCar_plugin::Load(physics::ModelPtr _parent, sdf::ElementPtr )
{   
    //obj_vec.push_back(this);
    printf("------------SimpleCar_plugin: Load ---------------\n");
    
    this->model = _parent;
    this->updateConnection = event::Events::ConnectWorldUpdateBegin
        (std::bind(&SimpleCar_plugin::OnUpdate, this));
    
    printf("------------SimpleCar_plugin: Obj_vec assigned ---------------\n");
}

void SimpleCar_plugin::OnUpdate()
{   
    if(myturn == 0)
    {   
        blah = *this;
        //this->obj_vec.push_back(this);
        myturn = 1;// SimpleCar_plugin::obj_vec.size() - 1;
        printf("------------SimpleCar_plugin: Onupdate(myID) ---------------\n");
    }
    ignition::math::Vector3d init_vel(0, 0.3, 0);
    this->model->SetLinearVel(init_vel);
    // if(myturn==0 && WorldPluginWelcome::flag == false)
    // {
    //     myturn ==1;
    //     WorldPluginWelcome::flag = true;
    // }
}
