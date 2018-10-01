## How to install Ubuntu 14.04.5 on your computor and install ros indigo
### step 1
Go to ubuntu official website and download 64 bit ubuntu desktop iso file.

### step 2
1. Create a boot USB stick. 
2. Go to pendrivelinux.com and download the boot usb creater. 
3. Follow the tutorial 
"How to Create a Bootable Ubuntu 13.10 USB Flash Drive"  select FAT32
https://www.youtube.com/watch?v=CFeri7UiYNs

### step 3
Follow the video guide and setup ubuntu 14.04
https://www.youtube.com/watch?v=i_4Kh5kE3xA&t=1030s

### step 4
Follow this link to install ros-indigo on ubuntu
http://wiki.ros.org/indigo/Installation/Ubuntu

* Failed to contact master at [localhost:11311] problem may caused by the computor name inconsist with the host name

* use "sudo gedit /etc/hosts" command and check the names
use "roscore" and then "rosrun turtlesim turtlesim_node" to check if your setup is correct. you should be able to see a turtle on the screen.
