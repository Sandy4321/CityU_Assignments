
public class ExLeave extends Exception {

	private static final long serialVersionUID = 1L;

	public ExLeave() {
		super("Leave Error!");
	}

	public ExLeave(String eMsg) {
		super(eMsg);
	}
}
