#!bin/bash

(ls /proc|grep -E -o "\b[0-9]*\b")>file.txt
declare -A ppid
declare pid
i=0
while read -r line
do
	if [[ -e /proc/$line/status ]]
	then
		ppid["$line"]=$(cat /proc/$line/status | grep -i ppid | grep -o "[0-9]*")
		pid["$i"]=$line
		i=`expr $i + 1`
	fi
done<file.txt
len1=${#pid[@]}
function rec () {
echo $2 $1
local i=0
for (( ;i<$len1;i++ ));
do
	if [[ "${ppid[${pid[$i]}]}" == "$1" ]]
	then
		rec "${pid[$i]}" "$2-----"
	fi
done
}
rec "1" ""
