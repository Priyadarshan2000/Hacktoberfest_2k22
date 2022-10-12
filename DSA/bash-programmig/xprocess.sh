#!/bin/bash

#Using if-else loop to control the life cycle of xclock

process=$1 #input each process via command line argument
ps=`exec pgrep -U <$id> xclock` #to store the value of PID for aws server when you have multiple user ids use $id number
if [ -z $process ]
then
	echo "Usage: xprocess [start] | [stop] | [restart] | [reload] | [kill] | [status]";
elif [ $process = "start" ] 
then 
	if [ -z "$ps" ] #if no PID of xclock is found xclock is launched
	then
		echo "Starting xclock...";
		`nohup xclock -update 1 &>/dev/null &`;
	else
		echo "xclock already running"; #else message is given that xclock is already running
	fi
elif [ $process = "stop" ]
then
	if [ -z "$ps" ]
	then
		echo "No xclock process to stop...";
	else
		echo "Stoping xclock...";
		`exec kill -TSTP $ps`; #-TSTP is used to pause/suspend a process
	fi
elif [ $process = "restart" ] 
then
	if [ -z "$ps" ]
	then
		echo "No xclock process to restart...";
	else
		echo "Restaring xclock...";
		`exec kill -CONT $ps`; #-CONT for continuing a suspended process
	fi
elif [ $process = "reload" ]
then
	if [ -z "$ps" ]
	then
		echo "No process to reload...";
	else
		echo "Reloading xclock process...";
		`exec kill -SIGKILL $ps`;
		`exec nohup xclock -update 1`;
	fi
elif [ $process = "kill" ]	
then 	
	if [ -z "$ps" ]
	then
		echo "No process to kill...";
	else
		echo "Killing xclock process...";
		`exec kill -SIGKILL $ps`;
	fi
elif [ $process = "status" ]
then
	if [ -z "$ps" ]
	then
		echo "No xclock process running"
	else
		echo "xclock process running at PID=$ps"
	fi
fi
