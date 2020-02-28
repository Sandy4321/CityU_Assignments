/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int oo = 1e9;

int calRing(int oPos, char ttype, int bhvr){
	if(ttype=='0') return oPos;
	
	int newRPos = oPos;
	
	if(ttype=='+')
		newRPos += bhvr%12;
	else if(ttype=='-')
		newRPos -= bhvr%12;
	else if(ttype=='=')
		newRPos = bhvr;
	else if(ttype=='*')
		newRPos = oPos*bhvr;
	
	if(newRPos>12) newRPos %= 12;
	if(newRPos<=0) newRPos += 12;
	
	//printf("%i %c %i -> %i\n",oPos,ttype,bhvr,newRPos);
	return newRPos;
}

struct Node{
	int to, w, rPos;
	Node(int a, int b, int r){
		to = a;
		w  = b;
		rPos = r;
	}
	Node(){};
	
	bool operator < (const Node &n) const{
		return w > n.w;
	}
};

int main(){

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}

	int rNum, cNum, tNum, start, ringPos, tsRoom, openPos;
	while(~scanf("%i%i%i%i%i%i%i",&rNum, &cNum, &tNum, &start, &ringPos, &tsRoom, &openPos)){
		bool ved[rNum+1][13];	//12 poosible states from 1 - 12;
		int trapN[rNum+1];
		char trapType[rNum+1];	// 0 - not trap, +, -, x, = 
		
		//Init
		memset(ved,false,sizeof(ved));
		memset(trapType,'0',sizeof(trapType));
		
		vector < vector<Node> > tribute;
		tribute.assign(rNum+2, vector<Node>());
		
		//Edges
		while(cNum--){
			int u, v, length;
			scanf("%i%i%i",&u,&v,&length);
			tribute[u].push_back( Node(v, length, 0) );
			tribute[v].push_back( Node(u, length, 0) );
		}
		
		//Traps
		while(tNum--){
			char type;
			int room, n;
			scanf("%i %c %i",&room,&type,&n);
			trapType[room] = type;
			trapN[room] = n;
		}
		
		int i;
		int tsDist = oo;	//treasureDist
		priority_queue<Node> dijk;
		
		if(start==tsRoom && ringPos == openPos)
			tsDist = 0;
		else
			dijk.push( Node(start,0,ringPos) );
		while(!dijk.empty()){
			Node top = dijk.top();
			dijk.pop();
			
			if(ved[top.to][top.rPos]) continue;
			ved[top.to][top.rPos] = true;
			
			for(i=0;i<tribute[top.to].size(); i++){
				Node nxtNode = tribute[top.to][i];
				int nxtNum = nxtNode.to;
				
				int newRPos = calRing( top.rPos, trapType[nxtNum], trapN[nxtNum]);
				if(nxtNum==tsRoom && newRPos==openPos)
					tsDist = min( tsDist, top.w + nxtNode.w);
				else
					dijk.push( Node( nxtNum, top.w+nxtNode.w, newRPos ) );
			}
		}
		
		if(tsDist>=oo)
			puts("Pray!");
		else
			printf("%i\n",tsDist);
	}

	return 0;
}
