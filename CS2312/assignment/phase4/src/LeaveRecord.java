
public class LeaveRecord implements Comparable<LeaveRecord>{
	
	private int leaveDays;
	private Day startDate;
	private Day endDate;
	
	public LeaveRecord (Day startDate, Day endDate,int leaveDays ) { 
		this.startDate = startDate;
		this.endDate = endDate;
		this.leaveDays = leaveDays;
	}
	
	public int getLeaves() {
		return this.leaveDays;
	}
	
	public boolean isWithin ( Day anotherStartDate, Day anotherEndDate ) {
		if ( anotherStartDate.compareTo(this.startDate) < 0 ) {
			return anotherEndDate.compareTo(this.startDate) >= 0;
		} else {
			return anotherStartDate.compareTo(this.endDate) <= 0;
		}
	}
	
	@Override
	public int compareTo (LeaveRecord anotherLeave) {
		return this.startDate.compareTo(anotherLeave.startDate);
	}
	
	@Override
	public String toString() {
		return startDate.toString() + " to " + endDate.toString(); 
	}
}
