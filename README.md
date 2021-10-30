# Stability-based Scale Estimation for Monocular SLAM

## 1. Supplementary materials for the paper
[1] First, read `supplementary_materials/Supplementary_Material.pdf` for the full derivations ommited in the paper.

[2] Run the MATLAB script `supplementary_materials/evaluate_alpha.m` for the numerial computation of `alpha`.

## 2. Source code
### - Prerequisites:
[1] Logitech Extreme 3D Pro joystick. Calibration instruction is available at https://wiki.paparazziuav.org/wiki/Joystick#Joystick_Calibration

[2] If you want to run simulations, you need to install Gazebo (see http://gazebosim.org/tutorials?tut=ros_installing)

[3] If you want to run on a real AR drone 2.0, you need to calibrate its camera. An example is provided in `ORB_SLAM2/Examples/Monocular/ardrone_calib.yaml`. You can use this file, but I recommend that you do your own calibration to make sure. Calibration instruction is at https://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html

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
[3] Clone and build the ORB-SLAM2 ROS node from https://github.com/appliedAI-Initiative/orb_slam_2_ros. Please follow the build instructions there

### - How to run:

##### 1.Launch Bebop Autonomy driver
Connect to the drone
````
roslaunch bebop_driver bebop_node.launch
````
##### 1. Specify the mode
Take a look at the setting file `modified_stability_scale/catkin_ws/src/bebopdrone_joystick/seong_param.yaml`

You need to specify the `test_mode` to choose between:

- Simulation (1-7) or Real drone (8-12) 
- Velocity control using thrust (test_mode 1-2) or Height control using velocity commands (test mode 3-12)
- Please look at `seong_param.yaml` for more details.

##### 2. Start joystick:
````
rosparam set joy_node/dev "/dev/input/js0" 
rosrun joy joy_node
````
##### 3. [Optional] Start dynamic_reconfigure:
````
cd ~/modified_stability_scale/catkin_ws && source devel/setup.bash
rosrun dynamic_reconfig dynamic_reconfig_node 
rosrun rqt_reconfigure rqt_reconfigure
````

##### 4. Run ORB-SLAM2
Note that the monocular node subscribes to a topic `/camera/image_raw` to run node ORB_SLAM2/Mono. So you need to relay to your camera topic
````
- Launch ORB-SLAM 2 Mono:
roslaunch orb_slam2_ros camera_mono.launch

- Visualize ORB SLAM 2 debug image
rosrun image_view image_view image:=/orb_slam2_mono/debug_image

- For you may want to change the calib.yaml to your own calibration file:
cd ~/orb_slam_2_ros/orb_slam2/config/bebo2.yaml
````
##### 5. Run the system:
````        
- For Bebop 2 drone.
rosparam load ~/modified_stability_scale/catkin_ws/src/bebopdrone_joystick/seong_param.yaml /seong_ns
cd ~/modified_stability_scale/catkin_ws && source devel/setup.bash 
rosrun bebopdrone_joystick bebopdrone_teleop
````

##### 6. Using the joystick:
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

