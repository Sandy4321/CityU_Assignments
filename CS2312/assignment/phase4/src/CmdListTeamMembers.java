
public class CmdListTeamMembers implements Command {

	@Override
	public void execute(String[] commandArgs) {
		Company companyInstance = Company.getInstance();
		companyInstance.listTeamMembers();
	}

}
