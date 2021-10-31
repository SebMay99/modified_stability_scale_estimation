# Stability-based Scale Estimation for Monocular SLAM
The paper "Stability-based Scale Estimation for Monocular SLAM" (1) from which the implementation is based can be found in: https://ieeexplore.ieee.org/document/8246525

(1) S. H. Lee and G. de Croon, "Stability-Based Scale Estimation for Monocular SLAM," in IEEE Robotics and Automation Letters, vol. 3, no. 2, pp. 780-787, April 2018, doi: 10.1109/LRA.2018.2789841.

This is a modification of the code provided by: https://github.com/sunghoon031/stability_scale. List of changes:
- Ubuntu 16.04 and ROS Kinetic tested.
- Bebop Autonomy driver integration
- Fixed pose extraction from ORB-SLAM 2
- Fixed Autopilot PID

## 1. Supplementary materials for the paper
[1] First, read `supplementary_materials/Supplementary_Material.pdf` for the full derivations ommited in the paper.

[2] Run the MATLAB script `supplementary_materials/evaluate_alpha.m` for the numerial computation of `alpha`.

## 2. Source code
### - Prerequisites:
[1] USB Joystick. Calibration instruction is available at https://wiki.paparazziuav.org/wiki/Joystick#Joystick_Calibration

[2] If you want to run simulations, you need to install Gazebo (see http://gazebosim.org/tutorials?tut=ros_installing)

[3] To run on a real Bebop 2 drone install Bebop Autonomy: https://bebop-autonomy.readthedocs.io/en/latest/
    
[4] You will also need to calibrate the drone camera for ORB-SLAM 2. Calibration instructions available at    https://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html

[5] ORB-SLAM2 ROS node from https://github.com/appliedAI-Initiative/orb_slam_2_ros. Please follow the build instructions there

### - How to build (Ubuntu 16.04, ROS Kinetic):
[1] Clone this repository first:
````
git clone https://github.com/SebMay99/modified_stability_scale_estimation
````
[2] Build:
````
cd modified_stability_scale_estimation/catkin_ws
catkin_make
````
## 3. How to run
#### External emergency button
The code includes a subscriber to the `chatter` topic that executes a system exit when the callback is requested. It is recommended to include an independent emergency button to stop the code to prevent an accident.

##### 1. Launch Bebop Autonomy driver
Connect to the drone
````
roslaunch bebop_driver bebop_node.launch
````
##### 2. Specify the mode
Take a look at the setting file `modified_stability_scale/catkin_ws/src/bebopdrone_joystick/seong_param.yaml`

You need to specify the `test_mode` to choose between:

- Simulation (1-7) or Real drone (8-12) 
- Velocity control using thrust (test_mode 1-2) or Height control using velocity commands (test mode 3-12)
- Please look at `seong_param.yaml` for more details.

For Autopilot hovering and scale estimation the default mode is 8.

##### 3. Start joystick:
````
rosparam set joy_node/dev "/dev/input/js0" 
rosrun joy joy_node
````
##### 4. [Optional] Start dynamic_reconfigure:
````
cd ~/modified_stability_scale/catkin_ws && source devel/setup.bash
rosrun dynamic_reconfig dynamic_reconfig_node 
rosrun rqt_reconfigure rqt_reconfigure
````

##### 5. Run ORB-SLAM2
Note that the monocular node subscribes to a topic `/camera/image_raw` to run node ORB_SLAM2/Mono. So you need to relay to your camera topic
````
- Launch ORB-SLAM 2 Mono:
roslaunch orb_slam2_ros [your_launch_file].launch

- Visualize ORB SLAM 2 debug image
rosrun image_view image_view image:=/orb_slam2_mono/debug_image

- You may want to change the calib.yaml to your own calibration file:
cd ~/orb_slam_2_ros/orb_slam2/config/[your_calibration_file].yaml
````
##### 6. Run the system:
- For Bebop 2 drone. Load ROS parameters, in this file the PID can be tunned as well as the `alpha` value:
````        
rosparam load ~/modified_stability_scale/catkin_ws/src/bebopdrone_joystick/seong_param.yaml /seong_ns
````
Source and run the code:
````
cd ~/modified_stability_scale/catkin_ws && source devel/setup.bash 
rosrun bebopdrone_joystick bebopdrone_teleop
````

##### 7. Using the joystick:
- Horizontal movement: Left stick
- Rotate: Right stick (left to right)
- Vertical movement: Right stick (up to down)
- Take off: Button A
- Land: Button B
- Emergency-state: Button X CAUTION: Turns off the drone propellers, it will not land the drone softly
- Start/Stop the adaptive scale estimation: Button LB
- Set the current position as the ground level: Button RB
- Write the scale estimation results to a file: Button BACK
- Set the current position as the reference (for scalefree navigation): Button SELECT
- Increase alpha parameter (only for vertical/horizontal waypoint flight): Button XBOX
- Decrease alpha parameter (only for vertical/horizontal waypoint flight): Button LZ

##### 8. Scale estimation:
Make sure ORB-SLAM 2 is running and is already producing a pose estimate. You can check how the pose Z position values change to determine if the SLAM system had a correct initialization.

Then when the drone is on the ground follow these steps: 
- Press RB to set the SLAM ground level.
- Press A for take off.

You can manually adjust the drone position prior to running the estimation. Once the drone is on the desired position and orientation:
- Press LB to turn on the Autopilot

A `True scale` value will be computed based only from SLAM, this value is useful as a reference.The drone will slowly begin to oscillate verticaly. Due to this movement, it will also begin to drift away in the X and Y axes but the PID should compensate with soft corrections. After some seconds, a `Pseudo-scale` value will be printed as a result of the determined `K critical gain` value and `alpha`. This value should be close to the previously `True scale` value.

Note: If the LB button is pressed again the Autopilot will turn off and manual control will be posible. When the autopilot is on, the land button may not work as intended, so the External emergency button is highly recommended.
