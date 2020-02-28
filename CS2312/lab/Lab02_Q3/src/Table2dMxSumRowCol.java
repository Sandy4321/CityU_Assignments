import java.io.*; //For file I/O
import java.util.*;

public class Table2dMxSumRowCol 
{

	//(1) Add the instance field, nums, for the 2D array here
	// (Answer is in Given_Code.txt!!)
	int[][] nums;
	//Constructor
	public Table2dMxSumRowCol(String filepathname) throws FileNotFoundException //learn exceptions later
	{
//		System.out.println(new File(".").getAbsoluteFile());
		//Part I. Create the 2D array
		// (2) nums = ____________ 
		// (Answer is in Given_Code.txt!!)
		nums = new int[10][10];
		
		//Part II. Perform file reading and insert values into the 2D array
		Scanner inFile;
		//(3) construct the scanner object for file reading
		// (Answer is in Given_Code.txt!!)
		inFile = new Scanner(new File(filepathname)); 
		
		// (4) read the file until the end and add values 
		// (Answer is in Given_Code.txt!!)
		while (inFile.hasNext()) {
			nums[inFile.nextInt()][inFile.nextInt()] = inFile.nextInt();
		}
		
		inFile.close();
	}
	
	//
	//Other methods 
	
	public void print() {
		for (int r = 0 ; r < 10 ; r ++) {
			for (int c = 0 ; c < 10 ;c++) {
				System.out.printf("%5d",nums[r][c]);
			}
			System.out.println();
		}
	}
	
	public int getRowSumMax() {
		int sum = 0,tempSum = 0;
		for (int r = 0 ; r < 10 ; r ++) {
			tempSum = 0;
			for (int c = 0 ; c < 10 ;c++) {
				tempSum += nums[r][c];
			}
			if (sum < tempSum ) {
				sum = tempSum;
			}
		}
		return sum;
	}
	
	public int getColSumMax() {
		int sum = 0,tempSum = 0;
		for (int c = 0 ; c < 10 ; c ++) {
			tempSum = 0;
			for (int r = 0 ; r < 10 ;r++) {
				tempSum += nums[r][c];
			}
			if (sum < tempSum ) {
				sum = tempSum;
			}
		}
		return sum;
	}
	
}