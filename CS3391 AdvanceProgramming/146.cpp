/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib> // random
#include <ctime>
#include <climits>    // all useful constants
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

#define maxn 10
#define maxw 5
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
    int u, v, c;
} e[10000];

int cmpFunc(const void *a, const void *b)
{
    return ((Edge *)a)->c - ((Edge *)b)->c;
}

int disjointSet[100];

int unionSet(int rootOfA,int rootOfB){
    disjointSet[rootOfA] = rootOfB;
}

int root(int a){
    if(disjointSet[a] == a){
        return a;
    }else{
        return disjointSet[a] = root(disjointSet[a]);
    }
}

bool isConnected(int start)
{
    from(i,0,n){
        disjointSet[i] = i;
    }

    from(i,start,m){
        unionSet(root(disjointSet[e[i].u]),root(disjointSet[e[i].v]));
    }

    int same = root(0);
    from(i,1,n){
        if (root(i) != same){
            return false;
        }
    }
    return true;
}

void mainFunction()
{
    /**
     * Talk about improvements,
     *      can add binary search
     */
    input(T);
    from(t, 0, T)
    {
        input(n);
        input(m);
        from(i, 0, m)
        {
            input(e[i].u);
            input(e[i].v);
            input(e[i].c);
        }

        qsort(e, m, sizeof(Edge), cmpFunc);

        // from largest to smallest.
        //      if is a connected graph
        //          largestMin = i
        //          break;

        int largestMin = 1000;
        fromNeg(j, m - 1, 0)
        {
            bool connected = isConnected(j);
            if (connected)
            {
                largestMin = e[j].c;
                break;
            }
        }
        outputs("Case #");
        output(t + 1);
        outputs(": ");
        output(largestMin);
        lnBrk();

        // from(j,0,m){
        //     output(e[j].c);
        //     lnBrk();
        // }
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