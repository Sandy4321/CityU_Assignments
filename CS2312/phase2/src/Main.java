import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	/*
	 * TODO:
	 * 1. Exception handling
	 * 2. Make all arrayList into list
	 * 4. try remove Exception e in main to see more other problems
	 * 5. add @ Override
	 * 6. should search employee be inside employee or company
	 * 7. beware of comparable generic field
	 * 8. use grep to find e turn it into exception if it is in the catch clause.
	 * 9. did i accidentally add finally for one of the command?
	 * 10. should i put finally on all LOL  contradiction?
	 * 11. do we need wrong command exception
	 * 12. eclipse random add import for me 
	 * 13. replace == for most of them to .equals (self implemented) and significantly reduce code lines.
	 * 14. Exception i spelled excpetion
	 * 15.  helena says there should exist another new object just for operation
	 */
	
	public static void main (String[] args) {
		
		
		Scanner inUser = new Scanner(System.in);
		
		
		System.out.print("Please input the file pathname: ");
		String strFilePath = inUser.nextLine();
		
		Scanner inFile = null;
		
		try {
			inFile = new Scanner (  new File ( strFilePath )  );
			
			Company company = Company.getInstance();
			
			String strStartingDate = inFile.nextLine();
			System.out.println( "\n> " + strStartingDate );
			SystemDate.initiateSystemDateInstance(  strStartingDate.split("\\|")[1]  );
			
			while ( inFile.hasNextLine() ) {
				
				String strNextCommand = inFile.nextLine();
				
				if ( strNextCommand.equals("") ) { continue; }


				strNextCommand = strNextCommand.trim();
				
				System.out.println( "\n> " + strNextCommand );
				
				String[] cmdParts = strNextCommand.split("\\|");
				
				if ( cmdParts[0].equals ( "hire" ) ) {
					(new CommandHire()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listEmployees" ) ) {
					(new CommandListEmployees()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listLeaves" ) ) {
					(new CommandListLeave()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listTeams" ) ) {
					(new CommandListTeams()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "startNewDay" ) ) {
					(new CommandStartNewDay()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "setupTeam" ) ) {
					(new CommandSetupTeams()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "takeLeave" ) ) {
					(new CommandTakeLeave()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "undo" ) ) {
					RecordedCommand.undoOneCommand();
					
					
				} else if ( cmdParts[0].equals( "redo" ) ) {
					RecordedCommand.redoOneCommand();
					
					
				} else {
					throw new ExCommandWrong() ;
				}
			}
			
		} catch ( FileNotFoundException e ) {
			System.out.println("File not found!");
		} catch ( ExCommandWrong e ) {
			System.out.println("Unknown command - ingnored!");
//		} catch ( Exception e ) {
//			System.out.println(e.getMessage());
		} finally {
			
			if (inFile != null) {
				inFile.close();
			}
			
			inUser.close();
		}
		
	}
	
	
	
}
