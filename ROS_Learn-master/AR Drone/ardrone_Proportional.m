% -------------------------
% This file shows how to do proportion control with MATLAB and Tum_simulator
% First run tum_simulator on the master
% topic /gazebo/model_states contains the global position coordinates of the quadcopter,
% we subscribe this topic and process the data by adding gain K to get the velocity message, then publish it to /cmd_vel
% Use the GUI to take off the quadcopter, and hand control the quadcopter to a proper initial height, then run the script
% Before run the script, remember to do rosinit on MATLAB.
% --------------------------

% Create publisher
cmdpub = rospublisher('/cmd_vel',rostype.geometry_msgs_Twist); 

% Create subscriber
sub = rossubscriber('/gazebo/model_states');

% Create message
cmdmsg = rosmessage(cmdpub);

% Pause one second before publishing messages
pause(1);

% Set the gain
k = 1;

% Set the stable state
final_height = 3;

% Proportional control
for i = 1:1000
msg = receive(sub,10)

height = msg.Pose(12,1).Position.Z  % Pose contains 12 "matrices", the height information is "hiding inside" the Pose matrix
cmdmsg.Linear.Z = -k * (height - final_height);  
send(cmdpub,cmdmsg);

pause(0.1)    % This time interval should not be too large, less than 0.2 is a good scale
end
