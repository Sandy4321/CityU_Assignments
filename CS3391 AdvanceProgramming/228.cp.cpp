/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s\n",n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

int tens[9];

void m(){
	int is = 9;
	int acu = 0;
	int bound[10];
	bound[0] = 0;
	for(int i = 0 ; i < 9 ;i++) {
		acu += is * i;
		bound[i] = acu;
		// cout << acu << endl;
		is *= 10;
	}
	tens[0]=0;
	tens[1]=1;
	for(int i=2;i<9;i++)
		tens[i]=tens[i-1]*10;
	int n;
	int cases=1;
	while(~sfd(n)){
			int lowerBound;
		for(int i =0 ;i< 9;i++) {
			if (bound[i] >= n) {
				lowerBound = i;
				break;
			}
		}

		int shift = n - bound[lowerBound-1] - 1 ;
		int diff1 = shift / (lowerBound);
		int diff2 = tens[lowerBound];
		int diff = diff1 + diff2;
		char numStr[25];
		sprintf(numStr,"%d",diff);
		int character = shift % (lowerBound);
		printf("Case %i : %c\n",cases++, numStr[character]);
	}
}

int main(){

		freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);

	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
