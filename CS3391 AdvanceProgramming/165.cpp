/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <complex>
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



struct Path{
	int p1;
	int p2;
	int length;
	Path(){}
	Path(int p1,int p2, int length):p1(p1),p2(p2),length(length){}
	// bool operator< (const Path& b){
	// 	return length > b.length;
	// }
};

struct Point{
	int x;
	int y;
};
double squaredDistance(Point a, Point b){
	return (a.x-b.x) *(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool sorter(Path a, Path b){
	// _(a.length);
	// $(b.length);
	return a.length < b.length;
}

int getRoot(int unionSet[],int node){
	if (unionSet[node] == -1){
		return node;
	}else{
		return unionSet[node] = getRoot(unionSet,unionSet[node]);
	}
}

int findMinDistanceTo(Path mst[][199],int mstLen[],bool visited[],int start,int end){

	// _(start);
	// $(end);
	visited[start] = true;

	int maxL = -1;
	from(i,0,mstLen[start]){
		int otherIndex = mst[start][i].p1==start?mst[start][i].p2:mst[start][i].p1;
		if (!visited[otherIndex]){
			if (otherIndex == end){
				return mst[start][i].length;
			}else{
				int distanceToStart =findMinDistanceTo(mst,mstLen,visited,otherIndex,end);
				if (distanceToStart != -1){
					maxL = max(mst[start][i].length,distanceToStart);
				}
			}
		}
	}
	return maxL;

}


void mainFunction()
{
	// int s[200][200];
	Point nodes[200];
	Path allPaths[40000];
	int n;
	Path mst[200][199];
	int mstLen[200];
	int unionSet[200];
	int x,y;
	bool visited[200];
	T =1;
	while(1){
		input(n);
		if (n==0){
			break;
		}

		// memset(s,-1,sizeof s);



		// complex <int > node;
		Point node;

		// memset(mst,complex<int>(-1,0),sizeof mst);
		memset(unionSet,-1,sizeof unionSet);
		memset(mstLen, 0 ,sizeof mstLen);
		int pC = 0;
		from(i,0,n){
			
			input(nodes[i].x);
			input(nodes[i].y);
			// node.x = x;
			// node.y = y;
			// mst[i].clear();
			
			// nodes.push_back(node);
			from(j,0,i){
				allPaths[pC++] =Path(j,i,squaredDistance(nodes[j],nodes[i]));
			}
		}
		// from(i,0,allPaths.size()){
		// 	_(allPaths[i].p1);
		// 	_(allPaths[i].p2);
		// 	$(allPaths[i].length);
		// }
		// _(allPaths.max_size());
		sort(allPaths,allPaths+pC,sorter);
		
		// sort(soRandom.begin(),soRandom.end(),sorter);
		int connected = 0;
		from(i,0,pC){
			Path p = allPaths[i];
			// _(p.p1);
			// _(p.p2);
			// _(getRoot(unionSet,p.p1));
			// $(getRoot(unionSet,p.p2));

			int r1 =getRoot(unionSet,p.p1);
			int r2 =getRoot(unionSet,p.p2);
			if ( r1 != r2 ) {
				connected ++;
				unionSet[r2] = r1;
				mst[p.p1][mstLen[p.p1]++]=p;
				mst[p.p2][mstLen[p.p2]++]=p;
				// 	from(j,0,n){
				// 	cout << j <<":"<<unionSet[j] << " ";
				// }
				// cout << endl;

				if (connected == n-1){
					break;
				}
			}
			
		};

		// from(i,0,n){
		// 	$(i);
		// 	from(j,0,mst[i].size()){
		// 		_(mst[i][j].p1);
		// 		_(mst[i][j].p2);
		// 		$(mst[i][j].length);
		// 	}
		// }

		memset(visited,false, sizeof visited);
		
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",T++,sqrt(findMinDistanceTo(mst,mstLen,visited,1,0)));


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

