#include <iostream>
#include <string>
using namespace std;

int function(int& index) {
	return index++;
}
int function2(int& index) {
	index++;
	return function(index);
}

int main() {

	char s[2000];
	cin >> s;
	s++;
	cout << s;

	return 0;
}