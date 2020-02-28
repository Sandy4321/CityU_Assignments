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
#define foreach(i,n) for (int i = 0 ;  i< n ; ++i)
#define eps 1e-6

using namespace std;

struct Node{
	int index;
	vector<int> friends;
};
int T;

int checker[201]; // -1 means not seen, 1 means seen assigned to A, 0 means seen assigned to B
Node nodes[200];
bool bico = true;
queue<int> q;

bool dfs(int next,bool requiredColour){
	bool opposite = !requiredColour;
	if (checker[next] == -1){
		checker[next] = requiredColour;// set to A
		for (auto d: nodes[next].friends){
			if  (!dfs(d,opposite )){
				return false;
			}
		}
		return true;
	}else if(
		(checker[next]== 1 && requiredColour == false) || 
		(checker[next] == 0 && requiredColour == true)
	) {
		return false;
	}else{
		return true;
	}
}

void mainFunction()
{
	int n,l;

	foreach(i,200){
		nodes[i].index = i;
	}
	while(input(n) && n != 0){
		bico = true;
		memset(checker,-1,sizeof checker);
		input(l);
		foreach(i,n){
			nodes[i].friends.clear();
		}
		
		int node1, node2;
		foreach(i,l){
			input(node1);
			input(node2);
			nodes[node1] .friends .push_back(node2);
			nodes[node2] .friends .push_back(node1);
		}

		foreach (i,n)
		{
			if(checker[i] == -1){
				if (!dfs(i,0)){
					bico = false;
					break;
				}
			}
		}

		// if A is true
		// 		then set its neigbour to false
		// 		if neighbour is setted 
		// 			bico = false; and exit;

		if (bico){
			outputs("BICOLORABLE.\n");
		}else{
			outputs("NOT BICOLORABLE.\n");
		}
	}

	
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen ("out.txt","w",stdout);
	}
	// testCaseGenerator();
	mainFunction();
	return 0;
}

