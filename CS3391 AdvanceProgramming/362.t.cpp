/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define MAXN 202	// 1 <= n <= 100

struct Edge{
	int fm, to, cap, flw;
	Edge(int f, int t, int c,int o){
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
	
	void addE(int from, int to, int cap){
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
	
	int dfs(int tn, int a){
		if(tn == t || a == 0)
			return a;
			
		int flow = 0;
		for(int &c = path[tn]; c<G[tn].size(); c++){
			int fff;
			Edge &e = edges[ G[tn][c] ];
			if(  af[tn] + 1 == af[e.to] &&
			 	0<( fff = dfs(e.to, min(a, e.cap-e.flw) ) )  ){
					//update flow along the path
					e.flw += fff;
					flow += fff;
					a -= fff;
					edges[ (G[tn][c])^1 ].flw -= fff;
					if(a<=0) break;
				}
		}
		
		return flow;
	}
	
	int mf(){
		
		int ans = 0;
		while( bfs() ){
			memset(path, 0, sizeof(path));
			ans += dfs( s, oo );
		}
		
		return ans;
	}
};

int main(){

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	int height, width, botNum, botRange;
	int cases=1;
	while(~scanf("%i %i %i %i",&height, &width, &botNum, &botRange)){
		if(height*width*botNum*botRange==0) break;
		
		int north = botNum*2;
		int south = botNum*2+1;
		Dinic dn(north,south);
		
		int x[MAXN],y[MAXN];	//co‐ordinates
		
		for(int i=0; i<botNum; i++)
			scanf("%i %i",&x[i], &y[i]);
			
		for(int i=0; i<botNum; i++){
			dn.addE(i*2, i*2+1, 1);
			
			if(botRange >= y[i])
				dn.addE(north, i*2, 1);
				
			if(botRange >= width-y[i])
				dn.addE(i*2+1, south, 1);
			
			for(int j=0; j<botNum; j++){
				int xdiff, ydiff;
				xdiff = x[i]-x[j];
				ydiff = y[i]-y[j];
				if(4*botRange*botRange >= xdiff*xdiff + ydiff*ydiff)
					dn.addE(i*2+1, j*2, 1);
			}
		}
		
		printf("Case %i: %i\n",cases++, dn.mf());
	}

	return 0;
}
