/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib> // random
#include <ctime>
#include <climits>    // all useful constants
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
#define $(x)                                     \
    {                                            \
        if (DUBUG)                               \
            std::cout << #x << " = " << x << " " \
                      << "\n";                   \
    }
#define _(x)                                      \
    {                                             \
        if (DUBUG)                                \
            std::cout << #x << " = " << x << " "; \
    }

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

int T;

int getFirst(ull a)
{
    ull i = 0;
    while (a > 0)
    {
        i++;
        a >>= 1;
    }
    return i;
}

void mainFunction()
{
    ull a, b;
    while (~scanf("%lld%lld", &a, &b))
    {
        if (a == b){
            printf("%lld",a);
        }else{
            ull sum = 0;
            doo:
                int afirst = getFirst(a);
                int bfirst = getFirst(b);
                if (afirst != bfirst){
                    printf("%lld",sum +((ull)1 << max(afirst,bfirst))-1);
                }else{
                    ull x = 1;
                    x <<= (afirst-1);
                    // cout << afirst<<endl;
                    sum += x;
                    // cout << x << endl;
                    a -= x;
                    b -= x;
                    // cout << a<< " " << b << endl;
                    goto doo;
                }
            
        }
        // output((1 << first));
        // outputs(" ");
        // output(getFirst(b));
        outputs("\n");
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
