#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int temp;

	cout << "Enter the temperature in Centigrade:";
	cin >> temp;

	float Fahrenheit = temp * (9.0 / 5) + 32;

	cout << scientific;
	cout << setprecision(5);

	cout << "Temperature in Fahrenheit is:";
	cout << Fahrenheit << endl;

	cout << "Temperature in Kelvin is:";
	cout << (Fahrenheit + 459.67) * 5 / 9;

	return 0;
}