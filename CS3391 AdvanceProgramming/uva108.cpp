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
int n[101][101] = {0};
int d4[101][101][101][101] = {0};
bool d4b[100][100][100][100] = {0};
int sum(int x1, int y1, int x2, int y2){
	if (d4b[x1][y1][x2][y2] == true){
		return d4[x1][y1][x2][y2];
	}else{
		if (x1 == x2 and y1 == y2){
			d4[x1][y1][x2][y2] = n[x1][y1];
			d4b[x1][y1][x2][y2] = true;
			return d4[x1][y1][x2][y2];
		}
		else if (x1 == x2){
			d4[x1][y1][x2][y2] = sum(x1,y1,x2,y2-1) + n[x1][y2];
			d4b[x1][y1][x2][y2] = true;
			return d4[x1][y1][x2][y2];
		}else if (y1 == y2)
		{
			d4[x1][y1][x2][y2] = sum(x1,y1,x2-1,y2) + n[x2][y1];
			d4b[x1][y1][x2][y2] = true;
			return d4[x1][y1][x2][y2];
		}else{
			int rowSum = 0;
			from(i,x1,x2+1){
				rowSum += n[i][y2];
			}
			d4[x1][y1][x2][y2] = sum(x1,y1,x2,y2-1) + rowSum;
			d4b[x1][y1][x2][y2] = true;
			return d4[x1][y1][x2][y2];
		}

	}
}

int T;

void mainFunction()
{

	while (cin >> T){
		memset(d4b,false, sizeof d4b);
		for (int i = 0 ; i < T ; i++ ){
			for (int j = 0 ; j < T ; j++){
				cin >> n[i][j];
			}
		}		

		int maxi = -1270001;
		for (int x1 = 0 ; x1 < T ; x1 ++){
			for (int y1 = 0 ; y1 < T ; y1 ++){
				for (int x2 = x1 ; x2 < T ; x2++){
					for (int y2 = y1 ; y2 < T ; y2 ++){
						if (sum(x1,y1,x2,y2) > maxi){
							maxi = sum(x1,y1,x2,y2);
						}
					}
				}
			}
		}
		cout << maxi << endl;

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

