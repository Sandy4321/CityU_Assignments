#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>

using namespace std;

int main()
{

	int pid = fork();
	// int pid = 10;
	if (pid > 0)
	{

		// kill(pid,SIGSTOP);

		// sleep(2);
		while (true)
		{
			
			// cout << "Who First" << endl;
			int stat_loc;
			int child_status_changed_pid = waitpid(-1, &stat_loc, WNOHANG);

			if (child_status_changed_pid == 0)
			{
				// cout << "No change state" << endl;

				if (WIFEXITED(stat_loc))
				{
					// cout << "Exited" << endl;
					// break;
				}
				if (WIFSIGNALED(stat_loc))
				{
					cout << "Exited with Signal" << endl;
					cout << WTERMSIG(stat_loc) << endl;
				}
				if (WIFSTOPPED(stat_loc))
				{
					cout << "Stop" << endl;
				}
				if (WIFCONTINUED(stat_loc))
				{
					cout << "Resume" << endl;
				}
			}
			else if (child_status_changed_pid == -1)
			{
				cout << "Error" << endl;
				break;
			}
			else
			{
				cout << "Changed state : " << pid << " : ";
				if (WIFEXITED(stat_loc))
				{
					cout << "Exited" << endl;
				}
				if (WIFSIGNALED(stat_loc))
				{
					cout << "Exited with Signal" << endl;
					cout << "term by: " << WTERMSIG(stat_loc) << endl;
				}
				if (WIFSTOPPED(stat_loc))
				{
					cout << "Stop" << endl;
				}
				if (WIFCONTINUED(stat_loc))
				{
					cout << "Resume" << endl;
				}
				// break;
			}
		}

		// cout << endl
		// 	 << endl
		// 	 << "second attempt" << endl;
		// 	 int stat_loc;
		// int child_status_changed_pid = waitpid(-1, &stat_loc, WUNTRACED);

		// if (child_status_changed_pid == 0)
		// {
		// 	cout << "No change state" << endl;

		// 	if (WIFEXITED(stat_loc))
		// 	{
		// 		cout << "Exited" << endl;
		// 	}
		// 	if (WIFSIGNALED(stat_loc))
		// 	{
		// 		cout << "Exited with Signal" << endl;
		// 		cout << WTERMSIG(stat_loc) << endl;
		// 	}
		// 	if (WIFSTOPPED(stat_loc))
		// 	{
		// 		cout << "Stop" << endl;
		// 	}
		// 	if (WIFCONTINUED(stat_loc))
		// 	{
		// 		cout << "Resume" << endl;
		// 	}
		// }
		// else if (child_status_changed_pid == -1)
		// {
		// 	cout << "Error" << endl;
		// }
		// else
		// {
		// 	cout << "Changed state : " << pid << " : ";
		// 	if (WIFEXITED(stat_loc))
		// 	{
		// 		cout << "Exited" << endl;
		// 	}
		// 	if (WIFSIGNALED(stat_loc))
		// 	{
		// 		cout << "Exited with Signal" << endl;
		// 		cout << "term by: " << WTERMSIG(stat_loc) << endl;
		// 	}
		// 	if (WIFSTOPPED(stat_loc))
		// 	{
		// 		cout << "Stop" << endl;
		// 	}
		// 	if (WIFCONTINUED(stat_loc))
		// 	{
		// 		cout << "Resume" << endl;
		// 	}
		// }
	}
	else
	{
		cout << "Me First, pid : "  << getpid() << endl;
		// TERM
		// raise(SIGTERM);
		// // STOP
		// kill(getpid(),SIGSTOP);
		// // RESUME
		// raise (SIGCONT);
		int i = 5;
		// while (true)
		// {
		// 	sleep(2);
		cin >> i;
			i --;
			cout << 1/i <<endl;
 			cout << "hey" <<endl;
		// }
	}

	return 0;
}