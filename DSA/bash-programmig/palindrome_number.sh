clear
echo "Enter the number"
read num
num1=$num

temp=0
rev=0

while [ $num -ne 0 ]
do
	temp=$(( $num % 10 ))
	rev=$(( ($rev * 10) + $temp ))
	num=$(( $num / 10 ))
done

if [ $rev -eq $num1 ]
then
	echo "It is a palindrome number"
else
	echo "It is not a palindrome number"	
fi

