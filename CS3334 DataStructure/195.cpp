#include<iostream>
#include <vector>
#include <string>
using namespace std;

struct StringAndState {
	StringAndState(string str, string state) :str(str), state(state) {}
	string str;
	string state;
};

string remove(string str) {
	switch (str.length()) {
	case 2:
		return "MUTANT";
	case 1:
		if (str[0] == 'B') {
			return "MUTANT";
		}
		else {
			return "SIMPLE";
		}
	case 0:
		return "MUTANT";
	}
	/*if (str.str.length() == 0) {
		return StringAndState()
	}
	if (str.str.length() == 1) {
		if (str[0] == 'B') {
			return StringAndState(str,"Mutant");
		}
		else {
			return StringAndState(str,"Simple");
		}
	}*/
	if (str[0] == 'B') {
		if (str.back() == 'A') {

			str.pop_back();
			str.erase(str.begin());

			string subStringResult = remove(str);
			if (subStringResult == "MUTANT") {
				return "MUTANT";
			}
			return "MUTAGENIC";
		}
		else {
			// remove all the ab in the end and return fully grown on the condition that the string is atleast longer than 5 
			while (str.length() >= 5) {
				if (str[str.length() - 2] == 'A') {
					str.pop_back();
					str.pop_back();
					if (str.back() == 'A') {

						str.pop_back();
						str.erase(str.begin());

						string subStringResult = remove(str);
						if (subStringResult == "MUTANT") {
							return "MUTANT";
						}
						return "FULLY-GROWN";
					}
				}
				else {
					return "MUTANT";
				}
			}
			return "MUTANT";

		}
	}
	else {
		if (str.back() == 'B' && str[str.length()-2] == 'A') {
			str.pop_back();
			str.pop_back();
			string subStringResult = remove(str);
			if (subStringResult == "MUTANT") {
				return "MUTANT";
			}else{
				return "FULLY-GROWN";
			}
		}
		else {
			return "MUTANT";
		}
	}
}


int main() {

	int T;
	cin >> T;
	getchar();
	while (T--) {

		string str;
		getline(cin, str);



		cout << remove(str) << endl;
	}


	return 0;
}