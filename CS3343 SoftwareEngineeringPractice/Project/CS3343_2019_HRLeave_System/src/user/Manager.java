package user;

import java.util.Calendar;
import java.util.Date;

import department.Department;

public class Manager extends User{

	//wait for designing the department class
	private Department department;
	
	public Manager(int eid, String username, String name, int age, Calendar dateJoined) {
		super(eid, username, name, age, dateJoined);
	}

	@Override
	public boolean isManager() {
		return true;
	}

	public Department getDepartment() {
		return null;
		//connect to database
		//get the department data where the record has the same pw and eid, using the geteid and getpw function
		//getDepartment Data
	}

	@Override
	public boolean isSenior() {
		return true;
	}
}
