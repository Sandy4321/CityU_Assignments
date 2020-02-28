
public class ExCommandArgumentsInsufficient extends ExCommand {

	private static final long serialVersionUID = 1L;
	
	public ExCommandArgumentsInsufficient () {
		super ("Insufficient command arguments!");
	}
	
	public ExCommandArgumentsInsufficient (String eMsg) {
		super(eMsg);
	}
}
