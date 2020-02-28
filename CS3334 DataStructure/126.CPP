#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include "126.h"

using namespace std;

struct Step {
	Step() { step = 0;link = 0; }
	int step;
};

class Node {
public:
	Node() { }
	int myVal;
	int* steps = new int[20];
};

int main() {

	int numConnectedNode;
	int connectTo;
	while (cin >> numConnectedNode) {

		Node* nodes = new Node[20];


		nodes[0].myVal = 1;
		while (numConnectedNode--) {
			cin >> connectTo;
			nodes[0].steps[connectTo - 1] = 1;
		}

		for (int i = 1; i < 20;i++) {
			cin >> numConnectedNode;
			nodes[i].myVal = i + 1;
			while (numConnectedNode--) {
				cin >> connectTo;
				nodes[i].steps[connectTo - 1] = 1;
			}

			for (int j = 0;j < i;j++) {
				// use my value to update urself


				// if I can go to you
				if (nodes[i].steps[j] != 0) {

					// update other, go from j+1 to 20
					for (int k = j + 1;k < 20; k++) {
						if (nodes[i].steps[k]) {
							// if you to him is 0
							if (nodes[j].steps[k] == 0 ) {
								nodes[j].steps[k] = nodes[i].steps[j] + nodes[i].steps[k];
							}else{
								if (nodes[i].steps[j] + nodes[i].steps[k] < nodes[j].steps[k]) {
									nodes[j].steps[k] = nodes[i].steps[j] + nodes[i].steps[k];
								}
							}
						}
					}
				}
			}

			//from me to anyone else;


		}

		solveMin();




	}



	return 0;
}