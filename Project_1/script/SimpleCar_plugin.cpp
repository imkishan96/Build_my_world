#include <gazebo-9/gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo
{
    class SimpleCar_plugin : public ModelPlugin
    {
    public:
        void Load(physics::ModelPtr _parent, sdf::ElementPtr )
        {
            this->model = _parent;
            this->updateConnection = event::Events::ConnectWorldUpdateBegin
            (std::bind(&SimpleCar_plugin::OnUpdate, this));
        }

        void OnUpdate()
        {   
            ignition::math::Vector3d init_vel(0, 0.3, 0);
            this->model->SetLinearVel(init_vel);   
        }
    
    private:
        physics::ModelPtr model;
        event::ConnectionPtr updateConnection;
    };
    GZ_REGISTER_MODEL_PLUGIN(SimpleCar_plugin)
}