import java.io.FileNotFoundException; //We will learn exceptions later
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException //We will learn exceptions later
	{
		System.out.print("Please input the file pathname: ");

		Scanner scannerObj = new Scanner(System.in);
		String filePathName = scannerObj.nextLine();
		
		Table2dMxSumRowCol table = new Table2dMxSumRowCol(filePathName);
		
		//Your tasks: 
		//  Create a new Table2dMxSumRowCol object and assign it to a variable of Table2dMxSumRowCol 
		//      Call its constructor with the filePathName as argument 
		//  Then apply the .print(), .getRowSumMax() and 
		//      .getColSumMax() methods to finish the work.
		//
		table.print();
		
		RowColResult rcr = table.getRowSumMax();
		System.out.printf("%s%d (row ","Maximum row sum: ",rcr.getValue() );
		
		System.out.print(rcr.getRowCol()[0]);
		for (int i = 1 ; i < rcr.getCount() ; i ++) {
			System.out.print("," + rcr.getRowCol()[i]);
		}
		
		System.out.println(")");
		
		rcr = table.getColSumMax();
		System.out.printf("%s%d (col ","Maximum col sum: " , rcr.getValue());

		System.out.print(rcr.getRowCol()[0]);
		for (int i = 1 ; i < rcr.getCount() ; i ++) {
			System.out.print("," + rcr.getRowCol()[i]);
		}
		
		System.out.println(")");
		
		
		scannerObj.close();
	}
	
}