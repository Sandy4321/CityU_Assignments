#include <iostream>
using namespace std;

int main(){
	short T;
	cin >> T;
	while(T--){
		int a , b;
		char s1[3];
		char s2[3];
		scanf("%s:%s",s1,s2);
		a = atoi(s1);
		b = atoi(s2);
		
		a = 12 - a - 1;
		b = 60 - b ;
		if (a == -1){
			cout << 11;
		}else{
			if (a == 0){
				cout << 12;
			}else if (a < 10){
				cout << '0' << a;
			}else{
				cout << a ;
			}
		}
		cout <<':';
		if (b == 60){
			cout << "00";
		}else{
			if (b < 10){
				cout << '0'<<b;
			}else{
				cout << b;
			}
		}
		cout << endl;
	}
	return 0;
}