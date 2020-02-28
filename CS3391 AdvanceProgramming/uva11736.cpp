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
#define $(x)                                     \
	{                                            \
		if (DUBUG)                               \
			std::cout << #x << " = " << x << " " \
					  << "\n";                   \
	}
#define _(x)                                      \
	{                                             \
		if (DUBUG)                                \
			std::cout << #x << " = " << x << " "; \
	}

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)
#define foreach(i, n) for (int i = 0; i < n; ++i)

#define eps 1e-6

using namespace std;

double cross(double cx, double cy, double x1, double y1, double x2, double y2)
{
	return (x1 - cx) * (y2 - cy) - (y1 - cy) * (x2 - cx);
}

int T;

void mainFunction()
{
	int b, v;
	int o[201];
	map <string,ull> mp;
	string s[201],stemp;
	ull val[201];
	char c;
	int t;
	while (~input(b))
	{
		mp.clear();
		input(v);
		from (i,0,v)
		{
			cin >> s[i] >> o[i];
		}

		from(i,0,v){
			ull newVal = 0;
			from(j,0,o[i]){
				from(k,0,b){
					cin >>c;
					newVal <<= 1;
					if (c == '1'){
						newVal ++;
					}
				}
			}
			// cout << newVal << endl;
			mp[s[i]] = newVal;
		}

		input(t);
		from(i,0,t){
			cin >> stemp;
			cout << stemp << "=";
			if (mp.find(stemp) != mp.end()){
				cout << (*mp.find(stemp)).second;
			}
			cout << endl;
		}

	}
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}
