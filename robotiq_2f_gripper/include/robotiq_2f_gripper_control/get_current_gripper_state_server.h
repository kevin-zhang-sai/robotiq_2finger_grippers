#ifndef ROBOTIQ_2F_GRIPPER_CONTROL_GET_CURRENT_GRIPPER_STATE_SERVER_H
#define ROBOTIQ_2F_GRIPPER_CONTROL_GET_CURRENT_GRIPPER_STATE_SERVER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>

#include <rclcpp/rclcpp.hpp>

#include "robotiq_2f_gripper_msgs/srv/get_current_gripper_state.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace robotiq_2f_gripper_control  
{ 
  class GetCurrentGripperStateServer : public rclcpp::Node
  {
    protected:

      rclcpp::Service<robotiq_2f_gripper_msgs::srv::GetCurrentGripperState>::SharedPtr get_current_gripper_state_server_;
      rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr gripper_state_subscriber_;
      std::string gripper_state_topic_name_;
      std::mutex current_gripper_state_mutex_;
      sensor_msgs::msg::JointState current_gripper_state_;

    public:

      GetCurrentGripperStateServer();

      ~GetCurrentGripperStateServer(void){}

    private:

      void gripper_state_subscriber_callback(const sensor_msgs::msg::JointState::SharedPtr gripper_state);
      bool get_current_gripper_state_service(const std::shared_ptr<robotiq_2f_gripper_msgs::srv::GetCurrentGripperState::Request> req,
                                                   std::shared_ptr<robotiq_2f_gripper_msgs::srv::GetCurrentGripperState::Response> res);
  };
}

#endif // ROBOTIQ_2F_GRIPPER_CONTROL_GET_CURRENT_GRIPPER_STATE_SERVER_H