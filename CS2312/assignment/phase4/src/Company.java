import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Company {

	// Singleton
	private static Company theCompany = new Company();

	public static Company getInstance() {
		return theCompany;
	}

	private Company() {
		this.allEmployees = new ArrayList<>();
		this.allTeams = new ArrayList<>();
	}

	
	
	// fields
	private List<Employee> allEmployees;
	private List<Team> allTeams;

	
	
	// methods

	// regarding employee
	public void hireEmployee(String name, int annualLeave) throws ExEmployee {

		if (Employee.employeeExist(allEmployees, name)) {
			throw new ExEmployeeDuplicate();
		} else if (annualLeave > 300 || annualLeave < 0) {
			throw new ExEmployeeAnnualLeavesOutOfRange();
		}

		Employee employee = new Employee(name, annualLeave);

		addEmployee(employee);
	}

	public void addEmployee(Employee e) {
		allEmployees.add(e);
		Collections.sort(allEmployees);

	}

	public void rmvEmployee(Employee e) {
		allEmployees.remove(e);
	}

	public void listEmployees() {
		for (Employee e : allEmployees) {
			e.printAnnualLeave();
		}
	}

	public Employee findEmployee(String employeeName) throws ExEmployeeNotFound {
		return Employee.findEmployee(allEmployees, employeeName);
	}

	
	
	// regarding teams
	public Team createTeam(String teamName, String employeeName) throws ExEmployeeNotFound, ExTeam {

		Employee employee = findEmployee(employeeName);

		if (teamExist(teamName)) {
			throw new ExTeamAlreadyExist();
		}

		Team team = new Team(teamName, employee);
		addTeam(team);
		return team;
	}

	private boolean teamExist(String teamName) {
		for (Team t : allTeams) {
			if (t.getTeamName().equals(teamName)) {
				return true;
			}
		}
		return false;
	}

	public void addTeam(Team t) {
		allTeams.add(t);
		Collections.sort(allTeams);
	}

	public void rmvTeam(Team t) {
		allTeams.remove(t);
	}

	public void listTeams() {

		System.out.printf("%-30s%-10s%-13s\n", "Team Name", "Leader", "Setup Date");

		for (Team t : allTeams) {
			System.out.println(t);
		}
	}

	public void listTeamMembers() {
		for (Team team : allTeams) {
			team.listTeamMembers();
		}
	}

	public Team findTeam(String teamName) throws ExTeam {
		for (Team team : allTeams) {
			if (team.getTeamName().equals(teamName)) {
				return team;
			}
		}
		throw new ExTeamNotFound();
	}

	public Member addEmployeeToTeam(Team team, String employeeName) throws ExEmployeeNotFound, ExTeam {
		Employee employee = findEmployee(employeeName);
		return team.addNewMember(employee, new RMember());
	}

	
	
	// regarding leave

	public LeaveRecord decideLeaveForEmployee(Employee employee, String[] leaveArgs) throws ExLeave, ExCommand {
		try {
			for (Team team : allTeams) {
				team.checkMemberAvailability(employee,leaveArgs);
				
			}
			LeaveRecord leaveRecord = employee.createLeaveRecord(leaveArgs[2], leaveArgs[3]);
			return leaveRecord;
		} catch (ArrayIndexOutOfBoundsException exception) {
			throw new ExCommandArgumentsInsufficient();
		}
	}

	public List<LeaveActingHeadRecord> handleActingHeadRecord(Employee employee, String[] leaveArgs,
			LeaveRecord leaveRecord) throws ExLeave {
		List<LeaveActingHeadRecord> actingHeadRecordList = new ArrayList<>();
		for (Team team : allTeams) {
			team.populateActingHeadLeaveRecord(employee, leaveArgs, leaveRecord, actingHeadRecordList);
		}

		return actingHeadRecordList;
	}

	public void listAllEmployeeLeave() {
		for (Employee e : theCompany.allEmployees) {
			e.listLeave();
		}
	}

	public void listEmployeeLeave(String employeeName) throws ExEmployeeNotFound {
		findEmployee(employeeName).listLeave();
	}

	public void rmvLeaveRecord(Employee employee, LeaveRecord leaveRec, List<LeaveActingHeadRecord> actingHeadRecords) {
		Team.rmvLeaveRecord(employee, leaveRec, actingHeadRecords);
	}

	public void addLeaveRecord(Employee employee, LeaveRecord leaveRec, List<LeaveActingHeadRecord> actingHeadRecords) {
		Team.addLeaveRecord(employee, leaveRec, actingHeadRecords);
	}

	// regarding roles
	public void listRoles(String employeeName) throws ExEmployeeNotFound {

		Employee employee = findEmployee(employeeName);

		Team.listRoleFor(allTeams, employee);

	}

}
