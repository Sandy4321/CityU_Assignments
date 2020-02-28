
public class ExLeaveBalanceInsufficient extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveBalanceInsufficient() {
		super("Insufficient Balance!");
	}

	public ExLeaveBalanceInsufficient(int numberOfDays) {
		super("Insufficient balance.  " + numberOfDays + " days left only!");
	}
	
	public ExLeaveBalanceInsufficient(String eMsg) {
		super(eMsg);
	}
}
