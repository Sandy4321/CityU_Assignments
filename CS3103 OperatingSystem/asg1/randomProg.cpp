#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
using namespace std;

int main(){
	
	int pid = fork();
	if (pid == 0){
		cout << "I am a child" << endl;
	}else{
		int i = 0;
		while (true){
			sleep(2);
			cout << pid << endl;
				int pid2 = waitpid(pid,NULL,0);
				cout <<  pid2 << endl;	
			
		}
	}

	return 0;
}