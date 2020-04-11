
public interface Role {

	public String getDescription();
	
	public String getNameAndRole(Employee e);
	
	public void checkLeaveAvailability (Team team ,Employee e,String[] leaveArgs,Day startDate,Day endDate)throws ExLeave ; 
}


