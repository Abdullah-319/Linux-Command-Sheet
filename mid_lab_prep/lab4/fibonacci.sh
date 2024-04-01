function fibonacci {
	echo "Enter a number "
	read num
	num1=0
	num2=1
	echo "Series is: "
	echo $num1
	echo $num2
	for((i=2;i<num;i++))
	do
		num3=$(($num1+$num2))
		num1=$num2
		num2=$num3
		echo $num3
	done
}
