#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	double Cel, Fah;

	cout << "Enter Temperature in Centigrade: ";
	cin >> Cel;
	Fah = 9.0 / 5.0 * Cel + 32;
	cout << "Temperature in Fahrenheit is: " << fixed << setprecision(2) << Fah << '\n';

}
