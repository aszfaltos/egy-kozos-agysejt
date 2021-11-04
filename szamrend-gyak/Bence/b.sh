#!/bin/bash
#

if [[ $1 -gt 0 ]] 2> /dev/null
then
	for i in $(seq 1 $1)
	do
		echo $(expr $RANDOM % 10 + 10) #>> b.ki
	done
else
	echo "MEH"
fi
