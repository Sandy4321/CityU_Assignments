#include<stdio.h>
#include<string.h>
#include<math.h>

const int MAX = 20000;

int p[MAX];
bool v[MAX];

bool ans(int a, int b, int c){
	printf("%i is the sum of %i and %i.\n", a, b, c);
	return false;
}

void ppp(int r){
	memset(v,false, sizeof(v));
	int pc = 0;
	int i,j;
	for(i=2;i<r; ++i){
		if(!v[i]) p[pc++] = i;
		for(j=0; r>i*p[j] && pc>j;j++){
			v[p[j]*i] = true;
			if(i%p[j]==0) break;
		}
	}
}

bool isPrime(int n){
	if(n<2) return false;
	if(n<=3) return true;
	if(!(n&1)) return false;
	
	int it = 1;
	while(p[it]*p[it] <=n){
		if(n%p[it]==0) return false;
		it++;
	}
	
	return true;
}

bool noAns(int n){
	if(n&1){
		if(n>2 && isPrime(n-2))
			return ans(n, 2, n-2);
		return true;
	}
	else
		for(int i=n/2; i>1; i--)
			if(isPrime(i) && isPrime(n-i) && (n-i != i))
				return ans(n, i, n-i);
	
	return true;
}
int main(){
	ppp(12111);
	int n;
	while(~scanf("%i",&n)){
		if(noAns(n)) printf("%i is not the sum of two primes!\n",n);
	}

	return 0;
}