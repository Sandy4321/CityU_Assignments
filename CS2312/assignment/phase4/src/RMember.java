
public class RMember implements Role{


	@Override
	public String getDescription() {
		return "";
	}

	@Override
	public String getNameAndRole(Employee e) {
		return e.getName();
	}

	@Override
	public void checkLeaveAvailability(Team team, Employee e, String[] leaveArgs,Day startDate,Day endDate) throws ExLeave {
		
		
		for (LeaveActingHeadRecord actHeadRecord : team.getActingHeadLeaveRecords()) {
			if (actHeadRecord.getActingHead() == e
					&& actHeadRecord.getLeaveRecord().isWithin(startDate, endDate)) {
				throw new ExLeaveActingHeadNotAllowed(actHeadRecord, team);
			}
		}
	}

}
