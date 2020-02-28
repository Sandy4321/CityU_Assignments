
echo "Which phase you want to check: (Eg: 2) [1-4] \n"

read phase

if [ $phase -gt 0 -a $phase -lt 5 ]
then
	echo "Which output a,b,c? "
	
	read output
	if [ $output = 'a' -o $output = 'b' -o $output = 'c' ]
	then
		if [ -e "res_${phase}_${output}.txt" ]
		then
			rm "res_${phase}_${output}.txt"
		fi
		vim "res_${phase}_${output}.txt"
		diff -c "res_${phase}_${output}.txt" ../inputs/out_${phase}_${output}.txt
	else
		echo "Wrong Input"
	fi
else
	echo "Wrong Input"
fi
