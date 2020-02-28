#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

class Node {
public:
	Node() { steps=new int[20];memset(steps,0,sizeof(steps));}
	int myVal;
	int* steps;
	vector<int> neighbours;

	int toNode(Node* nodes,int destination,int stepMax){
		
		for(int i= 0; i < neighbours.size() ;i++){
			if (neighbours[i] == destination ){
				return 1;
			}
		}

		int step = 1;
		bool found = false;
		while(!found){
			if (stepMax < step){
				return -1;
			}
			for (int i = 0; i< neighbours.size();i++){
				int res =nodes[neighbours[i]].toNode(nodes,destination,step-1);
				if (res != -1){
					return 1+step;
				}
			}
			step++;
		}
	}

};

int main() {

	int numConnectedNode;
	int connectTo;
	int caseN = 0;
	while (cin >> numConnectedNode) {

		Node* nodes = new Node[20];
		bool called[20] ={false} ;

		nodes[0].myVal = 0;
		while (numConnectedNode--) {
			cin >> connectTo;
			nodes[0].steps[connectTo - 1] = 1;
			nodes[connectTo - 1].steps[0] = 1;
			nodes[0].neighbours.push_back(connectTo-1);
			nodes[connectTo-1].neighbours.push_back(0);
		}

		for (int i = 1; i < 19;i++) {
			cin >> numConnectedNode;
			nodes[i].myVal = i;
			while (numConnectedNode--) {
				cin >> connectTo;
				nodes[i].steps[connectTo - 1] = 1;
				nodes[connectTo - 1].steps[i] = 1;
				nodes[i].neighbours.push_back(connectTo-1);
			nodes[connectTo-1].neighbours.push_back(i);
			}
		}
		nodes[19].myVal = 19;


		caseN ++;
		cout << "Test Set #"<<caseN << endl;
		int n,a,b ;
		cin >> n;
		while(n--){
			
			cin >> a >> b;
			printf("%2i to %2i:%2i\n",a,b,nodes[a-1].toNode(nodes,b-1,20));
			// cout << nodes[a-1].toNode(nodes,b-1,20) << endl;
		}
	cout << endl;




	}



	return 0;
}