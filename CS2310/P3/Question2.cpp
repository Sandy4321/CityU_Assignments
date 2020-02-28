#include <iostream>
using namespace std;

int main()
{
	/*
	I.		To determine the number of possible Occurrences (6*6=36)
	- find the number of Occurrences
	- use a dynamic array to store the possible non-unique Occurrences.
	II.		To determine the number of unique Occurrences
	- find the number of unique Occurrences
	- use a 2D dynamic array to store the unique Occurrences
	III.	Printing all the unique Occurrences and their respective frequency
	IV.		Sorting the array
	V.		Changing the array into a Capital Letters
	VI.		Deleting array
	*/

	// _______________I_________________ 

	// number of faces of a dice.
	int noOfFaces = 6;

	// calculate the number of possible occurance of 2 dices
	// length of possible Occurrences
	int lenOfPossibleOccurrences = noOfFaces * noOfFaces;

	// 1D dynamic array to store the number of possible Occurrences.
	int *possibleOccurrences;
	// create a dynamic array to store all the possible moves.
	possibleOccurrences = new int[lenOfPossibleOccurrences];


	// _______________II_________________ 

	// number of unique Occurrences.
	int noOfUniqueOccurrences = 0;

	int index = 0;

	// the faces is unique if the sum of the faces doesnt appear in the possible combination array.
	bool isUnique = true;
	for (int dice1 = 1; dice1 <= noOfFaces; dice1++)
	{
		for (int dice2 = 1; dice2 <= noOfFaces; dice2++)
		{
			// puting the sum into an possible array
			*(possibleOccurrences + index) = dice1 + dice2;

			// check if the sum of the array is unique
			/*
			Method:
			loop through the possible array that is formed up till the current index
			considering the sum is unique and if found same occurrance make it as false;
			*/
			isUnique = true;

			for (int isUniqueIndex = 0; isUniqueIndex < index; isUniqueIndex++)
			{
				if (*(possibleOccurrences + isUniqueIndex) == *(possibleOccurrences + index))
				{
					isUnique = false;
					break;
				}
			}

			if (isUnique)
			{
				noOfUniqueOccurrences++;
			}


			index++;

		}
	}


	index = -1;

	// 2D dynamic array
	int **uniqueOccurrences;
	// the size is the number of unique Occurrences.
	uniqueOccurrences = new int*[noOfUniqueOccurrences];

	// 
	for (int uniqueIndex = 0; uniqueIndex < noOfUniqueOccurrences; uniqueIndex++)
	{
		// create another dimension to store the frequency and its sum. 
		*(uniqueOccurrences + uniqueIndex) = new int[2];
		// reset the values to 0
		*(*(uniqueOccurrences + uniqueIndex)) = 0;
		*(*(uniqueOccurrences + uniqueIndex) + 1) = 0;

		/*
		Method:
		search the index of the first element as the unique character which is not 0
		remove the character by setting the element in possible Occurrences to 0
		and increment the second element in the 2D index
		since the sum of the dice also come from minimum (2 + 2) to the largest (6 + 6)
		the result will be same as if it is arranged in ascending order of the sum.
		1st index of 2D is the sum
		2nd is the Occurrences
		*/

		// finding the index of the first unique index in possible Occurrences
		index = -1;
		while (*(possibleOccurrences + ++index) == 0)
		{
		}

		// assigning that unique sum into the unique Occurrences.
		**(uniqueOccurrences + uniqueIndex) = *(possibleOccurrences + index);

		// searching just have to done from the index element because the it is the first element to have 
		// we will also take this chance to set the element into 0
		for (int uniqueIndexChecker = index; uniqueIndexChecker < lenOfPossibleOccurrences; uniqueIndexChecker++)
		{
			// increment the second index in 2D array and change the sum to 0 in possibleOccurrences
			if (*(possibleOccurrences + uniqueIndexChecker) == **(uniqueOccurrences + uniqueIndex))
			{
				(*(*(uniqueOccurrences + uniqueIndex) + 1))++;
				*(possibleOccurrences + uniqueIndexChecker) = 0;
			}
		}

		index++;
	}


	// _______________III_________________ 

	/*
	// print the results.
	cout << "The number of occurrences:" << endl;
	for (index = 0; index < noOfUniqueOccurrences; index++) {
		cout << *(*(uniqueOccurrences + index) + 1) << " occurrence(s) of the sum " << **(uniqueOccurrences + index) << endl;
	}
	*/



	// _______________IV_________________ 


	/*

	cout << "The sorted number of occurrences:" << endl;
	// sort the array according to occurrences Bubble sort
	for (index = 0; index < noOfUniqueOccurrences - 1; index++) {
		for (int sorter = 0; sorter < noOfUniqueOccurrences - 1; sorter++) {
			if (*(*(uniqueOccurrences + sorter) + 1) < *(*(uniqueOccurrences + sorter + 1) + 1)) {
				int tempSum = *(*(uniqueOccurrences + sorter));
				int tempOccurrence = *(*(uniqueOccurrences + sorter) + 1);

				*(*(uniqueOccurrences + sorter)) = *(*(uniqueOccurrences + sorter + 1));
				*(*(uniqueOccurrences + sorter) + 1) = *(*(uniqueOccurrences + sorter + 1) + 1);

				*(*(uniqueOccurrences + sorter + 1)) = tempSum;
				*(*(uniqueOccurrences + sorter + 1) + 1) = tempOccurrence;
			}
		}
	}

	// print the results
	for (index = 0; index < noOfUniqueOccurrences; index++) {
		cout << *(*(uniqueOccurrences + index) + 1) << " occurrence(s) of the sum " << **(uniqueOccurrences + index) << endl;
	}
	*/
	

	// _______________V_________________ 

	

	// find highest value of occurrence

	cout << "The sorted number of occurrences in letters:" << endl;
	int highestScore = 0;
	for (index = 0; index < noOfUniqueOccurrences; index++) {
		if (*(*(uniqueOccurrences + index) + 1) > highestScore) {
			highestScore = *(*(uniqueOccurrences + index) + 1);
		}
	}


	// update the highest score to Capital Letters
	for (index = 0; index < noOfUniqueOccurrences; index++) {
		*(*(uniqueOccurrences + index) + 1) = 65 + highestScore - *(*(uniqueOccurrences + index) + 1);
	}

	// print the results
	for (index = 0; index < noOfUniqueOccurrences; index++) {
		cout << char(*(*(uniqueOccurrences + index) + 1)) << " occurrence(s) of the sum " << **(uniqueOccurrences + index) << endl;
	}
	


	// _______________VI_________________ 
	// delete the arrays
	delete[] possibleOccurrences;
	for (int i = 0; i < noOfUniqueOccurrences; i++)
	{
		delete[] uniqueOccurrences[i];
	}
	delete[] uniqueOccurrences;

	return 0;
}