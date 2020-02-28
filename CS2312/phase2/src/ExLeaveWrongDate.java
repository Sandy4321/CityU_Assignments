
public class ExLeaveWrongDate extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveWrongDate() {
		super("Wrong Date.  System date is already " + SystemDate.getInstance() + "!");
	}

	public ExLeaveWrongDate(String eMsg) {
		super(eMsg);
	}
}
