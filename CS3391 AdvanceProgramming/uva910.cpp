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
#define mMax 30
using namespace std;


int T;
	int graph[26][2]; 
	int dp [26][30];
	bool special[26]; 

int count(int steps, int currentPos){
	if (dp[currentPos][steps] != -1){
		return dp[currentPos][steps];
	}else if (steps == 0){
		return special[currentPos];
	}else{
		dp[currentPos][steps] = count (steps-1,graph[currentPos][0]) + count (steps-1,graph[currentPos][1]);
		return dp[currentPos][steps];
	}
}



void mainFunction()
{
	int n,m;
	char c, c0 , c1 ;
	char cx;
	while (cin >> n){
		memset(graph, 0 , sizeof graph);
		memset(special, false, sizeof special);
		memset(dp, -1, sizeof dp);
		from (i,0,n){
			cin >> c >> c0 >> c1;
			cin >> cx;
			c = c-'A';
			c0 = c0 - 'A';
			c1 = c1 - 'A';

			graph[c][0] = c0;
			graph[c][1] = c1;
			if ( cx == 'x'){
				special [c] = true;
			}
		}
		input(m);
		cout << count(m,0) << endl;
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

