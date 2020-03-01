#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(){
	int *i;
	int pid = fork();
	if ( pid == 0 )
	{
		wait(i);
		cout << "abc"<<endl<<endl;
	} else {
		execv("O",nullptr);
	}
	// cout << pid << endl;
	// wait(i);
	std::cout << "abc";
	return 0;
}