#include <cstring>
#include <iostream>
using namespace std;

/*
 * 
 */
// strngCompare functon return true if s1>s2,else false.

bool stringCompare(char s1[], char s2[]) {
    int size;
    //longer is used to store which string is longer. true means s1 is longer.
    bool longer = true;
    if (strlen(s1) > strlen(s2)) {
        size = strlen(s2);
    } else {
        size = strlen(s1);
        longer = false;
    }
    for (int i = 0; i < size; i++) {
        if (s1[i] > s2[i]) {
            return true;
        } else if (s1[i] < s2[i]) {
            return false;
        }
    }
    if (longer) {
        return true;
    } else {
        return false;
    }
}

void swap(char s1[], char s2[]) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    char temp[20];
    int i;
    for (i = 0; i < l1; i++) {
        temp[i] = s1[i];
    }
    for (i = 0; i < l2; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    for (i = 0; i < l1; i++) {
        s2[i] = temp[i];
    }
    s2[i] = '\0';
}

int main() {
    //Here we use pointer to store array in oder to make the copy in bubble sort easier.
    char s[15][20];
    int number;
    cout << "Enter the number of the strings:" << endl;
    cin>>number;
    cout << "Enter the contents of each string:" << endl;
    for (int i = 0; i < number; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - 1 - i; j++)
            if (stringCompare(s[j], s[j + 1])) {
                swap(s[j],s[j+1]);
            }
    }
    cout << "The sorted strings are:";
    for (int i = 0; i < number; i++) {
        cout << endl << s[i];
    }
    cout << endl;
    return 0;
}

