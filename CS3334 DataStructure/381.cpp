#include <iostream>
#include <vector>
using namespace std;

int expectExpression(char[],int&);

int decimal(char c) {
	if (c >= 65) {
		return c - 55;
	}
	else {
		return c - 48;
	}
}

int expectNumber(char exp[],int&index ) {
	if (exp[index] == '(') {
		index++;
		int num = expectExpression(exp,index);
		index++;
		return num;
	}
	else {
		int num = exp[index];
		index++;
		return decimal(num);
	}
}

int expectExpression(char exp[], int& index) {

	vector<int> numStack;

	numStack.push_back(expectNumber(exp, index));
	// next should be +,-,*,/
	while (exp[index] == '+' || exp[index] == '*') {
		char op = exp[index];
		index++;
		int b = expectNumber(exp, index);
		if (op == '+') {
			numStack.push_back(b);
		}
		else {
			int temp = numStack.back();
			numStack.pop_back();
			temp *= b;
			numStack.push_back(temp);
		}
	}

	int res = 0;
	while (!numStack.empty()) {
		res += numStack.back();
		numStack.pop_back();
	}

	return res;
}


int main() {

	char exp[101];
	int index;
	while (~scanf("%s",&exp)) {
		index = 0;
		printf("%X\n", expectExpression(exp, index));
	}

	return 0;
}