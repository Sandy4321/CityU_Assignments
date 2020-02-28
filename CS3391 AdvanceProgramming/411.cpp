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

#define input(x) scanf("%lld",&x)
#define output(x) printf("%lld",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (ull i = x; i < y; ++i)
#define fromNeg(i, x, y) for (ull i = x; i >= y; --i)

#define eps 1e-6

using namespace std;


ull T;

// ull cmp(const void* c1,const void* c2){
// 	ull *lhs = <ull*>c1;
//     ull *rhs = <ull*>(c2);
// 	if (c1[0]==c2[0]){
// 		return c1[1] < c2[1];
// 	}else{
// 		return c1[0] < c2[0];
// 	}
// }

void mainFunction()
{
	input(T);
	T++;
	set<pair<ull,ull> > s;
	ull cs[48][2];
	from(i,1,T){
		ull n,m;
		input(n);
		input(m);
		ull c;
		input(c);

		ull ways = n*(m-1);

		from(i,0,c){
			input(cs[i][0]);
		}
		from(i,0,c){
			input(cs[i][1]);

			bool beforeMe = cs[i][1] == 1 || s.find(pair<ull,ull>(cs[i][0],cs[i][1]-1)) != s.end();
			bool afterMe = cs[i][1] == m || s.find(pair<ull,ull>(cs[i][0],cs[i][1]+1)) != s.end();
			if (beforeMe && afterMe){
				// do nothing
			}else if (beforeMe || afterMe){
				ways --;
			}else {
				ways -= 2;
			}

			s.insert(pair<ull,ull>(cs[i][0],cs[i][1]));
		}
		s.clear();



		outputs("Case #");
		output(i);
		outputs(": ");
		output(ways);
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

