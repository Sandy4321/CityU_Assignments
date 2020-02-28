
public class CommandSetupTeams extends RecordedCommand {

	private Team t;
	
	@Override
	public void execute(String[] commandArgs) {
		
		try {
			if ( commandArgs.length < 3 ) {
				throw new ExCommandArgumentsInsufficient();
			}
			
			Company companyInstance = Company.getInstance();
			
			Employee leader = companyInstance.findEmployee(commandArgs[2]);
			
			t = new Team(
					commandArgs[1], 
					leader);

			companyInstance.addTeam( t );
			
			addUndoCommand( this );
			clearRedoList();
			
			System.out.println( "Done." );
			
		} catch ( ExCommandArgumentsInsufficient exception ) {
			System.out.println( exception.getMessage() );
		} catch ( ExEmployeeNotFound exception ) {
			System.out.println( exception.getMessage() );
		} catch ( ExTeam exception ){
			System.out.println( exception.getMessage() );
		}
		
	}

	@Override
	public void undoMe() {
		Company companyInstance = Company.getInstance();
		companyInstance.rmvTeam(t);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		Company companyInstance = Company.getInstance();
		try {
			companyInstance.addTeam(t);
			addUndoCommand(this);
		} catch (ExTeam exception) {
			System.out.println( exception.getMessage() );
		}
	}

}
