#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    double x1, x2, y1, y2, dx, dy;
    double s1, s2;
	double max = 99999999;
    cout << "Enter the points on the first line:" << endl;
    cin >> x1 >> y1 >> x2>>y2;
    dx = x1 - x2;
    dy = y1 - y2;
    if (dx <= 0.0001 && dx >= -0.0001) {
        s1 = max;
    } else {
        s1 = dy / dx;
    }
    cout << "Enter the points on the second line:" << endl;
    cin >> x1 >> y1 >> x2>>y2;
    dx = x1 - x2;
    dy = y1 - y2;
    if (dx <= 0.0001 && dx >= -0.0001) {
        s2 = max;
    } else {
        s2 = dy / dx;
    }
    if (s1 - s2 <= 0.0001 && s1 - s2 >= -0.0001) {
        cout << "The two straight lines have no intersections." << endl;
    } else {
        cout << "The two straight lines have an intersection." << endl;
    }
    return 0;
}

