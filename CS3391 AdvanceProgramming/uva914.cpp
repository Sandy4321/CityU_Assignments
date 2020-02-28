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


int T;
int prime[78498];
int jump[1000000];

void mainFunction()
{
    /**
     * Talk about improvements,
     *      
     */

	
    // int b =0;
    // bool isPrime = true;
    bool siever[1000000];
    int noOfPrime = 0;
    // prime[noOfPrime++] = 1;
    memset(siever,false,sizeof siever);
    from(i,2,1000000){
        
        if (siever[i] == false){
            // not sieved, this is a prime
            prime[noOfPrime++] = i;
        }

        from(j,0,noOfPrime){ // ignoreing one because it is a prime of everyone
            if (prime[j] * i < 1000000){
                // we dont need to check further
                // we sieve it
                siever[prime[j]*i] = true;
            }else{
                // overflowed 10000
                break;
            }

            if (i % prime[j] == 0){
                // because if we dont do this
                // later we change exchange values with other prime larger than this
                // to create a larger i
                break;
            }
        }
    }
    // _(noOfPrime);
	// int maxDiff = 0;
    // from(i,1,noOfPrime){
    //     cout << prime[i] << " ";
	// 	if (prime[i] - prime[i-1]> maxDiff ){
	// 		maxDiff = prime[i] - prime[i-1];
	// 	}
    // }
	// _(maxDiff);
	// from (i,0,1000000){
	// 	cout << siever[i] << " "; 
	// }
	
	input(T);
	int l,u;
	int count[115]= {0};
	int maxCount = 0;
	int maxCountIndex = 0;
	bool moreThanOne = false;
	while(T--){
		// picking the most frequent
		maxCount = 0;
		maxCountIndex = 0;
		moreThanOne = false;
		input(l);
		input(u);
		memset(count, 0,sizeof count);

		if (l < 2){
			l = 2;
		}
		if (u < 2){
			u = 2;
		}

		while (l <= u){
			if (!siever[l]){
				break;
			}else{
				l++;
			}
		}
		u++;

		int currDiff = 0;
		from (i,l,u){
			if (!siever[i]){
				maxCount = max(currDiff,maxCount);
				count[currDiff] ++;
				currDiff = 1;
			}else{
				currDiff ++;
			}
		}
		// cout << maxCount << endl;
		maxCount ++;

		count[0] = 0;
		from (i,1,maxCount){
			// _(i) ;_(count[i]);
			// lnBrk();
			if (count[maxCountIndex] < count[i]){
				maxCountIndex = i;
				moreThanOne = false;
			}else if (count[maxCountIndex] == count[i]){
				moreThanOne = true;
			}
		}
		if (moreThanOne || maxCountIndex == 0){
			cout << "No jumping champion" << endl;
		}else{
			cout << "The jumping champion is "<< maxCountIndex << endl;
		}
			// lnBrk();
			// lnBrk();

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

