/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include <stdio.h>
#include <iostream>
#define oo 0x3f3f3f3f //https://www.kawabangga.com/posts/1153
using namespace std;

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

const int f5hours = 5 * 60 * 60;

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	while (true)
	{
		//init
		int signals[100];
		int p = 0;
		int green[100] = {0};

		//input
		while (~scanf("%i", &signals[p]))
			if (signals[p++] == 0)
				break; //terminated
		p -= 1;

		if (signals[0] == 0)
			break; //Must be All 0

		int i, j;

		int startSec = oo;
		for (i = 0; i < p; i++)
			startSec = min(startSec, signals[i]);

		int syncTime = 1;
		for (i = startSec; i <= f5hours; i++)
		{

			bool synced = true;
			for (j = 0; j < p; j++)
			{

				while (i >= signals[j] - 5 + green[j])
					green[j] += signals[j] * 2;

				if (!(green[j] <= i &&
					  i < green[j] + signals[j] - 5))
				{
					syncTime = i = green[j] - 1;
					synced = false;
					break;
				}
			}
			if (synced)
				break;
		}

		syncTime += 1;

		if (syncTime > f5hours)
			puts("Signals fail to synchronise in 5 hours");
		else
			printf("%02d:%02d:%02d\n", syncTime / 60 / 60, syncTime % 3600 / 60, syncTime % 60);
	}

	return 0;
}
