#include <iostream>
using namespace std;

int main() {

	cout << "Enter Value of each score: " << endl;

	int a, b, c, d, e, f, vMax = 0, vMin = 0, vMax2 = 0, vMin2 = 0;
	cin >> a >> b >> c >> d >> e >> f;




	if (a > b) {
		vMax = a;
		vMin = b;
	}
	else {
		vMax = b;
		vMin = a;
	}

	if ( )



	if (vMax < c) {
		vMax = c;
	}
	else if (vMax2 < c) {
		vMax2 = c;
	}
	else if (vMin > c) {
		vMin = c;
	}
	else if (vMin2 > c) {
		vMin2 = c;
	}


	if (vMax < d) {
		vMax = d;
	}
	else if (vMax2 < d) {
		vMax2 = d;
	}
	else if (vMin > d) {
		vMin = d;
	}
	else if (vMin2 > d) {
		vMin2 = d;
	}


	if (vMax < e) {
		vMax = e;
	}
	else if (vMax2 < e) {
		vMax2 = e;
	}
	else if (vMin > e) {
		vMin = e;
	}
	else if (vMin2 > e) {
		vMin2 = e;
	}


	if (vMax < f) {
		vMax = f;
	}
	else if (vMax2 <= f) {
		vMax2 = f;
	}
	else if (vMin > f) {
		vMin = f;
	}
	else if (vMin2 >= f) {
		vMin2 = f;
	}


	cout << "The effective score is: " << (a + b + c + d + e + f - vMax - vMax2 - vMin - vMin2) / 2<<endl;


		return 0;
}
