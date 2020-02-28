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
 
int getHighestBit(ull a){
	int numOfBits = 0;
	while(a > 0){
		a >>= 1;
		numOfBits++;
	}
	return numOfBits;
}

void mainFunction()
{

	bool siever[65537];
	int nonNearPerfectSquare[65537];
	int totalCount = 0;
	memset(siever,false,sizeof siever);
	from(i,2,65537){
		if (siever[i] == false){
			// sieve
			ull sieveingIndex = i*i;
			while ( sieveingIndex < 65537 ) {
				siever[sieveingIndex] = true;
				sieveingIndex *= i;
			}
			nonNearPerfectSquare[totalCount++] = i;
		}
		// _(i);
	}
	// from(i,0,totalCount ){
	// 	_(nonNearPerfectSquare[i]);
	// }

	int prime[65];
	bool sieved[65];
	int primeCounter = 0;
	int nonPrimeCounter = 0;
	int nonPrime[65];
	memset(sieved,false,sizeof sieved);
	from(i,2,65){
		if(not sieved[i]){
			prime[primeCounter++] = i;
		}else{
			nonPrime[nonPrimeCounter++] = i;
		}
		from(j,0,primeCounter){
			if (prime[j]*i < 65)
				sieved[prime[j] *i] =true;
			if (i%prime[j] == 0) break;
		}
	}

	// from(i,0,nonPrimeCounter){
	// 	_(i);
	// 	$(nonPrime[i]);
	// }

	fromNeg(i,nonPrimeCounter-1,1){
		// _(i);
		// $(nonPrime[i]);
		nonPrime[i] = nonPrime[i]-nonPrime[i-1];
	}


	// 	_(totalCount);
	int counts = 0;
	ull maxi = (ull)18445618199572250626;


	// _((1<<4));
	// _(maxi);
	set<ull> list;
	// _("wtf?");
		// _(nonNearPerfectSquare[0]);
	int maxConsideration = 64;
	// int consideration = 0;
	ull number = 1;
	list.insert(1);
		// _(nonNearPerfectSquare[0]);
	ull previousNum = 0;
	ull previousNum2 = 0;
	from(i,0,totalCount){
		// consideration = 0;
		// cout << i << endl;
		// _(nonNearPerfectSquare[i]);
		// number = nonNearPerfectSquare[i];
		// number = number *number *number*number;
		number = 1;
		previousNum = 1;
		from(j,0,maxConsideration){
			previousNum2 = previousNum;
			previousNum = number;
			from(k,0,nonPrime[j]){
				// _(nonNearPerfectSquare[i]);
				// _(j);
				// _(maxConsideration);
				// $(number);
				// cout << (number > maxi / nonNearPerfectSquare[i]) << endl;
				// assert(number != 11365870573289376);
					if (number > maxi / nonNearPerfectSquare[i]){
			// 			_(maxConsideration);
			// 			_(number);
			// assert(maxConsideration);
						maxConsideration = j;
						// _(maxConsideration);
					goto breakout;
				}
				number *=nonNearPerfectSquare[i];
				
			}
			
			
			list.insert(number);
			// _(nonNearPerfectSquare[i]);
			// _(j);
			// _(maxConsideration);
			// $(number);
			// assert(number != 4507793675642953);
		}
		breakout:{}

		// while( consideration < maxConsideration ){
		// 	consideration++;
		// 	// cout << number << endl;
		// 	list.insert(number);
		// 	number *= nonNearPerfectSquare[i]; 
		// 	number *= nonNearPerfectSquare[i];
		// 	if (number > maxi){
		// 		maxConsideration = consideration;
		// 		break;
		// 	}
		// 	// consideration ++;
		// }
		// counts ++;
	}

	set<ull>::iterator it = list.begin();
	for(;it!=list.end();it++){
		cout << *it << endl;
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

