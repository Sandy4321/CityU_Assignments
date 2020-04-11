
public class ExLeaveActingHeadNotFound extends ExLeave {
	
	public ExLeaveActingHeadNotFound(String actingHeadName, Team team) {
		super ("Employee ("+actingHeadName+") not found for "+team.getTeamName()+"!");
	}

	private static final long serialVersionUID = 1L;

	public ExLeaveActingHeadNotFound() {
		super ("Employee not found!");
	}
}
