#include <iostream>
using namespace std;
int main(){

	int a = 0,b,c;
	int T=1;
	while(cin >> a && a != 0){
		cin >> b >> c;
		if ((a*2)*(a*2) - b*b -c*c >= 0){
			cout << "Pizza "<<T++<<" fits on the table.\n";
		}else{
			cout << "Pizza "<<T++<<" does not fit on the table.\n";
		}
	}

	return 0;
}