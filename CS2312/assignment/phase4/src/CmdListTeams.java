
public class CmdListTeams implements Command {

	@Override
	public void execute(String[] commandArgs) {
		Company companyInstance = Company.getInstance();
		companyInstance.listTeams();
	}

}
