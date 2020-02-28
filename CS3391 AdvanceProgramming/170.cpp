#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

 long long int convTo10(long long int i,int base){
	 long long int res = 0;
	 long long int k =1;
	while(i>0 ){
		res += (i%10) * k;
		i/= 10;
		k*= base;
	}
	return res;
}
bool notAllowed(long long int n,int startWith){
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

	long long int n;
	int i = 0;
	while (cin >> n && n != 0)
	{
		int startWith = 1;
		double a = sqrt(n);
		// bool flag = true;
		if (n<=0){
			cout << 100 << endl;
			continue;
		}
		do{
			here:
			startWith++;
			if (startWith < 10){
				if (notAllowed(n,startWith)){
					goto here;
				}
			}else if (startWith >= 100){
				break;
			}
			// cout << convTo10(n,startWith) << endl;
			a= sqrt(convTo10(n,startWith));
		}while(a != ( long long int)a );
		// if (flag){
			cout << startWith <<endl ;
		// }

	}

	return 0;
}