cmdpub = rospublisher('turtle1/cmd_vel',rostype.geometry_msgs_Twist);
sub = rossubscriber('turtle1/pose');
cmdmsg = rosmessage(cmdpub);
pause(1);
k = 1; %gain
for i = 1:1000
msg = receive(sub,1)

cmdmsg.Linear.X = -k*(msg.X - 5);
send(cmdpub,cmdmsg);

pause(0.1)
end
