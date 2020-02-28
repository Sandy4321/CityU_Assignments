
public class ChangeAnnualLeaves extends RecordedCommand {

	Employee e;
	int oldAnnualLeaves;

	@Override
	public void execute(String[] cmdParts) {

		Company c = Company.getInstance();
		e = c.findEmployee(cmdParts[1]);
		if (e != null) {
			oldAnnualLeaves = e.getAnnualLeaves();
			e.changeAnnualLeaves(Integer.parseInt(cmdParts[2]));
			clearRedoList();
			addUndoCommand(this);
		}
		System.out.println("Done.");
	}

	@Override
	public void undoMe() {
		int temp = e.getAnnualLeaves();
		e.changeAnnualLeaves(oldAnnualLeaves);
		oldAnnualLeaves = temp;
		addRedoCommand(this);

	}

	@Override
	public void redoMe() {
		int temp = e.getAnnualLeaves();
		e.changeAnnualLeaves(oldAnnualLeaves);
		oldAnnualLeaves = temp;
		addUndoCommand(this);

	}

}
