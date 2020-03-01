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

	int pid =fork();
	if (pid == 0){
		
	}else{

		int stat_loc;
		int child_status = waitpid(pid,&stat_loc,WNOHANG ); 
		cout << "waitpid : " << child_status << endl;
		cout << "pid : " << pid << endl;
		cout << "If exited : " << WIFEXITED(stat_loc) << endl;
		cout << "If signaled : " << WIFSIGNALED(stat_loc) << endl;
		cout << endl;
		

		kill(pid,SIGSTOP);
		// sleep(1);
		kill(pid,SIGTERM);


		child_status = waitpid(pid,&stat_loc,WNOHANG ); 
		cout << "waitpid : " << child_status << endl;
		cout << "pid : " << pid << endl;
		cout << "If exited : " << WIFEXITED(stat_loc) << endl;
		cout << "If signaled : " << WIFSIGNALED(stat_loc) << endl;
		cout << endl;



		sleep(1);
		child_status = waitpid(pid,&stat_loc,WNOHANG ); 
		cout << "waitpid : " << child_status << endl;
		cout << "pid : " << pid << endl;
		cout << "If exited : " << WIFEXITED(stat_loc) << endl;
		cout << "If signaled : " << WIFSIGNALED(stat_loc) << endl;

	}

	return 0;
}