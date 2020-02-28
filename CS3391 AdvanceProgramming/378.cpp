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

struct Node{
	int weight;
	int to;
	int maxi;
	int mini;
	bool operator < (const Node &other)const{
		return weight > other.weight;
	}
};

void mainFunction()
{
	int maxDiff, n;
	int p,l,x;
	int t,v;

	vector< vector<Node> > graph;
	while(~input(maxDiff)){
		input(n);
		int cosToFinal[101];
		int monsterLevel[101];

		graph.clear();


		from(i,0,n+4){
			graph.push_back(vector<Node>());
		}

		from(i,1,n+1){
			input(p);
			input(l);
			input(x);
			monsterLevel[i] = l;
			Node newN = {p,i,l,l};
			graph[0].push_back(newN);

			from(j,0,x){
				input(t);
				input(v);
				Node thisMon = {v,i,monsterLevel[1],monsterLevel[1]};
				graph[t].push_back(thisMon);
			}
		}

		from(i,1,n+1){
			cosToFinal[i] = INF;
		}
		cosToFinal[0] = 0;
		monsterLevel[0] = monsterLevel[1];

		// from(i,0,n+1){
		// 	from(j,0,graph[i].size()){
		// 		cout << graph[i][j].weight << " "<< graph[i][j].to << " "<< graph[i][j].maxi << " "<< graph[i][j].mini << " "<<endl;
		// 	}
		// 	// _(monsterLevel[i]);
		// }

		priority_queue<Node> dijkstra;
		Node newN = {0,0,monsterLevel[1],monsterLevel[1]};
		dijkstra.push(newN);
		while (!dijkstra.empty())
		{
			Node tmp = dijkstra.top();
			dijkstra.pop();
			// cout << tmp.weight << " "<< tmp.to << " "<< tmp.maxi << " "<< tmp.mini << " "<<endl;
			from(i,0,graph[tmp.to].size()){
				int destination = graph[tmp.to][i].to;
				int lvl = monsterLevel[destination];

				if ( tmp.weight + graph[tmp.to][i].weight <cosToFinal[destination]  and 
					 maxDiff >= fabs(tmp.maxi - lvl ) and
					 maxDiff >= fabs(tmp.mini - lvl)
				){
					cosToFinal[destination] = tmp.weight + graph[tmp.to][i].weight;
					Node newNewN = {cosToFinal[destination],destination,max(lvl,tmp.maxi),min(lvl,tmp.mini)};
					dijkstra.push(
						newNewN
					);
				}

			}

		}
		output(cosToFinal[1]);
		lnBrk();
		

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

