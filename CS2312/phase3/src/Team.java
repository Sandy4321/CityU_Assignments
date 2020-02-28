import java.util.ArrayList;
import java.util.List;

public class Team implements Comparable<Team> {

	private String teamName;
	private Employee teamLeader;
	private Day dateSetup;
	
	private List<Employee> teamMembers;

	public Team(String teamName, Employee teamLeader) {
		this.teamName = teamName;
		this.teamLeader = teamLeader;
		this.dateSetup = SystemDate.getInstance().clone();
		this.teamMembers = new ArrayList<>();
	}

	@Override
	public int compareTo(Team anotherTeam) {
		return this.teamName.compareTo(anotherTeam.teamName);
	}

	@Override
	public String toString() {
		return String.format("%-30s%-10s%-13s", this.teamName, this.teamLeader.getName(), this.dateSetup);
	}

	public String getTeamName() {
		return this.teamName;
	}
	
	public void addMember() {
		
	}

}
