#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() 
{
	double a,b,c,p,area;

	cout << "Enter the first side: ";
	cin >> a;
	cout << "Enter the second side: ";
	cin >> b;
	cout << "Enter the third side: ";
	cin >> c;

	p = (a + b + c) / 2;
	area = sqrt(p*(p - a)*(p - b)*(p - c));
	cout << "The area is: " << fixed << setprecision(2) << area <<'\n';

	return 0;
}
