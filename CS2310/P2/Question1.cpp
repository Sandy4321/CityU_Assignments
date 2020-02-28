#include <iostream>
using namespace std;

int main()
{
	// START

	// I. retriving inputs

	// declaring total input variable
	int tInput;

	// requesting input 
	cout << "Enter the number of positive integers: " << endl;

	// retriving and assigning input
	cin >> tInput;

	// declaring input values
	int input[20] = {0};

	// requesting inputs from user
	cout << "Now enter the positive integers! " << endl;

	// loop for tInput times to retrive and assign input
	for (int counter = 1; counter <= tInput; counter++)
	{
		cout << "Positive integer " << counter << ":";
		cin >> input[counter - 1];
	}

	// II. calculation

	// to determine MAX and MIN value
	// declaring variables
	int maxValue, minValue;
	/*
		Notes : 
			maxValue = maximum value;
			minValue = minimum value;
	*/
	// letting the first input as max and min value then we will compare this value with the rest later
	maxValue = input[0];
	minValue = input[0];
	// loop through array to find maximum and minimum value
	for (int counter = 0; counter < tInput; counter++)
	{
		// if the maxValue is not the largest assign it with the next input[counter]
		if (maxValue < input[counter])
		{
			maxValue = input[counter];
		}
		// if the minValue is not the smallest assign it with the next input[counter]
		else if (minValue > input[counter])
		{
			minValue = input[counter];
		}
	}

	// to determine repetition
	// loop through input[] to assign unique value into abundance array
	bool unique = false, occurence = false;
	int  abundantValue, abundance, abundanceArray[20][2] = {0}, arrayIndex = 0;
	/*
		Notes :
			unique = to track the occurence when looping;
			occurence = is true if there is any value repeated, so it was assigned as false at first(assuming it 
			doesnt occur);
			
			abundantValue = most occurence;
			abundance = number of occurence for abundantValue;
			abundanceArray = all the value which have occurence will be kept here. All number of occurence 
				will be stored in the first index(0) The second dimension will be used to store the input 
				it self. Assigned to 0, to prevent problems ;
			arrayIndex = to track the index of the last value in abundanceArray[][];
			
	*/
	// loop through all the input[] to place them into another array -- abundanceArray[][] to track their occurence.
	for (int counter = 0; counter < tInput; counter++)
	{
		/* 
			all value is considered unique at first(never occured). For loop is used to check wherther they have 
			occured again or not. If they have occured they are never unique then unique will become false. If 
			the array have looped finished but there is no value occured unique will stay as true and that value 
			input[counter] will be stored in the abundanceArray with number of abundance as 1. 
		*/
		unique = true;
		for (int counter2 = 0; counter2 < counter; counter2++)
		{
			if (abundanceArray[counter2][1] == input[counter])
			{
				unique = false;
				// at the same time if a value have occured once again increment its number of occurence
				abundanceArray[counter2][0]++;
				// for later use, to determine the most abundance, and also to print occurence or not.
				occurence = true;
				// to exit the for loop
				break;
			}
		}
		// if the value is unique it will be assign to the new place in abundaceArray[]
		if (unique)
		{
			// the arrayIndex will keep track of the most recent index and new values dont overlap the old 1.
			abundanceArray[arrayIndex][1] = input[counter];
			abundanceArray[arrayIndex][0]++;

			arrayIndex++;
		}
	}

	// if there is repetition, find the abundance and abundanceValue
	if (occurence)
	{
		/*
			same concept as finding the largest value first let the most abundance and abundanceValue as
		 		the first index in abundanceArray

			then, loop through the abundanceArray[][]
				if the abundance is the same compare their abundanceValue 
					if the abundanceValue is smaller 
						assign them to the current abundance 
						and update the abundanceValue
				else if their abundance is more than the current abundance 
					assign them to the current abundance
					and update the abundanceValue
		*/
		abundance = abundanceArray[0][0];
		abundantValue = abundanceArray[0][1];
		for (int counter = 0; counter < arrayIndex; counter++)
		{
			if (abundance == abundanceArray[counter][0])
			{
				if (abundantValue > abundanceArray[counter][1])
				{
					abundance = abundanceArray[counter][0];
					abundantValue = abundanceArray[counter][1];
				}
			}
			else if (abundance < abundanceArray[counter][0])
			{
				abundance = abundanceArray[counter][0];
				abundantValue = abundanceArray[counter][1];
			}
		}
	}

	// for testing purposes.
	// for (int i = 0; i < counter; i++)
	// {
	// 	cout << abundanceArray[i][0] << "," << abundanceArray[i][1] << endl;
	// }

	// IV. printing results

	// printing maximum value
	cout << "Max=" << maxValue << endl;

	// printing minimum value
	cout << "Min=" << minValue << endl;

	// if there is any occurence print the number of times else print no multiple occurence
	if (occurence)
	{
		// print the most occurrence value
		cout << "The most occurring positive integer:" << abundantValue << endl;

		// print the number of occurence
		cout << "It occurs " << abundance << " times. " << endl;
	}
	else
	{
		// saying there is not any occurence
		cout << "There is no positive integer occuring more than once. " << endl;
	}

	// END
	return 0;
}