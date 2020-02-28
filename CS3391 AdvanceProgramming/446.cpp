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
#define foreach(i, y) for (int i = 0; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;


int T;

void mainFunction()
{
	int m,d,h,mi;
	char kp;

	int timeStamp[1001];
	bool keep[1001];

	int year[1001];
	int dp[1001];

	while(input(T) && T != 0){
		foreach(i , T ){
			scanf("%d:%d:%d:%d %*s %c",&m,&d,&h,&mi,&kp);
			timeStamp[i] = (m << 19) + (d << 13) + (h << 7) + mi;
			keep[i] = kp == '+';
		}
		// foreach(i,T){
		// 	cout << timeStamp[i]<<endl;
		// }

		// build years
		year[0] = 0;
		from(i,1,T){
			if (timeStamp[i] > timeStamp[i-1]){
				year[i] = year[i-1];
			}else{
				year[i] = year[i-1]+1;
			}
		}

		int now = year[T-1];

		int upperLim,lowerLim;

		// finding upper limit
		from (i,0,T){
			if (keep[i]){
				upperLim = i;
				break;
			}
		}

		// finding lower limit
		fromNeg(i,T-1,0){
			// happens when either year change
			// 		or you need to save
			if (keep[i] || year[i] != now){
				lowerLim = i;
				break;
			} 
		}


		memset(dp,T-1,sizeof dp);
		// assign dp for everything before lowerlim; 
		int stopIndex= T-1;
		for (;stopIndex >= lowerLim && year[stopIndex] == now ; stopIndex--){
			dp[stopIndex] = 1;
		}
		fromNeg(i,stopIndex,0){
			dp[i] = T-i;
		}

		// cout << lowerLim <<" "<<upperLim <<endl;

		// from(i,0,T){
		// 	cout << dp[i];
		// }


		fromNeg(i,lowerLim,upperLim){
			from(j,i+1,T){
				if (year[i]==year[j] or (year[j] - year[i] == 1 && timeStamp[j] <= timeStamp[i]) ){
					dp[i] = min(dp[i],dp[j]+1);
				}else{
					break;
				}
				if (keep[j]){
					break;
				}
			}
		}

		printf("%d\n",dp[upperLim]);

	}
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

