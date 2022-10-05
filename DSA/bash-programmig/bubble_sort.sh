clear

echo "enter the number of elements"
read n

echo "Enter the elements"

for (( i=0;i<n;i++ ))
do
	read arr[i]
done

echo "Unsorted Array is: "
echo -e "${arr[@]} \t"

for (( i=0;i<n;i++ ))
do
	for (( j=0;j<n-i-1;j++ ))
	do
		if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
		then
			temp=${arr[j]}
			arr[$j]=${arr[$((j+1))]}
			arr[$((j+1))]=$temp
		fi
	done
done

echo "The sorted array is: "
echo -e "${arr[@]} \t"


