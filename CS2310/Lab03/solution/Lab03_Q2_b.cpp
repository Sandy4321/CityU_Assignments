#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	double Cel, Fah, Kel;

	cout << "Enter Temperature in Centigrade: ";
	cin >> Cel;
	Fah = 9.0 / 5.0*Cel + 32;
	Kel = (Fah + 459.67) * 5.0 / 9.0;
	cout << "Temperature in Fahrenheit is: " << fixed << setprecision(2) << Fah << '\n';
	cout << "Temperature in Kelvin is: " << fixed << setprecision(2) << Kel << '\n';

}
