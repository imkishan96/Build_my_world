#ifndef SIMPLECAR_PLUGIN_H
#define SIMPLECAR_PLUGIN_H


#include <gazebo-9/gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo

{
    class SimpleCar_plugin : public ModelPlugin
    {
    public:
        SimpleCar_plugin();
        void Load(physics::ModelPtr _parent, sdf::ElementPtr );
        void OnUpdate();

    private:
        physics::ModelPtr model;
        event::ConnectionPtr updateConnection;
    };
    //GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin)
}

#endif