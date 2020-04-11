
public class ExTeamAlreadyExist extends ExTeam {

	private static final long serialVersionUID = 1L;

	public ExTeamAlreadyExist() {
		super("Team already exists!");
	}

	public ExTeamAlreadyExist(Team t) {
		super("Team : " + t + " already exist!");
	}

	public ExTeamAlreadyExist(String eMsg) {
		super(eMsg);
	}
}
