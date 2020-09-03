#ifndef WELCOME_WORLD_H
#define WELCOME_WORLD_H

#include <gazebo-9/gazebo/gazebo.hh>

namespace gazebo
{
    class SimpleCar_plugin;

    class WorldPluginWelcome: public WorldPlugin
    {
        //friend class SimpleCar_plugin;
    public:
        WorldPluginWelcome(); // : WorldPlugin() 
        // {
        //     printf("Welcome to Kishan's World, Enjoy the show.!! \n");
        //     flag = true;
        // }
    public:
        void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);
        //{}
        static bool flag;
    };
    //GZ_REGISTER_WORLD_PLUGIN(WorldPluginWelcome)
}

#endif