/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib> // random
#include <ctime>
#include <climits>	// all useful constants
#include <functional> // for hash
#include <algorithm>
#include <sstream>
#include <iomanip>
// #include <regex>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
#include <set>
// using namespace std;
#define ull unsigned long long
#define DUBUG true
#define $(x) {if (DUBUG) std::cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) std::cout << #x << " = " << x << " ";}

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d",&x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)
#define foreach(i,n) for (int i = 0 ;  i< n ; ++i)

#define eps 1e-6

using namespace std;

double cross(double cx, double cy, double x1, double y1,double x2, double y2){
	return (x1-cx)*(y2-cy) - (y1-cy)*(x2-cx);
}

int T;

void mainFunction()
{
	int dp[101][5]	;
	memset(dp,0,sizeof dp);
	dp[1][0] = 1;
	from(i,2,101){
		from(j,0,5){
			dp[i][j] = dp[i-1][j];
		}

		int tempi = i;

		if (tempi >= 100){
			tempi -= 100;
			dp[i][4] ++; 
		}
		if (tempi / 10 == 9){
			dp[i][4] ++;
			dp[i][2]++;
			tempi = tempi % 10;
		}else if (tempi / 10 == 4){
			dp[i][3]++;
			dp[i][2] ++;
			tempi = tempi % 10;
		}else if (tempi /10 >= 5){
			dp[i][3]++;
			tempi = tempi - 50; 
		}

		while (tempi >= 10){
			dp[i][2]++; 
			tempi -= 10;
		}

		if (tempi == 9){
			dp[i][2] ++;
			dp[i][0] ++;
			tempi -= 9;
		}else if (tempi == 4){
			dp[i][1]++;
			dp[i][0]++;
			tempi -= 4;
		}else if (tempi >= 5){
			dp[i][1]++;
			tempi -= 5;
		}

		while(tempi >= 1){
			tempi -= 1;
			dp[i][0] ++;
		}
	}

	int n;
	while(cin >> n && n != 0){
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,dp[n][0],dp[n][1],dp[n][2],dp[n][3],dp[n][4]);
	}


}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w",stdout);
	}
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

