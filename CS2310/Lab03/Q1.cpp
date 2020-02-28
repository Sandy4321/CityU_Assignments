#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

	int sideA, sideB, sideC;
	cout << "Enter the first side:";
	cin >> sideA;

	cout << "Enter the second side:";
	cin >> sideB;

	cout << "Enter the third side:";
	cin >> sideC;

	double p = (sideA + sideB + sideC) / 2;
	cout << "The area is:";
	cout << fixed;
	cout << setprecision(2);
	// cout << (p*(p-a))
	cout << sqrt(p * (p - sideA) * (p - sideB) * (p - sideC)) << endl;
	
	return 0;
}