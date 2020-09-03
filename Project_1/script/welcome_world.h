#ifndef WELCOME_WORLD_H
#define WELCOME_WORLD_H

#include <gazebo/gazebo.hh>

namespace gazebo
{
    class WorldPluginWelcome: public WorldPlugin
    {
    public:
        WorldPluginWelcome(); 
 
    public:
        void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);
    };
}

#endif