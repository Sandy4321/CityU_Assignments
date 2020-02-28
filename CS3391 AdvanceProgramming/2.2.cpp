#include <iostream>
using namespace std;

int main(){

	std::ios_base::sync_with_stdio(false);
    char s[] ;
    scanf("%s",s);
   	puts(s);
	// puts("\n");
	int i;
    while(~scanf("%i",&i)){
	    printf("\n%i\n",i);
    }
}