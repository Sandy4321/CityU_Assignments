
public class ExLeaveNoReplacement extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveNoReplacement () {
		super ("Please name a member to be the acting head of other team for which he is leader.");
	}
	
	public ExLeaveNoReplacement(Team team) {
		super ("Please name a member to be the acting head of "+team.getTeamName());
	}
}
