## What is remap
Remap allows you to modify the output of a node. It would be flexible if you can use one node to do different jobs. For instance, you write a node which can publish velocity to topic "cmd_vel", and with remap, you can modify the target topic to anywhere you want. You can publish the velocity to "vel" topic if you want. Therefore, you have a more widely used node if you are good at using remap. <br>

## How to remap
You can use launch file to do remap. The following is an example launch file who has remap tag. Originally, the node "publish_velocity" publish velocity to topic "/turtle1/cmd_vel". The remap tag can modify this topic to "/cmd_vel". This launch file is going to launch node "publish_velocity" and publish velocity to "/cmd_vel". 
```bash
<launch>

  <node pkg="beginner" name="publish_velocity" type="pubvel">
   <remap from="/turtle1/cmd_vel" to="/cmd_vel"/> 
  </node>

</launch>
```
## Launch file with remap
The xml grammer looks like the following.
```bash
<launch>

  <node pkg="package_name" name="node_name" type="executable file_name">
   <remap from="original_topic" to="target_topic"/> 
  </node>

</launch>
```
### Remote Control a Turtlebot
This is a more complicated example of how to use remap to achive the goal: let a simulated turtle move randomly, and let a real turtlebot mimic the action of the virtue turtel.<br>
Node publish_velocity publishes random velocity to topic "turtlesim1/turtle1/cmd". <br>
Node sim run a turtlesim. <br>
Topic "/mobile_base_nodelet_manager" receive velocity messages.
```bash
<launch>

  <node pkg="beginner" name="publish_velocity" type="pubvel">
   <remap from="turtlesim1/turtle1/cmd" to="turtlesim1/turtle1/cmd_vel"/> 
  </node>
   
  <group ns="turtlesim1">
   <node pkg="turtlesim" name="sim" type="turtlesim_node">
   </node>
  </group>
  
  <node pkg="turtlesim" name="mimic" type="mimic">
     <remap from="input" to="turtlesim1/turtle1"/> 
     <remap from="output" to="/mobile_base_nodelet_manager"/>
  </node> 
</launch>
```
