package user;

import java.util.Calendar;

public class Leave {

	private int leaveID;
	private String leaveType;
	private String applicationType;
	private Employee e;
	private Calendar d;
	
	public Leave(int lid, String leaveType, String applicationType,Employee e, Calendar d) {
		this.leaveID = lid;
		this.leaveType = leaveType;
		this.e = e;
		this.d = d;
	}
	
	public int getleaveID() {
		return this.leaveID;
	}

	public Employee getEmployee() {
		return e;
	}
	public Calendar getDate() {
		return d;
	}
	public String getType() {
		return leaveType;
	}
	public String getApplication() {
		return applicationType;
	}
	
}
