#include <iostream>
using namespace std;

int main()
{
	cout << "Enter a number of three digits:";
	int num;
	int sum = 0;
	cin >> num;

	do{
		sum += num % 10;
	} while ( num /= 10 );

	cout << "Sum of digits is:" << sum << endl;

	return 0;
}