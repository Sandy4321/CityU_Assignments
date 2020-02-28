#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d\n",&n);
		char s[50];
		bool first = true;
		while(n--){
			gets(s);
			if (first){
				cout << s;
				first = false;
			}else{
				cout <<" " << s;
			}
		}
		cout << endl << endl;
	}

	return 0;
}