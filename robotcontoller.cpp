RobotController::RobotController()
{
    node_ = std::make_shared<rclcpp::Node>(
        "qt_robot_controller");
    joint_pub_ =
        node_->create_publisher<
            sensor_msgs::msg::JointState
        >("/joint_command", 10);
    move_group_ =
        std::make_shared<
            moveit::planning_interface::MoveGroupInterface
        >(node_, "panda_arm");
    current_joints_ =
        move_group_->getCurrentJointValues();
}
void RobotController::publishJointCommand()
{
    sensor_msgs::msg::JointState msg;
    msg.header.stamp =
        node_->get_clock()->now();
    msg.name =
    {
        "panda_joint1",
        "panda_joint2",
        "panda_joint3",
        "panda_joint4",
        "panda_joint5",
        "panda_joint6",
        "panda_joint7"
    };
    msg.position = current_joints_;
    joint_pub_->publish(msg);
}
void RobotController::goHome()
{
    current_joints_ =
    {
        0.0,
        -0.7854,
        0.0,
        -2.3562,
        0.0,
        1.5708,
        0.7854
    };
    move_group_->setJointValueTarget(
        current_joints_);
    moveit::planning_interface::
        MoveGroupInterface::Plan plan;
    bool success =
        (move_group_->plan(plan) ==
         moveit::core::MoveItErrorCode::SUCCESS);
    if(success)
    {
        move_group_->execute(plan);
    }
    publishJointCommand();
}
void RobotController::moveJoint(
    int joint_index,
    double delta)
{
    if(joint_index < 0 ||
       joint_index >= current_joints_.size())
    {
        return;
    }
    current_joints_[joint_index] += delta;
    move_group_->setJointValueTarget(
        current_joints_);
    moveit::planning_interface::
        MoveGroupInterface::Plan plan;
    bool success =
        (move_group_->plan(plan) ==
         moveit::core::MoveItErrorCode::SUCCESS);
    if(success)
    {
        move_group_->execute(plan);
    }
    publishJointCommand();
}
