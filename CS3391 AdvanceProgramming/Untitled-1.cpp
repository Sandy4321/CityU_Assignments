// Student name: PATRICK KON TSER JERN	
// Student ID  : 55100597

// Submission deadling: Thursday, 4 April 2019, 2 pm

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

struct Coordinate
{
	int x, y;  // x is the row-index, y is the col-index
};

ostream& operator<<(ostream& osObject, const Coordinate& d)
{
	osObject << "(" << d.x << ", " << d.y << ")";
	return osObject;
}

//----------------------------------------------- function to be implemented by student

void findShortestPath(char **A, int row, int col, stack<Coordinate>& s)
{
	// A[][] represents the maze of size row x col.

	// The array offset[4] allows you to find out the coordinates of the 
	// 4 neighboring points of a given point using a for-loop.

	Coordinate offset[4];
	offset[0].x = offset[1].x = 0;
	offset[0].y = -1;
	offset[1].y = 1;
	offset[2].y = offset[3].y = 0;
	offset[2].x = -1;
	offset[3].x = 1;

	int **d;  // d[][] is used for finding the distances of other points from the start-point
	d = new int*[row];
	for (int i = 0; i < row; i++)
		d[i] = new int[col];


	queue<Coordinate> q;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (A[i][j] != 'S') d[i][j] = -1;
			else {
				d[i][j] = 0;
				Coordinate temp;
				temp.x = i; temp.y = j;
				q.push(temp);
			}
		}
	}
	// q.front() return the front element in the queue
	// q.push(e) add element e to the queue
	// q.pop()   remove the front element from the queue
	bool complete = false;
	bool has_num_added_in_cur_loop = false;
	int step = 1;
	int final_coorX = -1;
	int final_coorY = -1;
	// q is not empty at start. since there must be S from array A
	while (!q.empty() && !complete) {
		//.back element newest element 
		// push makes new .back
		
		//pop removes .front elem
		while (!q.empty() && !complete) {
			
			for (int i = 0; i < 4; i++) {
				int targetX = q.front().x + offset[i].x;
				int targetY = q.front().y + offset[i].y;
				if (targetX < row && targetX >= 0 && targetY < col && targetY >= 0) {
					if (d[targetX][targetY] == -1 ) {
						if (A[targetX][targetY] == '.') {
							d[targetX][targetY] = step;
							has_num_added_in_cur_loop = true;
						}
						else if (A[targetX][targetY] == 'E') {
							complete = true;
							d[targetX][targetY] = step;
							final_coorX = targetX; final_coorY = targetY;
						}
					}
				}
			}
			q.pop();
			}
		if (!has_num_added_in_cur_loop) complete = true;

		if (complete && final_coorX != -1) {
			Coordinate temp; temp.x = final_coorX; temp.y = final_coorY;
			s.push(temp);
			
			for (int i = step-1; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					if (final_coorX + offset[j].x < row && final_coorX + offset[j].x >= 0 && final_coorY + offset[j].y < col && final_coorY + offset[j].y >= 0) {
						if (d[final_coorX + offset[j].x][final_coorY + offset[j].y] == i) {
							temp.x = final_coorX + offset[j].x;
							temp.y = final_coorY + offset[j].y;
							final_coorX = temp.x;
							final_coorY = temp.y;
							break;
						}
					 }
				}
				s.push(temp);
			}
		}
		if (!complete) {
			Coordinate temp;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (d[i][j] == step) {
						temp.x = i; temp.y = j;
						q.push(temp);
					}
				}
			}
		}
		step++;
	}

	// Your codes


}

//---------------------------------------------------- functions prepared for student

char** readFile(const char filename[], int& row, int& col)
{
	ifstream inFile(filename);
	if (!inFile.is_open())
	{
		cout << "Cannot open data file " << filename << endl;
		system("pause");
		exit(1);
	}

	inFile >> row >> col;  // read the values of row and col

						   //create the 2D array A[row][col]
	char **A;
	A = new char*[row];
	for (int i = 0; i < row; i++)
		A[i] = new char[col];

	//read in the contents of A[][]
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			inFile >> A[i][j];

	inFile.close();
	return A;
}

void printArray(char **A, int row, int col)
{
	Coordinate startPoint, endPoint;

	cout << "Array[" << row << "][" << col << "]" << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << A[i][j];
			if (A[i][j] == 'S')
			{
				startPoint.x = i;
				startPoint.y = j;
			}
			else if (A[i][j] == 'E')
			{
				endPoint.x = i;
				endPoint.y = j;
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "start-point : " << startPoint << endl;
	cout << "end-point : " << endPoint << endl;
	cout << endl;
}


int main()
{
	const char *files[] = { "T10-data-1.txt", "T10-data-2.txt", "T10-data-3.txt" };
	char **A;
	int row, col;

	for (int i = 0; i < 3; i++)
	{
		cout << "\n------------------------------------------\n\n";
		cout << "Test file : " << files[i] << endl << endl;

		A = readFile(files[i], row, col);
		printArray(A, row, col);

		stack<Coordinate> s;
		findShortestPath(A, row, col, s);

		if (!s.empty())
		{
			cout << "\nShortest path from start-point to end-point:\n";

			cout << s.top();
			s.pop();

			int count = 1;
			while (!s.empty())
			{
				cout << " -> ";
				if (count % 5 == 0)
					cout << endl;

				cout << s.top();
				s.pop();
				count++;
			}
			cout << endl;
		}
		else
			cout << "DO NOT find any path from start-point to end-point\n";

		for (int j = 0; j < row; j++)
			delete[] A[j];
		delete[] A;  // return the memory space to the OS
	}

	system("pause");
	return 0;
}
