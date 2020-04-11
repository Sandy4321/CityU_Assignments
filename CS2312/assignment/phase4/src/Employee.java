import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Employee implements Comparable<Employee> {


	private String name;
	private int annualLeaves;

	private List<LeaveRecord> allLeaveRecord;

	public Employee(String name, int annualLeaves) {
		this.name = name;
		this.annualLeaves = annualLeaves;
		allLeaveRecord = new ArrayList<>();
	}

	@Override
	public int compareTo(Employee anotherEmployee) {
		return this.name.compareTo(anotherEmployee.name);
	}

	@Override
	public String toString() {
		return this.name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void printAnnualLeave() {
		System.out.println(this.name + " " + "(Entitled Annual Leaves: " + this.annualLeaves + " days)");
	}

	public int getAnnualLeaves() {
		return this.annualLeaves;
	}

	public int numOfLeaveAvailable() {
		int availableLeave = annualLeaves;
		for (LeaveRecord employeeLeave : allLeaveRecord) {
			availableLeave -= employeeLeave.getLeaves(); 
		}
		return availableLeave;
	}

	public void listLeave() {
		System.out.println(this.name+":");
		if (allLeaveRecord.isEmpty()) {
			System.out.println("No leave record");
		} else {
			for (LeaveRecord employeeLeave : allLeaveRecord) {
				System.out.println(employeeLeave);
			}
		}
	}
	
	public LeaveRecord createLeaveRecord (String strStartDate, String strEndDate) throws ExLeave {
		
		
		Day startDate = new Day (strStartDate);
		Day endDate = new Day (strEndDate);
		
		LeaveRecord overlappedLeave = checkOverlapped(startDate, endDate);
		if (overlappedLeave != null) {
			throw new ExLeaveOverlapping(overlappedLeave);		
		}
		
		int numOfLeave = numOfLeaveAvailable();
		int leaveDates = Day.dayDifference(startDate, endDate);
		if (numOfLeave - leaveDates < 0) {
			throw new ExLeaveBalanceInsufficient(numOfLeave);
		}

		if (SystemDate.getInstance().compareTo(startDate) > 0) {
			throw new ExLeaveWrongDate();
		}
		
		LeaveRecord leaveRecord = new LeaveRecord(startDate, endDate,leaveDates);
		
		addLeaveRecord(leaveRecord);
		
		return leaveRecord;
	}
	
	public LeaveRecord checkOverlapped (Day startDate,Day endDate) {
		for (LeaveRecord employeeLeave : allLeaveRecord) {
			if (employeeLeave.isWithin(startDate,endDate)) {
				return employeeLeave;
			}
		}
		return null;
	}
	
	public void addLeaveRecord(LeaveRecord leaveRec) {
		allLeaveRecord.add(leaveRec);
		Collections.sort(allLeaveRecord);
	}
	
	public void rmvLeaveRecord( LeaveRecord leaveRec) {
		allLeaveRecord.remove(leaveRec);
	}
	
	
	


	public static boolean employeeExist(List<Employee>  allEmployees , String employeeName) {
		for (Employee e : allEmployees) {
			if (e.name.equals(employeeName)) {
				return true;
			}
		}
		return false;
	}	
	
	public static Employee findEmployee(List<Employee> allEmployee,String employeeName) throws ExEmployeeNotFound {
		for (Employee e : allEmployee) {
			if (e.name.equals(employeeName)) {
				return e;
			}
		}
		throw new ExEmployeeNotFound();
	}
	
}
