
public class CommandHire extends RecordedCommand {

	Employee e;
	
	@Override
	public void execute(String[] commandArgs) {
		
		try {
			
			if ( commandArgs.length < 3 ) {
				throw new ExCommandArgumentsInsufficient();
			}
			
			e = new Employee(  commandArgs[1]  ,  Integer.parseInt(commandArgs[2])   );
			
			Company companyInstance = Company.getInstance();
			companyInstance.addEmployee(e);
			
			addUndoCommand( this );
			clearRedoList();
			
			System.out.println( "Done." );
			
		} catch ( NumberFormatException exception ) {
			System.out.println( exception.getMessage() );
		} catch ( ExCommandArgumentsInsufficient exception ) {
			System.out.println( exception.getMessage() );
		} catch ( ExEmployee exception ) {
			System.out.println( exception.getMessage() );
		}
		
	}

	@Override
	public void undoMe() {
		
		Company companyInstance = Company.getInstance();
		companyInstance.rmvEmployee( e );	
		
		addRedoCommand( this );
		
	}

	@Override
	public void redoMe() {

		Company companyInstance = Company.getInstance();
		try {
			companyInstance.addEmployee( e );
			addUndoCommand( this );
		} catch (ExEmployee exception) {
			System.out.println( exception.getMessage() );
		}
		
		
	}

}
