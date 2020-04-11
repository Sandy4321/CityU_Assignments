
public class CmdListEmployees implements Command {

	@Override
	public void execute(String[] commandArgs) {
		Company.getInstance().listEmployees();
	}

}
