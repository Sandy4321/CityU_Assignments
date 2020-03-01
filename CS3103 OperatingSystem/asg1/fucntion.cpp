#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cerrno>
#include <cstring>
using namespace std;


int main(){

	int pid = fork();
	if (pid == 0){

	}else{
		sleep(2);
		// while (true){
			cout << waitpid(pid,NULL,WNOHANG)<<endl;
			int killError =  kill(pid,SIGSTOP);
			cout << killError << endl;
			if (killError == -1){
				cout << "ESRCH : " << (errno == ESRCH) << endl;
				cout << "EPERM : " << (errno == EPERM) << endl;
			}
			// sleep(1);
		// }
	}


	return 0;
}