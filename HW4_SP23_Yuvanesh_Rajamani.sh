#!/bin/sh
#NAME: Yuvanesh Rajamani       4350 - Unix System Programming
#Serial Number: 9
#Assignment Number: 4
#Due Date: 3/8/2023


#1.  List detailed list of all files in your directory. Redirect the output to 
#    zlsCommandFile.txt 
#2.  Create directory ztest  by checking  its existence. Display a message if it 
#    does exist. 
#3.  Test if File   zlsCommandFile.txt  exist. If it exits then Read the File, display 
#    its size, number of chars in the file, and its contents. Display a message it 
#    does not exist. 
#4.  Create a File   zNew.txt. Add   “ This is a new file “   to zNew.txt file.  Display 
#    a message it does exist.  
#5.  Append “Learning Scripts and Shell Programming “  to an existing File  
#    zNew.txt. Display the content of the file before and after the append if the 
#    file exist. Display a message if the file does not exist.    
#6.  Rename an existing File  zNew.txt    to   zNew2.txt. Display a message if it 
#    does not exist 
#7.  Delete the existing Files (  zlsCommandFile.txt    and  zNew.txt ) . Display a 
#    message if either one of the files does not exist 
#8.  Delete an existing zTest Directory. Display a message if it does not exist 
#9.  Parse Current Date 
#10. Display a calendar for month of December 2018 
#11. Use random number generator that generates three numbers and store 
#    them in three variables such as A , B and C.  The Values of generated 
#    numbers are either 0  or 1. Display the values for each variable. Display 
#    Boolean expression for   A   or   B   or   C  



echo " "
echo "Unix Systems Programming"
echo " "
echo "CS 4350 – Section Number "
echo "Name: Yuvanesh Rajamani"
echo " "
echo "Assignment Number: 4"
echo " "
echo "Due Date: 3/8/2023"

# program functions for each number
#_____________________________________
function1 () {
   ls > "zlsCommandFile.txt"
   echo " "
}

function2 () {
   if [ -d "$1" ]; then
   echo "$1 already exists"
   echo " "
   else
   mkdir "$1"
   echo " "
   fi
}

function3 () {
   echo " "
   if [ -f "$1" ]; then
   filesize=$(ls -lh $1  | awk '{print  $5}')
   echo "$1 has a size of $filesize"
   echo " "
   filechar=$(wc -m zlsCommandFile.txt | awk '{print $1}')
   echo "$1 has $filechar characters"
   echo " "
   echo "The contents of $1 are:"
   cat $1
   else
   echo "$1 does not exist"
   fi
   echo " "
}

function4 () {
   if [ -f "$1" ]; then
   echo "file already exists"
   else
   echo "This is a new file" > $1
   fi
   echo " "
}

function5 () {
   if [ -f "$1" ]; then
   echo "$1 before append: "
   cat "$1"
   echo " "
   echo "$1 after append: "
   echo "Learning Scripts and Shell Programming" >> $1
   cat $1
   echo " "
   else
   echo "$1 does not exist"
   echo " "
   fi  
}

function6 () {
   mv $1 $2
   if [[ -f $1 ]] || [[ -f $2 ]];then
   echo " "
   else
   echo "Files doesn't exist" 
   echo " "
   fi
}


function7 () {
   rm $1
   rm $2
   if [[ -f $1 ]] || [[ -f $2 ]];then
   echo " "
   else
   echo "Files doesn't exist" 
   echo " "
   fi
}

function8 () {
   rmdir $1
   if [ -d $1 ]; then
      echo " "
   else
      echo "Directory does not exist"
      echo " "
   fi
}

function9 () {
   Date
   echo " "
}

function10 () {
   cal $1 $2
   echo " "
}

function11 () {
   a=$(($RANDOM%2))
   b=$(($RANDOM%2))
   c=$(($RANDOM%2))
   echo "A = $a"
   echo "B = $b"
   echo "C = $c"

   if test $a -eq 1
   then
      echo "A is true"
   else
      echo "A is false"
   fi

   if test $b -eq 1
   then
      echo "B is true"
   else
      echo "B is false"
   fi

   if test $c -eq 1
   then
      echo "C is true"
   else
      echo "C is false"
   fi
}
#_____________________________________


echo ""
echo ""
echo "The function of this script is to:"
echo ""
echo "1.List detailed list of all files in your directory. Redirect the output to zlsCommandFiles.txt" 
function1

echo "2.Create directory by checking its existence "
function2 ztest

echo "3.Test if File Exist."
function3 zlsCommandFile.txt

echo "4.Create a File"
function4 zNew.txt

echo "5.Append “Learning Scripts and Shell Programming “ to an existing File."
function5 zNew.txt

echo "6.Rename an existing File. "
function6 zNew.txt zNew2.txt

echo "7.Delete an existing File. "
function7 zNew2.txt zlsCommandFile.txt

echo "8.Delete an existing Directory. "
function8  ztest

echo "9.Parse Current Date "
function9
echo " "

echo "10.Display a calendar for a specific month / year. "
function10 12 2018

echo "11.Generate three random numbers and store them in three variables such as 
A , B, and C.  The Values of generated numbers are either 0  or 1. Display 
Boolean expression for   A   or   B  or C. "
function11

exit 0