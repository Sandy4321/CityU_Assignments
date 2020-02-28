#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	// cout << setprecision(5);
	cout << setw(3);
	cout << 2.3213123123123123;
	cout  << endl << 2000.132412341234;
	cout << endl << 2.124341234e21;

	int mama[2]={0};
	int nana[2];

	for ( int i = 0  ; i < 2 ;i ++ ){
		cout << mama[i] <<endl<< nana[i]<<endl;
	}


	return 0;
}