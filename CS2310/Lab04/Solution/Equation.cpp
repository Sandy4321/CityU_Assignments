#include <iostream>
#include <cmath>
using namespace std;

/*
 * 
 */
int main() {
    cout << "Enter the value of a, b and c for quadratic equation:" << endl;
    double a, b, c, ans1, ans2, delta;
    cin >> a >> b>>c;
    delta = b * b - 4 * a*c;
    if (a == 0) {
        ans1 = (-1)*(c / b);
        cout << "The linear equation has one real root." << endl;
        cout << "The root is " << ans1<< endl;
    } else if (delta > 0) {
        ans1 = (sqrt(delta) - b) / (2 * a);
        ans2 = (-sqrt(delta) - b) / (2 * a);
        cout << "The Quadratic Equation has two real roots." << endl;
        cout << "The roots are " << ans1 << " and " << ans2 << endl;
    } else if (delta == 0) {
        ans1 = (-b) / (2 * a);
        cout << "The Quadratic Equation has one real root." << endl;
        cout << "The root is " << ans1 << endl;
    } else {
        double real, im;
        real = (-b) / (2 * a);
        im = (sqrt(-delta)) / (2 * a);
        cout << "The Quadratic Equation has two Complex roots." << endl;
        cout << "The roots are " << real << '+' << im << "i and " << real << '-' << im << 'i' << endl;
    }
    return 0;
}

