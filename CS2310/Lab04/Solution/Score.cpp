#include <iostream>
using namespace std;

/*
 * 
 */
int main() {
    int s1, s2, s3, s4, s5, s6;
    cout << "Enter Value of each score:" << endl;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
    int min1, min2, max1, max2;

    if (s1 > s2) {
        min1 = s2;
        min2 = s1;
        max1 = s1;
        max2 = s2;
    } else {
        min1 = s1;
        min2 = s2;
        max1 = s2;
        max2 = s1;
    }

    // assert: min1 <= min2; max1 >= max2

    int sum = s1 + s2 + s3 + s4 + s5 + s6;
    if (s3 <= min1) {
        min2 = min1;
        min1 = s3;
    } else if (s3 < min2)
        min2 = s3;
    if (s3 >= max1) {
        max2 = max1;
        max1 = s3;
    } else if (s3 > max2)
        max2 = s3;

    if (s4 <= min1) {
        min2 = min1;
        min1 = s4;
    } else if (s4 < min2)
        min2 = s4;
    if (s4 >= max1) {
        max2 = max1;
        max1 = s4;
    } else if (s4 > max2)
        max2 = s4;

    if (s5 <= min1) {
        min2 = min1;
        min1 = s5;
    } else if (s5 < min2)
        min2 = s5;
    if (s5 >= max1) {
        max2 = max1;
        max1 = s5;
    } else if (s5 > max2)
        max2 = s5;

    if (s6 <= min1) {
        min2 = min1;
        min1 = s6;
    } else if (s6 < min2)
        min2 = s6;
    if (s6 >= max1) {
        max2 = max1;
        max1 = s6;
    } else if (s6 > max2)
        max2 = s6;
    double score = (sum - min1 - min2 - max1 - max2) / 2.0;
    cout << "The effective score is: " << score << endl;
    return 0;
}

