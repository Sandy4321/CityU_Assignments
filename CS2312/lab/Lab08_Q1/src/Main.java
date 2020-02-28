import java.io.*;
import java.util.*;

public class Main {

	public static void main(String [] args) throws FileNotFoundException
	{	
		Scanner in = new Scanner(System.in);
		System.out.print("Please input the file pathname: ");
		String filepathname = in.nextLine();
		Scanner inFile = new Scanner(new File(filepathname));
		int tot=inFile.nextInt();
		
		Company company = Company.getInstance();
		for (int i=0;i<tot;i++) 
			company.addEmployee(new Employee(inFile.next(),inFile.nextInt(),inFile.nextInt()));
				
		while (inFile.hasNext())		
		{
			String cmdLine = inFile.nextLine();
			
			//Blank lines exist in data file as separators.  Skip them.
			if (cmdLine.equals("")) continue;  
			
			System.out.println("\n> "+cmdLine);
			
			//split the words in actionLine => create an array of word strings [!!! LEARN !!!]
			String[] cmdParts = cmdLine.split(" "); 
			
			if (cmdParts[0].equals("addSalary"))
				(new AddSalary()).execute(cmdParts);
			if (cmdParts[0].equals("list"))
				(new ListAllRecords()).execute(cmdParts);
		}
		
		inFile.close();			
		in.close();
	}
}


/*




Step 4 Command interface, AddSalary class, ListAllRecords class
===============================================================
[See lab sheet]
*/