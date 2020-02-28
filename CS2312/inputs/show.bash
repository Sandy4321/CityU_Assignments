echo "1-4?"
read a
echo "a-c?"
read b
echo "out? [y/n]"
read c
if [ c = 'n' ]
then
	less ${a}_${b}.txt
else
	less out_${a}_${b}.txt
fi