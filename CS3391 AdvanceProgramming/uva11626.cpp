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

struct P{
    ll x,y;
};

ll cross(P c, P p1,P p2){
	return (p1.x-c.x)*(p2.y-c.y) - (p1.y-c.y)*(p2.x-c.x);
}

bool iIsLargerThanj(P p1, P p2){
    if (p1.x == p2.x){
        return p1.y < p2.y;
    }else{
        return p1.x < p2.x;
    }
}

int T;

void mainFunction()
{
    cin >> T;
    int n;
    P hull[100005];
    P result[200005];
    while (T--){
        cin >> n;
        
        int x,y;
        char c;
        int hullCount = 0;
        from (i,0,n){
            cin >> x >> y >> c;
            if (c == 'Y'){
                hull[hullCount].x = x;
                hull[hullCount].y = y;
                hullCount ++;
            }
        }

        
        sort(hull,hull+hullCount, iIsLargerThanj);
        int m = 0;
        from(i,0,hullCount){
            while (m >= 2 && cross(result[m-2],result[m-1],hull[i]) < 0){
                m --;
            }
            result[m++] = hull[i];
        }
        int t = m +1;
        fromNeg(i,hullCount-2, 0 ){
            while(m >= t && cross(result[m-2],result[m-1],hull[i]) < 0){
                m--;
            }
            result[m++] = hull[i];
        }
        m --;
        printf("%d\n",m);
        from(i,0,m){
            printf("%lld %lld\n",result[i].x,result[i].y);
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

