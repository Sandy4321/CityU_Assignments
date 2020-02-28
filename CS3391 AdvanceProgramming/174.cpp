
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

#define eps 1e-6

using namespace std;

// Number of vertices in the graph
// #define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[][2], bool sptSet[], int n)
{
	// Initialize min value
	int min = INF, min_index;

	for (int v = 0; v < n; v++)
		if (sptSet[v] == false && dist[v][0] <= min)
			min = dist[v][0], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
// int printSolution(int dist[], int n)
// {
//    printf("Vertex   Distance from Source\n");
//    for (int i = 0; i < V; i++)
//       printf("%d tt %d\n", i, dist[i]);
// }

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[][1000], int src, int n, int dist[][2])
{

	// sfrom(i,0,n){
	// 		from(j,0,n){
	// 			cout << graph[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	//  int dist[n][2];
	// The output array.  dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < n; i++)
		dist[i][0] = INF, dist[i][1] = -1, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src][0] = 0;
	dist[src][1] = src;

	// Find shortest path for all vertices
	for (int count = 0; count < n - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet, n);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < n; v++)
		{

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]

			//  cout << (!sptSet[v] && graph[u][v])<<endl;
			//  cout << ( dist[u] != INF2 &&max( dist[u], graph[u][v]) < dist[v] )<< endl;
			if (!sptSet[v] && graph[u][v] != -1 && dist[u][0] != INF && dist[u][0] + graph[u][v] < dist[v][0])
			{
				dist[v][0] = dist[u][0] + graph[u][v];
				dist[v][1] = u;
			}
			// dist[v] = dist[u] + graph[u][v];
			// if (dist[u] == INT_MAX){

			// }
		}
		// from(i,0,n){
		// 	cout << dist[i][0] << " ";
		// 	cout << dist[i][1] << "  ";
		// }
		// cout << endl;
	}
	// res = dist;s
	// print the constructed distance array
	//  printSolution(dist, V);
}

int getPath(int graph[][1000], int start, int end, int n)
{

	int dist[1000][2];
	dijkstra(graph, start, n, dist);

	vector<int> res;
	int idx = end;
	// res.push_back(idx);
	while (dist[idx][1] != start)
	{
		idx = dist[idx][1];
		res.push_back(idx);
	}
	res.push_back(start);

	while (!res.empty())
	{
		printf("%d-->", res.back() + 1);
		res.pop_back();
	}
	printf("%d\n", end + 1);

	// printf("abc\n");
	return dist[end][0];
}

int T;

void mainFunction()
{
	input(T);
	char s[10000];
	int graph[1000][1000];
	int b[1000];
	gets(s);
	gets(s);
	while (T--)
	{
		// cout << "wtf?"<<endl;
		gets(s);
		stringstream ss1(s);

		// istringstream ss(s);

		int n = 0;
		int temp;

		while (ss1 >> graph[0][n])
		{
			n++;
		}
		from(i, 1, n)
		{
			from(j, 0, n)
			{
				input(graph[i][j]);
			}
		}

		from(i, 0, n)
		{
			input(b[i]);
			// update graph
			// A -> B + cost of A;
			// A -> C + cost of A;
			from(j, 0, n)
			{
				if (j != i && graph[i][j] != -1)
				{
					graph[i][j] += b[i];
				}
			}
		}

		// from(i,0,n){
		// 	cout << b[i] << endl;
		// }

		gets(s);
		int start, end;
		gets(s);
		// if (strlen(s) == 0 ){
		// 	continue;
		// }
		stringstream ss(s);
		ss >> start;
		ss >> end;
		start--;
		end--;

		// do something
		// then print result in form
		printf(
			"From %d to %d :\nPath: ",
			start + 1, end + 1);
		int cost;
		if (start == end)
		{
			printf("%d\n", start + 1);
			cost = 0;
		}
		else
		{
			cost = getPath(graph, start, end, n) - b[start];
		}
		// TOOD: print path

		printf(
			"Total cost : %d\n",
			cost);
		while (gets(s) && strlen(s))
		{
			// cout << s;
			stringstream ss(s);
			ss >> start;
			ss >> end;
			start--;
			end--;
			// do something
			// then print result in form
			printf(
				"\nFrom %d to %d :\nPath: ",
				start + 1, end + 1);

			// TOOD: print path
			if (start == end)
			{
				printf("%d\n", start + 1);
				cost = 0;
			}
			else
			{
				cost = getPath(graph, start, end, n) - b[start];
			}

			printf(
				"Total cost : %d\n",
				cost);
		}

		if (T)
		{
			lnBrk();
		}

		// from(i,0,n){
		// 	from(j,0,n){
		// 		output(graph[i][j]);
		// 		outputs(" ");
		// 	}
		// 	lnBrk();
		// }

		// ideally you only want to pass each edge once!
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
