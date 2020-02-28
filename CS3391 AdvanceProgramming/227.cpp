/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 86320
 * Submitted at:  2019-05-09 04:29:18
 *
 * User ID:       554
 * Username:      54924670
 * Problem ID:    227
 * Problem Name:  Smart Customer
 */

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
#define inputf(x) scanf("%lf",&x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define foreach(i, y) for (int i = 0; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

struct Node {
	double cost;
	int noOfObjects;
	double avgCost;

	bool operator < (const Node &anotherN) const {
		return noOfObjects < anotherN.noOfObjects;
	}
	bool operator () (const Node &lhs, const Node &anotherN) const {
		//cout << "This is being executed" << endl;
		return lhs.noOfObjects < anotherN.noOfObjects;
	}

};

int T;

void mainFunction()
{
	double oriCost,p,dp[101];
	int m;
	int n;
	cout << fixed<< setprecision(2);
	T=1;
	while (~inputf(oriCost)) {

		input(m);
		from(i,0,101) {
			dp[i] = (double)INF;
		}
		set<Node,Node > costs;
		Node oriN = { oriCost, 1, oriCost };
		dp[1] = oriCost;
		dp[0] = 0;
		costs.insert(oriN);
		from(i,0,m) {
			input(n);
			inputf(p);

			Node newNode = { p, n,(double)p/n};
			set<Node,Node>::iterator it= costs.find(newNode);
			if (it != costs.end() && (*it).avgCost > newNode.avgCost) {
				costs.erase(it);
			}
			costs.insert(newNode);
		}

		for (set<Node,Node>::iterator it = costs.begin(); it != costs.end(); it++) {
			//cout << (*it).avgCost << " " << (*it).cost << endl;


			Node tmp = *it;
			from(i,tmp.noOfObjects, 101) {
				//cout << dp[i] << endl;
				dp[i] = min(dp[i], dp[i - tmp.noOfObjects] + tmp.cost);
			}

		}

		getchar();
		char s[10000];
		printf("Case %d:\n", T++);
		gets(s);
		int lp = 0, item;
		bool end = false;
		while (~sscanf(s+lp,"%d",&item)) {
			printf("Buy %d for $%.2f\n",item,dp[item]);
			while (s[lp]!=' ') {
				lp++;
				if (s[lp] =='\0') {
					end = true;
					break;
				}
			}
			if (end) break;
			lp++;
		}



	}

	/*

	22.00 2
	2 22.00
	4 60.00
	2 4
	25.00 2
	2 48.00
	2 46.00
	2
	22.00 2
	2 22.00
	4 40.00
	1 2 3 4
	
	
	*/
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}