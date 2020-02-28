import java.util.*;

public class Lab02Q2_MultTable_Given {

	public static void main(String[] args) {
		
		
		int width, height;
		
		Scanner s = new Scanner(System.in);
		
		
		System.out.print("Input the width of the multiplication table (2-10): ");
		width = s.nextInt();
		
		System.out.println();
		
		System.out.print("Input the height of the multiplication table (2-10): ");
		height = s.nextInt();

		System.out.println();
		
		for (int i = 0 ; i < height ; i++) {
			for (int j = 0 ; j<width ; j++ ) {
				System.out.printf("%5d|",(i+1)*(j+1));
			}
			System.out.println();
		}
		
		
		
		s.close();
		
		/* Notes to students:
			1.  We need a Scanner object to get user input (like Lab01-Q1 Page 3):
			- Add the import statement at the beginning: import java.util.*; 
			- Declare a scanner object: Scanner [object variable name];
			- Create a scanner object as: new Scanner(System.in);
			- To read an integer, we call the .nextInt() method: [scanner object].nextInt();
			- Close the scanner object: [scanner object].close();

	 		2.  Learn from Q1: System.out.printf("%5d", x); // Show x, "%" means a field,
								// right aligned, width=5, 
								// d means decimal 
		*/ 
	}
}
