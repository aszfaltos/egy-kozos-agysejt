#!/bin/bash

i=0

while read sor
do
	if [[ $(expr  $sor % 3) -eq 0 ]]
	then
		((i++))
	fi
done < b.ki

echo $i
