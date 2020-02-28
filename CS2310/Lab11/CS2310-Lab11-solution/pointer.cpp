#include <cstring>
#include <iostream>
using namespace std;
void findWord(char arr[], int* i, int* count){
    int begin = *i;
    *count = *count + 1;
    while(*i<strlen(arr) && arr[*i]!=' '){
        *i = *i + 1;
    }
    cout<<"Word "<<*count<<" has "<<*i - begin<<" characters."<<endl;
}
int main() {
    cout<<"Enter the content of the string:"<<endl;
    char arr[50];
    cin.getline(arr,50);
    int count = 0;
    for(int i = 0; i<strlen(arr); i++){
        if(arr[i]!=' '){
            findWord(arr, &i, &count);
        }
    }
    cout<<"The number of words in the string is: "<<count<<endl;
    return 0;
}
