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
int prime[10001];
bool isPrime(ull a){
    if ( a < 2){
        return false;
    }else if (a <= 3 ){
        return true;
    }else if (!(a & 1)){
        return false;
    }else {
        int primeIndex = 0;
        ull sqrtOfA = sqrt(a);
        // _(sqrtOfA);
        while(prime[primeIndex] <= sqrtOfA){

            // _(prime[primeIndex]);
            // _(a);
            // _(a % prime[primeIndex]);
            if (a % prime[primeIndex] == 0){
                return false;
            }
            primeIndex++;
            // _(prime[primeIndex]);
            // _(sqrtOfA);
            // assert( a != 99999989|| primeIndex != 1228);

        }
        return true;
    }
}

void mainFunction()
{
    T = 100000;

    // int b =0;
    // bool isPrime = true;
    bool siever[13001];
    int noOfPrime = 0;
    // prime[noOfPrime++] = 1;
    memset(siever,false,sizeof siever);
    from(i,2,13001){
        
        if (siever[i] == false){
            // not sieved, this is a prime
            prime[noOfPrime++] = i;
        }

        from(j,0,noOfPrime){ // ignoreing one because it is a prime of everyone
            if (prime[j] * i < 13001){
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
    // from(i,0,noOfPrime){
    //     cout << prime[i] << " ";
    // }
    // cout << endl;
    // this will give us a prime from 1 to 10001
    ull a,b;
    ull n;
    while(~scanf("%lld",&n)){

        // obtained the input 
        // from n/2 extend left right until both is prime

        if (n&1){
            a = 2;
            b = n - a;

            if (n > 2 && isPrime(b)){
                printf("%lld is the sum of %lld and %lld.\n",n,a,b);
            } else{
                printf("%lld is not the sum of two primes!\n",n);
            }
            continue;
        }


        // find_center:
        a = n >> 1; // divide by 2
        b = n - a; // believe that performance can be improved if considered
        // odd or even can do entirely on bit wise 
        // maybe not 
        // performance for +1 and +asdjksablfj is the same
        // if ( a == b){ // even number give us this
        // a --;
        // b ++;
        // }
        do {
            a --;
            b ++;
            // _(a);
            // _(b);
        } while ( a > 1 && (!isPrime(a) || !isPrime(b)) );
        if (a <= 1){
            printf("%lld is not the sum of two primes!\n",n);
        } else{
            printf("%lld is the sum of %lld and %lld.\n",n,a,b);
        }
    }
	// printf("what?");
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

