import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	
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

				strNextCommand = strNextCommand.trim();
				
				if ( strNextCommand.equals("") ) { continue; }

				
				System.out.println( "\n> " + strNextCommand );
				
				String[] cmdParts = strNextCommand.split("\\|");
				
				if ( cmdParts[0].equals ( "hire" ) ) {
					(new CmdHire()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listEmployees" ) ) {
					(new CmdListEmployees()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listLeaves" ) ) {
					(new CmdListLeave()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "listTeams" ) ) {
					(new CmdListTeams()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "startNewDay" ) ) {
					(new CmdStartNewDay()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "setupTeam" ) ) {
					(new CmdSetupTeams()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals( "takeLeave" ) ) {
					(new CmdTakeLeave()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals("addTeamMember") ) {
					(new CmdAddTeamMember()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals("listRoles") ) {
					(new CmdListRole()).execute(cmdParts);
					
					
				} else if ( cmdParts[0].equals("listTeamMembers") ) {
					(new CmdListTeamMembers()).execute(cmdParts);
					
					
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
