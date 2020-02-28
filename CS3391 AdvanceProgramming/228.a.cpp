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

int numOfDigitPositionRange[9];
int tens[9];

void m(){
	int i,j;
	tens[0]=0;
	tens[1]=1;
	for(i=2;i<9;i++)
		tens[i]=tens[i-1]*10;
	
	numOfDigitPositionRange[0] = 0;
	for(int from=1, len=1;from<100000000;from*=10,len++){
		int to=from*10;
		numOfDigitPositionRange[len] = len*(to-from)+numOfDigitPositionRange[len-1];
		$printf("%10d - %-10d:%i\n",from,to-1,numOfDigitPositionRange[len]);
	}
	
	int n;
	int cases=1;
	while(~sfd(n)){
		int nDigits=1;
		while(n>numOfDigitPositionRange[nDigits++]);
		nDigits-=1;
		
		int offset = (n-numOfDigitPositionRange[nDigits-1]-1)/(nDigits);
		//n-pos belongs to num
		int num = tens[ nDigits ]+offset;
		char numStr[25];
		sprintf(numStr,"%d",num);
		n-=numOfDigitPositionRange[nDigits-1]+offset*(nDigits)+1;
		$(offset);$(num);$(n);
		printf("Case %i : %c\n",cases++, numStr[n]);
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
