/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define MAXN 1010

struct Pad{
	double freq;
	int x, y, r;
}pads[MAXN];

bool intersect(Pad a, Pad b){
	double xdiff = (double) b.x-a.x;
	double ydiff = (double) b.y-a.y;
	double n1 = xdiff*xdiff + ydiff*ydiff;
	double n2 = (double) (a.r+b.r)*(a.r+b.r);
	
	return n1<n2;
}

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
					if(a==0) break;
				}
		}
		
		return flow;
	}
	
	int mf(int s, int t){
		this->s = s; this->t=t;
		
		int ans = 0;
		while( bfs() ){
			memset(path, 0, sizeof(path));
			ans += dfs( s, oo );
		}
		
		return ans;
	}
};

int main(){
	int cases;
	scanf("%i",&cases);
	while(cases--){
		int padNum;
		scanf("%i", &padNum);
		Dinic dn(0, 0);
		
		int i,j;
		Pad src, tar;
		
		for(i=1;i<=padNum;i++){
			scanf("%lf %i %i %i",&pads[i].freq, &pads[i].x, &pads[i].y, &pads[i].r);
			if(pads[i].freq==400){	//Red
				src = pads[i];
				padNum--;
				i--;
			}
			else if(pads[i].freq==789){	//Violet
				tar = pads[i];
				padNum--;
				i--;
			}
		}
		if( intersect(src,tar) ){
			puts("Game is VALID");
			continue;
		}
		
		for(i=1;i<=padNum;i++){
			dn.addE( i, padNum+i, 1 );
			if( intersect(src, pads[i]) && src.freq < pads[i].freq )
				dn.addE(0,i,1);
			if( intersect(pads[i], tar) && pads[i].freq < tar.freq )
				dn.addE(padNum+i, 2*padNum+1, 1);
			
			for(j=1; j<=padNum; j++){
				if(i==j) continue;
				if( intersect(pads[i],pads[j]) && pads[i].freq < pads[j].freq )
					dn.addE(padNum+i, j, 1);
			}
		}
		
		if(dn.mf(0,2*padNum+1)>=2) puts("Game is VALID");
		else puts("Game is NOT VALID");
	}

	return 0;
}
