
public class CmdListLeave implements Command {

	@Override
	public void execute(String[] commandArgs) {
		
		Company companyInstance = Company.getInstance();
		
		if (commandArgs.length == 1) {
			companyInstance.listAllEmployeeLeave();
		
		}else {
			try {
				companyInstance.listEmployeeLeave(commandArgs[1]);
				
				
			}catch (ExEmployeeNotFound exception) {
				System.out.println(exception.getMessage());
			}
		}
		
	}

}
