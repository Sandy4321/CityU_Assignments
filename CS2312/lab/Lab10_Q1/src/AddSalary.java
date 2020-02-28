
public class AddSalary extends RecordedCommand {

	Employee e;
	int addAmount; 
	
	
	@Override
	public void execute(String[] cmdParts) {
		
		try {
			if (cmdParts.length < 3) {
				throw new ExInsufficientArguments();
			}
			addAmount = Integer.parseInt(cmdParts[2]);
			
			Company c = Company.getInstance();
			e = c.findEmployee(cmdParts[1]);
			
			if(e!=null) {
				e.addSalary(addAmount);
				clearRedoList(); 
				addUndoCommand(this);
			}
			
			System.out.println("Done.");
		} catch (NumberFormatException e) {
			System.out.println("Wrong number format!");
		} catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		}catch (ExInsufficientArguments e) {
			System.out.println(e.getMessage());
		}
	}
	
	@Override
	public void undoMe() { // this function will not be called if e is null so no need checking
		e.addSalary(-addAmount);
		addRedoCommand(this);
	}
	
	@Override
	public void redoMe() { // this function will not be called if e is null so no need checking
		e.addSalary(addAmount);
		addUndoCommand(this);
	}

}
