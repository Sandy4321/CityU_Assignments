
public class AddSalary extends RecordedCommand {

	Employee e;
	int addAmount; 
	
	
	@Override
	public void execute(String[] cmdParts) {
		
		addAmount = Integer.parseInt(cmdParts[2]);
		
		Company c = Company.getInstance();
		e = c.findEmployee(cmdParts[1]);
		
		if(e!=null) {
			e.addSalary(addAmount);
			clearRedoList(); 
			addUndoCommand(this);
		}
		
		System.out.println("Done.");
	}
	
	@Override
	public void undoMe() { // this function will not be called if e is null so no need checking
		e.addSalary(-addAmount);
		addRedoCommand(this);
	}
	
	@Override
	public void redoMe() { // this function will not be called if e is null so no need checking
		e.addSalary(addAmount);
		addUndoCommand(this);
	}

}
