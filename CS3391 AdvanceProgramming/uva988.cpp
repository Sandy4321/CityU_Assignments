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
	vector<int >childs;
	int numberOfWays;
}nodes [100000];

int T;

int dfs(Node& n){
	if (n.numberOfWays != -1){
		return n.numberOfWays;
	}else{
		if (n.childs.empty()){
			n.numberOfWays = 1;
			return 1;
		}else{
			int aggregate = 0;
			for(auto v : n.childs){
				aggregate += dfs(nodes[v]);
			}
			n.numberOfWays = aggregate;
			return n.numberOfWays;
		}
	}
}

void mainFunction()
{
	int n,c;
	bool first = true;
	while (
		~input (T)
	){
		assert(T < 100000);
		for(int i = 0 ;i  <T ; i++){
			nodes[i].childs.clear();
			nodes[i].numberOfWays = -1;

			input(n);

			from(j,0,n){
				input(c);
				nodes[i].childs.push_back(c);
			}
		}

		if (!first){
			lnBrk();	
		}else{
			first = false;
		}

		output(dfs(nodes[0]));
		lnBrk();
	}


}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w",stdout);
	}
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

