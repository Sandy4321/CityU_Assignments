
public class Employee implements Comparable<Employee>{ 
	
	String name;
	int annualLeaves;
	
	public Employee ( String name , int annualLeaves ) {
		this.name = name;
		this.annualLeaves = annualLeaves;
	}
	
	@Override
	public int compareTo(Employee anotherEmployee) {
		return this.name.compareTo(anotherEmployee.name);
	}
	
	// TODO: Remember to see if anyone call this function
	public String getName () {
		return this.name;
	}
	
	public String toString() {
		return this.name + " " + "(Entitled Annual Leaves: " + this.annualLeaves + " days)";
	}

	public int getAnnualLeaves() {
		return this.annualLeaves;
	}
}
