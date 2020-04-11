
public class ExCommand extends Exception {
	
	private static final long serialVersionUID = 1L;

	public ExCommand () { super ("Command Error!"); }
	
	public ExCommand ( String msg ) { super( msg ); }

}
