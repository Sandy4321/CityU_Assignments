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
#define foreach(i,n) for (int i = 0 ;  i< n ; ++i)

#define eps 1e-6

using namespace std;



struct Gradient{
	int x,y;
	int p;
};
int cross(int cx, int cy, int x1, int y1,int x2, int y2){
	return (x1-cx)*(y2-cy) - (y1-cy)*(x2-cx);
}
int cross(Gradient g1, Gradient g2){
	return g1.x*g2.y - g1.y*g2.x;
}
int cross(Gradient g1, Gradient g2, Gradient g3, Gradient g4){
	return (g1.x-g2.x)*(g3.y-g4.y) - (g1.y-g2.y)*(g3.x-g4.x);
}
int dot(Gradient g1, Gradient g2, Gradient g3){
	return (g2.x-g1.x)*(g3.x-g1.x) + (g2.y-g1.y)*(g3.y-g1.y);
}
struct Point{
	int x,y;
};
bool iLargerThanj (Gradient i,Gradient j) { 
	// _(i.x);
	// _(i.y);
	// _(j.x);
	// $(j.y);
	return cross(i,j) > 0;
}

struct Shape{
	Gradient p[4];
};



int T;

void mainFunction()
{
	cin >> T;
	int p[4][2];
	Gradient g[3];
	from(t,1,T+1){
		cin >> p[0][0] >> p[0][1] >> p[1][0] >> p[1][1] >> p[2][0] >> p[2][1] >> p[3][0] >> p[3][1];
		printf("Case %d: ",t);

		// take 1 as center;
		g[0].x =  p[1][0] - p[0][0] ;
		g[0].y =  p[1][1]  - p[0][1];
		g[0].p = 1;
		g[1].x =  p[2][0] - p[0][0] ;
		g[1].y =  p[2][1]  - p[0][1];
		g[1].p = 2;
		g[2].x =  p[3][0] - p[0][0] ;
		g[2].y =  p[3][1]  - p[0][1];
		g[2].p = 3;

		sort(g,g+3,iLargerThanj);
		Shape s;
		
		s.p[0].x = p[0][0];
		s.p[0].y = p[0][1];
		from(i,1,4){
			from(j,0,2){
				s.p[i].x = p[g[i-1].p][0];
				s.p[i].y = p[g[i-1].p][1];
			}
		}


		// from(i,0,4){
		// 	_(s.p[i].x);
		// 	$(s.p[i].y);
		// }

		// detect opposite is parallel
		bool p1p2Top3p4 = cross(s.p[0],s.p[1],s.p[2],s.p[3]);
		p1p2Top3p4 = !p1p2Top3p4;
		bool p2p3Top4p1 = cross(s.p[1],s.p[2],s.p[3],s.p[0]);
		p2p3Top4p1 = !p2p3Top4p1;
		// _(cross(s.p[0],s.p[1],s.p[2],s.p[3]));
		// _(cross(s.p[1],s.p[2],s.p[3],s.p[0]));
		

		if (!p1p2Top3p4&&!p2p3Top4p1) {
			printf("Ordinary Quadrilateral\n");
			continue;
		}
		
		if (! (p1p2Top3p4&&p2p3Top4p1) ){
			printf("Trapezium\n");
			continue;
		}



		bool p1p2p3 = dot(s.p[0],s.p[1],s.p[3]);
		bool p3p4p1 = dot(s.p[2],s.p[1],s.p[3]);

		int p1p2 = (s.p[0].x - s.p[1].x)*(s.p[0].x-s.p[1].x) + (s.p[0].y - s.p[1].y)*(s.p[0].y-s.p[1].y);
		int p2p3 = (s.p[1].x - s.p[2].x)*(s.p[1].x-s.p[2].x) + (s.p[1].y - s.p[2].y)*(s.p[1].y-s.p[2].y);
		int p3p4 = (s.p[2].x - s.p[3].x)*(s.p[2].x-s.p[3].x) + (s.p[2].y - s.p[3].y)*(s.p[2].y-s.p[3].y);
		int p4p1 = (s.p[3].x - s.p[0].x)*(s.p[3].x-s.p[0].x) + (s.p[3].y - s.p[0].y)*(s.p[3].y-s.p[0].y);


		if (!p1p2p3 && !p3p4p1){
			if (p1p2 == p2p3 && p2p3 == p3p4 && p3p4 == p4p1 ){
				printf("Square\n");
				continue;
			}else{
				printf("Rectangle\n");
				continue;
			}
		}else{
			if (p1p2 == p2p3 && p2p3 == p3p4 && p3p4 == p4p1 ){
				printf("Rhombus\n");
				continue;
			}else{
				printf("Parallelogram\n");
				continue;
			}
		}






		// lnBrk();
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

