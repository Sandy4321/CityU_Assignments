import java.util.*;
public class Company {
	
	// Singleton fields/methods
	private static Company theCompany = new Company();

	public static Company getInstance() {return theCompany;}
	
	private Company() {
		allEmployees = new ArrayList<>();
	}
	
	
	// fields
	private ArrayList<Employee> allEmployees;
	
	
	
	// methods
	public void addEmployee(Employee e) {
		allEmployees.add(e);
	}
	
	public Employee findEmployee(String name) throws ExEmployeeNotFound {
		for(Employee e : allEmployees) {
			if(e.getName().equals(name)) {
				return e;
			}
		}
		throw new ExEmployeeNotFound();
	}
	public void listEmployee() {
		for(Employee e:allEmployees) {
			System.out.println(e);
		}
	}
	
	
}
