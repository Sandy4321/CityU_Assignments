
public class ExEmployeeAnnualLeavesOutOfRange extends ExEmployee {

	private static final long serialVersionUID = 1L;

	public ExEmployeeAnnualLeavesOutOfRange() {
		super("Annual leaves out of range (0-300)!");
	}

	public ExEmployeeAnnualLeavesOutOfRange(Employee e) {
		super("Annual leaves of " + e + " out of range (0-300)!");
	}

	public ExEmployeeAnnualLeavesOutOfRange(String eMsg) {
		super(eMsg);
	}
}
