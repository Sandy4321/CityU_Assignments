
public class AddSalary implements Command {

	@Override
	public void execute(String[] cmdParts) {
		
		Employee e;
		int addAmount = Integer.parseInt(cmdParts[2]);
		
		Company c = Company.getInstance();
		e = c.findEmployee(cmdParts[1]);
		
		if(e!=null) {
			e.addSalary(addAmount);
		}
		
		System.out.println("Done.");
	}

}
