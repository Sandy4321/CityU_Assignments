/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 86347
 * Submitted at:  2019-05-09 07:18:26
 *
 * User ID:       554
 * Username:      54924670
 * Problem ID:    228
 * Problem Name:  Moliu Task
 */

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

#define input(x) scanf("%i",&x)
#define inputf(x) scanf("%lf",&x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define foreach(i, y) for (int i = 0; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;


int T;

void mainFunction()
{
	int N;
	T = 1;
	int is = 9;
	int acu = 0;
	int bound[10];
int tens[9];
	bound[0] = 0;
	from(i, 1, 9) {
		acu += is * i;
		bound[i] = acu;
		// cout << acu << endl;
		is *= 10;
	}
	tens[0]=0;
	tens[1]=1;
	for(int i=2;i<9;i++)
		tens[i]=tens[i-1]*10;

	// string stemp;
	// from(i,1,10000){
	// 	// cout << i << endl;
	// 	stemp += to_string(i);
	// }
	// cout << stemp;
	// from(i,1,2000000){
	// 	cout << i << endl;
	// }

	while (~input(N)) {

		if (N <= 9) {
			printf("Case %i : %i\n" ,T++,N );
			continue;
		}
		
		int lowerBound;
		from(i, 0, 9) {
			if (bound[i] >= N) {
				lowerBound = i;
				break;
			}
		}

		int shift = N - bound[lowerBound-1] - 1 ;

		
		// cout << lowerBound << " ";
		// cout << shift << " ";
		int diff1 = shift / (lowerBound);
		int diff2 = tens[lowerBound];
		int diff = diff1 + diff2;
		// _(diff);
		// _(diff1);
		// _(diff2);
		
		char numStr[25];
		sprintf(numStr,"%d",diff);
		int character = shift % (lowerBound);
		//cout << s[character];
		/*while (){

		}*/


		//cout << tempS[shift % lowerBound];

	/*	if ( N > 189 ) {
			N
		}*/

		printf("Case %i : %c\n" ,T++,numStr[character] );
		// cout << (s[character] == stemp[N]) << endl;
		// if ((s[character] != stemp[N-1])){
		// // 	cout << stemp[N-1] << endl;
		// 	cout << "WRONGOWVAKDSDKASDKAKSDKAS"<<endl;
		// 	cout << "WRONGOWVAKDSDKASDKAKSDKAS"<<endl;
		// 	cout << "WRONGOWVAKDSDKASDKAKSDKAS"<<endl;
		// }
	}

	/*

	3
	9
	10
	11
	10000
	50000
	*/
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	}
	std::ios_base::sync_with_stdio(false);
	// testCaseGenerator();
	mainFunction();
	return 0;
}