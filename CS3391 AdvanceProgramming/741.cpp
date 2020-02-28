#include <iostream>
#include <string>
using namespace std;

int nOfRow;
	int nOfCol;int **a;
void flipRow(int row)
{

	cout << "from : (flipping row :"<< row<< ")"<<endl;
for (int i = 0; i < nOfRow; i++)
	{
		for (int j = 0; j < nOfCol; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < nOfCol; i++)
	{
		a[row][i] = a[row][i] ? 0 : 1;
	}
cout << endl << "to:"<<endl;

	for (int i = 0; i < nOfRow; i++)
	{
		for (int j = 0; j < nOfCol; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
cout << endl ;

}
void flipCol(int col)
{
	cout << "from : (flipping col :"<< col<< ")"<<endl;
for (int i = 0; i < nOfRow; i++)
	{
		for (int j = 0; j < nOfCol; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < nOfRow; i++)
	{
		a[i][col] = a[i][col] ? 0 : 1;
	}

cout << endl << "to:"<<endl;
	for (int i = 0; i < nOfRow; i++)
	{
		for (int j = 0; j < nOfCol; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	 cout << endl;

}

int main()
{
	cin >> nOfRow >> nOfCol;
	a = new int *[nOfRow];

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

	// search row by row capture the most 0 and flip
	// search col by col capture the most 0 and flip
	/**
	 * 1. choose row or column: Always flip the row/column that have higher ratio of tails to head
	 * 2. if n of tails - n of head > 0 flip 
	 *    else if n of tails - n of head = 0
	 * 		   if by flipping this row number of tails increase for any one of the column flip this  
	 */

	int nettImprovement = 0, ifFlipNOfHead = 0, ifFlipNOfTail = 0;
	bool flip = false;

	for (int i = 0; i < nOfRow; i++)
	{
		flip = false;
		nettImprovement =0;
		// imagine that i have fliped the row
		flipRow(i);
		for (int j = 0; j < nOfCol; j++)
		{
			nettImprovement += a[i][j] ? 1 : -1;

 			ifFlipNOfHead = ifFlipNOfTail = 0;
			flipCol(j);
			for (int r = 0; r < nOfRow; r++)
			{
				if (a[i][j] == 0)
				{
					ifFlipNOfTail++;
				}
				else
				{
					ifFlipNOfHead++;
				}
			}
			flipCol(j);
			if (ifFlipNOfHead - ifFlipNOfTail > 0){
				nettImprovement += a[i][j] ? -1 : 1;
			}
		}
		if (nettImprovement<=0){
			flipRow(i);
		}else{
			cout << "flipped : row - " << i <<endl; 
		}
	}

	for(int i = 0 ; i < nOfCol ; i++){
		nettImprovement =0;
		for(int j = 0 ;j < nOfRow;j++){
			nettImprovement += a[j][i] ? -1:1;
		}
		if (nettImprovement>0){
			flipCol(i);
			cout << "flipped : col - " << i <<endl; 
		}
	}
	cout << endl;
	for (int i = 0; i < nOfRow; i++)
	{
		for (int j = 0; j < nOfCol; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}