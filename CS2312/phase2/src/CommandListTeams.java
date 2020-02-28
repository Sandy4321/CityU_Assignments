
public class CommandListTeams implements Command {

	@Override
	public void execute(String[] commandArgs) {
		Company companyInstance = Company.getInstance();
		companyInstance.listTeams();
	}

}
