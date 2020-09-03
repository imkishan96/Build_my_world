#include <gazebo-9/gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include "welcome_world.h"
#include <vector>

namespace gazebo

{   class SimpleCar_plugin;
    class ContactPlugin;
    class SimpleCar_plugin : public ModelPlugin
    {
        //friend class ContactPlugin;
    public:
        SimpleCar_plugin();
        void Load(physics::ModelPtr _parent, sdf::ElementPtr );
        void OnUpdate();

        int myturn = 0;
        std::vector<physics::ModelPtr>::size_type myID = 0;   
         

    private:
        physics::ModelPtr model;
        event::ConnectionPtr updateConnection;
        static SimpleCar_plugin blah;

    };
    //GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin)
}