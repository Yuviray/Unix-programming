#!/bin/sh
#NAME 4350 - Unix System Programming
#Section Number: 251
#Assignment Number: 2
#Due Date: 2/15/2023 no later than 5:15 pm


echo " "
echo "This Script is Designed and Implemented by Yuvanesh Rajamani"
echo " "
echo "The function of This script is to : "
echo " "
echo "1.Display the integer arguments that are entered."
echo "2.Display the smallest of the integer arguments."
echo "3.Display the largest of the integer arguments."
echo "4.Sum of the 3 integer arguments."
echo "5.Product of the 3 integer arguments."
echo "6.Average of the 3 integer arguments."
echo "7.Square of each integer argument."
echo "8.Determine that each integer argument is positive, negative or zero."
echo "9.Determine that each integer argument is odd, or even ."
echo "10.Find all even numbers between 1 and the first integer argument."
echo "11.Find all odd numbers between 1 and the third integer argument."
echo "12.Find the factorial of the last integer argument."
echo "13.Determine whether or not the second integer argument is a prime number."
echo "14.Calculating Distinct Sequence of the second integer."
echo " "
#_____________________________________________________________________
read -p "Enter 3 integer Values  - - - - > " a b c 
re='^[+-]?[0-9]+$'
if ! [[ $a =~ $re ]]; 
   then echo "**** Error - Must input 3 integer Values" >&2;
	echo " "
        echo "End of script"
	echo "Yuvanesh Rajamani - 2-15-2023"
        exit 1 
fi

if ! [[ $b =~ $re ]];                                 
   then echo "**** Error - Must input 3 integer Values" >&2;
        echo " "
        echo "End of script"
        echo "Yuvanesh Rajamani - 2-15-2023"
        exit 1
fi

if ! [[ $c =~ $re ]];                                 
   then echo "**** Error - Must input 3 integer Values" >&2;
        echo " "
        echo "End of script"
        echo "Yuvanesh Rajamani - 2-15-2023"
        exit 1
fi

echo " "
echo " "
#_____________________________________________________________________
echo "1) You Entered $a  $b  $c"
echo " "
#_____________________________________________________________________
array=( $a $b $c)
for ((i = 0; i<3; i++))
do
    
    for((j = 0; j<3-i-1; j++))
    do
    
        if [ ${array[j]} -gt ${array[$((j+1))]} ]
        then
            # swap
            temp=${array[j]}
            array[$j]=${array[$((j+1))]}
            array[$((j+1))]=$temp
        fi
    done
done
echo "2) The Smallest interger is ${array[0]}"
echo " "
#_____________________________________________________________________
echo "3) The Largest integer is ${array[2]}"
echo " "
#_____________________________________________________________________

summ=$((a+b+c))
echo "4) $a + $b + $c = $summ"
#_____________________________________________________________________
echo " "
prodd=$((a*b*c))
echo "5) $a * $b * $c = $prodd"
#_____________________________________________________________________
echo " "
avgg=$((summ/3))
echo "6) ($a + $b + $c)/3 = $avgg"
#_____________________________________________________________________
 
aa=$((a**2))
bb=$((b**2))
cc=$((c**2))
echo " "
echo "7) $a*$a = $aa, $b*$b = $bb, $c*$c = $cc"
#_____________________________________________________________________


echo " "
if [ $a -eq 0 ]
then
	printf "8) $a is zero,"
elif [ $a -gt 0 ]
then
        printf "8) $a is positive,"
else
        printf "8) $a is negative,"
fi

if [ $b -eq 0 ]
then
        printf " $b is zero,"
elif [ $b -gt 0 ]
then
        printf " $b is positive,"
else
        printf " $b is negative,"
fi

if [ $c -eq 0 ]
then
        printf " $c is zero.\n"
elif [ $c -gt 0 ]
then
        printf " $c is positive.\n"
else
        printf " $c is negative.\n"
fi

echo " "
if [ $((a%2)) -eq 0 ]
then
        printf "9) $a is even,"
else
        printf "9) $a is odd,"
fi

if [ $((b%2)) -eq 0 ]
then
        printf " $b is even,"
else
        printf " $b is odd,"
fi  

if [ $((c%2)) -eq 0 ]
then
        printf " $c is even.\n"
else
        printf " $c is odd.\n"
fi  

echo " "
printf "10) All even numbers between 1 and $a are: "
#_____________________________________________________________________

i=1
while test $i -lt $a
do
ii=`expr $i % 2`
        if test $ii -eq 0
        then
                printf "$i "
        fi
i=`expr $i + 1`
done
printf "\n"

echo " "
printf "11) All odd numbers between 1 and $c are: "
#_____________________________________________________________________

j=1
while test $j -lt $c
do
jj=`expr $j % 2`
        if test $jj -ne 0
        then
                printf "$j "
        fi
j=`expr $j + 1`
done
printf "\n"

echo " "
total=1
for ((number=2; number<=$c; number++))
do 
	total=$((total*number))
done

echo "12) Factorial of $c is: $total"
#_____________________________________________________________________
echo " "
printf "13) $b is "
k=2
f=0
 
while test $k -le `expr $b / 2`
do

	if test `expr $b % $k` -eq 0
	then
		f=1
	fi
 
	k=`expr $k + 1`
done
if test $f -eq 1
then
	echo "not Prime"
else
	echo "prime"
fi

echo " "
#_____________________________________________________________________
printf "14) Distinct sequence for the integer $b is: $b"
n=$b
while test $n -ne 1
do
nn=`expr $n % 2`
        if test $nn -eq 0
        then
                n=$((n/2))
	else
		n=$((3*n))
		n=$((n+1))	
        fi
printf ", $n"
done
printf "\n"




echo " "
echo " "
echo "End of script"
echo "Yuvanesh Rajamani - 2-15-2023"
exit 0

