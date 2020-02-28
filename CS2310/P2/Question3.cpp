#include <iostream>
using namespace std;




int main(){
	
	// START
	

	// I. retriving inputs
	
	// To retrive maximum size
	// declaring the variable
	int size;
	// requesting variable
	cout << "Please input the number of integers: " << endl;
	// retriving and assigning input
	cin >> size;

	// To retrive sequence of number
	// declaring the sequence array (max=20)
	int sequence[20]={0};
	// requesting for input
	cout << "Please input the sequence of integers: " << endl;
	// retriving and assigning input
	for (int index = 0 ; index < size ; index ++){
		cin >> sequence[index];
	}

	// Repriting Original Sequence 
	cout << "Original sequence: ";
	for ( int index = 0 ; index < size ; index ++ ){
		cout << sequence[index] << " " ;
	}



	// II. calculate
	
	// modifying
	/*
	 if the current value is equal to the next value then multiply it by and make the 
	 next value 0
	*/ 
	for ( int index = 0 ; index < size - 1 ; index ++){
		if ( sequence[index] == sequence[index+1] ){
			sequence[index] *= 2;
			sequence[index + 1] = 0;
		}
	}

	// sorting
	
	/*
		The method is to create a index(pushToIndex) to keep track of the
		non-zero terms.

		if the current index is not zero then it will be push onto the 
		pushToIndex for update, further setting itself as a zero term.
		pushToIndex will then be incremented;

		take note that, if pushToIndex is equal to index, we should not change 
		the sequence[index] and pushToIndex should be incremented.
	*/
	// pushToIndex at first start from 0
	int pushToIndex = 0;
	// loop array one by one
	for ( int index = 0 ; index < size ; index ++ ){
		// if term is 0 do nothing if it is not, then assign it to pushToIndex
		if (sequence[index] != 0){
			// assigning the index
			sequence[pushToIndex] = sequence[index];
			// if the index is the same as the pushToIndex we should not change it 
			if (pushToIndex != index){
				sequence[index] = 0;
			}
			// increment pushToIndex to ready to accept the next term
			pushToIndex++;
		}
	}


	// III. print result
	cout << endl << "Modified sequence: ";
	for ( int index = 0 ; index < size ; index ++ ) {
		cout << sequence[index] << " " ;
	}



	//END
	return 0;
}