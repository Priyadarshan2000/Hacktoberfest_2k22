clear
echo enter a number
read x

if [ `expr $x % 400` -eq 0 ] || [ `expr $x % 100` -ne 0 ] && [ `expr $x % 4` -eq 0 ]
then
	echo "This is a leap year"
else
	echo "This is not a leap year"
fi	
