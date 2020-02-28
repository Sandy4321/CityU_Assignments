/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <complex>
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

#define eps 1e-6
using namespace std;

int T;


// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 
   
#include <stdio.h> 
#include <limits.h> 
   
// Number of vertices in the graph 
// #define V 9 
   
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[],int n) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < n; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
        min = dist[v], min_index = v; 
   
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
int dijkstra(int graph[][200], int src,int n) 
{ 

	// from(i,0,n){
	// 		from(j,0,n){
	// 			cout << graph[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
     int dist[n];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < n; i++) 
        dist[i] = INF2, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < n-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet,n); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 0; v < n; v++){

         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 

		//  cout << (!sptSet[v] && graph[u][v])<<endl;
		//  cout << ( dist[u] != INF2 &&max( dist[u], graph[u][v]) < dist[v] )<< endl;
         if (!sptSet[v] && graph[u][v] && dist[u] != INF2  
                                       &&max( dist[u], graph[u][v]) < dist[v]){
			dist[v] = max(graph[u][v],dist[u]);
		}
            // dist[v] = dist[u] + graph[u][v];
		// if (dist[u] == INT_MAX){

		// }
	   }
	// from(i,0,n){
	// 	cout << dist[i] << " ";
	// }
	// cout << endl;
     } 
	return dist[1];
     // print the constructed distance array 
    //  printSolution(dist, V); 
} 
   

struct Point{
	int x;
	int y;
};
int squaredDistance(Point a, Point b){
	return (a.x-b.x) *(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}



void mainFunction()
{
	// int s[200][200];
	Point nodes[200];
	// Path allPaths[40000];
	int n;
	// Path mst[200][199];
	// int mstLen[200];
	// int unionSet[200];
	int x,y;
	// bool visited[200];
	int graph[200][200];
	T =1;
	while(1){
		input(n);
		if (n==0){
			break;
		}

		// memset(s,-1,sizeof s);



		// complex <int > node;
		Point node;
		
		// memset(mst,complex<int>(-1,0),sizeof mst);
		// memset(unionSet,-1,sizeof unionSet);
		// memset(mstLen, 0 ,sizeof mstLen);
		// int pC = 0;
		from(i,0,n){
			
			input(x);
			input(y);
			node.x = x;
			node.y = y;
			// mst[i].clear();
			
			nodes[i] = node;
			from(j,0,i){
				int pathLen = squaredDistance(nodes[j],nodes[i]);
				graph[i][j] = squaredDistance(nodes[j],nodes[i]);
				graph[j][i] = squaredDistance(nodes[j],nodes[i]);
				// allPaths[pC++] =Path(j,i,pathLen);
			}
		}

		


		/* Let us create the example graph discussed above */
		// int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
		// 					{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
		// 					{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
		// 					{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
		// 					{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
		// 					{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
		// 					{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
		// 					{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
		// 					{0, 0, 2, 0, 0, 0, 6, 7, 0} 
		// 					}; 
		
			// ; 



		printf("Scenario #%d\nFrog Distance = %.3f\n\n",T++,sqrt(dijkstra(graph, 0,n)));


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

