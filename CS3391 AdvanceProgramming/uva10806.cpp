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
struct Node{
	int parent;
	int path;
	bool cleared ;
	Node (){
		parent = -1;
		path = INF;
		cleared =false;
	}
	// int 
}memo[101];
int T,n,m;

int g[101][101] = {0};
// int memo[][] 

int minIn(Node m[]){
	int res= INF;
	int resIndex = -1;
	from(i,0,n){
		if (!m[i].cleared && m[i].path < res ) {
			res = m[i].path;
			resIndex = i;
		}
	}
	return resIndex;
}


int dijkstra(int start, int end){

	from(i,0,n){memo[i].path=INF;}

	// at start
	memo[start].parent = start;
	memo[start].path = 0;
	while(1){
		// Find minimum distance
		int curr = minIn(memo);
		if (curr == -1){
			break;
		}else{
			memo[curr].cleared = true;
			// handle node
			// 1. test all edge
			from(i,0,n){
				// Compare edge to memo
				if (g[curr][i] != -1 && memo[i].path > memo[curr].path + g[curr][i] ){
					memo[i].parent = curr;
					memo[i].path   = memo[curr].path + g[curr][i];
				}
			}
		}
	}
	return memo[end].path;

}

void mainFunction()
{
	int	x1,x2,leng;
	while (cin >> n and n != 0){
		memset(g,-1,sizeof g);
		cin >> m;
		from(i,0,m){
			cin >> x1 >>	x2	>>	leng;
			g[x1][x2]=leng;
			g[x2][x1]=leng;
		}

		int	res	=	dijkstra(1,m);
		if(res==INF){
			cout<<"Back to jail\n";
			continue;
		}
		int pa = m;
		while(pa!=1){
			g[pa][memo[pa].parent]=-1;
			g[memo[pa].parent][pa]=-1;
			pa=memo[pa].parent;
		}
		res += dijkstra(m,1);
		if (res >=INF){
			cout<<"Back to jail\n"<<endl;
			continue;
		}else{
			cout << res << endl;
		}

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

