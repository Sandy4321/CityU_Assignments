#include <iostream>
using namespace std;

int main()
{
	// START

	// I. retriving input
	
	// To obtain size of sequence
	// declaring variable
	int size;
	// requesting input
	cout << "Please input the number of non-negative integers: " << endl;
	// recieving and assigning variable
	cin >> size;
	
	// To obtain the sequence
	// declaring array (max=10)
	int sequence[10]={0};
	// requesting input
	cout << "Now input the sequence of non-negative integers: " << endl;
	// recieving and assigning variable
	for ( int index = 0 ; index < size ; index ++ ){
		cin >> sequence[index];
	}

	// II. calculation
	
	// To reverse the sequence 
	// (creating another array and use for loop is much	more simplier)
	// another array to store the reverse ordered 
	int reverseSeq[10]={0};
	// the index for reverseSeq is the size - index for the sequence
	for( int index = 0 ; index < size ; index ++ ){
		reverseSeq[index] = sequence[(size-1) - index];
	}

	// To determine wherther it can reach the last index
	// for printing purposes
	bool canReachLast = true;
	/*
		The idea is to sum of the value infront of the term
		if the sum is larger, then it can reach this current index
		once it is not able to reach canReachLast will be set to 0
	*/
	// considering the movement is stackable means 2200(reversed) is reachable
	/* 
	sum started from 1 because it is already stepping from index = -1 to index = 0
		to make it iterable
	*/
	int sum = 1;
	for ( int index = 0 ; index < size ; index ++ ) {
		if ( sum - 1 < index ){
			canReachLast = false;
		}
		sum += reverseSeq[index];
	}



	// III. printing results
	// To print reverse order
	cout << "The reversed sequence of non-negative integers is: " << endl;
	for ( int index = 0 ; index < size ; index ++ ){
		cout << reverseSeq[index] << " ";
	}

	// To print the last index reachable or not
	if (canReachLast){
		cout << endl << "You can reach the last index" << endl;
	}else{
		cout << endl << "You cannot reach the last index" << endl;
	}


	// END
	return 0;
}