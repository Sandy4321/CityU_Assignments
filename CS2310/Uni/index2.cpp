#include <iostream>
using namespace std;

int main(){

	int a=0,b=1,c=2,d;

	d = a,b,c;
	cout << d << endl;
	cout << (c,b,d=a)<<endl;
	int k=5;

	int length ;
	cin >> length;

	for(int i = 1 ; i <= length ; i ++){
		for (int j = 1 ; j <= i-1 ; j ++){
			cout << " ";
		}
		cout << 'x' << endl;
	}




	return 0;
}

void test (int a, int b){

}