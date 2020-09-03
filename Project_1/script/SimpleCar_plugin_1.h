#ifndef SIMPLECAR_PLUGIN_1_H
#define SIMPLECAR_PLUGIN_1_H


#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo

{
    class SimpleCar_plugin_1 : public ModelPlugin
    {
    public:
        SimpleCar_plugin_1();
        void Load(physics::ModelPtr _parent, sdf::ElementPtr );
        void OnUpdate();

    private:
        physics::ModelPtr model;
        event::ConnectionPtr updateConnection;
    };

}

#endif