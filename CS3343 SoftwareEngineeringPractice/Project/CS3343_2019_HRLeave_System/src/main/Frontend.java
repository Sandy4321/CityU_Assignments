package main;

import java.util.ArrayList;
import java.util.Calendar;

import ui.Presentation;
import user.Employee;
import user.Leave;
import user.User;

public class Frontend extends Thread {

	private static Frontend instance;

	public static Frontend getInstance() {
		if (instance == null) {
			instance = new Frontend(new String[0]);
		}
		return instance;
	}

	private Frontend(String[] args) {
		this.args = args;
		
	}

	private Presentation app;

	private String[] args;

	private Backend observer;
	
	private String username;
	private String password;
	private int eid;
	private String sessionId;
	private boolean authenticated = false;

	private User currentUser; 
	
	private ArrayList<String> userOnLeaveToday = new ArrayList(); 
	@Override
	public void run() 
    { 
		try {
			// Displaying the thread that is running
			System.out.println("Frontend is starting at thread: " + Thread.currentThread().getId());
			Presentation.start(this.args);

		} catch (Exception e) {
			// Throwing an exception
			System.out.println("Exception is caught");
		}
    }

	public void addObserver(Backend be) {
		this.observer = be;
	}

	public boolean authenticate_login_user(String username, String password) {
		this.username = username;
		this.password = password;
		Backend.AuthState authState = this.observer.authenticate_login_user(username, password);

		this.eid = authState.eid;
		this.sessionId = authState.sessionId;
		this.authenticated = authState.authenticated;
		
		return authState.authenticated;
	}
	
	public boolean dummy_insertUser(String username, String password) {
		try {
			return this.observer.dummy_insert_user(username, password);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public boolean insertUser(
			String username, 
			String password, 
			String name, 
			int age, 
			boolean isManager,
			boolean isSenior
		) {
		try {
			return this.observer.insert_user(username, password,name,age,isManager,isSenior);
		} catch (Exception e) {
			System.out.println(e);
		}
		return false;
	}

	public boolean loggedIn() {
		return this.authenticated;
	}

	public void logout() {
		this.authenticated = false;
	}

	public boolean isManager() {
		// TODO Auto-generated method stub
		return false;
	}
	
	public User getCurrUser() {
		this.currentUser = this.observer.getUser(this.eid);
		return this.currentUser;
	}
	
	public User getUser(int eid) {
		return this.observer.getUser(eid);
	}
	
	public ArrayList<String> getUserOnLeaveToday(){
		this.userOnLeaveToday = this.getUserOnLeave(Calendar.getInstance());
		return this.userOnLeaveToday;
	}
	
	public ArrayList<String> getUserOnLeave(Calendar d) {
		return this.observer.getUserOnLeave(d);
	}

	public ArrayList<Leave> getLeaves() {
		return this.observer.getLeavePending();
	}
	
	public boolean insertLeaves(ArrayList<Calendar> leave_dates, String leaveType) {
		return this.observer.insertLeave(leave_dates, leaveType, ((Employee)this.currentUser));
	}

}
