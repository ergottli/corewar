#!/bin/bash

out=  

for i in {1..3000}
do
	out=$(diff ./00/$i.out ./01/$i.out)
	if [ -n $out ]
	then
		out=
	else
		echo $i
		diff ./00/$i.out ./01/$i.out
		exit
	fi
done
