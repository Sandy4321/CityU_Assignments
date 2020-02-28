#include <iostream>
#include <string>
using namespace std;

int nOfRow;
int nOfCol;
int **a;
int *rowDecider, *colDecider;

int lastFlipRow = 0;
int lastFlipCol = 0;

void print()
{
	for (int r = 0; r < nOfRow; r++)
	{
		for (int c = 0; c < nOfCol; c++)
		{
			cout << a[r][c] << " ";
		}
		cout << endl;
	}
}

void decide()
{
	for (int c = 0; c < nOfCol; c++)
	{
		colDecider[c] = 0;
	}
	for (int r = 0; r < nOfRow; r++)
	{
		rowDecider[r] = 0;
		for (int c = 0; c < nOfCol; c++)
		{
			rowDecider[r] += a[r][c] ? 1 : -1;
			colDecider[c] += a[r][c] ? 1 : -1;
		}
	}
}

bool checkMaybe()
{
	for (int r = 0; r < nOfRow; r++)
	{
		if (rowDecider[r] < 0)
		{
			return true;
		}
	}

	for (int c = 0; c < nOfCol; c++)
	{
		if (colDecider[c] < 0)
		{
			return true;
		}
	}

	for (int r = nOfRow - 1; r >= 0; r--)
	{
		if (rowDecider[r] == 0)
		{
			if (lastFlipRow == r)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	for (int c = nOfCol - 1; c >= 0; c--)
	{
		if (colDecider[c] == 0)
		{
			if (lastFlipCol == c)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}

void flipRow(int row)
{

	for (int i = 0; i < nOfCol; i++)
	{
		a[row][i] = a[row][i] ? 0 : 1;
	}
}
void flipCol(int col)
{
	for (int i = 0; i < nOfRow; i++)
	{
		a[i][col] = a[i][col] ? 0 : 1;
	}
}

int main()
{
	bool flipped = false;
	int whileLoopExecuted = 0;
	while (cin >> nOfRow >> nOfCol)
	{
		a = new int *[nOfRow];
		rowDecider = new int[nOfRow];
		colDecider = new int[nOfCol];

		string s;
		for (int r = 0; r < nOfRow; r++)
		{
			a[r] = new int[nOfCol];
			cin >> s;
			for (int c = 0; c < nOfCol; c++)
			{
				a[r][c] = s[c] - 48;
			}
		}

		decide();
		while (checkMaybe())
		{
			flipped = false;
			for (int r = 0; r < nOfRow; r++)
			{
				if (rowDecider[r] < 0)
				{
					flipRow(r);
					flipped = true;
				}
			}

			if (flipped)
			{
				lastFlipRow = lastFlipCol = -1;
				decide();
			}
			else
			{

				for (int c = 0; c < nOfCol; c++)
				{
					if (colDecider[c] < 0)
					{
						flipCol(c);
						flipped = true;
					}
				}
				if (flipped)
				{
					lastFlipRow = lastFlipCol = -1;
					decide();
				}
				else
				{
					for (int r = 0; r < nOfRow && !flipped; r++)
					{
						if (rowDecider[r] == 0 && r > lastFlipRow)
						{
							lastFlipRow = r;
							flipRow(r);
							flipped = true;
						}
					}
					if (flipped)
					{
						decide();
					}
					else
					{
						for (int c = 0; c < nOfCol; c++)
						{
							if (colDecider[c] == 0 && c > lastFlipCol)
							{
								lastFlipCol = c;
								flipCol(c);
								break;
							}
						}
						decide();
					}
				}
			}

			// print();
		}
		cout << endl;
		print();

		int total = 0;

		for (int i = 0; i < nOfRow; i++)
		{
			for (int j = 0; j < nOfCol; j++)
			{
				total += a[i][j];
			}
		}
		cout << total << endl;
	}

	return 0;
}