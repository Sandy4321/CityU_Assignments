
public class CommandTakeLeave extends RecordedCommand {

	private Employee e;
	private LeaveRecord leaveRec;
	
	@Override
	public void execute(String[] commandArgs) {
		
		try {
			
			if (commandArgs.length < 4) {
				throw new ExCommandArgumentsInsufficient();
			}
			
			Company companyInstance = Company.getInstance();
			e = companyInstance.findEmployee(commandArgs[1]);
			
			leaveRec = new LeaveRecord(new Day(commandArgs[2]), new Day(commandArgs[3]));
			
			e.addLeave(leaveRec);
			
			addUndoCommand(this);
			clearRedoList();
			
			System.out.println("Done.");
			
		} catch (ExCommandArgumentsInsufficient exception) {
			System.out.println( exception.getMessage() );
		} catch (ExEmployeeNotFound exception){
			System.out.println( exception.getMessage() );
		} catch (ExLeave exception) {
			System.out.println( exception.getMessage() );
		}
		
	}

	@Override
	public void undoMe() {
		
		e.rmvLeaveRecord(leaveRec);
		
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		
		try {
			e.addLeave(leaveRec);
			addUndoCommand(this);
		} catch (ExLeave exception) {
			System.out.println( exception.getMessage() );
		}
		
	}

}
