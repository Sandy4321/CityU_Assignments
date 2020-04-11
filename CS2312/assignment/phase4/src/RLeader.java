
public class RLeader implements Role {

	
	@Override
	public String getDescription() {
		return " (Head of Team)";
	}

	@Override
	public String getNameAndRole(Employee e) {
		return e.getName() + " (Head of Team)" ;
	}

	@Override
	public void checkLeaveAvailability(Team team, Employee e, String[] leaveArgs,Day startDate, Day endDate) throws ExLeave {
		String actingHeadName = "unknown";
		try {
			actingHeadName = team.extractActingHeadName(leaveArgs);
		
			if (actingHeadName.equals("")) {
				throw new ExLeaveNoReplacement(team);
			}
			
			Employee actingHead = Company.getInstance().findEmployee(actingHeadName);
			
			if (! team.isMember(actingHead)) {
				throw new ExLeaveActingHeadNotFound(actingHeadName,team);
			}
			
			LeaveRecord overlappedLeave = actingHead.checkOverlapped(startDate, endDate);
			if (overlappedLeave != null) {
				throw new ExLeaveActingHeadNotAvailable(actingHead, overlappedLeave);
			}
			
			
			
		}catch (ArrayIndexOutOfBoundsException exception) {
			throw new ExLeaveNoReplacement(team);
		} catch (ExEmployeeNotFound exception) {
			throw new ExLeaveActingHeadNotFound(actingHeadName, team);
		}
		
	}

	
	

}
