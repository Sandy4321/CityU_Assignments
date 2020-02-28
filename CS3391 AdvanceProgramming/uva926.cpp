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

struct Node{
	bool canGoTop;
	bool canGoRight;
	ull numberOfWays;
	int x,y;
}nodes [31][31];

int T,n,x,y, x2,y2;

ull dfs(Node& n){
	if (n.numberOfWays != -1){
		return n.numberOfWays;
	}else{
		// terminating 
		if ((n.x == x2 && n.y == y2)){
			n.numberOfWays == 1;
			return 1;
		}else{
			ull aggregate = 0;
			if (n.canGoRight && n.x != x2){
				aggregate += dfs(nodes[n.x+1][n.y]);
			}
			if (n.canGoTop && n.y != y2){
				aggregate += dfs(nodes[n.x][n.y+1]);
			}
			n.numberOfWays = aggregate;
			return n.numberOfWays;
		}
	}
}

void mainFunction()
{
	int w;
	int  bx,by;
	char c;

	from(i,1,31){
		from(j,1,31){
			nodes[i][j].x = i;
			nodes[i][j].y = j;
		}
	}


	input (T);
	while (
		T--
	){
		input(n);

		// run through all grids
		n ++;
		from(i,1,n){
			from(j,1,n){
				nodes[i][j].canGoRight = 
				nodes[i][j].canGoTop = true;
				nodes[i][j].numberOfWays = -1;
			}
		}

		input (x);
		input (y);

		input (x2);
		input (y2);

		input(w);

		from(i,0,w){
			input(bx);
			input(by);
			cin >> c;

			switch(c){
				case 'N':
					nodes[bx][by].canGoTop = false;
					break; 

				case 'E':
					nodes[bx][by].canGoRight = false;
					break;

				case 'S':
					nodes[bx][by-1].canGoTop = false;
					break;

				case 'W':
					nodes[bx-1][by].canGoRight = false;
					break;
			}
		}

		printf("%lld\n",dfs(nodes[x][y]));

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

