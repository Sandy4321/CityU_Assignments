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
	char temp[200];
	int n = 0;
	set<string> strs;
	while(~scanf("%s",temp)){
		char A = 'A';
		char Z = 'Z';
		char a = 'a';
		char z = 'z';
		string cstr;

		// int cstrI = 0;
		from(i,0,strlen(temp)){
			if(temp[i] <= z && temp[i] >= a){
				cstr.push_back(temp[i]);
			}else if (temp[i] <= Z && temp[i] >= A){
				cstr.push_back(temp[i]-A+a);
			}else{
				strs.insert(cstr);
				string news;
				cstr = news;
			}
		}
		// cstr[cstrI++]='\0'; 
		// if (cstr!=""){
			strs.insert(cstr);
		// }
		// cout << c[n]<<endl;
		// n++;
	}
	set<string>::iterator it = strs.begin();
	it++;
	for(;it!= strs.end();it++){
		// if (*it != ""){
			cout << *it <<endl;
		// }
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

