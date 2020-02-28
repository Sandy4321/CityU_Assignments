import java.util.ArrayList;
import java.util.Collections;

public class Company {

	// private fields
	private ArrayList<Employee> allEmployees;
	private ArrayList<Team> allTeams;
	
	// Singleton fields/methods
	private static Company instance = new Company();
	
	public static Company getInstance () {
		return instance;
	}
	
	private Company() {
		allEmployees = new ArrayList<>();
		allTeams = new ArrayList<>();
	}
	
	
	
	
	public void listTeams() 
	{
		Team.list(allTeams);
	}
	
	public Employee createEmployee(String name, int yle) // See how it is called in main()
	{
		Employee e = new Employee(name,yle);
		allEmployees.add(e);
		Collections.sort(allEmployees); //allEmployees
		return e;
	}
	
	public Team createTeam(String teamName, String employeeName) // See how it is called in main()
	{
		Employee e = Employee.searchEmployee(allEmployees,employeeName);
		Team t = new Team(teamName,e);
		allTeams.add(t);
		Collections.sort(allTeams); //allTeams
		return t; //Why return?  Ans: Later you'll find it useful for undoable comments.
	}
	
}
