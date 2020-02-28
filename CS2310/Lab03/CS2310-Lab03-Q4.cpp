#include <iostream>
using namespace std;

int main()
{
	int cYear, cMon, cAge; 	// prefix c is short for current
	int bYear, bMon; 		// prefix b is short for born
	int fYear, fMon;	    // prefix f is short for future
	int tYear, tMon; 		// prefix t is short for total

	cout << "Enter the current year: ";
	// ToDo1: add user input

	cout << "Enter the current month (a number in range from 1 to 12): ";
	// ToDo1: add user input

	cout << "Enter your current age in years: ";
	// ToDo1: add user input
	
	cout << "Enter the month in which you were born (a number in range from 1 to 12): ";
	// ToDo1: add user input

	cout << "Enter the year for which you want to know your age: ";
	// ToDo1: add user input

	cout << "Enter the month of year " << fYear << ": ";
	// ToDo1: add user input


	if (/* ToDo2: add the condition here*/)
	{
		// ToDo3: update bYear
	}
	else
	{
		// ToDo4: update bYear
	}

	if(/* ToDo5: add the condition here*/) 
	{
		// ToDo6: update tMon and tYear
	}
	else
	{
		// ToDo7: update tMon and tYear
	}
	
	cout << "Your age in " << fMon << "/" << fYear << " is: ";
	cout << tYear << " year(s) and " << tMon << " month(s)" << endl;
	return 0;
}
