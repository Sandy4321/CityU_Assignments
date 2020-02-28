#define _CRT_SECURE_NO_WARNINGS

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
#define inputs(x) scanf("%s",x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

#define MAXN 1000000
using namespace std;

int T;
char s1[MAXN];
char res[MAXN];
char *ACGT = "ACGT";

int counter[MAXN] ,it;
int resultLen;
int resultCount;
int tree[MAXN][4];

int translateItoC(int i){
	return ACGT[i];
}

int translateCtoI(char c){
	switch(c){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
}

void createTree(int i, char *x){
	counter[i]++;
	if (*x){
		int &newi = tree[i][translateCtoI(*x)];
		if (newi==-1){
			newi = it++;
		} 
		createTree(newi, x+1);
	}
}
void recc(int i, int d=0){
	s1[d] = 0;
	if (d > resultLen && counter[i] > 1){
		resultLen = d;
		resultCount = counter[i];
		strcpy(res,s1);
	}
	from(j,0,4){
		if (tree[i][j]!=-1){
			s1[d] = translateItoC(j);
			recc(tree[i][j],d+1);
		}
	}
}

void mainFunction()
{
	input(T);
	while (T--) {
		inputs(s1);
		memset(counter, 0, sizeof(counter));
		memset(tree, -1, sizeof(tree));
		it = 1;
		resultLen = 0;
		resultCount = 0;
		from(i,0,strlen(s1)){
			createTree(0,s1+i);
		}
		recc(0);
		if (resultLen > 0) {

			cout << res << " " << resultCount << '\n';
		}
		else {
			cout << "No repetitions found!\n";
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

/*
6
GATTACA
GAGAGAG
GATTACAGATTACA
TGAC
TGTAC
TTGGAACC
*/