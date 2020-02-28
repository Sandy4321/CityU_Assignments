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


int T;

void mainFunction()
{
	// build table
	// int table[1299710];
	int prime[1299710];
	from(i,0,1299710){
		prime[i] = -1;
	}

	for(int i = 2 ; i < 1299710 ; i++ ){
		if ( prime[i] == -1 ){
			int k = i+i;
			while(k < 1299710){
				prime[k] = 0;
				k += i;
			}
		}
	}

	int indexToMoveTo = 0;

	from(i,0,1299710){
		while ( indexToMoveTo < 1299710 ) {
			
		}
	}


	// do task
	while(cin >> T && T != 0){
		int index = T;
		while (prime[index] == 0){
			index ++;
		}
		int index2 = T;
		while(prime[index2] == 0){
			index2--;
		}
		output(index-index2);
		lnBrk();
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

