
public class ExTeam extends Exception {

	private static final long serialVersionUID = 1L;

	public ExTeam() {
		super("Team Error");
	}

	public ExTeam(String eMsg) {
		super(eMsg);
	}
}
