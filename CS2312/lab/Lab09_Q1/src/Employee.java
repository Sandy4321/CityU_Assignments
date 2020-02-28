import java.util.ArrayList;

public class Employee implements Comparable<Employee>{
	private String name;
	private int yrLeavesEntitled;
	
	public Employee(String n , int yle) {
		this.name = n;
		this.yrLeavesEntitled = yle;
	}
	
	public String getName() {
		return this.name;
	}
	
	public static Employee searchEmployee(ArrayList<Employee> list,String nameToSearch) {
		for(Employee e: list) {
			if(e.name.equals(nameToSearch)) {
				return e;
			}
		}
		return null;
	}
	
	@Override
	public int compareTo(Employee anotherEmployee) {
		return this.name.compareTo(anotherEmployee.name);
	}
	
}
