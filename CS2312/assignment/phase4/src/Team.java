import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Team implements Comparable<Team> {

	private String teamName;
	private Day dateSetup;

	private List<Member> teamMembers;

	private List<LeaveActingHeadRecord> allActingHeadsLeaveRecords;

	public Team(String teamName, Employee teamLeader) {
		this.teamName = teamName;
		this.dateSetup = SystemDate.getInstance().clone();

		Member teamLeaderRole = new Member(new RLeader(), teamLeader);
		this.teamMembers = new ArrayList<>();
		teamMembers.add(teamLeaderRole);
		
		this.allActingHeadsLeaveRecords = new ArrayList<>();
	}

	@Override
	public int compareTo(Team anotherTeam) {
		return this.teamName.compareTo(anotherTeam.teamName);
	}

	@Override
	public String toString() {
		return String.format("%-30s%-10s%-13s", this.teamName, getLeader().getName(), this.dateSetup);
	}
	
	public Member getLeader() {
		for (Member member : teamMembers) {
			if (member.getRole() instanceof RLeader) {
				return member;
			}
		}
		return null;
	}

	public String getTeamName() {
		return this.teamName;
	}

	public Member addNewMember(Employee employee, Role role) throws ExTeam {
		if (isMember(employee)) {
			throw new ExTeamEmployeeHadJoined();
		}
		Member member = new Member(role, employee);
		addMember(member);
		return member;
	}

	public void addMember(Member member) {
		teamMembers.add(member);
		Collections.sort(teamMembers);
	}

	public void rmvMember(Member member) {
		teamMembers.remove(member);
	}

	private Member findMember(Employee e) {
		for (Member member : teamMembers) {
			if (member.getEmployee() == e) {
				return member;
			}
		}
		return null;
	}

	public static void listRoleFor(List<Team> allTeams,Employee e) {

		boolean participatedAny = false;
		
		for (Team t: allTeams) {

			Member member = t.findMember(e);
			if (member != null) {
				participatedAny = true;
				System.out.println(t.teamName + member.getDescription());	
			}
		}
		if (!participatedAny) {
			System.out.println("No role");
		}
	}

	public void listTeamMembers() {
		System.out.println(teamName + ":");
		for (Member member : teamMembers) {
			System.out.println(member.getNameAndRole());
		}
		if (!allActingHeadsLeaveRecords.isEmpty()) {
			System.out.println("Acting heads:");	
			for (LeaveActingHeadRecord leaveActingHeadRecord : allActingHeadsLeaveRecords ) {
				System.out.println(leaveActingHeadRecord);
			}
		}
		System.out.println();
	}

	public boolean isMember(Employee e) {
		for (Member member : teamMembers) {
			if (member.getEmployee() == e) {
				return true;
			}
		}
		return false;
	}

	public String extractActingHeadName(String[] args) {
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals(teamName)) {
				return args[i + 1]; // might have array index out of bound
			}
		}
		return "";
	}

	
	public void checkMemberAvailability(Employee employee, String[] leaveArgs) throws ExLeave{
		Member member = findMember(employee);
		if (member != null) {
			Day startDate = new Day(leaveArgs[2]);
			Day endDate = new Day(leaveArgs[3]);
			member.getRole().checkLeaveAvailability(this,employee,leaveArgs,startDate, endDate);
		}
	}

	
	public void populateActingHeadLeaveRecord(Employee e, String[] leaveArgs, LeaveRecord leaveRecord,List<LeaveActingHeadRecord> actingHeadRecords) throws ExLeave {

		Member member = findMember(e);
		String actingHeadName = "";
		try {
			if (member != null) {
				if (member.getRole() instanceof RLeader) {
					actingHeadName = extractActingHeadName(leaveArgs);
		
					Employee actingHead = Company.getInstance().findEmployee(actingHeadName);
					LeaveActingHeadRecord leaveActingHeadRecord =  new LeaveActingHeadRecord(leaveRecord, actingHead,this);
					actingHeadRecords.add(leaveActingHeadRecord);
					addActingHeadLeaveRecord(leaveActingHeadRecord);
				}
			}
		} catch (ExEmployeeNotFound exception) {
			throw new ExLeaveActingHeadNotFound(actingHeadName, this);
		}

	}

	
	

	public static void rmvLeaveRecord(Employee e, LeaveRecord leaveRec, List<LeaveActingHeadRecord> actingHeadRecords) {
		for(LeaveActingHeadRecord actHeadRecord:actingHeadRecords) {
			actHeadRecord.getTeam().rmvActingHeadLeaveRecord(actHeadRecord);
		}
		e.rmvLeaveRecord(leaveRec);
	}

	public static void addLeaveRecord(Employee e, LeaveRecord leaveRec, List<LeaveActingHeadRecord> actingHeadRecords) {
		for(LeaveActingHeadRecord actHeadRecord:actingHeadRecords) {
			actHeadRecord.getTeam().addActingHeadLeaveRecord(actHeadRecord);
		}
		e.addLeaveRecord(leaveRec);
	}
	
	
	
	
	public void rmvActingHeadLeaveRecord(LeaveActingHeadRecord actingHeadRecord) {
		this.allActingHeadsLeaveRecords.remove(actingHeadRecord);
	}
	public void addActingHeadLeaveRecord(LeaveActingHeadRecord actingHeadRecord) {
		this.allActingHeadsLeaveRecords.add(actingHeadRecord);
		Collections.sort(allActingHeadsLeaveRecords);
	}

	public List<LeaveActingHeadRecord> getActingHeadLeaveRecords() {
		return this.allActingHeadsLeaveRecords;
	}



}
