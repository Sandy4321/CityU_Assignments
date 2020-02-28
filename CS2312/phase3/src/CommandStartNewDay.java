
public class CommandStartNewDay extends RecordedCommand {

	String oldDay;
	String newDay;

	@Override
	public void execute(String[] commandArgs) {

		try {
			if (commandArgs.length < 2) {
				throw new ExCommandArgumentsInsufficient();
			}

			oldDay = SystemDate.getInstance().toString();
			newDay = commandArgs[1];
			SystemDate.getInstance().set(commandArgs[1]);

			addUndoCommand(this);
			clearRedoList();

			System.out.println("Done.");

		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println(exception.getMessage());
		}

	}

	@Override
	public void undoMe() {
	
		SystemDate.getInstance().set(oldDay);
		addRedoCommand(this);
	
	}

	@Override
	public void redoMe() {
		
		SystemDate.getInstance().set(newDay);
		addUndoCommand(this);
	
	}

}
