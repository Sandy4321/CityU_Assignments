#include <iostream>
// #include <cmath>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int start_x = 0, start_y = 0, end_x = rand() % 5, end_y = rand() % 5;
	int pos_x = start_x, pos_y = start_y;
	int move;
	int temp_x, temp_y;
	char maze[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == end_y && j == end_x)
			{
				maze[i][j] = 'x';
			}
			else if (i == start_y && j == start_x)
			{
				maze[i][j] = 'o';
			}
			else
			{
				maze[i][j] = '-';
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}

	do
	{
		cout << "Input a direction number (1:up 2:down 3:left 4:right): " << endl;

		cin >> move;

		switch (move)
		{
		case 1:
			pos_y -= 1;
			break;
		case 2:
			pos_y += 1;
			break;
		case 3:
			pos_x -= 1;
			break;
		case 4:
			pos_x += 1;
		}

		if (pos_x >= 0 && pos_x < 5 && pos_y >= 0 && pos_y < 5)
		{
			maze[pos_y][pos_x] = 'o';
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << maze[i][j];
				}
				cout << endl;
			}
			cout << end_x << ',' << end_y<<','<<pos_x<<','<<pos_y<<endl;
		}
		else
		{
			cout << "Outside the maze!" << endl;
			if (pos_x < 0)
			{
				pos_x = 0;
			}
			else if (pos_x > 4)
			{
				pos_x = 4;
			}
			else if (pos_y < 0)
			{
				pos_y = 0;
			}
			else
			{
				pos_y = 4;
			}
		}

	} while (pos_x != end_x || pos_y != end_y);
	cout << "Successful!";
	return 0;
}