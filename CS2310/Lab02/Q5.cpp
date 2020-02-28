#include <iostream>
using namespace std;

int main()
{

	int i = 5;
	char a = 'A';
	double x = 1.23;
	i = i - x;
	x = x * a;

	cout << "Value of i is " << i << endl;
	cout << "Value of x is " << x << endl;

	// cout << (a='3') << endl;
	// cout << a <<endl;
	// if (x=2){
	// 	cout << x<< endl;
	// }
	// double b = 2.3;

	cout << a + 1 << endl;

	int j = 3, k = 2;

	double y;

	y = j / k;
	cout << y << endl;
	y = j / double(k);
	cout << y << endl;
	y = double(j) / k;
	cout << y << endl;
	y = j / 2;
	cout << y << endl;
	y = j / 2.0;
	cout << y << endl;

	return 0;
}