#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>

using namespace std;

int main()
{
	int pid;
	int task;
	cin >> pid;
	cin >> task;
	if (task == 1){
		kill (pid,SIGSTOP);
	}else if (task == 2){
		kill(pid,SIGCONT);
	}else if (task == 3){
		kill(pid,SIGTERM);
	}
	return 0;
}