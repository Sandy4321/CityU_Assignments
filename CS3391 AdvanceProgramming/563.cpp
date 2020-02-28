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
#define inputd(x) scanf("%lf", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

int T;

struct Network
{
	struct Edge
	{
		int to;
		int pre_edge;
		int cap;
		int flow;
	};

#define MAXNODE 700
	int last[MAXNODE];

	int nv; // total number of vertex, index range: [0, nv)
	vector<Edge> edge;
	void init(int _nv)
	{
		nv = _nv;
		edge.clear();
		fill(last, last + nv, -1);
	}

	void add_e(int x, int y, int cap, int r_cap = 0)
	{
		Edge e = {y, last[x], cap, 0};
		// Edge e{y, last[x], cap, 0};
		last[x] = edge.size();
		// edge.push_back(move(e));
		edge.push_back(e);

		Edge r_e = {x, last[y], r_cap, 0};
		// Edge r_e{x, last[y], r_cap, 0};
		last[y] = edge.size();
		// edge.push_back(move(r_e));
		edge.push_back(r_e);
	}
	void show_edge()
	{
		for (int i = 0; i < nv; i++)
		{
			printf("v [%d]:", i);
			for (int ie = last[i]; ie != -1;)
			{
				const Edge &e = edge[ie];
				ie = e.pre_edge;
				printf(" [%d]%d/%d", e.to, e.flow, e.cap);
			}
			printf("\n");
		}
		printf("\n");
	}

	//
	// maximum flow
	// dinic O(V * V * E)
	int lv[MAXNODE];
	bool mark_level(int start, int end)
	{
		fill(lv, lv + MAXNODE, -1);
		queue<int> q;
		lv[start] = 0;
		q.push(start);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int ie = last[cur]; ie != -1;)
			{
				const Edge &e = edge[ie];
				ie = e.pre_edge;
				if (e.cap != e.flow && lv[e.to] == -1)
				{
					lv[e.to] = lv[cur] + 1;
					q.push(e.to);
				}
			}
		}
		return lv[end] != -1;
	}
	void show_lv()
	{
		for (int i = 0; i < nv; i++)
		{
			printf("lv[%d] = %d\n", i, lv[i]);
		}
	}
	int augment(int cur, int end, int min_flow)
	{
		if (cur == end)
			return min_flow;

		int augmented_flow = 0;
		for (int ie = last[cur]; ie != -1;)
		{
			Edge &e = edge[ie];
			Edge &re = edge[ie ^ 1];
			ie = e.pre_edge;
			if (lv[e.to] == lv[cur] + 1 &&
				e.cap > e.flow &&
				(augmented_flow = augment(e.to, end, min(e.cap - e.flow, min_flow))))
			{
				e.flow += augmented_flow;
				re.flow -= augmented_flow;
				return augmented_flow;
			}
		}
		return 0;
	}
	int dinic(int start, int end)
	{
		int total_flow = 0;
		int flow = 0;
		while (mark_level(start, end))					// update level
			while ((flow = augment(start, end, INT_MAX))) // eat up all augmented flow
				total_flow += flow;
		return total_flow;
	}
	// end of
	// maximum flow - dinic
	//
};

bool within(double x1, double y1, double r1, double x2, double y2, double r2)
{
	double x = x1 - x2;
	double y = y1 - y2;
	return x * x + y * y < (r1 + r2) * (r1 + r2);
}

void mainFunction()
{
	input(T);
	int n;
	Network net;
	double pads[301][4];
	double src[4], tar[4];
	while (T--)
	{
		input(n);
		net.init((n-1)*2);
		from(i, 0, n)
		{
			inputd(pads[i][0]);
			inputd(pads[i][1]);
			inputd(pads[i][2]);
			inputd(pads[i][3]);

			if (pads[i][0] == 400)
			{
				src[0] = pads[i][0];
				src[1] = pads[i][1];
				src[2] = pads[i][2];
				src[3] = pads[i][3];
				i--;
				n--;
			}
			else if (pads[i][0] == 789)
			{
				tar[0] = pads[i][0];
				tar[1] = pads[i][1];
				tar[2] = pads[i][2];
				tar[3] = pads[i][3];
				i--;
				n--;
			}
		}

		// preprocessing
		/**
		Directional A.in -> A.out 
		if B to A
			B.out -> A.in
		else if A to B
			A.out -> B.in
		we put 
		<1.in,1.out,2.in,2.out ,... , src.out , tar.in>
		So:
			1. add A.in -> A.out
		 **/

		from(i, 0, n )
		{
			// put a.in -> a.out
			net.add_e(i * 2, i * 2 + 1, 1);

			// if this node is connect to source?
			if (within(
					src[1], src[2], src[3],
					pads[i][1], pads[i][2], pads[i][3]))
			{
				// from source to node
				// source.out -> a.in
				net.add_e(n * 2, i * 2, 1);
			}
			// if  this node is connected to tar
			if (within(
					tar[1], tar[2], tar[3],
					pads[i][1], pads[i][2], pads[i][3]))
			{
				// from node to tar
				// node.out -> tar.in
				net.add_e( i * 2 + 1,n * 2 + 1, 1);
			}

			// this node to all other node
			// if pad A < B make connection
			from(j, 0, n)
			{
				if (
					j != i && 
					pads[i][0] < pads[j][0] && 
					within(
						pads[i][1], pads[i][2], pads[i][3], 
						pads[j][1], pads[j][2], pads[j][3]))
				{
					// A.out -> B.in
					net.add_e(i*2+1, j*2, 1);
				}
			}
		}
		// net.show_edge();

		if (within(
			src[1], src[2], src[3], 
			tar[1], tar[2], tar[3]))
		{
			outputs("Game is VALID\n");
		}
		else
		{
			// output(net.dinic(src,tar));
			// // net.show_edge();
			// output(net.dinic(src,tar));
			// net.show_edge();
			if (net.dinic(n*2, n * 2 + 1) >= 2)
			{
				outputs("Game is VALID\n");
			}
			else
			{
				outputs("Game is NOT VALID\n");
			}
		}
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
