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

void bg(
	char **arg_for_program,
	int *bg_flag,
	pid_t &bg_pid)
{
	// 1. update child process condition explicitly
	int stat_loc;
	int child_cond = waitpid(bg_pid, &stat_loc, WNOHANG);
	if (child_cond == -1)
	{
		// child does not exist
		if (errno == ECHILD)
		{
			*bg_flag = 0;
			bg_pid = 0;
		}
	}
	else if (child_cond > 0)
	{
		// detect if child is terminated
		if (WIFEXITED(stat_loc) || WIFSIGNALED(stat_loc))
		{
			*bg_flag = 0;
			bg_pid = 0;
		}
	}

	// 2. evaluate flag
	if (*bg_flag == 0)
	{
		// 3. name is null?
		if (arg_for_program != NULL && strlen(arg_for_program[0]) > 2)
		{
			bg_pid = fork();

			if (bg_pid == 0) // child process
			{
				// 4. change process image of child

				string file_name = arg_for_program[0];
				if (file_name.find("./") != 0)
				{
					file_name = "./" + file_name;
				}
				int status = execvp(file_name.c_str(), arg_for_program);

				if (status == -1) // if failed to change
				{
					cout << "execvp() is failed." << endl;
					exit(EXIT_FAILURE); // kill self(child)
				}
			}
			else // parent process
			{
				if (bg_pid == -1) // child failed to fork
				{
					cout << "Failed to fork, error code: " << endl;
					exit(EXIT_FAILURE);
					bg_pid = 0;
				}
				else // successfully forked
				{
					cout << "pid: " << bg_pid << endl;
					*bg_flag = 1;
				}
			}
		}
		else
		{
			cout << "Error: Name is null. Please provide a file name." << endl;
		}
	}
	else
	{
		cout << "Error: there is a backgroundprocess already" << endl;
	}
}

// if signal succesfully sent return true, else return false
bool sendSignal(pid_t pid, int signal, pid_t bg_pid)
{
	if (pid > 0 & bg_pid == pid)
	{
		int error_status = kill(pid, signal);
		if (error_status == -1)
		{
			if (errno == EPERM)
			{
				cout << "The pid is not a valid process id of a background process." << endl;
			}
			else
			{
				cout << "kill() is failed" << endl;
			}
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		cout << "The pid is not a valid process id of a background process." << endl;
		return false;
	}
}

void bgKill(pid_t pid, int &bg_flag, pid_t &bg_pid)
{
	// if flag is running or stopped
	if (bg_flag == 2 || bg_flag == 1)
	{
		if (sendSignal(pid, SIGTERM, bg_pid))
		{
			cout << "Terminated : " << pid << endl;
			bg_flag = 0;
			bg_pid = 0;
		}
	}
	else
	{
		cout << "No background process to kill." << endl;
	}
}

void bgStop(pid_t pid, int &bg_flag, pid_t &bg_pid)
{
	// if flag is running
	if (bg_flag == 1)
	{

		if (sendSignal(pid, SIGSTOP, bg_pid))
		{
			cout << "Stopped : " << pid << endl;
			bg_flag = 2;
		}
	}
	else
	{
		cout << "No running background process to stop" << endl;
	}
}

void bgStart(pid_t pid, int &bg_flag, pid_t &bg_pid)
{
	// if flag is stopped
	if (bg_flag == 2)
	{
		if (sendSignal(pid, SIGCONT, bg_pid))
		{
			cout << "Started : " << pid << endl;
			bg_flag = 1;
		}
	}
	else
	{
		cout << "No stopped background process to start." << endl;
	}
}

void checkChildCond( int &bg_flag,pid_t &bg_pid)
{
	// ==== detect child condition ====
	int stat_loc;
	int child_cond = waitpid(bg_pid, &stat_loc, WNOHANG);
	if (child_cond == bg_pid)
	{
		// make sure child didn't terminated
		if (WIFEXITED(stat_loc) || WIFSIGNALED(stat_loc))
		{
			bg_flag = 0;
			bg_pid = 0;
		}
	}
}

int main()
{
	cout << " ===== Welcome to PMan =====" << endl;
	cout << "This process have pid: " << getpid() << endl;
	int bg_flag = 0;
	pid_t bg_pid;
	while (true)
	{
		// ==== getting input ====
		cout << "PMan: > ";
		char str_input[4096];
		cin.getline(str_input, 4096);

		// ==== extract tokens ====
		char *token = strtok(str_input, " ");
		if (token == NULL)
		{
			continue;
		}

		string cmd = token;

		char *tokens[256];
		int i = 0;
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			if (token != NULL)
			{
				tokens[i++] = token;
			}
		}

		// ==== evaluate ====
		if (cmd == "")
		{
			cout << "Empty input please try command : bg file_name [arg1] [arg2] ... | bgkill [pid] | bgstop [pid] | bgstart [pid] | exit" << endl;
		}
		else if (cmd == "bg")
		{
			if (tokens[0] == NULL)
			{
				cout << "Not enough arguments" << endl;
			}
			else
			{
				bg(tokens, &bg_flag, bg_pid);
			}
		}
		else if (cmd == "bgkill")
		{
			checkChildCond(bg_flag,bg_pid);
			bgKill(atoi(tokens[0]), bg_flag, bg_pid);
		}
		else if (cmd == "bgstop")
		{
			checkChildCond(bg_flag,bg_pid);
			bgStop(atoi(tokens[0]), bg_flag, bg_pid);
		}
		else if (cmd == "bgstart")
		{
			checkChildCond(bg_flag,bg_pid);
			bgStart(atoi(tokens[0]), bg_flag, bg_pid);
		}
		else if (cmd == "exit")
		{
			checkChildCond(bg_flag,bg_pid);
			if (bg_flag != 0){
				bgKill(bg_pid,bg_flag,bg_pid);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			cout << "Command not found." << endl;
		}
	}
	return 0;
}