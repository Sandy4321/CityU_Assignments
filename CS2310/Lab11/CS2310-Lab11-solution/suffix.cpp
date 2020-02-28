#include <iostream>
#include <cstring>

using namespace std;

/*
 * 
 */
bool stringCompare(char* s1, char* s2){
    int size;
    //longer is used to store which string is longer. true means s1 is longer.
    bool longer = true;
    if(strlen(s1)>strlen(s2)){
        size = strlen(s1);
    }else{
        size = strlen(s2);
        longer = false;
    }
    for(int i = 0; i<size; i++){
        if(s1[i]>s2[i]){
            return true;
        }else if(s1[i]<s2[i]){
            return false;
        }
    }
    if(longer){
        return true;
    }else{
        return false;
    }
}
int main() {
    char s[100];
    cout<<"Enter the string:"<<endl;
    cin>>s;
    int len = strlen(s);
    char** suffix = new char*[len];
    for(int i = 0; i<len;i++){
        suffix[i] = new char[len+1];
        int k = i, j;
        for( j = 0; j<len-i;j++){
            suffix[i][j] = s[k++];
        }
        suffix[i][j] = '\0';
    }
    for(int i = 0; i<len -1; i++){
       for (int j = 0; j < len - 1 - i; j++) 
           if (stringCompare(suffix[j],suffix[j+1])) {
               char* temp;
               temp = suffix[j];
               suffix[j] = suffix[j+1];
               suffix[j+1] = temp;
           }
    }
    cout<<"The suffixes of the string are:"<<endl;
    for(int i = 0; i<len; i++){
        cout<<suffix[i]<<endl;
        delete[] suffix[i];
    }
    delete[] suffix;
    return 0;
}

