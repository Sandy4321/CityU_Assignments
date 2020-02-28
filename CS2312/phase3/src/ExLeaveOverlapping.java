
public class ExLeaveOverlapping extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveOverlapping() {
		super("Overlap with leave!");
	}

	public ExLeaveOverlapping(Day startDate, Day endDate) {
		super("Overlap with leave from " + startDate + " to " + endDate + "!");
	}
	
	public ExLeaveOverlapping (String eMsg) {
		super (eMsg);
	}
}
