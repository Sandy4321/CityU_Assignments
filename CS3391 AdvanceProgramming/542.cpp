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

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

int T;

void mainFunction()
{
	int sig[100], g[100];
	int index;

	int maxHours = 5*60*60+1;
	again:
	{
		index = 0;
		while (input(sig[index]) && sig[index++] != 0){}
		index--;
		if (sig[0] != 0)
		{
			memset(g,0,sizeof g);
			int start = INF;

			from(i, 0, index)
			{
				start = min(start,sig[i]);
			}

			int syncAt = 1;
			bool didSync;
			from(i,start,maxHours){
				didSync = true;
				from(j,0,index){
					// wait for another round
					while(i >= sig[j] -5 + g[j]){
						g[j] = g[j] + sig[j]*2;
					}

					if (
						not (
							g[j] <= i
							and
							g[j] + sig[j] - 5 > i 
						)
					){
						syncAt = g[j] - 1;
						i = syncAt;
						didSync = false;
						break;
					}
				}
				if (didSync){
					break;
				}
			}

			if (syncAt > maxHours){
				outputs("Signals fail to synchronise in 5 hours\n");
			}else{
				syncAt += 1;
				int hour = syncAt /3600;
				int minit = syncAt %3600 / 60; 
				int seconds = syncAt %60; 
				printf("%02d:%02d:%02d\n", hour,minit,seconds);
			}

			goto again;
		}else{
			// cout << "hello"  << endl;
			goto end;
		}
	}
	end:{}
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
