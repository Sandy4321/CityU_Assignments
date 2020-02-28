
public class FireEmployee extends RecordedCommand {

	private Employee e;
	
	@Override
	public void execute(String[] cmdParts) {
		Company c = Company.getInstance();
		e = c.findEmployee(cmdParts[1]);
		if(e!=null) {
			c.removeEmployee(e);
			addUndoCommand(this);
			clearRedoList();
		}
		System.out.println("Done.");
	}

	@Override
	public void undoMe() {
		Company c = Company.getInstance();
		c.addEmployee(e);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		Company c = Company.getInstance();
		c.removeEmployee(e);
		addUndoCommand(this);
	}

}
