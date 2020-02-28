
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
#define ll long long
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

double cross(double cx, double cy, double x1, double y1,double x2, double y2){
	return (x1-cx)*(y2-cy) - (y1-cy)*(x2-cx);
}
map<ull,int> temp;

int r(ull k){
	if (temp.find(k) == temp.end()){
		int tempD = r( k % 2 == 0 ? k >> 1 : k *3+1 ) + 1;
		temp.insert(pair <ull,int>(k,tempD));
		return tempD;
	}else{
		return temp.find(k)->second;
	}
}

int T;
void mainFunction()
{
		temp.insert(pair <ull,int>(1,3));
		temp.insert(pair <ull,int>(2,3));
		temp.insert(pair <ull,int>(4,3));
	ull u ,l;
	while(cin>>u >>l && !(u==0 && l==0) ){
		if (u>l){
			swap(u,l);
		}
		int maxi = 0;
		ull maxiIndex=  0;
		for(ull i = u ; i <=l ; i++){
			// cout <<  i << endl;
			if (maxi < r(i)){
				maxiIndex= i;
				maxi = r(i);
			}
		}
		if (maxiIndex == 1 || maxiIndex == 2 || maxiIndex == 4){
			cout << "Between "<<u<<" and "<<l<<", "<<maxiIndex<<" generates the longest sequence of "<<maxi<<" values.\n";
		}else{
			cout << "Between "<<u<<" and "<<l<<", "<<maxiIndex<<" generates the longest sequence of "<<maxi-1<<" values.\n";
		}
	}

}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w",stdout);
	}
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

