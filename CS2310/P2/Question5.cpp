#include <iostream>
using namespace std;

int main()
{
    // START

    // I. retriving inputs

    // To obtain size of matrix
    // declaring variable
    int size;
    // requesting input
    cout << "Please input the size of the matrix: " << endl;
    // recieving and assigning input
    cin >> size;

    // To obtain matrix
    // declaring 2D-array (max=10)
    int matrix[10][10] = {0};
    // requesting input
    cout << "Please input the matrix row by row:" << endl;
    // recieving and assigning input
    /*
	The matrix have a structure of:
	col    col    col
	row [0][0] [1][0] [2][0]
	row [0][1] [1][1] [2][1]
	row [0][2] [1][2] [2][2]

	matrix[ COL y (vertical)][ ROW x (horizontal)]
	*/
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            cin >> matrix[col][row];
        }
    }


    // II. calculation

    // for result printing
    bool isToepliz = true;

    /*
	The main idea is to go through first col and check in a diagonal direction.
	Then go through the first row and check again.

	It was noticed that the line drawn diagonally for a 4 * 4 matrix is :
	4 variable > 3 variable > 2 variable > 1 variable
	[4][3][2][1]
	[0][4][3][2]
	[0][0][4][3]
	[0][0][0][4]

	This is the same for row
	[4][3][2][1]
	[3][4][3][2]
	[2][3][4][3]
	[1][2][3][4]

	So we can now loop through from 1 to 4 for size = 4;

	we will use a tracker to track the first element
	and the number of repetition is (size - 1)-index times.
	*/

    // start from the left-top of the matrix go to the right and to the bottom
    int cRow = 0, cCol = 0, tracker;
    for (int index = 0; index < size; index++)
    {
        // from the first row
        // get the first element in the col
        tracker = matrix[0][index];
        // repeat for (size - 1) - index times
        for (int increment = 1; increment <= (size - 1) - index; increment++)
        {
            // go diagonally row + 1; col + 1
            if (matrix[increment][index + increment] != tracker)
            {
                isToepliz = false;
            }
        }
        // from the first col
        // get the first element in the rows
        tracker = matrix[index][0];
        // move diagonaly, repeating (size - 1) - index times
        for (int increment = 1; increment <= (size - 1) - index; increment++)
        {
            if (matrix[index + increment][increment] != tracker)
            {
                isToepliz = false;
            }
        }
    }

    // III. printing results
    if (isToepliz)
    {
        cout << "Matrix is a Toepliz" << endl;
    }
    else
    {
        cout << "Matrix is not a Toepliz" << endl;
    }

    // END
    return 0;
}