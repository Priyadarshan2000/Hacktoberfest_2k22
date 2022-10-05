clear
echo "enter the grade"
read grade

if [ $grade -gt 100 ]
then
	echo "wrong input"
exit
fi

g=`expr $grade / 10`

case $g in
	10) echo "O";;
	9) echo "O";;
	8) echo "E";;
	7) echo "A";;
	6) echo "B";;
	5) echo "C";;
	4) echo "F";;
	3) echo "F";;
	2) echo "F";;
	1) echo "F";;
	0) echo "F";;
	*) echo "Wrong Input"

esac
