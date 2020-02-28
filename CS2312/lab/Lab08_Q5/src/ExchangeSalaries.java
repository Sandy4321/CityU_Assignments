
public class ExchangeSalaries extends RecordedCommand {

	Employee a;
	Employee b;

	@Override
	public void execute(String[] cmdParts) {

		Company c = Company.getInstance();
		a = c.findEmployee(cmdParts[1]);
		b = c.findEmployee(cmdParts[2]);
		if (a != null && b != null) {
			int tempSalary = a.getSalary();
			a.setSalary(b.getSalary());
			b.setSalary(tempSalary);
			addUndoCommand(this);
			clearRedoList();
		} else {
			if (a == null) {
				System.out.println("cannot find " + cmdParts[1]);
			} else {
				System.out.println("cannot find " + cmdParts[2]);
			}
		}
		System.out.println("Done.");
	}

	@Override
	public void undoMe() {
		int tempSalary = a.getSalary();
		a.setSalary(b.getSalary());
		b.setSalary(tempSalary);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		int tempSalary = a.getSalary();
		a.setSalary(b.getSalary());
		b.setSalary(tempSalary);
		addUndoCommand(this);
	}

}
