
public class ExLeaveOverlapping extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveOverlapping() {
		super("Overlap with leave!");
	}

	public ExLeaveOverlapping(LeaveRecord leaveRecord) {
		super("Overlap with leave from " + leaveRecord + "!");
	}
	
	public ExLeaveOverlapping (String eMsg) {
		super (eMsg);
	}
}
