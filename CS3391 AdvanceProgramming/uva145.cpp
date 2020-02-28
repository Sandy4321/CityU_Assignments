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
	double table[5][3] = {
		{0.1,0.06,0.02},{0.25,0.15,0.05},{0.53,0.33,0.13},{0.87,0.47,0.17},{1.44,0.80,0.30
		}
	};
	int timeBreak[4] = {8,18,22,24};
	char c;
	int cIndex;

	int translator(int t){
		if (t == 0 || t == 3){
			return 2;
		}else if (t == 1){
			return 0;
		}else{ // t == 2
			return 1;
		}
	}

void rec(int* mins, int sH, int eH){
	// _(sH);
	// $(eH);
	
	if (sH == eH){
		return;
	}
	int s, e ;
	if (sH < 8){
		s = 0;
	}else if (sH < 18){
		s = 1;
	}else if (sH < 22){
		s = 2;
	}else{
		s = 3;
	}

	if (eH < 8){
		e = 0;
	}else if (eH < 18){
		e = 1;
	}else if (eH < 22){
		e = 2;
	}else{
		e = 3;
	}

	if (sH > eH){
		rec (mins,sH,24);
		rec (mins,0,eH);
	}else { // eH > sH
		if (s == e){
			mins[translator(s)] += (eH - sH)*60;
		}else { // s < e cause e < s will never happen
			mins[translator(s)] += (timeBreak[s] - sH)*60;
			rec(mins,timeBreak[s],eH);
		}
	}
}


int T;

void mainFunction()
{
	int sH,sM,eH,eM;
	int s ,e;
	int mins[3];
	char phN[11];
	double total = 0;
	while (cin >> c && c != '#'){
		cIndex = (int)c-(int)'A';
		cin >> phN;
		cin >> sH >> sM >> eH >> eM;

		total = 0;
		memset(mins, 0 ,sizeof mins);

		if (sH < 8){
			s = 2;
		}else if (sH < 18){
			s = 0;
		}else if (sH < 22){
			s = 1;
		}else{
			s = 2;
		}

		if (eH < 8){
			e = 2;
		}else if (eH < 18){
			e = 0;
		}else if (eH < 22){
			e = 1;
		}else{
			e = 2;
		}
		
		if (sH == eH && sM < eM){
			total+= table[cIndex][s] * (eM-sM);
			if (s == 0){
				printf("%10s%6d%6d%6d  %c%8.2f\n",phN,eM-sM, 0 ,0 ,c,total);
			}else if (s == 1){
				printf("%10s%6d%6d%6d  %c%8.2f\n",phN,0,eM-sM ,0 ,c,total);
			}else{
				printf("%10s%6d%6d%6d  %c%8.2f\n",phN,0,0,eM-sM,c,total);
			}
		}else{
			
			mins[s] += 60 - sM; 
			mins[e] += eM;

				sH ++;

			rec(mins,sH,eH);
			total += mins[0] * table[cIndex][0] + mins[1] * table[cIndex][1] + mins[2] * table[cIndex][2];
			printf("%10s%6d%6d%6d  %c%8.2f\n",phN,mins[0],mins[1],mins[2],c,total);
		}


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

