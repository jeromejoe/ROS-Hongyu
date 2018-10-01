### Run "source devel/setup.bash" automatically<br>
Sometimes it is annoying to source "setup.bash" at every new shell, here is how can this be automatically.
1. Open your terminal
2. Write the command 'gedit ~/.bashrc' a file will open on gedit
3. Go to the bottom (my last line was "source /opt/ros/indigo/setup.bash" , for others it may differ)
4. Go under that line and write 'source [YOUR PATH]/catkin_ws/devel/setup.bash'
5. Save and exit
6. Now with every new shell you open, it will source automatically <br/>

Example:<br>
Add 'source ~/catkin_ws/devel/setup.bash'<br>
Workspace catkin_ws is no longer need to be sourced

### Change node name
rosrun package-name executable-name __name:=node-name

### Launch file tips
1. You can put launch files anywhere in the package folder(ex. package/src/launchfile  package/src/launch/launchfile). 'roslaunch' command
can find the launchfile.
2. You do not need to run catkin_make after you create a luanchfile, while you have to run catkin_make after you create a .cpp file or .py
file.
3. node pkg="package name" name="node name" type="executable file name"   For the executable file name, do not include the path, just the name. (src/name [ ]  name [x])
4. remap from="current topic" to="expected topic"
