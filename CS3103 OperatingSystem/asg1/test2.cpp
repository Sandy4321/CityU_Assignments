#include <iostream>
#include <string>

#include <sstream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;
int main(){
	// string a;
	// getline(cin,a);
	// int b =execv(a.c_str(),nullptr);
	// cout << ( a == "")<<endl<<b<<endl; 
	string s;
	getline(cin , s);

	stringstream ss;
	ss << s;
	ss >> s;
	ss << s;
	cout << ss.str();

	return 0;
}