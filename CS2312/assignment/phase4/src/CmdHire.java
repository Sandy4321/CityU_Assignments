
public class CmdHire extends RecordedCommand {

	Employee e;

	@Override
	public void execute(String[] commandArgs) {

		try {

			if (commandArgs.length < 3) {
				throw new ExCommandArgumentsInsufficient();
			}

			Company.getInstance().hireEmployee(commandArgs[1],Integer.parseInt(commandArgs[2]));

			addUndoCommand(this);
			clearRedoList();

			System.out.println("Done.");

		} catch (NumberFormatException exception) {
			System.out.println(exception.getMessage());
		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println(exception.getMessage());
		} catch (ExEmployee exception) {
			System.out.println(exception.getMessage());
		}

	}

	@Override
	public void undoMe() {
		Company.getInstance().rmvEmployee(e);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		Company.getInstance().addEmployee(e);
		addUndoCommand(this);

	}

}
