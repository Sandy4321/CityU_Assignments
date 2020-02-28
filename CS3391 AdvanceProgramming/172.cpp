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

#define eps 1e-6

using namespace std;


int T;

struct Edge{
	int to;
	int len;
};

struct Node{
	int idx;
	vector<Edge> edges;
};

bool canUpdate(int v[][2],int a, Edge e){
	// can a update b?
	// lnBrk();
	// _(a);
	// _(v[a][0]);
	// _(v[a][1]);
	// _(v[e.to][0]);
	// _(v[e.to][1]);
	// $(e.len);
	// lnBrk();
	// _((v[a][0] != INF and e.len + v[a][0] < v[e.to][1]));
	// _((v[a][1] != INF && e.len + v[a][1] < v[e.to][0]));
	if (v[a][0] != INF && e.len + v[a][0] < v[e.to][1]){
		v[e.to][1] = e.len + v[a][0];
		v[e.to][0] = min(v[e.to][0] , e.len + v[a][1]);
		return true;
	}else if(v[a][1] != INF && e.len + v[a][1] < v[e.to][0]){
		v[e.to][0] = e.len + v[a][1];
		return true;
	}else{
		return false;
	}
}


void boardcast(int start,int v[][2], Node graph[]){
	// $(start);
	// from(i,0,7){
	// 	_(v[i][0]);
	// 	$(v[i][1]);
	// }
	from(i,0,graph[start].edges.size()){
		if (canUpdate(v,start,graph[start].edges[i])){
			// $(graph[start].edges[i].to);
			boardcast(graph[start].edges[i].to,v,graph);
		}
	}
}

void mainFunction()
{
	int n,r;

	Node graph[500];
	int v[500][2];
	int p1,p2,l;
	T = 1;
	while(~input(n)){
		input(r);

		from(i,0,n){
			graph[i].edges.clear();
		}

		from(i,0,r){
			input(p1);
			input(p2);
			input(l);
			Edge e1,e2;
			e1.to = p1;
			e2.to = p2;
			e1.len = e2.len = l;
			graph[p1].edges.push_back(e2);
			graph[p2].edges.push_back(e1);
		}

		// from(i,0,n){
		// 	$(i);
		// 	from(j,0,graph[i].edges.size()){
		// 		_(graph[i].edges[j].to);
		// 		$(graph[i].edges[j].len);
		// 	}
		// 	lnBrk();
		// }

		memset(v,INF,sizeof v);

		v[0][1] = 0;

		boardcast(0,v,graph);
		// from(i,0,n){
		// 	_(v[i][0]);
		// 	$(v[i][1]);
		// }

		if (v[n-1][1] != INF){
			printf("Set #%d\n%d\n",T++,v[n-1][1]);
		}else{
			printf("Set #%d\n?\n",T++);
		}

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

