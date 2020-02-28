/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include <iostream>
#define _(x) {std::cout << #x << " = " << x << " ";}

#define from(i, x, y) for (int i = x; i < y; ++i)
using namespace std;

#define oo 2e9

struct Node{
	int to, w;
	int high, low;
	Node(int a, int b, int h, int l){
		to = a;
		w  = b;
		high = h;
		low = l;
	}
	Node(){};
	bool operator < (const Node &n) const{
		return w > n.w;
	}
};

int main(){
	int maxDiff, n;
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	while(~scanf("%i %i",&maxDiff, &n)){
		int costs[101];
		int lvls[101];

		vector< vector<Node> > monMap;
		monMap.assign(n+3, vector<Node>());

		int i,j;

		for(i=1; i<=n; i++){
			int cost, lv, ruleNum;
			scanf("%i %i %i",&cost, &lv, &ruleNum);
			lvls[i] = lv;
			monMap[0].push_back( Node(i, cost, lv, lv ));

			for(j=0; j<ruleNum; j++){
				int mont, tranCost;
				scanf("%i %i",&mont, &tranCost);
				monMap[mont].push_back( Node(i, tranCost, lvls[1], lvls[1]) );
			}
		}

		for(i=1;i<=n;i++)
			costs[i] = oo;
		costs[0] = 0;

		lvls[0] = lvls[1];
		from(i,0,n+1){
			from(j,0,monMap[i].size()){
				cout << monMap[i][j].w << " "<< monMap[i][j].to << " "<< monMap[i][j].high << " "<< monMap[i][j].low << " "<<endl;
			}
			// cout << lvls[i] << " "<<endl;
		}

		priority_queue<Node> dijk;
		dijk.push(Node(0,0,lvls[0],lvls[0]));
		while(!dijk.empty()){
			Node r = dijk.top();
			dijk.pop();
			cout << r.w << " "<< r.to << " "<< r.high << " "<< r.low << " "<<endl;

			for(i=0; i<monMap[r.to].size(); i++){
				int myI = monMap[r.to][i].to;
				int lvl = lvls[myI];

				if( costs[ myI ] > r.w + monMap[r.to][i].w &&
					abs(r.high-lvl)<=maxDiff && abs(r.low-lvl)<=maxDiff
				){
					costs[ myI ] = r.w + monMap[r.to][i].w;
					dijk.push( Node( myI, costs[myI], max(r.high,lvl), min(r.low,lvl) ) );
				}
			}
		}
		printf("%i\n",costs[1]);
	}

	return 0;
}
