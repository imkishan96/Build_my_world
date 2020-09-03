#include "welcome_world.h"

using namespace gazebo;

WorldPluginWelcome::WorldPluginWelcome() : WorldPlugin() 
{
    //printf("Welcome to Kishan's World, Enjoy the show.!! \n");
    printf("------------WorldPlugin: Constructor ---------------\n");
    //bool flag = true;
}

void WorldPluginWelcome::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
{printf("------------WorldPlugin: Load ---------------\n");}

GZ_REGISTER_WORLD_PLUGIN(WorldPluginWelcome)