
public class ExInsufficientArguments extends Exception {

	/**
	 * 
	 */
	
	private static final long serialVersionUID = 11;
	public ExInsufficientArguments () { super("Insufficient command arguments!");}
	public ExInsufficientArguments (String message) {super(message);}
}
