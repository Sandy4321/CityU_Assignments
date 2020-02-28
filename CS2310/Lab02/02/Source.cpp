#include <iostream>
using namespace std;

void main() {
	char vChar1 = 'B';
	char vChar2 = '9';
	
	cout << vChar1 << endl;
	cout << vChar2 << endl;


	vChar1 = vChar1 - 1;

	// result got demoted to assigned type byte
	cout << "The result of vChar1 when it is subtracted and assigned back to itself :" << vChar1 << endl;
	
	// result got promoted from 1 byte to 4 byte if it is not assigned
	cout << "The result of vChar1 when it is subtracted and not assigned back to itself :" << vChar1 - 2 << endl;



	// question 3

	double vFloat1 = 22.0 / 7;
	cout << vFloat1 << endl;



	// question 4

	cout << "Size of int is " << sizeof(int) << " bytes.\n";
	cout << "Size of char is " << sizeof(char) << " bytes.\n";
	cout << "Size of vFloat1 is " << sizeof(vFloat1) << " bytes.\n";


	// question 5
	int i = 5;
	char a = 'A';
	double x = 1.23;
	
	i = i - x; // 5(int) - 1.23(double) => (int got promoted) 5.0(double) - 1.23(double) => 3.77(double) => i(int) = 3.77 (double) => (assignment : 3.77 got demoted) i(int) = 3(int) (fractional or decimal got removed)
	x = x * a;

	cout << "Value of i is " << i << "\n";
	cout << "Value of x is " << x << "\n";


	// question 6
	int j = 3, k = 2;
	double y;
	y = j / k; // 1
	cout << "Value of y is " << y << "\n";
	y = j / double( k ); // 1.5
	cout << "Value of y is " << y << "\n";
	y = double( j ) / k; // 1.5
	cout << "Value of y is " << y << "\n";
	y = double( j / k ); // 1
	cout << "Value of y is " << y << "\n";
	y = j / 2; // 1
	cout << "Value of y is " << y << "\n";
	y = j / 2.0; // 1.5
	cout << "Value of y is " << y << "\n";



}