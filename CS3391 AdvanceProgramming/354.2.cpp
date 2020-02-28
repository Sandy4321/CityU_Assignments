#include <stdio.h>
#include <iostream>
using namespace std;


int main() {

	int T;
	int digit,digit2,result;

	cin >> T;
	while (T--) {

		result = 0;
		for (int i = 0;i < 4; i++) {

			cin >> digit;

			result += digit % 10;
			digit /= 10;

			digit2 = digit % 10 * 2;
			result += digit2 % 10 + digit2 / 10;
			digit /= 10;

			result += digit % 10;
			digit /= 10;

			digit2 = digit % 10 * 2;
			result += digit2 % 10 + digit2 / 10;

		}

		if (result % 10) {
			cout << "Invalid" << endl;
		}
		else {
			cout << "Valid" << endl;
		}

	}

	return 0;
}