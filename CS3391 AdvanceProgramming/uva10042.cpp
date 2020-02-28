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
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

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

int prime[3500];
void primeFactors( unsigned n, vector<unsigned>& r ) {
    int f = 2,currentI = 0,oriN = n; if( n == 1 ) r.push_back( 1 );
    else {
        while( true ) {
            if( !( n % f ) ) {
                r.push_back( f );
                n /= f; if( n == 1 ) return;
            }
            else {
				f = prime[currentI++];
				if (f*f > n ){
					r.push_back(n);
					return;
				}
			}
        }
    }
}

unsigned sumDigits( unsigned n ) {
    unsigned sum = 0, m;
    while( n ) {
        m = n % 10; sum += m;
        n -= m; n /= 10;
    }
    return sum;
}

unsigned sumDigits( vector<unsigned>& v ) {
    unsigned sum = 0;
    for( auto it : v ) {
        sum += sumDigits( it );
		// cout << it << " " << sumDigits( it )<<" sum: "<<sum<<", " ;
    }
	// cout << "total : "<< sum<<endl;
    return sum;
}


void listAllSmithNumbers( unsigned n ) {
    vector<unsigned> pf;
    for( unsigned i = 4; i < n; i++ ) {
        primeFactors( i, pf ); if( pf.size() < 2 ) continue;
        if( sumDigits( i ) == sumDigits( pf ) ){
            cout << setw( 6 ) << i << " ";
			// for(auto it : pf){
			// 	cout << it << ",";
			// }
			// cout << "\n";
		}
        pf.clear();
    }
    cout << "\n\n";
}

void mainFunction()
{
	bool siever[33000];
    int noOfPrime = 0;
    // prime[noOfPrime++] = 1;
    memset(siever,false,sizeof siever);
    from(i,2,33000){
        
        if (siever[i] == false){
            // not sieved, this is a prime
            prime[noOfPrime++] = i;
        }

        from(j,0,noOfPrime){ // ignoreing one because it is a prime of everyone
            if (prime[j] * i < 33000){
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
	input(T);
	// 1,000,000,000 ^ 0.5 => 31623 prime number smaller than
	int n;
	// generate first 31623 prime number
	while(T--){
		/* 
			from X -> move 1 indefinite try to find smith numbers
				first try find sum of number

		*/
		input(n);
		vector<unsigned> pf;
		while(n++){ 
			pf.clear();
			primeFactors( n, pf ); 
			if( pf.size() < 2 ) {

				continue;
			};
			// cout << n <<" ";
			// cout << sumDigits( n ) << " ";

			// 	for(auto it : pf){
			// 		cout << it << ",";
			// 	}
			// 	cout << "\n";
			// cout << sumDigits( pf ) << "\n";
			if( sumDigits( n ) == sumDigits( pf ) ){
				cout  << n << "\n";
				break;
			}
		}
	}
	
		// listAllSmithNumbers(1000000000);

}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w",stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

