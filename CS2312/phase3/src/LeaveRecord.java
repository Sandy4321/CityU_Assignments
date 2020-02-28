
public class LeaveRecord implements Comparable<LeaveRecord>{

	/**
	 * TODO:
	 * 1. consider a period class oh actually this class is a period object if we need more we might consider make a generic one 
	 */
	
	
	private int leaveDays;
	private Day startDate;
	private Day endDate;
	
	public LeaveRecord (Day startDate, Day endDate ) { // TODO:leave and start date might reverse
		this.startDate = startDate;
		this.endDate = endDate;
		this.leaveDays = Day.dayDifference(startDate, endDate);
		
	}
	
	public int getLeaves() {
		return this.leaveDays;
	}
	public Day getStartDate() {
		return this.startDate;
	}
	public Day getEndDate() {
		return this.endDate;
	}
	
	// TODO: conisder shifitng this into
	public boolean isWithin ( LeaveRecord leave ) {
		if ( leave.startDate.compareTo(this.startDate) < 0 ) {
			return leave.endDate.compareTo(this.startDate) >= 0;
		} else {
			return leave.startDate.compareTo(this.endDate) <= 0;
		}
	}
	
	public int compareTo (LeaveRecord anotherLeave) {
		return this.startDate.compareTo(anotherLeave.startDate);
	}
	
	public String toString() {
		return startDate.toString() + " to " + endDate.toString(); 
	}
	
}
