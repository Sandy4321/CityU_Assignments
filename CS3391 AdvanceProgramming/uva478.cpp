
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

double cross(double cx, double cy, double x1, double y1,double x2, double y2){
	return (x1-cx)*(y2-cy) - (y1-cy)*(x2-cx);
}

struct Shape{
	char sha;
	double x1;
	double x2;
	double x3;
	double y1;
	double y2;
	double y3;
	double r;

	bool contain(double x, double y){
		switch(sha){
			case 'r':
				return x > x1 && x < x2 && y < y1 && y > y2;
			case 'c':
				return (x-x1) * (x-x1) + (y - y1) * (y - y1) < r*r;
			default: // sha == 't'
				return cross(x1,y1,x2,y2,x,y)*cross(x1,y1,x3,y3,x,y) < 0 && cross(x2,y2,x1,y1,x,y)*cross(x2,y2,x3,y3,x,y) < 0;
		}
	}

} s[20]  ;


int T;

void mainFunction()
{
	double x,y;
	char c;
	int shapeIndex = 1 ;
	while (cin >> c && c != '*'){
		s[shapeIndex].sha = c;
		switch(c){
			case 'r':
				cin >> s[shapeIndex].x1
					>> s[shapeIndex].y1
					>> s[shapeIndex].x2
					>> s[shapeIndex].y2;
				break;
			case 'c':
				cin >> s[shapeIndex].x1
					>> s[shapeIndex].y1
					>> s[shapeIndex].r;
				break;
			case 't':
				cin >> s[shapeIndex].x1
					>> s[shapeIndex].y1
					>> s[shapeIndex].x2
					>> s[shapeIndex].y2
					>> s[shapeIndex].x3
					>> s[shapeIndex].y3;
		}
		shapeIndex ++;
	}
	int pointIndex = 1;
	while (cin >> x && cin >> y && !(x == 9999.9 && y == 9999.9)){
		bool containedInAny = false;
		from(i,1,shapeIndex){
			if (s[i].contain(x,y)){
				containedInAny = true;
				cout << "Point "<<pointIndex<<" is contained in figure "<< i << endl;
			}
		}
		if (!containedInAny){
			cout << "Point "<< pointIndex <<" is not contained in any figure\n"; 
		}
		pointIndex++;
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

