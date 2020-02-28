#include <iostream>
using namespace std;

/*
 * 
 */
int main() {
	int a, b, c, d;
	cout << "Enter 4 integer values:" << endl;
	cin >> a >> b >> c >> d;

	int vMax, vMin;

	if(a > b) {
	vMax = a;
	vMin = b;
	} else {
	vMax = b;
	vMin = a;
	}

	if(c > vMax) {
	 vMax = c;
	 } else if (c < vMin) {
	 vMin = c;
	 }

	 if(d > vMax) {
	 vMax = d;
	 } else if (d < vMin) {
	 vMin = d;
	 }

	 double res = (a + b + c + d - vMax - vMin)/2.0;
	 cout << "The median of 4 values is: " << res << endl; 

    return 0;
}

