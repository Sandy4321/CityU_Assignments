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

using namespace std;

// struct Cell{
// 	int count;
// 	bool match;
// };

int T;

void mainFunction()
{
	// Cell cells[1001][1001];
	int cells[1001][1001];
	char s1[1001];
	char s2[1001];
	input(T);
	while(T--){	
		scanf("%s", s1);
		scanf("%s", s2);
		int strl = strlen(s1);
		int strl2 = strlen(s2);
		// from(i,0,strl){
		// 	from(j,0,strl2){
		// 		cells[i][j].match = s1[i] == s2[j];
		// 		cells[i][j].count = 0; 
		// 	}
		// }

		// from lower right conner move up
		// cells[strl-1][strl2-1] = 1;
		// int r,b,d= INF;
		bool rightFound = false;
		bool bottomFound = false;
		if (s1[strl-1] == s2[strl2-1]){
			rightFound = bottomFound = true;
			cells[strl-1][strl2-1] = 1;
		}else{
			cells[strl-1][strl2-1] = 2;
		}
		// r =b=d;
		/**
		 [
			    ---s2---
			 |  ********
			 s1 ********
			 |  ********
		 ]
		 */
		fromNeg(i,strl-2,0){ 
			// solving right most column;
			if (!rightFound && s1[i] == s2[strl2-1]){
				rightFound = true;
				cells[i][strl2-1] = cells[i+1][strl2-1];
			}else{
				cells[i][strl2-1] = cells[i+1][strl2-1] + 1;
			}
		}

		fromNeg(i,strl2-2,0){
			// solving bottom most column
			if (!bottomFound && s1[strl-1] == s2[i]){
				bottomFound = true;
				cells[strl-1][i] = cells[strl-1][i+1];
			}else{
				cells[strl-1][i] = cells[strl-1][i+1]+1;
			}
		}

		fromNeg(i,strl-2,0){
			fromNeg(j,strl2-2,0){
				if(s1[i] == s2[j]){
					cells[i][j]=min(cells[i+1][j],min(cells[i][j+1],cells[i+1][j+1]))+1;
				}else{
					cells[i][j] = min(cells[i+1][j],min(cells[i][j+1],cells[i+1][j+1]+1))+1;
				}
			}
		}

		// from(i,0,strl){
		// 	from(j,0,strl2){
		// 		cout << cells[i][j] <<" ";
		// 	}
		// 	cout << endl;
		// }

		cout << cells[0][0]<<endl;
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

