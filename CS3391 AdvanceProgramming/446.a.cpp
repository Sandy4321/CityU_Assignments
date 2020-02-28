/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include <iostream>
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
using namespace std;
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int main(){


	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	int eNum;
	while(~scanf("%i",&eNum)){
		if(eNum==0) break;
		
		int ts[eNum];
		int year[eNum];
		bool keep[eNum];
		memset(keep,false,sizeof keep);
		
		int i,j;
		for(i=0; i<eNum; i++){
			int mm,dd,hour,mint,wtf;
			char pn;
			scanf("%d:%d:%d:%d %*s %c", &mm,&dd,&hour,&mint,&pn);
			if(pn=='+') keep[i] = true;
			ts[i]=mint+hour*100+dd*10000+mm*1000000;
		}
		
		year[0] = 0;	//	BC/AD	0
		for(i=1;i<eNum;i++){
			year[i] = year[i-1];
			if(ts[i-1]>=ts[i])year[i] += 1;
		}
		
		int firstToKeep=-1, lastToKeep;
		for(i=0;i<eNum;i++){
			if(keep[i]){
				lastToKeep = i;
				if(firstToKeep==-1) firstToKeep = i;
			}
			if(year[i]!=year[eNum-1]) lastToKeep = i;
		}
		
		
		
		int dp[eNum];
		for(j=eNum-1;j>=lastToKeep&&year[j]==year[eNum-1];j--)
			dp[j] = 1;
			
		for(i=j;i>=0;i--)
			dp[i] = (eNum-i);	//keep all below, init
			
		//  for(i=0; i<eNum;i++)
		//  	printf("odp[%i]: %i\n",i,dp[i]);
		// 
		// for(int i=0; i<eNum;i++)
        //     printf("dp[%i]:%i\n",i,dp[i]);
	cout << lastToKeep << " " << firstToKeep <<endl;
	for(i = 0; i < eNum ; i++){
			cout << dp[i];
		}
		for(i = lastToKeep; i>=firstToKeep; i--){
			for(j=i+1;j<eNum;j++){
				if(year[i] == year[j])
					dp[i] = min(dp[i], dp[j]+1);
				else if(year[j]-year[i]==1 && ts[j]<=ts[i])
					dp[i] = min(dp[i],dp[j]+1);
				else
					break;
				if(keep[j])break;
			}
		}
		// for(i=0; i<eNum;i++)
		// 	printf("dp[%i]: %i\n",i,dp[i]);
		// 
		// printf("last:%i first:%i\n",lastToKeep,firstToKeep);
		
		printf("%i\n",dp[firstToKeep]);
	}

	return 0;
}
