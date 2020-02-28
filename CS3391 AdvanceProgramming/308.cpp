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

#define input(x) scanf("%d",&x)
#define inputc(x) scanf("%c",&x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)


int T;
int n;
int keys[500][4];
int k;
struct Edge{
	int a,b,w;
}e[124750];

int diff[10][10] = { 
	{0,1,2,3,4,5,4,3,2,1},
	{1,0,1,2,3,4,5,4,3,2},
	{2,1,0,1,2,3,4,5,4,3},
	{3,2,1,0,1,2,3,4,5,4},
	{4,3,2,1,0,1,2,3,4,5},
	{5,4,3,2,1,0,1,2,3,4},
	{4,5,4,3,2,1,0,1,2,3},
	{3,4,5,4,3,2,1,0,1,2},
	{2,3,4,5,4,3,2,1,0,1},
	{1,2,3,4,5,4,3,2,1,0}};

int diffOf(int a, int b){
	return diff[keys[a][0]][keys[b][0]]+ diff[keys[a][1]][keys[b][1]]+diff[keys[a][2]][keys[b][2]]+diff[keys[a][3]][keys[b][3]];
}

int cmpFunc(const void* a,const void* b){
	return ((Edge *)a)->w > ((Edge*)b)->w;
}

int disjointSet[500];

void unionAtoB(int idxA, int idxB){
	disjointSet[idxA] = idxB;
}

int root(int a){
	if (disjointSet[a] == a){
		return a;
	}else
	{
		return disjointSet[a] = root(disjointSet[a]);
	}
}

int buildMST(){
	from(i,0,n){
		disjointSet[i] = i;
	}

	int	count =0;
	int total =0;
	from(i,0,k){
		
		int idxA = root(e[i].a);
		int idxB = root(e[i].b);
		

		if (idxA != idxB){
			unionAtoB(idxA,idxB);
			total += e[i].w;
			count++;
			if (count == n-1){
				break;
			}
		}
		
	}
	return total;

}

void mainFunction()
{
    /**
     * Talk about improvements,
     *      can add binary search
     */
	input(T);
	char c;
	int starter[500];

	while(T--){
		input(n);
		getchar_unlocked();
		from(i,0,n){
			keys[i][0] = getchar_unlocked() -'0';
			keys[i][1] = getchar_unlocked() -'0';
			keys[i][2] = getchar_unlocked() -'0';
			keys[i][3] = getchar_unlocked() -'0';
			getchar_unlocked();
		}

		// create edges
		k=0;
		from(i,0,n){
			from(j,i+1,n){
				e[k].a=i;
				e[k].b=j;
				e[k++].w=diffOf(i,j);
			}
		}

		// sort all edges
		qsort(e,k,sizeof(Edge),cmpFunc);

		// build minimum spanning tree
		int minStarter = 20;
		from(i,0,n){
			minStarter = std::min(minStarter,diff[0][keys[i][0]]+ diff[0][keys[i][1]]+diff[0][keys[i][2]]+diff[0][keys[i][3]]);
		}


		output(buildMST()+minStarter);


		lnBrk();
	}
	


}

int main()
{

	// if (getenv("vscode") != NULL)
	// {
	// 	freopen("in.txt", "r", stdin);
	// }
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

