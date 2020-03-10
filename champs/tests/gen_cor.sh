#!/bin/bash

asm_path='../../bin/asm'
players=$(ls | grep "\.s$")
echo $players
for player in $players
do
	$asm_path $player
	echo $player
done
