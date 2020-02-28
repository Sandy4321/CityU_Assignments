#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

class Pos {
public:
	Pos(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double x;
	double y;

	double distanceTo(Pos* a) {
		return sqrt( pow(a->x - this->x, 2) + pow(a->y - this->y, 2));
	}




};

int main() {

	int n;
	Pos *freddy,*fiona;
	vector<Pos> otherStones;
	while (cin >> n && n != 0) {
		otherStones = vector<Pos>();
		double x, y;
		cin >> x >> y;
		freddy = new Pos(x,y);
		cin >> x >> y;
		fiona = new Pos(x, y);
		n -= 2;
		while (n--) {
			cin >> x >> y;
			otherStones.push_back(new Pos(x,y));


		}

	}




	return 0;
}