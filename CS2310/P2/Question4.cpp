#include <iostream>
using namespace std;

int main(){

	// START

	// I. retriving inputs

	// To obtain size
	// declaring size variable
	int size;
	// requesting input
	cout << "Please input the number of integers: " << endl;
	// recievig and assigning input
	cin >> size;

	// To obtain sequence of integer
	// declaring sequence array (max=20)
	int sequence[20] = {0};
	// requesting input
	cout << "Please input the sequence of integers:" << endl;
	// using for loop to assign to array
	for ( int index = 0 ; index < size ; index ++ ) {
		cin >> sequence[index] ;
	}

	// II. calculation

	/*
		The main idea is to use mod (%) to count the total number of 
		factor in the integers without finding product.
		
		If there is ever a 0 in the sequence a boolean haveZero will note down 
		and the for loop is exited.

		while loop will be used to test if there is still any 2 or 5 factors 
		left in the temp.
	*/

	int trailingZeros = 0, noOf2 = 0, noOf5 = 0, temp;
	bool haveZero = false;
	for ( int index = 0 ; index < size ; index ++ ) {
		// temp is to keep the values so that to simplify the calculation
		temp = sequence[index];
		/*
		 if the temp can stil be mod by 2 or 5 then mod them and increment
			noOf2 and/or noOf5
		 divide them to keep track of other 2 or 5 factors in the program.
		*/
		while ((temp % 2 == 0 || temp % 5 == 0)&& temp != 0 ){
			if (temp % 2 == 0){
				noOf2 ++;
				temp = temp / 2;
			}
			if (temp % 5 == 0){
				noOf5 ++;
				temp = temp / 5;
			}
		}
		
		// exit the loop if there is ever 0 
		if(temp == 0){
			haveZero = true;
			break;
		}

	}


	/* 
		computing the trailingZeros
		if noOf2 is smaller then pick noOf2 else pick noOf5 
		if the sequence ever have 0 pick trailingZeros will be set to 1
	*/
	trailingZeros = noOf2 > noOf5 ? noOf5 : noOf2;
	trailingZeros = haveZero ? 1 : trailingZeros;

	// III. printing results
	cout << "The number of trailing zeros is " << trailingZeros << endl;


	return 0;
}