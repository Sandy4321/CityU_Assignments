import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Employee implements Comparable<Employee> {

	/**
	 * TODO: 1.turn leave into a leaveManager
	 */

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

	// TODO: Remember to see if anyone call this function
	public String getName() {
		return this.name;
	}

	public String toString() {
		return this.name + " " + "(Entitled Annual Leaves: " + this.annualLeaves + " days)";
	}

	public int getAnnualLeaves() {
		return this.annualLeaves;
	}

	public LeaveRecord leaveOverlap(LeaveRecord leave) {
		for (LeaveRecord employeeLeave : allLeaveRecord) {
			if (employeeLeave.isWithin(leave)) {
				return employeeLeave;
			}
		}
		return null;
	}

	public int numOfLeaveAvailable() {
		int availableLeave = annualLeaves;
		for (LeaveRecord employeeLeave : allLeaveRecord) {
			availableLeave -= employeeLeave.getLeaves(); // TODO: should be remove the employee should not have access
		}
		return availableLeave;
	}

	public void addLeave(LeaveRecord leave) throws ExLeave {
		LeaveRecord temp = leaveOverlap(leave); //TODO : helena says there should exist another new object
		if (temp != null) {
			throw new ExLeaveOverlapping(temp.getStartDate(),temp.getEndDate());
		}

		int numOfLeave = numOfLeaveAvailable();
		if (numOfLeave - leave.getLeaves() < 0) {
			throw new ExLeaveBalanceInsufficient(numOfLeave);
		}

		if (SystemDate.getInstance().compareTo(leave.getStartDate()) > 0) {
			throw new ExLeaveWrongDate();
		}

		allLeaveRecord.add(leave);
		Collections.sort(allLeaveRecord);
	}

	public void listLeave() {
		if (allLeaveRecord.isEmpty()) {
			System.out.println("No leave record");
		} else {
			for (LeaveRecord employeeLeave : allLeaveRecord) {
				System.out.println(employeeLeave);
			}
		}
	}
	public void rmvLeaveRecord( LeaveRecord leaveRec) {
		allLeaveRecord.remove(leaveRec);
	}
}
