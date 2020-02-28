#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

unsigned long long int convTo10(int i,int base){
	unsigned long long int res = 0;
	unsigned long long int k =1;
	while(i>0 ){
		res += (i%10) * k;
		i/= 10;
		k*= base;
	}
	return res;
}
bool notAllowed(int n,int startWith){
	while(n > 0){
		if (n%10 >= startWith){
			return true;
		}else{
			n/=10;
		}
	}
	return false;
}


int main()
{

	int n;
	int i = 0;
	bool first = 1;
	while (cin >> n)
	{
		if (n!=0&& !first){
			cout << endl;
		}else if (n == 0){
			break;
		}else{
			first = false;
		}
		int startWith = 1;
		double a = sqrt(n);
		do{
			here:
			startWith++;
			if (startWith < 10){
				if (notAllowed(n,startWith)){
					goto here;
				}
			}
			// cout << convTo10(n,startWith) << endl;
			a= sqrt(convTo10(n,startWith));
		}while(a != (unsigned long long int)a);
		cout << startWith  ;
	}

	return 0;
}
