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

int key(int a){
	int largest =0 ;
	int sum = 0;
	
	for(int i = 2 ;i*i <= a ; i++){
		if (a % i == 0){
			// we found factor which is prime
			sum += largest;
			largest = i;
			// sum += i;
			// _(i);
			do{
				a /= i;
			}while(a % i == 0);

		}
	}

	if ( a > 1 ) {
		sum += largest;
		largest = a;
			// _(a);
	}

	return largest - sum ;
}

void mainFunction()
{
	// input(T);
	int a,b;
	while(scanf("%d%d",&a,&b) && a != 0 && b != 0){
		// _(a);
		// _(key(a));
		// _(b);
		// $(key(b));
		if (a == b){
			outputs("a\n");
		} else if (key(a) > key(b)){
			outputs("a\n");
		}else{
			outputs("b\n");
		}
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

