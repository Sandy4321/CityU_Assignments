#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 1e9

#define from(i, x, y) for (int i = x; i < y; ++i)

struct State{
	int roomIndex, len, ring;
	State(int a, int r, int b){
		roomIndex = a;
		ring = r;
		len  = b;
	}
	State(){};
	
	bool operator < (const State &otherState) const{
		return len > otherState.len;
	}
};



int operateOn(int oldRing, char c, int bhvr){
	if(c=='0') return oldRing;
	
	int newRing = oldRing;
	
	switch(c){
		case '+':
		newRing += bhvr%12;
		break; 
		case '-':
		newRing -= bhvr%12;
		break;
		case '=':
		newRing = bhvr;
		break;
		case '*':
		newRing = oldRing*bhvr;
		break;
	}
	
	if(newRing>12) newRing %= 12;
	if(newRing<=0) newRing += 12;
	
	return newRing;
}

int main(){

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}

	int number_of_rooms,
	 	number_of_corridors, 
		 number_of_traps, 
		 room_number_of_entrance, 
		 initial_ring_position, 
		 room_number_of_treasure, 
		 final_ring_position;
			int u, v, length;

			char type;
			int room, n,mini;
	while(~scanf("%i%i%i%i%i%i%i",
	&number_of_rooms, 
	&number_of_corridors, 
	&number_of_traps, 
	&room_number_of_entrance, 
	&initial_ring_position, 
	&room_number_of_treasure, 
	&final_ring_position)){
		bool stateChecker[number_of_rooms+1][13];
		int statesModiferVal[number_of_rooms+1];
		char statesModifer[number_of_rooms+1];	
		
		mini = INF;	
		priority_queue<State> q;
		vector < vector<State> > graph;
		graph.assign(number_of_rooms+2, vector<State>());
		
		from (i,0,number_of_corridors){
			scanf("%i%i%i",&u,&v,&length);
			graph[u].push_back( State(v, 0, length) );
			graph[v].push_back( State(u, 0, length) );
		}

		memset(statesModifer,'0',sizeof(statesModifer));
		from(i,0,number_of_traps){
			scanf("%i %c %i",&room,&type,&n);
			statesModifer[room] = type;
			statesModiferVal[room] = n;
		}

		memset(stateChecker,false,sizeof(stateChecker));
		
		
		if(room_number_of_entrance==room_number_of_treasure && initial_ring_position == final_ring_position)
			mini = 0;
		else
			q.push( State(room_number_of_entrance,initial_ring_position,0) );
		while(!q.empty()){
			State curr = q.top();
			q.pop();
			
			if(stateChecker[curr.roomIndex][curr.ring]) continue;
			stateChecker[curr.roomIndex][curr.ring] = true;
			
			from(i,0,graph[curr.roomIndex].size()){
				State nxtState = graph[curr.roomIndex][i];

				int newRPos = operateOn( curr.ring, statesModifer[nxtState.roomIndex], statesModiferVal[nxtState.roomIndex]);
				if(nxtState.roomIndex==room_number_of_treasure && newRPos==final_ring_position)
					mini = min( nxtState.len+curr.len ,mini);
				else
					q.push( State( nxtState.roomIndex, newRPos , nxtState.len+curr.len) );
			}
		}
		
		if(mini>=INF)
			printf("Pray!\n");
		else
			printf("%i\n",mini);
	}

	return 0;
}
