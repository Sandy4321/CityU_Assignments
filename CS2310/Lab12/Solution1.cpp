#include <iostream>
using namespace std;

char* deleteStr(char* str, char delete_char){
	for (int i =0; i < strlen(*str);i++){
		if (*str[i] == delete_char){
			int temp=0;
			for(temp= i ; temp < (strlen(*str)-1);temp++){
				*str[j] = *str[j+1];
			}
			*str[temp+1] = '\0';
		}
	}
}

int main(){

	char str[100];
	char delete_char;
	cout << "Enter the input string:";
	cin >> cin.getline(str,100);
	cout << "Enter the input delete_char:";
	cint >> cin.get(delete_char);
	cout << "The modified string is:";



	return 0;
}