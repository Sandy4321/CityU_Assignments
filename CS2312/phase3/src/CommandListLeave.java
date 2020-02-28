
public class CommandListLeave implements Command {

	@Override
	public void execute(String[] commandArgs) {
		
		Company companyInstance = Company.getInstance();
		if (commandArgs.length == 1) {
			companyInstance.listAllEmployeeLeave();
		}else {
			try {
				Employee e = companyInstance.findEmployee(commandArgs[1]);
				e.listLeave();
			}catch (ExEmployeeNotFound exception) {
				System.out.println(exception.getMessage());
			}
		}
		
	}

}
