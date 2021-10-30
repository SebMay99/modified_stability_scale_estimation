/*
* bebop_joystick:
*
* This software provides a connection between an USB-Joystick and the Parrot Bebop 2 driver
*
* It receives the joystick state from the joy-node and publishes the corresponding commands to the driver
*
* Author: Nikolas Engelhard
*
* Edit: Seong Hun Lee
*       - Implemented the algorithm used in the paper "Stability-based Scale Estimation of Monocular SLAM for Autonomous Navigation"
*       - Specifially, the algorithm implemented in this project is the height control using velocity commands
*
* Edit: Sebastián Mayorga Castro
*       - Updated and fixed the code for Ubuntu 16.04 and ROS Kinetic
*       - Modified the code to work with an XBOX 360 USB controller and Bebop Autonomy driver
*/

#include <bebopdrone_joystick.h>

const int PUBLISH_FREQ = 50;

// Emergency stop button exit function
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  exit (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "bebopdrone_teleop");

  ROS_INFO("Started BebopDrone joystick-Teleop");
  ROS_INFO("Press Button A to take off");
  ROS_INFO("Press Button B to land");
  ROS_INFO("Press Button X to toggle emergency-state");
  ROS_INFO("Press Button Y to choose camera");
  ROS_INFO("Press Button LB to start/stop adaptive gain tuning");
  ROS_INFO("Press Button RB to set the current position as the ground level");
  ROS_INFO("Press Button BACK to enable/disable writing the simulation result to a file");
  ROS_INFO("Press Button SELECT to set the current pos as the reference pos for figure flying");
  ROS_INFO("Use left Joystick to move forward, backward, left and right");
  ROS_INFO("Use right Joystick to move up, down and yaw(Z axis)");

  TeleopBebopDrone TeleOperator;

  ros::NodeHandle n;
  ros::Rate pub_rate(PUBLISH_FREQ);

  // Emergency stop button subscriber
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  while (TeleOperator.nh_.ok())
  {
    ros::spinOnce();
    TeleOperator.send_cmd_vel();

    pub_rate.sleep();
  }

  return 0;
}
