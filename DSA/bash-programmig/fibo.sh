clear
echo "Enter the number of terms you want to print"
read num

x=0
y=1

echo "The fibonacci Series:"
for (( i=0; i<num; i++ ))
do
	echo -n "$x "
	z=`expr $x + $y`
	x=$y
	y=$z
done	
