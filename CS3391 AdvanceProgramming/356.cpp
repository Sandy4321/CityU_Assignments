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

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

int n, m;
struct Edge
{
	int a, b;
} e[1000000];

int disjointSet[501];
int maxRoot = 0;

int root(int a)
{
	// _(a);

	if (disjointSet[a] < 0)
	{
		return a;
	}
	else
	{
		return disjointSet[a] = root(disjointSet[a]);
	}
}

void unionSet(int a, int b)
{
	// if (disjointSet[a] == a){
	// 	disjointSet[a] = b;
	// 	return b;
	// }else{
	// 	return disjointSet[a] = unionSet(disjointSet[a],b);
	// }

	int rootA = root(a);
	int rootB = root(b);
	if (rootA != rootB)
	{
		disjointSet[rootB] += disjointSet[rootA];
		disjointSet[rootA] = rootB;
		if (maxRoot > disjointSet[rootB])
		{
			maxRoot = disjointSet[rootB];
		}
	}
}

void mainFunction()
{
	/**
     * Talk about improvements,
     *      can add binary search
     */

	input(n);
	input(m);
	int maxW = -1;
	int a, b, w = 0;
	int currentIdx = -1;
	while (n != 0)
	{
		maxW = INT_MIN;
		maxRoot = 0;
		from(i, 0, m)
		{
			input(a);
			input(b);
			input(w);
			if (w > maxW)
			{
				maxW = w;
				currentIdx = 0;
				e[currentIdx].a = a;
				e[currentIdx++].b = b;
			}
			else if (w == maxW)
			{
				e[currentIdx].a = a;
				e[currentIdx++].b = b;
			}
		}

		n++;
		memset(disjointSet, -1, sizeof(disjointSet));
		// from(i,1,n){
		// 	// disjo
		// }
		from(i, 0, currentIdx)
		{
			// _(e[i].a);
			// _(disjointSet[e[i].a]);
			// _(e[i].b);
			// _(disjointSet[e[i].b]);
			unionSet(e[i].a, e[i].b);
		}

		output(maxRoot * -1);
		lnBrk();

		input(n);
		input(m);
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

/*
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
0 0
*/