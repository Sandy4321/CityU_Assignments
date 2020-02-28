#include <iostream>
using namespace std;

char* replace(char* str, char* space){
	
	int len1 = 0;
	int len2 = 0;
	int count = 0;
	char* p = str;

	while(*p != '\0'){
		len1++;
		if(*p == ' ')
			count++;
		p++;
	}
	p = space;

	while(*p != '\0'){
		len2++;
		p++;
	}

	int n = len1 + count*(len2 - 1) + 1;
	char* result = new char[n];
	char* q = result + n - 1;
	*q = '\0';						// Add NULL at end of result array
	q--;							// Now q points to end of result;

	p = str + len1 - 1;				// p points to end of str;
	char* r = space + len2 - 1;		// r points to end of space;


	while(p >= str){
		if(*p != ' '){
			*q = *p;
			q--;
			p--;
		}
		else{
			for(int i = 0; i < len2; i++){
				*q = *r;
				q--;
				r--;
			}
			r = space + len2 -1;
			p--;
		}	
	}
	return result;
		
}

int main(){
	char s[100];
	char spa[100];
	
	cout << "Enter the input string: ";
	cin.getline(s, 100);
	cout << "Enter the input space str: ";
	cin.getline(spa, 100);

	char* str = s;
	char* space = spa;

	cout << "The replaced string is: " << replace(str, space) << endl;
	return 0;
}
	