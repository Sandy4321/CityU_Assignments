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

int T;
int n, m;

struct Edge
{
	int u, v, w;
	bool selected;
} e[25000];

int disjointSet[1000];

int root(int a)
{
	if (a == disjointSet[a])
	{
		return a;
	}
	else
	{
		return disjointSet[a] = root(disjointSet[a]);
	}
}

void unionAtoB(int idxA, int idxB)
{
	disjointSet[idxA] = idxB;
}

int buildMST()
{
	from(i, 0, n)
	{
		disjointSet[i] = i;
	}

	int count = 0;
	int total = 0;
	from(i, 0, m)
	{
		int rootA = root(e[i].u);
		int rootB = root(e[i].v);
		if (rootA != rootB)
		{
			unionAtoB(rootA, rootB);
			count++;
			total += e[i].w;
			e[i].selected = 1;
			if (count == n - 1)
			{
				break;
			}
		}
	}

	if (count < n - 1)
	{
		return -1;
	}
	else
	{
		return total;
	}
}

int cmpFunc(const void *a, const void *b)
{
	return ((Edge *)a)->w > ((Edge *)b)->w;
}

void mainFunction()
{
	/**
     * Talk about improvements,
     *      
     */
	input(n);
	input(m);
	while (n != 0)
	{
		from(i, 0, m)
		{
			input(e[i].u);
			input(e[i].v);
			input(e[i].w);
			e[i].selected = 0;
		}

		qsort(e, m, sizeof(Edge), cmpFunc);

		int total = buildMST();
		bool findFirst = false;
		if (total > 0)
		{
			outputs("Min cost: ");
			output(total);
			lnBrk();
			from(i, 0, m)
			{
				if (!findFirst)
				{
					if (!e[i].selected)
					{
						output(e[i].w);
						findFirst = true;
					}
				}
				else
				{
					if (!e[i].selected)
					{
						outputs(" ");
						output(e[i].w);
					}
				}
			}
			lnBrk();
		}
		else
		{
			outputs("\\(^o^)/ pray to god");
			lnBrk();
		}

		input(n);
		input(m);
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
