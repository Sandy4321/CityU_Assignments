
public class CommandListEmployees implements Command {

	@Override
	public void execute(String[] commandArgs) {
		Company companyInstance = Company.getInstance();
		companyInstance.listEmployees();
	}

}
