#!/bin/bash

# ------------------------------------------------- #
# $1 : the 42's asm                                 #
# $2 : our asm                                      #
# $3 : the path to the repository of the champions  #
# ------------------------------------------------- #

test()
{
	echo "NEW:"
	./${2} ${3}/${4}.s
	hexdump -C ${3}/${4}.cor > myret
	./${1} ${3}/${4}.s
	hexdump -C ${3}/${4}.cor > zazret
	echo "Champion: ${4} | diff with zaz is:" >> script.out;
	diff myret zazret >> script.out;
}

echo "ASM TEST FOR VALID CHAMPIONS"
touch script.out
echo "--- RESULTS ---" >> script.out
for f in ${3}/*.s
do
	test ${1} ${2} ${3} `echo $f | rev | cut -c 3- | rev | cut -d '/' -f 2`
done
cat -e script.out
rm ${3}/*.cor zazret myret script.out
