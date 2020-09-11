
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>


int main(int argc, char** argv) 
{
  ros::init(argc, argv, "my_code");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);

  ros::Rate loop_rate(3);
  //step of the joint
  double d2 = 0.05;
  double d3 = 0.05;

  //declaring type of msg
  sensor_msgs::JointState joint_state;

  //filling the intial state of joints
  joint_state.name.resize(3);
  joint_state.position.resize(3);
  joint_state.name[0] ="joint1";
  joint_state.name[1] ="joint2";
  joint_state.name[2] ="joint3";
  joint_state.position[0] = 1;
  joint_state.position[1] = -1;
  joint_state.position[2] = -0.7;

  while (ros::ok()) 
  {
    //publishing the joint states on the topic joint_states
    pub.publish(joint_state);
    joint_state.header.stamp = ros::Time::now();
    joint_state.position[0] += 0.05;
    if (joint_state.position[1]< -1.0 || joint_state.position[1] > 0)
      d2*=-1;
    joint_state.position[1] +=d2;
    joint_state.position[2] +=d2;

    loop_rate.sleep();
  }
  return 0;
}