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
			if (cmdParts[0].equals("changeAnnualLeaves"))
				(new ChangeAnnualLeaves()).execute(cmdParts);
			if (cmdParts[0].equals("list"))
				(new ListAllRecords()).execute(cmdParts);
			if (cmdParts[0].equals("undo"))
				RecordedCommand.undoOneCommand();
			if (cmdParts[0].equals("redo"))
				RecordedCommand.redoOneCommand();
		}
		
		inFile.close();			
		in.close();
	}
}


/*

Given code for main()
=====================
			if (cmdParts[0].equals("undo"))
				RecordedCommand.undoOneCommand();
			if (cmdParts[0].equals("redo"))
				RecordedCommand.redoOneCommand();

				
Given code for AddSalary
========================
public class AddSalary extends RecordedCommand //<=== note the change
{
	//When addSalary is invoked, an object of the AddSalary class will be 
	// added to the undo list (and may also be stored in the redo list later)
	//We add instance fields in the objects to store the data which will be needed upon undo/redo
	Employee e;
	int addAmount; 
	
	@Override
	public void execute(String[] cmdParts)
	{
		//Note: In Q1, e and addAmount were local variables.  But now they are the data in the object (instance fields).
		Company company = Company.getInstance();
		e = company.findEmployee(cmdParts[1]);
		addAmount=Integer.parseInt(cmdParts[2]);

		e.addSalary(addAmount);

		addUndoCommand(this); //<====== store this command (addUndoCommand is implemented in RecordedCommand.java)
		clearRedoList(); //<====== There maybe some commands stored in the redo list.  Clear them.

		System.out.println("Done.");
	}
	
	@Override
	public void undoMe()
	{
		e.addSalary(-addAmount);
		addRedoCommand(this); //<====== upon undo, we should keep a copy in the redo list (addRedoCommand is implemented in RecordedCommand.java)
	}
	
	@Override
	public void redoMe()
	{
		e.addSalary(addAmount);
		addUndoCommand(this); //<====== upon redo, we should keep a copy in the undo list
	}
}
*/