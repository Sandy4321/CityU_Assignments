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

	public void addEmployee(Employee e) throws ExEmployee {

		if (employeeExist(e.getName())) {
			throw new ExEmployeeDuplicate();
		} else if (e.getAnnualLeaves() > 300 || e.getAnnualLeaves() < 0) {
			throw new ExEmployeeAnnualLeavesOutOfRange();
		}

		theCompany.allEmployees.add(e);
		Collections.sort(theCompany.allEmployees);

	}

	public void rmvEmployee(Employee e) {
		theCompany.allEmployees.remove(e);
	}

	public void addTeam(Team t) throws ExTeam {

		if (teamExist(t.getTeamName())) {
			throw new ExTeamAlreadyExist();
		}

		theCompany.allTeams.add(t);
		Collections.sort(theCompany.allTeams);
	}

	private boolean teamExist(String teamName) {
		for (Team t : allTeams) {
			if (t.getTeamName().equals(teamName)) {
				return true;
			}
		}
		return false;
	}

	public void rmvTeam(Team t) {
		theCompany.allTeams.remove(t);
	}

	public void listEmployees() {
		for (Employee e : theCompany.allEmployees) {
			System.out.println(e);
		}
	}

	public void listTeams() { // TODO : what if its empty we still show?

		System.out.printf("%-30s%-10s%-13s\n", "Team Name", "Leader", "Setup Date");

		for (Team t : theCompany.allTeams) {
			System.out.println(t);
		}
	}

	private Boolean employeeExist(String employeeName) {
		for (Employee e : theCompany.allEmployees) {
			if (e.getName().equals(employeeName)) {
				return true;
			}
		}
		return false;
	}

	public Employee findEmployee(String employeeName) throws ExEmployeeNotFound {
		for (Employee e : theCompany.allEmployees) {
			if (e.getName().equals(employeeName)) {
				return e;
			}
		}
		throw new ExEmployeeNotFound();
	}

}
