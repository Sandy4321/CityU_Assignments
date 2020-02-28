#include <iostream>
using namespace std;

void main() {

	int Num, a, b, c, Sum;
	cout << "Enter a number of three digits: ";
	cin >> Num;
	a = Num / 100;
	b = Num % 100;
	c = b / 10;
	b = b % 10;
	Sum = a + b + c;
	cout << "Sum of digits is: " << Sum << '\n';

}
        	
