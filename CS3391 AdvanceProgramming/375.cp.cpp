#include<stdio.h>
#include<queue>
#include <iostream>
using namespace std;

/*This problem ruins okonomiyaki.*/
int capA, capB, capC, capD, target;
int caps[4];

struct State{
	int c[4];
	int steps;
	
	State(int av, int bv, int cv, int dv){
		steps = 0;
		c[0] = av;
		c[1] = bv;
		c[2] = cv;
		c[3] = dv;
	}
	State(){}
};

void set(State s, int cup, int vol, queue<State> *states, bool ved[30][30][30][30]){
	s.c[cup] = vol;
	s.steps++;
	// cout << "state:" << endl;
	// cout << s.c[0] <<" ";
	// cout << s.c[1] <<" ";
	// cout << s.c[2] <<" ";
	// cout << s.c[3] <<endl<<endl;
	if(!ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]]){
		//printf("set: ved[%i][%i][%i][%i]	steps:%i\n",s.c[0],s.c[1],s.c[2],s.c[3],s.steps);
		ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]] = true;
		states->push(s);

		// cout << "from :getState" << endl;
		// for (int i=0;i<states->size();i++){
		// 	State temptemp = states->front();
		// 	states->pop();
		// 	cout <<temptemp.c[0] <<" ";
		// 	cout << temptemp.c[1] <<" ";
		// 	cout << temptemp.c[2] <<" ";
		// 	cout << temptemp.c[3] <<" ";
		// 	states->push(temptemp);

		// cout << endl;
		// }

		// cout << endl;
	}
}

void xtoy(State s, int from, int to, queue<State> *states, bool ved[30][30][30][30]){
	// cout << from << " "<< to << endl;
	// cout << s.c[from] << " "<<s.c[to] << endl;
	if(s.c[from]+s.c[to] <= caps[to]){
		s.c[to]+=s.c[from];
		s.c[from]=0;
		// cout <<"if";
	}
	else{
		int dif = caps[to]-s.c[to];
		s.c[from]-=dif;
		s.c[to]+=dif;
		// cout <<"else";
	}
	s.steps++;
	// cout << s.c[from] << " "<<s.c[to] << endl;
	// cout << s.c[0]<<" ";
	// cout << s.c[1]<<" ";
	// cout << s.c[2]<<" ";
	// cout << s.c[3]<<" ";
	// cout << endl;
	if(!ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]]){
		//printf("fil: ved[%i][%i][%i][%i]	steps:%i\n",s.c[0],s.c[1],s.c[2],s.c[3],s.steps);
		ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]] = true;

		states->push(s);
		// for (int i=0;i<states->size();i++){
		// 	State temptemp = states->front();
		// 	states->pop();
		// 	cout <<temptemp.c[0] <<" ";
		// 	cout << temptemp.c[1] <<" ";
		// 	cout << temptemp.c[2] <<" ";
		// 	cout << temptemp.c[3] <<" ";
		// 	states->push(temptemp);

		// cout << endl;
		// }

		// cout << endl;
	}
}

int ans(queue<State> *states, bool ved[30][30][30][30]){
	//init
	states->push(State(0,0,0,0));
	ved[0][0][0][0] = true;
	
	//BFS
	int i,j;
	while(!states->empty()){
		State s = states->front();
		states->pop();
		//Checking
		for(i=0; i<4; i++)
			if(s.c[i]==target) return s.steps;	//optimal
		
		for(i=0; i<4; i++){
			set(s, i, caps[i], states, ved);	//fill
			// cout <<"1:"<< s.c[i] << " ";
			set(s, i, 0, states, ved);	//empty
			// cout <<"2:" <<s.c[i] << " ";
		}
		// cout << endl;
		// cout << states->size() << endl;
		
	// cout << "state:" << endl;
	// cout << s.c[0] <<" ";
	// cout << s.c[1] <<" ";
	// cout << s.c[2] <<" ";
	// cout << s.c[3] <<endl<<endl;

		for(i=0;i<4;i++)
			for(j=0;j<4;j++){
				if(i==j) continue;
				xtoy(s,i,j,states,ved);
				// std::cout << i << " " << j << std::endl;
				// std::cout << states->size() << std::endl;
			}
				
	}
	return -1;
}

int main(){
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	while(~scanf("%i %i %i %i %i",&capA,&capB,&capC,&capD,&target)){
		bool ved[30][30][30][30]={0};
		caps[0] = capA;
		caps[1] = capB;
		caps[2] = capC;
		caps[3] = capD;
		
		queue<State>* states = new queue<State>;
		if(capA<target && capB<target && capC<target && capD<target)
			printf("-1\n");
		else{
			printf("%i\n",ans(states,ved));
		}
		delete states;
	}
	
	return 0;
}
