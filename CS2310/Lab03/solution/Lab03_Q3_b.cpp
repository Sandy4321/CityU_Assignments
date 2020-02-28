#include <iostream>
using namespace std;

void main() {

	double Num;
	int a, b, c, d, Sum;
	cout << "Enter a decimal number: ";
	cin >> Num;
	a = (int)Num / 100;
	b = (int)Num % 100;
	c = b / 10;
	b = b % 10;
	d = (Num - (int)Num) * 10;
	Sum = a + b + c + d;
	cout << "Sum of digits is: " << Sum << '\n';

}

