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

#define eps 1e-6

#define MAAX 220

using namespace std;


int T;


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
void dijkstra(int graph[][MAAX], int src, int n, int dist[][2],bool sptSet[])
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

	// bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
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
			if (!sptSet[v] && graph[u][v] != INF && dist[u][0] != INF && dist[u][0] + graph[u][v] < dist[v][0])
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


void getPath(int graph[][MAAX], int start, int end, int n, string places[],int dist[][2],bool sptSet[])
{

	// int dist[200][2];

	dijkstra(graph, end, n, dist,sptSet);
	int res2 = dist[start][0];

	// from (i,0,n){
	// 	cout << dist[i][0] << " " << dist[i][1]<< endl;
	// }
	// cout << dist[end][0];
	vector<int> res;
	int idx = start;
	// res.push_back(idx);
	
	while (dist[idx][1] != end)
	{
		idx = dist[idx][1];
		res.push_back(idx);
	}
	res.push_back(end);
	
		// cout <<"Are you ok?" << endl;
	
	dijkstra(graph, start, n, dist,sptSet);
		// cout <<"Are you ok?" << endl;

	res2 += dist[end][0];

	// from (i,0,n){
	// 	cout << dist[i][0] << " " << dist[i][1]<< endl;
	// }
	// cout << dist[end][0];
	idx = end;
	// res.push_back(idx);
	while (dist[idx][1] != start)
	{
		idx = dist[idx][1];
		res.push_back(idx);
	}
	res.push_back(start);
	
	printf("%d\n",res2);
	
	
	while (!res.empty())
	{
		printf("%s -> ", places[res.back()].c_str());
		res.pop_back();
	}
	printf("%s\n\n", places[start].c_str());




	// return dist[end][0];
}
// bool compareString(char c1[],char c2[]){
// 	if (strlen(c1) !=){

// 	}

// }

int cstringLen(char c[]){
	int size =0;
	while (size < 50 && c[size] != '\0'){
		size++;
	}
	return size;
}

bool compareString(char c1[],char c2[]){
	int len = cstringLen(c1);

	if (len != cstringLen(c2)){
		return false;
	}else{
		from(i,0,len){	
			if(c1[i] != c2[i]){
				return false;
			}
		}
		return true;
	}
}

void mainFunction()
{
	int n;
	// char places[200][20];
	string places[MAAX];
	string places_no_spaces[MAAX];
	char s1[20];
	char s2[20];
	int d,d2;
	char wt[40];
	int graph[MAAX][MAAX];
	int officeIndex;
	int hallIndex;
	int dist[MAAX][2];
	bool sptSet[MAAX];
	char office[] ="office";
	char hall[] ="hall";
	while(cin >> n){

		string line;
		getline(cin, line);
		// cout << line<<endl;
		from(i,0,n){
			getline(cin, line);
			places[i] = line;
			// preprocess characters
			string places_without_space;
			from(j,0,line.length()){
				if (line[j] != ' ') {
					places_without_space +=line[j]; 
				}
			}
			places_no_spaces[i] = places_without_space;
			// gets(places[i]);
			if (places[i] == "office"){
				officeIndex = i;
			}else if (places[i] == "hall"){
				hallIndex = i;
			}
		}
		// // _(officeIndex);
		// // _(hallIndex);
		memset(graph,INF,sizeof graph);
		// from(i,0,n){
		// 	from(j,0,n){
		// 		graph[i][j] = INF;
		// 	}
		// }


		int p ;
		cin >> p;

		from(i,0,n){
			graph[i][i] =0; 
		}
		string tmp;
		getline(cin , tmp);
		int p1,p2;
		string source,dest,s_tmp;
		// gets(s1);
		from(i,0,p){
			bool singleLen = false;
			int fro = -1;
			int to = -1;
			char * ptr;
			getline(cin , tmp);

			from(j,0,tmp.length()){
				if(tmp[j] == ':'){
					source = tmp.substr(0,j);
					s_tmp = tmp.substr(j+1);
					break;
				}
			}

			stringstream ss(s_tmp);
			string s;
			string remaining [100];
			int t =0 ;
			while( ss >> s){
				remaining[t] =s;
				t++;
			}

			int guess;
			string ttt, ttt2;
			from(j,0,t-1){
				ttt += remaining[j];
			}
			from(j,0,n){
				if(places_no_spaces[j] == ttt){
					singleLen = true;
					guess = j;
					break;
				}
			}

			if (singleLen){
				dest = places[guess];
				fro = atoi (remaining[t-1].c_str());
			}else{
				from(j,0,t-2){
					ttt2 += remaining[j];
				}
				from(j,0,n){
					if(places_no_spaces[j] == ttt2){
						guess = j;
						break;
					}
				}
				dest = places[guess];
				fro = atoi(remaining[t-2].c_str());
				to = atoi(remaining[t-1].c_str());
			}

			from(k,0,n){
				if(places[k] == source){
					p1 = k;
				}else if (places[k] == dest){
					p2 = k;					
				}
			}

			if (singleLen){
				graph[p1] [p2] = fro;

			}else{
				graph[p1][p2] = fro;
				graph[p2][p1] = to;
			}
		

		// 	scanf(
		// 		"%[^:]s",
		// 		s1
		// 	);
		// 	getchar();
		// 	scanf(
		// 		"%[^(0-9)]s",
		// 		s2
		// 	);
		// 	s2[cstringLen(s2)-1] = '\0';

		// 	from(j,0,n){
		// 		// _(places[j]);
		// 		// _(s1);
		// 		// _(s2);
		// 		// _(strcmp(places[j],s1));
		// 		// $(strcmp(places[j],s2));
		// 		if(compareString(places[j],s1)==0){
		// 			p1 = j;
		// 		}else if (compareString(places[j],s2)==0){
		// 			p2 = j;
		// 		}
			// }
		// 	// cout << p1 <<" " << p2 << endl;
		// 	scanf("%d",&d);
		// 	gets(wt);
		// 	if (cstringLen(wt)){
		// 		d2 = atoi(wt);
		// 		graph[p1][p2] = d;
		// 		graph[p2][p1] = d2;
		// 	}else{
		// 		// d2 = -1;
		// 		graph[p1][p2] = d;
		// 	}
		}
		// from(i,0,n){
		// 	_(places[i]);
		// }

		// $(graph);
		// from(i,0,n){
		// 	from(j,0,n){
		// 		cout << graph[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// $(graph);


		getPath(graph,officeIndex,hallIndex,n,places,dist,sptSet);
		// cout <<"Are you ok?" << endl;

		// // getPath(graph,hallIndex,officeIndex,n,places);
		
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

