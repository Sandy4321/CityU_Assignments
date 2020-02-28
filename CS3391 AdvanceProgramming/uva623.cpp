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

class BigNo{
	public:
		int digits[2570];

		BigNo operator+(BigNo n){
			BigNo res;
			res.reset();
			from(i,0,2570){
				res.digits[i] += n.digits[i] + this->digits[i];
				if (res.digits[i] >= 10){
					res.digits[i] %= 10;
					res.digits[i+1]++; 
				}
			}
			return res;
		}

		BigNo operator*(int n){
			vector<int> breakDown;
			while(n > 0){
				breakDown.push_back(n%10);
				n/=10;
			}
			BigNo res;
			res.reset();
			BigNo temp;
			int digitNow = 0;
			for (auto i : breakDown){
				temp.reset();
				// sum by i times;
				from (j,0,i){
					temp = temp + *this;
				}
				// then shift by digitNow;
				temp.shiftChar(digitNow);
				res = res + temp;
				digitNow++;
			}
			// BigNo res;
			// res.reset();
			// from(i,0,n){
			// 	res = res + *this;
			// }
			return res;
		}

		void reset(){
			memset(digits,0,sizeof digits);
		}

		void shiftChar(int shiftBy){
			fromNeg(i,2569,shiftBy){
				digits[i] = digits[i-shiftBy];
			}
			from(i,0,shiftBy){
				digits[i] = 0;
			}
		}

		void print(){
			bool startPrinting = false;
			fromNeg(i,2569,0){
				if (digits[i] != 0){
					startPrinting = true;
				}
				if (startPrinting){
					cout << digits[i] ;
				}
			}
			if (!startPrinting){
				cout << 0;
			}
		}
}dp[1001];


int T;

void mainFunction()
{
	dp[0].reset();
	dp[0].digits[0] = 1;
	from(i,1,1001){
		dp[i].reset();
		dp[i] = dp[i-1] * i;
	}
		
	while(cin >> T){
		cout << T << "!" << endl;
		dp[T].print();
		lnBrk();
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

