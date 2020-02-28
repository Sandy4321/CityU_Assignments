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

#define INF 1e9
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d", &x)
#define output(x) printf("%d", x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define foreach(i, y) for (int i = 0; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;

struct State
{
	int roomIndex;
	int ring;
	int len;

	State(int roomIndex, int ring, int len) : roomIndex(roomIndex),
											  ring(ring), len(len) {}

	State() {}
	// sorting descending
	// the smallest on the top
	bool operator<(const State &anotherS) const
	{
		return len > anotherS.len;
	}
	int operateOn(char c, int modifier)
	{
		if (c == '0')
			return ring;

		int newRPos = ring;

		if (c == '+')
			newRPos += modifier % 12;
		else if (c == '-')
			newRPos -= modifier % 12;
		else if (c == '=')
			newRPos = modifier;
		else if (c == '*')
			newRPos = ring * modifier;

		if (newRPos > 12)
			newRPos %= 12;
		if (newRPos <= 0)
			newRPos += 12;

		//printf("%i %c %i -> %i\n",oPos,ttype,bhvr,newRPos);
		return newRPos;
	}
};

void mainFunction()
{
	int
		number_of_rooms,
		number_of_corridors,
		number_of_traps,
		room_number_of_entrance,
		initial_ring_position,
		room_number_of_treasure,
		final_ring_position;

	bool stateChecker[1002][13]; // lazy minus, thats why 13

	// int graph[1001][1001];
	vector<vector<State>> graph;
	int edgeIn, edgeOut, edgeLen;

	int statesModiferVal[1002];
	char statesModifer[1002];
	int roomNo;

	while (~scanf(
		"%i%i%i%i%i%i%i",
		&number_of_rooms,
		&number_of_corridors,
		&number_of_traps,
		&room_number_of_entrance,
		&initial_ring_position,
		&room_number_of_treasure,
		&final_ring_position))
	{
		// input(number_of_corridors);
		// input(number_of_traps);
		// input(room_number_of_entrance);
		// input(initial_ring_position);
		// input(room_number_of_treasure);
		// input(final_ring_position);

		// room_number_of_entrance --;
		// room_number_of_treasure --;

		memset(stateChecker, false, sizeof stateChecker);
		memset(statesModifer, '0', sizeof statesModifer);
		// memset(graph,-1,sizeof graph);
		graph.clear();
		graph.assign(number_of_rooms + 2, vector<State>());

		// build graph
		from(i, 0, number_of_corridors)
		{ // for each corridors accept their information
			input(edgeIn);
			input(edgeOut);
			input(edgeLen);
			graph[edgeIn].push_back(State(edgeOut, edgeLen, 0));
			graph[edgeOut].push_back(State(edgeIn, edgeLen, 0));
		}

		// from(i,0,number_of_rooms){
		// 	from(j,0,number_of_rooms){
		// 		cout << graph[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// // save state modifier
		// vector<int> tempN;
		from(i, 0, number_of_traps)
		{
			char type;
			int modifi;
			scanf("%i %c %i", &roomNo, &type, &modifi);
			statesModifer[roomNo] = type;
			statesModiferVal[roomNo] = modifi;
		}

		// while(number_of_traps--){
		// 	char type;
		// 	int room, n;
		// 	scanf("%i %c %i",&room,&type,&n);
		// 	statesModifer[room] = type;
		// 	trapN[room] = n;
		// }

		// foreach(i,number_of_traps){
		// 	cout << statesModifer[tempN[i]] << endl;
		// 	output(statesModiferVal[tempN[i]]);
		// }

		// walk graph with Dijkstra
		/**
		   How Dijkstra works?
		   0. place into starting point
		   while we can explore new states:
		   		1. take a new node
		   		2. have new node considered?
					a. yes: do nothing
					b. no: 
						i. for each edge outwards:
							a. calculate new Ring Position
							b. if new Ring Position and room fits:
								i. update minimum distance
							c. else if weight is smaller than minimum distance:
								i. push into the list, maintain shortest distance next in queue
		 */
		priority_queue<State> q;

		if (room_number_of_entrance == room_number_of_treasure and initial_ring_position == final_ring_position)
		{
			cout << 0 << '\n';
		}
		else
		{
			q.push(State(
				room_number_of_entrance,
				initial_ring_position,
				0));
		}

		// priority_queue<State> tempQ;
		int mini = INF;
		while (!q.empty())
		{

			// 		while (!q.empty()){
			// 			State tempS = q.top();
			// 			q.pop();
			// 			cout << tempS.roomIndex <<" "<<tempS.ring<<" "<<tempS.len <<endl;
			// 			tempQ.push(tempS);
			// 		}
			// 		while(!tempQ.empty()){
			// 			q.push(tempQ.top());
			// 			tempQ.pop();
			// 		}
			// cout << endl;
			// cout << q.size() << endl;

			State test = q.top();
			// q.erase(q.begin());
			q.pop();

			// cout << q.size() << endl;

			// evalute mini
			// if (
			// 	test.ring == final_ring_position and
			// 	test.roomIndex == room_number_of_treasure)
			// {
			// 	mini = min (mini, test.len);
			// }

			// if I have not seen this
			if (stateChecker[test.roomIndex][test.ring])
				continue;
			stateChecker[test.roomIndex][test.ring] = true;

			// for each edge
			from(i, 0, graph[test.roomIndex].size())
			{
				int newRPos = test.operateOn(statesModifer[i], statesModiferVal[i]);
				if (graph[test.roomIndex][i].roomIndex == room_number_of_treasure && newRPos == final_ring_position)
				{
					// cout << "Found : "<< i << " " << newRPos << " " << test.len + graph[test.roomIndex][i]<<endl;
					mini = min(mini, test.len + graph[test.roomIndex][i].len);
				}
				else
				{

					q.push(
						// (State){
						// 	i,
						// 	test.operateOn(statesModifer[i],statesModiferVal[i]),
						// 	test.len + graph[test.roomIndex][i]
						// }
						State(
							graph[test.roomIndex][i].roomIndex,
							newRPos,
							test.len + graph[test.roomIndex][i].len));
				}
				// cout << q.size() << endl;
				// cout << tempS.len <<" "<<tempS.ring << " "<< tempS.roomIndex << endl;
			}
		}

		if (mini >= INF)
			puts("Pray!");
		else
			printf("%i\n", mini);
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
