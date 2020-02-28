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
#define $(x)                                     \
	{                                            \
		if (DUBUG)                               \
			std::cout << #x << " = " << x << " " \
					  << "\n";                   \
	}
#define _(x)                                      \
	{                                             \
		if (DUBUG)                                \
			std::cout << #x << " = " << x << " "; \
	}

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

int dp[52][52][52][52];
int dp2[50][50][50][50];
bool board[52][52];

int T;

int recursion(int x1,int y1, int x2 ,int y2){
	if ((x2 -x1) < 3 || (y2-y1) < 3){
		return 0;
	}else if (dp[x1][y1][x2-1][y2-1] != -1){
		return dp[x1][y1][x2-1][y2-1];
	}else{

		int result =0;

		bool placing = true;
		if (dp2[x1][y1][x2-1][y2-1] != -1 ){
			placing = dp2[x1][y1][x2-1][y2-1] ;
		}else{
			from ( i, x1, x2 ) {
				// from ( j, y1, y2 ) {
				// 	if ( board[i][j] ) {
				// 		placing = false;
				// 		goto fck;
				// 	}
				// }
				if (board[y1][i] || board[y2-1][i] ){
					placing = false;
					break;
				}
			}
			from (i,y1,y2){
				if (board[i][x1] || board[i][x2-1] ){
					placing = false;
					break;
				}
			}

			dp2[x1][y1][x2-1][y2-1] = placing;
		}
		
		result = recursion ( x1+1,y1,x2,y2 );
		result = max(result , recursion(x1,y1+1,x2,y2));
		result = max(result , recursion(x1,y1,x2-1,y2));
		result = max(result , recursion(x1,y1,x2,y2-1));
		
		if ( placing ) {

			result = max ( result , 1 + recursion( x1+1,y1+1,x2-1,y2-1 ) );

		}

		// cout << x1<<" "<<x2<<" "<<y1<<" "<<y2<<" ";
		// cout << result <<" " << endl;

		dp[x1][y1][x2-1][y2-1] = result;

		return result;
	}
}

char grid[52][52];

void mainFunction()
{
	input(T);


	char line[52];
	char cha;
	T++;
	from(p,1,T)
	{

		memset(dp,-1,sizeof dp);
		memset(dp2,-1,sizeof dp2);

		int row;
		// cin >> row;
		// _(row);
		scanf("%i\n",&row);
		// _(line);

		from(i,0,row)
			gets(grid[i]);

		// stringstream ss;
		// ss << line;
		// int col = 0;
		// while (ss >> cha)
		// {
		// 	if (cha == '0')
		// 	{
		// 		board[0][col++] = false;
		// 	}
		// 	else
		// 	{
		// 		board[0][col++] = true;
		// 	}
		// }

		from(i, 0, row)
		{
			from(j, 0, strlen(grid[0]))
			{
				if (grid[i][j] == '0')
				{
					board[i][j] = false;
				}
				else
				{
					board[i][j] = true;
				}
			}
		}


		// from (i,0,row){
		// 	from(j,0,col){
		// 		cout << board[i][j] <<" ";
		// 	}
		// 	cout << endl;
		// }

		printf("Case #%d: %d\n",p,recursion(0,0,strlen(grid[0]),row) );

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
