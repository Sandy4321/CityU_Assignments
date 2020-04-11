import java.util.List;

public class CmdTakeLeave extends RecordedCommand {

	private Employee e;
	private LeaveRecord leaveRec;
	private List<LeaveActingHeadRecord> actingHeadRecord;

	@Override
	public void execute(String[] commandArgs) {

		try {

			if (commandArgs.length < 4) {
				throw new ExCommandArgumentsInsufficient();
			}

			Company companyInstance = Company.getInstance();
			e = companyInstance.findEmployee(commandArgs[1]);
			
			leaveRec = companyInstance.decideLeaveForEmployee(e, commandArgs);
			actingHeadRecord = companyInstance.handleActingHeadRecord(e, commandArgs,leaveRec);
			
			addUndoCommand(this);
			clearRedoList();

			System.out.println("Done.");

		} catch (ExCommand exception) {
			System.out.println(exception.getMessage());
		} catch (ExEmployeeNotFound exception) {
			System.out.println(exception.getMessage());
		} catch (ExLeave exception) {
			System.out.println(exception.getMessage());
		} 

	}

	@Override
	public void undoMe() {
		Company.getInstance().rmvLeaveRecord(e,leaveRec,actingHeadRecord);
		addRedoCommand(this);
	}

	@Override
	public void redoMe() {
		Company.getInstance().addLeaveRecord(e,leaveRec,actingHeadRecord);
		addUndoCommand(this);
	}

}
