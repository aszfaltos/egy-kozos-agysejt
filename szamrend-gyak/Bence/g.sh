#!/bin/bash

num=$1


for i in $(seq 1 $num)
do
	for j in $(seq 1 $num)
	do
		(( count=i+j ))
		if [[ $(expr $count % 2) -eq 0 ]]
		then
			echo -n $num
		else
			echo -n " "
		fi
	done
	echo ""
done


