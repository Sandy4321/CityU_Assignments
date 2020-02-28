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

// #define INF 0x3f3f3f3f
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
struct Network {
    struct Edge {
        int to;
        int pre_edge;
        int cap;
        int flow;
    };

    #define MAXNODE 405
    int last[MAXNODE];

    int nv; // total number of vertex, index range: [0, nv)
    vector<Edge> edge;
    void init(int _nv) {
        nv = _nv;
        edge.clear();
        fill(last, last + nv, -1);
    }

    void add_e(int x, int y, int cap, int r_cap = 0) {
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
    void show_edge() {
        for (int i = 0; i < nv; i++) {
            printf("v [%d]:", i);
            for (int ie = last[i]; ie != -1; ) {
                const Edge& e = edge[ie]; 
                ie = e.pre_edge;
                printf(" [%d]%d/%d", e.to, e.flow, e.cap);
            }
            printf("\n");
        }
        printf("\n");
    }

	int getNett(){
		int toBeMinus =0 ;
		for (int i = 1; i < nv-1; i++) {
            // printf("v [%d]:", i);
			int flowed = 0;
            for (int ie = last[i]; ie != -1; ) {
                const Edge& e = edge[ie]; 
                ie = e.pre_edge;
				if (e.flow > 0){
					flowed += e.flow;
				}
                // printf(" [%d]%d/%d", e.to, e.flow, e.cap);
            }
			if (flowed > 1){
				toBeMinus += flowed-1;
			}
            // printf("\n");
        }
		return toBeMinus;
        // printf("\n");
	}

    // 
    // maximum flow
    // dinic O(V * V * E)
    int lv[MAXNODE];
    bool mark_level(int start, int end) {
        fill(lv, lv + MAXNODE, -1);
        queue<int> q;
        lv[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int ie = last[cur]; ie != -1; ) {
                const Edge& e = edge[ie]; 
                ie = e.pre_edge;
                if (e.cap != e.flow && lv[e.to] == -1) {
                    lv[e.to] = lv[cur] + 1;
                    q.push(e.to);
                }
            }
        }
        return lv[end] != -1;
    }
    void show_lv() {
        for (int i = 0; i < nv; i++) {
            printf("lv[%d] = %d\n", i, lv[i]);
        }
    }
    int augment(int cur, int end, int min_flow) {
        if (cur == end)
            return min_flow;

        int augmented_flow = 0;
        for (int ie = last[cur]; ie != -1; ) {
            Edge& e = edge[ie]; 
            Edge& re = edge[ie ^ 1];
            ie = e.pre_edge;
            if (lv[e.to] == lv[cur] + 1 &&
                e.cap > e.flow &&
                (augmented_flow = augment(e.to, end, min(e.cap - e.flow, min_flow)))
            ) {
                e.flow += augmented_flow;
                re.flow -= augmented_flow;
                return augmented_flow;
            }
        }
        return 0;
    }
    int dinic(int start, int end) {
        int total_flow = 0;
        int flow = 0;
        while (mark_level(start, end)) // update level
            while (flow = augment(start, end, INT_MAX)) // eat up all augmented flow
                total_flow += flow;
        return total_flow;
    }
    // end of
    // maximum flow - dinic
    // 
};
// // Driver program to test above functions 
// int main() 
// { 
//     // Let us create a graph shown in the above example 
//     int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
//                         {0, 0, 10, 12, 0, 0}, 
//                         {0, 4, 0, 0, 14, 0}, 
//                         {0, 0, 9, 0, 0, 20}, 
//                         {0, 0, 0, 7, 0, 4}, 
//                         {0, 0, 0, 0, 0, 0} 
//                       }; 
  
//     cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5); 
  
//     return 0; 
// } 

void mainFunction()
{

	int n,s,t,d;
	int l,w;
	int s1,s2,weight;
	// int graph[101][101];
	Network net;
	// int totalFlow =0;
	int x,y;
	int nodes[100][2];
	int nodeIndex = 0;
	int dsquared = 0;
	T = 1;
	while(scanf("%d%d%d%d",&l,&w,&n,&d) && !( l== 0 and w==0  and n== 0 and d == 0 ) ){
		net.init(2+n*2);
		// totalFlow = 0;
		// from 0 -> n+1;
		nodeIndex= 0 ;
        int south = 1;
		dsquared = d*d*4;
        set<pair<int,int> > idx;
		from(i,1,n+1){
			input(x);
			input(y);
            // cout << i << endl;
            // cout << i*2 << endl;
            // cout << i*2+1 << endl;
            net.add_e(i*2,i*2+1,1);
			if ( w - d <= y ) {
                // cout << "one"<<endl;
				net.add_e(0,i*2,1);
			}
			if ( y <= d ){
                // cout << "two" << endl;
				net.add_e(i*2+1,south,1);
			}

			from(j,0,nodeIndex){
				// cout << ((nodes[j][0]-x)*(nodes[j][0]-x) +(nodes[j][1]-y)*(nodes[j][1]-y)) << endl;
				if (  ((nodes[j][0]-x)*(nodes[j][0]-x) +(nodes[j][1]-y)*(nodes[j][1]-y)) <= dsquared ) {
					// cout << "connected"<<endl;
                    // idx.insert(pair<int,int>(i*2+1,j*2));
                // cout << "three" << endl;
                // _(i);
                // $(j);
                // if (){

                // }
                    net.add_e(i*2+1,(j+1)*2,1);
                    net.add_e((j+1)*2+1,i*2,1);
					// net.add_e(i*2+1,(j+1)*2,1,1);
				}
			}
			nodes[nodeIndex][0]=x;
			nodes[nodeIndex++][1]=y;

			// net.add_e(i,k+1,weight);
			// totalFlow+=weight;
		}
		// net.show_edge();
		// int noOfEdge;
		// int index = k+2;
		// int destination;
		// from(i,0,p){
		// 	input(noOfEdge);
		// 	net.add_e(0,index,1);
		// 	from(j,0,noOfEdge){
		// 		input(s2);
		// 		net.add_e(index,s2,1);
		// 	}
		// 	index++;
		// }
		// cout << index <<" " <<k <<" "<< p;

		// input(s);
		// input(t);
		// input(c);
		// from(i,0,c){
		// 	input(s1);
		// 	input(s2);
		// 	input(weight);
		// 	net.add_e(s1,s2,weight,weight);
		// }
		// net.show_edge();
		// 0 -> k+1;

		// printf("Network %d\nThe bandwidth is %d.\n\n",T++,);
		// if(net.dinic(0,k+1) < totalFlow){
		// 	outputs("0\n");
		// }else{
		// 	outputs("1\n");
		// }

		int res =net.dinic(0,1); 
		cout << "Case " << T++ << ": ";
		// cout << res<<endl;
		cout << res<<endl;
		// net.show_edge();
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

