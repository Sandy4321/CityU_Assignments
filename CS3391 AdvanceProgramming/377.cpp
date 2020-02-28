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
#define ll long long
using namespace std;

const int MAXN = 5050;

struct Edge{
	int fm, to;
	ll cap, flw;
	Edge(int f, int t, ll c,ll o){
		fm = f;
		to = t;
		cap = c;
		flw = o;
	}
};

struct Dinic{
	
	int s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool ved[MAXN];
	int af[MAXN];	//avaliable flow
	int path[MAXN];	//Edge reach last node
	
	Dinic(int src, int tar){
		s = src;
		t = tar;
	}
	
	Dinic(){}

	bool fired[5002];
	int fireder(int maxi){
		memset(fired,false,sizeof fired);
		didFired(0);
		int res = 0;
		from(i,1,maxi){
			// cout << fired[i] << " ";
			if(fired[i]){
				res++;
			}
		}
		return res;
	}
	void didFired(int n){
		// cout << n;
		from(i,0,G[n].size()){
			Edge &e = edges[G[n][i]];
			if (!fired[e.to] && e.cap > e.flw ){
				fired[e.to] = true;
				didFired(e.to);
			}
		}
	}
	
	void addE(int from, int to, ll cap){
		edges.push_back( Edge(from, to, cap, 0) );
		edges.push_back( Edge(to, from, 0, 0) );
		int eSize = edges.size();
		G[from].push_back(eSize-2);
		G[to].push_back(eSize-1);
	}
	
	bool bfs(){
		memset(ved,false,sizeof(ved));
		queue<int> que;
		que.push(s);
		af[s] = 0;
		ved[s] = true;
		while(!que.empty()){
			int front = que.front();
			que.pop();
			
			for(int i=0; i<G[front].size(); i++){
				Edge &e = edges[ G[front][i] ];
				if( !ved[e.to] && e.cap>e.flw ){
					ved[e.to] = true;
					af[e.to] = af[front] + 1;
					que.push(e.to);
				}
			}
		}
		return ved[t];
	}
	
	ll dfs(int tn, ll a){
		if(tn == t || a == 0)
			return a;
			
		ll flow = 0;
		for(int &c = path[tn]; c<G[tn].size(); c++){
			ll fff;
			Edge &e = edges[ G[tn][c] ];
			if(  af[tn] + 1 == af[e.to] &&
			 	0<( fff = dfs(e.to, min(a, e.cap-e.flw) ) )  ){
					//update flow along the path
					e.flw += fff;
					flow += fff;
					a -= fff;
					edges[ (G[tn][c])^1 ].flw -= fff;
					if(a==0) break;
				}
		}
		
		return flow;
	}
	
	ll mf(){
		ll ans = 0;
		while( bfs() ){
			memset(path, 0, sizeof(path));
			ans += dfs( s, INF );
		}
		return ans;
	}
};

void mainFunction()
{

	int n,s,t,m;
	int s1,s2,weight;
	// int graph[101][101];
	// Network net;
	// int cost[5200];
	// int totalFlow =0;
		ull profit = 0;
		ull res = 0;
		int totalFired = 0;
			int p;
	// ull T = 1;
	while(~scanf("%d%d",&n,&m) ){
		Dinic dn(0,n+1);
		// net.init(2+n);
		profit = 0;
		from(i,1,n+1){
			input(p);
			if (p > 0 ){
				profit += p;
				dn.addE(0,i,p);
			}else{
				dn.addE(i,n+1,-p);
			}
		}

		from(i,0,m){
			input(s1);
			input(s2);
			dn.addE(s1,s2,INF);
		}

		res =profit-dn.mf(); 

		cout << dn.fireder(n+1)<< " " << res<<endl;
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

