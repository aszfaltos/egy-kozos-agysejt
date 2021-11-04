#!/bin/bash
#
#

if [ $# -eq 0 ]
then
	read a
	read b
elif [ $# -eq 2 ]
then
	a=$1
	b=$2
else
	echo "HIBA" 2> /dev/stderr
	exit
fi

if [ ${#a} -ge ${#b} ]
then
	echo $a | rev
else
	echo $b | rev
fi
