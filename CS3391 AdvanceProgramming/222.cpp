
#define _CRT_SECURE_NO_WARNINGS
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
// using namespace std;
#define ull unsigned long long
#define ll  long long
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
#define foreach(i,n) for (int i = 0 ; i < n ; ++i )
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

int T;


void mainFunction()
{
	long double a, ans;
	bool notFirst = false;
	char c;
	ans = 0;
	cout << fixed << setprecision(4);

	// get the string
	string s;
	while (getline(cin,s)) {
		stringstream ss;
		ss << s;

		ans = 0;
		while (ss >> a) {
			ans += a;
		}

		if (notFirst) {
			cout << endl << ans << endl;
		}
		else {
			notFirst = true;
			cout << ans << endl;
		}
	}


	//d: {

	//	while (cin >> a) {
	//		ans += a;
	//		//			printf("\n\n%.4lf",ans);
	//		c = getchar();
	//		if (c == '\n') {
	//			if (notFirst) {
	//				cout << endl << endl << ans;
	//			}
	//			else {
	//				cout  << ans;
	//				notFirst = true;
	//			}
	//			ans = 0;
	//		}
	//		else if (c == '\0') {
	//			cout << endl << endl  << ans;
	//			break;
	//		}
	//		else {
	//			goto d;
	//		}
	//	}

	//}
   /*
   1 3 5 7 9
2 4.6 5.01


   */


}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}

	//freopen("out.txt", "w", stdout);
	// testCaseGenerator();
	mainFunction();
	return 0;
}