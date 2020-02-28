#include <iostream>
#include <stdio.h>
using namespace std;

struct WeightAndStability {
	WeightAndStability(int weigh, bool stabilit):weight(weigh), stability(stabilit) {}
	int weight;
	bool stability;
};

WeightAndStability computeStabality() {
	int w1, w2, d1, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1 == 0) {
		WeightAndStability ws1 = computeStabality();
		if (ws1.stability) {
			w1 = ws1.weight;
		}
		else {
			w1 = -1;
		}
	}
	if (w2 == 0) {
		WeightAndStability ws2 = computeStabality();
		if (ws2.stability) {
			w2 = ws2.weight;
		}
		else {
			w2 = -1;
		}
	}

	if (w1*d1 == w2*d2) {
		return WeightAndStability(w1 + w2, true);
	}
	else {
		return WeightAndStability(0,false);
	}

}


int main() {
	int T;
	scanf("%d",&T);
	char next;
	getchar();
	while (T--) {
		cout << (computeStabality().stability? "YES":"NO")<<endl;
		if (T) {
			cout << endl;
		}
		getchar();
	}


	return 0;
}
