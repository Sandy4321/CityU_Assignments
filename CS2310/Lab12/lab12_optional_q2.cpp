#include <iostream>
#include <string.h>
using namespace std;


int compareStr(char* a, char* b){
	int len1 = strlen(a);
	int len2 = strlen(b);
	int len;

	if(len1 > len2)
		len = len2;
	else
		len = len1;

	for(int i = 0; i < len; i++){
		if(a[i] > b[i])
			return 1;
		else if(a[i] < b[i])
			return -1;
		else 
			continue;
	}
	if(len1 == len2)
		return 0;
	if(len1 > len2)
		return 1;
	if(len1 < len2)
		return -1;
}

void sortStr(char** str, int num){
	for(int i = 0; i < num - 1; i++){
		for(int j = 0 ; j < num - 1; j++)
			if( compareStr(str[j], str[j+1]) > 0 ){
				char* temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
	}
}


int main(){
	int num;
	cout << "Enter the number of strings: ";
	cin >> num;
	char** str = new char* [num];
	
	cout << "Enter the input strings: ";
	for (int i = 0; i < num; i++){
		str[i] = new char[100];
		cin >> str[i];
	}

	sortStr(str, num);
	cout << "Sorted result: ";
	for (int i = 0; i < num; i++){
		cout << str[i] << " ";
	}
	cout << endl;
	return 0;
}