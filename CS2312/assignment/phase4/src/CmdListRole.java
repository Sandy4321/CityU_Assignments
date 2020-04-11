
public class CmdListRole implements Command {

	@Override
	public void execute(String[] commandArgs) {
		try {
			if (commandArgs.length < 2) {
				throw new ExCommandArgumentsInsufficient();
			}
			
			Company.getInstance().listRoles(commandArgs[1]);
			
		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println(exception.getMessage());
		} catch (ExEmployeeNotFound exception) {
			System.out.println(exception.getMessage() );
		}
	}

}
