
public class CmdAddTeamMember extends RecordedCommand {

	private Team team;
	private Member member;

	@Override
	public void execute(String[] commandArgs) {

		try {
			if (commandArgs.length < 3) {
				throw new ExCommandArgumentsInsufficient();
			}

			// ask company to get me the team
			Company companyInstance = Company.getInstance();

			team = companyInstance.findTeam(commandArgs[1]);

			member = companyInstance.addEmployeeToTeam(team,commandArgs[2]);


			addUndoCommand(this);
			clearRedoList();

			System.out.println("Done.");

		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println(exception.getMessage());
		} catch (ExTeam exception) {
			System.out.println(exception.getMessage());
		} catch (ExEmployeeNotFound exception) {
			System.out.println(exception.getMessage());
		}

	}

	@Override
	public void undoMe() {
		team.rmvMember(member);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		team.addMember(member);
		addUndoCommand(this);
	}

}
