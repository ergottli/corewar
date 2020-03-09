cp $1.s $1_zaz.s
./asm_zaz $1_zaz.s
./asm $1.s
if [  ! -e $1.cor ] && [ ! -e $1.cor ]
then
	echo "$1 : [OK] NO FILE CREATE"
fi

if [ -e $1.cor ] && [ -e $1_zaz.cor ] && diff $1.cor $1_zaz.cor
then
	echo "$1: [OK]"	
	if [ -e $1.cor ]
		then
			hexdump -C $1.cor > ok_$1.txt
			rm $1.cor $1_zaz.cor
	fi
else
	 
	if [ -e $1.cor ] && [ -e $1_zaz.cor ] 
	then
		echo $1": [KO]"
		diff $1.cor $1_zaz.cor > diff_$1.txt
		echo "\n\n$1.cor \n" >> diff_$1.txt
		hexdump -C $1.cor >> diff_$1.txt
		echo "\n\n$1_zaz.cor\n" >> diff_$1.txt
		hexdump -C $1_zaz.cor >> diff_$1.txt
		echo "$1.s : binary diff" >> all_error.txt
	fi
fi
if [ ! -e $1.cor ] && [ -e $1_zaz.cor ]
then
	echo "J'ai une erreur que je ne devrais pas avoir $1.s"	
	echo "$1.s : error not legit" >> all_error.txt
fi
if [ -e $1.cor ] && [ ! -e $1_zaz.cor ]
then
	echo "Il me manque la detection d'un erreur sur le fichier $1.s"
	echo "$1.s : missing an error" >> all_error.txt
fi
rm $1_zaz.s
