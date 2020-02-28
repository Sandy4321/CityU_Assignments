
public class Employee {
	private String name;
	private int salary;
	private int annualLeaves;

	public Employee(String name, int salary, int leaves) {
		this.name = name;
		this.salary = salary;
		this.annualLeaves = leaves;
	}

	public String getName() {
		return this.name;
	}

	public int getSalary() {
		return this.salary;
	}

	public void addSalary(int increase) {
		this.salary += increase;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public void changeAnnualLeaves(int annualLeaves) {
		this.annualLeaves = annualLeaves;
	}

	public int getAnnualLeaves() {
		return this.annualLeaves;
	}

	@Override
	public String toString() {
		return this.name + String.format(" ($%d, %d days)", this.salary, this.annualLeaves);
	}

}
