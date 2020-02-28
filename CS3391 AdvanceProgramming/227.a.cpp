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

double prices[101];

void m(){
	double price1;
	int m;
	int i,j;
	int cases = 1;
	while(~scanf("%lf %d",&price1, &m)){
		printf("Case %d:\n",cases++);
		
		for(i=0; i<=100;i++)
			prices[i] = price1*i;
			
		for(i=0; i<m; i++){
			int n; double p;
			scanf("%d %lf",&n, &p);
			if(p<prices[n]) prices[n] = p;
		}
		
		for(i=3;i<=100;i++)
			for(j=i;j>=2&&j>=i/2;j--){
				double temp = prices[j-1] + prices[i-(j-1)];
				if( prices[i] > temp )
					prices[i] = temp;
			}
		
		getchar();	//eat \n
		char line[10000];
		gets(line);
		int lp = 0, item;
		bool end = false;
		while(~sscanf(line+lp,"%d",&item)){
			printf("Buy %d for $%.2f\n",item,prices[item]);
			
			while(line[lp]!=' '){
				lp++;
				if(line[lp]=='\0'){
					end = true;
					break;
				}
			}
			if(end) break;
			lp++;	//eat whitespace
		}
	}
}
/*
22.00 2
2 22.00
4 60.00
2 4
25.00 2
2 48.00
2 46.00
2
22.00 2
2 22.00
4 40.00
1 2 3 4
*/

int main(){

		freopen("in.txt", "r", stdin);

	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
