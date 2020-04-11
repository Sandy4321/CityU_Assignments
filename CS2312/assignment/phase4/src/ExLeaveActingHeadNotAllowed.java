
public class ExLeaveActingHeadNotAllowed extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveActingHeadNotAllowed(LeaveActingHeadRecord actHeadRecord, Team team) {
		super("Cannot take leave.  "+actHeadRecord.getActingHead().getName()+" is the acting head of "+team.getTeamName()+" during "+actHeadRecord.getLeaveRecord()+"!");
	}


}
