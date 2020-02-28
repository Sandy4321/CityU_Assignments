#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
// using namespace std;
int main(){

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}

	std::string s;
	while(getline(std::cin,s)){
		std::reverse(s.begin(),s.end());
		for(int i = 0 ;i < s.size() ; i++){
			if (s[i] >= 'A' && s[i] <= 'Z'){
				std::cout << (char)(s[i] - 'A' + 'a');
			}else if (s[i] >= 'a' && s[i] <= 'z'){
				std::cout << (char)(s[i] - 'a' + 'A');
			}else{
				std::cout << s[i];
			}
		}
		printf("\n");
	}

	return 0;
}