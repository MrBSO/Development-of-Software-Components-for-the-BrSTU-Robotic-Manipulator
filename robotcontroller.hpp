#pragma once
#include <memory>
#include <vector>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
class RobotController
{
public:
    RobotController();
    void goHome();
    void moveJoint(
        int joint_index,
        double delta);
private:
    void publishJointCommand();
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<
        sensor_msgs::msg::JointState
    >::SharedPtr joint_pub_;
    std::shared_ptr<
        moveit::planning_interface::MoveGroupInterface
    > move_group_;
    std::vector<double> current_joints_;
};
