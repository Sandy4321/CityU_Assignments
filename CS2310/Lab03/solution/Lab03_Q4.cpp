#include <iostream>
using namespace std;

int main()
{
	int cYear, cMon, cAge; 	// prefix c is short for current
	int bYear, bMon; 		// prefix b is short for born
	int fYear, fMon;	    // prefix f is short for future
	int tYear, tMon; 		// prefix t is short for total

	cout << "Enter the current year: ";
	cin >> cYear;

	cout << "Enter the current month (a number in range from 1 to 12): ";
	cin >> cMon;

	cout << "Enter your current age in years: ";
	cin >> cAge;
	
	cout << "Enter the month in which you were born (a number in range from 1 to 12): ";
	cin >> bMon;

	cout << "Enter the year for which you want to know your age: ";
	cin >> fYear;

	cout << "Enter the month of year " << fYear << ": ";
	cin >> fMon;

	// updata bYear
	if (bMon <= cMon)
	{
		bYear = cYear - cAge;
	}
	else
	{
		bYear = cYear - cAge - 1;
	}
	
	//updata tMon and tYear
	if (bMon<=fMon)
	{
		tYear = fYear - bYear;
		tMon = fMon - bMon;
	}
	else
	{
		tYear = fYear - bYear - 1;
		tMon = 12 - bMon + fMon;
	}

	cout << "Your age in " << fMon << "/" << fYear << " is: ";
	cout << tYear << " year(s) and " << tMon << " month(s)" << endl;
	return 0;
}
