
public class LeaveActingHeadRecord implements Comparable<LeaveActingHeadRecord> {

	private Employee actingHead;
	private LeaveRecord leaveRecord;
	private Team team;
	
	public LeaveActingHeadRecord(LeaveRecord leaveRecord,Employee actingHead,Team team) {
		this.leaveRecord = leaveRecord;
		this.actingHead = actingHead;
		this.team = team;
	}

	public Employee getActingHead() {
		return this.actingHead;
	}
	
	public LeaveRecord getLeaveRecord () {
		return this.leaveRecord;
	}
	
	public Team getTeam() {
		return this.team;
	}
	
	@Override
	public String toString () {
		return this.leaveRecord.toString() + ": " + this.actingHead;
	}
	
	@Override
	public int compareTo(LeaveActingHeadRecord anotherRecord) {
		return this.leaveRecord.compareTo(anotherRecord.leaveRecord);
	}
}
