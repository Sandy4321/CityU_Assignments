#include <iostream>

using namespace std;

int main(){
	int n , k;

	do{
		cout << "Input the value of n: ";
		cin >> n; 
	}while (n < 0);

	do{
		cout << "Input the value of k: ";
		cin >> k; 	
	}while (k < 0);

	if ( k > n ){
		cout << "The number of permutation is : 0" << endl;
	} else {
		int permutation = 1;
		for ( int count = 0 ; count < k ; count ++){
			permutation *= (n - count );
		}
		cout << "The number of permutation is : "<< permutation<<endl;
	}

	return 0;
}