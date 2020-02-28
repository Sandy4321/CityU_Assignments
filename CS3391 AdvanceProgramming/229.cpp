
/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 86347
 * Submitted at:  2019-05-09 07:18:26
 *
 * User ID:       554
 * Username:      54924670
 * Problem ID:    228
 * Problem Name:  Moliu Task
 */

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

#define input(x) scanf("%i",&x)
#define inputf(x) scanf("%lf",&x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define foreach(i, y) for (int i = 0; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

struct G{
	bool isCircle; // 0 :rect , 1: circle
	double w;
	double h;
	double fittingVal;
	int ind;
	set<int> parent;
	vector<G*> edgeOut; 
};
	bool setter[10002];

G gs[10002];


void printG(G g){
	if (g.isCircle){
		cout << "Cir : "<< g.w ;
	}else{
		cout << "Rect : " << g.w <<" "<<g.h ;
	}
	cout <<" " << g.ind << " Links to : (" << endl;

	from(i,0,g.edgeOut.size()){
		printG(*g.edgeOut[i]);
	}
	cout << ")";
}

int dp[10002];

int maxG(G &g){
	// cout << "hey?";
	if (dp[g.ind] != -1){
		return dp[g.ind];
	}
	int maxi = 0; 
	from(i,0,g.edgeOut.size()){
		maxi = max(maxi, maxG(*g.edgeOut[i]));
	}
	dp[g.ind] = maxi+1;
	return dp[g.ind];
}

int fitWithin(G &g1, G &g2){

	// if (g1.isCircle){
	// 	cout << "Cir : "<< g1.w ;
	// }else{
	// 	cout << "Rect : " << g1.w <<" "<<g1.h ;
	// }
	// cout << endl;

	// if (g2.isCircle){
	// 	cout << "Cir : "<< g2.w ;
	// }else{
	// 	cout << "Rect : " << g2.w <<" "<<g2.h ;
	// }
	// cout << endl;



	// circle cmp with circle
	if (g1.isCircle && g2.isCircle){
		if (g1.w > g2.w){
			return 1;
		}else if (g1.w < g2.w){
			return -1;
		}else{
			return 2;
		}
	}else if (
		(g1.isCircle && !g2.isCircle) || 
		(!g1.isCircle && g2.isCircle)){
		G* cir; G* rec;
		bool g1IsCircle = true;
		if (g1.isCircle){
			cir = &g1;
			rec = &g2;
		}else{
			cir = &g2;
			rec = &g1;
			g1IsCircle = false;
		}

		if (cir->fittingVal >= rec->fittingVal){
			return g1IsCircle? 1 : -1; // return circle
		}else if (cir->w <= rec->h){ // because rectangle is orient to w > h
			return g1IsCircle? -1 : 1; // return rectangle
		}else {
			return 0; // conflict
		}
	}else{
		// both rectangle
		if (g1.w > g2.w){
			// compare height
			// g1 needs to be larger than g2
			if (g1.h >= g2.h){
				return 1;
			}else{
				return 0; // coflict
			}
		}else if (g2.w > g1.w){
			if (g2.h >= g1.h){
				return -1;
			}else{
				return 0; // conflict
			}
		}else{
			if (g1.h > g2.h){
				return 1;
			}else if (g2.h > g1.h){
				return -1;
			}else{
				return 2;
			}
		}

	}

	// 2 g1 is the same as g2;
	// 0 conflict
	// 1 g1 into g2
	// -1 g2 into g1
}

bool parentHad(G &g, int newP,int layer){
	bool res = true;
	if (g.parent.find(newP) != g.parent.end()){
		return true;
	}
	layer += layer + 1;
	if (layer > 2){
		return false;
	}
	for(set<int>::iterator it = g.parent.begin() ; it != g.parent.end() ;it++){
		if (parentHad(gs[*it],newP,layer)){
			g.parent.insert(newP);
			return true;
		}
	}
	return false;
}

