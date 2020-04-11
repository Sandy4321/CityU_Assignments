
public class CmdSetupTeams extends RecordedCommand {

	private Team t;

	@Override
	public void execute(String[] commandArgs) {

		try {
			if (commandArgs.length < 3) {
				throw new ExCommandArgumentsInsufficient();
			}

			Company companyInstance = Company.getInstance();

			t = companyInstance.createTeam(commandArgs[1], commandArgs[2]);

			addUndoCommand(this);
			clearRedoList();

			System.out.println("Done.");

		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println(exception.getMessage());
		} catch (ExEmployeeNotFound exception) {
			System.out.println(exception.getMessage());
		} catch (ExTeam exception) {
			System.out.println(exception.getMessage());
		}

	}

	@Override
	public void undoMe() {
		Company.getInstance().rmvTeam(t);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		Company.getInstance().addTeam(t);
		addUndoCommand(this);
	}

}
