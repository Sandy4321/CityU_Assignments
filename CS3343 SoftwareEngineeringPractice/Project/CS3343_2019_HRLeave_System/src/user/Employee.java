package user;

import java.util.ArrayList;
import java.util.Calendar;

import department.Department;

public abstract class Employee extends User{

	//wait for designing the department class
	private Department department;
	
	public Employee(int eid, String username, String name, int age, Calendar dateJoined, int annualLeavesApplied) {
		super(eid, username, name, age, dateJoined);
		this.annualLeavesApplied = annualLeavesApplied;
	}
	
	private int annualLeavesApplied;

	@Override
	public boolean isManager() {
		return false;
	}

	
	public Department getDepartment() {
		return null;
		//connect to database
		//get the department data where the record has the same pw and eid, using the geteid and getpw function
		//getDepartment Data
	}
	
	public ArrayList<Calendar> applyLeave(int leaveType, Calendar startDate, Calendar endDate) {
		//Connect to database
		//leaveType == 1 means sick leave
		ArrayList<Calendar> leaveList = new ArrayList<Calendar>();
		
		Calendar temp = startDate;
        while(!temp.equals(endDate)){
       	 	temp.add(Calendar.DAY_OF_MONTH, +1);
       	 	leaveList.add((Calendar)temp.clone());
        }
        leaveList.add(temp);
        
		if(leaveType == 1 && leaveList.size() == 1) {
			//Find the record in the database using the eid and pw
			//Sick leave no need approval, parse "Sick Leave",  StartDate, EndDate in db
			return leaveList;
		} else if (leaveType == 2) {
			//leaveType == 2 means annual leave
			//Find the record in the database using the eid and pw
			//Annual leave no need approval, create Leave Object
			if(this.getEntitledAnnualLeaves() - this.annualLeavesApplied >= leaveList.size()) {
				//Todo: Create Leave object
				this.annualLeavesApplied -= leaveList.size();
				//Find the record in the database using the eid and pw
				//And then find out the corresponding department list, and push it to the pending list                      
				return leaveList;
			} else {
				System.out.println("No Enough Entitled Annual Leaves");
				return new ArrayList<Calendar>();
			}
		} else if (leaveType == 3) {
			//leaveType == 3 means no pay leave
			//Find the record in the database using the eid and pw
			//No Pay leave no need approval, parse "No Pay Leave", No of leave, StartDate, EndDate in db 
			return leaveList;
		} else {
			return new ArrayList<Calendar>();
		}
	}
	
	public abstract int getEntitledAnnualLeaves();
}


