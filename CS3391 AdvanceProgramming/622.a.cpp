/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include <iostream>
#include <string>
#include <string.h>

#define _(x) {std::cout << #x << " = " << x << " ";}
// using namespace std;

#define MAXL 1000005

char s[MAXL], ans[MAXL];
std::string ACGT = "ACGT";

int count[MAXL];
int nxt[MAXL][4] = {0};

int itr;

int oDepth, oNum;

//DNA base to array index
int b2c(char c)
{
	if (c == 'A')
		return 0;
	if (c == 'C')
		return 1;
	if (c == 'G')
		return 2;
	if (c == 'T')
		return 3;
}

void insertN(int i, char sfx[])
{
	count[i]++;
	if (sfx[0] == '\0')
	{
		return;
	}
	else
	{
		int &newi = nxt[i][b2c(sfx[0])];
		if (newi == -1)
		{
			newi = itr++;
		}
		insertN(newi, sfx + 1);
	}
	
}

void wSearch(int i, int d)
{
	s[d] = 0;
	if (count[i] > 1 && d > oDepth)
	{
		oNum = count[i];
		oDepth = d;
		strcpy(ans, s);
	}

	for (int j = 0; j < 4; j++)
		if (nxt[i][j] != -1)
		{
			s[d] = ACGT[j];
			wSearch(nxt[i][j], d + 1);
		}
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while (t--)
	{
		std::cin >> s;

		//Init
		memset(count, 0, sizeof(count));
		memset(nxt, -1, sizeof(nxt));
		itr = 1;

		int i;
		// for every suffix of s
		for (i = 0; i < strlen(s); i++)
			insertN(0, s + i);

		// for(i=0;i<strlen(s) ; i++){
		// 	_(count[i]);
		// }
		for (int k = 0; k < 4; k++)
		{
			printf("%c: ", ACGT[k]);
			for (int j = 0; j < strlen(s); j++)
			{
				printf("%3d ",nxt[j][k]);
			}
			printf("\n");
		}

		oNum = oDepth = 0;
		wSearch(0, 0);

		if (oNum > 0)
			std::cout<< ans << " " << oNum << std::endl;
		else
			std::cout<< "No repetitions found!" << std::endl;
	}

	return 0;
}
