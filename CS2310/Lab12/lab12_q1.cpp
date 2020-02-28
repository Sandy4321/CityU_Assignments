#include <iostream>
using namespace std;

char* deleteStr(char* str, char d_char){
	int count = 0;
	int length = 0;
	char* p = str;
	while(*p != '\0'){
		length++;
		if(*p == d_char)
			count++;
		p++;
	}

	char* result = new char[length - count + 1];
	char* q = result + (length - count );
	*q = '\0';
	q--;
	p = str + length - 1;

	while(p >= str){
		if(*p != d_char){
			*q = *p;
			q--;
			p--;
		}
		else
			p--;
	}
	return result;
}

int main(){
	char s[100];
	char delete_char;
	
	cout << "Enter the input string: ";
	cin.getline(s, 100);	
	cout << "Enter the input delete_char: ";
	cin.get(delete_char);
	char* str = s;
	
	char* result;
	result = deleteStr(str, delete_char);
	cout << "The modified string is: " << result << endl;
	return 0;
}
	