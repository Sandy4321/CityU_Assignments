#include <iostream>
using namespace std;
void main()
{
	// Q1. int data type
	int num1 = 2147483646;
	int num2;
	num2 = num1 + 2;
	cout << "Value of num1 is " << num1 << "\n";
	cout << "Value of num2 is " << num2 << "\n";
	cout << "\n";

	// Q2. char data type
	char vChar1 = 'B';
	char vChar2 = '9';
	cout << "Value of vChar1 is " << vChar1 << '\n';
	cout << "Valur of vChar2 is " << vChar2 << '\n';
	vChar1 = vChar1 - 1;
	cout << "updated value of vChar1 is " << vChar1 << '\n';
	cout << "\n";

	// Q3. double data type
	double vFloat1;
	vFloat1 = 22.0 / 7;
	cout << "Value of vFloat1 is " << vFloat1 << '\n';
	cout << "\n";

	// Q4. sizeof operator
	cout << "Size of int is " << sizeof(int) << " bytes.\n";
	cout << "Size of char is " << sizeof(char) << " bytes.\n";
	cout << "Size of vFloat1 is " << sizeof(vFloat1) << " bytes.\n";
	cout << "\n";

	// Q5. type conversion
	int i = 5;
	char a = 'A';
	double x = 1.23;
	i = i - x;
	x = x * a;
	cout << "Value of i is " << i << "\n";
	cout << "Value of x is " << x << "\n";
	cout << "\n";

	// Q6. implicit conversion between integers and floating point numbers
	int j = 3, k = 2;
	double y;
	y = j / k;
	cout << "Value of  j/k  is " << y << '\n';
	y = j / double(k);
	cout << "Value of  j/double(k)  is " << y << '\n';
	y = double(j) / k;
	cout << "Value of  double(j)/k  is " << y << '\n';
	y = double(j / k);
	cout << "Value of  double(j/k)  is " << y << '\n';
	y = j / 2;
	cout << "Value of  j/2  is " << y << '\n';
	y = j / 2.0;
	cout << "Value of  j/2.0  is " << y << '\n';

}