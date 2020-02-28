#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

struct Node{
	vector<Node*> follower;
	bool falled = false;
	int name;
};

int fall(Node& x){
	if (x.falled){
		return 0;
	}else{
		int totalFalling = 1;
		x.falled = true;
		for (int i = 0; i < x.follower.size() ; i++) {
			totalFalling += fall(*(x.follower[i]));
		}
		return totalFalling;
	}
}

int main() {

	int T;
	cin >> T;
	int n, m ,l;
	// vector <Node> all;
	int x,y;
	while(T--){

		cin >> n >> m >>l;

		Node all[n+1];

		while(m--){
			cin >> x >> y;
			all[x].follower.push_back(all+y);
			all[x].name= x;
		}

		int totalFalling =0 ;

		while (l--){
			cin >> x;

			totalFalling += fall(all[x]);
		}

		cout << totalFalling << endl;


		// remember to clear vector

	}



	return 0;
}