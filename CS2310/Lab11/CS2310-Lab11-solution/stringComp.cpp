#include <cstring>
#include <iostream>
using namespace std;

/*
 * 
 */
// strngCompare functon return true if s1>s2,else false.

int stringCompare(char s1[], char s2[]) {
    //longer is used to store which string is longer. 1 means s1 is longer, 
    //-1 means s2 is longer, 0 means they have the same length. 
    int size, longer = 0;

    if (strlen(s1) > strlen(s2)) {
        size = strlen(s2);
        longer = 1;
    } else if (strlen(s1) < strlen(s2)) {
        size = strlen(s1);
        longer = -1;
    } else {
        size = strlen(s1);
        longer = 0;
    }
    for (int i = 0; i < size; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }
    }
    return longer;
}

int main() {
    //Here we use pointer to store array in oder to make the copy in bubble sort easier.
    char s1[20], s2[20];
    cout << "Enter the first string:" << endl;
    cin>>s1;
    cout << "Enter the second string:" << endl;
    cin>>s2;
    int result = stringCompare(s1, s2);
    if (result == 1) {
        cout << "The first string is larger." << endl;
    } else if (result == -1) {
        cout << "The second string is larger." << endl;
    } else {
        cout << "The two strings are equal." << endl;
    }
    return 0;
}

