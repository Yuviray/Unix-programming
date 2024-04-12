#!/bin/sh
#NAME 4350 - Unix System Programming
#Serial Number: 9
#Assignment Number: 3
#Due Date: 2/27/2023 no later than 5:15 pm



echo " "
echo "Shell programming by Yuvanesh Rajamani"
echo " " 
echo "1.Creating a new File  Znew.txt"
echo " "

touch zNew.txt

# outputting to file
echo "Spring 2023" >> zNew.txt
echo "CS4350" >> zNew.txt
echo "Section #" >> zNew.txt
echo "251" >> zNew.txt
echo "scripts and shell programming using" >> zNew.txt
echo "zeus ide" >> zNew.txt
echo "@ TEXAS STATE UNIVERSITY" >> zNew.txt

# outputting to terminal
echo "2.The content of the created file is: "
echo " "
cat zNew.txt
echo " "

echo "3.All lines with alphabet characters: "
echo " "
grep [a-zA-Z] zNew.txt
echo " "

echo "4.All lines with digits: "
echo " "
grep -e "[0-9]" zNew.txt
echo " "

echo "5.All lines with lowercase characters: "
echo " "
grep '[[:lower:]]'  zNew.txt
echo " "

echo "6.All lines with uppercase character: "
echo " "
grep '[A-Z]'   zNew.txt
echo " "

echo "7.All lines with alphanumeric characters: "
echo " "
grep '[[:alnum:]]' zNew.txt
echo " "

echo "8.All lines with punctuation character: "
echo " "
grep '[[:punct:]]' zNew.txt
echo " "

echo "9.All the lines with the letter  s  followed by space: "
echo " "
grep  s[[:space:]]   zNew.txt
echo " "

echo "10.All the lines with the letter zeus followed by space: "
echo " "
grep  zeus[[:space:]]  zNew.txt
echo " "

echo "11.All the line that the word programming appears at  
the end of the line:  "
echo " "
grep programming$ zNew.txt
echo " "

echo "12.All the lines that the word Spring appears at the  
beginning of the sentence: "
echo " "
grep ^Spring zNew.txt
echo " "

echo "13.All lines that has a word that starts with C and  
ends with 0:  "
echo " "
grep "^C.*0$"   zNew.txt
echo " "

echo "14.All  lines that contain a word that starts with s and  
end with l: "
echo " "
grep "s\?l"  zNew.txt
echo " "

echo "15.Deleting the existing File zNew.txt: "
echo " "
if [ -f zNew.txt ]; then
   rm zNew.txt
   echo "zNew.txt is deleted"
fi
  
echo " "

echo "16.Display the content of zNew.txt: "
echo " "
if [ -f zNew.txt ]; then
   cat zNew.txt
else
   echo "zNew.txt does not exist"
fi

echo " "
echo "Prepared by Yuvanesh Rajamani"
echo "2-27-2023"
