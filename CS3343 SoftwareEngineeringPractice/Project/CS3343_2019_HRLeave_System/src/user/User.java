package user;

import java.util.Calendar;

public abstract class User {
	private String username;
	private String name;
	private int age;
	private Calendar dateJoined;
	private int eid;
	
	public User(
			int eid,
			String username,
			String name,
			int age,
			Calendar dateJoined
		) {
		this.eid = eid;
		this.username = username;
		this.name = name;
		this.age = age;
		this.dateJoined = dateJoined;
	}
	
	public String getUsername() {
		return username;
	}
	
	public String getName() {
		return name;
	}
	
	public int getAge() {
		return age;
	}
	
	public int getEid() {
		return eid;
	}
	
	public abstract boolean isManager();
	public abstract boolean isSenior();
}
