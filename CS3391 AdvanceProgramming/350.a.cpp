#include<stdio.h>
#include <iostream>
#include<string.h>
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
char grid[52][52];
int dp[52][52][52][52];

int main(){

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	int cases;
	scanf("%i",&cases);
	for(int ccc=0; ccc<cases; ccc++){
		int row;
		scanf("%i\n",&row);

		int i,j,k;

		for(i=0; i<row; i++)
			gets(grid[i]);

		int len = strlen(grid[0]);
		memset(dp,0,sizeof(dp));

		for(int r = 3 ; r<=row ; r++)
			for (int c = 3; c <=len; c++)
				for(i=0; i+r<row+1;i++)
					for(j=0; j+c<len+1;j++){
						bool dough = true;
						int x = i+r-1;
						int y = j+c-1;

						for(k=0; k<c; k++)
							if(grid[i][j+k]!='0'||grid[x][j+k]!='0'){
								dough = false;
								break;
							}
						if(dough)
							for(k=0; k<r; k++)
								if( grid[i+k][j]!='0'||grid[i+k][y]!='0'){
									dough = false;
									break;
								}

						int *step = &dp[i][j][x][y];
						*step = dough;
						*step = max(*step, dp[i+1][j+1][x-1][y-1]+dough);
						*step = max(*step, dp[i+1][j][x][y]);
						*step = max(*step, dp[i][j+1][x][y]);
						*step = max(*step, dp[i][j][x-1][y]);
						*step = max(*step, dp[i][j][x][y-1]);
					}

		printf("Case #%i: %i\n",ccc+1,dp[0][0][row-1][len-1]);
	}

	return 0;
}