void goCheck(G &n1, G &n2 ){
	// cout << "Check Fit Within \n";
	int canFit = fitWithin(n1 ,n2);
	// cout << canFit << endl;
	if (canFit == 1){

		if (!parentHad(n2,n1.ind,0)){
			n1.edgeOut.push_back(&n2);
			n2.parent.insert(n1.ind);
		}
	}else if (canFit == -1){
		if (!parentHad(n1,n2.ind,0)){
			n2.edgeOut.push_back(&n1);
			n1.parent.insert(n2.ind);
		}
	}else if (canFit == 0){
	}else{ // same thing
		if (n1.ind > n2.ind){
			if (!parentHad(n2,n1.ind,0)){
			n1.edgeOut.push_back(&n2);
			n2.parent.insert(n1.ind);
		}
		}else{
			if (!parentHad(n1,n2.ind,0)){
			n2.edgeOut.push_back(&n1);
			n1.parent.insert(n2.ind);
		}
		}
	}
}
bool cmper(G g1, G g2){
	return g1.fittingVal > g2.fittingVal;
}
int g2000= 0;
void buildGraph(int curr){
	if (curr == 0 || setter[curr]){
		return;
	}

	setter[curr] = true;
	// check previous entry
	int previousParent = curr-1;
	
	while(previousParent >= 0){
		
	int previousEntryResult = fitWithin(gs[curr],gs[previousParent]);
	// cout << curr <<" " << previousParent << " " << previousEntryResult<< endl;

	if (previousEntryResult == -1 || previousEntryResult == 2){
		gs[previousParent].edgeOut.push_back(gs+curr);
	assert(g2000++ < 5000000);
		break;
	}else if (previousEntryResult == 0){
		buildGraph(previousParent);
		previousParent --;
	}
	// if larger than me 
	// if conflict 
		// call him to build Graph
		// then check previous entry of him
	}
	if (previousParent>0){
		buildGraph(previousParent);
	}
	// tick the bool;
}

int T;

void mainFunction()
{

	char typ;
	int ger = 0;
	// vector< vector<G> > graph;
	while(cin >> T){
g2000 = 0;
		// memset(dp,-1,sizeof dp);
		from(i,0,T+1){
			dp[i] = -1;
			setter[i] = false;
		}

		gs[0].isCircle=true;
		gs[0].fittingVal = (double)INF2;
		gs[0].w = INF*2;

		gs[0].edgeOut.clear();
		gs[0].parent.clear();
		// build graph

		from(i,1,T+1){
			cin >> typ;
			if (typ == 'C'){
				gs[i].isCircle = true;
				cin >> gs[i].w;
				gs[i].w *= 2;
				gs[i].fittingVal = (gs[i].w)*(gs[i].w);
			}else{
				gs[i].isCircle = false;
				cin >> gs[i].w;
				cin >> gs[i].h;
				if (gs[i].h > gs[i].w){
					swap(gs[i].w,gs[i].h);
				}
				gs[i].fittingVal = gs[i].w*gs[i].w + gs[i].h*gs[i].h;
			}
			gs[i].ind =i;
			gs[i].edgeOut.clear();
			gs[i].parent.clear();
			// push gs[i] into graph
			// from root search 
			
		}

		sort(gs,gs+T+1, cmper);

		buildGraph(T);

		// assert(ger++ != 20);

		fromNeg(i,T,0){
			if (!setter[i]){
				buildGraph(i);
				// from(j,i+1, T){
				// 	switch(fitWithin(gs[i],gs[j])){
				// 		case 1:
				// 			gs[i].edgeOut.push_back(gs+j);
				// 			break;
				// 	}
				// }
			}
		}
		// assert(ger++ != 20);

		// from(i,0,T+1){
		// 	from(j,i+1,T+1){
		// 		if (j == i){
		// 		}else{
		// 			goCheck(gs[i],gs[j]);
		// 		}
		// 	}
		// }
		// printG(gs[0]);

		// from(i,0,T+1){
		// 	if (gs[i].isCircle){
		// 		cout << "Cir ";
		// 	}else{
		// 		cout << "Rect ";
 		// 	}
		// 	cout << gs[i].fittingVal << endl;
		// }

		cout << maxG(gs[0]) -1 << endl;
		





	}


	/*

	3
	9
	10
	11
	10000
	50000
	*/
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	}
	std::ios_base::sync_with_stdio(false);
	// testCaseGenerator();
	mainFunction();
	return 0;
}