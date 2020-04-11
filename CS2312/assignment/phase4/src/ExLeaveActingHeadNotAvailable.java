
public class ExLeaveActingHeadNotAvailable extends ExLeave {

	private static final long serialVersionUID = 1L;

	public ExLeaveActingHeadNotAvailable (Employee employee , LeaveRecord leaveRecord) {
		super (employee.getName()+" is on leave during "+leaveRecord+"!");
	}
}
