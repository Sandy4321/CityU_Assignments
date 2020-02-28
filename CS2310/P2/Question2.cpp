#include <iostream>
using namespace std;

int main()
{
	// START

	// I. retriving inputs

	// To retrive matrix size
	// declaring variable
	int size;
	// requesting variable
	cout << "Please input the size of the matrix: " << endl;
	// retriving and assigning input
	cin >> size;

	// To retrive matrix
	// declaring variable
	int matrix[10][10]={0};
	// requesting variable
	cout << "Please input the matrix row by row: " << endl;
	// retriving and assigning input
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			/*
				considering the first index is the row the second is the column
				the matrix is :
					  col 	 col    col
				row [0][0] [0][1] [0][2]
				row [1][0] [1][1] [1][2]
				row [2][0] [2][1] [2][2]
			*/
			cin >> matrix[row][col];
		}
	}

	// II. calculation and print

	/*
		Since DIRECTION will always be right > down > left > up > right ... looping
		So I will use a integer, to track the direction
		after moving in a line with that direction, direction will be incremented
		each value 1, 2, 3, 4 will be right, down, left, up respectively.
		after the value 4 direction will be set to zero then slowly increment again
	*/

	/*
		regarding the number of steps to move in a particular direction.
		it was found out that moving with a spiral for a 5X5 matrix
		you will get steps of 5(right) > 4 (down) > 4(left) > 3(up) > 3(right)
		> 2(down) > 2(left) > 1(up) > 1(right)
		if look closely for a matrix n*n it is always n > n-1 > n-1 > n-2 > n-2 >
		for the first 1 is exception then the rest continuously twice until 1 
		therefore for the whole algorithm, I will take out right as the first 
		special case and start with down as 1, left as 2, up as 3 and right as 4
	*/

	int direction = 1;
	int currentRow = 0, currentCol = 0;

	cout << "The spiral form of the matrix is " << endl;

	/*
	 take first time to the right, as special case with the steps equal to the 
		size of the matrix - 1
	*/
	for (int currentStep = 0; currentStep < size; currentStep++)
	{
		cout << matrix[currentRow][currentCol + currentStep] << " ";
	}
	currentCol += size - 1;

	// starts to iterate by n-1 > n-1 > n-2 > n-2 >... steps
	for (int noOfSteps = size - 1; noOfSteps > 0; noOfSteps--)
	{
		// need to repeat twice
		for (int repeat = 0; repeat < 2; repeat++)
		{
			switch (direction)
			{
			// handle down direction
			case 1:
				for (int currentStep = 1; currentStep <= noOfSteps; currentStep++)
				{
					cout << matrix[currentRow + currentStep][currentCol] << " ";
				}
				currentRow += noOfSteps;
				
				break;
			// handle left direction
			case 2:
				for (int currentStep = 1; currentStep <= noOfSteps; currentStep++)
				{
					cout << matrix[currentRow][currentCol - currentStep] << " ";
				}
				currentCol -= noOfSteps;
				break;
			// handle up direction
			case 3:
				for (int currentStep = 1; currentStep <= noOfSteps; currentStep++)
				{
					cout << matrix[currentRow - currentStep][currentCol] << " ";
				}
				currentRow -= noOfSteps ;
				break;
			// handle right direction
			case 4:
				for (int currentStep = 1; currentStep <= noOfSteps; currentStep++)
				{
					cout << matrix[currentRow][currentCol + currentStep] << " ";
				}
				currentCol += noOfSteps;
				break;
			}
			direction ++ ;
			direction = direction> 4 ? 1 : direction ;
		}
	}

	// END
	return 0;
}