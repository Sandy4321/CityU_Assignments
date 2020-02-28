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
struct State
{
	int cup[4];
	int curStep;

	State(int a, int b, int c, int d)
	{
		curStep = 0;
		cup[0] = a;
		cup[1] = b;
		cup[2] = c;
		cup[3] = d;
	}
	State() {}
};

int maxSize[4];
bool boi[30][30][30][30];

void getState(
	State sta,
	int volume,
	int cup,
	queue<State> *s)
{
	sta.curStep++;
	sta.cup[cup] = volume;

	// cout << "state:"<<endl;
	// cout << sta.cup[0] <<" ";
	// cout << sta.cup[1] <<" ";
	// cout << sta.cup[2] <<" ";
	// cout << sta.cup[3] <<endl<<endl;
	if (boi[sta.cup[0]][sta.cup[1]][sta.cup[2]][sta.cup[3]] == false)
	{
		boi[sta.cup[0]][sta.cup[1]][sta.cup[2]][sta.cup[3]] = true;
		s->push(sta);
		// cout << "from :getState" << endl;
		// from(i,0,s->size()){
		// 	State temptemp = s->front();
		// 	s->pop();
		// 	cout <<temptemp.cup[0] <<" ";
		// 	cout << temptemp.cup[1] <<" ";
		// 	cout << temptemp.cup[2] <<" ";
		// 	cout << temptemp.cup[3] <<" ";
		// 	s->push(temptemp);

		// 	cout << endl;
		// }
		// cout << endl;
		
	}
}
int measure(queue<State> *s)
{

	boi[0][0][0][0] = true;
	s->push(State(0, 0, 0, 0));

	while (!s->empty())
	{

		State tmpS = s->front();
		s->pop();
		from(i, 0, 4)
		{
			if (tmpS.cup[i] == T)
			{
				return tmpS.curStep;
			}
		}

		from(i, 0, 4)
		{
			getState(tmpS, maxSize[i], i, s);

			// cout <<"1:"<< tmpS.cup[i] << " ";
			getState(tmpS, 0, i, s);
			// cout <<"2:" <<tmpS.cup[i] << " ";
		}
		// cout << endl;
		// cout << s->size()<<endl;
	// cout << "state:"<<endl;
	// cout << tmpS.cup[0] <<" ";
	// cout << tmpS.cup[1] <<" ";
	// cout << tmpS.cup[2] <<" ";
	// cout << tmpS.cup[3] <<endl<<endl;

		from(i, 0, 4)
		{
			from(j, 0, 4)
			{
				if (i == j)
				{
					continue;
				}
					//  i : from 
					//  j : to
					// cout << i <<" "<< j << endl;
					// cout << tmpS.cup[i] << " "<<tmpS.cup[j] << endl;
					State newS = tmpS;
					if (maxSize[j] >= newS.cup[i] + newS.cup[j])
					{
						newS.cup[j] += newS.cup[i];
						newS.cup[i] = 0;
		// cout <<"if";
					}
					else
					{
						newS.cup[i] -= maxSize[j] - newS.cup[j];
						newS.cup[j] += maxSize[j] - newS.cup[j];
		// cout <<"else";
					}
					newS.curStep++;
					// cout << tmpS.cup[i] << " "<<tmpS.cup[j] << endl;
					// cout << tmpS.cup[0] << " ";
					// cout << tmpS.cup[1] << " ";
					// cout << tmpS.cup[2] << " ";
					// cout << tmpS.cup[3] << " ";
					// cout << endl;
					if (boi[newS.cup[0]][newS.cup[1]][newS.cup[2]][newS.cup[3]] == false)
					{
						boi[newS.cup[0]][newS.cup[1]][newS.cup[2]][newS.cup[3]] = true;
						s->push(newS);
		// 				from(i,0,s->size()){
		// 	State temptemp = s->front();
		// 	s->pop();
		// 	cout <<temptemp.cup[0] <<" ";
		// 	cout << temptemp.cup[1] <<" ";
		// 	cout << temptemp.cup[2] <<" ";
		// 	cout << temptemp.cup[3] <<" ";
		// 	s->push(temptemp);
		// 	cout << endl;
		// }
		// cout << endl;
					}
				}
			
		}
	}
	return -1;
}

void mainFunction()
{
	queue<State> *s;
	
	while (~input(maxSize[0]))
	{
		input(maxSize[1]);
		input(maxSize[2]);
		input(maxSize[3]);
		input(T);
		memset(boi,false,sizeof boi);
		s = new queue<State>;


		if (maxSize[0] < T && maxSize[1] < T && maxSize[2] < T && maxSize[3] < T)
		{
			output(-1);
			lnBrk();
		}
		else
		{
			output(measure(s));
			lnBrk();
		}
		delete s;
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
